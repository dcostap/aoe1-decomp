#ifndef COM_SYNC_TU_CONTEXT
class TCommunications_Handler;
class RGE_Communications_Synchronize {
public:
    TCommunications_Handler* Comm;
    unsigned long CheckTime;
    unsigned long CheckTurn;
    int StopOnSyncFail;
    int DialogOnSyncFail;
    int SendChatMsgs;
    void SendChatMsgsAtChecksum(int v);
};
#endif

void RGE_Communications_Synchronize::SendChatMsgsAtChecksum(int v) {
#ifdef COM_SYNC_TU_CONTEXT
    this->SendChatMsgs = v;
#else
    this->SendChatMsgs = v;
#endif
}
