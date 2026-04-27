// 0040C010 DiplomacyAIModule::update
// Source: aidipmod.cpp lines 65-93
// Size: 143 bytes
//
// Attempt log:
// Probe 1: 143/143B, 75% diff — codegen basin
//   Pointer chain and virtual dispatch generate different code

#include "..\..\include\game_globals.h"

class MainDecisionAIModule;

class AIModule {
public:
    virtual ~AIModule() {}
    virtual void dummy1() {}
    char _gap_04[0xEC];
};

class DiplomacyAIModule : public AIModule {
public:
    MainDecisionAIModule* md;            // +0xF0
    int dislikeTable[10];                // +0xF4
    int likeTable[10];                   // +0x11C
    unsigned char changeableTable[10];   // +0x144

    int update(int param);
    int isAlly(int id);
    int isAlliedWithMe(int id);
    void changeStance(int id, int a, int b);
};

int DiplomacyAIModule::update(int param)
{
    // Bounds check from md->player->world->player_count
    int num_players = *(short*)(*(int*)(*(int*)(*(int*)((char*)this + 0xF0) + 0xF0) + 0x3C) + 0x3C);
    for (int i = 1; i < num_players; i++) {
        // Skip self: player_id check
        int self_id = *(short*)(*(int*)(*(int*)(((char*)this + 0xF0)) + 0xF0) + 0x4A);
        if (i == self_id)
            continue;

        // If ally but not allied with me → make neutral
        if (isAlly(i) && !isAlliedWithMe(i))
            changeStance(i, 0, 1);

        // If not ally but allied with me → make ally
        if (!isAlly(i) && isAlliedWithMe(i))
            changeStance(i, 2, 1);
    }
    return 1;
}
