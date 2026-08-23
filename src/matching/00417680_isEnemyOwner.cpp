#include "../../include/aiuaimod_context.h"

int UnitAIModule::isEnemyOwner(int player_id) {
    RGE_Player* owner = this->objectValue->owner;
    if (owner->id == player_id) {
        return 0;
    }
    return owner->relations[player_id] == 3;
}
