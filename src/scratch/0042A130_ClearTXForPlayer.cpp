class TCommunications_Handler_ctx {
public:
    void ClearTXForPlayer(int player);
    char gap_00[0x1520];
    int* tx_data;
};


void TCommunications_Handler_ctx::ClearTXForPlayer(int player) {
    int index = player + 4;
    int count = 0x1F6;
    do {
        --count;
        this->tx_data[index] = 0;
        index += 14;
    } while (count != 0);
}
