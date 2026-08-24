#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    void ClearTXForPlayer(unsigned int player);
    void ClearRXForPlayer(unsigned int player);
    void ClearRXTXForPlayer(unsigned int player);
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::ClearRXTXForPlayer(unsigned int player) {
    ClearTXForPlayer(player);
    ClearRXForPlayer(player);
}
