//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectHasMihnea.cpp
//////////////////////////////////////////////////////////////////////////////

#include "EffectHasMihnea.h"
#include "Creature.h"
#include "Zone.h"
#include "Gpackets/GCAddEffect.h"
#include "Gpackets/GCRemoveEffect.h"

EffectHasMihnea::EffectHasMihnea(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	setTarget(pCreature);
	__END_CATCH
}

void EffectHasMihnea::affect()
	throw(Error)
{
	__BEGIN_TRY
	Creature* pCreature = dynamic_cast<Creature*>(m_pTarget);
	Assert(pCreature != NULL);
	affect(pCreature);
	__END_CATCH
}

void EffectHasMihnea::affect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	pCreature->setFlag(getEffectClass());

	Zone* pZone = pCreature->getZone();
	if (pZone == NULL) return;

	GCAddEffect gcAddEffect;
	gcAddEffect.setObjectID(pCreature->getObjectID());
	gcAddEffect.setEffectID(getSendEffectClass());
	gcAddEffect.setDuration(65000);
	pZone->broadcastPacket(pCreature->getX(), pCreature->getY(), &gcAddEffect);
	__END_CATCH
}

void EffectHasMihnea::unaffect()
	throw(Error)
{
	__BEGIN_TRY
	Creature* pCreature = dynamic_cast<Creature*>(m_pTarget);
	Assert(pCreature != NULL);
	unaffect(pCreature);
	__END_CATCH
}

void EffectHasMihnea::unaffect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	pCreature->removeFlag(getEffectClass());

	Zone* pZone = pCreature->getZone();
	if (pZone == NULL) return;

	GCRemoveEffect gcRemoveEffect;
	gcRemoveEffect.setObjectID(pCreature->getObjectID());
	gcRemoveEffect.addEffectList(getSendEffectClass());
	pZone->broadcastPacket(pCreature->getX(), pCreature->getY(), &gcRemoveEffect);
	__END_CATCH
}
