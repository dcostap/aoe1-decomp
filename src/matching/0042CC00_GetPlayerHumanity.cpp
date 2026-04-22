class TCommunications_Handler_gph {
public:
    int GetPlayerHumanity(unsigned int player);
    char gap_00[0x12D8];
    unsigned short max_players;
    char gap_12DA[0x3FA];
    int humanity[1];
};

int TCommunications_Handler_gph::GetPlayerHumanity(unsigned int player) {
    if (player >= 1u && player <= this->max_players)
        return this->humanity[player];
    return 0;
}
