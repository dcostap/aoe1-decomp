// VA: 0050A860 TRIBE_Command::command_make
// PDB: tcommand.cpp lines 906-938.

#include <windows.h>
#include <stdio.h>
#include "../tcommand_context.h"

extern "C" TDebuggingLog* L;
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_make(
    int player_id, int bldg_id, int unit_id, int param4)
{
    if (bldg_id >= 0) {
        unsigned char* cmd = (unsigned char*)calloc(1, 0x10);
        if (cmd) {
            *(int*)(cmd + 4) = bldg_id;
            cmd[8] = (char)player_id;
            cmd[0] = 0x64;
            *(short*)(cmd + 10) = (short)unit_id;
            *(int*)(cmd + 12) = param4;
            L->Log((char*)"      >SEND CMD MAKE2 (PLR=%d,BLDG=%d,OBJ=%d)",
                   player_id, bldg_id, unit_id);
            this->submit(cmd, 0x10);
        }
    }
}
