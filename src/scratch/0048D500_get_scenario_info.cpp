class RGE_Scenario_Header;

struct ScenarioInfoEntry {
    char gap_00[4];
    RGE_Scenario_Header* scenario_header;
    char gap_08[0x104];
};

class RGE_Scenario_File_Info {
public:
    char gap_00[0x104];
    int scenario_num;
    ScenarioInfoEntry* scenarios;

    RGE_Scenario_Header* get_scenario_info(long index);
};

RGE_Scenario_Header* RGE_Scenario_File_Info::get_scenario_info(long index) {
    if (index >= this->scenario_num) {
        return 0;
    }
    if (index < 0) {
        return 0;
    }
    return this->scenarios[index].scenario_header;
}
