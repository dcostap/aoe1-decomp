// VA: 0048D500 get_scenario_info (46B)
// sceninfo.cpp

#ifndef AOE1_SCENINFO_TU_CONTEXT
class RGE_Scenario_Header;

class RGE_Scenario_File_Info {
public:
    char gap_00[0x104];
    int scenario_num;          // +0x104
    char* scenarios;           // +0x108

    RGE_Scenario_Header* get_scenario_info(long index);
};
#endif

RGE_Scenario_Header* RGE_Scenario_File_Info::get_scenario_info(long index) {
    if (index >= this->scenario_num || index < 0) return 0;
    return *(RGE_Scenario_Header**)((char*)(this->scenarios) + index * 268 + 4);
}
