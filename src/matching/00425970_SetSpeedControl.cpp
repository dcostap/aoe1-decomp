struct Inner_00425970 {
    void target(int param);
};

class TCommunications_Handler {
public:
    char gap_0[0x14D4];
    Inner_00425970 *ptr_;
    void SetSpeedControl(int param);
};

void TCommunications_Handler::SetSpeedControl(int param) {
    this->ptr_->target(param);
}
