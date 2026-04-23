#include <stdlib.h>

class RGE_Command {
public:
    void submit(void* data, int size);
};

class TRIBE_Command : public RGE_Command {
public:
    void command_save_game();
};

extern void __cdecl TDebuggingLog_Log(void* log, const char* msg);

void TRIBE_Command::command_save_game() {
    unsigned char* packet = (unsigned char*)calloc(1, 0x10);
    if (packet != 0) {
        packet[0] = 0x67;
        packet[1] = 0x08;
        TDebuggingLog_Log(*(void**)0x62C4FC, "      >SEND CMD SAVEGAME");
        this->submit(packet, 0x10);
    }
}
