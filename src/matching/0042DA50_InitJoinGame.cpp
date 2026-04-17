class TChat_ijg {
public:
    void ClearChat(void);
};

class TCommunications_Handler_ijg {
public:
    long InitJoinGame(void);
    long CreateDirectPlayConversation(void);
    char gap_00[0x18];
    TChat_ijg* chat;
    int options_1c;
    int options_20;
    char gap_24[0x10C0];
    int multiplayer_flag;
    char gap_10E8[0x3FC];
    int dp_option;
};

long TCommunications_Handler_ijg::InitJoinGame(void) {
    this->chat->ClearChat();
    this->multiplayer_flag = 1;
    this->options_20 = 0;
    this->options_1c = 0;
    this->dp_option = 0;
    return this->CreateDirectPlayConversation();
}
