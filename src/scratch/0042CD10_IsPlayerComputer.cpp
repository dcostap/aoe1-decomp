class TCommunications_Handler_ipc {
public:
    int IsPlayerComputer(int player);
    char gap_00[0x12D8];
    unsigned short max_players;
    char gap_12DA[0x3FA];
    int humanity[1];
};

int TCommunications_Handler_ipc::IsPlayerComputer(int player) {
    if (player < 1) return 0;
    if (player > (int)this->max_players) return 0;
    int h = this->humanity[player];
    return h == 4;
}
