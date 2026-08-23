extern float g_version;

#ifndef SCENARIO_TU
class RGE_Scenario {
public:
    float Get_Version();
};
#endif

float RGE_Scenario::Get_Version() {
    return g_version;
}
