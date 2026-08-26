#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_0[0x13BC];
    int arr_[1];
protected:
    void SetPlayerStopTurn(unsigned int i, unsigned long v);
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::SetPlayerStopTurn(unsigned int i, unsigned long v) {
    this->arr_[i] = v;
}
