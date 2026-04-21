class TCommunications_Handler_ctx {
public:
    void ClearTXForPlayer(int player);
    char gap_00[0x1520];
    int* tx_data;
};

void TCommunications_Handler_ctx::ClearTXForPlayer(int player) {
    int base = player * 4 + 0x10;
    int count = 0x1F6;
    int* data = this->tx_data;
    while (count--) {
        *(int*)((char*)data + base) = 0;
        base += 0x38;
    }
}
