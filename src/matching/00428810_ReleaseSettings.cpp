#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    virtual ~TCommunications_Handler();
    char gap_0[0x154C];
    unsigned char field_1550;
    void ReleaseSettings();
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::ReleaseSettings() { this->field_1550 = 0; }
