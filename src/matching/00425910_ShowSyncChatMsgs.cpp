#if !defined(COM_HAND_TU_CONTEXT)
struct RGE_Communications_Synchronize {
    void SendChatMsgsAtChecksum(int param);
};
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_0[0x14D8];
    RGE_Communications_Synchronize *Sync;
    void ShowSyncChatMsgs(int param);
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::ShowSyncChatMsgs(int param) {
    this->Sync->SendChatMsgsAtChecksum(param);
}
