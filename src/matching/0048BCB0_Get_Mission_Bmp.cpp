class RGE_Scenario {
public:
    virtual ~RGE_Scenario();
    char gap_0[0x17A4];
    char field_17A8[1];
    char* Get_Mission_Bmp();
};

char* RGE_Scenario::Get_Mission_Bmp() { return this->field_17A8; }
