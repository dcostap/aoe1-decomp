class RGE_Communications_Speed {
public:
    virtual ~RGE_Communications_Speed();
    char gap_0[0x128];
    int field_12C;
    int GetBufferGranularity();
};

int RGE_Communications_Speed::GetBufferGranularity() { return this->field_12C; }
