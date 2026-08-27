#ifndef AOE1_SCENINFO_H
#define AOE1_SCENINFO_H

class RGE_Scenario_Header;

class RGE_Scenario_File_Entry {
public:
    long time;
    RGE_Scenario_Header* scenario_header;
    char name[260];
};

typedef char rge_scenario_file_entry_size_check[
    (sizeof(RGE_Scenario_File_Entry) == 0x10C) ? 1 : -1];

class RGE_Scenario_File_Info {
public:
    char filename[260];
    long scenario_num;
    RGE_Scenario_File_Entry* scenarios;

    RGE_Scenario_File_Info(char* path);
    ~RGE_Scenario_File_Info();
    void save();
    void reload_scenarios();
    char* get_scenario_name(long index);
    RGE_Scenario_Header* get_scenario_info(long index);
};

typedef char rge_scenario_file_info_size_check[
    (sizeof(RGE_Scenario_File_Info) == 0x10C) ? 1 : -1];

#endif  // AOE1_SCENINFO_H
