struct ScenarioInfoEntry {
    char gap_00[8];
    char name[0x104];
};

class RGE_Scenario_File_Info {
public:
    char gap_00[0x104];
    int scenario_num;
    ScenarioInfoEntry* scenarios;

    char* get_scenario_name(long index);
};

char* RGE_Scenario_File_Info::get_scenario_name(long index) {
    if (index >= this->scenario_num) {
        return 0;
    }
    if (index < 0) {
        return 0;
    }
    return this->scenarios[index].name;
}
