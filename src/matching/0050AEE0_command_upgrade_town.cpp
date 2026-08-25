// VA: 0050AEE0 TRIBE_Command::command_upgrade_town
// PDB: tcommand.cpp lines 1369-1390.

#include <stdlib.h>
#include "../tcommand_context.h"

extern void Log(void* log, const char* text, ...);

void TRIBE_Command::command_upgrade_town(short town_id) {
    unsigned char* packet = (unsigned char*)calloc(1, 0x10);
    if (packet != 0) {
        packet[0] = 0x67;
        *(short*)(packet + 2) = town_id;
        packet[1] = 3;
        Log(L, "      >SEND CMD UPG TOWN");
        this->submit(packet, 0x10);
    }
}
