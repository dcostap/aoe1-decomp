class TCommunications_Handler {
public:
    char gap_0[0x2580];
    volatile int field_2580;
    void IncServiceCount();
};

void TCommunications_Handler::IncServiceCount() {
    this->field_2580 = this->field_2580 + 1;
}
