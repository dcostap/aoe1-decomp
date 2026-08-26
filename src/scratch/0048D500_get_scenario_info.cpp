// VA: 0048D500 get_scenario_info (46B)
// sceninfo.cpp
// SOURCE NOTE: Typed entry ownership replaces the old raw byte cursor.
// The reduced grouped source remains exact.

#ifndef AOE1_SCENINFO_TU_CONTEXT
class RGE_Scenario_Header;

struct RGE_Scenario_File_Entry {
    long time;
    RGE_Scenario_Header* scenario_header;
    char name[260];
};

class RGE_Scenario_File_Info {
public:
    char filename[260];
    int scenario_num;
    RGE_Scenario_File_Entry* scenarios;

    RGE_Scenario_Header* get_scenario_info(long index);
};
#endif

RGE_Scenario_Header* RGE_Scenario_File_Info::get_scenario_info(long index) {
    if (index >= this->scenario_num || index < 0) return 0;
    return this->scenarios[index].scenario_header;
}
