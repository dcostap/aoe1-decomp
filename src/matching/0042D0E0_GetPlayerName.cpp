class TCommunications_Handler {
public:
    char gap_00[0x10E0];
    int Me;
    int Multiplayer;
    char gap_10E8[0x10];
    char MyFriendlyName[0x80];
    char gap_1178[0x150];
    char* FriendlyName;
    char gap_12CC[0x0C];
    unsigned short MaxGamePlayers;

    char* GetPlayerName(unsigned int player);
};

char* TCommunications_Handler::GetPlayerName(unsigned int player) {
    if (player > MaxGamePlayers) {
        return 0;
    }
    if ((int)player == Me) {
        return MyFriendlyName;
    }
    return FriendlyName + (player << 7);
}
