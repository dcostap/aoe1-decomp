int __cdecl target_0042BAD0();

class TCommunications_Handler {
public:
    char gap_0[0x12D4];
    int field_12D4;
    void GetCommunicationsStatus();
};

void TCommunications_Handler::GetCommunicationsStatus() {
    this->field_12D4 = target_0042BAD0();
}
