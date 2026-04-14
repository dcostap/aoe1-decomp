class RGE_Communications_Synchronize {
public:
    virtual ~RGE_Communications_Synchronize();
    char gap_0[0x24];
    int field_28;
    void SetLastWorldRandom(int v);
};

void RGE_Communications_Synchronize::SetLastWorldRandom(int v) { this->field_28 = v; }
