// debug_rand (__cdecl)
// VA: 004230A0
// basegame.cpp:6197-6225
// 154 bytes
//
// Attempt log:
// 1: Basic version with Ghidra loop — 60% diff
// 2: Fixed idx*100 struct size, while(1)+break loop — 56% diff
// 3: do-while with if guard — 68% diff
// 4: while(1)+break, closer to original — 68% diff
// 5: Simple indexed for-loop — similar diff
//
// Best result (attempt 2): 154 bytes, 56% positional diff.
// 88 bytes equal, 66% edit diff.
//
// Persistent differences:
// 1. Global loads: Branch offsets differ due to different function layout
// 2. Loop: Original uses eax=p, edx=dst, esi=end, cl=char;
//    rebuilt uses different register assignment
// 3. sprintf dest: Original uses triple-LEA (idx*5*5*4 = idx*100);
//    rebuilt uses different method for idx*100
// 4. sprintf arg loading: Original loads args in specific interleaved
//    order; rebuilt loads differently
//
// Root cause: VC5 codegen differences from single-function TU.
// In a larger TU, register pressure and function proximity would
// produce different optimization decisions.
//
// Left in scratch. Not proposing accepted_drift (>50% diff).
// Retry 2026-05-19 Boss pass: 12 additional variants (nested vs && debug gates, five copy-loop shapes including goto/break and buf sizing, idx*100 LEA spelling, sprintf arg temp/order). Best new positional was 55.8442% but edit diff worsened; no variant fixed register assignment/loop/sprintf scheduling. Restored prior exact-size scratch.

#include <stdlib.h>
#include <stdio.h>

extern int do_debug_random;
extern int debug_random_on;
extern int debug_random_index;
extern void* rge_base_game;
extern char debug_random_log[];

class RGE_Game_World {
public:
    char gap_00[4];
    int world_time;
};

class RGE_Base_Game {
public:
    char gap_00[0x3F4];
    RGE_Game_World* world;
};

int __cdecl debug_rand(char* param_1, int param_2)
{
    int rv = rand();
    if (do_debug_random && debug_random_on) {
        char buf[9];
        char* p = param_1 + 10;
        char* lim = p + 8;
        char* d = buf + 4;
        char c = *p;

        if (c != '.') {
            do {
                if (p >= lim)
                    break;
                *d = c;
                c = p[1];
                d++;
                p++;
            } while (c != '.');
        }
        *d = 0;

        int idx = debug_random_index;
        if (idx < 4999)
            idx++;
        else
            idx = 0;
        debug_random_index = idx;

        RGE_Base_Game* game = *(RGE_Base_Game**)&rge_base_game;
        RGE_Game_World* w = game->world;
        sprintf(debug_random_log + idx * 100, "t%d,%s,l%d,r%d",
                w->world_time, buf + 4, param_2, rv);
    }
    return rv;
}
