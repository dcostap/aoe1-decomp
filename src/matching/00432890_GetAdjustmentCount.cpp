class RGE_Communications_Speed {
public:
    virtual ~RGE_Communications_Speed();
    char gap_0[0x234];
    int field_238;
    int GetAdjustmentCount();
};

int RGE_Communications_Speed::GetAdjustmentCount() { return this->field_238; }
