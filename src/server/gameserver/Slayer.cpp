//////////////////////////////////////////////////////////////////////////////
// Filename    : Slayer.cpp
// Written By  : Elca
// Description :
//////////////////////////////////////////////////////////////////////////////

#include "DB.h"
#include "Slayer.h"
#include "Player.h"
#include "LogClient.h"
#include "EffectManager.h"
//#include <algo.h>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>

#include "SkillInfo.h"
#include "RareBookSkill.h"
#include "ItemInfoManager.h"
#include "ParkingCenter.h"
#include "SkillHandlerManager.h"
#include "SkillDomainInfoManager.h"
#include "ResurrectLocationManager.h"
#include "WarSystem.h"
#include "GamePlayer.h"
#include "PKZoneInfoManager.h"
#include "CastleInfoManager.h"
#include "CastleSkillInfo.h"

#include "OptionInfo.h"
#include "EffectLoaderManager.h"
#include "AbilityBalance.h"
#include "Stash.h"
#include "TradeManager.h"
#include "CreatureUtil.h"
#include "FlagSet.h"
//#include "AttrBalanceInfo.h"
#include "Party.h"
#include "Shape.h"
#include "VariableManager.h"

#include "ItemUtil.h"
#include "PacketUtil.h"
//#include "RankEXPInfo.h"

#include "item/Motorcycle.h"
#include "item/AR.h"
#include "item/SR.h"
#include "item/SG.h"
#include "item/SMG.h"
#include "item/Belt.h"
#include "item/Skull.h"
#include "item/SubInventory.h"
#include "item/Key.h"

#include "skill/CastleSkillSlot.h"
#include "skill/EffectBless.h"
#include "skill/EffectDancingSword.h"
#include "skill/EffectGhostBlade.h"
#include "skill/EffectChargingPower.h"
#include "skill/EffectPotentialExplosion.h"
#include "skill/EffectParalyze.h"
#include "skill/EffectDoom.h"
#include "skill/EffectProtectionFromPoison.h"
#include "skill/EffectProtectionFromCurse.h"
#include "skill/EffectProtectionFromAcid.h"
#include "EffectGrandMasterSlayer.h"
#include "EffectHoodlumStigma.h"
#include "EffectRecallMotorcycle.h"
#include "EffectBonusExp.h"
#include "EffectBonusExpSecond.h"
#include "EffectBonusExpAdvance.h"
#include "EffectChaoticExp.h"

#include "Cpackets/CGRideMotorCycle.h"

#include "Gpackets/GCAddEffect.h"
#include "Gpackets/GCRemoveEffect.h"
#include "Gpackets/GCModifyInformation.h"
#include "Gpackets/GCChangeShape.h"
#include "Gpackets/GCTakeOff.h"
#include "Gpackets/GCSkillInfo.h"
#include "Gpackets/GCRealWearingInfo.h"
#include "Gpackets/GCStatusCurrentHP.h"
#include "Gpackets/GCTradeFinish.h"
#include "Gpackets/GCOtherModifyInfo.h"
#include "Gpackets/GCPetStashList.h"
#include "Gpackets/GCAddSlayer.h"
#include "Gpackets/GCGetOffMotorCycle.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "Rpackets/RCSay.h"
#include "LoginServerManager.h"
#include "Properties.h"
//#include "RankEXPInfo.h"
#include "RaceWarLimiter.h"
#include "TimeLimitItemManager.h"
#include "RankExpTable.h"
#include "SlayerAttrExpTable.h"
#include "ExpFwd.h"

#include "skill/SkillUtil.h"

#include "SystemAvailabilitiesManager.h"
#include "types/ServerType.h"

#include "MonsterInfo.h"
#include "GuildUnion.h"
#include "Store.h"
#include "AdvancementClassExpTable.h"
#include "DynamicZone.h"
#include "DynamicZoneManager.h"

// 2007 01 03
#include "VSDateTime.h"
#ifdef __CONTRIBUTION_SYSTEM__
#include "LevelWarZoneInfoManager.h"
#endif
//#include "PlayerInventory.h"

#include "DBExecuteManager.h"

#include <sstream>

const Color_t UNIQUE_COLOR = 0xFFFF;
const Color_t UNIQUE_OPTION = 0xFFFF;

const Color_t QUEST_COLOR = 0xFFFE;
const Color_t QUEST_OPTION = 0xFFFE;

const Attr_t MAX_SLAYER_ATTR = 290;
const Attr_t MAX_SLAYER_SUM = 435;
const Attr_t MAX_SLAYER_ATTR_OLD = 200;
const Attr_t MAX_SLAYER_SUM_OLD = 300;
const Attr_t MAX_SLAYER_GEARSLOT = 2;

Slayer::Slayer () 
	throw () 
: PlayerCreature(0,NULL)
{
	__BEGIN_TRY

	m_CClass = CREATURE_CLASS_SLAYER;

	m_Mutex.setName("Slayer");

	// AttackMelee 같은 기본 기술을 집어넣어준다.
	for (int i=0; i<SKILL_DOUBLE_IMPACT; i++)
	{
		SlayerSkillSlot* pSkillSlot = new SlayerSkillSlot;
		//pSkillSlot = new SkillSlot;	// 2002.1.16  by sigi
		pSkillSlot->setName(m_Name);

		pSkillSlot->setSkillType(i);
		pSkillSlot->setInterval(5);
		pSkillSlot->setExpLevel(1);
		pSkillSlot->setExp(1);
		pSkillSlot->setRunTime();
		addSkill(pSkillSlot);
	}

	m_CurrentGearSlotID = 0;
	initWearItemSlot(WEAR_MAX, MAX_SLAYER_GEARSLOT);

	// Motorcycle을 Null 로 만든다.
	m_pMotorcycle = NULL;

	for (int i = 0; i < MAX_PHONE_SLOT; i++) 
	{
		m_PhoneSlot[i] = 0;
	}

	// 핫 키를 초기화 한다.
//	for (int i = 0; i < 4; i++) 
//	{
//		m_HotKey[i] = 0;
//	}

	// MP 리젠 시간 초기화
	getCurrentTime(m_MPRegenTime);

	// 경험치 세이브 카운트를 초기화한다.
	m_DomainExpSaveCount = 0;
	m_AttrExpSaveCount   = 0;
	m_SkillExpSaveCount  = 0;
	m_FameSaveCount      = 0;
	m_AlignmentSaveCount = 0;
//	m_RankExpSaveCount   = 0;
	m_Gold				 = 0;

	// 2006.09.11 겜블 추가
	m_GambleTryCount	 = 0;
	m_GambleAccumulation = 0;

//	m_pRank = NULL;

	m_pAddPacket = new GCAddSlayer;

	__END_CATCH
}

Slayer::~Slayer() 
    throw ()
{
	__BEGIN_TRY

	try 
	{
		if (getObjectID() != 0 )
		{
			if (m_pMotorcycle != NULL) 
			{
				//getOffMotorcycle();

				// 이거 IncomingPlayerManager에서 해버리면 문제가 된다..
				// 그래서.. 그냥 오토바이를 없애버리도록 하자. 2002.7.15 by sigi
				if (g_pParkingCenter->hasMotorcycleBox(m_pMotorcycle->getItemID()))
				{
					g_pParkingCenter->deleteMotorcycleBox(m_pMotorcycle->getItemID());
				}

				m_pMotorcycle = NULL;
			}
			
			// 복장 정보를 생성해둔다. by sigi. 2002.6.18
			DWORD 	flag;
			Color_t color[PCSlayerInfo::SLAYER_COLOR_MAX];
			getShapeInfo (flag, color);

			char pField[128];
			sprintf(pField, "Shape=%ld, HelmetColor=%d, JacketColor=%d, PantsColor=%d, WeaponColor=%d, ShieldColor=%d", 
							flag,
							color[PCSlayerInfo::SLAYER_COLOR_HELMET],
							color[PCSlayerInfo::SLAYER_COLOR_JACKET],
							color[PCSlayerInfo::SLAYER_COLOR_PANTS],
							color[PCSlayerInfo::SLAYER_COLOR_WEAPON],
							color[PCSlayerInfo::SLAYER_COLOR_SHIELD]);

			//cout << "SAVE = " << pField << endl;
				
			tinysave(pField);


			// 떨어진 아이템의 내구성과 경험치, 성향 등을 저장한다.
			saveGears();
			saveExps();
			saveSkills();
			
			// 입고 있는 아이템을 메모리에서 삭제한다. 
			destroyGears();
			
			// 클래스가 삭제될 경우, 해당하는 교환 정보를 삭제해야 함은 물론,
			// 교환 상대에게도 이 사실을 알려줘야 한다.
			TradeManager* pTradeManager = m_pZone->getTradeManager();
			TradeInfo* pInfo = pTradeManager->getTradeInfo(getName());
			if (pInfo != NULL)
			{
				// 교환 정보를 삭제
				pTradeManager->cancelTrade(this);
			}
			
			// 글로벌 파티에서 삭제한다.
			// 일반적인 로그아웃의 경우에는
			// CGLogoutHandler에서 Zone::deleteCreature() 함수를 부르게 되고,
			// 비정상적인 경우라고 해도, 
			// GamePlayer::disconnect()에서 Zone::deleteCreature() 함수를 부르게 되므로,
			// 로컬 파티 및 파티 초대, 트레이드 정보를 걱정할 필요는 없다.
			deleteAllPartyInfo(this);

			// 기술들을 삭제
			hash_map<SkillType_t, SlayerSkillSlot*>::iterator itr = m_SkillSlot.begin();
			for (; itr != m_SkillSlot.end(); itr++)
			{
				SlayerSkillSlot* pSkillSlot = itr->second;
				SAFE_DELETE(pSkillSlot);
			}

			m_SkillSlot.clear();
			
			g_GameDBExecuteManager.DeallocateExecuteUnit(getObjectID());
		}
	} 
	catch (Throwable& t) 
	{
		filelog("slayerDestructor.txt", "%s", t.toString().c_str());
		throw;
	} 
	catch (exception& e) 
	{
		filelog("slayerDestructor.txt", "Unknown std::exception");
		throw;
	} 
	catch (...) 
	{
		filelog("slayerDestructor.txt", "Unknown ... exception");
		throw;
	}

	try
	{
//		SAFE_DELETE( m_pRank );
		SAFE_DELETE( m_pAddPacket );		
	} 
	catch (Throwable& t) 
	{
		filelog("slayerDestructor.txt", "%s", t.toString().c_str());
		throw;
	} 
	catch (exception& e) 
	{
		filelog("slayerDestructor.txt", "Unknown std::exception");
		throw;
	} 
	catch (...) 
	{
		filelog("slayerDestructor.txt", "Unknown ... exception");
		throw;
	}


	m_bDeriveDestructed = true;
	
	__END_CATCH
}

// Zone에 종속된 ObjectRegistry를 사용해서, Slayer 와 소유아이템들의
// ObjectID를 할당받는다.
void Slayer::registerObject ()
	throw (Error)
{
	__BEGIN_TRY

	Assert(getZone() != NULL);

	// zone 의 object registery 에 접근한다.
	ObjectRegistry & OR = getZone()->getObjectRegistry();

	__ENTER_CRITICAL_SECTION(OR)

	// 모든 아이템에 OID 가 바뀌므로 시간제한 아이템 매니저에서 OID 맵을 지워줘야 한다.
	if (m_pTimeLimitItemManager != NULL)
		m_pTimeLimitItemManager->clear();

	// 우선 슬레이어의 OID를 등록받는다.
	OR.registerObject_NOLOCKED(this);

	// 인벤토리의 아이템들의 OID를 등록받는다.
	registerInventory(OR);

	// Goods Inventory의 아이템들의 OID를 등록받는다.
	registerGoodsInventory(OR);

	// 장착하고 있는 아이템들의 OID를 등록받는다.
	for(GearSlotID_t GearID = 0; GearID < m_pWearItemSwapPool.size(); ++GearID)
	{
		for (int i = 0; i < m_pWearItemSwapPool[GearID].size(); i++) 
		{
			Item* pItem = m_pWearItemSwapPool[GearID][i];

			if (pItem != NULL) 
			{
				bool bCheck = true;

				// 양손 무기일 경우, WEAR_LEFTHAND 에서 등록했으므로,
				// 또 등록할 필요는 없다.
				if (i == WEAR_RIGHTHAND && isTwohandWeapon(pItem))
					bCheck = false;

				if (bCheck) registerItem(pItem, OR);
			}
		}
	}

	// 마우스에 들고 있는 아이템의 OID를 등록 받는다.
	Item* pSlotItem = m_pExtraInventorySlot->getItem();
	if (pSlotItem != NULL) registerItem(pSlotItem, OR);

	// 오토바이의 OID를 등록 받는다.
	if (m_pMotorcycle != NULL) 
		OR.registerObject_NOLOCKED(m_pMotorcycle);

	m_Garbage.registerObject(OR);

	for ( int i=0; i<MAX_PET_STASH; ++i )
	{
		Item* pItem = getPetStashItem(i);
		if ( pItem != NULL ) registerItem( pItem, OR );
	}

	__LEAVE_CRITICAL_SECTION(OR)

	m_SlayerInfo.setObjectID(m_ObjectID);
	m_pStore->updateStoreInfo();

	__END_CATCH
}

// Zone에 종속된 ObjectRegistry를 사용해서, Slayer 와 소유아이템들의
// ObjectID를 할당받는다. 초기에 ItemTrace 를 위해 따로 뺌
void Slayer::registerInitObject ()
	throw (Error)
{
	__BEGIN_TRY

	Assert(getZone() != NULL);

	// zone 의 object registery 에 접근한다.
	ObjectRegistry & OR = getZone()->getObjectRegistry();

	__ENTER_CRITICAL_SECTION(OR)

	// 모든 아이템에 OID 가 바뀌므로 시간제한 아이템 매니저에서 OID 맵을 지워줘야 한다.
	if (m_pTimeLimitItemManager != NULL)
		m_pTimeLimitItemManager->clear();

	// 우선 슬레이어의 OID를 등록받는다.
	OR.registerObject_NOLOCKED(this);

	// 인벤토리의 아이템들의 OID를 등록받는다.
	registerInitInventory(OR);

	// Goods Inventory의 아이템들의 OID를 등록받는다.
	registerGoodsInventory(OR);

	// 장착하고 있는 아이템들의 OID를 등록받는다.
	for(GearSlotID_t GearID = 0; GearID < m_pWearItemSwapPool.size(); ++GearID)	
	{
		for (int i = 0; i < m_pWearItemSwapPool[GearID].size(); i++)
		{
			Item* pItem = m_pWearItemSwapPool[GearID][i];

			if (pItem != NULL) 
			{
				// ItemTrace 를 남길 것인지 결정
				pItem->setTraceItem( bTraceLog( pItem ) );

				bool bCheck = true;

				// 양손 무기일 경우, WEAR_LEFTHAND 에서 등록했으므로,
				// 또 등록할 필요는 없다.
				if (i == WEAR_RIGHTHAND && isTwohandWeapon(pItem))
					bCheck = false;

				if (bCheck) registerItem(pItem, OR);
			}
		}
	}

	// 마우스에 들고 있는 아이템의 OID를 등록 받는다.
	Item* pSlotItem = m_pExtraInventorySlot->getItem();
	if (pSlotItem != NULL)
	{
		// ItemTrace 를 남길 것인지 결정
		pSlotItem->setTraceItem( bTraceLog( pSlotItem ) );
		registerItem(pSlotItem, OR);
	}

	// 오토바이의 OID를 등록 받는다.
	if (m_pMotorcycle != NULL) 
		OR.registerObject_NOLOCKED(m_pMotorcycle);

	m_Garbage.registerObject(OR);

	__LEAVE_CRITICAL_SECTION(OR)

	m_SlayerInfo.setObjectID(m_ObjectID);

	__END_CATCH
}

Packet* Slayer::getAddPacket() const
{
	m_pAddPacket->setSlayerInfo(getSlayerInfo3());
	m_pAddPacket->setEffectInfo(getEffectInfo());
	m_pAddPacket->setPetInfo(getPetInfo());
	m_pAddPacket->setNicknameInfo(getNickname());
	m_pAddPacket->setStoreInfo(&(getStore()->getStoreInfo()));

	return m_pAddPacket;
}

// 시간제한 아이템을 체크한다.
// 모든 아이템이 이미 register 되어있어야 한다.
void Slayer::checkItemTimeLimit() throw (Error)
{
	__BEGIN_TRY

	// 인벤토리에서 찾는다.
	{
		list<Item*> ItemList;
		int height = m_pInventory->getHeight();
		int width  = m_pInventory->getWidth();

		for (int j=0; j<height; j++)
		{
			for (int i=0; i<width; i++)
			{
				Item* pItem = m_pInventory->getItem(i, j);
				if (pItem != NULL)
				{
					// 체크된 아이템의 리스트에서 현재 아이템을 찾는다.
					list<Item*>::iterator itr = find(ItemList.begin(), ItemList.end(), pItem);

					if (itr == ItemList.end())
					{
						i += pItem->getVolumeWidth() - 1;

						if ( wasteIfTimeLimitExpired( pItem ) )
						{
							m_pInventory->deleteItem( pItem->getObjectID() );
							SAFE_DELETE( pItem );
						}
						else
						{
							// 리스트에 아이템이 없으면
							// 같은 아이템을 두번 체크하지 않기 위해서
							// 리스트에다가 아이템을 집어넣는다.
							ItemList.push_back(pItem);
						}

						// 서브 인벤토리일 경우 안에도 찾는다.
						if ( pItem != NULL && pItem->getItemClass() == Item::ITEM_CLASS_SUB_INVENTORY )
						{
							SubInventory* pSubInventoryItem = dynamic_cast<SubInventory*>(pItem);
							Assert( pSubInventoryItem != NULL );
							Inventory* pSubInventory = pSubInventoryItem->getInventory();
							Assert( pSubInventory != NULL );

							list<Item*> SubItemList;

							for ( CoordInven_t sy = 0; sy < pSubInventory->getHeight(); ++sy )
							{
								for ( CoordInven_t sx = 0; sx < pSubInventory->getWidth(); ++sx )
								{
									Item* pSubItem = pSubInventory->getItem( sx, sy );

									if ( pSubItem != NULL )
									{
										// 체크된 아이템의 리스트에서 현재 아이템을 찾는다.
										list<Item*>::iterator itr = find(SubItemList.begin(), SubItemList.end(), pSubItem);

										if ( itr == SubItemList.end() )
										{
											if ( wasteIfTimeLimitExpired( pSubItem ) )
											{
												pSubInventory->deleteItem( pSubItem->getObjectID() );
												SAFE_DELETE( pSubItem );
											}
										}
										else
										{
											// 리스트에 아이템이 없으면
											// 같은 아이템을 두번 체크하지 않기 위해서
											// 리스트에다가 아이템을 집어넣는다.
											SubItemList.push_back(pSubItem);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	// 장착하고 있는 것 중에 찾는다.
	{
		for(GearSlotID_t GearSlotID = 0; GearSlotID < m_pWearItemSwapPool.size(); ++GearSlotID)
		{
			for (int i = 0; i < m_pWearItemSwapPool[GearSlotID].size(); i++)
			{
				Item* pItem = m_pWearItemSwapPool[GearSlotID][i];

				if (pItem != NULL) 
				{
					bool bCheck = true;

					if (i == WEAR_RIGHTHAND && isTwohandWeapon(pItem))
						bCheck = false;

					if (bCheck) 
					{
						if ( wasteIfTimeLimitExpired( pItem ) )
						{
							deleteWearItem(GearSlotID, (WearPart)i );
							if ( i == WEAR_LEFTHAND && isTwohandWeapon( pItem ) )
								deleteWearItem(GearSlotID, WEAR_RIGHTHAND );
							SAFE_DELETE( pItem );
						}
					}
				}
			}
		}
	}

	// 마우스에 들고 있는 아이템을 체크한다.
	{
		Item* pSlotItem = m_pExtraInventorySlot->getItem();
		if (pSlotItem != NULL && wasteIfTimeLimitExpired( pSlotItem ) )
		{
			deleteItemFromExtraInventorySlot();
			SAFE_DELETE( pSlotItem );
		}
	}

	// 오토바이를 체크한다.
	// 일단 복잡해서 오토바이는 시간제한 안함
/*	{
		if (m_pMotorcycle != NULL && wasteIfTimeLimitExpired( m_pMotorcycle ) )
		{
		}
	}*/

	__END_CATCH
}

void Slayer::updateEventItemTime( DWORD time ) throw(Error)
{
	__BEGIN_TRY

	// 인벤토리에서 찾는다.
	{
		list<Item*> ItemList;
		int height = m_pInventory->getHeight();
		int width  = m_pInventory->getWidth();

		for (int j=0; j<height; j++)
		{
			for (int i=0; i<width; i++)
			{
				Item* pItem = m_pInventory->getItem(i, j);
				if (pItem != NULL)
				{
					// 체크된 아이템의 리스트에서 현재 아이템을 찾는다.
					list<Item*>::iterator itr = find(ItemList.begin(), ItemList.end(), pItem);

					if (itr == ItemList.end())
					{
						i += pItem->getVolumeWidth() - 1;

						updateItemTimeLimit( pItem, time );

						// 리스트에 아이템이 없으면
						// 같은 아이템을 두번 체크하지 않기 위해서
						// 리스트에다가 아이템을 집어넣는다.
						ItemList.push_back(pItem);
					}
				}
			}
		}
	}

	// 장착하고 있는 것 중에 찾는다.
	{
		for(GearSlotID_t GearSlotID = 0; GearSlotID < m_pWearItemSwapPool.size(); ++GearSlotID)
		{
			for (int i = 0; i < m_pWearItemSwapPool[GearSlotID].size(); i++)
			{
				Item* pItem = m_pWearItemSwapPool[GearSlotID][i];

				if (pItem != NULL) 
				{
					bool bCheck = true;

					if (i == WEAR_RIGHTHAND && isTwohandWeapon(pItem))
						bCheck = false;

					if (bCheck) 
					{
						updateItemTimeLimit( pItem, time );
					}
				}
			}
		}
	}

	// 마우스에 들고 있는 아이템을 체크한다.
	{
		Item* pSlotItem = m_pExtraInventorySlot->getItem();
		if (pSlotItem != NULL)
		{
			updateItemTimeLimit( pSlotItem, time );
		}
	}

	__END_CATCH
}

void Slayer::loadItem( bool checkTimeLimit )
	throw (InvalidProtocolException, Error)
{
	__BEGIN_TRY

	PlayerCreature::loadItem();

	// 인벤토리를 생성한다. 
	// 생성하기 전에 전에 있던 것은 지워준다.
	SAFE_DELETE(m_pInventory);
//	m_pInventory = new PlayerInventory(this, 10, 6);
	m_pInventory = new Inventory(10, 6);
	m_pInventory->setOwner(getName());

	// 아이템을 로드한다.
	g_pItemLoaderManager->load(this);

	// 구매한 아이템을 로드한다.
	PlayerCreature::loadGoods();

	// 로드한 아이템들을 등록하고...
	registerInitObject();

	if( m_pFlagSet->isOn( FLAGSET_RECEIVE_NEWBIE_ITEM_AUTO ) )
	{
		addNewbieItemToInventory( this );
		addNewbieGoldToInventory( this );
		addNewbieItemToGear( this );
		// 2007 01 05 새로운 케릭터 이벤트
		if( g_pVariableManager->getNewbieItemEvent() )
		{
			Statement* pStmt = NULL;
			BEGIN_DB
			{
				Result* pResult = NULL;
				pStmt   = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
				pResult = pStmt->executeQuery(
						"SELECT * FROM EventNewbie WHERE Name = '%s'",
						m_Name.c_str()
						);

				if( pResult->getRowCount() == 0 )
				{
					if( addNewbieEventItemToInventory(this) )
					{
						pStmt->executeQuery( "INSERT INTO EventNewbie(Name) VALUES ('%s')", m_Name.c_str() );
					}
				}
				SAFE_DELETE(pStmt);
			}
			END_DB(pStmt)
		}

		// 주었을 경우 줬다는 플래그를 꺼준다.
		m_pFlagSet->turnOff( FLAGSET_RECEIVE_NEWBIE_ITEM_AUTO );
		m_pFlagSet->save( getName() );
	}

	if ( checkTimeLimit )
	{
		checkItemTimeLimit();
	}

	// 입고 있는 옷에 따라 능력치를 계산해 준다.
	initAllStat();

	//cout << "Slayer::loadItem() : STR[CURRENT]" << (int)m_STR[ATTR_CURRENT] << endl;
	//cout << "Slayer::loadItem() : STR[MAX]" << (int)m_STR[ATTR_MAX] << endl;
	//cout << "Slayer::loadItem() : STR[BASIC]" << (int)m_STR[ATTR_BASIC] << endl;
	//cout << "Slayer::loadItem() : DEX[CURRENT]" << (int)m_DEX[ATTR_CURRENT] << endl;
	//cout << "Slayer::loadItem() : DEX[MAX]" << (int)m_DEX[ATTR_MAX] << endl;
	//cout << "Slayer::loadItem() : DEX[BASIC]" << (int)m_DEX[ATTR_BASIC] << endl;
	//cout << "Slayer::loadItem() : INT[CURRENT]" << (int)m_INT[ATTR_CURRENT] << endl;
	//cout << "Slayer::loadItem() : INT[MAX]" << (int)m_INT[ATTR_MAX] << endl;
	//cout << "Slayer::loadItem() : INT[BASIC]" << (int)m_INT[ATTR_BASIC] << endl;

	__END_CATCH
}

bool Slayer::load ()
	throw (InvalidProtocolException, Error)
{
	__BEGIN_TRY

	if ( !PlayerCreature::load() ) return false;

	for (int i=0; i<SKILL_DOMAIN_VAMPIRE; i++)
	{
		m_SkillDomainLevels[i] = 0;
//		m_SkillDomainExps[i]   = 0;
	}

	Statement* pStmt   = NULL;
	Result*    pResult = NULL;

	int reward = 0;

	BEGIN_DB
	{
		pStmt   = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pResult = pStmt->executeQuery(
			"SELECT Name, AdvancementClass, AdvancementGoalExp, Competence, CompetenceShape, Sex, Born,"
			"HairStyle, HairColor, SkinColor, Phone, MasterEffectColor,"
			"STR, STRGoalExp,"
			"DEX, DEXGoalExp,"
			"INTE, INTGoalExp,"
			"AdvancedSTR, AdvancedDEX, AdvancedINT, Bonus," 
			"`Rank`, RankGoalExp," 
			"CurrentHP, HP, CurrentMP, MP," 
			"AttackBloodBurstPoint, DefenseBloodBurstPoint,"
			"Fame, Gold, GuildID," 
			"BladeLevel, BladeGoalExp," 
			"SwordLevel, SwordGoalExp," 
			"GunLevel, GunGoalExp," 
			"EnchantLevel, EnchantGoalExp," 
			"HealLevel, HealGoalExp," 
			"ETCLevel, ETCGoalExp," 
			"ZoneID, XCoord, YCoord, Sight," 
			"GunBonusExp, RifleBonusExp," 
			"Alignment,"
			"StashGold, StashNum, ResurrectZone, Reward,"
			"SMSCharge, ShopColor, GambleAccumulation, GambleTryCount"
			" FROM Slayer WHERE Name = '%s' AND Active = 'ACTIVE'",
			m_Name.c_str()
		);

		if (pResult->getRowCount() == 0) 
		{
			//throw Error("Critical Error : data intergrity broken. (로그인 서버에서 게임 서버로 넘어오는 동안에 캐릭터가 삭제되었습니다.)");
			SAFE_DELETE(pStmt);
			return false;
		}

		pResult->next();

		uint i = 0;

		setName(pResult->getString(++i));

		Level_t advLevel = pResult->getInt(++i);
		Exp_t	advGoalExp = pResult->getInt(++i);

		m_pAdvancementClass = new AdvancementClass( advLevel, advGoalExp, AdvancementClassExpTable::s_AdvancementClassExpTable );
		if ( getAdvancementClassLevel() > 0 ) m_bAdvanced = true;

		int competence = pResult->getInt(++i);
		if ( competence >= 4 ) competence = 3;

		setCompetence(competence);
		setCompetenceShape(pResult->getInt(++i));
		setSex(pResult->getString(++i));
		setBorn(pResult->getString(++i));
//		setMasterEffectColor(pResult->getInt(++i));
		setHairStyle(pResult->getString(++i));
		setHairColor(pResult->getInt(++i));
		setSkinColor(pResult->getInt(++i));
		setPhoneNumber(atoi(pResult->getString(++i)));
		setMasterEffectColor(pResult->getInt(++i));

		m_STR[ATTR_BASIC]   = pResult->getInt(++i);
		m_STR[ATTR_MAX]     = m_STR[ATTR_BASIC];
		m_STR[ATTR_CURRENT] = m_STR[ATTR_BASIC];
//		m_STRExp            = pResult->getInt(++i);
		Exp_t STRGoalExp        = pResult->getInt(++i);

		m_pAttrs[ATTR_KIND_STR] = new Attr( m_STR[ATTR_BASIC], STRGoalExp, SlayerAttrExpTable::s_SlayerAttrExpTable[ATTR_KIND_STR] );

		m_DEX[ATTR_BASIC]   = pResult->getInt(++i);
		m_DEX[ATTR_MAX]     = m_DEX[ATTR_BASIC];
		m_DEX[ATTR_CURRENT] = m_DEX[ATTR_BASIC];
//		m_DEXExp            = pResult->getInt(++i);
		Exp_t DEXGoalExp        = pResult->getInt(++i);

		m_pAttrs[ATTR_KIND_DEX] = new Attr( m_DEX[ATTR_BASIC], DEXGoalExp, SlayerAttrExpTable::s_SlayerAttrExpTable[ATTR_KIND_DEX] );
		
		m_INT[ATTR_BASIC]   = pResult->getInt(++i);
		m_INT[ATTR_MAX]     = m_INT[ATTR_BASIC];
		m_INT[ATTR_CURRENT] = m_INT[ATTR_BASIC];
//		m_INTExp            = pResult->getInt(++i);
		Exp_t INTGoalExp        = pResult->getInt(++i);

		m_pAttrs[ATTR_KIND_INT] = new Attr( m_INT[ATTR_BASIC], INTGoalExp, SlayerAttrExpTable::s_SlayerAttrExpTable[ATTR_KIND_INT] );

		// 20070911
		m_AdvancedSTR[ATTR_BASIC] = pResult->getInt(++i);
		m_AdvancedSTR[ATTR_MAX] = m_AdvancedSTR[ATTR_BASIC];
		m_AdvancedSTR[ATTR_CURRENT] = m_AdvancedSTR[ATTR_BASIC];
		m_AdvancedDEX[ATTR_BASIC] = pResult->getInt(++i);
		m_AdvancedDEX[ATTR_MAX] = m_AdvancedDEX[ATTR_BASIC];
		m_AdvancedDEX[ATTR_CURRENT] = m_AdvancedDEX[ATTR_BASIC];
		m_AdvancedINT[ATTR_BASIC] = pResult->getInt(++i);
		m_AdvancedINT[ATTR_MAX] = m_AdvancedINT[ATTR_BASIC];
		m_AdvancedINT[ATTR_CURRENT] = m_AdvancedINT[ATTR_BASIC];
		
		
		m_AdvancedAttrBonus = pResult->getInt(++i);
		
		Rank_t CurRank               = pResult->getInt(++i);
//		RankExp_t RankExp            = pResult->getInt(++i);
		RankExp_t RankGoalExp        = pResult->getInt(++i);

		m_pRank = new Rank( CurRank, RankGoalExp, RankExpTable::s_RankExpTables[RANK_TYPE_SLAYER] );
//		cout << getRankGoalExp() << endl;

		//cout << "Slayer::load() : STR[CURRENT]" << (int)m_STR[ATTR_CURRENT] << endl;
		//cout << "Slayer::load() : STR[MAX]" << (int)m_STR[ATTR_MAX] << endl;
		//cout << "Slayer::load() : STR[BASIC]" << (int)m_STR[ATTR_BASIC] << endl;
		//cout << "Slayer::load() : DEX[CURRENT]" << (int)m_DEX[ATTR_CURRENT] << endl;
		//cout << "Slayer::load() : DEX[MAX]" << (int)m_DEX[ATTR_MAX] << endl;
		//cout << "Slayer::load() : DEX[BASIC]" << (int)m_DEX[ATTR_BASIC] << endl;
		//cout << "Slayer::load() : INT[CURRENT]" << (int)m_INT[ATTR_CURRENT] << endl;
		//cout << "Slayer::load() : INT[MAX]" << (int)m_INT[ATTR_MAX] << endl;
		//cout << "Slayer::load() : INT[BASIC]" << (int)m_INT[ATTR_BASIC] << endl;

		m_HP[ATTR_CURRENT]  = pResult->getInt(++i);
		m_HP[ATTR_MAX]      = pResult->getInt(++i);
		m_HP[ATTR_BASIC]    = 0;

		m_MP[ATTR_CURRENT]  = pResult->getInt(++i);
		m_MP[ATTR_MAX]      = pResult->getInt(++i);
		m_MP[ATTR_BASIC]    = 0;

		setAttackBloodBurstPoint( pResult->getInt(++i) );
		setDefenseBloodBurstPoint( pResult->getInt(++i) );

		setFame(pResult->getInt(++i));
		setGold(pResult->getInt(++i));
		setGuildID(pResult->getInt(++i));
		//setInMagics(pResult->getString(++i));

		setSkillDomainLevel(SKILL_DOMAIN_BLADE,   pResult->getInt(++i));
//		setSkillDomainExp  (SKILL_DOMAIN_BLADE,   pResult->getInt(++i));
		setGoalExp         (SKILL_DOMAIN_BLADE,   pResult->getInt(++i));
		setSkillDomainLevel(SKILL_DOMAIN_SWORD,   pResult->getInt(++i));
//		setSkillDomainExp  (SKILL_DOMAIN_SWORD,   pResult->getInt(++i));
		setGoalExp         (SKILL_DOMAIN_SWORD,   pResult->getInt(++i));
		setSkillDomainLevel(SKILL_DOMAIN_GUN,     pResult->getInt(++i));
//		setSkillDomainExp  (SKILL_DOMAIN_GUN,     pResult->getInt(++i));
		setGoalExp         (SKILL_DOMAIN_GUN,     pResult->getInt(++i));
		//setSkillDomainLevel(SKILL_DOMAIN_RIFLE   , pResult->getInt(++i));
		//setSkillDomainExp(SKILL_DOMAIN_RIFLE   , pResult->getInt(++i));
		//setGoalExp(SKILL_DOMAIN_RIFLE	  , pResult->getInt(++i));
		setSkillDomainLevel(SKILL_DOMAIN_ENCHANT, pResult->getInt(++i));
//		setSkillDomainExp  (SKILL_DOMAIN_ENCHANT, pResult->getInt(++i));
		setGoalExp         (SKILL_DOMAIN_ENCHANT, pResult->getInt(++i));
		setSkillDomainLevel(SKILL_DOMAIN_HEAL,    pResult->getInt(++i));
//		setSkillDomainExp  (SKILL_DOMAIN_HEAL,    pResult->getInt(++i));
		setGoalExp         (SKILL_DOMAIN_HEAL,    pResult->getInt(++i));
		setSkillDomainLevel(SKILL_DOMAIN_ETC,     pResult->getInt(++i));
//		setSkillDomainExp  (SKILL_DOMAIN_ETC,     pResult->getInt(++i));
		setGoalExp         (SKILL_DOMAIN_ETC,     pResult->getInt(++i));

//		setZoneID(pResult->getInt(++i));
		ZoneID_t zoneID = pResult->getInt(++i);
		setX(pResult->getInt(++i));
		setY(pResult->getInt(++i));

		setSight(pResult->getInt(++i));
		setSight(13);
		setGunBonusExp(pResult->getInt(++i));
		setRifleBonusExp(pResult->getInt(++i));
		setAlignment(pResult->getInt(++i));

//		for (int j = 0; j < 4; j++) setHotKey(j, pResult->getInt(++i));

		setStashGold(pResult->getInt(++i));
		setStashNum(pResult->getBYTE(++i));
		setResurrectZoneID(pResult->getInt(++i));

		reward = pResult->getInt(++i);
		setSMSCharge( pResult->getInt(++i) );

        // 2006.04.25 상점 색 추가
        Store* pStore = getStore();
        pStore->setPaintColor(pResult->getInt(++i));

		// 2006.09.11 겜블 정보 추가
		setGambleAccumulation( (WORD)pResult->getInt(++i) );
		setGambleTryCount( (WORD)pResult->getInt(++i) );

		// 그냥 다시 계산해버린다. 2002.7.15 by sigi
		// 공식 바뀌면 AbilityBalance.cpp의 computeHP도 수정해야한다.
//		m_HP[ATTR_MAX]      = m_STR[ATTR_CURRENT]*2;

		try
		{
			setZoneID( zoneID );
		}
		catch ( Error& e )
		{
			// 길드 아지트 문제로 본다.
			// 길드 아지트가 한 게임 서버에만 존재하므로 다른 게임서버로 접속할 때 그 아지트로 들어가지 못한다.
			ZONE_COORD ResurrectCoord;
			g_pResurrectLocationManager->getSlayerPosition( 12, ResurrectCoord );
			setZoneID( ResurrectCoord.id );
			setX( ResurrectCoord.x );
			setY( ResurrectCoord.y );
		}

		SAFE_DELETE(pStmt);
	} 
	END_DB(pStmt)

	// zone 의 object registery 에 접근한다.
	ObjectRegistry & OR = getZone()->getObjectRegistry();
	OR.registerObject(this);

/*	if (reward != 0)
	{
		uint MaxExp     = 0;
		uint DomainType = SKILL_DOMAIN_MAX;
		uint sum        = 0;

		for (int i=0; i<SKILL_DOMAIN_VAMPIRE; i++)
		{
			if (MaxExp <= m_SkillDomainExps[i])
			{
				MaxExp     = m_SkillDomainExps[i];
				DomainType = i;
			}

			sum += m_SkillDomainLevels[i];
		}

		bool bSuccess = false;

		switch (DomainType)
		{
			case SKILL_DOMAIN_SWORD:
			case SKILL_DOMAIN_BLADE:
			case SKILL_DOMAIN_GUN:
			case SKILL_DOMAIN_ENCHANT:
			case SKILL_DOMAIN_HEAL:
				bSuccess = true;
				break;
			default:
				bSuccess = false;
				break;
		}

		if (bSuccess)
		{
			BEGIN_DB
			{
				pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
				pStmt->executeQuery("UPDATE Slayer SET Reward = 0 WHERE Name='%s'", m_Name.c_str());
				SAFE_DELETE(pStmt);
			} 
			END_DB(pStmt)

			GCModifyInformation gcModifyInformation;
			
			if (0 <= sum && sum <= 10)
			{
				for (int count=0; count<5; count++)
				{
					setGoalExp(DomainType, 1);
					increaseDomainExp(this, DomainType, 1, gcModifyInformation);
				}

				for (int count=0; count<4; count++)
				{
					m_STRGoalExp = 1; m_DEXGoalExp = 1; m_INTGoalExp = 1;
					divideAttrExp(this, 1, 1, 1, 1, gcModifyInformation, 0);
				}
			}
			else if (11 <= sum && sum <= 20)
			{
				for (int count=0; count<4; count++)
				{
					setGoalExp(DomainType, 1);
					increaseDomainExp(this, DomainType, 1, gcModifyInformation);
				}

				for (int count=0; count<3; count++)
				{
					m_STRGoalExp = 1; m_DEXGoalExp = 1; m_INTGoalExp = 1;
					divideAttrExp(this, 1, 1, 1, 1, gcModifyInformation, 0);
				}
			}
			else if (21 <= sum && sum <= 30)
			{
				for (int count=0; count<2; count++)
				{
					setGoalExp(DomainType, 1);
					increaseDomainExp(this, DomainType, 1, gcModifyInformation);
				}

				for (int count=0; count<2; count++)
				{
					m_STRGoalExp = 1; m_DEXGoalExp = 1; m_INTGoalExp = 1;
					divideAttrExp(this, 1, 1, 1, 1, gcModifyInformation, 0);
				}
			}
			else
			{
				for (int count=0; count<1; count++)
				{
					setGoalExp(DomainType, 1);
					increaseDomainExp(this, DomainType, 1, gcModifyInformation);
				}

				for (int count=0; count<1; count++)
				{
					m_STRGoalExp = 1; m_DEXGoalExp = 1; m_INTGoalExp = 1;
					divideAttrExp(this, 1, 1, 1, 1, gcModifyInformation, 0);
				}
			}
		}
	}
*/
	// Slayer Outlook Information 을 구성한다.
	m_SlayerInfo.setObjectID(m_ObjectID);
    m_SlayerInfo.setName(m_Name);
    m_SlayerInfo.setX(m_X);
    m_SlayerInfo.setY(m_Y);
    m_SlayerInfo.setDir(m_Dir);
    m_SlayerInfo.setSex(m_Sex);
    m_SlayerInfo.setHairStyle(m_HairStyle);

	// 0이나 1 권한을 가지고 있으면
	// 운영자로 스프라이트를 출력해줘야 한다. 
	m_SlayerInfo.setCompetence(m_CompetenceShape);

	// 스킬을 로딩한다.
	BEGIN_DB
	{
		pStmt   = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pResult = pStmt->executeQuery("SELECT SkillType, SkillLevel, SkillExp, CastingTime FROM SkillSave WHERE OwnerID = '%s'", m_Name.c_str());

		while(pResult->next()) 
		{
			int i = 0;

			SlayerSkillSlot* pSkillSlot = new SlayerSkillSlot();
			
			pSkillSlot->setName(m_Name);
			pSkillSlot->setSkillType(pResult->getInt(++i));

			pSkillSlot->setExpLevel(pResult->getInt(++i));
			pSkillSlot->setExp (pResult->getInt(++i));
			if (isRareBookSkill(pSkillSlot->getSkillType()))	// book skills never level: always mastered
				pSkillSlot->setExpLevel(RARE_BOOK_SLAYER_SKILL_LEVEL);
			pSkillSlot->setInterval (99999999);
			pSkillSlot->setCastingTime (pResult->getInt(++i));
			pSkillSlot->setRunTime();

			// 이 스킬을 쓸 수 있는지 없는지 체크 한돠..
			// 스킬인포를 받아온다.
			SkillInfo * pSkillInfo = g_pSkillInfoManager->getSkillInfo(pSkillSlot->getSkillType() );
			Assert( pSkillInfo != NULL );

			if ( pSkillInfo->getDomainType() > SKILL_DOMAIN_ETC )
			{
				delete pSkillSlot;

				// 슬레이어에 해당하는 스킬이 아닌경우 무시한다.
				continue;
			}


			// 배우는 레벨보다 지금 현재의 도메인 레벨이 낮으면 당연히 못쓴다.
			if( pSkillInfo->getLevel() > 150 )
			{
				Level_t advLevel = pSkillInfo->getLevel() - 151;
				if( advLevel > getAdvancementClassLevel() )
					pSkillSlot->setDisable();
			}
			else if( pSkillInfo->getLevel() > m_SkillDomainLevels[pSkillInfo->getDomainType()] && pSkillInfo->getDomainType() != SKILL_DOMAIN_ETC ) 
			{
				pSkillSlot->setDisable();
			}
			
			pSkillSlot->setDirty(false);

			addSkill(pSkillSlot);
		}

		SAFE_DELETE(pStmt);
	} 
	END_DB(pStmt)

	// 이펙트를 로딩한다.
	g_pEffectLoaderManager->load(this);

	// Rank Bonus 를 로딩한다.
	loadRankBonus();

	// GrandMaster인 경우는 Effect를 붙여준다.
	// by sigi. 2002.11.8
	if (getHighestSkillDomainLevel()>=100
		&& SystemAvailabilitiesManager::getInstance()->isAvailable( SystemAvailabilitiesManager::SYSTEM_GRAND_MASTER_EFFECT ) )
	{
		if (!isFlag(Effect::EFFECT_CLASS_GRAND_MASTER_SLAYER))
		{
			EffectGrandMasterSlayer* pEffect = new EffectGrandMasterSlayer(this);
			pEffect->setDeadline(999999);
			getEffectManager()->addEffect( pEffect );
			setFlag(Effect::EFFECT_CLASS_GRAND_MASTER_SLAYER);
		}
	}


	// 플래그 셋을 로드한다.
	m_pFlagSet->load(getName());

	// Slayer Outlook Information 을 구성한다.
	m_SlayerInfo.setHelmetType(HELMET_NONE);
	m_SlayerInfo.setJacketType(JACKET_BASIC);
	m_SlayerInfo.setPantsType(PANTS_BASIC);
	m_SlayerInfo.setWeaponType(WEAPON_NONE); 
	m_SlayerInfo.setShieldType(SHIELD_NONE); 
	m_SlayerInfo.setMotorcycleType(MOTORCYCLE_NONE);
    m_SlayerInfo.setMasterEffectColor(m_HairColor);
	m_SlayerInfo.setBorn(m_Born);
    m_SlayerInfo.setHairColor(m_HairColor);
    m_SlayerInfo.setSkinColor(m_SkinColor);
	m_SlayerInfo.setShoulderType(0);

	m_SlayerInfo.setAdvancementLevel(getAdvancementClassLevel());

	// 잘못된 경험치를 재조정 해준다.
/*	STRBalanceInfo* pSTRInfo = g_pSTRBalanceInfoManager->getSTRBalanceInfo(m_STR[ATTR_BASIC]);

	if (pSTRInfo->getAccumExp() != m_STRExp + m_STRGoalExp) 
	{
		//ofstream file("능력치조정.txt", ios::out | ios::app);
		//file << "NAME:" << m_Name << endl;
		//file << "==STR==" << endl;
		//file << "현재레벨의총경험치 : " << (int)pSTRInfo->getAccumExp() << endl;
		//file << "현재 누적 경험치 : " << (int)m_STRExp << endl;
		//file << "현재 목표 경험치 : " << (int)m_STRGoalExp << endl;
		//file << endl;

		// 현재 목표 경험치가 현재 레벨의 목표 경험치 보다 크다면, 재 설정 해준다.
		if (m_STRGoalExp > pSTRInfo->getGoalExp()) 
		{
			m_STRGoalExp = pSTRInfo->getGoalExp();
		}

		// 이전 레벨의 인포를 받아온다.
		STRBalanceInfo* pBeforeSTRInfo = g_pSTRBalanceInfoManager->getSTRBalanceInfo(m_STR[ATTR_BASIC] - 1);
		// 이전 레벨의 총 경험치 + 목표 경험치 변화량 = 현재 누적 경험치
		m_STRExp = pBeforeSTRInfo->getAccumExp() + (pSTRInfo->getGoalExp() - m_STRGoalExp);

		//file << "수정된 누적 경험치 : " << (int)m_STRExp << endl;
		//file << "수정된 목표 경험치 : " << (int)m_STRGoalExp << endl;

//		StringStream attrsave;
//		attrsave << "STRExp = " << (int)m_STRExp << ", STRGoalExp = " << (int)m_STRGoalExp;
//		tinysave(attrsave.toString());

		// by sigi. 2002.5.15
		char pField[80];
		sprintf(pField, "STRExp=%lu, STRGoalExp=%lu", m_STRExp, m_STRGoalExp);
		tinysave(pField);
		
		//file.close();
	}

	// 잘못된 경험치를 재조정 해준다.
	DEXBalanceInfo* pDEXInfo = g_pDEXBalanceInfoManager->getDEXBalanceInfo(m_DEX[ATTR_BASIC]);

	if (pDEXInfo->getAccumExp() != m_DEXExp + m_DEXGoalExp) 
	{
		//ofstream file("능력치조정.txt", ios::out | ios::app);
		//file << "NAME:" << m_Name << endl;
		//file << "==DEX==" << endl;
		//file << "현재레벨의총경험치 : " << (int)pDEXInfo->getAccumExp() << endl;
		//file << "현재 누적 경험치 : " << (int)m_DEXExp << endl;
		//file << "현재 목표 경험치 : " << (int)m_DEXGoalExp << endl;
		//file << endl;

		// 현재 목표 경험치가 현재 레벨의 목표 경험치 보다 크다면, 재 설정 해준다.
		if (m_DEXGoalExp > pDEXInfo->getGoalExp()) 
		{
			m_DEXGoalExp = pDEXInfo->getGoalExp();
		}

		// 이전 레벨의 인포를 받아온다.
		DEXBalanceInfo* pBeforeDEXInfo = g_pDEXBalanceInfoManager->getDEXBalanceInfo(m_DEX[ATTR_BASIC] - 1);
		// 이전 레벨의 총 경험치 + 목표 경험치 변화량 = 현재 누적 경험치
		m_DEXExp = pBeforeDEXInfo->getAccumExp() + (pDEXInfo->getGoalExp() - m_DEXGoalExp);

		//file << "수정된 누적 경험치 : " << (int)m_DEXExp << endl;
		//file << "수정된 목표 경험치 : " << (int)m_DEXGoalExp << endl;

//		StringStream attrsave;
//		attrsave << "DEXExp = " << (int)m_DEXExp << ", DEXGoalExp = " << (int)m_DEXGoalExp;
//		tinysave(attrsave.toString());

		// by sigi. 2002.5.15
		char pField[80];
		sprintf(pField, "DEXExp=%lu, DEXGoalExp=%lu", m_DEXExp, m_DEXGoalExp);
		tinysave(pField);
		
		//file.close();
	}

	// 잘못된 경험치를 재조정 해준다.
	INTBalanceInfo* pINTInfo = g_pINTBalanceInfoManager->getINTBalanceInfo(m_INT[ATTR_BASIC]);

	if (pINTInfo->getAccumExp() != m_INTExp + m_INTGoalExp) 
	{
		//ofstream file("능력치조정.txt", ios::out | ios::app);
		//file << "NAME:" << m_Name << endl;
		//file << "==INT==" << endl;
		//file << "현재레벨의총경험치 : " << (int)pINTInfo->getAccumExp() << endl;
		//file << "현재 누적 경험치 : " << (int)m_INTExp << endl;
		//file << "현재 목표 경험치 : " << (int)m_INTGoalExp << endl;
		//file << endl;

		// 현재 목표 경험치가 현재 레벨의 목표 경험치 보다 크다면, 재 설정 해준다.
		if (m_INTGoalExp > pINTInfo->getGoalExp()) 
		{
			m_INTGoalExp = pINTInfo->getGoalExp();
		}

		// 이전 레벨의 인포를 받아온다.
		INTBalanceInfo* pBeforeINTInfo = g_pINTBalanceInfoManager->getINTBalanceInfo(m_INT[ATTR_BASIC] - 1);
		// 이전 레벨의 총 경험치 + 목표 경험치 변화량 = 현재 누적 경험치
		m_INTExp = pBeforeINTInfo->getAccumExp() + (pINTInfo->getGoalExp() - m_INTGoalExp);

		//file << "수정된 누적 경험치 : " << (int)m_INTExp << endl;
		//file << "수정된 목표 경험치 : " << (int)m_INTGoalExp << endl;

//		StringStream attrsave;
//		attrsave << "INTExp = " << (int)m_INTExp << ", INTGoalExp = " << (int)m_INTGoalExp;
//		tinysave(attrsave.toString());

		// by sigi. 2002.5.15
		char pField[80];
		sprintf(pField, "INTExp=%lu, INTGoalExp=%lu", m_INTExp, m_INTGoalExp);
		tinysave(pField);
		
		
		//file.close();
	}
*/

	// rank가 0이면 초기값이 설정되지 않았다는 의미이다.
	if (getRank()==0)
	{
		setInitialRank();
	}

	// 잘못된 경험치를 재조정 해준다.
	// by sigi. 2002.8.31
/*	RankEXPInfo* pRankInfo = g_pRankEXPInfoManager[RANK_TYPE_SLAYER]->getRankEXPInfo(m_Rank);
	
	if (m_Rank>1 && pRankInfo->getAccumExp() != m_RankExp + m_RankGoalExp) 
	{
		//ofstream file("능력치조정.txt", ios::out | ios::app);
		//file << "NAME:" << m_Name << endl;
		//file << "==Rank==" << endl;
		//file << "현재레벨의총경험치 : " << (int)pRankInfo->getAccumExp() << endl;
		//file << "현재 누적 경험치 : " << (int)m_RankExp << endl;
		//file << "현재 목표 경험치 : " << (int)m_RankGoalExp << endl;
		//file << endl;

		// 현재 목표 경험치가 현재 레벨의 목표 경험치 보다 크다면, 재 설정 해준다.
		if (m_RankGoalExp > pRankInfo->getGoalExp()) 
		{
			m_RankGoalExp = pRankInfo->getGoalExp();
		}

		// 이전 레벨의 인포를 받아온다.
		RankEXPInfo* pBeforeRankInfo = g_pRankEXPInfoManager[RANK_TYPE_SLAYER]->getRankEXPInfo(m_Rank - 1);
		// 이전 레벨의 총 경험치 + 목표 경험치 변화량 = 현재 누적 경험치
		m_RankExp = pBeforeRankInfo->getAccumExp() + (pRankInfo->getGoalExp() - m_RankGoalExp);

		//file << "수정된 누적 경험치 : " << (int)m_RankExp << endl;
		//file << "수정된 목표 경험치 : " << (int)m_RankGoalExp << endl;

//		StringStream attrsave;
//		attrsave << "RankExp = " << (int)m_RankExp << ", RankGoalExp = " << (int)m_RankGoalExp;
//		tinysave(attrsave.toString());

		// by sigi. 2002.5.15
		char pField[80];
		sprintf(pField, "RankExp=%lu, RankGoalExp=%lu", m_RankExp, m_RankGoalExp);
		tinysave(pField);
		
		
		//file.close();
	}
*/

	// 잘못된 도메인 경험치를 보정한다.
/*	for (int i = 0; i < SKILL_DOMAIN_ETC; i++) 
	{
		DomainInfo* pDomainInfo = g_pSkillDomainInfoManager->getDomainInfo((SkillDomain)i , m_SkillDomainLevels[i]); 
		Assert(pDomainInfo!=NULL);

		if (pDomainInfo->getAccumExp() != m_SkillDomainExps[i] + m_GoalExp[i] 
			&& m_SkillDomainLevels[i] > 0) 
		{
			//ofstream file("도메인조정.txt", ios::out | ios::app);
			//file << "NAME:" << m_Name << endl;
			//file << "==" << i << "==" << endl;
			//file << "현재레벨의총경험치 : " << (int)pDomainInfo->getAccumExp() << endl;
			//file << "현재 누적 경험치 : " << (int)m_SkillDomainExps[i] << endl;
			//file << "현재 목표 경험치 : " << (int)m_GoalExp[i] << endl;
			//file << endl;

			// 현재 목표 경험치가 현재 레벨의 목표 경험치 보다 크다면, 재 설정 해준다.
			if (m_GoalExp[i] > pDomainInfo->getGoalExp()) 
			{
				m_GoalExp[i] = pDomainInfo->getGoalExp();
			}

			// 이전 레벨의 인포를 받아온다.
			DomainInfo* pBeforeDomainInfo = g_pSkillDomainInfoManager->getDomainInfo((SkillDomain)i , (m_SkillDomainLevels[i] - 1)); 
			// 이전 레벨의 총 경험치 + 목표 경험치 변화량 = 현재 누적 경험치
			m_SkillDomainExps[i] = pBeforeDomainInfo->getAccumExp() + (pDomainInfo->getGoalExp() - m_GoalExp[i]);

			//file << "수정된 누적 경험치 : " << (int)m_SkillDomainExps[i] << endl;
			//file << "수정된 목표 경험치 : " << (int)m_GoalExp[i] << endl;

			//StringStream attrsave;
			// by sigi. 2002.5.15
			char pField[80];
			pField[0] = '\0';

			if (i == SKILL_DOMAIN_BLADE) 
			{
				//attrsave << "BladeExp = " << (int)m_SkillDomainExps[i] << ", BladeGoalExp = " << (int)m_GoalExp[i];
				sprintf(pField, "BladeExp=%lu, BladeGoalExp=%lu", m_SkillDomainExps[i], m_GoalExp[i]);
			} 
			else if (i == SKILL_DOMAIN_SWORD) 
			{
				//attrsave << "SwordExp = " << (int)m_SkillDomainExps[i] << ", SwordGoalExp = " << (int)m_GoalExp[i];
				sprintf(pField, "SwordExp=%lu, SwordGoalExp=%lu", m_SkillDomainExps[i], m_GoalExp[i]);
			} 
			else if (i == SKILL_DOMAIN_GUN) 
			{
				//attrsave << "GunExp = " << (int)m_SkillDomainExps[i] << ", GunGoalExp = " << (int)m_GoalExp[i];
				sprintf(pField, "GunExp=%lu, GunGoalExp=%lu", m_SkillDomainExps[i], m_GoalExp[i]);
			}
			else if (i == SKILL_DOMAIN_HEAL) 
			{
				//attrsave << "HealExp = " << (int)m_SkillDomainExps[i] << ", HealGoalExp = " << (int)m_GoalExp[i];
				sprintf(pField, "HealExp=%lu, HealGoalExp=%lu", m_SkillDomainExps[i], m_GoalExp[i]);
			}
			else if (i == SKILL_DOMAIN_ENCHANT) 
			{
				//attrsave << "EnchantExp = " << (int)m_SkillDomainExps[i] << ", EnchantGoalExp = " << (int)m_GoalExp[i];
				sprintf(pField, "EnchantExp=%lu, EnchantGoalExp=%lu", m_SkillDomainExps[i], m_GoalExp[i]);
			}

			//tinysave(attrsave.toString());
			if (pField[0]!='\0')
				tinysave( pField );

			//file.close();
		}
	}*/

	// 모든 능력치를 로드했기 때문에,
	// 이걸 기본으로 부가 능력치를 초기화한다.
	initAllStat();

	// 전쟁 참가 Flag 체크
	if ( RaceWarLimiter::isInPCList( this ) )
	{
		setFlag( Effect::EFFECT_CLASS_RACE_WAR_JOIN_TICKET );
	}

	if (m_pZone->isHolyLand() 
		&& g_pWarSystem->hasActiveRaceWar()
		&& !isFlag( Effect::EFFECT_CLASS_RACE_WAR_JOIN_TICKET ))
	{
		ZONE_COORD ResurrectCoord;
		g_pResurrectLocationManager->getPosition( this, ResurrectCoord );
		setZoneID( ResurrectCoord.id );
		setX( ResurrectCoord.x );
		setY( ResurrectCoord.y );
	}

	return true;

	__END_CATCH
}

void Slayer::save () const
	throw (Error)
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex)
	
	ostringstream os;
	
	os << "UPDATE Slayer SET " 
		<< "CurrentHP=" << m_HP[ATTR_CURRENT] 
        << ", HP=" << m_HP[ATTR_MAX]
        << ", CurrentMP=" << m_MP[ATTR_CURRENT]
        << ", MP=" << m_MP[ATTR_MAX]
        << ", AttackBloodBurstPoint=" << getAttackBloodBurstPoint()
        << ", DefenseBloodBurstPoint=" << getDefenseBloodBurstPoint()
        << ", ZoneID=" << getZoneID()
        << ", XCoord=" << (int)m_X
        << ", YCoord=" << (int)m_Y
        << " WHERE Name='" << m_Name.c_str()
        << "'";
	
	g_GameDBExecuteManager.RequestExecQuery(getObjectID(), os.str());

	saveGears();
	saveExps();
	saveSkills();
	
#ifdef __CONTRIBUTION_SYSTEM__
	saveContributePoint();
#endif /* __CONTRIBUTION_SYSTEM__ */

	/*
	// 인벤토리의 아이템들을 세이브 한다.
	m_pInventory->save(m_Name);
	*/

	// 이펙트를 세이브 한다.
	m_pEffectManager->save(m_Name);

	// 오토바이를 세이브 한다.
	if (m_pMotorcycle != NULL) 
	{
		//m_pMotorcycle->save("", STORAGE_ZONE, m_pZone->getZoneID(), m_X, m_Y);
		// by sigi. 2002.5.15
		char pField[80];

		sprintf(pField, "OwnerID='', Storage=%d, StorageID=%u, X=%d, Y=%d",
									STORAGE_ZONE, m_pZone->getZoneID(), m_X, m_Y);
		m_pMotorcycle->tinysave( pField );
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH
}

// tinysave
void Slayer::tinysave(const string & field)
    const throw (Error)
{
    __BEGIN_TRY

	ostringstream os;
	
	os << "UPDATE Slayer SET " 
		<< field.c_str() 
		<< " WHERE NAME='" << m_Name.c_str() << "'";
	
	g_GameDBExecuteManager.RequestExecQuery(getObjectID(), os.str());

    __END_CATCH
}

PhoneNumber_t Slayer::getPhoneSlotNumber(SlotID_t SlotID)
	throw()
{
	__BEGIN_TRY

	Assert(SlotID <= MAX_PHONE_SLOT);

	return m_PhoneSlot[SlotID];

	__END_CATCH
}

void Slayer::setPhoneSlotNumber(SlotID_t SlotID, PhoneNumber_t PhoneNumber)
	throw()
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex)

	m_PhoneSlot[SlotID] = PhoneNumber;

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH
}

bool Slayer::isSlotByPhoneNumber(PhoneNumber_t PhoneNumber)
	throw()
{
	__BEGIN_TRY

	bool isFind = false;

	for (int i = 0; i < MAX_PHONE_SLOT; i++) 
	{
		if (m_PhoneSlot[i] == PhoneNumber) isFind = true;
	}

	return isFind;

	__END_CATCH
}

SlotID_t Slayer::getSlotWithPhoneNumber(PhoneNumber_t PhoneNumber)
	throw()
{
	__BEGIN_TRY

	for (int i = 0; i < MAX_PHONE_SLOT; i++) {

		if (m_PhoneSlot[i] == PhoneNumber) return i;
	}

	return MAX_PHONE_SLOT;

	__END_CATCH
}

SlotID_t Slayer::findEmptyPhoneSlot()
	throw()
{
	__BEGIN_TRY

	for (int i = 0; i < MAX_PHONE_SLOT; i++) 
	{
		if (m_PhoneSlot[i] == 0) 
		{
			return i;
		}
	}

	return MAX_PHONE_SLOT;

	__END_CATCH
}

bool Slayer::isEmptyPhoneSlot()
	throw()
{
	__BEGIN_TRY

	bool Success = false;

	for (int i = 0; i < MAX_PHONE_SLOT; i++) 
	{
		if (m_PhoneSlot[i] == 0) 
		{
			// 빈 슬랏을 찾았다.
			Success = true;
		}
	}

	return Success;

	__END_CATCH
}

// 특정 Skill이 존재하는지 조사하고 SkillSlot을 리턴한다.
SlayerSkillSlot* Slayer::getSkill(SkillType_t SkillType) const
	throw()
{
	__BEGIN_TRY

	hash_map<SkillType_t, SlayerSkillSlot*>::const_iterator itr = m_SkillSlot.find(SkillType);
	if (itr != m_SkillSlot.end())
	{
		return itr->second;
	}

	return NULL;

	__END_CATCH
}

// 특정 SkillSlot을 자동으로 빈 슬랏을 찾아 넣는다.
void Slayer::addSkill(SlayerSkillSlot* pSkillSlot)
	throw()
{
	__BEGIN_TRY

	SkillType_t SkillType = pSkillSlot->getSkillType();
	switch (SkillType)
	{
		case SKILL_UN_BURROW:
		case SKILL_UN_TRANSFORM:
		case SKILL_UN_INVISIBILITY:
		case SKILL_THROW_HOLY_WATER:
		case SKILL_EAT_CORPSE:
		case SKILL_HOWL:
			filelog("SlayerError.log", "SkillType[%d], %s", SkillType, toString().c_str());
			Assert(false);
			break;
		default:
			break;
	}

	hash_map<SkillType_t, SlayerSkillSlot*>::iterator itr = m_SkillSlot.find(pSkillSlot->getSkillType());
	
	if (itr == m_SkillSlot.end())
	{
		m_SkillSlot[pSkillSlot->getSkillType()] = pSkillSlot;
	}
	// 2002.1.16 by sigi
	// 2003.3.30 by Sequoia 조건 추가함
	else
	{
		if ( pSkillSlot != itr->second ) SAFE_DELETE(pSkillSlot);
	}

	__END_CATCH
}

// 기술을 배울때만 쓰는 함수이다. 다른 곳에서 쓰면 개 된다.
void Slayer::addSkill(SkillType_t SkillType)
	throw()
{
	__BEGIN_TRY

	switch (SkillType)
	{
		case SKILL_UN_BURROW:
		case SKILL_UN_TRANSFORM:
		case SKILL_UN_INVISIBILITY:
		case SKILL_THROW_HOLY_WATER:
		case SKILL_EAT_CORPSE:
		case SKILL_HOWL:
			filelog("SlayerError.log", "2 SkillType[%d], %s", SkillType, toString().c_str());
			Assert(false);
			break;
		default:
			break;
	}

	hash_map<SkillType_t, SlayerSkillSlot*>::iterator itr = m_SkillSlot.find(SkillType);
	
	if (itr == m_SkillSlot.end())
	{
		SkillInfo* pSkillInfo = g_pSkillInfoManager->getSkillInfo(SkillType);
		Turn_t Delay = pSkillInfo->getMaxDelay();

		SlayerSkillSlot* pSkillSlot = new SlayerSkillSlot();
		pSkillSlot->setName(m_Name);
		pSkillSlot->setSkillType(SkillType);
		pSkillSlot->setInterval(Delay);
		pSkillSlot->setExpLevel(isRareBookSkill(SkillType) ? RARE_BOOK_SLAYER_SKILL_LEVEL : 0);	// book skills never level
		pSkillSlot->setExp(1);
		pSkillSlot->setRunTime();
		pSkillSlot->create(m_Name);

		m_SkillSlot[SkillType] = pSkillSlot;
	}

	__END_CATCH
}

// 성지스킬을 지워주는 함수다.
void Slayer::removeCastleSkill(SkillType_t SkillType)
	throw()
{
	__BEGIN_TRY

	// 성지 스킬만 지울 수 있다.
	if ( g_pCastleSkillInfoManager->getZoneID( SkillType ) == 0 ) return;

	hash_map<SkillType_t, SlayerSkillSlot*>::iterator itr = m_SkillSlot.find(SkillType);
	
	if (itr != m_SkillSlot.end())
	{
		CastleSkillSlot* pCastleSkillSlot = dynamic_cast<CastleSkillSlot*>(itr->second);

		SAFE_DELETE( pCastleSkillSlot );

		m_SkillSlot.erase( itr );
	}

	__END_CATCH
}

// 갖고 있는 모든 성지스킬을 지워주는 함수이다.
void Slayer::removeAllCastleSkill()
	throw()
{
	__BEGIN_TRY

	hash_map<SkillType_t, SlayerSkillSlot*>::iterator itr = m_SkillSlot.begin();
	hash_map<SkillType_t, SlayerSkillSlot*>::iterator prevItr = m_SkillSlot.end();

	while ( itr != m_SkillSlot.end() )
	{
		if ( itr->second != NULL )
		{
			SlayerSkillSlot* pSkillSlot = itr->second;
			if ( pSkillSlot != NULL && g_pCastleSkillInfoManager->getZoneID( pSkillSlot->getSkillType() ) == 0 )
			{
				// 성지스킬이 아니면 다음껄로 넘어간다.
				++itr;
				continue;
			}

			// 성지스킬이면 지워준다. 반복자 사용에 주의
			SAFE_DELETE( pSkillSlot );
			
			prevItr = itr;
			
			++itr;
			m_SkillSlot.erase( prevItr );
		}
		else
		{
			filelog("ErrorSkillSlot.log", "Slayer::removeAllCastleSkill() SkillType=%d SkillSlot=%X", 
				itr->first, itr->second
			);
						
			prevItr = itr;
						
			++itr;
			m_SkillSlot.erase( prevItr );
		}
	}

	__END_CATCH
}

// Slayer::wearItem()
// Item을 장착창에 장착시키고 능력치를 계산한다.
// 이 메소드는 접속할때 Item을 Loading 하면서 쓰는 wearItem이다.
// 이 메소드 안에선 Broadcast를 하지 않는 것이 좋다.
void Slayer::wearItem(WearPart Part, Item* pItem)
	throw (Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	Assert(pItem != NULL);

	Item::ItemClass IClass    = pItem->getItemClass();
	Item*           pLeft     = NULL;
	Item*           pRight    = NULL;
	Item*           pPrevItem = NULL;

	// 현재 기획에서는...능력치가 모자라더라도 아이템을 무조건 사용할 수는
	// 있다. 하지만 아이템에 의한 능력치가 적용이 되지 않는다. 
	// 그러므로 일단 아이템을 해당하는 장착창에다 집어넣는다.
	// 양손 무기일 경우에는 양손 장착창에다 하나의 아이템 포인터를 할당...
	if (isTwohandWeapon(pItem))
	{
		// 양손에 아이템을 들고 있을 경우
		if (isWear(WEAR_RIGHTHAND) && isWear(WEAR_LEFTHAND))
		{
			pLeft  = getWearItem(WEAR_RIGHTHAND);
			pRight = getWearItem(WEAR_LEFTHAND);
			
			// 양손 무기를 들고 있을 경우
			if (pLeft == pRight)
			{
				// 요구한 아이템을 장착 포인트에 넣고,
				//m_pWearItem[WEAR_RIGHTHAND] = pItem;
				addWearItem(WEAR_RIGHTHAND, pItem);
				//m_pWearItem[WEAR_LEFTHAND]  = pItem;
				addWearItem(WEAR_LEFTHAND, pItem);

				// by sigi. 2002.5.15
				char pField[80];
				//pItem->save(m_Name, STORAGE_GEAR, 0, Part, 0);
				sprintf(pField, "Storage=%d, X=%d, Y=%d", STORAGE_GEAR, Part, getCurrentGearSlotID());
				pItem->tinysave(pField);

				// 원래 있던 아이템을 마우스 포인터에 달아 준다.
				addItemToExtraInventorySlot(pLeft);
				//pLeft->save(m_Name, STORAGE_EXTRASLOT, 0, 0, 0);
//				sprintf(pField, "Storage=%d", STORAGE_EXTRASLOT);
//				Gun* pGun = dynamic_cast<Gun*>(pItem);
				if( pLeft->isSilverWeapon() )
				{
					if( pLeft->isGun() )
					{
						sprintf(pField, "Storage=%d, Durability=%ld, BulletCount=%d, Silver=%d", (int)STORAGE_EXTRASLOT, pLeft->getDurability(), pLeft->getBulletCount(), pLeft->getSilver());
					}
					else
					{
						sprintf(pField, "Storage=%d, Durability=%ld, Silver=%d", (int)STORAGE_EXTRASLOT, pLeft->getDurability(), pLeft->getSilver());
					}
				}
				else
				{
						sprintf(pField, "Storage=%d, Durability=%ld", (int)STORAGE_EXTRASLOT, pLeft->getDurability());
				}
				pLeft->tinysave(pField);
			}
			// 검과 방패를 들고 있을 경우
			else
			{
				// 양손에 검과 방패를 들고 있었는데...양손 무기를 들려고 하면,
				// 검은 마우스 포인터에 달아줄 수 있지만, 방패는 어떻게 할 수가 없다.
				// 인벤토리에 넣어줘야 할 텐데, 지금 당장은 어떻게 할 지를 모르겠네...
				// 걍 입을 수 없다는 패킷을 보내주자...
				cerr << "양손에 칼과 방패를 들고 있어서, 양손 무기를 장착할 수 없습니다." << endl;
				return;
			}
		}
		// 양손에 아이템을 들고 있지 않을 경우
		else 
		{
			char pField[80];

			// 오른쪽에 아이템을 들고 있을 경우
			if (isWear(WEAR_RIGHTHAND))
			{
				pRight = getWearItem(WEAR_RIGHTHAND);
				// 요구한 아이템을 장착 포인트에 넣는다.
				//m_pWearItem[WEAR_RIGHTHAND] = pItem;
				addWearItem(WEAR_RIGHTHAND, pItem);
				//m_pWearItem[WEAR_LEFTHAND]  = pItem;
				addWearItem(WEAR_LEFTHAND, pItem);

				// by sigi. 2002.5.15
				//pItem->save(m_Name, STORAGE_GEAR, 0, Part, 0);
				sprintf(pField, "Storage=%d, X=%d, Y=%d", STORAGE_GEAR, Part, getCurrentGearSlotID());
				pItem->tinysave(pField);

				// 원래 있던 아이템을 마우스 포인터에 달아 준다.
				addItemToExtraInventorySlot(pRight);
				//pRight->save(m_Name, STORAGE_EXTRASLOT, 0, 0, 0);
//				sprintf(pField, "Storage=%d", STORAGE_EXTRASLOT);
				if( pRight->isSilverWeapon() )
				{
					if( pRight->isGun() )
					{
						sprintf(pField, "Storage=%d, Durability=%ld, BulletCount=%d, Silver=%d", STORAGE_EXTRASLOT, pRight->getDurability(), pRight->getBulletCount(), pRight->getSilver());
					}
					else
					{
						sprintf(pField, "Storage=%d, Durability=%ld, Silver=%u", STORAGE_EXTRASLOT, pRight->getDurability(), pRight->getSilver());
					}
				}
				else
				{
						sprintf(pField, "Storage=%d, Durability=%ld", STORAGE_EXTRASLOT, pRight->getDurability());
				}
				pRight->tinysave(pField);
			}
			// 왼쪽에 아이템을 들고 있을 경우
			else if (isWear(WEAR_LEFTHAND))
			{
				pLeft = getWearItem(WEAR_LEFTHAND);
				// 요구한 아이템을 장착 포인트에 넣는다.
				//m_pWearItem[WEAR_RIGHTHAND] = pItem;
				addWearItem(WEAR_RIGHTHAND, pItem);
				//m_pWearItem[WEAR_LEFTHAND]  = pItem;
				addWearItem(WEAR_LEFTHAND, pItem);

				// by sigi. 2002.5.15
				//pItem->save(m_Name, STORAGE_GEAR, 0, Part, 0);
				sprintf(pField, "Storage=%d, X=%d, Y=%d", STORAGE_GEAR, Part, getCurrentGearSlotID());
				pItem->tinysave(pField);

				// 원래 있던 아이템을 마우스 포인터에 달아 준다.
				addItemToExtraInventorySlot(pLeft);
				//pLeft->save(m_Name, STORAGE_EXTRASLOT, 0, 0, 0);
//				sprintf(pField, "Storage=%d", STORAGE_EXTRASLOT);
				if( pLeft->isSilverWeapon() )
				{
					if( pLeft->isGun() )
					{
						sprintf(pField, "Storage=%d, Durability=%ld, BulletCount=%d, Silver=%d", STORAGE_EXTRASLOT, pLeft->getDurability(), pLeft->getBulletCount(), pLeft->getSilver());
					}
					else
					{
						sprintf(pField, "Storage=%d, Durability=%ld, Silver=%d", STORAGE_EXTRASLOT, pLeft->getDurability(), pLeft->getSilver());
					}
				}
				else
				{
						sprintf(pField, "Storage=%d, Durability=%ld", STORAGE_EXTRASLOT, pLeft->getDurability());
				}

				pLeft->tinysave(pField);
			}
			// 아무쪽도 아이템을 들고 있지 않을 경우
			else
			{
				// 요구한 아이템을 장착 포인트에 넣는다.
				//m_pWearItem[WEAR_RIGHTHAND] = pItem;
				addWearItem(WEAR_RIGHTHAND, pItem);
				//m_pWearItem[WEAR_LEFTHAND]  = pItem;
				addWearItem(WEAR_LEFTHAND, pItem);

				// by sigi. 2002.5.15
				//pItem->save(m_Name, STORAGE_GEAR, 0, Part, 0);
				sprintf(pField, "Storage=%d, X=%d, Y=%d", STORAGE_GEAR, Part, getCurrentGearSlotID());
				pItem->tinysave(pField);
			}
		}
	}
	else
	{
		char pField[80];

		if (isWear(Part))
		{
			pPrevItem = getWearItem(Part);
			// 요구한 아이템을 장착 포인트에 넣는다.
			//m_pWearItem[Part] = pItem;
			addWearItem(Part, pItem);

			// by sigi. 2002.5.15
			//pItem->save(m_Name, STORAGE_GEAR, 0, Part, 0);
			sprintf(pField, "Storage=%d, X=%d, Y=%d", STORAGE_GEAR, Part, getCurrentGearSlotID());
			pItem->tinysave(pField);

			// 원래 있던 아이템을 마우스 포인터에 달아 준다.
			addItemToExtraInventorySlot(pPrevItem);

			//pPrevItem->save(m_Name, STORAGE_EXTRASLOT, 0, 0, 0);
//			sprintf(pField, "Storage=%d", STORAGE_EXTRASLOT);
			if( pPrevItem->isSilverWeapon() )
				{
					if( pPrevItem->isGun() )
					{
						sprintf(pField, "Storage=%d, Durability=%ld, BulletCount=%d, Silver=%d", STORAGE_EXTRASLOT, pPrevItem->getDurability(), pPrevItem->getBulletCount(), pPrevItem->getSilver());
					}
					else
					{
						sprintf(pField, "Storage=%d, Durability=%ld, Silver=%d", STORAGE_EXTRASLOT, pPrevItem->getDurability(), pPrevItem->getSilver());
					}
				}
				else
				{
						sprintf(pField, "Storage=%d, Durability=%ld", STORAGE_EXTRASLOT, pPrevItem->getDurability());
				}
			pPrevItem->tinysave(pField);
		}
		else
		{
			// 요구한 아이템을 장착 포인트에 넣는다.
			//m_pWearItem[Part] = pItem;
			addWearItem(Part, pItem);
			//pItem->save(m_Name, STORAGE_GEAR, 0, Part, 0);
			sprintf(pField, "Storage=%d, X=%d, Y=%d", STORAGE_GEAR, Part, getCurrentGearSlotID());
			pItem->tinysave(pField);
		}
	}

	ChangeShapeInfoWhenWear(pItem);

	__END_DEBUG
	__END_CATCH
}

// Slayer::wearItem()
// Item을 장착창에 장착시키고 능력치를 계산한다.
void Slayer::wearItem(WearPart Part)
	throw (Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	// 장착 준비중인 아이템을 받아온다.
	Item* pItem = getExtraInventorySlotItem();
	Assert(pItem != NULL);

	Item::ItemClass IClass      = pItem->getItemClass();
	OptionInfo*     pOptionInfo = NULL;
	Item*           pLeft       = NULL;
	Item*           pRight      = NULL;
	Item*           pPrevItem   = NULL;
	GCTakeOff       _GCTakeOff;

	// 첫번째 옵션의 색깔을 지정한다.
	if (pItem->getFirstOptionType() != 0)
		pOptionInfo = g_pOptionInfoManager->getOptionInfo(pItem->getFirstOptionType());


	if (IClass == Item::ITEM_CLASS_SHIELD) Part = WEAR_LEFTHAND;
	if (IClass == Item::ITEM_CLASS_SWORD)  Part = WEAR_RIGHTHAND;

	// 먼저 옷을 입히거나, 벗기기 전에 현재의 능력치를 버퍼에다 저장해 둔다.
	// 이는 나중에 변한 능력치만을 전송하기 위한 것이다.
	SLAYER_RECORD prev;
	getSlayerRecord(prev);

	// 현재 기획에서는...능력치가 모자라더라도 아이템을 무조건 사용할 수는
	// 있다. 하지만 아이템에 의한 능력치가 적용이 되지 않는다. 
	// 그러므로 일단 아이템을 해당하는 장착창에다 집어넣는다.
	// 양손 무기일 경우에는 양손 장착창에다 하나의 아이템 포인터를 할당...
	if (isTwohandWeapon(pItem))
	{
		// 양손에 아이템을 들고 있을 경우
		if (isWear(WEAR_RIGHTHAND) && isWear(WEAR_LEFTHAND))
		{
			pLeft  = getWearItem(WEAR_RIGHTHAND);
			pRight = getWearItem(WEAR_LEFTHAND);
			
			// 양손 무기를 들고 있을 경우
			if (pLeft == pRight)
			{
				char pField[80];

				takeOffItem(WEAR_LEFTHAND, false, false);

				// 요구한 아이템을 장착 포인트에 넣고,
				//m_pWearItem[WEAR_RIGHTHAND] = pItem;
				addWearItem(WEAR_RIGHTHAND, pItem);
				//m_pWearItem[WEAR_LEFTHAND]  = pItem;
				addWearItem(WEAR_LEFTHAND, pItem);
				// by sigi. 2002.5.15
				//pItem->save(m_Name, STORAGE_GEAR, 0, Part, 0);
				sprintf(pField, "Storage=%d, X=%d, Y=%d", STORAGE_GEAR, Part, getCurrentGearSlotID());
				pItem->tinysave(pField);

				// 요구한 아이템을 마우스 포인터에서 제거한다.
				deleteItemFromExtraInventorySlot();
				// 원래 있던 아이템을 마우스 포인터에 달아 준다.
				addItemToExtraInventorySlot(pLeft);

				sprintf(pField, "Storage=%d", STORAGE_EXTRASLOT);
				pLeft->tinysave(pField);

			}
			// 검과 방패를 들고 있을 경우
			else
			{
				// 양손에 검과 방패를 들고 있었는데...양손 무기를 들려고 하면,
				// 검은 마우스 포인터에 달아줄 수 있지만, 방패는 어떻게 할 수가 없다.
				// 인벤토리에 넣어줘야 할 텐데, 지금 당장은 어떻게 할 지를 모르겠네...
				// 걍 입을 수 없다는 패킷을 보내주자...
				return;
			}
		}
		// 양손에 아이템을 들고 있지 않을 경우
		else 
		{
			// by sigi. 2002.5.15
			char pField[80];

			// 오른쪽에 아이템을 들고 있을 경우
			if (isWear(WEAR_RIGHTHAND))
			{
				pRight = getWearItem(WEAR_RIGHTHAND);

				takeOffItem(WEAR_RIGHTHAND, false, false);

				// 요구한 아이템을 장착 포인트에 넣는다.
				//m_pWearItem[WEAR_RIGHTHAND] = pItem;
				addWearItem(WEAR_RIGHTHAND, pItem);
				//m_pWearItem[WEAR_LEFTHAND]  = pItem;
				addWearItem(WEAR_LEFTHAND, pItem);
				//pItem->save(m_Name, STORAGE_GEAR, 0, Part, 0);

				// by sigi. 2002.5.15
				sprintf(pField, "Storage=%d, X=%d, Y=%d", STORAGE_GEAR, Part, getCurrentGearSlotID());
				pItem->tinysave(pField);

				// 요구한 아이템을 마우스 포인터에서 제거한다.
				deleteItemFromExtraInventorySlot();
				// 원래 있던 아이템을 마우스 포인터에 달아 준다.
				addItemToExtraInventorySlot(pRight);
				
				sprintf(pField, "Storage=%d", STORAGE_EXTRASLOT);
				pRight->tinysave(pField);
				
			}
			// 왼쪽에 아이템을 들고 있을 경우
			else if (isWear(WEAR_LEFTHAND))
			{
				pLeft = getWearItem(WEAR_LEFTHAND);
				
				takeOffItem(WEAR_LEFTHAND, false, false);

				// 요구한 아이템을 장착 포인트에 넣는다.
				//m_pWearItem[WEAR_RIGHTHAND] = pItem;
				addWearItem(WEAR_RIGHTHAND, pItem);
				//m_pWearItem[WEAR_LEFTHAND]  = pItem;
				addWearItem(WEAR_LEFTHAND, pItem);
				
				// by sigi. 2002.5.15
				//pItem->save(m_Name, STORAGE_GEAR, 0, Part, 0);
				sprintf(pField, "Storage=%d, X=%d, Y=%d", STORAGE_GEAR, Part, getCurrentGearSlotID());
				pItem->tinysave(pField);

				// 요구한 아이템을 마우스 포인터에서 제거한다.
				deleteItemFromExtraInventorySlot();
				// 원래 있던 아이템을 마우스 포인터에 달아 준다.
				addItemToExtraInventorySlot(pLeft);

				sprintf(pField, "Storage=%d", STORAGE_EXTRASLOT);
				pLeft->tinysave(pField);
			}
			// 아무쪽도 아이템을 들고 있지 않을 경우
			else
			{
				// 요구한 아이템을 장착 포인트에 넣는다.
				//m_pWearItem[WEAR_RIGHTHAND] = pItem;
				addWearItem(WEAR_RIGHTHAND, pItem);
				//m_pWearItem[WEAR_LEFTHAND]  = pItem;
				addWearItem(WEAR_LEFTHAND, pItem);

				pItem->save(m_Name, STORAGE_GEAR, 0, Part, getCurrentGearSlotID());
				// 요구한 아이템을 마우스 포인터에서 제거한다.
				deleteItemFromExtraInventorySlot();
			}
		}
	}
	else
	{
		char pField[80];

		if (isWear(Part))
		{
			pPrevItem = getWearItem(Part);

			takeOffItem(Part, false, false);
			
			// 요구한 아이템을 장착 포인트에 넣는다.
			//m_pWearItem[Part] = pItem;
			addWearItem(Part, pItem);
			// by sigi. 2002.5.15
			//pItem->save(m_Name, STORAGE_GEAR, 0, Part, 0);
			sprintf(pField, "Storage=%d, X=%d, Y=%d", STORAGE_GEAR, Part, getCurrentGearSlotID());
			pItem->tinysave(pField);

			// 요구한 아이템을 마우스 포인터에서 제거한다.
			deleteItemFromExtraInventorySlot();
			// 원래 있던 아이템을 마우스 포인터에 달아 준다.
			addItemToExtraInventorySlot(pPrevItem);

			sprintf(pField, "Storage=%d", STORAGE_EXTRASLOT);
			pPrevItem->tinysave(pField);
		}
		else
		{
			// 요구한 아이템을 장착 포인트에 넣는다.
			//m_pWearItem[Part] = pItem;
			addWearItem(Part, pItem);

			// by sigi. 2002.5.15
			//pItem->save(m_Name, STORAGE_GEAR, 0, Part, 0);
			sprintf(pField, "Storage=%d, X=%d, Y=%d", STORAGE_GEAR, Part, getCurrentGearSlotID());
			pItem->tinysave(pField);
			// 요구한 아이템을 마우스 포인터에서 제거한다.
			deleteItemFromExtraInventorySlot();
		}
	}

	// 일단 입었다고 체크해둔다. 
	// by sigi. 2002.10.31
	m_pRealWearingCheck[Part] = true;

	initAllStat();
	sendRealWearingInfo();
	sendModifyInfo(prev); // 비교 후 달라진 능력치 전송

	//bool bisWeapon = false;
	bool bisChange = false;

	//ItemType_t IType = pItem->getItemType();

	Color_t color = getItemShapeColor( pItem, pOptionInfo ); 

	// 함수로 뺐다. by sigi. 2002.10.30
	bisChange = changeShape( pItem, color );

	/*
	if (bisWeapon) 
	{
		// 무기에 Strking이 붙어 있으면...
		EffectManager* pEffectManager = pItem->getEffectManager();
		if (pEffectManager->isEffect(Effect::EFFECT_CLASS_STRIKING)) 
		{
			Effect* pEffect = pEffectManager->findEffect(Effect::EFFECT_CLASS_STRIKING);
			// 현제 시간 체크
			Timeval currentTime;
			getCurrentTime(currentTime);

			// 남은시간 산출하기
			Timeval DeadLine = pEffect->getDeadline();
			Turn_t Duration = DeadLine.tv_sec - currentTime.tv_sec;

			GCAddEffect gcAddEffect;
			gcAddEffect.setObjectID(getObjectID());
			gcAddEffect.setEffectID(Effect::EFFECT_CLASS_STRIKING);
			gcAddEffect.setDuration(Duration*10);
			m_pZone->broadcastPacket(m_X, m_Y, &gcAddEffect);
		}
	}
	*/

	// 실제로 입을 수 있으면 복장을 바꿔준다. by sigi. 2002.10.30
	if (m_pRealWearingCheck[Part])
	//if (bisChange) 
	{
		ChangeShapeInfoWhenWear(pItem);
		
		Color_t color = getItemShapeColor( pItem );
		
		GCChangeShape _GCChangeShape;
		_GCChangeShape.setObjectID(getObjectID());
		_GCChangeShape.setItemClass(IClass);
		_GCChangeShape.setItemType(pItem->getItemType());
		_GCChangeShape.setOptionType(pItem->getFirstOptionType());
		_GCChangeShape.setAttackSpeed(m_AttackSpeed[ATTR_CURRENT]);

		if ( color == QUEST_COLOR )
			_GCChangeShape.setFlag( SHAPE_FLAG_QUEST );

		Zone* pZone = m_pZone;
		pZone->broadcastPacket(m_X, m_Y, &_GCChangeShape, this);
	}

	if (m_pZone != NULL)
	{
		GCOtherModifyInfo gcOtherModifyInfo;
		makeGCOtherModifyInfo(&gcOtherModifyInfo, this, &prev);

		if (gcOtherModifyInfo.getShortCount() != 0 || gcOtherModifyInfo.getLongCount() != 0)
		{
			m_pZone->broadcastPacket(m_X, m_Y, &gcOtherModifyInfo, this);
		}
	}

	__END_DEBUG
	__END_CATCH
}

// Slayer::takeOffItem()
// *NOTE : 임시로 bool 타입의 parameter를 넣어 둔다.
//         코드가 구질구질 해지기 때문에 나중에 바꾸도록 한다.. 필수!
void Slayer::takeOffItem(WearPart Part, bool bAddOnMouse, bool bSendModifyInfo)
	throw (Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	SLAYER_RECORD prev;

	// 장착창에 있는 아이템을 받아온다.
	//Item* pItem = m_pWearItem[Part];
	Item* pItem = getWearItem(Part);
	Assert(pItem != NULL);
	Item::ItemClass IClass = pItem->getItemClass();

	if (Part == WEAR_LEFTHAND || Part == WEAR_RIGHTHAND)
	{
		//if (m_pWearItem[WEAR_RIGHTHAND] && m_pWearItem[WEAR_LEFTHAND])
		if (getWearItem(WEAR_RIGHTHAND) && getWearItem(WEAR_LEFTHAND))
		{
			//if (m_pWearItem[WEAR_RIGHTHAND] == m_pWearItem[WEAR_LEFTHAND])
			if (getWearItem(WEAR_RIGHTHAND) == getWearItem(WEAR_LEFTHAND))
			{
				//m_pWearItem[WEAR_RIGHTHAND] = NULL;
				deleteWearItem(WEAR_RIGHTHAND);
				//m_pWearItem[WEAR_LEFTHAND] = NULL;
				deleteWearItem(WEAR_LEFTHAND);
			}
		}
	}

	// 아이템을 장착포인트에서 제거한다.
	if (isTwohandWeapon(pItem))
	{
		//m_pWearItem[WEAR_RIGHTHAND] = NULL;
		deleteWearItem(WEAR_RIGHTHAND);
		//m_pWearItem[WEAR_LEFTHAND] = NULL;
		deleteWearItem(WEAR_LEFTHAND);
	}
	else {
		//m_pWearItem[Part] = NULL;
		deleteWearItem(Part);
	}

	// wearItem에서 지정된 슬랏에 옷을 이미 입고 있는 경우에, 그것을 벗기고
	// 다시 옷을 입히는데, 그러면 벗길 때 패킷을 한번, 입었을 때 다시 패킷을
	// 한번, 총 두 번의 패킷을 보내게 된다. 그것을 방지하기 위해서
	// bool 변수를 하나 집어넣었다. -- 2002.01.24 김성민
	if (bSendModifyInfo)
	{
		getSlayerRecord(prev); 
		initAllStat();
		sendRealWearingInfo();
		sendModifyInfo(prev);
	}
	else
	{
		initAllStat();
	}

	// 있어선 안될 체크 -_-; 임시 땜빵
	// 아이템을 마우스 커서에다 달아준당.
	char pField[80] = {0, };
	char pFieldStorage[80] = {0, };
	
	if (bAddOnMouse) 
	{
		addItemToExtraInventorySlot(pItem);

		sprintf(pFieldStorage, "Storage=%d,", STORAGE_EXTRASLOT);
	}
	
	if (pItem->isSilverWeapon())
	{
		if (pItem->isGun())
		{
			sprintf(pField, "%sDurability=%ld, BulletCount=%d, Silver=%d", 
				pFieldStorage, 
				pItem->getDurability(), 
				pItem->getBulletCount(), 
				pItem->getSilver()
			);
		}
		else
		{
			sprintf(pField, "%sDurability=%ld, Silver=%d", 
				pFieldStorage, 
				pItem->getDurability(), 
				pItem->getSilver()
			);
		}
	}
	else
	{
		sprintf(pField, "%sDurability=%ld", pFieldStorage, pItem->getDurability());
	}
	pItem->tinysave(pField);
	
	if ( ChangeShapeInfoWhenTakeOff(pItem) )
	{
		GCTakeOff _GCTakeOff;
		
		_GCTakeOff.setObjectID(getObjectID());
		_GCTakeOff.setSlotID((SlotID_t)GetAddonType(pItem->getItemClass()));
		
		m_pZone->broadcastPacket(getX(), getY(), &_GCTakeOff, this);
	}

	/*
	if (bisWeapon) 
	{
		// 무기에 Strking이 붙어 있으면...
		EffectManager* pEffectManager = pItem->getEffectManager();

		if (pEffectManager->isEffect(Effect::EFFECT_CLASS_STRIKING)) 
		{
			GCRemoveEffect removeEffect;
			removeEffect.setObjectID(getObjectID());
			removeEffect.addEffectList(Effect::EFFECT_CLASS_STRIKING);
			m_pZone->broadcastPacket(m_X, m_Y, &removeEffect);
		}
	}
	*/

	if (m_pZone != NULL)
	{
		GCOtherModifyInfo gcOtherModifyInfo;
		makeGCOtherModifyInfo(&gcOtherModifyInfo, this, &prev);

		if (gcOtherModifyInfo.getShortCount() != 0 || gcOtherModifyInfo.getLongCount() != 0)
		{
			m_pZone->broadcastPacket(m_X, m_Y, &gcOtherModifyInfo, this);
		}
	}

	__END_DEBUG
	__END_CATCH
}

// destroyGears
// 장착 아이템을 Delete 한다.
void Slayer::destroyGears() 
	throw()
{
	__BEGIN_DEBUG

	for(GearSlotID_t GearSlotID = 0; GearSlotID < m_pWearItemSwapPool.size(); ++GearSlotID)
	{
		//for (int j = 0; j < WEAR_MAX; j++) 
		for (int j = 0; j < m_pWearItemSwapPool[GearSlotID].size(); j++) 
		{
			//Item* pItem = m_pWearItem[j];
			Item* pItem = m_pWearItemSwapPool[GearSlotID][j];
			if (pItem != NULL) 
			{
				// 양손 무기인지를 검사해서 아이템 하나를 지우면서
				// 양손을 비워준다.
				if (isTwohandWeapon(pItem))
				{
					//m_pWearItem[WEAR_RIGHTHAND] = NULL;
					deleteWearItem(GearSlotID, WEAR_RIGHTHAND);
					//m_pWearItem[WEAR_LEFTHAND]  = NULL;
					deleteWearItem(GearSlotID, WEAR_LEFTHAND);
				}
				else 
				{
					//m_pWearItem[j] = NULL;
					deleteWearItem(GearSlotID, j);
				}
	
				SAFE_DELETE(pItem);
			}
		}
	}

	__END_DEBUG
}

bool Slayer::isRealWearing(WearPart part)
	throw()
{
	__BEGIN_TRY

	if (part >= WEAR_MAX) throw ("Slayer::isRealWearing() : invalid wear point!");
	//if (m_pWearItem[part] == NULL) return false;
	if (!isWear(part)) return false;
	
	GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(getPlayer());

	if ( !pGamePlayer->isAuthGameFeature(GamePlayer::GAME_FEATURE_GEARSWAPPING, (void *)(intptr_t)getCurrentGearSlotID())) 
	{
		return false;
	}

	if (part >= WEAR_ZAP1 && part <= WEAR_ZAP4)
	{
		// 해당 위치에 반지도 있어야 된다.
		//if ( m_pWearItem[part-WEAR_ZAP1+WEAR_FINGER1]==NULL ) return false;
		if ( !isWear(part-WEAR_ZAP1+WEAR_FINGER1) ) return false;
	}
	if (part >=WEAR_CUE1 && part <= WEAR_CUE2)
	{
		// 해당 위치에 팔찌도 있어야 된다.
		//if ( m_pWearItem[part-WEAR_CUE1+WEAR_WRIST1]==NULL ) return false;
		if ( !isWear(part-WEAR_CUE1+WEAR_WRIST1) ) return false;
	}

	//return isRealWearing(m_pWearItem[part]);
	return isRealWearing(getWearItem(part));

	__END_CATCH
}

bool Slayer::isRealWearing(Item* pItem)
	throw()
{
	__BEGIN_TRY

	if (pItem == NULL) return false;
	if ( pItem->getDurability() == 0 ) return false;

	GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(getPlayer());

	if ( !pGamePlayer->isAuthGameFeature(GamePlayer::GAME_FEATURE_GEARSWAPPING, (void *)(intptr_t)getCurrentGearSlotID())) 
	{
			return false;
	}

/*	if ( m_pZone != NULL && m_pZone->isDynamicZone() && m_pZone->getDynamicZone()->getTemplateZoneID() == 4003 )
	{
		if ( !isSlayerWeapon( pItem->getItemClass() ) ) return false;
	}*/

	ItemInfo* pItemInfo = g_pItemInfoManager->getItemInfo(pItem->getItemClass(), pItem->getItemType());

	Level_t			ReqAdvancedLevel = pItemInfo->getReqAdvancedLevel();
	if ( ReqAdvancedLevel > 0 && ( !isAdvanced() || getAdvancementClassLevel() < ReqAdvancedLevel ) ) return false;

	if ( pItem->getItemClass() == Item::ITEM_CLASS_SMG || pItem->getItemClass() == Item::ITEM_CLASS_SG )
	{
		if ( ReqAdvancedLevel <= 0 && isAdvanced() ) return false;
	}
/*	if ( isSlayerWeapon(pItem->getItemClass()) || pItem->getItemClass() == Item::ITEM_CLASS_COAT || pItem->getItemClass() == Item::ITEM_CLASS_TROUSER )
	{
		if ( ReqAdvancedLevel <= 0 && isAdvanced() ) return false;
	}*/

	// 시간제한아이템은 레어나 유니크나 무료사용자도 쓸 수 있다....... 2003.5.4
	if ( pItem->isTimeLimitItem() )
	{
		Attr_t    ReqGender = pItemInfo->getReqGender();
		if ( ( m_Sex == MALE && ReqGender == GENDER_FEMALE ) ||
			 ( m_Sex == FEMALE && ReqGender == GENDER_MALE ) ) return false;
		return true;
	}

	// 프리미엄 존에서는 유료사용자만 유니크/레어 아이템이 적용된다.
	// 커플링도 유료사용자만 쓸 수 있다. by Sequoia 2003. 3. 5.
	if (getZone()->isPremiumZone()
		&& (pItem->isUnique() || pItem->getOptionTypeSize()>1 || 
			pItem->getItemClass() == Item::ITEM_CLASS_COUPLE_RING || pItem->getItemClass() == Item::ITEM_CLASS_VAMPIRE_COUPLE_RING))
	{
		GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(getPlayer());
//		if (!pGamePlayer->isPayPlaying() 
//			&& !pGamePlayer->isPremiumPlay())
		if (!pGamePlayer->isPremiumPlay() && !g_pVariableManager->isEndRestrictionWear()) // 20080227 유료존 티켓 추가로 수정
		{
			//cout << "Premium Item :" << pItem->getItemClassName().c_str() << endl;
			return false;
		}
	}

	if ( isCoupleRing( pItem ) )
	{
		return true;
	}

	Attr_t    ReqSTR    = pItemInfo->getReqSTR();
	Attr_t    ReqDEX    = pItemInfo->getReqDEX();
	Attr_t    ReqINT    = pItemInfo->getReqINT();
	Attr_t    ReqSum    = pItemInfo->getReqSum();
	Attr_t    ReqGender = pItemInfo->getReqGender();

	// 기본 아이템의 능력치 총합 요구치가 300이 넘으면 옵션을 포함한 요구치가 435까지 올라갈 수 있다.
	// 기본 아이템의 요구치가 300 이하일 경우 옵션을 다 포함해도 300을 넘어서는 안 된다.
	// 다른 것들도 마찬가지다. 2003.3.21 by Sequoia
	Attr_t	ReqSumMax	= ( ( ReqSum > MAX_SLAYER_SUM_OLD ) ? MAX_SLAYER_SUM : MAX_SLAYER_SUM_OLD );
	Attr_t	ReqSTRMax	= ( ( ReqSTR > MAX_SLAYER_ATTR_OLD ) ? MAX_SLAYER_ATTR : MAX_SLAYER_ATTR_OLD );
	Attr_t	ReqDEXMax	= ( ( ReqDEX > MAX_SLAYER_ATTR_OLD ) ? MAX_SLAYER_ATTR : MAX_SLAYER_ATTR_OLD );
	Attr_t	ReqINTMax	= ( ( ReqINT > MAX_SLAYER_ATTR_OLD ) ? MAX_SLAYER_ATTR : MAX_SLAYER_ATTR_OLD );

	// 아이템이 옵션을 가지고 있다면, 
	// 옵션의 종류에 따라서 능력치 제한을 올려준다.
	const list<OptionType_t>& optionTypes = pItem->getOptionTypeList();
	if (!optionTypes.empty())
	{
		// 모든 옵션에 대해서...
		list<OptionType_t>::const_iterator itr;
		
		OptionInfo* pOptionInfo = NULL;
		OptionType_t optionType;
		
		for (itr=optionTypes.begin(); itr!=optionTypes.end(); itr++)
		{
			optionType = *itr;
			pOptionInfo = g_pOptionInfoManager->getOptionInfo( optionType );

			if ( pOptionInfo == NULL )
			{
				filelog("InvalidOptionInfo.log", "Slayer::isRealWearing() Name=%s InvalidOptionType=%d", 
					getName().c_str(), optionType
				);
							
				return false;				
			}
			
			if (ReqSTR != 0) ReqSTR += (pOptionInfo->getReqSum() * 2);
			if (ReqDEX != 0) ReqDEX += (pOptionInfo->getReqSum() * 2);
			if (ReqINT != 0) ReqINT += (pOptionInfo->getReqSum() * 2);
			if (ReqSum != 0) ReqSum += (pOptionInfo->getReqSum());
		}

		/*
		ReqSTR = max((int)ReqSTR, pOptionInfo->getReqSTR());
		ReqDEX = max((int)ReqDEX, pOptionInfo->getReqDEX());
		ReqINT = max((int)ReqINT, pOptionInfo->getReqINT());
		ReqSum = max((int)ReqSum, pOptionInfo->getReqSum());
		*/
	}

	// 2003.1.6 by Sequoia, Bezz
	// 2003.3.21 위에 정의된 Max값이 최대치로 제한된다.
	ReqSTR = min(ReqSTR, ReqSTRMax);
	ReqDEX = min(ReqDEX, ReqDEXMax);
	ReqINT = min(ReqINT, ReqINTMax);
	ReqSum = min(ReqSum, ReqSumMax);
	
	// 능력치 제한이 하나라도 있다면,
	// 그 능력을 만족시키는지 검사해야 한다.
	Attr_t CSTR = m_STR[ATTR_CURRENT];
	Attr_t CDEX = m_DEX[ATTR_CURRENT];
	Attr_t CINT = m_INT[ATTR_CURRENT];
	Attr_t CSUM = CSTR + CDEX + CINT;

	if (CSTR < ReqSTR
		|| CDEX < ReqDEX
		|| CINT < ReqINT
		|| CSUM < ReqSum
		|| m_Sex == MALE && ReqGender == GENDER_FEMALE
		|| m_Sex == FEMALE && ReqGender == GENDER_MALE) 
	{
		//cout << "Disable: " << pItem->getItemClassName().c_str() << endl;
		return false;
	}

	//cout << "Enable: " << pItem->getItemClassName().c_str() << endl;

	return true;

	__END_CATCH
}

bool Slayer::isRealWearingEx(WearPart part) const
{
	if (part >= WEAR_MAX) return false;

	GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(getPlayer());

	if ( !pGamePlayer->isAuthGameFeature(GamePlayer::GAME_FEATURE_GEARSWAPPING, (void *)(intptr_t)getCurrentGearSlotID())) 
	{
		return false;
	}
	
	return m_pRealWearingCheck[part];
}

DWORD Slayer::sendRealWearingInfo(void)
	throw()
{
	__BEGIN_TRY

	DWORD info = 0;
	DWORD flag = 1;

	for (int i=0; i<WEAR_MAX; i++)
	{
		if (isRealWearing((Slayer::WearPart)i)) info |= flag;
		flag <<= 1;
	}

    GCRealWearingInfo pkt;
    pkt.setInfo(info);
    m_pPlayer->sendPacket(&pkt);
    
    SlayerSkillSlot* pSkillSlot = hasSkill(SKILL_AURA_SHIELD);
  	if ( pSkillSlot != NULL )
  	{
  		pSkillSlot->setRunTime( 0, false );
  	}

	return info;

	__END_CATCH
}

void Slayer::setMotorcycle(Motorcycle* pMotorcycle)
	throw()
{
	__BEGIN_DEBUG

	// 모터사이클을 셋팅한다.
	m_pMotorcycle = pMotorcycle;


	MotorcycleType motorcycleType = getMotorcycleType(pMotorcycle->getItemType());
	// SlaeyrInfo에 모토사이클을 타고 있다는 것을 셋팅한다.
	//m_SlayerInfo.setMotorcycleType(MOTORCYCLE1);
	// by sigi.2002.6.22
	m_SlayerInfo.setMotorcycleType( motorcycleType);

	switch( motorcycleType )
	{
		case MOTORCYCLE1 :
		case MOTORCYCLE2 :
		case MOTORCYCLE3 :
			if ( !pMotorcycle->hasOptionType() )
			{
  			  	m_SlayerInfo.setMotorcycleColor(388);
			}
			else
			{
				OptionType_t option = pMotorcycle->getFirstOptionType();
				OptionInfo* pOptionInfo = g_pOptionInfoManager->getOptionInfo( option );

				if ( pOptionInfo != NULL )
				{
					m_SlayerInfo.setMotorcycleColor( pOptionInfo->getColor() );
				}
				else
				{
			   		m_SlayerInfo.setMotorcycleColor(388);
				}
			}

  		 	m_SlayerInfo.setMotorcycleEffectColor(0);

			break;
		case MOTORCYCLE_WING :
			{
				m_SlayerInfo.setMotorItemType(getMotorcycle()->getItemType());
				m_SlayerInfo.setMotorcycleColor( pMotorcycle->getBodyColor() );
				m_SlayerInfo.setMotorcycleEffectColor( pMotorcycle->getEffectColor() );
			}
			break;
	}

	__END_DEBUG
}

void Slayer::getOffMotorcycle()
	throw(Error)
{
	__BEGIN_DEBUG
	
	// 모토사이클을 존에 떨어트린다.
	TPOINT pt = m_pZone->addItem((Item*)m_pMotorcycle, m_X, m_Y);

	if (pt.x != -1) 
	{
		MotorcycleBox* pMotorcycleBox = g_pParkingCenter->getMotorcycleBox(m_pMotorcycle->getItemID());

		if (pMotorcycleBox == NULL)
		{
			//cout << "Slayer::getOffMotorcycle() - pMotorcycleBox is NULL" << endl;
			filelog("errorLog.txt", "Slayer::getOffMotorcycle() - No MotorcycleBox: %d", (int)m_pMotorcycle->getItemID());
			//throw Error("오토바이를 벗을려고 하는데 ParkingCenter에 MotorcycleBox가 없습니다.");
		}
	} 
	else 
	{
		// 다른 아이템들이 넘 많이 깔려 있을 경우 그냥 Box자체를 삭제 해준다..
		// 다시 받기를 해야 하겠지? -_-;
		if (g_pParkingCenter->hasMotorcycleBox(m_pMotorcycle->getItemID())) 
		{
			g_pParkingCenter->deleteMotorcycleBox(m_pMotorcycle->getItemID());
		}

	}

	// 슬레이어의 모토사이클을 벗긴다.
	m_pMotorcycle = NULL;

	// 슬레이어가 모토사이클을 타고 있지 않다는 것을 셋팅한다.
	m_SlayerInfo.setMotorcycleType(MOTORCYCLE_NONE);

	__END_DEBUG
}

PCSlayerInfo2* Slayer::getSlayerInfo2 () const
	throw ()
{
	__BEGIN_DEBUG

	PCSlayerInfo2* pInfo = new PCSlayerInfo2();

	pInfo->setObjectID(m_ObjectID);
	pInfo->setName(m_Name);
	pInfo->setSex(m_Sex);
	pInfo->setHairStyle(m_HairStyle);
	pInfo->setHairColor(m_HairColor);
	pInfo->setSkinColor(m_SkinColor);
	pInfo->setMasterEffectColor(m_MasterEffectColor);
	pInfo->setBorn(m_Born);

	//cout << "PCSlayerInfo2: HairStyle = " << HairStyle2String[pInfo->getHairStyle()] << endl;

	//pInfo->setPhoneNumber(m_PhoneNumber);

	// 성향
	pInfo->setAlignment(m_Alignment);

	//cout << "STR[CURRENT]" << (int)m_STR[ATTR_CURRENT] << endl;
	//cout << "STR[MAX]" << (int)m_STR[ATTR_MAX] << endl;
	//cout << "STR[BASIC]" << (int)m_STR[ATTR_BASIC] << endl;
	//cout << "DEX[CURRENT]" << (int)m_DEX[ATTR_CURRENT] << endl;
	//cout << "DEX[MAX]" << (int)m_DEX[ATTR_MAX] << endl;
	//cout << "DEX[BASIC]" << (int)m_DEX[ATTR_BASIC] << endl;
	//cout << "INT[CURRENT]" << (int)m_INT[ATTR_CURRENT] << endl;
	//cout << "INT[MAX]" << (int)m_INT[ATTR_MAX] << endl;
	//cout << "INT[BASIC]" << (int)m_INT[ATTR_BASIC] << endl;

	// 능력치
	pInfo->setSTR(m_STR[ATTR_CURRENT], ATTR_CURRENT);
	pInfo->setSTR(m_STR[ATTR_MAX], ATTR_MAX);
	pInfo->setSTR(m_STR[ATTR_BASIC], ATTR_BASIC);
	pInfo->setDEX(m_DEX[ATTR_CURRENT], ATTR_CURRENT);
	pInfo->setDEX(m_DEX[ATTR_MAX], ATTR_MAX);
	pInfo->setDEX(m_DEX[ATTR_BASIC], ATTR_BASIC);
	pInfo->setINT(m_INT[ATTR_CURRENT], ATTR_CURRENT);
	pInfo->setINT(m_INT[ATTR_MAX], ATTR_MAX);
	pInfo->setINT(m_INT[ATTR_BASIC], ATTR_BASIC);

	// 20070910 슬레 승직 능력치 추가
	pInfo->setAdvancedSTR(getAdvancedSTR());
	pInfo->setAdvancedDEX(getAdvancedDEX());
	pInfo->setAdvancedINT(getAdvancedINT());
	
	// 능력치 경험치
//	pInfo->setSTRExp(m_STRExp);
//	pInfo->setDEXExp(m_DEXExp);
//	pInfo->setINTExp(m_INTExp);
	pInfo->setSTRExp( getSTRGoalExp() );
	pInfo->setDEXExp( getDEXGoalExp() );
	pInfo->setINTExp( getINTGoalExp() );

	// 계급
	pInfo->setRank(getRank());
	pInfo->setRankExp(getRankGoalExp());

//	cout << getRankGoalExp() << endl;

	pInfo->setHP(m_HP[ATTR_CURRENT] , m_HP[ATTR_MAX]);
	pInfo->setMP(m_MP[ATTR_CURRENT] , m_MP[ATTR_MAX]);
	pInfo->setFame(m_Fame);
	pInfo->setGold(m_Gold);
	pInfo->setSkillDomain(SKILL_DOMAIN_BLADE , m_SkillDomainLevels[SKILL_DOMAIN_BLADE] , m_GoalExp[SKILL_DOMAIN_BLADE]);
	pInfo->setSkillDomain(SKILL_DOMAIN_SWORD , m_SkillDomainLevels[SKILL_DOMAIN_SWORD] , m_GoalExp[SKILL_DOMAIN_SWORD]);
	pInfo->setSkillDomain(SKILL_DOMAIN_GUN , m_SkillDomainLevels[SKILL_DOMAIN_GUN] , m_GoalExp[SKILL_DOMAIN_GUN]);
	pInfo->setSkillDomain(SKILL_DOMAIN_ETC , m_SkillDomainLevels[SKILL_DOMAIN_ETC] , m_GoalExp[SKILL_DOMAIN_ETC]);
	pInfo->setSkillDomain(SKILL_DOMAIN_ENCHANT , m_SkillDomainLevels[SKILL_DOMAIN_ENCHANT] , m_GoalExp[SKILL_DOMAIN_ENCHANT]);
	pInfo->setSkillDomain(SKILL_DOMAIN_HEAL , m_SkillDomainLevels[SKILL_DOMAIN_HEAL] , m_GoalExp[SKILL_DOMAIN_HEAL]);
	pInfo->setSight(m_Sight);

//	for (int i = 0; i < 4; i++) 
//	{
//		pInfo->setHotKey(i, m_HotKey[i]);
//	}

	// 0이나 1 권한을 가지고 있으면
	// 운영자로 스프라이트를 출력해줘야 한다. 
	pInfo->setCompetence(m_CompetenceShape);
	pInfo->setGuildID(m_GuildID);
	pInfo->setGuildName( getGuildName() );
	pInfo->setGuildMemberRank( getGuildMemberRank() );

	// 현재 길드 유니온 막아놨는데 자꾸 문제가 생긴다.
	// 잠시 막아둔다.
	//GuildUnion* pUnion = GuildUnionManager::Instance().getGuildUnion( m_GuildID );
	GuildUnion* pUnion = NULL;
	if ( pUnion == NULL ) pInfo->setUnionID( 0 );
	else pInfo->setUnionID( pUnion->getUnionID() );

	pInfo->setAdvancementLevel( getAdvancementClassLevel() );
	pInfo->setAdvancementGoalExp( getAdvancementClassGoalExp() );
	pInfo->setAttrBonus( getBonus() );

	pInfo->setAttackBloodBurstPoint( getAttackBloodBurstPoint() );
	pInfo->setDefenseBloodBurstPoint( getDefenseBloodBurstPoint() );

	if ( getPartyID() != 0 )
	{
		pInfo->setPartyBloodBurstPoint( g_pGlobalPartyManager->getParty( getPartyID() )->getPartyBloodBurstPoint() );
	}
	else
	{
		pInfo->setPartyBloodBurstPoint( 0 );
	}

#ifdef __CONTRIBUTION_SYSTEM__
	pInfo->setContributePoint( getContributePoint() );
#endif
	//20090601 ksym555
	pInfo->setAttackSpeed(getAttackSpeed());
	

	return pInfo;

	__END_DEBUG
}

PCSlayerInfo3 Slayer::getSlayerInfo3 () const
	throw ()
{
	__BEGIN_DEBUG

	// 좌표와 방향은 너무 자주 바뀌기 때문에, 이 함수가 호출될 때에만
	// 지정해준다.
	m_SlayerInfo.setObjectID(m_ObjectID);	// by sigi. 2002.6.5. morph때문에
	m_SlayerInfo.setX(m_X);
	m_SlayerInfo.setY(m_Y);
	m_SlayerInfo.setDir(m_Dir);
	m_SlayerInfo.setCurrentHP(m_HP[ATTR_CURRENT]);
	m_SlayerInfo.setMaxHP(m_HP[ATTR_MAX]);
	m_SlayerInfo.setAlignment(m_Alignment);
	m_SlayerInfo.setGuildID(m_GuildID);

	// 공격 스피드
	m_SlayerInfo.setAttackSpeed(m_AttackSpeed[ATTR_CURRENT]);

	// by sigi. 2002.9.10
	m_SlayerInfo.setRank(getRank());

	// 2003.5.15 염색약용
    m_SlayerInfo.setHairColor(m_HairColor);
    m_SlayerInfo.setSkinColor(m_SkinColor);
	m_SlayerInfo.setMasterEffectColor(m_MasterEffectColor);

	
	if ( hasRideMotorcycle() )
	{
		m_SlayerInfo.setMotorcycleColor( getMotorcycle()->getBodyColor());
		m_SlayerInfo.setMotorcycleEffectColor( getMotorcycle()->getEffectColor());
		m_SlayerInfo.setMotorItemType(getMotorcycle()->getItemType());
	}

	GuildUnion* pUnion = GuildUnionManager::Instance().getGuildUnion( m_GuildID );
	if ( pUnion == NULL ) m_SlayerInfo.setUnionID( 0 );
	else m_SlayerInfo.setUnionID( pUnion->getUnionID() );

	m_SlayerInfo.setAdvancementLevel(getAdvancementClassLevel());
#ifdef __CONTRIBUTION_SYSTEM__
	m_SlayerInfo.setContributePoint(getContributePoint());
#endif
	
	

	return m_SlayerInfo;

	__END_DEBUG
}

ExtraInfo* Slayer::getExtraInfo() const
	throw()
{
	__BEGIN_DEBUG

	BYTE ItemCount = 0;

	ExtraInfo* pExtraInfo = new ExtraInfo();

	Item* pItem = m_pExtraInventorySlot->getItem();

	if (pItem != NULL) 
	{
		//Item::ItemClass IClass = pItem->getItemClass();

		ExtraSlotInfo* pExtraSlotInfo = new ExtraSlotInfo();
		pItem->makePCItemInfo( *pExtraSlotInfo );

/*
		pExtraSlotInfo->setObjectID(pItem->getObjectID());
		pExtraSlotInfo->setItemClass(pItem->getItemClass());
		pExtraSlotInfo->setItemType(pItem->getItemType());
		pExtraSlotInfo->setOptionType(pItem->getOptionTypeList());
		pExtraSlotInfo->setDurability(pItem->getDurability());
		pExtraSlotInfo->setSilver(pItem->getSilver());
		pExtraSlotInfo->setEnchantLevel(pItem->getEnchantLevel());

		if (IClass == Item::ITEM_CLASS_AR) 
		{
			AR* pAR = dynamic_cast<AR*>(pItem);
			pExtraSlotInfo->setItemNum(pAR->getBulletCount());
		} 
		else if (IClass == Item::ITEM_CLASS_SG) 
		{
			SG* pSG = dynamic_cast<SG*>(pItem);
			pExtraSlotInfo->setItemNum(pSG->getBulletCount());
		} 
		else if (IClass == Item::ITEM_CLASS_SMG) 
		{
			SMG* pSMG = dynamic_cast<SMG*>(pItem);
			pExtraSlotInfo->setItemNum(pSMG->getBulletCount());
		} 
		else if (IClass == Item::ITEM_CLASS_SR) 
		{
			SR* pSR = dynamic_cast<SR*>(pItem);
			pExtraSlotInfo->setItemNum(pSR->getBulletCount());
		} 
		else 
		{
			pExtraSlotInfo->setItemNum(pItem->getNum());
		}

		// 벨트라면 Sub 아이템의 추가 정보가 필요하다.
		if (IClass == Item::ITEM_CLASS_BELT) 
		{
			Belt* pBelt = dynamic_cast<Belt*>(pItem);
			Inventory* pBeltInventory = ((Belt*)pItem)->getInventory();
			BYTE SubItemCount = 0;

			for (int i = 0; i < pBelt->getPocketCount(); i++) 
			{
				Item* pBeltItem = pBeltInventory->getItem(i, 0);

				if (pBeltItem != NULL) 
				{
					SubItemInfo* pSubItemInfo = new SubItemInfo();
					pSubItemInfo->setObjectID(pBeltItem->getObjectID());
					pSubItemInfo->setItemClass(pBeltItem->getItemClass());
					pSubItemInfo->setItemType(pBeltItem->getItemType());
					pSubItemInfo->setItemNum(pBeltItem->getNum());
					pSubItemInfo->setSlotID(i);

					pExtraSlotInfo->addListElement(pSubItemInfo);

					SubItemCount++;
				}
			}

			pExtraSlotInfo->setListNum(SubItemCount);

		}

		// 상의 하의 Main Color 지금은 그냥 0 으로 셋팅 해둔다.
		pExtraSlotInfo->setMainColor(0);
*/	
		pExtraInfo->addListElement(pExtraSlotInfo);

		ItemCount++;
	}

	pExtraInfo->setListNum(ItemCount);

	return pExtraInfo;

	__END_DEBUG

}

//////////////////////////////////////////////////////////////////////////////
// get Inventory Info
//////////////////////////////////////////////////////////////////////////////
InventoryInfo* Slayer::getInventoryInfo() const
    throw()
{
	__BEGIN_DEBUG

	BYTE ItemCount = 0;
	InventoryInfo* pInventoryInfo = new InventoryInfo();
	list<Item*> ItemList;
	VolumeHeight_t Height = m_pInventory->getHeight();
	VolumeWidth_t Width  = m_pInventory->getWidth();

	for (int j = 0; j < Height; j++) 
	{
		for (int i = 0 ; i < Width ; i ++) 
		{
			if (m_pInventory->hasItem(i, j)) 
			{
				Item* pItem = m_pInventory->getItem(i , j);
				VolumeWidth_t ItemWidth = pItem->getVolumeWidth();
//				Item::ItemClass IClass = pItem->getItemClass();

				list<Item*>::iterator itr = find(ItemList.begin() , ItemList.end() , pItem);

				if (itr == ItemList.end()) 
				{
					// Hash_map 에 Item을 등록시켜 놓음,
					// 다음 비교때 같은 아이템인지 확인하기 위하여.
					ItemList.push_back(pItem);

					InventorySlotInfo* pInventorySlotInfo = new InventorySlotInfo();
					pItem->makePCItemInfo( *pInventorySlotInfo );
					pInventorySlotInfo->setInvenX(i);
					pInventorySlotInfo->setInvenY(j);

					pInventoryInfo->addListElement(pInventorySlotInfo);
					ItemCount++;
					i = i + ItemWidth - 1;
				}
			}
		}
	}

	pInventoryInfo->setListNum(ItemCount);

	return pInventoryInfo;

	__END_DEBUG
}

RideMotorcycleInfo* Slayer::getRideMotorcycleInfo() const
	throw()
{
	__BEGIN_DEBUG

	RideMotorcycleInfo* pRideMotorcycleInfo = new RideMotorcycleInfo();

	pRideMotorcycleInfo->setObjectID(m_pMotorcycle->getObjectID());
	pRideMotorcycleInfo->setItemType(m_pMotorcycle->getItemType());
	pRideMotorcycleInfo->setOptionType(m_pMotorcycle->getOptionTypeList());
	pRideMotorcycleInfo->setListNum(0);

    m_SlayerInfo.setMotorcycleColor(388);

	return pRideMotorcycleInfo;

	__END_DEBUG
}

void Slayer::sendSkillInfo()
	throw()
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	try {
		SlayerSkillInfo* pSlayerSkillInfo[SKILL_DOMAIN_VAMPIRE];

		for (int i = 0; i < SKILL_DOMAIN_VAMPIRE; i++) 
		{
			pSlayerSkillInfo[i]=  new SlayerSkillInfo();
			pSlayerSkillInfo[i]->setDomainType((SkillDomainType_t)i);
		}

		BYTE SkillCount[SKILL_DOMAIN_VAMPIRE] = {0,};
		SkillInfo* pSkillInfo = NULL;
		SkillDomainType_t SDomainType = 0;

		// 현재 시간, 남은 캐스팅 타임을 계산하기 위해
		Timeval currentTime;
		getCurrentTime( currentTime );

		hash_map<SkillType_t, SlayerSkillSlot*>::const_iterator itr = m_SkillSlot.begin();
		int SkillDelay;
		
		for (; itr != m_SkillSlot.end(); itr++)
		{
			SlayerSkillSlot* pSkillSlot = itr->second;
			Assert(pSkillSlot != NULL);

			// 기본 공격 스킬이 아니라면...
			if (pSkillSlot->getSkillType() >= SKILL_DOUBLE_IMPACT)
			{
				SkillHandler* pSkillHandler = NULL;
				int SkillDelay = 0;
				
				try
				{
					pSkillHandler = g_pSkillHandlerManager->getSkillHandler(pSkillSlot->getSkillType());
				}
				catch(Error& e)
				{
					pSkillHandler = NULL;
				}
				
				if ( pSkillHandler != NULL )
				{
					SkillDelay = GetSkillCastingTime(pSkillSlot->getSkillType());
					if ( SkillDelay >= 0 )
					{
						SkillDelay = SkillDelay / 100;
					}
					else
					{
						continue;
					}				
				}
				else
				{
					// SkillHandler가 없는 스킬(즉, Passive 스킬) 
					SkillDelay = pSkillSlot->getInterval();
				}
				
				// 스킬 인포를 받아온다.
				// 20071023
				pSkillInfo = g_pSkillInfoManager->getSkillInfo(pSkillSlot->getSkillType());

				// 스킬인포로 부터 현재 기술의 도메인을 받아온다.
				SDomainType = pSkillInfo->getDomainType();

				// 서브 스킬 인포를 구성한다.
				SubSlayerSkillInfo* pSubSlayerSkillInfo = new SubSlayerSkillInfo();
				pSubSlayerSkillInfo->setSkillType(pSkillSlot->getSkillType());
				pSubSlayerSkillInfo->setSkillExp(pSkillSlot->getExp());
				pSubSlayerSkillInfo->setSkillExpLevel(pSkillSlot->getExpLevel());
				pSubSlayerSkillInfo->setSkillTurn(SkillDelay);

//				cout << pSkillInfo->getName() << "스킬 딜레이 " << pSkillSlot->getInterval() << endl;

				// casting time 항목을 다음 캐스팅까지 남은 시간으로 한다.
				//pSubSlayerSkillInfo->setCastingTime(pSkillSlot->getCastingTime());
				pSubSlayerSkillInfo->setCastingTime( pSkillSlot->getRemainTurn( currentTime ) );
				pSubSlayerSkillInfo->setEnable(pSkillSlot->canUse());

				// 슬레이어 스킬인포에 서브 스킬 인포를 추가한다.
				pSlayerSkillInfo[SDomainType]->addListElement(pSubSlayerSkillInfo);
				SkillCount[SDomainType]++;
				pSlayerSkillInfo[SDomainType]->setListNum(SkillCount[SDomainType]);
			}
		}

		pSlayerSkillInfo[SDomainType]->setListNum(SkillCount[SDomainType]);
		GCSkillInfo gcSkillInfo;
		gcSkillInfo.setPCType(PC_SLAYER);

		for (int i = 0; i < SKILL_DOMAIN_VAMPIRE; i++) 
		{
			SkillType_t LearnSkillType = g_pSkillInfoManager->getSkillTypeByLevel(i, m_SkillDomainLevels[i]);

			// 현재 레벨에서 배울 수 있는 기술이 있는지 본다.
			if (LearnSkillType != 0) 
			{
				// 배울 수 있는 기술이 있고 배우지 않은 상태라면 배우라고 알려준다.
				if (hasSkill(LearnSkillType) == NULL) 
				{
					pSlayerSkillInfo[i]->setLearnNewSkill(true);
				}
			}

			if (pSlayerSkillInfo[i]->isLearnNewSkill() || pSlayerSkillInfo[i]->getListNum() > 0) 
			{
				gcSkillInfo.addListElement(pSlayerSkillInfo[i]);
			} 
			else 
			{
				SAFE_DELETE(pSlayerSkillInfo[i]);
			}
		}

		m_pPlayer->sendPacket(&gcSkillInfo);
	} catch (Throwable& t) {
		filelog("slayerBug.log", "%s", t.toString().c_str());
	}


	__END_DEBUG
	__END_CATCH
}


EffectInfo* Slayer::getEffectInfo()
	const throw()
{
	EffectInfo* pEffectInfo = m_pEffectManager->getEffectInfo();
	return pEffectInfo;
}

void Slayer::setGold( Gold_t gold )
	throw()
{
	__BEGIN_TRY

	// MAX_MONEY 를 넘어가는 걸 막는다
	// 2003.1.8  by bezz.
	m_Gold = min( (Gold_t)MAX_MONEY, gold );

	__END_CATCH
}

void Slayer::setGoldEx(Gold_t gold)
	throw()
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	setGold(gold);

	/*
	StringStream sql;
	sql << "Gold = " << (int)m_Gold;

	tinysave(sql.toString());
	*/
	char pField[80];
	sprintf(pField, "Gold = %ld", m_Gold);
	tinysave( pField );

	__END_DEBUG
	__END_CATCH
}

void Slayer::increaseGoldEx(Gold_t gold)
	throw()
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	// MAX_MONEY 를 넘어가는 걸 막는다
	// 2003.1.8  by bezz.
	if ( m_Gold + gold > MAX_MONEY )
		gold = MAX_MONEY - m_Gold;

	setGold(m_Gold+gold);

    Statement* pStmt = NULL;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pStmt->executeQuery("UPDATE Slayer SET Gold=Gold+%u WHERE NAME='%s'", gold, m_Name.c_str());
		SAFE_DELETE(pStmt);
	} 
	END_DB(pStmt)


	__END_DEBUG
	__END_CATCH
}

void Slayer::decreaseGoldEx(Gold_t gold)
	throw()
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	// 0 미만이 되는 걸 막는다. 0 미만이 되면 underflow 되서 난리가 난다.
	// 2003.1.8  by bezz.
	if ( m_Gold < gold )
		gold = m_Gold;

	setGold(m_Gold-gold);

    Statement* pStmt = NULL;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pStmt->executeQuery("UPDATE Slayer SET Gold=Gold-%u WHERE NAME='%s'", gold, m_Name.c_str());
		SAFE_DELETE(pStmt);
	} 
	END_DB(pStmt)

	__END_DEBUG
	__END_CATCH
}

bool Slayer::checkGoldIntegrity()
{
	__BEGIN_TRY

	Statement* pStmt = NULL;
	bool ret = false;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pResult = pStmt->executeQuery("SELECT Gold FROM Slayer WHERE NAME='%s'", m_Name.c_str());

		if ( pResult->next() )
		{
			ret = pResult->getInt(1) == m_Gold;
		}

		SAFE_DELETE(pStmt);
	} 
	END_DB(pStmt)

	return ret;

	__END_CATCH
}

bool Slayer::checkStashGoldIntegrity()
{
	__BEGIN_TRY

	Statement* pStmt = NULL;
	bool ret = false;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pResult = pStmt->executeQuery("SELECT StashGold FROM Slayer WHERE NAME='%s'", m_Name.c_str());

		if ( pResult->next() )
		{
			ret = pResult->getInt(1) == m_StashGold;
		}

		SAFE_DELETE(pStmt);
	} 
	END_DB(pStmt)

	return ret;

	__END_CATCH
}


void Slayer::heartbeat(const Timeval& currentTime)
    throw()
{
	__BEGIN_DEBUG

/*#ifdef __ACTIVE_QUEST__
	// by sigi. 2002.12.3
	if (m_pQuestManager!=NULL)
	{
		m_pQuestManager->heartbeat();
	}
#endif*/

	PlayerCreature::heartbeat( currentTime );

	// Restores MP related to Prayer and Meditation
	// Might be better to have a separate heartbeat function to execute this
	Item* pWeapon = getWearItem(Slayer::WEAR_RIGHTHAND);
	if (pWeapon != NULL)
	{
		Item::ItemClass IClass = pWeapon->getItemClass();

		SlayerSkillSlot* pPrayer     = hasSkill(SKILL_PRAYER);
		SlayerSkillSlot* pMeditation = hasSkill(SKILL_MEDITATION);

		if (IClass == Item::ITEM_CLASS_CROSS && pPrayer != NULL && pPrayer->canUse() && !isFlag( Effect::EFFECT_CLASS_PLEASURE_EXPLOSION))
		{
			Timeval currentTime;
			getCurrentTime(currentTime);

			if (m_MPRegenTime < currentTime)
			{
				MP_t MPMax          = getMP(ATTR_MAX);
				int  MPRegenPercent = 3 + getINT(ATTR_CURRENT)/20;
				MP_t MPQuantity     = max(1, getPercentValue(MPMax, MPRegenPercent));
				MP_t oldMP          = getMP(ATTR_CURRENT);
				MP_t newMP          = min((int)MPMax, (int)(oldMP + MPQuantity));

				if (oldMP != newMP)
				{
					setMP(newMP, ATTR_CURRENT);

					GCModifyInformation gcMI;
					gcMI.addShortData(MODIFY_CURRENT_MP, newMP);
					m_pPlayer->sendPacket(&gcMI);
				}

				// 5초 단위로 하트비트 시킨다. 
				m_MPRegenTime.tv_sec = currentTime.tv_sec + 5;
				m_MPRegenTime.tv_usec = currentTime.tv_usec;
			}
		}
		else if (IClass == Item::ITEM_CLASS_MACE && pMeditation != NULL && pMeditation->canUse() && !isFlag( Effect::EFFECT_CLASS_PLEASURE_EXPLOSION))
		{
			Timeval currentTime;
			getCurrentTime(currentTime);

			if (m_MPRegenTime < currentTime)
			{
				MP_t MPMax          = getMP(ATTR_MAX);
				int  MPRegenPercent = 3 + getINT(ATTR_CURRENT)/20;
				MP_t MPQuantity     = max(1, getPercentValue(MPMax, MPRegenPercent));
				MP_t oldMP          = getMP(ATTR_CURRENT);
				MP_t newMP          = min((int)MPMax, (int)(oldMP + MPQuantity));

				if (oldMP != newMP)
				{
					setMP(newMP, ATTR_CURRENT);

					GCModifyInformation gcMI;
					gcMI.addShortData(MODIFY_CURRENT_MP, newMP);
					m_pPlayer->sendPacket(&gcMI);
				}

				// 5초 단위로 하트비트시킨다.
				m_MPRegenTime.tv_sec = (currentTime.tv_sec + 5);
				m_MPRegenTime.tv_usec = currentTime.tv_usec;
			}
		}
	}

	/*
	list<Item*> ItemList;
	VolumeHeight_t Height = m_pInventory->getHeight();
	VolumeWidth_t Width = m_pInventory->getWidth();

	for (int j = 0; j < Height; j++) 
	{
		for (int i = 0 ; i < Width ; i ++) 
		{
			if (m_pInventory->hasItem(i, j)) 
			{
				Item* pItem = m_pInventory->getItem(i , j);
				VolumeWidth_t ItemWidth = pItem->getVolumeWidth();

				list<Item*>::iterator itr = find(ItemList.begin() , ItemList.end() , pItem);

				if (itr == ItemList.end()) 
				{
					ItemList.push_back(pItem);

					//아이템 크기의 다음 위치 부터 검색하기 위함.
					i = i + ItemWidth - 1;
				}
			}
		}
	}

	for (int i = 0; i < WEAR_MAX; i++) 
	{
		Item* pItem = m_pWearItem[i];

		if (pItem != NULL) 
		{
			if (i == WEAR_RIGHTHAND && isTwohandWeapon(pItem)) continue;
			ItemList.push_back(pItem);
		}
	}

	Item* pSlotItem = m_pExtraInventorySlot->getItem();
	if (pSlotItem != NULL) 
	{
		ItemList.push_back(pSlotItem);
	}

	for (list<Item*>::iterator itr = ItemList.begin(); itr != ItemList.end(); itr++)
	{
		Item* pItem  = (*itr);

		EffectManager* pItemEffectManager = pItem->getEffectManager();
		if (pItemEffectManager != NULL)
		{
			int rvalue = pItemEffectManager->heartbeat();

			// rvalue는 이펙트 매니저 내부에서 삭제된 이펙트의 갯수이다.
			// 이 갯수가 0이 아니라는 말은 삭제된 이펙트가 존재한다는 말이다.
			// 이펙트가 삭제되었으니, 능력치를 새로 계산해 준다.
			// 사실 이 코드는 스트라이킹 때문에 생긴 코드이다.
			// 스트라이킹이 걸리는 주체가 크리쳐가 아니라, 아이템이기 때문에,
			// unaffect될 때 크리쳐의 능력치를 재계산해야 하는데, 할 곳이 마땅하지 않았다.
			// 그래서 궁여지책으로 이 부분에서 능력치를 새로 계산하도록 변경한다.
			// 2002.01.17 - 김성민
			// 이 부분은 스트라이킹 이펙트 자체를 아이템에 붙는 것이 아니라,
			// 크리쳐에 붙는 것으로 변경해 버림으로써 해결해 버렸다.
			// 2002.01.17 -- 김성민
			//if (rvalue != 0)
			//{
			//	SLAYER_RECORD prev;
			//	getSlayerRecord(prev);
			//	initAllStat();
			//	sendRealWearingInfo();
			//	sendModifyInfo(prev);
			//}
		}
	}
	*/

	__END_DEBUG
}

void Slayer::getSlayerRecord(SLAYER_RECORD& record) const
	throw()
{
	__BEGIN_TRY

	record.pSTR[0] = m_STR[0];
	record.pSTR[1] = m_STR[1];
	record.pSTR[2] = m_STR[2];

	record.pDEX[0] = m_DEX[0];
	record.pDEX[1] = m_DEX[1];
	record.pDEX[2] = m_DEX[2];

	record.pINT[0] = m_INT[0];
	record.pINT[1] = m_INT[1];
	record.pINT[2] = m_INT[2];

	record.pHP[0] = m_HP[0];
	record.pHP[1] = m_HP[1];

	record.pMP[0] = m_MP[0];
	record.pMP[1] = m_MP[1];

	record.Rank = getRank();

	record.pDamage[0] = m_Damage[0];
	record.pDamage[1] = m_Damage[1];

	record.Defense     = m_Defense[0];
	record.Protection  = m_Protection[0];
	record.ToHit       = m_ToHit[0];
	record.AttackSpeed = m_AttackSpeed[0];

	record.Bonus = m_AdvancedAttrBonus;

	// 20070918
	record.MagicDefense	= m_MagicDefense;
	record.MagicToHit	= m_MagicToHit;

	// 20070907 슬레이어 망각의 수정땜시
	record.pAdvancedSTR[0] = m_AdvancedSTR[0];
	record.pAdvancedDEX[0] = m_AdvancedDEX[0];
	record.pAdvancedINT[0] = m_AdvancedINT[0];
	record.pAdvancedSTR[1] = m_AdvancedSTR[1];
	record.pAdvancedDEX[1] = m_AdvancedDEX[1];
	record.pAdvancedINT[1] = m_AdvancedINT[1];
	record.pAdvancedSTR[2] = m_AdvancedSTR[2];
	record.pAdvancedDEX[2] = m_AdvancedDEX[2];
	record.pAdvancedINT[2] = m_AdvancedINT[2];
#ifdef __CONTRIBUTION_SYSTEM__
	record.ContributePoint = m_ContributePoint;
#endif
	__END_CATCH
}

void Slayer::setResurrectZoneIDEx(ZoneID_t id)
	throw()
{
	__BEGIN_TRY

	setResurrectZoneID(id);

	/*
	StringStream sql;
	sql << "ResurrectZone = " << (int)id;
	tinysave(sql.toString());
	*/

	// by sigi. 2002.5.15
	char pField[80];
	sprintf(pField, "ResurrectZone=%d", id);
	tinysave(pField);

	__END_CATCH
}

void Slayer::setAlignment(Alignment_t alignment)
	throw()
{
	m_Alignment = alignment;

	if ( isFlag( Effect::EFFECT_CLASS_HOODLUM_STIGMA ) && m_Alignment >= -2500 )
	{
		Effect* pEffect = findEffect( Effect::EFFECT_CLASS_HOODLUM_STIGMA );
		if ( pEffect != NULL )
		{
			pEffect->setDeadline(0);
		}
	}
}

void Slayer::saveAlignment(Alignment_t alignment)
	throw()
{
	__BEGIN_TRY

	setAlignment(alignment);

	/*
	StringStream sql;
	sql << "Alignment = " << (int)alignment;

	tinysave(sql.toString());
	*/
	// by sigi. 2002.5.15
	char pField[80];
	sprintf(pField, "Alignment=%d", alignment);
	tinysave(pField);
				

	__END_CATCH
}

uint Slayer::getSlayerLevel(void) const
	throw()
{
	__BEGIN_TRY

	uint SumAttr = 0, SumDomain = 0;

	SumAttr += m_STR[ATTR_BASIC];
	SumAttr += m_DEX[ATTR_BASIC];
	SumAttr += m_INT[ATTR_BASIC];

	SumDomain += m_SkillDomainLevels[SKILL_DOMAIN_SWORD];
	SumDomain += m_SkillDomainLevels[SKILL_DOMAIN_BLADE];
	SumDomain += m_SkillDomainLevels[SKILL_DOMAIN_GUN];
	SumDomain += m_SkillDomainLevels[SKILL_DOMAIN_HEAL];
	SumDomain += m_SkillDomainLevels[SKILL_DOMAIN_ENCHANT];

	return (uint)(SumAttr/4 + SumDomain/2);

	__END_CATCH
}

string Slayer::toString () const
	throw ()
{
	__BEGIN_DEBUG

	StringStream msg;
	msg << "Slayer("
		//<< "ObjectID:"     << (int)getObjectID()
		<< ",Name:"        << m_Name
		<< ",Sex:"         << Sex2String[m_Sex]
		<< ",HairStyle:"   << HairStyle2String[m_HairStyle]
		<< ",HairColor:"   << (int)m_HairColor
		<< ",SkinColor:"   << (int)m_SkinColor
		<< ",Rank:"        << (int)getRank()
//		<< ",RankExp:"     << (int)m_RankExp
		<< ",RankGoalExp:" << (int)getRankGoalExp()
		<< ",STR:"         << (int)m_STR[ATTR_CURRENT] << "/" << (int)m_STR[ATTR_MAX]
		<< ",DEX:"         << (int)m_DEX[ATTR_CURRENT] << "/" << (int)m_DEX[ATTR_MAX]
		<< ",INT:"         << (int)m_INT[ATTR_CURRENT] << "/" << (int)m_INT[ATTR_MAX]
//		<< ",STRExp:"      << (int)m_STRExp
		<< ",STRGoalExp :" << (int)getSTRGoalExp()
//		<< ",DEXExp:"      << (int)m_DEXExp
//		<< ",INTExp:"      << (int)m_INTExp
		<< ",HP:"          << (int)m_HP[ATTR_CURRENT] << "/" << (int)m_HP[ATTR_MAX]
		<< ",MP:"          << (int)m_MP[ATTR_CURRENT] << "/" << (int)m_MP[ATTR_MAX]
		<< ",Fame:"        << (int)m_Fame
		<< ",Gold:"        << (int)m_Gold
		<< ",GuildID:"     << (int)m_GuildID
		<< ",ZoneID:"      << (int)getZoneID()
		<< ",X:"           << (int)m_X
		<< ",Y:"           << (int)m_Y
		<< ",Sight :"      << (int)m_Sight
		<< ")";
	return msg.toString();

	__END_DEBUG
}

SkillLevel_t Slayer::getSkillDomainLevelSum() const 
	throw() 
{ 
	__BEGIN_TRY

	SkillLevel_t sum = 0;
	sum += m_SkillDomainLevels[SKILL_DOMAIN_BLADE];
	sum += m_SkillDomainLevels[SKILL_DOMAIN_SWORD];
	sum += m_SkillDomainLevels[SKILL_DOMAIN_GUN];
	sum += m_SkillDomainLevels[SKILL_DOMAIN_HEAL];
	sum += m_SkillDomainLevels[SKILL_DOMAIN_ENCHANT];
	return sum;

	__END_CATCH
}


SkillLevel_t Slayer::getHighestSkillDomainLevel() const
	throw()
{
	__BEGIN_TRY

	SkillLevel_t highest;

	highest = max( m_SkillDomainLevels[SKILL_DOMAIN_BLADE], m_SkillDomainLevels[SKILL_DOMAIN_SWORD] );
	highest = max( highest, m_SkillDomainLevels[SKILL_DOMAIN_GUN] );
	highest = max( highest, m_SkillDomainLevels[SKILL_DOMAIN_HEAL] );
	highest = max( highest, m_SkillDomainLevels[SKILL_DOMAIN_ENCHANT] );

	return highest;

	__END_CATCH
}

SkillDomainType_t Slayer::getHighestSkillDomain() const
	throw()
{
	__BEGIN_TRY
	
	SkillDomainType_t highest;	

	if ( m_SkillDomainLevels[SKILL_DOMAIN_BLADE] > m_SkillDomainLevels[SKILL_DOMAIN_SWORD] )
		highest = SKILL_DOMAIN_BLADE;
	else
		highest = SKILL_DOMAIN_SWORD;

	if ( m_SkillDomainLevels[SKILL_DOMAIN_GUN] > m_SkillDomainLevels[highest] )
		highest = SKILL_DOMAIN_GUN;

	if ( m_SkillDomainLevels[SKILL_DOMAIN_HEAL] > m_SkillDomainLevels[highest] )
		highest = SKILL_DOMAIN_HEAL;

	if ( m_SkillDomainLevels[SKILL_DOMAIN_ENCHANT] > m_SkillDomainLevels[highest] )
		highest = SKILL_DOMAIN_ENCHANT;

	return highest;

	__END_CATCH
}
	
void Slayer::saveSkills(void) const 
	throw (Error)
{
	__BEGIN_TRY

	hash_map<SkillType_t, SlayerSkillSlot*>::const_iterator itr = m_SkillSlot.begin();
	for (; itr != m_SkillSlot.end(); itr++)
	{
		SlayerSkillSlot* pSkillSlot = itr->second;
		Assert(pSkillSlot != NULL);

		// 기본 공격 스킬이 아니라면...
		if (pSkillSlot->getDirty() && pSkillSlot->getSkillType() >= SKILL_DOUBLE_IMPACT)
		{
			pSkillSlot->save(m_Name);
		}
	}

	__END_CATCH
}

void Slayer::saveGears(void) const
	throw (Error)
{
	__BEGIN_TRY

	// 장착하고 있는 아이템들을 저장한다.
	char pField[80];

	for(GearSlotID_t GearSlotID = 0; GearSlotID < m_pWearItemSwapPool.size(); ++GearSlotID)
	{
		//for (int i=0; i < Slayer::WEAR_MAX; i++) 
		for (int i=0; i < m_pWearItem.size(); i++) 
		{
			//Item* pItem = m_pWearItem[i];
			Item* pItem = m_pWearItemSwapPool[GearSlotID][i];

			if (pItem != NULL) 
			{
				Durability_t maxDurability = computeMaxDurability(pItem);
				if (pItem->getDurability() < maxDurability)
				{

					// 무기인 경우는 총알 개수를 저장한다. by sigi. 2002.5.13
					if (i==Slayer::WEAR_RIGHTHAND)	// 체크 빨리 할려고 서비스로. - -;
					{
						if (pItem->isGun())
						{
//							Gun* pGun = dynamic_cast<Gun*>(pItem);

							if (pItem!=NULL)
							{
								//pItem->saveBullet();
								sprintf(pField, "Durability=%ld, BulletCount=%d, Silver=%d", pItem->getDurability(), pItem->getBulletCount(), pItem->getSilver());
								pItem->tinysave(pField);
							}
						}
						// 지금 현재 무기는 전부 은도금된다.
						else //if (pItem->isSilverWeapon())
						{
							sprintf(pField, "Durability=%ld, Silver=%d", pItem->getDurability(), pItem->getSilver());
							pItem->tinysave(pField);
						}
					}
					else
					{
						//pItem->save(m_Name, STORAGE_GEAR, 0, i, 0);
						// item저장 최적화. by sigi. 2002.5.13
						sprintf(pField, "Durability=%ld", pItem->getDurability());
						pItem->tinysave(pField);
					}
				}
			}
		}
	}

	__END_CATCH
}

void Slayer::saveExps(void) const 
	throw (Error)
{
	__BEGIN_TRY

	// 스킬 핸들러에서 쿼리 숫자를 줄이기 위해서 10으로 나누는 부분들은,
	// 서버 다운이 되지 않고, 정상적으로 로그아웃하는 경우에 
	// 세이브를 명시적으로 해주지 않으면 10 이하 올라간 부분은 날아가 버리게 된다.
	// 그러므로 여기서 세이브를 해 준다. 

	ostringstream os;
	
	os << "UPDATE Slayer SET "
		<< "STRGoalExp=" << getSTRGoalExp()
		<< ",DEXGoalExp=" << getDEXGoalExp()
		<< ",INTGoalExp=" << getINTGoalExp()
		
		<< ",BladeGoalExp=" << m_GoalExp[SKILL_DOMAIN_BLADE]
		<< ",SwordGoalExp=" << m_GoalExp[SKILL_DOMAIN_SWORD]
		<< ",GunGoalExp=" << m_GoalExp[SKILL_DOMAIN_GUN]
		<< ",EnchantGoalExp=" << m_GoalExp[SKILL_DOMAIN_ENCHANT]
		<< ",HealGoalExp=" << m_GoalExp[SKILL_DOMAIN_HEAL]
		<< ",ETCGoalExp=" << m_GoalExp[SKILL_DOMAIN_ETC]
		                               
		<< ",Alignment=" << (int)m_Alignment
		<< ",Fame=" << m_Fame
		<< ",`Rank`=" << (int)getRank()
		<< ",RankGoalExp=" << getRankGoalExp()
		<< ",AdvancementClass=" << (int)getAdvancementClassLevel()
		<< ",AdvancementGoalExp=" << getAdvancementClassGoalExp()
		<< ",AdvancedSTR=" << m_AdvancedSTR[ATTR_BASIC]
		<< ",AdvancedDEX=" << m_AdvancedDEX[ATTR_BASIC]
		<< ",AdvancedINT=" << m_AdvancedINT[ATTR_BASIC]
		<< ",Bonus=" << m_AdvancedAttrBonus
		<< " WHERE Name='" << m_Name.c_str() << "'";
	
	g_GameDBExecuteManager.RequestExecQuery(getObjectID(), os.str());
	
	__END_CATCH
}

//----------------------------------------------------------------------
// getShapeInfo
//----------------------------------------------------------------------
// 현재 slayer의 복장을 참고로해서 복장flag/color 정보를 만든다.
// login할때 처리를 빨리하기 위해서다.
//----------------------------------------------------------------------
// 일단 32bit로 32가지를 표현하는걸로도 충분하다고 본다.
// 언젠가? over되면 bitset을 써야겠지..
//
// (!) 색깔은 index색값이 아니고 optionType을 넣어서 사용한다.
//     클라이언트에서 옵션으로 색값을 찾아서 쓴다.
//----------------------------------------------------------------------
void Slayer::getShapeInfo (DWORD& flag, Color_t colors[PCSlayerInfo::SLAYER_COLOR_MAX])
//	throw ()
{
	__BEGIN_DEBUG

	Item* 						pItem;
	//OptionInfo* 				pOptionInfo;
	PCSlayerInfo::SlayerBits 	slayerBit;
	PCSlayerInfo::SlayerColors 	slayerColor;

	WearPart Part;

	// 초기화
	flag = 0;

	//-----------------------------------------------------------------
	// 성별
	//-----------------------------------------------------------------
	slayerBit	= PCSlayerInfo::SLAYER_BIT_SEX;
	flag |= ((m_Sex? 1:0) << slayerBit);

	//-----------------------------------------------------------------
	// HairStyle
	//-----------------------------------------------------------------
	slayerBit 	= PCSlayerInfo::SLAYER_BIT_HAIRSTYLE1;
	flag |= (m_HairStyle << slayerBit);

	//-----------------------------------------------------------------
	// 바지
	//-----------------------------------------------------------------
	Part = WEAR_LEG;
	//pItem = m_pWearItem[Part];
	pItem = getWearItem(Part);
	slayerBit	= PCSlayerInfo::SLAYER_BIT_PANTS1;
	slayerColor = PCSlayerInfo::SLAYER_COLOR_PANTS;
	if (pItem!=NULL && m_pRealWearingCheck[Part])
	{
		ItemType_t IType = pItem->getItemType();

		/*
		if (pItem->getOptionType() != 0)
		{
			pOptionInfo = g_pOptionInfoManager->getOptionInfo(pItem->getOptionType());
			colors[slayerColor] = (pOptionInfo==NULL? 377 : pOptionInfo->getColor());
		}
		*/

//		colors[slayerColor] = (pItem->isUnique()? UNIQUE_OPTION : pItem->getFirstOptionType());
		if ( pItem->isTimeLimitItem() ) colors[slayerColor] = QUEST_OPTION;
		else if ( pItem->isUnique() ) colors[slayerColor] = UNIQUE_OPTION;
		else colors[slayerColor] = pItem->getFirstOptionType();

		flag |= (getPantsType(IType) << slayerBit);
	} 
	else 
	{
		colors[slayerColor] = 0;
		flag |= (PANTS_BASIC << slayerBit);
	}
	//-----------------------------------------------------------------
	// 쟈켓
	//-----------------------------------------------------------------
	Part = WEAR_BODY;
	//pItem = m_pWearItem[Part];
	pItem = getWearItem(Part);
	slayerBit	= PCSlayerInfo::SLAYER_BIT_JACKET1;
	slayerColor = PCSlayerInfo::SLAYER_COLOR_JACKET;
	if (pItem!=NULL && m_pRealWearingCheck[Part])
	{
		ItemType_t IType = pItem->getItemType();

		/*
		if (pItem->getOptionType() != 0)
		{
			pOptionInfo = g_pOptionInfoManager->getOptionInfo(pItem->getOptionType());
			colors[slayerColor] = (pOptionInfo==NULL? 377 : pOptionInfo->getColor());
		}
		*/

//		colors[slayerColor] = (pItem->isUnique()? UNIQUE_OPTION : pItem->getFirstOptionType());

		if ( pItem->isTimeLimitItem() ) colors[slayerColor] = QUEST_OPTION;
		else if ( pItem->isUnique() ) colors[slayerColor] = UNIQUE_OPTION;
		else colors[slayerColor] = pItem->getFirstOptionType();

		flag |= (getJacketType(IType) << slayerBit);
	} 
	else 
	{
		colors[slayerColor] = 0;
		flag |= (JACKET_BASIC << slayerBit);
	}

	//-----------------------------------------------------------------
	// 투구
	//-----------------------------------------------------------------
	Part = WEAR_HEAD;
	//pItem = m_pWearItem[Part];
	pItem = getWearItem(Part);
	slayerBit	= PCSlayerInfo::SLAYER_BIT_HELMET1;
	slayerColor = PCSlayerInfo::SLAYER_COLOR_HELMET;
	if (pItem!=NULL && m_pRealWearingCheck[Part])
	{
		ItemType_t IType = pItem->getItemType();

		/*
		if (pItem->getOptionType() != 0)
		{
			pOptionInfo = g_pOptionInfoManager->getOptionInfo(pItem->getOptionType());
			colors[slayerColor] = (pOptionInfo==NULL? 377 : pOptionInfo->getColor());
		}
		*/

//		colors[slayerColor] = (pItem->isUnique()? UNIQUE_OPTION : pItem->getFirstOptionType());

		if ( pItem->isTimeLimitItem() ) colors[slayerColor] = QUEST_OPTION;
		else if ( pItem->isUnique() ) colors[slayerColor] = UNIQUE_OPTION;
		else colors[slayerColor] = pItem->getFirstOptionType();

		flag |= (getHelmetType(IType) << slayerBit);

	} 
	else 
	{
		colors[slayerColor] = 0;
		// 없다
	}

	//-----------------------------------------------------------------
	// 방패
	//-----------------------------------------------------------------
	Part = WEAR_LEFTHAND;
	//pItem = m_pWearItem[Part];
	pItem = getWearItem(Part);
	slayerBit	= PCSlayerInfo::SLAYER_BIT_SHIELD1;
	slayerColor = PCSlayerInfo::SLAYER_COLOR_SHIELD;
	if (pItem!=NULL 
		&& m_pRealWearingCheck[Part]
		&& pItem->getItemClass()==Item::ITEM_CLASS_SHIELD)
	{
		ItemType_t IType = pItem->getItemType();

		/*
		if (pItem->getOptionType() != 0)
		{
			pOptionInfo = g_pOptionInfoManager->getOptionInfo(pItem->getOptionType());
			colors[slayerColor] = (pOptionInfo==NULL? 377 : pOptionInfo->getColor());
		}
		*/

//		colors[slayerColor] = (pItem->isUnique()? UNIQUE_OPTION : pItem->getFirstOptionType());

//		if ( pItem->isUnique() ) colors[slayerColor] = UNIQUE_OPTION;
		if ( pItem->isTimeLimitItem() ) colors[slayerColor] = QUEST_OPTION;
		else if ( pItem->isUnique() ) colors[slayerColor] = UNIQUE_OPTION;
		else colors[slayerColor] = pItem->getFirstOptionType();

		flag |= (getShieldType(IType) << slayerBit);
	} 
	else 
	{
		colors[slayerColor] = 0;
		// 없다
	}

	//-----------------------------------------------------------------
	// 무기
	//-----------------------------------------------------------------
	Part = WEAR_RIGHTHAND;
	//pItem = m_pWearItem[Part];
	pItem = getWearItem(Part);
	slayerBit	= PCSlayerInfo::SLAYER_BIT_WEAPON1;
	slayerColor = PCSlayerInfo::SLAYER_COLOR_WEAPON;

	if (pItem!=NULL && m_pRealWearingCheck[Part])
	{
		DWORD weaponType = 0;

		if (pItem->getItemClass()==Item::ITEM_CLASS_SWORD) 		weaponType = WEAPON_SWORD;
		else if (pItem->getItemClass()==Item::ITEM_CLASS_BLADE) weaponType = WEAPON_BLADE;
		else if (pItem->getItemClass()==Item::ITEM_CLASS_SR)	weaponType = WEAPON_SR;
		else if (pItem->getItemClass()==Item::ITEM_CLASS_AR)	weaponType = WEAPON_AR;
		else if (pItem->getItemClass()==Item::ITEM_CLASS_SG)	weaponType = WEAPON_SG;
		else if (pItem->getItemClass()==Item::ITEM_CLASS_SMG)	weaponType = WEAPON_SMG;
		else if (pItem->getItemClass()==Item::ITEM_CLASS_CROSS)	weaponType = WEAPON_CROSS;
		else if (pItem->getItemClass()==Item::ITEM_CLASS_MACE)	weaponType = WEAPON_MACE;//MACE;

		/*
		if (pItem->getOptionType() != 0)
		{
			pOptionInfo = g_pOptionInfoManager->getOptionInfo(pItem->getOptionType());
			colors[slayerColor] = (pOptionInfo==NULL? 377 : pOptionInfo->getColor());
		}
		*/

		//colors[slayerColor] = (pItem->isUnique()? UNIQUE_OPTION : pItem->getFirstOptionType());

		if ( pItem->isUnique() ) colors[slayerColor] = UNIQUE_OPTION;
		else if ( pItem->isTimeLimitItem() ) colors[slayerColor] = QUEST_OPTION;
		else colors[slayerColor] = pItem->getFirstOptionType();

		flag |= (weaponType << slayerBit);
		flag |= (getWeaponArtTier(pItem) << PCSlayerInfo::SLAYER_BIT_WEAPON_TIER1);
	}
	else
	{
		colors[slayerColor] = 0;
	}

	__END_DEBUG
}


//----------------------------------------------------------------------
// set InitialRank
//----------------------------------------------------------------------
// Rank, RankExp, RankGoalExp의 초기값을 저장한다.
//----------------------------------------------------------------------
void Slayer::setInitialRank(void)
{
	int maxDomainLevel = getHighestSkillDomainLevel();

	int curRank = max(1, (maxDomainLevel+3) / 4);
	m_pRank->SET_LEVEL( curRank );
}

Slayer::WearPart 
Slayer::getWearPart(Item::ItemClass IClass) const
{
	switch (IClass)
	{
		case Item::ITEM_CLASS_COAT 		: return WEAR_BODY;
		case Item::ITEM_CLASS_TROUSER 	: return WEAR_LEG;

		case Item::ITEM_CLASS_SWORD 	: 
		case Item::ITEM_CLASS_BLADE 	: 
		case Item::ITEM_CLASS_AR 		: 
		case Item::ITEM_CLASS_SR 		: 
		case Item::ITEM_CLASS_SG 		: 
		case Item::ITEM_CLASS_SMG 		: 
		case Item::ITEM_CLASS_MACE 		: 
		case Item::ITEM_CLASS_CROSS 	: 
			return WEAR_RIGHTHAND;

		case Item::ITEM_CLASS_HELM 		: return WEAR_HEAD;

		case Item::ITEM_CLASS_SHIELD 	: return WEAR_LEFTHAND;

		case Item::ITEM_CLASS_SHOULDER_ARMOR : return WEAR_SHOULDER;

		default :
			  return WEAR_MAX;
	}

	return WEAR_MAX;
}

bool
Slayer::changeShape(Item* pItem, Color_t color, bool bSendPacket)
{
	Item::ItemClass IClass = pItem->getItemClass();
	ItemType_t 		IType  = pItem->getItemType();

	WearPart Part = getWearPart(IClass);

	if (Part==WEAR_MAX)
		return false;

	bool bRealWear = m_pRealWearingCheck[Part];

	if (bRealWear)
		return addShape(IClass, IType, color);

	return removeShape(IClass, bSendPacket);
}

bool
Slayer::addShape(Item::ItemClass IClass, ItemType_t IType, Color_t color)
{
	bool bisWeapon = false;
	bool bisChange = false;

	switch (IClass)
	{
		case Item::ITEM_CLASS_MACE:
			bisWeapon = true;
			bisChange = true;
			//m_SlayerInfo.setWeaponType(WEAPON_MACE);

			m_SlayerInfo.setWeaponType(WEAPON_MACE);
			m_SlayerInfo.setWeaponColor( color );
			break;
		case Item::ITEM_CLASS_CROSS:
			bisWeapon = true;
			bisChange = true;

			m_SlayerInfo.setWeaponType(WEAPON_CROSS);
			m_SlayerInfo.setWeaponColor( color );
			break;
		case Item::ITEM_CLASS_BLADE:
			bisWeapon = true;
			bisChange = true;

			m_SlayerInfo.setWeaponType(WEAPON_BLADE);
			m_SlayerInfo.setWeaponColor( color );
			break;
		case Item::ITEM_CLASS_AR:
			bisWeapon = true;
			bisChange = true;

			m_SlayerInfo.setWeaponType(WEAPON_AR);
			m_SlayerInfo.setWeaponColor( color );
			break;
		case Item::ITEM_CLASS_SR:
			bisWeapon = true;
			bisChange = true;

			m_SlayerInfo.setWeaponType(WEAPON_SR);
			m_SlayerInfo.setWeaponColor( color );
			break;
		case Item::ITEM_CLASS_SMG:
			bisWeapon = true;
			bisChange = true;

			m_SlayerInfo.setWeaponType(WEAPON_SMG);
			m_SlayerInfo.setWeaponColor( color );
			break;
		case Item::ITEM_CLASS_SG:
			bisWeapon = true;
			bisChange = true;

			m_SlayerInfo.setWeaponType(WEAPON_SG);
			m_SlayerInfo.setWeaponColor( color );
			break;
		case Item::ITEM_CLASS_HELM:
			bisChange = true;

			m_SlayerInfo.setHelmetType(getHelmetType(IType));
			m_SlayerInfo.setHelmetColor( color );
			break;
		case Item::ITEM_CLASS_SHIELD:
			bisChange = true;

			m_SlayerInfo.setShieldType(getShieldType(IType));
			m_SlayerInfo.setShieldColor( color );
			break;
		case Item::ITEM_CLASS_SWORD:
			bisWeapon = true;
			bisChange = true;

			m_SlayerInfo.setWeaponType(WEAPON_SWORD);
			m_SlayerInfo.setWeaponColor( color );
			break;
		case Item::ITEM_CLASS_COAT:
			bisChange = true;

			m_SlayerInfo.setJacketType(getJacketType(IType));
			m_SlayerInfo.setJacketColor( color );
			break;
		case Item::ITEM_CLASS_TROUSER:
			bisChange = true;

			m_SlayerInfo.setPantsType(getPantsType(IType));
			m_SlayerInfo.setPantsColor( color );
			break;

		case Item::ITEM_CLASS_SHOULDER_ARMOR:
			bisChange = true;

			m_SlayerInfo.setShoulderType(getShoulderType(IType));
			m_SlayerInfo.setShoulderColor( color );
			break;

		default:
			break;
	}

	if (bisWeapon)
		m_SlayerInfo.setWeaponTier(getWeaponArtTier(IClass, IType));

	return bisChange;
}

bool
Slayer::removeShape(Item::ItemClass IClass, bool bSendPacket)
{
	bool bisWeapon = false;

	// 죽을때 아이템 떨어뜨릴때는 자신에게도 패킷을 보내야하기 때문에..
	// parameter로 받는게 좋을텐데 header 안바꿀려고.. -_-;
	// by sigi. 2002.11.7
	Creature* pOwner = (isDead()? NULL : this);

	switch (IClass)
	{
		case Item::ITEM_CLASS_MACE:
		case Item::ITEM_CLASS_CROSS:
		case Item::ITEM_CLASS_BLADE:
		case Item::ITEM_CLASS_AR:
		case Item::ITEM_CLASS_SR:
		case Item::ITEM_CLASS_SMG:
		case Item::ITEM_CLASS_SG:
		{
			bisWeapon = true;
			m_SlayerInfo.setWeaponType(WEAPON_NONE);
			m_SlayerInfo.setWeaponTier(0);

			if (bSendPacket)	// by sigi. 2002.11.6
			{
				GCTakeOff _GCTakeOff;
				_GCTakeOff.setObjectID(getObjectID());
				_GCTakeOff.setSlotID((SlotID_t)ADDON_RIGHTHAND);
				m_pZone->broadcastPacket(getX(), getY(), &_GCTakeOff, pOwner);
			}
		}
		break;
			
		case Item::ITEM_CLASS_HELM:
		{
			m_SlayerInfo.setHelmetType(HELMET_NONE);

			if (bSendPacket)	// by sigi. 2002.11.6
			{
				GCTakeOff _GCTakeOff;
				_GCTakeOff.setObjectID(getObjectID());
				_GCTakeOff.setSlotID((SlotID_t)ADDON_HELM);
				m_pZone->broadcastPacket(getX(), getY(), &_GCTakeOff, pOwner);
			}
		}
		break;

		case Item::ITEM_CLASS_SHIELD:
		{
			m_SlayerInfo.setShieldType(SHIELD_NONE);

			if (bSendPacket)	// by sigi. 2002.11.6
			{
				GCTakeOff _GCTakeOff;
				_GCTakeOff.setObjectID(getObjectID());
				_GCTakeOff.setSlotID((SlotID_t)ADDON_LEFTHAND);
				m_pZone->broadcastPacket(getX(), getY(), &_GCTakeOff, pOwner);
			}
		}
		break;

		case Item::ITEM_CLASS_SWORD:
		{
			bisWeapon = true;
			m_SlayerInfo.setWeaponType(WEAPON_NONE);
			m_SlayerInfo.setWeaponTier(0);

			if (bSendPacket)	// by sigi. 2002.11.6
			{
				GCTakeOff _GCTakeOff;
				_GCTakeOff.setObjectID(getObjectID());
				_GCTakeOff.setSlotID((SlotID_t)ADDON_RIGHTHAND);
				m_pZone->broadcastPacket(getX(), getY(), &_GCTakeOff, pOwner);
			}
		}
		break;

		case Item::ITEM_CLASS_COAT:
		{
			m_SlayerInfo.setJacketType(JACKET_BASIC);

			if (bSendPacket)	// by sigi. 2002.11.6
			{
				GCTakeOff _GCTakeOff;
				_GCTakeOff.setObjectID(getObjectID());
				_GCTakeOff.setSlotID((SlotID_t)ADDON_COAT);
				m_pZone->broadcastPacket(getX(), getY(), &_GCTakeOff, pOwner);
			}
		}
		break;

		case Item::ITEM_CLASS_TROUSER:
		{
			m_SlayerInfo.setPantsType(PANTS_BASIC);

			if (bSendPacket)	// by sigi. 2002.11.6
			{
				GCTakeOff _GCTakeOff;
				_GCTakeOff.setObjectID(getObjectID());
				_GCTakeOff.setSlotID((SlotID_t)ADDON_TROUSER);
				m_pZone->broadcastPacket(getX(), getY(), &_GCTakeOff, pOwner);
			}
		}
		break;

		case Item::ITEM_CLASS_SHOULDER_ARMOR:
		{
			m_SlayerInfo.setShoulderType(0);

			if (bSendPacket)	// by sigi. 2002.11.6
			{
				GCTakeOff _GCTakeOff;
				_GCTakeOff.setObjectID(getObjectID());
				_GCTakeOff.setSlotID((SlotID_t)ADDON_TROUSER);
				m_pZone->broadcastPacket(getX(), getY(), &_GCTakeOff, pOwner);
			}
		}
		break;

		default:
			break;
	}

	return bisWeapon;
}

Color_t 
Slayer::getItemShapeColor(Item* pItem, OptionInfo* pOptionInfo) const
{
	Color_t color;

	if ( pItem->isTimeLimitItem() )
	{
		// 퀘스트 아이템도 특정한 색깔로 대체해서 처리한다.
		color = QUEST_COLOR;
	}
	else if (pItem->isUnique())
	{
		// 유니크는 특정한 색깔로 대체해서 처리한다.
		color = UNIQUE_COLOR;
	}
	// 외부에서 이미 OptionInfo를 찾은 경우
	else if (pOptionInfo != NULL) 
	{
		color = pOptionInfo->getColor();
	}
	// 아니면.. 첫번째 옵션의 색깔을 지정한다.
	else if (pItem->getFirstOptionType() != 0)
	{
		OptionInfo* pOptionInfo = g_pOptionInfoManager->getOptionInfo(pItem->getFirstOptionType());
		color = pOptionInfo->getColor();
	}
	else 
	{
		// default 색
		color = 377;
	}

	return color;
}
 

bool Slayer::canPlayFree()
	throw(Error)
{
	__BEGIN_TRY

	return getSkillDomainLevelSum() <= g_pVariableManager->getVariable(FREE_PLAY_SLAYER_DOMAIN_SUM);

	__END_CATCH
}

bool Slayer::isPayPlayAvaiable() 
	throw(Error)
{
	__BEGIN_TRY

	if (m_pPlayer==NULL)
		return false;

	GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(m_pPlayer);

#ifdef __CONNECT_BILLING_SYSTEM__
	if (pGamePlayer->isPayPlaying())
	{
		// 완전 무료 사용자. ㅋㅋ
		if (pGamePlayer->getPayType()==PAY_TYPE_FREE)
			return true;

		int DomainSUM = getSkillDomainLevelSum();

		// 제한된 도메인합까지 play가능
		if (DomainSUM <= g_pVariableManager->getVariable(FREE_PLAY_SLAYER_DOMAIN_SUM))
		{
			return true;
		}
	}

	return false;

// 애드빌 빌링을 사용하지 않고 사용자 제한을 하는 경우
#elif defined(__PAY_SYSTEM_FREE_LIMIT__)

	if (!pGamePlayer->isPayPlaying())
	{
		int DomainSUM = getSkillDomainLevelSum();

		// 제한된 도메인합까지 play가능
		if (DomainSUM <= g_pVariableManager->getVariable(FREE_PLAY_SLAYER_DOMAIN_SUM))
		{
			return true;
		}

		return false;
	}

	return true;

#else

	return pGamePlayer->isPayPlaying();

#endif


	__END_CATCH
}

QuestGrade_t Slayer::getQuestGrade() const throw() { return getTotalAttr( ATTR_BASIC ) - getSkillDomainLevel(SKILL_DOMAIN_HEAL)*1.5 - getSkillDomainLevel(SKILL_DOMAIN_ENCHANT)*1.5; }

// 순수 능력치 합이 40 미만이면 초보(Novice) 이다.
bool Slayer::isNovice() const
{
	return ( m_STR[ATTR_BASIC] + m_DEX[ATTR_BASIC] + m_INT[ATTR_BASIC] ) <= 40;
}

// live attribute sum: m_STR/DEX/INT[ATTR_BASIC] are only refreshed by initAllStat
static int liveAttrSum( Attr* const* pAttrs )
{
	return pAttrs[ATTR_KIND_STR]->getLevel() + pAttrs[ATTR_KIND_DEX]->getLevel() + pAttrs[ATTR_KIND_INT]->getLevel();
}

void Slayer::divideAttrExp(AttrKind kind, Damage_t damage, ModifyInfo& modifyInfo)
{
	SLAYER_RECORD prev;
	getSlayerRecord(prev);

	// Damage_t is a 16-bit WORD: with the EXP ratio applied it wrapped past 65535. Work in Exp_t.
	Exp_t expPoint = damage;

	expPoint = getPercentValue(expPoint, AttrExpTimebandFactor[getZoneTimeband(m_pZone)]);

	if(g_pVariableManager->getExpRatio()>100 && g_pVariableManager->getEventActivate() == 1)
		expPoint = getPercentValue(expPoint, g_pVariableManager->getExpRatio());

	// 시간대에 따라 경험치 두배
	if ( isAffectExp2X() )
		expPoint <<= 1;

	if ( isFlag( Effect::EFFECT_CLASS_BONUS_EXP ) ) 
	{
		EffectBonusExp *pEffect = dynamic_cast<EffectBonusExp *>(findEffect(Effect::EFFECT_CLASS_BONUS_EXP));
																
		if ( pEffect != NULL )
		{
			expPoint = (Exp_t)((float)expPoint * pEffect->GetBonusRate());
		}
	}
	
	if ( isFlag( Effect::EFFECT_CLASS_BONUS_EXP_SECOND ) ) 
	{
		EffectBonusExpSecond *pEffect = dynamic_cast<EffectBonusExpSecond *>(findEffect(Effect::EFFECT_CLASS_BONUS_EXP_SECOND));
			
		if ( pEffect != NULL )
		{
			expPoint = (Exp_t)((float)expPoint * pEffect->GetBonusRate());
		}
	}
	
	if ( isFlag( Effect::EFFECT_CLASS_BONUS_EXP_ADVANCE ) ) 
	{
		EffectBonusExpAdvance *pEffect = dynamic_cast<EffectBonusExpAdvance *>(findEffect(Effect::EFFECT_CLASS_BONUS_EXP_ADVANCE));
			
		if ( pEffect != NULL )
		{
			expPoint = (Exp_t)((float)expPoint * pEffect->GetBonusRate());
		}
	}
	
	if ( isFlag( Effect::EFFECT_CLASS_CHAOTIC_STONE_EXP ) ) 
	{
		EffectChaoticExp *pEffect = dynamic_cast<EffectChaoticExp *>(findEffect(Effect::EFFECT_CLASS_CHAOTIC_STONE_EXP));
			
		if ( pEffect != NULL )
		{
			expPoint = (Exp_t)((float)expPoint * pEffect->GetBonusRate());
		}
	}
	
	

#ifdef __CONTRIBUTION_SYSTEM__
	if( g_pLevelWarZoneInfoManager->isCreatureBonusZone(dynamic_cast<Creature*>(this), getZoneID() ) )
		expPoint = expPoint + (expPoint * 0.5 * getZone()->expLevelWarBonusTimeCheck(getRace()));
#endif

	// 20080502 도메인 경험치 보너스 추가
	if(getEnemyTarget())
	{
		Creature* pTargetCreature = getZone()->getCreature( getEnemyTarget() );
		if( pTargetCreature != NULL && pTargetCreature->isMonster() )
		{
			Monster* pMonster = dynamic_cast<Monster*>(pTargetCreature);
			if(pMonster->getEnhanceHP() < 100)
				expPoint = (int)((float)expPoint * (1.0 + (float)pMonster->getMonsterAddExp()/100.0 * 0.5));
			else
				expPoint = (int)((float)expPoint * (1.0 + (float)pMonster->getMonsterAddExp()/(float)pMonster->getEnhanceHP() * 0.5));
		}
	}

	Exp_t MainPoint = max( (Exp_t)1, expPoint * 8 / 10 );
	Exp_t SubPoint = max( (Exp_t)1, expPoint / 10 );

#ifdef __CHINA_SERVER__

	// 중국쪽은 레벨별로 능력치 경험치 얻는 것이 다르다
	float userExpConst = 1.0;

	SkillLevel_t HighSkillLevel = getHighestSkillDomainLevel();

	if ( HighSkillLevel < 50 )
		userExpConst = 1.0;
	else if ( HighSkillLevel > 49 && HighSkillLevel < 75 )
		userExpConst = 0.8;
	else if ( HighSkillLevel > 74 && HighSkillLevel < 100 )
		userExpConst = 0.6;
	else if ( HighSkillLevel > 99 )
		userExpConst = 0.4;

	MainPoint = (Exp_t)(MainPoint*userExpConst);
	SubPoint = (Exp_t)(SubPoint*userExpConst);

#endif

	// 슬레이어 능력치는 도메인 레벨 100이전에는 총합 300으로 제한 된다.(기존처럼 50, 200, 50 으로..)또한 그 이후의 경험치는 누적되지 않는다.
	// 그리고 도메인 레벨 이 100을 넘어서면 다시 능력치 경험치가 누적되어 능력치가 올라가기 시작한다.
	// 도메인 레벨이 100 아래로 도로 떨어졌어도 능력치 총합이 300을 넘었을 경우 300의 제한을 받지 않는다.

	SkillLevel_t	MaxDomainLevel	= getHighestSkillDomainLevel();
	Attr_t			TotalAttr		= getTotalAttr( ATTR_BASIC );
    Attr_t          TotalAttrBound      = 0;        // 능력치 총합 제한
    Attr_t          AttrBound           = 0;        // 단일 능력치 제한
    Attr_t          OneAttrExpBound     = 0;        // 한 개의 능력치에만 경험치 주는 능력치 총합 경계값
	Attr_t			SubAttrMax			= 0;		// 보조 능력치 최대값

	if ( MaxDomainLevel <= SLAYER_BOUND_LEVEL && TotalAttr <= SLAYER_BOUND_ATTR_SUM )
	{
		TotalAttrBound  = SLAYER_BOUND_ATTR_SUM;        // 300
		AttrBound       = SLAYER_BOUND_ATTR;            // 200
		OneAttrExpBound = SLAYER_BOUND_ONE_EXP_ATTR;    // 200
		SubAttrMax		= SLAYER_BOUND_SUB_ATTR;		// 50
	}
	else
	{
		TotalAttrBound  = SLAYER_MAX_ATTR_SUM;          // 435
		AttrBound       = SLAYER_MAX_ATTR;              // 295
		OneAttrExpBound = SLAYER_ONE_EXP_ATTR;          // 400
		SubAttrMax		= SLAYER_MAX_SUB_ATTR;			// 70
	}

	Attr* pMainAttr = m_pAttrs[kind];
	Attr* pSubAttrs[2];
	int count = 0;

	bool levelUpSubAttrs[2] = { false, false };

	for ( int itr = ATTR_KIND_STR ; itr != ATTR_KIND_MAX ; ++itr )
	{
		if ( m_pAttrs[itr] != pMainAttr ) pSubAttrs[count++] = m_pAttrs[itr];
	}

	if ( pSubAttrs[0]->getLevel() < pSubAttrs[1]->getLevel() )
	{
		Attr* pTemp;
		SWAP(pSubAttrs[0], pSubAttrs[1], pTemp);
	}

	// EXP carries over (chain level-ups), but every single level re-checks the caps the original
	// one-level-per-grant code enforced, against the live levels (m_STR/DEX/INT[ATTR_BASIC] only refresh
	// in initAllStat):
	//  - the main attribute stops at AttrBound;
	//  - at the sum bound a main level costs one level of the higher sub attribute (none to shed = no level);
	//  - a sub attribute only earns EXP while the sum is under OneAttrExpBound or it is under SubAttrMax,
	//    and never levels past AttrBound or the sum bound.
	bool levelUpMainAttr = false;
	{
		Exp_t rest  = MainPoint;
		int   guard = 0;
		while ( rest > 0 && ++guard < 1000 )
		{
			Exp_t goal = pMainAttr->getGoalExp();
			if ( pMainAttr->getLevel() >= AttrBound || rest < goal )
			{
				pMainAttr->increaseExp( rest, false );
				break;
			}

			if ( liveAttrSum( m_pAttrs ) >= TotalAttrBound )
			{
				Attr* pShed = ( pSubAttrs[0]->getLevel() >= pSubAttrs[1]->getLevel() ) ? pSubAttrs[0] : pSubAttrs[1];
				if ( !pShed->levelDown() )
				{
					pMainAttr->increaseExp( rest, false );
					break;
				}
				levelUpSubAttrs[0] = true;	// stats changed: recompute + heal below
			}

			if ( !pMainAttr->increaseExp( goal, true ) ) break;   // table max level
			levelUpMainAttr = true;
			rest -= goal;
		}
	}

	for ( int s = 0; s < 2; ++s )
	{
		Attr* pSub  = pSubAttrs[s];
		Exp_t rest  = SubPoint;
		int   guard = 0;
		while ( rest > 0 && ++guard < 1000 )
		{
			int sum = liveAttrSum( m_pAttrs );
			if ( sum >= OneAttrExpBound && pSub->getLevel() >= SubAttrMax ) break;

			Exp_t goal = pSub->getGoalExp();
			if ( rest < goal || sum >= TotalAttrBound || pSub->getLevel() >= AttrBound )
			{
				pSub->increaseExp( rest, false );
				break;
			}

			if ( !pSub->increaseExp( goal, true ) ) break;
			levelUpSubAttrs[s] = true;
			rest -= goal;
		}
	}

	if ( ++m_AttrExpSaveCount > ATTR_EXP_SAVE_PERIOD )
	{
		char pField[256];
		sprintf(pField, "STRGoalExp=%ld, DEXGoalExp=%ld, INTGoalExp=%ld",
							getSTRGoalExp(), getDEXGoalExp(), getINTGoalExp());

		tinysave( pField );

		m_AttrExpSaveCount = 0;
	}

	if ( levelUpMainAttr || levelUpSubAttrs[0] || levelUpSubAttrs[1] )
	{
		healCreatureForLevelUp(this, modifyInfo, &prev);
		sendEffectLevelUp( this );
		if ( g_pVariableManager->isNewbieTransportToGuild() ) checkNewbieTransportToGuild(this);

		char pField[256];
		sprintf(pField, "STR=%d, DEX=%d, INTE=%d, STRGoalExp=%ld, DEXGoalExp=%ld, INTGoalExp=%ld",
//							getSTR(ATTR_BASIC), getDEX(ATTR_BASIC), getINT(ATTR_BASIC), getSTRGoalExp(), getDEXGoalExp(), getINTGoalExp();
							m_pAttrs[ATTR_KIND_STR]->getLevel(),
							m_pAttrs[ATTR_KIND_DEX]->getLevel(),
							m_pAttrs[ATTR_KIND_INT]->getLevel(),
							getSTRGoalExp(), getDEXGoalExp(), getINTGoalExp());

		tinysave( pField );
	}

	modifyInfo.addLongData(MODIFY_STR_EXP, getSTRGoalExp());
	modifyInfo.addLongData(MODIFY_DEX_EXP, getDEXGoalExp());
	modifyInfo.addLongData(MODIFY_INT_EXP, getINTGoalExp());
}

void Slayer::setLastTarget( ObjectID_t value )
{
	if ( getPet() != NULL && value != getLastTarget() )
	{
		GCOtherModifyInfo gcOMI;
		gcOMI.setObjectID( getObjectID() );
		gcOMI.addLongData( MODIFY_LAST_TARGET, value );

		m_pZone->broadcastPacket( getX(), getY(), &gcOMI, this );

		GCModifyInformation gcMI;
		gcMI.addLongData( MODIFY_LAST_TARGET, value );

		getPlayer()->sendPacket( &gcMI );
	}

	Creature::setLastTarget( value );
}

void Slayer::initPetQuestTarget()
{
	QuestGrade_t grade = getQuestGrade();

	int minClass = 1, maxClass = 1;

	if ( grade <= 60 )
	{
		minClass = maxClass = 2;
	}
	else if ( grade <= 95 )
	{
		minClass = maxClass = 3;
	}
	else if ( grade <= 130 )
	{
		minClass = 4; maxClass = 5;
	}
	else if ( grade <= 170 )
	{
		minClass = maxClass = 6;
	}
	else if ( grade <= 210 )
	{
		minClass = maxClass = 7;
	}
	else if ( grade <= 240 )
	{
		minClass = 7; maxClass = 8;
	}
	else if ( grade <= 270 )
	{
		minClass = 8; maxClass = 9;
	}
	else if ( grade <= 290 )
	{
		minClass = 9; maxClass = 10;
	}
	else if ( grade <= 300 )
	{
		minClass = maxClass = 10;
	}
	else if ( grade <= 320 )
	{
		minClass = 10; maxClass = 11;
	}
	else if ( grade <= 360 )
	{
		minClass = 10; maxClass = 11;
	}
	else
	{
		minClass = 11; maxClass = 12;
	}

	m_TargetMonster = g_pMonsterInfoManager->getRandomMonsterByClass( minClass, maxClass );
	m_TargetNum = 80;
	m_TimeLimit = 3600;
}

bool Slayer::recallMotorcycle(Key *pKey, bool bRide, bool bRedeem)
{
	if ( pKey == NULL )
	{
		return false;
	}
	
	Zone *pZone  = getZone();
	GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(getPlayer());
	int iRecallRangeLimit = 15;
	
	ItemID_t targetID = pKey->getTarget();
	
	filelog("motorcycle.txt", 
		"[RecallMotorcycle] Ready, Owner=%s, KeyID=%lu, Key's targetID=%lu", 
		this->getName().c_str(), 
		pKey->getItemID(), 
		targetID
	);
	
	if (targetID == 0)
	{
		targetID = pKey->setNewMotorcycle(this);
	}
	else
	{
		Statement* pStmt   = NULL;
		Result*    pResult = NULL;
		
		// 한번 모터사이클이랑 키랑 연결됐는데 모터사이클을 누가 자꾸 지우나보다.
		// 키에 연결된 모터사이클이 실제로 디비에 있는지 체크하고 없으면 새로 만들어서 넣어준다.
		BEGIN_DB
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			pResult = pStmt->executeQuery("SELECT ItemID FROM MotorcycleObject WHERE ItemID=%lu", targetID);

			if ( !pResult->next() )
			{
				targetID = pKey->setNewMotorcycle(this);
			}

			SAFE_DELETE(pStmt);
		}
		END_DB(pStmt);
	}
	  // 필살 방어 코드 -_-;
	if (targetID == 0)
	{
		filelog("errorLog.txt", "[ActionRedeemMotorcycle] itemID=%lu, motorItemID=%lu", 
			(int)pKey->getItemID(), (int)targetID
		);
		
		return false;
	}
	
	if (g_pParkingCenter->hasMotorcycleBox(targetID))
	{
		MotorcycleBox* pMotorcycleBox = g_pParkingCenter->getMotorcycleBox(targetID);

		if ( pMotorcycleBox->getZone() == NULL )
		{
			// 로그인이후 처음으로 모터사이클 소환하는 경우
			pMotorcycleBox->setZone(pZone);
			pMotorcycleBox->setX(this->getX());
			pMotorcycleBox->setY(this->getY());

			Motorcycle* pMotorcycle = pMotorcycleBox->getMotorcycle();
			
			TPOINT pt = pZone->addItem(pMotorcycle, this->getX(), this->getY(), false);
			
			if ( pt.x != -1 && bRide )
			{
				CGRideMotorCycle cgRide;
				
				cgRide.setObjectID( pMotorcycle->getObjectID() );
				cgRide.setX(pt.x);
				cgRide.setY(pt.y);
				cgRide.execute(pGamePlayer);
			}
			
			filelog("motorcycle.txt", 
				"[RecallMotorcycle] FirstRecall, Owner=%s, OwnerX=%d, OwnerY=%d, KeyID=%lu, Key's targetID=%lu, Ride=%s, MotorcycleID=%lu, X=%d, Y=%d", 
				this->getName().c_str(), 
				this->getX(),
				this->getY(),
				pKey->getItemID(), 
				targetID,
				bRide ? "true" : "false",
				pMotorcycle->getItemID(),
				pt.x,
				pt.y
			);
			
			return true;
		}
		else if ( !bRedeem && !DynamicZoneManager::isDynamicZone(pMotorcycleBox->getZoneID()) )
		{
			// 일반 맵에서 모터사이클 소환하는 경우
			if ( pMotorcycleBox != NULL && !pMotorcycleBox->isTransport())
			{
				Zone* pMotorZone = pMotorcycleBox->getZone();
				ZoneCoord_t motorX = pMotorcycleBox->getX();
				ZoneCoord_t motorY = pMotorcycleBox->getY();
				
				Motorcycle* pMotorcycle = pMotorcycleBox->getMotorcycle();

				// 같은 존에 있는 경우
				// 거리가 너무 가까우면 부르지 말자~
				if ( pMotorZone != pZone || this->getDistance(motorX, motorY) > iRecallRangeLimit )
				{
					pMotorcycleBox->setTransport();
					
					if ( bRide )
					{
						EffectRecallMotorcycle* pEffectRecallMotorcycle;
														
						pEffectRecallMotorcycle = new EffectRecallMotorcycle(
							pMotorZone, 
							motorX, motorY, 
							pZone, 
							this->getX(), this->getY(), 
							pMotorcycle, 
							this->getObjectID(), 
							0
						);
						
						pMotorZone->registerObject( pEffectRecallMotorcycle );
						pMotorZone->addEffect_LOCKING( pEffectRecallMotorcycle );
					}
					else
					{
						pMotorZone->transportItem( 
							motorX, motorY, 
							pMotorcycle, 
							pZone, 
							this->getX(), this->getY() 
						);
					}
				}
				
				filelog("motorcycle.txt", 
					"[RecallMotorcycle] Transport, Owner=%s, OwnerX=%d, OwnerY=%d, KeyID=%lu, Key's targetID=%lu, Ride=%s, Distance=%d, MotorcycleID=%lu, OriginZoneID=%d, OringinX=%d, OringinY=%d", 
					this->getName().c_str(), 
					this->getX(),
					this->getY(),
					pKey->getItemID(), 
					targetID,
					bRide ? "true" : "false",
					this->getDistance(motorX, motorY),
					pMotorcycle->getItemID(),
					pMotorZone->getZoneID(),
					motorX,
					motorY
				);
			}
			
			return true;
		}
		else if ( !bRedeem )
		{
			// 인던에서 모터사이클 소환하는 경우
			
			Zone* pMotorZone = pMotorcycleBox->getZone();
			ZoneCoord_t motorX = pMotorcycleBox->getX();
			ZoneCoord_t motorY = pMotorcycleBox->getY();
			
			// 인던의 경우 pMotorZone 이 유효하지 않을 수 있으므로 직접적으로 사용시 주의를 기울려야 한다.
			
			if ( pMotorZone != pZone || this->getDistance(motorX, motorY) > iRecallRangeLimit )
			{
				// 바이크가 DynamicZone에 있었던 경우 무조건 지우고, 새로 소환한다.
				g_pParkingCenter->deleteMotorcycleBox(targetID);

				targetID = pKey->setNewMotorcycle(this);
				
				pMotorcycleBox = g_pParkingCenter->getMotorcycleBox(targetID);
				
				if ( pMotorcycleBox != NULL )
				{
					pMotorcycleBox->setZone(pZone);
					pMotorcycleBox->setX(this->getX());
					pMotorcycleBox->setY(this->getY());

					Motorcycle* pMotorcycle = pMotorcycleBox->getMotorcycle();
					
					TPOINT pt = pZone->addItem(pMotorcycle, this->getX(), this->getY(), false);
					
					if ( pt.x != -1 && bRide )
					{
						CGRideMotorCycle cgRide;
						
						cgRide.setObjectID( pMotorcycle->getObjectID() );
						cgRide.setX(pt.x);
						cgRide.setY(pt.y);
						cgRide.execute(pGamePlayer);
					}
					
					filelog("motorcycle.txt", 
						"[RecallMotorcycle] RecallInIntanceDoungeon, Owner=%s, OwnerX=%d, OwnerY=%d, KeyID=%lu, Key's targetID=%lu, Ride=%s, MotorcycleID=%lu, X=%d, Y=%d", 
						this->getName().c_str(), 
						this->getX(),
						this->getY(),
						pKey->getItemID(), 
						targetID,
						bRide ? "true" : "false",
						pMotorcycle->getItemID(),
						pt.x,
						pt.y
					);
				}
			}
		}
		
		return true;
	}	
	
	return false;
	
}

ADDON Slayer::GetAddonType(Item::ItemClass IClass)
{
	switch (IClass)
	{
		case Item::ITEM_CLASS_MACE:
		case Item::ITEM_CLASS_CROSS:
		case Item::ITEM_CLASS_BLADE:
		case Item::ITEM_CLASS_AR:
		case Item::ITEM_CLASS_SR:
		case Item::ITEM_CLASS_SMG:
		case Item::ITEM_CLASS_SG:
			return ADDON_RIGHTHAND;
			
		case Item::ITEM_CLASS_HELM:
			return ADDON_HELM;
			
		case Item::ITEM_CLASS_SHIELD:
			return ADDON_LEFTHAND;
			
		case Item::ITEM_CLASS_SWORD:
			return ADDON_RIGHTHAND;
			
		case Item::ITEM_CLASS_COAT:
			return ADDON_COAT;
			
		case Item::ITEM_CLASS_TROUSER:
			return ADDON_TROUSER;
			
		case Item::ITEM_CLASS_SHOULDER_ARMOR:
			return ADDON_SHOULDER;
			
		default:
			break;
	}
	
	return ADDON_MAX;
}

void Slayer::ChangeShapeInfoWhenWear(Item *pItem)
{
	if ( pItem == NULL )
	{
		return;
	}
	
	OptionInfo *pOptionInfo = NULL;
	
	if (pItem->getFirstOptionType() != 0)
	{
		pOptionInfo = g_pOptionInfoManager->getOptionInfo(pItem->getFirstOptionType());
	}
	
	// 어떤 무기를 잡고 있다는 정보를 저장한다. 
	// SlayerInfo에 셋팅을 해 놓아야 다음 누군가가 볼때 날려준다.
	ItemType_t IType = pItem->getItemType();
	Color_t color = getItemShapeColor( pItem, pOptionInfo ); 

	switch (pItem->getItemClass())
	{
		case Item::ITEM_CLASS_MACE:
			m_SlayerInfo.setWeaponType(WEAPON_MACE);
			m_SlayerInfo.setWeaponColor( color );
			break;
		case Item::ITEM_CLASS_CROSS:
			m_SlayerInfo.setWeaponType(WEAPON_CROSS);
			m_SlayerInfo.setWeaponColor( color );
			break;
		case Item::ITEM_CLASS_BLADE:
			m_SlayerInfo.setWeaponType(WEAPON_BLADE);
			m_SlayerInfo.setWeaponColor( color );
			break;
		case Item::ITEM_CLASS_AR:
			m_SlayerInfo.setWeaponType(WEAPON_AR);
			m_SlayerInfo.setWeaponColor( color );
			break;
		case Item::ITEM_CLASS_SR:
			m_SlayerInfo.setWeaponType(WEAPON_SR);
			m_SlayerInfo.setWeaponColor( color );
			break;
		case Item::ITEM_CLASS_SMG:
			m_SlayerInfo.setWeaponType(WEAPON_SMG);
			m_SlayerInfo.setWeaponColor( color );
			break;
		case Item::ITEM_CLASS_SG:
			m_SlayerInfo.setWeaponType(WEAPON_SG);
			m_SlayerInfo.setWeaponColor( color );
			break;
		case Item::ITEM_CLASS_HELM:
			m_SlayerInfo.setHelmetType(getHelmetType(IType));
			m_SlayerInfo.setHelmetColor( color );
			break;
		case Item::ITEM_CLASS_SHIELD:
			m_SlayerInfo.setShieldType(getShieldType(IType));
			m_SlayerInfo.setShieldColor( color );
			break;
		case Item::ITEM_CLASS_SWORD:
			m_SlayerInfo.setWeaponType(WEAPON_SWORD);
			m_SlayerInfo.setWeaponColor( color );
			break;
		case Item::ITEM_CLASS_COAT:
			m_SlayerInfo.setJacketType(getJacketType(IType));
			m_SlayerInfo.setJacketColor( color );
			break;
		case Item::ITEM_CLASS_TROUSER:
			m_SlayerInfo.setPantsType(getPantsType(IType));
			m_SlayerInfo.setPantsColor( color );
			break;
		case Item::ITEM_CLASS_SHOULDER_ARMOR:
			m_SlayerInfo.setShoulderType(getShoulderType(IType));
			m_SlayerInfo.setShoulderColor( color );
			break;
		default:
			break;
	}
}

bool Slayer::ChangeShapeInfoWhenTakeOff(Item *pItem)
{
	switch (pItem->getItemClass())
	{
		case Item::ITEM_CLASS_MACE:
		case Item::ITEM_CLASS_CROSS:
		case Item::ITEM_CLASS_BLADE:
		case Item::ITEM_CLASS_AR:
		case Item::ITEM_CLASS_SR:
		case Item::ITEM_CLASS_SMG:
		case Item::ITEM_CLASS_SG:
			m_SlayerInfo.setWeaponType(WEAPON_NONE);
			break;
			
		case Item::ITEM_CLASS_HELM:
			m_SlayerInfo.setHelmetType(HELMET_NONE);
			break;
			
		case Item::ITEM_CLASS_SHIELD:
			m_SlayerInfo.setShieldType(SHIELD_NONE);
			break;
			
		case Item::ITEM_CLASS_SWORD:
			m_SlayerInfo.setWeaponType(WEAPON_NONE);
			break;
			
		case Item::ITEM_CLASS_COAT:
			m_SlayerInfo.setJacketType(JACKET_BASIC);
			break;
			
		case Item::ITEM_CLASS_TROUSER:
			m_SlayerInfo.setPantsType(PANTS_BASIC);
			break;
			
		case Item::ITEM_CLASS_SHOULDER_ARMOR:
			m_SlayerInfo.setShoulderType(0);
			break;
			
		default:
			return false;
	}
	
	return true;
}

void Slayer::OnChangeItemInGearSlot(Item *pWearItem, Item *pTakeOffItem)
{
	if ( pTakeOffItem != NULL && ChangeShapeInfoWhenTakeOff(pTakeOffItem) )
	{
		GCTakeOff pkt;
		
		pkt.setObjectID(getObjectID());
		pkt.setSlotID((SlotID_t)GetAddonType(pTakeOffItem->getItemClass()));
		
		m_pZone->broadcastPacket(getX(), getY(), &pkt, this);
	}
	
	ChangeShapeInfoWhenWear(pWearItem);
}

void Slayer::OnDead()
{
	// 모터사이클을 타고 있다면, 모터사이클에서 내린다.
	if (hasRideMotorcycle())
	{
		Zone* pZone = getZone();
		Assert(pZone!=NULL);

		getOffMotorcycle();
		
		GCGetOffMotorCycle _GCGetOffMotorCycle;
		_GCGetOffMotorCycle.setObjectID(getObjectID());
		
		pZone->broadcastPacket(getX(), getY(), &_GCGetOffMotorCycle);
	}

	// 현재 헬기를 부른 상태라면 헬기를 끈다.
	if (isFlag(Effect::EFFECT_CLASS_SLAYER_PORTAL))
	{
		removeFlag(Effect::EFFECT_CLASS_SLAYER_PORTAL);

		// 헬기를 제거하라고 뿌려줘야 하는데...?
		//GCAddHelicopter gcAddHelicopter;
		//gcAddHelicopter.setObjectID(pSlayer->getObjectID());
		//gcAddHelicopter.setCode(1);
		//pZone->broadcastPacket(pSlayer->getX(), pSlayer->getY(), &gcAddHelicopter);
	}
							
	PlayerCreature::OnDead();
	
}

bool Slayer::ComputeSkillOutput(SkillType_t SkillType, SkillOutput& output)
{
	SlayerSkillSlot* pSlayerSkillSlot = NULL;
				
	pSlayerSkillSlot = getSkill(SkillType);
	if ( pSlayerSkillSlot == NULL )
	{
		return false;
	}
	
	SkillHandler* pSkillHandler = NULL;
	
	try
	{
		pSkillHandler = g_pSkillHandlerManager->getSkillHandler(SkillType);
	}
	catch(Error& e)
	{
		pSkillHandler = NULL;
	}
	
	if ( pSkillHandler != NULL && pSlayerSkillSlot != NULL )
	{
		SkillInput input(this, pSlayerSkillSlot);
		
		output.Init();
		pSkillHandler->computeOutput(input, output);
		
		return true;
	}
	
	return false;

}

bool Slayer::GetSkillInterval(SkillType_t SkillType, int& iSkillInterval)
{
	SlayerSkillSlot* pSlayerSkillSlot = NULL;
				
	pSlayerSkillSlot = getSkill(SkillType);
	if ( pSlayerSkillSlot == NULL )
	{
		return false;
	}
	
	iSkillInterval = pSlayerSkillSlot->getInterval();
	
	return true;
}

void Slayer::ComputeAllSkillDelay()
{
	hash_map<SkillType_t, SlayerSkillSlot*>::const_iterator itr = m_SkillSlot.begin();
	SkillType_t SkillType;
	
	SkillOutput output;
	
	SlayerSkillSlot* pSlayerSkillSlot = NULL;
	
	for (; itr != m_SkillSlot.end(); itr++)
	{
		pSlayerSkillSlot = itr->second;
		if ( pSlayerSkillSlot == NULL )
		{
			continue;
		}
		
		SkillType = pSlayerSkillSlot->getSkillType();
		if (pSlayerSkillSlot->getSkillType() >= SKILL_DOUBLE_IMPACT)
		{
			ComputeSkillOutput(SkillType, output);
				
			pSlayerSkillSlot->setInterval (output.Delay);
			pSlayerSkillSlot->setRunTime();
		}
		
	}
}
