//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectMihneaDoor.h
// Description : The door on Dracula Castle 1F that blocks the stairs to 2F,
//               as a tile effect: while it sits on its tile the zone re-sends
//               it to every player who comes into view (isBroadcastingEffect)
//               with the client status row for the standing door. The stair
//               tiles themselves are blocked by DraculaCastleManager.
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_MIHNEA_DOOR__
#define __EFFECT_MIHNEA_DOOR__

#include "Effect.h"

class Zone;

class EffectMihneaDoor : public Effect
{
public:
	EffectMihneaDoor(Zone* pZone, ZoneCoord_t x, ZoneCoord_t y, EffectID_t sendStatus) throw(Error);

public:
	EffectClass getEffectClass() const throw() { return EFFECT_CLASS_MIHNEA_DOOR; }
	EffectClass getSendEffectClass() const throw() { return (EffectClass)m_SendStatus; }

	void affect() throw(Error);
	void unaffect() throw(Error);

	string toString() const throw() { return "EffectMihneaDoor"; }

private:
	EffectID_t	m_SendStatus;
};

#endif
