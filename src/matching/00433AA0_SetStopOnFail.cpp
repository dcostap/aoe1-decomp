class RGE_Communications_Synchronize {
public:
    virtual ~RGE_Communications_Synchronize();
    char gap_0[0x8];
    int field_C;
    void SetStopOnFail(int v);
};

void RGE_Communications_Synchronize::SetStopOnFail(int v) { this->field_C = v; }
