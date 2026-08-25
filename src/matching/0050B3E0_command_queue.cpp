// VA: 0050B3E0 TRIBE_Command::command_queue
// PDB: tcommand.cpp lines 1770-1796.
// The natural queue packet builder is retained as the module observation.

#include <windows.h>
#include <stdio.h>
#include "../tcommand_context.h"

extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_queue(
    RGE_Static_Object* building,
    short train_id,
    short count)
{
    unsigned char* cmd = (unsigned char*)calloc(1, 0x0C);
    if (cmd) {
        cmd[0] = 0x77;
        int building_id = building->id;
        *(short*)(cmd + 10) = count;
        *(int*)(cmd + 4) = building_id;
        *(short*)(cmd + 8) = train_id;
        L->Log((char*)"      >SEND CMD QUEUE (B=%d,T=%d,C=%d)",
               building->id, (int)train_id, (int)count);
        this->submit(cmd, 0x0C);
    }
}
