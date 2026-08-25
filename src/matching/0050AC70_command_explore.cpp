// VA: 0050AC70 TRIBE_Command::command_explore
// PDB: tcommand.cpp lines 1182-1221.

#include <windows.h>
#include <stdio.h>
#include "../tcommand_context.h"

extern "C" TDebuggingLog* L;
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_explore(
    int player_id, int* obj_ids, int obj_count, float x, float y)
{
    if (obj_ids && obj_count >= 1) {
        int size = obj_count * 4 + 12;
        unsigned char* cmd = (unsigned char*)calloc(1, size);
        int* dest = (int*)(cmd + 12);
        if (cmd) {
            for (int i = 0; i < obj_count; ++i) {
                dest[i] = obj_ids[i];
            }
            cmd[0] = 0x68;
            cmd[1] = (unsigned char)obj_count;
            cmd[2] = (unsigned char)player_id;
            *(float*)(cmd + 4) = x;
            *(float*)(cmd + 8) = y;
            L->Log((char*)"      >SEND CMD EXPLORE (CNT=%d)", obj_count);
            this->submit(cmd, size);
        }
    }
}
