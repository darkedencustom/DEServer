#ifndef __GQUEST_STATUS_H__
#define __GQUEST_STATUS_H__

#include "Types.h"
#include "QuestStatusInfo.h"
#include "GQuestInfo.h"
#include "GQuestElement.h"

#include <list>
#include <map>

class GQuestMission : public MissionInfo
{
public:
	virtual ~GQuestMission() { }
	vector<GQuestElement*>::const_iterator m_Position;
	GQuestStatus*	m_pParent;
	virtual string	getMissionName() const = 0;

	// Element-specific progress that m_NumArg/m_StrArg do not carry (kill targets, flags, counters).
	// Written to GQuestMissionSave.State and read back on login; see GQuestMissionState.h.
	virtual string	saveState() const { return ""; }
	virtual void	loadState(const string& state) { }
};

class GQuestStatus : public QuestStatusInfo
{
public:
	GQuestStatus(PlayerCreature* pOwner, DWORD QuestID) : QuestStatusInfo(QuestID), m_pOwner(pOwner), m_pGQuestInfo(NULL) { }
	GQuestStatus(PlayerCreature* pOwner, GQuestInfo* pGQuestInfo) : QuestStatusInfo(pGQuestInfo->getQuestID()), m_pOwner(pOwner), m_pGQuestInfo(pGQuestInfo) { }
	~GQuestStatus();

	BYTE	getStatus() const { return m_Status; }
	void	setStatus(BYTE status) { m_Status = status; }

	void	initMissions();
	BYTE	checkMissions();
	void	update();

	GQuestElement::ResultType	checkElements(GQuestInfo::ElementType);
	GQuestElement::ResultType	checkElementsSEQ(GQuestInfo::ElementType);
	GQuestElement::ResultType	checkElementsOR(GQuestInfo::ElementType);
	GQuestElement::ResultType	checkElementsAND(GQuestInfo::ElementType);

	void	cleanUpMissions();
	void	save() throw(Error);

	// In-progress persistence (KAN-13). A DOING/SUCCESS quest keeps its GQuestSave row and one
	// GQuestMissionSave row per mission; anything else clears the mission rows.
	void	persist() throw(Error);
	void	saveMissions() throw(Error);
	void	deleteMissions() throw(Error);
	bool	restoreMission(BYTE cond, WORD position, BYTE status, DWORD numArg, const string& strArg, const string& state);
	void	finishRestore();

	GQuestInfo*	getGQuestInfo() const { return m_pGQuestInfo; }

private:
	PlayerCreature*	m_pOwner;
	GQuestInfo*	m_pGQuestInfo;
	vector<GQuestElement*>::const_iterator	m_ElementAdvance[GQuestInfo::MAX];
	map<vector<GQuestElement*>::const_iterator, GQuestMission*>	m_MissionMap;
};

#endif
