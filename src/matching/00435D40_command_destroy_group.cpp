#include <stdlib.h>

class RGE_Command {
public:
    void submit(void* command, int size);
    void command_destroy_group(int player_id, int group_id);
};

extern void* L;
extern void Log(void* log, const char* text, int player_id);

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
