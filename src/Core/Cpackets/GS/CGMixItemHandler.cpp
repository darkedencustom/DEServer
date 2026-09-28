//////////////////////////////////////////////////////////////////////////////
// Filename    : CGMixItemHandler.cpp
// Written By  : elca@ewestsoft.com
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "CGMixItem.h"

#ifdef __GAME_SERVER__
#include <cstdio>
#include "GamePlayer.h"
#include "Inventory.h"
#include "PlayerCreature.h"
#include "Item.h"
#include "item/PetItem.h"
#include "PetInfo.h"
#include "MixingItem.h"
#include "ItemUtil.h"
#include "ItemInfoManager.h"
#include "OptionInfo.h"
#include "Gpackets/GCCannotUse.h"
#include "Gpackets/GCUseOK.h"
#include "Gpackets/GCAddItemToItemVerify.h"
#include "Gpackets/GCDeleteInventoryItem.h"
#include "PetAttrInfo.h"
#include "Gpackets/GCPetInfo.h"

#include "DB.h"

void sendCannotUse(CGMixItem* pPacket, Player* pPlayer);
#endif

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void CGMixItemHandler::execute(CGMixItem* pPacket, Player* pPlayer)
	throw (ProtocolException, Error)
{
	__BEGIN_TRY __BEGIN_DEBUG_EX

#ifdef __GAME_SERVER__

	////cout << "CGMixItemHandler " << endl;
	Assert(pPacket != NULL);
	Assert(pPlayer != NULL);

	GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(pPlayer);
	Assert(pGamePlayer != NULL);

	Creature* pCreature = pGamePlayer->getCreature();
	Assert(pCreature != NULL);
	Assert(pCreature->isPC());

	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
	Assert(pPC != NULL);

	Inventory* pInventory = pPC->getInventory();
	Zone*      pZone      = pPC->getZone();

	Assert(pInventory != NULL);
	Assert(pZone != NULL);

	CoordInven_t InvenX = pPacket->getX();
	CoordInven_t InvenY = pPacket->getY();

	//cout << "패킷날라옴 : " << pPacket->toString() << endl;

	// 인벤토리 좌표를 넘어가는 영역이라면 안 된다.
	if (InvenX >= pInventory->getWidth() || InvenY >= pInventory->getHeight())
	{
		sendCannotUse( pPacket, pPlayer );
		return;
	}

	Item* pItem = pPC->findItemOID( pPacket->getObjectID() );
	
	if (pItem == NULL)
	{
		// 캐릭터가 아이템을 가지고 있지 않는 경우
		sendCannotUse( pPacket, pPlayer );
        
		return;
	}

	// 믹싱 포지가 아니면 안된다 -_-
	if ( pItem->getItemClass() != Item::ITEM_CLASS_MIXING_ITEM )
	{
		sendCannotUse( pPacket, pPlayer );
		return;
	}

	MixingItemInfo* pInfo = dynamic_cast<MixingItemInfo*>(g_pItemInfoManager->getItemInfo( pItem->getItemClass(), pItem->getItemType() ));
	Assert( pInfo != NULL );

	switch ( pInfo->getType() )
	{
		case MixingItemInfo::TYPE_MIX:
		{
			// 믹싱아이템을 우클릭하여 합칠 아이템 2개를 선택한 후 적용
			
			Item* pTempItem = pInventory->getItem(InvenX, InvenY);
			if ( pTempItem == NULL || pTempItem->getObjectID() != pItem->getObjectID() )
			{
				sendCannotUse( pPacket, pPlayer );
				return;
			}
			cout<< " #####################  Item Taget : " << pInfo->getTarget() << endl;
			
			//20090526 ksym555
			if(pInfo->getTarget() == MixingItemInfo::MIXING_PET)
			{
				cout<< " #####################  executePetMix " << endl;
				executePetMix( pPacket, pPlayer, pItem );
			}
			else
			{
				cout<< " #####################  executeMix " << endl;
				executeMix( pPacket, pPlayer, pItem );
			}
		}
			break;
		case MixingItemInfo::TYPE_DETACH:
			// Target 아이템에 믹싱아이템을 올려 놓는 형태
			if ( pPC->getExtraInventorySlotItem() != NULL )
			{
				if(pInfo->getTarget() == MixingItemInfo::MIXING_PET)
				{
					cout<< " #####################  executePetDetach " << endl;
					executePetDetach( pPacket, pPlayer, pItem );
				}
				else
				{	
				// 마우스에 아이템이 붙은 경우에만 적용
					executeDetach( pPacket, pPlayer, pItem );
				}
			}
			else
			{
				sendCannotUse( pPacket, pPlayer );
				return;
			}
			
			break;

		case MixingItemInfo::TYPE_CLEAR:
			// Target 아이템에 믹싱아이템을 올려 놓는 형태
			if ( pPC->getExtraInventorySlotItem() != NULL )
			{
				// 마우스에 아이템이 붙은 경우에만 적용
				executeClearOption( pPacket, pPlayer, pItem );
			}
			else
			{
				sendCannotUse( pPacket, pPlayer );
				return;
			}
			break;

		default:
			sendCannotUse( pPacket, pPlayer );
			break;
	}

#endif

    __END_DEBUG_EX __END_CATCH
}

#ifdef __GAME_SERVER__
void CGMixItemHandler::executeMix(CGMixItem* pPacket, Player* pPlayer, Item* pItem) throw(Error)
{
	__BEGIN_TRY

	Assert(pPacket != NULL);
	Assert(pPlayer != NULL);

	GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(pPlayer);
	Assert(pGamePlayer != NULL);

	Creature* pCreature = pGamePlayer->getCreature();
	Assert(pCreature != NULL);
	Assert(pCreature->isPC());

	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
	Assert(pPC != NULL);

	Inventory* pInventory = pPC->getInventory();
	Zone*      pZone      = pPC->getZone();

	CoordInven_t InvenX = pPacket->getX();
	CoordInven_t InvenY = pPacket->getY();

	Assert(pInventory != NULL);
	Assert(pZone != NULL);

	Item *pTargetItem1 = NULL;
	Item *pTargetItem2 = NULL;

	CoordInven_t dummy;

	pTargetItem1 = pInventory->findItemOID( pPacket->getTargetObjectID(0), dummy, dummy );
	pTargetItem2 = pInventory->findItemOID( pPacket->getTargetObjectID(1), dummy, dummy );
//#ifdef VERSION_THIRD_ENCHANT_1
//	cout << "executeMix, pTargetItem1->getThirdOptionTypeSize() : " << pTargetItem1->getThirdOptionTypeSize() << endl;
//	cout << "executeMix, pTargetItem2->getThirdOptionTypeSize() : " << pTargetItem2->getThirdOptionTypeSize() << endl;
//	if((pTargetItem1->getThirdOptionTypeSize() > 0) || (pTargetItem2->getThirdOptionTypeSize() > 0))
//	{
//		sendCannotUse( pPacket, pPlayer );
//		return;
//	}
//#endif
	if ( pTargetItem1 == NULL || pTargetItem2 == NULL )
	{
		sendCannotUse( pPacket, pPlayer );
		return;
	}

	ItemInfo* pInfo1 = g_pItemInfoManager->getItemInfo( pTargetItem1->getItemClass(), pTargetItem1->getItemType() );
	int GradeDiff = pTargetItem1->getGrade() - pTargetItem2->getGrade();
	Grade_t TargetGrade = ( pTargetItem1->getGrade() > pTargetItem2->getGrade() )?pTargetItem1->getGrade():pTargetItem2->getGrade();

	if ( pTargetItem1->getItemClass() != pTargetItem2->getItemClass() ||
		 pTargetItem1->getItemType() != pTargetItem2->getItemType() ||
		 pTargetItem1->getOptionTypeSize() != 1 ||
		 pTargetItem2->getOptionTypeSize() != 1 ||
		 pTargetItem1->isTimeLimitItem() ||
		 pTargetItem2->isTimeLimitItem() ||
		 pInfo1->isUnique() ||
		 GradeDiff < -2 || GradeDiff > 2
	   )
	{
		sendCannotUse( pPacket, pPlayer );
		return;
	}
	
	bool Success = true;
	bool IMImixItem = false;
	
	if (pItem->getItemType() == 31 ||
		pItem->getItemType() == 32 ||
		pItem->getItemType() == 33
	)
	{
		IMImixItem = true;
		cout<< "New Mix Item Use ... =_=;; " << endl;

		// The untyped forges (Weapon/Armor/Accessory Mixing Forge) used to fail 60% of
		// the time (rand()%100 < 60). They always succeed now, like the typed ones.
	}

	MixingItemInfo* pInfo = dynamic_cast<MixingItemInfo*>(g_pItemInfoManager->getItemInfo( pItem->getItemClass(), pItem->getItemType() ));
	Assert( pInfo != NULL );

	MixingItemInfo::Target target = pInfo->getTarget();
	if ( IMImixItem == false )
	{
		switch ( target )
		{
			case MixingItemInfo::MIXING_WEAPON:
				{
					if ( isSlayerWeapon( pTargetItem1->getItemClass() ) ) 
					{
						if ( pInfo1->getItemLevel() > pInfo->getSlayerLevel() ||
							// 20070724 승직 전용으로 설정 이하의 아이템은 되지 않도록 한다. 비승직용 보다 가격이 저렴하다;;
	//						(pInfo->getItemType() == 26 && !(pInfo1->getReqAdvancedLevel() == 1 || pInfo1->getReqAdvancedLevel() == 11)) // 20080728 세트등급도 되도록 변경
							(pInfo->getItemType() == 26 && !(pInfo1->getReqAdvancedLevel() > 0 && pInfo1->getReqAdvancedLevel() < 41)) // smallheart - 오시리스까지 허용
							 )
						{
							sendCannotUse( pPacket, pPlayer );
							return;
						}
					}
					else if ( isVampireWeapon( pTargetItem1->getItemClass() ) )
					{
						if ( pInfo1->getItemLevel() > pInfo->getVampireLevel()  ||
							// 20070724 승직 전용으로 설정 이하의 아이템은 되지 않도록 한다. 비승직용 보다 가격이 저렴하다;;
	//						(pInfo->getItemType() == 26 && !(pInfo1->getReqAdvancedLevel() == 1 || pInfo1->getReqAdvancedLevel() == 11)) // 20080728 세트등급도 되도록 변경
							(pInfo->getItemType() == 26 && !(pInfo1->getReqAdvancedLevel() > 0 && pInfo1->getReqAdvancedLevel() < 41)) // smallheart - 오시리스까지 허용
							)
						{
							sendCannotUse( pPacket, pPlayer );
							return;
						}
					}
					else if ( isOustersWeapon( pTargetItem1->getItemClass() ) )
					{
						if ( pTargetItem1->getItemClass() == Item::ITEM_CLASS_OUSTERS_WRISTLET )
						{
							if ( pInfo1->getItemLevel() > pInfo->getOustersLevel() ||
							// 20070724 승직 전용으로 설정 이하의 아이템은 되지 않도록 한다. 비승직용 보다 가격이 저렴하다;;
	//							(pInfo->getItemType() == 26 && !(pInfo1->getReqAdvancedLevel() == 1 || pInfo1->getReqAdvancedLevel() == 11)) // 20080728 세트등급도 되도록 변경
								(pInfo->getItemType() == 26 && !(pInfo1->getReqAdvancedLevel() > 0 && pInfo1->getReqAdvancedLevel() < 41)) // smallheart - 오시리스까지 허용
								)
							{
								sendCannotUse( pPacket, pPlayer );
								return;
							}
						}
						else if ( pInfo1->getItemLevel() > pInfo->getOustersLevel()  ||
							// 20070724 승직 전용으로 설정 이하의 아이템은 되지 않도록 한다. 비승직용 보다 가격이 저렴하다;;
	//							(pInfo->getItemType() == 26 && !(pInfo1->getReqAdvancedLevel() == 1 || pInfo1->getReqAdvancedLevel() == 11)) // 20080728 세트등급도 되도록 변경
								(pInfo->getItemType() == 26 && !(pInfo1->getReqAdvancedLevel() > 0 && pInfo1->getReqAdvancedLevel() < 41)) // smallheart - 오시리스까지 허용
								)
						{
							sendCannotUse( pPacket, pPlayer );
							return;
						}
					}
					else
					{
						sendCannotUse( pPacket, pPlayer );
						return;
					}
				}
				break;
	
			case MixingItemInfo::MIXING_ARMOR:
				{
					if ( isSlayerArmor( pTargetItem1->getItemClass() ) ) 
					{
						if ( pInfo1->getItemLevel() > pInfo->getSlayerLevel() ||
							// 20070724 승직 전용으로 설정 이하의 아이템은 되지 않도록 한다. 비승직용 보다 가격이 저렴하다;;
							// 081001 smallheart - 승직전용으로 처리하기 위한 아래 조건문에 오류가 있어 수정함.
	//						(pInfo->getItemType() == 27 && pInfo1->getItemLevel() != pInfo->getSlayerLevel() )
							//  -- 오시리스까지만 허용
							(pInfo->getItemType() == 27 && !(pInfo1->getReqAdvancedLevel() > 0 && pInfo1->getReqAdvancedLevel() < 41) )
							)
						{
							sendCannotUse( pPacket, pPlayer );
							return;
						}
					}
					else if ( isVampireArmor( pTargetItem1->getItemClass() ) )
					{
						if ( pInfo1->getItemLevel() > pInfo->getVampireLevel() ||
							// 20070724 승직 전용으로 설정 이하의 아이템은 되지 않도록 한다. 비승직용 보다 가격이 저렴하다;;
							// 081001 smallheart - 승직전용으로 처리하기 위한 아래 조건문에 오류가 있어 수정함.
	//						(pInfo->getItemType() == 27 && pInfo1->getItemLevel() != pInfo->getVampireLevel() )
							//  -- 오시리스까지만 허용
							(pInfo->getItemType() == 27 && !(pInfo1->getReqAdvancedLevel() > 0 && pInfo1->getReqAdvancedLevel() < 41) )
							)
						{
							sendCannotUse( pPacket, pPlayer );
							return;
						}
					}
					else if ( isOustersArmor( pTargetItem1->getItemClass() ) )
					{
						if ( pInfo1->getItemLevel() > pInfo->getOustersLevel() ||
							// 20070724 승직 전용으로 설정 이하의 아이템은 되지 않도록 한다. 비승직용 보다 가격이 저렴하다;;
							// 081001 smallheart - 승직전용으로 처리하기 위한 아래 조건문에 오류가 있어 수정함.
	//						(pInfo->getItemType() == 27 && pInfo1->getItemLevel() != pInfo->getOustersLevel() )
							//  -- 오시리스까지만 허용
							(pInfo->getItemType() == 27 && !(pInfo1->getReqAdvancedLevel() > 0 && pInfo1->getReqAdvancedLevel() < 41) )
							)
						{
							sendCannotUse( pPacket, pPlayer );
							return;
						}
					}
					else
					{
						sendCannotUse( pPacket, pPlayer );
						return;
					}
				}
				break;
	
			case MixingItemInfo::MIXING_ACCESSORY:
				{
					if ( isSlayerAccessory( pTargetItem1->getItemClass() ) ) 
					{
						if ( pInfo1->getItemLevel() > pInfo->getSlayerLevel() )
						{
							sendCannotUse( pPacket, pPlayer );
							return;
						}
					}
					else if ( isVampireAccessory( pTargetItem1->getItemClass() ) )
					{
						if ( pInfo1->getItemLevel() > pInfo->getVampireLevel() )
						{
							sendCannotUse( pPacket, pPlayer );
							return;
						}
					}
					else if ( isOustersAccessory( pTargetItem1->getItemClass() ) )
					{
						//081002 smallheart - 정령석도~ 믹싱레벨 체크를 해야 한다.
						if ( pInfo1->getItemLevel() > pInfo->getOustersLevel() )
	//					if ( pTargetItem1->getItemClass() != Item::ITEM_CLASS_OUSTERS_STONE && pInfo1->getItemLevel() > pInfo->getOustersLevel() )
						{
							sendCannotUse( pPacket, pPlayer );
							return;
						}
					}
					else
					{
						sendCannotUse( pPacket, pPlayer );
						return;
					}
				}
				break;
			case MixingItemInfo::MIXING_ADV_ARMOR:
				{
					if ( isSlayerAdvancedArmor( pTargetItem1->getItemClass() ) ) 
					{
					}
					else if ( isVampireAdvancedArmor( pTargetItem1->getItemClass() ) )
					{
					}
					else if ( isOustersAdvancedArmor( pTargetItem1->getItemClass() ) )
					{
					}
					else
					{
						sendCannotUse( pPacket, pPlayer );
						return;
					}
				}
				break;
	
			default:
				{
					sendCannotUse( pPacket, pPlayer );
					return;
				}
		}
	}

	GCAddItemToItemVerify gcVerify;
	
	const list<OptionType_t>& oList1 = pTargetItem1->getOptionTypeList();
	Assert( !oList1.empty() );
	OptionType_t option1 = oList1.front();
	OptionInfo* pOptionInfo1 = g_pOptionInfoManager->getOptionInfo( option1 );

	const list<OptionType_t>& oList2 = pTargetItem2->getOptionTypeList();
	Assert( !oList2.empty() );
	OptionType_t option2 = oList2.front();
	OptionInfo* pOptionInfo2 = g_pOptionInfoManager->getOptionInfo( option2 );
	
	if ( g_pOptionInfoManager->getOptionClassInfo( pOptionInfo1->getClass() )->getOptionGroup() ==
		 g_pOptionInfoManager->getOptionClassInfo( pOptionInfo2->getClass() )->getOptionGroup() )
	{
//		sendCannotUse(pPacket, pPlayer);
		gcVerify.setCode(ADD_ITEM_TO_ITEM_VERIFY_MIXING_FAILED_SAME_OPTION_GROUP);
		pPlayer->sendPacket(&gcVerify);
		return;
	}
	
	if(Success == true)
	{
		pTargetItem1->addOptionType( option2 );
		// pTargetItem1 이나 pTargetItem2 중 하나라도 남기는 거면 만들어지는 것도 남긴다
		pTargetItem1->setTraceItem(pTargetItem1->isTraceItem() || pTargetItem2->isTraceItem() );
		pTargetItem1->setGrade( TargetGrade );
	
		string optionfield = "";
		setOptionTypeToField( pTargetItem1->getOptionTypeList(), optionfield );
		char query[100];
		if ( TargetGrade == -1 )
			sprintf( query, "OptionType='%s'", optionfield.c_str() );
		else
			sprintf( query, "OptionType='%s', Grade=%d", optionfield.c_str(), pTargetItem1->getGrade() );
	
		pTargetItem1->tinysave(query);
	
		sprintf( query, "%ld", pTargetItem1->getItemID() );
	
		pInventory->deleteItem( pTargetItem2->getObjectID() );
		if ( pTargetItem2->isTraceItem() )
		{
			remainTraceLog( pTargetItem2, pPC->getName(), query, ITEM_LOG_DELETE, DETAIL_ENCHANT );
		}
		pTargetItem2->destroy();
		SAFE_DELETE( pTargetItem2 );
	}

	if ( pItem->isTraceItem() )
	{
		remainTraceLog( pItem, pPC->getName(), "Mixing Forge", ITEM_LOG_DELETE, DETAIL_ENCHANT );
	}

	if ( isStackable(pItem) )
	{
		decreaseItemNum( pItem, pInventory, pCreature->getName(), STORAGE_INVENTORY, 0, InvenX, InvenY);
	}
	else 
	{
		pInventory->deleteItem( pItem->getObjectID() );
		pItem->destroy();
		SAFE_DELETE( pItem );
	}
	
	if(Success == true)
	{
		gcVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_MIXING_OK );
		uint param = 0;

		param = ( ( ((int)option1) << 16 ) | option2 );
		printf("Param:%x\n", param);

		gcVerify.setParameter( param );

		pPlayer->sendPacket( &gcVerify );
	}
	else
	{
		gcVerify.setCode(ADD_ITEM_TO_ITEM_VERIFY_MIXING_FAIL);
		pPlayer->sendPacket(&gcVerify);
	}
	
	GCUseOK gcUseOK;
	pPlayer->sendPacket(&gcUseOK);

	__END_CATCH
}

void CGMixItemHandler::executeDetach(CGMixItem* pPacket, Player* pPlayer, Item* pItem) throw(Error)
{
	__BEGIN_TRY

	Assert(pPacket != NULL);
	Assert(pPlayer != NULL);

	GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(pPlayer);
	Assert(pGamePlayer != NULL);

	Creature* pCreature = pGamePlayer->getCreature();
	Assert(pCreature != NULL);
	Assert(pCreature->isPC());

	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
	Assert(pPC != NULL);

	Inventory* pInventory = pPC->getInventory();
	Zone*      pZone      = pPC->getZone();

	Assert(pInventory != NULL);
	Assert(pZone != NULL);

	Item *pTargetItem = NULL;

	CoordInven_t dummy;

	pTargetItem = pInventory->findItemOID( pPacket->getTargetObjectID(0), dummy, dummy );
	uint optionNo = (uint)pPacket->getTargetObjectID(1);

	if ( pTargetItem == NULL || optionNo >= 2 || pItem->getNum() != 1)
	{
		sendCannotUse( pPacket, pPlayer );
		return;
	}

	ItemInfo* pTargetInfo = g_pItemInfoManager->getItemInfo( pTargetItem->getItemClass(), pTargetItem->getItemType() );
#ifdef VERSION_THIRD_ENCHANT_1
	cout << "executeDetach, pTargetItem->getThirdOptionTypeSize() : " << pTargetItem->getThirdOptionTypeSize() << endl;

	if ( pTargetInfo->isUnique() || pTargetItem->isTimeLimitItem() || (pTargetItem->getOptionTypeSize() != 2) || (pTargetItem->getThirdOptionTypeSize() > 0))
#else
	if ( pTargetInfo->isUnique() || pTargetItem->isTimeLimitItem() || pTargetItem->getOptionTypeSize() != 2)
#endif
	{
		sendCannotUse( pPacket, pPlayer );
		return;
	}

	MixingItemInfo* pInfo = dynamic_cast<MixingItemInfo*>(g_pItemInfoManager->getItemInfo( pItem->getItemClass(), pItem->getItemType() ));
	Assert( pInfo != NULL );

	MixingItemInfo::Target target = pInfo->getTarget();

	switch ( target )
	{
		case MixingItemInfo::MIXING_WEAPON:
			{
				if ( isSlayerWeapon( pTargetItem->getItemClass() ) ) 
				{
					if ( pTargetInfo->getItemLevel() > pInfo->getSlayerLevel() )
					{
						sendCannotUse( pPacket, pPlayer );
						return;
					}
				}
				else if ( isVampireWeapon( pTargetItem->getItemClass() ) )
				{
					if ( pTargetInfo->getItemLevel() > pInfo->getVampireLevel() )
					{
						sendCannotUse( pPacket, pPlayer );
						return;
					}
				}
				else if ( isOustersWeapon( pTargetItem->getItemClass() ) )
				{
					if ( pTargetInfo->getItemLevel() > pInfo->getOustersLevel() )
					{
						sendCannotUse( pPacket, pPlayer );
						return;
					}
				}
				else
				{
					sendCannotUse( pPacket, pPlayer );
					return;
				}
			}
			break;

		case MixingItemInfo::MIXING_ARMOR:
			{
				if ( isSlayerArmor( pTargetItem->getItemClass() ) ) 
				{
					if ( pTargetInfo->getItemLevel() > pInfo->getSlayerLevel() )
					{
						sendCannotUse( pPacket, pPlayer );
						return;
					}
				}
				else if ( isVampireArmor( pTargetItem->getItemClass() ) )
				{
					if ( pTargetInfo->getItemLevel() > pInfo->getVampireLevel() )
					{
						sendCannotUse( pPacket, pPlayer );
						return;
					}
				}
				else if ( isOustersArmor( pTargetItem->getItemClass() ) )
				{
					if ( pTargetInfo->getItemLevel() > pInfo->getOustersLevel() )
					{
						sendCannotUse( pPacket, pPlayer );
						return;
					}
				}
				else
				{
					sendCannotUse( pPacket, pPlayer );
					return;
				}
			}
			break;

		case MixingItemInfo::MIXING_ACCESSORY:
			{
				if ( isSlayerAccessory( pTargetItem->getItemClass() ) ) 
				{
					if ( pTargetInfo->getItemLevel() > pInfo->getSlayerLevel() )
					{
						sendCannotUse( pPacket, pPlayer );
						return;
					}
				}
				else if ( isVampireAccessory( pTargetItem->getItemClass() ) )
				{
					if ( pTargetInfo->getItemLevel() > pInfo->getVampireLevel() )
					{
						sendCannotUse( pPacket, pPlayer );
						return;
					}
				}
				else if ( isOustersAccessory( pTargetItem->getItemClass() ) )
				{
					if ( pTargetInfo->getItemLevel() > pInfo->getOustersLevel() )
					{
						sendCannotUse( pPacket, pPlayer );
						return;
					}
				}
				else
				{
					sendCannotUse( pPacket, pPlayer );
					return;
				}
			}
			break;
		// 20070726
		case MixingItemInfo::MIXING_ALL:
			{
				if ( isSlayerWeapon( pTargetItem->getItemClass() ) || isSlayerArmor( pTargetItem->getItemClass() ) || isSlayerAccessory( pTargetItem->getItemClass() ) )
				{
					if ( pTargetInfo->getItemLevel() > pInfo->getSlayerLevel() )
					{
						sendCannotUse( pPacket, pPlayer );
						return;
					}
				}
				else if ( isVampireWeapon( pTargetItem->getItemClass() ) || isVampireArmor( pTargetItem->getItemClass() ) || isVampireAccessory( pTargetItem->getItemClass() ) )
				{
					if ( pTargetInfo->getItemLevel() > pInfo->getVampireLevel() )
					{
						sendCannotUse( pPacket, pPlayer );
						return;
					}
				}
				else if ( isOustersWeapon( pTargetItem->getItemClass() ) || isOustersArmor( pTargetItem->getItemClass() ) || isOustersAccessory( pTargetItem->getItemClass() ) )
				{
					if ( pTargetInfo->getItemLevel() > pInfo->getOustersLevel() )
					{
						sendCannotUse( pPacket, pPlayer );
						return;
					}
				}
				else
				{
					sendCannotUse( pPacket, pPlayer );
					return;
				}
			}
			break;

		default:
			{
				sendCannotUse( pPacket, pPlayer );
				return;
			}
	}

	list<OptionType_t> oList = pTargetItem->getOptionTypeList();
	Assert( oList.size() == 2 );

	// optionNo는 0 아니면 1이다. (위에서 체크했다.)
	if ( optionNo == 0 ) oList.pop_front(); else oList.pop_back();
	pTargetItem->setOptionType( oList );

	string optionfield = "";
	setOptionTypeToField( pTargetItem->getOptionTypeList(), optionfield );
	char query[100];
	sprintf( query, "OptionType='%s'", optionfield.c_str() );
	pTargetItem->tinysave(query);

	pTargetItem->setTraceItem( bTraceLog( pTargetItem ) );

//	pInventory->deleteItem( pItem->getObjectID() );
	Assert( pItem == pPC->getExtraInventorySlotItem() );
	// 옵션 떼내는 아템은 마우스 위에 있다. 없음말고
	pPC->deleteItemFromExtraInventorySlot();
	if ( pItem->isTraceItem() )
	{
		remainTraceLog( pItem, pPC->getName(), "Furitas", ITEM_LOG_DELETE, DETAIL_ENCHANT );
	}
	pItem->destroy();
	SAFE_DELETE( pItem );

	GCAddItemToItemVerify gcVerify;
	gcVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_DETACHING_OK );

	OptionType_t finalOption = oList.front();
	gcVerify.setParameter(finalOption);

	pPlayer->sendPacket( &gcVerify );

//	GCUseOK gcUseOK;
//	pPlayer->sendPacket(&gcUseOK);

	__END_CATCH
}

void CGMixItemHandler::executeClearOption(CGMixItem* pPacket, Player* pPlayer, Item* pItem) throw(Error)
{
	__BEGIN_TRY

	Assert(pPacket != NULL);
	Assert(pPlayer != NULL);

	GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(pPlayer);
	Assert(pGamePlayer != NULL);

	Creature* pCreature = pGamePlayer->getCreature();
	Assert(pCreature != NULL);
	Assert(pCreature->isPC());

	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
	Assert(pPC != NULL);

	Inventory* pInventory = pPC->getInventory();
	Zone*      pZone      = pPC->getZone();

	Assert(pInventory != NULL);
	Assert(pZone != NULL);

	Item *pTargetItem = NULL;

	CoordInven_t dummy;

	pTargetItem = pInventory->findItemOID( pPacket->getTargetObjectID(0), dummy, dummy );
	uint optionNo = (uint)pPacket->getTargetObjectID(1);

	if ( pTargetItem == NULL || optionNo >= 2 || pItem->getNum() != 1)
	{
		sendCannotUse( pPacket, pPlayer );
		return;
	}

	Item::ItemClass iClass = pTargetItem->getItemClass();

	ItemInfo* pTargetInfo = g_pItemInfoManager->getItemInfo( pTargetItem->getItemClass(), pTargetItem->getItemType() );
#ifdef VERSION_THIRD_ENCHANT_1
	cout << "executeClearOption, pTargetItem->getThirdOptionTypeSize() : " << pTargetItem->getThirdOptionTypeSize() << endl;

	if ( pTargetInfo->isUnique() || pTargetItem->isTimeLimitItem() || (pTargetItem->getOptionTypeSize() != 1) || (pTargetItem->getThirdOptionTypeSize() > 0))
#else
	if ( pTargetInfo->isUnique() || pTargetItem->isTimeLimitItem() || (pTargetItem->getOptionTypeSize() != 1) )
#endif
	{
		sendCannotUse( pPacket, pPlayer );
		return;
	}

	MixingItemInfo* pInfo = dynamic_cast<MixingItemInfo*>(g_pItemInfoManager->getItemInfo( pItem->getItemClass(), pItem->getItemType() ));
	Assert( pInfo != NULL );

	MixingItemInfo::Target target = pInfo->getTarget();

	switch ( target )
	{
		case MixingItemInfo::MIXING_ALL:
			{
				if ( isSlayerWeapon( iClass ) || isSlayerArmor( iClass ) || isSlayerAccessory( iClass ) )
				{
					if ( pTargetInfo->getItemLevel() > pInfo->getSlayerLevel() )
					{
						sendCannotUse( pPacket, pPlayer );
						return;
					}
				}
				else if ( isVampireWeapon( iClass ) || isVampireArmor( iClass ) || isVampireAccessory( iClass ) )
				{
					if ( pTargetInfo->getItemLevel() > pInfo->getVampireLevel() )
					{
						sendCannotUse( pPacket, pPlayer );
						return;
					}
				}
				else if ( isOustersWeapon( iClass ) || isOustersArmor( iClass ) || isOustersAccessory( iClass ) )
				{
					if ( pTargetInfo->getItemLevel() > pInfo->getOustersLevel() )
					{
						sendCannotUse( pPacket, pPlayer );
						return;
					}
				}
				else
				{
					sendCannotUse( pPacket, pPlayer );
					return;
				}
			}
			break;

		default:
			{
				sendCannotUse( pPacket, pPlayer );
				return;
			}
	}

	list<OptionType_t> oList = pTargetItem->getOptionTypeList();
	if ( oList.size() != 1 )
	{
		sendCannotUse( pPacket, pPlayer );
		return;
	}

	// 이제 옵션을 없애버린다.
	oList.clear();
	pTargetItem->setOptionType( oList );

	// 옵션이 없다고 DB에 저장한다
	pTargetItem->tinysave( "OptionType=''" );

	pTargetItem->setTraceItem( bTraceLog( pTargetItem ) );

//	pInventory->deleteItem( pItem->getObjectID() );
	Assert( pItem == pPC->getExtraInventorySlotItem() );
	// 옵션 떼내는 아템은 마우스 위에 있다. 없음말고
	pPC->deleteItemFromExtraInventorySlot();
	if ( pItem->isTraceItem() )
	{
		remainTraceLog( pItem, pPC->getName(), "ClearOption", ITEM_LOG_DELETE, DETAIL_ENCHANT );
	}
	pItem->destroy();
	SAFE_DELETE( pItem );

	GCAddItemToItemVerify gcVerify;
	gcVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_CLEAR_OPTION_OK );

	pPlayer->sendPacket( &gcVerify );

	__END_CATCH
}

void CGMixItemHandler::executePetMix(CGMixItem* pPacket, Player* pPlayer, Item* pItem) throw(Error)
{
	__BEGIN_TRY

	Assert(pPacket != NULL);
	Assert(pPlayer != NULL);

	GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(pPlayer);
	Assert(pGamePlayer != NULL);

	Creature* pCreature = pGamePlayer->getCreature();
	Assert(pCreature != NULL);
	Assert(pCreature->isPC());

	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
	Assert(pPC != NULL);

	Inventory* pInventory = pPC->getInventory();
	Zone*      pZone      = pPC->getZone();

	CoordInven_t InvenX = pPacket->getX();
	CoordInven_t InvenY = pPacket->getY();

	Assert(pInventory != NULL);
	Assert(pZone != NULL);

	PetItem* pPetItem1 = NULL;
	PetItem* pPetItem2 = NULL;
	
	GCAddItemToItemVerify gcVerify;
	
	CoordInven_t dummy;

	pPetItem1 = dynamic_cast<PetItem*>(pInventory->findItemOID( pPacket->getTargetObjectID(0), dummy, dummy ));
	pPetItem2 = dynamic_cast<PetItem*>(pInventory->findItemOID( pPacket->getTargetObjectID(1), dummy, dummy ));
	
	if ( pPetItem1 == NULL || pPetItem2 == NULL )
	{
		sendCannotUse( pPacket, pPlayer );
		return;
	}
		
	cout << " 대상 펫 레벨 : " << (int)pPetItem1->getPetInfo()->getPetLevel() << endl;
	cout << " 재료 펫 레벨 : " << (int)pPetItem2->getPetInfo()->getPetLevel() << endl;

	int iMaterialPetLevel = (int)pPetItem2->getPetInfo()->getPetLevel();
	int iDefaultValue = 0;
	int iRandomValue = 0;
	int iOptionValue = 0;
	int iRV = 0;
	
	if ( pPetItem1->getItemClass() != Item::ITEM_CLASS_PET_ITEM ||
		 (int)pPetItem1->getPetInfo()->getPetLevel() != 50 ||
		 pPetItem1->getPetInfo()->getMixOptionTypeSize() != NULL ||
		 pPetItem1->isTimeLimitItem()
	   )
	{
		gcVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_PET_MIXING_FAIL );
		pPlayer->sendPacket( &gcVerify );
		
		cout << " 대상아이템 제한 사항에 걸리셨구나~ +_+ " << endl;
		sendCannotUse( pPacket, pPlayer );
		return;
	}
	
	if ( pPetItem2->getItemClass() != Item::ITEM_CLASS_PET_ITEM ||
		 iMaterialPetLevel < 11 ||
		 iMaterialPetLevel > 39 ||
		 pPetItem2->isTimeLimitItem()
	   )
	{
		gcVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_PET_MIXING_FAIL );
		pPlayer->sendPacket( &gcVerify );
		
		cout << " 재료아이템 제한 사항에 걸리셨구나~ +_+ " << endl;
		sendCannotUse( pPacket, pPlayer );
		return;
	}

	if(pPetItem2->getPetInfo()->getPetAttr() == 255)
	{
		gcVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_PET_MIXING_FAIL );
		pPlayer->sendPacket( &gcVerify );
		
		cout << " 아놔 1차 옵션 없네 그랴 " << endl;
		sendCannotUse( pPacket, pPlayer );		
		return;
		
	}
	else if(pPetItem2->getPetInfo()->getPetAttr() != 255 && pPetItem2->getPetInfo()->getPetAttrLevel() >= 1)
	{
		cout << " 속성이 있구먼! " << endl;
				
//		const OptionClassInfo* pClassInfo = 
//			g_pOptionInfoManager->getOptionClassInfo((OptionClass)PetAttrInfoManager::Instance().PetRandomAttr());
	
		const OptionClassInfo* pClassInfo = 
		g_pOptionInfoManager->getOptionClassInfo((OptionClass)pPetItem2->getPetInfo()->getPetAttr());
	
		string optionString="";
		string MixoptionString="";
		optionString = pClassInfo->getIndexName();
		cout << " Mix OptionClassName : " << optionString << endl;
		
		//재료 펫의 레벨에 따른 기본수치 지정 ksym555 20090526
		if(iMaterialPetLevel <= 19)iDefaultValue=1;
		if(iMaterialPetLevel >= 20 && iMaterialPetLevel <= 29)iDefaultValue=3;
		if(iMaterialPetLevel >= 30 && iMaterialPetLevel <= 39)iDefaultValue=5;
			
		int iRandomValue = random()%((19-(iMaterialPetLevel%10) + 9-(iMaterialPetLevel%10))*1000);
		
		cout << " 재료펫에 의한 기본값 : " << iDefaultValue << endl;	
		cout << " 재료펫에 의한 랜덤값 : " << iRandomValue << endl;
		
		if(iRandomValue <= 49)iRV=5;
		if(iRandomValue >= 50 && iRandomValue <= 549)iRV=4;
		if(iRandomValue >= 550 && iRandomValue <= 3999)iRV=3;
		if(iRandomValue >= 4000 && iRandomValue <= 9999)iRV=2;
		if(iRandomValue >= 10000 && iRandomValue <= 17999)iRV=1;
		if(iRandomValue >= 18000 && iRandomValue <= 27999)iRV=0;
		
		iOptionValue = iDefaultValue + iRV;
		
		cout << " 최종 부여 수치 : " << iOptionValue << endl;
		
		char buf[128];
		sprintf(buf, "%d", iOptionValue);
		
		optionString = optionString + "+" + buf;
		cout << optionString << endl;
		
//		OptionType_t optionType;
//		optionType = g_pOptionInfoManager->getOptionType(optionString);
		
		OptionInfo* pOptionInfo = NULL;
		pOptionInfo = g_pOptionInfoManager->getOptionInfo( optionString );
		
		if(pOptionInfo == NULL)
		{
			gcVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_PET_MIXING_FAIL );
			pPlayer->sendPacket( &gcVerify );
					
			cout << " 세상의 중심에서 옵션을 외치다! " << endl;
			sendCannotUse( pPacket, pPlayer );		
			return;
		}
		
		cout << pOptionInfo->getType() << endl;
		
		list<OptionType_t> options;
		options.push_back( pOptionInfo->getType() );
		
		pPetItem1->getPetInfo()->setMixOptionType( options );
	
		string optionField="";
		setOptionTypeToField( pPetItem1->getPetInfo()->getMixOptionType(), optionField );
			
		char pField[80];
		sprintf(pField, "MixOptionType='%s'", optionField.c_str());
		pPetItem1->tinysave(pField);
		
		GCPetInfo gcPetInfo;
		gcPetInfo.setPetInfo( pPetItem1->getPetInfo() );
		gcPetInfo.setSummonInfo( 0 );
		gcPetInfo.setObjectID( pPC->getObjectID() );
		pGamePlayer->sendPacket( &gcPetInfo );
		
		pPC->initAllStatAndSend();		
			
		executePetMixLog(pPlayer, pPetItem1, pPetItem2, optionField );
	}
	
	//재료 펫 아이템을 지우자 20090527 ksym555
	pInventory->deleteItem( pPetItem2->getObjectID() );
	pPetItem2->whenPCLost ( pPC );
	
	pPetItem2->destroy();
	SAFE_DELETE( pPetItem2 );
	
	//펫 조합기를 지우자 20090527 ksym555
	if ( isStackable(pItem) )
	{
		decreaseItemNum( pItem, pInventory, pCreature->getName(), STORAGE_INVENTORY, 0, InvenX, InvenY);
	}
	else 
	{
		pInventory->deleteItem( pItem->getObjectID() );
		pItem->destroy();
		SAFE_DELETE( pItem );
	}
	
	gcVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_PET_MIXING_OK );
	pPlayer->sendPacket( &gcVerify );
	
	GCUseOK gcUseOK;
	pPlayer->sendPacket(&gcUseOK);
	

	__END_CATCH
}

void CGMixItemHandler::executePetDetach(CGMixItem* pPacket, Player* pPlayer, Item* pItem) throw(Error)
{
	__BEGIN_TRY

	Assert(pPacket != NULL);
	Assert(pPlayer != NULL);

	GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(pPlayer);
	Assert(pGamePlayer != NULL);

	Creature* pCreature = pGamePlayer->getCreature();
	Assert(pCreature != NULL);
	Assert(pCreature->isPC());

	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
	Assert(pPC != NULL);

	Inventory* pInventory = pPC->getInventory();
	Zone*      pZone      = pPC->getZone();
	
	CoordInven_t InvenX = pPacket->getX();
	CoordInven_t InvenY = pPacket->getY();

	Assert(pInventory != NULL);
	Assert(pZone != NULL);

	PetItem* pPetItem = NULL;
	GCAddItemToItemVerify gcVerify;
	CoordInven_t dummy;
	
	pPetItem = dynamic_cast<PetItem*>(pInventory->findItemOID( pPacket->getTargetObjectID(0), dummy, dummy ));


	if ( pPetItem == NULL ||
			(int)pPetItem->getPetInfo()->getPetLevel() != 50 ||
			pPetItem->getItemClass() != Item::ITEM_CLASS_PET_ITEM		
	)
	{
		gcVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_DETACHING_OK );
		pPlayer->sendPacket( &gcVerify );
				
		sendCannotUse( pPacket, pPlayer );
		return;
	}

	
	list<OptionType_t> oList = pPetItem->getPetInfo()->getMixOptionType();

	// 이제 옵션을 없애버린다.
	oList.clear();
	pPetItem->getPetInfo()->setMixOptionType( oList );

	// 옵션이 없다고 DB에 저장한다
	pPetItem->tinysave( "MixOptionType=''" );

	pPetItem->setTraceItem( bTraceLog( pPetItem ) );

	Assert( pItem == pPC->getExtraInventorySlotItem() );

	pPC->deleteItemFromExtraInventorySlot();
	if ( pItem->isTraceItem() )
	{
		remainTraceLog( pItem, pPC->getName(), "펫 조합 제거기", ITEM_LOG_DELETE, DETAIL_ENCHANT );
	}
	
	pItem->destroy();
	SAFE_DELETE( pItem );
	
	GCPetInfo gcPetInfo;
	gcPetInfo.setPetInfo( pPetItem->getPetInfo() );
	gcPetInfo.setSummonInfo( 0 );
	gcPetInfo.setObjectID( pPC->getObjectID() );
	pGamePlayer->sendPacket( &gcPetInfo );
			
	pPC->initAllStatAndSend();
	

	gcVerify.setCode( ADD_ITEM_TO_ITEM_VERIFY_DETACHING_OK );
	pPlayer->sendPacket( &gcVerify );

	GCUseOK gcUseOK;
	pPlayer->sendPacket(&gcUseOK);

	__END_CATCH
}

void sendCannotUse(CGMixItem* pPacket, Player* pPlayer)
{
	GCCannotUse _GCCannotUse;
	_GCCannotUse.setObjectID(pPacket->getObjectID());
	pPlayer->sendPacket(&_GCCannotUse);
	return;
}

void CGMixItemHandler::executePetMixLog(Player* pPlayer, PetItem* pPetItem1, PetItem* pPetItem2, const string& MixOption) throw(Error)
{
	__BEGIN_TRY

	GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(pPlayer);
	Assert(pGamePlayer != NULL);

	Creature* pCreature = pGamePlayer->getCreature();
	Assert(pCreature != NULL);
	Assert(pCreature->isPC());

	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
	Assert(pPC != NULL);

	Statement* pStmt = NULL;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pStmt->executeQuery(
		"INSERT INTO PetMixingLog (OwnerID, ReportTime, TargetItemID, TargetItemType, TargetMixOptionType, "
		" materialItemID, materialItemType, PetLevel, PetAttr, PetAttrLevel, PetOption, PetOption2)"
		" VALUES('%s', now(), %d, %d,'%s', %d, %d, %d, %d, %d, %d, %d)",
															
		pPC->getName().c_str(),
		(int)pPetItem1->getItemID(),		
		(int)pPetItem1->getItemType(),
		MixOption.c_str(),
		(int)pPetItem2->getItemID(),
		(int)pPetItem2->getItemType(),
		(int)pPetItem2->getPetInfo()->getPetLevel(),
		(int)pPetItem2->getPetInfo()->getPetAttr(),
		(int)pPetItem2->getPetInfo()->getPetAttrLevel(),
		(int)pPetItem2->getPetInfo()->getPetOption(),
		(int)pPetItem2->getPetInfo()->getPetOption2()	
		);
		SAFE_DELETE( pStmt );
	}
	END_DB(pStmt);
			
	__END_CATCH	
}
#endif


