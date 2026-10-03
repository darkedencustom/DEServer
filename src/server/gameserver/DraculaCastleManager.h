//////////////////////////////////////////////////////////////////////////////
// Filename    : DraculaCastleManager.h
// Description : The Mihnea ritual that opens Dracula Castle's 2nd floor.
//
//   Every 12 hours from server start the seal on Mihnea's Storage (NPC 1202,
//   1F, 103/134) fades and its Mihnea can be taken by talking to it. Carrying
//   the Mihnea works like carrying a Blood Bible: no attacks or skills, half
//   move speed, and it falls to the floor when the carrier dies, logs out,
//   leaves 1F or morphs; anyone can pick it up again, and if nobody has after
//   10 minutes it returns to the storage, whose seal drops again. Five minutes
//   after the Mihnea was first taken the cage around the Mihnea Altar (NPC
//   1203, by the 2F stairs, 204/47) drops; placing the Mihnea there breaks the
//   door across the stairs. The door stands again whenever a new Vlad II
//   Dracul appears on 2F.
//
//   Driven from Zone::heartbeat of the three castle zones (all in zone group
//   2, so one thread) before the PC-count gate, like RodinBossManager. The GM
//   commands only raise flags that the next 1F heartbeat applies, since the
//   GM may be in another zone group's thread.
//////////////////////////////////////////////////////////////////////////////

#ifndef __DRACULA_CASTLE_MANAGER_H__
#define __DRACULA_CASTLE_MANAGER_H__

#include "Types.h"
#include "Exception.h"
#include "Mutex.h"
#include <time.h>
#include <string>
#include <vector>
#include <set>

class Zone;
class NPC;
class Creature;
class PlayerCreature;
class Item;

class DraculaCastleManager
{
public:
	enum
	{
		ZONE_GATE        = 6050,
		ZONE_1F          = 6051,
		ZONE_2F          = 6052,
		STORAGE_NPC_ID   = 1202,		// creature.en.inf "Mihnea's Storage", sprite set 350
		ALTAR_NPC_ID     = 1203,		// creature.en.inf "Mihnea Altar", sprite set 351
		VLAD_TYPE        = 1196,
		MIHNEA_TYPE      = 64,			// CommonQuestItemInfo 64 "Mihnea"
		OPEN_INTERVAL    = 12 * 60 * 60,	// seconds between openings
		ALTAR_DELAY      = 5 * 60,		// seconds from the take to the altar's cage dropping
		FLOOR_TIMEOUT    = 10 * 60,		// seconds a dropped Mihnea lies about before going home
		COLLAPSE_SECONDS = 0,			// the cage collapse animation (48 frames) before the artifact floats
		// --- the 2F lair (Vlad II Dracul) ---
		LAIR_COUNTDOWN_SECONDS = 5 * 60,	// door broken -> Dracula spawns
		FIRE_INTERVAL_SEC = 1,			// a burst of fire pillars every second ...
		FIRE_MIN = 10,					// ... this many pillars per burst (dracFire tunes all four live)
		FIRE_MAX = 16,
		FIRE_DAMAGE_PERCENT = 100,		// of max HP on the tile, half on the 8 around it (the lairs use 100)
		FIRE_STRIKE_TURNS = 20,			// swirl first, the pillar rises ~2 s later and strikes (skill Ground Attack: Duration 20; Effect() defaults to never)
		DRAC_X = 60,					// where Dracula appears (centre room)
		DRAC_Y = 80,
		ENTRY_X = 13,					// the 1F -> 2F portal landing: resurrect spot during the countdown
		ENTRY_Y = 125,
		ROOM_X1 = 44,					// the centre room + its alcoves: never any fire in here
		ROOM_Y1 = 54,
		ROOM_X2 = 88,
		ROOM_Y2 = 96,
		AFTERMATH_SECONDS = 10,			// Dracula defeated -> everyone is sent down to 1F
		RETURN_X = 200,					// 1F, at the foot of the stairs in front of the door
		RETURN_Y = 45,

		// client effectstatus.inf rows appended for this (build_mihnea_client.py). Creature statuses must stay
		// below the client's EFFECTSTATUS_MAX (1020) and 1017 must stay inert (creature.en.inf uses it as "no
		// status"); tile statuses are not bounds-checked, so the door takes 1020/1021.
		// Rows mirror DK670's action.inf 907-917 (build_mihnea_client.py ACTIONS/STATUSES): every cage comes with
		// its shadow sprite, and the Mihnea itself is a separate effect on whichever stand holds it.
		STORAGE_SEAL_STATUS  = 1016,	// CASTLE_PLATFORM: cage 2287 + shadow, held (creature status)
		ALTAR_SEAL_STATUS    = 1018,	// CASTLE_EMPTY_PLATFORM: cage 2293 + shadow, held (creature status)
		DOOR_STANDING_STATUS = 1020,	// CASTLE_GATE: EST 2282, a delay node (tile)
		DOOR_BREAKING_STATUS = 1021,	// CASTLE_GATE_BRAKE: 2280 + debris 2279 (tile, one-shot)
		MIHNEA_STATUS        = 1022,	// CASTLE_MIHNEA: the artifact 2289 + shadow on a stand (tile, held)
		BREAK_FULL_STATUS    = 1023,	// CASTLE_PLATFORM_BRAKE: the cage holding the Mihnea collapsing (tile, one-shot)
		BREAK_EMPTY_STATUS   = 1024,	// CASTLE_EMPTY_PLATFORM_BRAKE: the empty cage collapsing (tile, one-shot)
		CAGE_FULL_STATUS     = 1026,	// CASTLE_PLATFORM: wire cage with the Mihnea drawn inside it + shadow, held
		CAGE_EMPTY_STATUS    = 1027,	// CASTLE_EMPTY_PLATFORM: empty wire cage + shadow, held (tile effects: the
										// v664 client did not draw these as creature statuses)
		BREAK_TURNS          = 50,		// tenths of a second a one-shot stays registered
		DOOR_BREAK_TURNS     = 50,		// tenths of a second the breaking effect stays on the tile
		DOOR_X               = 201,		// tile the door sprite hangs on, measured from screenshots at 200/41 and
		DOOR_Y               = 38,		// 202/39 (MapToPixel is axis-aligned, 48x24 px per tile, sprite anchor
										// (-39,-207)); a wall tile is fine since
										// the effect goes on with Tile::addObject. *command dracDoorAt x y moves it live.
		FOREVER_TURNS        = 99999999	// setDeadline() value for effects that never expire on their own
	};

	DraculaCastleManager() throw();

	static bool isCastleZone(ZoneID_t zoneID) { return zoneID >= ZONE_GATE && zoneID <= ZONE_2F; }
	static bool isLairZone(ZoneID_t zoneID) { return zoneID == ZONE_2F; }	// PvE (all races vs Dracula), no teleport-in
	enum LairState { LAIR_IDLE, LAIR_COUNTDOWN, LAIR_FIGHT, LAIR_AFTERMATH };
	static bool isMihnea(const Item* pItem);

	// every castle zone's heartbeat, in the zone group's thread
	void heartbeat(Zone* pZone) throw(Error);

	// NPC dialogue answers (ActionTakeMihnea / ActionPlaceMihnea); the returned text goes to the player
	string takeMihnea(PlayerCreature* pPC) throw(Error);
	string placeMihnea(PlayerCreature* pPC, Item* pHandItem = NULL) throw(Error);	// pHandItem: already off the mouse, ours to consume
	bool canPlaceHere(PlayerCreature* pPC) throw();		// beside the open altar with a ritual under way

	// the carrier dies, logs out, leaves 1F or morphs: the Mihnea falls where they stand
	bool dropMihnea(Creature* pCreature, bool bSendPacket = true, const char* why = "dropped") throw(Error);	// death, morph: it falls where the carrier stood
	void startLair(const char* why) throw(Error);				// the door broke: 5-minute countdown on 2F, then Dracula
	bool overrideResurrect(Creature* pDead, ZoneID_t& zoneID, ZoneCoord_t& x, ZoneCoord_t& y) throw();	// PCManager hook
	string forceLair() throw();								// GM startDrac2
	void leave2F(Creature* pCreature) throw();				// ZoneUtil hook: timer and shake off for whoever leaves 2F
	string forceFire(int intervalSec, int minN, int maxN, int percent) throw();	// GM dracFire
	void returnMihnea(Creature* pCreature, const char* why, bool bSendPacket = true) throw(Error);	// logout, transport, leaving 1F: it goes back to the storage (the 1F heartbeat reopens it)
	// picked up off the floor (CGAddZoneToInventory / CGAddZoneToMouse), or dropped by hand (CGAddMouseToZone)
	void onMihneaPickedUp(PlayerCreature* pPC, Item* pItem) throw(Error);
	void onMihneaDropped(PlayerCreature* pPC, Item* pItem, Zone* pZone, ZoneCoord_t x, ZoneCoord_t y) throw(Error);

	// GM: *command startDrac / resetDrac / dracDoor / dracDoorAt x y / dracSeal N / dracStatus
	string forceOpen() throw();
	string forceReset() throw();
	string forceDoor(const string& how) throw();
	string forceDoorAt(int x, int y) throw();		// move the door sprite's anchor tile (placement tuning)
	string forceSeal(int status, int altarStatus) throw();	// show other client status rows as the seals (look tuning)
	string toString() const throw();

private:
	enum StorageState { STORAGE_SEALED, STORAGE_OPEN, STORAGE_TAKEN };

	// all of these run in the castle zone group's thread with m_Mutex held
	void init(Zone* pZone1F) throw(Error);
	void tick1F(time_t now) throw(Error);
	void openStorage(bool bAnnounce) throw(Error);
	void sealStorage() throw(Error);
	void unsealAltar() throw(Error);
	void sealAltar() throw(Error);
	void reset(const char* why) throw(Error);
	void returnToStorage(const char* why) throw(Error);
	void raiseDoor() throw(Error);
	void breakDoor() throw(Error);
	void blockStairs(bool bBlock) throw(Error);
	bool findDoorTile(ZoneCoord_t& x, ZoneCoord_t& y) throw();
	ObjectID_t addDoorEffect(EffectID_t sendStatus, Turn_t turns) throw();
	ObjectID_t addTileEffect(ZoneCoord_t x, ZoneCoord_t y, EffectID_t sendStatus, Turn_t turns) throw();
	ObjectID_t addTileEffectIn(Zone* pZone, ZoneCoord_t x, ZoneCoord_t y, EffectID_t sendStatus, Turn_t turns) throw();
	void clearFloorEffect() throw();
	void showArtifact(NPC* pWhere) throw();		// the Mihnea on a stand (NULL = nowhere: carried or on the floor)
	bool isSealed(NPC* pNPC) const throw();
	EffectID_t cageStatus(NPC* pNPC) const throw();	// the cage variant a caged stand shows
	void refreshCage(NPC* pNPC) throw();
	void purgeCarriers() throw(Error);		// every Mihnea item/flag off the PCs on 1F
	void tick2F(Zone* pZone2F, time_t now) throw(Error);
	void buildHallways(Zone* pZone2F) throw();
	void fireHallways(Zone* pZone2F) throw();
	void sendLairTimer(Zone* pZone2F, bool bEveryone) throw();
	void sendTimerMessage(PlayerCreature* pPC, int remainSec) throw();
	void updateShake(Zone* pZone2F) throw();
	void stopShake(Zone* pZone2F) throw();
	static bool inRoom(int x, int y) { return x >= ROOM_X1 && x <= ROOM_X2 && y >= ROOM_Y1 && y <= ROOM_Y2; }
	bool spawnDracula(Zone* pZone2F) throw();
	void endLair(const char* why) throw();
	const char* lairStateName() const throw();
	void checkVlad(Zone* pZone2F) throw(Error);
	void verifyCarrier() throw(Error);
	void placePendingDrop(Zone* pZone, time_t now) throw(Error);
	void checkFloor(time_t now) throw(Error);
	void removeFloorItem() throw(Error);

	NPC* findNPC(NPCID_t npcID, const char* name) throw();
	void setSeal(NPC* pNPC, bool bSealed) throw(Error);
	Item* takeFromInventory(PlayerCreature* pPC, bool bSendPacket) throw(Error);
	void addCarrierEffect(PlayerCreature* pPC) throw(Error);
	void removeCarrierEffect(Creature* pCreature) throw(Error);
	void announce(const string& message) throw();
	void announceZone(Zone* pZone, const string& message) throw();
	const char* stateName() const throw();

	Zone*			m_pZone1F;
	NPC*			m_pStorage;
	NPC*			m_pAltar;
	bool			m_bInit;
	time_t			m_StartTime;

	StorageState	m_StorageState;
	time_t			m_NextOpenTime;
	time_t			m_TakenTime;		// when the Mihnea left the storage this cycle
	bool			m_bAltarSealed;
	string			m_Carrier;			// player carrying it, or ""

	Item*			m_pPendingDrop;		// left an inventory, goes on the floor at the next tick of its zone
	Zone*			m_pPendingDropZone;
	ZoneCoord_t		m_PendingX, m_PendingY;

	Zone*			m_pFloorZone;		// lying on the floor here, or NULL
	ObjectID_t		m_FloorItemOID;
	ObjectID_t		m_FloorEffectOID;	// the Mihnea hovering over the floor item
	ZoneCoord_t		m_FloorX, m_FloorY;
	time_t			m_FloorSince;

	bool			m_bDoorUp;
	ObjectID_t		m_DoorOID;			// the standing door's tile effect, 0 when no tile could take it
	ZoneCoord_t		m_DoorAnchorX, m_DoorAnchorY;	// tile the door sprite is asked to hang on (DOOR_X/Y unless a GM moved it)
	ZoneCoord_t		m_DoorTileX, m_DoorTileY;		// where the door effects actually sit
	ObjectID_t		m_LastVladOID;		// the Vlad the door was last raised for
	ObjectID_t		m_ArtifactOID;		// the Mihnea-on-a-stand tile effect, 0 when carried / on the floor
	ObjectID_t		m_StorageCageOID;	// the cage tile effects, 0 when down
	ObjectID_t		m_AltarCageOID;
	int				m_CarrierMisses;	// verifyCarrier(): consecutive ticks the carrier was seen without the item
	NPC*			m_pCollapsing;		// the stand whose cage is collapsing, until m_CollapseUntil
	time_t			m_CollapseUntil;
	bool			m_bArtifactPending;	// the artifact effect waits for the collapse to finish
	bool			m_bPendingReturn;	// returnMihnea() asked the 1F heartbeat to reopen the storage
	string			m_PendingReturnWhy;
	// the 2F lair
	Zone*			m_pZone2F;
	LairState		m_LairState;
	time_t			m_LairStart;
	time_t			m_LairEnd;			// countdown end = Dracula's spawn time
	time_t			m_LastFireSec;
	ObjectID_t		m_DraculaOID;
	bool			m_bPendingLair;		// GM startDrac2
	int				m_FireInterval;		// live-tunable copies of the FIRE_* constants
	int				m_FireMin;
	int				m_FireMax;
	int				m_FirePercent;
	vector< pair<ZoneCoord_t, ZoneCoord_t> > m_Hallways;	// 2F walkable tiles outside the centre room
	set<ObjectID_t>	m_LairNotified;		// PCs that already have the countdown on screen
	set<ObjectID_t>	m_Shaking;			// PCs whose screen shakes (in a hallway)
	NPC*			m_pArtifactNPC;		// which stand shows it
	EffectID_t		m_SealStatus;		// client status row shown on the sealed storage
	EffectID_t		m_AltarSealStatus;	// ... and on the caged altar

	bool			m_bPendingOpen;		// GM requests, applied on the next 1F tick
	bool			m_bPendingReset;
	int				m_PendingDoor;		// 0 none, 1 raise, 2 break
	int				m_PendingDoorX, m_PendingDoorY;	// -1 none
	int				m_PendingSeal, m_PendingAltarSeal;	// -1 none

	mutable Mutex	m_Mutex;
};

extern DraculaCastleManager g_DraculaCastleManager;

#endif
