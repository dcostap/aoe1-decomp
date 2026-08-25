// VA: 0050A7F0 TRIBE_Command::command_make
// PDB: tcommand.cpp lines 872-900.

#include <windows.h>
#include <stdio.h>
#include "../tcommand_context.h"

extern "C" TDebuggingLog* L;
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_make(RGE_Static_Object* obj, short unit_id)
{
    if (obj) {
        unsigned char* cmd = (unsigned char*)calloc(1, 0x10);
        if (cmd) {
            *(int*)(cmd + 4) = obj->id;
            RGE_Player* owner = obj->owner;
            short unit_id_copy = unit_id;
            char owner_id = (char)owner->id;
            cmd[8] = owner_id;
            cmd[0] = 100;
            *(short*)(cmd + 10) = unit_id_copy;
            *(int*)(cmd + 12) = -1;
            RGE_Master_Static_Object* master = obj->master_obj;
            int unit_id_int = (int)unit_id_copy;
            L->Log((char*)"      >SEND CMD MAKE (UNIT=%s,OBJ=%d)",
                   master->name, unit_id_int);
            this->submit(cmd, 0x10);
        }
    }
}
