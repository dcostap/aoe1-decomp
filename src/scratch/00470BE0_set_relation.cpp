// 00470BE0 RGE_Game_State::set_relation
// Source: player.cpp lines 1670-1734
// Size: 134 bytes
//
// Attempt log:
// Probe 1: 23% diff — self_id at +0x4A, node list at [eax+4]
// Probe 2: 14.9% diff — function pointer generates 'push esi'+'add esp,0Ch' instead of 'mov edx,[ecx]'+'call [edx+94h]'
// Probe 3: try without notify loop, just null check

#include "..\..\include\game_globals.h"

struct NotifyNode {
    char _gap_00[4];
};

class Something {
public:
    char _gap_00[4];
    NotifyNode* nodeList;       // +0x04
};

class RGE_Game_State {
public:
    char _gap_00[0x28];
    Something* something;       // +0x28
    char _gap_2C[0x1E];
    short self_id;              // +0x4A
    char _gap_4C[0x38];
    char* relationTable;        // +0x84
    int relationToPlayer[8];    // +0x88

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

    if (this->something->nodeList) {
    }
}
