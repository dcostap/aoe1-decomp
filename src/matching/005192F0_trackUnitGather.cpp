// VA: 005192F0 TRIBE_Player::trackUnitGather | tplayer.cpp:4810-4815
// Canonical shared tplayer owner. The null guard and tactical-AI offset are
// direct evidence from the target body.

#include "../../include/tplayer_context.h"

void TRIBE_Player::trackUnitGather(int a, int b, int c)
{
    if (!this->playerAI)
        return;

    ((TribeTacticalAIModule*)((char*)this->playerAI + 0x1146C))
        ->trackUnitGather(a, b, c);
}
