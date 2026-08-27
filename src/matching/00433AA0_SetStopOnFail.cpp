#ifndef COM_SYNC_TU_CONTEXT
class TCommunications_Handler;
class RGE_Communications_Synchronize {
public:
    TCommunications_Handler* Comm;
    unsigned long CheckTime;
    unsigned long CheckTurn;
    int StopOnSyncFail;
    void SetStopOnFail(int v);
};
#endif

void RGE_Communications_Synchronize::SetStopOnFail(int v) {
#ifdef COM_SYNC_TU_CONTEXT
    this->StopOnSyncFail = v;
#else
    this->StopOnSyncFail = v;
#endif
}
