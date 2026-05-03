// VA: 005182E0, TRIBE_Player::setupPhoenician, 275 bytes
// Source: tplayer.cpp lines 4248-4287
// FLAGS: default
//
// Attempt log:
// - v1: Defined TRIBE_Game + deathMatch() as class method → inlined deathMatch
//       body (7 bytes) as first function in .text. DeathMatch path scrambled.
// - v2: Used extern "C" __fastcall deathMatch_fn to prevent inlining. First 157
//       bytes now match exactly (whole deathmatch path section).
// - v3-v10+: Varied register allocation approach (declaration order, reassignment,
//       separate variables, grouping stores by value). Always same VC5 behavior:
//       edx=0x64 (100), ecx=0x14 (20). Original has edx=0x14 (20), then edx=0x64 (100).
//       Also param_2 reload position differs (after v20 stores vs before).
//
// What matches (260/275 bytes):
// - All prologue through deathmatch switch path: first 157 bytes EXACT match
// - Non-deathmatch path: instruction patterns match, values correct
// - All comparison chains, return sequences, ret 10h cleanups
// - After offset 0xD3: everything matches to end (64 bytes)
//
// Remaining mismatches (25 bytes in 2 hunks, non-deathmatch only):
// 1. reg alloc: edx loads 100 (0x64) instead of 20 (0x14) initially.
//    Original: edx=20 → 3 stores to [0],[18h],[4C]; then edx=100 → [D4],[170]
//    Mine: edx=100 immediately; ecx=20 → same 3 stores via ecx
// 2. param_2 reload (mov ecx,[esp+8]) scheduled after v20 stores instead of before
//    → cascading 12-byte displacement difference.
// Both are VC5 register allocator / scheduler decisions, resistant to source tricks.
//
// Note: logCommonHistory is __cdecl (has add esp,8 after call), not __thiscall.
// This was a key insight to get the first 157 bytes matching.

#include <stddef.h>

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
    void setupPhoenician(int* param_1, int param_2, int param_3, int param_4);
};

extern void* rge_base_game;  // 0x0062C574

void TRIBE_Player::setupPhoenician(int* param_1, int param_2, int param_3, int param_4)
{
    logCommonHistory(this->playerAI, "Setting up as Phoenicians.");

    if (deathMatch_fn(rge_base_game) == 1) {
        if (param_2 == 0 || param_2 == 1) {
            param_1[0x44] = 100;
        } else if (param_2 == 2 || param_2 == 6) {
            param_1[0x1E] = 60;
            param_1[0x44] = 40;
        } else if (param_2 == 5 || param_2 == 8) {
            param_1[0x1E] = 80;
            param_1[0x44] = 20;
        } else {
            param_1[0x1E] = 100;
        }
    } else {
        int v10 = 10;
        int v20 = 20;
        int v70 = 70;

        param_1[3] = v10;
        param_1[4] = v10;
        param_1[9] = v10;
        param_1[10] = v10;
        param_1[11] = v10;

        param_1[0x11] = v70;
        param_1[0x12] = v70;

        param_1[0x00] = v20;
        param_1[6] = v20;
        param_1[0x13] = v20;

        v20 = 100;

        param_1[1] = 40;
        param_1[0x14] = 30;
        param_1[0x35] = v20;

        if (param_2 == 0 || param_2 == 1) {
            param_1[0x5C] = 200;
        } else if (param_2 == 2 || param_2 == 6 || param_2 == 8 || param_2 == 5) {
            param_1[0x5C] = v20;
        }
    }
}
