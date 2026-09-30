//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectMihneaDoor.cpp
//////////////////////////////////////////////////////////////////////////////

#include "EffectMihneaDoor.h"
#include "Zone.h"
#include "Tile.h"
#include "Gpackets/GCAddEffectToTile.h"
#include "Gpackets/GCDeleteEffectFromTile.h"

EffectMihneaDoor::EffectMihneaDoor(Zone* pZone, ZoneCoord_t x, ZoneCoord_t y, EffectID_t sendStatus)
	throw(Error)
	: m_SendStatus(sendStatus)
{
	__BEGIN_TRY
	setTarget(NULL);
	m_pZone = pZone;
	m_X = x;
	m_Y = y;
	__END_CATCH
}

void EffectMihneaDoor::affect()
	throw(Error)
{
	__BEGIN_TRY
	// Everyone in view now; the zone's view code re-sends it to anyone who arrives later.
	GCAddEffectToTile gcAET;
	gcAET.setObjectID(getObjectID());
	gcAET.setXY(m_X, m_Y);
	gcAET.setEffectID(getSendEffectClass());
	gcAET.setDuration(getRemainDuration());
	m_pZone->broadcastPacket(m_X, m_Y, &gcAET);
	__END_CATCH
}

void EffectMihneaDoor::unaffect()
	throw(Error)
{
	__BEGIN_TRY
	// added with Tile::addObject (not addEffect, which refuses the portal tile the door sits on)
	try
	{
		m_pZone->getTile(m_X, m_Y).deleteObject(m_ObjectID);
	}
	catch (Throwable&)
	{
	}

	GCDeleteEffectFromTile gcDET;
	gcDET.setObjectID(getObjectID());
	gcDET.setXY(m_X, m_Y);
	gcDET.setEffectID(getSendEffectClass());
	m_pZone->broadcastPacket(m_X, m_Y, &gcDET);
	__END_CATCH
}
