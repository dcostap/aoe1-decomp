// compact ally-owner check first
// expected basin: resolve the unit owner, compare ids, then test the symmetric relation bytes

#include "../../include/aiuaimod_context.h"

int UnitAIModule::isAllyOwner(int player_id) {
    RGE_Player* owner = this->objectValue->owner;
    if (owner->id == player_id) {
        return 1;
    }
    if (owner->relations[player_id] == 0 && owner->world->players[player_id]->relations[owner->id] == 0) {
        return 1;
    }
    return 0;
}
