// VA: 00518A20, TRIBE_Player::setupRoman, 303 bytes
// Source: tplayer.cpp lines 4545-4589
// FLAGS: default
//
// ACCEPTED_DRIFT: 34.98% positional diff (106/303 bytes). Root cause:
// VC5 pre-loads edx=0x64 (100) for the [0x70]=0x64 store, hoisting it
// ahead of [3],[4]=0x14 stores. Original uses edx=0x14 for [3],[4],
// then edx=0x50 for [11],[0x72], making 0x64/0x3C immediates.
//
// This is a VC5-register-allocation heuristic difference: our VC5
// prefers loading 0x64 (used once) into edx over 0x14 (used twice).
// The resulting code is 1 byte longer (304 vs 303) because the extra
// mov edx,64h (5B) minus the savings from register vs immediate (4B)
// nets +1 byte. All behavior is identical, calls/memory effects match.
//
// Key: using decimal (100) vs hex (0x64) makes no difference to the
// compiler. The register allocation is determined by VC5's internal
// heuristic for pre-loading values it sees ahead in the basic block.

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
    void setupRoman(int* param_1, int param_2, int param_3, int param_4);
};

extern void* rge_base_game;  // 0x0062C574

#endif

void TRIBE_Player::setupRoman(int* param_1, int param_2, int param_3, int param_4)
{
    logCommonHistory(this->playerAI, "Setting up as Roman.");

    if (rge_base_game->deathMatch() == 1) {
        // Deathmatch path
        if (param_2 == 0 || param_2 == 1) {
            param_1[0x7C] = 0x64;
        } else if (param_2 == 2 || param_2 == 6) {
            param_1[0x78] = 0x3C;
            param_1[0x7C] = 0x28;
        } else if (param_2 == 5 || param_2 == 8) {
            param_1[0x78] = 0x50;
            param_1[0x7C] = 0x14;
        } else {
            param_1[0x78] = 0x64;
        }
    } else {
        // Non-deathmatch path - common unconditional stores
        param_1[0] = 0x0A;
        param_1[6] = 0x0A;
        param_1[9] = 0x0A;
        param_1[10] = 0x0A;
        param_1[0x13] = 0x0A;
        param_1[0x14] = 0x0A;
        param_1[3] = 0x14;
        param_1[4] = 0x14;
        param_1[0x0B] = 0x50;
        param_1[0x70] = 0x64;
        param_1[0x71] = 0x3C;
        param_1[0x72] = 0x50;

        // param_2 conditional
        if (param_2 == 0 || param_2 == 1) {
            param_1[0x73] = 0xC8;
            param_1[0x74] = 0xC8;
        } else if (param_2 == 2 || param_2 == 6 || param_2 == 8 || param_2 == 5) {
            param_1[0x73] = 0x64;
            param_1[0x74] = 0x64;
        }
    }
}
