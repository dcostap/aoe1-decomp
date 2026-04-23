#include <stdlib.h>

class RGE_Command {
public:
    void submit(void* data, int size);
};

class TRIBE_Command : public RGE_Command {
public:
    void command_game_speed(float speed);
};

extern void __cdecl TDebuggingLog_Log(void* log, const char* msg);

void TRIBE_Command::command_game_speed(float speed) {
    unsigned char* packet = (unsigned char*)calloc(1, 0x10);
    if (packet != 0) {
        packet[0] = 0x67;
        *(float*)(packet + 8) = speed;
        packet[1] = 1;
        TDebuggingLog_Log(*(void**)0x62C4FC, "      >SEND CMD GAME SPD");
        this->submit(packet, 0x10);
    }
}
