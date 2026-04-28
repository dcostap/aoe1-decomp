// RGE_Game_State::set_relation
// VA: 00470BE0
// player.cpp:1670-1734
// 134 bytes

#include "../../include/game_globals.h"

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
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(void);
    virtual void vf54(void);
    virtual void vf58(void);
    virtual void vf5C(void);
    virtual void vf60(void);
    virtual void vf64(void);
    virtual void vf68(void);
    virtual void vf6C(void);
    virtual void vf70(void);
    virtual void vf74(void);
    virtual void vf78(void);
    virtual void vf7C(void);
    virtual void vf80(void);
    virtual void vf84(void);
    virtual void vf88(void);
    virtual void vf8C(void);
    virtual void vf90(void);
    virtual void setRelation(int playerId, unsigned char relation);
};

class RGE_Game_State {
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

void RGE_Game_State::set_relation(int playerId, char relation)
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
