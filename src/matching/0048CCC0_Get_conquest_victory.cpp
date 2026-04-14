class RGE_Scenario {
public:
    virtual ~RGE_Scenario();
    char gap_0[0x8];
    unsigned char field_C;
    unsigned char Get_conquest_victory();
};

unsigned char RGE_Scenario::Get_conquest_victory() { return this->field_C; }
