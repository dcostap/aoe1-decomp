class RGE_Scenario {
public:
    virtual ~RGE_Scenario();
    char gap_0[0x1884];
    int field_1888;
    void Set_Version(int v);
};

void RGE_Scenario::Set_Version(int v) { this->field_1888 = v; }
