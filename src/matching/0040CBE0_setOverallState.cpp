// 0040CBE0 EmotionalAIModule::setOverallState
// Source: aiemomod.cpp lines 134-187
// Size: 382 bytes, no EH
//
// Attempt log:
// Probe 1: switch with 6 cases, body order 0,4,1,3,2,5 to match PDB — 10.99% diff (offset issue)
// Probe 2: fixed class layout (md at +0xF0, stateValue at +0xF4), default flags

#include "..\..\include\game_globals.h"

class AIModule {
public:
    char _gap_00[0xF0];
};

class EmotionalAIModule : public AIModule {
public:
    int md;                   // +0xF0
    int stateValue[6];        // +0xF4
    char stateNameValue[6][30]; // +0x10C

    void setOverallState(int state);
};

void EmotionalAIModule::setOverallState(int state)
{
    switch (state) {
    case 0:
        stateValue[0] = 100;
        stateValue[4] = 10;
        stateValue[1] = 10;
        stateValue[3] = 10;
        stateValue[2] = 0;
        stateValue[5] = 70;
        break;
    case 4:
        stateValue[0] = 20;
        stateValue[4] = 100;
        stateValue[1] = 70;
        stateValue[3] = 50;
        stateValue[2] = 60;
        stateValue[5] = 0;
        break;
    case 1:
        stateValue[0] = 10;
        stateValue[4] = 50;
        stateValue[1] = 100;
        stateValue[3] = 80;
        stateValue[2] = 50;
        stateValue[5] = 0;
        break;
    case 3:
        stateValue[0] = 10;
        stateValue[4] = 50;
        stateValue[1] = 70;
        stateValue[3] = 100;
        stateValue[2] = 50;
        stateValue[5] = 20;
        break;
    case 2:
        stateValue[0] = 20;
        stateValue[4] = 60;
        stateValue[1] = 50;
        stateValue[3] = 50;
        stateValue[2] = 100;
        stateValue[5] = 10;
        break;
    case 5:
        stateValue[0] = 90;
        stateValue[4] = 10;
        stateValue[1] = 0;
        stateValue[3] = 30;
        stateValue[2] = 50;
        stateValue[5] = 100;
        break;
    }
}
