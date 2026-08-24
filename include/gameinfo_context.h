#ifndef AOE1_GAMEINFO_CONTEXT_H
#define AOE1_GAMEINFO_CONTEXT_H

// Canonical declarations for the original gameinfo.cpp translation unit.
// The owner files use GAMEINFO_SHARED_CONTEXT to omit their standalone
// declarations.  The order in src/gameinfo_tu.cpp follows the PDB line bands.

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
extern "C" long __cdecl _findfirst(const char* filespec, void* file_info);
extern "C" int __cdecl _findnext(long handle, void* file_info);
extern "C" void __cdecl getstring(char** destination, char* source);
extern "C" void __cdecl operator_delete(void* pointer);

struct TDebuggingLog {
    static void Log(void* log, char* format, ...);
};

extern void* L;
extern int version_marker;

class RGE_Campaign {
public:
    char* get_name();
    long scenario_number();
    char* get_scenario_name(int index);
    int open_scenario(int index);

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

#pragma pack(push, 4)
struct FindDataLocal {
    unsigned int attrib;
    int time_create;
    int time_access;
    int time_write;
    char name[260];
};

struct FindCampaignWork {
    FindDataLocal file_info;
    char file_name[260];
    char gap_21C[4];
};
#pragma pack(pop)

class RGE_Campaign_Info {
public:
    char name[256];                 // +0x000
    int current_scenario;           // +0x100
    int scenario_num;               // +0x104
    RGE_Scenario_Info* scenario_info; // +0x108
    int last_scenario;              // +0x10C
    RGE_Campaign* campaign;         // +0x110

    RGE_Campaign_Info(int fd, RGE_Campaign** camps, int count);
    RGE_Campaign_Info(RGE_Campaign* campaign);
    ~RGE_Campaign_Info();

    void save(int fd);
    void rehook_campaigns(RGE_Campaign** list, long count);
    unsigned char set_current_scenario(long scenario);
    unsigned char verify_campaign_name(char* campaign);
    long get_scenario_list(char*** list, long& current);
    int get_current_scenario();
    void notify_of_scenario_complete();
    int open_scenario();
};

class RGE_Person_Info {
public:
    char name[256];                 // +0x000
    int current_campaign;           // +0x100
    int campaign_info_num;          // +0x104
    RGE_Campaign_Info** campaign_info; // +0x108
    int campaign_num;               // +0x10C
    RGE_Campaign** campaigns;       // +0x110

    RGE_Person_Info(int fd, RGE_Campaign** camps, int count);
    RGE_Person_Info(char* name, RGE_Campaign** campaigns, long count);
    ~RGE_Person_Info();
    void dtor();

    void save(int fd);
    void rehook_campaigns(RGE_Campaign** campaigns, long count);
    unsigned char set_current_campaign(long campaign);
    long get_current_campaign();
    int get_current_scenario();
    unsigned char set_current_scenario(long scenario);
    int get_scenario_list(char*** list, long* count);
    void notify_of_scenario_complete();
    int open_scenario();
    char* get_name();
};

class RGE_Game_Info {
public:
    union {
        int current_person;         // +0x00
        int field_0;
    };
    int people_num;                 // +0x04
    RGE_Person_Info** people_info;  // +0x08
    int campaign_num;               // +0x0C
    RGE_Campaign** campaigns;       // +0x10
    char save_filename[256];       // +0x14

    RGE_Game_Info(char* path);
    ~RGE_Game_Info();

    void save(char* path);
    void find_campaigns();
    unsigned char add_new_person(int fd);
    unsigned char set_current_person(long person);
    unsigned char set_current_campaign(int campaign);
    unsigned char set_current_scenario(int scenario);
    long get_people_list(char*** list, long& current);
    long get_campaign_list(char*** list, long& current);
    long get_scenario_list(char*** list, long* current);
    long get_current_scenario();
    long get_current_campaign();
    int get_current_player();
    char* get_current_player_name();
    void notify_of_scenario_complete();
    int open_scenario();
    void remove_player(long person);
};

#endif
