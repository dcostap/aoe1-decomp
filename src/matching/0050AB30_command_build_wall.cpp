// VA: 0050AB30 TRIBE_Command::command_build_wall
// PDB: tcommand.cpp lines 1116-1176.

#include <windows.h>
#include <stdio.h>
#include "../tcommand_context.h"

extern "C" TDebuggingLog* L;
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_build_wall(
    RGE_Static_Object** objs, short count, short build_id,
    long a, long b, long c, long d)
{
    if (objs && count >= 1) {
        int obj_count = (int)count;
        int size = obj_count * 4 + 0x10;
        unsigned char* cmd = (unsigned char*)calloc(1, size);
        int* dest = (int*)(cmd + 0x10);
        if (cmd) {
            for (int i = 0; i < obj_count; ++i) {
                if (objs[i]) {
                    dest[i] = objs[i]->id;
                } else {
                    dest[i] = -1;
                }
            }
            cmd[0] = 0x69;
            cmd[1] = (unsigned char)count;
            int owner_id;
            if (objs[0]) {
                owner_id = objs[0]->owner->id;
            } else {
                owner_id = -1;
            }
            cmd[2] = (unsigned char)owner_id;
            *(short*)(cmd + 8) = build_id;
            if (a < 0) a = 0;
            if (a > 0xFF) a = 0xFF;
            if (b < 0) b = 0;
            if (b > 0xFF) b = 0xFF;
            if (c < 0) c = 0;
            if (c > 0xFF) c = 0xFF;
            if (d < 0) d = 0;
            if (d > 0xFF) d = 0xFF;
            cmd[6] = (unsigned char)d;
            cmd[3] = (unsigned char)a;
            cmd[4] = (unsigned char)b;
            cmd[5] = (unsigned char)c;
            *(int*)(cmd + 12) = -1;

            L->Log((char*)"      >SEND CMD WALL (CNT=%d,CAT=%d)",
                   obj_count, (int)build_id);

            this->submit(cmd, size);
        }
    }
}
