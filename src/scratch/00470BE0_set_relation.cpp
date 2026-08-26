#ifndef PLAYER_GROUPED_TU
#include "../player_tu_context.h"
#endif

void RGE_Player::set_relation(long playerId, unsigned char relation) {
    this->relations[playerId] = relation;

    if (playerId == 0) {
        this->unitDiplomacy[0] = 0;
    } else if (playerId == this->id) {
        this->unitDiplomacy[playerId] = 1;
    } else if (relation == 0) {
        this->unitDiplomacy[playerId] = 2;
    } else if (relation == 1) {
        this->unitDiplomacy[playerId] = 3;
    } else {
        this->unitDiplomacy[playerId] = 4;
    }

    RGE_Object_Node* node = this->objects->list;
    while (node != 0) {
        node->node->notify_of_relation(playerId, relation);
        node = node->next;
    }
}
