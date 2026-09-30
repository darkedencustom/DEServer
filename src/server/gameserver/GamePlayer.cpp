//////////////////////////////////////////////////////////////////////////////
// Filename    : GamePlyaer.cpp 
// Written By  : reiot@ewestsoft.com
// Description :
//////////////////////////////////////////////////////////////////////////////

#include "GamePlayer.h"
#include "Utility.h"
#include <cmath>
#include "Assert.h"
#include "Creature.h"
#include "Slayer.h"
#include "Vampire.h"
#include "Ousters.h"
#include "LogClient.h"
#include "Zone.h"
#include "RelicUtil.h"
#include "PacketFactoryManager.h"
#include "PacketValidator.h"
#include "IncomingPlayerManager.h"
#include "PCFinder.h"
#include "TelephoneCenter.h"
#include "DB.h"
#include "VSDateTime.h"
#include "Thread.h"
#include "GuildManager.h"
#include "Guild.h"
#include "VariableManager.h"
#include "BillingInfo.h"
#include "BillingPlayerManager.h"
#include <fstream>
#include "Properties.h"
#include "EventKick.h"
#include "StringPool.h"
#include "CreatureUtil.h"
#include "PlayerCreature.h"
#include "GQuestManager.h"
#include "item/Motorcycle.h"
#include "Shape.h"
#include "EffectMute.h"
#include "SkillInfo.h"
#include "SkillHandlerManager.h"
#include "SkillCastingTimeManager.h"
#include "DBExecuteManager.h"

#include "Cpackets/CGConnect.h"
#include "Gpackets/GCKickMessage.h"
#include "Gpackets/GCSystemMessage.h"

#include "ServiceDeadline.h"

#include "chinabilling/CBillingInfo.h"
#ifdef __CONNECT_CBILLING_SYSTEM__
	#include "chinabilling/CBillingPlayerManager.h"
#endif

#include <stdio.h>
#include <sstream>

#include "GameWorldInfoManager.h"
//#include "PacketLog.h" // packet log�� �����ֱ� ���� ���? 

//////////////////////////////////////////////////////////////////////////////
// ��� packet�鿡 ���ؼ� profiling�Ѵ�. by sigi. 2002.5.6
//
// ��, �̰� ����ϱ� ���ؼ��� 
// Profile.h�� MAX_PROFILE_SAMPLES += 300�� ����� �Ѵ�.
//////////////////////////////////////////////////////////////////////////////
//#define __PROFILE_PACKETS__

#ifdef __PROFILE_PACKETS__
	#include "Profile.h"
#endif

// by sigi. 2002.11.12
const int defaultGamePlayerInputStreamSize = 1024;
const int defaultGamePlayerOutputStreamSize = 20480;

static int maxIdleSec         = 60* 5;		// 5��
//static int maxSpeedVerifyTime = 2;  		// 0.3 ��
static int maxVerifyCount     = 3;      	// 3 ��.
static int maxTimeGap         =	2;			// 2 sec
static int SpeedCheckDelay    = 5;			// 5 sec

//----------------------------------------------------------------------------
// How long the client may stay silent before checkToRecvVerifyTime() counts a
// missed CGVerifyTime. This MUST exceed the client's actual send interval.
//
// The original value was 3 seconds, which assumed a client sending every ~2s.
// This client does not: UI/game/GameMain.cpp:4990 (CheckTime) sends CGVerifyTime
// every 5000ms only when __CHECKTIME_CONTROLL is __ON, and that flag is __OFF
// for __DESIGNED_INTERNATION (ContentsFilter.h:252, inside the 168-318 block),
// so the real cadence is 60000ms. With a 3-second window the miss counter hit
// its limit of 4 after ~12-16s and the player was flagged as a speed hacker and
// kicked -- logged to SpeedHack.log as "VerifyTimeCount=0,
// NumOfNotRecvVerifyTime=4", then surfacing as
// "DisconnectException : He is had penalty" in ICMPCProtocolExcpt.log.
//
// 90s leaves comfortable headroom over the client's 60s heartbeat, so a kick
// now needs ~6 minutes of genuine silence (4 misses) rather than 12 seconds.
//----------------------------------------------------------------------------
static int maxVerifyTimeSilenceSec = 90;	// client heartbeat is 60s

const int PCRoomLottoSec = 3600;			// 3600 ��. 1�ð�
const int PCRoomLottoMaxAmount = 3;			// �ѹ��� ���� �� �ִ� �ִ� ���Ǽ�
// CLLoginHandler.cpp�� �ִ� �Լ���.
void addLogoutPlayerData(Player* pPlayer);

//////////////////////////////////////////////////////////////////////////////
// constructor
//////////////////////////////////////////////////////////////////////////////

GamePlayer::GamePlayer (Socket* pSocket)
	 throw (Error)
: //Player(pSocket), 	// by sigi. 2002.11.12
	m_pCreature(NULL), m_PlayerStatus(GPS_NONE), m_pReconnectPacket(NULL)
{
	
	__BEGIN_TRY

	Assert( pSocket != NULL );
	m_pSocket = pSocket;

	//--------------------------------------------------------------------------
	// Plain streams, NOT the SocketEncrypt* pair.
	//
	// __USE_ENCRYPTER__ is unconditionally #defined in Core/Encrypter.h, so this
	// used to always build the encrypted branch. The client is built with
	// __CRYPT __OFF and sends plaintext, so the gameserver was decrypting
	// plaintext into garbage: it read all 23 bytes of CGConnect off the socket,
	// then peek() never produced a usable header, so processCommand() spun with
	// buffered=23 forever and the connection reservation timed out.
	//
	// The loginserver always used the plain SocketInputStream/SocketOutputStream
	// pair, which is exactly why login worked and the gameserver handoff did not.
	//
	// The old #else branch named "SockettInputStream" (doubled t) -- a type that
	// exists nowhere in the tree. It could never have compiled, which shows that
	// branch had never once been built.
	//--------------------------------------------------------------------------
	// create socket input stream
	m_pInputStream = new SocketInputStream( m_pSocket, defaultGamePlayerInputStreamSize );
	Assert( m_pInputStream != NULL );

	// create socket output stream
	m_pOutputStream = new SocketOutputStream( m_pSocket, defaultGamePlayerOutputStreamSize );
	Assert( m_pOutputStream != NULL );

	m_Mutex.setName("GamePlayer");
		
	getCurrentTime(m_ExpireTime);
	m_ExpireTime.tv_sec += maxIdleSec;

	m_AbuseActionPoint = 0;
	
    // ���� �ð��� �޾ƿ´�
	//getCurrentTime(m_SpeedVerify);
	m_SpeedVerify.tv_sec = 0;;
	m_SpeedVerify.tv_usec = 0;;
	m_VerifyCount = 0;
	m_NumOfNotRecvVerifyTime = 0;
	
	getCurrentTime(m_MoveSpeedVerify);
	getCurrentTime(m_AttackSpeedVerify);
	
	m_BasePacketTime.tv_sec = 0;
	m_BasePacketTime.tv_usec = 0;
	m_UpdatePacketTime.tv_sec = 0;
	m_UpdatePacketTime.tv_usec = 0;
	m_dwPrevTimeStamp = 0;
	m_dwPrevServerTime = 0;
	m_dwPrevClientTime = 0;
	m_bCalcPacketDeltaTime = false;
	m_PacketDeltaTime = 0;
	m_PacketDeltaSign = 1;
	
	m_dwPrevChatTime = 0;
	m_iAbnormalChatTryCount = 0;
	m_iAccumAbnormalChatCount = 0;
	
	DWORD dwCurrentTime;
	Timeval currentTime;
	
	getCurrentTime(currentTime);
	
	dwCurrentTime = currentTime.tv_sec * 1000 + currentTime.tv_usec / 1000;
	
	m_dwPrevMoveTime = dwCurrentTime;
	m_lastZoneID = 0;
	m_MoveHist.clear();
	m_iAbnormalMoveTryCount = 0;
	
	m_dwLastMeleeAttackTime = 0;
	m_lAccumAttackTime = 0;
	m_lPenaltyAttackTime = 0;
		
	m_lastSkillType = 0;
	m_GunSkillState = 0;	
	
	m_SpecialEventCount = 0;

	m_bKickForLogin = false;
	
	m_bFreePass = false;

	m_bMetroFreePlayer = false;

//	if ( m_bPCRoomPlay )
//		m_ItemRatioBonusPoint = g_pVariableManager->getPCRoomItemRatioBonusPercent();
//	else
		m_ItemRatioBonusPoint = 0;

	m_PCRoomLottoStartTime.tv_sec = 0;
	m_PCRoomLottoStartTime.tv_usec = 0;
	m_PCRoomLottoSumTime = 0;

	m_bPacketLog = false;

	// ��ü�� ������ ������ �α����� �ð����� ����.
	m_LoginDateTime = VSDateTime::currentDateTime();

#ifdef	__THAILAND_SERVER__
	m_bPermission = false;
#endif
	
//	m_NProtectCSAuth.Init();

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
// destructor
//////////////////////////////////////////////////////////////////////////////

GamePlayer::~GamePlayer ()
	 throw (Error)
{
	__BEGIN_TRY

	//__ENTER_CRITICAL_SECTION(m_Mutex)

	// �� � �÷��̾� ��ü�� ������ ������, �� ���´� �α׾ƿ��̾�� �Ѵ�.
	// �� � �÷��̾ ���� ���� ��Ű����, �� ���¸� �α׾ƿ����� ������ �Ѵ�.
	Assert(m_PlayerStatus == GPS_END_SESSION);

	try
	{
		#ifdef __CONNECT_BILLING_SYSTEM__
			// Pay �����Ѵٰ� �˷��ش�. by sigi. 2002.11.18
			if ( isBillingPlayAvaiable() && !m_bMetroFreePlayer )	// by sigi. 2002.11.23
			{
				g_pBillingPlayerManager->sendPayLogout( this );
			}
		#elif defined(__CONNECT_CBILLING_SYSTEM__ )
			// �߱� ���� ������ logout ��Ŷ�� ������.
			g_pCBillingPlayerManager->sendLogout( this );
		#endif
			
		if ( m_pCreature != NULL )
		{
			g_pPCFinder->deleteCreature(m_pCreature->getName());
			{
				// in-progress quests go with the character (KAN-13)
				PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(m_pCreature);
				if ( pPC != NULL && pPC->getGQuestManager() != NULL ) pPC->getGQuestManager()->save();
			}
			m_pCreature->save();
				
			SAFE_DELETE(m_pCreature);
		}

	}
	catch (Throwable& t )
	{
		filelog("GamePlayer::~GamePlayer() : %s", t.toString().c_str());
		
		t.addStack( __PRETTY_FUNCTION__ );
		throw ("GamePlayer::~GamePlayer() : Throwable");
	}

	// ��Ŷ�� �����Ѵ�.
	while (!m_PacketHistory.empty()) 
	{
		Packet* pPacket = m_PacketHistory.front();
		SAFE_DELETE(pPacket);
		m_PacketHistory.pop_front();
	}

	SAFE_DELETE(m_pReconnectPacket);

	//__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH

}


//////////////////////////////////////////////////////////////////////
//
// parse packet and execute handler for the packet
//
//////////////////////////////////////////////////////////////////////

DWORD DiffDWORD(DWORD dwVal1, DWORD dwVal2)
{
	DWORD dwDiff;
	
	if ( dwVal1 > dwVal2 )
	{
		dwDiff = dwVal1 - dwVal2;
	}
	else
	{
		dwDiff = dwVal2 - dwVal1;
	}
	
	return dwDiff;
}

bool GamePlayer::verifyPacketTimeStamp(Packet *pPacket)
{
	Timeval currentTime;
	
	DWORD dwCurTimeStamp;
	DWORD dwServerTime;

	getCurrentTime(currentTime);
	
	if ( m_BasePacketTime.tv_sec == 0 && m_BasePacketTime.tv_usec == 0)
	{
		// ���� �ð� ����
		m_BasePacketTime = 	currentTime;
		m_UpdatePacketTime = currentTime;
	}

	{
		Timeval diffTime;
		diffTime = timediff(m_UpdatePacketTime, currentTime);
		if ( diffTime.tv_sec > 5 * 60 )	// 5�и���  �ð��� ���� 
		{
			// Ŭ���̾�Ʈ�� PC�� Ŭ������ ���� �ð����� ������ �ǹǷ� ���� �ֱ⺰�� ���� �ϵ��� �Ѵ�.
			m_UpdatePacketTime = currentTime;
			m_bCalcPacketDeltaTime = false;
		}
	}
	
	currentTime = timediff(currentTime, m_BasePacketTime);
	dwServerTime = currentTime.tv_sec * 1000 + currentTime.tv_usec / 1000;	// ms ������ ȯ��
	
	if ( m_dwPrevServerTime > dwServerTime )
	{
		// getCurrentTime() ���� ���� �ð� ������ ���������� �����ð��� �����ִ� ��찡 ����.
		dwServerTime = m_dwPrevServerTime;
		
		m_bCalcPacketDeltaTime = false;
	}

	dwCurTimeStamp = pPacket->GetTimeStamp();
	if ( dwCurTimeStamp <  m_dwPrevTimeStamp )
	{
		// TimeStamp�� Overflow �� ���. ���� Ŭ���̾�Ʈ PC�� ������ �� 49���� ���� ���(timeGetTime() �Լ� ����)
		m_bCalcPacketDeltaTime = false;
		
	}
	
	m_dwPrevTimeStamp = pPacket->GetTimeStamp();
	
	if ( m_bCalcPacketDeltaTime )
	{
		// ������ �ʿ��� ��찡 �ִ��� �˻�
		
		if ( dwCurTimeStamp < m_PacketDeltaTime && m_PacketDeltaSign < 0 )
		{
			m_bCalcPacketDeltaTime = false;
		}
		if ( (0xFFFFFFFF - dwCurTimeStamp) < m_PacketDeltaTime && m_PacketDeltaSign > 0 )
		{
			dwCurTimeStamp = (0xFFFFFFFF - dwCurTimeStamp) + m_PacketDeltaTime;
			m_bCalcPacketDeltaTime = false;
		}
	}
	
	if ( !m_bCalcPacketDeltaTime )
	{
		m_PacketDeltaTime = DiffDWORD(dwServerTime, dwCurTimeStamp);
		
		if ( dwServerTime > dwCurTimeStamp )
		{
			m_PacketDeltaSign = 1;
		}
		else
		{
			m_PacketDeltaSign = -1;
		}
		
		m_bCalcPacketDeltaTime = true;
	}

	DWORD dwClientTime;
	DWORD dwDiffTime;
	DWORD dwDiffServerTime;
	DWORD dwDiffClientTime;
		
	// Ŭ���̾�Ʈ ��� �ð�(������ ms)�� ���� �ð� �������� ��ȯ�� �Ѵ�.
	dwClientTime = dwCurTimeStamp + m_PacketDeltaSign * m_PacketDeltaTime;
	
	dwDiffTime = DiffDWORD(dwServerTime, dwClientTime);
	dwDiffServerTime = DiffDWORD(dwServerTime, m_dwPrevServerTime);
	dwDiffClientTime = DiffDWORD(dwClientTime, m_dwPrevClientTime);
	
	// ���ӻ� ������ �������� m_pCreature�� NULL�� �Ǿ� ����
	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(m_pCreature);
	if ( pPC != NULL && pPC->GetParameter<bool>("showTimeStampLog", false) )
	{
		char strBuf[1024];
		sprintf( strBuf, 
			"PacketID=%d, PacketDT=%ld, CurTS=%ld, ST=%ld, DiffST=%ld, CT=%ld, DiffCT=%ld, DT=%c%ld",
			pPacket->getPacketID(),
			m_PacketDeltaSign * m_PacketDeltaTime,
			dwCurTimeStamp,
			dwServerTime,
			dwDiffServerTime,
			dwClientTime,
			dwDiffClientTime,
			dwServerTime > dwClientTime ? '-' : '+',
			dwDiffTime
		);
		
		GCSystemMessage msg;
		msg.setMessage( strBuf );
		
		sendPacket( &msg );
	}
	
	m_dwPrevServerTime = dwServerTime;
	m_dwPrevClientTime = dwClientTime;
	
	pPacket->SetTimeStamp(dwClientTime);
	
	if ( dwServerTime < dwClientTime && dwDiffTime > 10 * 1000 ) 
	{
		IncreaseAbuseActionPoint(100);
		
		// Ŭ���̾�Ʈ �ð��� �������� �ð��� ������,  
		// Ŭ���̾�Ʈ �ð��� ���� �ð����̰� 10�� �̻��̸� ���ۿ� ���� ��Ŷ �������� ����
		
		filelog(
			"AbuseTimeStamp.log", 
			"Too much Difference between Client Time and Server Time. "
			"ID[%s] PacketID=%d, PacketDT=%ld, CurTS=%ld, ST=%ld, DiffST=%ld, CT=%ld, DiffCT=%ld, DT=%ld",
			m_ID.c_str(),
			pPacket->getPacketID(),
			m_PacketDeltaSign * m_PacketDeltaTime,
			dwCurTimeStamp,
			dwServerTime,
			dwDiffServerTime,
			dwClientTime,
			dwDiffClientTime,
			dwDiffTime
		);
		
		m_bCalcPacketDeltaTime = false;
		
		ostringstream strAbuseAction;
		
		strAbuseAction << "(TimeStamp, " 
			<< pPacket->getPacketID() << ", " 
			<< dwServerTime << ", " 
			<< dwClientTime << ", " 
			<< dwDiffTime << ")";
			
//		saveSpeedHackLog(strAbuseAction.str());
		
		return false;
	}
	
	return true;
}

void GamePlayer::processCommand (bool Option) 
     throw (IOException , Error)
{
	__BEGIN_TRY

	sPacketHeader header;
	
	PacketID_t packetID;
	PacketSize_t packetSize;
	Packet* pPacket = NULL;

	try {

		// �г�Ƽ�� �ް� �ִ� ����� �� ��� �� �κп��� ó�� ���ش�.
		// �г�Ƽ�� �޴� ��� � ���� ��Ȳ�� �߻����� �𸣹Ƿ�,
		// �������� ó���� �� �Ѵ��� �г�Ƽ�� ó���ϵ��� �Ѵ�.
		if (isPenaltyFlag(PENALTY_TYPE_KICKED))
		{
			filelog("GamePlayer.txt", "Penalty Kicked. Name[%s],Host[%s],Type[%d] zone=%d pos=(%d,%d)", 
												((getCreature()==NULL)?"NULL":getCreature()->getName().c_str()), 
												((getSocket()==NULL)?"NULL":getSocket()->getHost().c_str()),
												m_ItemRatioBonusPoint,
												(getCreature()==NULL||getCreature()->getZone()==NULL)?-1:(int)getCreature()->getZone()->getZoneID(),
												(getCreature()==NULL)?-1:(int)getCreature()->getX(),
												(getCreature()==NULL)?-1:(int)getCreature()->getY());

			throw DisconnectException("He is had penalty");
		}

		if (Option) 
		{
			m_EventManager.heartbeat();
		}
		
		
		
		// �Է¹��ۿ� ����ִ� ������ ��Ŷ���� ������ ó���Ѵ�.
		while (true) 
		{
			if ( m_EventManager.getEvent( Event::EVENT_CLASS_KICK ) != NULL )
			{
				// ű �̺�Ʈ�� �ɸ�  ���� ������ ��Ŷ�� �����ϵ��� �Ѵ�.
				
				return;
			}
			
			// �Է½�Ʈ������ ��Ŷ���ũ�⸸ŭ �о��.
			// ���� ������ ũ�⸸ŭ ��Ʈ������ ���� �� ���ٸ�,
			// Insufficient ���ܰ� �߻��ϰ�, ������ ����������.
			// NoSuch����. by sigi. 2002.5.4
			// DIAGNOSTIC: strace shows recvfrom() pulling a valid 23-byte
			// CGConnect off the accepted socket, yet Packet.log never records
			// packet id 10 -- so either processCommand() is not running for
			// this player, or peek() cannot see the bytes that were read.
			// Gated on length() so it only fires when data is actually
			// buffered; otherwise this loop would flood the log.
			// DIAGNOSTIC: capture the peek result itself. Note Packet.log's
			// "Recv Packet ID" is inside #ifdef __PACKET_LOG__, which the
			// gameserver Makefile does not define -- so its absence proves
			// nothing about whether packets dispatch. Throttled, because the
			// unthrottled version produced 78k lines in 15 seconds.
			bool dbgPeekOK = m_pInputStream->peek((char *)&header , sizeof(sPacketHeader));
			{
				static int dbgCount = 0;
				if (m_pInputStream->length() > 0 && dbgCount < 20)
				{
					dbgCount++;
					filelog("gpProcessCommand.log",
						"buffered=%d hdrsize=%d peek=%d id=%d size=%d status=%d host=%s",
						(int)m_pInputStream->length(),
						(int)sizeof(sPacketHeader),
						(int)dbgPeekOK,
						(int)header.packetID,
						(int)header.packetSize,
						(int)getPlayerStatus(),
						(getSocket()==NULL ? "NULL" : getSocket()->getHost().c_str()));
				}
			}

			//if (!m_pInputStream->peek(&header[0] , szPacketHeader))
			if (!dbgPeekOK)
			{
				Timeval currentTime;
				getCurrentTime(currentTime);
				if (currentTime >= m_ExpireTime)
				{
					filelog(
						"GamePlayer.txt", 
						"Timeout Disconnect1. Name[%s],Host[%s],ZoneID[%d]", 

						((getCreature()==NULL)?"NULL":getCreature()->getName().c_str()), 
						((getSocket()==NULL)?"NULL":getSocket()->getHost().c_str()),
						((getCreature()==NULL||getCreature()->getZone()==NULL)? -1 : getCreature()->getZone()->getZoneID()) 

					);

					throw DisconnectException("���� �ð����� �Է����� ���� ���, ������ �����մϴ�.");
				}

				break;
			}
			
			// ��Ŷ���̵� �� ��Ŷũ�⸦ �˾Ƴ���.
			// �̶� ��Ŷũ��� ����� �����Ѵ�.
			packetID = header.packetID;
			packetSize = header.packetSize;

			// ��Ŷ ���̵� �̻��ϸ� �������� ������ �����Ѵ�.
			if (packetID >= (int)Packet::PACKET_MAX)
			{
				filelog("GamePlayer.txt", "Packet ID exceed MAX, RECV [%d/%d],ID[%s],Host[%s]", 
					packetID, 
					Packet::PACKET_MAX,
					m_ID.c_str(),
//					getCreature()->getName().c_str(), 
					getSocket()->getHost().c_str());

				throw InvalidProtocolException("too large packet id");
			}

#ifdef __PACKET_LOG__
			filelog("Packet.log", "Recv Packet ID : [%d], ID[%s], Host[%s]", packetID, m_ID.c_str(),getSocket()->getHost().c_str());
			cout << "Recv Packet ID : [" << packetID << "], ID[" << m_ID.c_str() << "], Host[" << getSocket()->getHost().c_str() << "]" << endl;
#endif
			try 
			{
				// ��Ŷ ������ �ùٸ��� �����Ѵ�.
				if (! g_pPacketValidator->isValidPacketID(getPlayerStatus() , packetID))
				{
					filelog("GamePlayer.txt", "Not Valid Packet, RECV [%d],ID[%s],Host[%s]", 
						packetID, 
						m_ID.c_str(),
//						getCreature()->getName().c_str(), 
						getSocket()->getHost().c_str());
					throw InvalidProtocolException("invalid packet order");
				}

				if (!g_pPacketFactoryManager->isCGPacket(packetID))
				{
					   filelog("ErrorPacket.txt", "Not Valid Packet, RECV [%d],ID[%s],Host[%s]",
							   	     packetID, 	m_ID.c_str(),getSocket()->getHost().c_str());					
					      throw InvalidProtocolException("invalid error packet");
				}
			
				// ��Ŷ ũ�Ⱑ �ʹ� ũ�� �������� ������ �����Ѵ�.
				if (packetSize > g_pPacketFactoryManager->getPacketMaxSize(packetID))
				{
					filelog("GamePlayer.txt", "Too Larget Packet Size, RECV [%d],PacketSize[%d/%d],ID[%s],Host[%s]", 
						packetID, packetSize, g_pPacketFactoryManager->getPacketMaxSize(packetID),
						m_ID.c_str(),
//						getCreature()->getName().c_str(), 
						getSocket()->getHost().c_str());
					throw InvalidProtocolException("too large packet size");
				}
			
				// �Է¹��۳��� ��Ŷũ�⸸ŭ�� ����Ÿ�� ����ִ��� Ȯ���Ѵ�.
				// ����ȭ�� break �� ����ϸ� �ȴ�. (���⼭�� �ϴ� exception�� �� ���̴�.)
				//if (m_pInputStream->length() < szPacketHeader + packetSize)
				// No sizeof(DWORD) timestamp term: nothing writes a per-packet
				// timestamp (readTimeStamp() was removed for exactly that
				// reason), so demanding those 4 extra bytes meant a complete
				// 23-byte CGConnect looked incomplete against a required 27 and
				// this loop spun forever without ever consuming it.
				if (m_pInputStream->length() < sizeof(sPacketHeader) + packetSize)
					//throw InsufficientDataException();
					break;

				// ��Ŷ �ϳ��� �о�����, expire time �� �����Ѵ�.
				getCurrentTime(m_ExpireTime);
				m_ExpireTime.tv_sec += maxIdleSec;
			
				// ������� �Դٸ� �Է¹��ۿ��� ������ ��Ŷ �ϳ� �̻��� ����ִٴ� ���̴�.
				// ��Ŷ���丮�Ŵ����κ��� ��Ŷ���̵� ����ؼ� ��Ŷ ��Ʈ��ó�� �����ϸ� �ȴ�.
				// ��Ŷ���̵� �߸��� ���� ��Ŷ���丮�Ŵ������� ó���Ѵ�.
				pPacket = g_pPacketFactoryManager->createPacket(packetID);

				const uint lenBeforeRead = m_pInputStream->length();
				m_pInputStream->skip( szPacketHeader );
				// readTimeStamp() ���� -- LoginPlayer.cpp �� ���� ����.
				// Ŭ���̾�Ʈ�� Ÿ�ӽ������� ���� �ʴµ� 4����Ʈ�� �о
				// ��Ŷ ��� ��ġ�� �ױ� ���ߴ� ���̴�.
				//pPacket->readTimeStamp(*m_pInputStream);
				
				// ���� �� ��Ŷ��Ʈ��ó�� �ʱ�ȭ�Ѵ�.
				// ��Ŷ����Ŭ������ ���ǵ� read()�� virtual ��Ŀ���� ���ؼ� ȣ��Ǿ�
				// �ڵ������� �ʱ�ȭ�ȴ�.
				m_pInputStream->readPacket(pPacket, false);

				// A CG packet must consume exactly as many bytes as its header
				// declared. When it doesn't, the rest of this stream is garbage and
				// the player gets logged out with nothing explaining why. That is
				// what CGAddMouseToGear did: the client compiles m_GearSlotID out
				// under __CONTENTS(__GEAR_SWAP_CHANGE) and sends 5 bytes, while this
				// side read 7. A field-name audit cannot see that, so check it here.
				const uint consumed = lenBeforeRead - m_pInputStream->length();
				const uint expected = szPacketHeader + packetSize;

				if ( consumed != expected )
				{
					filelog("PacketSizeMismatch.log",
						"RECV id %d declared %u but read %u : ID[%s] Host[%s]",
						packetID, expected - (uint)szPacketHeader, consumed - (uint)szPacketHeader,
						m_ID.c_str(), (getSocket()==NULL ? "NULL" : getSocket()->getHost().c_str()));
					cout << "[PacketSizeMismatch] RECV id " << packetID << " declared " << packetSize
					     << " but read " << (consumed - (uint)szPacketHeader) << endl;

					if ( consumed < expected )
					{
						// Under-read: the remainder is still buffered, so step over it
						// and keep the session alive instead of desyncing everything
						// that follows.
						m_pInputStream->skip( expected - consumed );
					}
				}

				if ( GetAbuseActionPoint() > g_pVariableManager->getSkillSpeedMaxAbuseActionPoint() )
				{
					if ( g_pVariableManager->isSkillSpeedDisconnectAbuseAction() )
					{
						if ( m_EventManager.getEvent( Event::EVENT_CLASS_KICK ) == NULL )
						{
							string strAbuseAction;
							
							strAbuseAction = "(Kicked)";
//							saveSpeedHackLog(strAbuseAction, false);
							
							// ���������� �����÷��̰� ����ȸ���� �ʰ��Ͽ� ���õ� ��� ���� ���� ��Ų��.
							kickPlayer(3, KICK_MESSAGE_ABUSE_ACTION );
							
							return;
						}
					}
				}
				
				if ( !verifyPacketTimeStamp(pPacket) ) 
				{
					// TimeStamp �������� �ǽɵǴ� ��Ŷ�� ��� �����Ѵ�.
					
					return;
				}
				
/*				if ( m_PacketHistory.size() > 0 )
				{
					Packet* prevPacket = m_PacketHistory.back();
					if ( prevPacket->getPacketID() == Packet::PACKET_CG_READY )
					{
						switch( pPacket->getPacketID())
						{
							case Packet::PACKET_CG_READY :
							case Packet::PACKET_CG_SET_SLAYER_HOT_KEY :
							case Packet::PACKET_CG_SET_VAMPIRE_HOT_KEY :
							{
								filelog("CGReadyPacketDup.log", "PacketID=%d, PlayerID=%s, IP=%s", 
									pPacket->getPacketID(),	
									m_ID.c_str(), 
									getSocket()->getHost().c_str()
								);
	
								continue;
							}
						}
					}
				}*/

				// ���� ��Ŷ�� ��Ŷ �����丮�� �� �ڿ� �ִ´�.
				m_PacketHistory.push_back(pPacket);

				// packet file log�� �����.
				if ( m_bPacketLog )
				{
					Timeval currentTime;
					getCurrentTime( currentTime );

					if ( currentTime >= m_PacketLogEndTime )
					{
						m_bPacketLog = false;
					}
					else
					{
						filelog( m_PacketLogFileName.c_str(), "%s", pPacket->toString().c_str() );
					}
				}

				if ( m_pCreature != NULL)
				{
					PlayerCreature *pPC = dynamic_cast<PlayerCreature *>(m_pCreature);
					
					if ( pPC->GetTalkingCallNPC() != NULL )
					{
						switch( packetID )
						{
							case Packet::PACKET_CG_READY :
							//case Packet::PACKET_CG_MOVE :
							case Packet::PACKET_CG_NPC_TALK :
							case Packet::PACKET_CG_TRADE_PREPARE :
							case Packet::PACKET_CG_TRADE_FINISH :
								{
									PlayerCreature *pPC = dynamic_cast<PlayerCreature *>(m_pCreature);
									pPC->FinishToTalkWithCallNPC();
								}
								break;
							default :
								break;
						}
					}
				}
				
				//cout << "[" << (int)Thread::self() << "] execute before : " << pPacket->getPacketName().c_str() << endl;

				if ( m_pCreature != NULL && m_pCreature->isFlag(Effect::EFFECT_CLASS_HAS_BLOOD_BIBLE) )
				{
					filelog( "TraceBloodBible.log", "ID=%s Name=%s ZoneID=%d X=%d Y=%d Packet=%s", 
						m_ID.c_str(),
						getCreature()->getName().c_str(),
						getCreature()->getZone()->getZoneID(),
						getCreature()->getX(),
						getCreature()->getY(),
						pPacket->toString().c_str()
					);
				}
				
				// ���� �� ��Ŷ��Ʈ��ó�� ������ ��Ŷ�ڵ鷯�� �����ϸ� �ȴ�.
				// ��Ŷ���̵� �߸��� ���� ��Ŷ�ڵ鷯�Ŵ������� ó���Ѵ�.
				try
				{
				#ifdef __PROFILE_PACKETS__
					
					beginProfileEx(	pPacket->getPacketName().c_str() );
					pPacket->execute(this);
					endProfileEx( pPacket->getPacketName().c_str() );

				#else
					pPacket->execute(this);
				#endif
				} catch ( Throwable& t )
				{
					filelog( "GPPC.txt", "%s PacketID : %d", t.toString().c_str(), packetID );
					throw;
				}
				
				if ( !checkToRecvVerifyTime() )
				{
					// ���������� CGVerifyTime �� ���ŵǰ� ���� ����
					saveSpeedHackPlayer();
					
					throw DisconnectException("Abnormal Sending CGVerifyTime packet.");
				}

				//cout << "[" << (int)Thread::self() << "] execute after : " << pPacket->getPacketName().c_str() << endl;

				// ��Ŷ�� nPacketHistorySize ����ŭ�� �����Ѵ�.
				while (m_PacketHistory.size() > nPacketHistorySize) 
				{
					Packet* oldPacket = m_PacketHistory.front();
					SAFE_DELETE(oldPacket);
					m_PacketHistory.pop_front();
				}
			} 
			catch (IgnorePacketException & igpe) 
			{
				// PacketValidator ���� ��Ŷ�� �����϶�� ������,
				// �Է½�Ʈ������ ��� ���������� �������� �ʵ��� �Ѵ�.

				// ��Ŷ ũ�Ⱑ �ʹ� ũ�� �������� ������ �����Ѵ�.
				if (packetSize > g_pPacketFactoryManager->getPacketMaxSize(packetID))
				{
					filelog("GamePlayer.txt", "Too Larget Packet Size[Ignore], RECV [%d],PacketSize[%d],Name[%s],Host[%s]", 
																packetID, packetSize,
																((getCreature()==NULL)?"NULL":getCreature()->getName().c_str()), 
																((getSocket()==NULL)?"NULL":getSocket()->getHost().c_str()));
					throw InvalidProtocolException("too large packet sizeIgnore");
				}
			
				// �Է¹��۳��� ��Ŷũ�⸸ŭ�� ����Ÿ�� ����ִ��� Ȯ���Ѵ�.
				// ����ȭ�� break �� ����ϸ� �ȴ�. (���⼭�� �ϴ� exception�� �� ���̴�.)
				//if (m_pInputStream->length() < szPacketHeader + packetSize)
				// No sizeof(DWORD) timestamp term: nothing writes a per-packet
				// timestamp (readTimeStamp() was removed for exactly that
				// reason), so demanding those 4 extra bytes meant a complete
				// 23-byte CGConnect looked incomplete against a required 27 and
				// this loop spun forever without ever consuming it.
				if (m_pInputStream->length() < sizeof(sPacketHeader) + packetSize)
					throw InsufficientDataException();

				// ����Ÿ�� ��� ����������, �� ũ�⸸ŭ �����ϰ�,
				// �ٸ� ��Ŷ�� ó���ϵ��� �Ѵ�....
				//m_pInputStream->skip(szPacketHeader + packetSize);
				m_pInputStream->skip(
					sizeof(sPacketHeader) + 	// Packet Header
					packetSize					// Packet Body
				);	// no TimeStamp term -- it is not on the wire

				// ���õ� ��Ŷ��, expire �� ������ ���� �ʰ� �ȴ�.
				// �� ��ȿ�� ��Ŷ���� ©���� �ʰ� ���ش�.
				// ���� �����丮���� ���� �ʴ´�.
			}
		}
	} 
	catch (InsufficientDataException & ide) 
	{
		// expire time �� �ʰ����� ��� ������ �����Ѵ�.
		Timeval currentTime;
		getCurrentTime(currentTime);
		if (currentTime >= m_ExpireTime)
		{
			filelog("GamePlayer.txt", "Timeout Diconnect. Name[%s],Host[%s]", 
												((getCreature()==NULL)?"NULL":getCreature()->getName().c_str()), 
												((getSocket()==NULL)?"NULL":getSocket()->getHost().c_str()));

			throw DisconnectException("���� �ð����� �Է����� ���� ���, ������ �����մϴ�.");
		}
	}
	// �ּ�ó�� by sigi. 2002.5.14
	/*
	catch (InvalidProtocolException & ipe) 
	{
		// ������ ����������Ѿ� �Ѵ�. ���� �������??
		throw;
	} 
	catch (Throwable & t) 
	{
		//cerr << t.toString() << endl;
		//cerr << "GamePlayer Throwable Exception Check!" << endl;
		throw;
	}
	*/

	__END_CATCH
}
		    

//////////////////////////////////////////////////////////////////////
//
// flush output buffer to socket's send buffer
//
// flush�� ���� �ٸ� �����忡�� ��� ���ۿ� sendPacket�� ȣ���ؼ��� �ȵȴ�.
// (�̷� ���� ������ ������� say�� ���ƿ��� �͹ۿ� ����.)
//
//////////////////////////////////////////////////////////////////////
void GamePlayer::processOutput () 
     throw (IOException , Error)
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex)

	int i = 0;
		
	try 
	{
		Player::processOutput();

		i = 100000;
	} 
	catch (InvalidProtocolException & It) 
	{
		//cerr << "GamePlayer::processOutput Exception Check!!" << endl;
		//cerr << It.toString() << endl;
		//cerr << "�ͼ��� ���µ�...... ���̴� ���ΰ�?" << (int)i << endl;
		throw DisconnectException("Pipe ������ �ı��� ������ ¥����");
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
//
// send packet to player's output buffer
//
//////////////////////////////////////////////////////////////////////
void GamePlayer::sendPacket (Packet* pPacket) 
	 throw (ProtocolException , Error)
{	
	__BEGIN_TRY
	
	__ENTER_CRITICAL_SECTION(m_Mutex)

	try 
	{
		// packet file log�� �����.
		if ( m_bPacketLog )
		{
			Timeval currentTime;
			getCurrentTime( currentTime );

			if ( currentTime >= m_PacketLogEndTime )
			{
				m_bPacketLog = false;
			}
			else
			{
				filelog( m_PacketLogFileName.c_str(), "%s", pPacket->toString().c_str() );
			}
		}

		Player::sendPacket(pPacket);

#ifdef __PACKET_LOG__
        filelog("Packet.log", "Send Packet ID : [%d], ID[%s], Host[%s]", pPacket->getPacketID(), m_ID.c_str(),getSocket()->getHost().c_str());
        cout << "Send Packet ID : [" << pPacket->getPacketID() << "], ID[" << m_ID.c_str() << "], Host[" << getSocket()->getHost().c_str() << "]" << endl;
#endif

		//cout << "GamePlayer::sendPacket() : " << pPacket->toString() << endl;
		//cout << "GamePlayer::sendPacket() PACKET SIZE : " << pPacket->getPacketSize() << endl;

		/*
		if (getCreature() != NULL)
		{
			PacketID_t packetID = pPacket->getPacketID();
			switch (packetID)
			{
				case Packet::PACKET_GC_UPDATE_INFO:
				case Packet::PACKET_GC_MOVE_OK:
				case Packet::PACKET_GC_SET_POSITION:
					filelog("GamePlayer.txt", "SEND [%s],Name[%s],Host[%s]", 
							pPacket->getPacketName().c_str(), 
							getCreature()->getName().c_str(), 
							getSocket()->getHost().c_str());
					break;
				default:
					break;
			}
		}
		else
		{
			PacketID_t packetID = pPacket->getPacketID();
			switch (packetID)
			{
				case Packet::PACKET_GC_UPDATE_INFO:
				case Packet::PACKET_GC_MOVE_OK:
				case Packet::PACKET_GC_SET_POSITION:
					filelog("GamePlayer.txt", "SEND [%s],Name[NULL],Host[%s]", 
							pPacket->getPacketName().c_str(), 
							getSocket()->getHost().c_str());
					break;
				default:
					break;
			}
		}
		*/
	} 
	catch (InvalidProtocolException & It) 
	{
		//cout << "GamePlayer::sendPacket Exception Check!!" << endl;
		//cout << It.toString() << endl;
		//throw DisconnectException("Pipe ������ �ı��� ������ ¥����");
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH
}


//--------------------------------------------------------------------------------
//
// disconnect player
//
// (1) ũ��ó�� ������ ���, ������ �����ϰ� ��ε�ĳ��Ʈ�Ѵ�.
// (2) ũ��ó�� �����Ѵ�.
//
//--------------------------------------------------------------------------------
void GamePlayer::disconnect (bool bDisconnected)
	throw (InvalidProtocolException, Error)
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex)
	
	#ifdef __NETMARBLE_SERVER__
	///< �� ���� �����̸�
	Netmb_LogoutLog();
	#endif

	//--------------------------------------------------------------------------------
	// ũ��ó�� ������ ������ ��, �ֺ��� PC�鿡�� ��ε�ĳ��Ʈ���ش�.
	// �״��� ũ��ó�� DB�� �����Ѵ�.
	//--------------------------------------------------------------------------------
	string CreatureName = "";
	if (m_pCreature != NULL) 
	{
		CreatureName = m_pCreature->getName();

		try 
		{
			// GPS_NORMAL �� ��쿡��, ���� ũ��ó�� �� �ְ� �ȴ�.
			// *CAUTION*
			// Ȥ�� pushPC()�� ȣ��� �Ŀ� ������ ����Ǹ� ��� �ϳ�.. ��� ������ ���ɼ��� �ִ�.
			// �׷���, ó�� ��ƾ�� ������ �� ���캸�� �׷� ������ �� �ʿ䰡 ����.
			// ������ ������ �������, ���� ó���� �� ũ��ó�� ���� Ÿ�Ϸ� �ö� ����,
			// �ٽ� �÷��̾��� ó�������� ���ƿ��� �����̴�.
			if (getPlayerStatus() == GPS_NORMAL) 
			{
				//----------------------------------
				// ������ �����ϰ� ��ε�ĳ��Ʈ�Ѵ�.
				//----------------------------------
				Zone* pZone = m_pCreature->getZone();
				Assert(pZone != NULL);
				pZone->deleteQueuePC(m_pCreature);
				pZone->deleteCreature(m_pCreature , m_pCreature->getX() , m_pCreature->getY());
				{
					// in-progress quests go with the character (KAN-13)
					PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(m_pCreature);
					if ( pPC != NULL && pPC->getGQuestManager() != NULL ) pPC->getGQuestManager()->save();
				}
				//--------------------------------------------------------------------------------
				// ũ��ó�� �����Ѵ�.
				//--------------------------------------------------------------------------------
				m_pCreature->save();
			} 
		} 
		catch (Throwable & t) 
		{
		}
	}

	setPlayerStatus(GPS_END_SESSION);

	//--------------------------------------------------------------------------------
    // ���̵� �����Ǿ��ٴ� ����, �α����� �̷�����ٴ� ���̴�.
	//--------------------------------------------------------------------------------
    if (m_ID != "")
    {
        Statement* pStmt1 = NULL;
        Statement* pStmt2 = NULL;

		BEGIN_DB
		{

//            pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
            // �α׿����� �����Ѵ�.
	      	//pStmt1 = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			pStmt1 = g_pDatabaseManager->getDistConnection( "PLAYER_DB" )->createStatement();

			// LogOn�� GAME������ ��츸 LOGOFF�� �ٲ۴�. by sigi. 2002.5.15
            pStmt1->executeQuery("UPDATE Player SET LogOn='LOGOFF', LastLogoutDate=now() WHERE PlayerID = '%s' AND LogOn='GAME'" , m_ID.c_str());

			// LogoutPlayerData �� �߰��Ѵ�.
		//	addLogoutPlayerData(this);
            


			if (pStmt1->getAffectedRowCount()==0)
			{
				// �̹� LOGOFF�ų�
				// LOGON�����ΰ�?
				// �̷� �� ������? -_-;
			}

			// ���� by sigi. 2002.5.31
#if defined(__PAY_SYSTEM_LOGIN__) || defined(__PAY_SYSTEM_ZONE__) || defined(__PAY_SYSTEM_FREE_LIMIT__)
			if (isPayPlaying() || isPremiumPlay())
			{
				logoutPayPlay( m_ID );
			}
#endif


			SAFE_DELETE(pStmt1);

		}
		END_DB(pStmt1)
		
		
		BEGIN_DB
        {

			// IP ������ ������ �ش�.
            pStmt2 = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
            pStmt2->executeQuery("DELETE FROM UserIPInfo WHERE Name = '%s'", CreatureName.c_str());

			SAFE_DELETE(pStmt2);
        }
		END_DB(pStmt2)
    }

	// login������ ����� client���� ������.
	// ������ LGIncomingConnectionOKHandler���� ó���ߴ�. by sigi. 2002.6.19
	if (m_pReconnectPacket!=NULL)
	{
		//cout << "[SendReconnect] " << m_pReconnectPacket->toString().c_str() << endl;

		try 
		{
			//sendPacket( m_pReconnectPacket );
			Player::sendPacket( m_pReconnectPacket );
			// ��� ���ۿ� �����ִ� ����Ÿ�� �����Ѵ�.
			m_pOutputStream->flush();
		} 
		catch (Throwable & t) 
		{
			// ����
		}
		
		SAFE_DELETE(m_pReconnectPacket);
	}


	// �Լ� ���κп��� ó���ߴµ�.. Ÿ�̹� ����(LogOn�̳� UserIPInfo ��)��
	// ���⼭ �����ְ�.. ������Ŷ~�� �������� �Ѵ�.
	if (bDisconnected == UNDISCONNECTED) 
	{
		try 
		{
			// Ŭ���̾�Ʈ���� GCDisconnect ��Ŷ�� �����Ѵ�.
			//GCDisconnect gcDisconnect;
			//sendPacket(gcDisconnect);

			// ��� ���ۿ� �����ִ� ����Ÿ�� �����Ѵ�.
			m_pOutputStream->flush();
		} 
		catch (Throwable & t) 
		{
			//cerr << "GamePlayer::disconnect() : GamePlayer::disconnect Exception Check!!" << endl;
			//cerr << t.toString() << endl;
		}
	}

	// ���� ������ �ݴ´�.
	m_pSocket->close();

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
//
// �ֱ� N ��°�� ��Ŷ�� �����Ѵ�.
// 
// N == 0 �� ���, ���� �ֱ��� ��Ŷ�� �����ϰ� �ȴ�.
//
// �ִ� nPacketHistorySize - 1 ���� ������ �� �ִ�. 
//
//////////////////////////////////////////////////////////////////////
Packet* GamePlayer::getOldPacket (uint prev)
	throw (OutOfBoundException , NoSuchElementException)
{
	__BEGIN_TRY

	if (prev >= nPacketHistorySize)
		throw OutOfBoundException();

	// if prev == 0 , return m_PacketHistory[9]
	// if prev == 9 , return m_PacketHistory[0]
	Packet* pPacket = m_PacketHistory[ nPacketHistorySize - prev - 1 ];

	if (pPacket == NULL)
		throw NoSuchElementException("packet history is empty");

	return pPacket;

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
//
// Ư�� ��Ŷ���̵� ���� ���� �ֱ��� ��Ŷ�� �����Ѵ�.
//
//////////////////////////////////////////////////////////////////////
Packet* GamePlayer::getOldPacket (PacketID_t packetID)
	throw (NoSuchElementException)
{
	__BEGIN_TRY

	Packet* pPacket = NULL;
	deque<Packet*>::reverse_iterator ritr = m_PacketHistory.rbegin();

	for (; ritr != m_PacketHistory.rend(); ritr++) 
	{
		if ((*ritr)->getPacketID() == packetID) {
			pPacket = (*ritr);
			break;
		}	
	}

	if (pPacket == NULL)
		throw NoSuchElementException("packet history is empty");

	return pPacket;

	__END_CATCH
}

//--------------------------------------------------------------------------------
//
//--------------------------------------------------------------------------------
void GamePlayer::addEvent (Event* pEvent)
	throw (Error)
{
	__BEGIN_TRY

	m_EventManager.addEvent(pEvent);

	__END_CATCH
}

//--------------------------------------------------------------------------------
//
//--------------------------------------------------------------------------------
void GamePlayer::deleteEvent (Event::EventClass EClass)
	throw (Error)
{
	__BEGIN_TRY

	m_EventManager.deleteEvent(EClass);

	__END_CATCH
}

//--------------------------------------------------------------------------------
//
//--------------------------------------------------------------------------------
Event* GamePlayer::getEvent (Event::EventClass EClass)
	throw (Error)
{
	__BEGIN_TRY

	return m_EventManager.getEvent(EClass);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////
//
// get debug string
//
//////////////////////////////////////////////////////////////////////
string GamePlayer::toString () const
       throw (Error)
{
	__BEGIN_TRY
		
	StringStream msg;
	
	//////////////////////////////////////////////////
	// enter critical section
	//////////////////////////////////////////////////
	__ENTER_CRITICAL_SECTION(m_Mutex)
	
	msg << "GamePlayer(SocketID:" << m_pSocket->getSOCKET() << ",Host:" << m_pSocket->getHost() << ")" ;

	//////////////////////////////////////////////////
	// leave critical section
	//////////////////////////////////////////////////
	__LEAVE_CRITICAL_SECTION(m_Mutex)
	
	return msg.toString();

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////
//
// verifySpeed
//
//////////////////////////////////////////////////////////////////////
bool GamePlayer::verifySpeed(Packet* pPacket)
	throw (Error)
{
	__BEGIN_TRY

	bool SpeedCheck = false;

	Timeval CurrentTime;
	getCurrentTime( CurrentTime );

	if( m_SpeedVerify.tv_sec == 0 )
	{
//		getCurrentTime( m_SpeedVerify );
//		m_SpeedVerify.tv_sec += SpeedCheckDelay;
		// m_SpeedVerify �� ���� �ð����� ���� �޾ƿ� �ʿ����
		// �Լ� ù �κп��� �޾� ���� �� �� ����.
		// 2002.1.7 by bezz
		m_SpeedVerify.tv_sec = CurrentTime.tv_sec + SpeedCheckDelay;

		SpeedCheck = true;
	}
	else
	{
		// ���� ���ƿ;ߵ� ���� �ð����� 5�� ���� ���ƿ��� ���ǵ����̴�.
		if( CurrentTime.tv_sec > m_SpeedVerify.tv_sec - maxTimeGap )
		{
			// ���ǵ� �� ����� �ߴٸ� ���� ���ƿ� ���� �ð��� ���� �ؾ� �Ѵ�.
//			getCurrentTime( m_SpeedVerify );
//			m_SpeedVerify.tv_sec += SpeedCheckDelay;
			// m_SpeedVerify �� ���� �ð����� ���� �޾ƿ� �ʿ����
			// �Լ� ù �κп��� �޾� ���� �� �� ����.
			// 2002.1.7 by bezz
			m_SpeedVerify.tv_sec = CurrentTime.tv_sec + SpeedCheckDelay;

			SpeedCheck = true;
			m_VerifyCount = max(0, m_VerifyCount-1);
			
			m_NumOfNotRecvVerifyTime = 0;
		}
		else
		{
//			getCurrentTime( m_SpeedVerify );
//			m_SpeedVerify.tv_sec += SpeedCheckDelay;
			// m_SpeedVerify �� ���� �ð����� ���� �޾ƿ� �ʿ����
			// �Լ� ù �κп��� �޾� ���� �� �� ����.
			// 2002.1.7 by bezz
			m_SpeedVerify.tv_sec = CurrentTime.tv_sec + SpeedCheckDelay;

			if( m_VerifyCount > maxVerifyCount )
			{
				SpeedCheck = false;
			}
			else
			{
				SpeedCheck = true;
			}
			m_VerifyCount++;
		}
	}
	
	if ( !SpeedCheck )
	{
		ostringstream strAbuseAction;
		
		strAbuseAction << "(FastSendPacket, " 
			<< (int)m_VerifyCount << ", " 
			<< (int)m_NumOfNotRecvVerifyTime << ")";
			
//		saveSpeedHackLog(strAbuseAction.str());
	}

	return SpeedCheck;

	__END_CATCH
}

bool GamePlayer::checkToRecvVerifyTime()
{
	Timeval CurrentTime;
	getCurrentTime( CurrentTime );
	
	if ( m_SpeedVerify.tv_sec == 0 )
	{
		m_SpeedVerify = CurrentTime;
	}
	
	if ( CurrentTime.tv_sec - m_SpeedVerify.tv_sec > maxVerifyTimeSilenceSec )
	{
		// ���� ���۵� �Ͱ� ������ 3 sec �̻���. ��, Ŭ���̾�Ʈ��  CGVerifyTime �� �������� �ʰ� ���� 
		
		++m_NumOfNotRecvVerifyTime;
		
		m_SpeedVerify = CurrentTime;
	}
	
	if ( m_NumOfNotRecvVerifyTime > 3 )
	{
		// ���������� CGVerifyTime�� �������� �ʴ´ٰ� ���� 3ȸ �̻� �Ǵ�
		return false;
	}
	
	// ���������� ���۵Ǿ� ���� ����
	return true;
		 	
}

void GamePlayer::loadSpecialEventCount(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL;
	Result*    pResult = NULL;

	BEGIN_DB
	{
//		pStmt   = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pStmt   = g_pDatabaseManager->getDistConnection( "PLAYER_DB" )->createStatement();

		pResult = pStmt->executeQuery("SELECT SpecialEventCount FROM Player WHERE PlayerID='%s'", m_ID.c_str());

		if (pResult->getRowCount() != 0)
		{
			pResult->next();
			m_SpecialEventCount = pResult->getDWORD(1);
		}
		else
		{
			SAFE_DELETE(pStmt);
			throw ("GamePlayer::loadSpecialEventCount() : unable to dispatch data");
			return;
		}

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt);

	__END_CATCH
}

void GamePlayer::saveSpecialEventCount(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getDistConnection("PLAYER_DB")->createStatement();
//		pStmt = g_pDatabaseManager->getConnection( (int)Thread::self() )->createStatement();

		pStmt->executeQuery("UPDATE Player SET SpecialEventCount=%d WHERE PlayerID='%s'", m_SpecialEventCount, m_ID.c_str());
		SAFE_DELETE(pStmt);	
	}
	END_DB(pStmt);

	__END_CATCH
}

bool    GamePlayer::sendBillingLogin() 
	throw (Error)
{
	__BEGIN_TRY

	if (!m_ID.empty() && m_ID!="NONE")
	{
		Timeval currentTime;
		getCurrentTime(currentTime);

		if (currentTime > m_BillingNextLoginRequestTime)
		{
			g_pBillingPlayerManager->sendPayLogin( this );

			Timeval afterTime;
			getCurrentTime( afterTime );

			// 1�� �̻� �ɸ��� �α� �����.
			if ( afterTime.tv_sec > currentTime.tv_sec + 1 )
			{
				filelog( "billingLoginTime.txt", "PlayerID : %s, CallTime : %d sec, Try : %d", m_ID.c_str(), (int)(afterTime.tv_sec - currentTime.tv_sec), m_BillingLoginRequestCount );
			}

			// PayLogin ��û�� ȸ�� ���
			m_BillingLoginRequestCount ++;

			// 60�� �� �ٽ� üũ�Ѵ�.
			m_BillingNextLoginRequestTime.tv_sec = currentTime.tv_sec + 60;
		}

		return true;
	}

	return false;

	__END_CATCH
}

void GamePlayer::sendCBillingPayInfo()
	throw ( Error )
{
	__BEGIN_TRY

	char m[200];
	if ( m_CBPlayerType == CBILLING_PLAYER_TYPE_MONTHLY )
	{
		VSDate currentDate;
		currentDate = VSDate::currentDate();

		sprintf( m, g_pStringPool->c_str( STRID_CB_MONTHLY_PLAYER ),
						m_CBEndDateTime.date().year(),
						m_CBEndDateTime.date().month(),
						m_CBEndDateTime.date().day(),
						currentDate.year(),
						currentDate.month(),
						currentDate.day() );

		GCSystemMessage msg;
		msg.setMessage( m );

		sendPacket( &msg );
	}
	else if ( m_CBPlayerType == CBILLING_PLAYER_TYPE_POINT )
	{
		sprintf( m, g_pStringPool->c_str( STRID_CB_POINT_PLAYER ), m_CBLeftTime / 10 );

		GCSystemMessage msg;
		msg.setMessage( m );

		sendPacket( &msg );
	}

	__END_CATCH
}

// ��ȣȭ �ڵ带 �����Ѵ�.
void GamePlayer::setEncryptCode()
    throw (Error)
{
    __BEGIN_TRY

#ifdef __USE_ENCRYPTER__
	Assert(m_pCreature!=NULL);

	// �ϴ��� ObjectID�� �̿��Ѵ�.
	//ObjectID_t 	objectID 	= m_pCreature->getObjectID();

	// ������ ������ �ϵ��� �����Ѵ�.
//	ZoneID_t 	zoneID 		= m_pCreature->getZone()->getZoneID();
//	static int	serverID	= g_pConfig->getPropertyInt("ServerID");

//	if (objectID!=0)
//	{
		//uchar code = (uchar)(objectID / zoneID + objectID);
		//uchar code = (uchar)( ( ( zoneID >> 8 ) ^ zoneID ) ^ ( ( serverID + 1 ) << 4 ) );
		uchar code = m_pCreature->getZone()->getEncryptCode();

#ifdef __ACTIVE_SERVICE_DEADLINE__
		// ���� �ٺ� ����� �ڵ�
		VSDate date = VSDate::currentDate();
		// 2003�� 1�� �̻��� ���: 2003, 0
		if (date.year()>=DEADLINE_YEAR && date.month()>DEADLINE_MONTH)
			code += (date.year()+date.month())/11;
#endif

		SocketEncryptOutputStream* pEOS = dynamic_cast<SocketEncryptOutputStream*>(m_pOutputStream);
		SocketEncryptInputStream* pEIS = dynamic_cast<SocketEncryptInputStream*>(m_pInputStream);

		//----------------------------------------------------------------------
		// Nothing to key when the streams are not encrypting.
		//
		// GamePlayer now builds plain SocketInputStream/SocketOutputStream to
		// match a client compiled with __CRYPT __OFF, so both casts return NULL
		// and the old Assert(pEOS!=NULL) fired on every connect -- which after
		// the catch-all in IncomingPlayerManager shows up as an AssertionError
		// that disconnects the player. There is no cipher to configure here.
		//----------------------------------------------------------------------
		if (pEOS == NULL || pEIS == NULL)
			return;

		pEOS->setEncryptCode(code);
		pEIS->setEncryptCode(code);
//	}
#endif

	__END_CATCH
}

void GamePlayer::kickPlayer( uint nSeconds, uint KickMessageType )
	throw (Error)
{
	__BEGIN_TRY

	// �̹� EventKick �� �ִٸ� �����Ѵ�.
	if ( m_EventManager.getEvent( Event::EVENT_CLASS_KICK ) != NULL )
		return;

	EventKick* pEventKick = new EventKick( this );
	pEventKick->setDeadline( nSeconds * 10 );
	addEvent( pEventKick );

	// �� ���Ŀ� ©����..�� �����ش�.
	GCKickMessage gcKickMessage;
	gcKickMessage.setType( KickMessageType );
	gcKickMessage.setSeconds( nSeconds );
	sendPacket( &gcKickMessage );

	__END_CATCH
}

//////////////////////////////////////////////////////////////////
// PaySystem ����
//////////////////////////////////////////////////////////////////
bool GamePlayer::loginPayPlay( PayType payType, const string& PayPlayDate, int PayPlayHours, uint payPlayFlag, const string& ip, const string& playerID )
	throw (Error)
{
	__BEGIN_TRY
#ifdef __CONNECT_BILLING_SYSTEM__
	return BillingPlayerInfo::isBillingPlayAvaiable();
#else
//	return PaySystem::loginPayPlay( payType, PayPlayDate, PayPlayHours, payPlayFlag, ip, playerID );
	return PaySystem::CheckPayFunction(ip, playerID );
#endif
	__END_CATCH
}

bool GamePlayer::loginPayPlay( const string& ip, const string& playerID )
    throw (Error)
{
	__BEGIN_TRY
#ifdef __CONNECT_BILLING_SYSTEM__
	return BillingPlayerInfo::isBillingPlayAvaiable();
#else
//	bool bRet = PaySystem::loginPayPlay( ip, playerID );
	bool bRet = PaySystem::CheckPayFunction( ip, playerID );

	if ( bRet )
		setPCRoomLottoStartTime();

	return bRet;
#endif
	__END_CATCH
}

bool GamePlayer::updatePayPlayTime( const string& playerID, const VSDateTime& currentDateTime, const Timeval& currentTime )
    throw ( ProtocolException, Error )
{
	__BEGIN_TRY
#ifdef __CONNECT_BILLING_SYSTEM__
	return BillingPlayerInfo::isBillingPlayAvaiable();
#else
	checkPCRoomLotto( currentTime );

	return PaySystem::updatePayPlayTime( playerID, currentDateTime, currentTime );
#endif
	__END_CATCH
}

void GamePlayer::logoutPayPlay( const string& playerID, bool bClear, bool bDecreaseTime )
    throw (Error)
{
	__BEGIN_TRY
#ifdef __CONNECT_BILLING_SYSTEM__
	if ( !BillingPlayerInfo::isBillingPlayAvaiable() )
		setPremiumPlay( false );
#else
	savePCRoomLottoTime();

	PaySystem::logoutPayPlay( playerID, bClear, bDecreaseTime );
#endif
	__END_CATCH
}

bool GamePlayer::isPayPlaying() const
{
#ifdef __CONNECT_BILLING_SYSTEM__
	return BillingPlayerInfo::isBillingPlayAvaiable();
#elif defined(__CONNECT_CBILLING_SYSTEM__)
	return CBillingPlayerInfo::isPayPlayer();
#elif !defined(__PAY_SYSTEM_ZONE__) && !defined(__PAY_SYSTEM_LOGIN__) && !defined(__PAY_SYSTEM_FREE_LIMIT__)
	// if there is no Pay defines, all users are pay player
	return true;
#else
	return PaySystem::isPayPlaying();
#endif
}

//////////////////////////////////////////////////////////////////////////////
//
// add LogoutPlayerdata
//
// ������ ��踦 ���ؼ� 
// UserInfo DB�� LogoutPlayerData�� Logout�� ����ڸ� �߰��Ѵ�.
//
//////////////////////////////////////////////////////////////////////////////
void addLogoutPlayerData(Player* pPlayer)
{

	Statement* pStmt = NULL;

	pStmt = g_pDatabaseManager->getUserInfoConnection()->createStatement();

	// ���� ��� ���� ������ �Է��Ѵ�.
	BEGIN_DB
	{
		string ID = pPlayer->getID();
		string ip = pPlayer->getSocket()->getHost();

		// ���� ���� �ð��� ����.
		int year, month, day, hour, minute, second;
		getCurrentTimeEx(year, month, day, hour, minute, second);
		string currentDT = VSDateTime::currentDateTime().toDateTime();

		StringStream sql;
		//by kim 2021-08-12
		//sql << "INSERT INTO USERINFO.LogoutPlayerData (PlayerID,IP,Date,Time) VALUES ('"
		sql << "INSERT INTO LogoutPlayerData (PlayerID,IP,Date,Time) VALUES ('"
			<< ID << "','" << ip << "','"
			<< currentDT.substr( 0, 10 ).c_str() << "','"
			<< currentDT.substr( 11 ).c_str() << "')";

		pStmt->executeQuery(sql.toString());

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt)
}

void GamePlayer::setPCRoomLottoStartTime()
{
	if ( !g_pVariableManager->isPCRoomLottoEvent() )
		return;

	if ( !m_bPCRoomPlay )
		return;

	m_PCRoomLottoStartTime.tv_sec = m_PayPlayStartTime.tv_sec - m_PCRoomLottoSumTime;
}

void GamePlayer::savePCRoomLottoTime()
{
	if ( !g_pVariableManager->isPCRoomLottoEvent() )
		return;

	if ( !m_bPCRoomPlay )
		return;

	Timeval currentTime;
	getCurrentTime( currentTime );

	m_PCRoomLottoSumTime = currentTime.tv_sec - m_PCRoomLottoStartTime.tv_sec;
	m_PCRoomLottoStartTime.tv_sec = 0;
}

void GamePlayer::checkPCRoomLotto( const Timeval& currentTime )
{
	if ( !g_pVariableManager->isPCRoomLottoEvent() )
		return;

	if ( !m_bPCRoomPlay )
		return;

	if ( m_PCRoomLottoStartTime.tv_sec == 0 )
	{
		m_PCRoomLottoStartTime.tv_sec = currentTime.tv_sec - m_PCRoomLottoSumTime;
	}

	int time = currentTime.tv_sec - m_PCRoomLottoStartTime.tv_sec;	

	if ( time >= PCRoomLottoSec )
	{
		giveLotto();

		// �ٽ� �ð��� �ʱ�ȭ�Ѵ�.
		m_PCRoomLottoStartTime.tv_sec = currentTime.tv_sec;
		m_PCRoomLottoSumTime = 0;
	}
}

void GamePlayer::giveLotto()
{
	if ( m_pCreature == NULL )
		return;

	Statement* pStmt = NULL;
	Result* pResult = NULL;

	BEGIN_DB
	{
		static uint DimensionID	= g_pConfig->getPropertyInt( "Dimension" );
		static uint WorldID		= g_pConfig->getPropertyInt( "WorldID" );
		string PlayerID		= getID();
		string Name			= m_pCreature->getName();
		Race_t Race			= m_pCreature->getRace();
		int Amount			= 0;
		pStmt = g_pDatabaseManager->getDistConnection("PLAYER_DB")->createStatement();
		pResult = pStmt->executeQuery( "SELECT Amount FROM PCRoomLottoObject WHERE PlayerID = '%s' AND Name = '%s' AND DimensionID = %u AND WorldID = %u",
										PlayerID.c_str(), Name.c_str(), DimensionID, WorldID );

		if ( pResult->next() )
		{
			Amount = pResult->getInt( 1 );

			if ( Amount < PCRoomLottoMaxAmount )
			{
				pStmt->executeQuery( "UPDATE PCRoomLottoObject SET Amount = %d WHERE PlayerID = '%s' AND Name = '%s' AND DimensionID = %u AND WorldID = %u",
										Amount + 1, PlayerID.c_str(), Name.c_str(), DimensionID, WorldID );
			}
		}
		else
		{
			// ������ ������. ���� �־��ش�.
			pStmt->executeQuery( "INSERT INTO PCRoomLottoObject VALUES ( 0, %u, '%s', %u, %u, '%s', %u, 1 )",
									m_PCRoomID, PlayerID.c_str(), DimensionID, WorldID, Name.c_str(), Race );
		}

		if ( Amount < PCRoomLottoMaxAmount )
		{
			char msg[100];
			sprintf( msg, g_pStringPool->c_str( STRID_GIVE_LOTTO ), Amount + 1 ); 

			GCSystemMessage gcMsg;
			gcMsg.setMessage( msg );
			sendPacket( &gcMsg );

			if ( Amount >= PCRoomLottoMaxAmount - 1 )
			{
				gcMsg.setMessage( g_pStringPool->getString( STRID_CANNOT_GIVE_LOTTO ) );
				sendPacket( &gcMsg );
			}
		}

		SAFE_DELETE( pStmt );
	}
	END_DB( pStmt )
}

bool GamePlayer::startPacketLog( uint sec )
{
	if ( m_pCreature == NULL )
		return false;

	m_bPacketLog = true;
	getCurrentTime( m_PacketLogEndTime );
	m_PacketLogEndTime.tv_sec += sec;

	char filename[100];
	sprintf( filename, "log/%s.log", m_pCreature->getName().c_str() );
	m_PacketLogFileName = filename;

	return true;
}

void GamePlayer::logLoginoutDateTime()
{
	if ( m_pCreature == NULL )
		return;

	// DimensionID ���ϱ�
	uint dimensionID = g_pConfig->getPropertyInt("Dimension");
	if ( g_pConfig->getPropertyInt("IsNetMarble") == 0 )
	{
		// �ݸ��� �� ��쿣 2
		dimensionID = 2;
	}

	// WorldID
	uint worldID = g_pConfig->getPropertyInt("WorldID");

	// ���� �ڵ�
	uint racecode;
	uint str,dex,inte;
	if ( m_pCreature->isSlayer() )
	{
		Slayer* pSlayer = dynamic_cast<Slayer*>(m_pCreature);
		Assert( pSlayer != NULL );

		racecode = (uint)pSlayer->getHighestSkillDomain();

		str = pSlayer->getSTR();
		dex = pSlayer->getDEX();
		inte = pSlayer->getINT();
	}
	else if ( m_pCreature->isVampire() )
	{
		// �����̾��  10
		racecode = 10;

		Vampire* pVampire = dynamic_cast<Vampire*>(m_pCreature);
		Assert( pVampire != NULL );

		str = pVampire->getSTR();
		dex = pVampire->getDEX();
		inte = pVampire->getINT();
	}
	else if ( m_pCreature->isOusters() )
	{
		// �ƿ콺����� 20
		racecode = 20;

		Ousters* pOusters = dynamic_cast<Ousters*>(m_pCreature);
		Assert( pOusters != NULL );

		str = pOusters->getSTR();
		dex = pOusters->getDEX();
		inte = pOusters->getINT();
	}
	else
	{
		return;
	}

	// ����
	uint level = (uint)m_pCreature->getLevel();

	// �α׾ƿ� �ð�. ���� �ð�
	VSDateTime logoutDateTime = VSDateTime::currentDateTime();

	// filename
	// one file per day under log/ (this used to target bin/log/, which does not exist)
	string filename = logPath(("logout_" + logoutDateTime.toStringforWeb() + ".txt").c_str());

	try
	{
		ofstream file( filename.c_str(), ios::out | ios::app );
		file << dimensionID << "\t" << worldID << "\t" << m_ID << "\t"
			 << m_pCreature->getName() << "\t" << racecode << "\t"
			 << level << "\t" << str << "\t" << dex << "\t" << inte << "\t"
			 << m_LoginDateTime.toDateTime() << "\t"
			 << logoutDateTime.toDateTime() << endl;
		file.close();
	}
	catch (...)
	{
	}
}

int GamePlayer::getPCRoomExpBonus()
{
	int iExpRate = 100;

	switch(getPayPlayRoomType())
    {
		case PAY_PLAY_ROOM_TYPE_HOME :
	        iExpRate = g_pVariableManager->getVariable(HOME_EXP_BONUS);
			break;
		case PAY_PLAY_ROOM_TYPE_FREE_PCROOM :
	        iExpRate = g_pVariableManager->getVariable(PCROOM_FREE_EXP_BONUS);
			break;
		case PAY_PLAY_ROOM_TYPE_CHARGE_PCROOM :
			iExpRate = g_pVariableManager->getVariable(PCROOM_CHARGE_EXP_BONUS);
			break;
	}

	return iExpRate;
}

bool GamePlayer::isAuthGameFeature(GameFeature gameFeature, void *pData)
{
	switch(gameFeature)
	{
		case GAME_FEATURE_GEARSWAPPING :
		{
			GearSlotID_t GearSlotID = (GearSlotID_t)(int)(intptr_t)pData;

			//20081007 kim seong yong
			if ( isPremiumPlay() || g_pVariableManager->isEndRestrictionGearSlot() )
			{
				return true;
			}
			else if ( GearSlotID == 0 )	// default GearSlot
			{
				return true;
			}
			else if ( GearSlotID >= 1 )
			{
				return false;
			}
			
			break;
		}
		
		case GAME_FEATURE_GIVE_WEEKITEM :
		{
			if ( isPremiumPlay() && g_pVariableManager->isGiveWeekItem() )
			{
				return true;
			}
			else
			{
				return false;	
			}
			
			break;
		}
		//1222 wlzzi - �����̾� �� ����
		case GAME_FEATURE_APPLY_PREMIUMZONE:
		{
			Zone* pZone = (Zone*)pData;
			if (!pZone) return false;
			BYTE PremiumZoneType = pZone->getPremiumZoneType ();
			if ( isPremiumPlay() && PremiumZoneType != 0)
				return true;
			else if ( !isPremiumPlay() && PremiumZoneType == 2)
				return true;
			return false;
		}
	}

	return false;

}

long GamePlayer::GetBaseTimeToVerifyMoveSpeed()
{
	long lBaseMoveTime = 500;	// milli-second

	if ( m_pCreature->isFlag(Effect::EFFECT_CLASS_HAS_BLOOD_BIBLE) ||
			m_pCreature->isFlag(Effect::EFFECT_CLASS_HAS_SWEEPER) ||
			m_pCreature->isFlag(Effect::EFFECT_CLASS_HAS_MIHNEA)
			)
	{
		lBaseMoveTime = 1000;
	}
	else if ( m_pCreature->isFlag(Effect::EFFECT_CLASS_DRAGON_EYE) )
	{
		lBaseMoveTime = 250;
	}
	else
	{
		if (m_pCreature->isSlayer()) 
		{
			Slayer* pSlayer = dynamic_cast<Slayer*>(m_pCreature);
	
			lBaseMoveTime = 500;
	
			// if MotorCycle is ride.
			if ( pSlayer->hasRideMotorcycle() )
			{		
				Motorcycle *pMotorcycle = pSlayer->getMotorcycle();
				MotorcycleType motorcycleType = getMotorcycleType(pMotorcycle->getItemType());
				
				if ( motorcycleType == MOTORCYCLE_WING )
				{
					lBaseMoveTime = 180;
				}
				else
				{
					lBaseMoveTime = 250;
				}
			}
			else if ( pSlayer->isFlag(Effect::EFFECT_CLASS_SLAYER_HERO_ITEM) ||
				pSlayer->isFlag(Effect::EFFECT_CLASS_SLAYER_LEVELWAR_HERO_ITEM)
			)
			{
				lBaseMoveTime = 250;
			}
			
		}
		else if ( m_pCreature->isVampire()) 
		{
			Vampire* pVampire = dynamic_cast<Vampire*>(m_pCreature);
	
			lBaseMoveTime = 500;
	
			if ( pVampire->isFlag(Effect::EFFECT_CLASS_TRANSFORM_TO_BAT) )
			{
				if ( pVampire->GetBatType() == Vampire::BAT_TYPE_WING)
				{
					lBaseMoveTime = 180;
				}
				else
				{
					lBaseMoveTime = 250;	
				}
			}
			else if ( pVampire->isFlag(Effect::EFFECT_CLASS_TRANSFORM_TO_WOLF) )
			{
				lBaseMoveTime = 375;
			}
			else if ( pVampire->isFlag(Effect::EFFECT_CLASS_VAMPIRE_HERO_ITEM) ||
				pVampire->isFlag(Effect::EFFECT_CLASS_VAMPIRE_LEVELWAR_HERO_ITEM)
			)
			{
				lBaseMoveTime = 250;
			}
		}
	
		else if (m_pCreature->isOusters()) 
		{
			Ousters* pOusters = dynamic_cast<Ousters*>(m_pCreature);
	
			lBaseMoveTime = 500;
	
			if ( pOusters->isFlag(Effect::EFFECT_CLASS_SUMMON_SYLPH) )
			{
				if ( pOusters->GetWingSylphType() == Ousters::SYLPH_TYPE_WING)
				{
					lBaseMoveTime = 180;
				}
				else
				{
					lBaseMoveTime = 250;	
				}
			}
			else if ( pOusters->isFlag(Effect::EFFECT_CLASS_OUSTERS_HERO_ITEM) ||
				pOusters->isFlag(Effect::EFFECT_CLASS_OUSTERS_LEVELWAR_HERO_ITEM)
			)
			{
				lBaseMoveTime = 250;
			}
		}
	}
	
	return lBaseMoveTime;
}

bool GamePlayer::verifyMoveSpeed(DWORD dwPacketTimeStamp, ZONE_COORD& adjCoord)
{
	__BEGIN_TRY

	if ( m_pCreature->isDM() || m_pCreature->isGOD() )
	{
		return true;
	}

	Zone *pZone = m_pCreature->getZone();
	if ( pZone == NULL )
	{
		return false;
	}

	long lBaseMoveTime;
	
	lBaseMoveTime = GetBaseTimeToVerifyMoveSpeed();
	
	if ( m_lastZoneID != pZone->getZoneID())
	{
		m_MoveHist.clear();
	}

	ZONE_COORD coord;

	coord.x = m_pCreature->getX();	
	coord.y = m_pCreature->getY();	

	long lErrorTime;	// milli-second
	long lDiffTime;		// milli-second
	
	if ( dwPacketTimeStamp > m_dwPrevMoveTime )
	{
		lDiffTime = dwPacketTimeStamp - m_dwPrevMoveTime;
	}
	else
	{
		lDiffTime = lBaseMoveTime;
	}

	lBaseMoveTime = lBaseMoveTime - g_pVariableManager->getSkillSpeedNetworkLatencyTime();
	lErrorTime = lBaseMoveTime - lDiffTime; 
	
	if ( lErrorTime > 0 )
	{
		++m_iAbnormalMoveTryCount;
		
		IncreaseAbuseActionPoint((lErrorTime * 100) / lBaseMoveTime);
		
		ostringstream strAbuseAction;
				
		strAbuseAction << "(Move, " 
			<< (int)m_pCreature->getRace() << ", " 
			<< (int)lBaseMoveTime << ", " 
			<< (int)lDiffTime << ", "
			<< (int)lErrorTime << ", "
			<< GetAbuseActionPoint() << ")";
		
//		saveSpeedHackLog(strAbuseAction.str(), false);
	}
	else
	{
		m_iAbnormalMoveTryCount = 0;
		
		DecreaseAbuseActionPoint(10);
	}

	if ( m_iAbnormalMoveTryCount >= 2 )
	{
		// To protect increasing unlimitly
		m_iAbnormalMoveTryCount = 2;

		if ( m_MoveHist.size() > 0 )
		{
			adjCoord = m_MoveHist.front();
		}
		else
		{
			adjCoord = coord;
		}
		
		return false;
	}
	else
	{
		// �̵� �ð� ������ �������� ��츸 ����
		m_dwPrevMoveTime = dwPacketTimeStamp;
		
		m_MoveHist.push_back(coord);

		if ( m_MoveHist.size() >= 2 )
		{
			m_MoveHist.pop_front();
		}

		return true;
	}

	return false;

	__END_CATCH

}

void GamePlayer::rollbackMoveSpeed()
{
	unsigned long lBaseMoveTime;
	
	lBaseMoveTime = GetBaseTimeToVerifyMoveSpeed();
	
	if ( m_dwPrevMoveTime > lBaseMoveTime )
	{
		m_dwPrevMoveTime -= lBaseMoveTime;	
	}
	else
	{
		m_dwPrevMoveTime = 0;
	}
	
}

BYTE GamePlayer::getAttackSpeedStage(Speed_t AttackSpeed)
{
	BYTE Speed = 0;

	if (AttackSpeed < 33) 
	{
		Speed = 0;	// slow
	} else if (AttackSpeed < 67) 
	{
		Speed = 1;	// normal
	} else 
	{
		Speed = 2;	// fast
	}
	
	return Speed;
}

bool GamePlayer::verifyMeleeAttackSpeed(DWORD dwPacketTimeStamp)
{
	if ( !g_pVariableManager->isSkillSpeedEnableVerification() )
	{
		return true;
	}
	
	__BEGIN_TRY

	long lBaseAttackTime = 0;	// unit - milli-second
	Item::ItemClass IClass = Item::ITEM_CLASS_MAX;
	BYTE Speed = 0;
	
	if (m_pCreature->isSlayer()) {

		Slayer* pSlayer = dynamic_cast<Slayer*>(m_pCreature);

		Speed = getAttackSpeedStage(pSlayer->getAttackSpeed());

		// ���⸦ ������ ��� �ִ��� üũ�Ѵ�.
		Item* pItem = pSlayer->getWearItem(Slayer::WEAR_RIGHTHAND);
		IClass = Item::ITEM_CLASS_MAX;
		if (pItem != NULL) {
			IClass = pItem->getItemClass();
		} 

		long lBaseAttackTimeTable[3][9] = {
			// default, SWORD, BLADE, CROSS, MACE, AR, SG, SR, SMG
			{ 875, 937, 1180, 1180, 1180, 1000, 1250, 1375, 1000},	// Slow
			{ 875, 812, 1062, 1062, 1062,  875, 1125, 1250,  875},	// Normal
			{ 875, 687,  937,  937,  937,  750, 1000, 1125,  750},	// Fast
		};

		switch (IClass) 
		{
			case Item::ITEM_CLASS_SWORD :
				lBaseAttackTime = lBaseAttackTimeTable[Speed][1];
				break;
			case Item::ITEM_CLASS_BLADE :
				lBaseAttackTime = lBaseAttackTimeTable[Speed][2];
				break;
			case Item::ITEM_CLASS_CROSS :
				lBaseAttackTime = lBaseAttackTimeTable[Speed][3];
				break;
			case Item::ITEM_CLASS_MACE :
				lBaseAttackTime = lBaseAttackTimeTable[Speed][4];
				break;
			case Item::ITEM_CLASS_AR :
				lBaseAttackTime = lBaseAttackTimeTable[Speed][5];
				break;
			case Item::ITEM_CLASS_SG :
				lBaseAttackTime = lBaseAttackTimeTable[Speed][6];
				break;
			case Item::ITEM_CLASS_SR :
				lBaseAttackTime = lBaseAttackTimeTable[Speed][7];
				break;
			case Item::ITEM_CLASS_SMG :
				lBaseAttackTime = lBaseAttackTimeTable[Speed][8];
				break;
			default :
				lBaseAttackTime = lBaseAttackTimeTable[Speed][0];
				break;
		}
	}
	else if ( m_pCreature->isVampire()) 
	{
		Vampire* pVampire = dynamic_cast<Vampire*>(m_pCreature);

		Speed = getAttackSpeedStage(pVampire->getAttackSpeed());

		switch(Speed)
		{
			case 0 :
				lBaseAttackTime = 937;
				break;
			case 1 :
				lBaseAttackTime = 812;
				break;
			case 2 :
				lBaseAttackTime = 687;
				break;
		}

	}
	else if (m_pCreature->isOusters()) 
	{
		Ousters* pOusters = dynamic_cast<Ousters*>(m_pCreature);

		Speed = getAttackSpeedStage(pOusters->getAttackSpeed());

		// ���⸦ ������ ��� �ִ��� üũ�Ѵ�.
		Item* pItem = pOusters->getWearItem(Ousters::WEAR_RIGHTHAND);
		IClass = Item::ITEM_CLASS_MAX;
		if (pItem != NULL) {
			IClass = pItem->getItemClass();
		} 

		long lBaseAttackTimeTable[3][2] = {
			// default, Chakram
			{1250, 937},	// Slow
			{1250, 812},	// Normal
			{1250, 687},	// Fast
		};

		switch(IClass)
		{
			case Item::ITEM_CLASS_OUSTERS_CHAKRAM :
				lBaseAttackTime = lBaseAttackTimeTable[Speed][1];
				break;
			default :
				lBaseAttackTime = lBaseAttackTimeTable[Speed][0];
				break;
		}
	}

	long lErrorTime;	// milli-second
	long lDiffTime;		// milli-second

	if ( m_dwLastMeleeAttackTime == 0 )
	{
		// ���� ó�� ������ �ϴ� ���
		m_dwLastMeleeAttackTime = dwPacketTimeStamp; 	
	}
	
	lDiffTime = dwPacketTimeStamp - m_dwLastMeleeAttackTime;
	
	if ( lDiffTime >= lBaseAttackTime )
	{
		m_lAccumAttackTime = 0;
	}

	lBaseAttackTime = lBaseAttackTime - g_pVariableManager->getSkillSpeedNetworkLatencyTime();
	lErrorTime = lBaseAttackTime - ( lDiffTime + m_lAccumAttackTime);
			
	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(m_pCreature);
	if ( pPC->GetParameter<bool>("showSkillSpeedLog", false) ) 
	{
		char strBuf[1024];
		
		sprintf(strBuf,"MeleeSpeedTime : AccumAttackTime = %ld BaseAttackTime = %ld DiffTime = %ld ErrorTime = %ld",
			m_lAccumAttackTime ,
			lBaseAttackTime ,
			lDiffTime ,
			lErrorTime
		);
	
		GCSystemMessage msg;
		msg.setMessage( strBuf );
		
		sendPacket( &msg );
	}	

	m_dwLastMeleeAttackTime = dwPacketTimeStamp;
	
	// if melee-attack try is received faster than base time.
	if ( lErrorTime > 0 )
	{
		m_lAccumAttackTime += lDiffTime;

		if ( m_lAccumAttackTime > 1000 * 3 )
		{
			m_lAccumAttackTime = 1000 * 3;
			
			IncreaseAbuseActionPoint((lErrorTime * 100) / lBaseAttackTime);
			
			ostringstream strAbuseAction;
					
			strAbuseAction << "(Melee, " 
				<< (int)m_pCreature->getRace() << ", " 
				<< (int)Speed << ", "
				<< (int)IClass << ", "
				<< (int)lBaseAttackTime << ", "
				<< (int)lDiffTime << ", "
				<< (int)lErrorTime << ", "
				<< GetAbuseActionPoint() << ")";
			
			
//			saveSpeedHackLog(strAbuseAction.str(), false);
		}
		
		return false;
	}
	else
	{
		m_lAccumAttackTime = 0;
		m_lPenaltyAttackTime = 0;
		
		DecreaseAbuseActionPoint(5);

		return true;
	}

	return false;

	__END_CATCH
}

long GamePlayer::GetBaseTimeToVerifySkillSpeed(SkillType_t SkillType, int& iCheckType)
{
	PlayerCreature* pPlayerCreature = dynamic_cast<PlayerCreature*>(m_pCreature);

	// ���⸦ ������ ��� �ִ��� üũ�Ѵ�.
	Item* pItem = pPlayerCreature->getWearItem(pPlayerCreature->getWearPartOfRightHand());
	Item::ItemClass IClass = Item::ITEM_CLASS_MAX;
	if (pItem != NULL) 
	{
		IClass = pItem->getItemClass();
	} 
	
	long lBaseTime = 0x7fffffff;
	
	SkillCastingTime castingTime;
	
	if ( g_SkillCastingTimeManager.GetSkillTime(SkillType, IClass, castingTime) )
	{
		// ������ ���� CastingTime���� ���� �ð� ����
		if ( pPlayerCreature->isAdvanced() ) 
		{
			lBaseTime = castingTime.iCastingTimeForAdv;
			
		}
		else
		{
			lBaseTime = castingTime.iCastingTimeForNonAdv;
		}		
		
		iCheckType = 1;		// ���� ���� �ð����� ������ ������ �˻�
	}
	else
	{
		Turn_t Interval = 0;
		
		if ( pPlayerCreature->isSlayer() )
		{
			Slayer* pSlayer = dynamic_cast<Slayer*>(pPlayerCreature);
			
			// ������ ���� CastingTime(���ȵ����� ���� ���ϴ� ��ų CastingTime)���� ���� �ð� ����
			SlayerSkillSlot *pSkillSlot = pSlayer->getSkill(SkillType);
			if ( pSkillSlot != NULL )
			{
				Interval = pSkillSlot->getInterval();
			}
		}
		else if ( pPlayerCreature->isVampire() )
		{
			Vampire* pVampire = dynamic_cast<Vampire*>(pPlayerCreature);
				
			VampireSkillSlot *pSkillSlot = pVampire->getSkill(SkillType);
			if ( pSkillSlot != NULL )
			{
				Interval = pSkillSlot->getInterval();
			}
		}
		else if ( pPlayerCreature->isOusters() )
		{
			Ousters* pOusters = dynamic_cast<Ousters*>(pPlayerCreature);
							
			OustersSkillSlot *pSkillSlot = pOusters->getSkill(SkillType);
			if ( pSkillSlot != NULL )
			{
				Interval = pSkillSlot->getInterval();
			}
		}
		
		iCheckType = 2;			// ���� ���� �ð����� ������ ������ �˻�(��ų�� ���� �ð��� ���ȿ� ���� �ٸ�) 
		
		if ( Interval == 0 )
		{
			SkillInfo* pSkillInfo;
			
			try
			{
				pSkillInfo = g_pSkillInfoManager->getSkillInfo(SkillType);
				Interval = pSkillInfo->getMaxDelay();
			}
			catch(NoSuchElementException& e)
			{
				Interval = 0;	
			}
			
			iCheckType = 3;		// DB ������(SkillBalance ���̺��� MaxDelay ���� ���)
		}
		
		lBaseTime = Interval * 100;
	}
	
	return lBaseTime;
}

bool GamePlayer::verifySkillSpeed(DWORD dwPacketTimeStamp, SkillType_t SkillType)
{
	if ( !g_pVariableManager->isSkillSpeedEnableVerification() )
	{
		return true;
	}

	__BEGIN_TRY

	long lBaseSkillTime;	// milli-second
	
	long lErrorTime;	// milli-second
	long lDiffTime;		// milli-second
	
	if ( m_LastSkillTime.find(SkillType) == m_LastSkillTime.end() )
	{
		m_LastSkillTime[SkillType].push_front(0);
		
		lDiffTime = 0x7fffffff;
	}
	else
	{
		DWORD LastSkillTime;
		
		LastSkillTime = m_LastSkillTime[SkillType].front();
		
		if ( LastSkillTime == 0 )
		{
			lDiffTime = 0x7fffffff;
		}
		else if ( dwPacketTimeStamp > LastSkillTime )
		{
			lDiffTime = dwPacketTimeStamp - LastSkillTime;	
		}
		else
		{
			// ������ ��ų ����� �ð����� ����  PacketTimeStamp�� �� ��� �ð����� 0���� ����
			lDiffTime = 0;
		}
	}
	
	int iCheckType = 0;
	long lBaseTime;
	
	lBaseTime = GetBaseTimeToVerifySkillSpeed(SkillType, iCheckType);

	lBaseSkillTime = lBaseTime - g_pVariableManager->getSkillSpeedNetworkLatencyTime();
	if ( lBaseSkillTime < 0 )
	{
		lBaseSkillTime = 0;
	}

	lErrorTime = lBaseSkillTime - lDiffTime; 
	
	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(m_pCreature);
	if ( pPC->GetParameter<bool>("showSkillSpeedLog", false) ) 
	{
		char strBuf[1024];
		
		sprintf(strBuf,"SkillSpeed : CheckType=%d, BaseSkillTime=%ld DiffTime=%ld ErrorTime=%ld",
			iCheckType,
			lBaseSkillTime ,
			lDiffTime ,
			lErrorTime
		);
	
		GCSystemMessage msg;
		msg.setMessage( strBuf );
		
		sendPacket( &msg );
	}
	
	if ( lErrorTime > 0 )
	{
		IncreaseAbuseActionPoint((lErrorTime * 100) / lBaseSkillTime);
		
		ostringstream strAbuseAction;
		
		strAbuseAction << "(Skill, " 
			<< (int)SkillType << ", " 
			<< (int)lBaseSkillTime << ", " 
			<< (int)lDiffTime << ", "
			<< (int)lErrorTime << ")"
			<< GetAbuseActionPoint() << ")";
			
//		saveSpeedHackLog(strAbuseAction.str(), false);

		return false;
	}

	if ( m_LastSkillTime[SkillType].size() > 2 )
	{
		// ť�� �ִ� 2������ ���� �ϵ��� �Ѵ�.
		m_LastSkillTime[SkillType].pop_front();
	}
	m_LastSkillTime[SkillType].push_front(dwPacketTimeStamp);
	
	DecreaseAbuseActionPoint(5);

	return true;

	__END_CATCH
}

void GamePlayer::rollbackSkillSpeed(SkillType_t SkillType)
{
	if ( m_LastSkillTime.find(SkillType) != m_LastSkillTime.end() )
	{
		if ( m_LastSkillTime[SkillType].size() > 0 )
		{
			m_LastSkillTime[SkillType].pop_front();	
		}
		else
		{
			m_LastSkillTime[SkillType].push_front(0);
		}
	}
}

void GamePlayer::saveSpeedHackPlayer()
{
	__BEGIN_TRY
	
	Creature* pCreature = this->getCreature();

	string ID = getID();
	string IP = getSocket()->getHost();
	string Name = "";

	if ( pCreature != NULL )
	{
		if ( pCreature->isSlayer() )
		{
			Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);
			Name = "Slayer:" + pSlayer->getName();
		}
		else if ( pCreature->isVampire() )
		{
			Vampire* pVampire = dynamic_cast<Vampire*>(pCreature);
			Name = "Vampire:" + pVampire->getName();
		}
		else if ( pCreature->isOusters() )
		{
			Ousters* pOusters = dynamic_cast<Ousters*>(pCreature);
			Name = "Ousters:" + pOusters->getName();
		}
	}

	filelog("SpeedHack.log", "ID[%s], Name[%s], IP[%s] VerifyTimeCount=%d, NumOfNotRecvVerifyTime=%d", 
		ID.c_str(), 
		Name.c_str(), 
		IP.c_str(),
		m_VerifyCount,
		m_NumOfNotRecvVerifyTime
	);

	/////////////////////////////////////////////////////////
	// ��� ���� ������ �ִ´�.
	/////////////////////////////////////////////////////////
	Statement* pStmt = NULL;

	try 
	{
		static WorldID_t 		WorldID 		= g_pConfig->getPropertyInt( "WorldID" );
		static ServerGroupID_t 	ServerGroupID 	= g_pConfig->getPropertyInt( "ServerID" );

		BEGIN_DB
		{
			pStmt = g_pDatabaseManager->getDistConnection("PLAYER_DB")->createStatement();

			pStmt->executeQuery( "UPDATE SpeedHackPlayer SET IP = '%s', NAME = '%s', WorldID = %d, ServerGroupID = %d, Date = now(), Count = Count + 1 WHERE PlayerID = '%s'",
								IP.c_str(), Name.c_str(), (int)WorldID, (int)ServerGroupID, ID.c_str() );

			if ( pStmt->getAffectedRowCount() == 0 )
			{
				pStmt->executeQuery( "INSERT IGNORE INTO SpeedHackPlayer( PlayerID, IP, Name, WorldID, ServerGroupID, Date, Count ) VALUES ( '%s', '%s', '%s', %d, %d, now(), 1 )",
								ID.c_str(), IP.c_str(), Name.c_str(), (int)WorldID, (int)ServerGroupID );
			}

			SAFE_DELETE( pStmt );
		}
		END_DB(pStmt)
	}
	catch ( Throwable& t )
	{
		filelog("SpeedHackLogError.log", "%s", t.toString().c_str() );
	}

	__END_CATCH
}

void GamePlayer::saveSpeedHackLog(const string& strAbuseAction, bool bSendWarningMesg)
{
	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(m_pCreature);

	static ServerGroupID_t ServerGroupID = g_pConfig->getPropertyInt( "ServerID" );
	
	string strName = "";
	string strIP = getSocket()->getHost();
	ZoneID_t  ZoneID = 0;
	ZoneCoord_t ZoneX = 0;
	ZoneCoord_t ZoneY = 0;
	
	if ( pPC != NULL )
	{
		strName = pPC->getName();
		ZoneID = pPC->getZoneID();
		ZoneX = pPC->getX();
		ZoneY = pPC->getY();
	}

	ostringstream os;
	
	os << "INSERT SpeedHackLog(PlayerID, Name, ServerGroupID, ZoneID, XCoord, YCoord, IP, AbuseAction, IssueDate) VALUES('" 
		<< getID() << "', '" 
		<< strName << "', " 
		<< (int)ServerGroupID << ", " 
		<< ZoneID << ", " 
		<< ZoneX << ", " 
		<< ZoneY << ", '" 
		<< strIP << "', '" 
		<< strAbuseAction 
		<< "', now())"; 
	
	// this ������ ������ Query Key �� ����
	g_GameDBExecuteManager.RequestExecQuery((TDBExecuteUnitKey)(uintptr_t)this, os.str());

	if ( bSendWarningMesg && g_pVariableManager->isSkillSpeedShowAbuseMessage() )
	{
		char strBuf[1024];
		
		sprintf(strBuf, "���������� �����÷��̷� ������ �ǰ� �ֽ��ϴ�. ���������� ���� ���縦 ���� �� �ֽ��ϴ�.");
				
		GCSystemMessage msg;
		msg.setMessage( strBuf );
		
		sendPacket( &msg );
	}
}

bool GamePlayer::verifyChat(DWORD dwPacketTimeStamp)
{
	// GM accounts are exempt from the chat flood guard. Running a burst of
	// operator commands is ordinary work, and tripping this applies an
	// EffectMute that is written to the DB and survives relog. GOD was already
	// exempt; DM and HELPER were not, which is what locked operators out.
	if (!m_pCreature->isPLAYER())
	{
		return true;
	}
	
	if ( m_dwPrevChatTime > dwPacketTimeStamp )
	{
		// Timestamp ���� ���ɼ� ����
		
		++m_iAbnormalChatTryCount;
	}
	else if (  dwPacketTimeStamp - m_dwPrevChatTime < 250 )
	{
		++m_iAbnormalChatTryCount;
	}
	
	if ( m_iAbnormalChatTryCount > 5 )
	{
		m_iAbnormalChatTryCount = 0;
		++m_iAccumAbnormalChatCount;
		
		Duration_t duration;
		
		// unit - 1/10 sec
		duration = (Duration_t)(5 * 60 * 10 * pow(2.0f, m_iAccumAbnormalChatCount-1));
		
		if(!m_pCreature->isFlag(Effect::EFFECT_CLASS_MUTE))
		{
			EffectMute *pEffectMute = new EffectMute(getCreature());
			pEffectMute->setDeadline(duration);
			getCreature()->addEffect(pEffectMute);
		
			pEffectMute->create(getCreature()->getName());
			pEffectMute->affect();
		}
		return false;
	}
	
	m_dwPrevChatTime = dwPacketTimeStamp;
	
	return true;
}

void GamePlayer::IncreaseAbuseActionPoint(int iPoint)
{
	m_AbuseActionPoint += iPoint;
}
	
void GamePlayer::DecreaseAbuseActionPoint(int iPoint)
{
	m_AbuseActionPoint -= iPoint;
	if ( m_AbuseActionPoint < 0 )
	{
		m_AbuseActionPoint = 0;
	}
}

void GamePlayer::Netmb_LoginLog()
{
	cout << "Netmb_LoginLog" << endl;
	
	string ID = getID();
	string  Password;
	Statement* pStmtLDB = NULL;

	Result* pResult = NULL;
	pStmtLDB = g_pDatabaseManager->getDistConnection("PLAYER_DB")->createStatement();
	BEGIN_DB
	{
		pResult = pStmtLDB->executeQuery("SELECT Password FROM Player WHERE PlayerID = '%s'", ID.c_str());
	
		if (pResult->getRowCount() != 1)
		{
			StringStream msg;
			msg << "Failed to load Netmb_LoginLog data from DB. No Player(" 
				<< ID.c_str() << ")";
	
			//filelog("connectDB_BUG.txt", "%s", msg.toString().c_str());
	
			SAFE_DELETE(pStmtLDB);
			throw ProtocolException(msg.toString().c_str());
		}
		if ( pResult->next() )
		{
			Password = pResult->getString(1);
		}
		SAFE_DELETE(pStmtLDB);
	}
	END_DB(pStmtLDB)
	
	Statement* pStmt = NULL;

	pStmt = g_pDatabaseManager->getConnection( "DARKEDEN" ) ->createStatement() ;//getUserInfoConnection()->createStatement();

	// ���� ��� ���� ������ �Է��Ѵ�.
	BEGIN_DB
	{
		
		PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(getCreature());
		Assert( pPC != NULL );
		string Name = pPC->getName();
		string ip = getSocket()->getHost();
		//string ServerName ;//=g_pGameServerInfoManager->getNickName();
		
		string worldName = g_pGameWorldInfoManager->getGameWorldInfo(g_pConfig->getPropertyInt( "WorldID" ))->getName();
		
		// ���� ���� �ð��� ����.
		int year, month, day, hour, minute, second;
		getCurrentTimeEx(year, month, day, hour, minute, second);
		//string currentDT = VSDateTime::currentDateTime().toDateTime();
		m_NetmbLoginDT = VSDateTime::currentDateTime();
		string currentDT = m_NetmbLoginDT.toDateTime();
		
		string rValue;
		rValue += itos(year)  ;
		rValue += itos(month) ;
		rValue += itos(day) ;
			
		StringStream sql;
		sql << "INSERT INTO Netmb_PlayTimeLog (cur_date, CN, UserID, ServerName, CharacName, LoginDate, IP) VALUES ('"
			<< rValue << "','"
			<< Password << "','"
			<< ID << "','"
			<< worldName << "','"
			<< Name << "','" 
			<< currentDT.c_str() << "','"
			<< ip << "')";
			
		pStmt->executeQuery(sql.toString());

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt)
	

}

void GamePlayer::Netmb_LogoutLog()
{
	//cout << "Netmb_LogoutLog" << endl;

	Statement* pStmt = NULL;
	pStmt = g_pDatabaseManager->getConnection( "DARKEDEN" )->createStatement() ;//getUserInfoConnection()->createStatement();

	// ���� ��� ���� ������ �Է��Ѵ�.
	BEGIN_DB
	{
		string ID = getID();
		PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(getCreature());
		Assert( pPC != NULL );
		string Name = pPC->getName();
		string ip = getSocket()->getHost();
		
		// ���� ���� �ð��� ����.
		int year, month, day, hour, minute, second;
		getCurrentTimeEx(year, month, day, hour, minute, second);
		string currentDT = VSDateTime::currentDateTime().toDateTime();
		string loginDT = m_NetmbLoginDT.toDateTime();
		//VSDateTime PlayTimeDT = m_NetmbLoginDT - VSDateTime::currentDateTime();
		//cout << "Netmb_LogoutLog2" << endl;
		pStmt->executeQuery("UPDATE Netmb_PlayTimeLog SET LogoutDate ='%s' WHERE LogoutDate is NULL AND UserID = '%s' AND CharacName = '%s'" ,currentDT.c_str(), ID.c_str(), Name.c_str());
		//cout << "Netmb_LogoutLog3" << endl;
	/*	StringStream sql;
		sql << "UPDATE DARKEDEN.Netmb_PlayTimeLog  SET  LogoutDate = now(), PlayTime = %d WHERE LoginDate = '%s' AND PlayerID"
			<< currentDT.substr( 0, 8).c_str() << "','"
			<< 0 << "','"
			<<UserID << "','"
			<< ID << "','" << ip << "','"
			<< currentDT.substr( 0, 10 ).c_str() << "','"
			<< currentDT.substr( 11 ).c_str() << "')";

		pStmt->executeQuery(sql.toString());*/

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt)
	//cout << "Netmb_LogoutLog4" << endl;
	

}
