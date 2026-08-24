struct Inner_0042F250 {
    void target(int param);
};

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_0[0x14D4];
    Inner_0042F250 *ptr_;
    void SetSpeedV2(int param);
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::SetSpeedV2(int param) {
    this->ptr_->target(param);
}
