// VA: 0050AF30 TRIBE_Command::command_quick_build
// PDB: tcommand.cpp lines 1396-1417.
// Exact grouped finish uses the canonical base submit, debug log, and game packet.

#include <stdlib.h>
#include "../tcommand_context.h"

void TRIBE_Command::command_quick_build(short value) {
    TRIBE_Command_Game* packet = (TRIBE_Command_Game*)calloc(1, 0x10);
    if (packet != 0) {
        packet->command = 0x67;
        packet->var1 = value;
        packet->game_command = 4;
        L->Log((char*)"      >SEND CMD QUICKBLD");
        this->submit(packet, 0x10);
    }
}
