#ifndef COM_SYNC_TU_CONTEXT
class RGE_Communications_Synchronize {
public:
    virtual ~RGE_Communications_Synchronize();
    char gap_0[0xC];
    int field_10;
    void SetDialogOnFail(int v);
};
#endif

void RGE_Communications_Synchronize::SetDialogOnFail(int v) {
#ifdef COM_SYNC_TU_CONTEXT
    this->dialogOnSyncFail = v;
#else
    this->field_10 = v;
#endif
}
