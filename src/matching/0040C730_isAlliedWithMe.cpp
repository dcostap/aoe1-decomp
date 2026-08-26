#include "../../include/aiconmod_context.h"

#ifndef AOE1_AIDIPMOD_TU_CONTEXT
class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Player* player;
};

class DiplomacyAIModule {
public:
    char gap_00[0xF0];
    MainDecisionAIModule* md;

    int isAlliedWithMe(int player_num) const;
};

#endif

int DiplomacyAIModule::isAlliedWithMe(int player_num) const
{
    if (0 < player_num) {
        RGE_Player* me = this->md->player;
        RGE_Game_World* world = me->world;
        if (player_num < world->player_num) {
            RGE_Player* other = world->players[player_num];
            if (other != 0) {
                if (other->isAlly((int)me->id) != 0)
                    return 1;
            }
        }
    }

    return 0;
}
