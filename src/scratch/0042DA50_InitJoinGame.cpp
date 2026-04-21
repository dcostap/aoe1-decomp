class TCommunications_Handler_ijg {
public:
    void InitJoinGame(void);
    void ClearChat(void);
    void CreateDirectPlayConversation(void);
    char gap_00[0x18];
    void* chat;
    char gap_1C[0x01];
    int options_1c;
    int options_20;
    char gap_24[0x10C0];
    int multiplayer_flag;
    char gap_10E8[0x3FC];
    int dp_option;
};

void TCommunications_Handler_ijg::InitJoinGame(void) {
    this->ClearChat();
    this->multiplayer_flag = 1;
    this->options_20 = 0;
    this->options_1c = 0;
    this->dp_option = 0;
    this->CreateDirectPlayConversation();
}
