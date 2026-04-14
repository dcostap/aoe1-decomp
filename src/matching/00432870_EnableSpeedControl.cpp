class RGE_Communications_Speed {
public:
    virtual ~RGE_Communications_Speed();
    char gap_0[0x114];
    int field_118;
    void EnableSpeedControl(int v);
};

void RGE_Communications_Speed::EnableSpeedControl(int v) { this->field_118 = v; }
