// VA: 0050AD00 TRIBE_Command::command_allied_victory
// PDB: tcommand.cpp lines 1227-1250.

#include <windows.h>
#include <stdio.h>
#include "../tcommand_context.h"

extern "C" TDebuggingLog* L;
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_allied_victory(short player_id, unsigned char flag)
{
    unsigned char* cmd = (unsigned char*)calloc(1, 0x10);
    if (cmd) {
        *(short*)(cmd + 2) = player_id;
        int flag_int = (int)flag;
        unsigned short flag_short = (unsigned short)flag;
        *(unsigned short*)(cmd + 4) = flag_short;
        int player_id_int = (int)player_id;
        *(unsigned int*)(cmd + 8) = 0;
        cmd[0] = 0x67;
        cmd[1] = 5;
        L->Log((char*)"      >SEND CMD ALLIED VIC (PLR=%d,FLAG=%d)",
               player_id_int, flag_int);
        this->submit(cmd, 0x10);
    }
}
