// VA: 005181C0, TRIBE_Player::setupHittite, 288 bytes
// Source: tplayer.cpp lines 4200-4243
// FLAGS: default

#include "../../include/tplayer_context.h"
#include <stddef.h>

#if 0
typedef unsigned char uchar;

extern "C" void __cdecl logCommonHistory(void* target, const char* msg);
extern "C" uchar __fastcall deathMatch_fn(void* game);

class RGE_Player {
public:
    char pad_00[0x238];
    void* playerAI;  // +0x238
};

class TRIBE_Player : public RGE_Player {
public:
    void setupHittite(int* param_1, int param_2, int param_3, int param_4);
};

extern void* rge_base_game;  // 0x0062C574

#endif

void TRIBE_Player::setupHittite(int* param_1, int param_2, int param_3, int param_4)
{
    logCommonHistory(this->playerAI, "Setting up as Hittites.");

    if (rge_base_game->deathMatch() == 1) {
        // Deathmatch path
        if (param_2 == 0 || param_2 == 1) {
            param_1[0x41] = 100;
        } else if (param_2 == 2 || param_2 == 6) {
            param_1[0x1B] = 60;
            param_1[0x41] = 40;
        } else if (param_2 == 5 || param_2 == 8) {
            param_1[0x1B] = 80;
            param_1[0x41] = 20;
        } else {
            param_1[0x1B] = 100;
        }
    } else {
        // Non-deathmatch path - unconditional stores first
        param_1[4] = 0x28;
        param_1[0x12] = 0x28;
        param_1[0x10] = 80;
        param_1[0x31] = 100;
        param_1[0x32] = 100;
        param_1[3] = 30;

        // These stores happen BEFORE the param_2 conditional
        param_1[6] = 0x14;
        param_1[9] = 10;
        param_1[10] = 10;
        param_1[11] = 10;
        param_1[0x11] = 0x14;

        // param_2 conditional
        if (param_2 == 0 || param_2 == 1) {
            param_1[0x57] = 0xA0;
            param_1[0] = 0x14;
        } else if (param_2 == 2 || param_2 == 6 || param_2 == 8 || param_2 == 5) {
            param_1[0x57] = 0x50;
            param_1[0] = 10;
        }
    }
}
