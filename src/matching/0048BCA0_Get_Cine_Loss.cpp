class RGE_Scenario {
public:
    virtual ~RGE_Scenario();
    char gap_0[0x16C4];
    char field_16C8[1];
    char* Get_Cine_Loss();
};

char* RGE_Scenario::Get_Cine_Loss() { return this->field_16C8; }
