// RGE_Game_State::set_relation
// VA: 00470BE0
// player.cpp:1670-1734
// 134 bytes

#ifndef PLAYER_GROUPED_TU
#include "../../include/game_globals.h"
#endif

struct NotifyNode {
    void* obj;           // +0x00
    NotifyNode* next;    // +0x04
};

struct ObjectList {
    char gap_00[4];
    NotifyNode* nodeList; // +0x04
};

// Class with virtual method at vtable offset 0x94
class NotifyObject {
public:
    void setRelation(int playerId, unsigned char relation);
};

class RGE_Game_State_Relation {
public:
    char gap_00[0x28];
    ObjectList* objects;     // +0x28
    char gap_2C[0x1E];
    short self_id;           // +0x4A
    char gap_4C[0x38];
    char* relationTable;     // +0x84
    int relationToPlayer[8]; // +0x88

    void set_relation(int playerId, char relation);
};

void RGE_Game_State_Relation::set_relation(int playerId, char relation)
{
    this->relationTable[playerId] = relation;

    if (playerId == 0) {
        this->relationToPlayer[0] = 0;
    } else if (playerId == this->self_id) {
        this->relationToPlayer[playerId] = 1;
    } else if (relation == 0) {
        this->relationToPlayer[playerId] = 2;
    } else if (relation == 1) {
        this->relationToPlayer[playerId] = 3;
    } else {
        this->relationToPlayer[playerId] = 4;
    }

    if (this->objects->nodeList) {
        NotifyNode* node = this->objects->nodeList;
        while (node) {
            ((NotifyObject*)node->obj)->setRelation(playerId, relation);
            node = node->next;
        }
    }
}
