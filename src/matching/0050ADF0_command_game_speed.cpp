// VA: 0050ADF0 TRIBE_Command::command_game_speed
// PDB: tcommand.cpp lines 1287-1308.
// SCRATCH: natural shared-closure reconstruction.
// Attempt log (sa-b39e5fe5):
// - The natural packet form had exact size, frame, CFG, and three calls.
//   Its helper spelling selected TDebuggingLog_Log instead of original Log.
// - The canonical TDebuggingLog::Log member restored the original relocation
//   target and produced MATCH in the authentic wrapper.
#include <stdlib.h>
#include "../tcommand_context.h"

void TRIBE_Command::command_game_speed(float speed)
{
    unsigned char* packet = (unsigned char*)calloc(1, 0x10);
    if (packet != 0) {
        packet[0] = 0x67;
        *(float*)(packet + 8) = speed;
        packet[1] = 1;
        L->Log((char*)"      >SEND CMD GAME SPD");
        this->submit(packet, 0x10);
    }
}
