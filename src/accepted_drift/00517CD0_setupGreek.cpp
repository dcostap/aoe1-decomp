// VA: 00517CD0, TRIBE_Player::setupGreek, 318 bytes
// Source: tplayer.cpp lines 3992-4041
// FLAGS: default
// ACCEPTED_DRIFT
//
// Deathmatch path (114 bytes) is 100% identical.
// Non-deathmatch path has VC5 constant CSE-hoisting: loads edx=100
// (for [0xC0],[0x150] stores) at the top alongside ecx=30, instead of
// after the 10-stores. Same root cause as setupRoman/setupPalmyran.
// Fresh validation: 131/318 positional bytes differ (41.0658%).
// All drift is in the non-deathmatch path.
//
// Exact-finish continuation:
// - The canonical tplayer.cpp context keeps the 3 ordered calls, 14
//   conditional branches, 7 returns, no frame, and the owner symbol exact.
// - The first mismatch stays at +0xA1. VC5 emits `jge` before the private
//   param_1 load. It also hoists edx=100 before the 30/10/50 store groups.
// - Direct member access, pointer aliases, guard forms, declaration order,
//   PDB-indicated store order, and local register hints did not change this
//   codegen basin. Restore this source after each experiment.
// - Fresh grouped checks kept these tplayer anchors exact: 00513000,
//   00517B90, 00517E10, 005181C0, 005188F0, 00518DD0, 00518F00,
//   005192F0, and 00519320.

#include "../../include/tplayer_context.h"
#include <stddef.h>

#if 0
typedef unsigned char uchar;

extern "C" void __cdecl logCommonHistory(void* target, const char* msg);
extern void* rge_base_game;  // 0x0062C574
extern "C" uchar __fastcall deathMatch_fn(void* game);
extern "C" int __fastcall difficulty_fn(void* game);

class TRIBE_Player {
public:
    char pad_000[0x238];
    void* playerAI;         // +0x238
    
    void setupGreek(int* param_1, int param_2, int param_3, int param_4);
};

#endif

void TRIBE_Player::setupGreek(int* param_1, int param_2, int param_3, int param_4)
{
    logCommonHistory(this->playerAI, "Setting up as Greeks.");
    
    if (rge_base_game->deathMatch() == 1) {
        // Deathmatch path
        if (param_2 == 0 || param_2 == 1) {
            param_1[0x40] = 100;  // [0x100]
        } else if (param_2 == 2 || param_2 == 6) {
            param_1[0x1A] = 60;   // [0x68] = 3Ch
            param_1[0x40] = 40;   // [0x100] = 28h
        } else if (param_2 == 5 || param_2 == 8) {
            param_1[0x1A] = 80;   // [0x68] = 50h
            param_1[0x40] = 20;   // [0x100] = 14h
        } else {
            param_1[0x1A] = 100;  // [0x68] = 64h
        }
    } else {
        // Non-deathmatch path
        int* p1 = param_1;
        int diff = rge_base_game->difficulty();
        if (diff < 1) {
            p1[0x24] = 100;  // [0x90]
            return;
        }
        
        // Common unconditional stores
        p1[6] = 30;        // [0x18] = 1Eh
        p1[0xB] = 30;      // [0x2C] = 1Eh
        p1[0x14] = 30;     // [0x50] = 1Eh
        p1[9] = 10;        // [0x24] = 0Ah
        p1[10] = 10;       // [0x28] = 0Ah
        p1[3] = 70;        // [0x0C] = 46h
        
        // param_2 check
        int p2 = param_2;
        
        p1[4] = 50;        // [0x10] = 32h
        p1[7] = 20;        // [0x1C] = 14h
        p1[0x13] = 50;     // [0x4C] = 32h
        p1[0x30] = 100;    // [0xC0] = 64h
        p1[0x54] = 100;    // [0x150] = 64h
        
        // Conditional stores based on param_2
        if (p2 == 0 || p2 == 1) {
            p1[0x55] = 200;  // [0x154] = 0C8h
            p1[0x56] = 200;  // [0x158] = 0C8h
        } else if (p2 == 2 || p2 == 6 || p2 == 8 || p2 == 5) {
            p1[0x55] = 100;  // [0x154] = 64h
            p1[0x56] = 100;  // [0x158] = 64h
        }
    }
}
