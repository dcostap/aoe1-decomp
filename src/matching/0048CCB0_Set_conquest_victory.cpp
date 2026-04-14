class RGE_Scenario {
public:
    virtual ~RGE_Scenario();
    char gap_0[0x8];
    unsigned char field_C;
    void Set_conquest_victory(unsigned char v);
};

void RGE_Scenario::Set_conquest_victory(unsigned char v) { this->field_C = v; }
