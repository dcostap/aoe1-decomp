#ifndef SCENARIO_TU
class RGE_Scenario {
public:
    virtual ~RGE_Scenario();
    char gap_0[0x1884];
    float Version;
    void Set_Version(float v);
};
#endif

void RGE_Scenario::Set_Version(float v) { this->Version = v; }
