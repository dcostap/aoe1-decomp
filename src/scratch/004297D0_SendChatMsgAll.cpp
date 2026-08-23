#include <string.h>

class TCommunications_Handler_chat {
public:
    void SendChatMsgAll(const char* msg);
    void SendChatMsg(int player_id, char* dest_map, const char* msg);
    char gap_00[0x10E0];
    int local_player;
};

void TCommunications_Handler_chat::SendChatMsgAll(const char* msg) {
    char dest[10];

    memset(dest, 'Y', 10);
    this->SendChatMsg(this->local_player, dest, msg);
}
