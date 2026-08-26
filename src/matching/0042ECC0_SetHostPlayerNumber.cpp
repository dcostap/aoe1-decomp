#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    virtual ~TCommunications_Handler();
    char gap_0[0x1710];
    int field_1714;
protected:
    void SetHostPlayerNumber(unsigned int v);
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::SetHostPlayerNumber(unsigned int v) { this->field_1714 = v; }
