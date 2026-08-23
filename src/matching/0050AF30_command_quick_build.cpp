#include <stdlib.h>

class TRIBE_Command {
public:
    void submit(void* command, int size);
    void command_quick_build(short value);
};

extern void* L;
extern void Log(void* log, const char* text);

struct CommandQuickBuildPacket {
    unsigned char type;
    unsigned char flag;
    unsigned short value;
    char gap_04[0x0C];
};

void TRIBE_Command::command_quick_build(short value) {
    CommandQuickBuildPacket* packet = (CommandQuickBuildPacket*)calloc(1, 0x10);
    if (packet != 0) {
        packet->type = 0x67;
        *(short*)((char*)packet + 2) = value;
        packet->flag = 4;
        Log(L, "      >SEND CMD QUICKBLD");
        this->submit(packet, 0x10);
    }
}
