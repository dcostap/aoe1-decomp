// VA: 0050AF80 TRIBE_Command::command_shared_los
// PDB: tcommand.cpp lines 1423-1444.
// Exact grouped finish uses the canonical base submit, debug log, and game packet.

#include <stdlib.h>

#ifndef TCOMMAND_CONTEXT_H
class TDebuggingLog;

class TDebuggingLog {
public:
    void __cdecl Log(char* format, ...);
};

extern TDebuggingLog* L;

class RGE_Command {
protected:
    void submit(void* order, long size);
};

class TRIBE_Command : public RGE_Command {
public:
    void command_shared_los(short param_1);
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
