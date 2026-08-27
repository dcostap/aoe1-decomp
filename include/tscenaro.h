#ifndef AOE1_TSCENARO_H
#define AOE1_TSCENARO_H

// Declarations for the scenario source module.

typedef unsigned char uchar;

extern const double DAT_00577330;

class RGE_Game_World;
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
};
class TRIBE_Player;
class TRIBE_Player_Tech;
class RGE_Player;
class RGE_Timeline {
public:
    void update();
};

class RGE_Victory_Conditions {
public:
    void destroy_all();
    unsigned char add_explore(unsigned char, long, unsigned char);
    unsigned char add_attributes(unsigned char, long, long, unsigned char);
    unsigned char add_capture(unsigned char, RGE_Static_Object*, unsigned char);
    unsigned char add_bring(unsigned char, RGE_Static_Object*, RGE_Static_Object*);
    unsigned char add_bring(unsigned char, RGE_Static_Object*, float, float, float, float);
    unsigned char add_create(unsigned char, long, long, unsigned char);
    unsigned char add_create(unsigned char, long, long, float, float, float, float, unsigned char);
    unsigned char add_tech(unsigned char, long);
    unsigned char add_destroy(unsigned char, long, RGE_Player*);
    unsigned char add_destroy(unsigned char, long, long, RGE_Player*);
    unsigned char add_destroy(unsigned char, RGE_Player*);
    unsigned char add_destroy(unsigned char, RGE_Static_Object*);
};

class RGE_Effects {
public:
    virtual ~RGE_Effects();
    virtual void save(int file);
    virtual void do_effect(short effect_id, RGE_Player* player);
};

class TRIBE_Player {
public:
    char gap_00[0x4A];
    short player_number;
    char gap_4C[4];
    void* object_50;
    char gap_54[0x1CC];
    TRIBE_Player_Tech* tech_tree;
    void tech_abling(int, uchar);
    void rev_tech(int);
};

class TRIBE_Player_Tech {
public:
    unsigned char check_for_new_tech();
};

class RGE_Base_Game {
public:
    char gap_00[0x1B0];
    int prog_mode;
};

extern RGE_Base_Game* rge_base_game;

class TPicture;

struct Player_Start_Info {
    int Gold;
    int Wood;
    int Food;
    int Stone;
};

struct Victory_Info {
    int MP_Conquest;
    int MP_Ruins;
    int MP_Artifacts;
    int MP_Discoveries;
    int MP_Exploration;
    int MP_Gold;
};

struct Friendliness {
    int Attitude[16];
};

struct SP_Victory_Info {
    int ObjType;
    int AllFlag;
    int PlayerID;
    int DestObjID;
    float x1;
    float y1;
    float x2;
    float y2;
    int VictoryType;
    int Amount;
    int AttribType;
    int obj_ID;
    int dest_obj_ID;
    void* obj;
    void* dest_obj;
};

struct SP_Victory_Raw_Objects {
    char gap_00[0x2C];
    int sp_victory_obj_id[1024];
};

struct SP_Victory_Raw_Dest_Objects {
    char gap_00[0x30];
    int sp_victory_dest_obj_id[1024];
};

class RGE_Scenario {
protected:
    virtual RGE_Static_Object* get_object_pointer(int);

public:
    virtual ~RGE_Scenario();
    virtual void rehook();
    virtual void save(int);

    RGE_Timeline* time_line;
    RGE_Game_World* world;
    unsigned char victory_conquest;
    char player_name[16][0x100];
    char pad_100d[3];
    char* scenario_name;
    char* description;
    char* hints;
    char* win_message;
    char* loss_message;
    char* historicle_notes;
    char temp_text_1[0xE0];
    char temp_text_2[0xE0];
    char temp_text_3[0xE0];
    char* build_list[16];
    char* city_plan[16];
    char* ai_rules[16];
    unsigned char* build_list_file[16];
    unsigned char* city_plan_file[16];
    unsigned char* ai_rules_file[16];
    int build_list_file_size[16];
    int city_plan_file_size[16];
    int ai_rules_file_size[16];
    char cine_pre_game[0xE0];
    char cine_victory[0xE0];
    char cine_loss[0xE0];
    char mission_bmp[0xE0];
    float version;
    int player_posture[16];
    int pl_type[16];
    int pl_civilization[16];
    int pl_active[16];
    TPicture* mission_picture;

    char* Get_player_AI(int, int);
    char* Get_CityPlan(int, int);
    char* Get_BuildList(int, int);
    int GetPlayerPosture(int);
    int Get_player_Active(int);
    int active_player_count();
    void Set_conquest_victory(uchar);

    RGE_Scenario(RGE_Game_World*);
    RGE_Scenario(int, RGE_Game_World*);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x38];
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
    char gap_44[8];
    RGE_Effects* field_4C;
    RGE_Static_Object* object(int);
};

class RGE_Scenario_Header {
public:
    int error_code;
    long version;
    unsigned long checksum;
    char* description;

    virtual long get_size();
    virtual void save(int);
    RGE_Scenario_Header(RGE_Scenario*);
    RGE_Scenario_Header(int);
    ~RGE_Scenario_Header();
};

class T_Scenario : public RGE_Scenario {
private:
    virtual RGE_Static_Object* get_object_pointer(int);

public:
    virtual ~T_Scenario();
    virtual void rehook();
    virtual void save(int);

    Player_Start_Info player_info[16];
    Victory_Info victory;
    union {
        SP_Victory_Info sp_victory[16][12];
        char player_data[16][0x2d0];
        SP_Victory_Raw_Objects raw_objects;
        SP_Victory_Raw_Dest_Objects raw_dest_objects;
    };
    Friendliness Opponent[16];
    int AlliedVictory[16];
    int victory_all_flag;
    int is_multi_player_flag;
    int which_player;
    int DisabledTechnology[16][20];
    int ScenarioOptions[3];
    int PlayerAge[16];
    int mp_victory_type;
    int victory_score;
    int victory_time;

    T_Scenario(RGE_Game_World*);
    T_Scenario(int, RGE_Game_World*);

    void ClearSPVictoryCondition(int);
    int GetDisabledTechnology(int, int);
    int GetMPVictory();
    int GetPlayerAge(int);
    int GetPlayerAlliedVictory(int);
    int GetSPAllFlag(int);
    int GetSPAmount(int);
    int GetSPAttribType(int);
    RGE_Static_Object* GetSPDestObjectID(int);
    RGE_Static_Object* GetSPObject(int);
    int GetSPObjectType(int);
    int GetSPPlayerID(int);
    void GetSPRectangle(int, float*, float*, float*, float*);
    int GetSPVictoryType(int);
    int GetSPWhich();
    int GetScenarioOption(int);
    int GetVictoryScore();
    int GetVictoryTime();
    int Get_Multi_Artifacts();
    int Get_Multi_Conquest();
    int Get_Multi_Discoveries();
    int Get_Multi_Exploration();
    int Get_Multi_Gold();
    int Get_Multi_Ruins();
    int Get_player_Food(int);
    int Get_player_Gold(int);
    Player_Start_Info* Get_player_Info(int);
    int Get_player_Stone(int);
    int Get_player_Wood(int);
    int Get_player_attitude(int, int);
    int Get_victory_all_flag();
    void InitializeAIInformation();
    void InitializeFriendlinessValues();
    void InitializePlayerValues();
    void InitializeVictoryValues();
    void Save_victory_conditions_into_players(int);
    void SetDisabledTechnology(int, int, int);
    void SetMPVictory(int);
    void SetPlayerAge(int, int);
    void SetPlayerAlliedVictory(int, int);
    void SetSPAllFlag(int, int);
    void SetSPAmount(int, int);
    void SetSPAttribType(int, int);
    void SetSPDestObjectID(int, RGE_Static_Object*);
    void SetSPObject(int, RGE_Static_Object*);
    void SetSPObjectType(int, int);
    void SetSPPlayerID(int, int);
    void SetSPRectangle(int, float, float, float, float);
    void SetSPVictoryType(int, int);
    void SetSPWhich(int);
    void SetScenarioOption(int, int);
    void SetVictoryScore(int);
    void SetVictoryTime(int);
    void Set_Multi_Artifacts(int);
    void Set_Multi_Conquest(int);
    void Set_Multi_Discoveries(int);
    void Set_Multi_Exploration(int);
    void Set_Multi_Gold(int);
    void Set_Multi_Ruins(int);
    void Set_player_Food(int, int);
    void Set_player_Gold(int, int);
    void Set_player_Info(int, Player_Start_Info*);
    void Set_player_Stone(int, int);
    void Set_player_Wood(int, int);
    void Set_player_attitude(int, int, int);
    void Set_victory_all_flag(int);
    int any_sp_victory();
    void set_player_tech(TRIBE_Player*);
    void update();

private:
    void ClearDisabledTechnologies();
    void SaveAttributesIntoPlayers();
    int get_object_ID(RGE_Static_Object*);
    void WriteDisabledTechnologiesToMainSystem();
};

class TRIBE_Scenario_Header : public RGE_Scenario_Header {
public:
    int any_sp_victory;
    int active_player_count;

    TRIBE_Scenario_Header(T_Scenario*);
    TRIBE_Scenario_Header(int);
    virtual long get_size();
    virtual void save(int);
};

#endif
