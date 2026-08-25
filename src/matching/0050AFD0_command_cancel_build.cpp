// VA: 0050AFD0 TRIBE_Command::command_cancel_build
// PDB: tcommand.cpp lines 1450-1471.
// Exact grouped finish uses the canonical packet, log, and inherited submit.

#include <windows.h>
#include <stdio.h>
#include "../tcommand_context.h"

extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_cancel_build(RGE_Static_Object* obj)
{
    TRIBE_Command_Cancel_Build* cmd =
        (TRIBE_Command_Cancel_Build*)calloc(1, 8);
    if (cmd) {
        cmd->command = 0x6A;
        cmd->unit_id = obj->id;
        L->Log((char*)"      >SEND CMD CANCELBLD");
        this->submit(cmd, 8);
    }
}
