//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionPlaceMihnea.h
// Description : Trigger action "PlaceMihnea": the player answered the Mihnea
//               Altar and places the Mihnea if the cage is down, which breaks
//               the door to the 2nd floor. No properties.
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_PLACE_MIHNEA_H__
#define __ACTION_PLACE_MIHNEA_H__

#include "Action.h"
#include "ActionFactory.h"

class ActionPlaceMihnea : public Action
{
public:
	ActionPlaceMihnea() throw(Error) {}
	virtual ~ActionPlaceMihnea() throw(Error) {}

	virtual ActionType_t getActionType() const throw() { return ACTION_PLACE_MIHNEA; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error) {}
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw() { return "ActionPlaceMihnea()"; }
};

class ActionPlaceMihneaFactory : public ActionFactory
{
public:
	virtual ActionType_t getActionType() const throw() { return Action::ACTION_PLACE_MIHNEA; }
	virtual string getActionName() const throw() { return "PlaceMihnea"; }
	virtual Action* createAction() const throw() { return new ActionPlaceMihnea(); }
};

#endif
