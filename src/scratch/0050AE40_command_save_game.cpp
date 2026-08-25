// VA: 0050AE40 TRIBE_Command::command_save_game
// PDB: tcommand.cpp lines 1314-1334.
// SCRATCH: natural shared-closure reconstruction.
#include <stdlib.h>
#include "../tcommand_context.h"

void TRIBE_Command::command_save_game()
{
    unsigned char* packet = (unsigned char*)calloc(1, 0x10);
    if (packet != 0) {
        packet[0] = 0x67;
        packet[1] = 0x08;
        TDebuggingLog_Log(L, "      >SEND CMD SAVEGAME");
        this->submit(packet, 0x10);
    }
}
