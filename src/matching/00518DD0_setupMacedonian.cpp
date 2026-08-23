// VA: 00518DD0, TRIBE_Player::setupMacedonian, 301 bytes
// Source: tplayer.cpp lines 4696-4739
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
    void setupMacedonian(int* param_1, int param_2, int param_3, int param_4);
};

extern void* rge_base_game;  // 0x0062C574

#endif

void TRIBE_Player::setupMacedonian(int* param_1, int param_2, int param_3, int param_4)
{
    logCommonHistory(this->playerAI, "Setting up as Macedonian.");

    if (rge_base_game->deathMatch() == 1) {
        // Deathmatch path
        if (param_2 == 0 || param_2 == 1) {
            param_1[0x7A] = 100;
        } else if (param_2 == 2 || param_2 == 6) {
            param_1[0x76] = 60;
            param_1[0x7A] = 40;
        } else if (param_2 == 5 || param_2 == 8) {
            param_1[0x76] = 80;
            param_1[0x7A] = 20;
        } else {
            param_1[0x76] = 100;
        }
    } else {
        // Non-deathmatch path - common unconditional stores
        param_1[3] = 0x28;
        param_1[4] = 0x28;
        param_1[0] = 0x0A;
        param_1[6] = 0x1E;
        param_1[7] = 0x1E;
        param_1[0x11] = 0x1E;
        param_1[0x68] = 0x50;
        param_1[0x66] = 0x50;
        param_1[0x67] = 0x50;
        param_1[1] = 0x0A;
        param_1[0x10] = 0x14;

        // param_2 conditional
        if (param_2 == 0 || param_2 == 1) {
            param_1[0x69] = 0xC8;
            param_1[0x6A] = 0xC8;
        } else if (param_2 == 2 || param_2 == 6 || param_2 == 8 || param_2 == 5) {
            param_1[0x69] = 100;
            param_1[0x6A] = 100;
        }
    }
}
