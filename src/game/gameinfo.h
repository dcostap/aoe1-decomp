#pragma once
#include "../common.h"

class RGE_Person_Info {
public:
    long current_campaign;                   // 0x100
    long campaign_info_num;                  // 0x104
    RGE_Campaign_Info** campaign_info;       // 0x108
    long campaign_num;                       // 0x10C
    RGE_Campaign** campaigns;                // 0x110

    RGE_Person_Info(int param_1, RGE_Campaign** param_2, long param_3);
    RGE_Person_Info(char* param_1, RGE_Campaign** param_2, long param_3);
    virtual ~RGE_Person_Info();
    virtual void save(int param_1);
    virtual void rehook_campaigns(RGE_Campaign** param_1, long param_2);
    virtual char* get_name();
    virtual uchar set_current_campaign(long param_1);
    virtual long get_current_campaign();
    virtual long get_current_scenario();
    virtual uchar set_current_scenario(long param_1);
    virtual long get_scenario_list(char*** param_1, long* param_2);
    virtual void notify_of_scenario_complete();
    virtual int open_scenario();
};

static_assert(sizeof(RGE_Person_Info) == 0x114, "RGE_Person_Info Size Mismatch");
static_assert(offsetof(RGE_Person_Info, campaigns) == 0x110, "RGE_Person_Info Offset Mismatch");

class RGE_Game_Info {
public:
    long people_num;                         // 0x4
    RGE_Person_Info** people_info;           // 0x8
    long campaign_num;                       // 0xC
    RGE_Campaign** campaigns;                // 0x10
    char save_filename[260];                 // 0x14

    RGE_Game_Info(char* param_1);
    virtual ~RGE_Game_Info();
    virtual void save(char* param_1);
    virtual void find_campaigns();
    virtual uchar add_new_person(char* param_1);
    virtual uchar set_current_person(long param_1);
    virtual uchar set_current_campaign(long param_1);
    virtual uchar set_current_scenario(long param_1);
    virtual long get_people_list(char*** param_1, long* param_2);
    virtual long get_campaign_list(char*** param_1, long* param_2);
    virtual long get_scenario_list(char*** param_1, long* param_2);
    virtual long get_current_scenario();
    virtual long get_current_campaign();
    virtual long get_current_player();
    virtual char* get_current_player_name();
    virtual void notify_of_scenario_complete();
    virtual int open_scenario();
    virtual void remove_player(long param_1);
};

static_assert(sizeof(RGE_Game_Info) == 0x118, "RGE_Game_Info Size Mismatch");
static_assert(offsetof(RGE_Game_Info, save_filename) == 0x14, "RGE_Game_Info Offset Mismatch");

class RGE_Campaign_Info {
public:
    long current_scenario;                   // 0x100
    long scenario_num;                       // 0x104
    RGE_Scenario_Info* scenario_info;        // 0x108
    long last_scenario;                      // 0x10C
    RGE_Campaign* campaign;                  // 0x110

    RGE_Campaign_Info(int param_1, RGE_Campaign** param_2, long param_3);
    RGE_Campaign_Info(RGE_Campaign* param_1);
    virtual ~RGE_Campaign_Info();
    virtual void save(int param_1);
    virtual void rehook_campaigns(RGE_Campaign** param_1, long param_2);
    virtual uchar set_current_scenario(long param_1);
    virtual uchar verify_campaign_name(char* param_1);
    virtual long get_scenario_list(char*** param_1, long* param_2);
    virtual long get_current_scenario();
    virtual void notify_of_scenario_complete();
    virtual int open_scenario();
};

static_assert(sizeof(RGE_Campaign_Info) == 0x114, "RGE_Campaign_Info Size Mismatch");
static_assert(offsetof(RGE_Campaign_Info, campaign) == 0x110, "RGE_Campaign_Info Offset Mismatch");

