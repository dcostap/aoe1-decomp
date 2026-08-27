#ifndef AOE1_GAMEINFO_H
#define AOE1_GAMEINFO_H

struct RGE_Scenario_Info {
    unsigned char scenario_status;
};

class RGE_Campaign;
class RGE_Campaign_Info;
class RGE_Person_Info;
class RGE_Game_Info;

extern "C" int __cdecl rge_read(int fd, void* buffer, int size);
extern "C" int __cdecl rge_write(int fd, void* buffer, int size);
extern "C" int __cdecl rge_open(char* path, int mode, ...);
extern "C" int __cdecl rge_close(int fd);
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" void __cdecl free(void* pointer);
extern "C" char* __cdecl strcpy(char* destination, const char* source);
extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern "C" void __cdecl getstring(char** destination, char* source);
extern "C" void __cdecl operator_delete(void* pointer);

class TDebuggingLog {
public:
    void __cdecl Log(char* format, ...);
};

extern TDebuggingLog* L;
extern int version_marker;

class RGE_Campaign {
public:
    char gap_00[0x20C];

    char* get_name();
    long scenario_number();
    char* get_scenario_name(long index);
    int open_scenario(long index);

    RGE_Campaign(char* filename);
    ~RGE_Campaign();
    void dtor();
};

class RGE_Prog_Info {
public:
    char gap_00[0xD1C];
    char campaign_dir[256];
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[8];
    RGE_Prog_Info* prog_info;
};

extern RGE_Base_Game* rge_base_game;

class RGE_Campaign_Info {
public:
    char name[256];
    int current_scenario;
    int scenario_num;
    RGE_Scenario_Info* scenario_info;
    int last_scenario;
    RGE_Campaign* campaign;

    RGE_Campaign_Info(int fd, RGE_Campaign** campaigns, long count);
    RGE_Campaign_Info(RGE_Campaign* campaign);
    ~RGE_Campaign_Info();

    void save(int fd);
    void rehook_campaigns(RGE_Campaign** campaigns, long count);
    unsigned char set_current_scenario(long scenario);
    unsigned char verify_campaign_name(char* campaign);
    long get_scenario_list(char*** list, long& current);
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

    RGE_Person_Info(int fd, RGE_Campaign** campaigns, long count);
    RGE_Person_Info(char* name, RGE_Campaign** campaigns, long count);
    ~RGE_Person_Info();
    void dtor();

    void save(int fd);
    void rehook_campaigns(RGE_Campaign** campaigns, long count);
    unsigned char set_current_campaign(long campaign);
    long get_current_campaign();
    long get_current_scenario();
    unsigned char set_current_scenario(long scenario);
    long get_scenario_list(char*** list, long& count);
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
    char save_filename[256];

    RGE_Game_Info(char* path);
    ~RGE_Game_Info();

    void save(char* path);
    void find_campaigns();
    unsigned char add_new_person(char* name);
    unsigned char set_current_person(long person);
    unsigned char set_current_campaign(long campaign);
    unsigned char set_current_scenario(long scenario);
    long get_people_list(char*** list, long& current);
    long get_campaign_list(char*** list, long& current);
    long get_scenario_list(char*** list, long& current);
    long get_current_scenario();
    long get_current_campaign();
    long get_current_player();
    char* get_current_player_name();
    void notify_of_scenario_complete();
    int open_scenario();
    void remove_player(long person);
};

#endif
