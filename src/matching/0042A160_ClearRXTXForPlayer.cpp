class TCommunications_Handler {
public:
    void ClearTXForPlayer(unsigned int player);
    void ClearRXForPlayer(unsigned int player);
    void ClearRXTXForPlayer(unsigned int player);
};

void TCommunications_Handler::ClearRXTXForPlayer(unsigned int player) {
    ClearTXForPlayer(player);
    ClearRXForPlayer(player);
}
