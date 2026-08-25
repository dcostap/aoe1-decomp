// VA: 0050AF80 TRIBE_Command::command_shared_los
// PDB: tcommand.cpp lines 1423-1444.
// Exact grouped finish uses the canonical base submit, debug log, and game packet.

#include <stdlib.h>
#include "../tcommand_context.h"

void TRIBE_Command::command_shared_los(short param_1) {
    TRIBE_Command_Game* order;

    order = (TRIBE_Command_Game*)calloc(1, 0x10);
    if (order != 0) {
        order->command = 0x67;
        order->var1 = param_1;
        order->game_command = 7;
        L->Log((char*)"      >SEND CMD SHAREDLOS");
        this->submit(order, 0x10);
    }
}
