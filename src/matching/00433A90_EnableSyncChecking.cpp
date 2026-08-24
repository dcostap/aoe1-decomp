#ifndef COM_SYNC_TU_CONTEXT
class RGE_Communications_Synchronize {
public:
    virtual ~RGE_Communications_Synchronize();
    char gap_0[0x20];
    int field_24;
    void EnableSyncChecking(int v);
};
#endif

void RGE_Communications_Synchronize::EnableSyncChecking(int v) {
#ifdef COM_SYNC_TU_CONTEXT
    this->doChecksums = v;
#else
    this->field_24 = v;
#endif
}
