class RGE_Scenario {
public:
    virtual ~RGE_Scenario();
    char gap_0[0x15E4];
    char field_15E8[1];
    char* Get_Cine_Victory();
};

char* RGE_Scenario::Get_Cine_Victory() { return this->field_15E8; }
