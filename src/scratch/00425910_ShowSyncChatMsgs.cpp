struct Inner_00425910 {
    void target(int param);
};

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_0[0x14D8];
    Inner_00425910 *ptr_;
    void ShowSyncChatMsgs(int param);
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::ShowSyncChatMsgs(int param) {
    this->ptr_->target(param);
}
