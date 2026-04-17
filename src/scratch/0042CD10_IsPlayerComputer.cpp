class TCommunications_Handler_ipc {
public:
    int IsPlayerComputer(unsigned int player);
    char gap_00[0x12D8];
    unsigned short max_players;
    char gap_12DA[0x3FA];
    int humanity[1];
};

int TCommunications_Handler_ipc::IsPlayerComputer(unsigned int player) {
    if (player < 1u) {
        goto fail;
    }
    if (player > (unsigned int)this->max_players) {
        goto fail;
    }

    {
        int h = this->humanity[player];
        return h == 4;
    }

fail:
    return 0;
}
