// VA: 0048D500 get_scenario_info (46B)
// sceninfo.cpp

class RGE_Scenario_File_Info2 {
public:
    char gap_00[0x104];
    int scenario_num;          // +0x104
    char* scenarios;           // +0x108

    char* get_scenario_info(int index);
};

char* RGE_Scenario_File_Info2::get_scenario_info(int index) {
    if (index >= this->scenario_num || index < 0) return 0;
    return *(char**)((char*)(this->scenarios) + index * 268 + 4);
}
