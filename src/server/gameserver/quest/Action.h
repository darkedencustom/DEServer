//////////////////////////////////////////////////////////////////////////////
// Filename    : Action.h
// Written By  : 
// Description :
// Ʈ������ ������ ������ ��� ����Ǿ�� �ϴ� �׼��� ��Ÿ���� Ŭ����
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_H__
#define __ACTION_H__

#include "Types.h"
#include "Exception.h"
#include "PropertyBuffer.h"

//////////////////////////////////////////////////////////////////////////////
// class Action
//////////////////////////////////////////////////////////////////////////////

class Creature;

class Action 
{
public:

	enum ActionTypes 
	{
		ACTION_SET_POSITION,             // ��ġ�� �����Ѵ�.
		ACTION_WANDER,                   // ���� ������ ��Ȳ�Ѵ�.
		ACTION_SAY,                      // ���� ��ũ��Ʈ�� ���Ѵ�.
		ACTION_RANDOM_SAY,               // ���� ��ũ��Ʈ�� ��ε�ĳ�����Ѵ�.
		ACTION_ASK,                      // �÷��̾�� ������ �Ѵ�.
		ACTION_QUIT_DIALOGUE,            // Ŭ���̾�Ʈ�� �Ͽ��� ��ȭâ�� �ݰ� �Ѵ�.
		ACTION_PREPARE_SHOP,             // ������ �غ��Ѵ�.
		ACTION_SELL,                     // �÷��̾�� �������� �Ǵ�.
		ACTION_BUY,                      // �÷��̾�κ��� ������ ����δ�.
		ACTION_REGEN_SHOP,               // ���� �ȿ� �ִ� �������� �������Ѵ�.
		ACTION_PREPARE_TEACH,            // ����� ����ĥ �غ� �Ѵ�.
		ACTION_TEACH_SKILL,              // �÷��̾�� ����� �������ش�.
		ACTION_HEAL,                     // �÷��̾ ġ�����ش�.
		ACTION_REDEEM_MOTORCYCLE,        // ���ͻ���Ŭ�� ��ȯ���ش�.
		ACTION_SEARCH_MOTORCYCLE,        // �÷��̾��� ������� ��ġ�� �����ش�.
		ACTION_REPAIR,                   // �÷��̾��� �������� �������ش�.
		ACTION_STASH_SELL,               // ������ ��� �������̽��� ������ �Ѵ�.
		ACTION_STASH_OPEN,               // ������ �������̽��� ������ �Ѵ�.
		ACTION_RESTORE,                  // �����̾ �����̾�� ��ȯ�� �ش�.
		ACTION_SET_RESURRECT_ZONE,       // ��Ȱ ��ġ�� �����Ѵ�.
		ACTION_SILVER_COATING,           // �����ۿ��� �� ������ ���ش�.
		ACTION_CREATE_GUILD,             // ��� ���� �������̽��� ���� �Ѵ�.
		ACTION_DESTROY_GUILD,            // ��� ��ü �������̽��� ���� �Ѵ�.
		ACTION_TUTORIAL,                 // Ʃ�丮�� �������̽��� ���� �Ѵ�.
		ACTION_GIVE_NEWBIE_ITEM,         // �ʺ��ڿ� ������ ���� �������̽��� ���� �Ѵ�.
		ACTION_ACTIVATE_PORTAL,          // ��Ż�� �۵���Ų��.
		ACTION_TURN_ON_FLAG,             // �÷��׸� �Ѱ� �����Ѵ�.
		ACTION_TURN_OFF_FLAG,            // �÷��׸� ���� �����Ѵ�.
		ACTION_SYSTEM_MESSAGE,           // �ý��� �޽����� ������.
		ACTION_TAKE_DONATION,            // ��θ� �޴´�.
		ACTION_CALL_HELICOPTER,          // ��� �������̽��� ���� �Ѵ�.
		ACTION_REGEN_EVENT_SHOP,         // �̺�Ʈ�� ������ �����Ѵ�.
		ACTION_SAY_DYNAMIC,              // ���� ��ũ��Ʈ�� ���Ѵ�.
		ACTION_ASK_DYNAMIC,              // �÷��̾�� ������ �Ѵ�.
		ACTION_GIVE_SPECIAL_EVENT_ITEM,  // 
		ACTION_REDISTRIBUTE_ATTR,        // 
		ACTION_GIVE_GARBAGE_ITEM,        // ������ �������� �ش�.

		//ACTION_TALK ,
		//ACTION_RANDOM_TALK ,
		//ACTION_GIVE ,
		//ACTION_TAKE ,
		//ACTION_DROP ,
		//ACTION_CREATE_ITEM ,
		//ACTION_DESTROY_ITEM ,
		//ACTION_SET_ATTRIBUTE ,
		//ACTION_SET_DISCOUNT_RATE ,
		//ACTION_DIE ,
		//ACTION_USE_SKILL ,
		//ACTION_USE_ITEM ,
		//ACTION_REMOVE_QUEST ,
		//ACTION_AFTER ,

		// Monster AI specific actions
		ACTION_ATTACK ,	
		ACTION_RETREAT ,	
		ACTION_MOVE ,
		ACTION_ATTACK_MOVE ,	
		ACTION_STOP ,
		ACTION_HOLD_POSITION ,
		ACTION_PATROL ,

		ACTION_TRADE_EVENT_ITEM,
		ACTION_SHOW_GUILD_DIALOG,

		ACTION_TRADE_LAIR_ITEM,

		ACTION_SIMPLE_QUEST_LIST,
		ACTION_SIMPLE_QUEST_COMPLETE,
		ACTION_SIMPLE_QUEST_REGEN,

		ACTION_TRADE_GIFT_BOX,

		ACTION_GIVE_TEST_SERVER_REWARD,

		// ���� ���� Action
		// 2003. 1.20. by bezz,Sequoia
		ACTION_ENTER_CASTLE_WITH_FEE,

		// ���� �׿��ִ� ������ �ܾ��� �����ش�.
		ACTION_SHOW_TAX_BALANCE,

		ACTION_ASK_VARIABLE,

		// ���� ��û ���� �׼ǵ�
		ACTION_WAR_REGISTRATION,
		ACTION_SHOW_WAR_SCHEDULE,

		// ���� ���� ��û
		ACTION_JOIN_RACE_WAR,

		// �̺�Ʈ ���� ������
		ACTION_GIVE_EVENT_ITEM,				// ĳ������ �� ��
		ACTION_GIVE_ACCOUNT_EVENT_ITEM,		// �������� �� ��

		// Ŀ�� �Ŵ��� ���� �ʱ�ȭ �׼�
		ACTION_INIT_PARTNER_WAITING_MANAGER,
		ACTION_WAIT_FOR_MEET_COUPLE,
		ACTION_WAIT_FOR_APART_COUPLE,
		ACTION_ACCEPT_COUPLE_REQUEST,
		ACTION_ACCEPT_APART_COUPLE,

		ACTION_FORCE_APART_COUPLE,

		ACTION_ENTER_PK_ZONE,
		ACTION_WARP_TO_RESURRECT_POSITION,

		ACTION_SELECT_QUEST,
		ACTION_QUEST_REWARD,

		ACTION_WARP_TO_NOVICE_ZONE,
		ACTION_CANCEL_QUEST,

		ACTION_INIT_SIMPLE_QUEST,
		ACTION_WANDER_ZONE,

		ACTION_INIT_EVENT_QUEST,
		ACTION_ASK_BY_QUEST_LEVEL,
		ACTION_GIVE_EVENT_QUEST,
		ACTION_ADVANCE_EVENT_QUEST,
		ACTION_REWARD_EVENT_QUEST,
		ACTION_CANCEL_EVENT_QUEST_SCRIPT,
		ACTION_GIVE_LOTTO,
		ACTION_GIVE_EVENT_QUEST_SCRIPT,
		ACTION_START_EVENT_QUEST,
		ACTION_WARP_IN_ZONE,
		ACTION_EVENT_MEET,
		ACTION_GIVE_FINAL_LOTTO_SCRIPT,
		ACTION_GIVE_QUEST_ITEM,
		ACTION_TAKE_OUT_GOODS,
		ACTION_CLEAR_RANK_BONUS,
		ACTION_CONTRACT_GNOMES_HORN,
		ACTION_DOWN_SKILL,
		ACTION_MINI_GAME,
		ACTION_GIVE_ITEM,
		ACTION_ACTIVATE_MAZE_EXIT,
		ACTION_ACTIVATE_MAZE_ENTER,
		ACTION_ACTIVATE_MAZE_RETURN,

		ACTION_SYSTEM_MESSAGE_PER_RACE,           // �ý��� �޽����� ������.

		ACTION_WARP_LEVEL_WAR_ZONE,

		ACTION_CHECK_PARTNER_NAME,				// ��Ʈ�� �̸� Ȯ��

		ACTION_START_PET_QUEST,					// 2�� �� ����Ʈ�� �����Ѵ�.

		ACTION_PET_WITHDRAW,					// �� ã������
		ACTION_PET_DEPOSIT,						// �� �ñ淡��

		ACTION_ENTER_EVENT_ZONE,				// �̺�Ʈ ������ ������.
		ACTION_ENTER_GDR_LAIR,					// �Ϸ����� ���̿��� ���巹 ����� ����

		ACTION_TRADE_GQUEST_EVENT_ITEM,			// �̺�Ʈ ����Ʈ ������

		ACTION_ENTER_SIEGE,						// ������ ����(���� �������� �̵�)

		ACTION_REGISTER_SIEGE,					// ���� ��û
		ACTION_REGISTER_REINFORCE,				// ������ ���� ��û
		ACTION_ACCEPT_REINFORCE,				// ������ ���� ��û ����
		ACTION_DENY_REINFORCE,					// ������ ���� ��û �ź�

		ACTION_RECALL_SIEGE,					// �������� ���� ��������
		ACTION_SELECT_BLOOD_BIBLE,				// ���� ���� �뿩
		ACTION_CLEAR_BLOOD_BIBLE,				// ���� ���� ����

		ACTION_MODIFY_TAX_RATIO,				// ���� ����
		ACTION_SWAP_ADVANCEMENT_ITEM,			// ���� ������ ��ȯ

		ACTION_SHOW_DONATION_DIALOG,			// ���â �����ֱ�
		ACTION_ENTER_QUEST_ZONE,				// DynamicZone ����
		ACTION_SHOW_CONFIRM_GET_EVENT_ITEM_DIALOG,	// �̺�Ʈ ������ �ޱ� Ȯ��â
		ACTION_GIVE_COMMON_EVENT_ITEM,			// ���� �̺�Ʈ ������ �ֱ�
		// 2006.03.13
		ACTION_GIVE_COMMON_QUEST_ITEM,
		ACTION_CHECK_COMMON_QUEST_ITEM,

		ACTION_RESET_ATTRIBUTE,

		ACTION_CHECK_EVENT_LEVELUP_200604,
		ACTION_GIVE_EVENT_LEVELUP_200604,

		// 2006.03.30
		ACTION_CHECK_COMEBACK_EVENT_ITEM_200604,
		ACTION_GIVE_COMEBACK_EVENT_ITEM_200604,

		ACTION_REDISTRIBUTE_ATTR_50,
		ACTION_CHANGE_PLAYER_COLOR,

		ACTION_EXCHANGE_OF_MONEY,

		ACTION_SOCCER_EVENT_200606,
		ACTION_TRADE_SEALING_STONE,

		ACTION_ENTER_CASTLE_B2F,
		ACTION_ENTER_SURVIVAL_ZONE,

		ACTION_GAMBLE_SYSTEM,

		ACTION_CHECK_GLUTINOUS_RICE_KNEADING,

		ACTION_GIVE_EVENT_BOX_ITEM,

		ACTION_TRADE_MYSTERY_POTION,
		ACTION_TRADE_LEATHER,

		ACTION_GIVE_HELLGARDEN_CROSS_ITEM,
		ACTION_GIVE_HELLGARDEN_SEED_ITEM,

		ACTION_ENTER_HELLGARDEN,
		ACTION_ATTEND_CHECK,
#ifdef __CONTRIBUTION_SYSTEM__
		ACTION_GIVE_CONTRIBUTE_REWARD,
		ACTION_CHECK_LEVEL_WAR_REWARD,
#endif

#ifdef __MENEGROTH_DOUNGEON_SYSTEM__
		ACTION_ENTER_MENEGROTH,
		ACTION_INSERT_CABRACAM_HEART,
#endif // __MENEGROTH_DOUNGEON_SYSTEM__
		ACTION_GIVE_CRASHING_REWARD,

		ACTION_INIT_INSTANCEDOUNGEON,
		
		ACTION_BLITZ_REGISTER, 	// 20080829 ������ ���� ���
		ACTION_BLITZ_REWARD,	// 20080829 ������ �̺�Ʈ ����

		ACTION_MAPLE_REGISTER, 	// 20080925 ������ ���� ���
		ACTION_MAPLE_REWARD,	// 20080925 ������ �̺�Ʈ ����
		
		ACTION_ENTER_PVP_SYSTEM,
		ACTION_PVP_SYSTEM_SIGN_UP,

		ACTION_MONSTER_SUMMON,		// Ruper Island: Altar of Heroes wakes Sius
		ACTION_ENTER_WITH_ITEM,		// Dracula Castle: Marcus lets players in for a Forbidden Blood
		ACTION_TAKE_MIHNEA,			// Dracula Castle: Mihnea's Storage hands over the Mihnea
		ACTION_PLACE_MIHNEA,		// Dracula Castle: the Mihnea Altar takes it and breaks the 2F door
		ACTION_MAX
	};

public:
	virtual ~Action() throw(Error) {}
	virtual ActionType_t getActionType() const throw() = 0;
	virtual void read(PropertyBuffer & buffer) throw(Error) = 0;
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error) = 0;	
	virtual string toString() const throw() = 0;

};

#endif
