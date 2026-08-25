// VA: 004230A0
// PDB source: basegame.cpp
// debug_rand (__cdecl)

#include <stdlib.h>
#include <stdio.h>

extern int do_debug_random;
extern int debug_random_on;
extern int debug_random_index;
extern char debug_random_log[25][100];

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
        sprintf(&debug_random_log[0][0] + idx * 100, (char*)0x580478,
                rge_base_game->world->world_time, temp_name, param_2, rv);
    }
    return rv;
}
