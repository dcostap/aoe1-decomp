#include <stdlib.h>

class RGE_Command {
public:
    void submit(void* data, int size);
};

class TRIBE_Command : public RGE_Command {
public:
    void command_upgrade_town(short townId);
};

extern void* L;
extern void Log(void* log, const char* text);

void TRIBE_Command::command_upgrade_town(short townId) {
    unsigned char* packet = (unsigned char*)calloc(1, 0x10);
    if (packet != 0) {
        packet[0] = 0x67;
        *(short*)(packet + 2) = townId;
        packet[1] = 3;
        Log(L, "      >SEND CMD UPG TOWN");
        this->submit(packet, 0x10);
    }
}
