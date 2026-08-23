// VA: 0050B0D0 TRIBE_Command::command_cheat
// PDB: tcommand.cpp lines 1525-1547.
// The canonical log identity repairs the prior relocation mismatch.

extern "C" void* __cdecl calloc(size_t, size_t);

#ifndef TCOMMAND_CONTEXT_H
class TDebuggingLog {
public:
    void __cdecl Log(char* format, ...);
};

extern TDebuggingLog* L;

class RGE_Command {
protected:
    void submit(void* buf, long size);
};

class TRIBE_Command : public RGE_Command {
public:
    void command_cheat(short param1, short param2);
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
