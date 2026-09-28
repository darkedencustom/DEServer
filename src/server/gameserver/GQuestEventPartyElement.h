#ifndef __GQUEST_EVENT_PARTY_ELEMENT_H__
#define __GQUEST_EVENT_PARTY_ELEMENT_H__

#include "GQuestElement.h"
#include "GQuestStatus.h"
#include "GQuestMissionState.h"

class GQuestEventPartyMission : public GQuestMission
{
public:
	GQuestEventPartyMission() : m_bMet(false) { }

	bool	isMet() const { return m_bMet; }
	void	meet() { m_bMet = true; }

	string	getMissionName() const { return "EventPartyMission"; }
	string	saveState() const { return GQuestMissionState::fromBool(m_bMet); }
	void	loadState(const string& s) { m_bMet = GQuestMissionState::toBool(s); }
private:
	bool	m_bMet;
};

class GQuestEventPartyElement : public GQuestElement
{
public:
	GQuestEventPartyElement() : m_Target(0) { }
	string 				getElementName() const { return "EventParty"; }
	GQuestManager::EventTypes	getEventType() const { return GQuestManager::EVENT_PARTY; }

	ResultType	 		checkCondition( PlayerCreature* pPC ) const;
	ResultType			checkMission(GQuestMission* pStatus) const;

	GQuestMission*		makeInitMission(PlayerCreature* pPC) const;
	GQuestEventPartyElement*	makeElement(XMLTree* pTree);

	NPCID_t getTarget() const { return m_Target; }

private:
	NPCID_t	m_Target;
};

extern GQuestEventPartyElement g_EventPartyElement;

#endif
