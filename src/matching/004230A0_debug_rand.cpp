// debug_rand (__cdecl)
// VA: 004230A0
// basegame.cpp:6197-6225
// 154 bytes
// ACCEPTED_DRIFT 2026-05-20 Boss: exact size; remaining diff is localized to independent sprintf-argument setup scheduling only. The store to debug_random_index and one idx*5 LEA occur a few bytes earlier, but all globals, destination address, format address, pushed args, temp buffer, call, stack cleanup, and return are identical after resync.
//
// Attempt log:
// Prior attempts left a 56%+ positional diff with broad loop/register/sprintf scheduling drift.
// Retry 2026-05-19 Boss pass: 12 variants (nested vs && debug gates, five copy-loop shapes including goto/break and buf sizing, idx*100 LEA spelling, sprintf arg temp/order). Best positional was 55.8442% but edit diff worsened.
// Retry 2026-05-20 Boss pass: exact-looking source found except localized scheduling drift.
// Key improvements kept:
// - use fixed-address #define globals for original absolute loads;
// - mutate param_1 by +10 and use temp_name as the visible 9-byte local (not temp_name+4), giving the original [esp+8] temp pointer;
// - use `while (c != '.' && param_1 < end)` to preserve the original cmp-char/cmp-bound loop;
// - read debug_random_index before writing the terminator, matching the original load/zero order;
// - use hardcoded format-string address 0x580478.
// Final validation: 154/154, MISMATCH, 25 positional bytes / 16.2338%, 16 edit bytes / 10.3896%, first mismatch +92.
// ACCEPTED_DRIFT proposal: remaining bytes are localized to side-effect-free scheduling in sprintf setup:
//   rebuilt stores debug_random_index five bytes earlier (before pushing param_2 / loading rge_base_game) whereas original stores it after computing the temp_name pointer;
//   rebuilt computes idx*5 (`lea eax,[eax+eax*4]`) before loading world pointer, original computes it after loading world pointer;
//   all pushed arguments, global store value, destination address, temp buffer, call, stack cleanup, and return are identical after resync. No changed predicates, calls, stack balance, or memory targets.

#include <stdlib.h>
#include <stdio.h>

#define do_debug_random (*(int*)0x62C4D0)
#define debug_random_on (*(int*)0x62C4D4)
#define debug_random_index (*(int*)0x62C4D8)
#define debug_random_log ((char*)0x5B2378)

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

#define rge_base_game (*(RGE_Base_Game**)0x62C574)

int __cdecl debug_rand(char* param_1, int param_2)
{
    int rv = rand();
    if (do_debug_random && debug_random_on) {
        char temp_name[9];
        param_1 += 10;
        char* dst = temp_name;
        char* end = param_1 + 8;
        char c = *param_1;
        while (c != '.' && param_1 < end) {
            *dst = c;
            c = param_1[1];
            ++dst;
            ++param_1;
        }
        int idx = debug_random_index;
        *dst = 0;
        if (idx < 4999)
            ++idx;
        else
            idx = 0;
        debug_random_index = idx;
        sprintf(debug_random_log + idx * 100, (char*)0x580478,
                rge_base_game->world->world_time, temp_name, param_2, rv);
    }
    return rv;
}
