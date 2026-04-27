// first pass: calloc a 0x14-byte command packet, fill the fields, log the command, then submit it
// tried to keep the source natural so VC5 can stay in the same small packet-construction basin
#include <stdlib.h>

class RGE_Command {
public:
    void submit(unsigned char* order, long size);
    void command_create(short param_1, short param_2, float param_3, float param_4, float param_5);
};

extern void* __cdecl calloc(size_t count, size_t size);
extern void* g_debug_log;
extern const char s_send_cmd_create[];
extern void Log(void* log, const char* msg, int a1, int a2);

void RGE_Command::command_create(short param_1, short param_2, float param_3, float param_4, float param_5) {
    unsigned char* packet = (unsigned char*)calloc(1, 0x14);
    packet[0] = 4;
    *(short*)(packet + 2) = param_1;
    packet[4] = (unsigned char)param_2;
    *(float*)(packet + 8) = param_3;
    *(float*)(packet + 0xC) = param_4;
    *(float*)(packet + 0x10) = param_5;
    Log(g_debug_log, s_send_cmd_create, (int)param_1, (int)param_2);
    this->submit(packet, 0x14);
}
