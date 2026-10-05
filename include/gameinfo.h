#ifndef AOE1_GAMEINFO_H
#define AOE1_GAMEINFO_H

struct RGE_Scenario_Info {
    unsigned char scenario_status;
};

class RGE_Campaign;
class RGE_Campaign_Info;
class RGE_Person_Info;
class RGE_Game_Info;

class RGE_Campaign_Info {
  public:
    char name[256];
    int current_scenario;
    int scenario_num;
    RGE_Scenario_Info* scenario_info;
    int last_scenario;
    RGE_Campaign* campaign;

    RGE_Campaign_Info(int infile, RGE_Campaign** campaigns, long campaign_num);
    RGE_Campaign_Info(RGE_Campaign* new_campaign);
    ~RGE_Campaign_Info();

    void save(int outfile);
    void rehook_campaigns(RGE_Campaign** campaigns, long campaign_num);
    unsigned char set_current_scenario(long num);
    unsigned char verify_campaign_name(char* in_campaign_name);
    long get_scenario_list(char*** list, long& curr_scenario);
    long get_current_scenario();
    void notify_of_scenario_complete();
    int open_scenario();
};

class RGE_Person_Info {
  public:
    char name[256];
    int current_campaign;
    int campaign_info_num;
    RGE_Campaign_Info** campaign_info;
    int campaign_num;
    RGE_Campaign** campaigns;

    RGE_Person_Info(int infile, RGE_Campaign** in_campaigns, long in_campaign_num);
    RGE_Person_Info(char* in_name, RGE_Campaign** in_campaigns, long in_campaign_num);
    ~RGE_Person_Info();
    void dtor();

    void save(int outfile);
    void rehook_campaigns(RGE_Campaign** in_campaigns, long in_campaign_num);
    unsigned char set_current_campaign(long num);
    long get_current_campaign();
    long get_current_scenario();
    unsigned char set_current_scenario(long num);
    long get_scenario_list(char*** list, long& current_scenario);
    void notify_of_scenario_complete();
    int open_scenario();
    char* get_name();
};

class RGE_Game_Info {
  public:
    int current_person;
    int people_num;
    RGE_Person_Info** people_info;
    int campaign_num;
    RGE_Campaign** campaigns;
    char save_filename[260];

    RGE_Game_Info(char* filename);
    ~RGE_Game_Info();

    void save(char* filename);
    void find_campaigns();
    unsigned char add_new_person(char* name);
    unsigned char set_current_person(long num);
    unsigned char set_current_campaign(long num);
    unsigned char set_current_scenario(long num);
    long get_people_list(char*** list, long& current_player);
    long get_campaign_list(char*** list, long& current_campaign);
    long get_scenario_list(char*** list, long& current_scenario);
    long get_current_scenario();
    long get_current_campaign();
    long get_current_player();
    char* get_current_player_name();
    void notify_of_scenario_complete();
    int open_scenario();
    void remove_player(long id);
};

typedef char rge_game_info_size_check[(sizeof(RGE_Game_Info) == 0x118) ? 1 : -1];

#endif
