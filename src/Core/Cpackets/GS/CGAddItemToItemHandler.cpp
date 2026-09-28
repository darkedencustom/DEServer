//////////////////////////////////////////////////////////////////////////////
// Filename    : CGAddItemToItemHandler.cc
// Written By  : elca@ewestsoft.com
// Description :
//////////////////////////////////////////////////////////////////////////////

// 한 아이템을 들어서 다른 아이템에 넣는다.
/* [Client]                                               [Server]
           -- CGAddItemToItem
              (mouseItem_ObjectID, invenX, invenY)
			  =(마우스에 들고있는 별, upgrade할 item XY) -->

            <-- GCAddItemToItemVerify(결과코드, 관련값) ---
*/   
//-------------+---------------------------------------------
// 사용 packet | client 처리
//-------------+---------------------------------------------
// 불가 packet | 불가 message 출력
// 실패 packet | 실패 message 출력, 별 삭제, [아이템 제거]
// 성공 packet | 별 삭제, option변경
//-------------+---------------------------------------------



#include "CGAddItemToItem.h"

#ifdef __GAME_SERVER__
	#include <stdio.h>
	#include "GamePlayer.h"
	#include "PlayerCreature.h"
	#include "Inventory.h"
	#include "Item.h"
	#include "ItemInfoManager.h"
	#include "ItemFactoryManager.h"
	#include "OptionInfo.h"
	#include "ItemUtil.h"
	#include "EventStar.h"
	#include "PetItem.h"
	#include "PetEnchantItem.h"
	#include "PetInfo.h"
	#include "PetAttrInfo.h"
	#include "PetTypeInfo.h"
	#include "CreatureUtil.h"
	#include "MixingItem.h"
	#include "SlayerTunningItem.h" //20080604
	#include "VampireTunningItem.h" //20080604
	#include "OustersTunningItem.h" //20080604
	#include "Slayer.h"
	#include "Vampire.h"
	#include "Ousters.h"

	#include "PacketUtil.h"
	#include "DB.h"
	#include "Zone.h"
	#include "EventGiftBoxRewardManager.h"
	#include "EventGiftBox.h"

	#include "Gpackets/GCAddItemToItemVerify.h"
	#include "Gpackets/GCDeleteInventoryItem.h"
	#include "Gpackets/GCCreateItem.h"
	#include "Gpackets/GCPetInfo.h"

	#include "SystemAvailabilitiesManager.h"
		#include "VariableManager.h"	//by kim

	// Dice range for the Blue Bird / Blue Drop rolls. A 0 from AttrInfo made
	// `rand() % range` divide by zero and crash the gameserver.
	static int enchantDiceRange(VariableType vt)
	{
		int range = g_pVariableManager->getVariable(vt);
		return (range > 0) ? range : 10000;
	}
		
#ifdef VERSION_THIRD_ENCHANT_1
	#include "ItemClassInfo.h"
	#include "ThirdEnchantInfo.h"
	void executeThirdEnchantOption(GamePlayer* pGamePlayer, Item* pMouseItem, Item* pItem, OptionType_t addOptionType) throw(Error);
	void sendThirdEnchantOK(GamePlayer* pGamePlayer, list<OptionType_t>& changeOption, BYTE enchantClass)  throw (Error);
	void sendThirdEnchantFail(GamePlayer* pGamePlayer, BYTE grade) throw (Error);
	void saveThirdOptionType(Item* pItem) throw (Error);
#endif

	void executeUpGrade(GamePlayer* pGamePlayer, Item* pMouseItem, Item* pItem) throw(Error);
	void executeUpGradeInferiorYellowDrop(GamePlayer* pGamePlayer, Item* pMouseItem, Item* pItem, CoordInven_t invenX, CoordInven_t invenY) throw(Error);
	void yellowDropLog(PlayerCreature* pPC, Item* pItem, int ratio, int success) throw(Error);
	void UseYellowDropLog(GamePlayer* pGamePlayer, Item* pItem, int prevGrade, const string& optionString, int ratio, int success) throw(Error);
	void executeEnchantOption(GamePlayer* pGamePlayer, Item* pMouseItem, Item* pItem, CoordInven_t invenX, CoordInven_t invenY) throw(Error);
	void executeEnchantRareOption(GamePlayer* pGamePlayer, Item* pMouseItem, Item* pItem, CoordInven_t invenX, CoordInven_t invenY) throw(Error);
	void executeAddOption(GamePlayer* pGamePlayer, Item* pMouseItem, Item* pItem, OptionType_t addOptionType) throw(Error);
	void executeTransKit(GamePlayer* pGamePlayer, Item* pMouseItem, Item* pItem) throw(Error);
	// 20070725 코랄추가
	void executeAddRandomOption(GamePlayer* pGamePlayer, Item* pMouseItem, Item* pItem, OptionType_t addOptionType) throw(Error);
	// 20080218 by Kim Sung Yong
	void executeCrystalAddRandomOption(GamePlayer* pGamePlayer, Item* pMouseItem, Item* pItem) throw(Error);
	void executeOneOpCrystalAddRandomOption(GamePlayer* pGamePlayer, Item* pMouseItem, Item* pItem) throw(Error);

	// 2021-08-27 블루크리스탈 by kim
	void executeCrystalAdd2RandomOption(GamePlayer* pGamePlayer, Item* pMouseItem, Item* pItem) throw(Error);
	void executeTwoOpCrystalAdd2RandomOption2(GamePlayer* pGamePlayer, Item* pMouseItem, Item* pItem) throw(Error);

	//20080604
	void executeTunningItem(GamePlayer* pGamePlayer, Item* pMouseItem, Item* pItem) throw(Error);

	extern bool isPossibleOptionItemClass(Item::ItemClass IClass);

	OptionInfo* getOptionInfo(OptionType_t optionType);

	void    	processUpgradeOptionType(Item* pItem, OptionType_t currentOptionType, OptionInfo* pOptionInfo) throw (Error);
	void		crashItem(Item* pItem, Inventory* pInventory, CoordInven_t invenX, CoordInven_t invenY) throw (Error);
	void    	downgradeOptionType(Item* pItem, OptionType_t currentOptionType, OptionInfo* pOptionInfo) throw (Error);

	void		sendEnchantImpossible(GamePlayer* pGamePlayer) throw (Error);
	void		sendEnchantOK(GamePlayer* pGamePlayer, DWORD optionChange) throw (Error);
	
	bool 		isSuccessCoralEnchant(Item* pMouseItem, int AddRatioValue);
	bool 		isSuccessCrystalEnchant(Item* pMouseItem);
	bool 		isSuccessThirdEnchant(Item* pMouseItem, int AddRatioValue);
	
	int			rangeRandom(int iMinNum, int iMaxNum);

#endif	// __GAME_SERVER__

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void CGAddItemToItemHandler::execute (CGAddItemToItem* pPacket , Player* pPlayer)
	 throw (Error)
{
	__BEGIN_TRY __BEGIN_DEBUG_EX
		
#ifdef __GAME_SERVER__

	Assert(pPacket != NULL);
	Assert(pPlayer != NULL);

//	cout << pPacket->toString().c_str() << endl;

	GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(pPlayer);

	Assert(pGamePlayer != NULL);	// by sigi

	if (pGamePlayer->getPlayerStatus() == GPS_NORMAL) 
	{
		SYSTEM_ASSERT( SYSTEM_ENCHANT );

		Creature*  		pCreature   = pGamePlayer->getCreature();
		PlayerCreature* pPC         = dynamic_cast<PlayerCreature*>(pCreature);
		ObjectID_t      objectID    = pPacket->getObjectID();
		Inventory* 		pInventory  = pPC->getInventory();
		CoordInven_t 	invenX      = pPacket->getX();
		CoordInven_t 	invenY      = pPacket->getY();

		// 인벤토리에 아이템이 없을때(좌표체크도 하게 된다.)
		if (!pInventory->hasItem(invenX, invenY))
		{
			GCAddItemToItemVerify gcAddItemToItemVerify;
			gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
			pGamePlayer->sendPacket( &gcAddItemToItemVerify );
			return;
		}

		// 마우스 아이템
		Item*           pMouseItem  = pPC->getExtraInventorySlotItem();

		// 인벤토리에 있는 아이템
		Item*      		pItem       = pInventory->getItem(invenX, invenY);

		// 아이템이 없거나
		// objectID가 잘못된 경우
		if (pMouseItem==NULL
			|| pItem==NULL
			|| pMouseItem->getObjectID()!=objectID
			|| pMouseItem->getNum() != 1 )
		{
			//cout << "Wrong Item" << endl;

			GCAddItemToItemVerify gcAddItemToItemVerify;
			gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
			pGamePlayer->sendPacket( &gcAddItemToItemVerify );
			return;
		}
		
		if ( pItem->getItemClass() == Item::ITEM_CLASS_CORE_ZAP && pItem->getItemType() == 4
			||  pItem->getItemClass() == Item::ITEM_CLASS_CORE_ZAP && pItem->getItemType() == 5)
		{
			GCAddItemToItemVerify gcAddItemToItemVerify;
			gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
			pGamePlayer->sendPacket( &gcAddItemToItemVerify );
			return;
		}

		switch (pMouseItem->getItemClass())
		{
			//---------------------------------------------------------
			//
			// 				ITEM_CLASS_EVENT_STAR
			//
			//---------------------------------------------------------
			// 아이템의 옵션을 upgrade 시킨다.
			//---------------------------------------------------------
			case Item::ITEM_CLASS_EVENT_STAR : 
			{
				ItemInfo* pItemInfo = g_pEventStarInfoManager->getItemInfo( pMouseItem->getItemType() );
				Assert(pItemInfo!=NULL);

				EventStarInfo* pEventStarInfo = dynamic_cast<EventStarInfo*>(pItemInfo);
				Assert(pEventStarInfo!=NULL);
				
				if (pEventStarInfo->getFunctionFlag() == EventStarInfo::FUNCTION_NULL)
				{
					cout << "바르는 녀석이 아니다!" << endl;
					GCAddItemToItemVerify gcAddItemToItemVerify;
					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_IMPOSSIBLE );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );
					return;
				}

				// 20071003 International Version 착용이 가능한 아이템만 인챈트가 가능하다.
/*				if( pPC->isSlayer() )
				{
					Slayer* pSlayer = dynamic_cast<Slayer*>(pPC);
					Assert( pSlayer != NULL );

					if( !pSlayer->isRealWearing( pItem ) )
					{
						GCAddItemToItemVerify gcAddItemToItemVerify;
						gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_NEED_LEVEL_FAIL );
						pGamePlayer->sendPacket( &gcAddItemToItemVerify );
						return;
					}
				}
				else if( pPC->isVampire() )
				{
					Vampire* pVampire = dynamic_cast<Vampire*>(pPC);
					Assert( pVampire != NULL );

					if( !pVampire->isRealWearing( pItem ) )
					{
						GCAddItemToItemVerify gcAddItemToItemVerify;
						gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_NEED_LEVEL_FAIL );
						pGamePlayer->sendPacket( &gcAddItemToItemVerify );
						return;
					}
				}
				else if( pPC->isOusters() )
				{
					Ousters* pOusters = dynamic_cast<Ousters*>(pPC);
					Assert( pOusters != NULL );

					if( !pOusters->isRealWearing( pItem ) )
					{
						GCAddItemToItemVerify gcAddItemToItemVerify;
						gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_NEED_LEVEL_FAIL );
						pGamePlayer->sendPacket( &gcAddItemToItemVerify );
						return;
					}
				}*/

				int optionSize = pItem->getOptionTypeSize();
//				cout << "Third 옵션 추가 pEventStarInfo->getFunctionFlag() : " << (int)pEventStarInfo->getFunctionFlag() << endl;
//				cout << "Third 옵션 추가 pEventStarInfo->isFunctionThirdEnchantOption() : " << (int)pEventStarInfo->isFunctionThirdEnchantOption() << endl;

				if ( (pEventStarInfo->getFunctionFlag() & EventStarInfo::FUNCTION_UP_GRADE) != 0 )
				{
					if (
						pMouseItem->getNum() == 1 &&
						pItemInfo->getReqAdvancedLevel() == 0 &&
						!pItem->isUnique() &&
						pItem->getItemClass() != Item::ITEM_CLASS_CORE_ZAP &&
						pItem->getItemClass() != Item::ITEM_CLASS_ETHEREAL_CHAIN &&
						pItem->getItemClass() != Item::ITEM_CLASS_CUE_OF_ADAM
					)
					{
						if( pMouseItem->getItemType() == 22 && 
							pItem->getOptionTypeSize() < 2 && 
							pItem->getGrade() < 6 
						)
						{
							executeUpGrade(pGamePlayer, pMouseItem, pItem);
							return;
						}
						if( pMouseItem->getItemType() == 48 && 
							pItem->getOptionTypeSize() < 2 && 
							pItem->getGrade() < 8
						)
						{
							executeUpGrade(pGamePlayer, pMouseItem, pItem);
							return;
						}
						if( pMouseItem->getItemType() == 57 && 
							pItem->getOptionTypeSize() < 3 && 
							pItem->getGrade() < 10
						)
						{
							executeUpGrade(pGamePlayer, pMouseItem, pItem);
							return;
						}
						if( pMouseItem->getItemType() == 69 && 
							pItem->getOptionTypeSize() < 3 && 
							pItem->getGrade() < 10
						)
						{
							cout << " executeUpGradeInferiorYellowDrop invenX : " << invenX << endl;
							cout << " executeUpGradeInferiorYellowDrop invenY : " << invenY << endl;
							executeUpGradeInferiorYellowDrop(pGamePlayer, pMouseItem, pItem, invenX, invenY);
							return;
						}
						if( pMouseItem->getItemType() == 80 &&
							pItem->getOptionTypeSize() < 3 &&
							pItem->getGrade() < 10
						)
						{
							executeUpGrade(pGamePlayer, pMouseItem, pItem);
							return;
						}
					}
					GCAddItemToItemVerify gcAddItemToItemVerify;
					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );
					return;	
				}
				else if (pEventStarInfo->isFunctionTransKit())
				{
					executeTransKit(pGamePlayer, pMouseItem, pItem);
				}
								// 20070725 코랄 추가
				else if (pEventStarInfo->isFunctionAddRandomOption())
				{
					int addOptionType = pEventStarInfo->getFunctionValue();
			 	    // 20080218 by Kim Sung Yong
					if(pEventStarInfo->getItemType() == 58  || pEventStarInfo->getItemType() == 68)
					{
						if(pItem->getOptionTypeSize() == 0)
						{
							executeCrystalAddRandomOption(pGamePlayer, pMouseItem, pItem);
						}
						else if(pItem->getOptionTypeSize() == 1)
						{
							executeOneOpCrystalAddRandomOption(pGamePlayer, pMouseItem, pItem);
						}
					}
					else if(pEventStarInfo->getItemType() == 81)
					{
						if(pItem->getOptionTypeSize() == 0)
						{
							executeCrystalAdd2RandomOption(pGamePlayer, pMouseItem, pItem);
						}
						else// if(pItem->getOptionTypeSize() == 2)
						{
							executeTwoOpCrystalAdd2RandomOption2(pGamePlayer, pMouseItem, pItem);
						}
					}
					else
					{
						executeAddRandomOption(pGamePlayer, pMouseItem, pItem, addOptionType);
					}
				}
				// Enchant Option
				else if (optionSize>1)	// by sigi. 2002.10.21
				{
					if (pEventStarInfo->isFunctionEnchantRareOption())
					{
						executeEnchantRareOption(pGamePlayer, pMouseItem, pItem, invenX, invenY);
					}
#ifdef VERSION_THIRD_ENCHANT_1
					// 20071010 ThirdEnchat 추가
					else if (pEventStarInfo->isFunctionThirdEnchantOption())
					{
						int addOptionType = pEventStarInfo->getFunctionValue();
//						cout << "Third 옵션 추가 addOptionType : " << addOptionType << endl;

						executeThirdEnchantOption(pGamePlayer, pMouseItem, pItem, addOptionType);
					}
#endif			
					else
					{
						GCAddItemToItemVerify gcAddItemToItemVerify;
						gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_IMPOSSIBLE );
						pGamePlayer->sendPacket( &gcAddItemToItemVerify );
						return;
					}
				}
				else if (pEventStarInfo->isFunctionEnchantOption())
				{
					executeEnchantOption(pGamePlayer, pMouseItem, pItem, invenX, invenY);
				}
				// Add Option
				else if (pEventStarInfo->isFunctionAddOption())
				{
					int addOptionType = pEventStarInfo->getFunctionValue();
					executeAddOption(pGamePlayer, pMouseItem, pItem, addOptionType);
				}
				// 20070725 코랄 추가
				/*	2021-08-28 by kim 위치 (else if (optionSize>1) ?문에 인챈트가 안되서 위로올림)
				else if (pEventStarInfo->isFunctionAddRandomOption())
				{
					int addOptionType = pEventStarInfo->getFunctionValue();
			 	    // 20080218 by Kim Sung Yong
					if(pEventStarInfo->getItemType() == 58  || pEventStarInfo->getItemType() == 68)
					{
						if(pItem->getOptionTypeSize() == 0)
						{
							executeCrystalAddRandomOption(pGamePlayer, pMouseItem, pItem);
						}
						else if(pItem->getOptionTypeSize() == 1)
						{
							executeOneOpCrystalAddRandomOption(pGamePlayer, pMouseItem, pItem);
						}
					}
					else if(pEventStarInfo->getItemType() == 81)
					{
						if(pItem->getOptionTypeSize() == 0)
						{
							executeCrystalAdd2RandomOption(pGamePlayer, pMouseItem, pItem);
						}
						else// if(pItem->getOptionTypeSize() == 2)
						{
							executeTwoOpCrystalAdd2RandomOption2(pGamePlayer, pMouseItem, pItem);
						}
					}
					else
					{
						executeAddRandomOption(pGamePlayer, pMouseItem, pItem, addOptionType);
					}
				}*/
				//end by kim
			}
			break;

			case Item::ITEM_CLASS_PET_ENCHANT_ITEM :
			{
				//cout << "Trying Pet Enchant... " << endl;
				if ( pItem->getItemClass() != Item::ITEM_CLASS_PET_ITEM )
				{
					//cout << "펫 아이템에다가 한게 아님다." << endl;
					GCAddItemToItemVerify gcAddItemToItemVerify;
					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );
					return;
				}

				PetEnchantItemInfo* pItemInfo = dynamic_cast<PetEnchantItemInfo*>(g_pPetEnchantItemInfoManager->getItemInfo( pMouseItem->getItemType() ));
				Assert( pItemInfo != NULL );

				PetItem* pPetItem = dynamic_cast<PetItem*>(pItem);
				PetInfo* pPetInfo = NULL;
				if ( pPetItem == NULL || ( pPetInfo = pPetItem->getPetInfo() ) == NULL )
				{
					//cout << "펫 아이템이 아니거나 펫 아이템에 펫 상태가 없습니다." << endl;
					GCAddItemToItemVerify gcAddItemToItemVerify;
					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );
					return;
				}

				/*
					ENCHANT_FUNCTION = 0,
					SPEC_OPTION_FUNCTION = 1,
					REVIVAL_FUNCTION = 13,
					RARE_FUNCTION = 14
				*/
				switch ( pItemInfo->getFunction() )
				{
					case PetEnchantItemInfo::ENCHANT_FUNCTION :
					{
						if ( pPetInfo->getPetAttr() != 0xff )
						{
							//cout << "이미 인챈트된 아이템입니다." << endl;
							GCAddItemToItemVerify gcAddItemToItemVerify;
							gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
							pGamePlayer->sendPacket( &gcAddItemToItemVerify );
							return;
						}
						//cout << "표준 인챈트 시도중입니다." << endl;
						pPC->deleteItemFromExtraInventorySlot();
						pMouseItem->destroy();
						SAFE_DELETE( pMouseItem );

						if ( PetAttrInfoManager::Instance().enchantRandomAttr( pPetInfo, pItemInfo->getFunctionGrade() ) )
						{
							//cout << "인챈트 성공." << endl;
							pPetItem->savePetInfo();

							GCAddItemToItemVerify gcAddItemToItemVerify;
							gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_OK );
							gcAddItemToItemVerify.setParameter( ((uint)pPetInfo->getPetAttr())<<16 | (uint)pPetInfo->getPetAttrLevel() );

							pGamePlayer->sendPacket( &gcAddItemToItemVerify );

							if ( pPC->getPetInfo() == pPetInfo )
							{
								//cout << "이미 불러져있어서 패킷 보내는 중입니다." << endl;
								sendPetInfo( pGamePlayer, true );
								pPC->initAllStatAndSend();
							}
							//1210 wlzzi - 분석결과 주석
							//	- 인챈트 성공 후, 그 결과에 대한 펫 정보변화를 펫이 소환상태가 아닐 때 보내지 않고 있다.
							//	- 그럼에도~ 클라에서는 펫 속성에 대한 UI표시가 정상적으로 적용된다.
							//	- 그 이유는~ 위 AddItemToItemVerify 패킷을 클라에서 처리할  때.. 클라의 펫 정보의 펫 속성정보를 갱신하기 때문
							//	---> 다시 수정... AddItemToItemVerify에서는.. 펫의 경우에 한해~~ 클라에서..펫 속성정보 갱신을 하지 않도록함..
							//		따라서.. 소환중이지 않은 녀석도.. GCPetInfo를 보내야 한다.
							else
							{
								GCPetInfo gcPetInfo;
								gcPetInfo.setPetInfo( pPetInfo );
								gcPetInfo.setSummonInfo( 0 );
								gcPetInfo.setObjectID( pPC->getObjectID() );
								pGamePlayer->sendPacket( &gcPetInfo );
							}
							return;
						}
						else
						{
							//cout << "인챈트 실패" << endl;
							GCAddItemToItemVerify gcAddItemToItemVerify;
							gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_FAIL );
							pGamePlayer->sendPacket( &gcAddItemToItemVerify );
							return;
						}
					}
					break;
//1204 wlzzi - 추가 옵션 인챈트
					case PetEnchantItemInfo::ADDED_OPTION_FUNCTION:
						// 인챈트 되어 있으면.. 기존의 것을 지우고 .. 인챈트 한다. -- 레벨제한은 없다.
						// 인챈트 되는 옵션내용을 확장성 있게 적용하려면, 인챈트되는 옵션정보를 별도로 구성해서 관리해야 한다.
						//   --> 시간 부족 및 확장성 여부 불투명 : 이번에는 하드코딩으로 .. 구현하고,
						//		추후, 동종 인챈트 아이템이 개발될 때~ 개발시간을 확보해서~ 개선하도록 한다.
					{
						int AddedOptionClass = pItemInfo->getFunctionGrade();
						int value = rand()%100;
						OptionType_t rOptionType;
						switch (AddedOptionClass)
						{
						case 18:	//Vision
							if (value < 60 )
								rOptionType = 77;
							else if (value < 90)
								rOptionType = 161;
							else
								rOptionType = 162;
							break;
						default:
							GCAddItemToItemVerify gcAddItemToItemVerify;
							gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
							pGamePlayer->sendPacket( &gcAddItemToItemVerify );
							return;
						}
						pPC->deleteItemFromExtraInventorySlot();
						pMouseItem->destroy();
						SAFE_DELETE( pMouseItem );
						
						pPetInfo->setPetOption2( rOptionType );
						
						GCAddItemToItemVerify gcAddItemToItemVerify;
						gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_OK );
						gcAddItemToItemVerify.setParameter( rOptionType );
						pGamePlayer->sendPacket( &gcAddItemToItemVerify );

						char query[100];
						sprintf(query, "PetOption2=%u", (uint)rOptionType);
						pItem->tinysave(query);

						if ( pPC->getPetInfo() == pPetInfo )
						{
							sendPetInfo( pGamePlayer, true );
							pPC->initAllStatAndSend();
						}
						else
						{
//							sendPetInfo( pGamePlayer);
							GCPetInfo gcPetInfo;
							gcPetInfo.setPetInfo( pPetInfo );
							gcPetInfo.setSummonInfo( 0 );
							gcPetInfo.setObjectID( pPC->getObjectID() );
							pGamePlayer->sendPacket( &gcPetInfo );
						}
					}
					break;
//-
					case PetEnchantItemInfo::SPEC_OPTION_FUNCTION :
					{
						if ( pPetInfo->getPetAttr() != 0xff )
						{
							//cout << "이미 인챈트된 아이템입니다." << endl;
							GCAddItemToItemVerify gcAddItemToItemVerify;
							gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
							pGamePlayer->sendPacket( &gcAddItemToItemVerify );
							return;
						}
						pPC->deleteItemFromExtraInventorySlot();
						pMouseItem->destroy();
						SAFE_DELETE( pMouseItem );

						if ( PetAttrInfoManager::Instance().enchantSpecAttr( pPetInfo, (PetAttr_t)pItemInfo->getFunctionGrade() ) )
						{
							pPetItem->savePetInfo();
							GCAddItemToItemVerify gcAddItemToItemVerify;
							gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_OK );
							gcAddItemToItemVerify.setParameter( ((uint)pPetInfo->getPetAttr())<<16 | (uint)pPetInfo->getPetAttrLevel() );
//							gcAddItemToItemVerify.setParameter( pPetInfo->getPetAttr() );

							pGamePlayer->sendPacket( &gcAddItemToItemVerify );

							if ( pPC->getPetInfo() == pPetInfo )
							{
								sendPetInfo( pGamePlayer, true );
								pPC->initAllStatAndSend();
							}
							//1210 wlzzi - 분석결과 주석
							//	- 인챈트 성공 후, 그 결과에 대한 펫 정보변화를 펫이 소환상태가 아닐 때 보내지 않고 있다.
							//	- 그럼에도~ 클라에서는 펫 속성에 대한 UI표시가 정상적으로 적용된다.
							//	- 그 이유는~ 위 AddItemToItemVerify 패킷을 클라에서 처리할  때.. 클라의 펫 정보의 펫 속성정보를 갱신하기 때문
							//	---> 다시 수정... AddItemToItemVerify에서는.. 펫의 경우에 한해~~ 클라에서..펫 속성정보 갱신을 하지 않도록함..
							//		따라서.. 소환중이지 않은 녀석도.. GCPetInfo를 보내야 한다.
							else
							{
								GCPetInfo gcPetInfo;
								gcPetInfo.setPetInfo( pPetInfo );
								gcPetInfo.setSummonInfo( 0 );
								gcPetInfo.setObjectID( pPC->getObjectID() );
								pGamePlayer->sendPacket( &gcPetInfo );
							}
							return;
						}
						else
						{
							GCAddItemToItemVerify gcAddItemToItemVerify;
							gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_FAIL );
							pGamePlayer->sendPacket( &gcAddItemToItemVerify );
							return;
						}
					}
					break;

					case PetEnchantItemInfo::RARE_FUNCTION:
					{
						//const list<PetEnchantOption*>& petEnchantOptions = g_pOptionInfoManager->getPetEnchantOptionList();
						//cout << "펫 속성이 몇개? " << petEnchantOptions.size() << endl;
						//cout << "펫 레어 인챈트 중입니다." << endl;
						if ( (pMouseItem->getItemType() == 15 && (pPetInfo->getPetLevel() != 49 || pPetInfo->getPetOption() != 0) )
							|| (pMouseItem->getItemType() == 26 && pPetInfo->getPetLevel() < 49)
							// 20070719 가칭 레드버드2 일때는 예외이다.
	//						&& ( pMouseItem->getItemType() != 26 && pPetInfo->getPetLevel() >= 49 )
							// 2007 04 10 넣었는대... 확인 않했으므로... 주석
							//&& petEnchantOptions.size() > 1 
							)
						{
							//cout << "레벨도 안된 넘 인챈트하지 마셈" << endl;
							GCAddItemToItemVerify gcAddItemToItemVerify;
							//							gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
							gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_PET_ENCHANT_LEVEL_FAIL ); // 20070807 수정 펫레벨이 안됐을 때를 구분하기 위해 코드 추가
							pGamePlayer->sendPacket( &gcAddItemToItemVerify );
							return;
						}

						/*
						OptionType_t targetOption = rand()%87;
						targetOption++;
						*/

						OptionType_t targetOption = 0;
						int ratio = rand() % 100000;
						if( pMouseItem->getItemType() == 15 )
						{
							const list<PetEnchantOption*>& petEnchantOptions = g_pOptionInfoManager->getPetEnchantOptionList();

							list<PetEnchantOption*>::const_iterator itr = petEnchantOptions.begin();
							list<PetEnchantOption*>::const_iterator endItr = petEnchantOptions.end();

							for ( ; itr != endItr ; itr++ )
							{
								PetEnchantOption* pPetEnchantOption = *itr;
								if ( pPetEnchantOption->getRatio() > ratio )
								{
									targetOption = pPetEnchantOption->getOptionType();
									break;
								}
							}
						}
						else if( pMouseItem->getItemType() == 26 )
						{
							const list<PetEnchantOption*>& petEnchantOptions = g_pOptionInfoManager->getPetEnchantOptionList2();

							list<PetEnchantOption*>::const_iterator itr = petEnchantOptions.begin();
							list<PetEnchantOption*>::const_iterator endItr = petEnchantOptions.end();

							for ( ; itr != endItr ; itr++ )
							{
								PetEnchantOption* pPetEnchantOption = *itr;
								if ( pPetEnchantOption->getRatio() > ratio )
								{
									targetOption = pPetEnchantOption->getOptionType();
									break;
								}
							}
						}

						pPC->deleteItemFromExtraInventorySlot();
						pMouseItem->destroy();
						SAFE_DELETE( pMouseItem );

/*						const list<PetEnchantOption*>& petEnchantOptions = g_pOptionInfoManager->getPetEnchantOptionList();
						list<PetEnchantOption*>::const_iterator itr = petEnchantOptions.begin();
						list<PetEnchantOption*>::const_iterator endItr = petEnchantOptions.end();

						for ( ; itr != endItr ; itr++ )
						{
							PetEnchantOption* pPetEnchantOption = *itr;
							if ( pPetEnchantOption->getRatio() > ratio )
							{
								targetOption = pPetEnchantOption->getOptionType();
								break;
							}
						}
*/
						pPetInfo->setPetOption( targetOption );
//						sendPetInfo( pGamePlayer );

						GCAddItemToItemVerify gcAddItemToItemVerify;
						gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_OK );
						gcAddItemToItemVerify.setParameter( targetOption );
						pGamePlayer->sendPacket( &gcAddItemToItemVerify );

						char query[100];
						sprintf(query, "PetOption=%u", (uint)targetOption);
						pItem->tinysave(query);

//						pPetInfo->setPetOption( targetOption );
//1210 wlzzi - 인챈트 결과 전달방식 변경						
						if ( pPC->getPetInfo() == pPetInfo )
						{
							sendPetInfo( pGamePlayer, true );
							pPC->initAllStatAndSend();
						}
						else
						{
//							sendPetInfo( pGamePlayer);
							GCPetInfo gcPetInfo;
							gcPetInfo.setPetInfo( pPetInfo );
							gcPetInfo.setSummonInfo( 0 );
							gcPetInfo.setObjectID( pPC->getObjectID() );
							pGamePlayer->sendPacket( &gcPetInfo );
						}
//						sendPetInfo( pGamePlayer );
					}
					break;

					case PetEnchantItemInfo::REVIVAL_FUNCTION:
					{
						//cout << "부활 시도중 입니다."  << endl;
						if ( pPetInfo->getPetHP() != 0 )
						{
							//cout << "안 죽은 애 부활시키지 마셈" << endl;
							GCAddItemToItemVerify gcAddItemToItemVerify;
							gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
							pGamePlayer->sendPacket( &gcAddItemToItemVerify );
							return;
						}

						pPC->deleteItemFromExtraInventorySlot();
						pMouseItem->destroy();
						SAFE_DELETE( pMouseItem );

						VSDateTime current = VSDateTime::currentDateTime();
						int Days = pPetInfo->getLastFeedTime().daysTo(current);
						if ( Days < 0 ) Days = 0;

						if ( pItemInfo->getItemType() != 14 )
						{
							int value = rand()%100;
							if ( Days >= 8 || value >= (10-Days/2)*10 )
							{
								GCAddItemToItemVerify gcAddItemToItemVerify;
								gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_FAIL );
								pGamePlayer->sendPacket( &gcAddItemToItemVerify );
								return;
							}
						}

						pPetInfo->setPetHP( pItemInfo->getFunctionGrade() );
						pPetInfo->setFeedTime( VSDateTime::currentDateTime() );
						pPetInfo->getPetItem()->savePetInfo();
						
						
						GCAddItemToItemVerify gcAddItemToItemVerify;
						gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_REVIVAL_OK );
						gcAddItemToItemVerify.setParameter( pPetInfo->getPetHP() );

						pGamePlayer->sendPacket( &gcAddItemToItemVerify );
					}
					break;

					case PetEnchantItemInfo::MUTANT_FUNCTION:
					{		
						if ( (pPetInfo->getPetType() != 1) )
						{
							cout << "울프독이 아니랍니다." << endl;
							GCAddItemToItemVerify gcAddItemToItemVerify;
							gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );  
							pGamePlayer->sendPacket( &gcAddItemToItemVerify );
							return;
						}
					
						bool summonPet = pPC->getPetInfo() == pPetInfo;

						pPC->deleteItemFromExtraInventorySlot();
						pMouseItem->destroy();
						SAFE_DELETE( pMouseItem );

						PetTypeInfo* pPetTypeInfo = PetTypeInfoManager::getInstance()->getPetTypeInfo(2);
						Assert( pPetTypeInfo != NULL );

						pPetInfo->setPetType(2);
						pPetInfo->setPetCreatureType( pPetTypeInfo->getPetCreatureType( pPetInfo->getPetLevel() ) );
						pPetItem->setItemType(2);

						pPetItem->tinysave( "ItemType=2" );

//						if ( pPC->getPetInfo() == pPetInfo ) sendPetInfo( pGamePlayer );
						if ( summonPet )
						{
							pPC->setPetInfo( NULL );
							sendPetInfo( pGamePlayer );
						}

						GCAddItemToItemVerify gcAddItemToItemVerify;
						gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_OK );
						gcAddItemToItemVerify.setParameter( 0 );

						pGamePlayer->sendPacket( &gcAddItemToItemVerify );

						GCDeleteInventoryItem gcDI;
						gcDI.setObjectID( pPetItem->getObjectID() );
						pGamePlayer->sendPacket( &gcDI );

						CoordInven_t X = -1, Y;
						pPC->getInventory()->findItemOID( pPetItem->getObjectID(), X, Y );
						Assert( X != -1 );

//						pPC->getInventory()->deleteItem( pPetItem->getObjectID() );
//						pPC->getInventory()->addItem( X, Y, pPetItem );

						GCCreateItem gcCI;
						makeGCCreateItem( &gcCI, pPetItem, X, Y );
						pGamePlayer->sendPacket( &gcCI );

						if ( summonPet )
						{
							pPC->setPetInfo( pPetInfo );
							sendPetInfo( pGamePlayer );
						}
					}
					break;

					case PetEnchantItemInfo::POLYMORPH_FUNCTION:
					{
						PetType_t currentPetType = pPetInfo->getPetType();
						PetType_t afterPetType = 0;

						if ( pPC->isSlayer() )
						{
							if ( currentPetType == 1 )
								afterPetType = 3;
							else if ( currentPetType == 3 )
								afterPetType = 1;
						}
						else if ( pPC->isVampire() )
						{
							if ( currentPetType == 1 )
								afterPetType = 4;
							else if ( currentPetType == 4 )
								afterPetType = 1;
						}
						else if ( pPC->isOusters() )
						{
							if ( currentPetType == 1 )
								afterPetType = 5;
							else if ( currentPetType == 5 )
								afterPetType = 1;
						}

						if ( afterPetType == 0 )
						{
							cout << "변환 할 수 없는 펫 타입입니다.." << endl;
							GCAddItemToItemVerify gcAddItemToItemVerify;
							gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
							pGamePlayer->sendPacket( &gcAddItemToItemVerify );
							return;
						}

						bool summonPet = pPC->getPetInfo() == pPetInfo;

						pPC->deleteItemFromExtraInventorySlot();
						pMouseItem->destroy();
						SAFE_DELETE( pMouseItem );

						PetTypeInfo* pPetTypeInfo = PetTypeInfoManager::getInstance()->getPetTypeInfo(afterPetType);
						Assert( pPetTypeInfo != NULL );

						pPetInfo->setPetType(afterPetType);
						pPetInfo->setPetCreatureType( pPetTypeInfo->getPetCreatureType( pPetInfo->getPetLevel() ) );
						pPetItem->setItemType(afterPetType);

						char tinySQL[16];
						sprintf( tinySQL, "ItemType=%u", afterPetType );
						pPetItem->tinysave( tinySQL );

						// 3,4,5 번 타입으로 변환시 30레벨 이상이면 Attack 기능 부여
						if ( afterPetType >= 3 && afterPetType <= 5 )
						{
							pPetInfo->setAttack(1);
							pPetItem->savePetInfo();
						}

						if ( summonPet )
						{
							pPC->setPetInfo( NULL );
							sendPetInfo( pGamePlayer );
						}

						GCAddItemToItemVerify gcAddItemToItemVerify;
						gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_OK );
						gcAddItemToItemVerify.setParameter( 0 );

						pGamePlayer->sendPacket( &gcAddItemToItemVerify );

						GCDeleteInventoryItem gcDI;
						gcDI.setObjectID( pPetItem->getObjectID() );
						pGamePlayer->sendPacket( &gcDI );

						CoordInven_t X = -1, Y;
						pPC->getInventory()->findItemOID( pPetItem->getObjectID(), X, Y );
						Assert( X != -1 );

						GCCreateItem gcCI;
						makeGCCreateItem( &gcCI, pPetItem, X, Y );
						pGamePlayer->sendPacket( &gcCI );

						if ( summonPet )
						{
							pPC->setPetInfo( pPetInfo );
							sendPetInfo( pGamePlayer );
						}
					}
					break;
				
				//smallheart - 20080930 - 신규펫 작업
				// 공용펫에 대한 인젝션은 하나의 Function으로 단일화 하자.
				// 그 시작으로~ 파이어엘리멘털과 신규 펫을 하나의 Function으로...
				// 가고일, 밀리터리베어, 괴도루펭까지도 하나의 Function으로.. 개별 펫 구부은 FunctionGrade값으로 구분한다.
					
					case PetEnchantItemInfo::COMMON_PET_INJECTION:
					{
						//파이어엘리멘탈는 울프독에서 밀리터리 인젝션을 사용하여 변형한다.
						//우선 변경시키려는 타입이 울프독이 아니면 할수 없다.
						
						int PetItemType = pItemInfo->getFunctionGrade ();
						
						if ( (pPetInfo->getPetType() != 40) )
						{
							if ( (pPetInfo->getPetType() != 1) && (pMouseItem->getItemType() != 65 ) )
							{
								cout << "울프독이 아니랍니다." << endl;
								GCAddItemToItemVerify gcAddItemToItemVerify;
								gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
								pGamePlayer->sendPacket( &gcAddItemToItemVerify );
								return;
							}
						}

						bool summonPet = pPC->getPetInfo() == pPetInfo;

						pPC->deleteItemFromExtraInventorySlot();
						pMouseItem->destroy();
						SAFE_DELETE( pMouseItem );

						PetTypeInfo* pPetTypeInfo = PetTypeInfoManager::getInstance()->getPetTypeInfo(PetItemType);
						Assert( pPetTypeInfo != NULL );

						ItemInfo* pPetItemInfo = g_pItemInfoManager->getItemInfo( Item::ITEM_CLASS_PET_ITEM, PetItemType );
						Assert( pPetItemInfo != NULL );

						pPC->getInventory()->deleteItem( pPetItem->getObjectID() );

						pPetInfo->setPetType(PetItemType);
						pPetInfo->setPetCreatureType( pPetTypeInfo->getPetCreatureType( pPetInfo->getPetLevel() ) );
						pPetItem->setItemType(PetItemType);
							
						if ( summonPet )
						{
							pPC->setPetInfo( NULL );
//1217 wlzzi - 펫 관련 버그수정.
//							sendPetInfo( pGamePlayer );
							sendPetInfo( pGamePlayer, true );
						}

						GCAddItemToItemVerify gcAddItemToItemVerify;
						gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_PET_ENCHANT_OK_MESSAGE );
						gcAddItemToItemVerify.setParameter( 0 );
						pGamePlayer->sendPacket( &gcAddItemToItemVerify );

						GCDeleteInventoryItem gcDI;
						gcDI.setObjectID( pPetItem->getObjectID() );
						pGamePlayer->sendPacket( &gcDI );

						CoordInven_t X = -1, Y;
						pPC->getInventory()->findItemOID( pPetItem->getObjectID(), X, Y );
						Assert( X != -1 );

						Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_PET_ITEM, PetItemType, pPetItem->getOptionTypeList() );
						Assert( pItem != NULL );
						PetItem* pNewPetItem = dynamic_cast<PetItem*>(pItem);
						Assert( pNewPetItem != NULL );
						
						PetInfo* pNewPetInfo = pPetInfo->createClone();
						//2008.12.03 - wlzzi 펫의 기본옵션 추가
						//		펫 인젝션의 경우, 인젝션되는 펫의 기본옵션을 부여해야 한다.
						pNewPetInfo->setOptionType(pPetItemInfo->getDefaultOptions());						
						//-
						//2008.12.01 - wlzzi 인큐버스일 때는 공격능력이 기본이다. --- 공격능력이 기본이 되는 펫이 또 나올 때.. Data기반으로 변경.
						if (PetItemType == 11
							|| PetItemType == 28
							|| PetItemType == 29
							|| PetItemType == 34
							|| PetItemType == 35
							)
							pNewPetInfo->setAttack (1);
						//-
						pNewPetItem->setPetInfo( pNewPetInfo );
						pNewPetInfo->setPetItem( pNewPetItem );                		
						pNewPetItem->setPetInfo( pNewPetInfo );

						Zone* pZone = pPC->getZone();
						pZone->registerObject( pItem );

						_TPOINT pt;
						if( pPC->getInventory()->addItem(pItem, pt) )
						{
							pItem->create( pPC->getName(), STORAGE_INVENTORY, 0, pt.x, pt.y );
							string strTraceLog;
							strTraceLog = pPetItemInfo->getEName ();
							strTraceLog += "Pet Changer";
							remainTraceLog( pItem, strTraceLog, pPC->getName(), ITEM_LOG_CREATE, DETAIL_ENCHANT);
						}
						else
						{
							pItem->destroy();
							string strErrorLog = pItemInfo->getEName ();
							strErrorLog += "Error - fail to addItem to Inventory";
							strErrorLog += "%s";
						 	filelog("PetItemError.txt", strErrorLog.c_str(), pPC->getName().c_str() );
							return;
						}

						pPetItem->destroy();

						GCCreateItem gcCI;
						makeGCCreateItem( &gcCI, pItem, pt.x, pt.y );
						pGamePlayer->sendPacket( &gcCI );

						if ( summonPet )
						{
							pPC->setPetInfo( pNewPetItem->getPetInfo() );
//1218 wlzzi - 펫 관련 버그 수정
//							sendPetInfo( pGamePlayer );
							sendPetInfo( pGamePlayer, true, 1 );
						}
						else
						{
							GCPetInfo gcPetInfo;
							gcPetInfo.setPetInfo( pNewPetItem->getPetInfo() );
							gcPetInfo.setSummonInfo( 0 );
							gcPetInfo.setObjectID( pPC->getObjectID() );
							pGamePlayer->sendPacket( &gcPetInfo );
						}
					}
					break;					

					case PetEnchantItemInfo::CLEAR_FIRST_ATTRIBUTE_FUNCTION:
					{
						if ( pPetInfo->getPetAttr() == 0xff || pPetInfo->getPetOption() != 0 )
						{
							// 속성(1차옵션) 이 없거나, 옵션(2차옵션)이 있다면 사용불가
							GCAddItemToItemVerify gcAddItemToItemVerify;
							gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
							pGamePlayer->sendPacket( &gcAddItemToItemVerify );
							return;
						}
						//cout << "표준 인챈트 시도중입니다." << endl;
						pPC->deleteItemFromExtraInventorySlot();
						pMouseItem->destroy();
						SAFE_DELETE( pMouseItem );

						// 펫 속성(1차옵션) 초기화
						pPetInfo->setPetAttr( 0xff );
						pPetInfo->setPetAttrLevel( 0 );

						// 저장
						pPetItem->savePetInfo();

						// 인챈트 성공 패킷 보내기
						GCAddItemToItemVerify gcAddItemToItemVerify;
						gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_OK );
						gcAddItemToItemVerify.setParameter( ((uint)pPetInfo->getPetAttr())<<16 | (uint)pPetInfo->getPetAttrLevel() );

						pGamePlayer->sendPacket( &gcAddItemToItemVerify );

						if ( pPC->getPetInfo() == pPetInfo )
						{
							// 이미 불러져있으면 패킷 보낸다.
							sendPetInfo( pGamePlayer, true );
							pPC->initAllStatAndSend();
						}
						return;
					}
					break;
					case PetEnchantItemInfo::MAGIC_ENCHANT_FUNCTION:
					{
						if ( pPetInfo->getMagicRemainSec() > 0 )
						{
							// 이미 인챈트 되어 있으면 실패
							GCAddItemToItemVerify gcAddItemToItemVerify;
							gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
							pGamePlayer->sendPacket( &gcAddItemToItemVerify );
							return;
						}
						//cout << "표준 인챈트 시도중입니다." << endl;
						pPC->deleteItemFromExtraInventorySlot();
						pMouseItem->destroy();
						SAFE_DELETE( pMouseItem );

						// 펫 속성(1차옵션) 초기화
						VSDateTime vsDateTime = VSDateTime::currentDateTime().addDays(3);
						//vsDateTime.addDays( 3 );

						pPetInfo->setMagicExpireTime( vsDateTime );

						// MagicExpireTime저장
						char sql[32];
						sprintf( sql, "MagicExpireTime='%s'", pPetInfo->getMagicExpireTime().toDateTime().c_str() );
						pPetItem->tinysave( sql );

						// 인챈트 성공 패킷 보내기
						GCAddItemToItemVerify gcAddItemToItemVerify;
						gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_PET_MAGIC_ENCHANT_OK );
						gcAddItemToItemVerify.setParameter( pPetInfo->getMagicRemainSec() );

						pGamePlayer->sendPacket( &gcAddItemToItemVerify );

						if ( pPC->getPetInfo() == pPetInfo )
						{
							// 이미 불러져있으면 패킷 보낸다.
							sendPetInfo( pGamePlayer, true );
							pPC->initAllStatAndSend();
						}
						return;
					}
					break;
					//20080701 kim sung yong --> 1202 wlzzi 본 섭에 적용	
					case PetEnchantItemInfo::EXPERT_PET_CHANGER_ENCHANT_FUNCTION:
                    {
                        if ( pPetInfo->getExpertPetChangerRemainSec() > 0 )
                        {
                            GCAddItemToItemVerify gcAddItemToItemVerify;
                            gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
                            pGamePlayer->sendPacket( &gcAddItemToItemVerify );
                            return;
                        }
                        pPC->deleteItemFromExtraInventorySlot();
                        pMouseItem->destroy();
                        SAFE_DELETE( pMouseItem );

                        VSDateTime vsDateTime = VSDateTime::currentDateTime().addDays(15);

                        pPetInfo->setExpertPetChangerExpireTime( vsDateTime );

                        char sql[32];
                        sprintf( sql, "ExpertExpireTime='%s'", pPetInfo->getExpertPetChangerExpireTime().toDateTime().c_str() );
                        pPetItem->tinysave( sql );

                        GCAddItemToItemVerify gcAddItemToItemVerify;
                        gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_PET_EXPERT_ENCHANT_OK );
                        gcAddItemToItemVerify.setParameter( pPetInfo->getExpertPetChangerRemainSec() );

                        pGamePlayer->sendPacket( &gcAddItemToItemVerify );

                        if ( pPC->getPetInfo() == pPetInfo )
                        {
                            sendPetInfo( pGamePlayer, true );
                            pPC->initAllStatAndSend();
                        }
                        return;
                    }
                    break;
                    
					// 20070720
					case PetEnchantItemInfo::ENCHANT_SKILL_FUNCTION:
					{
						PetEnchantItemInfo* pItemInfo = dynamic_cast<PetEnchantItemInfo*>(g_pPetEnchantItemInfoManager->getItemInfo( pMouseItem->getItemType() ));
						// 20070724 Add 레벨 50이하는 인챈트 할수 없다. 그리고 정해진 펫 이외의 종류도 인챈트 할수 없다.
						if( pPetInfo->getPetLevel() < 50 )
						{
							GCAddItemToItemVerify gcAddItemToItemVerify;
							//	gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
							gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_PET_ENCHANT_LEVEL_FAIL ); // 20070807 수정 펫레벨이 안됐을 때를 구분하기 위해 코드 추가
							pGamePlayer->sendPacket( &gcAddItemToItemVerify );
							return;
						}
						if(pItemInfo->getFunctionGrade() == pPetInfo->getEnchantSkill())
						{
							GCAddItemToItemVerify gcAddItemToItemVerify;
							//	gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
							gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_PET_ENCHANT_DUPLICATE_FAIL ); // 20070807 수정 같은 인챈을 시도할 때 코드 추가
							pGamePlayer->sendPacket( &gcAddItemToItemVerify );
							return;

						}

						pPetInfo->setEnchantSkill( pItemInfo->getFunctionGrade() );
/*						// 쇼크 스틱
						if( pMouseItem->getItemType() == 27 )
						{
							pPetInfo->setEnchantSkill(1);
						}
						// 아이스 스틱
						else if( pMouseItem->getItemType() == 28 )
						{
							pPetInfo->setEnchantSkill(2);
						}
						// 다이어트 스틱
						else if( pMouseItem->getItemType() == 29 )
						{
							pPetInfo->setEnchantSkill(3);
						}
						else
						{
							GCAddItemToItemVerify gcAddItemToItemVerify;
							gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
							pGamePlayer->sendPacket( &gcAddItemToItemVerify );
							return;
						}*/

						char sql[32];
						sprintf( sql, "EnchantSkill='%d'", (int)pPetInfo->getEnchantSkill() );
						pPetItem->tinysave( sql );

						pPC->deleteItemFromExtraInventorySlot();
						pMouseItem->destroy();
						SAFE_DELETE( pMouseItem );

						GCAddItemToItemVerify gcAddItemToItemVerify;
						gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_OK );
//						gcAddItemToItemVerify.setParameter(0);

						pGamePlayer->sendPacket( &gcAddItemToItemVerify );

						if ( pPC->getPetInfo() == pPetInfo )
						{
							//cout << "이미 불러져있어서 패킷 보내는 중입니다." << endl;
							sendPetInfo( pGamePlayer, true );
							pPC->initAllStatAndSend();
						}
						return;
					}
					break;
					default:
					{
						GCAddItemToItemVerify gcAddItemToItemVerify;
						gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
						pGamePlayer->sendPacket( &gcAddItemToItemVerify );
						return;
					}
				}
			}
			break;

			case Item::ITEM_CLASS_MIXING_ITEM :
			{
				if ( pItem->getItemClass() != Item::ITEM_CLASS_PET_ITEM )
				{
					//cout << "펫 아이템에다가 한게 아님다." << endl;
					GCAddItemToItemVerify gcAddItemToItemVerify;
					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );
					return;
				}

				MixingItemInfo* pItemInfo = dynamic_cast<MixingItemInfo*>(g_pMixingItemInfoManager->getItemInfo( pMouseItem->getItemType() ));
				Assert( pItemInfo != NULL );

				if ( pItemInfo->getType() != MixingItemInfo::TYPE_DETACH )
				{
					//cout << "펫 아이템에다가 한게 아님다." << endl;
					GCAddItemToItemVerify gcAddItemToItemVerify;
					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );
					return;
				}

				//20090601 ksym555
				PetItem* pPetItem = dynamic_cast<PetItem*>(pItem);
				PetInfo* pPetInfo = NULL;
				if ( pMouseItem->getItemType() != 30 )
				{
					if ( pPetItem == NULL || ( pPetInfo = pPetItem->getPetInfo() ) == NULL || pPetInfo->getPetOption() == 0 )
					{
						//cout << "펫 아이템이 아니거나 펫 아이템에 펫 상태가 없습니다." << endl;
						GCAddItemToItemVerify gcAddItemToItemVerify;
						gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
						pGamePlayer->sendPacket( &gcAddItemToItemVerify );
						return;
					}

					pPC->deleteItemFromExtraInventorySlot();
					pMouseItem->destroy();
					SAFE_DELETE( pMouseItem );

					pPetInfo->setPetOption(0);
					pPetItem->tinysave("PetOption=0");
				}
				else if ( pMouseItem->getItemType() == 30 )
				{
					if ( pPetItem == NULL || ( pPetInfo = pPetItem->getPetInfo() ) == NULL || pPetInfo->getMixOptionTypeSize() == NULL )
					{
						//cout << "펫 아이템이 아니거나 펫 아이템에 펫 상태가 없습니다." << endl;
						GCAddItemToItemVerify gcAddItemToItemVerify;
						gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
						pGamePlayer->sendPacket( &gcAddItemToItemVerify );
						return;
					}
					
					pPC->deleteItemFromExtraInventorySlot();
					pMouseItem->destroy();
					SAFE_DELETE( pMouseItem );

					list<OptionType_t> oList = pPetInfo->getMixOptionType();
					oList.clear();
					pPetInfo->setMixOptionType( oList );
					pPetItem->tinysave("MixOptionType=''");
					
					GCPetInfo gcPetInfo;
					gcPetInfo.setPetInfo( pPetItem->getPetInfo() );
					gcPetInfo.setSummonInfo( 0 );
					gcPetInfo.setObjectID( pPC->getObjectID() );
					pGamePlayer->sendPacket( &gcPetInfo );
					
					pPC->initAllStatAndSend();
				}
				
				GCAddItemToItemVerify gcAddItemToItemVerify;
				gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_OK );
				gcAddItemToItemVerify.setParameter(0);

				pGamePlayer->sendPacket( &gcAddItemToItemVerify );

				if ( pPC->getPetInfo() == pPetInfo )
				{
					//cout << "이미 불러져있어서 패킷 보내는 중입니다." << endl;
					sendPetInfo( pGamePlayer, true );
					pPC->initAllStatAndSend();
				}
				return;
			}
			break;
			//20080604
			case Item::ITEM_CLASS_SLAYER_TUNNING_ITEM :
			{
				SlayerTunningItemInfo* pMouseItemInfo = dynamic_cast<SlayerTunningItemInfo*>(g_pItemInfoManager->getItemInfo( Item::ITEM_CLASS_SLAYER_TUNNING_ITEM, pMouseItem->getItemType() ));
				Slayer* pSlayer = dynamic_cast<Slayer*>(pPC);
				
				Assert(pSlayer != NULL);
									
				if( pSlayer->getTotalAttr() < pMouseItemInfo->getReqSum() || pSlayer->getLevel() < pMouseItemInfo->getReqAdvancedLevel() )
				{
					GCAddItemToItemVerify gcAddItemToItemVerify;
					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );
					return;
				}

				if ( pItem->getItemClass() != pMouseItemInfo->getTunningItemClass() || pItem->getItemType() != pMouseItemInfo->getTunningItemType() 
				|| pItem->isTimeLimitItem())
				{
					GCAddItemToItemVerify gcAddItemToItemVerify;
					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );
					return;
				}

				ItemInfo* pItemInfo = g_pItemInfoManager->getItemInfo(pItem->getItemClass(), pItem->getItemType()); 
				list<OptionType_t> options;
				if( !g_pItemInfoManager->isPossibleItem(pItem->getItemClass(), pItemInfo->getNextItemType(), options) )
				{
					GCAddItemToItemVerify gcAddItemToItemVerify;
					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );
					return;
				}
				
				if( pItemInfo->getNextItemType() == pItem->getItemType() )
				{
					GCAddItemToItemVerify gcAddItemToItemVerify;
					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );
					return;
				}

				

				pPC->deleteItemFromExtraInventorySlot();
				pMouseItem->destroy();
				SAFE_DELETE( pMouseItem );

				pItem->setItemType( pItemInfo->getNextItemType() );
				char buffer[80];
				snprintf(buffer, 80, "ItemType=%u", pItem->getItemType() );
				pItem->tinysave(buffer);

				GCAddItemToItemVerify gcAddItemToItemVerify;
				gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_TUNNING_OK );
				gcAddItemToItemVerify.setParameter( pItem->getItemType() );
				pGamePlayer->sendPacket( &gcAddItemToItemVerify );

				return;
			}
			break;
			case Item::ITEM_CLASS_VAMPIRE_TUNNING_ITEM :
			{
				VampireTunningItemInfo* pMouseItemInfo = dynamic_cast<VampireTunningItemInfo*>(g_pItemInfoManager->getItemInfo( Item::ITEM_CLASS_VAMPIRE_TUNNING_ITEM, pMouseItem->getItemType() ));
				
				Vampire* pVampire = dynamic_cast<Vampire*>(pPC);

				Assert(pVampire != NULL);

				if( pVampire->getLevel() < pMouseItemInfo->getReqLevel() || pVampire->getLevel() < pMouseItemInfo->getReqAdvancedLevel() )
				{
					GCAddItemToItemVerify gcAddItemToItemVerify;
					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );
					return;
				}

				if ( pItem->getItemClass() != pMouseItemInfo->getTunningItemClass() || pItem->getItemType() != pMouseItemInfo->getTunningItemType() 
				|| pItem->isTimeLimitItem())
				{
					GCAddItemToItemVerify gcAddItemToItemVerify;
					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );
					return;
				}

				ItemInfo* pItemInfo = g_pItemInfoManager->getItemInfo(pItem->getItemClass(), pItem->getItemType());
				list<OptionType_t> options;
				if( !g_pItemInfoManager->isPossibleItem(pItem->getItemClass(), pItemInfo->getNextItemType(), options) )
				{
					GCAddItemToItemVerify gcAddItemToItemVerify;
					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );
					return;
				}

				if( pItemInfo->getNextItemType() == pItem->getItemType() )
				{
					GCAddItemToItemVerify gcAddItemToItemVerify;
					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );
					return;
				}


				pPC->deleteItemFromExtraInventorySlot();
				pMouseItem->destroy();
				SAFE_DELETE( pMouseItem );

				pItem->setItemType( pItemInfo->getNextItemType() );
				char buffer[80];
				snprintf(buffer, 80, "ItemType=%u", pItem->getItemType() );
				pItem->tinysave(buffer);

				GCAddItemToItemVerify gcAddItemToItemVerify;
				gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_TUNNING_OK );
				gcAddItemToItemVerify.setParameter( pItem->getItemType() );
				pGamePlayer->sendPacket( &gcAddItemToItemVerify );

				return;
			}
			break;
			case Item::ITEM_CLASS_OUSTERS_TUNNING_ITEM :
			{
				OustersTunningItemInfo* pMouseItemInfo = dynamic_cast<OustersTunningItemInfo*>( g_pItemInfoManager->getItemInfo( Item::ITEM_CLASS_OUSTERS_TUNNING_ITEM, pMouseItem->getItemType() ));
				
				Ousters* pOusters = dynamic_cast<Ousters*>(pPC);

				Assert(pOusters != NULL);

				if( pOusters->getLevel() < pMouseItemInfo->getReqLevel() || pOusters->getLevel() < pMouseItemInfo->getReqAdvancedLevel() )
				{
					GCAddItemToItemVerify gcAddItemToItemVerify;
					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );
					return;
				}

				if ( pItem->getItemClass() != pMouseItemInfo->getTunningItemClass() || pItem->getItemType() != pMouseItemInfo->getTunningItemType() 
				|| pItem->isTimeLimitItem())
				{
					GCAddItemToItemVerify gcAddItemToItemVerify;
					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );
					return;
				}

				ItemInfo* pItemInfo = g_pItemInfoManager->getItemInfo(pItem->getItemClass(), pItem->getItemType());
				list<OptionType_t> options;
				if( !g_pItemInfoManager->isPossibleItem(pItem->getItemClass(), pItemInfo->getNextItemType(), options) )
				{
					GCAddItemToItemVerify gcAddItemToItemVerify;
					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );
					return;
				}

				if( pItemInfo->getNextItemType() == pItem->getItemType() )
				{
					GCAddItemToItemVerify gcAddItemToItemVerify;
					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );
					return;
				}


				pPC->deleteItemFromExtraInventorySlot();
				pMouseItem->destroy();
				SAFE_DELETE( pMouseItem );

				pItem->setItemType( pItemInfo->getNextItemType() );
				char buffer[80];
				snprintf(buffer, 80, "ItemType=%u", pItem->getItemType() );
				pItem->tinysave(buffer);

				GCAddItemToItemVerify gcAddItemToItemVerify;
				gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_TUNNING_OK );
				gcAddItemToItemVerify.setParameter( pItem->getItemType() );
				pGamePlayer->sendPacket( &gcAddItemToItemVerify );

				return;
			}
			break;
			
			case Item::ITEM_CLASS_COMMON_QUEST_ITEM :
			{
				Inventory* pInventory = pPC->getInventory();
				Zone *pZone = pPC->getZone();

				Item *pResultItem;
				int LimitTime = 0;
				
				if ( !(pItem->getItemType() >= 36 && pItem->getItemType() <= 51 && pMouseItem->getItemType() == 35) /* 일반 보물상자와 해당키 확인 */ )
				{
					// 보물상자와 키가 일치 하지 않는 경우
					
					GCAddItemToItemVerify gcAddItemToItemVerify;
					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_OPEN_CASE_FAIL_INCORRECT_KEY );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );
					
					return;
				}
				
				if ( pItem->getNum() > 1 || pMouseItem->getNum() > 1 )
				{
					// 열려는 상자는 여러개 쌓여있지 않아야 한다.
					
					GCAddItemToItemVerify gcAddItemToItemVerify;
					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_OPEN_CASE_FAIL_INCORRECT_KEY );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );
					
					return;
				}
				
				_TPOINT pt;
				
				if ( !pPC->getInventory()->getEmptySlot( 2, 3, pt ) )
				{
					cout << "아이템 공간 없음" << endl;
										
					GCAddItemToItemVerify gcAddItemToItemVerify;
					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_OPEN_CASE_FAIL_NOT_ENOUGH_SPACE );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );
					
					return;					
				}
				////////+_+ ADD_ITEM_TO_ITEM_VERIFY_OPEN_CASE_FAIL_NOT_ENOUGH_SPACE
				
				pResultItem = g_pEventGiftBoxRewardManager->getEventGiftBoxReward(
					pCreature, 
					( Item::ITEM_CLASS_COMMON_QUEST_ITEM * 10000 ) + pItem->getItemType(), 
					LimitTime
				);
				
				if ( pResultItem == NULL )
				{
					cout << "아이템 보상 정보 없음" << endl;
					
					GCAddItemToItemVerify gcAddItemToItemVerify;
					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_OPEN_CASE_FAIL_NO_ITEM );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );
					
					return;
				}
				
				bool bEnoughSpace = false;

				
				if ( (pItem->getVolumeWidth() >= pResultItem->getVolumeWidth()) && 
					(pItem->getVolumeHeight() >= pResultItem->getVolumeHeight()) )
				{
					// 결과 아이템이 상자보다 작으면
					bEnoughSpace = true;
				}
				else if ( pInventory->getEmptySlot(pResultItem, pt) )
				{
					bEnoughSpace = true;

					// 빈공간으로 좌표 변경
					invenX = pt.x;
					invenY = pt.y;
				}
				else
				{
					cout << "아이템 공간 없음" << endl;
					
					GCAddItemToItemVerify gcAddItemToItemVerify;
					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_OPEN_CASE_FAIL_NOT_ENOUGH_SPACE );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );
					
					SAFE_DELETE(pResultItem);
					
					return;
				}
				
				pZone->registerObject(pResultItem);

				pPC->deleteItemFromExtraInventorySlot();
				pMouseItem->destroy();
				SAFE_DELETE( pMouseItem );
				
				ObjectID_t CaseItemObjectID;
				
				CaseItemObjectID = pItem->getObjectID();
				
				pInventory->deleteItem(CaseItemObjectID);
				pItem->destroy();
				SAFE_DELETE(pItem);
				
				GCDeleteInventoryItem gcDI;
				gcDI.setObjectID( CaseItemObjectID );
				pGamePlayer->sendPacket( &gcDI );
				
				if(pInventory->addItem(invenX, invenY, pResultItem))
				{
					pResultItem->create(pPC->getName(), STORAGE_INVENTORY, 0, invenX, invenY);

					if( LimitTime > 0)
					{
						pPC->addTimeLimitItem( pResultItem, LimitTime );        
						pPC->sendTimeLimitItemInfo();
					}

					GCAddItemToItemVerify gcAddItemToItemVerify;
					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_OPEN_CASE_OK );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );
					
					GCCreateItem gcCreateItem;
					makeGCCreateItem( &gcCreateItem, pResultItem, invenX, invenY );
					pGamePlayer->sendPacket(&gcCreateItem);

					// ItemTraceLog 를 남긴다
					if ( pResultItem != NULL && pResultItem->isTraceItem() )
					{
						remainTraceLog( pResultItem, "Case", pCreature->getName(), ITEM_LOG_CREATE, DETAIL_EVENTNPC);
					}
				}
				else
				{
//					filelog("GiftBoxErrorLog.txt", "[Name] : %s : 인벤토리에 아이템을 넣을 수 없다. Item : %s\n", pCreature->getName().c_str(), pResultItem->toString().c_str());
					return;
				}				
			}
			break;

			default:
			{
				//cout << "upgrade error" << endl;

				GCAddItemToItemVerify gcAddItemToItemVerify;
				gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ERROR );
				pGamePlayer->sendPacket( &gcAddItemToItemVerify );
				return;
			}
		}
	}

#endif	// __GAME_SERVER__
		
	__END_DEBUG_EX __END_CATCH
}


#ifdef __GAME_SERVER__

	int	rangeRandom(int iMinNum, int iMaxNum)
	{

		filelog("EventStar.txt", "iMinNum = %d iMaxNum = %d \n", iMinNum, iMaxNum);
		if(iMinNum > iMaxNum)
			return iMinNum;
		else if (iMinNum == iMaxNum)
			return iMaxNum;

		return (	rand() % (iMaxNum + 1 - iMinNum)	) + iMinNum;
	}



	void executeUpGrade(GamePlayer* pGamePlayer, Item* pMouseItem, Item* pItem)
		throw(Error)
	{
		__BEGIN_TRY

		Creature*  		pCreature   = pGamePlayer->getCreature();
		PlayerCreature* pPC         = dynamic_cast<PlayerCreature*>(pCreature);

		InfoClassManager* pInfoClassManager = g_pItemInfoManager->getInfoManager( pItem->getItemClass() );
		ItemType_t maxItemType = pInfoClassManager->getInfoCount();

		float typeFailRatio = 1.0 / (maxItemType - pItem->getItemType() + 2 ) / 1.25;
		float optionFailRatio = 0;
		string optionString="";

		//2007.11.20 kim sung yong
		if ( pItem->getOptionTypeSize() >= 1 &&  pMouseItem->getItemType() != 57 && pMouseItem->getItemType() != 80)
		{
			OptionType_t option = pItem->getFirstOptionType();

			OptionInfo* pOptionInfo = g_pOptionInfoManager->getOptionInfo(option);
			const OptionClassInfo* pClassInfo = g_pOptionInfoManager->getOptionClassInfo( pOptionInfo->getClass() );

			int maxGrade = pClassInfo->getTotalGrade();
			int curGrade = pOptionInfo->getGrade();

			optionFailRatio = 1.0 / (maxGrade - curGrade + 2 ) / 2.0;

			static float optionLevelWeight[] = { 1.0, 1.0, 1.1, 1.15, 1.2 };

			optionFailRatio *= optionLevelWeight[min(4,(int)pClassInfo->getLevel())];
			optionString = pOptionInfo->getNickname();
		}

		float gradeFailRatio = 1.0 - ( 4.2 / (pItem->getGrade()+1.0) );
		bool success = false;
		int prevGrade = pItem->getGrade();
		float payItemBonus = 1.0f;
		if( pMouseItem->getItemType() == 22 )
		{
			payItemBonus = 2.0f;
		}
		else if( pMouseItem->getItemType() == 48 )
		{
			payItemBonus = 2.5f;
		}

		int ratio = 1000000 - ((typeFailRatio + optionFailRatio + gradeFailRatio)/payItemBonus * 1000000);

		//2007.11.20 kim sung yong :: yellow drop USE UpGrade  
		if(pItem->getOptionTypeSize() < 3 &&  pMouseItem->getItemType() == 57)
		{
			success = true;
			pItem->setGrade( pItem->getGrade() + 1 );
			char buffer[80];
			snprintf(buffer, 80, "Grade=%u", pItem->getGrade() );
			pItem->tinysave(buffer);

			GCAddItemToItemVerify gcAddItemToItemVerify;
			gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_UP_GRADE_OK );
			gcAddItemToItemVerify.setParameter( pItem->getGrade() );
			pGamePlayer->sendPacket( &gcAddItemToItemVerify );
		}
		



		//2010.03.04 kim kyeong jin
		int			iDownGradeRatio		= 0;
		int			iUpGradeRatio		= 0;
		int			iUpDownRatio		= rand() % 2;
		int			iItemGrade			= pItem->getGrade();

		if (pItem->getOptionTypeSize() < 3 && iItemGrade < 6 && pMouseItem->getItemType() == 80 )
		{
			success = true;

			iDownGradeRatio	=	rangeRandom(2, 	iItemGrade - 1);
			iUpGradeRatio	=	rangeRandom(iItemGrade + 1, 6);

			if(iUpDownRatio == 1 || iItemGrade < 3)
			{
				pItem->setGrade(iUpGradeRatio);
			}
			else
			{
				pItem->setGrade(iDownGradeRatio);
			}

			char buffer[80];
			snprintf(buffer, 80, "Grade=%u", pItem->getGrade() );
			pItem->tinysave(buffer);

			GCAddItemToItemVerify gcAddItemToItemVerify;
			gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_UP_GRADE_OK );
			gcAddItemToItemVerify.setParameter( pItem->getGrade() );
			pGamePlayer->sendPacket( &gcAddItemToItemVerify );
		}




		//2007.11.20 kim sung yong
		if (pMouseItem->getItemType() == 80 || pMouseItem->getItemType() == 57)
		{

		}
		else if ( rand()%1000000 < ratio)
		{
			success = true;
			pItem->setGrade( pItem->getGrade() + 1 );
			char buffer[80];
			snprintf(buffer, 80, "Grade=%u", pItem->getGrade() );
			pItem->tinysave(buffer);

			GCAddItemToItemVerify gcAddItemToItemVerify;
			gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_UP_GRADE_OK );
			gcAddItemToItemVerify.setParameter( pItem->getGrade() );
			pGamePlayer->sendPacket( &gcAddItemToItemVerify );
		}
		else
		{
			GCAddItemToItemVerify gcAddItemToItemVerify;
			gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_FAIL );
			pGamePlayer->sendPacket( &gcAddItemToItemVerify );
		}

		pPC->deleteItemFromExtraInventorySlot();
		pMouseItem->destroy();
		SAFE_DELETE(pMouseItem);

		UseYellowDropLog(pGamePlayer, pItem, prevGrade, optionString.c_str(), ratio, success);

		__END_CATCH
	}
	
	void executeUpGradeInferiorYellowDrop(GamePlayer* pGamePlayer, Item* pMouseItem, Item* pItem, CoordInven_t invenX, CoordInven_t invenY)
		throw(Error)
	{
		__BEGIN_TRY

		Creature*  		pCreature   = pGamePlayer->getCreature();
		PlayerCreature* pPC         = dynamic_cast<PlayerCreature*>(pCreature);
		Inventory* 		pInventory  = pPC->getInventory();
		
		OptionType_t option = pItem->getFirstOptionType();
		OptionInfo* pOptionInfo = g_pOptionInfoManager->getOptionInfo(option);
		string optionString="";
		
		Item* pFindItem = NULL;
				
		if ( pItem->getOptionTypeSize() >= 1 && pItem->getItemType() == 69)
		{
			optionString = pOptionInfo->getNickname();
		}
			
		int prevGrade = pItem->getGrade();
		int iGradeValue = 1;
		unsigned int iGraderatio = rand() % 100;
		unsigned int ratio = rand() % 10000;
		unsigned int defenseRatio = rand() % 100;
		int SuccessRatioValue = 0;
		bool bSuccess = false;
		
		//73번 있다면... 
			
		if(pItem->getGrade() <= 3)
		{
			SuccessRatioValue = 10000; 
		}
		else if(pItem->getGrade() == 4)
		{
			SuccessRatioValue = 2000;
		}
		else if(pItem->getGrade() == 5)
		{
			SuccessRatioValue = 2000;
		}
		else if(pItem->getGrade() == 6)
		{
			SuccessRatioValue = 2000;		
		}
		else if(pItem->getGrade() == 7)
		{
			SuccessRatioValue = 2000;				
		}
		else if(pItem->getGrade() == 8)
		{
			SuccessRatioValue = 2000;						
		}
		else if(pItem->getGrade() == 9)
		{
			SuccessRatioValue = 500;								
		}
		
		if(pInventory->hasEnoughNumItem(Item::ITEM_CLASS_EVENT_STAR, 73, 1) && pItem->getGrade() >= 4)
		{
			cout << "오디너리 엘로우 드롭 인챈트 확률 상향 적용!" << endl;
			pInventory->decreaseNumItem(Item::ITEM_CLASS_EVENT_STAR, 73, 1, pCreature->getPlayer());
			
			SuccessRatioValue += 2500;
			
			if(iGraderatio < 80 || pItem->getGrade() == 9)
			{
				iGradeValue = 1;
			}
			else
			{
				iGradeValue = 2;
			}
		}
		
		if(ratio < SuccessRatioValue)
		{
			bSuccess = true;
		}
		else
		{
			bSuccess = false;
		}
		
		if(bSuccess == true)
		{		
			pItem->setGrade( pItem->getGrade() + iGradeValue );
			char buffer[80];
			snprintf(buffer, 80, "Grade=%u", pItem->getGrade() );
			pItem->tinysave(buffer);

			GCAddItemToItemVerify gcAddItemToItemVerify;
			gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_UP_GRADE_OK );
			gcAddItemToItemVerify.setParameter( pItem->getGrade() );
			pGamePlayer->sendPacket( &gcAddItemToItemVerify );
		}
		else
		{
			int FailPenaltyRatio = rand() % 10000;
			
			if(FailPenaltyRatio <= 1000)
			{
				cout<< "FailPenalty :: Yellow Drop Fail :: FailPenalty" << endl;
				
				GCAddItemToItemVerify gcAddItemToItemVerify;
				gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_FAIL );
				pGamePlayer->sendPacket( &gcAddItemToItemVerify );
				
				UseYellowDropLog(pGamePlayer, pItem, prevGrade, optionString.c_str(), ratio, bSuccess);
			}
			else if(FailPenaltyRatio >= 1001 && FailPenaltyRatio <= 3000)
			{
				cout<< "FailPenalty :: Item Delete :: FailPenalty" << endl;
				if ( pItem != NULL )
				{
					cout<< "FailPenalty :: Item Delete remainTraceLog :: FailPenalty" << endl;
					remainTraceLog( pItem, pCreature->getName(), "GOD", ITEM_LOG_DELETE, DETAIL_ENCHANT);
				}
				
				if(pInventory->hasEnoughNumItem(Item::ITEM_CLASS_EVENT_STAR, 74, 1))
				{
					pInventory->decreaseNumItem(Item::ITEM_CLASS_EVENT_STAR, 74, 1, pCreature->getPlayer());
					
					cout<< "FailPenalty :: Yellow Drop Delete Fail :: FailPenalty Fail!!" << endl;
					
					if( defenseRatio > 50 )
					{
						cout << "오디너리 엘로우 드롭 아이템 삭제 패널티에 대한 방어 성공!" << endl;
						
						GCAddItemToItemVerify gcAddItemToItemVerify;
						gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_DELETE_DEFENSE );
						pGamePlayer->sendPacket( &gcAddItemToItemVerify );
					}
					else
					{
						crashItem( pItem, pInventory, invenX, invenY );
						GCAddItemToItemVerify gcAddItemToItemVerify;
						gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_FAIL_CRASH );
						pGamePlayer->sendPacket( &gcAddItemToItemVerify );
					}
				}
				else
				{	
					crashItem( pItem, pInventory, invenX, invenY );
					GCAddItemToItemVerify gcAddItemToItemVerify;
					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_FAIL_CRASH );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );	
				}
			}
			else if(FailPenaltyRatio >= 3001 && FailPenaltyRatio <= 10000)
			{
				cout<< "FailPenalty :: DownGrade :: FailPenalty" << endl;
				
				pItem->setGrade( pItem->getGrade() - 1 );
				char buffer[80];
				snprintf(buffer, 80, "Grade=%u", pItem->getGrade() );
				pItem->tinysave(buffer);
				
				cout<< "FailPenalty :: DownGrade pItem->getGrade() :: " << (int)pItem->getGrade() << endl;
				
				GCAddItemToItemVerify gcAddItemToItemVerify;
				gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_DOWN_GRADE );
				gcAddItemToItemVerify.setParameter( pItem->getGrade() );
				pGamePlayer->sendPacket( &gcAddItemToItemVerify );
						
				UseYellowDropLog(pGamePlayer, pItem, prevGrade, optionString.c_str(), ratio, bSuccess);
			}
		}
		
		pPC->deleteItemFromExtraInventorySlot();
		pMouseItem->destroy();
		SAFE_DELETE(pMouseItem);
		
		__END_CATCH
	}
	
	void UseYellowDropLog(GamePlayer* pGamePlayer, Item* pItem, int prevGrade, const string& optionString, int ratio, int success)
		throw (Error)
	{
		__BEGIN_TRY
		
		Creature*  		pCreature   = pGamePlayer->getCreature();
		PlayerCreature* pPC         = dynamic_cast<PlayerCreature*>(pCreature);
		
		Statement* pStmt = NULL;

		BEGIN_DB
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			pStmt->executeQuery("INSERT INTO YellowDropLog (PlayerID, Name, ReportTime, IClass, IType, IID, IGrade, IOption, Ratio, Success) "
					"VALUES ('%s', '%s', now(), %u, %u, %u, %u, '%s', %u, %u)",
					pGamePlayer->getID().c_str(), pPC->getName().c_str(), pItem->getItemClass(), pItem->getItemType(), pItem->getItemID(),
					prevGrade, optionString.c_str(), (uint)ratio, ((success)?1:0) );
			SAFE_DELETE( pStmt );
		}
		END_DB(pStmt);
		
		__END_CATCH
	}

	void executeEnchantRareOption(GamePlayer* pGamePlayer, Item* pMouseItem, Item* pItem, CoordInven_t invenX, CoordInven_t invenY)
		throw (Error)
	{
		__BEGIN_TRY

		Creature*  		pCreature   = pGamePlayer->getCreature();
		PlayerCreature* pPC         = dynamic_cast<PlayerCreature*>(pCreature);
//		Inventory* 		pInventory  = pPC->getInventory();

		// 실패할 확률은 itemType에 의해서 결정된다.
		const ItemInfo* pItemInfo = g_pItemInfoManager->getItemInfo( 
													pItem->getItemClass(), 
													pItem->getItemType() );

		// 인챈트 할려는 아이템의 현재 옵션이 2개가 아니거나
		// 유니크 아이템인 경우
		// 혹은 별을 2개 이상 들고 인챈트할라고 할 때
		if (pItem->getOptionTypeSize()!=2
			|| pItemInfo->isUnique()
			|| pMouseItem->getNum() != 1
		)
		{
			//cout << "no Option " << endl;
			sendEnchantImpossible( pGamePlayer );
			return;
		}

		bool bFirstSucceed = false;
		uint optionChange = 0;
		int  shiftValue = 16;

		list<OptionType_t> optionList = pItem->getOptionTypeList();
		list<OptionType_t>::const_iterator itr = optionList.begin();

		OptionType_t firstOption = *itr++;
		OptionType_t secondOption = *itr;

		OptionInfo* pFirstOptionInfo = getOptionInfo( firstOption );
		OptionInfo* pSecondOptionInfo = getOptionInfo( secondOption );

		if ( pFirstOptionInfo == NULL || pSecondOptionInfo == NULL )
		{
			sendEnchantImpossible( pGamePlayer );
			return;
		}

		bool bFirstUpgradePossible = pFirstOptionInfo->isUpgradePossible();
		bool bSecondUpgradePossible = pSecondOptionInfo->isUpgradePossible();

		if ( !bFirstUpgradePossible && !bSecondUpgradePossible )
		{
			sendEnchantImpossible( pGamePlayer );
			return;
		}

		if ( bFirstUpgradePossible )
		{
			// 첫번째 옵션의 인챈트 확률은 블루드롭 2의 확률에 따른다.
			int succeedRatio = pFirstOptionInfo->getUpgradeSecondRatio() * pItemInfo->getUpgradeRatio();
			int dice = rand() % enchantDiceRange(EVENT_BLUE_BIRD_ENCHANT_RATIO);	//by kim old 10000

			//cout << "첫번째 옵션 : " << pFirstOptionInfo->getHName() << " 인챈트 확률 " << succeedRatio << endl;

			if ( dice < succeedRatio )
			{
				//cout << "인챈트 성공" << endl;
				processUpgradeOptionType( pItem, firstOption, pFirstOptionInfo );

				OptionType_t upgradeOptionType = pFirstOptionInfo->getUpgradeType();
				optionChange = (firstOption << (shiftValue+8)) | (upgradeOptionType << shiftValue);

				bFirstSucceed = true;
			}
			else
			{
				int noChangeRatio = 33;
				int downgradeRatio = pItemInfo->getDowngradeRatio();
				dice = rand() % 100;

				//cout << "인챈트 아템 : " << pItemInfo->getName() << " 옵션떨어질 확률 " << downgradeRatio << endl;

				if ( dice < noChangeRatio )
				{
					// 변화없음
				}
				else if ( dice < noChangeRatio + downgradeRatio )
				{
					// 옵션떨어짐
					downgradeOptionType(pItem, firstOption, pFirstOptionInfo );

					OptionType_t previousOptionType = pFirstOptionInfo->getPreviousType();
					optionChange = (firstOption << (shiftValue+8)) | (previousOptionType << shiftValue);
				}
				else
				{
					// 옵션없어짐
					pItem->removeOptionType( firstOption );
					optionChange = (firstOption << (shiftValue+8));

					// DB변경
					string optionField;
					setOptionTypeToField( pItem->getOptionTypeList(), optionField );

					char pField[80];
					sprintf(pField, "OptionType='%s'", optionField.c_str());
					pItem->tinysave(pField);
				}
			}
		}
		else
		{
			OptionType_t prev = pFirstOptionInfo->getPreviousType();

			if ( prev != 0 )
			{
				//옵션떨어질 확률 계산해야 된다.

				int noChangeRatio = 33;
				int downgradeRatio = pItemInfo->getDowngradeRatio();
				int dice = rand() % 100;

				//cout << "첫번째 옵션 : " << pFirstOptionInfo->getHName() << " 옵 떨어질 확률 : " << downgradeRatio << endl;

				if ( dice < noChangeRatio )
				{
					// 변화없음
				}
				else if ( dice < noChangeRatio + downgradeRatio )
				{
					// 옵션떨어짐
					downgradeOptionType(pItem, firstOption, pFirstOptionInfo );

					OptionType_t previousOptionType = pFirstOptionInfo->getPreviousType();
					optionChange = (firstOption << (shiftValue+8)) | (previousOptionType << shiftValue);
				}
				else
				{
					// 옵션없어짐
					pItem->removeOptionType( firstOption );
					optionChange = (firstOption << (shiftValue+8));

					// DB변경
					string optionField;
					setOptionTypeToField( pItem->getOptionTypeList(), optionField );

					char pField[80];
					sprintf(pField, "OptionType='%s'", optionField.c_str());
					pItem->tinysave(pField);

				}
			}
		}

		shiftValue -= 16;

		if ( bSecondUpgradePossible )
		{
			// 두번째 옵션의 인챈트 확률은 첫번째 옵션의 성공여부에 따른다.
			int succeedRatio = g_pOptionInfoManager->getRareUpgradeRatio( secondOption, bFirstSucceed ) * pItemInfo->getUpgradeRatio();
			int dice = rand() % enchantDiceRange(EVENT_BLUE_BIRD_ENCHANT_RATIO);	//by kim old 10000

			//cout << "두번째 옵션 : " << pSecondOptionInfo->getHName() << " 인챈트 확률 " << succeedRatio << endl;

			if ( dice < succeedRatio )
			{
				//cout << "인챈트 성공" << endl;
				processUpgradeOptionType(pItem, secondOption, pSecondOptionInfo );

				OptionType_t upgradeOptionType = pSecondOptionInfo->getUpgradeType();
				optionChange |= (secondOption << (shiftValue+8)) | (upgradeOptionType << shiftValue);

				bFirstSucceed = true;
			}
			else
			{
				int noChangeRatio = 33;
				int downgradeRatio = pItemInfo->getDowngradeRatio();
				dice = rand() % 100;

				//cout << "인챈트 아템 : " << pItemInfo->getName() << " 옵션떨어질 확률 " << downgradeRatio << endl;

				if ( dice < noChangeRatio )
				{
					// 변화없음
				}
				else if ( dice < noChangeRatio + downgradeRatio )
				{
					// 옵션떨어짐
					downgradeOptionType(pItem, secondOption, pSecondOptionInfo );

					OptionType_t previousOptionType = pSecondOptionInfo->getPreviousType();
					optionChange |= (secondOption << (shiftValue+8)) | (previousOptionType << shiftValue);
				}
				else
				{
					// 옵션없어짐
					pItem->removeOptionType( secondOption );
					optionChange |= (secondOption << (shiftValue+8));

					// DB변경
					string optionField;
					setOptionTypeToField( pItem->getOptionTypeList(), optionField );

					char pField[80];
					sprintf(pField, "OptionType='%s'", optionField.c_str());
					pItem->tinysave(pField);
				}
			}
		}
		else
		{
			OptionType_t prev = pSecondOptionInfo->getPreviousType();

			if ( prev != 0 )
			{
				//옵션떨어질 확률 계산해야 된다.
				int noChangeRatio = 33;
				int downgradeRatio = pItemInfo->getDowngradeRatio();
				int dice = rand() % 100;

				//cout << "두번째 옵션 : " << pSecondOptionInfo->getHName() << " 옵 떨어질 확률 : " << downgradeRatio << endl;

				if ( dice < noChangeRatio )
				{
					// 변화없음
				}
				else if ( dice < noChangeRatio + downgradeRatio )
				{
					// 옵션떨어짐
					downgradeOptionType(pItem, secondOption, pSecondOptionInfo );

					OptionType_t previousOptionType = pSecondOptionInfo->getPreviousType();
					optionChange |= (secondOption << (shiftValue+8)) | (previousOptionType << shiftValue);
				}
				else
				{
					// 옵션없어짐
					pItem->removeOptionType( secondOption );
					optionChange |= (secondOption << (shiftValue+8));

					// DB변경
					string optionField;
					setOptionTypeToField( pItem->getOptionTypeList(), optionField );

					char pField[80];
					sprintf(pField, "OptionType='%s'", optionField.c_str());
					pItem->tinysave(pField);
				}
			}
		}

/*		// 옵션이 여러개인 경우는 불가능하지는 않다고 보고..
		// 들고 있는 아이템이 맞는지 확인하고
		// upgrade가능한 option인 경우에...


		//const list<OptionType_t>& optionList = pItem->getOptionTypeList();
		// 복사해서 쓴다.. 
		list<OptionType_t>::const_iterator itr = optionList.begin();

		for (; itr!=optionList.end(); itr++)
		{
			OptionType_t currentOptionType = *itr;

			OptionInfo* pOptionInfo = getOptionInfo( currentOptionType );

			if (pOptionInfo==NULL)
			{
				sendEnchantImpossible( pGamePlayer );
				return;
			}

			bool bUpgradePossible = pOptionInfo->isUpgradePossible();

			if (bUpgradePossible)
			{
				//---------------------------------------------------------
				// item개수가 1개인 경우만 할 수 있도록 해둔다.
				// 여러개인 경우도 가능하게 하려면
				// 아이템 개수를 줄여야겠지.. client도 수정해야 한다.
				// upgrade 성공할까?
				//---------------------------------------------------------
				// 옵션확률 * 타잎확률 / 10000
				//---------------------------------------------------------
				// 첫번째 옵션
				//---------------------------------------------------------
	
				// 첫번째 옵션이 성공하면 두번째 옵션확률로 계산한다.
				int upgradeRatio = (bFirstSucceed? pOptionInfo->getUpgradeSecondRatio() 
												: pOptionInfo->getUpgradeRatio());


				int succeedRatio = upgradeRatio * pItemInfo->getUpgradeRatio();
				
				int dice = rand()%10000;
				bool bSucceed = (dice < succeedRatio);

				//cout << "EnchantCheck = " 
				//	<< pOptionInfo->getUpgradeRatio() << " * "
				//	<< pItemInfo->getUpgradeRatio() << " = "
				//	<< succeedRatio << ", dice = " << dice << " , succeed=" << (int)bSucceed << endl;

				//cout << "Before = " << getOptionTypeToString( pItem->getOptionTypeList() ) << endl;
				//cout << "CurrentOptionType = " << (int)currentOptionType << endl;


				if (pMouseItem->getNum()==1
					&& bSucceed)
				{
					processUpgradeOptionType( pItem, currentOptionType, pOptionInfo );

					OptionType_t upgradeOptionType = pOptionInfo->getUpgradeType();
					optionChange = (currentOptionType << (shiftValue+8)) | (upgradeOptionType << shiftValue);

					bFirstSucceed = true;
					//cout << gcAddItemToItemVerify.toString().c_str() << endl;
				}
				//---------------------------------------------------------
				// upgrade 실패
				//---------------------------------------------------------
				else
				{
					//cout << "Failed!" << endl;
					bool bCrashItem = pItemInfo->isUpgradeCrash();

					if ( bCrashItem )
					{
						// 아이템 부수기 전에 ItemTrace Log 남기자 ㅡ.ㅡ; 
						if ( pItem != NULL && pItem->isTraceItem() )
						{
							remainTraceLog( pItem, pCreature->getName(), "GOD", ITEM_LOG_DELETE, DETAIL_ENCHANT);
						}
						crashItem(pItem, pInventory, invenX, invenY);

						GCAddItemToItemVerify gcAddItemToItemVerify;
						gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_FAIL_CRASH );
						pGamePlayer->sendPacket( &gcAddItemToItemVerify );

						return;
					}
					else
					{
						// 위에서 list를 reference로 쓰면 여기에서 옵션이 제거될 수 있으므로
						// list iterator가 다이~될수도 있다.
						downgradeOptionType( pItem, currentOptionType, pOptionInfo );

						OptionType_t previousOptionType = pOptionInfo->getPreviousType();
						optionChange = (currentOptionType << (shiftValue+8)) | (previousOptionType << shiftValue);
					}
				}
			}
			else
			{
				impossibleCount ++;
			}

			shiftValue -= 16;
		}*/

		{
			// 들고 있는 별 삭제
			pPC->deleteItemFromExtraInventorySlot();

			// DB에서 삭제
			pMouseItem->destroy();

			// 메모리에서 삭제
			SAFE_DELETE(pMouseItem);

			// 결과 패킷 보내기
			sendEnchantOK(pGamePlayer, optionChange);
		}

		__END_CATCH
	}

	void executeEnchantOption(GamePlayer* pGamePlayer, Item* pMouseItem, Item* pItem, CoordInven_t invenX, CoordInven_t invenY)
		throw (Error)
	{
		__BEGIN_TRY

		Creature*  		pCreature   = pGamePlayer->getCreature();
		PlayerCreature* pPC         = dynamic_cast<PlayerCreature*>(pCreature);
		Inventory* 		pInventory  = pPC->getInventory();

		// Item의 OptionInfo를 얻어온다.
		OptionType_t currentOptionType = //pItem->getFirstOptionType();
										pItem->getRandomOptionType();

		int optionSize = pItem->getOptionTypeSize();

		// 실패할 확률은 itemType에 의해서 결정된다.
		const ItemInfo* pItemInfo = g_pItemInfoManager->getItemInfo( 
													pItem->getItemClass(), 
													pItem->getItemType() );

		// 인챈트 할려는 아이템이 무옵이거나
		// 레어 아이템이거나
		// 유니크 아이템인 경우
		if (optionSize!=1
			|| pItemInfo->isUnique())
		{
			//cout << "no Option " << endl;
			sendEnchantImpossible( pGamePlayer );
			return;
		}

		OptionInfo* pOptionInfo = getOptionInfo( currentOptionType );

		if (pOptionInfo==NULL)
		{
			sendEnchantImpossible( pGamePlayer );
			return;
		}
		
		bool bUpgradePossible = false;

		// 옵션이 여러개인 경우는 불가능하지는 않다고 보고..
		// 들고 있는 아이템이 맞는지 확인하고
		// upgrade가능한 option인 경우에...
		if(pMouseItem->getItemType() == 78 
		  || pMouseItem->getItemType() == 79
		)
		{
			bUpgradePossible = pOptionInfo->isUpgradeThirdPossible();
		}
		else
		{
			bUpgradePossible = pOptionInfo->isUpgradePossible();
		}
		
		if (optionSize>1 || bUpgradePossible)
		{
			//---------------------------------------------------------
			// item개수가 1개인 경우만 할 수 있도록 해둔다.
			// 여러개인 경우도 가능하게 하려면
			// 아이템 개수를 줄여야겠지.. client도 수정해야 한다.
			// upgrade 성공할까?
			//---------------------------------------------------------
			// 옵션확률 * 타잎확률 / 10000
			int succeedRatio = 0;
			
			if ( pMouseItem->getItemType() == 78 
				|| pMouseItem->getItemType() == 79
			)
			{
				// 블루 드롭 3
				succeedRatio = pOptionInfo->getUpgradeThirdRatio() * pItemInfo->getUpgradeRatio();
			}
			else if ( pMouseItem->getItemType() == 15 )
			{
				// 블루 드롭 2
				succeedRatio = pOptionInfo->getUpgradeSecondRatio() * pItemInfo->getUpgradeRatio();
			}
			else
			{
				// 기존 인챈트 아템들
				succeedRatio = pOptionInfo->getUpgradeRatio() * pItemInfo->getUpgradeRatio();
			}

//			cout << "옵션 " << pOptionInfo->getHName() << " 인챈트 확률 : " << succeedRatio << endl;
			
			//int dice = rand()%10000;
			int dice = rand() % enchantDiceRange(EVENT_BLUE_DROP_ENCHANT_RATIO);

			bool bSucceed = (dice < succeedRatio);

			/*
			cout << "EnchantCheck = " 
				<< pOptionInfo->getUpgradeRatio() << " * "
				<< pItemInfo->getUpgradeRatio() << " = "
				<< succeedRatio << ", dice = " << dice << " , succeed=" << (int)bSucceed << endl;
			*/

			//cout << "Before = " << getOptionTypeToString( pItem->getOptionTypeList() ) << endl;
			//cout << "CurrentOptionType = " << (int)currentOptionType << endl;

			// 옵션이 여러개 붙어있는 경우에 현재 지정한 옵션이 upgrade가 불가능하다면 실패로 본다.
			// 위의 if에서 optionSize>1 을 체크했기 때문에.. bUpgradePossible인 경우가 아니면,
			// optionSize>1 이라고 판단할 수 있다.
			if (bUpgradePossible
				&& pMouseItem->getNum()==1
				&& bSucceed)
			{
//				cout << "인챈트 성공" << endl;
				processUpgradeOptionType( pItem, currentOptionType, pOptionInfo );

				OptionType_t upgradeOptionType = pOptionInfo->getUpgradeType();
				uint optionChange = (currentOptionType << 24) | (upgradeOptionType << 16);

				sendEnchantOK( pGamePlayer, optionChange );

				//cout << gcAddItemToItemVerify.toString().c_str() << endl;
			}
			//---------------------------------------------------------
			// upgrade 실패
			//---------------------------------------------------------
			else
			{
				//cout << "Failed!" << endl;
				bool bCrashItem = pItemInfo->isUpgradeCrash();

				// 실패 packet : 아이템이 부서지는지 아닌지 결정
				GCAddItemToItemVerify gcAddItemToItemVerify;

				if ( bCrashItem && pMouseItem->getItemType() != 78 && pMouseItem->getItemType() != 79)
				{
					// 아이템 부수기 전에 ItemTrace Log 남기자 ㅡ.ㅡ; 
					if ( pItem != NULL && pItem->isTraceItem() )
					{
						remainTraceLog( pItem, pCreature->getName(), "GOD", ITEM_LOG_DELETE, DETAIL_ENCHANT);
					}

					crashItem( pItem, pInventory, invenX, invenY );

					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_FAIL_CRASH );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );
				}
				else if( pMouseItem->getItemType() != 79 )
				{
					downgradeOptionType( pItem, currentOptionType, pOptionInfo );

					OptionType_t previousOptionType = pOptionInfo->getPreviousType();
					uint optionChange = (currentOptionType << 24) | (previousOptionType << 16);

					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_FAIL_DECREASE );
					gcAddItemToItemVerify.setParameter( optionChange );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );
				}
				else if ( pMouseItem->getItemType() == 79)
				{
					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_FAIL );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );	
				}
			}

			// 들고 있는 별 삭제
			pPC->deleteItemFromExtraInventorySlot();

			// DB에서 삭제
			pMouseItem->destroy();

			// 메모리에서 삭제
			SAFE_DELETE(pMouseItem);
		}
		else
		{
			sendEnchantImpossible( pGamePlayer );
			//cout << "upgrade impossible" << endl;
		}

		__END_CATCH
	}

	// 무옵 아이템에 옵션을 추가시킨다.
	void executeAddOption(GamePlayer* pGamePlayer, Item* pMouseItem, Item* pItem, OptionType_t addOptionType)
		throw (Error)
	{
		__BEGIN_TRY

		Creature*  		pCreature   = pGamePlayer->getCreature();
		PlayerCreature* pPC         = dynamic_cast<PlayerCreature*>(pCreature);

		// 프리미엄 서비스가 아닌 경우는 안되지..
/*		if (!pGamePlayer->isPayPlaying()
			&& !pGamePlayer->isPremiumPlay())
		{
			//cout << "no Option " << endl;
			GCAddItemToItemVerify gcAddItemToItemVerify;
			gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_IMPOSSIBLE_NO_PREMIUM );
			pGamePlayer->sendPacket( &gcAddItemToItemVerify );
			return;
		}
*/

		// 이 클래스에 붙을 수 있는 옵션클래스이고..
		// 옵션이 없고
		// 유니크가 아니고
		// 마우스에 한개만 들고 하는 경우에 옵션 추가가 가능하다.
		if (isPossibleOptionItemClass(pItem->getItemClass())
			&& pItem->getOptionTypeSize()==0 
			&& !pItem->isUnique()
			&& pMouseItem->getNum()==1
			&& pMouseItem->getItemType()!=47)
		{
			// 옵션 변경
			pItem->addOptionType( addOptionType );
			
			string optionField;
			setOptionTypeToField( pItem->getOptionTypeList(), optionField );

			// DB변경
			char pField[80];
			sprintf(pField, "OptionType='%s'", optionField.c_str());
			pItem->tinysave(pField);

			uint optionChange = addOptionType;

			// 들고 있는 별 삭제
			pPC->deleteItemFromExtraInventorySlot();
			pMouseItem->destroy(); 					// DB에서 삭제
			SAFE_DELETE(pMouseItem); 				// 메모리에서 삭제


			// 성공packet : upgrade될 option을 넣어준다.
			GCAddItemToItemVerify gcAddItemToItemVerify;
			gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_OK );
			gcAddItemToItemVerify.setParameter( optionChange );
			pGamePlayer->sendPacket( &gcAddItemToItemVerify );

			//cout << gcAddItemToItemVerify.toString().c_str() << endl;
		}
		else
		{
			//cout << "Enchant Impossible" << endl;
			//cout << "impossibleOption : " << (int)currentOptionType << endl;
			// upgrade 할 수 없는 option이다.
			// 불가 packet
			GCAddItemToItemVerify gcAddItemToItemVerify;
			gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_IMPOSSIBLE );
			pGamePlayer->sendPacket( &gcAddItemToItemVerify );

			//cout << "upgrade impossible" << endl;
		}

		__END_CATCH
	}

// 20080218 by Kim Sung Yong
	void executeCrystalAddRandomOption(GamePlayer* pGamePlayer, Item* pMouseItem, Item* pItem) throw(Error)
	{
		__BEGIN_TRY

		Creature*  		pCreature   = pGamePlayer->getCreature();
		PlayerCreature* pPC         = dynamic_cast<PlayerCreature*>(pCreature);

		OptionType_t  targetOption = 0;
		int ratio = rand() % 10000;

		if (isPossibleOptionItemClass(pItem->getItemClass())
			&& pItem->getOptionTypeSize() < 1 
			&& !pItem->isUnique()
			&& pMouseItem->getNum()==1
			&& pMouseItem->getItemType()!=47)
		{
			bool bSuccess = isSuccessCrystalEnchant(pMouseItem);
			
			if(bSuccess == true)
			{
				const list<CrystalEnchantOption*>& CrystalEnchantOptions = g_pOptionInfoManager->getClystalEnchantOptionList();
				list<CrystalEnchantOption*>::const_iterator itr = CrystalEnchantOptions.begin();
				list<CrystalEnchantOption*>::const_iterator endItr = CrystalEnchantOptions.end();
	
				for ( ; itr != endItr ; itr++ )
				{
					CrystalEnchantOption* pCrystalEnchantOption = *itr;
					if ( pCrystalEnchantOption->getRatio() > ratio )
					{
						targetOption = pCrystalEnchantOption->getOptionType();
						break;
					}
				}
	
				pItem->addOptionType(targetOption);
	
				string optionField;
				setOptionTypeToField( pItem->getOptionTypeList(), optionField );
				// DB..
				char pField[80];
				sprintf(pField, "OptionType='%s'", optionField.c_str());
				pItem->tinysave(pField);
				uint optionChange = targetOption;
	
				pPC->deleteItemFromExtraInventorySlot();
				pMouseItem->destroy(); 
				SAFE_DELETE(pMouseItem);
	
				GCAddItemToItemVerify gcAddItemToItemVerify;
				gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_OK );
				gcAddItemToItemVerify.setParameter( optionChange );
				pGamePlayer->sendPacket( &gcAddItemToItemVerify );
			
				cout << "ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_OK ////////// " << optionChange << "//////////////// T_T;;;" << endl;
			}
			else
			{
				pPC->deleteItemFromExtraInventorySlot();
				pMouseItem->destroy(); 					
				SAFE_DELETE(pMouseItem); 				
				
				GCAddItemToItemVerify gcAddItemToItemVerify;
				gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_FAIL );
				pGamePlayer->sendPacket( &gcAddItemToItemVerify );	
			}
		}
		else
		{
			GCAddItemToItemVerify gcAddItemToItemVerify;
			gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_IMPOSSIBLE );
			pGamePlayer->sendPacket( &gcAddItemToItemVerify );
		}

		__END_CATCH

	}
	
// 2011.11.28 by svi  2
	void executeCrystalAdd2RandomOption(GamePlayer* pGamePlayer, Item* pMouseItem, Item* pItem) throw(Error)
	{
		__BEGIN_TRY

		Creature*  		pCreature   = pGamePlayer->getCreature();
		PlayerCreature* pPC         = dynamic_cast<PlayerCreature*>(pCreature);

		OptionType_t  targetOption = 0;
		OptionType_t  targetOption2 = 0;
		//by viva
		int mod = g_pOptionInfoManager->getTotalCrystalEnchantOption();
		//cout << "Crystal Total Ratio is " << mod << endl;
		int ratio = rand() % mod;
		int ratio2 = rand() % mod;

		if (isPossibleOptionItemClass(pItem->getItemClass())
			&& pItem->getOptionTypeSize() < 1 
			&& !pItem->isUnique()
			&& pMouseItem->getNum()==1
			&& pMouseItem->getItemType()!=47)
		{
			const list<CrystalEnchantOption*>& CrystalEnchantOptions = g_pOptionInfoManager->getClystalEnchantOptionList();
			list<CrystalEnchantOption*>::const_iterator itr = CrystalEnchantOptions.begin();
			list<CrystalEnchantOption*>::const_iterator endItr = CrystalEnchantOptions.end();

			for ( ; itr != endItr ; itr++ )
			{
				CrystalEnchantOption* pCrystalEnchantOption = *itr;
				if ( pCrystalEnchantOption->getRatio() > ratio && targetOption == 0 )
				{
					targetOption = pCrystalEnchantOption->getOptionType();
					break;
				}
			}

			itr = CrystalEnchantOptions.begin();
			for ( ; itr != endItr ; itr++ )
			{
				CrystalEnchantOption* pCrystalEnchantOption = *itr;
				if ( pCrystalEnchantOption->getRatio() > ratio2 && targetOption2 == 0 )
				{
					
					OptionInfo* pOption1= getOptionInfo( targetOption );
					OptionInfo* pOption2 = getOptionInfo( pCrystalEnchantOption->getOptionType() );
					if( pOption1->getClass() == pOption2->getClass() )
						continue;
					else
					{
						targetOption2 = pCrystalEnchantOption->getOptionType();
						break;
					}
				}
			}

			pItem->addOptionType(targetOption);
			pItem->addOptionType(targetOption2);

			string optionField;
			setOptionTypeToField( pItem->getOptionTypeList(), optionField );
			// DB..
			char pField[80];
			sprintf(pField, "OptionType='%s'", optionField.c_str());
			pItem->tinysave(pField);
			uint optionChange = (targetOption << 16) | targetOption2 ;

			pPC->deleteItemFromExtraInventorySlot();
			pMouseItem->destroy(); 
			SAFE_DELETE(pMouseItem);

			GCAddItemToItemVerify gcAddItemToItemVerify;
			gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_OK );
			gcAddItemToItemVerify.setParameter( optionChange );
			pGamePlayer->sendPacket( &gcAddItemToItemVerify );
		
			cout << "ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_OK ////////// " << optionChange << "//////////////// T_T;;;" << endl;
		}
		
		else
		{
			GCAddItemToItemVerify gcAddItemToItemVerify;
			gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_IMPOSSIBLE );
			pGamePlayer->sendPacket( &gcAddItemToItemVerify );
		}

		__END_CATCH

	}	
	
	// 20080218 by Kim Sung Yong
	void executeOneOpCrystalAddRandomOption(GamePlayer* pGamePlayer, Item* pMouseItem, Item* pItem) throw(Error)
	{
		__BEGIN_TRY

		Creature*  		pCreature   = pGamePlayer->getCreature();
		PlayerCreature* pPC         = dynamic_cast<PlayerCreature*>(pCreature);


		OptionType_t targetOption = 0;
		uint optionChange = 0;
		int ratio = rand() % 10000;

		if (isPossibleOptionItemClass(pItem->getItemClass())	
			&& pItem->getOptionTypeSize() == 1 
			&& !pItem->isUnique()
			&& pMouseItem->getNum()==1
			&& pMouseItem->getItemType()!=47)
		{
			bool bSuccess = isSuccessCrystalEnchant(pMouseItem);
			
			if(bSuccess == true)
			{
				list<OptionType_t> optionList = pItem->getOptionTypeList();
				list<OptionType_t>::const_iterator itr_op = optionList.begin();
	
				OptionType_t firstOption = *itr_op;
	
				const list<CrystalEnchantOption*>& CrystalEnchantOptions = g_pOptionInfoManager->getClystalEnchantOptionList();
	
				list<CrystalEnchantOption*>::const_iterator itr = CrystalEnchantOptions.begin();
				list<CrystalEnchantOption*>::const_iterator endItr = CrystalEnchantOptions.end();
	
				for ( ; itr != endItr ; itr++ )
				{
					CrystalEnchantOption* pCrystalEnchantOption = *itr;
					if ( pCrystalEnchantOption->getRatio() > ratio )
					{
						targetOption = pCrystalEnchantOption->getOptionType();
						break;
					}
				}
			
				pItem->changeOptionType(firstOption, targetOption);
	
				string optionField;
				setOptionTypeToField( pItem->getOptionTypeList(), optionField );
				// DB..
				char pField[80];
				sprintf(pField, "OptionType='%s'", optionField.c_str());
				pItem->tinysave(pField);
	
				optionChange = targetOption;
	
				pPC->deleteItemFromExtraInventorySlot();
				pMouseItem->destroy(); 
				SAFE_DELETE(pMouseItem);
	
				GCAddItemToItemVerify gcAddItemToItemVerify;
				gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_CHANGE_ENCHANT_OK );
				gcAddItemToItemVerify.setParameter( optionChange );
				pGamePlayer->sendPacket( &gcAddItemToItemVerify );
	
				cout << "ADD_ITEM_TO_ITEM_VERIFY_CHANGE_ENCHANT_OK ///////// " << targetOption << "//////////////////" << endl;
			}
			else
			{
				pPC->deleteItemFromExtraInventorySlot();
				pMouseItem->destroy(); 					
				SAFE_DELETE(pMouseItem); 				
				
				GCAddItemToItemVerify gcAddItemToItemVerify;
				gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_FAIL );
				pGamePlayer->sendPacket( &gcAddItemToItemVerify );	
			}
		}
		else
		{
			GCAddItemToItemVerify gcAddItemToItemVerify;
			gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_IMPOSSIBLE );
			pGamePlayer->sendPacket( &gcAddItemToItemVerify );
		}
		__END_CATCH

	}
	
	// 2011.11.28 by svi     22
	void executeTwoOpCrystalAdd2RandomOption2(GamePlayer* pGamePlayer, Item* pMouseItem, Item* pItem) throw(Error)
	{
		__BEGIN_TRY

		Creature*  		pCreature   = pGamePlayer->getCreature();
		PlayerCreature* pPC         = dynamic_cast<PlayerCreature*>(pCreature);


		OptionType_t targetOption = 0;
		OptionType_t targetOption2 = 0;
		uint optionChange = 0;
		//by viva
		int mod = g_pOptionInfoManager->getTotalCrystalEnchantOption();
		//cout << "Crystal Total Ratio is " << mod << endl;
		int ratio = rand() % mod;
		int ratio2 = rand() % mod;

		if (isPossibleOptionItemClass(pItem->getItemClass())	
			&& pItem->getOptionTypeSize() >0  
			&& !pItem->isUnique()
			&& pMouseItem->getNum()==1
			&& pMouseItem->getItemType()!=47)
		{

			int optionnum = pItem->getOptionTypeSize();
			
			list<OptionType_t> optionList = pItem->getOptionTypeList();
			list<OptionType_t>::const_iterator itr_op = optionList.begin();
			OptionType_t firstOption, secondOption;
			
			if(optionnum == 1)
			{
				firstOption = *itr_op;
				secondOption = 0;
			}
			else
			{
				firstOption = *itr_op++;
				secondOption = *itr_op;
			}


			const list<CrystalEnchantOption*>& CrystalEnchantOptions = g_pOptionInfoManager->getClystalEnchantOptionList();

			list<CrystalEnchantOption*>::const_iterator itr = CrystalEnchantOptions.begin();
			list<CrystalEnchantOption*>::const_iterator endItr = CrystalEnchantOptions.end();

			for ( ; itr != endItr ; itr++ )
			{
				CrystalEnchantOption* pCrystalEnchantOption = *itr;
				if ( pCrystalEnchantOption->getRatio() > ratio && targetOption == 0 )
				{
					targetOption = pCrystalEnchantOption->getOptionType();
					continue;
				}
				if ( pCrystalEnchantOption->getRatio() > ratio2 && targetOption2 == 0 )
				{
					targetOption2 = pCrystalEnchantOption->getOptionType();
					continue;
				}
				if(targetOption != 0 && targetOption2 != 0){
					break;
				}
			}
			if( optionnum == 1)
			{
				pItem->changeOptionType(firstOption, targetOption);
				pItem->addOptionType(targetOption2);
			}
			else
			{
				pItem->changeOptionType(firstOption, targetOption);
				pItem->changeOptionType(secondOption, targetOption2);
			}


			string optionField;
			setOptionTypeToField( pItem->getOptionTypeList(), optionField );
			// DB..
			char pField[80];
			sprintf(pField, "OptionType='%s'", optionField.c_str());
			pItem->tinysave(pField);

			optionChange = (targetOption << 16)  | targetOption2;

			pPC->deleteItemFromExtraInventorySlot();
			pMouseItem->destroy(); 
			SAFE_DELETE(pMouseItem);

			GCAddItemToItemVerify gcAddItemToItemVerify;
			gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_CHANGE_ENCHANT_OK );
			gcAddItemToItemVerify.setParameter( optionChange );
			pGamePlayer->sendPacket( &gcAddItemToItemVerify );

			cout << "ADD_ITEM_TO_ITEM_VERIFY_CHANGE_ENCHANT_OK ///////// " << targetOption << "//////////////////" << endl;
		}
		else
		{
			GCAddItemToItemVerify gcAddItemToItemVerify;
			gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_IMPOSSIBLE );
			pGamePlayer->sendPacket( &gcAddItemToItemVerify );
		}
		__END_CATCH

	}

 //20070725 


 //20070725 코랄추가
	void executeAddRandomOption(GamePlayer* pGamePlayer, Item* pMouseItem, Item* pItem, OptionType_t addOptionType) throw(Error)
	{
		__BEGIN_TRY

		Creature*  		pCreature   = pGamePlayer->getCreature();
		PlayerCreature* pPC         = dynamic_cast<PlayerCreature*>(pCreature);
		Inventory* 		pInventory  = pPC->getInventory();
		
		bool bOrdinaryCoralSeries = false;
		int AddRatioValue		  = 0;

		// 프리미엄 서비스가 아닌 경우는 안되지..
		/*		if (!pGamePlayer->isPayPlaying()
		&& !pGamePlayer->isPremiumPlay())
		{
		//cout << "no Option " << endl;
		GCAddItemToItemVerify gcAddItemToItemVerify;
		gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_IMPOSSIBLE_NO_PREMIUM );
		pGamePlayer->sendPacket( &gcAddItemToItemVerify );
		return;
		}
		*/

		if(pMouseItem->getItemType() == 63 || pMouseItem->getItemType() == 64 || pMouseItem->getItemType() == 65 ||
			pMouseItem->getItemType() == 66 || pMouseItem->getItemType() == 67 )
		{
			bOrdinaryCoralSeries = true;
		}
		
		// 이 클래스에 붙을 수 있는 옵션클래스이고..
		// 옵션이 없고
		// 유니크가 아니고
		// 마우스에 한개만 들고 하는 경우에 옵션 추가가 가능하다.
		if (isPossibleOptionItemClass(pItem->getItemClass())
			&& pItem->getOptionTypeSize()==0 
			&& !pItem->isUnique()
			&& pMouseItem->getNum()==1
			&& pMouseItem->getItemType()!=47)
		{
			
			if(pInventory->hasEnoughNumItem(Item::ITEM_CLASS_EVENT_STAR, 77, 1) && bOrdinaryCoralSeries == true)
			{	
				cout << "오디너리 코랄  앤챈트 확률 상승 적용!" << endl;
				pInventory->decreaseNumItem(Item::ITEM_CLASS_EVENT_STAR, 77, 1, pCreature->getPlayer());
			
				AddRatioValue = 30;
			}
			
			bool bSuccess = isSuccessCoralEnchant(pMouseItem, AddRatioValue);
						
			if(bSuccess == true)
			{
				int randValue = rand()%100;
	//			cout << "코랄 옵션 추가 randValue : " << randValue << endl;
				OptionType_t resultAddOptionType = addOptionType;
				if(addOptionType == 183)
				{
					if(randValue >= 90) // 블루그린 코랄 ATTR+1이 나올 확률 90% ATTR+2이 나올 확률 10%
					{
						resultAddOptionType = addOptionType + 1;
					}
				}
				else
				{
					if(randValue < 40 && randValue >= 10) // 나머지 코랄은 +1이 나올 확률 60%, +2가 나올 확률 30%, +3가 나올 확률 10%
					{
						resultAddOptionType = addOptionType + 1;
					}
					else if( pMouseItem->getItemType()==49 && randValue < 10 ||
							 pMouseItem->getItemType()==50 && randValue < 10 ||
							 pMouseItem->getItemType()==51 && randValue < 10 ||
							 pMouseItem->getItemType()==52 && randValue < 10 )
					{
						resultAddOptionType = addOptionType + 2;
					}
				}
				// 옵션 변경
				pItem->addOptionType( resultAddOptionType );
	
				string optionField;
				setOptionTypeToField( pItem->getOptionTypeList(), optionField );
	
				// DB변경
				char pField[80];
				sprintf(pField, "OptionType='%s'", optionField.c_str());
				pItem->tinysave(pField);
	
				uint optionChange = resultAddOptionType;
	
				// 들고 있는 별 삭제
				pPC->deleteItemFromExtraInventorySlot();
				pMouseItem->destroy(); 					// DB에서 삭제
				SAFE_DELETE(pMouseItem); 				// 메모리에서 삭제
	
	
				// 성공packet : upgrade될 option을 넣어준다.
				GCAddItemToItemVerify gcAddItemToItemVerify;
				gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_OK );
				gcAddItemToItemVerify.setParameter( optionChange );
				pGamePlayer->sendPacket( &gcAddItemToItemVerify );
			}
			else
			{
				// 들고 있는 별 삭제
				pPC->deleteItemFromExtraInventorySlot();
				pMouseItem->destroy(); 					// DB에서 삭제
				SAFE_DELETE(pMouseItem); 				// 메모리에서 삭제
				
				GCAddItemToItemVerify gcAddItemToItemVerify;
				gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_FAIL );
				pGamePlayer->sendPacket( &gcAddItemToItemVerify );
				
			}

			//cout << gcAddItemToItemVerify.toString().c_str() << endl;
		}
		else
		{
			//cout << "Enchant Impossible" << endl;
			//cout << "impossibleOption : " << (int)currentOptionType << endl;
			// upgrade 할 수 없는 option이다.
			// 불가 packet
			GCAddItemToItemVerify gcAddItemToItemVerify;
			gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_IMPOSSIBLE );
			pGamePlayer->sendPacket( &gcAddItemToItemVerify );

			//cout << "upgrade impossible" << endl;
		}

		__END_CATCH
	}
	
	bool isSuccessCrystalEnchant(Item* pMouseItem)
	{
		int SuccessRatioValue = rand()%100;
		
		if(pMouseItem->getItemType() == 68)
		{
			if(SuccessRatioValue > 70)
			{
				return true;
			}
			return false;
		}
		return true;
	}
	
	bool isSuccessCoralEnchant(Item* pMouseItem, int AddRatioValue)
	{
		int SuccessRatioValue = rand()%100;
		
		if(pMouseItem->getItemType() == 63)
		{
			if(SuccessRatioValue >= (70 - AddRatioValue))
			{
				return true;
			}
			return false;
		}
		else if(pMouseItem->getItemType() == 64)
		{
			if(SuccessRatioValue >= (70 - AddRatioValue))
			{
				return true;
			}
			return false;
		}
		else if(pMouseItem->getItemType() == 65)
		{
			if(SuccessRatioValue >= (70 - AddRatioValue))
			{
				return true;
			}
			return false;		
		}
		else if(pMouseItem->getItemType() == 66)
		{
			if(SuccessRatioValue >= (70 - AddRatioValue))
			{
				return true;
			}
			return false;	
		}
		else if(pMouseItem->getItemType() == 67)
		{
			if(SuccessRatioValue >= (70 - AddRatioValue))
			{
				return true;
			}
			return false;
		}
		return true;
	}

	void executeTransKit(GamePlayer* pGamePlayer, Item* pMouseItem, Item* pItem) throw(Error)
	{
		__BEGIN_TRY

		Creature*  		pCreature   = pGamePlayer->getCreature();
		PlayerCreature* pPC         = dynamic_cast<PlayerCreature*>(pCreature);
				
		GCAddItemToItemVerify gcResult;
		uint optionChange;

		ItemInfo* pItemInfo = g_pItemInfoManager->getItemInfo( pItem->getItemClass(), pItem->getItemType() );
		if ( pItemInfo->getReqGender() == GENDER_BOTH || pItemInfo->getReqGender() == GENDER_MAX
			|| pItemInfo->isUnique() 
			|| pMouseItem->getNum() != 1 )
		{
			gcResult.setCode( ADD_ITEM_TO_ITEM_VERIFY_TRANS_IMPOSSIBLE );
			pGamePlayer->sendPacket(&gcResult);
			return;
		}

		ItemType_t newItemType = pItem->getItemType() ^ 1;
		optionChange = ( pItem->getItemType() << 16 ) | newItemType;
		pItem->setItemType( newItemType );

		char query[50];
		sprintf(query, "ItemType=%u", newItemType );
		pItem->tinysave(query);

		gcResult.setCode( ADD_ITEM_TO_ITEM_VERIFY_TRANS_OK );
		gcResult.setParameter( optionChange );
		pGamePlayer->sendPacket(&gcResult);

		pPC->deleteItemFromExtraInventorySlot();
		pMouseItem->destroy();
		SAFE_DELETE(pMouseItem);

		__END_CATCH
	}

	OptionInfo* getOptionInfo(OptionType_t optionType)
	{
		OptionInfo* pOptionInfo = NULL;

		try {
			pOptionInfo = g_pOptionInfoManager->getOptionInfo( optionType );

			if (pOptionInfo==NULL)
			{
				filelog("optionError.txt", "CGAddItemToItemHandler: no option [%d]", optionType);

				return NULL;
			}
		} catch (NoSuchElementException& t) {
			filelog("optionError.txt", "CGAddItemToItemHandler: no option [%d]", optionType);

			return NULL;
		}

		return pOptionInfo;
	}


	void	processUpgradeOptionType(
					Item* pItem,
					OptionType_t currentOptionType,
					OptionInfo* pOptionInfo)
		throw (Error)
	{
		__BEGIN_TRY

		//cout << "Succeed!" << endl;
		// upgrage될 option
		OptionType_t upgradeOptionType = pOptionInfo->getUpgradeType();

		// 옵션 변경
		pItem->changeOptionType( currentOptionType, upgradeOptionType );

		//cout << "Succeed = " << getOptionTypeToString( pItem->getOptionTypeList() );
		
		string optionField;
		setOptionTypeToField( pItem->getOptionTypeList(), optionField );

		//list<OptionType_t> op;
		//setOptionTypeFromField( op, optionField );
		//cout << "Check = " << getOptionTypeToString( op ) << endl;

		// DB변경
		char pField[80];
		sprintf(pField, "OptionType='%s'", optionField.c_str());
		pItem->tinysave(pField);

		__END_CATCH
	}

	void	crashItem(Item* pItem, Inventory* pInventory, CoordInven_t invenX, CoordInven_t invenY)
		throw (Error)
	{
		__BEGIN_TRY

		// inventory에서 아이템 제거
		pInventory->deleteItem( invenX, invenY );

		// DB에서 제거
		pItem->destroy();

		// 메모리에서 제거
		SAFE_DELETE(pItem);

		__END_CATCH
	}

	void	downgradeOptionType(
					Item* pItem,
					OptionType_t currentOptionType,
					OptionInfo* pOptionInfo)
		throw (Error)
	{
		__BEGIN_TRY

		// 아이템의 옵션을 한단계 떨어뜨린다.
		OptionType_t previousOptionType = pOptionInfo->getPreviousType();

		//cout << "FailBefore : " << getOptionTypeToString(pItem->getOptionTypeList()) << endl;

		// 옵션 변경
		// 이전 옵션이 없다면 아예 옵션을 없앤다.
		if (previousOptionType==0)
		{
			pItem->removeOptionType( currentOptionType );
			//cout << "Remove = " << getOptionTypeToString( pItem->getOptionTypeList() ) << endl;
		}
		else
		{
			pItem->changeOptionType( currentOptionType, previousOptionType );
			//cout << "Down = " << getOptionTypeToString( pItem->getOptionTypeList() ) << endl;
		}

		// DB변경
		string optionField;
		setOptionTypeToField( pItem->getOptionTypeList(), optionField );

		//cout << "FailAfter : " << getOptionTypeToString(pItem->getOptionTypeList()) << endl;

		char pField[80];
		sprintf(pField, "OptionType='%s'", optionField.c_str());
		pItem->tinysave(pField);


		__END_CATCH
	}


	void	sendEnchantImpossible(GamePlayer* pGamePlayer)
		throw (Error)
	{
		__BEGIN_TRY

		GCAddItemToItemVerify gcAddItemToItemVerify;
		gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_IMPOSSIBLE );
		pGamePlayer->sendPacket( &gcAddItemToItemVerify );

		__END_CATCH
	}

	void	sendEnchantOK(GamePlayer* pGamePlayer, DWORD optionChange)
		throw (Error)
	{
		__BEGIN_TRY

		GCAddItemToItemVerify gcAddItemToItemVerify;
		gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_OK );
		gcAddItemToItemVerify.setParameter( optionChange );
		pGamePlayer->sendPacket( &gcAddItemToItemVerify );

		__END_CATCH
	}

	void yellowDropLog(PlayerCreature* pPC, Item* pItem, int ratio, int success) throw(Error)
	{
		__BEGIN_TRY

		__END_CATCH
	}

#ifdef VERSION_THIRD_ENCHANT_1
	void		sendThirdEnchantOK(GamePlayer* pGamePlayer, list<OptionType_t>& changeOption, BYTE enchantClass) 
		throw (Error)
	{
		__BEGIN_TRY

		GCAddItemToItemVerify gcAddItemToItemVerify;
		gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_THIRD_ENCHANT_OK );
		gcAddItemToItemVerify.setThirdOptionType(changeOption);
		gcAddItemToItemVerify.setThirdEnchantType(enchantClass);
		pGamePlayer->sendPacket( &gcAddItemToItemVerify );

		__END_CATCH

	}
	void		sendThirdEnchantFail(GamePlayer* pGamePlayer, BYTE grade) 
		throw (Error)
	{
		__BEGIN_TRY

		GCAddItemToItemVerify gcAddItemToItemVerify;
		gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_THIRD_ENCHANT_FAIL );
		gcAddItemToItemVerify.setGrade( grade );
		pGamePlayer->sendPacket( &gcAddItemToItemVerify );

		__END_CATCH

	}

	void	saveThirdOptionType(Item* pItem)
		throw (Error)
	{
		__BEGIN_TRY

		string optionField;
		setOptionTypeToField( pItem->getThirdOptionTypeList(), optionField );

		// DB변경
		char pField[80];
		sprintf(pField, "ThirdOptionType='%s'", optionField.c_str());
		pItem->tinysave(pField);
		cout << "pField : " << pField << endl;

		__END_CATCH
	}
	
	bool isSuccessThirdEnchant(Item* pMouseItem, int AddRatioValue)
	{
		int SuccessRatioValue = rand()%100;
		
		if(pMouseItem->getItemType() == 70)
		{
			if(SuccessRatioValue >= (70 - AddRatioValue))
			{
				return true;
			}
			return false;
		}
		if(pMouseItem->getItemType() == 71)
		{
			if(SuccessRatioValue >= (70 - AddRatioValue))
			{
				return true;
			}
			return false;
		}	
		if(pMouseItem->getItemType() == 72)
		{
			if(SuccessRatioValue >= (70 - AddRatioValue))
			{
				return true;
			}
			return false;
		}
		return true;
	}


	void executeThirdEnchantOption(GamePlayer* pGamePlayer, Item* pMouseItem, Item* pItem, OptionType_t addOptionType)
		throw (Error)
	{
		__BEGIN_TRY

		Creature*  		pCreature   = pGamePlayer->getCreature();
		PlayerCreature* pPC         = dynamic_cast<PlayerCreature*>(pCreature);
		Inventory* 		pInventory  = pPC->getInventory();
		

		const ItemInfo* pItemInfo = g_pItemInfoManager->getItemInfo( 
			pItem->getItemClass(), 
			pItem->getItemType() );

		// 인챈트 할려는 아이템의 현재 옵션이 2개가 아니거나
		// 유니크 아이템인 경우
		// 혹은 별을 2개 이상 들고 인챈트할라고 할 때
		if (pItem->getOptionTypeSize()!=2
			|| pItemInfo->isUnique()
			|| pMouseItem->getNum() != 1
			)
		{
			//cout << "no Option " << endl;
			sendEnchantImpossible( pGamePlayer );
			return;
		}

		int iEnchantClass = addOptionType-1; // 서버 코드상에는 ENCHANT_CLASS_MELEE가 0부터 시작된다.
		if(iEnchantClass < ThirdEnchantInfo::ENCHANT_CLASS_MELEE || iEnchantClass > ThirdEnchantInfo::ENCHANT_CLASS_MAX)
		{
			filelog("thirdEnchant.log", "addOptionType wrong value");
			Assert(false);
		}

		list<OptionType_t> optionList = pItem->getThirdOptionTypeList();
		list<OptionType_t> changeOptionList;
	
		unsigned int successRatio = rand()%100;
		unsigned int defenseRatio = rand()%100;
		bool bSuccess = false;
		int ibeforeGrade = pItem->getGrade();
		int iAfterGrade = pItem->getGrade();
		
		int ibeforeThirdOptionNum = g_pThirdEnchantInfo->getThirdOptionNumOptionList(iEnchantClass, optionList) + 1;
		int iAfterThirdOptionNum = -1;
		int iClientDeleteCode = 1;
		int AddRatioValue = 0;
		bool Lilith2Series = false;
								
		//isSuccessThirdEnchant(pMouseItem, AddRatioValue);

		if(optionList.size() > 0)
		{
			int iEnchantedClass = g_pThirdEnchantInfo->getEnchantClassThirdOption(optionList);
			if(iEnchantClass != iEnchantedClass)
			{
				cout << "Enchanted class : " << iEnchantedClass << ", EnchantClass : " << iEnchantClass << "different" << endl;
				sendEnchantImpossible( pGamePlayer );
				return;
			}
		}
		
		//20090410 ksym555 릴리스2 시리즈 추가
		if(pMouseItem->getItemType() == 60 || pMouseItem->getItemType() == 61 || pMouseItem->getItemType() == 62 )
		{
			ibeforeThirdOptionNum = g_pThirdEnchantInfo->getThirdOptionNumOptionList(iEnchantClass, optionList) + 1;
				
			if(ibeforeThirdOptionNum > 3)
			{
				//클라이언트와 4이상 못하는것에 대한 실패코드를 99로 정한다.
				int iFailCode = 99;
				sendThirdEnchantFail(pGamePlayer, iFailCode);
				return;
			}
			
			Lilith2Series = true;
			successRatio = 0;
		}
		
		// itemClass 검사 iEnchantClass가 동일하지 않으면 이상한거다.
		if(!g_pItemClassInfo->hasEnchantClass(pItem->getItemClass(), (int)addOptionType))
		{
			cout << "item wrong enchant class pItem->getItemClass(): " << pItem->getItemClass() << ", addOptionType : " << (int)addOptionType << endl;
			sendEnchantImpossible( pGamePlayer );
			return;
		}
			
		if(pInventory->hasEnoughNumItem(Item::ITEM_CLASS_EVENT_STAR, 75, 1) && Lilith2Series == false)
		{	
			cout << "오디너리 릴리스 앤챈트 확률 상승 적용!" << endl;
			pInventory->decreaseNumItem(Item::ITEM_CLASS_EVENT_STAR, 75, 1, pCreature->getPlayer());
		
			//일괄적으로 25% 확률 상향 하며, 9단계일때는 4% 상향시킨다.
			AddRatioValue = 25;
		}
		
		// 업그레이드 성공인가?
		if(successRatio < (g_pThirdEnchantInfo->getUpdadeRatio(iEnchantClass, optionList) + AddRatioValue))
		{
			// 성공시 다음 레벨의 옵션을 부여한다.
			if(!g_pThirdEnchantInfo->getNextThirdOptionType(iEnchantClass, optionList, changeOptionList))
			{
				cout << "Function getNextThirdOptionType failed" << endl;
				filelog("thirdEnchant.log", "Function getNextThirdOptionType failed");
				sendEnchantImpossible( pGamePlayer );
				return;
			}
			cout << "ThirdEnchant Succeed!!! " << endl;
			pItem->setThirdOptionType(changeOptionList);
			saveThirdOptionType(pItem);
			ibeforeGrade = pItem->getGrade();
			iAfterGrade = pItem->getGrade();
			bSuccess = true;
			
			iAfterThirdOptionNum = g_pThirdEnchantInfo->getThirdOptionNumOptionList(iEnchantClass, optionList) + 1;
		}
		else
		{
			if(pInventory->hasEnoughNumItem(Item::ITEM_CLASS_EVENT_STAR, 76, 1) && optionList.size() != 0)
			{
				pInventory->decreaseNumItem(Item::ITEM_CLASS_EVENT_STAR, 76, 1, pCreature->getPlayer());
				
				cout<< "FailPenalty Fail :: Lilith Series :: FailPenalty Fail!!" << endl;
				
				if(defenseRatio > 50)
				{
					cout << "오디너리 릴리스를 사용하여  아이템  패널티에 대한 방어 성공!" << endl;
					
					GCAddItemToItemVerify gcAddItemToItemVerify;
					gcAddItemToItemVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_ENCHANT_THIRDOPTION_PENALTY_DEFENSE );
					pGamePlayer->sendPacket( &gcAddItemToItemVerify );
					
					pPC->deleteItemFromExtraInventorySlot();
					pMouseItem->destroy();
	
					SAFE_DELETE(pMouseItem);
					
					return;
				}
				else
				{
					iClientDeleteCode = 0;
					iAfterThirdOptionNum = -1;
					
					pItem->clearThirdOption();
					saveThirdOptionType(pItem);
					
				}
			}	
			else if(optionList.size() == 0) // thirdoption이 없다면 등급을 한단계 낮춘다.
			{
				ibeforeGrade = pItem->getGrade();
				if(ibeforeGrade > 1)
					pItem->setGrade(ibeforeGrade - 1);
				iAfterGrade = pItem->getGrade();
				
				cout << "beforeGrade : " << ibeforeGrade << endl;
				cout << "AfterGrade : " << iAfterGrade << endl;

				char buffer[80];
				snprintf(buffer, 80, "Grade=%u", pItem->getGrade() );
				pItem->tinysave(buffer);
				
				ibeforeThirdOptionNum = 0;
				iAfterThirdOptionNum = -1;
			}
			else if(optionList.size() != 0) // thirdoption이 있다면 삭제한다.
			{
				iClientDeleteCode = 0;
				iAfterThirdOptionNum = -1;
				
				pItem->clearThirdOption();
				saveThirdOptionType(pItem);
			}
			
			bSuccess = false;
		}

		Statement* pStmt = NULL;

		BEGIN_DB
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			pStmt->executeQuery(
			"INSERT INTO LilithSeriesLog (PlayerID, Name, ReportTime, ItemType, ItemID, BeforeLevel, AfterLevel, BeforeGrade, AfterGrade, TargetItemClass, TargetItemType, TargetItemID, Success)"
			" VALUES('%s','%s',now(),%u, %u, %u, %u, %u, %u, '%s', %u, %u, %d )",
														
			pGamePlayer->getID().c_str(),
			pPC->getName().c_str(),
			pMouseItem->getItemType(),
			pMouseItem->getItemID(),
			ibeforeThirdOptionNum,
			iAfterThirdOptionNum + 1,
			ibeforeGrade,
			iAfterGrade,
			ItemClass2ShortString[ (int)(pItem->getItemClass()) ].c_str(),
			pItem->getItemType(),
			pItem->getItemID(),
			bSuccess
			);
			SAFE_DELETE( pStmt );
		}
		END_DB(pStmt);
		
		{
			// 들고 있는 별 삭제
			pPC->deleteItemFromExtraInventorySlot();

			// DB에서 삭제
			pMouseItem->destroy();

			// 메모리에서 삭제
			SAFE_DELETE(pMouseItem);

			// 결과 패킷 보내기
			if(bSuccess)
				sendThirdEnchantOK(pGamePlayer, changeOptionList, iEnchantClass);
			else if(iClientDeleteCode == 0)
				sendThirdEnchantFail(pGamePlayer, 0);
			else
				sendThirdEnchantFail(pGamePlayer, iAfterGrade);

		}

		__END_CATCH

	}
#endif // VERSION_THIRD_ENCHANT_1

#endif 
