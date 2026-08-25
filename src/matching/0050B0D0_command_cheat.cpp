// VA: 0050B0D0 TRIBE_Command::command_cheat
// PDB: tcommand.cpp lines 1525-1547.
// The canonical log identity repairs the prior relocation mismatch.

extern "C" void* __cdecl calloc(size_t, size_t);

#include "../tcommand_context.h"

void TRIBE_Command::command_cheat(short param1, short param2) {
    TRIBE_Command_Game* buf = (TRIBE_Command_Game*)calloc(1, 16);
    if (buf) {
        buf->command = 0x67;
        buf->var1 = param1;
        buf->var2 = param2;
        buf->game_command = 6;
        L->Log((char*)"      >SEND CMD CHEAT %d", param2);
        submit(buf, 0x10);
    }
}
