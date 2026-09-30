//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionTakeMihnea.h
// Description : Trigger action "TakeMihnea": the player answered Mihnea's
//               Storage and takes the Mihnea if the seal is down. No
//               properties. Everything is decided by DraculaCastleManager.
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_TAKE_MIHNEA_H__
#define __ACTION_TAKE_MIHNEA_H__

#include "Action.h"
#include "ActionFactory.h"

class ActionTakeMihnea : public Action
{
public:
	ActionTakeMihnea() throw(Error) {}
	virtual ~ActionTakeMihnea() throw(Error) {}

	virtual ActionType_t getActionType() const throw() { return ACTION_TAKE_MIHNEA; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error) {}
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw() { return "ActionTakeMihnea()"; }
};

class ActionTakeMihneaFactory : public ActionFactory
{
public:
	virtual ActionType_t getActionType() const throw() { return Action::ACTION_TAKE_MIHNEA; }
	virtual string getActionName() const throw() { return "TakeMihnea"; }
	virtual Action* createAction() const throw() { return new ActionTakeMihnea(); }
};

#endif
