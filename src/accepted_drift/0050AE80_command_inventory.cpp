// VA: 0050AE80 TRIBE_Command::command_inventory
// PDB: tcommand.cpp lines 1340-1363.
// ACCEPTED_DRIFT: natural shared-closure reconstruction.
#include <stdlib.h>
#include "../tcommand_context.h"

void TRIBE_Command::command_inventory(short player_id, short inventory_id, float amount)
{
    unsigned char* cmd = (unsigned char*)calloc(1, 0x10);
    if (cmd) {
        short inv = inventory_id;
        short player = player_id;
        *(short*)(cmd + 4) = inv;
        *(float*)(cmd + 8) = amount;
        *(short*)(cmd + 2) = player;
        cmd[0] = 0x67;
        cmd[1] = 2;
        L->Log("      >SEND CMD INV (PLR=%d,INV=%d)",
               (int)player_id, (int)inventory_id);
        this->submit(cmd, 0x10);
    }
}
