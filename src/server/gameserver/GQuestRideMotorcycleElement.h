#ifndef __GQUEST_RIDE_MOTORCYCLE_ELEMENT_H__
#define __GQUEST_RIDE_MOTORCYCLE_ELEMENT_H__

#include "GQuestElement.h"
#include "GQuestStatus.h"
#include "GQuestMissionState.h"

class GQuestRideMotorcycleMission : public GQuestMission
{
public:
	GQuestRideMotorcycleMission() : m_bRide(false) { }

	bool	isRide() const { return m_bRide; }
	void	ride() { m_bRide = true; }

	string	getMissionName() const { return "RideMotorcycleMission"; }
	string	saveState() const { return GQuestMissionState::fromBool(m_bRide); }
	void	loadState(const string& s) { m_bRide = GQuestMissionState::toBool(s); }
private:
	bool	m_bRide;
};

class GQuestRideMotorcycleElement : public GQuestElement
{
public:
	GQuestRideMotorcycleElement() { }
	string 				getElementName() const { return "RideMotorcycle"; }
	GQuestManager::EventTypes	getEventType() const { return GQuestManager::RIDE_MOTORCYCLE; }

	ResultType			checkMission(GQuestMission* pStatus) const;

	GQuestMission*		makeInitMission(PlayerCreature* pPC) const;
	GQuestRideMotorcycleElement*	makeElement(XMLTree* pTree);

private:
};

extern GQuestRideMotorcycleElement g_RideMotorcycleElement;

#endif
