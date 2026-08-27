#ifndef AOE1_SCENARIO_H
#define AOE1_SCENARIO_H

// Declarations for the original scenario.cpp source module.

typedef unsigned char uchar;
typedef unsigned int uint;

class TPanel;
class RGE_Static_Object;
class RGE_Game_World;
class RGE_Scenario;
class RGE_Scenario_Header;
class RGE_Scenario_File_Info;

class RGE_Prog_Info {
public:
    char gap_000[0xC17];
    char scenario_dir[0x100];
    char gap_D17[0x314];
    char ai_dir[0x100];
};

class RGE_Timeline {
public:
    virtual ~RGE_Timeline();
    RGE_Game_World* world;
    void* time_list;
    short list_num;
    short avail_id;
    float old_time;
    RGE_Timeline(RGE_Game_World* world);
    RGE_Timeline(int file, RGE_Game_World* world);
    void update();
    void save(int file);
};

class TPicture {
public:
    void* Dib;
    void* BitmapInfo;
    unsigned char* Bits;
    void* TransInfo;
    int OwnMemory;
    int Width;
    int Height;
    short Orien;
    TPicture(char* name, long a, int b, void* c, int d);
    TPicture(int file_handle, int param_2);
    ~TPicture();
    void Save(int file);
};

class RGE_Scenario_Header {
public:
    virtual long get_size();
    virtual void save(int file);

    int error_code;
    int version;
    int checksum;
    char* description;

    RGE_Scenario_Header(RGE_Scenario* scenario);
    RGE_Scenario_Header(int file);
    ~RGE_Scenario_Header();
};

class RGE_Scenario {
protected:
    virtual RGE_Static_Object* get_object_pointer(int object_id);

public:
    virtual ~RGE_Scenario();
    virtual void rehook();
    virtual void save(int file);

    RGE_Timeline* time_line;
    RGE_Game_World* world;
    char victory_conquest;
    char player_name[16][0x100];
    char pad_100D[3];
    char* scenario_name;
    char* description;
    char* hints;
    char* win_message;
    char* loss_message;
    char* historicle_notes;
    char TempText1[0xE0];
    char TempText2[0xE0];
    char TempText3[0xE0];
    char* BuildList[16];
    char* CityPlan[16];
    char* AiRules[16];
    unsigned char* BuildListFile[16];
    unsigned char* CityPlanFile[16];
    unsigned char* AiRulesFile[16];
    int BuildListFileSize[16];
    int CityPlanFileSize[16];
    int AiRulesFileSize[16];
    char Cine_PreGame[0xE0];
    char Cine_Victory[0xE0];
    char Cine_Loss[0xE0];
    char Mission_Bmp[0xE0];
    float Version;
    int PlayerPosture[16];
    int PlType[16];
    int PlCivilization[16];
    int PlActive[16];
    TPicture* mission_picture;

    RGE_Scenario(RGE_Game_World* world);
    RGE_Scenario(int file, RGE_Game_World* world);
    void InitializeTextValues();
    void Set_scenario_name(char* text);
    void Set_description(char* text);
    void Set_Cine_PreGame(char* text);
    void Set_Cine_Victory(char* text);
    void Set_Cine_Loss(char* text);
    void Set_Mission_Bmp(char* text);
    void Set_BuildList(int player, char* text, int flag);
    void Set_CityPlan(int player, char* text, int flag);
    void Set_player_AI(int player, char* text, int flag);
    void Set_Version(float version);
    void Set_player_Type(int player, int value);
    void Set_player_Civ(int player, int value);
    void Set_player_Active(int player, int value);
    void SetPlayerName(int player, char* name);
    char* Get_scenario_name();
    char* Get_description();
    char* Get_Cine_PreGame();
    char* Get_Cine_Victory();
    char* Get_Cine_Loss();
    char* Get_Mission_Bmp();
    char* Get_BuildList(int player, int use_file);
    char* Get_CityPlan(int player, int use_file);
    float Get_Version();
    char* Get_player_AI(int player, int use_temp_file);
    int GetPlayerPosture(int player);
    char* GetPlayerName(int player);
    int Get_player_Type(int player);
    int Get_player_Civ(int player);
    int Get_player_Active(int player);
    void update();
    int active_player_count();
    int any_player_count();
    int computer_player_count();
    void Set_conquest_victory(unsigned char value);
    unsigned char Get_conquest_victory();
    void add_description(char* text);
    void Set_message(char* text, long field_index);
    char* Get_message(long field_index);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void* param_1, uint param_2, uint param_3, long param_4);
    virtual void set_prog_mode(int param_1);
    virtual void set_game_mode(int param_1, int param_2);
    virtual void set_player(short param_1);
    virtual int get_error_code();
    virtual char* get_string(int param_1, long param_2, char* param_3, int param_4);
    virtual char* get_string(long param_1, char* param_2, int param_3);
    virtual char* get_string(long param_1);
    virtual char* get_string2(int param_1, long param_2, long param_3, char* param_4, int param_5);
    virtual TPanel* get_view_panel();
    virtual TPanel* get_map_panel();
    virtual RGE_Scenario_Header* new_scenario_header(RGE_Scenario* scenario);
    virtual RGE_Scenario_Header* new_scenario_header(int file);
    virtual RGE_Scenario* new_scenario_info(int file);

    char gap_04[8];
    RGE_Prog_Info* prog_info;
};

extern RGE_Base_Game* rge_base_game;

struct RGE_Scenario_File_Entry {
    long time;
    RGE_Scenario_Header* scenario_header;
    char name[260];
};

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

#endif
