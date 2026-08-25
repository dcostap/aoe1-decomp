// VA: 0050AA90 TRIBE_Command::command_build
// PDB: tcommand.cpp lines 1066-1110.
// ACCEPTED_DRIFT: natural shared-closure reconstruction.
#include <windows.h>
#include <stdio.h>
#include "../tcommand_context.h"

extern void Log(void* log, const char* format, ...);
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_build(int player_id, int* ids, int count,
                                  int build_id, float x, float y, int terrain)
{
    if (ids && count >= 1) {
        int size = count * 4 + 0x14;
        unsigned char* cmd = (unsigned char*)calloc(1, size);
        int* dest = (int*)(cmd + 0x14);
        if (cmd) {
            for (int i = 0; i < count; ++i) {
                dest[i] = ids[i];
            }
            short build_short = (short)build_id;
            int cat_for_log = build_id;
            *(float*)(cmd + 4) = x;
            *(float*)(cmd + 8) = y;
            cmd[0] = 0x66;
            cmd[1] = (unsigned char)count;
            *(short*)(cmd + 12) = build_short;
            *(int*)(cmd + 0x10) = terrain;
            cmd[2] = (unsigned char)player_id;
            Log(L, "      >SEND CMD BUILD2 (CNT=%d,CAT=%d)", count, cat_for_log);
            this->submit(cmd, size);
        }
    }
}
