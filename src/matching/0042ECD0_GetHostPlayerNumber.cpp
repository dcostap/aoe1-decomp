#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    virtual ~TCommunications_Handler();
    char gap_0[0x1710];
    int field_1714;
    unsigned int GetHostPlayerNumber();
};
#endif // COM_HAND_TU_CONTEXT


unsigned int TCommunications_Handler::GetHostPlayerNumber() { return this->field_1714; }
