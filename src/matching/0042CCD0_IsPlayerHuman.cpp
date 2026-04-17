class TCommunications_Handler {
public:
    char gap_00[0x12D8];
    unsigned short MaxGamePlayers;
    char gap_12DA[0x3FA];
    int Humanity[1];

    int IsPlayerHuman(unsigned int player);
};

int TCommunications_Handler::IsPlayerHuman(unsigned int player) {
    int humanity;

    if (player >= 1 && player <= MaxGamePlayers) {
        humanity = Humanity[player];
        if (humanity == 2 || humanity == 5) {
            return 1;
        }
    }
    return 0;
}
