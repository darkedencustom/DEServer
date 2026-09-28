#ifndef __GQUEST_TRAVEL_ELEMENT_H__
#define __GQUEST_TRAVEL_ELEMENT_H__

#include "GQuestElement.h"
#include "GQuestStatus.h"
#include "GQuestMissionState.h"
#include <vector>
#include <list>
#include <algorithm>

class GQuestTravelMission : public GQuestMission
{
public:
	GQuestTravelMission() { }
	DWORD	getCurrent() const { return m_NumArg; }
	void	increase() { m_NumArg++; }

	bool	isTarget(DWORD target) { return find(m_TargetList.begin(), m_TargetList.end(), target) != m_TargetList.end(); }
	bool	isVisited(DWORD target) { return find(m_VisitedList.begin(), m_VisitedList.end(), target) != m_VisitedList.end(); }

	string	getMissionName() const { return "TravelMission"; }
	string	saveState() const { return GQuestMissionState::fromList(m_TargetList) + ";" + GQuestMissionState::fromList(m_VisitedList); }
	void	loadState(const string& s) { string a, b; GQuestMissionState::split2(s, a, b); GQuestMissionState::toList(a, m_TargetList); GQuestMissionState::toList(b, m_VisitedList); }
	void	updateStr();

	vector<DWORD>&	getTargetList() { return m_TargetList; }
	vector<DWORD>&	getVisitedList() { return m_VisitedList; }
private:
	vector<DWORD>	m_TargetList;
	vector<DWORD>	m_VisitedList;
};

class GQuestTravelElement : public GQuestElement
{
public:
	GQuestTravelElement() : m_Grade(0) { }
	string 						getElementName() const { return "Travel"; }
	GQuestManager::EventTypes	getEventType() const { return GQuestManager::TRAVEL; }

	ResultType			checkMission(GQuestMission* pStatus) const;

	GQuestMission*		makeInitMission(PlayerCreature* pPC) const;
	GQuestTravelElement*	makeElement(XMLTree* pTree);

	DWORD	getGrade() const { return m_Grade; }
	DWORD	getBaseNum() const { return m_BaseNum; }

private:
	DWORD					m_Grade;
	DWORD					m_BaseNum;
};

extern GQuestTravelElement g_TravelElement;

#endif
