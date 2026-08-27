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
    int NewData;
    int LastResult;
    unsigned int Offset;
    int DoChecksums;
    unsigned long LastWorldRandom;
    void SetLastWorldRandom(unsigned long v);
};
#endif

void RGE_Communications_Synchronize::SetLastWorldRandom(unsigned long v) {
#ifdef COM_SYNC_TU_CONTEXT
    this->LastWorldRandom = v;
#else
    this->LastWorldRandom = v;
#endif
}
