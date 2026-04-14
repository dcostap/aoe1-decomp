class TCommunications_Handler {
public:
    char gap_0[0x210];
    volatile int field_210;
    void WaitingOnAcknowledgement();
};

void TCommunications_Handler::WaitingOnAcknowledgement() {
    this->field_210 = this->field_210 + 1;
}
