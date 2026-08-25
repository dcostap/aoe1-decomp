// VA: 0050B190 TRIBE_Command::command_trade_attribute
// PDB: tcommand.cpp lines 1585-1625.
// Exact grouped finish uses the canonical packet, log, and inherited submit.

#include <windows.h>
#include <stdio.h>
#include "../tcommand_context.h"

extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_trade_attribute(RGE_Static_Object** objs, short count, long attribute)
{
    if (objs && count >= 1) {
        int obj_count = (int)count;
        int size = obj_count * 4 + 8;
        TRIBE_Command_Trade_Attribute* cmd =
            (TRIBE_Command_Trade_Attribute*)calloc(1, size);
        int* dest = (int*)(cmd + 1);
        if (cmd) {
            for (int i = 0; i < obj_count; ++i) {
                if (objs[i]) {
                    dest[i] = objs[i]->id;
                } else {
                    dest[i] = -1;
                }
            }
            cmd->command = 0x6D;
            cmd->unit_num = (unsigned char)count;
            cmd->attribute = attribute;

            L->Log(
                (char*)"      >SEND CMD TRADE ATTR (CNT=%d)", obj_count);

            this->submit(cmd, size);
        }
    }
}
