// VA: 0050AD70 TRIBE_Command::command_relation
// PDB: tcommand.cpp lines 1256-1281.
// ACCEPTED_DRIFT: natural shared-closure reconstruction.
#include <stdlib.h>
#include "../tcommand_context.h"

void TRIBE_Command::command_relation(short player_id, short target_player_id, short relation)
{
    TRIBE_Command* self = this;
    unsigned char* cmd = (unsigned char*)calloc(1, 0x10);
    if (cmd) {
        short rel_s = relation;
        short player_s = player_id;
        short target_s = target_player_id;
        int rel_i = (int)rel_s;
        *(short*)(cmd + 4) = target_s;
        *(float*)(cmd + 8) = (float)rel_i;
        *(short*)(cmd + 12) = rel_s;
        L->Log("      >SEND CMD RELATION (PLR=%d,TAR=%d,REL=%d)",
               (int)player_s, (int)target_s, rel_i);
        *(short*)(cmd + 2) = player_s;
        cmd[0] = 0x67;
        cmd[1] = 0;
        self->submit(cmd, 0x10);
    }
}
