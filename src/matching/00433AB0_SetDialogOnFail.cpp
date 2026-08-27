#ifndef COM_SYNC_TU_CONTEXT
class TCommunications_Handler;
class RGE_Communications_Synchronize {
public:
    TCommunications_Handler* Comm;
    unsigned long CheckTime;
    unsigned long CheckTurn;
    int StopOnSyncFail;
    int DialogOnSyncFail;
    void SetDialogOnFail(int v);
};
#endif

void RGE_Communications_Synchronize::SetDialogOnFail(int v) {
#ifdef COM_SYNC_TU_CONTEXT
    this->DialogOnSyncFail = v;
#else
    this->DialogOnSyncFail = v;
#endif
}
