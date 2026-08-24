#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    virtual ~TCommunications_Handler();
    char gap_0[0x1308];
    int field_130C;
    void SetWindowHandle(int v);
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::SetWindowHandle(int v) { this->HostHWND = (void*)v; }
