// VA: 0050B330 TRIBE_Command::command_unload
// PDB: tcommand.cpp lines 1722-1764.
// The natural packet builder remains observed while its register topology is
// unresolved in the standalone source.

#include <windows.h>
#include <stdio.h>
#include "../tcommand_context.h"

extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_unload(RGE_Static_Object** objs, short count, float x, float y)
{
    if (objs && count >= 1) {
        int obj_count = (int)count;
        int size = obj_count * 4 + 12;
        unsigned char* cmd = (unsigned char*)calloc(1, size);
        int* dest = (int*)(cmd + 12);
        if (cmd) {
            for (int i = 0; i < obj_count; ++i) {
                if (objs[i]) {
                    dest[i] = objs[i]->id;
                } else {
                    dest[i] = -1;
                }
            }
            cmd[0] = 0x6F;
            cmd[1] = (unsigned char)count;
            *(float*)(cmd + 4) = x;
            *(float*)(cmd + 8) = y;

            L->Log((char*)"      >SEND CMD UNLOAD (CNT=%d)", obj_count);

            this->submit(cmd, size);
        }
    }
}
