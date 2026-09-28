#ifndef __GQUEST_ENTER_DYNAMIC_ZONE_ELEMENT_H__
#define __GQUEST_ENTER_DYNAMIC_ZONE_ELEMENT_H__

#include "GQuestElement.h"
#include "GQuestStatus.h"
#include "GQuestMissionState.h"

class GQuestEnterDynamicZoneMission : public GQuestMission
{
public:
	GQuestEnterDynamicZoneMission(ZoneID_t targetZoneID) : m_bEnter(false), m_TargetZoneID(targetZoneID) { }

	bool	isEnter() const { return m_bEnter; }
	void	enter(ZoneID_t zoneID) { if ( m_TargetZoneID == zoneID ) m_bEnter = true; }

	string	getMissionName() const { return "EnterDynamicZoneMission"; }
	string	saveState() const { return GQuestMissionState::fromBool(m_bEnter); }
	void	loadState(const string& s) { m_bEnter = GQuestMissionState::toBool(s); }
private:
	bool	m_bEnter;
	ZoneID_t	m_TargetZoneID;
};

class GQuestEnterDynamicZoneElement : public GQuestElement
{
public:
	GQuestEnterDynamicZoneElement() : m_bAutoEnter(false) { }
	string 				getElementName() const { return "EnterDynamicZone"; }
	GQuestManager::EventTypes	getEventType() const { return GQuestManager::ENTER_DYNAMIC_ZONE; }

	ResultType			checkMission(GQuestMission* pStatus) const;

	GQuestMission*		makeInitMission(PlayerCreature* pPC) const;
	GQuestEnterDynamicZoneElement*	makeElement(XMLTree* pTree);

private:
	bool		m_bAutoEnter;
	ZoneID_t	m_TargetZoneID;
};

extern GQuestEnterDynamicZoneElement g_EnterDynamicZoneElement;

#endif
