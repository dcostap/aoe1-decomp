class TCommunications_Handler_chat {
public:
    void SendChatMsgAll(const char* msg);
    void SendChatMsg(int player_id, char* dest_map, const char* msg);
    char gap_00[0x10E0];
    int local_player;
};

void TCommunications_Handler_chat::SendChatMsgAll(const char* msg) {
    char dest[10];
    *(int*)&dest[0] = 0x59595959;
    *(int*)&dest[4] = 0x59595959;
    *(short*)&dest[8] = 0x5959;
    this->SendChatMsg(this->local_player, dest, msg);
}
