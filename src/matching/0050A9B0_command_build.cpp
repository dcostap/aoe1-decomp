// VA: 0050A9B0 TRIBE_Command::command_build
// PDB: tcommand.cpp lines 1015-1060.

#include <windows.h>
#include <stdio.h>
#include "../tcommand_context.h"

extern "C" TDebuggingLog* L;
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_build(
    RGE_Static_Object** objs, short count, short build_id, float x, float y)
{
    if (objs && count >= 1) {
        int obj_count = (int)count;
        int size = obj_count * 4 + 0x14;
        unsigned char* cmd = (unsigned char*)calloc(1, size);
        int* dest = (int*)(cmd + 0x14);
        if (cmd) {
            for (int i = 0; i < obj_count; ++i) {
                if (objs[i]) {
                    dest[i] = objs[i]->id;
                } else {
                    dest[i] = -1;
                }
            }
            cmd[0] = 0x66;
            cmd[1] = (unsigned char)count;
            int owner_id;
            if (objs[0]) {
                owner_id = objs[0]->owner->id;
            } else {
                owner_id = -1;
            }
            *(float*)(cmd + 4) = x;
            *(float*)(cmd + 8) = y;
            cmd[2] = (unsigned char)owner_id;
            *(short*)(cmd + 12) = build_id;
            *(int*)(cmd + 0x10) = -1;
            L->Log((char*)"      >SEND CMD BUILD (CNT=%d,CAT=%d)",
                   obj_count, (int)build_id);
            this->submit(cmd, size);
        }
    }
}
