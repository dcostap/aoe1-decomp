// VA: 0050A8D0 TRIBE_Command::command_research
// PDB: tcommand.cpp lines 944-972.

#include <windows.h>
#include <stdio.h>
#include "../tcommand_context.h"

extern "C" TDebuggingLog* L;
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_research(RGE_Static_Object* obj, short tech_id)
{
    if (obj) {
        unsigned char* cmd = (unsigned char*)calloc(1, 0x10);
        if (cmd) {
            *(int*)(cmd + 4) = obj->id;
            RGE_Player* owner = obj->owner;
            short tech_id_copy = tech_id;
            char owner_id = (char)owner->id;
            cmd[8] = owner_id;
            cmd[0] = 0x65;
            *(short*)(cmd + 10) = tech_id_copy;
            *(int*)(cmd + 12) = -1;
            RGE_Master_Static_Object* master = obj->master_obj;
            int tech_id_int = (int)tech_id_copy;
            L->Log((char*)"      >SEND CMD RESEARCH (UNIT=%s,TECH=%d)",
                   master->name, tech_id_int);
            this->submit(cmd, 0x10);
        }
    }
}
