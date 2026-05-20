// 00423140 debug_srand
// basegame.cpp:6231-6257, 158 bytes
// Retry 2026-05-19 Boss pass:
// - Implemented from packet/Ghidra. 10 variants tried: nested vs && debug gates, several filename-copy loops (do/while, while, goto, for bounded), idx*100 address spelling, seed local, record-array surface, and goto done.
// - Best variant is bounded for-loop copy: exact size 158, MISMATCH 34.8101% positional / 34.1772% edit, first mismatch 27.
// - Original shares the same hand-shaped copy/index/sprintf family as debug_rand; rebuilt still uses different loop topology/registers and sprintf argument scheduling. No accepted_drift: broad control-flow/register/scheduling differences, not localized.
// Retry 2026-05-20: MATCH. Mutating param_1 in place (`param_1 += 10`) plus `char buf[9]` with `d = buf` recovered the exact copy-loop and stack LEA. Removing the game/world local and using the direct nested expression inside sprintf preserved right-to-left vararg scheduling (push seed/line before loading rge_base_game) and matched exactly.

#include <stdlib.h>
#include <stdio.h>

extern int do_debug_random;
extern int debug_random_on;
extern int debug_random_index;
extern void* rge_base_game;
extern char debug_random_log[];

class RGE_Game_World {
public:
    char gap[4];
    int world_time;
};

class RGE_Base_Game {
public:
    char gap[0x3F4];
    RGE_Game_World* world;
};

void __cdecl debug_srand(char* param_1, int param_2, unsigned int param_3)
{
    if (do_debug_random && debug_random_on) {
        char buf[9]; param_1 += 10; char* d = buf; char* end = param_1 + 8; char c = *param_1;
        while (c != '.' && param_1 < end) { *d = c; c = param_1[1]; d++; param_1++; }
        *d = 0;
        int idx = debug_random_index;
        if (idx < 4999) idx++; else idx = 0;
        debug_random_index = idx;
        sprintf(debug_random_log + idx * 100, "t%d,%s,l%d,s%u", (*(RGE_Base_Game**)&rge_base_game)->world->world_time, buf, param_2, param_3);
    }
    srand(param_3);
}
