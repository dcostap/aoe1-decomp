// VA: 0050AF30 TRIBE_Command::command_quick_build
// PDB: tcommand.cpp lines 1396-1417.
// Exact grouped finish uses the canonical base submit, debug log, and game packet.

#include <stdlib.h>

#ifndef TCOMMAND_CONTEXT_H
class TDebuggingLog {
public:
    void __cdecl Log(char* format, ...);
};

extern TDebuggingLog* L;

class RGE_Command {
protected:
    void submit(void* command, long size);
};

class TRIBE_Command : public RGE_Command {
public:
    void command_quick_build(short value);
};

class TRIBE_Command_Game {
public:
    unsigned char command;
    unsigned char game_command;
    short var1;
    short var2;
    char gap_06[2];
    float var3;
    short var4;
    char gap_0E[2];
};
#endif

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
