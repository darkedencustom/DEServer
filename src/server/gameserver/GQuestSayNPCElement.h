#ifndef __GQUEST_SAY_NPC_ELEMENT_H__
#define __GQUEST_SAY_NPC_ELEMENT_H__

#include "GQuestElement.h"
#include "GQuestStatus.h"
#include "GQuestMissionState.h"

class GQuestSayNPCMission : public GQuestMission
{
public:
	GQuestSayNPCMission() : m_bMet(false) { }

	bool	isMet() const { return m_bMet; }
	void	meet() { m_bMet = true; }

	string	getMissionName() const { return "SayNPCMission"; }
	string	saveState() const { return GQuestMissionState::fromBool(m_bMet); }
	void	loadState(const string& s) { m_bMet = GQuestMissionState::toBool(s); }
private:
	bool	m_bMet;
};

class GQuestSayNPCElement : public GQuestElement
{
public:
	GQuestSayNPCElement() : m_Target(0), m_Volume(0) { }
	string 				getElementName() const { return "SayNPC"; }
	GQuestManager::EventTypes	getEventType() const { return GQuestManager::MEETNPC; }

	ResultType			checkMission(GQuestMission* pStatus) const;
	bool				checkVolume( PlayerCreature* pPC ) const;

	GQuestMission*		makeInitMission(PlayerCreature* pPC) const;
	GQuestSayNPCElement*	makeElement(XMLTree* pTree);

	NPCID_t getTarget() const { return m_Target; }

private:
	NPCID_t			m_Target;
	VolumeType_t	m_Volume;
};

extern GQuestSayNPCElement g_SayNPCElement;

#endif
