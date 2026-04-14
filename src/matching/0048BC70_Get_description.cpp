class RGE_Scenario {
public:
    virtual ~RGE_Scenario();
    char gap_0[0x1010];
    int field_1014;
    int Get_description();
};

int RGE_Scenario::Get_description() { return this->field_1014; }
