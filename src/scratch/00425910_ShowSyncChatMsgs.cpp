struct Inner_00425910 {
    void target(int param);
};

class TCommunications_Handler {
public:
    char gap_0[0x14D8];
    Inner_00425910 *ptr_;
    void ShowSyncChatMsgs(int param);
};

void TCommunications_Handler::ShowSyncChatMsgs(int param) {
    this->ptr_->target(param);
}
