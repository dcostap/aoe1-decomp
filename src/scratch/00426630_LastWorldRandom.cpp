struct Inner_00426630 {
    void target(int param);
};

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_0[0x14D8];
    Inner_00426630 *ptr_;
    void LastWorldRandom(int param);
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::LastWorldRandom(int param) {
    this->ptr_->target(param);
}
