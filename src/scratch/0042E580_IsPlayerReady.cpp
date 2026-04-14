class TCommunications_Handler_ipr {
public:
    int IsPlayerReady(int player);
    char gap_00[0x12D8];
    unsigned short max_players;
    char gap_12DA[0x2BA];
    int ready[1];
};

int TCommunications_Handler_ipr::IsPlayerReady(int player) {
    if (player < 1) return 0;
    if (player > (int)this->max_players) return 0;
    return this->ready[player];
}
