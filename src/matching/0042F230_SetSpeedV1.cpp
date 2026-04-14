struct Inner_0042F230 {
    void target(int param);
};

class TCommunications_Handler {
public:
    char gap_0[0x14D4];
    Inner_0042F230 *ptr_;
    void SetSpeedV1(int param);
};

void TCommunications_Handler::SetSpeedV1(int param) {
    this->ptr_->target(param);
}
