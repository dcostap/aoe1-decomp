// VA: 00518C90, TRIBE_Player::setupPalmyran, 315 bytes
// Source: tplayer.cpp lines 4645-4691
// FLAGS: default
//
// ACCEPTED_DRIFT: 23.17% positional diff (73/315 bytes). Root cause same as
// setupRoman: VC5 register allocation heuristic. Original pre-loads edx=0x3C
// early and keeps edx alive across the non-deathmatch block for the final
// [0x10]=[0x11]=0x3C stores. Our VC5 loads 0x3C into ecx later on demand.
//
// First 165 bytes (deathmatch path + setup) are IDENTICAL. Remaining 150
// bytes are functionally identical with different register lifetimes.
// All calls, control flow, and memory effects match exactly.

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
    void setupPalmyran(int* param_1, int param_2, int param_3, int param_4);
};

extern void* rge_base_game;  // 0x0062C574

#endif

void TRIBE_Player::setupPalmyran(int* param_1, int param_2, int param_3, int param_4)
{
    logCommonHistory(this->playerAI, "Setting up as Palmyran.");

    if (rge_base_game->deathMatch() == 1) {
        // Deathmatch path
        if (param_2 == 0 || param_2 == 1) {
            param_1[0x7B] = 0x64;
        } else if (param_2 == 2 || param_2 == 6) {
            param_1[0x77] = 0x3C;
            param_1[0x7B] = 0x28;
        } else if (param_2 == 5 || param_2 == 8) {
            param_1[0x77] = 0x50;
            param_1[0x7B] = 0x14;
        } else {
            param_1[0x77] = 0x64;
        }
    } else {
        // Non-deathmatch path - common unconditional stores
        param_1[3] = 0x28;
        param_1[6] = 0x28;
        param_1[0] = 0x1E;
        param_1[7] = 0x0A;
        param_1[9] = 0x0A;
        param_1[10] = 0x0A;
        param_1[11] = 0x0A;
        param_1[1] = 0x1E;
        param_1[0x6B] = 0x50;
        param_1[0x6C] = 0x50;
        param_1[0x6D] = 0x50;
        param_1[0x10] = 0x3C;
        param_1[4] = 0x14;
        param_1[0x11] = 0x3C;

        // param_2 conditional
        if (param_2 == 0 || param_2 == 1) {
            param_1[0x6E] = 0xC8;
            param_1[0x6F] = 0xC8;
        } else if (param_2 == 2 || param_2 == 6 || param_2 == 8 || param_2 == 5) {
            param_1[0x6E] = 0x64;
            param_1[0x6F] = 0x64;
        }
    }
}
