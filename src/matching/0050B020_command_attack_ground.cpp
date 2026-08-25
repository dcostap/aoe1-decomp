// VA: 0050B020 TRIBE_Command::command_attack_ground
// PDB: tcommand.cpp lines 1477-1519.
// Exact grouped finish uses the canonical packet, log, and inherited submit.

#include <windows.h>
#include <stdio.h>
#include "../tcommand_context.h"

extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_attack_ground(RGE_Static_Object** objs, short count, float x, float y)
{
    if (objs && count >= 1) {
        int obj_count = (int)count;
        int size = obj_count * 4 + 12;
        TRIBE_Command_Attack_Ground* cmd =
            (TRIBE_Command_Attack_Ground*)calloc(1, size);
        int* dest = (int*)(cmd + 1);
        if (cmd) {
            for (int i = 0; i < obj_count; ++i) {
                if (objs[i]) {
                    dest[i] = objs[i]->id;
                } else {
                    dest[i] = -1;
                }
            }
            cmd->command = 0x6B;
            cmd->unit_num = (unsigned char)count;
            cmd->location_x = x;
            cmd->location_y = y;

            L->Log(
                (char*)"      >SEND CMD ATTACK GROUND (CNT=%d)", obj_count);

            this->submit(cmd, size);
        }
    }
}
