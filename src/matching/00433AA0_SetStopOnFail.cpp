#ifndef COM_SYNC_TU_CONTEXT
class RGE_Communications_Synchronize {
public:
    virtual ~RGE_Communications_Synchronize();
    char gap_0[0x8];
    int field_C;
    void SetStopOnFail(int v);
};
#endif

void RGE_Communications_Synchronize::SetStopOnFail(int v) {
#ifdef COM_SYNC_TU_CONTEXT
    this->stopOnSyncFail = v;
#else
    this->field_C = v;
#endif
}
