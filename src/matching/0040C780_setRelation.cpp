#include "../../include/aiconmod_context.h"

#ifndef AOE1_AIDIPMOD_TU_CONTEXT
class MainDecisionAIModule {
public:
    char gap_000[0xF0];
    RGE_Player* player;
};

class DiplomacyAIModule {
public:
    char gap_000[0xF0];
    MainDecisionAIModule* md;
    int dislikeTable[10];
    int likeTable[10];
    unsigned char changeableTable[10];

    void setRelation(int player_id, int stance);
};
#endif

void DiplomacyAIModule::setRelation(int player_id, int stance) {
    if (player_id > 0) {
        if (player_id < this->md->player->world->player_num) {
            if (this->changeableTable[player_id] != 0) {
                this->md->player->setDiplomaticStance(player_id, stance);
            }
        }
    }
}
