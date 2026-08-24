#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_0[0x12A8];
    int ShuttingDown;
    void ShutdownGameMessages();
    void ReceiveGameMessages();
};
#endif // COM_HAND_TU_CONTEXT

void TCommunications_Handler::ShutdownGameMessages() {
    this->ShuttingDown = 1;
    this->ReceiveGameMessages();
}
