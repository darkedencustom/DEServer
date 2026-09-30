#----------------------------------------------------------------------
#
# Filename    : Makefile
# Written By  : Reiot
# Description :
#
#----------------------------------------------------------------------

#----------------------------------------------------------------------
# Directories Setting
#----------------------------------------------------------------------
VSHOME   = ../../../..
BINDIR   = $(VSHOME)/bin
LIBDIR   = $(VSHOME)/lib
LOGDIR   = $(VSHOME)/log
SRCDIR   = ../../..
COREDIR  = ../../../Core
SERVDIR  = ../..
DBDIR    = ../../database
MYSQLDIR = /usr/lib/x86_64-linux-gnu
GSDIR    = ..
SKILLDIR = ../skill
ITEMDIR  = ../item
WARDIR  = ../war
#SIMPLEQUESTDIR  = ./Squest
#LUASCRIPTDIR  = ./luaScript


#----------------------------------------------------------------------
# General Rules
#----------------------------------------------------------------------
.SUFFIXES    : .cpp .o

CC       = g++
DEFS     = -D__LINUX__ -D_REENTRANT -D__GAME_SERVER__
INCLUDES = -I$(COREDIR)/compat -I$(COREDIR) -I$(SERVDIR) -I$(DBDIR) -I$(GSDIR) -I$(SKILLDIR) -I$(ITEMDIR) -I$(WARDIR) -I$(LUASCRIPTDIR) -I.
CCFLAGS  = -Wall -c -g -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
#CCFLAGS  = -Wall -c -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
.cpp.o :
	$(CC) $(CCFLAGS) $(DEFS) $(INCLUDES) $<

#----------------------------------------------------------------------
# Objects
#----------------------------------------------------------------------

QUEST_OBJS = Trigger.o TriggerManager.o PropertyBuffer.o VariableBuffer.o VariableInfo.o TriggerParser.o

CONDITION_OBJS = \
	ConditionFactoryManager.o \
	ConditionEveryTime.o \
	ConditionAnsweredBy.o \
	ConditionFlagOn.o \
	ConditionFlagOff.o \
	ConditionAttrComp.o \
	ConditionRaceComp.o \
	ConditionSameClan.o \
	ConditionPayPlay.o \
	ConditionEnterMasterLair.o \
	ConditionEnterCastle.o \
	ConditionEnterHolyLand.o \
ConditionEnterCastleDungeon.o \
	ConditionHasQuest.o \
	ConditionHasInvenSpace.o \
	ConditionCanEnterPayZone.o \
	ConditionCanEnterBeginnerZone.o \
	ConditionCanWarpGate.o \
	ConditionCanEnterLevelWarZone.o \
	ConditionCanPetQuest.o \
	ConditionCanEnterEventZone.o \
	ConditionEffectFlag.o \
	ConditionCanEnterGDRLair.o \
	ConditionExistReinforce.o \
	ConditionSiegeDefenderSide.o \
	ConditionSiegeAttackerSide.o \
	ConditionNotGuildMember.o \
	ConditionIsGuildMember.o \
	ConditionCanEnterQuestZone.o \
	ConditionHasEnoughFamilyCoin.o \
	ConditionEnterMikllizzLair.o \
	ConditionEnterHellGardenTower.o \
	ConditionTalkedBy.o

ACTION_OBJS = \
	ActionFactoryManager.o \
	ActionSetPosition.o \
	ActionWander.o \
	ActionSay.o \
	ActionRandomSay.o \
	ActionAsk.o \
	ActionQuitDialogue.o \
	ActionPrepareShop.o \
	ActionSell.o \
	ActionBuy.o \
	ActionRegenShop.o \
	ActionTeachSkill.o \
	ActionHeal.o \
	ActionRedeemMotorcycle.o \
	ActionSearchMotorcycle.o \
	ActionRepair.o \
	ActionStashSell.o \
	ActionStashOpen.o \
	ActionRestore.o \
	ActionSetResurrectZone.o \
	ActionSilverCoating.o \
	ActionCreateGuild.o \
	ActionDestroyGuild.o \
	ActionTutorial.o \
	ActionGiveNewbieItem.o \
	ActionActivatePortal.o \
	ActionTurnOnFlag.o \
	ActionTurnOffFlag.o \
	ActionSystemMessage.o \
	ActionTakeDonation.o \
	ActionCallHelicopter.o \
	ActionRegenEventShop.o \
	ActionAskDynamic.o \
	ActionSayDynamic.o \
	ActionGiveSpecialEventItem.o \
	ActionRedistributeAttr.o \
	ActionTradeEventItem.o \
	ActionTradeLairItem.o \
	ActionShowGuildDialog.o \
	ActionSimpleQuestList.o \
	ActionSimpleQuestComplete.o \
	ActionSimpleQuestRegen.o \
	ActionEnterCastleWithFee.o \
	ActionShowTaxBalance.o \
	ActionAskVariable.o \
	ActionWarRegistration.o \
	ActionShowWarSchedule.o \
	ActionJoinRaceWar.o \
	ActionInitPartnerWaitingManager.o \
	ActionWaitForMeetCouple.o \
	ActionWaitForApartCouple.o \
	ActionAcceptCoupleRequest.o \
	ActionAcceptApartCouple.o \
	ActionForceApartCouple.o \
	ActionEnterPKZone.o \
	ActionWarpToResurrectPosition.o \
	ActionSelectQuest.o \
	ActionQuestReward.o \
	ActionWarpToNoviceZone.o \
	ActionCancelQuest.o \
	ActionInitSimpleQuest.o \
	ActionWanderZone.o \
	ActionInitEventQuest.o \
	ActionAskByQuestLevel.o \
	ActionGiveEventQuest.o \
	ActionAdvanceEventQuest.o \
	ActionCancelEventQuestScript.o \
	ActionRewardEventQuest.o \
	ActionGiveLotto.o \
	ActionGiveEventQuestScript.o \
	ActionStartEventQuest.o \
	ActionWarpInZone.o \
	ActionEventMeet.o \
	ActionGiveFinalLottoScript.o \
	ActionGiveQuestItem.o \
	ActionTakeOutGoods.o \
	ActionClearRankBonus.o \
	ActionContractGnomesHorn.o \
	ActionDownSkill.o \
	ActionMiniGame.o \
	ActionGiveItem.o \
	ActionActivateMazeExit.o \
	ActionActivateMazeEnter.o \
	ActionActivateMazeReturn.o \
	ActionSystemMessagePerRace.o \
	ActionWarpLevelWarZone.o \
	ActionCheckPartnerName.o \
	ActionStartPetQuest.o \
	ActionPetWithdraw.o \
	ActionPetDeposit.o \
	ActionEnterEventZone.o \
	ActionEnterGDRLair.o \
	ActionTradeGQuestEventItem.o \
	ActionRegisterSiege.o \
	ActionRegisterReinforce.o \
	ActionAcceptReinforce.o \
	ActionDenyReinforce.o \
	ActionEnterSiege.o \
	ActionRecallSiege.o \
	ActionSelectBloodBible.o \
	ActionClearBloodBible.o \
	ActionModifyTaxRatio.o \
	ActionSwapAdvancementItem.o \
	ActionShowDonationDialog.o \
	ActionEnterQuestZone.o \
	ActionShowConfirmGetEventItemDialog.o \
	ActionGiveCommonEventItem.o \
	ActionGiveCommonQuestItem.o \
	ActionCheckCommonQuestItem.o \
	ActionResetAttribute.o \
	ActionCheckEventLevelUp200604.o \
	ActionGiveEventLevelUp200604.o \
	ActionGiveComebackEventItem200604.o \
	ActionCheckComebackEventItem200604.o \
	ActionRedistributeAttr50.o \
	ActionChangePlayerColor.o \
	ActionExchangeOfMoney.o \
	ActionSoccerEvent200606.o \
	ActionTradeSealingStone.o \
	ActionEnterCastleB2F.o \
	ActionEnterSurvivalZone.o \
	ActionGambleSystem.o \
	ActionCheckGlutinousRiceKneading.o \
	ActionGiveEventBoxItem.o \
	ActionTradeMysteryPotion.o \
	ActionTradeLeather.o \
	ActionGiveHellGardenCrossItem.o \
	ActionGiveHellGardenSeedItem.o \
	ActionEnterHellGarden.o \
	ActionAttendCheck.o \
	ActionEnterMenegroth.o \
	ActionGiveContributeReward.o \
	ActionInsertCabracamHeart.o \
	ActionCheckLevelWarReward.o \
	ActionGiveCrashingReward.o \
	ActionInitInstanceDoungeon.o \
	ActionBlitzRegister.o \
	ActionBlitzReward.o \
	ActionMapleRegister.o \
	ActionMapleReward.o \
	ActionEnterPVPSystem.o \
	ActionPVPSystemSignUp.o \
	ActionMonsterSummon.o \
	ActionEnterWithItem.o ActionTakeMihnea.o ActionPlaceMihnea.o
#	ActionTradeGiftBox.o
#	ActionGiveTestServerReward.o
#	ActionGiveEventItem.o
#	ActionGiveAccountEventItem.o
              
OBJS = $(QUEST_OBJS) $(CONDITION_OBJS) $(ACTION_OBJS)

SRCS = $(OBJS:.o=.cpp)

TARGET   = $(LIBDIR)/libQuest.a


#----------------------------------------------------------------------
# actions
#----------------------------------------------------------------------
all :
#	$(MAKE) -C luaScript 
	$(MAKE) $(TARGET)
#$(MAKE) -C Squest

$(TARGET) : $(OBJS)
	ar rc $@ $^

clean :
	rm -rf *.o
#	$(MAKE) -C luaScript clean
#	$(MAKE) -C Squest clean

cleanall :
	rm -rf *.o $(TARGET)
#	$(MAKE) -C luaScript cleanall
#	$(MAKE) -C Squest cleanll

depall :
	gccmakedep $(SRCS) $(INCLUDES)
#	$(MAKE) -C luaScript depall
#	$(MAKE) -C Squest depall

dep :
	gccmakedep $(SRCS) $(INCLUDES)

# DO NOT DELETE
Trigger.o: Trigger.cpp Trigger.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Condition.h PropertyBuffer.h ConditionFactoryManager.h \
  ConditionFactory.h Action.h ActionFactoryManager.h ActionFactory.h \
  $(COREDIR)/Assert.h
TriggerManager.o: TriggerManager.cpp TriggerManager.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Trigger.h Condition.h PropertyBuffer.h $(COREDIR)/Assert.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
  TriggerParser.h $(COREDIR)/SXml.h $(COREDIR)/Properties.h \
  $(GSDIR)/ScriptManager.h $(GSDIR)/Script.h
PropertyBuffer.o: PropertyBuffer.cpp PropertyBuffer.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h
VariableBuffer.o: VariableBuffer.cpp VariableBuffer.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  VariableInfo.h
VariableInfo.o: VariableInfo.cpp VariableInfo.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h
TriggerParser.o: TriggerParser.cpp TriggerParser.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/SXml.h $(COREDIR)/Assert.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(GSDIR)/ScriptManager.h $(GSDIR)/Script.h
ConditionFactoryManager.o: ConditionFactoryManager.cpp \
  $(COREDIR)/Assert.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  ConditionFactoryManager.h Condition.h PropertyBuffer.h \
  ConditionFactory.h ConditionAnsweredBy.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h ConditionAtFirst.h ConditionTalkedBy.h \
  ConditionIdle.h ConditionEveryTime.h ConditionFlagOn.h \
  ConditionFlagOff.h ConditionAttrComp.h ConditionRaceComp.h \
  ConditionSameClan.h ConditionPayPlay.h ConditionEnterMasterLair.h \
  ConditionEnterCastle.h ConditionEnterHolyLand.h \
  ConditionEnterCastleDungeon.h ConditionHasQuest.h \
  ConditionHasInvenSpace.h ConditionCanEnterPayZone.h \
  ConditionCanEnterBeginnerZone.h ConditionCanWarpGate.h \
  ConditionCanEnterLevelWarZone.h ConditionCanPetQuest.h \
  ConditionCanEnterEventZone.h ConditionEffectFlag.h \
  ConditionCanEnterGDRLair.h ConditionExistReinforce.h \
  ConditionSiegeDefenderSide.h ConditionSiegeAttackerSide.h \
  ConditionNotGuildMember.h ConditionIsGuildMember.h \
  ConditionCanEnterQuestZone.h ConditionHasEnoughFamilyCoin.h \
  ConditionEnterMikllizzLair.h ConditionEnterHellGardenTower.h
ConditionEveryTime.o: ConditionEveryTime.cpp ConditionEveryTime.h \
  Condition.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h PropertyBuffer.h \
  ConditionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h
ConditionAnsweredBy.o: ConditionAnsweredBy.cpp ConditionAnsweredBy.h \
  Condition.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h PropertyBuffer.h \
  ConditionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h
ConditionFlagOn.o: ConditionFlagOn.cpp ConditionFlagOn.h Condition.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h PropertyBuffer.h \
  ConditionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Item.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/FlagSet.h
ConditionFlagOff.o: ConditionFlagOff.cpp ConditionFlagOff.h Condition.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h PropertyBuffer.h \
  ConditionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Item.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/FlagSet.h
ConditionAttrComp.o: ConditionAttrComp.cpp ConditionAttrComp.h \
  Condition.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h PropertyBuffer.h \
  ConditionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h $(GSDIR)/Garbage.h \
  $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h $(GSDIR)/Sector.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h
ConditionRaceComp.o: ConditionRaceComp.cpp ConditionRaceComp.h \
  Condition.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h PropertyBuffer.h \
  ConditionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h
ConditionSameClan.o: ConditionSameClan.cpp ConditionSameClan.h \
  Condition.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h PropertyBuffer.h \
  ConditionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Item.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/FlagSet.h
ConditionPayPlay.o: ConditionPayPlay.cpp ConditionPayPlay.h Condition.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h PropertyBuffer.h \
  ConditionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Item.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/FlagSet.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/PacketUtil.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h
ConditionEnterMasterLair.o: ConditionEnterMasterLair.cpp \
  ConditionEnterMasterLair.h Condition.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  PropertyBuffer.h ConditionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Item.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/FlagSet.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/MasterLairManager.h $(GSDIR)/MonsterCounter.h \
  $(GSDIR)/DynamicZoneScript.h $(GSDIR)/DynamicZone.h $(GSDIR)/Monster.h \
  $(GSDIR)/MonsterInfo.h $(GSDIR)/MonsterSummonInfo.h \
  $(GSDIR)/MonsterInfoTypes.h $(GSDIR)/Treasure.h \
  $(GSDIR)/PrecedenceTable.h $(GSDIR)/DynamicZoneGroup.h \
  $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/PacketUtil.h \
  $(GSDIR)/ZoneInfoManager.h $(GSDIR)/ZoneInfo.h \
  $(GSDIR)/ZoneGroupManager.h $(GSDIR)/ZoneGroup.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h $(GSDIR)/ZoneUtil.h $(GSDIR)/VariableManager.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h
ConditionEnterCastle.o: ConditionEnterCastle.cpp ConditionEnterCastle.h \
  Condition.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h PropertyBuffer.h \
  ConditionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Item.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/FlagSet.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/PacketUtil.h \
  $(GSDIR)/ZoneInfoManager.h $(GSDIR)/ZoneInfo.h \
  $(GSDIR)/ZoneGroupManager.h $(GSDIR)/ZoneGroup.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h $(GSDIR)/ZoneUtil.h $(GSDIR)/VariableManager.h \
  $(GSDIR)/CastleInfoManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
  $(WARDIR)/WarSystem.h $(WARDIR)/Scheduler.h $(WARDIR)/Work.h \
  $(WARDIR)/Schedule.h $(COREDIR)/Gpackets/GCWarList.h \
  $(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
  $(COREDIR)/RaceWarInfo.h
ConditionEnterHolyLand.o: ConditionEnterHolyLand.cpp \
  ConditionEnterHolyLand.h Condition.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  PropertyBuffer.h ConditionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Item.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/FlagSet.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(SERVDIR)/PaySystem.h \
  $(WARDIR)/WarSystem.h $(WARDIR)/Scheduler.h $(WARDIR)/Work.h \
  $(WARDIR)/Schedule.h $(COREDIR)/Gpackets/GCWarList.h \
  $(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
  $(COREDIR)/RaceWarInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/PacketUtil.h \
  $(GSDIR)/ZoneInfoManager.h $(GSDIR)/ZoneInfo.h \
  $(GSDIR)/ZoneGroupManager.h $(GSDIR)/ZoneGroup.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h $(GSDIR)/ZoneUtil.h $(GSDIR)/VariableManager.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h
ConditionEnterCastleDungeon.o: ConditionEnterCastleDungeon.cpp \
  ConditionEnterCastleDungeon.h Condition.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  PropertyBuffer.h ConditionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Item.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/FlagSet.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(SERVDIR)/PaySystem.h \
  $(WARDIR)/WarSystem.h $(WARDIR)/Scheduler.h $(WARDIR)/Work.h \
  $(WARDIR)/Schedule.h $(COREDIR)/Gpackets/GCWarList.h \
  $(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
  $(COREDIR)/RaceWarInfo.h $(GSDIR)/PacketUtil.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/CastleInfoManager.h \
  $(GSDIR)/VariableManager.h
ConditionHasQuest.o: ConditionHasQuest.cpp ConditionHasQuest.h \
  Condition.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h PropertyBuffer.h \
  ConditionFactory.h $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/mission/QuestManager.h \
  $(GSDIR)/mission/QuestInfo.h $(GSDIR)/mission/RewardClass.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(GSDIR)/mission/QuestStatus.h
ConditionHasInvenSpace.o: ConditionHasInvenSpace.cpp \
  ConditionHasInvenSpace.h Condition.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  PropertyBuffer.h ConditionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Item.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/FlagSet.h
ConditionCanEnterPayZone.o: ConditionCanEnterPayZone.cpp \
  ConditionCanEnterPayZone.h Condition.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  PropertyBuffer.h ConditionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Item.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/FlagSet.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/PacketUtil.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h
ConditionCanEnterBeginnerZone.o: ConditionCanEnterBeginnerZone.cpp \
  ConditionCanEnterBeginnerZone.h Condition.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  PropertyBuffer.h ConditionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/Item.h
ConditionCanWarpGate.o: ConditionCanWarpGate.cpp ConditionCanWarpGate.h \
  Condition.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h PropertyBuffer.h \
  ConditionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/Item.h
ConditionCanEnterLevelWarZone.o: ConditionCanEnterLevelWarZone.cpp \
  ConditionCanEnterLevelWarZone.h Condition.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  PropertyBuffer.h ConditionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/Item.h $(GSDIR)/LevelWarZoneInfoManager.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/VariableManager.h
ConditionCanPetQuest.o: ConditionCanPetQuest.cpp ConditionCanPetQuest.h \
  Condition.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h PropertyBuffer.h \
  ConditionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/Item.h $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h $(GSDIR)/Sector.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
  $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
  $(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(GSDIR)/Vampire.h $(COREDIR)/PCVampireInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(SKILLDIR)/VampireSkillSlot.h $(GSDIR)/Ousters.h \
  $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
  $(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
  $(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h
ConditionCanEnterEventZone.o: ConditionCanEnterEventZone.cpp \
  ConditionCanEnterEventZone.h Condition.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  PropertyBuffer.h ConditionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/Item.h $(GSDIR)/EventZoneInfo.h
ConditionEffectFlag.o: ConditionEffectFlag.cpp ConditionEffectFlag.h \
  Condition.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h PropertyBuffer.h \
  ConditionFactory.h $(GSDIR)/Effect.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(SERVDIR)/Timeval.h $(GSDIR)/Creature.h \
  $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/FlagSet.h
ConditionCanEnterGDRLair.o: ConditionCanEnterGDRLair.cpp \
  ConditionCanEnterGDRLair.h Condition.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  PropertyBuffer.h ConditionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/GDRLairManager.h \
  $(GSDIR)/FiniteStateMachine.h $(COREDIR)/VSDateTime.h \
  $(GSDIR)/GDRLairAbstractStates.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Player.h $(GSDIR)/StringPool.h
ConditionExistReinforce.o: ConditionExistReinforce.cpp \
  ConditionExistReinforce.h Condition.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  PropertyBuffer.h ConditionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ZoneUtil.h \
  $(COREDIR)/VSDateTime.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(WARDIR)/WarScheduler.h $(WARDIR)/Work.h \
  $(WARDIR)/Scheduler.h $(WARDIR)/Schedule.h $(WARDIR)/War.h \
  $(WARDIR)/WarSchedule.h $(WARDIR)/SiegeWar.h $(GSDIR)/GuildManager.h \
  $(GSDIR)/Guild.h
ConditionSiegeDefenderSide.o: ConditionSiegeDefenderSide.cpp \
  ConditionSiegeDefenderSide.h Condition.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  PropertyBuffer.h ConditionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/GDRLairManager.h \
  $(GSDIR)/FiniteStateMachine.h $(COREDIR)/VSDateTime.h \
  $(GSDIR)/GDRLairAbstractStates.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Player.h
ConditionSiegeAttackerSide.o: ConditionSiegeAttackerSide.cpp \
  ConditionSiegeAttackerSide.h Condition.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  PropertyBuffer.h ConditionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/GDRLairManager.h \
  $(GSDIR)/FiniteStateMachine.h $(COREDIR)/VSDateTime.h \
  $(GSDIR)/GDRLairAbstractStates.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Player.h
ConditionNotGuildMember.o: ConditionNotGuildMember.cpp \
  ConditionNotGuildMember.h Condition.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  PropertyBuffer.h ConditionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Item.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h
ConditionIsGuildMember.o: ConditionIsGuildMember.cpp \
  ConditionIsGuildMember.h Condition.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  PropertyBuffer.h ConditionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Item.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h
ConditionCanEnterQuestZone.o: ConditionCanEnterQuestZone.cpp \
  ConditionCanEnterQuestZone.h Condition.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  PropertyBuffer.h ConditionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Item.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GQuestManager.h \
  $(GSDIR)/GQuestInventory.h $(COREDIR)/Gpackets/GCGQuestInventory.h \
  $(GSDIR)/DynamicZoneInfo.h $(GSDIR)/DynamicZoneManager.h \
  $(GSDIR)/DynamicZoneGroup.h
ConditionHasEnoughFamilyCoin.o: ConditionHasEnoughFamilyCoin.cpp \
  ConditionHasEnoughFamilyCoin.h Condition.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  PropertyBuffer.h ConditionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Item.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/FlagSet.h
ConditionEnterMikllizzLair.o: ConditionEnterMikllizzLair.cpp \
  ConditionEnterMikllizzLair.h Condition.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  PropertyBuffer.h ConditionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Item.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/FlagSet.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/MikllizzLairManager.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/PacketUtil.h \
  $(GSDIR)/ZoneInfoManager.h $(GSDIR)/ZoneInfo.h \
  $(GSDIR)/ZoneGroupManager.h $(GSDIR)/ZoneGroup.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h $(GSDIR)/ZoneUtil.h $(GSDIR)/VariableManager.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h
ConditionEnterHellGardenTower.o: ConditionEnterHellGardenTower.cpp \
  ConditionEnterHellGardenTower.h Condition.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  PropertyBuffer.h ConditionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Item.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/FlagSet.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/HellGardenTowerManager.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/PacketUtil.h \
  $(GSDIR)/ZoneInfoManager.h $(GSDIR)/ZoneInfo.h \
  $(GSDIR)/ZoneGroupManager.h $(GSDIR)/ZoneGroup.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h $(GSDIR)/ZoneUtil.h $(GSDIR)/VariableManager.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h
ConditionTalkedBy.o: ConditionTalkedBy.cpp ConditionTalkedBy.h \
  Condition.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h PropertyBuffer.h \
  ConditionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h
ActionFactoryManager.o: ActionFactoryManager.cpp $(COREDIR)/Assert.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  ActionFactoryManager.h Action.h PropertyBuffer.h ActionFactory.h \
  ActionSetPosition.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h ActionWander.h ActionSay.h \
  ActionRandomSay.h ActionAsk.h ActionQuitDialogue.h ActionPrepareShop.h \
  ActionSell.h ActionBuy.h ActionRegenShop.h ActionTeachSkill.h \
  ActionHeal.h ActionRedeemMotorcycle.h ActionSearchMotorcycle.h \
  $(GSDIR)/Item.h ActionRepair.h ActionStashSell.h ActionStashOpen.h \
  ActionRestore.h ActionSetResurrectZone.h ActionSilverCoating.h \
  ActionCreateGuild.h ActionDestroyGuild.h ActionTutorial.h \
  ActionGiveNewbieItem.h ActionActivatePortal.h ActionTurnOnFlag.h \
  ActionTurnOffFlag.h ActionSystemMessage.h ActionSystemMessagePerRace.h \
  ActionTakeDonation.h ActionCallHelicopter.h ActionRegenEventShop.h \
  ActionAskDynamic.h ActionSayDynamic.h ActionGiveSpecialEventItem.h \
  ActionRedistributeAttr.h ActionTradeEventItem.h ActionTradeLairItem.h \
  ActionShowGuildDialog.h ActionSimpleQuestList.h \
  ActionSimpleQuestComplete.h ActionSimpleQuestRegen.h \
  ActionEnterCastleWithFee.h ActionShowTaxBalance.h ActionAskVariable.h \
  ActionWarRegistration.h ActionShowWarSchedule.h ActionJoinRaceWar.h \
  ActionInitPartnerWaitingManager.h ActionWaitForMeetCouple.h \
  ActionWaitForApartCouple.h ActionAcceptCoupleRequest.h \
  ActionAcceptApartCouple.h ActionForceApartCouple.h ActionEnterPKZone.h \
  ActionWarpToResurrectPosition.h ActionSelectQuest.h \
  ActionQuestReward.h ActionWarpToNoviceZone.h ActionCancelQuest.h \
  ActionInitSimpleQuest.h ActionWanderZone.h ActionInitEventQuest.h \
  ActionAskByQuestLevel.h ActionGiveEventQuest.h \
  ActionAdvanceEventQuest.h ActionRewardEventQuest.h \
  ActionCancelEventQuestScript.h ActionGiveLotto.h \
  ActionGiveEventQuestScript.h ActionStartEventQuest.h \
  ActionWarpInZone.h ActionEventMeet.h ActionGiveFinalLottoScript.h \
  ActionGiveQuestItem.h ActionTakeOutGoods.h ActionClearRankBonus.h \
  ActionContractGnomesHorn.h ActionDownSkill.h ActionMiniGame.h \
  ActionGiveItem.h ActionActivateMazeExit.h ActionActivateMazeEnter.h \
  ActionActivateMazeReturn.h ActionWarpLevelWarZone.h \
  ActionCheckPartnerName.h ActionStartPetQuest.h ActionPetDeposit.h \
  ActionPetWithdraw.h ActionEnterEventZone.h ActionEnterGDRLair.h \
  ActionTradeGQuestEventItem.h ActionRegisterSiege.h \
  ActionRegisterReinforce.h ActionAcceptReinforce.h \
  ActionDenyReinforce.h ActionEnterSiege.h ActionRecallSiege.h \
  ActionSelectBloodBible.h ActionClearBloodBible.h \
  ActionModifyTaxRatio.h ActionSwapAdvancementItem.h \
  ActionShowDonationDialog.h ActionEnterQuestZone.h \
  ActionShowConfirmGetEventItemDialog.h ActionGiveCommonEventItem.h \
  ActionGiveCommonQuestItem.h ActionCheckCommonQuestItem.h \
  ActionResetAttribute.h ActionCheckEventLevelUp200604.h \
  ActionGiveEventLevelUp200604.h ActionGiveComebackEventItem200604.h \
  ActionCheckComebackEventItem200604.h ActionRedistributeAttr50.h \
  ActionChangePlayerColor.h ActionExchangeOfMoney.h \
  ActionSoccerEvent200606.h ActionTradeSealingStone.h \
  ActionEnterCastleB2F.h ActionEnterSurvivalZone.h ActionGambleSystem.h \
  ActionCheckGlutinousRiceKneading.h ActionGiveEventBoxItem.h \
  ActionTradeMysteryPotion.h ActionTradeLeather.h \
  ActionGiveHellGardenCrossItem.h ActionGiveHellGardenSeedItem.h \
  ActionEnterHellGarden.h ActionAttendCheck.h \
  ActionGiveContributeReward.h ActionCheckLevelWarReward.h \
  ActionEnterMenegroth.h ActionInsertCabracamHeart.h \
  ActionGiveCrashingReward.h ActionInitInstanceDoungeon.h \
  ActionBlitzRegister.h ActionBlitzReward.h ActionMapleRegister.h \
  ActionMapleReward.h ActionEnterPVPSystem.h ActionPVPSystemSignUp.h
ActionSetPosition.o: ActionSetPosition.cpp ActionSetPosition.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/NPC.h $(GSDIR)/Inventory.h \
  $(GSDIR)/VolumeInfo.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/couple/PartnerWaitingManager.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(COREDIR)/NPCInfo.h
ActionWander.o: ActionWander.cpp ActionWander.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h
ActionSay.o: ActionSay.cpp ActionSay.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/Gpackets/GCNPCSay.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionRandomSay.o: ActionRandomSay.cpp ActionRandomSay.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Script.h $(GSDIR)/ScriptManager.h \
  $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/Gpackets/GCNPCSay.h
ActionAsk.o: ActionAsk.cpp ActionAsk.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/Gpackets/GCNPCAsk.h
ActionQuitDialogue.o: ActionQuitDialogue.cpp ActionQuitDialogue.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/PacketFactory.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
  $(SERVDIR)/Mutex.h $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h \
  $(GSDIR)/Event.h $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(COREDIR)/VSDateTime.h $(GSDIR)/Item.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h
ActionPrepareShop.o: ActionPrepareShop.cpp ActionPrepareShop.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/ShopTemplate.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SERVDIR)/LogClient.h \
  $(GSDIR)/ItemFactoryManager.h $(GSDIR)/ItemFactory.h
ActionSell.o: ActionSell.cpp ActionSell.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/couple/PartnerWaitingManager.h $(GSDIR)/Script.h Trigger.h \
  $(COREDIR)/Gpackets/GCShopVersion.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h
ActionBuy.o: ActionBuy.cpp ActionBuy.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCShopMarketCondition.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h
ActionRegenShop.o: ActionRegenShop.cpp ActionRegenShop.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(SERVDIR)/Timeval.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/ShopTemplate.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SERVDIR)/LogClient.h \
  $(GSDIR)/ItemFactoryManager.h $(GSDIR)/ItemFactory.h
ActionTeachSkill.o: ActionTeachSkill.cpp ActionTeachSkill.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/Slayer.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/SlayerSkillSlot.h \
  $(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(GSDIR)/Vampire.h $(COREDIR)/PCVampireInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(SKILLDIR)/VampireSkillSlot.h $(GSDIR)/SkillInfo.h \
  $(COREDIR)/Gpackets/GCTeachSkillInfo.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionHeal.o: ActionHeal.cpp ActionHeal.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h $(GSDIR)/Garbage.h \
  $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(SERVDIR)/LogClient.h \
  $(COREDIR)/Gpackets/GCRemoveEffect.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCStatusCurrentHP.h $(GSDIR)/EffectAftermath.h \
  $(GSDIR)/EffectLoader.h
ActionRedeemMotorcycle.o: ActionRedeemMotorcycle.cpp \
  ActionRedeemMotorcycle.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
  $(COREDIR)/SocketEncryptInputStream.h $(SERVDIR)/Mutex.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h \
  $(GSDIR)/Item.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h $(GSDIR)/ObjectRegistry.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
  $(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(GSDIR)/Inventory.h \
  $(GSDIR)/VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/SlayerSkillSlot.h \
  $(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(GSDIR)/Vampire.h $(COREDIR)/PCVampireInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(SKILLDIR)/VampireSkillSlot.h $(GSDIR)/ParkingCenter.h \
  $(ITEMDIR)/Motorcycle.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemFactory.h $(ITEMDIR)/Belt.h \
  $(GSDIR)/ConcreteItem.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemPolicies.h $(GSDIR)/ItemFactoryManager.h \
  $(GSDIR)/ItemUtil.h $(ITEMDIR)/Key.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionSearchMotorcycle.o: ActionSearchMotorcycle.cpp \
  ActionSearchMotorcycle.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Creature.h $(GSDIR)/NPC.h \
  $(GSDIR)/Zone.h $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/Slayer.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/SlayerSkillSlot.h \
  $(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(ITEMDIR)/Key.h $(GSDIR)/ItemInfo.h $(GSDIR)/InfoClassManager.h \
  $(GSDIR)/ItemFactory.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCSearchMotorcycleOK.h \
  $(COREDIR)/Gpackets/GCSearchMotorcycleFail.h $(GSDIR)/ParkingCenter.h \
  $(ITEMDIR)/Motorcycle.h $(ITEMDIR)/Belt.h $(GSDIR)/ConcreteItem.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemPolicies.h
ActionRepair.o: ActionRepair.cpp ActionRepair.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
  $(COREDIR)/SocketEncryptInputStream.h $(SERVDIR)/Mutex.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h \
  $(GSDIR)/Item.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionStashSell.o: ActionStashSell.cpp ActionStashSell.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h $(GSDIR)/Garbage.h \
  $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h $(GSDIR)/PriceManager.h \
  $(COREDIR)/Gpackets/GCStashSell.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h
ActionStashOpen.o: ActionStashOpen.cpp ActionStashOpen.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h $(GSDIR)/Garbage.h \
  $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h
ActionRestore.o: ActionRestore.cpp ActionRestore.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(SKILLDIR)/SkillHandlerManager.h \
  $(SKILLDIR)/Skill.h $(SKILLDIR)/SkillHandler.h $(GSDIR)/SkillInfo.h \
  $(GSDIR)/Slayer.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/SlayerSkillSlot.h \
  $(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(GSDIR)/Vampire.h $(COREDIR)/PCVampireInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(SKILLDIR)/VampireSkillSlot.h $(GSDIR)/Ousters.h \
  $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
  $(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
  $(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
  $(GSDIR)/Monster.h $(GSDIR)/MonsterInfo.h $(GSDIR)/MonsterSummonInfo.h \
  $(GSDIR)/MonsterInfoTypes.h $(GSDIR)/Treasure.h \
  $(GSDIR)/PrecedenceTable.h $(SKILLDIR)/HitRoll.h \
  $(SKILLDIR)/SkillUtil.h $(GSDIR)/ZoneUtil.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(SKILLDIR)/Restore.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionSetResurrectZone.o: ActionSetResurrectZone.cpp \
  ActionSetResurrectZone.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h Trigger.h Condition.h \
  $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
  $(SERVDIR)/Mutex.h $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h \
  $(GSDIR)/Event.h $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(COREDIR)/VSDateTime.h $(GSDIR)/Item.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h $(GSDIR)/ObjectRegistry.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
  $(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(GSDIR)/Inventory.h \
  $(GSDIR)/VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/SlayerSkillSlot.h \
  $(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(GSDIR)/Vampire.h $(COREDIR)/PCVampireInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(SKILLDIR)/VampireSkillSlot.h $(GSDIR)/Ousters.h \
  $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
  $(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
  $(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
  $(GSDIR)/StringPool.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
ActionSilverCoating.o: ActionSilverCoating.cpp ActionSilverCoating.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
  $(COREDIR)/SocketEncryptInputStream.h $(SERVDIR)/Mutex.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h \
  $(GSDIR)/Item.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionCreateGuild.o: ActionCreateGuild.cpp ActionCreateGuild.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
  $(COREDIR)/SocketEncryptInputStream.h $(SERVDIR)/Mutex.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h \
  $(GSDIR)/Item.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(GSDIR)/SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h
ActionDestroyGuild.o: ActionDestroyGuild.cpp ActionDestroyGuild.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
  $(COREDIR)/SocketEncryptInputStream.h $(SERVDIR)/Mutex.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h \
  $(GSDIR)/Item.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(GSDIR)/SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h
ActionTutorial.o: ActionTutorial.cpp ActionTutorial.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/PacketFactory.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
  $(SERVDIR)/Mutex.h $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h \
  $(GSDIR)/Event.h $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(COREDIR)/VSDateTime.h $(GSDIR)/Item.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h
ActionGiveNewbieItem.o: ActionGiveNewbieItem.cpp ActionGiveNewbieItem.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/FlagSet.h \
  $(GSDIR)/ItemFactoryManager.h $(GSDIR)/ItemFactory.h \
  $(ITEMDIR)/Magazine.h $(GSDIR)/ItemInfo.h $(GSDIR)/InfoClassManager.h \
  $(COREDIR)/Gpackets/GCCreateItem.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/PacketUtil.h
ActionActivatePortal.o: ActionActivatePortal.cpp ActionActivatePortal.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/Creature.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h \
  $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/ZoneGroup.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/ZoneGroupManager.h $(GSDIR)/ZoneInfo.h \
  $(GSDIR)/ZoneInfoManager.h $(GSDIR)/ZonePlayerManager.h \
  $(SERVDIR)/PlayerManager.h $(COREDIR)/Player.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h \
  $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(SKILLDIR)/VampireSkillSlot.h $(GSDIR)/WeatherManager.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h \
  $(GSDIR)/IncomingPlayerManager.h $(COREDIR)/ServerSocket.h \
  $(COREDIR)/DatagramSocket.h $(GSDIR)/ConnectionInfoManager.h \
  $(GSDIR)/ConnectionInfo.h $(SERVDIR)/LogClient.h $(GSDIR)/PacketUtil.h \
  $(GSDIR)/ZoneUtil.h $(COREDIR)/Properties.h $(GSDIR)/StringPool.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h $(GSDIR)/GQuestManager.h \
  $(GSDIR)/GQuestInventory.h $(COREDIR)/Gpackets/GCGQuestInventory.h \
  $(COREDIR)/Gpackets/GCUpdateInfo.h $(COREDIR)/NPCInfo.h \
  $(COREDIR)/NicknameInfo.h $(COREDIR)/BloodBibleSignInfo.h \
  $(COREDIR)/Gpackets/GCMoveOK.h $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(WARDIR)/WarSystem.h \
  $(WARDIR)/Scheduler.h $(WARDIR)/Work.h $(WARDIR)/Schedule.h \
  $(COREDIR)/Gpackets/GCWarList.h $(COREDIR)/GuildWarInfo.h \
  $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h $(COREDIR)/RaceWarInfo.h
ActionTurnOnFlag.o: ActionTurnOnFlag.cpp ActionTurnOnFlag.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/FlagSet.h
ActionTurnOffFlag.o: ActionTurnOffFlag.cpp ActionTurnOffFlag.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/FlagSet.h
ActionSystemMessage.o: ActionSystemMessage.cpp ActionSystemMessage.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
  $(COREDIR)/SocketEncryptInputStream.h $(SERVDIR)/Mutex.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h \
  $(GSDIR)/Item.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h $(GSDIR)/StringPool.h
ActionTakeDonation.o: ActionTakeDonation.cpp ActionTakeDonation.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/Slayer.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/SlayerSkillSlot.h \
  $(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(GSDIR)/Vampire.h $(COREDIR)/PCVampireInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(SKILLDIR)/VampireSkillSlot.h $(GSDIR)/Ousters.h \
  $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
  $(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
  $(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionCallHelicopter.o: ActionCallHelicopter.cpp ActionCallHelicopter.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/NPC.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Slayer.h $(COREDIR)/PCSlayerInfo.h \
  $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
  $(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
  $(COREDIR)/InventorySlotInfo.h $(GSDIR)/ItemLoaderManager.h \
  $(GSDIR)/ItemLoader.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
  $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
  $(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionRegenEventShop.o: ActionRegenEventShop.cpp ActionRegenEventShop.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(SERVDIR)/Timeval.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/ShopTemplate.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SERVDIR)/LogClient.h \
  $(GSDIR)/ItemFactoryManager.h $(GSDIR)/ItemFactory.h
ActionAskDynamic.o: ActionAskDynamic.cpp ActionAskDynamic.h Action.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h PropertyBuffer.h \
  ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
  $(COREDIR)/SocketEncryptInputStream.h $(SERVDIR)/Mutex.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h \
  $(GSDIR)/Item.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/Script.h $(GSDIR)/ScriptManager.h \
  $(COREDIR)/Gpackets/GCNPCAskDynamic.h
ActionSayDynamic.o: ActionSayDynamic.cpp ActionSayDynamic.h Action.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h PropertyBuffer.h \
  ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
  $(COREDIR)/SocketEncryptInputStream.h $(SERVDIR)/Mutex.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h \
  $(GSDIR)/Item.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/Script.h $(GSDIR)/ScriptManager.h \
  $(COREDIR)/Gpackets/GCNPCSayDynamic.h
ActionGiveSpecialEventItem.o: ActionGiveSpecialEventItem.cpp \
  ActionGiveSpecialEventItem.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/ItemUtil.h \
  $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h \
  $(GSDIR)/ItemFactoryManager.h $(GSDIR)/ItemFactory.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h \
  $(GSDIR)/StringPool.h $(GSDIR)/PacketUtil.h $(ITEMDIR)/Key.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/Gpackets/GCCreateItem.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
ActionRedistributeAttr.o: ActionRedistributeAttr.cpp \
  ActionRedistributeAttr.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Vampire.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/Zone.h $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/PCVampireInfo.h \
  $(COREDIR)/PCInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/InventoryInfo.h \
  $(COREDIR)/InventorySlotInfo.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(SKILLDIR)/VampireSkillSlot.h \
  $(SKILLDIR)/Skill.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/VariableManager.h $(GSDIR)/StringPool.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
ActionTradeEventItem.o: ActionTradeEventItem.cpp ActionTradeEventItem.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/ItemUtil.h \
  $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h \
  $(GSDIR)/ItemFactoryManager.h $(GSDIR)/ItemFactory.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h \
  $(GSDIR)/Slayer.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/StringPool.h $(GSDIR)/PacketUtil.h $(ITEMDIR)/Key.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/InfoClassManager.h \
  $(COREDIR)/Gpackets/GCCreateItem.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h $(GSDIR)/PriceManager.h
ActionTradeLairItem.o: ActionTradeLairItem.cpp ActionTradeLairItem.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/ItemUtil.h \
  $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h \
  $(GSDIR)/ItemFactoryManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
  $(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
  $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(GSDIR)/Treasure.h \
  $(GSDIR)/Slayer.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h $(GSDIR)/MonsterInfo.h \
  $(GSDIR)/MonsterSummonInfo.h $(GSDIR)/MonsterInfoTypes.h \
  $(ITEMDIR)/QuestItem.h $(GSDIR)/StringPool.h $(GSDIR)/ItemMineInfo.h \
  $(GSDIR)/PacketUtil.h $(GSDIR)/ItemGradeManager.h \
  $(COREDIR)/Gpackets/GCCreateItem.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCDeleteInventoryItem.h \
  $(GSDIR)/SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h
ActionShowGuildDialog.o: ActionShowGuildDialog.cpp \
  ActionShowGuildDialog.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/Slayer.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h $(GSDIR)/Guild.h \
  $(GSDIR)/GuildManager.h $(COREDIR)/GuildInfo.h \
  $(GSDIR)/SharedServerManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCWaitGuildList.h \
  $(COREDIR)/Gpackets/GCActiveGuildList.h \
  $(COREDIR)/Gpackets/GSQuitGuild.h \
  $(GSDIR)/SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h
ActionSimpleQuestList.o: ActionSimpleQuestList.cpp \
  ActionSimpleQuestList.h Action.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
  $(COREDIR)/SocketEncryptInputStream.h $(SERVDIR)/Mutex.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h \
  $(GSDIR)/Item.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/Script.h $(GSDIR)/ScriptManager.h $(GSDIR)/NPC.h \
  $(GSDIR)/Zone.h $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
  $(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h \
  $(COREDIR)/Gpackets/GCNPCAskDynamic.h
ActionSimpleQuestComplete.o: ActionSimpleQuestComplete.cpp \
  ActionSimpleQuestComplete.h Action.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
  $(COREDIR)/SocketEncryptInputStream.h $(SERVDIR)/Mutex.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h \
  $(GSDIR)/Item.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/Script.h $(GSDIR)/ScriptManager.h \
  $(COREDIR)/Gpackets/GCNPCAskDynamic.h
ActionSimpleQuestRegen.o: ActionSimpleQuestRegen.cpp \
  ActionSimpleQuestRegen.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(SERVDIR)/Timeval.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h
ActionEnterCastleWithFee.o: ActionEnterCastleWithFee.cpp \
  ActionEnterCastleWithFee.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/Creature.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h \
  $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/ZoneGroup.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/ZoneGroupManager.h $(GSDIR)/ZoneInfo.h \
  $(GSDIR)/ZoneInfoManager.h $(GSDIR)/ZonePlayerManager.h \
  $(SERVDIR)/PlayerManager.h $(COREDIR)/Player.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h \
  $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(SKILLDIR)/VampireSkillSlot.h $(GSDIR)/WeatherManager.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h \
  $(GSDIR)/IncomingPlayerManager.h $(COREDIR)/ServerSocket.h \
  $(COREDIR)/DatagramSocket.h $(GSDIR)/ConnectionInfoManager.h \
  $(GSDIR)/ConnectionInfo.h $(SERVDIR)/LogClient.h $(GSDIR)/PacketUtil.h \
  $(GSDIR)/ZoneUtil.h $(COREDIR)/Properties.h \
  $(GSDIR)/CastleInfoManager.h $(GSDIR)/StringPool.h \
  $(COREDIR)/Gpackets/GCUpdateInfo.h $(COREDIR)/NPCInfo.h \
  $(COREDIR)/NicknameInfo.h $(COREDIR)/BloodBibleSignInfo.h \
  $(COREDIR)/Gpackets/GCMoveOK.h $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionShowTaxBalance.o: ActionShowTaxBalance.cpp ActionShowTaxBalance.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/Guild.h \
  $(GSDIR)/GuildManager.h $(GSDIR)/CastleInfoManager.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionAskVariable.o: ActionAskVariable.cpp ActionAskVariable.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/couple/PartnerWaitingManager.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h VariableInfo.h VariableBuffer.h \
  $(GSDIR)/CastleInfoManager.h $(GSDIR)/Guild.h $(GSDIR)/GuildManager.h \
  $(WARDIR)/WarSystem.h $(WARDIR)/Scheduler.h $(WARDIR)/Work.h \
  $(WARDIR)/Schedule.h $(COREDIR)/Gpackets/GCWarList.h \
  $(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
  $(COREDIR)/RaceWarInfo.h $(GSDIR)/VariableManager.h \
  $(GSDIR)/MonsterInfo.h $(GSDIR)/MonsterSummonInfo.h \
  $(GSDIR)/MonsterInfoTypes.h $(GSDIR)/Treasure.h $(GSDIR)/Slayer.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/SlayerSkillSlot.h \
  $(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(GSDIR)/Vampire.h $(COREDIR)/PCVampireInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(SKILLDIR)/VampireSkillSlot.h $(GSDIR)/Ousters.h \
  $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
  $(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
  $(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
  $(COREDIR)/Gpackets/GCNPCAskVariable.h $(COREDIR)/ScriptParameter.h \
  $(GSDIR)/StringPool.h $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(WARDIR)/WarScheduler.h \
  $(WARDIR)/War.h $(WARDIR)/WarSchedule.h $(WARDIR)/SiegeWar.h \
  $(GSDIR)/ZoneUtil.h
ActionWarRegistration.o: ActionWarRegistration.cpp \
  ActionWarRegistration.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(WARDIR)/GuildWar.h \
  $(WARDIR)/War.h $(WARDIR)/Work.h $(WARDIR)/WarScheduler.h \
  $(WARDIR)/Scheduler.h $(WARDIR)/Schedule.h $(GSDIR)/GuildManager.h \
  $(GSDIR)/Guild.h $(GSDIR)/ZoneUtil.h $(GSDIR)/VariableManager.h \
  $(COREDIR)/Properties.h $(GSDIR)/CastleInfoManager.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(GSDIR)/SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h
ActionShowWarSchedule.o: ActionShowWarSchedule.cpp \
  ActionShowWarSchedule.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(WARDIR)/WarScheduler.h \
  $(WARDIR)/Work.h $(WARDIR)/Scheduler.h $(WARDIR)/Schedule.h \
  $(WARDIR)/War.h $(GSDIR)/GuildManager.h $(GSDIR)/Guild.h \
  $(GSDIR)/ZoneUtil.h $(GSDIR)/PacketUtil.h $(GSDIR)/VariableManager.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCWarScheduleList.h
ActionJoinRaceWar.o: ActionJoinRaceWar.cpp ActionJoinRaceWar.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(WARDIR)/RaceWarLimiter.h \
  $(GSDIR)/PCLimiter.h $(GSDIR)/VariableManager.h $(WARDIR)/WarSystem.h \
  $(WARDIR)/Scheduler.h $(WARDIR)/Work.h $(WARDIR)/Schedule.h \
  $(COREDIR)/Gpackets/GCWarList.h $(COREDIR)/GuildWarInfo.h \
  $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h $(COREDIR)/RaceWarInfo.h \
  $(COREDIR)/Properties.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(GSDIR)/SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h
ActionInitPartnerWaitingManager.o: ActionInitPartnerWaitingManager.cpp \
  ActionInitPartnerWaitingManager.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h \
  $(GSDIR)/SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h
ActionWaitForMeetCouple.o: ActionWaitForMeetCouple.cpp \
  ActionWaitForMeetCouple.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h \
  $(GSDIR)/SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionWaitForApartCouple.o: ActionWaitForApartCouple.cpp \
  ActionWaitForApartCouple.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h \
  $(GSDIR)/SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionAcceptCoupleRequest.o: ActionAcceptCoupleRequest.cpp \
  ActionAcceptCoupleRequest.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h \
  $(GSDIR)/SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionAcceptApartCouple.o: ActionAcceptApartCouple.cpp \
  ActionAcceptApartCouple.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h \
  $(GSDIR)/SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionForceApartCouple.o: ActionForceApartCouple.cpp \
  ActionForceApartCouple.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h \
  $(GSDIR)/SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionEnterPKZone.o: ActionEnterPKZone.cpp ActionEnterPKZone.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/Creature.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h \
  $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/ZoneGroup.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/ZoneGroupManager.h $(GSDIR)/ZoneInfo.h \
  $(GSDIR)/ZoneInfoManager.h $(GSDIR)/ZonePlayerManager.h \
  $(SERVDIR)/PlayerManager.h $(COREDIR)/Player.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCOustersInfo2.h \
  $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(SKILLDIR)/VampireSkillSlot.h $(GSDIR)/Ousters.h \
  $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h $(GSDIR)/WeatherManager.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h \
  $(GSDIR)/IncomingPlayerManager.h $(COREDIR)/ServerSocket.h \
  $(COREDIR)/DatagramSocket.h $(GSDIR)/ConnectionInfoManager.h \
  $(GSDIR)/ConnectionInfo.h $(SERVDIR)/LogClient.h $(GSDIR)/PacketUtil.h \
  $(GSDIR)/ZoneUtil.h $(COREDIR)/Properties.h \
  $(GSDIR)/CastleInfoManager.h $(GSDIR)/StringPool.h \
  $(GSDIR)/PKZoneInfoManager.h $(COREDIR)/Cpackets/CGSay.h \
  $(GSDIR)/GQuestManager.h $(GSDIR)/GQuestInventory.h \
  $(COREDIR)/Gpackets/GCGQuestInventory.h \
  $(COREDIR)/Gpackets/GCUpdateInfo.h $(COREDIR)/NPCInfo.h \
  $(COREDIR)/NicknameInfo.h $(COREDIR)/BloodBibleSignInfo.h \
  $(COREDIR)/Gpackets/GCMoveOK.h $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(GSDIR)/SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h
ActionWarpToResurrectPosition.o: ActionWarpToResurrectPosition.cpp \
  ActionWarpToResurrectPosition.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h \
  $(GSDIR)/ResurrectLocationManager.h $(GSDIR)/ZoneUtil.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionSelectQuest.o: ActionSelectQuest.cpp ActionSelectQuest.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Item.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/couple/PartnerWaitingManager.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/StringPool.h \
  $(GSDIR)/VariableManager.h $(GSDIR)/mission/QuestManager.h \
  $(GSDIR)/mission/QuestInfo.h $(GSDIR)/mission/RewardClass.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(GSDIR)/mission/QuestStatus.h \
  $(GSDIR)/mission/QuestInfoManager.h \
  $(GSDIR)/mission/MonsterKillQuestInfo.h \
  $(GSDIR)/mission/MonsterKillQuestStatus.h \
  $(COREDIR)/Gpackets/GCQuestStatus.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
ActionQuestReward.o: ActionQuestReward.cpp ActionQuestReward.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Item.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/couple/PartnerWaitingManager.h $(COREDIR)/Player.h \
  $(GSDIR)/mission/QuestManager.h $(GSDIR)/mission/QuestInfo.h \
  $(GSDIR)/mission/RewardClass.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(GSDIR)/mission/QuestStatus.h \
  $(GSDIR)/mission/RewardClassInfoManager.h $(GSDIR)/CreatureUtil.h
ActionWarpToNoviceZone.o: ActionWarpToNoviceZone.cpp \
  ActionWarpToNoviceZone.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/Creature.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h \
  $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/ZoneGroup.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/ZoneGroupManager.h $(GSDIR)/ZoneInfo.h \
  $(GSDIR)/ZoneInfoManager.h $(GSDIR)/ZonePlayerManager.h \
  $(SERVDIR)/PlayerManager.h $(COREDIR)/Player.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h \
  $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(SKILLDIR)/VampireSkillSlot.h $(GSDIR)/WeatherManager.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h \
  $(GSDIR)/IncomingPlayerManager.h $(COREDIR)/ServerSocket.h \
  $(COREDIR)/DatagramSocket.h $(GSDIR)/ConnectionInfoManager.h \
  $(GSDIR)/ConnectionInfo.h $(SERVDIR)/LogClient.h $(GSDIR)/PacketUtil.h \
  $(GSDIR)/ZoneUtil.h $(COREDIR)/Properties.h $(GSDIR)/StringPool.h \
  $(COREDIR)/Gpackets/GCUpdateInfo.h $(COREDIR)/NPCInfo.h \
  $(COREDIR)/NicknameInfo.h $(COREDIR)/BloodBibleSignInfo.h \
  $(COREDIR)/Gpackets/GCMoveOK.h $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionCancelQuest.o: ActionCancelQuest.cpp ActionCancelQuest.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Item.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(GSDIR)/Inventory.h \
  $(GSDIR)/VolumeInfo.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/VariableManager.h $(GSDIR)/mission/QuestInfoManager.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(GSDIR)/mission/QuestInfo.h \
  $(GSDIR)/mission/RewardClass.h $(GSDIR)/mission/QuestManager.h \
  $(GSDIR)/mission/QuestStatus.h $(GSDIR)/mission/MonsterKillQuestInfo.h \
  $(GSDIR)/mission/MonsterKillQuestStatus.h \
  $(COREDIR)/Gpackets/GCQuestStatus.h $(COREDIR)/Gpackets/GCNPCAsk.h
ActionInitSimpleQuest.o: ActionInitSimpleQuest.cpp \
  ActionInitSimpleQuest.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/NPC.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/mission/SimpleQuestInfoManager.h \
  $(GSDIR)/mission/QuestInfoManager.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(GSDIR)/mission/QuestInfo.h \
  $(GSDIR)/mission/RewardClass.h \
  $(GSDIR)/mission/SimpleQuestRewardManager.h \
  $(GSDIR)/mission/RewardClassInfoManager.h
ActionWanderZone.o: ActionWanderZone.cpp ActionWanderZone.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h
ActionInitEventQuest.o: ActionInitEventQuest.cpp ActionInitEventQuest.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/NPC.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/mission/EventQuestInfoManager.h \
  $(GSDIR)/mission/QuestInfoManager.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(GSDIR)/mission/QuestInfo.h \
  $(GSDIR)/mission/RewardClass.h \
  $(GSDIR)/mission/SimpleQuestRewardManager.h \
  $(GSDIR)/mission/RewardClassInfoManager.h
ActionAskByQuestLevel.o: ActionAskByQuestLevel.cpp \
  ActionAskByQuestLevel.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/mission/QuestManager.h \
  $(GSDIR)/mission/QuestInfo.h $(GSDIR)/mission/RewardClass.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(GSDIR)/mission/QuestStatus.h \
  $(GSDIR)/mission/EventQuestAdvance.h $(COREDIR)/Gpackets/GCNPCAsk.h
ActionGiveEventQuest.o: ActionGiveEventQuest.cpp ActionGiveEventQuest.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Item.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/couple/PartnerWaitingManager.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/VariableManager.h \
  $(GSDIR)/mission/QuestManager.h $(GSDIR)/mission/QuestInfo.h \
  $(GSDIR)/mission/RewardClass.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(GSDIR)/mission/QuestStatus.h $(GSDIR)/mission/QuestInfoManager.h \
  $(GSDIR)/mission/MonsterKillQuestInfo.h \
  $(GSDIR)/mission/MonsterKillQuestStatus.h \
  $(COREDIR)/Gpackets/GCQuestStatus.h \
  $(GSDIR)/mission/EventQuestAdvance.h
ActionAdvanceEventQuest.o: ActionAdvanceEventQuest.cpp \
  ActionAdvanceEventQuest.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Item.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/couple/PartnerWaitingManager.h $(COREDIR)/Player.h \
  $(GSDIR)/mission/QuestManager.h $(GSDIR)/mission/QuestInfo.h \
  $(GSDIR)/mission/RewardClass.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(GSDIR)/mission/QuestStatus.h $(GSDIR)/mission/EventQuestAdvance.h \
  $(GSDIR)/mission/RewardClassInfoManager.h \
  $(COREDIR)/Gpackets/GCDeleteInventoryItem.h
ActionCancelEventQuestScript.o: ActionCancelEventQuestScript.cpp \
  ActionCancelEventQuestScript.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/mission/QuestManager.h \
  $(GSDIR)/mission/QuestInfo.h $(GSDIR)/mission/RewardClass.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(GSDIR)/mission/QuestStatus.h \
  $(GSDIR)/mission/EventQuestAdvance.h $(COREDIR)/Gpackets/GCNPCAsk.h
ActionRewardEventQuest.o: ActionRewardEventQuest.cpp \
  ActionRewardEventQuest.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/PacketUtil.h \
  $(GSDIR)/ItemUtil.h $(GSDIR)/mission/QuestManager.h \
  $(GSDIR)/mission/QuestInfo.h $(GSDIR)/mission/RewardClass.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(GSDIR)/mission/QuestStatus.h \
  $(GSDIR)/mission/EventQuestAdvance.h $(COREDIR)/Gpackets/GCNPCAsk.h \
  $(COREDIR)/Gpackets/GCCreateItem.h
ActionGiveLotto.o: ActionGiveLotto.cpp ActionGiveLotto.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/Properties.h \
  $(GSDIR)/mission/QuestManager.h $(GSDIR)/mission/QuestInfo.h \
  $(GSDIR)/mission/RewardClass.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(GSDIR)/mission/QuestStatus.h $(GSDIR)/mission/EventQuestAdvance.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCDeleteInventoryItem.h \
  $(COREDIR)/Cpackets/CGLotterySelect.h
ActionGiveEventQuestScript.o: ActionGiveEventQuestScript.cpp \
  ActionGiveEventQuestScript.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/mission/QuestManager.h \
  $(GSDIR)/mission/QuestInfo.h $(GSDIR)/mission/RewardClass.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(GSDIR)/mission/QuestStatus.h \
  $(GSDIR)/mission/EventQuestAdvance.h $(COREDIR)/Gpackets/GCNPCAsk.h
ActionStartEventQuest.o: ActionStartEventQuest.cpp \
  ActionStartEventQuest.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Item.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/couple/PartnerWaitingManager.h $(COREDIR)/Player.h \
  $(GSDIR)/mission/QuestManager.h $(GSDIR)/mission/QuestInfo.h \
  $(GSDIR)/mission/RewardClass.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(GSDIR)/mission/QuestStatus.h $(GSDIR)/mission/QuestInfoManager.h \
  $(GSDIR)/mission/EventQuestAdvance.h \
  $(GSDIR)/mission/RewardClassInfoManager.h
ActionWarpInZone.o: ActionWarpInZone.cpp ActionWarpInZone.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/PacketUtil.h \
  $(COREDIR)/Gpackets/GCDeleteObject.h $(COREDIR)/Gpackets/GCAddNPC.h
ActionEventMeet.o: ActionEventMeet.cpp ActionEventMeet.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/mission/QuestManager.h \
  $(GSDIR)/mission/QuestInfo.h $(GSDIR)/mission/RewardClass.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(GSDIR)/mission/QuestStatus.h \
  $(COREDIR)/Gpackets/GCNPCAsk.h $(COREDIR)/Gpackets/GCNoticeEvent.h
ActionGiveFinalLottoScript.o: ActionGiveFinalLottoScript.cpp \
  ActionGiveFinalLottoScript.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/mission/QuestManager.h \
  $(GSDIR)/mission/QuestInfo.h $(GSDIR)/mission/RewardClass.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(GSDIR)/mission/QuestStatus.h \
  $(GSDIR)/mission/EventQuestAdvance.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h $(COREDIR)/Gpackets/GCNPCAsk.h \
  $(COREDIR)/Gpackets/GCDeleteInventoryItem.h
ActionGiveQuestItem.o: ActionGiveQuestItem.cpp ActionGiveQuestItem.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/PacketUtil.h \
  $(GSDIR)/mission/QuestManager.h $(GSDIR)/mission/QuestInfo.h \
  $(GSDIR)/mission/RewardClass.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(GSDIR)/mission/QuestStatus.h $(GSDIR)/mission/EventQuestAdvance.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h $(COREDIR)/Gpackets/GCNPCAsk.h \
  $(COREDIR)/Gpackets/GCCreateItem.h
ActionTakeOutGoods.o: ActionTakeOutGoods.cpp ActionTakeOutGoods.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GoodsInventory.h $(GSDIR)/NPC.h \
  $(GSDIR)/Zone.h $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/couple/PartnerWaitingManager.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/VariableManager.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Gpackets/GCGoodsList.h
ActionClearRankBonus.o: ActionClearRankBonus.cpp ActionClearRankBonus.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/FlagSet.h \
  $(GSDIR)/VariableManager.h $(GSDIR)/StringPool.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
ActionContractGnomesHorn.o: ActionContractGnomesHorn.cpp \
  ActionContractGnomesHorn.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Script.h Trigger.h \
  $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/FlagSet.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionDownSkill.o: ActionDownSkill.cpp ActionDownSkill.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
  $(COREDIR)/SocketEncryptInputStream.h $(SERVDIR)/Mutex.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h \
  $(GSDIR)/Item.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionMiniGame.o: ActionMiniGame.cpp ActionMiniGame.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h \
  $(COREDIR)/Gpackets/GCNoticeEvent.h
ActionGiveItem.o: ActionGiveItem.cpp ActionGiveItem.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Creature.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/ItemFactoryManager.h \
  $(GSDIR)/ItemFactory.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/ItemUtil.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(GSDIR)/PacketUtil.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/Slayer.h $(COREDIR)/PCSlayerInfo.h \
  $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
  $(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
  $(COREDIR)/InventorySlotInfo.h $(GSDIR)/ItemLoaderManager.h \
  $(GSDIR)/ItemLoader.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(SKILLDIR)/SlayerSkillSlot.h \
  $(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(GSDIR)/Vampire.h $(COREDIR)/PCVampireInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(SKILLDIR)/VampireSkillSlot.h $(GSDIR)/Ousters.h \
  $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
  $(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
  $(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
  $(COREDIR)/Gpackets/GCCreateItem.h $(COREDIR)/Gpackets/GCNPCResponse.h
ActionActivateMazeExit.o: ActionActivateMazeExit.cpp \
  ActionActivateMazeExit.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/Creature.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h \
  $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/ZoneGroup.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/ZoneGroupManager.h $(GSDIR)/ZoneInfo.h \
  $(GSDIR)/ZoneInfoManager.h $(GSDIR)/ZonePlayerManager.h \
  $(SERVDIR)/PlayerManager.h $(COREDIR)/Player.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h \
  $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(SKILLDIR)/VampireSkillSlot.h $(GSDIR)/WeatherManager.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h \
  $(GSDIR)/IncomingPlayerManager.h $(COREDIR)/ServerSocket.h \
  $(COREDIR)/DatagramSocket.h $(GSDIR)/ConnectionInfoManager.h \
  $(GSDIR)/ConnectionInfo.h $(SERVDIR)/LogClient.h $(GSDIR)/PacketUtil.h \
  $(GSDIR)/ZoneUtil.h $(COREDIR)/Properties.h \
  $(GSDIR)/EffectRefiniumTicket.h $(COREDIR)/Gpackets/GCUpdateInfo.h \
  $(COREDIR)/NPCInfo.h $(COREDIR)/NicknameInfo.h \
  $(COREDIR)/BloodBibleSignInfo.h $(COREDIR)/Gpackets/GCMoveOK.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionActivateMazeEnter.o: ActionActivateMazeEnter.cpp \
  ActionActivateMazeEnter.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/Creature.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h \
  $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/ZoneGroup.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/ZoneGroupManager.h $(GSDIR)/ZoneInfo.h \
  $(GSDIR)/ZoneInfoManager.h $(GSDIR)/ZonePlayerManager.h \
  $(SERVDIR)/PlayerManager.h $(COREDIR)/Player.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h \
  $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(SKILLDIR)/VampireSkillSlot.h $(GSDIR)/WeatherManager.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h \
  $(GSDIR)/IncomingPlayerManager.h $(COREDIR)/ServerSocket.h \
  $(COREDIR)/DatagramSocket.h $(GSDIR)/ConnectionInfoManager.h \
  $(GSDIR)/ConnectionInfo.h $(SERVDIR)/LogClient.h $(GSDIR)/PacketUtil.h \
  $(GSDIR)/ZoneUtil.h $(COREDIR)/Properties.h $(GSDIR)/StringPool.h \
  $(GSDIR)/EffectRefiniumTicket.h $(COREDIR)/Gpackets/GCUpdateInfo.h \
  $(COREDIR)/NPCInfo.h $(COREDIR)/NicknameInfo.h \
  $(COREDIR)/BloodBibleSignInfo.h $(COREDIR)/Gpackets/GCMoveOK.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionActivateMazeReturn.o: ActionActivateMazeReturn.cpp \
  ActionActivateMazeReturn.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/Creature.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h \
  $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/ZoneGroup.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/ZoneGroupManager.h $(GSDIR)/ZoneInfo.h \
  $(GSDIR)/ZoneInfoManager.h $(GSDIR)/ZonePlayerManager.h \
  $(SERVDIR)/PlayerManager.h $(COREDIR)/Player.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h \
  $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(SKILLDIR)/VampireSkillSlot.h $(GSDIR)/WeatherManager.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h \
  $(GSDIR)/IncomingPlayerManager.h $(COREDIR)/ServerSocket.h \
  $(COREDIR)/DatagramSocket.h $(GSDIR)/ConnectionInfoManager.h \
  $(GSDIR)/ConnectionInfo.h $(SERVDIR)/LogClient.h $(GSDIR)/PacketUtil.h \
  $(GSDIR)/ZoneUtil.h $(COREDIR)/Properties.h $(GSDIR)/StringPool.h \
  $(GSDIR)/EffectRefiniumTicket.h $(COREDIR)/Gpackets/GCUpdateInfo.h \
  $(COREDIR)/NPCInfo.h $(COREDIR)/NicknameInfo.h \
  $(COREDIR)/BloodBibleSignInfo.h $(COREDIR)/Gpackets/GCMoveOK.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionSystemMessagePerRace.o: ActionSystemMessagePerRace.cpp \
  ActionSystemMessagePerRace.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
  $(COREDIR)/SocketEncryptInputStream.h $(SERVDIR)/Mutex.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h \
  $(GSDIR)/Item.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/StringPool.h $(COREDIR)/Gpackets/GCSystemMessage.h
ActionWarpLevelWarZone.o: ActionWarpLevelWarZone.cpp \
  ActionWarpLevelWarZone.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
  $(COREDIR)/SocketEncryptInputStream.h $(SERVDIR)/Mutex.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h \
  $(GSDIR)/Item.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/NPC.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h \
  $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h \
  $(GSDIR)/ObjectRegistry.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(GSDIR)/Inventory.h \
  $(GSDIR)/VolumeInfo.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/couple/PartnerWaitingManager.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
  $(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(GSDIR)/ZoneInfo.h \
  $(GSDIR)/ZoneUtil.h $(GSDIR)/PacketUtil.h $(COREDIR)/Properties.h \
  $(GSDIR)/StringPool.h $(GSDIR)/VariableManager.h \
  $(GSDIR)/ZoneInfoManager.h $(GSDIR)/LevelWarManager.h \
  $(WARDIR)/Scheduler.h $(WARDIR)/Work.h $(WARDIR)/Schedule.h \
  $(GSDIR)/SweeperSet.h $(GSDIR)/MonsterCorpse.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/Corpse.h $(ITEMDIR)/Sweeper.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/Gpackets/GCWarList.h $(COREDIR)/GuildWarInfo.h \
  $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h $(COREDIR)/RaceWarInfo.h \
  $(GSDIR)/LevelWarItemManager.h $(ITEMDIR)/WarItem.h \
  $(GSDIR)/LevelWarZoneInfoManager.h $(GSDIR)/GQuestManager.h \
  $(GSDIR)/GQuestInventory.h $(COREDIR)/Gpackets/GCGQuestInventory.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
ActionCheckPartnerName.o: ActionCheckPartnerName.cpp \
  ActionCheckPartnerName.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h $(GSDIR)/StringPool.h \
  $(GSDIR)/FlagSet.h $(GSDIR)/couple/CoupleManager.h
ActionStartPetQuest.o: ActionStartPetQuest.cpp ActionStartPetQuest.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h $(GSDIR)/mission/QuestManager.h \
  $(GSDIR)/mission/QuestInfo.h $(GSDIR)/mission/RewardClass.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(GSDIR)/mission/QuestStatus.h \
  $(GSDIR)/mission/MonsterKillQuestStatus.h \
  $(COREDIR)/Gpackets/GCQuestStatus.h $(GSDIR)/VariableManager.h \
  $(GSDIR)/StringPool.h $(GSDIR)/MonsterInfo.h \
  $(GSDIR)/MonsterSummonInfo.h $(GSDIR)/MonsterInfoTypes.h \
  $(GSDIR)/Treasure.h
ActionPetWithdraw.o: ActionPetWithdraw.cpp ActionPetWithdraw.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/couple/PartnerWaitingManager.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/PacketUtil.h \
  $(COREDIR)/Gpackets/GCPetStashList.h $(COREDIR)/PetInfo.h \
  $(COREDIR)/types/PetTypes.h
ActionPetDeposit.o: ActionPetDeposit.cpp ActionQuitDialogue.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h ActionPetDeposit.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/couple/PartnerWaitingManager.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/PacketUtil.h \
  $(COREDIR)/Gpackets/GCPetStashList.h $(COREDIR)/PetInfo.h \
  $(COREDIR)/types/PetTypes.h $(COREDIR)/Gpackets/GCNPCResponse.h
ActionEnterEventZone.o: ActionEnterEventZone.cpp ActionEnterEventZone.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/Creature.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h \
  $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/ZoneGroup.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/ZoneGroupManager.h $(GSDIR)/ZoneInfo.h \
  $(GSDIR)/ZoneInfoManager.h $(GSDIR)/ZonePlayerManager.h \
  $(SERVDIR)/PlayerManager.h $(COREDIR)/Player.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCOustersInfo2.h \
  $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(SKILLDIR)/VampireSkillSlot.h $(GSDIR)/Ousters.h \
  $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h $(GSDIR)/WeatherManager.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h \
  $(GSDIR)/IncomingPlayerManager.h $(COREDIR)/ServerSocket.h \
  $(COREDIR)/DatagramSocket.h $(GSDIR)/ConnectionInfoManager.h \
  $(GSDIR)/ConnectionInfo.h $(SERVDIR)/LogClient.h $(GSDIR)/PacketUtil.h \
  $(GSDIR)/ZoneUtil.h $(COREDIR)/Properties.h \
  $(GSDIR)/CastleInfoManager.h $(GSDIR)/StringPool.h \
  $(GSDIR)/EventZoneInfo.h $(COREDIR)/Gpackets/GCUpdateInfo.h \
  $(COREDIR)/NPCInfo.h $(COREDIR)/NicknameInfo.h \
  $(COREDIR)/BloodBibleSignInfo.h $(COREDIR)/Gpackets/GCMoveOK.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionEnterGDRLair.o: ActionEnterGDRLair.cpp ActionEnterGDRLair.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/Creature.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h \
  $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/ZoneGroup.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/ZoneGroupManager.h $(GSDIR)/ZoneInfo.h \
  $(GSDIR)/ZoneInfoManager.h $(GSDIR)/ZonePlayerManager.h \
  $(SERVDIR)/PlayerManager.h $(COREDIR)/Player.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCOustersInfo2.h \
  $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(SKILLDIR)/VampireSkillSlot.h $(GSDIR)/Ousters.h \
  $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h $(GSDIR)/WeatherManager.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h \
  $(GSDIR)/IncomingPlayerManager.h $(COREDIR)/ServerSocket.h \
  $(COREDIR)/DatagramSocket.h $(GSDIR)/ConnectionInfoManager.h \
  $(GSDIR)/ConnectionInfo.h $(SERVDIR)/LogClient.h $(GSDIR)/PacketUtil.h \
  $(GSDIR)/ZoneUtil.h $(COREDIR)/Properties.h \
  $(GSDIR)/CastleInfoManager.h $(GSDIR)/StringPool.h \
  $(GSDIR)/GDRLairManager.h $(GSDIR)/FiniteStateMachine.h \
  $(GSDIR)/GDRLairAbstractStates.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h $(COREDIR)/Gpackets/GCUpdateInfo.h \
  $(COREDIR)/NPCInfo.h $(COREDIR)/NicknameInfo.h \
  $(COREDIR)/BloodBibleSignInfo.h $(COREDIR)/Gpackets/GCMoveOK.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionTradeGQuestEventItem.o: ActionTradeGQuestEventItem.cpp \
  ActionTradeGQuestEventItem.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/GQuestManager.h \
  $(GSDIR)/GQuestInventory.h $(COREDIR)/Gpackets/GCGQuestInventory.h \
  $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h $(GSDIR)/ItemUtil.h \
  $(GSDIR)/Zone.h $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h \
  $(GSDIR)/ItemFactoryManager.h $(GSDIR)/ItemFactory.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h \
  $(GSDIR)/Slayer.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/StringPool.h $(GSDIR)/PacketUtil.h $(ITEMDIR)/Key.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/InfoClassManager.h \
  $(COREDIR)/Gpackets/GCCreateItem.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h $(GSDIR)/PriceManager.h
ActionRegisterSiege.o: ActionRegisterSiege.cpp ActionRegisterSiege.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(WARDIR)/GuildWar.h \
  $(WARDIR)/War.h $(WARDIR)/Work.h $(WARDIR)/SiegeWar.h \
  $(WARDIR)/WarScheduler.h $(WARDIR)/Scheduler.h $(WARDIR)/Schedule.h \
  $(WARDIR)/WarSchedule.h $(GSDIR)/GuildManager.h $(GSDIR)/Guild.h \
  $(GSDIR)/ZoneUtil.h $(GSDIR)/VariableManager.h $(COREDIR)/Properties.h \
  $(GSDIR)/CastleInfoManager.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(GSDIR)/SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h
ActionRegisterReinforce.o: ActionRegisterReinforce.cpp \
  ActionRegisterReinforce.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(WARDIR)/GuildWar.h \
  $(WARDIR)/War.h $(WARDIR)/Work.h $(WARDIR)/SiegeWar.h \
  $(WARDIR)/WarScheduler.h $(WARDIR)/Scheduler.h $(WARDIR)/Schedule.h \
  $(WARDIR)/WarSchedule.h $(GSDIR)/GuildManager.h $(GSDIR)/Guild.h \
  $(GSDIR)/ZoneUtil.h $(GSDIR)/VariableManager.h $(COREDIR)/Properties.h \
  $(GSDIR)/CastleInfoManager.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(GSDIR)/SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h
ActionAcceptReinforce.o: ActionAcceptReinforce.cpp \
  ActionAcceptReinforce.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(WARDIR)/GuildWar.h \
  $(WARDIR)/War.h $(WARDIR)/Work.h $(WARDIR)/SiegeWar.h \
  $(WARDIR)/WarScheduler.h $(WARDIR)/Scheduler.h $(WARDIR)/Schedule.h \
  $(WARDIR)/WarSchedule.h $(GSDIR)/GuildManager.h $(GSDIR)/Guild.h \
  $(GSDIR)/ZoneUtil.h $(GSDIR)/VariableManager.h $(COREDIR)/Properties.h \
  $(GSDIR)/CastleInfoManager.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(GSDIR)/SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h
ActionDenyReinforce.o: ActionDenyReinforce.cpp ActionDenyReinforce.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(WARDIR)/GuildWar.h \
  $(WARDIR)/War.h $(WARDIR)/Work.h $(WARDIR)/SiegeWar.h \
  $(WARDIR)/WarScheduler.h $(WARDIR)/Scheduler.h $(WARDIR)/Schedule.h \
  $(WARDIR)/WarSchedule.h $(GSDIR)/GuildManager.h $(GSDIR)/Guild.h \
  $(GSDIR)/ZoneUtil.h $(GSDIR)/VariableManager.h $(COREDIR)/Properties.h \
  $(GSDIR)/CastleInfoManager.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(GSDIR)/SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h
ActionEnterSiege.o: ActionEnterSiege.cpp ActionEnterSiege.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/CastleInfoManager.h \
  $(GSDIR)/StringPool.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(WARDIR)/WarScheduler.h $(WARDIR)/Work.h \
  $(WARDIR)/Scheduler.h $(WARDIR)/Schedule.h $(WARDIR)/War.h \
  $(GSDIR)/ZoneUtil.h $(WARDIR)/WarSchedule.h $(WARDIR)/WarSystem.h \
  $(COREDIR)/Gpackets/GCWarList.h $(COREDIR)/GuildWarInfo.h \
  $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h $(COREDIR)/RaceWarInfo.h \
  $(WARDIR)/SiegeWar.h $(GSDIR)/SiegeManager.h $(GSDIR)/GuildManager.h \
  $(GSDIR)/EventTransport.h $(GSDIR)/CreatureUtil.h \
  $(COREDIR)/Gpackets/GCUpdateInfo.h $(COREDIR)/GameTime.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(COREDIR)/InventoryInfo.h \
  $(COREDIR)/InventorySlotInfo.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/NPCInfo.h \
  $(COREDIR)/NicknameInfo.h $(COREDIR)/BloodBibleSignInfo.h \
  $(COREDIR)/Gpackets/GCMoveOK.h $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h
ActionRecallSiege.o: ActionRecallSiege.cpp ActionRecallSiege.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/CastleInfoManager.h \
  $(GSDIR)/StringPool.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(WARDIR)/WarScheduler.h $(WARDIR)/Work.h \
  $(WARDIR)/Scheduler.h $(WARDIR)/Schedule.h $(WARDIR)/War.h \
  $(GSDIR)/ZoneUtil.h $(WARDIR)/WarSchedule.h $(WARDIR)/SiegeWar.h \
  $(GSDIR)/SiegeManager.h $(GSDIR)/Guild.h $(GSDIR)/GuildManager.h \
  $(GSDIR)/EventTransport.h $(GSDIR)/CreatureUtil.h \
  $(WARDIR)/WarSystem.h $(COREDIR)/Gpackets/GCWarList.h \
  $(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
  $(COREDIR)/RaceWarInfo.h $(COREDIR)/Gpackets/GCUpdateInfo.h \
  $(COREDIR)/GameTime.h $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(COREDIR)/InventoryInfo.h \
  $(COREDIR)/InventorySlotInfo.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/NPCInfo.h \
  $(COREDIR)/NicknameInfo.h $(COREDIR)/BloodBibleSignInfo.h \
  $(COREDIR)/Gpackets/GCMoveOK.h $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(COREDIR)/Gpackets/GCGuildMemberList.h $(COREDIR)/GuildMemberInfo.h
ActionSelectBloodBible.o: ActionSelectBloodBible.cpp \
  ActionSelectBloodBible.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Item.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/couple/PartnerWaitingManager.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/StringPool.h \
  $(GSDIR)/BloodBibleBonus.h $(GSDIR)/ItemUtil.h \
  $(GSDIR)/BloodBibleBonusManager.h \
  $(COREDIR)/Gpackets/GCBloodBibleList.h
ActionClearBloodBible.o: ActionClearBloodBible.cpp \
  ActionClearBloodBible.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Item.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/couple/PartnerWaitingManager.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/StringPool.h \
  $(GSDIR)/BloodBibleBonus.h $(GSDIR)/ItemUtil.h \
  $(GSDIR)/BloodBibleBonusManager.h \
  $(COREDIR)/Gpackets/GCBloodBibleSignInfo.h \
  $(COREDIR)/BloodBibleSignInfo.h
ActionModifyTaxRatio.o: ActionModifyTaxRatio.cpp ActionModifyTaxRatio.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/Guild.h \
  $(GSDIR)/GuildManager.h $(GSDIR)/CastleInfoManager.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionSwapAdvancementItem.o: ActionSwapAdvancementItem.cpp \
  ActionSwapAdvancementItem.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/Guild.h \
  $(GSDIR)/GuildManager.h $(GSDIR)/CastleInfoManager.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionShowDonationDialog.o: ActionShowDonationDialog.cpp \
  ActionShowDonationDialog.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/Player.h \
  $(COREDIR)/Cpackets/CGDonationMoney.h $(COREDIR)/PacketFactory.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionEnterQuestZone.o: ActionEnterQuestZone.cpp ActionEnterQuestZone.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(COREDIR)/Properties.h \
  $(GSDIR)/StringPool.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/Creature.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h \
  $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/ZoneInfo.h \
  $(GSDIR)/ZoneInfoManager.h $(GSDIR)/ZoneUtil.h $(COREDIR)/VSDateTime.h \
  $(GSDIR)/ZoneGroup.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/ZoneGroupManager.h $(GSDIR)/PacketUtil.h \
  $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
  $(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h \
  $(GSDIR)/DynamicZoneAlterOfBlood.h $(GSDIR)/DynamicZone.h \
  $(GSDIR)/Monster.h $(GSDIR)/MonsterInfo.h $(GSDIR)/MonsterSummonInfo.h \
  $(GSDIR)/MonsterInfoTypes.h $(GSDIR)/Treasure.h \
  $(GSDIR)/PrecedenceTable.h $(GSDIR)/DynamicZoneGroup.h \
  $(GSDIR)/DynamicZoneManager.h $(GSDIR)/DynamicZoneInfo.h \
  $(GSDIR)/GQuestManager.h $(GSDIR)/GQuestInventory.h \
  $(COREDIR)/Gpackets/GCGQuestInventory.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
ActionShowConfirmGetEventItemDialog.o: ActionShowConfirmGetEventItemDialog.cpp \
  ActionShowConfirmGetEventItemDialog.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(COREDIR)/Player.h \
  $(COREDIR)/Cpackets/CGGetEventItem.h $(COREDIR)/PacketFactory.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionGiveCommonEventItem.o: ActionGiveCommonEventItem.cpp \
  ActionGiveCommonEventItem.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h $(COREDIR)/Player.h \
  $(GSDIR)/ItemFactoryManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemUtil.h $(GSDIR)/VariableManager.h $(GSDIR)/PacketUtil.h \
  $(COREDIR)/Gpackets/GCCreateItem.h $(COREDIR)/Gpackets/GCNPCResponse.h
ActionGiveCommonQuestItem.o: ActionGiveCommonQuestItem.cpp \
  ActionGiveCommonQuestItem.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/NPC.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(COREDIR)/Player.h $(GSDIR)/ItemFactoryManager.h \
  $(GSDIR)/ItemFactory.h $(GSDIR)/ItemUtil.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/InfoClassManager.h \
  $(GSDIR)/VariableManager.h $(GSDIR)/FlagSet.h $(GSDIR)/PacketUtil.h \
  $(COREDIR)/Gpackets/GCCreateItem.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCNPCAsk.h
ActionCheckCommonQuestItem.o: ActionCheckCommonQuestItem.cpp \
  ActionCheckCommonQuestItem.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/NPC.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(COREDIR)/Player.h $(GSDIR)/ItemFactoryManager.h \
  $(GSDIR)/ItemFactory.h $(GSDIR)/ItemUtil.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/InfoClassManager.h \
  $(GSDIR)/VariableManager.h $(GSDIR)/FlagSet.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Gpackets/GCNPCAsk.h
ActionResetAttribute.o: ActionResetAttribute.cpp ActionResetAttribute.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Vampire.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/Zone.h $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/PCVampireInfo.h \
  $(COREDIR)/PCInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/InventoryInfo.h \
  $(COREDIR)/InventorySlotInfo.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(SKILLDIR)/VampireSkillSlot.h \
  $(SKILLDIR)/Skill.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Ousters.h \
  $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
  $(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
  $(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
  $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(GSDIR)/VariableManager.h $(GSDIR)/StringPool.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
ActionCheckEventLevelUp200604.o: ActionCheckEventLevelUp200604.cpp \
  ActionCheckEventLevelUp200604.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h $(GSDIR)/NPC.h \
  $(GSDIR)/couple/PartnerWaitingManager.h $(COREDIR)/Player.h \
  $(GSDIR)/VariableManager.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCNPCAsk.h
ActionGiveEventLevelUp200604.o: ActionGiveEventLevelUp200604.cpp \
  ActionGiveEventLevelUp200604.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h $(GSDIR)/NPC.h \
  $(GSDIR)/couple/PartnerWaitingManager.h $(COREDIR)/Player.h \
  $(GSDIR)/VariableManager.h $(GSDIR)/ItemFactoryManager.h \
  $(GSDIR)/ItemFactory.h $(GSDIR)/ItemUtil.h $(GSDIR)/PacketUtil.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Gpackets/GCNPCAsk.h \
  $(COREDIR)/Gpackets/GCCreateItem.h
ActionGiveComebackEventItem200604.o: ActionGiveComebackEventItem200604.cpp \
  ActionGiveComebackEventItem200604.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/NPC.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/ItemFactoryManager.h \
  $(GSDIR)/ItemFactory.h $(GSDIR)/ItemUtil.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/InfoClassManager.h $(GSDIR)/PacketUtil.h \
  $(GSDIR)/VariableManager.h $(GSDIR)/NicknameBook.h \
  $(COREDIR)/NicknameInfo.h $(GSDIR)/FlagSet.h $(ITEMDIR)/PetItem.h \
  $(COREDIR)/PetInfo.h $(COREDIR)/types/PetTypes.h \
  $(COREDIR)/Gpackets/GCCreateItem.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCNPCAsk.h
ActionCheckComebackEventItem200604.o: ActionCheckComebackEventItem200604.cpp \
  ActionCheckComebackEventItem200604.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/NPC.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/VariableManager.h \
  $(GSDIR)/FlagSet.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCNPCAsk.h
ActionRedistributeAttr50.o: ActionRedistributeAttr50.cpp \
  ActionRedistributeAttr50.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/VariableManager.h \
  $(GSDIR)/StringPool.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
ActionChangePlayerColor.o: ActionChangePlayerColor.cpp \
  ActionChangePlayerColor.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/ZonePlayerManager.h \
  $(SERVDIR)/PlayerManager.h $(COREDIR)/Player.h $(GSDIR)/PriceManager.h \
  $(GSDIR)/Slayer.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/ItemUtil.h \
  $(GSDIR)/ItemFactoryManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/PacketUtil.h $(GSDIR)/CastleInfoManager.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Gpackets/GCNPCAsk.h \
  $(COREDIR)/Gpackets/GCDeleteObject.h $(COREDIR)/Gpackets/GCAddSlayer.h \
  $(COREDIR)/PetInfo.h $(COREDIR)/types/PetTypes.h \
  $(COREDIR)/NicknameInfo.h $(COREDIR)/StoreInfo.h \
  $(COREDIR)/Gpackets/GCAddVampire.h $(COREDIR)/Gpackets/GCAddOusters.h \
  $(COREDIR)/NPCInfo.h $(GSDIR)/ZoneUtil.h $(GSDIR)/GuildManager.h \
  $(SERVDIR)/LogClient.h $(GSDIR)/GQuestManager.h \
  $(GSDIR)/GQuestInventory.h $(COREDIR)/Gpackets/GCGQuestInventory.h
ActionExchangeOfMoney.o: ActionExchangeOfMoney.cpp \
  ActionExchangeOfMoney.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(GSDIR)/Creature.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/EffectManager.h \
  $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/Slayer.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h $(GSDIR)/ItemUtil.h \
  $(GSDIR)/PacketUtil.h $(GSDIR)/ItemFactoryManager.h \
  $(GSDIR)/ItemFactory.h $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ZoneInfo.h \
  $(ITEMDIR)/CheckMoney.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCWaitGuildList.h $(COREDIR)/GuildInfo.h \
  $(COREDIR)/Gpackets/GCActiveGuildList.h \
  $(COREDIR)/Gpackets/GSQuitGuild.h \
  $(COREDIR)/Gpackets/GCDeleteInventoryItem.h \
  $(COREDIR)/Gpackets/GCCreateItem.h $(COREDIR)/Gpackets/GCNPCAsk.h \
  $(GSDIR)/SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h
ActionSoccerEvent200606.o: ActionSoccerEvent200606.cpp \
  ActionSoccerEvent200606.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/NPC.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(COREDIR)/Player.h $(GSDIR)/ItemFactoryManager.h \
  $(GSDIR)/ItemFactory.h $(GSDIR)/ItemUtil.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/InfoClassManager.h \
  $(GSDIR)/VariableManager.h $(GSDIR)/FlagSet.h $(GSDIR)/PacketUtil.h \
  $(COREDIR)/Gpackets/GCCreateItem.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCNPCAsk.h
ActionTradeSealingStone.o: ActionTradeSealingStone.cpp \
  ActionTradeSealingStone.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h $(GSDIR)/NPC.h \
  $(GSDIR)/couple/PartnerWaitingManager.h $(COREDIR)/Player.h \
  $(GSDIR)/ItemFactoryManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemUtil.h $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/VariableManager.h \
  $(GSDIR)/FlagSet.h $(GSDIR)/PacketUtil.h \
  $(COREDIR)/Gpackets/GCCreateItem.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCNPCAsk.h
ActionEnterCastleB2F.o: ActionEnterCastleB2F.cpp ActionEnterCastleB2F.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/StringPool.h \
  $(GSDIR)/Zone.h $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h $(GSDIR)/ZoneUtil.h \
  $(GSDIR)/MonsterManager.h $(GSDIR)/MonsterCounter.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
ActionEnterSurvivalZone.o: ActionEnterSurvivalZone.cpp \
  ActionEnterSurvivalZone.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/Creature.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h \
  $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/ZoneGroup.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/ZoneGroupManager.h $(GSDIR)/ZoneInfo.h \
  $(GSDIR)/ZoneInfoManager.h $(GSDIR)/ZonePlayerManager.h \
  $(SERVDIR)/PlayerManager.h $(COREDIR)/Player.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCOustersInfo2.h \
  $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(SKILLDIR)/VampireSkillSlot.h $(GSDIR)/Ousters.h \
  $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h $(GSDIR)/WeatherManager.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h \
  $(GSDIR)/IncomingPlayerManager.h $(COREDIR)/ServerSocket.h \
  $(COREDIR)/DatagramSocket.h $(GSDIR)/ConnectionInfoManager.h \
  $(GSDIR)/ConnectionInfo.h $(SERVDIR)/LogClient.h $(GSDIR)/PacketUtil.h \
  $(GSDIR)/ZoneUtil.h $(COREDIR)/Properties.h \
  $(GSDIR)/CastleInfoManager.h $(GSDIR)/StringPool.h \
  $(GSDIR)/EventSurvivalZoneManager.h $(SKILLDIR)/EffectHallucination.h \
  $(GSDIR)/GQuestManager.h $(GSDIR)/GQuestInventory.h \
  $(COREDIR)/Gpackets/GCGQuestInventory.h \
  $(COREDIR)/Gpackets/GCUpdateInfo.h $(COREDIR)/NPCInfo.h \
  $(COREDIR)/NicknameInfo.h $(COREDIR)/BloodBibleSignInfo.h \
  $(COREDIR)/Gpackets/GCMoveOK.h $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(GSDIR)/SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h
ActionGambleSystem.o: ActionGambleSystem.cpp ActionGambleSystem.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h $(GSDIR)/NPC.h \
  $(GSDIR)/couple/PartnerWaitingManager.h $(COREDIR)/Player.h \
  $(GSDIR)/ItemFactoryManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemUtil.h $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/VariableManager.h \
  $(GSDIR)/FlagSet.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/PacketUtil.h \
  $(COREDIR)/Gpackets/GCCreateItem.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCNPCAsk.h
ActionCheckGlutinousRiceKneading.o: ActionCheckGlutinousRiceKneading.cpp \
  ActionCheckGlutinousRiceKneading.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/NPC.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(COREDIR)/Player.h $(GSDIR)/ItemFactoryManager.h \
  $(GSDIR)/ItemFactory.h $(GSDIR)/ItemUtil.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/InfoClassManager.h \
  $(GSDIR)/VariableManager.h $(GSDIR)/FlagSet.h $(GSDIR)/PacketUtil.h \
  $(COREDIR)/Gpackets/GCCreateItem.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCNPCAsk.h
ActionGiveEventBoxItem.o: ActionGiveEventBoxItem.cpp \
  ActionGiveEventBoxItem.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h $(GSDIR)/NPC.h \
  $(GSDIR)/couple/PartnerWaitingManager.h $(COREDIR)/Player.h \
  $(GSDIR)/ItemFactoryManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/ItemUtil.h \
  $(GSDIR)/VariableManager.h $(GSDIR)/FlagSet.h $(GSDIR)/PacketUtil.h \
  $(COREDIR)/Gpackets/GCCreateItem.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCNPCAsk.h \
  $(COREDIR)/Gpackets/GCDeleteInventoryItem.h
ActionTradeMysteryPotion.o: ActionTradeMysteryPotion.cpp \
  ActionTradeMysteryPotion.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h $(GSDIR)/NPC.h \
  $(GSDIR)/couple/PartnerWaitingManager.h $(COREDIR)/Player.h \
  $(GSDIR)/ItemFactoryManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemUtil.h $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/VariableManager.h \
  $(GSDIR)/FlagSet.h $(GSDIR)/PacketUtil.h \
  $(COREDIR)/Gpackets/GCCreateItem.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCNPCAsk.h
ActionTradeLeather.o: ActionTradeLeather.cpp ActionTradeLeather.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h $(GSDIR)/NPC.h \
  $(GSDIR)/couple/PartnerWaitingManager.h $(COREDIR)/Player.h \
  $(GSDIR)/ItemFactoryManager.h $(GSDIR)/ItemFactory.h \
  $(GSDIR)/ItemUtil.h $(GSDIR)/ItemInfoManager.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/VariableManager.h \
  $(GSDIR)/FlagSet.h $(GSDIR)/PacketUtil.h \
  $(COREDIR)/Gpackets/GCCreateItem.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCNPCAsk.h
ActionGiveHellGardenCrossItem.o: ActionGiveHellGardenCrossItem.cpp \
  ActionGiveHellGardenCrossItem.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/ItemUtil.h \
  $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h \
  $(GSDIR)/ItemFactoryManager.h $(GSDIR)/ItemFactory.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h \
  $(GSDIR)/Treasure.h $(GSDIR)/Slayer.h $(COREDIR)/PCSlayerInfo.h \
  $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
  $(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
  $(COREDIR)/InventorySlotInfo.h $(GSDIR)/ItemLoaderManager.h \
  $(GSDIR)/ItemLoader.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(SKILLDIR)/SlayerSkillSlot.h \
  $(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(GSDIR)/Vampire.h $(COREDIR)/PCVampireInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(SKILLDIR)/VampireSkillSlot.h $(GSDIR)/Ousters.h \
  $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
  $(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
  $(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
  $(GSDIR)/MonsterInfo.h $(GSDIR)/MonsterSummonInfo.h \
  $(GSDIR)/MonsterInfoTypes.h $(ITEMDIR)/QuestItem.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/StringPool.h \
  $(GSDIR)/ItemMineInfo.h $(GSDIR)/PacketUtil.h \
  $(GSDIR)/ItemGradeManager.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/FlagSet.h $(COREDIR)/Gpackets/GCCreateItem.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCDeleteInventoryItem.h \
  $(GSDIR)/SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h
ActionGiveHellGardenSeedItem.o: ActionGiveHellGardenSeedItem.cpp \
  ActionGiveHellGardenSeedItem.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/ItemUtil.h \
  $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h \
  $(GSDIR)/ItemFactoryManager.h $(GSDIR)/ItemFactory.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h \
  $(GSDIR)/Treasure.h $(GSDIR)/Slayer.h $(COREDIR)/PCSlayerInfo.h \
  $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
  $(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
  $(COREDIR)/InventorySlotInfo.h $(GSDIR)/ItemLoaderManager.h \
  $(GSDIR)/ItemLoader.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(SKILLDIR)/SlayerSkillSlot.h \
  $(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(GSDIR)/Vampire.h $(COREDIR)/PCVampireInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(SKILLDIR)/VampireSkillSlot.h $(GSDIR)/Ousters.h \
  $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
  $(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
  $(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
  $(GSDIR)/MonsterInfo.h $(GSDIR)/MonsterSummonInfo.h \
  $(GSDIR)/MonsterInfoTypes.h $(ITEMDIR)/QuestItem.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/StringPool.h \
  $(GSDIR)/ItemMineInfo.h $(GSDIR)/PacketUtil.h \
  $(GSDIR)/ItemGradeManager.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/FlagSet.h $(COREDIR)/Gpackets/GCCreateItem.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCDeleteInventoryItem.h \
  $(GSDIR)/SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h
ActionEnterHellGarden.o: ActionEnterHellGarden.cpp \
  ActionEnterHellGarden.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/Creature.h $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h \
  $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/ZoneGroup.h $(COREDIR)/GameTime.h \
  $(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h \
  $(GSDIR)/ZoneGroupManager.h $(GSDIR)/ZoneInfo.h \
  $(GSDIR)/ZoneInfoManager.h $(GSDIR)/ZonePlayerManager.h \
  $(SERVDIR)/PlayerManager.h $(COREDIR)/Player.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCOustersInfo2.h \
  $(GSDIR)/Slayer.h $(GSDIR)/PlayerCreature.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/Gpackets/GCSelectQuestID.h $(GSDIR)/OptionInfo.h \
  $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(SKILLDIR)/VampireSkillSlot.h $(GSDIR)/Ousters.h \
  $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h $(GSDIR)/WeatherManager.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/GamePlayer.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h \
  $(GSDIR)/IncomingPlayerManager.h $(COREDIR)/ServerSocket.h \
  $(COREDIR)/DatagramSocket.h $(GSDIR)/ConnectionInfoManager.h \
  $(GSDIR)/ConnectionInfo.h $(SERVDIR)/LogClient.h $(GSDIR)/PacketUtil.h \
  $(GSDIR)/ZoneUtil.h $(COREDIR)/Properties.h \
  $(GSDIR)/CastleInfoManager.h $(GSDIR)/StringPool.h \
  $(SKILLDIR)/EffectHallucination.h $(GSDIR)/GQuestManager.h \
  $(GSDIR)/GQuestInventory.h $(COREDIR)/Gpackets/GCGQuestInventory.h \
  $(GSDIR)/FlagSet.h $(COREDIR)/Gpackets/GCUpdateInfo.h \
  $(COREDIR)/NPCInfo.h $(COREDIR)/NicknameInfo.h \
  $(COREDIR)/BloodBibleSignInfo.h $(COREDIR)/Gpackets/GCMoveOK.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(GSDIR)/SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h
ActionAttendCheck.o: ActionAttendCheck.cpp ActionAttendCheck.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/NPC.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/ItemFactoryManager.h \
  $(GSDIR)/ItemFactory.h $(GSDIR)/ItemUtil.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/InfoClassManager.h $(GSDIR)/PacketUtil.h \
  $(GSDIR)/VariableManager.h $(GSDIR)/NicknameBook.h \
  $(COREDIR)/NicknameInfo.h $(GSDIR)/FlagSet.h $(ITEMDIR)/PetItem.h \
  $(COREDIR)/PetInfo.h $(COREDIR)/types/PetTypes.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Gpackets/GCNPCAsk.h
ActionEnterMenegroth.o: ActionEnterMenegroth.cpp $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h ActionEnterMenegroth.h $(COREDIR)/Exception.h \
  $(COREDIR)/StringStream.h Action.h PropertyBuffer.h ActionFactory.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/Slayer.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/SlayerSkillSlot.h \
  $(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(GSDIR)/Vampire.h $(COREDIR)/PCVampireInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(SKILLDIR)/VampireSkillSlot.h $(GSDIR)/Ousters.h \
  $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
  $(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
  $(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
  $(GSDIR)/ZoneUtil.h $(GSDIR)/StringPool.h \
  $(GSDIR)/MenegrothDoungeonManager.h $(GSDIR)/EffectMenegrothDoungeon.h \
  $(GSDIR)/EffectLoader.h $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h
ActionGiveContributeReward.o: ActionGiveContributeReward.cpp \
  ActionGiveContributeReward.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/ItemUtil.h \
  $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h \
  $(GSDIR)/ItemFactoryManager.h $(GSDIR)/ItemFactory.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h \
  $(GSDIR)/Treasure.h $(GSDIR)/Slayer.h $(COREDIR)/PCSlayerInfo.h \
  $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
  $(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
  $(COREDIR)/InventorySlotInfo.h $(GSDIR)/ItemLoaderManager.h \
  $(GSDIR)/ItemLoader.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(SKILLDIR)/SlayerSkillSlot.h \
  $(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(GSDIR)/Vampire.h $(COREDIR)/PCVampireInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(SKILLDIR)/VampireSkillSlot.h $(GSDIR)/Ousters.h \
  $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
  $(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
  $(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
  $(GSDIR)/MonsterInfo.h $(GSDIR)/MonsterSummonInfo.h \
  $(GSDIR)/MonsterInfoTypes.h $(ITEMDIR)/QuestItem.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/StringPool.h \
  $(GSDIR)/ItemMineInfo.h $(GSDIR)/PacketUtil.h \
  $(GSDIR)/ItemGradeManager.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/FlagSet.h $(COREDIR)/Gpackets/GCCreateItem.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCDeleteInventoryItem.h \
  $(GSDIR)/SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h \
  $(GSDIR)/VariableManager.h
ActionInsertCabracamHeart.o: ActionInsertCabracamHeart.cpp \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  ActionInsertCabracamHeart.h $(COREDIR)/Exception.h \
  $(COREDIR)/StringStream.h Action.h PropertyBuffer.h ActionFactory.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/Slayer.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/SlayerSkillSlot.h \
  $(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(GSDIR)/Vampire.h $(COREDIR)/PCVampireInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(SKILLDIR)/VampireSkillSlot.h $(GSDIR)/Ousters.h \
  $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
  $(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
  $(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
  $(GSDIR)/ZoneUtil.h $(GSDIR)/StringPool.h \
  $(GSDIR)/MenegrothDoungeonZoneManager.h \
  $(GSDIR)/MenegrothDoungeonManager.h $(GSDIR)/EffectCabracamAltar.h \
  $(GSDIR)/EffectLoader.h $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Gpackets/GCNPCAsk.h \
  $(COREDIR)/Gpackets/GCAddEffect.h
ActionCheckLevelWarReward.o: ActionCheckLevelWarReward.cpp \
  ActionCheckLevelWarReward.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/Item.h \
  $(GSDIR)/Object.h $(COREDIR)/Assert.h $(GSDIR)/Effect.h \
  $(SERVDIR)/Timeval.h $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h \
  $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/NPC.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(COREDIR)/Player.h $(GSDIR)/ItemFactoryManager.h \
  $(GSDIR)/ItemFactory.h $(GSDIR)/ItemUtil.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/InfoClassManager.h \
  $(GSDIR)/VariableManager.h $(GSDIR)/FlagSet.h $(GSDIR)/PacketUtil.h \
  $(GSDIR)/LevelWarZoneInfoManager.h $(COREDIR)/Gpackets/GCCreateItem.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Gpackets/GCNPCAsk.h
ActionGiveCrashingReward.o: ActionGiveCrashingReward.cpp \
  ActionGiveCrashingReward.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/ItemUtil.h \
  $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h \
  $(GSDIR)/ItemFactoryManager.h $(GSDIR)/ItemFactory.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h \
  $(GSDIR)/Treasure.h $(GSDIR)/Slayer.h $(COREDIR)/PCSlayerInfo.h \
  $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
  $(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
  $(COREDIR)/InventorySlotInfo.h $(GSDIR)/ItemLoaderManager.h \
  $(GSDIR)/ItemLoader.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(SKILLDIR)/SlayerSkillSlot.h \
  $(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(GSDIR)/Vampire.h $(COREDIR)/PCVampireInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(SKILLDIR)/VampireSkillSlot.h $(GSDIR)/Ousters.h \
  $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
  $(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
  $(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
  $(GSDIR)/MonsterInfo.h $(GSDIR)/MonsterSummonInfo.h \
  $(GSDIR)/MonsterInfoTypes.h $(ITEMDIR)/QuestItem.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/StringPool.h \
  $(GSDIR)/ItemMineInfo.h $(GSDIR)/PacketUtil.h \
  $(GSDIR)/ItemGradeManager.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/FlagSet.h $(COREDIR)/Gpackets/GCCreateItem.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCDeleteInventoryItem.h \
  $(GSDIR)/SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h
ActionInitInstanceDoungeon.o: ActionInitInstanceDoungeon.cpp \
  ActionInitInstanceDoungeon.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/NPC.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h
ActionBlitzRegister.o: ActionBlitzRegister.cpp ActionBlitzRegister.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/NPC.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(COREDIR)/Player.h $(GSDIR)/ItemFactoryManager.h \
  $(GSDIR)/ItemFactory.h $(GSDIR)/ItemUtil.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/InfoClassManager.h \
  $(GSDIR)/VariableManager.h $(GSDIR)/FlagSet.h $(SKILLDIR)/SkillUtil.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCNPCAsk.h
ActionBlitzReward.o: ActionBlitzReward.cpp ActionBlitzReward.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/NPC.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(COREDIR)/Player.h $(GSDIR)/ItemFactoryManager.h \
  $(GSDIR)/ItemFactory.h $(GSDIR)/ItemUtil.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/InfoClassManager.h \
  $(GSDIR)/VariableManager.h $(GSDIR)/FlagSet.h $(SKILLDIR)/SkillUtil.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h $(COREDIR)/Gpackets/GCCreateItem.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Gpackets/GCNPCAsk.h \
  $(GSDIR)/EventBlitzRewardManager.h $(GSDIR)/PacketUtil.h
ActionMapleRegister.o: ActionMapleRegister.cpp ActionMapleRegister.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/NPC.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(COREDIR)/Player.h $(GSDIR)/ItemFactoryManager.h \
  $(GSDIR)/ItemFactory.h $(GSDIR)/ItemUtil.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/InfoClassManager.h \
  $(GSDIR)/VariableManager.h $(GSDIR)/FlagSet.h $(SKILLDIR)/SkillUtil.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCNPCAsk.h
ActionMapleReward.o: ActionMapleReward.cpp ActionMapleReward.h \
  $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
  $(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
  $(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
  $(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
  $(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
  $(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
  $(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
  $(COREDIR)/Exception.h $(COREDIR)/StringStream.h Action.h \
  PropertyBuffer.h ActionFactory.h $(GSDIR)/Item.h $(GSDIR)/Object.h \
  $(COREDIR)/Assert.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(GSDIR)/EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/Slayer.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Creature.h \
  $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/Zone.h $(GSDIR)/Tile.h \
  $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h $(GSDIR)/quest/TriggerManager.h \
  $(GSDIR)/quest/Trigger.h $(GSDIR)/quest/Condition.h \
  $(GSDIR)/quest/PropertyBuffer.h $(GSDIR)/Sector.h $(GSDIR)/Party.h \
  $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h $(GSDIR)/Vampire.h \
  $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
  $(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
  $(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
  $(GSDIR)/NPC.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(COREDIR)/Player.h $(GSDIR)/ItemFactoryManager.h \
  $(GSDIR)/ItemFactory.h $(GSDIR)/ItemUtil.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/ItemInfo.h $(GSDIR)/InfoClassManager.h \
  $(GSDIR)/VariableManager.h $(GSDIR)/FlagSet.h $(SKILLDIR)/SkillUtil.h \
  $(GSDIR)/Ousters.h $(COREDIR)/PCOustersInfo.h \
  $(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
  $(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
  $(SKILLDIR)/OustersSkillSlot.h $(COREDIR)/Gpackets/GCCreateItem.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Gpackets/GCNPCAsk.h \
  $(GSDIR)/EventBlitzRewardManager.h $(GSDIR)/PacketUtil.h
ActionEnterPVPSystem.o: ActionEnterPVPSystem.cpp $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h ActionEnterPVPSystem.h $(COREDIR)/Exception.h \
  $(COREDIR)/StringStream.h Action.h PropertyBuffer.h ActionFactory.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/NPC.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Item.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/ObjectRegistry.h $(SERVDIR)/Mutex.h \
  $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h $(GSDIR)/PCManager.h \
  $(GSDIR)/CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h \
  $(GSDIR)/InventorySlot.h $(GSDIR)/couple/PartnerWaitingManager.h \
  $(GSDIR)/PlayerCreature.h $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h \
  $(GSDIR)/ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
  $(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
  $(GSDIR)/EventManager.h $(GSDIR)/Event.h $(SKILLDIR)/Skill.h \
  $(SERVDIR)/PaySystem.h $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/Slayer.h \
  $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
  $(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
  $(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
  $(GSDIR)/ItemLoaderManager.h $(GSDIR)/ItemLoader.h \
  $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
  $(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
  $(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
  $(COREDIR)/SubSlayerSkillInfo.h $(GSDIR)/CreatureUtil.h \
  $(GSDIR)/SlayerAttrExpTable.h $(GSDIR)/SomethingGrowingUp.h \
  $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
  $(DBDIR)/Statement.h $(DBDIR)/Result.h $(SKILLDIR)/SlayerSkillSlot.h \
  $(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(GSDIR)/Vampire.h $(COREDIR)/PCVampireInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(SKILLDIR)/VampireSkillSlot.h $(GSDIR)/Ousters.h \
  $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
  $(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
  $(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
  $(GSDIR)/ZoneUtil.h $(GSDIR)/StringPool.h $(GSDIR)/PVPSystemManager.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h $(COREDIR)/Gpackets/GCAddEffect.h \
  $(GSDIR)/VariableManager.h
ActionPVPSystemSignUp.o: ActionPVPSystemSignUp.cpp \
  ActionPVPSystemSignUp.h $(COREDIR)/Types.h \
  $(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
  $(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
  $(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
  $(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
  $(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
  $(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  Action.h PropertyBuffer.h ActionFactory.h $(GSDIR)/PlayerCreature.h \
  $(GSDIR)/Creature.h $(GSDIR)/Object.h $(COREDIR)/Assert.h \
  $(GSDIR)/EffectManager.h $(GSDIR)/Effect.h $(SERVDIR)/Timeval.h \
  $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
  $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
  $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h $(GSDIR)/ObjectRegistry.h \
  $(SERVDIR)/Mutex.h $(GSDIR)/InventorySlot.h $(GSDIR)/Item.h \
  $(GSDIR)/Garbage.h $(GSDIR)/RankBonus.h $(GSDIR)/ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
  $(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
  $(GSDIR)/OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
  $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
  $(COREDIR)/SubItemInfo.h $(GSDIR)/GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
  $(COREDIR)/PlayerStatus.h $(GSDIR)/EventManager.h $(GSDIR)/Event.h \
  $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(GSDIR)/billing/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h $(GSDIR)/ItemUtil.h \
  $(GSDIR)/Inventory.h $(GSDIR)/VolumeInfo.h $(GSDIR)/Zone.h \
  $(GSDIR)/Tile.h $(GSDIR)/Obstacle.h $(GSDIR)/Portal.h \
  $(GSDIR)/quest/TriggerManager.h $(GSDIR)/quest/Trigger.h \
  $(GSDIR)/quest/Condition.h $(GSDIR)/quest/PropertyBuffer.h \
  $(GSDIR)/Sector.h $(GSDIR)/Party.h $(COREDIR)/ModifyInfo.h \
  $(GSDIR)/PCManager.h $(GSDIR)/CreatureManager.h \
  $(GSDIR)/ItemFactoryManager.h $(GSDIR)/ItemFactory.h $(DBDIR)/DB.h \
  $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h \
  $(GSDIR)/Treasure.h $(GSDIR)/Slayer.h $(COREDIR)/PCSlayerInfo.h \
  $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
  $(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
  $(COREDIR)/InventorySlotInfo.h $(GSDIR)/ItemLoaderManager.h \
  $(GSDIR)/ItemLoader.h $(COREDIR)/ExtraInfo.h \
  $(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
  $(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
  $(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
  $(GSDIR)/CreatureUtil.h $(GSDIR)/SlayerAttrExpTable.h \
  $(GSDIR)/SomethingGrowingUp.h $(SKILLDIR)/SlayerSkillSlot.h \
  $(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(GSDIR)/Vampire.h $(COREDIR)/PCVampireInfo.h \
  $(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCVampireInfo3.h \
  $(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
  $(SKILLDIR)/VampireSkillSlot.h $(GSDIR)/Ousters.h \
  $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
  $(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
  $(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
  $(GSDIR)/MonsterInfo.h $(GSDIR)/MonsterSummonInfo.h \
  $(GSDIR)/MonsterInfoTypes.h $(ITEMDIR)/QuestItem.h $(GSDIR)/ItemInfo.h \
  $(GSDIR)/InfoClassManager.h $(GSDIR)/StringPool.h \
  $(GSDIR)/ItemMineInfo.h $(GSDIR)/PacketUtil.h \
  $(GSDIR)/ItemGradeManager.h $(GSDIR)/ItemInfoManager.h \
  $(GSDIR)/FlagSet.h $(COREDIR)/Gpackets/GCCreateItem.h \
  $(COREDIR)/Gpackets/GCNPCResponse.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCDeleteInventoryItem.h \
  $(GSDIR)/SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h \
  $(GSDIR)/VariableManager.h $(GSDIR)/PVPSystemManager.h
