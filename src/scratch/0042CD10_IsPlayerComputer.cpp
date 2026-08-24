class TCommunications_Handler_ipc {
public:
    int IsPlayerComputer(unsigned int player);
    char gap_00[0x12D8];
    unsigned short max_players;
    char gap_12DA[0x3FA];
    int humanity[1];
};


int TCommunications_Handler_ipc::IsPlayerComputer(unsigned int player) {
    int humanity;

    if (player >= 1u && player <= this->max_players) {
        humanity = this->humanity[player];
        return humanity == 4;
    }
    return 0;
}
