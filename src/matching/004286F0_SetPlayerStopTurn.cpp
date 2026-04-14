class TCommunications_Handler {
public:
    char gap_0[0x13BC];
    int arr_[1];
    void SetPlayerStopTurn(int i, int v);
};

void TCommunications_Handler::SetPlayerStopTurn(int i, int v) {
    this->arr_[i] = v;
}
