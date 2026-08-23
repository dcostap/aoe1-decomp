struct Inner_0042F270 {
    void target(int a, int b);
};

class TCommunications_Handler {
public:
    char gap_0[0x14D8];
    Inner_0042F270 *ptr_;
    void IsPlayerOutOfSync(int a, int b);
};

void TCommunications_Handler::IsPlayerOutOfSync(int a, int b) {
    this->ptr_->target(a, b);
}
