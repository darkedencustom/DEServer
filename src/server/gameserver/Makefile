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
VSHOME   = ../../..
BINDIR   = $(VSHOME)/bin
LIBDIR   = $(VSHOME)/lib
LOGDIR   = $(VSHOME)/log
SRCDIR   = ../..
COREDIR  = ../../Core
SERVDIR  = ..
DBDIR    = ../database
MYSQLDIR = /usr/lib/x86_64-linux-gnu
SKILLDIR = skill
ITEMDIR  = item
BILLINGDIR  = billing
WARDIR  = war
COUPLEDIR = couple
TESTDIR  = test
MISSIONDIR = mission
CTFDIR = ctf
SCRIPTDIR = script
PYLIBDIR = /usr/local/lib/python2.2/config
PYINCDIR = /usr/local/include/python2.2

#GQUESTDIR = ./gq
#SIMPLEQUESTDIR  = ./quest/Squest

#----------------------------------------------------------------------
# General Rules
#----------------------------------------------------------------------
.SUFFIXES    : .cpp .o

CC       = g++
DEFS     = -D__LINUX__ -D_REENTRANT -D__GAME_SERVER__ -D__DEBUG__  -D__COMBAT__
INCLUDES = -I$(COREDIR)/compat -I/usr/include/lua5.1 -I$(COREDIR) -I$(SERVDIR) -I$(DBDIR) -I$(SKILLDIR) -I$(ITEMDIR) -I$(BILLINGDIR) -I$(WARDIR) -I$(COUPLEDIR) -I$(TESTDIR) -I$(MISSIONDIR) -I$(SCRIPTDIR) -I.
CCFLAGS  = -Wall -c -g -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
#CCFLAGS  = -Wall -c -std=gnu++14 -Wno-deprecated -fno-enforce-eh-specs
#LIBS     = -L$(LIBDIR) -lItems -lQuest -lMofus -lGameServerDatabase -lServerCore -lGameServerPackets -lSkill -lCore -lGameServerBilling -lLuaScript -lGameServerTest -lWar -lCouple -lMission -lCTF -lGameServerCBilling -lxerces-c -lsicuuc -lsicudata -lCSAuth
#LIBS     = -L$(LIBDIR) -lItems -lQuest -lMofus -lGameServerDatabase -lServerCore -lGameServerPackets -lSkill -lCore -lGameServerBilling -lLuaScript -lWar -lCouple -lMission -lCTF -lGameServerCBilling -lxerces-c -lsicuuc -lsicudata -lCSAuth
#SYSLIBS  = -L$(MYSQLDIR) -static -lpthread -lnsl -lutil -lmysqlclient -llua5.1 -llualib -lz -lcppunit -lm -lssl
#SYSLIBS  = -L$(MYSQLDIR) -static -lpthread -lnsl -lutil -ldl -lmysqlclient -llua5.1 -llualib -lz 
#SYSLIBS  = -L$(MYSQLDIR) -static -lpthread -lnsl -lutil -ldl -lmysqlclient -llua5.1 -llualib -lz -lcppunit
#LIBS     = -L$(LIBDIR) -lItems -lQuest -lMofus -lGameServerDatabase -lServerCore -lGameServerPackets -lSkill -lCore -lGameServerBilling -lLuaScript -lGameServerTest -lWar -lCouple -lMission -lCTF -lGameServerCBilling -lxerces-c -lsicuuc -lsicudata -lCSAuth
#SYSLIBS  = -L$(MYSQLDIR) -static -lpthread -lnsl -lutil -ldl -lmysqlclient -llua5.1 -llualib -lz -lcppunit -lsybdb
#LIBS     = -L$(LIBDIR) -lItems -lQuest -lMofus -lGameServerDatabase -lServerCore -lGameServerPackets -lSkill -lCore -lGameServerBilling -lLuaScript -lWar -lCouple -lMission -lCTF -lGameServerCBilling -lxerces-c -lsicuuc -lsicudata -lCSAuth
# xerces/mysql/lua/sybdb now come from the system, so they must NOT be searched
# under $(LIBDIR) -- that directory still holds the 2009 32-bit archives.
LIBS     =-L$(LIBDIR) -lItems -lQuest -lGameServerDatabase -lServerCore -lGameServerPackets -lSkill -lCore -lGameServerBilling -lDEScript -lWar -lCouple -lMission -lCTF -lGameServerCBilling
SYSLIBS  = -L$(MYSQLDIR) -lxerces-c -lmysqlclient -llua5.1 -lsybdb -lpthread -lnsl -lutil -ldl -lz -lssl -lcrypto -lresolv -lrt -lm

.cpp.o :
	$(CC) $(CCFLAGS) $(DEFS) $(INCLUDES) $<

#----------------------------------------------------------------------
# Objects
#----------------------------------------------------------------------

MONSTER_OBJS = Monster.o MonsterInfo.o MonsterManager.o \
	MonsterAI.o Directive.o MonsterNameManager.o MonsterCounter.o 

ITEM_OBJS = Item.o ItemInfo.o ItemUtil.o \
	ItemFactoryManager.o ItemInfoManager.o ItemLoaderManager.o \
	SlayerCorpse.o VampireCorpse.o OustersCorpse.o MonsterCorpse.o

GUILD_OBJS = Party.o Guild.o GuildManager.o GuildUnion.o

EVENT_OBJS = Event.o EventManager.o EventShutdown.o \
	EventRegeneration.o EventSave.o EventMorph.o EventResurrect.o EventReloadInfo.o \
	EventTransport.o EventKick.o EventSystemMessage.o EventRefreshHolyLandPlayer.o EventHeadCount.o \
	EventCBilling.o EventAuth.o

EFFECT_OBJS = Effect.o EffectManager.o EffectSchedule.o EffectLoaderManager.o \
	EffectShutDown.o EffectHPRecovery.o EffectMPRecovery.o \
	EffectAlignmentRecovery.o EffectEnemyErase.o \
	EffectDecayCorpse.o EffectDecayItem.o EffectAftermath.o EffectComa.o \
	EffectPrecedence.o EffectTransportItem.o EffectAddItem.o EffectRelicTable.o \
	EffectHasSlayerRelic.o EffectHasVampireRelic.o EffectIncreaseAttr.o \
	EffectDeleteItem.o EffectSlayerRelic.o EffectVampireRelic.o EffectRelicPosition.o \
	EffectRelicLock.o EffectMasterLairPass.o EffectContinualGroundAttack.o \
	EffectGhost.o EffectTransportCreature.o EffectGrandMasterSlayer.o \
	EffectGrandMasterVampire.o EffectKillAftermath.o EffectHasBloodBible.o \
	EffectShrineHoly.o EffectShrineGuard.o EffectShrineShield.o \
	EffectTransportItemToCorpse.o EffectAddItemToCorpse.o \
	EffectHasRelic.o EffectHasCastleSymbol.o EffectLoveChain.o \
	EffectPKZoneRegen.o EffectPKZoneResurrection.o EffectGrandMasterOusters.o \
	EffectTranslation.o EffectLoud.o EffectMute.o \
	SimpleCreatureEffect.o EffectRefiniumTicket.o EffectFlagInsert.o EffectHasSweeper.o EffectKeepSweeper.o \
	EffectRegenZone.o EffectTryingPosition.o EffectTrying.o EffectTryRegenZone.o EffectOnBridge.o EffectHasPet.o \
	EffectPacketSend.o EffectDarknessForbidden.o EffectCastingTrap.o EffectWithWarning.o EffectKickOut.o EffectGDRLairClose.o \
	EffectEventQuestReset.o EffectShareHP.o EffectCanEnterGDRLair.o \
	EffectAutoTurret.o EffectTurretLaser.o EffectKillTimer.o EffectDragonEye.o EffectRegenerate.o EffectRecallMotorcycle.o \
	EffectRideMotorcycle.o EffectDonation200501.o SimpleTileEffect.o EffectDeleteTile.o \
	EffectBehemothForceScroll.o EffectSafeForceScroll.o EffectCarnelianForceScroll.o EffectHoodlumStigma.o \
	EffectFuriousIncense.o EffectStrengthenIncense.o EffectHyperactiveIncense.o EffectImpregnableIncense.o \
	EffectGreyfellForceScroll.o EffectSoviusForceScroll.o EffectMirForceScroll.o EffectWarpMonster.o \
	EffectBonusExp.o EffectMysteryPotion.o EffectOdinForceScroll.o EffectTituosForceScroll.o EffectPetBonusExp.o \
	EffectVampireHeroItem.o EffectSlayerHeroItem.o EffectOustersHeroItem.o \
	EffectMenegrothDoungeon.o \
	EffectCabracamAltar.o \
	EffectSummonCabracam.o \
	EffectSlayerLevelWarHeroItem.o \
	EffectVampireLevelWarHeroItem.o \
	EffectOustersLevelWarHeroItem.o \
	EffectDSG.o \
	EffectQuestSuccess.o \
	EffectRankBonusExpRed.o \
	EffectRankBonusExpBlue.o \
	EffectPremiumService.o \
	EffectExtremeForceScroll.o \
	EventReloginToSharedServer.o \
	EffectPromotionAngelFlutter.o \
	EffectPromotionBatWing.o \
	EffectPromotionButterflyWing.o \
	EffectLifeForceScroll.o \
	EffectAccuraForceScroll.o \
	EffectBonusExpSecond.o \
	EffectBonusExpAdvance.o \
	EffectChaoticExp.o \

#	EffectDropBloodBible.o

GQUEST_OBJS = \
	GQuestInfo.o GQuestManager.o GQuestElement.o GQuestStatus.o GQuestInventory.o \
	GQuestLevelElement.o GQuestTimeElement.o GQuestGiveVampireExpElement.o GQuestBloodDrainElement.o GQuestSayNPCElement.o GQuestExecuteElement.o \
	GQuestGiveQuestItemElement.o GQuestLoseQuestItemElement.o GQuestGiveItemElement.o GQuestTamePetElement.o GQuestRaceElement.o GQuestKilledElement.o \
	GQuestGiveDomainExpElement.o GQuestGiveMoneyElement.o GQuestSkillLevelElement.o GQuestRideMotorcycleElement.o GQuestGiveOustersExpElement.o \
	GQuestTouchWayPointElement.o GQuestHasQuestItemElement.o GQuestPartyDissectElement.o GQuestKillMonsterElement.o GQuestGiveEventQuestItemElement.o \
	GQuestEventPartyElement.o GQuestEventPartyCrashElement.o GQuestCompleteQuestElement.o GQuestFastMoveElement.o GQuestIllegalWarpElement.o \
	GQuestCheckPoint.o GQuestTravelElement.o GQuestORElement.o GQuestNOTElement.o GQuestRandomElement.o GQuestAdvancementClassLevelElement.o \
	GQuestClearDynamicZoneElement.o GQuestAddEffectElement.o GQuestRemoveEffectElement.o GQuestSetEnterDynamicZoneElement.o \
	GQuestEnterDynamicZoneElement.o GQuestStartOtherQuestElement.o GQuestGiveAdvancementClassExpElement.o GQuestAdvanceClassElement.o \
	GQuestWarpElement.o GQuestEnterZoneElement.o GQuestGenderElement.o GQuestSlayerHighestSkillDomainElement.o


OBJS = main.o Zone.o Slayer.o Vampire.o Ousters.o OustersEXPInfo.o \
	ClientManager.o ConnectionInfoManager.o \
	Creature.o CreatureManager.o DarkLightInfo.o Corpse.o \
	GamePlayer.o GameServer.o IncomingPlayerManager.o SharedServerClient.o \
	InfoClassManager.o Inventory.o LoginServerManager.o SharedServerManager.o\
	NPC.o NPCManager.o ResurrectLocationManager.o PCFinder.o \
	TelephoneCenter.o ParkingCenter.o PCManager.o Portal.o \
	Script.o ScriptManager.o ThreadManager.o ThreadPool.o \
	Tile.o Sector.o TimeManager.o GoodsInventory.o GoodsInfoManager.o \
	VisionInfo.o WeatherInfo.o WeatherManager.o \
	ZoneInfo.o ZoneGroup.o ZoneGroupManager.o ZoneInfoManager.o \
	ZonePlayerManager.o ZoneGroupThread.o \
	ObjectManager.o AbilityBalance.o \
	PlayerCreature.o ZoneUtil.o Treasure.o  \
	PacketUtil.o ConnectionInfo.o InventorySlot.o  \
	ObjectRegistry.o WayPoint.o OptionInfo.o \
	VolumeInfo.o VampEXPInfo.o ItemRack.o ShopRack.o Stash.o Garbage.o \
	ShopTemplate.o PriceManager.o CreatureUtil.o ItemMap.o \
	TradeManager.o FlagSet.o AlignmentManager.o \
	SkillInfo.o SkillDomainInfoManager.o SkillParentInfo.o InitAllStat.o \
	PrecedenceTable.o VariableManager.o CombatInfoManager.o \
	UniqueItemManager.o \
	MasterLairInfoManager.o MasterLairManager.o \
	MonsterSummonInfo.o LuckInfo.o \
	LogNameManager.o RankBonusInfo.o RankBonus.o \
	CastleInfoManager.o HolyLandRaceBonus.o \
	ShrineInfoManager.o GlobalItemPositionLoader.o \
	RelicUtil.o HolyLandManager.o \
	BloodBibleBonus.o BloodBibleBonusManager.o \
	CastleShrineInfoManager.o SkillPropertyManager.o \
	StringPool.o PKZoneInfoManager.o \
	GameServerGroupInfoManager.o DefaultOptionSetInfo.o \
	CastleSkillInfo.o TimeLimitItemManager.o ItemMineInfo.o \
	EventItemUtil.o SweeperSet.o SweeperBonus.o SweeperBonusManager.o \
	LevelWar.o LevelWarManager.o LevelWarZoneInfoManager.o \
	RegenZoneManager.o PetTypeInfo.o PetUtil.o PetAttrInfo.o PetExpInfo.o \
	RankExpTable.o SlayerAttrExpTable.o \
	Pet.o SystemAvailabilitiesManager.o LocalIP.o \
	ItemGradeManager.o EventZoneInfo.o SMSServiceThread.o \
	SMSAddressBook.o FiniteStateMachine.o GDRLairManager.o GDRLairAbstractStates.o \
	NicknameBook.o LevelNickInfoManager.o SiegeManager.o \
	BroadcastFilter.o Store.o AdvancementClassExpTable.o DynamicZoneManager.o \
	DynamicZoneInfo.o DynamicZone.o DynamicZoneGroup.o DynamicZoneGateOfAlter.o \
	DynamicZoneAlterOfBlood.o DynamicZoneFactoryManager.o DynamicZoneSlayerMirrorOfAbyss.o \
	DynamicZoneVampireMirrorOfAbyss.o DynamicZoneOustersMirrorOfAbyss.o \
	NewYear2005ItemUtil.o BalloonHeadbandUtil.o Fall2005ItemUtil.o \
	ViewAbility.o Viewable.o Born.o \
	MikllizzLairManager.o CastleDungeonMonsterManager.o RodinBossManager.o DraculaCastleManager.o EffectHasMihnea.o EffectMihneaSeal.o EffectMihneaDoor.o \
	EventSurvivalZoneManager.o \
	PlayerInventory.o ContractOfBloodUtil.o \
	HellGardenTowerManager.o \
    ThirdEnchantInfo.o \
    ItemClassInfo.o \
	ContributeInfo.o \
	HeroItemManager.o\
    MenegrothDoungeonManager.o \
    MenegrothDoungeonZoneManager.o \
	LevelWarItemManager.o \
	EventGiftBoxRewardManager.o \
	EventBlitzRewardManager.o \
	DynamicZoneScript.o DynamicZoneScriptGroup.o \
	EffectScript.o \
	SkillScript.o \
	InstanceDoungeonManager.o \
	TimeCheckerLoader.o \
	WeekItemListManager.o \
	GlobalNPCManager.o \
	SkillCastingTimeManager.o \
	md5.o \
	PVPSystemManager.o \
	$(MONSTER_OBJS) $(ITEM_OBJS) $(GUILD_OBJS) $(EFFECT_OBJS) $(EVENT_OBJS) $(COMBAT_OBJS) $(GQUEST_OBJS)

SRCS = $(OBJS:.o=.cpp)

TARGET = $(BINDIR)/gameserver


#----------------------------------------------------------------------
# actions
#----------------------------------------------------------------------
all :
	$(MAKE) -C mission
	$(MAKE) -C couple
	$(MAKE) -C war
	$(MAKE) -C item
	$(MAKE) -C skill
	$(MAKE) -C quest
	$(MAKE) -C billing
#	$(MAKE) -C test
	$(MAKE) -C ctf
#	$(MAKE) -C mofus
	$(MAKE) -C script 
	$(MAKE) $(TARGET)

gameserver :
	$(MAKE) -C mission
	$(MAKE) -C couple
	$(MAKE) -C war
	$(MAKE) -C item
	$(MAKE) -C skill
	$(MAKE) -C quest
	$(MAKE) -C billing
#	$(MAKE) -C test
	$(MAKE) -C ctf
#	$(MAKE) -C mofus
	$(MAKE) -C script 
	$(MAKE) $(TARGET)

$(TARGET) : $(OBJS) $(LIBDIR)/libGameServerDatabase.a $(LIBDIR)/libSkill.a $(LIBDIR)/libGameServerPackets.a $(LIBDIR)/libItems.a $(LIBDIR)/libQuest.a $(LIBDIR)/libServerCore.a $(LIBDIR)/libCore.a $(LIBDIR)/libSharedServerPackets.a $(LIBDIR)/libGameServerBilling.a $(LIBDIR)/libDEScript.a $(LIBDIR)/libWar.a $(LIBDIR)/libCouple.a $(LIBDIR)/libMission.a $(LIBDIR)/libCTF.a $(LIBDIR)/libGameServerCBilling.a
	$(CC) -o $@ $(OBJS) $(LIBS) $(SYSLIBS) -rdynamic

clean :
	rm -rf *.o
	$(MAKE) -C mission clean
	$(MAKE) -C couple clean
	$(MAKE) -C war clean
	$(MAKE) -C skill clean
	$(MAKE) -C item clean
	$(MAKE) -C quest clean
	$(MAKE) -C billing clean
#	$(MAKE) -C test clean
	$(MAKE) -C ctf clean
	$(MAKE) -C script clean
#	$(MAKE) -C mofus clean

cleanall :
	rm -rf *.o $(TARGET)
	$(MAKE) -C mission cleanall
	$(MAKE) -C couple cleanall
	$(MAKE) -C war cleanall
	$(MAKE) -C skill cleanall
	$(MAKE) -C item cleanall
	$(MAKE) -C quest cleanall
	$(MAKE) -C billing cleanall
#	$(MAKE) -C test cleanall
	$(MAKE) -C ctf cleanall
#	$(MAKE) -C mofus cleanall
	$(MAKE) -C script cleanall 

depall :
	$(MAKE) -C war depall
	$(MAKE) -C skill depall
	$(MAKE) -C item depall
	$(MAKE) -C quest depall
	$(MAKE) -C billing depall
#	$(MAKE) -C test depall
	$(MAKE) -C mission depall
	$(MAKE) -C couple depall
	$(MAKE) -C ctf depall
#	$(MAKE) -C mofus depall
	$(MAKE) -C script depall 
	gccmakedep $(SRCS) $(INCLUDES)

dep :
	gccmakedep $(SRCS) $(INCLUDES)


# DO NOT DELETE
main.o: main.cpp $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h GameServer.h \
$(COREDIR)/Properties.h $(SERVDIR)/LogClient.h
Zone.o: Zone.cpp Zone.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
Tile.h Object.h $(COREDIR)/Assert.h Creature.h EffectManager.h Effect.h \
$(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(SERVDIR)/LogClient.h ZoneGroup.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
$(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h ZoneInfo.h \
ZoneInfoManager.h ZonePlayerManager.h $(SERVDIR)/PlayerManager.h \
$(COREDIR)/Player.h NPCManager.h MonsterManager.h MonsterCounter.h \
MasterLairInfoManager.h MasterLairManager.h DynamicZoneScript.h \
DynamicZone.h Monster.h MonsterInfo.h MonsterSummonInfo.h \
MonsterInfoTypes.h Treasure.h PrecedenceTable.h DynamicZoneGroup.h \
MikllizzLairManager.h EventSurvivalZoneManager.h \
$(WARDIR)/WarScheduler.h $(WARDIR)/Work.h $(WARDIR)/Scheduler.h \
$(WARDIR)/Schedule.h $(COREDIR)/VSDateTime.h $(WARDIR)/War.h \
$(WARDIR)/WarSystem.h $(COREDIR)/Gpackets/GCWarList.h \
$(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
$(COREDIR)/RaceWarInfo.h $(MISSIONDIR)/QuestManager.h \
$(MISSIONDIR)/QuestInfo.h $(MISSIONDIR)/RewardClass.h \
$(COREDIR)/Gpackets/GCNPCResponse.h $(MISSIONDIR)/QuestStatus.h \
VisionInfo.h EffectSchedule.h $(COREDIR)/NPCInfo.h WeatherManager.h \
ItemInfo.h DarkLightInfo.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h Slayer.h \
PlayerCreature.h InventorySlot.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h NPC.h \
$(COUPLEDIR)/PartnerWaitingManager.h $(COREDIR)/Properties.h ZoneUtil.h \
PacketUtil.h TradeManager.h ParkingCenter.h $(ITEMDIR)/Motorcycle.h \
InfoClassManager.h ItemFactory.h $(ITEMDIR)/Relic.h ItemFactoryManager.h \
CombatInfoManager.h $(SERVDIR)/PaySystem.h GamePlayer.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h VariableManager.h \
CastleInfoManager.h RelicUtil.h HolyLandManager.h \
BloodBibleBonusManager.h BloodBibleBonus.h ItemUtil.h \
ShrineInfoManager.h TimeManager.h PKZoneInfoManager.h \
$(COREDIR)/Cpackets/CGSay.h StringPool.h FlagSet.h PCFinder.h \
DefaultOptionSetInfo.h LevelWarZoneInfoManager.h SweeperBonusManager.h \
BroadcastFilter.h $(CTFDIR)/FlagManager.h \
$(COREDIR)/Gpackets/GCFlagWarStatus.h RegenZoneManager.h MonsterCorpse.h \
Corpse.h $(SKILLDIR)/EffectDarkness.h EffectLoader.h \
$(SKILLDIR)/EffectVampirePortal.h SlayerCorpse.h VampireCorpse.h \
OustersCorpse.h EffectLoaderManager.h EffectDecayCorpse.h \
EffectDecayItem.h $(SKILLDIR)/EffectObservingEye.h \
$(SKILLDIR)/EffectGnomesWhisper.h EffectDecayMotorcycle.h \
EffectCallMotorcycle.h EffectAddItem.h EffectDeleteItem.h \
EffectTransportItem.h $(SKILLDIR)/EffectSanctuary.h EffectRelicTable.h \
EffectHasSlayerRelic.h EffectHasRelic.h EffectHasVampireRelic.h \
EffectVampireRelic.h EffectSlayerRelic.h EffectHasBloodBible.h \
EffectShrineGuard.h EffectShrineHoly.h EffectShrineShield.h \
EffectAddItemToCorpse.h EffectTransportItemToCorpse.h \
EffectHasCastleSymbol.h EffectPKZoneRegen.h \
EffectContinualGroundAttack.h EventTransport.h \
  $(COREDIR)/Gpackets/GCAddBurrowingCreature.h \
  $(COREDIR)/Gpackets/GCAddVampireFromTransformation.h \
  $(COREDIR)/Gpackets/GCAddMonsterFromTransformation.h \
  $(COREDIR)/Gpackets/GCUntransformOK.h \
  $(COREDIR)/Gpackets/GCUntransformFail.h \
  $(COREDIR)/Gpackets/GCAddVampireFromBurrowing.h \
  $(COREDIR)/Gpackets/GCAddMonsterFromBurrowing.h \
$(COREDIR)/Gpackets/GCAddWolf.h $(COREDIR)/Gpackets/GCAddBat.h \
  $(COREDIR)/Gpackets/GCAddSlayerCorpse.h \
  $(COREDIR)/Gpackets/GCAddVampireCorpse.h \
  $(COREDIR)/Gpackets/GCAddOustersCorpse.h \
  $(COREDIR)/Gpackets/GCAddMonsterCorpse.h \
  $(COREDIR)/Gpackets/GCAddEffectToTile.h \
  $(COREDIR)/Gpackets/GCAddVampirePortal.h \
  $(COREDIR)/Gpackets/GCDeleteEffectFromTile.h \
  $(COREDIR)/Gpackets/GCMineExplosionOK1.h \
  $(COREDIR)/Gpackets/GCMineExplosionOK2.h \
  $(COREDIR)/Gpackets/GCAddInstalledMineToZone.h \
  $(COREDIR)/Gpackets/GCAddItemToZone.h \
$(COREDIR)/Gpackets/GCSystemMessage.h $(COREDIR)/Gpackets/GCFastMove.h \
$(COREDIR)/Gpackets/GCMove.h $(COREDIR)/Gpackets/GCMoveOK.h \
$(COREDIR)/Gpackets/GCMoveError.h $(COREDIR)/Gpackets/GCAddMonster.h \
  $(COREDIR)/Gpackets/GCAddNewItemToZone.h \
$(COREDIR)/Gpackets/GCDropItemToZone.h $(COREDIR)/Gpackets/GCAddNPC.h \
$(COREDIR)/Gpackets/GCAddSlayer.h $(COREDIR)/PetInfo.h \
$(COREDIR)/types/PetTypes.h $(COREDIR)/NicknameInfo.h \
$(COREDIR)/StoreInfo.h $(COREDIR)/Gpackets/GCAddVampire.h \
$(COREDIR)/Gpackets/GCAddOusters.h $(COREDIR)/Gpackets/GCDeleteObject.h \
$(COREDIR)/Gpackets/GCSetPosition.h $(COREDIR)/Gpackets/GCUnburrowOK.h \
  $(COREDIR)/Gpackets/GCUnburrowFail.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(COREDIR)/Gpackets/GCAddEffect.h \
$(COREDIR)/Gpackets/GCKnockBack.h $(COREDIR)/Gpackets/GCNoticeEvent.h \
  $(COREDIR)/Gpackets/GCNPCInfo.h \
  $(COREDIR)/Gpackets/GCHolyLandBonusInfo.h \
  $(COREDIR)/BloodBibleBonusInfo.h \
$(COREDIR)/Gpackets/GCSweeperBonusInfo.h $(COREDIR)/SweeperBonusInfo.h \
  $(COREDIR)/Gpackets/GCRegenZoneStatus.h \
  $(COREDIR)/Gpackets/GCUnionOfferList.h \
  $(COREDIR)/Gpackets/GCMyStoreInfo.h \
$(COREDIR)/Gpackets/GCGetOffMotorCycle.h $(ITEMDIR)/VampirePortalItem.h \
$(SERVDIR)/Profile.h ResurrectLocationManager.h LevelWarManager.h \
SweeperSet.h $(ITEMDIR)/Sweeper.h LevelWarItemManager.h \
$(ITEMDIR)/WarItem.h NicknameBook.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h EffectCastingTrap.h \
$(COREDIR)/Gpackets/GGCommand.h $(SERVDIR)/GameServerInfoManager.h \
$(SERVDIR)/GameServerInfo.h LoginServerManager.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h $(COREDIR)/DatagramSocket.h SiegeManager.h \
$(SKILLDIR)/SkillUtil.h GDRLairManager.h FiniteStateMachine.h \
GDRLairAbstractStates.h Store.h HellGardenTowerManager.h \
MenegrothDoungeonZoneManager.h MenegrothDoungeonManager.h GuildUnion.h \
GuildManager.h DynamicZoneManager.h ViewAbility.h Viewable.h \
ViewEffect.h ItemInfoManager.h $(COREDIR)/Gpackets/GCCreateItem.h \
$(SKILLDIR)/SkillHandlerManager.h $(SKILLDIR)/SkillHandler.h SkillInfo.h \
$(SKILLDIR)/HitRoll.h PVPSystemManager.h
Slayer.o: Slayer.cpp $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(DBDIR)/Connection.h \
$(SERVDIR)/Mutex.h $(DBDIR)/Statement.h $(DBDIR)/Result.h Slayer.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h InventorySlot.h Item.h \
Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(SKILLDIR)/Skill.h \
$(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
$(COREDIR)/Gpackets/GCModifyInformation.h $(COREDIR)/Player.h \
$(SERVDIR)/LogClient.h SkillInfo.h ItemInfoManager.h ItemInfo.h \
InfoClassManager.h ParkingCenter.h $(ITEMDIR)/Motorcycle.h ItemFactory.h \
$(SKILLDIR)/SkillHandlerManager.h $(SKILLDIR)/SkillHandler.h Vampire.h \
$(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h $(SKILLDIR)/HitRoll.h \
$(SKILLDIR)/SkillUtil.h ZoneUtil.h GamePlayer.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h SkillDomainInfoManager.h \
ResurrectLocationManager.h $(WARDIR)/WarSystem.h $(WARDIR)/Scheduler.h \
$(WARDIR)/Work.h $(WARDIR)/Schedule.h $(COREDIR)/Gpackets/GCWarList.h \
$(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
$(COREDIR)/RaceWarInfo.h PKZoneInfoManager.h $(COREDIR)/Cpackets/CGSay.h \
CastleInfoManager.h CastleSkillInfo.h EffectLoaderManager.h \
EffectLoader.h AbilityBalance.h Stash.h TradeManager.h FlagSet.h \
$(COREDIR)/Shape.h VariableManager.h ItemUtil.h PacketUtil.h \
$(ITEMDIR)/AR.h ConcreteItem.h ItemPolicies.h $(ITEMDIR)/SR.h \
$(ITEMDIR)/SG.h $(ITEMDIR)/SMG.h $(ITEMDIR)/Belt.h $(ITEMDIR)/Skull.h \
$(ITEMDIR)/SubInventory.h $(ITEMDIR)/Key.h $(SKILLDIR)/CastleSkillSlot.h \
$(SKILLDIR)/EffectBless.h $(SKILLDIR)/EffectDancingSword.h \
$(SKILLDIR)/EffectGhostBlade.h $(SKILLDIR)/EffectChargingPower.h \
$(SKILLDIR)/EffectPotentialExplosion.h $(SKILLDIR)/EffectParalyze.h \
$(SKILLDIR)/EffectDoom.h $(SKILLDIR)/EffectProtectionFromPoison.h \
  $(SKILLDIR)/EffectProtectionFromCurse.h \
$(SKILLDIR)/EffectProtectionFromAcid.h EffectGrandMasterSlayer.h \
EffectHoodlumStigma.h EffectRecallMotorcycle.h EffectBonusExp.h \
EffectBonusExpSecond.h EffectBonusExpAdvance.h EffectChaoticExp.h \
$(COREDIR)/Cpackets/CGRideMotorCycle.h $(COREDIR)/Gpackets/GCAddEffect.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(COREDIR)/Gpackets/GCChangeShape.h \
$(COREDIR)/Gpackets/GCTakeOff.h $(COREDIR)/Gpackets/GCSkillInfo.h \
  $(COREDIR)/Gpackets/GCRealWearingInfo.h \
  $(COREDIR)/Gpackets/GCStatusCurrentHP.h \
  $(COREDIR)/Gpackets/GCTradeFinish.h \
  $(COREDIR)/Gpackets/GCOtherModifyInfo.h \
$(COREDIR)/Gpackets/GCPetStashList.h $(COREDIR)/PetInfo.h \
$(COREDIR)/types/PetTypes.h $(COREDIR)/Gpackets/GCAddSlayer.h \
$(COREDIR)/NicknameInfo.h $(COREDIR)/StoreInfo.h \
$(COREDIR)/Gpackets/GCGetOffMotorCycle.h $(COREDIR)/Rpackets/RCSay.h \
$(COREDIR)/DatagramPacket.h $(COREDIR)/Datagram.h LoginServerManager.h \
$(COREDIR)/DatagramSocket.h $(COREDIR)/Properties.h \
$(WARDIR)/RaceWarLimiter.h PCLimiter.h TimeLimitItemManager.h \
RankExpTable.h SystemAvailabilitiesManager.h \
$(COREDIR)/Gpackets/GCSystemAvailabilities.h GuildUnion.h \
$(COREDIR)/Gpackets/GCUnionOfferList.h Store.h \
AdvancementClassExpTable.h DynamicZone.h DynamicZoneGroup.h \
DynamicZoneManager.h LevelWarZoneInfoManager.h \
$(SERVDIR)/DBExecuteManager.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
Vampire.o: Vampire.cpp Vampire.h PlayerCreature.h Creature.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
EffectManager.h Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Inventory.h \
VolumeInfo.h Zone.h Tile.h Obstacle.h Portal.h quest/TriggerManager.h \
quest/Trigger.h quest/Condition.h quest/PropertyBuffer.h Sector.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/PCVampireInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCVampireInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/VampireSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h CreatureUtil.h \
$(SKILLDIR)/VampireSkillSlot.h $(SKILLDIR)/Skill.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
$(COREDIR)/Player.h SkillInfo.h Slayer.h $(COREDIR)/PCSlayerInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/SlayerSkillSlot.h EffectLoaderManager.h EffectLoader.h \
SkillParentInfo.h ItemInfoManager.h ItemInfo.h InfoClassManager.h \
AbilityBalance.h Stash.h TradeManager.h FlagSet.h VampEXPInfo.h \
ItemUtil.h PacketUtil.h $(SKILLDIR)/SkillUtil.h Ousters.h \
$(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
$(COREDIR)/Shape.h GamePlayer.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h RankExpTable.h VariableManager.h \
$(WARDIR)/WarSystem.h $(WARDIR)/Scheduler.h $(WARDIR)/Work.h \
$(WARDIR)/Schedule.h $(COREDIR)/Gpackets/GCWarList.h \
$(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
$(COREDIR)/RaceWarInfo.h ResurrectLocationManager.h PKZoneInfoManager.h \
$(COREDIR)/Cpackets/CGSay.h TimeLimitItemManager.h CastleSkillInfo.h \
$(COREDIR)/PetInfo.h $(COREDIR)/types/PetTypes.h \
$(SKILLDIR)/SkillHandlerManager.h $(SKILLDIR)/SkillHandler.h Monster.h \
MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h Treasure.h \
PrecedenceTable.h $(SKILLDIR)/HitRoll.h ZoneUtil.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h SkillCastingTimeManager.h $(ITEMDIR)/AR.h \
ConcreteItem.h ItemPolicies.h ItemFactory.h $(ITEMDIR)/SR.h \
$(ITEMDIR)/SG.h $(ITEMDIR)/SMG.h $(ITEMDIR)/PetItem.h $(ITEMDIR)/Belt.h \
$(ITEMDIR)/Skull.h $(ITEMDIR)/SubInventory.h \
$(SKILLDIR)/VampireCastleSkillSlot.h $(SKILLDIR)/EffectBless.h \
$(SKILLDIR)/EffectParalyze.h $(SKILLDIR)/EffectDoom.h \
$(SKILLDIR)/EffectTransformToWolf.h $(SKILLDIR)/EffectTransformToBat.h \
EffectGrandMasterVampire.h $(WARDIR)/RaceWarLimiter.h PCLimiter.h \
EffectHoodlumStigma.h $(COREDIR)/Gpackets/GCChangeShape.h \
  $(COREDIR)/Gpackets/GCSkillInfo.h \
  $(COREDIR)/Gpackets/GCRealWearingInfo.h \
$(COREDIR)/Gpackets/GCStatusCurrentHP.h $(COREDIR)/Gpackets/GCTakeOff.h \
  $(COREDIR)/Gpackets/GCOtherModifyInfo.h \
$(COREDIR)/Gpackets/GCPetStashList.h $(COREDIR)/Gpackets/GCAddVampire.h \
$(COREDIR)/NicknameInfo.h $(COREDIR)/StoreInfo.h \
$(COREDIR)/Gpackets/GCAddBurrowingCreature.h GuildUnion.h \
$(COREDIR)/Gpackets/GCUnionOfferList.h Store.h \
AdvancementClassExpTable.h DynamicZone.h DynamicZoneGroup.h \
ViewAbility.h SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h \
$(SERVDIR)/DBExecuteManager.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
Ousters.o: Ousters.cpp Ousters.h PlayerCreature.h Creature.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
EffectManager.h Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Inventory.h \
VolumeInfo.h Zone.h Tile.h Obstacle.h Portal.h quest/TriggerManager.h \
quest/Trigger.h quest/Condition.h quest/PropertyBuffer.h Sector.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/PCOustersInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/OustersSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h CreatureUtil.h \
$(SKILLDIR)/OustersSkillSlot.h $(SKILLDIR)/Skill.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
$(COREDIR)/Player.h SkillInfo.h Slayer.h $(COREDIR)/PCSlayerInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/SlayerSkillSlot.h EffectLoaderManager.h EffectLoader.h \
SkillParentInfo.h ItemInfoManager.h ItemInfo.h InfoClassManager.h \
AbilityBalance.h Stash.h TradeManager.h FlagSet.h OustersEXPInfo.h \
ItemUtil.h PacketUtil.h $(SKILLDIR)/SkillUtil.h Vampire.h \
$(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
$(COREDIR)/Shape.h GamePlayer.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h RankExpTable.h VariableManager.h \
$(WARDIR)/WarSystem.h $(WARDIR)/Scheduler.h $(WARDIR)/Work.h \
$(WARDIR)/Schedule.h $(COREDIR)/Gpackets/GCWarList.h \
$(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
$(COREDIR)/RaceWarInfo.h ResurrectLocationManager.h PKZoneInfoManager.h \
$(COREDIR)/Cpackets/CGSay.h TimeLimitItemManager.h \
$(SKILLDIR)/SkillHandlerManager.h $(SKILLDIR)/SkillHandler.h Monster.h \
MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h Treasure.h \
PrecedenceTable.h $(SKILLDIR)/HitRoll.h ZoneUtil.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h SkillCastingTimeManager.h $(ITEMDIR)/AR.h \
ConcreteItem.h ItemPolicies.h ItemFactory.h $(ITEMDIR)/SR.h \
$(ITEMDIR)/SG.h $(ITEMDIR)/SMG.h $(ITEMDIR)/Belt.h $(ITEMDIR)/Skull.h \
$(ITEMDIR)/OustersWristlet.h $(ITEMDIR)/OustersStone.h \
$(ITEMDIR)/OustersArmsband.h $(ITEMDIR)/SubInventory.h \
$(SKILLDIR)/EffectBless.h $(SKILLDIR)/EffectParalyze.h \
$(SKILLDIR)/EffectDoom.h $(SKILLDIR)/EffectTransformToWolf.h \
$(SKILLDIR)/EffectTransformToBat.h $(SKILLDIR)/EffectReactiveArmor.h \
EffectGrandMasterOusters.h $(WARDIR)/RaceWarLimiter.h PCLimiter.h \
EffectHoodlumStigma.h $(COREDIR)/Gpackets/GCChangeShape.h \
  $(COREDIR)/Gpackets/GCSkillInfo.h \
  $(COREDIR)/Gpackets/GCRealWearingInfo.h \
$(COREDIR)/Gpackets/GCStatusCurrentHP.h $(COREDIR)/Gpackets/GCTakeOff.h \
  $(COREDIR)/Gpackets/GCOtherModifyInfo.h \
$(COREDIR)/Gpackets/GCPetStashList.h $(COREDIR)/PetInfo.h \
$(COREDIR)/types/PetTypes.h $(COREDIR)/Gpackets/GCAddOusters.h \
$(COREDIR)/NicknameInfo.h $(COREDIR)/StoreInfo.h CastleSkillInfo.h \
$(SKILLDIR)/OustersCastleSkillSlot.h GuildUnion.h \
$(COREDIR)/Gpackets/GCUnionOfferList.h Store.h \
AdvancementClassExpTable.h DynamicZone.h DynamicZoneGroup.h \
  SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h \
$(SERVDIR)/DBExecuteManager.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
OustersEXPInfo.o: OustersEXPInfo.cpp OustersEXPInfo.h \
$(COREDIR)/Exception.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/StringStream.h $(COREDIR)/Assert.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h
ClientManager.o: ClientManager.cpp ClientManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(SERVDIR)/Timeval.h EventManager.h Event.h $(SERVDIR)/Mutex.h \
$(COREDIR)/Socket.h $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
ThreadManager.h $(COREDIR)/Assert.h ThreadPool.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h $(COREDIR)/ServerSocket.h \
$(COREDIR)/Properties.h IncomingPlayerManager.h \
$(SERVDIR)/PlayerManager.h GamePlayer.h $(COREDIR)/Player.h \
$(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/SocketOutputStream.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/SocketInputStream.h \
$(COREDIR)/Packet.h $(COREDIR)/PlayerStatus.h $(SKILLDIR)/Skill.h \
$(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h Item.h Object.h Effect.h \
EffectManager.h $(COREDIR)/EffectInfo.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/DatagramSocket.h $(COREDIR)/Datagram.h \
ConnectionInfoManager.h ConnectionInfo.h ZonePlayerManager.h \
ZoneGroupManager.h ZoneGroup.h Zone.h Tile.h Creature.h Obstacle.h \
Portal.h quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/GameTime.h $(COREDIR)/Gpackets/GMServerInfo.h \
$(COREDIR)/DatagramPacket.h VariableManager.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(WARDIR)/WarSystem.h $(WARDIR)/Scheduler.h \
$(WARDIR)/Work.h $(WARDIR)/Schedule.h $(COREDIR)/Gpackets/GCWarList.h \
$(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
$(COREDIR)/RaceWarInfo.h ParkingCenter.h $(ITEMDIR)/Motorcycle.h \
ItemInfo.h InfoClassManager.h ItemFactory.h ItemLoader.h \
$(CTFDIR)/FlagManager.h $(COREDIR)/Gpackets/GCFlagWarStatus.h \
GDRLairManager.h FiniteStateMachine.h GDRLairAbstractStates.h LocalIP.h \
$(COREDIR)/TOpackets/GTOAcknowledgement.h LoginServerManager.h \
$(COREDIR)/Gpackets/GCSystemMessage.h $(COREDIR)/TimeChecker.h \
$(COREDIR)/../server/Timeval.h StringPool.h
ConnectionInfoManager.o: ConnectionInfoManager.cpp \
ConnectionInfoManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(SERVDIR)/Mutex.h ConnectionInfo.h $(SERVDIR)/Timeval.h \
$(COREDIR)/Assert.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h ZoneGroup.h \
Zone.h Tile.h Object.h Creature.h EffectManager.h Effect.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
$(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h ZoneGroupManager.h \
LoginServerManager.h $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h \
$(COREDIR)/DatagramSocket.h ZonePlayerManager.h \
$(SERVDIR)/PlayerManager.h $(COREDIR)/Player.h $(COREDIR)/Properties.h \
LogDef.h VariableManager.h
Creature.o: Creature.cpp Creature.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h EffectManager.h Effect.h $(SERVDIR)/Timeval.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ZoneInfo.h Zone.h Tile.h Item.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
ZoneInfoManager.h ZoneGroup.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
$(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h ZoneGroupManager.h \
Slayer.h PlayerCreature.h InventorySlot.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
ZoneUtil.h VisionInfo.h $(COREDIR)/Gpackets/GCSay.h Viewable.h \
ViewEffect.h ViewAbility.h
CreatureManager.o: CreatureManager.cpp CreatureManager.h Creature.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
EffectManager.h Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(SERVDIR)/Mutex.h GamePlayer.h \
$(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
$(COREDIR)/VSDateTime.h Item.h $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
ZoneGroupManager.h ZoneGroup.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
$(COREDIR)/Datagram.h ZoneInfo.h ZoneInfoManager.h ZonePlayerManager.h \
$(SERVDIR)/PlayerManager.h IncomingPlayerManager.h \
$(COREDIR)/ServerSocket.h $(COREDIR)/DatagramSocket.h \
ConnectionInfoManager.h ConnectionInfo.h Slayer.h PlayerCreature.h \
InventorySlot.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
$(COREDIR)/Gpackets/GCModifyInformation.h Vampire.h \
$(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
$(SERVDIR)/LogClient.h LevelWarZoneInfoManager.h SweeperBonusManager.h \
  $(COREDIR)/Gpackets/GCCreatureDied.h
DarkLightInfo.o: DarkLightInfo.cpp DarkLightInfo.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(COREDIR)/GameTime.h $(COREDIR)/SocketInputStream.h \
$(COREDIR)/Socket.h $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h TimeManager.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h Zone.h Tile.h Object.h Creature.h \
EffectManager.h Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h Item.h Obstacle.h Portal.h quest/TriggerManager.h \
quest/Trigger.h quest/Condition.h quest/PropertyBuffer.h Sector.h \
ObjectRegistry.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h
Corpse.o: Corpse.cpp Corpse.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
Item.h Object.h $(COREDIR)/Assert.h Effect.h $(SERVDIR)/Timeval.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ItemFactory.h Zone.h Tile.h Creature.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
Inventory.h VolumeInfo.h InventorySlot.h ItemUtil.h RelicUtil.h \
$(COREDIR)/Gpackets/GCAddEffect.h $(COREDIR)/PacketFactory.h
GamePlayer.o: GamePlayer.cpp GamePlayer.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
$(COREDIR)/SocketInputStream.h $(SERVDIR)/Mutex.h $(COREDIR)/Packet.h \
$(SERVDIR)/Timeval.h $(COREDIR)/PlayerStatus.h EventManager.h Event.h \
$(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h \
Item.h Object.h $(COREDIR)/Assert.h Effect.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
Creature.h Slayer.h PlayerCreature.h ObjectRegistry.h InventorySlot.h \
Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
$(COREDIR)/Gpackets/GCModifyInformation.h Vampire.h \
$(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
$(SERVDIR)/LogClient.h RelicUtil.h $(COREDIR)/PacketFactoryManager.h \
$(COREDIR)/PacketValidator.h $(COREDIR)/PacketIDSet.h \
IncomingPlayerManager.h $(SERVDIR)/PlayerManager.h \
$(COREDIR)/ServerSocket.h $(COREDIR)/DatagramSocket.h \
$(COREDIR)/Datagram.h ConnectionInfoManager.h ConnectionInfo.h \
PCFinder.h NPC.h $(COUPLEDIR)/PartnerWaitingManager.h TelephoneCenter.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h GuildManager.h Guild.h \
VariableManager.h $(BILLINGDIR)/BillingInfo.h \
$(BILLINGDIR)/BillingPlayerManager.h $(COREDIR)/Properties.h EventKick.h \
StringPool.h $(ITEMDIR)/Motorcycle.h ItemInfo.h InfoClassManager.h \
ItemFactory.h $(COREDIR)/Shape.h EffectMute.h EffectLoader.h SkillInfo.h \
$(SKILLDIR)/SkillHandlerManager.h $(SKILLDIR)/SkillHandler.h Monster.h \
MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h Treasure.h \
PrecedenceTable.h $(SKILLDIR)/HitRoll.h $(SKILLDIR)/SkillUtil.h \
ZoneUtil.h SkillCastingTimeManager.h $(SERVDIR)/DBExecuteManager.h \
$(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h \
$(COREDIR)/Cpackets/CGConnect.h $(COREDIR)/Gpackets/GCKickMessage.h \
$(COREDIR)/Gpackets/GCSystemMessage.h ServiceDeadline.h \
$(SERVDIR)/GameWorldInfoManager.h $(SERVDIR)/GameWorldInfo.h
GameServer.o: GameServer.cpp GameServer.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Properties.h $(COREDIR)/Assert.h ThreadManager.h \
ClientManager.h $(SERVDIR)/Timeval.h EventManager.h Event.h \
$(SERVDIR)/Mutex.h ObjectManager.h LoginServerManager.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(COREDIR)/DatagramSocket.h \
$(COREDIR)/SocketAPI.h $(COREDIR)/Datagram.h SharedServerManager.h \
$(COREDIR)/Socket.h $(COREDIR)/SocketImpl.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/SocketOutputStream.h \
$(SERVDIR)/LogClient.h $(SERVDIR)/SystemAPI.h \
$(COREDIR)/PacketFactoryManager.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/PacketValidator.h $(COREDIR)/PacketIDSet.h \
$(COREDIR)/PlayerStatus.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(SERVDIR)/GameServerInfoManager.h \
$(SERVDIR)/GameServerInfo.h $(BILLINGDIR)/BillingPlayerManager.h \
$(BILLINGDIR)/BillingInfo.h $(SERVDIR)/chinabilling/CBillingInfo.h \
mofus/Mofus.h SMSServiceThread.h $(DBDIR)/DB.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h GDRLairManager.h FiniteStateMachine.h \
$(COREDIR)/VSDateTime.h GDRLairAbstractStates.h Effect.h Object.h \
VariableManager.h ZoneGroupManager.h ZoneGroup.h Zone.h Tile.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h Item.h Obstacle.h \
Portal.h quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h
IncomingPlayerManager.o: IncomingPlayerManager.cpp \
IncomingPlayerManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(SERVDIR)/PlayerManager.h $(SERVDIR)/Timeval.h $(COREDIR)/SocketAPI.h \
$(SERVDIR)/Mutex.h GamePlayer.h $(COREDIR)/Player.h \
$(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/SocketOutputStream.h \
$(COREDIR)/Socket.h $(COREDIR)/SocketImpl.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Packet.h \
$(COREDIR)/PlayerStatus.h EventManager.h Event.h $(SKILLDIR)/Skill.h \
$(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h Item.h Object.h \
$(COREDIR)/Assert.h Effect.h EffectManager.h $(COREDIR)/EffectInfo.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/ServerSocket.h $(COREDIR)/DatagramSocket.h \
$(COREDIR)/Datagram.h ConnectionInfoManager.h ConnectionInfo.h \
$(COREDIR)/Properties.h LoginServerManager.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h PacketUtil.h ZoneInfoManager.h Zone.h Tile.h \
Creature.h Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h ObjectRegistry.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h ZoneInfo.h \
ZoneGroup.h $(COREDIR)/GameTime.h $(COREDIR)/Gpackets/GMServerInfo.h \
$(COREDIR)/DatagramPacket.h ZonePlayerManager.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SERVDIR)/LogClient.h MasterLairManager.h \
MonsterCounter.h DynamicZoneScript.h DynamicZone.h Monster.h \
MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h Treasure.h \
PrecedenceTable.h DynamicZoneGroup.h MikllizzLairManager.h \
HellGardenTowerManager.h EventSurvivalZoneManager.h LogDef.h \
VariableManager.h PlayerCreature.h InventorySlot.h Garbage.h RankBonus.h \
ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h PKZoneInfoManager.h $(COREDIR)/Cpackets/CGSay.h \
CreatureUtil.h $(COREDIR)/Gpackets/GCUpdateInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCVampireInfo2.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/NPCInfo.h \
$(COREDIR)/NicknameInfo.h $(COREDIR)/BloodBibleSignInfo.h \
  $(COREDIR)/Gpackets/GLIncomingConnection.h \
$(COREDIR)/Gpackets/GLKickVerify.h SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h
SharedServerClient.o: SharedServerClient.cpp SharedServerClient.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Player.h \
$(SERVDIR)/Mutex.h $(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h \
$(COREDIR)/Socket.h $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/Assert.h \
$(COREDIR)/PacketFactoryManager.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/PacketValidator.h $(COREDIR)/PacketIDSet.h \
$(COREDIR)/PlayerStatus.h GuildManager.h $(SERVDIR)/Timeval.h Guild.h \
  $(COREDIR)/VSDateTime.h
InfoClassManager.o: InfoClassManager.cpp InfoClassManager.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h Item.h Object.h \
$(COREDIR)/Assert.h Effect.h $(SERVDIR)/Timeval.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ItemInfo.h VariableManager.h
Inventory.o: Inventory.cpp Inventory.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h Item.h Object.h $(COREDIR)/Exception.h \
$(COREDIR)/StringStream.h $(COREDIR)/Assert.h Effect.h \
$(SERVDIR)/Timeval.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h VolumeInfo.h InventorySlot.h \
ItemInfoManager.h ItemInfo.h InfoClassManager.h ParkingCenter.h Zone.h \
Tile.h Creature.h Obstacle.h Portal.h quest/TriggerManager.h \
quest/Trigger.h quest/Condition.h quest/PropertyBuffer.h Sector.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h $(ITEMDIR)/Motorcycle.h ItemFactory.h \
ItemLoader.h ItemUtil.h EffectSchedule.h Store.h $(COREDIR)/StoreInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
$(COREDIR)/Player.h PacketUtil.h $(ITEMDIR)/Key.h $(ITEMDIR)/Belt.h \
ConcreteItem.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
ItemPolicies.h $(SKILLDIR)/EffectVampirePortal.h EffectLoader.h \
$(COREDIR)/Gpackets/GCDeleteInventoryItem.h $(COREDIR)/PacketFactory.h \
  $(COREDIR)/Gpackets/GCCreateItem.h \
  $(COREDIR)/Gpackets/GCSubInventoryInfo.h
LoginServerManager.o: LoginServerManager.cpp LoginServerManager.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h $(COREDIR)/DatagramSocket.h \
$(COREDIR)/SocketAPI.h $(COREDIR)/Datagram.h $(SERVDIR)/Mutex.h \
$(COREDIR)/Properties.h $(SERVDIR)/LogClient.h $(COREDIR)/Assert.h \
ThreadManager.h ThreadPool.h $(COREDIR)/DatagramPacket.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketOutputStream.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SERVDIR)/Timeval.h VariableManager.h
SharedServerManager.o: SharedServerManager.cpp SharedServerManager.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h $(COREDIR)/Socket.h $(COREDIR)/SocketImpl.h \
$(COREDIR)/SocketAPI.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/SocketOutputStream.h \
$(SERVDIR)/Mutex.h SharedServerClient.h $(COREDIR)/Player.h \
$(COREDIR)/Properties.h $(SERVDIR)/LogClient.h $(COREDIR)/Assert.h \
ThreadManager.h ThreadPool.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SERVDIR)/Timeval.h $(COREDIR)/Gpackets/GSRequestGuildInfo.h \
$(COREDIR)/PacketFactory.h VariableManager.h PCFinder.h Creature.h \
Object.h EffectManager.h Effect.h $(COREDIR)/EffectInfo.h NPC.h Zone.h \
Tile.h Item.h Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h ObjectRegistry.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h InventorySlot.h $(COUPLEDIR)/PartnerWaitingManager.h \
PlayerCreature.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h \
EventReloginToSharedServer.h Event.h GamePlayer.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h
NPC.o: NPC.cpp NPC.h Creature.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h EffectManager.h Effect.h $(SERVDIR)/Timeval.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Zone.h Tile.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h InventorySlot.h $(COUPLEDIR)/PartnerWaitingManager.h \
PlayerCreature.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h ShopRack.h ItemRack.h \
$(MISSIONDIR)/QuestInfoManager.h $(COREDIR)/Gpackets/GCNPCResponse.h \
$(MISSIONDIR)/QuestInfo.h $(MISSIONDIR)/RewardClass.h \
  $(MISSIONDIR)/RewardClassInfoManager.h \
$(COREDIR)/Gpackets/GCNPCAskDynamic.h $(COREDIR)/Gpackets/GCAddNPC.h \
  CastleInfoManager.h
NPCManager.o: NPCManager.cpp NPCManager.h CreatureManager.h Creature.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
EffectManager.h Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h NPC.h Zone.h Tile.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h InventorySlot.h \
$(COUPLEDIR)/PartnerWaitingManager.h PlayerCreature.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h \
  PCFinder.h
ResurrectLocationManager.o: ResurrectLocationManager.cpp \
ResurrectLocationManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
Slayer.h PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h \
EffectManager.h Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
GamePlayer.h $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(WARDIR)/WarSystem.h \
$(WARDIR)/Scheduler.h $(WARDIR)/Work.h $(WARDIR)/Schedule.h \
$(COREDIR)/Gpackets/GCWarList.h $(COREDIR)/GuildWarInfo.h \
$(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h $(COREDIR)/RaceWarInfo.h \
ZoneInfo.h ZoneInfoManager.h CastleInfoManager.h PacketUtil.h \
VariableManager.h MenegrothDoungeonManager.h DynamicZoneScript.h \
DynamicZone.h Monster.h MonsterInfo.h MonsterSummonInfo.h \
MonsterInfoTypes.h Treasure.h PrecedenceTable.h DynamicZoneGroup.h \
  DynamicZoneInfo.h
PCFinder.o: PCFinder.cpp PCFinder.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h Effect.h \
$(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h NPC.h Zone.h Tile.h Item.h Obstacle.h \
Portal.h quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h InventorySlot.h $(COUPLEDIR)/PartnerWaitingManager.h \
PlayerCreature.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(COREDIR)/Player.h
TelephoneCenter.o: TelephoneCenter.cpp TelephoneCenter.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h Slayer.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h
ParkingCenter.o: ParkingCenter.cpp ParkingCenter.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
Zone.h Tile.h Object.h $(COREDIR)/Assert.h Creature.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(ITEMDIR)/Motorcycle.h ItemInfo.h InfoClassManager.h ItemFactory.h \
ItemLoader.h ZoneUtil.h $(COREDIR)/VSDateTime.h \
$(COREDIR)/Gpackets/GCDeleteObject.h $(COREDIR)/PacketFactory.h
PCManager.o: PCManager.cpp $(COREDIR)/Assert.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
PCManager.h CreatureManager.h Creature.h Object.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(SERVDIR)/Mutex.h GamePlayer.h \
$(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
$(COREDIR)/VSDateTime.h Item.h $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
PlayerCreature.h ObjectRegistry.h InventorySlot.h Garbage.h RankBonus.h \
ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Slayer.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
Inventory.h VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
$(COREDIR)/Gpackets/GCModifyInformation.h Vampire.h \
$(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
MonsterCorpse.h ItemFactory.h Corpse.h ZoneGroupManager.h ZoneGroup.h \
$(COREDIR)/GameTime.h $(COREDIR)/Gpackets/GMServerInfo.h \
$(COREDIR)/DatagramPacket.h $(COREDIR)/Datagram.h ZoneInfo.h \
ZoneInfoManager.h ZonePlayerManager.h $(SERVDIR)/PlayerManager.h \
IncomingPlayerManager.h $(COREDIR)/ServerSocket.h \
$(COREDIR)/DatagramSocket.h ConnectionInfoManager.h ConnectionInfo.h \
TimeManager.h EventResurrect.h ResurrectLocationManager.h ItemUtil.h \
AlignmentManager.h ItemFactoryManager.h SlayerCorpse.h VampireCorpse.h \
OustersCorpse.h $(SERVDIR)/LogClient.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h TradeManager.h $(SKILLDIR)/SkillHandlerManager.h \
$(SKILLDIR)/SkillHandler.h SkillInfo.h Monster.h MonsterInfo.h \
MonsterSummonInfo.h MonsterInfoTypes.h Treasure.h PrecedenceTable.h \
$(SKILLDIR)/HitRoll.h $(SKILLDIR)/SkillUtil.h ZoneUtil.h \
$(ITEMDIR)/Relic.h ItemInfo.h InfoClassManager.h RelicUtil.h \
ItemInfoManager.h PacketUtil.h PKZoneInfoManager.h \
$(COREDIR)/Cpackets/CGSay.h BloodBibleBonusManager.h BloodBibleBonus.h \
HolyLandManager.h LevelWarZoneInfoManager.h $(WARDIR)/WarSystem.h \
$(WARDIR)/Scheduler.h $(WARDIR)/Work.h $(WARDIR)/Schedule.h \
$(COREDIR)/Gpackets/GCWarList.h $(COREDIR)/GuildWarInfo.h \
$(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h $(COREDIR)/RaceWarInfo.h \
EventZoneInfo.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h SiegeManager.h \
$(COREDIR)/Properties.h EffectComa.h EffectLoader.h EventTransport.h \
EffectPKZoneResurrection.h EffectTryingPosition.h \
$(SKILLDIR)/EffectSummonCasket.h $(SKILLDIR)/EffectHarpoonBomb.h \
$(COREDIR)/Gpackets/GCAddEffect.h $(COREDIR)/Gpackets/GCCreatureDied.h \
  $(COREDIR)/Gpackets/GCGetOffMotorCycle.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCRemoveEffect.h \
  $(COREDIR)/Gpackets/GCRemoveFromGear.h \
  $(COREDIR)/Gpackets/GCHolyLandBonusInfo.h \
$(COREDIR)/BloodBibleBonusInfo.h PVPSystemManager.h
Portal.o: Portal.cpp Portal.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Zone.h Tile.h Creature.h \
EffectManager.h Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Sector.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h ZoneGroup.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
$(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h ZoneGroupManager.h \
ZoneInfo.h ZoneInfoManager.h ZonePlayerManager.h \
$(SERVDIR)/PlayerManager.h $(COREDIR)/Player.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCVampireInfo2.h $(SERVDIR)/LogClient.h Slayer.h \
PlayerCreature.h InventorySlot.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo3.h \
$(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
$(SKILLDIR)/VampireSkillSlot.h TimeManager.h WeatherManager.h \
GamePlayer.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h IncomingPlayerManager.h \
$(COREDIR)/ServerSocket.h $(COREDIR)/DatagramSocket.h \
ConnectionInfoManager.h ConnectionInfo.h PacketUtil.h ZoneUtil.h \
$(COREDIR)/Properties.h Guild.h GuildManager.h DynamicZoneScript.h \
DynamicZone.h Monster.h MonsterInfo.h MonsterSummonInfo.h \
MonsterInfoTypes.h Treasure.h PrecedenceTable.h DynamicZoneGroup.h \
InstanceDoungeonManager.h DynamicZoneManager.h DynamicZoneInfo.h \
DynamicZoneScriptGroup.h $(COREDIR)/Gpackets/GCUpdateInfo.h \
$(COREDIR)/NPCInfo.h $(COREDIR)/NicknameInfo.h \
$(COREDIR)/BloodBibleSignInfo.h $(COREDIR)/Gpackets/GCMoveOK.h
Script.o: Script.cpp Script.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h
ScriptManager.o: ScriptManager.cpp ScriptManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
Script.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(SERVDIR)/Mutex.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(COREDIR)/SXml.h $(COREDIR)/Properties.h $(COREDIR)/Assert.h
ThreadManager.o: ThreadManager.cpp ThreadManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
ThreadPool.h $(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h \
$(SERVDIR)/Mutex.h ZoneGroupThread.h ZoneGroup.h Zone.h Tile.h Object.h \
$(COREDIR)/Assert.h Creature.h EffectManager.h Effect.h \
$(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
$(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h $(SERVDIR)/LogClient.h \
ZoneGroupManager.h $(COREDIR)/Properties.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h
ThreadPool.o: ThreadPool.cpp ThreadPool.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/Mutex.h \
$(COREDIR)/Assert.h $(SERVDIR)/LogClient.h
Tile.o: Tile.cpp Tile.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
Object.h $(COREDIR)/Assert.h Creature.h EffectManager.h Effect.h \
$(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h $(COREDIR)/Player.h Slayer.h \
PlayerCreature.h ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h \
Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
GamePlayer.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(SKILLDIR)/EffectYellowPoison.h \
EffectLoader.h $(SKILLDIR)/EffectGreenPoison.h \
$(SKILLDIR)/EffectDarkness.h EffectTryingPosition.h
Sector.o: Sector.cpp Sector.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
Object.h $(COREDIR)/Assert.h
TimeManager.o: TimeManager.cpp TimeManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/GameTime.h $(COREDIR)/Exception.h \
$(COREDIR)/StringStream.h $(COREDIR)/SocketInputStream.h \
$(COREDIR)/Socket.h $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/Properties.h
GoodsInventory.o: GoodsInventory.cpp GoodsInventory.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h Item.h Object.h $(COREDIR)/Exception.h \
$(COREDIR)/StringStream.h $(COREDIR)/Assert.h Effect.h \
$(SERVDIR)/Timeval.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h
GoodsInfoManager.o: GoodsInfoManager.cpp GoodsInfoManager.h \
$(COREDIR)/Exception.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/StringStream.h Item.h Object.h $(COREDIR)/Assert.h Effect.h \
$(SERVDIR)/Timeval.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h ItemFactoryManager.h ItemFactory.h ItemInfoManager.h \
ItemInfo.h InfoClassManager.h ItemUtil.h
VisionInfo.o: VisionInfo.cpp VisionInfo.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/LogClient.h
WeatherInfo.o: WeatherInfo.cpp WeatherInfo.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(SERVDIR)/Mutex.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
  $(COREDIR)/Assert.h
WeatherManager.o: WeatherManager.cpp WeatherManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(COREDIR)/GameTime.h $(COREDIR)/SocketInputStream.h \
$(COREDIR)/Socket.h $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h TimeManager.h WeatherInfo.h \
$(SERVDIR)/LogClient.h DarkLightInfo.h Zone.h Tile.h Object.h Creature.h \
EffectManager.h Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h Item.h Obstacle.h Portal.h quest/TriggerManager.h \
quest/Trigger.h quest/Condition.h quest/PropertyBuffer.h Sector.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h PKZoneInfoManager.h \
$(COREDIR)/Cpackets/CGSay.h $(COREDIR)/PacketFactory.h \
  $(COREDIR)/Gpackets/GCChangeDarkLight.h \
$(COREDIR)/Gpackets/GCChangeWeather.h $(COREDIR)/Gpackets/GCLightning.h
ZoneInfo.o: ZoneInfo.cpp ZoneInfo.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
Zone.h Tile.h Object.h $(COREDIR)/Assert.h Creature.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h MenegrothDoungeonManager.h
ZoneGroup.o: ZoneGroup.cpp ZoneGroup.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
Zone.h Tile.h Object.h $(COREDIR)/Assert.h Creature.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
$(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h ZonePlayerManager.h \
$(SERVDIR)/PlayerManager.h $(COREDIR)/Player.h $(COREDIR)/VSDateTime.h \
$(SERVDIR)/Profile.h DynamicZone.h Monster.h MonsterInfo.h \
MonsterSummonInfo.h MonsterInfoTypes.h Treasure.h PrecedenceTable.h \
  DynamicZoneGroup.h
ZoneGroupManager.o: ZoneGroupManager.cpp ZoneGroupManager.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h ZoneGroup.h Zone.h \
Tile.h Object.h $(COREDIR)/Assert.h Creature.h EffectManager.h Effect.h \
$(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
$(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h ZonePlayerManager.h \
$(SERVDIR)/PlayerManager.h $(COREDIR)/Player.h ZoneInfoManager.h \
ZoneInfo.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SERVDIR)/LogClient.h GamePlayer.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
$(COREDIR)/VSDateTime.h $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h LoginServerManager.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(COREDIR)/DatagramSocket.h \
IncomingPlayerManager.h $(COREDIR)/ServerSocket.h \
ConnectionInfoManager.h ConnectionInfo.h
ZoneInfoManager.o: ZoneInfoManager.cpp ZoneInfoManager.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h Zone.h Tile.h Object.h \
$(COREDIR)/Assert.h Creature.h EffectManager.h Effect.h \
$(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h ZoneInfo.h ZoneUtil.h \
$(COREDIR)/VSDateTime.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
  SystemAvailabilitiesManager.h \
$(COREDIR)/Gpackets/GCSystemAvailabilities.h $(COREDIR)/PacketFactory.h
ZonePlayerManager.o: ZonePlayerManager.cpp ZonePlayerManager.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(SERVDIR)/PlayerManager.h $(SERVDIR)/Timeval.h $(COREDIR)/SocketAPI.h \
$(SERVDIR)/Mutex.h $(COREDIR)/Player.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h Effect.h Object.h $(COREDIR)/Assert.h \
IncomingPlayerManager.h GamePlayer.h \
$(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/SocketOutputStream.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/SocketInputStream.h \
$(COREDIR)/Packet.h $(COREDIR)/PlayerStatus.h EventManager.h Event.h \
$(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h \
Item.h EffectManager.h $(COREDIR)/EffectInfo.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/ServerSocket.h $(COREDIR)/DatagramSocket.h \
$(COREDIR)/Datagram.h ConnectionInfoManager.h ConnectionInfo.h Slayer.h \
PlayerCreature.h Creature.h ObjectRegistry.h InventorySlot.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
$(COREDIR)/Gpackets/GCModifyInformation.h $(SERVDIR)/LogClient.h \
$(COREDIR)/Cpackets/CGLogout.h $(SERVDIR)/Profile.h ZoneInfoManager.h \
ZoneInfo.h ZoneUtil.h ResurrectLocationManager.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h $(BILLINGDIR)/BillingInfo.h StringPool.h \
ZoneGroup.h $(COREDIR)/GameTime.h $(COREDIR)/Gpackets/GMServerInfo.h \
$(COREDIR)/DatagramPacket.h VariableManager.h DefaultOptionSetInfo.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
$(COREDIR)/Gpackets/GCKickMessage.h $(COREDIR)/Properties.h
ZoneGroupThread.o: ZoneGroupThread.cpp ZoneGroupThread.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h ZoneGroup.h Zone.h Tile.h Object.h \
$(COREDIR)/Assert.h Creature.h EffectManager.h Effect.h \
$(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
$(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h ZonePlayerManager.h \
$(SERVDIR)/PlayerManager.h $(COREDIR)/Player.h $(SERVDIR)/LogClient.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h $(COREDIR)/VSDateTime.h \
$(COREDIR)/Properties.h $(SERVDIR)/Profile.h VariableManager.h
ObjectManager.o: ObjectManager.cpp ObjectManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h CreatureManager.h Creature.h Object.h \
EffectManager.h Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(SERVDIR)/Mutex.h \
$(SERVDIR)/LogClient.h $(SERVDIR)/PlayerManager.h MonsterInfo.h \
MonsterSummonInfo.h MonsterInfoTypes.h Treasure.h Item.h TimeManager.h \
$(COREDIR)/GameTime.h DarkLightInfo.h VisionInfo.h WeatherInfo.h \
ZoneGroupManager.h ZoneGroup.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h $(COREDIR)/Gpackets/GMServerInfo.h \
$(COREDIR)/DatagramPacket.h $(COREDIR)/Datagram.h \
$(COREDIR)/PacketFactory.h ZoneInfoManager.h ZoneInfo.h \
ItemInfoManager.h ItemInfo.h InfoClassManager.h ItemMineInfo.h \
ItemFactoryManager.h ItemFactory.h ItemLoaderManager.h ItemLoader.h \
SkillInfo.h Slayer.h PlayerCreature.h InventorySlot.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
SkillDomainInfoManager.h $(SERVDIR)/GameWorldInfoManager.h \
$(SERVDIR)/GameWorldInfo.h SkillParentInfo.h \
$(SKILLDIR)/SkillHandlerManager.h $(SKILLDIR)/SkillHandler.h Vampire.h \
$(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
Monster.h PrecedenceTable.h $(SKILLDIR)/HitRoll.h \
$(SKILLDIR)/SkillUtil.h ZoneUtil.h GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h PCFinder.h NPC.h \
$(COUPLEDIR)/PartnerWaitingManager.h ParkingCenter.h \
$(ITEMDIR)/Motorcycle.h TelephoneCenter.h ScriptManager.h Script.h \
ShopTemplate.h PriceManager.h TradeManager.h Directive.h \
MonsterNameManager.h GuildManager.h ResurrectLocationManager.h \
AlignmentManager.h WayPoint.h VariableManager.h CombatInfoManager.h \
$(ITEMDIR)/Relic.h UniqueItemManager.h $(COREDIR)/Properties.h \
quest/ConditionFactoryManager.h quest/ConditionFactory.h \
quest/ActionFactoryManager.h quest/Action.h quest/ActionFactory.h \
EffectLoaderManager.h EffectLoader.h VampEXPInfo.h OustersEXPInfo.h \
FlagSet.h RankExpTable.h MasterLairInfoManager.h CastleInfoManager.h \
LogNameManager.h NameManager.h RankBonusInfo.h $(WARDIR)/WarSystem.h \
$(WARDIR)/Scheduler.h $(WARDIR)/Work.h $(WARDIR)/Schedule.h \
$(COREDIR)/Gpackets/GCWarList.h $(COREDIR)/GuildWarInfo.h \
$(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h $(COREDIR)/RaceWarInfo.h \
$(WARDIR)/War.h ShrineInfoManager.h CastleShrineInfoManager.h \
HolyLandManager.h BloodBibleBonusManager.h BloodBibleBonus.h ItemUtil.h \
SkillPropertyManager.h $(WARDIR)/RaceWarLimiter.h PCLimiter.h \
$(COUPLEDIR)/CoupleManager.h PKZoneInfoManager.h \
$(COREDIR)/Cpackets/CGSay.h CastleSkillInfo.h StringPool.h \
GameServerGroupInfoManager.h GameServerGroupInfo.h GoodsInfoManager.h \
$(MISSIONDIR)/EventQuestLootingManager.h $(CTFDIR)/FlagManager.h \
$(COREDIR)/Gpackets/GCFlagWarStatus.h DefaultOptionSetInfo.h \
LevelWarZoneInfoManager.h SweeperBonusManager.h RegenZoneManager.h \
MonsterCorpse.h Corpse.h PetTypeInfo.h $(COREDIR)/types/PetTypes.h \
PetAttrInfo.h PetExpInfo.h ItemGradeManager.h EventZoneInfo.h \
  SystemAvailabilitiesManager.h \
$(COREDIR)/Gpackets/GCSystemAvailabilities.h LevelNickInfoManager.h \
GQuestInfo.h $(COREDIR)/SXml.h GQuestElement.h GQuestManager.h \
GQuestInventory.h $(COREDIR)/Gpackets/GCGQuestInventory.h \
GQuestCheckPoint.h SiegeManager.h GuildUnion.h \
$(COREDIR)/Gpackets/GCUnionOfferList.h $(WARDIR)/DragonEyeManager.h \
$(ITEMDIR)/WarItem.h AdvancementClassExpTable.h $(COREDIR)/TimeChecker.h \
$(COREDIR)/../server/Timeval.h TimeCheckerLoader.h DynamicZoneManager.h \
DynamicZoneInfo.h DynamicZoneFactoryManager.h DynamicZone.h \
DynamicZoneGroup.h ItemClassInfo.h ThirdEnchantInfo.h ContributeInfo.h \
HeroItemManager.h EventGiftBoxRewardManager.h InstanceDoungeonManager.h \
DynamicZoneScriptGroup.h DynamicZoneScript.h EventBlitzRewardManager.h \
GlobalNPCManager.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
AbilityBalance.o: AbilityBalance.cpp AbilityBalance.h Creature.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
EffectManager.h Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Slayer.h PlayerCreature.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h ItemUtil.h $(COREDIR)/Properties.h \
VariableManager.h $(SKILLDIR)/SkillHandler.h SkillInfo.h \
$(SKILLDIR)/HitRoll.h $(SKILLDIR)/SkillUtil.h ZoneUtil.h GamePlayer.h \
$(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h $(COREDIR)/Gpackets/GCStatusCurrentHP.h
PlayerCreature.o: PlayerCreature.cpp PlayerCreature.h Creature.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
EffectManager.h Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Stash.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h ItemUtil.h $(ITEMDIR)/Belt.h ConcreteItem.h ItemInfo.h \
ItemInfoManager.h InfoClassManager.h ItemPolicies.h ItemFactory.h \
ItemLoader.h Inventory.h VolumeInfo.h GoodsInventory.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h FlagSet.h \
ParkingCenter.h $(ITEMDIR)/Motorcycle.h $(ITEMDIR)/Key.h Guild.h \
GuildManager.h $(COREDIR)/Gpackets/GCRankBonusInfo.h \
  $(COREDIR)/Gpackets/GCTimeLimitItemInfo.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(COREDIR)/Gpackets/GCOtherModifyInfo.h \
$(COREDIR)/Gpackets/GCNoticeEvent.h $(COREDIR)/Gpackets/GCPetStashList.h \
$(COREDIR)/PetInfo.h $(COREDIR)/types/PetTypes.h \
$(COREDIR)/Gpackets/GCModifyNickname.h $(COREDIR)/NicknameInfo.h \
$(COREDIR)/Gpackets/GCSystemMessage.h $(COREDIR)/Player.h \
RankBonusInfo.h GamePlayer.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h TimeLimitItemManager.h \
$(MISSIONDIR)/QuestManager.h $(MISSIONDIR)/QuestInfo.h \
$(MISSIONDIR)/RewardClass.h $(COREDIR)/Gpackets/GCNPCResponse.h \
$(MISSIONDIR)/QuestStatus.h $(COREDIR)/Properties.h PKZoneInfoManager.h \
$(COREDIR)/Cpackets/CGSay.h RankExpTable.h SomethingGrowingUp.h \
EventKick.h $(SERVDIR)/GameServerInfoManager.h \
$(SERVDIR)/GameServerInfo.h DefaultOptionSetInfo.h Pet.h Slayer.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
$(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h Vampire.h \
$(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
SMSAddressBook.h $(COREDIR)/Gpackets/GCSMSAddressList.h NicknameBook.h \
GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h VariableManager.h \
$(COREDIR)/BloodBibleSignInfo.h Store.h $(COREDIR)/StoreInfo.h \
AdvancementClassExpTable.h $(ITEMDIR)/SubInventory.h PlayerInventory.h \
$(SKILLDIR)/SkillUtil.h $(SKILLDIR)/SkillHandler.h SkillInfo.h Monster.h \
MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h Treasure.h \
PrecedenceTable.h $(SKILLDIR)/HitRoll.h ZoneUtil.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h SkillCastingTimeManager.h \
$(COREDIR)/TimeChecker.h $(COREDIR)/../server/Timeval.h Born.h \
ContributeInfo.h LevelWarZoneInfoManager.h WeekItemListManager.h \
GlobalNPCManager.h NPC.h $(COUPLEDIR)/PartnerWaitingManager.h \
$(SERVDIR)/DBExecuteManager.h $(SERVDIR)/CondVar.h \
$(SERVDIR)/CondVarAttr.h $(COREDIR)/Gpackets/GCChangeShape.h \
EventSystemMessage.h StringPool.h RelicUtil.h PCFinder.h \
$(COREDIR)/Gpackets/GSGuildMemberLogOn.h SharedServerManager.h \
ResurrectLocationManager.h $(COREDIR)/Gpackets/GSLogout.h \
$(COREDIR)/StringInfo.h $(COREDIR)/Gpackets/GCFriendUpdateConnect.h \
$(COREDIR)/Gpackets/GSFriendUpdateZone.h EffectBonusExp.h EffectLoader.h \
EffectBonusExpSecond.h EffectBonusExpAdvance.h EffectChaoticExp.h \
ItemFactoryManager.h $(COREDIR)/Gpackets/GCCreateItem.h PacketUtil.h \
  $(COREDIR)/Gpackets/GCDeleteInventoryItem.h
ZoneUtil.o: ZoneUtil.cpp ZoneUtil.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h Effect.h \
$(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/VSDateTime.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h $(COREDIR)/Properties.h Item.h \
$(ITEMDIR)/Relic.h ItemInfo.h InfoClassManager.h ItemFactory.h \
ItemLoader.h Zone.h Tile.h Obstacle.h Portal.h quest/TriggerManager.h \
quest/Trigger.h quest/Condition.h quest/PropertyBuffer.h Sector.h \
ObjectRegistry.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
Slayer.h PlayerCreature.h InventorySlot.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h Corpse.h GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h ZoneInfo.h ZoneInfoManager.h \
ZoneGroup.h $(COREDIR)/GameTime.h $(COREDIR)/Gpackets/GMServerInfo.h \
$(COREDIR)/DatagramPacket.h $(COREDIR)/Datagram.h ZoneGroupManager.h \
ZonePlayerManager.h $(SERVDIR)/PlayerManager.h IncomingPlayerManager.h \
$(COREDIR)/ServerSocket.h $(COREDIR)/DatagramSocket.h \
ConnectionInfoManager.h ConnectionInfo.h PacketUtil.h MonsterManager.h \
MonsterCounter.h ResurrectLocationManager.h \
$(SKILLDIR)/EffectObservingEye.h $(SKILLDIR)/EffectGnomesWhisper.h \
EffectLoader.h MasterLairManager.h DynamicZoneScript.h DynamicZone.h \
DynamicZoneGroup.h VariableManager.h EventTransport.h MonsterCorpse.h \
RelicUtil.h CastleInfoManager.h TimeManager.h EffectPrecedence.h \
StringPool.h PKZoneInfoManager.h $(COREDIR)/Cpackets/CGSay.h \
VisionInfo.h LevelWarZoneInfoManager.h EffectDarknessForbidden.h \
GDRLairManager.h FiniteStateMachine.h GDRLairAbstractStates.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h MenegrothDoungeonManager.h \
$(CTFDIR)/FlagManager.h $(WARDIR)/Work.h $(WARDIR)/Scheduler.h \
$(WARDIR)/Schedule.h $(COREDIR)/Gpackets/GCFlagWarStatus.h \
  $(COREDIR)/Gpackets/GCMoveOK.h \
  $(COREDIR)/Gpackets/GCAddBurrowingCreature.h \
  $(COREDIR)/Gpackets/GCAddVampireFromTransformation.h \
  $(COREDIR)/Gpackets/GCAddMonsterFromTransformation.h \
  $(COREDIR)/Gpackets/GCUntransformOK.h \
  $(COREDIR)/Gpackets/GCUntransformFail.h \
  $(COREDIR)/Gpackets/GCAddVampireFromBurrowing.h \
  $(COREDIR)/Gpackets/GCAddMonsterFromBurrowing.h \
  $(COREDIR)/Gpackets/GCMineExplosionOK1.h \
  $(COREDIR)/Gpackets/GCMineExplosionOK2.h \
  $(COREDIR)/Gpackets/GCAddInstalledMineToZone.h \
$(COREDIR)/Gpackets/GCAddItemToZone.h $(COREDIR)/Gpackets/GCFastMove.h \
$(COREDIR)/Gpackets/GCMove.h $(COREDIR)/Gpackets/GCMoveError.h \
  $(COREDIR)/Gpackets/GCAddMonster.h \
  $(COREDIR)/Gpackets/GCAddNewItemToZone.h \
$(COREDIR)/Gpackets/GCDropItemToZone.h $(COREDIR)/Gpackets/GCAddNPC.h \
$(COREDIR)/Gpackets/GCAddSlayer.h $(COREDIR)/PetInfo.h \
$(COREDIR)/types/PetTypes.h $(COREDIR)/NicknameInfo.h \
$(COREDIR)/StoreInfo.h $(COREDIR)/Gpackets/GCAddVampire.h \
$(COREDIR)/Gpackets/GCDeleteObject.h $(COREDIR)/Gpackets/GCSetPosition.h \
$(COREDIR)/Gpackets/GCUnburrowOK.h $(COREDIR)/Gpackets/GCUnburrowFail.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(COREDIR)/Gpackets/GCAddEffect.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCDeleteInventoryItem.h \
$(COREDIR)/Gpackets/GCGetOffMotorCycle.h $(ITEMDIR)/Mine.h \
$(SKILLDIR)/EffectTrapInstalled.h $(SKILLDIR)/SummonGroundElemental.h \
$(SKILLDIR)/SkillHandler.h SkillInfo.h Ousters.h \
$(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
$(SKILLDIR)/HitRoll.h $(SKILLDIR)/SkillUtil.h $(WARDIR)/WarSystem.h \
$(COREDIR)/Gpackets/GCWarList.h $(COREDIR)/GuildWarInfo.h \
$(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h $(COREDIR)/RaceWarInfo.h \
$(SERVDIR)/GameServerInfoManager.h $(SERVDIR)/GameServerInfo.h \
Viewable.h ViewEffect.h ParkingCenter.h $(ITEMDIR)/Motorcycle.h \
DynamicZoneManager.h DynamicZoneInfo.h DynamicZoneScriptGroup.h \
$(SKILLDIR)/EffectSquallyBarrier1.h $(SKILLDIR)/EffectSquallyBarrier2.h
Treasure.o: Treasure.cpp Treasure.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
Item.h Object.h $(COREDIR)/Assert.h Effect.h $(SERVDIR)/Timeval.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h OptionInfo.h ItemInfoManager.h \
ItemInfo.h InfoClassManager.h VariableManager.h UniqueItemManager.h \
ItemUtil.h $(COREDIR)/SXml.h
PacketUtil.o: PacketUtil.cpp PacketUtil.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Properties.h GamePlayer.h $(COREDIR)/Player.h \
$(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/SocketOutputStream.h \
$(COREDIR)/Socket.h $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/SocketInputStream.h \
$(SERVDIR)/Mutex.h $(COREDIR)/Packet.h $(SERVDIR)/Timeval.h \
$(COREDIR)/PlayerStatus.h EventManager.h Event.h $(SKILLDIR)/Skill.h \
$(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h Item.h Object.h \
$(COREDIR)/Assert.h Effect.h EffectManager.h $(COREDIR)/EffectInfo.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
Slayer.h PlayerCreature.h Creature.h ObjectRegistry.h InventorySlot.h \
Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
$(COREDIR)/Gpackets/GCModifyInformation.h Vampire.h \
$(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h NPC.h $(COUPLEDIR)/PartnerWaitingManager.h \
ZoneGroup.h $(COREDIR)/GameTime.h $(COREDIR)/Gpackets/GMServerInfo.h \
$(COREDIR)/DatagramPacket.h $(COREDIR)/Datagram.h ZoneGroupManager.h \
ZonePlayerManager.h $(SERVDIR)/PlayerManager.h TimeManager.h \
WeatherManager.h ItemInfo.h ItemInfoManager.h InfoClassManager.h \
EventSystemMessage.h ZoneUtil.h $(WARDIR)/WarScheduler.h \
$(WARDIR)/Work.h $(WARDIR)/Scheduler.h $(WARDIR)/Schedule.h \
$(WARDIR)/War.h $(COREDIR)/ItemNameInfo.h $(SERVDIR)/GameServerInfo.h \
$(SERVDIR)/GameServerInfoManager.h GameServerGroupInfoManager.h \
GameServerGroupInfo.h $(ITEMDIR)/AR.h ConcreteItem.h ItemPolicies.h \
ItemFactory.h $(ITEMDIR)/SR.h $(ITEMDIR)/SG.h $(ITEMDIR)/SMG.h \
$(ITEMDIR)/Belt.h $(ITEMDIR)/OustersArmsband.h $(ITEMDIR)/Mine.h \
$(ITEMDIR)/PetItem.h $(COREDIR)/PetInfo.h $(COREDIR)/types/PetTypes.h \
Corpse.h SlayerCorpse.h VampireCorpse.h OustersCorpse.h MonsterCorpse.h \
$(COREDIR)/NPCInfo.h CastleInfoManager.h PKZoneInfoManager.h \
$(COREDIR)/Cpackets/CGSay.h $(SKILLDIR)/SkillUtil.h \
$(COREDIR)/Gpackets/GCUpdateInfo.h $(COREDIR)/NicknameInfo.h \
$(COREDIR)/BloodBibleSignInfo.h $(COREDIR)/Gpackets/GCAddSlayer.h \
$(COREDIR)/StoreInfo.h $(COREDIR)/Gpackets/GCAddVampire.h \
$(COREDIR)/Gpackets/GCAddOusters.h $(COREDIR)/Gpackets/GCAddMonster.h \
$(COREDIR)/Gpackets/GCAddNPC.h $(COREDIR)/Gpackets/GCAddNewItemToZone.h \
  $(COREDIR)/Gpackets/GCAddItemToZone.h \
  $(COREDIR)/Gpackets/GCDropItemToZone.h \
  $(COREDIR)/Gpackets/GCAddSlayerCorpse.h \
  $(COREDIR)/Gpackets/GCAddVampireCorpse.h \
  $(COREDIR)/Gpackets/GCAddMonsterCorpse.h \
  $(COREDIR)/Gpackets/GCAddOustersCorpse.h \
  $(COREDIR)/Gpackets/GCOtherModifyInfo.h \
$(COREDIR)/Gpackets/GCSystemMessage.h $(COREDIR)/Gpackets/GCCreateItem.h \
  $(COREDIR)/Gpackets/GCAddEffect.h \
  $(COREDIR)/Gpackets/GCAddEffectToTile.h \
  $(COREDIR)/Gpackets/GCWarScheduleList.h \
  $(COREDIR)/Gpackets/GCMiniGameScores.h \
  $(COREDIR)/Gpackets/GCPetStashList.h \
  $(COREDIR)/Gpackets/GCUpdateWeekItemList.h \
$(COREDIR)/Gpackets/GCAddInstalledMineToZone.h GuildManager.h \
$(SERVDIR)/LogClient.h PCFinder.h GuildUnion.h \
$(COREDIR)/Gpackets/GCUnionOfferList.h Store.h DynamicZone.h \
DynamicZoneGroup.h WeekItemListManager.h $(COREDIR)/Gpackets/GSLogin.h \
  $(COREDIR)/StringInfo.h
ConnectionInfo.o: ConnectionInfo.cpp ConnectionInfo.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(SERVDIR)/Timeval.h
InventorySlot.o: InventorySlot.cpp InventorySlot.h Item.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
Effect.h $(SERVDIR)/Timeval.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h
ObjectRegistry.o: ObjectRegistry.cpp ObjectRegistry.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
Object.h $(COREDIR)/Assert.h $(SERVDIR)/Mutex.h
WayPoint.o: WayPoint.cpp WayPoint.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
Zone.h Tile.h Object.h $(COREDIR)/Assert.h Creature.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h ZoneUtil.h \
$(COREDIR)/VSDateTime.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
OptionInfo.o: OptionInfo.cpp OptionInfo.h $(COREDIR)/Exception.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/StringStream.h Item.h Object.h $(COREDIR)/Assert.h Effect.h \
$(SERVDIR)/Timeval.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h Slayer.h PlayerCreature.h Creature.h ObjectRegistry.h \
InventorySlot.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h $(COREDIR)/VSDateTime.h \
$(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h
VolumeInfo.o: VolumeInfo.cpp VolumeInfo.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h
VampEXPInfo.o: VampEXPInfo.cpp VampEXPInfo.h $(COREDIR)/Exception.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/StringStream.h $(COREDIR)/Assert.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h
ItemRack.o: ItemRack.cpp $(COREDIR)/Assert.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
ItemRack.h Item.h Object.h Effect.h $(SERVDIR)/Timeval.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ParkingCenter.h Zone.h Tile.h Creature.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(ITEMDIR)/Motorcycle.h ItemInfo.h InfoClassManager.h ItemFactory.h \
ItemLoader.h $(ITEMDIR)/Key.h
ShopRack.o: ShopRack.cpp ShopRack.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h ItemRack.h $(COREDIR)/Assert.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h
Stash.o: Stash.cpp Stash.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h Item.h Object.h $(COREDIR)/Exception.h \
$(COREDIR)/StringStream.h $(COREDIR)/Assert.h Effect.h \
$(SERVDIR)/Timeval.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ItemRack.h
Garbage.o: Garbage.cpp Garbage.h ObjectRegistry.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
Object.h $(COREDIR)/Assert.h $(SERVDIR)/Mutex.h Item.h Effect.h \
$(SERVDIR)/Timeval.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
ShopTemplate.o: ShopTemplate.cpp ShopTemplate.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(SERVDIR)/Mutex.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
PriceManager.o: PriceManager.cpp PriceManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
Item.h Object.h $(COREDIR)/Assert.h Effect.h $(SERVDIR)/Timeval.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ItemInfoManager.h ItemInfo.h \
InfoClassManager.h OptionInfo.h ItemUtil.h Creature.h Slayer.h \
PlayerCreature.h ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h \
Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h $(COREDIR)/VSDateTime.h \
$(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
VariableManager.h GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(ITEMDIR)/Skull.h ItemFactory.h \
$(ITEMDIR)/SlayerPortalItem.h $(ITEMDIR)/VampirePortalItem.h \
  $(ITEMDIR)/OustersSummonItem.h
CreatureUtil.o: CreatureUtil.cpp CreatureUtil.h Creature.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
EffectManager.h Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Slayer.h PlayerCreature.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h $(COREDIR)/Player.h Stash.h \
$(ITEMDIR)/Belt.h ConcreteItem.h ItemInfo.h ItemInfoManager.h \
InfoClassManager.h ItemPolicies.h ItemFactory.h RelicUtil.h \
$(ITEMDIR)/BloodBible.h CombatInfoManager.h $(ITEMDIR)/Relic.h \
EffectAftermath.h EffectLoader.h EffectKillAftermath.h \
EffectGrandMasterSlayer.h EffectGrandMasterVampire.h \
$(SKILLDIR)/EffectObservingEye.h $(SKILLDIR)/EffectGnomesWhisper.h \
ShrineInfoManager.h CastleInfoManager.h \
$(COUPLEDIR)/PartnerWaitingManager.h PacketUtil.h FlagSet.h \
SimpleCreatureEffect.h EffectRelicLock.h $(CTFDIR)/FlagManager.h \
$(WARDIR)/Work.h $(WARDIR)/Scheduler.h $(WARDIR)/Schedule.h \
$(COREDIR)/Gpackets/GCFlagWarStatus.h $(SKILLDIR)/Sniping.h \
$(SKILLDIR)/SkillHandler.h SkillInfo.h $(SKILLDIR)/HitRoll.h \
$(SKILLDIR)/SkillUtil.h ZoneUtil.h GamePlayer.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h $(SKILLDIR)/SummonGroundElemental.h \
LevelWarManager.h SweeperSet.h MonsterCorpse.h Corpse.h \
$(ITEMDIR)/Sweeper.h $(COREDIR)/Gpackets/GCWarList.h \
$(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
$(COREDIR)/RaceWarInfo.h LevelWarItemManager.h $(ITEMDIR)/WarItem.h \
VariableManager.h $(COREDIR)/TimeChecker.h \
$(COREDIR)/../server/Timeval.h $(ITEMDIR)/SubInventory.h TradeManager.h \
$(WARDIR)/WarSystem.h $(WARDIR)/SiegeWar.h $(WARDIR)/War.h \
$(COREDIR)/PetInfo.h $(COREDIR)/types/PetTypes.h Store.h \
$(COREDIR)/StoreInfo.h $(COREDIR)/Cpackets/CGSay.h ZoneGroupManager.h \
ZoneGroup.h $(COREDIR)/GameTime.h $(COREDIR)/Gpackets/GMServerInfo.h \
$(COREDIR)/DatagramPacket.h $(COREDIR)/Datagram.h \
$(SERVDIR)/GameWorldInfoManager.h $(SERVDIR)/GameWorldInfo.h \
$(COREDIR)/Properties.h $(COREDIR)/Gpackets/GCNotifyWin.h \
$(COREDIR)/Gpackets/GCAddEffect.h $(COREDIR)/Gpackets/GCAddSlayer.h \
$(COREDIR)/NicknameInfo.h $(COREDIR)/Gpackets/GCAddVampire.h \
  $(COREDIR)/Gpackets/GCDeleteObject.h \
  $(COREDIR)/Gpackets/GCDeleteInventoryItem.h \
$(COREDIR)/Gpackets/GCPetInfo.h $(COREDIR)/Gpackets/GCNoticeEvent.h \
$(COREDIR)/Gpackets/GCSystemMessage.h ViewAbility.h StringPool.h NPC.h
ItemMap.o: ItemMap.cpp ItemMap.h Item.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h Effect.h $(SERVDIR)/Timeval.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Inventory.h VolumeInfo.h InventorySlot.h
TradeManager.o: TradeManager.cpp TradeManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(SERVDIR)/Timeval.h Creature.h Object.h $(COREDIR)/Assert.h \
EffectManager.h Effect.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Slayer.h PlayerCreature.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
ItemUtil.h $(COREDIR)/Player.h ItemMap.h $(SERVDIR)/LogClient.h \
FlagSet.h EventItemUtil.h GamePlayer.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h ContractOfBloodUtil.h \
VariableManager.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h \
  $(COREDIR)/Gpackets/GCTradeFinish.h
FlagSet.o: FlagSet.cpp FlagSet.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(SERVDIR)/Mutex.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
  $(COREDIR)/Assert.h
AlignmentManager.o: AlignmentManager.cpp AlignmentManager.h \
$(COREDIR)/Exception.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/StringStream.h $(COREDIR)/Assert.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h $(COREDIR)/Alignment.h
SkillInfo.o: SkillInfo.cpp SkillInfo.h $(COREDIR)/Exception.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/StringStream.h Slayer.h PlayerCreature.h Creature.h Object.h \
$(COREDIR)/Assert.h EffectManager.h Effect.h $(SERVDIR)/Timeval.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
SkillPropertyManager.h $(SKILLDIR)/SkillUtil.h Vampire.h \
$(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
  SkillCastingTimeManager.h
SkillDomainInfoManager.o: SkillDomainInfoManager.cpp \
$(COREDIR)/Exception.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/StringStream.h SkillDomainInfoManager.h $(COREDIR)/Assert.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(SERVDIR)/Mutex.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
SkillParentInfo.o: SkillParentInfo.cpp SkillParentInfo.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h $(COREDIR)/Assert.h
InitAllStat.o: InitAllStat.cpp Slayer.h PlayerCreature.h Creature.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
EffectManager.h Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h AbilityBalance.h ItemUtil.h \
ItemInfo.h ItemInfoManager.h InfoClassManager.h SkillInfo.h \
CombatInfoManager.h $(ITEMDIR)/Relic.h ItemFactory.h VariableManager.h \
HolyLandRaceBonus.h BloodBibleBonus.h BloodBibleBonusManager.h \
$(WARDIR)/WarSystem.h $(WARDIR)/Scheduler.h $(WARDIR)/Work.h \
$(WARDIR)/Schedule.h $(COREDIR)/Gpackets/GCWarList.h \
$(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
$(COREDIR)/RaceWarInfo.h CastleInfoManager.h DefaultOptionSetInfo.h \
LevelWarZoneInfoManager.h SweeperBonus.h SweeperBonusManager.h \
$(COREDIR)/BloodBibleSignInfo.h $(COREDIR)/PetInfo.h \
$(COREDIR)/types/PetTypes.h $(ITEMDIR)/CoreZap.h ConcreteItem.h \
ItemPolicies.h $(ITEMDIR)/OustersWristlet.h $(ITEMDIR)/OustersStone.h \
$(ITEMDIR)/CueOfAdam.h $(SKILLDIR)/CastleSkillSlot.h \
  $(SKILLDIR)/VampireCastleSkillSlot.h \
$(SKILLDIR)/OustersCastleSkillSlot.h $(SKILLDIR)/EffectBless.h \
$(SKILLDIR)/EffectDancingSword.h $(SKILLDIR)/EffectGhostBlade.h \
$(SKILLDIR)/EffectChargingPower.h $(SKILLDIR)/EffectPotentialExplosion.h \
$(SKILLDIR)/EffectParalyze.h EffectLoader.h $(SKILLDIR)/EffectDoom.h \
$(SKILLDIR)/EffectSeduction.h $(SKILLDIR)/EffectProtectionFromPoison.h \
  $(SKILLDIR)/EffectProtectionFromCurse.h \
  $(SKILLDIR)/EffectProtectionFromAcid.h \
  $(SKILLDIR)/EffectProtectionFromBlood.h \
$(SKILLDIR)/EffectTransformToWolf.h $(SKILLDIR)/EffectTransformToBat.h \
$(SKILLDIR)/EffectMindControl.h $(SKILLDIR)/EffectExpansion.h \
$(SKILLDIR)/EffectBerserker.h $(SKILLDIR)/EffectStriking.h \
$(SKILLDIR)/EffectExtreme.h $(SKILLDIR)/EffectDeath.h \
$(SKILLDIR)/EffectMephisto.h $(SKILLDIR)/EffectObservingEye.h \
$(SKILLDIR)/EffectSummonCasket.h $(SKILLDIR)/EffectConcealment.h \
$(SKILLDIR)/EffectEvade.h $(SKILLDIR)/EffectCrossGuard.h \
$(SKILLDIR)/EffectBlunting.h $(SKILLDIR)/EffectHandsOfFire.h \
$(SKILLDIR)/EffectRingOfFlare.h $(SKILLDIR)/EffectWaterBarrier.h \
$(SKILLDIR)/EffectGnomesWhisper.h $(SKILLDIR)/EffectRediance.h \
$(SKILLDIR)/EffectHolyArmor.h $(SKILLDIR)/EffectTransformToWerwolf.h \
$(SKILLDIR)/EffectReactiveArmor.h $(SKILLDIR)/EffectGroundBless.h \
$(SKILLDIR)/EffectSharpChakram.h $(SKILLDIR)/EffectWhitsuntide.h \
$(SKILLDIR)/EffectIntimateGrail.h $(SKILLDIR)/EffectPartyAura.h \
  $(SKILLDIR)/EffectBloodsSymposionAttack.h \
$(SKILLDIR)/EffectBloodyShout.h $(COREDIR)/Gpackets/GCAddEffect.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(COREDIR)/Gpackets/GCChangeShape.h \
$(COREDIR)/Gpackets/GCBloodBibleSignInfo.h ContractOfBloodUtil.h \
$(SKILLDIR)/EffectBloodCurse.h EffectMysteryPotion.h EffectDragonEye.h \
EffectHasRelic.h EffectSlayerHeroItem.h EffectSlayerLevelWarHeroItem.h \
EffectVampireHeroItem.h EffectVampireLevelWarHeroItem.h \
EffectOustersHeroItem.h EffectOustersLevelWarHeroItem.h \
$(SKILLDIR)/EffectSquallyBarrier1.h $(SKILLDIR)/EffectSquallyBarrier2.h
PrecedenceTable.o: PrecedenceTable.cpp PrecedenceTable.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h $(SERVDIR)/Timeval.h \
Creature.h Object.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h EffectManager.h Effect.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h
VariableManager.o: VariableManager.cpp VariableManager.h \
$(COREDIR)/Exception.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/StringStream.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(COREDIR)/Properties.h SystemAvailabilitiesManager.h \
$(COREDIR)/Gpackets/GCSystemAvailabilities.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h
CombatInfoManager.o: CombatInfoManager.cpp StringPool.h \
$(COREDIR)/Exception.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/StringStream.h CombatInfoManager.h $(COREDIR)/Assert.h \
$(SERVDIR)/Mutex.h $(ITEMDIR)/Relic.h Item.h Object.h Effect.h \
$(SERVDIR)/Timeval.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ItemInfo.h InfoClassManager.h \
ItemFactory.h ItemLoader.h $(COREDIR)/Gpackets/GCSystemMessage.h \
$(COREDIR)/PacketFactory.h ZoneGroupManager.h ZoneGroup.h Zone.h Tile.h \
Creature.h Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h ObjectRegistry.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h
UniqueItemManager.o: UniqueItemManager.cpp UniqueItemManager.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h Item.h Object.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
Effect.h $(SERVDIR)/Timeval.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ItemInfoManager.h ItemInfo.h \
InfoClassManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h
MasterLairInfoManager.o: MasterLairInfoManager.cpp \
MasterLairInfoManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
MonsterInfo.h $(COREDIR)/Assert.h Creature.h Object.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h Item.h ZoneInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h ZoneInfoManager.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h
MasterLairManager.o: MasterLairManager.cpp MasterLairManager.h \
MonsterCounter.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h Item.h Object.h \
$(COREDIR)/Assert.h Effect.h $(SERVDIR)/Timeval.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(SERVDIR)/Mutex.h DynamicZoneScript.h \
DynamicZone.h Creature.h Monster.h MonsterInfo.h MonsterSummonInfo.h \
MonsterInfoTypes.h Treasure.h PrecedenceTable.h DynamicZoneGroup.h \
MasterLairInfoManager.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h VariableManager.h \
MonsterManager.h PlayerCreature.h InventorySlot.h Garbage.h RankBonus.h \
ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Inventory.h VolumeInfo.h ItemUtil.h \
ItemFactoryManager.h ItemFactory.h EffectMasterLairPass.h \
EffectContinualGroundAttack.h PacketUtil.h $(COREDIR)/Player.h \
MonsterCorpse.h Corpse.h ZoneInfoManager.h ZoneInfo.h ZoneGroupManager.h \
ZoneGroup.h $(COREDIR)/GameTime.h $(COREDIR)/Gpackets/GMServerInfo.h \
$(COREDIR)/DatagramPacket.h $(COREDIR)/Datagram.h StringPool.h \
InstanceDoungeonManager.h DynamicZoneManager.h DynamicZoneInfo.h \
DynamicZoneScriptGroup.h ZoneUtil.h EventTransport.h Event.h \
GamePlayer.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h \
  $(COREDIR)/Gpackets/GCNoticeEvent.h \
$(COREDIR)/Gpackets/GCSystemMessage.h $(COREDIR)/Gpackets/GCCreateItem.h \
$(COREDIR)/Gpackets/GCAddEffect.h $(COREDIR)/Gpackets/GCSay.h \
  $(COREDIR)/Gpackets/GCAddEffectToScreen.h
MonsterSummonInfo.o: MonsterSummonInfo.cpp $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h MonsterSummonInfo.h MonsterInfoTypes.h \
MonsterInfo.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h Creature.h Object.h EffectManager.h Effect.h \
$(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Treasure.h Item.h
LuckInfo.o: LuckInfo.cpp LuckInfo.h $(COREDIR)/Exception.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/StringStream.h $(COREDIR)/Assert.h VariableManager.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(SERVDIR)/Mutex.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
LogNameManager.o: LogNameManager.cpp LogNameManager.h NameManager.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h
RankBonusInfo.o: RankBonusInfo.cpp RankBonusInfo.h \
$(COREDIR)/Exception.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/StringStream.h $(COREDIR)/Assert.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h
RankBonus.o: RankBonus.cpp RankBonus.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h
CastleInfoManager.o: CastleInfoManager.cpp CastleInfoManager.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h PlayerCreature.h \
Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h Effect.h \
$(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h ItemUtil.h \
$(COREDIR)/Properties.h ZoneInfoManager.h Zone.h Tile.h Obstacle.h \
Portal.h quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h ZoneInfo.h ZoneGroupManager.h ZoneGroup.h \
$(COREDIR)/GameTime.h $(COREDIR)/Gpackets/GMServerInfo.h \
$(COREDIR)/DatagramPacket.h $(COREDIR)/Datagram.h VariableManager.h \
Guild.h GuildManager.h ZoneUtil.h NPCManager.h $(WARDIR)/War.h \
$(WARDIR)/Work.h $(WARDIR)/WarSystem.h $(WARDIR)/Scheduler.h \
$(WARDIR)/Schedule.h $(COREDIR)/Gpackets/GCWarList.h \
$(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
$(COREDIR)/RaceWarInfo.h $(WARDIR)/WarScheduler.h ClientManager.h \
EventManager.h Event.h EventRefreshHolyLandPlayer.h ShrineInfoManager.h \
EffectHasBloodBible.h EffectHasRelic.h CastleSkillInfo.h GamePlayer.h \
$(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
$(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h NPC.h Inventory.h VolumeInfo.h \
$(COUPLEDIR)/PartnerWaitingManager.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h StringPool.h $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCNoticeEvent.h \
  $(COREDIR)/Gpackets/GCModifyInformation.h
HolyLandRaceBonus.o: HolyLandRaceBonus.cpp HolyLandRaceBonus.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h CastleInfoManager.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h
ShrineInfoManager.o: ShrineInfoManager.cpp ShrineInfoManager.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(SERVDIR)/Mutex.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h $(WARDIR)/ZoneItemPosition.h \
$(WARDIR)/GlobalItemPosition.h ZoneUtil.h Creature.h Object.h \
$(COREDIR)/Assert.h EffectManager.h Effect.h $(SERVDIR)/Timeval.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/VSDateTime.h Zone.h Tile.h \
Item.h Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h ObjectRegistry.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h MonsterCorpse.h \
ItemFactory.h Inventory.h VolumeInfo.h InventorySlot.h Corpse.h \
ItemFactoryManager.h EffectShrineGuard.h EffectShrineHoly.h \
EffectShrineShield.h $(WARDIR)/War.h $(WARDIR)/Work.h \
$(WARDIR)/WarSystem.h $(WARDIR)/Scheduler.h $(WARDIR)/Schedule.h \
$(COREDIR)/Gpackets/GCWarList.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
$(COREDIR)/RaceWarInfo.h RelicUtil.h CastleInfoManager.h \
PlayerCreature.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h GlobalItemPositionLoader.h ZoneGroupManager.h \
ZoneGroup.h $(COREDIR)/GameTime.h $(COREDIR)/Gpackets/GMServerInfo.h \
$(COREDIR)/DatagramPacket.h $(COREDIR)/Datagram.h $(COREDIR)/Player.h \
CreatureUtil.h BloodBibleBonusManager.h BloodBibleBonus.h ItemUtil.h \
HolyLandManager.h ClientManager.h EventManager.h Event.h \
EffectHasRelic.h StringPool.h EventRefreshHolyLandPlayer.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(COREDIR)/Gpackets/GCAddEffect.h \
  $(COREDIR)/Gpackets/GCAddEffectToTile.h \
  $(COREDIR)/Gpackets/GCDeleteInventoryItem.h \
$(COREDIR)/Gpackets/GCBloodBibleStatus.h $(ITEMDIR)/BloodBible.h \
ItemInfo.h InfoClassManager.h ItemLoader.h
GlobalItemPositionLoader.o: GlobalItemPositionLoader.cpp \
GlobalItemPositionLoader.h Item.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h Effect.h $(SERVDIR)/Timeval.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(WARDIR)/GlobalItemPosition.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(SERVDIR)/Mutex.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(WARDIR)/InventoryItemPosition.h PlayerCreature.h Creature.h \
ObjectRegistry.h InventorySlot.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h \
$(WARDIR)/MouseItemPosition.h $(WARDIR)/ZoneItemPosition.h ZoneUtil.h \
$(WARDIR)/CorpseItemPosition.h $(WARDIR)/SubInventoryItemPosition.h
RelicUtil.o: RelicUtil.cpp RelicUtil.h $(COREDIR)/Exception.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/StringStream.h Effect.h Object.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Item.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Zone.h Tile.h Creature.h Obstacle.h \
Portal.h quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Corpse.h \
ItemFactory.h $(ITEMDIR)/BloodBible.h ItemInfo.h InfoClassManager.h \
ItemLoader.h $(ITEMDIR)/CastleSymbol.h Inventory.h VolumeInfo.h \
InventorySlot.h $(ITEMDIR)/SubInventory.h $(COREDIR)/Player.h \
PlayerCreature.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h ZoneInfoManager.h \
ZoneInfo.h ZoneGroupManager.h ZoneGroup.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
$(COREDIR)/Datagram.h CombatInfoManager.h $(ITEMDIR)/Relic.h \
CastleInfoManager.h HolyLandManager.h $(WARDIR)/DragonEyeManager.h \
$(ITEMDIR)/WarItem.h StringPool.h EffectHasVampireRelic.h \
EffectHasRelic.h EffectHasSlayerRelic.h EffectHasBloodBible.h \
EffectHasCastleSymbol.h EffectRelicPosition.h EffectRelicLock.h \
EffectDragonEye.h EffectSlayerLevelWarHeroItem.h \
EffectVampireLevelWarHeroItem.h EffectOustersLevelWarHeroItem.h \
$(COREDIR)/Gpackets/GCSystemMessage.h $(COREDIR)/Gpackets/GCAddEffect.h \
  $(COREDIR)/Gpackets/GCAddEffectToTile.h \
$(COREDIR)/Gpackets/GCDeleteInventoryItem.h HeroItemManager.h \
EffectOustersHeroItem.h EffectSlayerHeroItem.h EffectVampireHeroItem.h \
$(WARDIR)/WarSystem.h $(WARDIR)/Scheduler.h $(WARDIR)/Work.h \
$(WARDIR)/Schedule.h $(COREDIR)/Gpackets/GCWarList.h \
$(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
  $(COREDIR)/RaceWarInfo.h
HolyLandManager.o: HolyLandManager.cpp HolyLandManager.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(SERVDIR)/Mutex.h \
$(COREDIR)/VSDateTime.h PCManager.h CreatureManager.h Creature.h \
Object.h $(COREDIR)/Assert.h EffectManager.h Effect.h \
$(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h PlayerCreature.h ObjectRegistry.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h ShrineInfoManager.h Zone.h Tile.h Obstacle.h \
Portal.h quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h
BloodBibleBonus.o: BloodBibleBonus.cpp BloodBibleBonus.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h ItemUtil.h Item.h \
Object.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h Effect.h $(SERVDIR)/Timeval.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h
BloodBibleBonusManager.o: BloodBibleBonusManager.cpp BloodBibleBonus.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h ItemUtil.h Item.h \
Object.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h Effect.h $(SERVDIR)/Timeval.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h BloodBibleBonusManager.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(COREDIR)/Gpackets/GCHolyLandBonusInfo.h $(COREDIR)/PacketFactory.h \
  $(COREDIR)/BloodBibleBonusInfo.h
CastleShrineInfoManager.o: CastleShrineInfoManager.cpp \
CastleShrineInfoManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
ShrineInfoManager.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(WARDIR)/ZoneItemPosition.h \
$(WARDIR)/GlobalItemPosition.h ZoneUtil.h Creature.h Object.h \
$(COREDIR)/Assert.h EffectManager.h Effect.h $(SERVDIR)/Timeval.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/VSDateTime.h Zone.h Tile.h \
Item.h Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h ObjectRegistry.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h MonsterCorpse.h \
ItemFactory.h Inventory.h VolumeInfo.h InventorySlot.h Corpse.h \
ItemFactoryManager.h EffectShrineGuard.h EffectShrineHoly.h \
EffectShrineShield.h $(WARDIR)/War.h $(WARDIR)/Work.h \
$(WARDIR)/WarSystem.h $(WARDIR)/Scheduler.h $(WARDIR)/Schedule.h \
$(COREDIR)/Gpackets/GCWarList.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
$(COREDIR)/RaceWarInfo.h RelicUtil.h CastleInfoManager.h \
PlayerCreature.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h GlobalItemPositionLoader.h ZoneGroupManager.h \
ZoneGroup.h $(COREDIR)/GameTime.h $(COREDIR)/Gpackets/GMServerInfo.h \
$(COREDIR)/DatagramPacket.h $(COREDIR)/Datagram.h $(COREDIR)/Player.h \
$(WARDIR)/GuildWar.h CreatureUtil.h StringPool.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(COREDIR)/Gpackets/GCAddEffect.h \
  $(COREDIR)/Gpackets/GCAddEffectToTile.h \
$(COREDIR)/Gpackets/GCDeleteInventoryItem.h $(ITEMDIR)/CastleSymbol.h \
ItemInfo.h InfoClassManager.h ItemLoader.h
SkillPropertyManager.o: SkillPropertyManager.cpp SkillPropertyManager.h \
$(COREDIR)/Exception.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/StringStream.h SkillInfo.h Slayer.h PlayerCreature.h \
Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h Effect.h \
$(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h
StringPool.o: StringPool.cpp StringPool.h $(COREDIR)/Exception.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/StringStream.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h
PKZoneInfoManager.o: PKZoneInfoManager.cpp $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h Zone.h Tile.h Object.h $(COREDIR)/Assert.h Creature.h \
EffectManager.h Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h ZoneUtil.h \
$(COREDIR)/VSDateTime.h PKZoneInfoManager.h $(COREDIR)/Cpackets/CGSay.h \
  $(COREDIR)/PacketFactory.h
GameServerGroupInfoManager.o: GameServerGroupInfoManager.cpp \
GameServerGroupInfoManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
GameServerGroupInfo.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(SERVDIR)/Mutex.h $(DBDIR)/Statement.h $(DBDIR)/Result.h $(DBDIR)/DB.h
DefaultOptionSetInfo.o: DefaultOptionSetInfo.cpp DefaultOptionSetInfo.h \
$(COREDIR)/Exception.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/StringStream.h OptionInfo.h Item.h Object.h \
$(COREDIR)/Assert.h Effect.h $(SERVDIR)/Timeval.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h ItemUtil.h
CastleSkillInfo.o: CastleSkillInfo.cpp CastleSkillInfo.h \
$(COREDIR)/Exception.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/StringStream.h $(SKILLDIR)/Skill.h $(COREDIR)/Assert.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(SERVDIR)/Mutex.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
TimeLimitItemManager.o: TimeLimitItemManager.cpp TimeLimitItemManager.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/VSDateTime.h \
Item.h Object.h $(COREDIR)/Assert.h Effect.h $(SERVDIR)/Timeval.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h PlayerCreature.h Creature.h ObjectRegistry.h \
InventorySlot.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h $(COREDIR)/Gpackets/GCTimeLimitItemInfo.h
ItemMineInfo.o: ItemMineInfo.cpp ItemUtil.h Item.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
Effect.h $(SERVDIR)/Timeval.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ItemMineInfo.h ItemFactoryManager.h \
ItemFactory.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h Treasure.h
EventItemUtil.o: EventItemUtil.cpp EventItemUtil.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
Item.h Object.h $(COREDIR)/Assert.h Effect.h $(SERVDIR)/Timeval.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Slayer.h PlayerCreature.h Creature.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h VariableManager.h ItemFactoryManager.h \
  ItemFactory.h
SweeperSet.o: SweeperSet.cpp SweeperSet.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
MonsterCorpse.h Item.h Object.h $(COREDIR)/Assert.h Effect.h \
$(SERVDIR)/Timeval.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ItemFactory.h Inventory.h VolumeInfo.h \
InventorySlot.h Corpse.h $(ITEMDIR)/Sweeper.h ItemInfo.h \
InfoClassManager.h ItemLoader.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h Zone.h Tile.h Creature.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h ItemFactoryManager.h \
SweeperBonus.h ItemUtil.h SweeperBonusManager.h EffectKeepSweeper.h \
$(WARDIR)/GlobalItemPosition.h $(WARDIR)/CorpseItemPosition.h \
GlobalItemPositionLoader.h ZoneUtil.h $(COREDIR)/VSDateTime.h \
$(COREDIR)/Gpackets/GCAddEffect.h $(COREDIR)/PacketFactory.h
SweeperBonus.o: SweeperBonus.cpp $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h SweeperBonus.h ItemUtil.h Item.h Object.h \
$(COREDIR)/Assert.h Effect.h $(SERVDIR)/Timeval.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h
SweeperBonusManager.o: SweeperBonusManager.cpp Zone.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
Tile.h Object.h $(COREDIR)/Assert.h Creature.h EffectManager.h Effect.h \
$(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h ZoneUtil.h \
$(COREDIR)/VSDateTime.h SweeperBonus.h ItemUtil.h SweeperBonusManager.h \
LevelWarManager.h $(WARDIR)/Scheduler.h $(WARDIR)/Work.h \
$(WARDIR)/Schedule.h SweeperSet.h MonsterCorpse.h ItemFactory.h \
Inventory.h VolumeInfo.h InventorySlot.h Corpse.h $(ITEMDIR)/Sweeper.h \
ItemInfo.h InfoClassManager.h ItemLoader.h \
$(COREDIR)/Gpackets/GCWarList.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
$(COREDIR)/RaceWarInfo.h LevelWarItemManager.h $(ITEMDIR)/WarItem.h \
LevelWarZoneInfoManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(COREDIR)/Gpackets/GCSweeperBonusInfo.h $(COREDIR)/SweeperBonusInfo.h
LevelWar.o: LevelWar.cpp LevelWar.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(WARDIR)/Work.h LevelWarManager.h $(SERVDIR)/Mutex.h \
$(WARDIR)/Scheduler.h $(WARDIR)/Schedule.h $(COREDIR)/VSDateTime.h \
SweeperSet.h MonsterCorpse.h Item.h Object.h $(COREDIR)/Assert.h \
Effect.h $(SERVDIR)/Timeval.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ItemFactory.h Inventory.h VolumeInfo.h \
InventorySlot.h Corpse.h $(ITEMDIR)/Sweeper.h ItemInfo.h \
InfoClassManager.h ItemLoader.h $(COREDIR)/Gpackets/GCWarList.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/GuildWarInfo.h \
$(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h $(COREDIR)/RaceWarInfo.h \
LevelWarItemManager.h $(ITEMDIR)/WarItem.h
LevelWarManager.o: LevelWarManager.cpp $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(COREDIR)/Properties.h $(COREDIR)/Player.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h InventorySlot.h Item.h \
Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h ZoneGroupManager.h \
ZoneGroup.h Zone.h Tile.h Obstacle.h Portal.h quest/TriggerManager.h \
quest/Trigger.h quest/Condition.h quest/PropertyBuffer.h Sector.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
$(COREDIR)/Datagram.h StringPool.h LevelWar.h $(WARDIR)/Work.h \
LevelWarManager.h $(WARDIR)/Scheduler.h $(WARDIR)/Schedule.h \
SweeperSet.h MonsterCorpse.h ItemFactory.h Inventory.h VolumeInfo.h \
Corpse.h $(ITEMDIR)/Sweeper.h ItemInfo.h InfoClassManager.h ItemLoader.h \
$(COREDIR)/Gpackets/GCWarList.h $(COREDIR)/GuildWarInfo.h \
$(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h $(COREDIR)/RaceWarInfo.h \
LevelWarItemManager.h $(ITEMDIR)/WarItem.h $(COREDIR)/LevelWarInfo.h \
LevelWarZoneInfoManager.h SweeperBonus.h ItemUtil.h \
SweeperBonusManager.h VariableManager.h \
  $(COREDIR)/Gpackets/GCNoticeEvent.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
$(COREDIR)/Gpackets/GCSweeperBonusInfo.h $(COREDIR)/SweeperBonusInfo.h \
  $(COREDIR)/Cpackets/CGSay.h
LevelWarZoneInfoManager.o: LevelWarZoneInfoManager.cpp $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h Slayer.h PlayerCreature.h Creature.h Object.h \
$(COREDIR)/Assert.h EffectManager.h Effect.h $(SERVDIR)/Timeval.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h InventorySlot.h Item.h \
Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(SKILLDIR)/Skill.h \
$(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
$(COREDIR)/Gpackets/GCModifyInformation.h Vampire.h \
$(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
ZoneUtil.h LevelWarZoneInfoManager.h
RegenZoneManager.o: RegenZoneManager.cpp RegenZoneManager.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h MonsterCorpse.h Item.h \
Object.h $(COREDIR)/Assert.h Effect.h $(SERVDIR)/Timeval.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ItemFactory.h Inventory.h VolumeInfo.h \
InventorySlot.h Corpse.h $(SERVDIR)/Mutex.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h Zone.h Tile.h Creature.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h ZoneUtil.h \
$(COREDIR)/VSDateTime.h PlayerCreature.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h EffectRegenZone.h EffectTryingPosition.h \
Slayer.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(SKILLDIR)/Skill.h \
$(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
$(COREDIR)/Gpackets/GCModifyInformation.h Vampire.h \
$(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h HolyLandManager.h CastleInfoManager.h \
StringPool.h MonsterManager.h MonsterCounter.h SiegeManager.h \
$(WARDIR)/WarSystem.h $(WARDIR)/Scheduler.h $(WARDIR)/Work.h \
$(WARDIR)/Schedule.h $(COREDIR)/Gpackets/GCWarList.h \
$(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
$(COREDIR)/RaceWarInfo.h $(COREDIR)/Gpackets/GCAddEffectToTile.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(COREDIR)/Gpackets/GCAddEffect.h \
  $(COREDIR)/Gpackets/GCRegenZoneStatus.h
PetTypeInfo.o: PetTypeInfo.cpp PetTypeInfo.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/types/PetTypes.h $(COREDIR)/Exception.h \
$(COREDIR)/StringStream.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h
PetUtil.o: PetUtil.cpp PetUtil.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/types/PetTypes.h $(COREDIR)/PetInfo.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/VSDateTime.h PetExpInfo.h \
$(ITEMDIR)/PetItem.h Item.h Object.h $(COREDIR)/Assert.h Effect.h \
$(SERVDIR)/Timeval.h EffectManager.h $(COREDIR)/EffectInfo.h ItemInfo.h \
InfoClassManager.h ItemFactory.h ItemLoader.h $(SERVDIR)/Mutex.h \
PetTypeInfo.h PetAttrInfo.h $(COREDIR)/ModifyInfo.h GamePlayer.h \
$(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
  VariableManager.h
PetAttrInfo.o: PetAttrInfo.cpp PetAttrInfo.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/types/PetTypes.h $(COREDIR)/Exception.h \
$(COREDIR)/StringStream.h PetExpInfo.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h $(COREDIR)/PetInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/VSDateTime.h
PetExpInfo.o: PetExpInfo.cpp PetExpInfo.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/types/PetTypes.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(COREDIR)/Exception.h \
$(COREDIR)/StringStream.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h
RankExpTable.o: RankExpTable.cpp RankExpTable.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(COREDIR)/Assert.h
SlayerAttrExpTable.o: SlayerAttrExpTable.cpp SlayerAttrExpTable.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h ExpFwd.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(COREDIR)/Assert.h
Pet.o: Pet.cpp Pet.h Slayer.h PlayerCreature.h Creature.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
EffectManager.h Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
$(COREDIR)/PetInfo.h $(COREDIR)/types/PetTypes.h PetUtil.h GamePlayer.h \
$(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h Corpse.h ItemFactory.h \
$(SKILLDIR)/SkillUtil.h $(COREDIR)/Gpackets/GCPetUseSkill.h \
VariableManager.h EffectPetBonusExp.h EffectLoader.h
SystemAvailabilitiesManager.o: SystemAvailabilitiesManager.cpp \
SystemAvailabilitiesManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Gpackets/GCSystemAvailabilities.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h $(COREDIR)/Assert.h
LocalIP.o: LocalIP.cpp LocalIP.h
ItemGradeManager.o: ItemGradeManager.cpp ItemGradeManager.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h $(COREDIR)/Assert.h
EventZoneInfo.o: EventZoneInfo.cpp EventZoneInfo.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
Zone.h Tile.h Object.h $(COREDIR)/Assert.h Creature.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h ZoneUtil.h \
$(COREDIR)/VSDateTime.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
SMSServiceThread.o: SMSServiceThread.cpp SMSServiceThread.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(COREDIR)/Properties.h VariableManager.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h
SMSAddressBook.o: SMSAddressBook.cpp SMSAddressBook.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Gpackets/GCSMSAddressList.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h PlayerCreature.h Creature.h \
Object.h $(COREDIR)/Assert.h EffectManager.h Effect.h \
$(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h \
  $(COREDIR)/Gpackets/GCAddressListVerify.h
FiniteStateMachine.o: FiniteStateMachine.cpp FiniteStateMachine.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h $(SERVDIR)/Timeval.h \
$(COREDIR)/Assert.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/VSDateTime.h
GDRLairManager.o: GDRLairManager.cpp GDRLairManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h FiniteStateMachine.h $(SERVDIR)/Timeval.h \
$(COREDIR)/Assert.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/VSDateTime.h GDRLairAbstractStates.h Effect.h Object.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h ZoneUtil.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Zone.h Tile.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h EffectCastingTrap.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h MonsterAI.h Directive.h MonsterManager.h \
MonsterCounter.h $(COREDIR)/Gpackets/GCNoticeEvent.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSystemMessage.h \
EffectKickOut.h ZoneGroupManager.h ZoneGroup.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
$(COREDIR)/Datagram.h PacketUtil.h ItemFactoryManager.h ItemFactory.h \
$(COREDIR)/Gpackets/GCCreateItem.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h PlayerCreature.h InventorySlot.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h Inventory.h VolumeInfo.h ItemUtil.h \
$(COREDIR)/Player.h EffectGDRLairClose.h VariableManager.h \
$(COREDIR)/SXml.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(COREDIR)/Properties.h StringPool.h SystemAvailabilitiesManager.h \
  $(COREDIR)/Gpackets/GCSystemAvailabilities.h
GDRLairAbstractStates.o: GDRLairAbstractStates.cpp \
GDRLairAbstractStates.h FiniteStateMachine.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(SERVDIR)/Timeval.h $(COREDIR)/Assert.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/VSDateTime.h \
Effect.h Object.h StringPool.h $(COREDIR)/Gpackets/GCSay.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCGlobalChat.h Zone.h Tile.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Monster.h \
MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h Treasure.h \
PrecedenceTable.h CreatureUtil.h ZoneUtil.h GDRLairManager.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h MonsterManager.h \
MonsterCounter.h $(COREDIR)/Gpackets/GCSkillToObjectOK4.h \
$(SKILLDIR)/Skill.h ZoneGroup.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
  $(COREDIR)/Datagram.h
NicknameBook.o: NicknameBook.cpp NicknameBook.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/NicknameInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h PlayerCreature.h Creature.h Object.h \
$(COREDIR)/Assert.h EffectManager.h Effect.h $(SERVDIR)/Timeval.h \
$(COREDIR)/EffectInfo.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h \
$(COREDIR)/Gpackets/GCNicknameList.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h LevelNickInfoManager.h Guild.h GuildManager.h
LevelNickInfoManager.o: LevelNickInfoManager.cpp LevelNickInfoManager.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h Creature.h Object.h \
$(COREDIR)/Assert.h EffectManager.h Effect.h $(SERVDIR)/Timeval.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h
SiegeManager.o: SiegeManager.cpp SiegeManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
Zone.h Tile.h Object.h $(COREDIR)/Assert.h Creature.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h ZoneUtil.h \
$(COREDIR)/VSDateTime.h Monster.h MonsterInfo.h MonsterSummonInfo.h \
MonsterInfoTypes.h Treasure.h PrecedenceTable.h MonsterCorpse.h \
ItemFactory.h Inventory.h VolumeInfo.h InventorySlot.h Corpse.h \
EffectShareHP.h PlayerCreature.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h $(COREDIR)/Gpackets/GCDeleteInventoryItem.h \
$(COREDIR)/Gpackets/GCSystemMessage.h $(COREDIR)/Gpackets/GCCannotAdd.h \
RelicUtil.h $(COREDIR)/Player.h GamePlayer.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h PCFinder.h NPC.h \
$(COUPLEDIR)/PartnerWaitingManager.h CreatureUtil.h CastleInfoManager.h \
$(WARDIR)/WarSystem.h $(WARDIR)/Scheduler.h $(WARDIR)/Work.h \
$(WARDIR)/Schedule.h $(COREDIR)/Gpackets/GCWarList.h \
$(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
$(COREDIR)/RaceWarInfo.h EventTransport.h StringPool.h
BroadcastFilter.o: BroadcastFilter.cpp BroadcastFilter.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h GamePlayer.h \
$(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
$(COREDIR)/SocketInputStream.h $(SERVDIR)/Mutex.h $(COREDIR)/Packet.h \
$(SERVDIR)/Timeval.h $(COREDIR)/PlayerStatus.h EventManager.h Event.h \
$(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h \
Item.h Object.h $(COREDIR)/Assert.h Effect.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
  Creature.h
Store.o: Store.cpp Store.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/StoreInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h $(COREDIR)/Assert.h Item.h Object.h Effect.h \
$(SERVDIR)/Timeval.h EffectManager.h $(COREDIR)/EffectInfo.h
AdvancementClassExpTable.o: AdvancementClassExpTable.cpp \
AdvancementClassExpTable.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(COREDIR)/Assert.h
DynamicZoneManager.o: DynamicZoneManager.cpp DynamicZoneManager.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h $(SERVDIR)/Mutex.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h DynamicZoneGroup.h \
DynamicZoneScriptGroup.h DynamicZoneInfo.h $(COREDIR)/Assert.h
DynamicZoneInfo.o: DynamicZoneInfo.cpp DynamicZoneInfo.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h $(COREDIR)/Assert.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h
DynamicZone.o: DynamicZone.cpp DynamicZone.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(SERVDIR)/Timeval.h Creature.h Object.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
EffectManager.h Effect.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Monster.h MonsterInfo.h \
MonsterSummonInfo.h MonsterInfoTypes.h Treasure.h Item.h \
PrecedenceTable.h DynamicZoneGroup.h DynamicZoneInfo.h ZoneInfoManager.h \
Zone.h Tile.h Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
ZoneInfo.h ZoneGroupManager.h ZoneGroup.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
$(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h
DynamicZoneGroup.o: DynamicZoneGroup.cpp DynamicZoneGroup.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h DynamicZone.h \
$(SERVDIR)/Timeval.h Creature.h Object.h $(COREDIR)/Exception.h \
$(COREDIR)/StringStream.h $(COREDIR)/Assert.h EffectManager.h Effect.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Monster.h MonsterInfo.h \
MonsterSummonInfo.h MonsterInfoTypes.h Treasure.h Item.h \
PrecedenceTable.h DynamicZoneManager.h $(SERVDIR)/Mutex.h \
DynamicZoneFactoryManager.h DynamicZoneInfo.h
DynamicZoneGateOfAlter.o: DynamicZoneGateOfAlter.cpp \
DynamicZoneGateOfAlter.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h DynamicZone.h $(SERVDIR)/Timeval.h Creature.h \
Object.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h EffectManager.h Effect.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Monster.h MonsterInfo.h \
MonsterSummonInfo.h MonsterInfoTypes.h Treasure.h Item.h \
PrecedenceTable.h DynamicZoneGroup.h DynamicZoneInfo.h PlayerCreature.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h ZoneUtil.h EffectDeleteTile.h EffectLoader.h \
$(SKILLDIR)/HitRoll.h EffectTilePortal.h GQuestManager.h \
GQuestInventory.h $(COREDIR)/Gpackets/GCGQuestInventory.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCAddEffectToTile.h \
  $(COREDIR)/Gpackets/GCDeleteEffectFromTile.h
DynamicZoneAlterOfBlood.o: DynamicZoneAlterOfBlood.cpp \
DynamicZoneAlterOfBlood.h DynamicZone.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(SERVDIR)/Timeval.h Creature.h Object.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
EffectManager.h Effect.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Monster.h MonsterInfo.h \
MonsterSummonInfo.h MonsterInfoTypes.h Treasure.h Item.h \
PrecedenceTable.h DynamicZoneGroup.h DynamicZoneInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
PlayerCreature.h InventorySlot.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h GQuestManager.h \
GQuestInventory.h $(COREDIR)/Gpackets/GCGQuestInventory.h \
MonsterManager.h MonsterCounter.h EffectKillTimer.h EffectLoader.h \
$(SKILLDIR)/EffectCauseCriticalWounds.h $(COREDIR)/NPCInfo.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCAddEffectToTile.h
DynamicZoneFactoryManager.o: DynamicZoneFactoryManager.cpp \
DynamicZoneFactoryManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
DynamicZone.h $(SERVDIR)/Timeval.h Creature.h Object.h \
$(COREDIR)/Assert.h EffectManager.h Effect.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Monster.h MonsterInfo.h \
MonsterSummonInfo.h MonsterInfoTypes.h Treasure.h Item.h \
PrecedenceTable.h DynamicZoneGroup.h DynamicZoneInfo.h \
DynamicZoneGateOfAlter.h DynamicZoneAlterOfBlood.h \
DynamicZoneSlayerMirrorOfAbyss.h DynamicZoneVampireMirrorOfAbyss.h \
DynamicZoneOustersMirrorOfAbyss.h DynamicZoneScript.h
DynamicZoneSlayerMirrorOfAbyss.o: DynamicZoneSlayerMirrorOfAbyss.cpp \
DynamicZoneSlayerMirrorOfAbyss.h DynamicZone.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(SERVDIR)/Timeval.h Creature.h Object.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
EffectManager.h Effect.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Monster.h MonsterInfo.h \
MonsterSummonInfo.h MonsterInfoTypes.h Treasure.h Item.h \
PrecedenceTable.h DynamicZoneGroup.h DynamicZoneInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
Slayer.h PlayerCreature.h InventorySlot.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
MonsterManager.h MonsterCounter.h EffectKillTimer.h EffectLoader.h \
GQuestManager.h GQuestInventory.h \
  $(COREDIR)/Gpackets/GCGQuestInventory.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
DynamicZoneVampireMirrorOfAbyss.o: DynamicZoneVampireMirrorOfAbyss.cpp \
DynamicZoneVampireMirrorOfAbyss.h DynamicZone.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(SERVDIR)/Timeval.h Creature.h Object.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
EffectManager.h Effect.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Monster.h MonsterInfo.h \
MonsterSummonInfo.h MonsterInfoTypes.h Treasure.h Item.h \
PrecedenceTable.h DynamicZoneGroup.h DynamicZoneInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
Slayer.h PlayerCreature.h InventorySlot.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
MonsterManager.h MonsterCounter.h EffectKillTimer.h EffectLoader.h \
GQuestManager.h GQuestInventory.h \
  $(COREDIR)/Gpackets/GCGQuestInventory.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
DynamicZoneOustersMirrorOfAbyss.o: DynamicZoneOustersMirrorOfAbyss.cpp \
DynamicZoneOustersMirrorOfAbyss.h DynamicZone.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(SERVDIR)/Timeval.h Creature.h Object.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
EffectManager.h Effect.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Monster.h MonsterInfo.h \
MonsterSummonInfo.h MonsterInfoTypes.h Treasure.h Item.h \
PrecedenceTable.h DynamicZoneGroup.h DynamicZoneInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
Slayer.h PlayerCreature.h InventorySlot.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
MonsterManager.h MonsterCounter.h EffectKillTimer.h EffectLoader.h \
GQuestManager.h GQuestInventory.h \
  $(COREDIR)/Gpackets/GCGQuestInventory.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
NewYear2005ItemUtil.o: NewYear2005ItemUtil.cpp EventItemUtil.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h Item.h Object.h \
$(COREDIR)/Assert.h Effect.h $(SERVDIR)/Timeval.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Slayer.h PlayerCreature.h Creature.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h VariableManager.h ItemFactoryManager.h \
  ItemFactory.h
BalloonHeadbandUtil.o: BalloonHeadbandUtil.cpp BalloonHeadbandUtil.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h Item.h Object.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
Effect.h $(SERVDIR)/Timeval.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h VariableManager.h ItemUtil.h \
OptionInfo.h PlayerCreature.h Creature.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h $(COREDIR)/VSDateTime.h \
$(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h ItemFactoryManager.h ItemFactory.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h
Fall2005ItemUtil.o: Fall2005ItemUtil.cpp EventItemUtil.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h Item.h Object.h \
$(COREDIR)/Assert.h Effect.h $(SERVDIR)/Timeval.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Slayer.h PlayerCreature.h Creature.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h VariableManager.h ItemFactoryManager.h \
  ItemFactory.h
ViewAbility.o: ViewAbility.cpp ViewAbility.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Assert.h $(COREDIR)/Exception.h \
$(COREDIR)/StringStream.h Viewable.h ViewEffect.h Creature.h Object.h \
EffectManager.h Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
  $(COREDIR)/SocketOutputStream.h
Viewable.o: Viewable.cpp Viewable.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h ViewEffect.h
Born.o: Born.cpp Born.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
  $(COREDIR)/Utility.h
MikllizzLairManager.o: MikllizzLairManager.cpp MikllizzLairManager.h \
$(SERVDIR)/Timeval.h $(SERVDIR)/Mutex.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h Zone.h Tile.h Object.h Creature.h EffectManager.h \
Effect.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h VariableManager.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h MonsterAI.h Directive.h MonsterManager.h \
MonsterCounter.h PlayerCreature.h InventorySlot.h Garbage.h RankBonus.h \
ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Inventory.h VolumeInfo.h ItemUtil.h \
ItemFactoryManager.h ItemFactory.h PacketUtil.h $(COREDIR)/Player.h \
MonsterCorpse.h Corpse.h ZoneInfoManager.h ZoneInfo.h ZoneGroupManager.h \
ZoneGroup.h $(COREDIR)/GameTime.h $(COREDIR)/Gpackets/GMServerInfo.h \
$(COREDIR)/DatagramPacket.h $(COREDIR)/Datagram.h StringPool.h \
EventTransport.h Event.h GamePlayer.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h MasterLairInfoManager.h \
ItemGradeManager.h Slayer.h $(COREDIR)/PCSlayerInfo.h \
$(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
$(COREDIR)/Gpackets/GCModifyInformation.h Vampire.h \
$(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
ZoneUtil.h $(COREDIR)/Gpackets/GCNoticeEvent.h \
$(COREDIR)/Gpackets/GCSystemMessage.h $(COREDIR)/Gpackets/GCCreateItem.h \
  $(COREDIR)/Gpackets/GCDeleteObject.h
CastleDungeonMonsterManager.o: CastleDungeonMonsterManager.cpp \
CastleDungeonMonsterManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
ZoneUtil.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/VSDateTime.h Zone.h Tile.h \
Item.h Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
MonsterManager.h MonsterCounter.h
EventSurvivalZoneManager.o: EventSurvivalZoneManager.cpp \
EventSurvivalZoneManager.h $(SERVDIR)/Timeval.h $(SERVDIR)/Mutex.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
Zone.h Tile.h Object.h Creature.h EffectManager.h Effect.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h VariableManager.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h MonsterAI.h Directive.h MonsterManager.h \
MonsterCounter.h PlayerCreature.h InventorySlot.h Garbage.h RankBonus.h \
ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Inventory.h VolumeInfo.h ItemUtil.h \
ItemFactoryManager.h ItemFactory.h PacketUtil.h $(COREDIR)/Player.h \
MonsterCorpse.h Corpse.h ZoneInfoManager.h ZoneInfo.h ZoneGroupManager.h \
ZoneGroup.h $(COREDIR)/GameTime.h $(COREDIR)/Gpackets/GMServerInfo.h \
$(COREDIR)/DatagramPacket.h $(COREDIR)/Datagram.h StringPool.h \
EventTransport.h Event.h GamePlayer.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h MasterLairInfoManager.h \
ItemGradeManager.h $(SKILLDIR)/EffectEdgeArch.h \
  $(COREDIR)/Gpackets/GCNoticeEvent.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
$(COREDIR)/Gpackets/GCDeleteObject.h $(COREDIR)/Gpackets/GCAddEffect.h
PlayerInventory.o: PlayerInventory.cpp PlayerCreature.h Creature.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
EffectManager.h Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h PlayerInventory.h \
Inventory.h VolumeInfo.h ContractOfBloodUtil.h
ContractOfBloodUtil.o: ContractOfBloodUtil.cpp ContractOfBloodUtil.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h Inventory.h Item.h \
Object.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h Effect.h $(SERVDIR)/Timeval.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h VolumeInfo.h InventorySlot.h \
PlayerCreature.h Creature.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h PlayerInventory.h \
VariableManager.h ItemUtil.h
HellGardenTowerManager.o: HellGardenTowerManager.cpp \
HellGardenTowerManager.h $(SERVDIR)/Timeval.h $(SERVDIR)/Mutex.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
Zone.h Tile.h Object.h Creature.h EffectManager.h Effect.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h VariableManager.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h MonsterAI.h Directive.h MonsterManager.h \
MonsterCounter.h PlayerCreature.h InventorySlot.h Garbage.h RankBonus.h \
ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Inventory.h VolumeInfo.h ItemUtil.h \
ItemFactoryManager.h ItemFactory.h ItemInfoManager.h ItemInfo.h \
InfoClassManager.h PacketUtil.h $(COREDIR)/Player.h MonsterCorpse.h \
Corpse.h ZoneInfoManager.h ZoneInfo.h ZoneGroupManager.h ZoneGroup.h \
$(COREDIR)/GameTime.h $(COREDIR)/Gpackets/GMServerInfo.h \
$(COREDIR)/DatagramPacket.h $(COREDIR)/Datagram.h StringPool.h \
EventTransport.h Event.h GamePlayer.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h MasterLairInfoManager.h \
ItemGradeManager.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
  $(COREDIR)/Gpackets/GCNoticeEvent.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCDeleteObject.h
ThirdEnchantInfo.o: ThirdEnchantInfo.cpp ThirdEnchantInfo.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h ItemUtil.h Item.h \
Object.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h Effect.h $(SERVDIR)/Timeval.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h
ItemClassInfo.o: ItemClassInfo.cpp ItemClassInfo.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h Item.h Object.h $(COREDIR)/Exception.h \
$(COREDIR)/StringStream.h $(COREDIR)/Assert.h Effect.h \
$(SERVDIR)/Timeval.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h
ContributeInfo.o: ContributeInfo.cpp ContributeInfo.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(SERVDIR)/Mutex.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
HeroItemManager.o: HeroItemManager.cpp HeroItemManager.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(ITEMDIR)/WarItem.h \
Item.h Object.h $(COREDIR)/Assert.h Effect.h $(SERVDIR)/Timeval.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ItemInfo.h InfoClassManager.h \
ItemFactory.h ItemLoader.h $(SERVDIR)/Mutex.h ItemFactoryManager.h \
ZoneUtil.h Creature.h $(COREDIR)/VSDateTime.h Zone.h Tile.h Obstacle.h \
Portal.h quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
GlobalItemPositionLoader.h $(WARDIR)/GlobalItemPosition.h \
EffectVampireHeroItem.h EffectHasRelic.h EffectSlayerHeroItem.h \
EffectOustersHeroItem.h ShrineInfoManager.h
MenegrothDoungeonManager.o: MenegrothDoungeonManager.cpp \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h Creature.h Object.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
EffectManager.h Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Slayer.h PlayerCreature.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
StringPool.h $(COREDIR)/Player.h MenegrothDoungeonManager.h \
EffectMenegrothDoungeon.h EffectLoader.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
MenegrothDoungeonZoneManager.o: MenegrothDoungeonZoneManager.cpp \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h Monster.h Creature.h \
Object.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h EffectManager.h Effect.h $(SERVDIR)/Timeval.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h MonsterInfo.h MonsterSummonInfo.h \
MonsterInfoTypes.h Treasure.h Item.h PrecedenceTable.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
MonsterManager.h MonsterCounter.h MenegrothDoungeonZoneManager.h \
MenegrothDoungeonManager.h $(SKILLDIR)/EffectMenegrothTrap1.h \
EffectLoader.h $(SKILLDIR)/EffectMenegrothTrap2.h EffectSummonCabracam.h \
StringPool.h $(COREDIR)/Player.h PlayerCreature.h InventorySlot.h \
Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h ItemFactoryManager.h \
ItemFactory.h Inventory.h VolumeInfo.h ItemUtil.h PacketUtil.h \
VariableManager.h $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCAddEffect.h \
  $(COREDIR)/Gpackets/GCAddEffectToTile.h \
  $(COREDIR)/Gpackets/GCCreateItem.h
LevelWarItemManager.o: LevelWarItemManager.cpp LevelWarItemManager.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(ITEMDIR)/WarItem.h \
Item.h Object.h $(COREDIR)/Assert.h Effect.h $(SERVDIR)/Timeval.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ItemInfo.h InfoClassManager.h \
ItemFactory.h ItemLoader.h $(SERVDIR)/Mutex.h ItemFactoryManager.h \
ZoneUtil.h Creature.h $(COREDIR)/VSDateTime.h Zone.h Tile.h Obstacle.h \
Portal.h quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
GlobalItemPositionLoader.h $(WARDIR)/GlobalItemPosition.h \
EffectVampireLevelWarHeroItem.h EffectHasRelic.h \
EffectSlayerLevelWarHeroItem.h EffectOustersLevelWarHeroItem.h \
ShrineInfoManager.h LevelWarManager.h $(WARDIR)/Scheduler.h \
$(WARDIR)/Work.h $(WARDIR)/Schedule.h SweeperSet.h MonsterCorpse.h \
Inventory.h VolumeInfo.h InventorySlot.h Corpse.h $(ITEMDIR)/Sweeper.h \
$(COREDIR)/Gpackets/GCWarList.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
  $(COREDIR)/RaceWarInfo.h
EventGiftBoxRewardManager.o: EventGiftBoxRewardManager.cpp \
EventGiftBoxRewardManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
Item.h Object.h $(COREDIR)/Assert.h Effect.h $(SERVDIR)/Timeval.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h GamePlayer.h $(COREDIR)/Player.h \
$(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
$(SERVDIR)/Mutex.h $(COREDIR)/PlayerStatus.h EventManager.h Event.h \
$(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
Slayer.h PlayerCreature.h Creature.h ObjectRegistry.h InventorySlot.h \
Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
$(COREDIR)/Gpackets/GCModifyInformation.h Vampire.h \
$(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h NPC.h \
$(COUPLEDIR)/PartnerWaitingManager.h ItemFactoryManager.h ItemFactory.h \
ItemUtil.h ItemInfoManager.h ItemInfo.h InfoClassManager.h \
VariableManager.h FlagSet.h $(COREDIR)/Gpackets/GCNPCResponse.h \
$(COREDIR)/Gpackets/GCNPCAsk.h $(COREDIR)/Gpackets/GCUseOK.h \
$(ITEMDIR)/SlayerPortalItem.h $(ITEMDIR)/VampirePortalItem.h \
  $(ITEMDIR)/OustersSummonItem.h
EventBlitzRewardManager.o: EventBlitzRewardManager.cpp \
EventBlitzRewardManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
Item.h Object.h $(COREDIR)/Assert.h Effect.h $(SERVDIR)/Timeval.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h GamePlayer.h $(COREDIR)/Player.h \
$(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
$(SERVDIR)/Mutex.h $(COREDIR)/PlayerStatus.h EventManager.h Event.h \
$(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
Slayer.h PlayerCreature.h Creature.h ObjectRegistry.h InventorySlot.h \
Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
$(COREDIR)/Gpackets/GCModifyInformation.h Vampire.h \
$(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h NPC.h \
$(COUPLEDIR)/PartnerWaitingManager.h ItemFactoryManager.h ItemFactory.h \
ItemUtil.h ItemInfoManager.h ItemInfo.h InfoClassManager.h \
VariableManager.h FlagSet.h $(COREDIR)/Gpackets/GCNPCResponse.h \
$(COREDIR)/Gpackets/GCNPCAsk.h $(COREDIR)/Gpackets/GCUseOK.h
DynamicZoneScript.o: DynamicZoneScript.cpp DynamicZoneManager.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h $(SERVDIR)/Mutex.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h DynamicZoneScript.h \
DynamicZone.h $(SERVDIR)/Timeval.h Creature.h Object.h \
$(COREDIR)/Assert.h EffectManager.h Effect.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Monster.h MonsterInfo.h \
MonsterSummonInfo.h MonsterInfoTypes.h Treasure.h Item.h \
PrecedenceTable.h DynamicZoneGroup.h DynamicZoneInfo.h PlayerCreature.h \
ObjectRegistry.h InventorySlot.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h ZoneUtil.h \
EffectDeleteTile.h EffectLoader.h $(SKILLDIR)/HitRoll.h \
EffectTilePortal.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
MonsterManager.h MonsterCounter.h MonsterAI.h Directive.h \
$(COREDIR)/Properties.h $(SCRIPTDIR)/DEScriptZone.h \
$(SCRIPTDIR)/DEScript.h $(SCRIPTDIR)/lua_tinker.h \
$(COREDIR)/Gpackets/GCSystemMessage.h EventTransport.h Event.h \
DynamicZoneScriptGroup.h GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h ZoneInfo.h ZoneInfoManager.h
DynamicZoneScriptGroup.o: DynamicZoneScriptGroup.cpp \
DynamicZoneScriptGroup.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h DynamicZoneGroup.h DynamicZone.h \
$(SERVDIR)/Timeval.h Creature.h Object.h $(COREDIR)/Exception.h \
$(COREDIR)/StringStream.h $(COREDIR)/Assert.h EffectManager.h Effect.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Monster.h MonsterInfo.h \
MonsterSummonInfo.h MonsterInfoTypes.h Treasure.h Item.h \
PrecedenceTable.h DynamicZoneScript.h DynamicZoneManager.h \
$(SERVDIR)/Mutex.h DynamicZoneFactoryManager.h DynamicZoneInfo.h
EffectScript.o: EffectScript.cpp EffectScript.h Effect.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h $(SCRIPTDIR)/DEScriptEffect.h \
$(SCRIPTDIR)/DEScript.h $(SCRIPTDIR)/lua_tinker.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Monster.h MonsterInfo.h \
MonsterSummonInfo.h MonsterInfoTypes.h Treasure.h Item.h \
PrecedenceTable.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCSystemMessage.h $(COREDIR)/PacketFactory.h \
PlayerCreature.h InventorySlot.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h ZoneUtil.h \
$(COREDIR)/Properties.h PacketUtil.h $(COREDIR)/Player.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SkillUtil.h Slayer.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
$(COREDIR)/Gpackets/GCModifyInformation.h Vampire.h \
$(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
  $(COREDIR)/Gpackets/GCSkillToObjectOK1.h \
  $(COREDIR)/Gpackets/GCSkillToObjectOK2.h \
  $(COREDIR)/Gpackets/GCSkillToObjectOK4.h
SkillScript.o: SkillScript.cpp SkillScript.h $(SKILLDIR)/SkillHandler.h \
$(SKILLDIR)/Skill.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h SkillInfo.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h Slayer.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
$(COREDIR)/Gpackets/GCModifyInformation.h Vampire.h \
$(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h $(SKILLDIR)/HitRoll.h \
$(SKILLDIR)/SkillUtil.h ZoneUtil.h GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h $(COREDIR)/Properties.h \
$(SCRIPTDIR)/DEScriptSkill.h $(SCRIPTDIR)/DEScript.h \
$(SCRIPTDIR)/lua_tinker.h $(COREDIR)/Gpackets/GCSystemMessage.h \
$(SKILLDIR)/SimpleSkill.h $(SKILLDIR)/SimpleMeleeSkill.h \
$(SKILLDIR)/SimpleMissileSkill.h $(SKILLDIR)/SimpleTileMissileSkill.h
InstanceDoungeonManager.o: InstanceDoungeonManager.cpp \
InstanceDoungeonManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h DynamicZoneManager.h $(SERVDIR)/Mutex.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h DynamicZoneInfo.h \
DynamicZoneScriptGroup.h DynamicZoneGroup.h DynamicZoneScript.h \
DynamicZone.h $(SERVDIR)/Timeval.h Creature.h Object.h \
$(COREDIR)/Assert.h EffectManager.h Effect.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Monster.h MonsterInfo.h \
MonsterSummonInfo.h MonsterInfoTypes.h Treasure.h Item.h \
PrecedenceTable.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
TimeCheckerLoader.o: TimeCheckerLoader.cpp TimeCheckerLoader.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/TimeChecker.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/../server/Timeval.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(DBDIR)/Connection.h \
$(SERVDIR)/Mutex.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
WeekItemListManager.o: WeekItemListManager.cpp WeekItemListManager.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h Item.h Object.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
Effect.h $(SERVDIR)/Timeval.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h ItemFactoryManager.h ItemFactory.h PlayerCreature.h \
Creature.h ObjectRegistry.h InventorySlot.h Garbage.h RankBonus.h \
ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h $(COREDIR)/Player.h ItemUtil.h \
ItemInfoManager.h ItemInfo.h InfoClassManager.h
GlobalNPCManager.o: GlobalNPCManager.cpp GlobalNPCManager.h \
CreatureManager.h Creature.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h EffectManager.h Effect.h $(SERVDIR)/Timeval.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(SERVDIR)/Mutex.h NPC.h Zone.h Tile.h \
Item.h Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h ObjectRegistry.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h InventorySlot.h \
$(COUPLEDIR)/PartnerWaitingManager.h PlayerCreature.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h PCFinder.h
SkillCastingTimeManager.o: SkillCastingTimeManager.cpp \
SkillCastingTimeManager.h Item.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h Effect.h $(SERVDIR)/Timeval.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(SKILLDIR)/Skill.h
md5.o: md5.cpp md5.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h
PVPSystemManager.o: PVPSystemManager.cpp $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h Creature.h Object.h $(COREDIR)/Exception.h \
$(COREDIR)/StringStream.h $(COREDIR)/Assert.h EffectManager.h Effect.h \
$(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Slayer.h PlayerCreature.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
StringPool.h $(COREDIR)/Player.h PVPSystemManager.h \
$(COREDIR)/Gpackets/GCSystemMessage.h EffectContinualGroundAttack.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h MonsterCorpse.h ItemFactory.h Corpse.h \
EffectShrineGuard.h EffectShrineShield.h \
$(COREDIR)/Gpackets/GCAddEffect.h ItemFactoryManager.h \
$(COREDIR)/Gpackets/GCDeleteInventoryItem.h RelicUtil.h \
ZoneGroupManager.h ZoneGroup.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
$(COREDIR)/Datagram.h ItemInfo.h ItemInfoManager.h InfoClassManager.h \
ItemUtil.h $(COREDIR)/Gpackets/GCCreateItem.h PacketUtil.h \
GlobalItemPositionLoader.h $(WARDIR)/GlobalItemPosition.h GamePlayer.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h MonsterManager.h MonsterCounter.h \
ZoneUtil.h PCFinder.h NPC.h $(COUPLEDIR)/PartnerWaitingManager.h \
EventTransport.h VariableManager.h
Monster.o: Monster.cpp Monster.h Creature.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h EffectManager.h Effect.h $(SERVDIR)/Timeval.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h MonsterInfo.h MonsterSummonInfo.h \
MonsterInfoTypes.h Treasure.h Item.h PrecedenceTable.h MonsterManager.h \
CreatureManager.h $(SERVDIR)/Mutex.h MonsterCounter.h Slayer.h \
PlayerCreature.h ObjectRegistry.h InventorySlot.h Garbage.h RankBonus.h \
ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
Inventory.h VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
MonsterAI.h Directive.h AbilityBalance.h MonsterNameManager.h \
MonsterFunctionObject.h VariableManager.h StringPool.h \
$(SKILLDIR)/SkillUtil.h $(SKILLDIR)/SkillHandler.h SkillInfo.h \
$(SKILLDIR)/HitRoll.h ZoneUtil.h GamePlayer.h $(COREDIR)/Player.h \
  $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h $(COREDIR)/Gpackets/GCAddMonster.h \
$(COREDIR)/Gpackets/GCMove.h $(COREDIR)/Gpackets/GCStatusCurrentHP.h \
$(COREDIR)/Gpackets/GCSay.h $(SKILLDIR)/SkillHandlerManager.h \
$(SKILLDIR)/EffectParalyze.h EffectLoader.h $(SKILLDIR)/EffectDoom.h \
$(SKILLDIR)/EffectTransformToWolf.h $(SKILLDIR)/EffectTransformToBat.h \
$(SKILLDIR)/EffectPeace.h $(SKILLDIR)/EffectInvisibility.h \
$(SKILLDIR)/SummonGroundElemental.h $(SERVDIR)/Profile.h SiegeManager.h \
GDRLairManager.h FiniteStateMachine.h GDRLairAbstractStates.h Viewable.h \
ViewEffect.h EffectRegenerate.h
MonsterInfo.o: MonsterInfo.cpp MonsterInfoTypes.h MonsterInfo.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
Creature.h Object.h EffectManager.h Effect.h $(SERVDIR)/Timeval.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h MonsterSummonInfo.h Treasure.h Item.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(SERVDIR)/Mutex.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(COREDIR)/Properties.h $(SKILLDIR)/EffectObservingEye.h \
$(SKILLDIR)/EffectDetectInvisibility.h EffectLoader.h $(COREDIR)/SXml.h \
  ViewAbility.h
MonsterManager.o: MonsterManager.cpp MonsterManager.h CreatureManager.h \
Creature.h Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
EffectManager.h Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(SERVDIR)/Mutex.h MonsterCounter.h \
Item.h $(SERVDIR)/LogClient.h MonsterInfo.h MonsterSummonInfo.h \
MonsterInfoTypes.h Treasure.h ItemInfoManager.h ItemInfo.h \
InfoClassManager.h GamePlayer.h $(COREDIR)/Player.h \
$(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
$(COREDIR)/PlayerStatus.h EventManager.h Event.h $(SKILLDIR)/Skill.h \
$(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
MonsterCorpse.h ItemFactory.h Inventory.h VolumeInfo.h InventorySlot.h \
Corpse.h Tile.h Obstacle.h Portal.h quest/TriggerManager.h \
quest/Trigger.h quest/Condition.h quest/PropertyBuffer.h Sector.h Zone.h \
ObjectRegistry.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h Monster.h \
PrecedenceTable.h OptionInfo.h $(ITEMDIR)/Skull.h ItemLoader.h \
$(ITEMDIR)/EventStar.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h ItemFactoryManager.h \
ZoneUtil.h CreatureUtil.h VariableManager.h MonsterNameManager.h \
MasterLairInfoManager.h LuckInfo.h ItemUtil.h EventItemUtil.h \
$(WARDIR)/WarSystem.h $(WARDIR)/Scheduler.h $(WARDIR)/Work.h \
$(WARDIR)/Schedule.h $(COREDIR)/Gpackets/GCWarList.h \
$(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
$(COREDIR)/RaceWarInfo.h $(COREDIR)/Properties.h CastleInfoManager.h \
PlayerCreature.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h SweeperBonusManager.h \
$(SKILLDIR)/SummonGroundElemental.h $(SKILLDIR)/SkillHandler.h \
SkillInfo.h Slayer.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h $(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
$(SKILLDIR)/HitRoll.h $(SKILLDIR)/SkillUtil.h \
$(SKILLDIR)/EffectHarpoonBomb.h EffectLoader.h EffectPacketSend.h \
ItemGradeManager.h StringPool.h Viewable.h ViewEffect.h \
CastleDungeonMonsterManager.h RelicUtil.h \
$(COREDIR)/Gpackets/GCCreatureDied.h $(COREDIR)/Gpackets/GCAddEffect.h \
  $(COREDIR)/Gpackets/GCAddEffectToTile.h \
$(COREDIR)/Gpackets/GCDeleteObject.h $(COREDIR)/Gpackets/GCSay.h \
$(SERVDIR)/Profile.h GDRLairManager.h FiniteStateMachine.h \
GDRLairAbstractStates.h DynamicZone.h DynamicZoneGroup.h \
DynamicZoneGateOfAlter.h $(COREDIR)/TimeChecker.h \
  $(COREDIR)/../server/Timeval.h
MonsterAI.o: MonsterAI.cpp MonsterAI.h Creature.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
EffectManager.h Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Zone.h Tile.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Directive.h Slayer.h \
PlayerCreature.h InventorySlot.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h SkillInfo.h \
$(SKILLDIR)/SkillHandlerManager.h $(SKILLDIR)/SkillHandler.h Ousters.h \
$(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
$(SKILLDIR)/HitRoll.h $(SKILLDIR)/SkillUtil.h ZoneUtil.h GamePlayer.h \
$(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h MonsterManager.h MonsterCounter.h \
MikllizzLairManager.h MasterLairManager.h DynamicZoneScript.h \
DynamicZone.h DynamicZoneGroup.h VariableManager.h StringPool.h \
$(SERVDIR)/Profile.h $(COREDIR)/Gpackets/GCSay.h
Directive.o: Directive.cpp Directive.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(SERVDIR)/Mutex.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(COREDIR)/Assert.h $(SKILLDIR)/Skill.h
MonsterNameManager.o: MonsterNameManager.cpp MonsterNameManager.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h Monster.h Creature.h \
Object.h $(COREDIR)/Assert.h EffectManager.h Effect.h \
$(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h MonsterInfo.h MonsterSummonInfo.h \
MonsterInfoTypes.h Treasure.h Item.h PrecedenceTable.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h
MonsterCounter.o: MonsterCounter.cpp MonsterCounter.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
  $(COREDIR)/Assert.h
Item.o: Item.cpp Item.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h Effect.h $(SERVDIR)/Timeval.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h ItemInfoManager.h ItemInfo.h InfoClassManager.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h PlayerCreature.h \
Creature.h ObjectRegistry.h InventorySlot.h Garbage.h RankBonus.h \
ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h Store.h $(COREDIR)/StoreInfo.h \
$(COREDIR)/Cpackets/CGRequestStoreInfo.h ThirdEnchantInfo.h ItemUtil.h \
$(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
ItemInfo.o: ItemInfo.cpp ItemInfo.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h Item.h Object.h $(COREDIR)/Exception.h \
$(COREDIR)/StringStream.h $(COREDIR)/Assert.h Effect.h \
$(SERVDIR)/Timeval.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ItemUtil.h VolumeInfo.h OptionInfo.h
ItemUtil.o: ItemUtil.cpp $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(DBDIR)/Connection.h \
$(SERVDIR)/Mutex.h $(DBDIR)/Statement.h $(DBDIR)/Result.h ItemUtil.h \
Item.h Object.h $(COREDIR)/Assert.h Effect.h $(SERVDIR)/Timeval.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ItemInfo.h ItemInfoManager.h \
InfoClassManager.h OptionInfo.h $(COREDIR)/Player.h PlayerCreature.h \
Creature.h ObjectRegistry.h InventorySlot.h Garbage.h RankBonus.h \
ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Inventory.h \
VolumeInfo.h Slayer.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h $(COREDIR)/PCSlayerInfo.h \
$(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
Treasure.h UniqueItemManager.h RelicUtil.h GoodsInfoManager.h \
ItemGradeManager.h PacketUtil.h $(ITEMDIR)/AR.h ConcreteItem.h \
ItemPolicies.h ItemFactory.h $(ITEMDIR)/SR.h $(ITEMDIR)/SG.h \
$(ITEMDIR)/SMG.h $(ITEMDIR)/Magazine.h $(ITEMDIR)/SlayerPortalItem.h \
$(ITEMDIR)/Relic.h $(ITEMDIR)/OustersSummonItem.h \
$(ITEMDIR)/SubInventory.h $(ITEMDIR)/Belt.h $(ITEMDIR)/OustersArmsband.h \
ItemFactoryManager.h VariableManager.h \
$(COREDIR)/Gpackets/GCCreateItem.h Corpse.h MonsterCorpse.h \
$(CTFDIR)/FlagManager.h $(WARDIR)/Work.h $(WARDIR)/Scheduler.h \
$(WARDIR)/Schedule.h $(COREDIR)/Gpackets/GCFlagWarStatus.h \
$(COREDIR)/PetInfo.h $(COREDIR)/types/PetTypes.h PetExpInfo.h \
PetTypeInfo.h $(ITEMDIR)/PetItem.h $(SERVDIR)/DBExecuteManager.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
ItemFactoryManager.o: ItemFactoryManager.cpp Item.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
Effect.h $(SERVDIR)/Timeval.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ItemUtil.h ItemFactoryManager.h \
ItemFactory.h ItemInfoManager.h ItemInfo.h InfoClassManager.h \
$(ITEMDIR)/Motorcycle.h ItemLoader.h $(SERVDIR)/Mutex.h \
$(ITEMDIR)/Potion.h ConcreteItem.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h ItemPolicies.h $(ITEMDIR)/Water.h \
$(ITEMDIR)/HolyWater.h $(ITEMDIR)/Magazine.h $(ITEMDIR)/BombMaterial.h \
$(ITEMDIR)/ETC.h $(ITEMDIR)/Key.h $(ITEMDIR)/Ring.h \
$(ITEMDIR)/Bracelet.h $(ITEMDIR)/Necklace.h $(ITEMDIR)/Coat.h \
$(ITEMDIR)/Trouser.h $(ITEMDIR)/Shoes.h $(ITEMDIR)/Sword.h \
$(ITEMDIR)/Blade.h $(ITEMDIR)/Shield.h $(ITEMDIR)/Cross.h \
$(ITEMDIR)/Mace.h $(ITEMDIR)/Glove.h $(ITEMDIR)/Helm.h $(ITEMDIR)/SG.h \
$(ITEMDIR)/SMG.h $(ITEMDIR)/AR.h $(ITEMDIR)/SR.h $(ITEMDIR)/Bomb.h \
$(ITEMDIR)/Mine.h $(ITEMDIR)/Belt.h $(ITEMDIR)/LearningItem.h \
$(ITEMDIR)/Money.h Corpse.h $(ITEMDIR)/VampireRing.h \
$(ITEMDIR)/VampireBracelet.h $(ITEMDIR)/VampireNecklace.h \
$(ITEMDIR)/VampireCoat.h $(ITEMDIR)/Skull.h $(ITEMDIR)/Serum.h \
$(ITEMDIR)/VampireETC.h $(ITEMDIR)/SlayerPortalItem.h \
$(ITEMDIR)/VampirePortalItem.h $(ITEMDIR)/EventGiftBox.h \
$(ITEMDIR)/EventStar.h $(ITEMDIR)/VampireEarring.h $(ITEMDIR)/Relic.h \
$(ITEMDIR)/VampireWeapon.h $(ITEMDIR)/VampireAmulet.h \
$(ITEMDIR)/QuestItem.h $(ITEMDIR)/EventTree.h $(ITEMDIR)/EventETC.h \
$(ITEMDIR)/BloodBible.h $(ITEMDIR)/CastleSymbol.h \
$(ITEMDIR)/CoupleRing.h $(ITEMDIR)/CoupleRingBase.h \
$(ITEMDIR)/VampireCoupleRing.h $(ITEMDIR)/EventItem.h \
$(ITEMDIR)/DyePotion.h $(ITEMDIR)/ResurrectItem.h \
$(ITEMDIR)/MixingItem.h $(ITEMDIR)/OustersArmsband.h \
$(ITEMDIR)/OustersBoots.h $(ITEMDIR)/OustersChakram.h \
$(ITEMDIR)/OustersCirclet.h $(ITEMDIR)/OustersCoat.h \
$(ITEMDIR)/OustersPendent.h $(ITEMDIR)/OustersRing.h \
$(ITEMDIR)/OustersStone.h $(ITEMDIR)/OustersWristlet.h \
$(ITEMDIR)/Larva.h $(ITEMDIR)/Pupa.h $(ITEMDIR)/ComposMei.h \
$(ITEMDIR)/OustersSummonItem.h $(ITEMDIR)/EffectItem.h \
$(ITEMDIR)/CodeSheet.h $(ITEMDIR)/MoonCard.h $(ITEMDIR)/Sweeper.h \
$(ITEMDIR)/PetItem.h $(COREDIR)/PetInfo.h $(COREDIR)/types/PetTypes.h \
$(COREDIR)/VSDateTime.h $(ITEMDIR)/PetFood.h $(ITEMDIR)/PetEnchantItem.h \
$(ITEMDIR)/LuckyBag.h $(ITEMDIR)/SMSItem.h $(ITEMDIR)/CoreZap.h \
OptionInfo.h $(ITEMDIR)/TrapItem.h $(ITEMDIR)/WarItem.h \
$(ITEMDIR)/CarryingReceiver.h $(ITEMDIR)/ShoulderArmor.h \
$(ITEMDIR)/Dermis.h $(ITEMDIR)/Persona.h $(ITEMDIR)/Fascia.h \
$(ITEMDIR)/Mitten.h $(ITEMDIR)/SubInventory.h \
$(ITEMDIR)/CommonQuestItem.h $(ITEMDIR)/EtherealChain.h \
$(ITEMDIR)/OustersCoupleRing.h $(ITEMDIR)/CheckMoney.h \
$(ITEMDIR)/CueOfAdam.h $(ITEMDIR)/ContractOfBlood.h \
$(ITEMDIR)/SkillBook.h $(ITEMDIR)/VampireWingItem.h \
$(ITEMDIR)/OustersWingItem.h $(ITEMDIR)/SlayerTunningItem.h \
$(ITEMDIR)/VampireTunningItem.h $(ITEMDIR)/OustersTunningItem.h \
  $(ITEMDIR)/CallNPCCard.h
ItemInfoManager.o: ItemInfoManager.cpp $(COREDIR)/Exception.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/StringStream.h ItemInfoManager.h Item.h Object.h \
$(COREDIR)/Assert.h Effect.h $(SERVDIR)/Timeval.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ItemInfo.h InfoClassManager.h ItemUtil.h \
$(ITEMDIR)/AR.h ConcreteItem.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h ItemPolicies.h ItemFactory.h ItemLoader.h \
$(ITEMDIR)/Belt.h $(ITEMDIR)/Blade.h $(ITEMDIR)/Bomb.h \
$(ITEMDIR)/BombMaterial.h $(ITEMDIR)/Bracelet.h $(ITEMDIR)/Coat.h \
$(ITEMDIR)/Cross.h $(ITEMDIR)/ETC.h $(ITEMDIR)/Glove.h $(ITEMDIR)/Helm.h \
$(ITEMDIR)/HolyWater.h $(ITEMDIR)/Potion.h $(ITEMDIR)/Key.h \
$(ITEMDIR)/LearningItem.h $(ITEMDIR)/Magazine.h $(ITEMDIR)/Mine.h \
$(ITEMDIR)/Money.h $(ITEMDIR)/Motorcycle.h $(ITEMDIR)/Necklace.h \
$(ITEMDIR)/Ring.h $(ITEMDIR)/SG.h $(ITEMDIR)/SMG.h $(ITEMDIR)/Shield.h \
$(ITEMDIR)/Shoes.h $(ITEMDIR)/Sword.h $(ITEMDIR)/SR.h \
$(ITEMDIR)/Trouser.h $(ITEMDIR)/VampireBracelet.h \
$(ITEMDIR)/VampireNecklace.h $(ITEMDIR)/VampireRing.h $(ITEMDIR)/Water.h \
$(ITEMDIR)/VampireCoat.h $(ITEMDIR)/Skull.h $(ITEMDIR)/Mace.h \
$(ITEMDIR)/Serum.h $(ITEMDIR)/VampireETC.h $(ITEMDIR)/SlayerPortalItem.h \
$(ITEMDIR)/VampirePortalItem.h $(ITEMDIR)/EventGiftBox.h \
$(ITEMDIR)/EventStar.h $(ITEMDIR)/VampireEarring.h $(ITEMDIR)/Relic.h \
$(ITEMDIR)/VampireWeapon.h $(ITEMDIR)/VampireAmulet.h \
$(ITEMDIR)/QuestItem.h $(ITEMDIR)/EventTree.h $(ITEMDIR)/EventETC.h \
$(ITEMDIR)/BloodBible.h $(ITEMDIR)/CastleSymbol.h \
$(ITEMDIR)/CoupleRing.h $(ITEMDIR)/CoupleRingBase.h \
$(ITEMDIR)/VampireCoupleRing.h $(ITEMDIR)/OustersCoupleRing.h \
$(ITEMDIR)/EventItem.h $(ITEMDIR)/DyePotion.h $(ITEMDIR)/ResurrectItem.h \
$(ITEMDIR)/MixingItem.h $(ITEMDIR)/OustersArmsband.h \
$(ITEMDIR)/OustersBoots.h $(ITEMDIR)/OustersChakram.h \
$(ITEMDIR)/OustersCirclet.h $(ITEMDIR)/OustersCoat.h \
$(ITEMDIR)/OustersPendent.h $(ITEMDIR)/OustersRing.h \
$(ITEMDIR)/OustersStone.h $(ITEMDIR)/OustersWristlet.h \
$(ITEMDIR)/Larva.h $(ITEMDIR)/Pupa.h $(ITEMDIR)/ComposMei.h \
$(ITEMDIR)/OustersSummonItem.h $(ITEMDIR)/EffectItem.h \
$(ITEMDIR)/CodeSheet.h $(ITEMDIR)/MoonCard.h $(ITEMDIR)/Sweeper.h \
$(ITEMDIR)/PetItem.h $(COREDIR)/PetInfo.h $(COREDIR)/types/PetTypes.h \
$(COREDIR)/VSDateTime.h $(ITEMDIR)/PetFood.h $(ITEMDIR)/PetEnchantItem.h \
$(ITEMDIR)/LuckyBag.h $(ITEMDIR)/SMSItem.h $(ITEMDIR)/CoreZap.h \
OptionInfo.h $(ITEMDIR)/TrapItem.h $(ITEMDIR)/WarItem.h \
$(ITEMDIR)/CarryingReceiver.h $(ITEMDIR)/ShoulderArmor.h \
$(ITEMDIR)/Dermis.h $(ITEMDIR)/Persona.h $(ITEMDIR)/Fascia.h \
$(ITEMDIR)/Mitten.h $(ITEMDIR)/SubInventory.h \
$(ITEMDIR)/CommonQuestItem.h $(ITEMDIR)/EtherealChain.h \
$(ITEMDIR)/CheckMoney.h $(ITEMDIR)/CueOfAdam.h \
$(ITEMDIR)/ContractOfBlood.h $(ITEMDIR)/SkillBook.h \
$(ITEMDIR)/VampireWingItem.h $(ITEMDIR)/OustersWingItem.h \
$(ITEMDIR)/SlayerTunningItem.h $(ITEMDIR)/VampireTunningItem.h \
$(ITEMDIR)/OustersTunningItem.h $(ITEMDIR)/CallNPCCard.h \
  $(COREDIR)/Properties.h
ItemLoaderManager.o: ItemLoaderManager.cpp ItemLoaderManager.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h Item.h Object.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
Effect.h $(SERVDIR)/Timeval.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ItemLoader.h Slayer.h PlayerCreature.h \
Creature.h ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
$(ITEMDIR)/AR.h ConcreteItem.h ItemInfo.h ItemInfoManager.h \
InfoClassManager.h ItemPolicies.h ItemFactory.h $(ITEMDIR)/Belt.h \
$(ITEMDIR)/Blade.h $(ITEMDIR)/Bomb.h $(ITEMDIR)/BombMaterial.h \
$(ITEMDIR)/Bracelet.h $(ITEMDIR)/Coat.h $(ITEMDIR)/Cross.h \
$(ITEMDIR)/Mace.h $(ITEMDIR)/ETC.h $(ITEMDIR)/Glove.h $(ITEMDIR)/Helm.h \
$(ITEMDIR)/HolyWater.h $(ITEMDIR)/Key.h $(ITEMDIR)/LearningItem.h \
$(ITEMDIR)/Magazine.h $(ITEMDIR)/Mine.h $(ITEMDIR)/Money.h \
$(ITEMDIR)/Motorcycle.h $(ITEMDIR)/Necklace.h $(ITEMDIR)/Potion.h \
$(ITEMDIR)/Ring.h $(ITEMDIR)/SG.h $(ITEMDIR)/SMG.h $(ITEMDIR)/Shield.h \
$(ITEMDIR)/Shoes.h $(ITEMDIR)/Sword.h $(ITEMDIR)/SR.h \
$(ITEMDIR)/Trouser.h $(ITEMDIR)/VampireBracelet.h \
$(ITEMDIR)/VampireCoat.h $(ITEMDIR)/VampireNecklace.h \
$(ITEMDIR)/VampireRing.h $(ITEMDIR)/Water.h $(ITEMDIR)/Skull.h \
$(ITEMDIR)/Serum.h $(ITEMDIR)/VampireETC.h $(ITEMDIR)/SlayerPortalItem.h \
$(ITEMDIR)/VampirePortalItem.h $(ITEMDIR)/EventGiftBox.h \
$(ITEMDIR)/EventStar.h $(ITEMDIR)/VampireEarring.h $(ITEMDIR)/Relic.h \
$(ITEMDIR)/VampireWeapon.h $(ITEMDIR)/VampireAmulet.h \
$(ITEMDIR)/QuestItem.h $(ITEMDIR)/EventTree.h $(ITEMDIR)/EventETC.h \
$(ITEMDIR)/BloodBible.h $(ITEMDIR)/CastleSymbol.h \
$(ITEMDIR)/CoupleRing.h $(ITEMDIR)/CoupleRingBase.h \
$(ITEMDIR)/VampireCoupleRing.h $(ITEMDIR)/EventItem.h \
$(ITEMDIR)/DyePotion.h $(ITEMDIR)/ResurrectItem.h \
$(ITEMDIR)/MixingItem.h $(ITEMDIR)/OustersArmsband.h \
$(ITEMDIR)/OustersBoots.h $(ITEMDIR)/OustersChakram.h \
$(ITEMDIR)/OustersCirclet.h $(ITEMDIR)/OustersCoat.h \
$(ITEMDIR)/OustersPendent.h $(ITEMDIR)/OustersRing.h \
$(ITEMDIR)/OustersStone.h $(ITEMDIR)/OustersWristlet.h \
$(ITEMDIR)/Larva.h $(ITEMDIR)/Pupa.h $(ITEMDIR)/ComposMei.h \
$(ITEMDIR)/OustersSummonItem.h $(ITEMDIR)/EffectItem.h \
$(ITEMDIR)/CodeSheet.h $(ITEMDIR)/MoonCard.h $(ITEMDIR)/Sweeper.h \
$(ITEMDIR)/PetItem.h $(COREDIR)/PetInfo.h $(COREDIR)/types/PetTypes.h \
$(ITEMDIR)/PetFood.h $(ITEMDIR)/PetEnchantItem.h $(ITEMDIR)/LuckyBag.h \
$(ITEMDIR)/SMSItem.h $(ITEMDIR)/CoreZap.h $(ITEMDIR)/TrapItem.h \
$(ITEMDIR)/WarItem.h $(ITEMDIR)/CarryingReceiver.h \
$(ITEMDIR)/ShoulderArmor.h $(ITEMDIR)/Dermis.h $(ITEMDIR)/Persona.h \
$(ITEMDIR)/Fascia.h $(ITEMDIR)/Mitten.h $(ITEMDIR)/SubInventory.h \
$(ITEMDIR)/CommonQuestItem.h $(ITEMDIR)/EtherealChain.h \
$(ITEMDIR)/OustersCoupleRing.h $(ITEMDIR)/CheckMoney.h \
$(ITEMDIR)/CueOfAdam.h $(ITEMDIR)/ContractOfBlood.h \
$(ITEMDIR)/SkillBook.h $(ITEMDIR)/VampireWingItem.h \
$(ITEMDIR)/OustersWingItem.h $(ITEMDIR)/SlayerTunningItem.h \
$(ITEMDIR)/VampireTunningItem.h $(ITEMDIR)/OustersTunningItem.h \
  $(ITEMDIR)/CallNPCCard.h
SlayerCorpse.o: SlayerCorpse.cpp SlayerCorpse.h Item.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
Effect.h $(SERVDIR)/Timeval.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ItemFactory.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/PCInfo.h Corpse.h Creature.h Slayer.h PlayerCreature.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h
VampireCorpse.o: VampireCorpse.cpp VampireCorpse.h Item.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
Effect.h $(SERVDIR)/Timeval.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ItemFactory.h Corpse.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/PCInfo.h Creature.h Vampire.h \
PlayerCreature.h ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h \
Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Inventory.h \
VolumeInfo.h Zone.h Tile.h Obstacle.h Portal.h quest/TriggerManager.h \
quest/Trigger.h quest/Condition.h quest/PropertyBuffer.h Sector.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/VampireSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h CreatureUtil.h \
$(SKILLDIR)/VampireSkillSlot.h $(SKILLDIR)/Skill.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h
OustersCorpse.o: OustersCorpse.cpp OustersCorpse.h Item.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
Effect.h $(SERVDIR)/Timeval.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ItemFactory.h Corpse.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/PCInfo.h Creature.h Ousters.h \
PlayerCreature.h ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h \
Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Inventory.h \
VolumeInfo.h Zone.h Tile.h Obstacle.h Portal.h quest/TriggerManager.h \
quest/Trigger.h quest/Condition.h quest/PropertyBuffer.h Sector.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/OustersSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h CreatureUtil.h \
$(SKILLDIR)/OustersSkillSlot.h $(SKILLDIR)/Skill.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h
MonsterCorpse.o: MonsterCorpse.cpp MonsterCorpse.h Item.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
Effect.h $(SERVDIR)/Timeval.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ItemFactory.h Inventory.h VolumeInfo.h \
InventorySlot.h Corpse.h Monster.h Creature.h MonsterInfo.h \
MonsterSummonInfo.h MonsterInfoTypes.h Treasure.h PrecedenceTable.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(SERVDIR)/Mutex.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
Party.o: Party.cpp Party.h Creature.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h EffectManager.h Effect.h $(SERVDIR)/Timeval.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(SERVDIR)/Mutex.h \
$(COREDIR)/ModifyInfo.h CreatureUtil.h Item.h GamePlayer.h \
$(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
$(COREDIR)/VSDateTime.h $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h Zone.h \
Tile.h Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h ObjectRegistry.h \
PCManager.h CreatureManager.h Slayer.h PlayerCreature.h InventorySlot.h \
Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
$(COREDIR)/Gpackets/GCModifyInformation.h Vampire.h \
$(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
PCFinder.h NPC.h $(COUPLEDIR)/PartnerWaitingManager.h PacketUtil.h \
GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(SKILLDIR)/SkillUtil.h \
VariableManager.h $(SKILLDIR)/EffectRevealer.h EffectLoader.h \
$(SKILLDIR)/EffectDetectHidden.h $(SKILLDIR)/EffectDetectInvisibility.h \
$(SKILLDIR)/EffectExpansion.h $(SKILLDIR)/EffectActivation.h \
$(SKILLDIR)/EffectGnomesWhisper.h $(SKILLDIR)/EffectHolyArmor.h \
EffectCanEnterGDRLair.h $(COREDIR)/Gpackets/GCPartyLeave.h \
$(COREDIR)/Gpackets/GCPartyInvite.h $(COREDIR)/Gpackets/GCPartyJoined.h \
  $(COREDIR)/Gpackets/GCAddEffect.h \
  $(COREDIR)/Gpackets/GCStatusCurrentHP.h \
  $(COREDIR)/Gpackets/GCOtherModifyInfo.h \
  $(COREDIR)/Gpackets/GCOtherGuildName.h
Guild.o: Guild.cpp Guild.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Assert.h $(COREDIR)/Exception.h \
$(COREDIR)/StringStream.h $(SERVDIR)/Mutex.h $(COREDIR)/VSDateTime.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h $(COREDIR)/GuildInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/Gpackets/GCGuildMemberList.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/GuildMemberInfo.h \
  $(COREDIR)/Properties.h
GuildManager.o: GuildManager.cpp Guild.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Assert.h $(COREDIR)/Exception.h \
$(COREDIR)/StringStream.h $(SERVDIR)/Mutex.h $(COREDIR)/VSDateTime.h \
GuildManager.h $(SERVDIR)/Timeval.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(COREDIR)/Properties.h \
$(COREDIR)/Gpackets/GCWaitGuildList.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/GuildInfo.h $(COREDIR)/Gpackets/GCActiveGuildList.h
GuildUnion.o: GuildUnion.cpp GuildUnion.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Gpackets/GCUnionOfferList.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
$(SERVDIR)/Mutex.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(COREDIR)/Gpackets/GGCommand.h $(COREDIR)/DatagramPacket.h \
$(COREDIR)/Datagram.h LoginServerManager.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h $(COREDIR)/DatagramSocket.h GameServer.h \
$(COREDIR)/Properties.h $(SERVDIR)/GameServerInfoManager.h \
$(SERVDIR)/GameServerInfo.h PacketUtil.h $(COREDIR)/Player.h PCFinder.h \
Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h Effect.h \
$(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h NPC.h Zone.h Tile.h Item.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h ObjectRegistry.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h InventorySlot.h $(COUPLEDIR)/PartnerWaitingManager.h \
PlayerCreature.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Guild.h GuildManager.h \
VariableManager.h $(COREDIR)/Gpackets/GCModifyInformation.h
Effect.o: Effect.cpp Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h
EffectManager.o: EffectManager.cpp EffectManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
Effect.h Object.h $(COREDIR)/Assert.h $(SERVDIR)/Timeval.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h EffectEnemyErase.h EffectLoader.h \
Creature.h Zone.h Tile.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h ZoneUtil.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/Gpackets/GCAddEffect.h \
$(COREDIR)/PacketFactory.h $(SERVDIR)/Profile.h
EffectSchedule.o: EffectSchedule.cpp EffectSchedule.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(SERVDIR)/Mutex.h Effect.h Object.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Zone.h Tile.h Creature.h Item.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h ObjectRegistry.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h ZoneUtil.h \
$(COREDIR)/VSDateTime.h $(SKILLDIR)/EffectVampirePortal.h EffectLoader.h \
$(COREDIR)/Gpackets/GCAddVampirePortal.h $(COREDIR)/PacketFactory.h
EffectLoaderManager.o: EffectLoaderManager.cpp EffectLoaderManager.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h Effect.h Object.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h EffectLoader.h Slayer.h PlayerCreature.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
$(SKILLDIR)/EffectBloodDrain.h $(SKILLDIR)/EffectLight.h \
EffectAftermath.h EffectEnemyErase.h $(SKILLDIR)/EffectRestore.h \
EffectKillAftermath.h EffectMute.h EffectOnBridge.h \
$(SKILLDIR)/EffectGreenPoison.h $(SKILLDIR)/EffectYellowPoison.h \
$(SKILLDIR)/EffectDarkness.h $(SKILLDIR)/EffectAcidSwamp.h \
$(SKILLDIR)/EffectContinualBloodyWall.h $(SKILLDIR)/EffectIceField.h \
$(SKILLDIR)/EffectProminence.h EffectCanEnterGDRLair.h \
EffectBehemothForceScroll.h EffectSafeForceScroll.h \
EffectCarnelianForceScroll.h EffectGreyfellForceScroll.h \
EffectSoviusForceScroll.h EffectMirForceScroll.h \
EffectAccuraForceScroll.h EffectLifeForceScroll.h EffectHoodlumStigma.h \
$(SKILLDIR)/EffectBleeding.h EffectBonusExp.h EffectMysteryPotion.h \
EffectOdinForceScroll.h EffectTituosForceScroll.h EffectPetBonusExp.h \
EffectDSG.h EffectRankBonusExpRed.h EffectRankBonusExpBlue.h \
EffectExtremeForceScroll.h EffectBonusExpSecond.h \
EffectBonusExpAdvance.h EffectChaoticExp.h
EffectShutDown.o: EffectShutDown.cpp $(COREDIR)/Assert.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h EffectShutDown.h \
Effect.h Object.h $(SERVDIR)/Timeval.h \
$(COREDIR)/Gpackets/GCSystemMessage.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h Zone.h Tile.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h Item.h Obstacle.h \
Portal.h quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h Corpse.h ItemFactory.h EventShutdown.h Event.h \
ClientManager.h EventManager.h ZoneInfoManager.h ZoneInfo.h \
ZonePlayerManager.h $(SERVDIR)/PlayerManager.h $(COREDIR)/Player.h \
ZoneGroupManager.h ZoneGroup.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
$(COREDIR)/Datagram.h StringPool.h
EffectHPRecovery.o: EffectHPRecovery.cpp EffectHPRecovery.h Effect.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Zone.h Tile.h Creature.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h Slayer.h PlayerCreature.h InventorySlot.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
$(COREDIR)/Player.h $(COREDIR)/Gpackets/GCHPRecoveryEndToSelf.h \
  $(COREDIR)/Gpackets/GCHPRecoveryEndToOthers.h
EffectMPRecovery.o: EffectMPRecovery.cpp $(COREDIR)/Assert.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h EffectMPRecovery.h \
Effect.h Object.h $(SERVDIR)/Timeval.h \
$(COREDIR)/Gpackets/GCMPRecoveryEnd.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/EffectInfo.h Zone.h Tile.h Creature.h EffectManager.h Item.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
Slayer.h PlayerCreature.h InventorySlot.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
  $(COREDIR)/Player.h
EffectAlignmentRecovery.o: EffectAlignmentRecovery.cpp \
$(COREDIR)/Assert.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
EffectAlignmentRecovery.h Effect.h Object.h $(SERVDIR)/Timeval.h Zone.h \
Tile.h Creature.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h Slayer.h PlayerCreature.h InventorySlot.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
$(COREDIR)/Player.h AlignmentManager.h \
  $(COREDIR)/Gpackets/GCOtherModifyInfo.h
EffectEnemyErase.o: EffectEnemyErase.cpp EffectEnemyErase.h Effect.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h EffectLoader.h Creature.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Slayer.h PlayerCreature.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h $(COREDIR)/Player.h \
  $(COREDIR)/Gpackets/GCRemoveInjuriousCreature.h \
$(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
EffectDecayCorpse.o: EffectDecayCorpse.cpp $(COREDIR)/Assert.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h EffectDecayCorpse.h \
Effect.h Object.h $(SERVDIR)/Timeval.h \
$(COREDIR)/Gpackets/GCDeleteObject.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h Tile.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h Item.h Obstacle.h \
Portal.h quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Zone.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
Corpse.h ItemFactory.h SlayerCorpse.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/PCInfo.h VampireCorpse.h $(COREDIR)/PCVampireInfo3.h \
MonsterCorpse.h Inventory.h VolumeInfo.h InventorySlot.h ZoneUtil.h \
  $(COREDIR)/VSDateTime.h
EffectDecayItem.o: EffectDecayItem.cpp $(COREDIR)/Assert.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h EffectDecayItem.h \
Effect.h Object.h $(SERVDIR)/Timeval.h \
$(COREDIR)/Gpackets/GCDeleteObject.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h Tile.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h Item.h Obstacle.h \
Portal.h quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Zone.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(ITEMDIR)/Money.h ItemInfo.h InfoClassManager.h ItemFactory.h \
ItemLoader.h ItemUtil.h ZoneUtil.h $(COREDIR)/VSDateTime.h \
UniqueItemManager.h VariableManager.h
EffectAftermath.o: EffectAftermath.cpp EffectAftermath.h Effect.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h EffectLoader.h Creature.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Slayer.h PlayerCreature.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
GamePlayer.h $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(SERVDIR)/DBExecuteManager.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
EffectComa.o: EffectComa.cpp EffectComa.h Effect.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h EffectLoader.h Slayer.h PlayerCreature.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
GamePlayer.h $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h ZoneGroupManager.h ZoneGroup.h \
$(COREDIR)/GameTime.h $(COREDIR)/Gpackets/GMServerInfo.h \
$(COREDIR)/DatagramPacket.h $(COREDIR)/Datagram.h ZoneInfo.h \
ZoneInfoManager.h ZonePlayerManager.h $(SERVDIR)/PlayerManager.h \
IncomingPlayerManager.h $(COREDIR)/ServerSocket.h \
$(COREDIR)/DatagramSocket.h ConnectionInfoManager.h ConnectionInfo.h \
EventResurrect.h ResurrectLocationManager.h ItemUtil.h \
AlignmentManager.h ItemFactoryManager.h ItemFactory.h \
$(SKILLDIR)/EffectRequestResurrect.h SlayerCorpse.h Corpse.h \
VampireCorpse.h $(SERVDIR)/LogClient.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h $(COREDIR)/Gpackets/GCCreatureDied.h \
  $(COREDIR)/Gpackets/GCGetOffMotorCycle.h
EffectPrecedence.o: EffectPrecedence.cpp EffectPrecedence.h Effect.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Zone.h Tile.h Creature.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h
EffectTransportItem.o: EffectTransportItem.cpp $(COREDIR)/Assert.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h EffectTransportItem.h \
Effect.h Object.h $(SERVDIR)/Timeval.h \
$(COREDIR)/Gpackets/GCDeleteObject.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h Tile.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h Item.h Obstacle.h \
Portal.h quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Zone.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
ZoneUtil.h $(COREDIR)/VSDateTime.h
EffectAddItem.o: EffectAddItem.cpp $(COREDIR)/Assert.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h EffectAddItem.h \
Effect.h Object.h $(SERVDIR)/Timeval.h \
$(COREDIR)/Gpackets/GCDeleteObject.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h Tile.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h Item.h Obstacle.h \
Portal.h quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Zone.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
ZoneUtil.h $(COREDIR)/VSDateTime.h ParkingCenter.h \
$(ITEMDIR)/Motorcycle.h ItemInfo.h InfoClassManager.h ItemFactory.h \
  ItemLoader.h
EffectRelicTable.o: EffectRelicTable.cpp EffectRelicTable.h Effect.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Item.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Slayer.h PlayerCreature.h Creature.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h $(COREDIR)/Player.h \
  $(COREDIR)/Gpackets/GCStatusCurrentHP.h \
  $(COREDIR)/Gpackets/GCRemoveEffect.h
EffectHasSlayerRelic.o: EffectHasSlayerRelic.cpp EffectHasSlayerRelic.h \
EffectHasRelic.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h Creature.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Slayer.h PlayerCreature.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h MonsterCorpse.h ItemFactory.h Corpse.h \
$(COREDIR)/Player.h ZoneInfoManager.h ZoneInfo.h ZoneGroupManager.h \
ZoneGroup.h $(COREDIR)/GameTime.h $(COREDIR)/Gpackets/GMServerInfo.h \
$(COREDIR)/DatagramPacket.h $(COREDIR)/Datagram.h StringPool.h \
  $(COREDIR)/Gpackets/GCStatusCurrentHP.h \
$(COREDIR)/Gpackets/GCAddEffect.h $(COREDIR)/Gpackets/GCRemoveEffect.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
EffectHasVampireRelic.o: EffectHasVampireRelic.cpp \
EffectHasVampireRelic.h EffectHasRelic.h Effect.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h ZoneInfoManager.h Zone.h Tile.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h ZoneInfo.h \
ZoneGroupManager.h ZoneGroup.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
$(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h Slayer.h \
PlayerCreature.h InventorySlot.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h MonsterCorpse.h ItemFactory.h Corpse.h \
$(COREDIR)/Player.h StringPool.h $(COREDIR)/Gpackets/GCStatusCurrentHP.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(COREDIR)/Gpackets/GCAddEffect.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
EffectIncreaseAttr.o: EffectIncreaseAttr.cpp EffectIncreaseAttr.h \
Effect.h Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Slayer.h PlayerCreature.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h $(COREDIR)/Player.h PacketUtil.h \
  $(COREDIR)/Gpackets/GCStatusCurrentHP.h \
  $(COREDIR)/Gpackets/GCRemoveEffect.h \
  $(COREDIR)/Gpackets/GCOtherModifyInfo.h
EffectDeleteItem.o: EffectDeleteItem.cpp $(COREDIR)/Assert.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h EffectDeleteItem.h \
Effect.h Object.h $(SERVDIR)/Timeval.h \
$(COREDIR)/Gpackets/GCDeleteObject.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h Tile.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h Item.h Obstacle.h \
Portal.h quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Zone.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
ZoneUtil.h $(COREDIR)/VSDateTime.h
EffectSlayerRelic.o: EffectSlayerRelic.cpp EffectSlayerRelic.h Effect.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Creature.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Slayer.h PlayerCreature.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h MonsterCorpse.h ItemFactory.h Corpse.h \
$(COREDIR)/Player.h ZoneGroupManager.h ZoneGroup.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
$(COREDIR)/Datagram.h StringPool.h \
  $(COREDIR)/Gpackets/GCStatusCurrentHP.h \
$(COREDIR)/Gpackets/GCAddEffect.h $(COREDIR)/Gpackets/GCRemoveEffect.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
EffectVampireRelic.o: EffectVampireRelic.cpp EffectVampireRelic.h \
Effect.h Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h ZoneGroupManager.h ZoneGroup.h Zone.h Tile.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
$(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h Slayer.h \
PlayerCreature.h InventorySlot.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h MonsterCorpse.h ItemFactory.h Corpse.h \
$(COREDIR)/Player.h StringPool.h $(COREDIR)/Gpackets/GCStatusCurrentHP.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(COREDIR)/Gpackets/GCAddEffect.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
EffectRelicPosition.o: EffectRelicPosition.cpp EffectRelicPosition.h \
Effect.h Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h ZoneUtil.h Creature.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/VSDateTime.h \
ZoneGroupManager.h ZoneGroup.h Zone.h Tile.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
$(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h HolyLandManager.h \
ShrineInfoManager.h $(ITEMDIR)/Relic.h ItemInfo.h InfoClassManager.h \
ItemFactory.h ItemLoader.h ZoneInfoManager.h ZoneInfo.h \
CastleInfoManager.h PlayerCreature.h InventorySlot.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h $(COREDIR)/Gpackets/GCSystemMessage.h \
$(COREDIR)/Gpackets/GCBloodBibleStatus.h StringPool.h
EffectRelicLock.o: EffectRelicLock.cpp EffectRelicLock.h Effect.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Creature.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Slayer.h PlayerCreature.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h MonsterCorpse.h ItemFactory.h Corpse.h \
$(COREDIR)/Player.h ZoneGroupManager.h ZoneGroup.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
$(COREDIR)/Datagram.h $(COREDIR)/Gpackets/GCStatusCurrentHP.h \
$(COREDIR)/Gpackets/GCAddEffect.h $(COREDIR)/Gpackets/GCRemoveEffect.h
EffectMasterLairPass.o: EffectMasterLairPass.cpp EffectMasterLairPass.h \
Effect.h Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Creature.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/Player.h ZoneInfoManager.h \
Zone.h Tile.h Item.h Obstacle.h Portal.h quest/TriggerManager.h \
quest/Trigger.h quest/Condition.h quest/PropertyBuffer.h Sector.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h ZoneInfo.h \
$(COREDIR)/Gpackets/GCSystemMessage.h $(COREDIR)/PacketFactory.h \
  $(COREDIR)/Gpackets/GCRemoveEffect.h
EffectContinualGroundAttack.o: EffectContinualGroundAttack.cpp \
$(COREDIR)/Assert.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
EffectContinualGroundAttack.h Effect.h Object.h $(SERVDIR)/Timeval.h \
$(SKILLDIR)/EffectGroundAttack.h EffectLoader.h \
$(SKILLDIR)/EffectMeteorStrike.h MonsterManager.h CreatureManager.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(SERVDIR)/Mutex.h MonsterCounter.h \
Item.h PCManager.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h Party.h \
$(COREDIR)/ModifyInfo.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h ZoneUtil.h $(COREDIR)/VSDateTime.h \
$(SKILLDIR)/SkillUtil.h Slayer.h PlayerCreature.h InventorySlot.h \
Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
  $(COREDIR)/Gpackets/GCAddEffectToTile.h
EffectGhost.o: EffectGhost.cpp EffectGhost.h Effect.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Creature.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/Player.h ZoneInfoManager.h \
Zone.h Tile.h Item.h Obstacle.h Portal.h quest/TriggerManager.h \
quest/Trigger.h quest/Condition.h quest/PropertyBuffer.h Sector.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h ZoneInfo.h \
$(COREDIR)/Gpackets/GCSystemMessage.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h Viewable.h ViewEffect.h
EffectTransportCreature.o: EffectTransportCreature.cpp \
$(COREDIR)/Assert.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
EffectTransportCreature.h Effect.h Object.h $(SERVDIR)/Timeval.h \
$(COREDIR)/Gpackets/GCSystemMessage.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
VariableManager.h Zone.h Tile.h Creature.h EffectManager.h \
$(COREDIR)/EffectInfo.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h ZoneUtil.h \
$(COREDIR)/VSDateTime.h Slayer.h PlayerCreature.h InventorySlot.h \
Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
$(COREDIR)/Player.h StringPool.h
EffectGrandMasterSlayer.o: EffectGrandMasterSlayer.cpp \
EffectGrandMasterSlayer.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h Creature.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Slayer.h PlayerCreature.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
$(COREDIR)/Player.h $(COREDIR)/Gpackets/GCAddEffect.h \
  $(COREDIR)/Gpackets/GCRemoveEffect.h
EffectGrandMasterVampire.o: EffectGrandMasterVampire.cpp \
EffectGrandMasterVampire.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h Creature.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/Player.h Zone.h Tile.h Item.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
Vampire.h PlayerCreature.h InventorySlot.h Garbage.h RankBonus.h \
ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCVampireInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCVampireInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/VampireSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h CreatureUtil.h \
$(SKILLDIR)/VampireSkillSlot.h $(SKILLDIR)/Skill.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
$(COREDIR)/Gpackets/GCAddEffect.h $(COREDIR)/Gpackets/GCRemoveEffect.h
EffectKillAftermath.o: EffectKillAftermath.cpp EffectKillAftermath.h \
Effect.h Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h EffectLoader.h Creature.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Slayer.h PlayerCreature.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
GamePlayer.h $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(SERVDIR)/DBExecuteManager.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
EffectHasBloodBible.o: EffectHasBloodBible.cpp EffectHasBloodBible.h \
EffectHasRelic.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h Creature.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Slayer.h PlayerCreature.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
$(ITEMDIR)/BloodBible.h ItemInfo.h InfoClassManager.h ItemFactory.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h MonsterCorpse.h Corpse.h \
$(COREDIR)/Player.h $(WARDIR)/WarSystem.h $(WARDIR)/Scheduler.h \
$(WARDIR)/Work.h $(WARDIR)/Schedule.h $(COREDIR)/Gpackets/GCWarList.h \
$(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
$(COREDIR)/RaceWarInfo.h CastleInfoManager.h ZoneInfoManager.h \
ZoneInfo.h HolyLandManager.h ZoneGroupManager.h ZoneGroup.h \
$(COREDIR)/GameTime.h $(COREDIR)/Gpackets/GMServerInfo.h \
$(COREDIR)/DatagramPacket.h $(COREDIR)/Datagram.h ShrineInfoManager.h \
  $(COREDIR)/Gpackets/GCStatusCurrentHP.h \
$(COREDIR)/Gpackets/GCAddEffect.h $(COREDIR)/Gpackets/GCRemoveEffect.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Gpackets/GCBloodBibleStatus.h
EffectShrineHoly.o: EffectShrineHoly.cpp EffectShrineHoly.h Effect.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Creature.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Slayer.h PlayerCreature.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h MonsterCorpse.h ItemFactory.h Corpse.h \
$(COREDIR)/Player.h ZoneGroupManager.h ZoneGroup.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
$(COREDIR)/Datagram.h $(COREDIR)/Gpackets/GCStatusCurrentHP.h \
$(COREDIR)/Gpackets/GCAddEffect.h $(COREDIR)/Gpackets/GCRemoveEffect.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
EffectShrineGuard.o: EffectShrineGuard.cpp EffectShrineGuard.h Effect.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Creature.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Slayer.h PlayerCreature.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h MonsterCorpse.h ItemFactory.h Corpse.h \
$(COREDIR)/Player.h ZoneGroupManager.h ZoneGroup.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
$(COREDIR)/Datagram.h $(COREDIR)/Gpackets/GCStatusCurrentHP.h \
$(COREDIR)/Gpackets/GCAddEffect.h $(COREDIR)/Gpackets/GCRemoveEffect.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
EffectShrineShield.o: EffectShrineShield.cpp EffectShrineShield.h \
Effect.h Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Creature.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Slayer.h PlayerCreature.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h MonsterCorpse.h ItemFactory.h Corpse.h \
$(COREDIR)/Player.h ZoneGroupManager.h ZoneGroup.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
$(COREDIR)/Datagram.h $(COREDIR)/Gpackets/GCStatusCurrentHP.h \
$(COREDIR)/Gpackets/GCAddEffect.h $(COREDIR)/Gpackets/GCRemoveEffect.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
EffectTransportItemToCorpse.o: EffectTransportItemToCorpse.cpp \
$(COREDIR)/Assert.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
EffectTransportItemToCorpse.h Effect.h Object.h $(SERVDIR)/Timeval.h \
$(COREDIR)/Gpackets/GCDeleteObject.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h Tile.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h Item.h Obstacle.h \
Portal.h quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Zone.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
Corpse.h ItemFactory.h ZoneUtil.h $(COREDIR)/VSDateTime.h
EffectAddItemToCorpse.o: EffectAddItemToCorpse.cpp $(COREDIR)/Assert.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h EffectAddItemToCorpse.h \
Effect.h Object.h $(SERVDIR)/Timeval.h \
$(COREDIR)/Gpackets/GCDeleteObject.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h Tile.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h Item.h Obstacle.h \
Portal.h quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Zone.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
Corpse.h ItemFactory.h ZoneUtil.h $(COREDIR)/VSDateTime.h \
ParkingCenter.h $(ITEMDIR)/Motorcycle.h ItemInfo.h InfoClassManager.h \
  ItemLoader.h
EffectHasRelic.o: EffectHasRelic.cpp EffectHasRelic.h Effect.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Creature.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Slayer.h PlayerCreature.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
$(ITEMDIR)/Relic.h ItemInfo.h InfoClassManager.h ItemFactory.h Vampire.h \
$(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h MonsterCorpse.h Corpse.h \
$(COREDIR)/Player.h $(WARDIR)/WarSystem.h $(WARDIR)/Scheduler.h \
$(WARDIR)/Work.h $(WARDIR)/Schedule.h $(COREDIR)/Gpackets/GCWarList.h \
$(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
$(COREDIR)/RaceWarInfo.h ZoneInfoManager.h ZoneInfo.h ZoneGroupManager.h \
ZoneGroup.h $(COREDIR)/GameTime.h $(COREDIR)/Gpackets/GMServerInfo.h \
$(COREDIR)/DatagramPacket.h $(COREDIR)/Datagram.h \
  $(COREDIR)/Gpackets/GCStatusCurrentHP.h \
$(COREDIR)/Gpackets/GCAddEffect.h $(COREDIR)/Gpackets/GCRemoveEffect.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
EffectHasCastleSymbol.o: EffectHasCastleSymbol.cpp \
EffectHasCastleSymbol.h EffectHasRelic.h Effect.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h ZoneUtil.h Creature.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/VSDateTime.h Slayer.h \
PlayerCreature.h ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h \
Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
$(ITEMDIR)/CastleSymbol.h ItemInfo.h InfoClassManager.h ItemFactory.h \
CastleInfoManager.h Vampire.h $(COREDIR)/PCVampireInfo.h \
$(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCVampireInfo3.h \
$(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
$(SKILLDIR)/VampireSkillSlot.h Monster.h MonsterInfo.h \
MonsterSummonInfo.h MonsterInfoTypes.h Treasure.h PrecedenceTable.h \
MonsterCorpse.h Corpse.h $(COREDIR)/Player.h $(WARDIR)/WarSystem.h \
$(WARDIR)/Scheduler.h $(WARDIR)/Work.h $(WARDIR)/Schedule.h \
$(COREDIR)/Gpackets/GCWarList.h $(COREDIR)/GuildWarInfo.h \
$(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h $(COREDIR)/RaceWarInfo.h \
ZoneInfoManager.h ZoneInfo.h ZoneGroupManager.h ZoneGroup.h \
$(COREDIR)/GameTime.h $(COREDIR)/Gpackets/GMServerInfo.h \
$(COREDIR)/DatagramPacket.h $(COREDIR)/Datagram.h GuildManager.h \
StringPool.h $(COREDIR)/Gpackets/GCStatusCurrentHP.h \
$(COREDIR)/Gpackets/GCAddEffect.h $(COREDIR)/Gpackets/GCRemoveEffect.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
EffectLoveChain.o: EffectLoveChain.cpp EffectLoveChain.h Effect.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Slayer.h PlayerCreature.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
GamePlayer.h $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h PCFinder.h NPC.h \
$(COUPLEDIR)/PartnerWaitingManager.h ZoneUtil.h ZoneInfoManager.h \
ZoneInfo.h $(COREDIR)/Gpackets/GCRemoveEffect.h \
$(COREDIR)/Gpackets/GCUseOK.h $(COREDIR)/Gpackets/GCCannotUse.h \
GDRLairManager.h FiniteStateMachine.h GDRLairAbstractStates.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h Store.h \
$(COREDIR)/StoreInfo.h GQuestManager.h GQuestInventory.h \
  $(COREDIR)/Gpackets/GCGQuestInventory.h
EffectPKZoneRegen.o: EffectPKZoneRegen.cpp EffectPKZoneRegen.h Effect.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Zone.h Tile.h Creature.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Slayer.h \
PlayerCreature.h InventorySlot.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h $(COREDIR)/Player.h ZoneUtil.h \
$(SKILLDIR)/EffectBloodDrain.h EffectLoader.h \
  $(COREDIR)/Gpackets/GCStatusCurrentHP.h \
  $(COREDIR)/Gpackets/GCRemoveEffect.h
EffectPKZoneResurrection.o: EffectPKZoneResurrection.cpp \
EffectPKZoneResurrection.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h Zone.h Tile.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h PlayerCreature.h \
InventorySlot.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(COREDIR)/Player.h \
  $(COREDIR)/Gpackets/GCAddEffect.h
EffectGrandMasterOusters.o: EffectGrandMasterOusters.cpp \
EffectGrandMasterOusters.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h Creature.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/Player.h Zone.h Tile.h Item.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
Ousters.h PlayerCreature.h InventorySlot.h Garbage.h RankBonus.h \
ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCOustersInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/OustersSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h CreatureUtil.h \
$(SKILLDIR)/OustersSkillSlot.h $(SKILLDIR)/Skill.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
$(COREDIR)/Gpackets/GCAddEffect.h $(COREDIR)/Gpackets/GCRemoveEffect.h
EffectTranslation.o: EffectTranslation.cpp EffectTranslation.h Effect.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Creature.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/Player.h Zone.h Tile.h Item.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(COREDIR)/PacketFactory.h
EffectLoud.o: EffectLoud.cpp EffectLoud.h Effect.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Ousters.h PlayerCreature.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Inventory.h \
VolumeInfo.h Zone.h Tile.h Obstacle.h Portal.h quest/TriggerManager.h \
quest/Trigger.h quest/Condition.h quest/PropertyBuffer.h Sector.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/PCOustersInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/OustersSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h CreatureUtil.h \
$(SKILLDIR)/OustersSkillSlot.h $(SKILLDIR)/Skill.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(COREDIR)/Gpackets/GCRemoveEffect.h
EffectMute.o: EffectMute.cpp EffectMute.h Effect.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h EffectLoader.h Creature.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h GamePlayer.h $(COREDIR)/Player.h \
$(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
$(SERVDIR)/Mutex.h $(COREDIR)/PlayerStatus.h EventManager.h Event.h \
$(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h \
Item.h $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCAddEffect.h $(COREDIR)/Gpackets/GCRemoveEffect.h \
$(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h
SimpleCreatureEffect.o: SimpleCreatureEffect.cpp SimpleCreatureEffect.h \
Effect.h Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Ousters.h PlayerCreature.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Inventory.h \
VolumeInfo.h Zone.h Tile.h Obstacle.h Portal.h quest/TriggerManager.h \
quest/Trigger.h quest/Condition.h quest/PropertyBuffer.h Sector.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/PCOustersInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/OustersSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h CreatureUtil.h \
$(SKILLDIR)/OustersSkillSlot.h $(SKILLDIR)/Skill.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
$(COREDIR)/Player.h $(COREDIR)/Gpackets/GCRemoveEffect.h
EffectRefiniumTicket.o: EffectRefiniumTicket.cpp EffectRefiniumTicket.h \
Effect.h Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Ousters.h PlayerCreature.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Inventory.h \
VolumeInfo.h Zone.h Tile.h Obstacle.h Portal.h quest/TriggerManager.h \
quest/Trigger.h quest/Condition.h quest/PropertyBuffer.h Sector.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/PCOustersInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/OustersSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h CreatureUtil.h \
$(SKILLDIR)/OustersSkillSlot.h $(SKILLDIR)/Skill.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(COREDIR)/Gpackets/GCRemoveEffect.h
EffectFlagInsert.o: EffectFlagInsert.cpp EffectFlagInsert.h Effect.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Creature.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Slayer.h PlayerCreature.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h MonsterCorpse.h ItemFactory.h Corpse.h \
$(COREDIR)/Player.h ZoneGroupManager.h ZoneGroup.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
$(COREDIR)/Datagram.h StringPool.h \
  $(COREDIR)/Gpackets/GCStatusCurrentHP.h \
$(COREDIR)/Gpackets/GCAddEffect.h $(COREDIR)/Gpackets/GCRemoveEffect.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
EffectHasSweeper.o: EffectHasSweeper.cpp EffectHasSweeper.h Effect.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Creature.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Zone.h Tile.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(COREDIR)/PacketFactory.h
EffectKeepSweeper.o: EffectKeepSweeper.cpp EffectKeepSweeper.h Effect.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Item.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/Gpackets/GCRemoveEffect.h \
  $(COREDIR)/PacketFactory.h
EffectRegenZone.o: EffectRegenZone.cpp EffectRegenZone.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h Effect.h Object.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h RegenZoneManager.h \
MonsterCorpse.h Item.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ItemFactory.h Inventory.h VolumeInfo.h \
InventorySlot.h Corpse.h $(SERVDIR)/Mutex.h Zone.h Tile.h Creature.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h ObjectRegistry.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(COREDIR)/PacketFactory.h
EffectTryingPosition.o: EffectTryingPosition.cpp EffectTryingPosition.h \
Effect.h Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Zone.h Tile.h Creature.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h MonsterCorpse.h \
ItemFactory.h Inventory.h VolumeInfo.h InventorySlot.h Corpse.h \
PlayerCreature.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Slayer.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
$(WARDIR)/WarSystem.h $(WARDIR)/Scheduler.h $(WARDIR)/Work.h \
$(WARDIR)/Schedule.h $(COREDIR)/Gpackets/GCWarList.h \
$(COREDIR)/GuildWarInfo.h $(COREDIR)/WarInfo.h $(COREDIR)/ValueList.h \
$(COREDIR)/RaceWarInfo.h RegenZoneManager.h ZoneUtil.h \
EffectTryRegenZone.h EffectTrying.h $(SKILLDIR)/EffectFadeOut.h \
EffectLoader.h $(COREDIR)/Gpackets/GCDeleteEffectFromTile.h \
  $(COREDIR)/Gpackets/GCAddEffect.h \
  $(COREDIR)/Gpackets/GCAddEffectToTile.h \
  $(COREDIR)/Gpackets/GCRemoveEffect.h
EffectTrying.o: EffectTrying.cpp EffectTrying.h Effect.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Creature.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Zone.h Tile.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCDeleteEffectFromTile.h $(COREDIR)/PacketFactory.h \
  $(COREDIR)/Gpackets/GCRemoveEffect.h
EffectTryRegenZone.o: EffectTryRegenZone.cpp EffectTryRegenZone.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h Effect.h Object.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h RegenZoneManager.h \
MonsterCorpse.h Item.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ItemFactory.h Inventory.h VolumeInfo.h \
InventorySlot.h Corpse.h $(SERVDIR)/Mutex.h Creature.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h ObjectRegistry.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(COREDIR)/PacketFactory.h \
  $(COREDIR)/Gpackets/GCAddEffect.h
EffectOnBridge.o: EffectOnBridge.cpp $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(DBDIR)/Connection.h $(SERVDIR)/Mutex.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h EffectOnBridge.h Effect.h Object.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h EffectLoader.h Zone.h Tile.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Slayer.h \
PlayerCreature.h InventorySlot.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(SKILLDIR)/Skill.h \
$(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
$(COREDIR)/Gpackets/GCModifyInformation.h Vampire.h \
$(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h $(COREDIR)/Player.h ZoneUtil.h \
$(SKILLDIR)/EffectBloodDrain.h $(COREDIR)/Gpackets/GCStatusCurrentHP.h \
  $(COREDIR)/Gpackets/GCRemoveEffect.h
EffectHasPet.o: EffectHasPet.cpp EffectHasPet.h Effect.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h PlayerCreature.h Creature.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h GamePlayer.h \
$(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/PetInfo.h \
$(COREDIR)/types/PetTypes.h CreatureUtil.h PetExpInfo.h PetUtil.h \
$(COREDIR)/Gpackets/GCAddEffect.h $(COREDIR)/Gpackets/GCRemoveEffect.h \
$(COREDIR)/Gpackets/GCModifyInformation.h $(ITEMDIR)/PetItem.h \
ItemInfo.h InfoClassManager.h ItemFactory.h ItemLoader.h \
VariableManager.h EffectPetBonusExp.h EffectLoader.h
EffectPacketSend.o: EffectPacketSend.cpp EffectPacketSend.h Effect.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Zone.h Tile.h Creature.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h $(COREDIR)/Player.h
EffectDarknessForbidden.o: EffectDarknessForbidden.cpp \
EffectDarknessForbidden.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h EffectLoader.h Tile.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Zone.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCModifyInformation.h $(COREDIR)/PacketFactory.h \
  $(COREDIR)/Gpackets/GCStatusCurrentHP.h
EffectCastingTrap.o: EffectCastingTrap.cpp EffectCastingTrap.h Effect.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h EffectWithWarning.h ZoneUtil.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/VSDateTime.h Tile.h Item.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Zone.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
  $(COREDIR)/EncryptUtility.h
EffectWithWarning.o: EffectWithWarning.cpp EffectWithWarning.h Effect.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h $(COREDIR)/Gpackets/GCAddEffectToTile.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
  $(COREDIR)/Gpackets/GCDeleteEffectFromTile.h \
$(COREDIR)/Gpackets/GCModifyInformation.h $(COREDIR)/ModifyInfo.h \
$(COREDIR)/Gpackets/GCStatusCurrentHP.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Gpackets/GCAddEffect.h $(SKILLDIR)/EffectIceFieldToCreature.h \
EffectLoader.h Zone.h Tile.h Creature.h EffectManager.h Item.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h Party.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Slayer.h \
PlayerCreature.h InventorySlot.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h Vampire.h $(COREDIR)/PCVampireInfo.h \
$(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCVampireInfo3.h \
$(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
$(SKILLDIR)/VampireSkillSlot.h Ousters.h $(COREDIR)/PCOustersInfo.h \
$(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
$(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
$(SKILLDIR)/OustersSkillSlot.h ZoneUtil.h
EffectKickOut.o: EffectKickOut.cpp EffectKickOut.h Effect.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Zone.h Tile.h Creature.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCSystemMessage.h $(COREDIR)/PacketFactory.h \
  StringPool.h
EffectGDRLairClose.o: EffectGDRLairClose.cpp EffectGDRLairClose.h \
Effect.h Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h GDRLairManager.h FiniteStateMachine.h \
$(COREDIR)/VSDateTime.h GDRLairAbstractStates.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h $(COREDIR)/Gpackets/GCSystemMessage.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
ZoneGroupManager.h ZoneGroup.h Zone.h Tile.h Creature.h EffectManager.h \
$(COREDIR)/EffectInfo.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
$(COREDIR)/Datagram.h StringPool.h
EffectEventQuestReset.o: EffectEventQuestReset.cpp \
EffectEventQuestReset.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(COREDIR)/Player.h \
GQuestManager.h GQuestInventory.h \
  $(COREDIR)/Gpackets/GCGQuestInventory.h \
$(COREDIR)/Gpackets/GCSystemMessage.h StringPool.h
EffectShareHP.o: EffectShareHP.cpp EffectShareHP.h Effect.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Slayer.h PlayerCreature.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h $(COREDIR)/Player.h $(SKILLDIR)/SkillUtil.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
  $(COREDIR)/Gpackets/GCStatusCurrentHP.h
EffectCanEnterGDRLair.o: EffectCanEnterGDRLair.cpp \
EffectCanEnterGDRLair.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h EffectLoader.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Slayer.h PlayerCreature.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h $(COREDIR)/Player.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(SERVDIR)/DBExecuteManager.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
  $(SERVDIR)/CondVarAttr.h
EffectAutoTurret.o: EffectAutoTurret.cpp EffectAutoTurret.h Effect.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h EffectLoader.h Zone.h Tile.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h ZoneUtil.h \
  $(COREDIR)/VSDateTime.h
EffectTurretLaser.o: EffectTurretLaser.cpp EffectTurretLaser.h Effect.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h EffectLoader.h Zone.h Tile.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h ZoneUtil.h \
$(COREDIR)/VSDateTime.h $(SKILLDIR)/SkillUtil.h Slayer.h \
PlayerCreature.h InventorySlot.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
$(COREDIR)/Player.h $(COREDIR)/Gpackets/GCAddEffectToTile.h
EffectKillTimer.o: EffectKillTimer.cpp EffectKillTimer.h Effect.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h EffectLoader.h Creature.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Monster.h MonsterInfo.h \
MonsterSummonInfo.h MonsterInfoTypes.h Treasure.h Item.h \
PrecedenceTable.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h
EffectDragonEye.o: EffectDragonEye.cpp EffectDragonEye.h \
EffectHasRelic.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h Slayer.h PlayerCreature.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h
EffectRegenerate.o: EffectRegenerate.cpp EffectRegenerate.h Effect.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h EffectLoader.h Creature.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Monster.h MonsterInfo.h \
MonsterSummonInfo.h MonsterInfoTypes.h Treasure.h Item.h \
PrecedenceTable.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCStatusCurrentHP.h $(COREDIR)/PacketFactory.h
EffectRecallMotorcycle.o: EffectRecallMotorcycle.cpp $(COREDIR)/Assert.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
EffectRecallMotorcycle.h Effect.h Object.h $(SERVDIR)/Timeval.h \
$(COREDIR)/Gpackets/GCDeleteObject.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h Tile.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h Item.h Obstacle.h \
Portal.h quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Zone.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
ZoneUtil.h $(COREDIR)/VSDateTime.h EffectRideMotorcycle.h Slayer.h \
PlayerCreature.h InventorySlot.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h
EffectRideMotorcycle.o: EffectRideMotorcycle.cpp $(COREDIR)/Assert.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h EffectRideMotorcycle.h \
Effect.h Object.h $(SERVDIR)/Timeval.h \
$(COREDIR)/Gpackets/GCDeleteObject.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Cpackets/CGRideMotorCycle.h Tile.h Creature.h EffectManager.h \
$(COREDIR)/EffectInfo.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Zone.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
ZoneUtil.h $(COREDIR)/VSDateTime.h Slayer.h PlayerCreature.h \
InventorySlot.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
GamePlayer.h $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
  $(COREDIR)/Gpackets/GCReconnectLogin.h
EffectDonation200501.o: EffectDonation200501.cpp EffectDonation200501.h \
Effect.h Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Creature.h EffectManager.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Slayer.h PlayerCreature.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCSelectQuestID.h \
OptionInfo.h $(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
$(COREDIR)/Player.h $(COREDIR)/Gpackets/GCAddEffect.h \
  $(COREDIR)/Gpackets/GCRemoveEffect.h
SimpleTileEffect.o: SimpleTileEffect.cpp SimpleTileEffect.h Effect.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h EffectLoader.h Tile.h Creature.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Zone.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(COREDIR)/PacketFactory.h
EffectDeleteTile.o: EffectDeleteTile.cpp EffectDeleteTile.h Effect.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h EffectLoader.h $(SKILLDIR)/HitRoll.h \
$(COREDIR)/ModifyInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Zone.h Tile.h Creature.h EffectManager.h \
$(COREDIR)/EffectInfo.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h PCManager.h CreatureManager.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h $(COREDIR)/Gpackets/GCAddEffectToTile.h \
$(COREDIR)/PacketFactory.h $(COREDIR)/Gpackets/GCDeleteEffectFromTile.h
EffectBehemothForceScroll.o: EffectBehemothForceScroll.cpp \
EffectBehemothForceScroll.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(SERVDIR)/DBExecuteManager.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
$(SERVDIR)/CondVarAttr.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
EffectSafeForceScroll.o: EffectSafeForceScroll.cpp \
EffectSafeForceScroll.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(SERVDIR)/DBExecuteManager.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
$(SERVDIR)/CondVarAttr.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
EffectCarnelianForceScroll.o: EffectCarnelianForceScroll.cpp \
EffectCarnelianForceScroll.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(SERVDIR)/DBExecuteManager.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
$(SERVDIR)/CondVarAttr.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
EffectHoodlumStigma.o: EffectHoodlumStigma.cpp EffectHoodlumStigma.h \
Effect.h Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(COREDIR)/Player.h \
$(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h \
  $(COREDIR)/Gpackets/GCRemoveEffect.h
EffectFuriousIncense.o: EffectFuriousIncense.cpp EffectFuriousIncense.h \
Effect.h Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h
EffectStrengthenIncense.o: EffectStrengthenIncense.cpp \
EffectStrengthenIncense.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h
EffectHyperactiveIncense.o: EffectHyperactiveIncense.cpp \
EffectHyperactiveIncense.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h
EffectImpregnableIncense.o: EffectImpregnableIncense.cpp \
EffectImpregnableIncense.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
  $(DBDIR)/Result.h
EffectGreyfellForceScroll.o: EffectGreyfellForceScroll.cpp \
EffectGreyfellForceScroll.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(SERVDIR)/DBExecuteManager.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
$(SERVDIR)/CondVarAttr.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
EffectSoviusForceScroll.o: EffectSoviusForceScroll.cpp \
EffectSoviusForceScroll.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(SERVDIR)/DBExecuteManager.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
$(SERVDIR)/CondVarAttr.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
EffectMirForceScroll.o: EffectMirForceScroll.cpp EffectMirForceScroll.h \
Effect.h Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(SERVDIR)/DBExecuteManager.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
$(SERVDIR)/CondVarAttr.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
EffectWarpMonster.o: EffectWarpMonster.cpp $(COREDIR)/Assert.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h EffectWarpMonster.h \
Effect.h Object.h $(SERVDIR)/Timeval.h \
$(COREDIR)/Gpackets/GCDeleteObject.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h Tile.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h Item.h Obstacle.h \
Portal.h quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Zone.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
ZoneUtil.h $(COREDIR)/VSDateTime.h
EffectBonusExp.o: EffectBonusExp.cpp EffectBonusExp.h Effect.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(COREDIR)/Player.h \
$(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h \
  $(COREDIR)/Gpackets/GCRemoveEffect.h
EffectMysteryPotion.o: EffectMysteryPotion.cpp EffectMysteryPotion.h \
Effect.h Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(COREDIR)/Player.h \
$(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h \
  $(COREDIR)/Gpackets/GCRemoveEffect.h
EffectOdinForceScroll.o: EffectOdinForceScroll.cpp \
EffectOdinForceScroll.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(SERVDIR)/DBExecuteManager.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
$(SERVDIR)/CondVarAttr.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
EffectTituosForceScroll.o: EffectTituosForceScroll.cpp \
EffectTituosForceScroll.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(SERVDIR)/DBExecuteManager.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
$(SERVDIR)/CondVarAttr.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
EffectPetBonusExp.o: EffectPetBonusExp.cpp EffectPetBonusExp.h Effect.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(COREDIR)/Player.h \
$(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h \
  $(COREDIR)/Gpackets/GCRemoveEffect.h
EffectVampireHeroItem.o: EffectVampireHeroItem.cpp \
EffectVampireHeroItem.h EffectHasRelic.h Effect.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Slayer.h PlayerCreature.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h
EffectSlayerHeroItem.o: EffectSlayerHeroItem.cpp EffectSlayerHeroItem.h \
EffectHasRelic.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h Slayer.h PlayerCreature.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h
EffectOustersHeroItem.o: EffectOustersHeroItem.cpp \
EffectOustersHeroItem.h EffectHasRelic.h Effect.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Slayer.h PlayerCreature.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h
EffectMenegrothDoungeon.o: EffectMenegrothDoungeon.cpp \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
EffectMenegrothDoungeon.h Effect.h Object.h $(COREDIR)/Exception.h \
$(COREDIR)/StringStream.h $(COREDIR)/Assert.h $(SERVDIR)/Timeval.h \
EffectLoader.h Slayer.h PlayerCreature.h Creature.h EffectManager.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h ZoneUtil.h ZoneInfoManager.h ZoneInfo.h \
GamePlayer.h $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h EventTransport.h \
MenegrothDoungeonManager.h StringPool.h \
  $(COREDIR)/Gpackets/GCRemoveEffect.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
EffectCabracamAltar.o: EffectCabracamAltar.cpp $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h EffectCabracamAltar.h Effect.h Object.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h EffectLoader.h Slayer.h PlayerCreature.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h ZoneUtil.h ZoneInfoManager.h ZoneInfo.h \
GamePlayer.h $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h EventTransport.h \
MenegrothDoungeonManager.h $(COREDIR)/Gpackets/GCAddEffect.h \
  $(COREDIR)/Gpackets/GCRemoveEffect.h
EffectSummonCabracam.o: EffectSummonCabracam.cpp $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h EffectSummonCabracam.h Effect.h Object.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h EffectLoader.h Slayer.h PlayerCreature.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Monster.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h PrecedenceTable.h ZoneUtil.h ZoneInfoManager.h ZoneInfo.h \
GamePlayer.h $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h MenegrothDoungeonZoneManager.h \
MenegrothDoungeonManager.h $(COREDIR)/Gpackets/GCAddEffectToTile.h
EffectSlayerLevelWarHeroItem.o: EffectSlayerLevelWarHeroItem.cpp \
EffectSlayerLevelWarHeroItem.h EffectHasRelic.h Effect.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Slayer.h PlayerCreature.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h
EffectVampireLevelWarHeroItem.o: EffectVampireLevelWarHeroItem.cpp \
EffectVampireLevelWarHeroItem.h EffectHasRelic.h Effect.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Slayer.h PlayerCreature.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h
EffectOustersLevelWarHeroItem.o: EffectOustersLevelWarHeroItem.cpp \
EffectOustersLevelWarHeroItem.h EffectHasRelic.h Effect.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h Slayer.h PlayerCreature.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h
EffectDSG.o: EffectDSG.cpp EffectDSG.h Effect.h Object.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(COREDIR)/Player.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h \
  $(COREDIR)/Gpackets/GCRemoveEffect.h
EffectQuestSuccess.o: EffectQuestSuccess.cpp EffectQuestSuccess.h \
Effect.h Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(COREDIR)/Player.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h \
  $(COREDIR)/Gpackets/GCRemoveEffect.h
EffectRankBonusExpRed.o: EffectRankBonusExpRed.cpp \
EffectRankBonusExpRed.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(COREDIR)/Player.h \
$(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h \
  $(COREDIR)/Gpackets/GCRemoveEffect.h
EffectRankBonusExpBlue.o: EffectRankBonusExpBlue.cpp \
EffectRankBonusExpBlue.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(COREDIR)/Player.h \
$(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h \
  $(COREDIR)/Gpackets/GCRemoveEffect.h
EffectPremiumService.o: EffectPremiumService.cpp EffectPremiumService.h \
Effect.h Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(COREDIR)/Player.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h \
  $(COREDIR)/Gpackets/GCRemoveEffect.h
EffectExtremeForceScroll.o: EffectExtremeForceScroll.cpp \
EffectExtremeForceScroll.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(SERVDIR)/DBExecuteManager.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
$(SERVDIR)/CondVarAttr.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
EventReloginToSharedServer.o: EventReloginToSharedServer.cpp \
EventReloginToSharedServer.h Event.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(SERVDIR)/Timeval.h GamePlayer.h $(COREDIR)/Player.h \
$(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/SocketOutputStream.h \
$(COREDIR)/Socket.h $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/SocketInputStream.h \
$(SERVDIR)/Mutex.h $(COREDIR)/Packet.h $(COREDIR)/PlayerStatus.h \
EventManager.h $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
$(COREDIR)/VSDateTime.h Item.h Object.h $(COREDIR)/Assert.h Effect.h \
EffectManager.h $(COREDIR)/EffectInfo.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
PlayerCreature.h Creature.h ObjectRegistry.h InventorySlot.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h SharedServerManager.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h PacketUtil.h $(COREDIR)/Gpackets/GSLogin.h \
  $(COREDIR)/StringInfo.h
EffectPromotionAngelFlutter.o: EffectPromotionAngelFlutter.cpp \
EffectPromotionAngelFlutter.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(SERVDIR)/DBExecuteManager.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
$(SERVDIR)/CondVarAttr.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
EffectPromotionBatWing.o: EffectPromotionBatWing.cpp \
EffectPromotionBatWing.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(SERVDIR)/DBExecuteManager.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
$(SERVDIR)/CondVarAttr.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
EffectPromotionButterflyWing.o: EffectPromotionButterflyWing.cpp \
EffectPromotionButterflyWing.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(SERVDIR)/DBExecuteManager.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
$(SERVDIR)/CondVarAttr.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
EffectLifeForceScroll.o: EffectLifeForceScroll.cpp \
EffectLifeForceScroll.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(SERVDIR)/DBExecuteManager.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
$(SERVDIR)/CondVarAttr.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
EffectAccuraForceScroll.o: EffectAccuraForceScroll.cpp \
EffectAccuraForceScroll.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(SERVDIR)/DBExecuteManager.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
$(SERVDIR)/CondVarAttr.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
EffectBonusExpSecond.o: EffectBonusExpSecond.cpp EffectBonusExpSecond.h \
Effect.h Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(COREDIR)/Player.h \
$(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h \
  $(COREDIR)/Gpackets/GCRemoveEffect.h
EffectBonusExpAdvance.o: EffectBonusExpAdvance.cpp \
EffectBonusExpAdvance.h Effect.h Object.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Assert.h $(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(COREDIR)/Player.h \
$(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h \
  $(COREDIR)/Gpackets/GCRemoveEffect.h
EffectChaoticExp.o: EffectChaoticExp.cpp EffectChaoticExp.h Effect.h \
Object.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
$(SERVDIR)/Timeval.h EffectLoader.h PlayerCreature.h Creature.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
$(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/Gpackets/GCRemoveEffect.h $(SERVDIR)/DBExecuteManager.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h \
$(SERVDIR)/CondVarAttr.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h
Event.o: Event.cpp Event.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(SERVDIR)/Timeval.h $(COREDIR)/Assert.h
EventManager.o: EventManager.cpp EventManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
Event.h $(SERVDIR)/Timeval.h $(COREDIR)/Assert.h
EventShutdown.o: EventShutdown.cpp EventShutdown.h Event.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(SERVDIR)/Timeval.h \
ZoneGroupManager.h ZoneGroup.h Zone.h Tile.h Object.h \
$(COREDIR)/Assert.h Creature.h EffectManager.h Effect.h \
$(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h $(COREDIR)/GameTime.h \
$(COREDIR)/Gpackets/GMServerInfo.h $(COREDIR)/DatagramPacket.h \
$(COREDIR)/Datagram.h $(COREDIR)/PacketFactory.h ZonePlayerManager.h \
$(SERVDIR)/PlayerManager.h $(COREDIR)/Player.h IncomingPlayerManager.h \
GamePlayer.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
$(COREDIR)/VSDateTime.h $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/ServerSocket.h \
$(COREDIR)/DatagramSocket.h ConnectionInfoManager.h ConnectionInfo.h \
$(BILLINGDIR)/BillingInfo.h VariableManager.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SERVDIR)/DBExecuteManager.h $(SERVDIR)/Thread.h \
$(SERVDIR)/pthreadAPI.h $(SERVDIR)/CondVar.h $(SERVDIR)/CondVarAttr.h
EventRegeneration.o: EventRegeneration.cpp EventRegeneration.h Event.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(SERVDIR)/Timeval.h \
GamePlayer.h $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
$(COREDIR)/SocketInputStream.h $(SERVDIR)/Mutex.h $(COREDIR)/Packet.h \
$(COREDIR)/PlayerStatus.h EventManager.h $(SKILLDIR)/Skill.h \
$(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h Item.h Object.h \
$(COREDIR)/Assert.h Effect.h EffectManager.h $(COREDIR)/EffectInfo.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
Creature.h Slayer.h PlayerCreature.h ObjectRegistry.h InventorySlot.h \
Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
$(COREDIR)/Gpackets/GCModifyInformation.h Vampire.h \
$(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
  $(COREDIR)/Gpackets/GCStatusCurrentHP.h
EventSave.o: EventSave.cpp EventSave.h Event.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(SERVDIR)/Timeval.h GamePlayer.h $(COREDIR)/Player.h \
$(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/SocketOutputStream.h \
$(COREDIR)/Socket.h $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/SocketInputStream.h \
$(SERVDIR)/Mutex.h $(COREDIR)/Packet.h $(COREDIR)/PlayerStatus.h \
EventManager.h $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
$(COREDIR)/VSDateTime.h Item.h Object.h $(COREDIR)/Assert.h Effect.h \
EffectManager.h $(COREDIR)/EffectInfo.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
Creature.h Slayer.h PlayerCreature.h ObjectRegistry.h InventorySlot.h \
Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
$(COREDIR)/Gpackets/GCModifyInformation.h Vampire.h \
$(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h
EventMorph.o: EventMorph.cpp EventMorph.h Event.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(SERVDIR)/Timeval.h Creature.h Object.h $(COREDIR)/Assert.h \
EffectManager.h Effect.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h GamePlayer.h $(COREDIR)/Player.h \
$(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
$(SERVDIR)/Mutex.h $(COREDIR)/PlayerStatus.h EventManager.h \
$(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h \
Item.h $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
PCFinder.h NPC.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h Inventory.h \
VolumeInfo.h InventorySlot.h $(COUPLEDIR)/PartnerWaitingManager.h \
PlayerCreature.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Vampire.h $(COREDIR)/PCVampireInfo.h \
$(COREDIR)/PCInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h CreatureUtil.h \
$(SKILLDIR)/VampireSkillSlot.h $(SKILLDIR)/SkillSlot.h \
$(COREDIR)/Gpackets/GCModifyInformation.h Slayer.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/SlayerSkillSlot.h ItemUtil.h \
ZoneInfoManager.h ZoneInfo.h ZoneGroupManager.h ZoneGroup.h \
$(COREDIR)/GameTime.h $(COREDIR)/Gpackets/GMServerInfo.h \
$(COREDIR)/DatagramPacket.h $(COREDIR)/Datagram.h \
IncomingPlayerManager.h $(SERVDIR)/PlayerManager.h \
$(COREDIR)/ServerSocket.h $(COREDIR)/DatagramSocket.h \
ConnectionInfoManager.h ConnectionInfo.h ZonePlayerManager.h \
TimeManager.h $(SERVDIR)/LogClient.h PacketUtil.h TradeManager.h \
GuildManager.h Guild.h ZoneUtil.h RelicUtil.h SharedServerManager.h \
$(SERVDIR)/Thread.h $(SERVDIR)/pthreadAPI.h \
$(COREDIR)/Gpackets/GCUpdateInfo.h $(COREDIR)/NPCInfo.h \
$(COREDIR)/NicknameInfo.h $(COREDIR)/BloodBibleSignInfo.h \
$(COREDIR)/Gpackets/GCMorph1.h $(COREDIR)/Gpackets/GCMorphVampire2.h \
  $(COREDIR)/Gpackets/GSGuildMemberLogOn.h
EventResurrect.o: EventResurrect.cpp EventResurrect.h Event.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(SERVDIR)/Timeval.h \
Zone.h Tile.h Object.h $(COREDIR)/Assert.h Creature.h EffectManager.h \
Effect.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h GamePlayer.h \
$(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
$(COREDIR)/VSDateTime.h $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
ZoneGroup.h $(COREDIR)/GameTime.h $(COREDIR)/Gpackets/GMServerInfo.h \
$(COREDIR)/DatagramPacket.h $(COREDIR)/Datagram.h ZoneGroupManager.h \
ZoneInfo.h ZoneInfoManager.h IncomingPlayerManager.h \
$(SERVDIR)/PlayerManager.h $(COREDIR)/ServerSocket.h \
$(COREDIR)/DatagramSocket.h ConnectionInfoManager.h ConnectionInfo.h \
ZonePlayerManager.h Slayer.h PlayerCreature.h InventorySlot.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
$(COREDIR)/Gpackets/GCModifyInformation.h Vampire.h \
$(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
TimeManager.h PacketUtil.h $(COREDIR)/Gpackets/GCUpdateInfo.h \
$(COREDIR)/NPCInfo.h $(COREDIR)/NicknameInfo.h \
  $(COREDIR)/BloodBibleSignInfo.h
EventReloadInfo.o: EventReloadInfo.cpp EventReloadInfo.h Event.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(SERVDIR)/Timeval.h \
Zone.h Tile.h Object.h $(COREDIR)/Assert.h Creature.h EffectManager.h \
Effect.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h GamePlayer.h \
$(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
$(COREDIR)/VSDateTime.h $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
ZoneGroup.h $(COREDIR)/GameTime.h $(COREDIR)/Gpackets/GMServerInfo.h \
$(COREDIR)/DatagramPacket.h $(COREDIR)/Datagram.h ZoneGroupManager.h \
ZoneInfo.h ZoneInfoManager.h ZoneUtil.h IncomingPlayerManager.h \
$(SERVDIR)/PlayerManager.h $(COREDIR)/ServerSocket.h \
$(COREDIR)/DatagramSocket.h ConnectionInfoManager.h ConnectionInfo.h \
ZonePlayerManager.h MasterLairInfoManager.h ItemInfoManager.h ItemInfo.h \
InfoClassManager.h MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h \
Treasure.h LogNameManager.h NameManager.h Directive.h RankBonusInfo.h \
OptionInfo.h $(WARDIR)/WarScheduler.h $(WARDIR)/Work.h \
$(WARDIR)/Scheduler.h $(WARDIR)/Schedule.h $(WARDIR)/War.h \
ShrineInfoManager.h StringPool.h $(COREDIR)/Gpackets/GCSystemMessage.h \
$(WARDIR)/RaceWarLimiter.h PCLimiter.h $(MISSIONDIR)/QuestInfoManager.h \
$(COREDIR)/Gpackets/GCNPCResponse.h $(MISSIONDIR)/QuestInfo.h \
$(MISSIONDIR)/RewardClass.h GoodsInfoManager.h SweeperBonusManager.h
EventTransport.o: EventTransport.cpp EventTransport.h Event.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(SERVDIR)/Timeval.h \
Zone.h Tile.h Object.h $(COREDIR)/Assert.h Creature.h EffectManager.h \
Effect.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h GamePlayer.h \
$(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
$(COREDIR)/VSDateTime.h $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
ZoneGroup.h $(COREDIR)/GameTime.h $(COREDIR)/Gpackets/GMServerInfo.h \
$(COREDIR)/DatagramPacket.h $(COREDIR)/Datagram.h ZonePlayerManager.h \
$(SERVDIR)/PlayerManager.h ZoneUtil.h PlayerCreature.h InventorySlot.h \
Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h RelicUtil.h CreatureUtil.h StringPool.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
EventKick.o: EventKick.cpp EventKick.h Event.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(SERVDIR)/Timeval.h Zone.h Tile.h Object.h $(COREDIR)/Assert.h \
Creature.h EffectManager.h Effect.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h GamePlayer.h \
$(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
$(COREDIR)/VSDateTime.h $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
StringPool.h $(COREDIR)/Gpackets/GCSystemMessage.h
EventSystemMessage.o: EventSystemMessage.cpp EventSystemMessage.h \
Event.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(SERVDIR)/Timeval.h \
Zone.h Tile.h Object.h $(COREDIR)/Assert.h Creature.h EffectManager.h \
Effect.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h GamePlayer.h \
$(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
$(COREDIR)/VSDateTime.h $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
  $(COREDIR)/Gpackets/GCSystemMessage.h
EventRefreshHolyLandPlayer.o: EventRefreshHolyLandPlayer.cpp \
EventRefreshHolyLandPlayer.h Event.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(SERVDIR)/Timeval.h HolyLandManager.h $(SERVDIR)/Mutex.h \
$(COREDIR)/VSDateTime.h Zone.h Tile.h Object.h $(COREDIR)/Assert.h \
Creature.h EffectManager.h Effect.h $(COREDIR)/EffectInfo.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h ZoneGroupManager.h \
ZoneGroup.h $(COREDIR)/GameTime.h $(COREDIR)/Gpackets/GMServerInfo.h \
$(COREDIR)/DatagramPacket.h $(COREDIR)/Datagram.h \
  $(COREDIR)/PacketFactory.h
EventHeadCount.o: EventHeadCount.cpp EventHeadCount.h Event.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(SERVDIR)/Timeval.h \
Zone.h Tile.h Object.h $(COREDIR)/Assert.h Creature.h EffectManager.h \
Effect.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h Item.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h GamePlayer.h \
$(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
$(COREDIR)/VSDateTime.h $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h Slayer.h PlayerCreature.h \
InventorySlot.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h
EventCBilling.o: EventCBilling.cpp EventCBilling.h Event.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(SERVDIR)/Timeval.h \
GamePlayer.h $(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h $(COREDIR)/Encrypter.h \
$(COREDIR)/EncryptUtility.h $(COREDIR)/SocketEncryptInputStream.h \
$(COREDIR)/SocketInputStream.h $(SERVDIR)/Mutex.h $(COREDIR)/Packet.h \
$(COREDIR)/PlayerStatus.h EventManager.h $(SKILLDIR)/Skill.h \
$(SERVDIR)/PaySystem.h $(COREDIR)/VSDateTime.h Item.h Object.h \
$(COREDIR)/Assert.h Effect.h EffectManager.h $(COREDIR)/EffectInfo.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
$(SERVDIR)/chinabilling/CBillingPlayerManager.h $(SERVDIR)/Thread.h \
  $(SERVDIR)/pthreadAPI.h
EventAuth.o: EventAuth.cpp EventAuth.h Event.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(SERVDIR)/Timeval.h GamePlayer.h $(COREDIR)/Player.h \
$(COREDIR)/SocketEncryptOutputStream.h $(COREDIR)/SocketOutputStream.h \
$(COREDIR)/Socket.h $(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/SocketInputStream.h \
$(SERVDIR)/Mutex.h $(COREDIR)/Packet.h $(COREDIR)/PlayerStatus.h \
EventManager.h $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
$(COREDIR)/VSDateTime.h Item.h Object.h $(COREDIR)/Assert.h Effect.h \
EffectManager.h $(COREDIR)/EffectInfo.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h $(COREDIR)/PacketFactory.h \
Creature.h Slayer.h PlayerCreature.h ObjectRegistry.h InventorySlot.h \
Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h $(COREDIR)/GearInfo.h \
$(COREDIR)/GearSlotInfo.h $(COREDIR)/PCItemInfo.h \
$(COREDIR)/SubItemInfo.h Zone.h Tile.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h Party.h $(COREDIR)/ModifyInfo.h \
PCManager.h CreatureManager.h Inventory.h VolumeInfo.h \
$(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h $(COREDIR)/PCSlayerInfo2.h \
$(COREDIR)/PCSlayerInfo3.h $(COREDIR)/InventoryInfo.h \
$(COREDIR)/InventorySlotInfo.h ItemLoaderManager.h ItemLoader.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/RideMotorcycleInfo.h $(COREDIR)/RideMotorcycleSlotInfo.h \
$(COREDIR)/SlayerSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/SkillSlot.h \
$(COREDIR)/Gpackets/GCModifyInformation.h Vampire.h \
$(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
$(COREDIR)/Gpackets/GCAuthKey.h $(COREDIR)/Gpackets/GCSystemMessage.h \
  EventKick.h
GQuestInfo.o: GQuestInfo.cpp GQuestInfo.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/SXml.h $(COREDIR)/Exception.h \
$(COREDIR)/StringStream.h GQuestElement.h GQuestManager.h \
GQuestInventory.h $(COREDIR)/Gpackets/GCGQuestInventory.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestLevelElement.h GQuestStatus.h $(COREDIR)/QuestStatusInfo.h \
$(COREDIR)/Assert.h $(COREDIR)/Properties.h \
  SystemAvailabilitiesManager.h \
$(COREDIR)/Gpackets/GCSystemAvailabilities.h VariableManager.h
GQuestManager.o: GQuestManager.cpp GQuestManager.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
GQuestInventory.h $(COREDIR)/Gpackets/GCGQuestInventory.h \
$(COREDIR)/Packet.h $(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h \
$(COREDIR)/SXml.h GQuestElement.h PlayerCreature.h Creature.h Object.h \
$(COREDIR)/Assert.h EffectManager.h Effect.h $(SERVDIR)/Timeval.h \
$(COREDIR)/EffectInfo.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h \
  $(COREDIR)/Gpackets/GCGQuestStatusInfo.h \
  $(COREDIR)/Gpackets/GCGQuestStatusModify.h \
$(COREDIR)/Gpackets/GCSystemMessage.h $(COREDIR)/Player.h \
GQuestAllElements.h GQuestBloodDrainElement.h \
GQuestGiveVampireExpElement.h GQuestLevelElement.h GQuestSayNPCElement.h \
GQuestTimeElement.h GQuestTamePetElement.h GQuestExecuteElement.h \
GQuestGiveItemElement.h GQuestGiveQuestItemElement.h \
GQuestLoseQuestItemElement.h GQuestRaceElement.h GQuestKilledElement.h \
GQuestGiveDomainExpElement.h GQuestGiveMoneyElement.h \
GQuestSkillLevelElement.h GQuestRideMotorcycleElement.h \
GQuestGiveOustersExpElement.h GQuestTouchWayPointElement.h \
GQuestHasQuestItemElement.h GQuestKillMonsterElement.h \
GQuestPartyDissectElement.h GQuestGiveEventQuestItemElement.h \
GQuestEventPartyElement.h GQuestEventPartyCrashElement.h \
GQuestCompleteQuestElement.h GQuestFastMoveElement.h \
GQuestIllegalWarpElement.h GQuestTravelElement.h GQuestORElement.h \
GQuestNOTElement.h GQuestRandomElement.h \
GQuestAdvancementClassLevelElement.h GQuestClearDynamicZoneElement.h \
GQuestAddEffectElement.h GQuestRemoveEffectElement.h \
GQuestSetEnterDynamicZoneElement.h GQuestEnterDynamicZoneElement.h \
GQuestStartOtherQuestElement.h GQuestGiveAdvancementClassExpElement.h \
GQuestAdvanceClassElement.h GQuestWarpElement.h GQuestEnterZoneElement.h \
GQuestGenderElement.h GQuestSlayerHighestSkillDomainElement.h NPC.h \
Zone.h Tile.h Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COUPLEDIR)/PartnerWaitingManager.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h MonsterCorpse.h ItemFactory.h Corpse.h Monster.h \
MonsterInfo.h MonsterSummonInfo.h MonsterInfoTypes.h Treasure.h \
PrecedenceTable.h EffectEventQuestReset.h EffectLoader.h \
GQuestCheckPoint.h StringPool.h
GQuestElement.o: GQuestElement.cpp GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestAllElements.h GQuestBloodDrainElement.h GQuestStatus.h \
$(COREDIR)/QuestStatusInfo.h GQuestInfo.h GQuestGiveVampireExpElement.h \
GQuestLevelElement.h GQuestSayNPCElement.h GQuestTimeElement.h \
$(SERVDIR)/Timeval.h GQuestTamePetElement.h GQuestExecuteElement.h \
GQuestGiveItemElement.h Item.h Object.h $(COREDIR)/Assert.h Effect.h \
EffectManager.h $(COREDIR)/EffectInfo.h GQuestGiveQuestItemElement.h \
GQuestLoseQuestItemElement.h GQuestRaceElement.h GQuestKilledElement.h \
GQuestGiveDomainExpElement.h GQuestGiveMoneyElement.h \
GQuestSkillLevelElement.h GQuestRideMotorcycleElement.h \
GQuestGiveOustersExpElement.h GQuestTouchWayPointElement.h \
GQuestHasQuestItemElement.h GQuestKillMonsterElement.h \
GQuestPartyDissectElement.h GQuestGiveEventQuestItemElement.h \
GQuestEventPartyElement.h GQuestEventPartyCrashElement.h \
GQuestCompleteQuestElement.h GQuestFastMoveElement.h \
GQuestIllegalWarpElement.h GQuestTravelElement.h GQuestORElement.h \
GQuestNOTElement.h GQuestRandomElement.h \
GQuestAdvancementClassLevelElement.h GQuestClearDynamicZoneElement.h \
GQuestAddEffectElement.h GQuestRemoveEffectElement.h \
GQuestSetEnterDynamicZoneElement.h GQuestEnterDynamicZoneElement.h \
GQuestStartOtherQuestElement.h GQuestGiveAdvancementClassExpElement.h \
GQuestAdvanceClassElement.h GQuestWarpElement.h GQuestEnterZoneElement.h \
GQuestGenderElement.h GQuestSlayerHighestSkillDomainElement.h \
PlayerCreature.h Creature.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h
GQuestStatus.o: GQuestStatus.cpp GQuestStatus.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/QuestStatusInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h GQuestInfo.h $(COREDIR)/SXml.h \
GQuestElement.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/PacketFactory.h \
$(COREDIR)/Gpackets/GCGQuestStatusModify.h PlayerCreature.h Creature.h \
Object.h $(COREDIR)/Assert.h EffectManager.h Effect.h \
$(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(COREDIR)/Player.h \
$(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h EffectEventQuestReset.h \
EffectLoader.h EffectQuestSuccess.h Vampire.h Inventory.h VolumeInfo.h \
Zone.h Tile.h Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/PCVampireInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCVampireInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/VampireSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h CreatureUtil.h \
$(SKILLDIR)/VampireSkillSlot.h $(SKILLDIR)/Skill.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
  $(COREDIR)/Gpackets/GCAddEffect.h
GQuestInventory.o: GQuestInventory.cpp GQuestInventory.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(SERVDIR)/Mutex.h \
$(DBDIR)/Statement.h $(DBDIR)/Result.h
GQuestLevelElement.o: GQuestLevelElement.cpp GQuestLevelElement.h \
GQuestElement.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/SXml.h \
GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h
GQuestTimeElement.o: GQuestTimeElement.cpp GQuestTimeElement.h \
GQuestElement.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/SXml.h \
GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h \
$(SERVDIR)/Timeval.h $(COREDIR)/Assert.h
GQuestGiveVampireExpElement.o: GQuestGiveVampireExpElement.cpp \
GQuestGiveVampireExpElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Vampire.h Inventory.h \
VolumeInfo.h Zone.h Tile.h Obstacle.h Portal.h quest/TriggerManager.h \
quest/Trigger.h quest/Condition.h quest/PropertyBuffer.h Sector.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/PCVampireInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCVampireInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/VampireSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h CreatureUtil.h \
$(SKILLDIR)/VampireSkillSlot.h $(SKILLDIR)/Skill.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
$(SKILLDIR)/SkillUtil.h Slayer.h $(COREDIR)/PCSlayerInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/SlayerSkillSlot.h Ousters.h $(COREDIR)/PCOustersInfo.h \
$(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
$(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
$(SKILLDIR)/OustersSkillSlot.h $(COREDIR)/Gpackets/GCSystemMessage.h \
$(COREDIR)/Player.h StringPool.h
GQuestBloodDrainElement.o: GQuestBloodDrainElement.cpp \
GQuestBloodDrainElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h \
  $(COREDIR)/Assert.h
GQuestSayNPCElement.o: GQuestSayNPCElement.cpp GQuestSayNPCElement.h \
GQuestElement.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/SXml.h \
GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Inventory.h \
  VolumeInfo.h
GQuestExecuteElement.o: GQuestExecuteElement.cpp GQuestExecuteElement.h \
GQuestElement.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/SXml.h \
GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h GQuestInfo.h \
$(COREDIR)/Gpackets/GCExecuteElement.h $(COREDIR)/Player.h
GQuestGiveQuestItemElement.o: GQuestGiveQuestItemElement.cpp \
GQuestGiveQuestItemElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(COREDIR)/Player.h \
$(COREDIR)/Gpackets/GCSystemMessage.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h StringPool.h
GQuestLoseQuestItemElement.o: GQuestLoseQuestItemElement.cpp \
GQuestLoseQuestItemElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(COREDIR)/Player.h \
$(COREDIR)/Gpackets/GCSystemMessage.h StringPool.h
GQuestGiveItemElement.o: GQuestGiveItemElement.cpp \
GQuestGiveItemElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h Item.h \
Object.h $(COREDIR)/Assert.h Effect.h $(SERVDIR)/Timeval.h \
EffectManager.h $(COREDIR)/EffectInfo.h PlayerCreature.h Creature.h \
ObjectRegistry.h $(SERVDIR)/Mutex.h InventorySlot.h Garbage.h \
RankBonus.h ExpFwd.h $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(COREDIR)/Player.h \
Treasure.h ItemUtil.h ItemFactoryManager.h ItemFactory.h Inventory.h \
VolumeInfo.h $(COREDIR)/Gpackets/GCCreateItem.h \
$(COREDIR)/Gpackets/GCSystemMessage.h PacketUtil.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h StringPool.h \
  EffectPrecedence.h
GQuestTamePetElement.o: GQuestTamePetElement.cpp GQuestTamePetElement.h \
GQuestElement.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/SXml.h \
GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h \
  $(COREDIR)/Assert.h
GQuestRaceElement.o: GQuestRaceElement.cpp GQuestRaceElement.h \
GQuestElement.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/SXml.h \
GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h
GQuestKilledElement.o: GQuestKilledElement.cpp GQuestKilledElement.h \
GQuestElement.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/SXml.h \
GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h \
  $(COREDIR)/Assert.h
GQuestGiveDomainExpElement.o: GQuestGiveDomainExpElement.cpp \
GQuestGiveDomainExpElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Slayer.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
$(SKILLDIR)/SkillUtil.h Vampire.h $(COREDIR)/PCVampireInfo.h \
$(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCVampireInfo3.h \
$(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
$(SKILLDIR)/VampireSkillSlot.h Ousters.h $(COREDIR)/PCOustersInfo.h \
$(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
$(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
$(SKILLDIR)/OustersSkillSlot.h $(COREDIR)/Gpackets/GCSystemMessage.h \
$(COREDIR)/Player.h StringPool.h
GQuestGiveMoneyElement.o: GQuestGiveMoneyElement.cpp \
GQuestGiveMoneyElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h \
$(COREDIR)/Gpackets/GCModifyInformation.h $(COREDIR)/ModifyInfo.h \
$(COREDIR)/Gpackets/GCSystemMessage.h $(COREDIR)/Player.h StringPool.h
GQuestSkillLevelElement.o: GQuestSkillLevelElement.cpp \
GQuestSkillLevelElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h \
$(SKILLDIR)/SlayerSkillSlot.h $(SKILLDIR)/Skill.h \
  $(SKILLDIR)/SkillSlot.h
GQuestRideMotorcycleElement.o: GQuestRideMotorcycleElement.cpp \
GQuestRideMotorcycleElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h \
  $(COREDIR)/Assert.h
GQuestGiveOustersExpElement.o: GQuestGiveOustersExpElement.cpp \
GQuestGiveOustersExpElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Ousters.h Inventory.h \
VolumeInfo.h Zone.h Tile.h Obstacle.h Portal.h quest/TriggerManager.h \
quest/Trigger.h quest/Condition.h quest/PropertyBuffer.h Sector.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/PCOustersInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
$(COREDIR)/ExtraInfo.h $(COREDIR)/ExtraSlotInfo.h \
$(COREDIR)/OustersSkillInfo.h $(COREDIR)/PCSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h CreatureUtil.h \
$(SKILLDIR)/OustersSkillSlot.h $(SKILLDIR)/Skill.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
$(SKILLDIR)/SkillUtil.h Slayer.h $(COREDIR)/PCSlayerInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/SubSlayerSkillInfo.h SlayerAttrExpTable.h \
SomethingGrowingUp.h $(DBDIR)/DB.h $(DBDIR)/DatabaseManager.h \
$(DBDIR)/Connection.h $(DBDIR)/Statement.h $(DBDIR)/Result.h \
$(SKILLDIR)/SlayerSkillSlot.h Vampire.h $(COREDIR)/PCVampireInfo.h \
$(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCVampireInfo3.h \
$(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
$(SKILLDIR)/VampireSkillSlot.h $(COREDIR)/Gpackets/GCSystemMessage.h \
$(COREDIR)/Player.h StringPool.h
GQuestTouchWayPointElement.o: GQuestTouchWayPointElement.cpp \
GQuestTouchWayPointElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h MonsterCorpse.h \
Item.h Object.h $(COREDIR)/Assert.h Effect.h $(SERVDIR)/Timeval.h \
EffectManager.h $(COREDIR)/EffectInfo.h ItemFactory.h Inventory.h \
VolumeInfo.h InventorySlot.h Corpse.h Zone.h Tile.h Creature.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h Party.h $(COREDIR)/ModifyInfo.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
ZoneUtil.h $(COREDIR)/VSDateTime.h
GQuestHasQuestItemElement.o: GQuestHasQuestItemElement.cpp \
GQuestHasQuestItemElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h
GQuestPartyDissectElement.o: GQuestPartyDissectElement.cpp \
GQuestPartyDissectElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h \
$(COREDIR)/Assert.h PlayerCreature.h Creature.h Object.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h MonsterInfo.h \
MonsterSummonInfo.h MonsterInfoTypes.h Treasure.h
GQuestKillMonsterElement.o: GQuestKillMonsterElement.cpp \
GQuestKillMonsterElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h \
  $(COREDIR)/Assert.h
GQuestGiveEventQuestItemElement.o: GQuestGiveEventQuestItemElement.cpp \
GQuestGiveEventQuestItemElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h $(COREDIR)/Player.h \
$(COREDIR)/Gpackets/GCSystemMessage.h CreatureUtil.h \
$(SKILLDIR)/SkillUtil.h $(COREDIR)/ModifyInfo.h Slayer.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h PCManager.h \
CreatureManager.h $(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
Inventory.h VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h
GQuestEventPartyElement.o: GQuestEventPartyElement.cpp \
GQuestEventPartyElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h Party.h \
Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h Effect.h \
$(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h $(SERVDIR)/Mutex.h \
$(COREDIR)/ModifyInfo.h PlayerCreature.h ObjectRegistry.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h
GQuestEventPartyCrashElement.o: GQuestEventPartyCrashElement.cpp \
GQuestEventPartyCrashElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h \
  $(COREDIR)/Assert.h
GQuestCompleteQuestElement.o: GQuestCompleteQuestElement.cpp \
GQuestCompleteQuestElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h
GQuestFastMoveElement.o: GQuestFastMoveElement.cpp \
GQuestFastMoveElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h \
  $(COREDIR)/Assert.h
GQuestIllegalWarpElement.o: GQuestIllegalWarpElement.cpp \
GQuestIllegalWarpElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h \
  $(COREDIR)/Assert.h
GQuestCheckPoint.o: GQuestCheckPoint.cpp GQuestCheckPoint.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/Assert.h \
MonsterCorpse.h Item.h Object.h Effect.h $(SERVDIR)/Timeval.h \
EffectManager.h $(COREDIR)/EffectInfo.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h ItemFactory.h Inventory.h VolumeInfo.h \
InventorySlot.h Corpse.h Zone.h Tile.h Creature.h Obstacle.h Portal.h \
quest/TriggerManager.h quest/Trigger.h quest/Condition.h \
quest/PropertyBuffer.h Sector.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
Party.h $(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h ZoneUtil.h \
$(COREDIR)/VSDateTime.h ZoneInfo.h $(COREDIR)/Properties.h \
ZoneInfoManager.h $(COREDIR)/SXml.h
GQuestTravelElement.o: GQuestTravelElement.cpp GQuestTravelElement.h \
GQuestElement.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/SXml.h \
GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h \
GQuestCheckPoint.h $(COREDIR)/Assert.h PlayerCreature.h Creature.h \
Object.h EffectManager.h Effect.h $(SERVDIR)/Timeval.h \
$(COREDIR)/EffectInfo.h ObjectRegistry.h $(SERVDIR)/Mutex.h \
InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h MonsterInfo.h \
MonsterSummonInfo.h MonsterInfoTypes.h Treasure.h
GQuestORElement.o: GQuestORElement.cpp GQuestORElement.h GQuestElement.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/SXml.h \
GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h
GQuestNOTElement.o: GQuestNOTElement.cpp GQuestNOTElement.h \
GQuestElement.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/SXml.h \
GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h
GQuestRandomElement.o: GQuestRandomElement.cpp GQuestRandomElement.h \
GQuestElement.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/SXml.h \
GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h
GQuestAdvancementClassLevelElement.o: GQuestAdvancementClassLevelElement.cpp \
GQuestAdvancementClassLevelElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h
GQuestClearDynamicZoneElement.o: GQuestClearDynamicZoneElement.cpp \
GQuestClearDynamicZoneElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h \
  $(COREDIR)/Assert.h
GQuestAddEffectElement.o: GQuestAddEffectElement.cpp \
GQuestAddEffectElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h Effect.h \
Object.h $(COREDIR)/Assert.h $(SERVDIR)/Timeval.h PlayerCreature.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h CreatureUtil.h
GQuestRemoveEffectElement.o: GQuestRemoveEffectElement.cpp \
GQuestRemoveEffectElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h Effect.h \
Object.h $(COREDIR)/Assert.h $(SERVDIR)/Timeval.h PlayerCreature.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h
GQuestSetEnterDynamicZoneElement.o: GQuestSetEnterDynamicZoneElement.cpp \
GQuestSetEnterDynamicZoneElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h Effect.h \
Object.h $(COREDIR)/Assert.h $(SERVDIR)/Timeval.h PlayerCreature.h \
Creature.h EffectManager.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h CreatureUtil.h
GQuestEnterDynamicZoneElement.o: GQuestEnterDynamicZoneElement.cpp \
GQuestEnterDynamicZoneElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h \
  $(COREDIR)/Assert.h
GQuestStartOtherQuestElement.o: GQuestStartOtherQuestElement.cpp \
GQuestStartOtherQuestElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h
GQuestGiveAdvancementClassExpElement.o: GQuestGiveAdvancementClassExpElement.cpp \
GQuestGiveAdvancementClassExpElement.h GQuestElement.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/SXml.h \
GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Slayer.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
$(SKILLDIR)/SkillUtil.h Vampire.h $(COREDIR)/PCVampireInfo.h \
$(COREDIR)/PCVampireInfo2.h $(COREDIR)/PCVampireInfo3.h \
$(COREDIR)/VampireSkillInfo.h $(COREDIR)/SubVampireSkillInfo.h \
$(SKILLDIR)/VampireSkillSlot.h Ousters.h $(COREDIR)/PCOustersInfo.h \
$(COREDIR)/PCOustersInfo2.h $(COREDIR)/PCOustersInfo3.h \
$(COREDIR)/OustersSkillInfo.h $(COREDIR)/SubOustersSkillInfo.h \
$(SKILLDIR)/OustersSkillSlot.h $(COREDIR)/Gpackets/GCSystemMessage.h \
  $(COREDIR)/Player.h
GQuestAdvanceClassElement.o: GQuestAdvanceClassElement.cpp \
GQuestAdvanceClassElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Slayer.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h \
Vampire.h $(COREDIR)/PCVampireInfo.h $(COREDIR)/PCVampireInfo2.h \
$(COREDIR)/PCVampireInfo3.h $(COREDIR)/VampireSkillInfo.h \
$(COREDIR)/SubVampireSkillInfo.h $(SKILLDIR)/VampireSkillSlot.h \
Ousters.h $(COREDIR)/PCOustersInfo.h $(COREDIR)/PCOustersInfo2.h \
$(COREDIR)/PCOustersInfo3.h $(COREDIR)/OustersSkillInfo.h \
$(COREDIR)/SubOustersSkillInfo.h $(SKILLDIR)/OustersSkillSlot.h \
$(COREDIR)/Player.h SkillDomainInfoManager.h VampEXPInfo.h \
  OustersEXPInfo.h
GQuestWarpElement.o: GQuestWarpElement.cpp GQuestWarpElement.h \
GQuestElement.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/SXml.h \
GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h GamePlayer.h \
$(COREDIR)/Player.h $(COREDIR)/SocketEncryptOutputStream.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h \
$(COREDIR)/SocketEncryptInputStream.h $(COREDIR)/PlayerStatus.h \
EventManager.h Event.h $(SKILLDIR)/Skill.h $(SERVDIR)/PaySystem.h \
  $(BILLINGDIR)/BillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingPlayerInfo.h \
  $(SERVDIR)/chinabilling/CBillingInfo.h \
$(COREDIR)/Gpackets/GCReconnectLogin.h ZoneUtil.h EventTransport.h \
Zone.h Tile.h Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h
GQuestEnterZoneElement.o: GQuestEnterZoneElement.cpp \
GQuestEnterZoneElement.h GQuestElement.h $(COREDIR)/Types.h \
$(COREDIR)/types/SystemTypes.h $(COREDIR)/types/PlayerTypes.h \
$(COREDIR)/types/ObjectTypes.h $(COREDIR)/types/CreatureTypes.h \
$(COREDIR)/types/ItemTypes.h $(COREDIR)/types/ZoneTypes.h \
$(COREDIR)/types/QuestTypes.h $(COREDIR)/types/ShopTypes.h \
$(COREDIR)/types/GuildTypes.h $(COREDIR)/types/WarTypes.h \
$(COREDIR)/types/ServerType.h $(COREDIR)/types/VersionType.h \
$(COREDIR)/Utility.h $(COREDIR)/Exception.h $(COREDIR)/StringStream.h \
$(COREDIR)/SXml.h GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h
GQuestGenderElement.o: GQuestGenderElement.cpp GQuestGenderElement.h \
GQuestElement.h $(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/SXml.h \
GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h
GQuestSlayerHighestSkillDomainElement.o: GQuestSlayerHighestSkillDomainElement.cpp \
GQuestSlayerHighestSkillDomainElement.h GQuestElement.h \
$(COREDIR)/Types.h $(COREDIR)/types/SystemTypes.h \
$(COREDIR)/types/PlayerTypes.h $(COREDIR)/types/ObjectTypes.h \
$(COREDIR)/types/CreatureTypes.h $(COREDIR)/types/ItemTypes.h \
$(COREDIR)/types/ZoneTypes.h $(COREDIR)/types/QuestTypes.h \
$(COREDIR)/types/ShopTypes.h $(COREDIR)/types/GuildTypes.h \
$(COREDIR)/types/WarTypes.h $(COREDIR)/types/ServerType.h \
$(COREDIR)/types/VersionType.h $(COREDIR)/Utility.h \
$(COREDIR)/Exception.h $(COREDIR)/StringStream.h $(COREDIR)/SXml.h \
GQuestManager.h GQuestInventory.h \
$(COREDIR)/Gpackets/GCGQuestInventory.h $(COREDIR)/Packet.h \
$(COREDIR)/SocketInputStream.h $(COREDIR)/Socket.h \
$(COREDIR)/SocketImpl.h $(COREDIR)/SocketAPI.h \
$(COREDIR)/SocketOutputStream.h $(COREDIR)/PacketFactory.h \
GQuestStatus.h $(COREDIR)/QuestStatusInfo.h GQuestInfo.h \
PlayerCreature.h Creature.h Object.h $(COREDIR)/Assert.h EffectManager.h \
Effect.h $(SERVDIR)/Timeval.h $(COREDIR)/EffectInfo.h ObjectRegistry.h \
$(SERVDIR)/Mutex.h InventorySlot.h Item.h Garbage.h RankBonus.h ExpFwd.h \
  $(COREDIR)/Gpackets/GCMonsterKillQuestInfo.h \
$(COREDIR)/Gpackets/GCSelectQuestID.h OptionInfo.h \
$(COREDIR)/VSDateTime.h $(COREDIR)/GearInfo.h $(COREDIR)/GearSlotInfo.h \
$(COREDIR)/PCItemInfo.h $(COREDIR)/SubItemInfo.h Slayer.h Zone.h Tile.h \
Obstacle.h Portal.h quest/TriggerManager.h quest/Trigger.h \
quest/Condition.h quest/PropertyBuffer.h Sector.h Party.h \
$(COREDIR)/ModifyInfo.h PCManager.h CreatureManager.h \
$(COREDIR)/Encrypter.h $(COREDIR)/EncryptUtility.h Inventory.h \
VolumeInfo.h $(COREDIR)/PCSlayerInfo.h $(COREDIR)/PCInfo.h \
$(COREDIR)/PCSlayerInfo2.h $(COREDIR)/PCSlayerInfo3.h \
$(COREDIR)/InventoryInfo.h $(COREDIR)/InventorySlotInfo.h \
ItemLoaderManager.h ItemLoader.h $(COREDIR)/ExtraInfo.h \
$(COREDIR)/ExtraSlotInfo.h $(COREDIR)/RideMotorcycleInfo.h \
$(COREDIR)/RideMotorcycleSlotInfo.h $(COREDIR)/SlayerSkillInfo.h \
$(COREDIR)/PCSkillInfo.h $(COREDIR)/SubSlayerSkillInfo.h CreatureUtil.h \
SlayerAttrExpTable.h SomethingGrowingUp.h $(DBDIR)/DB.h \
$(DBDIR)/DatabaseManager.h $(DBDIR)/Connection.h $(DBDIR)/Statement.h \
$(DBDIR)/Result.h $(SKILLDIR)/Skill.h $(SKILLDIR)/SlayerSkillSlot.h \
$(SKILLDIR)/SkillSlot.h $(COREDIR)/Gpackets/GCModifyInformation.h
