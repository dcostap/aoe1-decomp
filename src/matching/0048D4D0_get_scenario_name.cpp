// VA: 0048D4D0 get_scenario_name (46B)
// sceninfo.cpp

#ifndef AOE1_SCENINFO_TU_CONTEXT
class RGE_Scenario_File_Info {
public:
    char gap_00[0x104];
    int scenario_num;          // +0x104
    char* scenarios;           // +0x108

    char* get_scenario_name(long index);
};
#endif

char* RGE_Scenario_File_Info::get_scenario_name(long index) {
    if (index >= this->scenario_num || index < 0) return 0;
    return (char*)(this->scenarios) + index * 268 + 8;
}
