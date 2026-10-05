#ifndef AOE1_CAMPAIGN_H
#define AOE1_CAMPAIGN_H

class RGE_Scenario_Offset {
  public:
    long size;
    long offset;
    char name[255];
    char file_name[255];
};

typedef char campaign_scenario_offset_size_check[(sizeof(RGE_Scenario_Offset) == 0x208) ? 1 : -1];

class RGE_Campaign_Header {
  public:
    long version;
    char name[255];
    long scenario_num;
};

typedef char campaign_header_size_check[(sizeof(RGE_Campaign_Header) == 0x108) ? 1 : -1];

class RGE_Campaign {
  public:
    RGE_Campaign_Header campaign_header;
    RGE_Scenario_Offset* scenario_offsets;
    char filename[255];

    RGE_Campaign(char* in_filename);
    RGE_Campaign(
        char* campaign_filename, char* campaign_name, long scenario_num, char** scenarios, char** scenarios_name
    );
    ~RGE_Campaign();
    void create_file();
    int open_scenario(long scenario);
    char* get_name();
    long scenario_number();
    long scenario_info(char*** scenario_names);
    char* get_scenario_name(long num);
};

typedef char campaign_size_check[(sizeof(RGE_Campaign) == 0x20C) ? 1 : -1];

extern int version_marker;

#endif
