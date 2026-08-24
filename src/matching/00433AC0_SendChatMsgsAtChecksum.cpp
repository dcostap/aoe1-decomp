#ifndef COM_SYNC_TU_CONTEXT
class RGE_Communications_Synchronize {
public:
    virtual ~RGE_Communications_Synchronize();
    char gap_0[0x10];
    int field_14;
    void SendChatMsgsAtChecksum(int v);
};
#endif

void RGE_Communications_Synchronize::SendChatMsgsAtChecksum(int v) {
#ifdef COM_SYNC_TU_CONTEXT
    this->sendChatMsgs = v;
#else
    this->field_14 = v;
#endif
}
