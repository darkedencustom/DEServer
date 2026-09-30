//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectMihneaSeal.h
// Description : The barrier on Mihnea's Storage and the Mihnea Altar. The
//               client is shown status 1019, a row appended to its
//               effectstatus.inf for this (the last index under its
//               EFFECTSTATUS_MAX of 1020). Menegroth's altar seal 570 was
//               tried first, but its sprite is a 140-px sealed-altar overlay
//               that hides the stand completely. The client no longer refuses
//               the dialogue on its own; takeMihnea()/placeMihnea() do.
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_MIHNEA_SEAL__
#define __EFFECT_MIHNEA_SEAL__

#include "Effect.h"

class EffectMihneaSeal : public Effect
{
public:
	enum { SEND_STATUS = 1016 };	// default client row (storage cage); DraculaCastleManager passes the real one

	// sendStatus: the client status row to show; DraculaCastleManager lets a GM try others (*command dracSeal N)
	EffectMihneaSeal(Creature* pCreature, EffectID_t sendStatus = SEND_STATUS) throw(Error);

public:
	EffectClass getEffectClass() const throw() { return EFFECT_CLASS_MIHNEA_SEAL; }
	EffectClass getSendEffectClass() const throw() { return (EffectClass)m_SendStatus; }

	void affect() throw(Error);
	void affect(Creature* pCreature) throw(Error);
	void unaffect() throw(Error);
	void unaffect(Creature* pCreature) throw(Error);

	string toString() const throw() { return "EffectMihneaSeal"; }

private:
	EffectID_t	m_SendStatus;
};

#endif
