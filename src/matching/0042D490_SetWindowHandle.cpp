#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    virtual ~TCommunications_Handler();
    char gap_0[0x1308];
    int field_130C;
    void* SetWindowHandle(void* v);
};
#endif // COM_HAND_TU_CONTEXT


void* TCommunications_Handler::SetWindowHandle(void* v) {
    this->HostHWND = v;
    return v;
}
