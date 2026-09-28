#include "GQuestManager.h"
#include "GQuestStatus.h"
#include "GQuestInfo.h"
#include "PlayerCreature.h"
#include "Gpackets/GCGQuestStatusInfo.h"
#include "Gpackets/GCGQuestStatusModify.h"
#include "Gpackets/GCSystemMessage.h"
#include "Player.h"
#include "SXml.h"
#include "GQuestAllElements.h"
#include "Timeval.h"
#include "NPC.h"
#include "DB.h"
#include "MonsterCorpse.h"
#include "Monster.h"
#include "MonsterInfo.h"
#include "Party.h"
#include "EffectEventQuestReset.h"
#include "GQuestCheckPoint.h"
#include <cstdio>
#include <algorithm>
#include <list>
#include "StringPool.h"

GQuestManager::~GQuestManager()
{
	clear();
}

void GQuestManager::load()
	throw(Error)
{
	__BEGIN_TRY

	Statement* pStmt = NULL;
	hash_map<DWORD, GQuestInfo*>& infos = GQuestInfoManager::Instance().getInfos();
	list<DWORD> restoring;		// quests found DOING/SUCCESS; their missions come from GQuestMissionSave below

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pResult = pStmt->executeQuery("SELECT QuestID, Status, unix_timestamp(now()) - unix_timestamp(Time) FROM GQuestSave WHERE OwnerID='%s'",
				m_pOwner->getName().c_str() );

		while ( pResult->next() )
		{
			WORD	qID = pResult->getInt(1);
			BYTE	sta = pResult->getInt(2);

			if ( sta == QuestStatusInfo::DOING || sta == QuestStatusInfo::SUCCESS )
			{
				// An accepted quest survives logout (KAN-13).
				hash_map<DWORD, GQuestInfo*>::iterator infoItr = infos.find(qID);
				if ( infoItr == infos.end() || infoItr->second == NULL )
				{
					filelog("GQuestError.log", "in-progress quest is no longer in the quest data, dropping it : [%s]:%d/%d",
							m_pOwner->getName().c_str(), qID, sta);
					continue;
				}

				GQuestStatus* pStatus = new GQuestStatus(m_pOwner, infoItr->second);
				pStatus->setStatus(sta);
				m_QuestStatuses[qID] = pStatus;
				restoring.push_back(qID);
			}
			else if ( sta == QuestStatusInfo::COMPLETE || sta == QuestStatusInfo::FAIL )
			{
				m_QuestStatuses[qID] = new GQuestStatus(m_pOwner, qID);
				m_QuestStatuses[qID]->setStatus(sta);
			}
			else if ( sta != QuestStatusInfo::CAN_REPLAY )
			{
				filelog("GQuestError.log", "saved quest has an unexpected status : [%s]:%d/%d",
						m_pOwner->getName().c_str(), qID, sta);
				continue;
			}

			if ( ( qID == 1001 || qID == 2001 || qID == 3001 ) && sta == QuestStatusInfo::COMPLETE )
			{
				cout << "complete.." << endl;
				EffectEventQuestReset* pEffect = new EffectEventQuestReset( m_pOwner, 1 );
				int lastSec = pResult->getInt(3);
				if ( lastSec > EVENT_QUEST_TIME_LIMIT ) lastSec = EVENT_QUEST_TIME_LIMIT;
				cout << "지난 시간 lastSec : " << lastSec << endl;
				pEffect->setDeadline((EVENT_QUEST_TIME_LIMIT-lastSec)*10);
				cout << "데드라인 : " << (Turn_t)((EVENT_QUEST_TIME_LIMIT-lastSec)*10) << endl;
				pEffect->setNextTime( ((EVENT_QUEST_TIME_LIMIT-lastSec)%BROADCASTING_DELAY) * 10 );
				m_pOwner->addEffect( pEffect );
			}
		}

		SAFE_DELETE(pStmt);

		if ( !restoring.empty() )
		{
			list<DWORD> broken;

			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			pResult = pStmt->executeQuery("SELECT QuestID, Cond, Position, Status, NumArg, StrArg, State FROM GQuestMissionSave WHERE OwnerID='%s' ORDER BY QuestID, Cond, Position",
					m_pOwner->getName().c_str() );

			while ( pResult->next() )
			{
				DWORD qID = pResult->getDWORD(1);
				if ( find(restoring.begin(), restoring.end(), qID) == restoring.end() ) continue;
				if ( find(broken.begin(), broken.end(), qID) != broken.end() ) continue;

				GQuestStatus* pStatus = getGQuestStatus(qID);
				if ( pStatus == NULL ) continue;

				BYTE cond = pResult->getBYTE(2);
				WORD position = pResult->getWORD(3);
				if ( !pStatus->restoreMission(cond, position, pResult->getBYTE(4), pResult->getDWORD(5),
							pResult->getString(6), pResult->getString(7)) )
				{
					filelog("GQuestError.log", "cannot restore a saved mission (quest data changed?), quest is offered again : [%s]:%u cond %u pos %u",
							m_pOwner->getName().c_str(), (unsigned int)qID, (unsigned int)cond, (unsigned int)position);
					broken.push_back(qID);
				}
			}

			SAFE_DELETE(pStmt);

			list<DWORD>::iterator qItr = restoring.begin();
			for ( ; qItr != restoring.end() ; ++qItr )
			{
				GQuestStatus* pStatus = getGQuestStatus(*qItr);
				if ( pStatus == NULL ) continue;

				if ( find(broken.begin(), broken.end(), *qItr) != broken.end() )
				{
					// forget the attempt; refreshQuest() offers the quest again if it still applies
					pStatus->initMissions();
					pStatus->setStatus( QuestStatusInfo::CAN_REPLAY );
					pStatus->save();
					pStatus->deleteMissions();
					m_QuestStatuses.erase(*qItr);
					SAFE_DELETE( pStatus );
					continue;
				}

				pStatus->finishRestore();
			}
		}
	}
	END_DB(pStmt);

	__END_CATCH
}

void GQuestManager::init()
	throw(Error)
{
	__BEGIN_TRY

	load();
	m_GQuestInventory.load(m_pOwner->getName());
	refreshQuest(false);

	__END_CATCH
}

void GQuestManager::clear()
	throw(Error)
{
	HashMapGQuestStatusItr itr = m_QuestStatuses.begin();
	HashMapGQuestStatusItr endItr = m_QuestStatuses.end();

	for ( ; itr != endItr; ++itr )
	{
		GQuestStatus* pGQuestStatus = itr->second;
		SAFE_DELETE( pGQuestStatus );
	}

	m_QuestStatuses.clear();

	for ( int i = TIMER; i<MAX; ++i )
	{
		m_EventMissions[i].clear();
	}
}

void GQuestManager::save()
	throw(Error)
{
	__BEGIN_TRY

	HashMapGQuestStatusItr itr = m_QuestStatuses.begin();
	HashMapGQuestStatusItr endItr = m_QuestStatuses.end();

	for ( ; itr != endItr ; ++itr )
	{
		GQuestStatus* pStatus = itr->second;
		if ( pStatus == NULL || pStatus->getGQuestInfo() == NULL ) continue;
		if ( pStatus->getStatus() != QuestStatusInfo::DOING && pStatus->getStatus() != QuestStatusInfo::SUCCESS ) continue;

		pStatus->persist();
	}

	__END_CATCH
}

void GQuestManager::refreshQuest(bool sendPacket)
{
	__BEGIN_TRY

	hash_map<DWORD, GQuestInfo*>& infos = GQuestInfoManager::Instance().getInfos();

	hash_map<DWORD, GQuestInfo*>::iterator itr = infos.begin();
	hash_map<DWORD, GQuestInfo*>::iterator endItr = infos.end();

	GQuestStatus *pGQuestStatus = NULL;
	
	for ( ; itr != endItr ; ++itr )
	{
//		if ( m_QuestStatuses[itr->first] != NULL ) continue;
		hash_map<DWORD, GQuestStatus*>::iterator finditr = m_QuestStatuses.find(itr->first);
		if ( finditr != m_QuestStatuses.end() )
		{
			pGQuestStatus = finditr->second; 
			
			if ( pGQuestStatus != NULL && pGQuestStatus->getStatus() == QuestStatusInfo::CAN_ACCEPT )
			{
				if ( !itr->second->isInstanceSuccess(GQuestInfo::HAPPEN, m_pOwner) )
				{
					SAFE_DELETE( finditr->second );
					m_QuestStatuses.erase(finditr);
					continue;
				}
			}
			else
			{
				continue;
			}
		}

		if ( itr->second->isInstanceSuccess(GQuestInfo::HAPPEN, m_pOwner) )
		{
			m_QuestStatuses[itr->first] = itr->second->makeInitStatus(m_pOwner);
		}
	}

	if ( sendPacket )
	{
		Packet* pPacket = getStatusInfoPacket();
		m_pOwner->getPlayer()->sendPacket( pPacket );
		m_pOwner->getPlayer()->sendPacket( m_GQuestInventory.getInventoryPacket() );

		SAFE_DELETE( pPacket );
	}

	__END_CATCH
}

Packet* GQuestManager::getStatusInfoPacket() const
{
	GCGQuestStatusInfo* pRet = new GCGQuestStatusInfo;

	hash_map<DWORD, GQuestStatus*>::const_iterator itr = m_QuestStatuses.begin();
	hash_map<DWORD, GQuestStatus*>::const_iterator endItr = m_QuestStatuses.end();

	for ( ; itr != endItr ; ++itr )
	{
		if ( itr->second != NULL ) pRet->getInfos().push_back( itr->second );
	}

	return pRet;
}

void GQuestManager::accept(DWORD qID)
{
	hash_map<DWORD, GQuestStatus*>::iterator itr = m_QuestStatuses.find(qID);
	if ( itr == m_QuestStatuses.end() )
	{
		cout << "accept : 없다 -_- " << qID << endl;
		return;
	}

//	GQuestStatus* pQS = m_QuestStatuses[qID];
	GQuestStatus* pQS = itr->second;
	if ( pQS == NULL )
	{
		cout << "accept : 널이다 -_- " << qID << endl;
		return;
	}
	if ( pQS->getStatus() != QuestStatusInfo::CAN_ACCEPT && pQS->getStatus() != QuestStatusInfo::CAN_REPLAY )
	{
		cout << "accept : CAN_ACCEPT가 아니다 -_- " << (int)pQS->getStatus() << endl;
		return;
	}

	pQS->initMissions();
	pQS->setStatus( QuestStatusInfo::DOING );
	pQS->checkMissions();

	GCGQuestStatusModify gcModify;
	gcModify.setInfo( pQS );
	gcModify.setType( GCGQuestStatusModify::CURRENT );
	m_pOwner->getPlayer()->sendPacket( &gcModify );

	pQS->persist();
}

void GQuestManager::cancel(DWORD qID)
{
	hash_map<DWORD, GQuestStatus*>::iterator itr = m_QuestStatuses.find(qID);
	if ( itr == m_QuestStatuses.end() )
	{
		cout << "accept : 없다 -_- " << qID << endl;
		return;
	}

//	GQuestStatus* pQS = m_QuestStatuses[qID];
	GQuestStatus* pQS = itr->second;
	if ( pQS == NULL )
	{
		cout << "cancel : 널이다 -_- " << qID << endl;
		return;
	}
	if ( pQS->getStatus() != QuestStatusInfo::DOING )
	{
		cout << "cancel : DOING이 아니다 -_- " << (int)pQS->getStatus() << endl;
		return;
	}

	pQS->setStatus( QuestStatusInfo::CAN_REPLAY );
	pQS->cleanUpMissions();
	pQS->save();
	pQS->persist();

	GCGQuestStatusModify gcModify;
	gcModify.setInfo( pQS );
	gcModify.setType( GCGQuestStatusModify::FAIL );
	m_pOwner->getPlayer()->sendPacket( &gcModify );
}

void GQuestManager::heartbeat()
{
	list<GQuestMission*>::iterator itr = m_EventMissions[TIMER].begin();
	list<GQuestMission*>::iterator endItr = m_EventMissions[TIMER].end();

	for ( ; itr != endItr ; ++itr )
	{
		GQuestTimeMission* pTimeMission = dynamic_cast<GQuestTimeMission*>((*itr));
		if ( pTimeMission == NULL ) continue;

		pTimeMission->updateArg();
		Timeval endTime = pTimeMission->getEndTime();
		if ( gCurrentTime > endTime )
		{
			pTimeMission->m_pParent->update();
			// -_- 땜빵;
			break;
		}
	}
}

void GQuestManager::blooddrain()
{
	list<GQuestMission*>::iterator itr = m_EventMissions[BLOODDRAIN].begin();
	while ( itr != m_EventMissions[BLOODDRAIN].end() )
	{
		GQuestBloodDrainMission* pBloodDrainMission = dynamic_cast<GQuestBloodDrainMission*>((*itr));
		++itr;
		if ( pBloodDrainMission == NULL ) continue;

		pBloodDrainMission->increase();
		char buffer[256];

		if ( m_pOwner->isVampire() )
		{
			sprintf(buffer, g_pStringPool->c_str(STRID_TIMES_BLOODSUCKING), (uint)pBloodDrainMission->getCurrent() ); // 20070814
			GCSystemMessage gcSM;
			gcSM.setMessage(buffer);
			m_pOwner->getPlayer()->sendPacket(&gcSM);
		}
		else if ( m_pOwner->isOusters() )
		{
			sprintf(buffer, g_pStringPool->c_str(STRID_TIMES_ABSORB_ENERGY), (uint)pBloodDrainMission->getCurrent() );
			GCSystemMessage gcSM;
			gcSM.setMessage(buffer);
			m_pOwner->getPlayer()->sendPacket(&gcSM);
		}

		if ( pBloodDrainMission->getGoal() <= pBloodDrainMission->getCurrent() )
		{
			pBloodDrainMission->m_pParent->update();
		}
		else
		{
			GCGQuestStatusModify gcSM;
			gcSM.setInfo( pBloodDrainMission->m_pParent );
			gcSM.setType( GCGQuestStatusModify::NO_MODIFY );
			m_pOwner->getPlayer()->sendPacket( &gcSM );
			pBloodDrainMission->m_pParent->saveMissions();
		}

		// -_- 땜빵;
//		break;
	}
}

void GQuestManager::levelUp()
{
	list<GQuestMission*>::iterator itr = m_EventMissions[LEVELUP].begin();
	while ( itr != m_EventMissions[LEVELUP].end() )
	{
		GQuestLevelMission* pLevelMission = dynamic_cast<GQuestLevelMission*>((*itr));
		++itr;
		if ( pLevelMission == NULL ) continue;

		if ( pLevelMission->isSuccess( m_pOwner ) )
		{
			pLevelMission->m_pParent->update();
			// -_- 땜빵;
//			break;
		}
	}

	refreshQuest();

	if ( m_pOwner->getLevel() == 25 && m_pOwner->getPartyID() != 0 )
	{
		Party* pParty = g_pGlobalPartyManager->getParty( m_pOwner->getPartyID() );
		if ( pParty != NULL && pParty->getSize() == 2 )
		{
			pParty->eventPartyCrash();
		}
	}
}

void GQuestManager::getItem(Item* pItem)
{
}

bool GQuestManager::metNPC(NPC* pNPC)
{
	list<GQuestMission*>::iterator itr = m_EventMissions[MEETNPC].begin();
	while ( itr != m_EventMissions[MEETNPC].end() )
	{
		GQuestSayNPCMission* pSayNPCMission = dynamic_cast<GQuestSayNPCMission*>((*itr));
		++itr;
		if ( pSayNPCMission == NULL ) continue;

		GQuestSayNPCElement* pSayNPCElement = dynamic_cast<GQuestSayNPCElement*>(*pSayNPCMission->m_Position);
		if ( pSayNPCElement == NULL )
		{
			cout << "SayNPCElement 캐스팅 실패!!!!" << endl;
			Assert( false );
		}

//		cout << "check SayNPCElement : " << pSayNPCElement->getTarget() << endl;

		if ( pSayNPCElement->getTarget() == pNPC->getNPCID() && pSayNPCElement->checkVolume( m_pOwner ) )
		{
			pSayNPCMission->meet();
			pSayNPCMission->m_pParent->update();
			// 한번에 한명씩만 만나기
			return true;
		}
	}

	return false;
}

void GQuestManager::tamePet(PetInfo* pPetInfo)
{
	list<GQuestMission*>::iterator itr = m_EventMissions[TAMEPET].begin();
	while ( itr != m_EventMissions[TAMEPET].end() )
	{
		GQuestTamePetMission* pTamePetMission = dynamic_cast<GQuestTamePetMission*>((*itr));
		++itr;
		if ( pTamePetMission == NULL ) continue;

		pTamePetMission->tame();
		pTamePetMission->m_pParent->update();
	}
}

void GQuestManager::killed()
{
	list<GQuestMission*>::iterator itr = m_EventMissions[KILLED].begin();
	while ( itr != m_EventMissions[KILLED].end() )
	{
		GQuestKilledMission* pKilledMission = dynamic_cast<GQuestKilledMission*>((*itr));
		++itr;
		if ( pKilledMission == NULL ) continue;

		pKilledMission->increase();

		if ( pKilledMission->getGoal() <= pKilledMission->getCurrent() )
		{
			pKilledMission->m_pParent->update();
		}
		else
		{
			pKilledMission->m_pParent->saveMissions();
		}

		// -_- 땜빵;
//		break;
	}
}

void GQuestManager::skillLevelUp(SlayerSkillSlot* pSkillSlot)
{
	list<GQuestMission*>::iterator itr = m_EventMissions[SKILL_LEVELUP].begin();
	while ( itr != m_EventMissions[SKILL_LEVELUP].end() )
	{
		GQuestSkillLevelMission* pSkillLevelMission = dynamic_cast<GQuestSkillLevelMission*>((*itr));
		++itr;
		if ( pSkillLevelMission == NULL ) continue;

		if ( pSkillLevelMission->isSuccess( pSkillSlot ) )
		{
			pSkillLevelMission->m_pParent->update();
		}
	}
}

void GQuestManager::rideMotorcycle(bool isParty)
{
	list<GQuestMission*>::iterator itr = m_EventMissions[RIDE_MOTORCYCLE].begin();
	while ( itr != m_EventMissions[RIDE_MOTORCYCLE].end() )
	{
		GQuestRideMotorcycleMission* pRideMotorcycleMission = dynamic_cast<GQuestRideMotorcycleMission*>((*itr));
		++itr;
		if ( pRideMotorcycleMission == NULL ) continue;

		pRideMotorcycleMission->ride();

		if ( pRideMotorcycleMission->isRide() )
		{
			pRideMotorcycleMission->m_pParent->update();
		}

		// -_- 땜빵;
//		break;
	}

	if ( !isParty && m_pOwner->getPartyID() != 0 )
	{
		Party* pParty = g_pGlobalPartyManager->getParty( m_pOwner->getPartyID() );
		if ( pParty != NULL && pParty->getSize() == 2 )
		{
			hash_map<string, Creature*> members = pParty->getMemberMap();
			hash_map<string, Creature*>::iterator itr = members.begin();

			for ( ; itr != members.end() ; ++itr )
			{
				if ( m_pOwner->getZoneID() != itr->second->getZoneID() )
				{
					itr->second->getZone()->lock();
				}

				PlayerCreature* pMember = dynamic_cast<PlayerCreature*>(itr->second);
				pMember->getGQuestManager()->rideMotorcycle(true);

				if ( m_pOwner->getZoneID() != itr->second->getZoneID() )
				{
					itr->second->getZone()->unlock();
				}
			}
		}
	}
}

void GQuestManager::touchWayPoint(PlayerCreature *pPC)
{
	list<GQuestMission*>::iterator itr = m_EventMissions[TOUCH_WAY_POINT].begin();
	while ( itr != m_EventMissions[TOUCH_WAY_POINT].end() )
	{
		GQuestTouchWayPointMission* pTouchWayPointMission = dynamic_cast<GQuestTouchWayPointMission*>((*itr));
		++itr;
		if ( pTouchWayPointMission == NULL ) continue;

		GQuestTouchWayPointElement* pTouchWayPointElement = dynamic_cast<GQuestTouchWayPointElement*>(*pTouchWayPointMission->m_Position);
		if ( pTouchWayPointElement == NULL )
		{
			cout << "TouchWayPointElement 캐스팅 실패!!!!" << endl;
			Assert( false );
		}

		if ( pTouchWayPointElement->m_ZoneID == m_pOwner->getZoneID() &&
			pTouchWayPointElement->m_X == pPC->getX() &&
			pTouchWayPointElement->m_Y == pPC->getY() )
		{
			// 해당 위치에 서 있으면 미션 성공
			pTouchWayPointMission->touch();

			pTouchWayPointMission->m_pParent->update();
		}
	}
}

void GQuestManager::touchWayPoint(MonsterCorpse* pWayPoint)
{
	cout << "touchWayPoint : " << m_pOwner->getName() << endl;
	list<GQuestMission*>::iterator itr = m_EventMissions[TOUCH_WAY_POINT].begin();
	while ( itr != m_EventMissions[TOUCH_WAY_POINT].end() )
	{
		GQuestTouchWayPointMission* pTouchWayPointMission = dynamic_cast<GQuestTouchWayPointMission*>((*itr));
		++itr;
		if ( pTouchWayPointMission == NULL ) continue;

		GQuestTouchWayPointElement* pTouchWayPointElement = dynamic_cast<GQuestTouchWayPointElement*>(*pTouchWayPointMission->m_Position);
		if ( pTouchWayPointElement == NULL )
		{
			cout << "TouchWayPointElement 캐스팅 실패!!!!" << endl;
			Assert( false );
		}

		if ( pTouchWayPointElement->m_ZoneID == m_pOwner->getZoneID() &&
			pTouchWayPointElement->m_X == pWayPoint->getX() &&
			pTouchWayPointElement->m_Y == pWayPoint->getY() )
		{
			if ( pTouchWayPointElement->m_Type != pWayPoint->getMonsterType() )
				cout << "몬스터 타입이 다르다!! 먼일이지 -_-" << endl;
			pTouchWayPointMission->touch();

			pTouchWayPointMission->m_pParent->update();
		}
	}

	if ( m_pOwner->getPartyID() != 0 )
	{
		Party* pParty = g_pGlobalPartyManager->getParty( m_pOwner->getPartyID() );
		if ( pParty != NULL && pParty->getSize() == 2 )
		{
			hash_map<string, Creature*> members = pParty->getMemberMap();
			hash_map<string, Creature*>::iterator itr = members.begin();

			for ( ; itr != members.end() ; ++itr )
			{
				if ( m_pOwner->getZoneID() != itr->second->getZoneID() )
				{
					itr->second->getZone()->lock();
				}

				PlayerCreature* pMember = dynamic_cast<PlayerCreature*>(itr->second);
				pMember->getGQuestManager()->partyTravel(pWayPoint);

				if ( m_pOwner->getZoneID() != itr->second->getZoneID() )
				{
					itr->second->getZone()->unlock();
				}
			}
		}
	}
}

void GQuestManager::killedMonster(Monster* pMonster)
{
	list<GQuestMission*>::iterator itr = m_EventMissions[KILLMONSTER].begin();
	while ( itr != m_EventMissions[KILLMONSTER].end() )
	{
		GQuestKillMonsterMission* pKillMonsterMission = dynamic_cast<GQuestKillMonsterMission*>((*itr));
		++itr;
		if ( pKillMonsterMission == NULL ) continue;

		if ( pKillMonsterMission->isTarget( pMonster->getMonsterType() ) )
		{
			pKillMonsterMission->increase();
			GQuestKillMonsterElement* pKillMonsterElement = dynamic_cast<GQuestKillMonsterElement*>(*pKillMonsterMission->m_Position);
			if ( pKillMonsterElement == NULL )
			{
				cout << "KillMonsterElement 캐스팅 실패!!!!" << endl;
				Assert( false );
			}
			if ( pKillMonsterElement->getGoal() >= pKillMonsterMission->getCurrent() )
			{
				pKillMonsterMission->m_pParent->update();
			}
		}
	}
}

void GQuestManager::partyDissect(MonsterCorpse* pMonsterCorpse)
{
	cout << "partyDissect : " << endl;
	list<GQuestMission*>::iterator itr = m_EventMissions[PARTY_DISSECT].begin();
	while ( itr != m_EventMissions[PARTY_DISSECT].end() )
	{
		GQuestPartyDissectMission* pPartyDissectMission = dynamic_cast<GQuestPartyDissectMission*>((*itr));
		++itr;
		if ( pPartyDissectMission == NULL ) continue;

		cout << "목표 : " << pPartyDissectMission->m_StrArg << endl;
		cout << "숫자 : " << (int)pPartyDissectMission->getTargetList().front() << endl;
		cout << "잡은놈 : " << pMonsterCorpse->getMonsterType() << endl;

		if ( pPartyDissectMission->isTarget( g_pMonsterInfoManager->getMonsterInfo(pMonsterCorpse->getMonsterType())->getSpriteType() ) )
		{
			GQuestPartyDissectElement* pPartyDissectElement = dynamic_cast<GQuestPartyDissectElement*>(*pPartyDissectMission->m_Position);
			if ( pPartyDissectElement == NULL )
			{
				cout << "PartyDissectElement 캐스팅 실패!!!!" << endl;
				Assert( false );
			}
			pPartyDissectMission->increase();
			cout << "partyDissect : +1" << endl;
			if ( pPartyDissectElement->getGoal() <= pPartyDissectMission->getCurrent() )
			{
				pPartyDissectMission->m_pParent->update();
			}
			else
			{
				GCGQuestStatusModify gcSM;
				gcSM.setInfo( pPartyDissectMission->m_pParent );
				gcSM.setType( GCGQuestStatusModify::NO_MODIFY );
				m_pOwner->getPlayer()->sendPacket( &gcSM );
			}
		}
	}
}

void GQuestManager::eventParty()
{
	m_bPartyQuest = true;
	cout << "이벤트 파티가 결성되었습니다. : " << m_pOwner->getName() << endl;
	list<GQuestMission*>::iterator itr = m_EventMissions[EVENT_PARTY].begin();
	while ( itr != m_EventMissions[EVENT_PARTY].end() )
	{
		GQuestEventPartyMission* pEventPartyMission = dynamic_cast<GQuestEventPartyMission*>((*itr));
		++itr;
		if ( pEventPartyMission == NULL ) continue;

		GQuestEventPartyElement* pEventPartyElement = dynamic_cast<GQuestEventPartyElement*>(*pEventPartyMission->m_Position);
		if ( pEventPartyElement == NULL )
		{
			cout << "EventPartyElement 캐스팅 실패!!!!" << endl;
			Assert( false );
		}

//		cout << "check EventPartyElement : " << pEventPartyElement->getTarget() << endl;

		pEventPartyMission->meet();
		pEventPartyMission->m_pParent->update();
	}
}

void GQuestManager::eventPartyCrash()
{
	m_bPartyQuest = false;
	cout << "이벤트 파티가 깨졌습니다. : " << m_pOwner->getName() << endl;
	list<GQuestMission*>::iterator itr = m_EventMissions[EVENT_PARTY_CRASH].begin();
	while ( itr != m_EventMissions[EVENT_PARTY_CRASH].end() )
	{
		GQuestEventPartyCrashMission* pEventPartyCrashMission = dynamic_cast<GQuestEventPartyCrashMission*>((*itr));
		++itr;
		if ( pEventPartyCrashMission == NULL ) continue;

		GQuestEventPartyCrashElement* pEventPartyCrashElement = dynamic_cast<GQuestEventPartyCrashElement*>(*pEventPartyCrashMission->m_Position);
		if ( pEventPartyCrashElement == NULL )
		{
			cout << "EventPartyCrashElement 캐스팅 실패!!!!" << endl;
			Assert( false );
		}

//		cout << "check EventPartyCrashElement : " << pEventPartyCrashElement->getTarget() << endl;

		pEventPartyCrashMission->meet();
		pEventPartyCrashMission->m_pParent->update();
	}
}

void GQuestManager::fastMove(bool isParty)
{
	list<GQuestMission*>::iterator itr = m_EventMissions[FASTMOVE].begin();
	while ( itr != m_EventMissions[FASTMOVE].end() )
	{
		GQuestFastMoveMission* pFastMoveMission = dynamic_cast<GQuestFastMoveMission*>((*itr));
		++itr;
		if ( pFastMoveMission == NULL ) continue;

		pFastMoveMission->ride();

		if ( pFastMoveMission->isRide() )
		{
			pFastMoveMission->m_pParent->update();
		}
	}

	if ( !isParty && m_pOwner->getPartyID() != 0 )
	{
		Party* pParty = g_pGlobalPartyManager->getParty( m_pOwner->getPartyID() );
		if ( pParty != NULL && pParty->getSize() == 2 )
		{
			hash_map<string, Creature*> members = pParty->getMemberMap();
			hash_map<string, Creature*>::iterator itr = members.begin();

			for ( ; itr != members.end() ; ++itr )
			{
				if ( m_pOwner->getZoneID() != itr->second->getZoneID() )
				{
					itr->second->getZone()->lock();
				}

				PlayerCreature* pMember = dynamic_cast<PlayerCreature*>(itr->second);
				pMember->getGQuestManager()->fastMove(true);

				if ( m_pOwner->getZoneID() != itr->second->getZoneID() )
				{
					itr->second->getZone()->unlock();
				}
			}
		}
	}
}

void GQuestManager::illegalWarp(bool isParty)
{
	list<GQuestMission*>::iterator itr = m_EventMissions[ILLEGAL_WARP].begin();
	while ( itr != m_EventMissions[ILLEGAL_WARP].end() )
	{
		GQuestIllegalWarpMission* pIllegalWarpMission = dynamic_cast<GQuestIllegalWarpMission*>((*itr));
		++itr;
		if ( pIllegalWarpMission == NULL ) continue;

		pIllegalWarpMission->ride();

		if ( pIllegalWarpMission->isRide() )
		{
			pIllegalWarpMission->m_pParent->update();
		}
	}

	if ( !isParty && m_pOwner->getPartyID() != 0 )
	{
		Party* pParty = g_pGlobalPartyManager->getParty( m_pOwner->getPartyID() );
		if ( pParty != NULL && pParty->getSize() == 2 )
		{
			hash_map<string, Creature*> members = pParty->getMemberMap();
			hash_map<string, Creature*>::iterator itr = members.begin();

			for ( ; itr != members.end() ; ++itr )
			{
				if ( m_pOwner->getZoneID() != itr->second->getZoneID() )
				{
					itr->second->getZone()->lock();
				}

				PlayerCreature* pMember = dynamic_cast<PlayerCreature*>(itr->second);
				pMember->getGQuestManager()->illegalWarp(true);

				if ( m_pOwner->getZoneID() != itr->second->getZoneID() )
				{
					itr->second->getZone()->unlock();
				}
			}
		}
	}
}

void GQuestManager::partyTravel(MonsterCorpse* pCorpse)
{
	cout << "partyTravel : " << m_pOwner->getName();
	DWORD id = GQuestCheckPoint::Instance().getCheckPointID( pCorpse );
	if ( id == 0 ) return;

	list<GQuestMission*>::iterator itr = m_EventMissions[TRAVEL].begin();
	while ( itr != m_EventMissions[TRAVEL].end() )
	{
		GQuestTravelMission* pTravelMission = dynamic_cast<GQuestTravelMission*>((*itr));
		++itr;
		if ( pTravelMission == NULL ) continue;

		if ( pTravelMission->isTarget(id) && !pTravelMission->isVisited(id) )
		{
			pTravelMission->increase();
			pTravelMission->getVisitedList().push_back( id );
			pTravelMission->updateStr();
			pTravelMission->m_pParent->update();
		}

	}
}

void GQuestManager::advancementClassLevelUp()
{
	list<GQuestMission*>::iterator itr = m_EventMissions[ADVANCEMENT_LEVELUP].begin();
	while ( itr != m_EventMissions[ADVANCEMENT_LEVELUP].end() )
	{
		GQuestAdvancementClassLevelMission* pAdvancementClassLevelMission = dynamic_cast<GQuestAdvancementClassLevelMission*>((*itr));
		++itr;
		if ( pAdvancementClassLevelMission == NULL ) continue;

		if ( pAdvancementClassLevelMission->isSuccess( m_pOwner ) )
		{
			pAdvancementClassLevelMission->m_pParent->update();
			// -_- 땜빵;
//			break;
		}
	}

	refreshQuest();
}

void GQuestManager::clearDynamicZone(ZoneID_t zoneID)
{
	list<GQuestMission*>::iterator itr = m_EventMissions[CLEAR_DYNAMIC_ZONE].begin();
	while ( itr != m_EventMissions[CLEAR_DYNAMIC_ZONE].end() )
	{
		GQuestClearDynamicZoneMission* pClearDynamicZoneMission = dynamic_cast<GQuestClearDynamicZoneMission*>((*itr));
		++itr;
		if ( pClearDynamicZoneMission == NULL ) continue;
		pClearDynamicZoneMission->clear(zoneID);

		if ( pClearDynamicZoneMission->isClear() )
		{
			pClearDynamicZoneMission->m_pParent->update();
			// -_- 땜빵;
//			break;
		}
	}
}

void GQuestManager::enterDynamicZone(ZoneID_t zoneID)
{
	list<GQuestMission*>::iterator itr = m_EventMissions[ENTER_DYNAMIC_ZONE].begin();
	while ( itr != m_EventMissions[ENTER_DYNAMIC_ZONE].end() )
	{
		GQuestEnterDynamicZoneMission* pEnterDynamicZoneMission = dynamic_cast<GQuestEnterDynamicZoneMission*>((*itr));
		++itr;
		if ( pEnterDynamicZoneMission == NULL ) continue;
		pEnterDynamicZoneMission->enter(zoneID);

		if ( pEnterDynamicZoneMission->isEnter() )
		{
			pEnterDynamicZoneMission->m_pParent->update();
			// -_- 땜빵;
//			break;
		}
	}
}

GQuestStatus* GQuestManager::getGQuestStatus(DWORD qID)
{
	hash_map<DWORD, GQuestStatus*>::iterator itr = m_QuestStatuses.find(qID);

	if ( itr == m_QuestStatuses.end() ) return NULL;

	return itr->second;
}

void GQuestManager::eraseQuest(DWORD qID)
{
	hash_map<DWORD, GQuestStatus*>::iterator itr = m_QuestStatuses.find(qID);
	if ( itr != m_QuestStatuses.end() ) m_QuestStatuses.erase(itr);

	Statement* pStmt = NULL;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pStmt->executeQuery("DELETE FROM GQuestSave WHERE OwnerID='%s' AND QuestID='%u'",
				m_pOwner->getName().c_str(), qID);

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt);

}
