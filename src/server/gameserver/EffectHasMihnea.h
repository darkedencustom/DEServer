//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectHasMihnea.h
// Description : Carrying the Mihnea from Dracula Castle. Server-side flag
//               only; the client is shown HAS_SWEEPER, which is what halves
//               its own movement and draws the "carrying" icon.
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_HAS_MIHNEA__
#define __EFFECT_HAS_MIHNEA__

#include "Effect.h"

class EffectHasMihnea : public Effect
{
public:
	EffectHasMihnea(Creature* pCreature) throw(Error);

public:
	EffectClass getEffectClass() const throw() { return EFFECT_CLASS_HAS_MIHNEA; }
	enum { SEND_STATUS = 1028 };	// client row: the Mihnea drawn above the bearer (EFFECTSTATUS_HAS_MIHNEA)
	EffectClass getSendEffectClass() const throw() { return (EffectClass)SEND_STATUS; }

	void affect() throw(Error);
	void affect(Creature* pCreature) throw(Error);
	void unaffect() throw(Error);
	void unaffect(Creature* pCreature) throw(Error);

	string toString() const throw() { return "EffectHasMihnea"; }
};

#endif
