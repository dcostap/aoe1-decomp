#ifndef COM_SYNC_TU_CONTEXT
class RGE_Communications_Synchronize {
public:
    virtual ~RGE_Communications_Synchronize();
    char gap_0[0x24];
    int field_28;
    void SetLastWorldRandom(int v);
};
#endif

void RGE_Communications_Synchronize::SetLastWorldRandom(int v) {
#ifdef COM_SYNC_TU_CONTEXT
    this->lastWorldRandom = v;
#else
    this->field_28 = v;
#endif
}
