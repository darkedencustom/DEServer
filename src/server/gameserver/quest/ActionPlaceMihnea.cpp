//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionPlaceMihnea.cpp
//////////////////////////////////////////////////////////////////////////////

#include "ActionPlaceMihnea.h"
#include "Creature.h"
#include "NPC.h"
#include "PlayerCreature.h"
#include "GamePlayer.h"
#include "DraculaCastleManager.h"
#include "Gpackets/GCNPCResponse.h"
#include "Gpackets/GCSystemMessage.h"

void ActionPlaceMihnea::execute(Creature* pCreature1, Creature* pCreature2)
	throw(Error)
{
	__BEGIN_TRY

	Assert(pCreature1 != NULL);
	Assert(pCreature2 != NULL);
	Assert(pCreature1->isNPC());
	Assert(pCreature2->isPC());

	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature2);
	Player* pPlayer = pCreature2->getPlayer();
	Assert(pPC != NULL && pPlayer != NULL);

	string message = g_DraculaCastleManager.placeMihnea(pPC);

	GCNPCResponse gcNPCResponse;
	gcNPCResponse.setCode(NPC_RESPONSE_QUIT_DIALOGUE);
	pPlayer->sendPacket(&gcNPCResponse);

	if (!message.empty())
	{
		GCSystemMessage gcSystemMessage;
		gcSystemMessage.setMessage(message);
		pPlayer->sendPacket(&gcSystemMessage);
	}

	__END_CATCH
}
