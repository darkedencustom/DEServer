//////////////////////////////////////////////////////////////////////////////
// Filename    : DraculaCastleManager.cpp
// Description : The Mihnea ritual that opens Dracula Castle's 2nd floor.
//               See DraculaCastleManager.h. Log: log/DraculaCastle.log.
//////////////////////////////////////////////////////////////////////////////

#include "DraculaCastleManager.h"
#include "PCFinder.h"
#include "PCManager.h"
#include "Zone.h"
#include "Tile.h"
#include "NPC.h"
#include "Monster.h"
#include "MonsterManager.h"
#include "PlayerCreature.h"
#include "Player.h"
#include "Item.h"
#include "ItemFactoryManager.h"
#include "Inventory.h"
#include "ZoneGroupManager.h"
#include "PacketUtil.h"
#include "EffectHasMihnea.h"
#include "EffectMihneaSeal.h"
#include "EffectMihneaDoor.h"
#include "Gpackets/GCSystemMessage.h"
#include "Gpackets/GCAddEffect.h"
#include "Gpackets/GCCreateItem.h"
#include "Gpackets/GCDeleteInventoryItem.h"
#include "Gpackets/GCDeleteObject.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

DraculaCastleManager g_DraculaCastleManager;

namespace
{
	struct MutexGuard
	{
		Mutex& m_rMutex;
		MutexGuard(Mutex& rMutex) : m_rMutex(rMutex) { m_rMutex.lock(); }
		~MutexGuard() { m_rMutex.unlock(); }
	};

	void log(const char* fmt, ...)
	{
		char buf[512];
		va_list ap;
		va_start(ap, fmt);
		vsnprintf(buf, sizeof(buf), fmt, ap);
		va_end(ap);
		filelog("DraculaCastle.log", "%s", buf);
	}

	string clock(time_t t)
	{
		char buf[32];
		struct tm tmv;
		localtime_r(&t, &tmv);
		strftime(buf, sizeof(buf), "%m-%d %H:%M:%S", &tmv);
		return buf;
	}
}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
DraculaCastleManager::DraculaCastleManager()
	throw()
	: m_pZone1F(NULL), m_pStorage(NULL), m_pAltar(NULL), m_bInit(false),
	  m_StartTime(time(NULL)),
	  m_StorageState(STORAGE_SEALED), m_NextOpenTime(0), m_TakenTime(0), m_bAltarSealed(true),
	  m_pPendingDrop(NULL), m_pPendingDropZone(NULL), m_PendingX(0), m_PendingY(0),
	  m_pFloorZone(NULL), m_FloorItemOID(0), m_FloorEffectOID(0), m_FloorX(0), m_FloorY(0), m_FloorSince(0),
	  m_bDoorUp(false), m_DoorOID(0), m_DoorAnchorX(DOOR_X), m_DoorAnchorY(DOOR_Y),
	  m_DoorTileX(DOOR_X), m_DoorTileY(DOOR_Y), m_LastVladOID(0), m_ArtifactOID(0), m_pArtifactNPC(NULL), m_StorageCageOID(0), m_AltarCageOID(0), m_CarrierMisses(0),
	  m_pCollapsing(NULL), m_CollapseUntil(0), m_bArtifactPending(false), m_bPendingReturn(false),
	  m_SealStatus(STORAGE_SEAL_STATUS), m_AltarSealStatus(ALTAR_SEAL_STATUS),
	  m_bPendingOpen(false), m_bPendingReset(false), m_PendingDoor(0),
	  m_PendingDoorX(-1), m_PendingDoorY(-1), m_PendingSeal(-1), m_PendingAltarSeal(-1)
{
	m_NextOpenTime = m_StartTime + OPEN_INTERVAL;
}

bool DraculaCastleManager::isMihnea(const Item* pItem)
{
	return pItem != NULL
		&& pItem->getItemClass() == Item::ITEM_CLASS_COMMON_QUEST_ITEM
		&& pItem->getItemType() == MIHNEA_TYPE;
}

////////////////////////////////////////////////////////////////////////////////
// heartbeat
////////////////////////////////////////////////////////////////////////////////
void DraculaCastleManager::heartbeat(Zone* pZone)
	throw(Error)
{
	__BEGIN_TRY

	MutexGuard guard(m_Mutex);

	// Nothing in here may take the zone-group thread down (an uncaught Throwable aborts the server), so
	// every failure is logged and the ritual carries on as best it can.
	try
	{
		ZoneID_t zoneID = pZone->getZoneID();
		if (!m_bInit)
		{
			if (zoneID != ZONE_1F) return;
			init(pZone);
		}

		time_t now = time(NULL);

		if (m_pPendingDrop != NULL && m_pPendingDropZone == pZone)
			placePendingDrop(pZone, now);

		if (m_pFloorZone == pZone && m_FloorItemOID != 0)
			checkFloor(now);

		if (zoneID == ZONE_2F)
			checkVlad(pZone);
		else if (zoneID == ZONE_1F)
			tick1F(now);
	}
	catch (Throwable& t)
	{
		log("heartbeat zone %d: %s", pZone->getZoneID(), t.toString().c_str());
	}

	__END_CATCH
}

void DraculaCastleManager::init(Zone* pZone1F)
	throw(Error)
{
	m_pZone1F = pZone1F;
	m_bInit = true;

	m_pStorage = findNPC(STORAGE_NPC_ID, "Mihnea Storage");
	m_pAltar = findNPC(ALTAR_NPC_ID, "Mihnea Altar");
	if (m_pStorage == NULL || m_pAltar == NULL)
		log("init: storage %s, altar %s (NPC rows 1202/1203 in zone 6051 missing?)",
			m_pStorage ? "found" : "MISSING", m_pAltar ? "found" : "MISSING");

	showArtifact(m_pStorage);
	sealStorage();
	sealAltar();
	raiseDoor();

	log("init: first opening at %s", clock(m_NextOpenTime).c_str());
}

void DraculaCastleManager::tick1F(time_t now)
	throw(Error)
{
	// The NPCs are placed by their triggers; if they were not there yet at init (or migration 1.3.8 went
	// in later), keep looking every 10 s and seal them when they turn up.
	if ((m_pStorage == NULL || m_pAltar == NULL) && now % 10 == 0)
	{
		if (m_pStorage == NULL && (m_pStorage = findNPC(STORAGE_NPC_ID, "Mihnea Storage")) != NULL)
		{
			log("storage NPC found");
			if (m_StorageState != STORAGE_TAKEN) showArtifact(m_pStorage);
			if (m_StorageState != STORAGE_OPEN) sealStorage();
		}
		if (m_pAltar == NULL && (m_pAltar = findNPC(ALTAR_NPC_ID, "Mihnea Altar")) != NULL)
		{
			log("altar NPC found");
			if (m_bAltarSealed) sealAltar();
		}
	}

	// GM requests
	if (m_bPendingReset)
	{
		m_bPendingReset = false;
		reset("GM resetDrac");
	}
	if (m_bPendingOpen)
	{
		m_bPendingOpen = false;
		if (m_StorageState != STORAGE_SEALED) reset("GM startDrac");
		openStorage(true);
	}
	if (m_PendingDoor != 0)
	{
		int how = m_PendingDoor;
		m_PendingDoor = 0;
		if (how == 1 && !m_bDoorUp) raiseDoor();
		if (how == 2 && m_bDoorUp) breakDoor();
	}
	if (m_PendingDoorX >= 0)
	{
		int x = m_PendingDoorX, y = m_PendingDoorY;
		m_PendingDoorX = m_PendingDoorY = -1;
		if (x >= m_pZone1F->getWidth() || y >= m_pZone1F->getHeight())
		{
			log("dracDoorAt %d/%d: outside the zone", x, y);
		}
		else
		{
			m_DoorAnchorX = x;
			m_DoorAnchorY = y;
			if (m_bDoorUp)
			{
				if (m_DoorOID != 0) m_pZone1F->deleteEffect(m_DoorOID);
				m_DoorOID = addDoorEffect(DOOR_STANDING_STATUS, FOREVER_TURNS);
			}
			log("dracDoorAt: door anchor now %d/%d (effect %u)", x, y, m_DoorOID);
		}
	}
	if (m_PendingSeal >= 0)
	{
		m_SealStatus = (EffectID_t)m_PendingSeal;
		if (m_PendingAltarSeal >= 0) m_AltarSealStatus = (EffectID_t)m_PendingAltarSeal;
		m_PendingSeal = m_PendingAltarSeal = -1;
		// re-apply whatever is sealed with the new look
		if (m_StorageState != STORAGE_OPEN) { setSeal(m_pStorage, false); setSeal(m_pStorage, true); }
		if (m_bAltarSealed) { setSeal(m_pAltar, false); setSeal(m_pAltar, true); }
		log("dracSeal: seals now show client statuses %d / %d", m_SealStatus, m_AltarSealStatus);
	}

	// a carrier logged out / left: the item is already gone, reopen the storage from this thread
	if (m_bPendingReturn)
	{
		m_bPendingReturn = false;
		if (m_StorageState == STORAGE_TAKEN)
			returnToStorage(m_PendingReturnWhy.c_str());
		else
			purgeCarriers();
	}
	// the artifact appears on an opened stand once its cage has finished collapsing
	if (m_bArtifactPending && now >= m_CollapseUntil)
	{
		m_bArtifactPending = false;
		if (m_pArtifactNPC != NULL && !isSealed(m_pArtifactNPC) && m_ArtifactOID == 0)
			m_ArtifactOID = addTileEffect(m_pArtifactNPC->getX(), m_pArtifactNPC->getY(), MIHNEA_STATUS, FOREVER_TURNS);
	}

	// the schedule
	if (now >= m_NextOpenTime)
	{
		while (m_NextOpenTime <= now) m_NextOpenTime += OPEN_INTERVAL;
		if (m_StorageState == STORAGE_SEALED)
			openStorage(true);
		else
			log("scheduled opening skipped: storage is %s", stateName());
	}

	if (m_StorageState != STORAGE_TAKEN) return;

	if (m_bAltarSealed && now >= m_TakenTime + ALTAR_DELAY)
		unsealAltar();

	if (!m_Carrier.empty())
		verifyCarrier();
	else if (m_pPendingDrop == NULL && m_FloorItemOID == 0)
		returnToStorage("nobody has it");
}

////////////////////////////////////////////////////////////////////////////////
// storage / altar
////////////////////////////////////////////////////////////////////////////////
void DraculaCastleManager::openStorage(bool bAnnounce)
	throw(Error)
{
	m_StorageState = STORAGE_OPEN;
	m_Carrier = "";
	setSeal(m_pStorage, false);
	if (m_pArtifactNPC != m_pStorage) showArtifact(m_pStorage);
	if (!m_bAltarSealed) sealAltar();		// a Mihnea placed last time went back to the storage just above
	log("storage open");
	if (bAnnounce)
		announce("The seal on Mihnea's Storage in Dracula Castle has faded. The Mihnea can be taken.");
}

void DraculaCastleManager::sealStorage()
	throw(Error)
{
	setSeal(m_pStorage, true);
}

void DraculaCastleManager::unsealAltar()
	throw(Error)
{
	m_bAltarSealed = false;
	setSeal(m_pAltar, false);
	log("altar open");
	announce("The cage around the Mihnea Altar in Dracula Castle has opened.");
}

void DraculaCastleManager::sealAltar()
	throw(Error)
{
	m_bAltarSealed = true;
	setSeal(m_pAltar, true);
}

// Everything back to the sealed start: the carrier loses the item, a floor copy is removed.
void DraculaCastleManager::reset(const char* why)
	throw(Error)
{
	log("reset: %s (was %s)", why, stateName());

	if (!m_Carrier.empty() && m_pZone1F != NULL)
	{
		Creature* pCreature = m_pZone1F->getCreature(m_Carrier);
		PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
		if (pPC != NULL)
		{
			Item* pItem = takeFromInventory(pPC, true);
			SAFE_DELETE(pItem);
			removeCarrierEffect(pPC);
		}
	}
	m_Carrier = "";

	if (m_pPendingDrop != NULL)
	{
		SAFE_DELETE(m_pPendingDrop);
		m_pPendingDropZone = NULL;
	}
	if (m_FloorItemOID != 0)
		removeFloorItem();

	purgeCarriers();
	m_StorageState = STORAGE_SEALED;
	showArtifact(m_pStorage);
	sealStorage();
	sealAltar();
}

// The Mihnea was lost or left lying about: the storage opens again for the next taker.
void DraculaCastleManager::returnToStorage(const char* why)
	throw(Error)
{
	log("returned to storage: %s", why);
	purgeCarriers();
	m_Carrier = "";
	m_bArtifactPending = false;
	clearFloorEffect();
	m_FloorItemOID = 0;
	m_pFloorZone = NULL;
	sealAltar();
	openStorage(false);
	announce("The Mihnea has returned to Mihnea's Storage in Dracula Castle.");
}

////////////////////////////////////////////////////////////////////////////////
// the door
////////////////////////////////////////////////////////////////////////////////
// The door hangs on a stair (portal) tile, which Tile::addEffect refuses (its assert took the zone thread down
// on 2026-09-29), so addDoorEffect() uses Tile::addObject; any tile inside the zone is acceptable here.
bool DraculaCastleManager::findDoorTile(ZoneCoord_t& x, ZoneCoord_t& y)
	throw()
{
	if (m_pZone1F == NULL) return false;
	for (int dy = 0; dy <= 3; dy++)
	{
		for (int dx = 0; dx <= 3; dx++)
		{
			int cands[2] = { DOOR_X + dx, DOOR_X - dx };
			for (int k = 0; k < 2; k++)
			{
				int cx = cands[k], cy = DOOR_Y + dy;
				if (cx < 0 || cy < 0 || cx >= m_pZone1F->getWidth() || cy >= m_pZone1F->getHeight()) continue;
				x = cx;
				y = cy;
				return true;
			}
		}
	}
	return false;
}

// Any client tile-status row on any tile of 1F (Tile::addObject: no portal/obstacle assert); 0 on failure.
ObjectID_t DraculaCastleManager::addTileEffect(ZoneCoord_t x, ZoneCoord_t y, EffectID_t sendStatus, Turn_t turns)
	throw()
{
	return addTileEffectIn(m_pZone1F, x, y, sendStatus, turns);
}

ObjectID_t DraculaCastleManager::addTileEffectIn(Zone* pZone, ZoneCoord_t x, ZoneCoord_t y, EffectID_t sendStatus, Turn_t turns)
	throw()
{
	if (pZone == NULL) return 0;
	try
	{
		EffectMihneaDoor* pEffect = new EffectMihneaDoor(pZone, x, y, sendStatus);
		pEffect->setDeadline(turns);
		pZone->registerObject(pEffect);
		pZone->addEffect(pEffect);
		pZone->getTile(x, y).addObject(pEffect);
		pEffect->affect();
		return pEffect->getObjectID();
	}
	catch (Throwable& t)
	{
		log("tile status %d at %d/%d failed: %s", sendStatus, x, y, t.toString().c_str());
		return 0;
	}
}

// The Mihnea on a stand. Only one exists. On an open stand it is its own tile effect (client CASTLE_MIHNEA);
// on a caged stand the cage sprite draws it (CASTLE_PLATFORM), so the stand-alone effect is not shown there.
void DraculaCastleManager::showArtifact(NPC* pWhere)
	throw()
{
	NPC* pOld = m_pArtifactNPC;
	m_pArtifactNPC = pWhere;
	if (m_ArtifactOID != 0 && m_pZone1F != NULL)
	{
		m_pZone1F->deleteEffect(m_ArtifactOID);
		m_ArtifactOID = 0;
	}
	if (pOld != NULL && pOld != pWhere)
		refreshCage(pOld);			// a caged stand that lost the Mihnea shows the empty cage
	if (pWhere == NULL) return;
	if (isSealed(pWhere))
		refreshCage(pWhere);		// caged: the cage sprite carries the Mihnea
	else if (pWhere == m_pCollapsing && time(NULL) < m_CollapseUntil)
		m_bArtifactPending = true;	// after the collapse animation
	else
		m_ArtifactOID = addTileEffect(pWhere->getX(), pWhere->getY(), MIHNEA_STATUS, FOREVER_TURNS);
}

bool DraculaCastleManager::isSealed(NPC* pNPC) const
	throw()
{
	return pNPC != NULL && pNPC->findEffect(Effect::EFFECT_CLASS_MIHNEA_SEAL) != NULL;
}

EffectID_t DraculaCastleManager::cageStatus(NPC* pNPC) const
	throw()
{
	return (pNPC != NULL && pNPC == m_pArtifactNPC) ? CAGE_FULL_STATUS : CAGE_EMPTY_STATUS;
}

// Redraw a caged stand's cage in the variant that matches what it holds.
void DraculaCastleManager::refreshCage(NPC* pNPC)
	throw()
{
	if (pNPC == NULL || !isSealed(pNPC)) return;
	ObjectID_t& cageOID = (pNPC == m_pAltar) ? m_AltarCageOID : m_StorageCageOID;
	if (cageOID != 0 && m_pZone1F != NULL) m_pZone1F->deleteEffect(cageOID);
	cageOID = addTileEffect(pNPC->getX(), pNPC->getY(), cageStatus(pNPC), FOREVER_TURNS);
}

ObjectID_t DraculaCastleManager::addDoorEffect(EffectID_t sendStatus, Turn_t turns)
	throw()
{
	ZoneCoord_t x, y;
	if (!findDoorTile(x, y))
	{
		log("no usable tile near %d/%d for door status %d; the stairs are blocked without a sprite", m_DoorAnchorX, m_DoorAnchorY, sendStatus);
		return 0;
	}
	try
	{
		EffectMihneaDoor* pEffect = new EffectMihneaDoor(m_pZone1F, x, y, sendStatus);
		pEffect->setDeadline(turns);
		m_pZone1F->registerObject(pEffect);
		m_pZone1F->addEffect(pEffect);
		// Tile::addObject, not addEffect(): addEffect asserts on portal tiles and the door hangs on the stairs.
		// The zone's view code iterates the tile's objects, so arriving players still get it re-sent.
		m_pZone1F->getTile(x, y).addObject(pEffect);
		pEffect->affect();
		m_DoorTileX = x;
		m_DoorTileY = y;
		return pEffect->getObjectID();
	}
	catch (Throwable& t)
	{
		log("door status %d at %d/%d failed: %s", sendStatus, x, y, t.toString().c_str());
		return 0;
	}
}

void DraculaCastleManager::raiseDoor()
	throw(Error)
{
	if (m_pZone1F == NULL || m_bDoorUp) return;

	blockStairs(true);
	m_bDoorUp = true;
	m_DoorOID = addDoorEffect(DOOR_STANDING_STATUS, FOREVER_TURNS);
	log("door up (effect %u at %d/%d)", m_DoorOID, m_DoorTileX, m_DoorTileY);
}

void DraculaCastleManager::breakDoor()
	throw(Error)
{
	if (m_pZone1F == NULL || !m_bDoorUp) return;

	// the zone's deleteEffect calls unaffect(), which clears the tile and tells the clients
	if (m_DoorOID != 0)
	{
		m_pZone1F->deleteEffect(m_DoorOID);
		m_DoorOID = 0;
	}

	// the breaking animation, a short-lived tile effect of its own
	addDoorEffect(DOOR_BREAKING_STATUS, DOOR_BREAK_TURNS);

	blockStairs(false);
	m_bDoorUp = false;
	log("door broken");
}

// The stairs to 2F are the portal tiles in x197-203, y38-43.
void DraculaCastleManager::blockStairs(bool bBlock)
	throw(Error)
{
	if (m_pZone1F == NULL) return;

	for (int y = 38; y <= 43; y++)
	{
		for (int x = 197; x <= 203; x++)
		{
			Tile& tile = m_pZone1F->getTile(x, y);
			if (!tile.hasPortal()) continue;
			if (bBlock)
			{
				tile.setBlocked(Creature::MOVE_MODE_WALKING);
				tile.setBlocked(Creature::MOVE_MODE_FLYING);
				tile.setBlocked(Creature::MOVE_MODE_BURROWING);
			}
			else
			{
				tile.clearBlocked(Creature::MOVE_MODE_WALKING);
				tile.clearBlocked(Creature::MOVE_MODE_FLYING);
				tile.clearBlocked(Creature::MOVE_MODE_BURROWING);
			}
		}
	}
}

// A Vlad the door has not seen yet is up on 2F: the door comes back.
void DraculaCastleManager::checkVlad(Zone* pZone2F)
	throw(Error)
{
	const hash_map<ObjectID_t, Creature*>& creatures = pZone2F->getMonsterManager()->getCreatures();
	for (hash_map<ObjectID_t, Creature*>::const_iterator itr = creatures.begin(); itr != creatures.end(); ++itr)
	{
		Monster* pMonster = dynamic_cast<Monster*>(itr->second);
		if (pMonster == NULL || pMonster->getMonsterType() != VLAD_TYPE) continue;
		if (pMonster->isDead()) continue;
		if (pMonster->getObjectID() == m_LastVladOID) return;

		m_LastVladOID = pMonster->getObjectID();
		log("Vlad %u is up on 2F", m_LastVladOID);
		if (!m_bDoorUp)
		{
			raiseDoor();
			announce("Vlad II Dracul has returned to the 2nd floor of Dracula Castle. The door on the stairs stands again.");
		}
		return;
	}
}

////////////////////////////////////////////////////////////////////////////////
// take / place
////////////////////////////////////////////////////////////////////////////////
string DraculaCastleManager::takeMihnea(PlayerCreature* pPC)
	throw(Error)
{
	__BEGIN_TRY

	MutexGuard guard(m_Mutex);

	if (!m_bInit || pPC == NULL || pPC->getZone() != m_pZone1F) return "";
	if (m_StorageState != STORAGE_OPEN) return "The seal on Mihnea's Storage still holds.";
	if (pPC->isFlag(Effect::EFFECT_CLASS_HAS_MIHNEA)) return "";

	Item* pItem = NULL;
	try
	{
		pItem = g_pItemFactoryManager->createItem(Item::ITEM_CLASS_COMMON_QUEST_ITEM, MIHNEA_TYPE, list<OptionType_t>());
	}
	catch (Throwable&)
	{
		pItem = NULL;
	}
	if (pItem == NULL)
	{
		log("take: cannot create item 91/%d (CommonQuestItemInfo row missing?)", MIHNEA_TYPE);
		return "The Mihnea cannot be taken right now.";
	}

	// never create()d: the Mihnea has no DB row and lives only while the ritual runs
	m_pZone1F->registerObject(pItem);

	Inventory* pInventory = pPC->getInventory();
	TPOINT pt;
	bool bAdded = false;
	try
	{
		bAdded = pInventory->addItem(pItem, pt);
	}
	catch (Throwable&)
	{
		bAdded = false;
	}
	if (!bAdded)
	{
		SAFE_DELETE(pItem);
		return "You have no room in your inventory for the Mihnea.";
	}

	GCCreateItem gcCreateItem;
	makeGCCreateItem(&gcCreateItem, pItem, pt.x, pt.y);
	pPC->getPlayer()->sendPacket(&gcCreateItem);

	addCarrierEffect(pPC);

	m_StorageState = STORAGE_TAKEN;
	m_TakenTime = time(NULL);
	m_Carrier = pPC->getName();
	showArtifact(NULL);
	sealStorage();

	log("taken by %s", m_Carrier.c_str());
	announce(m_Carrier + " has taken the Mihnea from Mihnea's Storage. The Mihnea Altar opens in 5 minutes.");
	return "You take the Mihnea. You cannot attack and you move slowly while you carry it.";

	__END_CATCH
}

bool DraculaCastleManager::canPlaceHere(PlayerCreature* pPC)
	throw()
{
	MutexGuard guard(m_Mutex);
	if (!m_bInit || pPC == NULL || m_pAltar == NULL || pPC->getZone() != m_pZone1F) return false;
	if (m_StorageState != STORAGE_TAKEN || m_bAltarSealed) return false;
	int dx = (int)pPC->getX() - (int)m_pAltar->getX();
	int dy = (int)pPC->getY() - (int)m_pAltar->getY();
	return dx >= -3 && dx <= 3 && dy >= -3 && dy <= 3;
}

string DraculaCastleManager::placeMihnea(PlayerCreature* pPC, Item* pHandItem)
	throw(Error)
{
	__BEGIN_TRY

	MutexGuard guard(m_Mutex);

	if (!m_bInit || pPC == NULL || pPC->getZone() != m_pZone1F) return "";
	if (m_StorageState != STORAGE_TAKEN) return "";
	if (m_bAltarSealed) return "The cage around the Mihnea Altar has not opened yet.";

	Item* pItem = pHandItem != NULL ? pHandItem : takeFromInventory(pPC, true);
	if (pItem == NULL) return "You are not carrying the Mihnea.";
	SAFE_DELETE(pItem);
	removeCarrierEffect(pPC);

	string name = pPC->getName();
	m_Carrier = "";
	m_StorageState = STORAGE_SEALED;
	showArtifact(m_pAltar);			// floats on the open altar until the next opening / reset re-cages it
	sealStorage();

	log("placed by %s, door %s", name.c_str(), m_bDoorUp ? "breaks" : "was already down");
	if (m_bDoorUp)
	{
		breakDoor();
		announce(name + " has placed the Mihnea on the altar. The door to the 2nd floor of Dracula Castle breaks!");
	}
	else
	{
		announce(name + " has placed the Mihnea on the altar.");
	}
	return "You place the Mihnea on the altar.";

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// carrying
////////////////////////////////////////////////////////////////////////////////
void DraculaCastleManager::verifyCarrier()
	throw(Error)
{
	// The hooks (OnLogOut, transport, leaving 1F, death, morph, hand drop) are the real bookkeeping; this is the
	// backstop for whatever slips past them, so it is slow to conclude anything.
	Creature* pCreature = g_pPCFinder->getCreature(m_Carrier);
	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
	if (pPC == NULL)
	{
		if (++m_CarrierMisses < 30) return;
		m_CarrierMisses = 0;
		returnToStorage("carrier is offline");
		return;
	}
	Zone* pZone = pPC->getZone();
	if (pZone == NULL || !isCastleZone(pZone->getZoneID()))
	{
		m_CarrierMisses = 0;
		returnToStorage("carrier left the castle");
		return;
	}
	if (pZone != m_pZone1F)
	{
		// elsewhere in the castle: another zone thread owns that PC; the zone-change hook handles it
		m_CarrierMisses = 0;
		return;
	}
	Item* pItem = pPC->getInventory()->findItem(Item::ITEM_CLASS_COMMON_QUEST_ITEM, MIHNEA_TYPE);
	if (pItem == NULL && isMihnea(pPC->getExtraInventorySlotItem()))
		pItem = pPC->getExtraInventorySlotItem();		// on the mouse, halfway through a drag out of the bag
	if (pItem != NULL)
	{
		m_CarrierMisses = 0;
		return;
	}
	if (++m_CarrierMisses < 10) return;
	m_CarrierMisses = 0;
	removeCarrierEffect(pPC);
	returnToStorage("carrier no longer has it");
}

bool DraculaCastleManager::dropMihnea(Creature* pCreature, bool bSendPacket, const char* why)
	throw(Error)
{
	__BEGIN_TRY

	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
	if (pPC == NULL || !pPC->isFlag(Effect::EFFECT_CLASS_HAS_MIHNEA)) return false;

	MutexGuard guard(m_Mutex);

	Item* pItem = takeFromInventory(pPC, bSendPacket);
	removeCarrierEffect(pPC);
	if (m_Carrier == pPC->getName()) m_Carrier = "";

	Zone* pZone = pPC->getZone();
	if (pItem == NULL || pZone == NULL || !isCastleZone(pZone->getZoneID()))
	{
		SAFE_DELETE(pItem);
		log("drop by %s: nothing to put down", pPC->getName().c_str());
		return false;
	}

	// This runs inside death, logout, transport and morph handling, where the zone must not gain an
	// item yet (cf. Zone::addItemDelayed); the next heartbeat of the zone puts it on the floor.
	if (m_pPendingDrop != NULL) SAFE_DELETE(m_pPendingDrop);
	m_pPendingDrop = pItem;
	m_pPendingDropZone = pZone;
	m_PendingX = pPC->getX();
	m_PendingY = pPC->getY();

	log("%s: %s drops it at %d/%d in zone %d", why, pPC->getName().c_str(), m_PendingX, m_PendingY, pZone->getZoneID());
	return true;

	__END_CATCH
}

// Spec: logout or leaving the castle while holding the Mihnea sends it back to the storage. The item and the flag
// go now (they belong to the PC); the storage itself is reopened by the next 1F heartbeat, since this runs in
// the leaving player's thread.
void DraculaCastleManager::returnMihnea(Creature* pCreature, const char* why, bool bSendPacket)
	throw(Error)
{
	__BEGIN_TRY

	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
	if (pPC == NULL || !pPC->isFlag(Effect::EFFECT_CLASS_HAS_MIHNEA)) return;

	MutexGuard guard(m_Mutex);

	Item* pItem = takeFromInventory(pPC, bSendPacket);
	SAFE_DELETE(pItem);
	removeCarrierEffect(pPC);
	if (m_Carrier == pPC->getName()) m_Carrier = "";
	m_bPendingReturn = true;
	m_PendingReturnWhy = why;
	log("%s: %s gives it back", why, pPC->getName().c_str());

	__END_CATCH
}

void DraculaCastleManager::clearFloorEffect()
	throw()
{
	if (m_FloorEffectOID != 0 && m_pFloorZone != NULL)
		m_pFloorZone->deleteEffect(m_FloorEffectOID);
	m_FloorEffectOID = 0;
}

// Every Mihnea item and carrier flag off the PCs on 1F: a reset or a return must not leave ghost copies behind.
void DraculaCastleManager::purgeCarriers()
	throw(Error)
{
	if (m_pZone1F == NULL) return;
	const hash_map<ObjectID_t, Creature*>& pcs = m_pZone1F->getPCManager()->getCreatures();
	for (hash_map<ObjectID_t, Creature*>::const_iterator it = pcs.begin(); it != pcs.end(); ++it)
	{
		PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(it->second);
		if (pPC == NULL) continue;
		bool bHad = false;
		Item* pItem = takeFromInventory(pPC, true);
		while (pItem != NULL)
		{
			bHad = true;
			SAFE_DELETE(pItem);
			pItem = takeFromInventory(pPC, true);
		}
		if (pPC->isFlag(Effect::EFFECT_CLASS_HAS_MIHNEA))
		{
			removeCarrierEffect(pPC);
			bHad = true;
		}
		if (bHad) log("purged a Mihnea from %s", pPC->getName().c_str());
	}
}

void DraculaCastleManager::placePendingDrop(Zone* pZone, time_t now)
	throw(Error)
{
	Item* pItem = m_pPendingDrop;
	m_pPendingDrop = NULL;
	m_pPendingDropZone = NULL;

	TPOINT pt;
	try
	{
		pZone->registerObject(pItem);
		// the zone's own decay is only a backstop; checkFloor() removes it at FLOOR_TIMEOUT
		pt = pZone->addItem(pItem, m_PendingX, m_PendingY, true, FLOOR_TIMEOUT * 10 * 2);
	}
	catch (Throwable&)
	{
		SAFE_DELETE(pItem);
		returnToStorage("no floor for it");
		return;
	}

	m_pFloorZone = pZone;
	m_FloorItemOID = pItem->getObjectID();
	m_FloorX = pt.x;
	m_FloorY = pt.y;
	m_FloorSince = now;
	m_FloorEffectOID = addTileEffectIn(pZone, pt.x, pt.y, MIHNEA_STATUS, FOREVER_TURNS);
	log("on the floor at %d/%d in zone %d (object %u)", pt.x, pt.y, pZone->getZoneID(), m_FloorItemOID);
	announceZone(pZone, "The Mihnea lies on the floor. It returns to its storage in 10 minutes.");
}

void DraculaCastleManager::checkFloor(time_t now)
	throw(Error)
{
	Item* pItem = m_pFloorZone->getItem(m_FloorItemOID);
	if (pItem == NULL)
	{
		// picked up without the hook seeing it, or decayed
		clearFloorEffect();
		m_FloorItemOID = 0;
		m_pFloorZone = NULL;
		if (m_Carrier.empty()) returnToStorage("vanished from the floor");
		return;
	}

	if (now - m_FloorSince < FLOOR_TIMEOUT) return;

	removeFloorItem();
	returnToStorage("not picked up in time");
}

void DraculaCastleManager::removeFloorItem()
	throw(Error)
{
	if (m_pFloorZone == NULL || m_FloorItemOID == 0) return;

	Item* pItem = m_pFloorZone->getItem(m_FloorItemOID);
	if (pItem != NULL)
	{
		Tile& tile = m_pFloorZone->getTile(m_FloorX, m_FloorY);
		if (tile.hasItem() && tile.getItem() == pItem)
		{
			m_pFloorZone->deleteItem(pItem, m_FloorX, m_FloorY);

			GCDeleteObject gcDeleteObject;
			gcDeleteObject.setObjectID(m_FloorItemOID);
			m_pFloorZone->broadcastPacket(m_FloorX, m_FloorY, &gcDeleteObject);

			SAFE_DELETE(pItem);
		}
		else
		{
			log("floor item %u is not on %d/%d any more", m_FloorItemOID, m_FloorX, m_FloorY);
		}
	}
	clearFloorEffect();
	m_FloorItemOID = 0;
	m_pFloorZone = NULL;
}

void DraculaCastleManager::onMihneaPickedUp(PlayerCreature* pPC, Item* pItem)
	throw(Error)
{
	__BEGIN_TRY

	if (!isMihnea(pItem) || pPC == NULL) return;

	MutexGuard guard(m_Mutex);

	if (pItem->getObjectID() == m_FloorItemOID)
	{
		clearFloorEffect();
		m_FloorItemOID = 0;
		m_pFloorZone = NULL;
	}
	addCarrierEffect(pPC);
	m_Carrier = pPC->getName();
	if (m_StorageState != STORAGE_TAKEN)
	{
		// a copy that outlived a reset: it is the ritual's again
		m_StorageState = STORAGE_TAKEN;
		m_TakenTime = time(NULL);
	}
	log("picked up by %s", m_Carrier.c_str());

	__END_CATCH
}

void DraculaCastleManager::onMihneaDropped(PlayerCreature* pPC, Item* pItem, Zone* pZone, ZoneCoord_t x, ZoneCoord_t y)
	throw(Error)
{
	__BEGIN_TRY

	if (!isMihnea(pItem) || pPC == NULL || pZone == NULL) return;

	MutexGuard guard(m_Mutex);

	removeCarrierEffect(pPC);
	if (m_Carrier == pPC->getName()) m_Carrier = "";

	// the handler gave it the zone's default 3-minute decay; when it goes, checkFloor() sees it vanish
	m_pFloorZone = pZone;
	m_FloorItemOID = pItem->getObjectID();
	m_FloorX = x;
	m_FloorY = y;
	m_FloorSince = time(NULL);
	m_FloorEffectOID = addTileEffectIn(pZone, x, y, MIHNEA_STATUS, FOREVER_TURNS);
	log("put down by %s at %d/%d in zone %d", pPC->getName().c_str(), x, y, pZone->getZoneID());

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// helpers
////////////////////////////////////////////////////////////////////////////////
NPC* DraculaCastleManager::findNPC(NPCID_t npcID, const char* name)
	throw()
{
	if (m_pZone1F == NULL) return NULL;
	NPC* pNPC = dynamic_cast<NPC*>(m_pZone1F->getCreature(string(name)));
	if (pNPC != NULL && pNPC->getNPCID() != npcID)
	{
		log("NPC '%s' has NPCID %d, expected %d", name, pNPC->getNPCID(), npcID);
		return NULL;
	}
	return pNPC;
}

void DraculaCastleManager::setSeal(NPC* pNPC, bool bSealed)
	throw(Error)
{
	if (pNPC == NULL) return;

	Effect* pOld = pNPC->findEffect(Effect::EFFECT_CLASS_MIHNEA_SEAL);
	ObjectID_t& cageOID = (pNPC == m_pAltar) ? m_AltarCageOID : m_StorageCageOID;
	bool bHolds = (pNPC == m_pArtifactNPC);
	if (bSealed)
	{
		if (pOld != NULL) return;
		EffectMihneaSeal* pEffect = new EffectMihneaSeal(pNPC, pNPC == m_pAltar ? m_AltarSealStatus : m_SealStatus);
		pEffect->setDeadline(FOREVER_TURNS);
		pNPC->addEffect(pEffect);
		pEffect->affect();
		// the cage sprite draws the Mihnea itself, so the stand-alone artifact goes while the stand is caged
		if (bHolds && m_ArtifactOID != 0 && m_pZone1F != NULL)
		{
			m_pZone1F->deleteEffect(m_ArtifactOID);
			m_ArtifactOID = 0;
		}
		// the cage (with its shadow) is a held tile effect on the stand's tile
		if (cageOID != 0 && m_pZone1F != NULL) m_pZone1F->deleteEffect(cageOID);
		cageOID = addTileEffect(pNPC->getX(), pNPC->getY(), cageStatus(pNPC), FOREVER_TURNS);
	}
	else if (pOld != NULL)
	{
		if (cageOID != 0 && m_pZone1F != NULL)
		{
			m_pZone1F->deleteEffect(cageOID);
			cageOID = 0;
		}
		// Creature::deleteEffect() frees without unaffect(), so tell the clients first
		pOld->unaffect();
		pNPC->deleteEffect(Effect::EFFECT_CLASS_MIHNEA_SEAL);

		// the cage falling away (with its shadow), once, on the stand's tile
		// always the empty cage's collapse: the full one draws its own (lower) Mihnea, which then jumped to
		// the artifact's spot; the artifact appears at its final spot the moment the cage starts to fall
		addTileEffect(pNPC->getX(), pNPC->getY(), BREAK_EMPTY_STATUS, BREAK_TURNS);
		m_pCollapsing = pNPC;
		m_CollapseUntil = time(NULL) + COLLAPSE_SECONDS;
		if (bHolds && m_ArtifactOID == 0)
			m_ArtifactOID = addTileEffect(pNPC->getX(), pNPC->getY(), MIHNEA_STATUS, FOREVER_TURNS);
	}
}

// Pulls the Mihnea out of the inventory; the caller owns the returned item.
Item* DraculaCastleManager::takeFromInventory(PlayerCreature* pPC, bool bSendPacket)
	throw(Error)
{
	Inventory* pInventory = pPC->getInventory();
	if (pInventory == NULL) return NULL;

	Item* pItem = pInventory->findItem(Item::ITEM_CLASS_COMMON_QUEST_ITEM, MIHNEA_TYPE);
	if (pItem == NULL) return NULL;

	pInventory->deleteItem(pItem->getObjectID());
	if (bSendPacket)
	{
		GCDeleteInventoryItem gcDeleteInventoryItem;
		gcDeleteInventoryItem.setObjectID(pItem->getObjectID());
		pPC->getPlayer()->sendPacket(&gcDeleteInventoryItem);
	}
	return pItem;
}

void DraculaCastleManager::addCarrierEffect(PlayerCreature* pPC)
	throw(Error)
{
	if (pPC->isFlag(Effect::EFFECT_CLASS_HAS_MIHNEA)) return;
	EffectHasMihnea* pEffect = new EffectHasMihnea(pPC);
	pEffect->setDeadline(FOREVER_TURNS);
	pPC->addEffect(pEffect);
	pEffect->affect();
}

void DraculaCastleManager::removeCarrierEffect(Creature* pCreature)
	throw(Error)
{
	Effect* pEffect = pCreature->findEffect(Effect::EFFECT_CLASS_HAS_MIHNEA);
	if (pEffect == NULL)
	{
		pCreature->removeFlag(Effect::EFFECT_CLASS_HAS_MIHNEA);
		return;
	}
	pEffect->unaffect();
	pCreature->deleteEffect(Effect::EFFECT_CLASS_HAS_MIHNEA);
}

void DraculaCastleManager::announce(const string& message)
	throw()
{
	GCSystemMessage gcSystemMessage;
	gcSystemMessage.setType(SYSTEM_MESSAGE_MASTER_LAIR);
	gcSystemMessage.setMessage(message);
	g_pZoneGroupManager->pushBroadcastPacket(&gcSystemMessage);
}

void DraculaCastleManager::announceZone(Zone* pZone, const string& message)
	throw()
{
	GCSystemMessage gcSystemMessage;
	gcSystemMessage.setType(SYSTEM_MESSAGE_MASTER_LAIR);
	gcSystemMessage.setMessage(message);
	pZone->broadcastPacket(&gcSystemMessage);
}

const char* DraculaCastleManager::stateName() const
	throw()
{
	switch (m_StorageState)
	{
		case STORAGE_SEALED: return "sealed";
		case STORAGE_OPEN:   return "open";
		case STORAGE_TAKEN:  return "taken";
	}
	return "?";
}

////////////////////////////////////////////////////////////////////////////////
// GM
////////////////////////////////////////////////////////////////////////////////
string DraculaCastleManager::forceOpen()
	throw()
{
	MutexGuard guard(m_Mutex);
	if (!m_bInit) return "Dracula Castle 1F (zone 6051) has not started yet.";
	m_bPendingOpen = true;
	return "Mihnea's Storage opens within 1 s (ritual reset first).";
}

string DraculaCastleManager::forceReset()
	throw()
{
	MutexGuard guard(m_Mutex);
	if (!m_bInit) return "Dracula Castle 1F (zone 6051) has not started yet.";
	m_bPendingReset = true;
	return "Mihnea ritual reset within 1 s.";
}

string DraculaCastleManager::forceDoor(const string& how)
	throw()
{
	MutexGuard guard(m_Mutex);
	if (!m_bInit) return "Dracula Castle 1F (zone 6051) has not started yet.";
	if (how == "up" || how == "raise")
		m_PendingDoor = 1;
	else if (how == "down" || how == "break")
		m_PendingDoor = 2;
	else
		m_PendingDoor = m_bDoorUp ? 2 : 1;
	return m_PendingDoor == 1 ? "2F door rises within 1 s." : "2F door breaks within 1 s.";
}

string DraculaCastleManager::forceDoorAt(int x, int y)
	throw()
{
	MutexGuard guard(m_Mutex);
	if (!m_bInit) return "Dracula Castle 1F (zone 6051) has not started yet.";
	if (x < 0 || y < 0 || x > 255 || y > 255) return "dracDoorAt needs two tile coordinates, e.g. dracDoorAt 200 42";
	m_PendingDoorX = x;
	m_PendingDoorY = y;
	char buf[160];
	snprintf(buf, sizeof(buf), "Door anchor -> %d/%d (within 1 s).", x, y);
	return buf;
}

string DraculaCastleManager::forceSeal(int status, int altarStatus)
	throw()
{
	MutexGuard guard(m_Mutex);
	if (!m_bInit) return "Dracula Castle 1F (zone 6051) has not started yet.";
	if (status < 0 || status > 1019 || altarStatus > 1019)
		return "dracSeal needs client effect statuses 0-1019: dracSeal <storage> [<altar>], e.g. dracSeal 1016 1018";
	m_PendingSeal = status;
	m_PendingAltarSeal = altarStatus;
	char buf[128];
	snprintf(buf, sizeof(buf), "Seal statuses -> %d / %d (within 1 s).", status, altarStatus);
	return buf;
}

string DraculaCastleManager::toString() const
	throw()
{
	MutexGuard guard(m_Mutex);

	if (!m_bInit) return "Dracula Castle: 1F (zone 6051) has not started yet.";

	char buf[160];
	const char* where = "in the storage";
	if (!m_Carrier.empty()) where = "carried";
	else if (m_pArtifactNPC == m_pAltar && m_pAltar != NULL) where = "on the altar";
	else if (m_pPendingDrop != NULL || m_FloorItemOID != 0) where = "on the floor";
	snprintf(buf, sizeof(buf), "Drac: storage %s, altar %s, Mihnea %s, door %s %d/%d, next %s%s",
		stateName(), m_bAltarSealed ? "caged" : "open", where, m_bDoorUp ? "up" : "down", m_DoorTileX, m_DoorTileY,
		clock(m_NextOpenTime).c_str(), (m_pStorage == NULL || m_pAltar == NULL) ? " (NPC MISSING)" : "");
	return buf;
}
