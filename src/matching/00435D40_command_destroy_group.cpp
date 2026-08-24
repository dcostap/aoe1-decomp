#include <stdlib.h>

#ifndef COMMAND_TU_CONTEXT
class RGE_Command {
public:
    void submit(void* command, int size);
    void command_destroy_group(int player_id, int group_id);
};
#endif

#ifndef COMMAND_TU_CONTEXT
extern void* L;
extern void Log(void* log, const char* text, int player_id);
#endif

struct CommandDestroyGroupPacket {
    unsigned char type;
    unsigned char player_id;
    unsigned short gap_02;
    int group_id;
};

void RGE_Command::command_destroy_group(int player_id, int group_id) {
    CommandDestroyGroupPacket* packet = (CommandDestroyGroupPacket*)calloc(1, 8);
    packet->type = 9;
    packet->player_id = (unsigned char)player_id;
    packet->group_id = group_id;
    Log(L, "      >SEND CMD DES GROUP (PLR=%d)", player_id);
    this->submit(packet, 8);
}
