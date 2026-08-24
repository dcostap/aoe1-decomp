int __cdecl target_0042BAD0();

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_0[0x12D4];
    int field_12D4;
    void GetCommunicationsStatus();
};
#endif // COM_HAND_TU_CONTEXT


COMMSTATUS TCommunications_Handler::GetCommunicationsStatus() {
    this->field_12D4 = target_0042BAD0();
    return (COMMSTATUS)this->field_12D4;
}
