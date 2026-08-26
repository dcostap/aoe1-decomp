#ifndef AOE1_TRIBEGAM_CONTEXT_H
#define AOE1_TRIBEGAM_CONTEXT_H

#include <stdio.h>
#include <mbstring.h>

// Canonical tribegam.cpp context for the validated prefix owners.
// Evidence: original PDB source order, exact constructor/destructor/cleanup
// anchors, and the repaired setup_palette/setup_sounds owners. This header is
// only for the grouped module. It is not a complete game class declaration.

struct RGE_Prog_Info;
class RGE_Game_Info;
class RGE_Game_World;
struct RGE_Player_Info;
struct XYZBYTEPoint;
class RGE_Sound;
class RGE_Static_Object;
class RGE_Player;
class RGE_Object_List;
class RGE_Object_Node;
class RGE_Victory_Conditions;
class RGE_Master_Static_Object;
class TRIBE_Command;
class AIPlayBook;
class RGE_Scenario;
class RGE_Scenario_Header;
class TRIBE_World;
class TCommunications_Handler;
class TribeJoinScreen;
class TPanelSystem;
class TPanel;
class TPicture;
class TScreenPanel;
class TSound_Driver;
class TMusic_System;
class TDigital;
struct MouseClickInfo;
class RGE_Visible_Map;

class TSound_Driver {
public:
    unsigned char pad_00;
    unsigned char game_loading;
    unsigned char sound_enabled;
};

extern char DAT_0086BCE0[];
extern int video_codec_available;
extern "C" void __cdecl RESFILE_build_res_file(const char* name, const char* dir, char* out);
extern "C" void __cdecl RESFILE_open_new_resource_file(const char* name,
                                                        const char* tribe,
                                                        char* out, int flag);
extern "C" int __stdcall ICInfo(unsigned int fccType, unsigned int dwHandler,
                                 void* pICI);

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    unsigned char selected;
    unsigned char object_type;
    RGE_Static_Object* get_target_obj();
    long get_action_checksum();
};

struct RGE_Timing_Info {
    unsigned long accum_time;
    unsigned long last_time;
    unsigned long start_time;
    int include_in_total;
    int is_summary;
    unsigned long last_single_time;
    unsigned long max_time;
    unsigned long last_max_time;
};

struct ScenarioFileInfo {
    int attrib;
    long time_create;
    char rest[0x114];
};

enum SaveMode {
    SaveModeA = 4,
    SaveModeB = 6,
    SaveModeC = 7,
    SaveModeD = 5
};

enum { SERVICE_AVAILABLE = 5 };

class TDrawSystem {
public:
    void SetPalette(void* palette);
    void ClearPrimarySurface();
    int SetDisplaySize(long wid, long hgt, int bits);
    unsigned char CheckSurfaces();
    void ClearRestored();
    void* palette;
    long ScreenWidth;
    long ScreenHeight;
    unsigned char ScreenMode;
    int IsModeAvail(long width, long height, int bits);
};

class TMusic_System {
public:
    char gap_00[0x104];
    unsigned char music_type;
    char gap_105[0x3];
    int play_track(int track, int position, unsigned long loop);
    int play_file(char* file, int position, unsigned long loop);
    void play_tracks();
    int play_tracks(int track, int track_count, int loop, int unknown1,
                    int unknown2);
    int stop_track();
    int track_count;
};

class TRegistry {
public:
    char* RegGetAscii(int value, char* name);
};

class TDebuggingLog {
public:
    void __cdecl Log(char* format, ...);
};
extern TDebuggingLog* L;
extern void __cdecl Log(TDebuggingLog* log, char* format, ...);

class TChat {
public:
    void ClearChat();
    void setInChatGroup(int player, int enabled);
};

class TMousePointer {
public:
    void center();
    int Shutdown_Mouse();
};

class TRIBE_Command {
public:
    void command_save_game();
    void command_quick_build(short value);
};

class AIPlayBook {
public:
    int playNumber(char* name);
};

class RGE_Game_Options {
public:
    char gap_00[0x86];
    unsigned char multiplayerGameValue;
    char gap_87[0x21];
};

class TribePlayerInfo {
public:
    char gap_00[0x7C];
    short playerNum;
};

class TPanel {
public:
    char gap_00[0x4C8];
    TPanel* previousPanelValue;
    char* panelName();
    void popupOKDialog(int string_id, char* text, int value1, int value2);
};

// TPanel is kept as the proven panel lookup surface above. These layout-only
// bases provide the canonical status and mission screen ABI.
class TPanelLayout {
public:
    virtual ~TPanelLayout();
    char gap_04[0xD4];
    int error_code;
    unsigned short interface_messages;
    char gap_DC[0x18];
};

class TEasy_Panel : public TPanelLayout {
public:
    virtual ~TEasy_Panel();
    char gap_F4[0x384];
    void popupOKDialog(int string_id, char* text, int value1, int value2);
};

// Inventory sizes: TScreenPanel is 0x478 and the status screen is 0x47C.
class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TRIBE_Screen_Status_Message : public TScreenPanel {
public:
    TPanel* message;
    TRIBE_Screen_Status_Message(char* panel_name, char* text,
                                char* info_file, long info_id);
    TRIBE_Screen_Status_Message(char* panel_name, int text,
                                char* info_file, long info_id);
    void set_text(char* text);
};

class TRIBE_Mission_Screen : public TScreenPanel {
public:
    char gap_478[0x24];
    TRIBE_Mission_Screen(char* description, unsigned char flag,
                         TPicture* picture);
};

class TribeAchievementsScreen : public TScreenPanel {
public:
    char gap_478[0x180];
    virtual ~TribeAchievementsScreen();
    TribeAchievementsScreen(char* message, int end_game);
};

class TRIBE_Screen_Game {
public:
    int error_code;
    unsigned short interface_messages;
    void game_mode_changed(int old_mode, int new_mode);
    void player_changed(int old_player, int new_player);
    char gap_00[0x4B8];
    TPanel* main_view;
    TPanel* map_view;
    void show_timings(void* param1, void* param2);
    void show_comm(char* a, char* b, char* c, char* d, char* e, char* f);
    void show_ai(char* a, char* b, char* c, char* d, char* e, char* f);
    void setup_buttons();
    void show_message(int type, char* text, unsigned char color1,
                      unsigned char color2);
    void display_system_message(char* text);
    void reset_clocks();
    void handle_game_update();
    void handle_pause();
    void handle_resume();
    void handleChatReceived(unsigned long value);
};

class TRIBE_Screen_Wait {
public:
    int error_code;
    void set_text(long string_id);
    void set_text(char* text);
};

class TRIBE_Screen_Sed {
public:
    int need_to_save_flag;
    TRIBE_Screen_Sed(char* scenario_filename, int mode);
    virtual ~TRIBE_Screen_Sed();
};

class TribeMPSetupScreen {
public:
    int field_D8;
    TribeMPSetupScreen();
};

class TRIBE_Screen_Main_Error {
public:
    int field_D8;
    TRIBE_Screen_Main_Error();
    void set_text(int value);
};

// BINARY NOTE: the constructor FPO symbol uses the struct spelling for this
// pointer parameter, so keep the tag kind in the grouped module context.
struct RGE_Prog_Info {
public:
    char gap_00[0x410];
    void* instance;
    char gap_414[0x104];
    char cmd_line[0x100];
    char gap_618[0x2C8];
    long main_wid;
    long main_hgt;
    char gap_8E8[0x22A];
    char save_dir[0x105];
    char scenario_dir[0x105];
    char gap_D1C[0x414];
    char avi_dir[0x105];
    char resource_dir[0x105];
    char game_data_file[261];
    int skip_startup;
    char gap_1235[0x3];
};

class TPanelSystem {
public:
    TPanel* panel(char* panel_name);
    int restorePreviousPanel(int mode);
    int destroyPanel(char* name);
    int setCurrentPanel(char* name, int mode);
    TPanel* currentPanel();
};

extern TPanelSystem panel_system;

class RGE_Game_Info {
public:
    long current_person;
    long people_num;
    void* people_info;

    unsigned char set_current_person(long person);
    unsigned char set_current_campaign(long campaign);
    char* get_current_player_name();
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char value);
    virtual void do_resign(int value);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int value);
    virtual int isEnemy(int player);
    virtual int isAlly(int player);
    virtual int isNeutral(int player);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int player, int stance);
    virtual void loadAIInformation(char* ai1, char* ai2, char* ai3,
                                   int value1, int value2);
    virtual void sendUnitAIOrder(int a, int b, int c, int d, int e,
                                 float f, float g, float h, float i,
                                 int j, int k, int l);
    virtual void processAIOrder(int a, int b, int c, int d, int e,
                                float f, float g, float h, float i,
                                int j, int k, int l);
    virtual void kickAI(int value);
    virtual int strategicNumber(int value);
    virtual void sendGameOrder(RGE_Static_Object* first,
                               RGE_Static_Object* second, float x, float y);
    virtual void sendAddWaypointCommand(int value, XYZBYTEPoint* point,
                                        int count);
    virtual void processAddWaypointCommand(int value, XYZBYTEPoint* point,
                                           int count);
    virtual void sendPlayCommand(int value, int* data, int a, int b, int c);
    virtual void sendPlayCommand(int value, int a, int b);
    virtual int sendAICommand(int a, int b, int c, int d, int e);
    virtual int objectCostByType(int value);
    virtual void trackUnitGather(int a, int b, int c);
    virtual RGE_Static_Object* make_scenario_obj(float x, float y, float z,
                                                  short type,
                                                  unsigned char active,
                                                  float value);
    virtual void scenario_save(int file);
    virtual void scenario_load(int file, long* data, float value);
    virtual void scenario_postsave(int file);
    virtual void scenario_postload(int file, long* data, float value);
    virtual void load(int file);
    virtual void add_attribute_num(short attr, float value,
                                   unsigned char active);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int file);
    virtual void save2(int file);
    virtual void save_info(int file);
    virtual void random_start();
    virtual RGE_Static_Object* make_new_object(long id, float x, float y,
                                                float z, int type);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int value, int* first,
                                              int* second);
    virtual unsigned char command_make_move(RGE_Static_Object* object,
                                            float x, float y);
    virtual unsigned char command_make_work(RGE_Static_Object* object,
                                            float x, float y);
    virtual unsigned char command_make_do(RGE_Static_Object* object,
                                          float x, float y);
    virtual unsigned char command_stop();
    virtual unsigned char command_place_object(short type, float x, float y,
                                               float z);
    virtual void set_attribute(short attr, float value);

    char gap_00[0x7C];
    unsigned char game_status;
    char gap_81[0x3];
    int computerPlayer() const;
    int humanPlayer() const;
    char* name;
    const char* ai_name(int slot);
    unsigned char relation(long player);
    void notify(long player, int to_player, int event, long a, long b, long c);
    short id;
    unsigned char allied_victory;
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    RGE_Victory_Conditions* victory_conditions;
    short attribute_num;
    float* attributes;
    unsigned char civilization;
    unsigned char full_visibility;
    unsigned char fog_of_war;
    RGE_Visible_Map* visible;
    void unselect_object();
    void loss_if_game_on();
    void set_view_loc(float x, float y);
};

class TCommunications_Handler {
public:
    int IsLobbyLaunched();
    void SetPlayerHumanity(int player, int humanity);
    void SetMyGameOptions(void* data, int size);
    void GetMyGameOptions(void* data);
    void* GetMyGameOptions(unsigned long* size);
    void SetPlayerName(int player, char* name);
    void SendIResignMsg();
    void ShutdownGameMessages();
    int CountWaitingMessages();
    void GameOver();
    int UnlinkToLevel(int level);
    int LaunchLobbyGame();
    char* GetCommInfo(int index);
    unsigned int GetRandomSeed();
    int GetPlayerHumanity(unsigned int player);
    int WhoAmI();
    char* GetPlayerName(unsigned int player);
    int MultiplayerGameStart();
    int IsPlayerHuman(unsigned int player);
    char* WaitingOnNamedInfo(unsigned int player);
    int IsHost();
    int WhoAmI(unsigned long param);
    int IsPlayerOutOfSync(int player);
};

// This is the shared world surface used by create_world and quit_game.
// The virtual slot at +0xB8 is proved by quit_game's del_game_info call.
class RGE_Game_World {
public:
    virtual unsigned char data_load_world(FILE* file);
    virtual unsigned char data_load_terrain_tables(char* name);
    virtual unsigned char data_load_players(char* name);
    virtual unsigned char data_load_objects(char* name);
    virtual unsigned char data_load_sounds(char* name);
    virtual unsigned char data_load_color_tables(char* name);
    virtual unsigned char data_load_sprites(char* name);
    virtual void data_load_players_type(short player, short type, FILE* file);
    virtual void data_load_effects(char* name);
    virtual void data_load_map(char* map, char* terrain, char* effect,
                               char* random, short width, short height,
                               short tile_set, RGE_Sound** sounds,
                               char* name);
    virtual void data_load_random_map(char* map, char* terrain,
                                      char* effect, char* random);
    virtual unsigned char init_player_type(int player, short type,
                                           unsigned char active);
    virtual unsigned char init_player(int player);
    virtual void load_player(int player, unsigned char type, short id);
    virtual void color_table_init(int table);
    virtual void terrain_tables_init(int table);
    virtual void init_sounds(int count, TSound_Driver* driver);
    virtual void init_sprites(int count);
    virtual void map_init(int count, TSound_Driver* driver);
    virtual void effects_init(int count);
    virtual void master_player_init(int count);
    virtual void command_init(int count, TCommunications_Handler* comm);
    virtual void world_init(int count, TSound_Driver* driver,
                            TCommunications_Handler* comm);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info& info);
    virtual unsigned char new_random_game(RGE_Player_Info& info);
    virtual void save(int file);
    virtual void scenario_make_player(short player, unsigned char active,
                                      unsigned char type, unsigned char civ,
                                      char* name);
    virtual void scenario_make_map(int map);
    virtual unsigned char load_scenario(char* name, RGE_Player_Info* info);
    virtual unsigned char load_scenario(RGE_Player_Info& info);
    virtual void load_scenario1(int player, RGE_Player_Info& info);
    virtual void load_scenario2(int player, RGE_Player_Info& info);
    virtual void load_scenario3(int player, RGE_Player_Info& info);
    virtual void load_scenario4(int player, RGE_Player_Info& info);
    virtual void load_scenario5(int player, RGE_Player_Info& info);
    virtual void load_scenario6(int player, RGE_Player_Info& info);
    virtual void load_scenario7(int player, RGE_Player_Info& info);
    virtual void load_scenario8(int player, RGE_Player_Info& info);
    virtual void logStatus(FILE* file, int verbose);
    virtual ~RGE_Game_World();
    virtual void setup_player_colors();
    virtual void setup_player_colors(RGE_Player_Info* info);
    virtual unsigned char data_load(char* first, char* second);
    virtual unsigned char init(char* name, TSound_Driver* driver,
                               TCommunications_Handler* comm);
    virtual void turn_sound_off();
    virtual void del_game_info();
    virtual unsigned char update();
    virtual unsigned char get_game_state();
    virtual unsigned char check_game_state();
    virtual unsigned char load_world(int file);
    virtual unsigned char load_game(char* name);
    virtual unsigned char new_game(RGE_Player_Info& info, int flags);
    virtual unsigned char new_scenario(RGE_Player_Info& info, int flags);
    virtual unsigned char save_game(char* name);
    virtual void base_save(char* name);
    virtual void base_save(int file);
    virtual unsigned char save_scenario(char* name);
    virtual RGE_Scenario* get_scenario_info(char* name);
    virtual void pause(unsigned char value);
    virtual void scenario_init(int file, RGE_Game_World* world);
    virtual void scenario_init(RGE_Game_World* world);

    union {
        char gap_04[0x58];
        struct {
            char gap_04_fields[0x38];
            short player_num;
            char gap_3E_fields[2];
            RGE_Player** players;
            char gap_44_fields[0x18];
            short curr_player;
        };
    };
    RGE_Scenario* scenario;
    char gap_60[0x44];
    int campaign;
    int person;
    char gap_AC[0x58];
    int world_time;
    int old_world_time;
    float game_speed;
    RGE_Player* player_zero;

    void update_mutual_allies();
    void destroyGameData();
    void destroyGameData(int flag);
    char load_db_files(char* file1, char* file2);
    char loadGameData(char* file, void* sound, void* comm);
};

class TRIBE_World : public RGE_Game_World {
public:
    TRIBE_Command* command;
    AIPlayBook* playbook;
    void* tech;
    int victory_type;
    int artifact_count;
    int ruin_count;
    unsigned char countdown_victory;
    unsigned char gap_115[0x3];
    float countdown_clock;
    unsigned char score_displayed;
    unsigned char controllingComputerPlayer;
    unsigned char gap_11E[0x2];
    int sent_zone_score;
    unsigned char game_status;

    TRIBE_World();
    void send_zone_score_info();
    unsigned char save_game(char* name);
    long get_achievement(unsigned char param_1, char** param_2);
    RGE_Static_Object* object(int id);
    void send_cheat(short code);
};

class RGE_Scenario {
public:
    virtual RGE_Static_Object* get_object_pointer(int id);
    virtual ~RGE_Scenario();
    virtual void rehook();
    virtual void save(int file);
    char pad_0[0x198C];
    TPicture* picture;
    char* Get_description();
    int Get_player_Active(int player);
    int Get_player_Civ(int player);
    int Get_player_Type(int player);
    char* GetPlayerName(int player);
    void Set_player_Active(int player, int value);
};

class T_Scenario : public RGE_Scenario {
public:
    char pad_0[0x514C - 0x1994];
    T_Scenario(int param_1, RGE_Game_World* zero);
};

class RGE_Scenario_Header {
public:
    virtual long get_size();
    virtual void save(int file);
    int error_code;
    long version;
    unsigned long checksum;
    char* description;

    RGE_Scenario_Header(RGE_Scenario* param_1);
    RGE_Scenario_Header(int param_1);
};

class TRIBE_Scenario_Header : public RGE_Scenario_Header {
public:
    int any_sp_victory;
    int active_player_count;

    TRIBE_Scenario_Header(int param_1);
    TRIBE_Scenario_Header(RGE_Scenario* param_1);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    RGE_Base_Game(RGE_Prog_Info* prog_info, int flags);

    // The first four slots are proved by quit_game's set_prog_mode call.
    virtual int run();
    virtual long __stdcall wnd_proc(void* window, unsigned int message,
                                    unsigned int wparam, long lparam);
    virtual void set_prog_mode(int mode);
    virtual void set_game_mode(int mode, int sub_mode);
    virtual void set_player(short player);
    virtual int get_error_code();
    virtual char* get_string(int id, long param, char* buffer, int length);
    virtual char* get_string(long id, char* buffer, int length);
    virtual char* get_string(long id);
    virtual char* get_string2(int id, long p2, long p3, char* buffer, int length);
    virtual TPanel* get_view_panel();
    virtual TPanel* get_map_panel();
    virtual RGE_Scenario_Header* new_scenario_header(RGE_Scenario* scenario);
    virtual RGE_Scenario_Header* new_scenario_header(int scenario);
    virtual RGE_Scenario* new_scenario_info(int scenario);
    virtual void notification(int id, long p2, long p3, long p4, long p5);
    virtual int reset_comm();
    virtual void send_game_options();
    virtual void receive_game_options();
    virtual char* gameSummary();
    virtual int processCheatCode(int id, char* code);
    virtual int setup_music_system();
    virtual void shutdown_music_system();
    virtual int setup();

protected:
    virtual int setup_cmd_options();
    virtual int setup_class();
    virtual int setup_main_window();
    virtual int setup_graphics_system();
    virtual int setup_palette();

public:
    virtual int setup_mouse();
    virtual int setup_registry();
    virtual int setup_debugging_log();
    virtual int setup_chat();
    virtual int setup_comm();
    virtual int setup_sound_system();
    virtual int setup_fonts();

protected:
    virtual int setup_sounds();

public:
    virtual int setup_shapes();
    virtual int setup_blank_screen();
    virtual void setup_timings();
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void stop_music_system();
    virtual int restart_music_system();

protected:
    virtual RGE_Game_World* create_world();
    virtual int handle_idle();
    virtual int handle_query_new_palette(void* window, unsigned int message,
                                         unsigned int wparam, long lparam);
    virtual int handle_activate(void* window, unsigned int message,
                                unsigned int wparam, long lparam);
    // Original FPO marks the timing, AI, and user-command base entries as
    // protected virtual members. These declarations pair with the public
    // TRIBE_Game overrides below and preserve their decorated symbols.
    virtual void calc_timing_text();
    virtual void show_timings();
    virtual void show_comm();
    virtual void show_ai();
    virtual int action_user_command(unsigned long param_1,
                                    unsigned long param_2);

    union {
        RGE_Game_Info* game_info;
        RGE_Game_Info* player_game_info;
    };
    void* scenario_info;
    RGE_Prog_Info* prog_info;
    void* prog_window;
    void* input_disabled_window;
    char gap_14[0x08];
    void* prog_palette;
    union {
        char gap_20[0x20];
        struct {
            char gap_20_fields[0x8];
            int random_game_seed;
            char gap_2C_fields[4];
            int save_random_game_seed;
        };
    };
    int prog_active;
    int random_game;
    int random_map;
    TMousePointer* mouse_pointer;
    int error_code;
    int is_timer;
    TDrawSystem* draw_system;
    void* draw_area;
    unsigned char outline_type;
    unsigned char gap_51[0x3];
    int custom_mouse;
    short shape_num;
    unsigned char gap_5A[0x2];
    void* shapes;
    TSound_Driver* sound_system;
    TMusic_System* music_system;
    short sound_num;
    unsigned char gap_6A[0x2];
    TDigital** sounds;
    char gap_70[0x108];
    TCommunications_Handler* comm_handler;
    char gap_190[0x1C];
    TRegistry* registry;
    int prog_mode;
    int field_1B4;
    int field_1B8;
    char gap_1BC[0x1C];
    int is_mouse_on;
    void* windows_mouse;
    char gap_1E0[0x214];
    union {
        TRIBE_World* world;
        TribePlayerInfo* tribeInfo;
    };
    union {
        char gap_3F8[0x500];
        struct {
            char timing_gap[0xC];
            char timing_text[0x100];
            unsigned long frame_count;
            unsigned long world_update_count;
            unsigned long view_update_count;
            unsigned long last_frame_count;
            unsigned long last_world_update_count;
            unsigned long last_view_update_count;
            unsigned long fps;
            unsigned long world_update_fps;
            unsigned long view_update_fps;
            RGE_Timing_Info timings[30];
            int do_show_timings;
            int do_show_comm;
            int do_show_ai;
        };
    };
    RGE_Game_Options rge_game_options;
    union {
        char gap_9A0[0x84];
        struct {
            int campaignGameValue;
            int savedGameValue;
            int quick_build;
        };
    };
    unsigned char resigned[9];

public:
    void setNumberPlayers(int number_players);
    int singlePlayerGame();
    void close();
    void draw_window();
    void set_render_all();
    int check_paint();
    void set_mouse_cursor(void* cursor);
    void mouse_on();
    void mouse_off();
    void enable_input();
    int multiplayerGame();
    int randomGame();
    int campaignGame();
    int difficulty();
    void reset_timings();
    int auto_paused;
    RGE_Player* get_player();
    void setMapSize(int x, int y, int z);
    int scenarioGame() const;
    int savedGame() const;
    int numberPlayers() const;
    int mapXSize() const;
    int mapYSize() const;
    void disable_input();
    void set_paused(int value);
    void set_paused(int value, int update);
    unsigned char check_prog_argument(char* argument);
    void set_map_visible(unsigned char value);
    void set_map_fog(unsigned char value);
    unsigned char check_prog_argument(const char* argument);
    void setSinglePlayerGame(int value);
    void setMultiplayerGame(int value);
    void setCampaignGame(int value);
    void setSavedGame(int value);
    void setScenarioGame(int value);
    void setScenarioName(char* name);
    void setFullVisibility(int value);
    void setFogOfWar(int value);
    void setAllowCheatCodes(int value);
    void setPlayerTeam(int player, int team);
    RGE_Scenario* get_scenario_info(char* name, int mode);
    int get_single_player_difficulty();
    void get_game_options(void* dst);
    void set_game_options(void* options);
    void setDifficulty(int difficulty);
    int fullVisibility() const;
    int fogOfWar() const;
    unsigned char pathFinding();
    unsigned char mpPathFinding();
    void setPlayerID(int player, int value);
    int playerID(int player);
    int reset_countdown_timer(int player);
    char* scenarioName();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    int game_state;
    int game_substate;
    // BINARY NOTE: FPO records use these nested enum types in return and
    // parameter symbols. Their storage remains the period four-byte ABI.
    enum MapSize { Tiny = 0, Small, Medium, Large, Huge, Humongous };
    enum MapType { MapType_Unknown = 0 };
    enum VictoryType { VictoryType_Unknown = 0 };
    enum ResourceLevel { ResourceLevel_Unknown = 0 };
    enum Age { Age_Unknown = 0 };
    struct TRIBE_Game_Options {
        int mapSizeValue;
        int mapTypeValue;
        int animalsValue;
        int predatorsValue;
        int victoryTypeValue;
        int victoryAmountValue;
        unsigned char civilizationValue[9];
        unsigned char gap_21[3];
        int scenarioPlayerValue[9];
        unsigned char playerColorValue[9];
        unsigned char computerNameValue[9];
        unsigned char allowTradingValue;
        unsigned char longCombatValue;
        unsigned char randomizePositionsValue;
        unsigned char fullTechTreeValue;
        unsigned char gap_5E[2];
        int resourceLevelValue;
        int startingAgeValue;
        unsigned char startingUnitsValue;
        unsigned char deathMatchValue;
        unsigned char popLimitValue;
        unsigned char gap_6B;
    };

    void* MouseRightClickTable;
    int MouseRightClickTableSize;
    void* MouseLeftClickTable;
    int MouseLeftClickTableSize;
    union {
        char gap_A34[0xB4];
        struct {
            long queue_is_waiting_on_pop_counter[9];
            int random_civ[9];
            TRIBE_Game_Options tribe_game_options;
        };
    };
    char testing_scenario[260];
    void* video_window;
    int cur_video;
    int (__stdcall *old_video_wnd_proc)();
    int video_paused;
    unsigned long last_video_time;
    int video_setup;
    int video_double_size;
    int video_changed_res;
    int video_hi_color;
    long video_save_res_wid;
    long video_save_res_hgt;
    void* video_save_palette;
    int started_menu_music;
    int show_object_id;
    union {
        TRIBE_Screen_Game* game_screen;
        TRIBE_Screen_Game* gameScreen;
    };
    long notification_loc_x[5];
    long notification_loc_y[5];
    long current_notification_loc;
    long current_notification_recalled;
    char startup_scenario[260];
    char startup_game[260];
    unsigned long auto_exit_time;
    char save_game_name[260];
    char load_game_name[260];
    char timing_text2[256];
    int save_humanity[9];
    unsigned char quick_start_game;
    unsigned char gap_1191[3];
    int random_start_value;
    unsigned char computerNameUsed[18][10];
    void* handleIdleLock;
    int inHandleIdle;

    virtual ~TRIBE_Game();
    virtual long __stdcall wnd_proc(void* window, unsigned int message,
                                    unsigned int wparam, long lparam);
    TRIBE_Game(RGE_Prog_Info* prog_info, int setup_game);
    virtual int setup_cmd_options();

    void close_game_screens(int destroy_game_screen);
protected:
    virtual int setup();

public:
    void setup(int param);

protected:
    virtual int setup_palette();
    virtual int setup_sounds();
    virtual RGE_Game_World* create_world();

public:
    virtual void set_game_mode(int mode, int sub_mode);
    void set_player(short player);
    void set_save_game_name(char* name);
    void set_load_game_name(char* name);
    char* get_save_game_name();
    char* get_load_game_name();
    virtual char* get_string(int id, long param, char* buffer, int length);
    virtual char* get_string(long id, char* buffer, int length);
    virtual char* get_string(long id);
    virtual char* get_string2(int id, long p2, long p3, char* buffer, int length);
    virtual TPanel* get_view_panel();
    virtual TPanel* get_map_panel();
    long video_wnd_proc(void* window, unsigned int message, unsigned int wparam, long lparam);
    virtual RGE_Scenario_Header* new_scenario_header(int scenario);
    virtual RGE_Scenario_Header* new_scenario_header(RGE_Scenario* scenario);
    virtual RGE_Scenario* new_scenario_info(int scenario);
    void show_error_message(int id);
    void show_status_message(char* text, char* format, long value);
    void show_status_message(int id, char* format, long value);
    void close_status_message();
    int setup_video_system();
    int start_video(int mode, char* file);
    void shutdown_video_system();
    char* game_over_msg();
    long video_sub_wnd_proc(void* window, unsigned int message, unsigned int wparam, long lparam);
    void stop_video(unsigned char mode);
    int start_campaign_menu();
    int start_menu();
    void quit_game();
    void restart_game();
    int load_db_files();
    int load_game_data();
    int save_game(char* name);
    int save_scenario(char* name);
    // FPO names these three TRIBE_Game overrides as public virtual members
    // (UAEXXZ). Keep the virtual surface in the grouped TU, not only in the
    // standalone owner stubs.
    virtual void calc_timing_text();
    void show_timings();
    void show_comm();
    virtual void show_ai();
    int start_game(int mode);
    int test_scenario(char* name);
    int start_scenario(char* name);
    int load_game(char* name);
    RGE_Game_World* createGameWorld();
    void do_game_over();
protected:
    int create_game(int mode);

public:
    int create_game_screen();
    int processCheatCode(char* code);
protected:
    void let_game_begin();

public:
    int start_scenario_editor(char* scenario_filename, int mode);
    void send_game_options();
    void receive_game_options();
    void set_tribe_options(void* options);
    void get_tribe_options(void* options);
    int mapSize();
    MapSize mapSize() const;
    void setMapSize(int value);
    void setMapSize(MapSize value);
    int mapType();
    MapType mapType() const;
    void setMapType(MapType value);
    int animals();
    int animals() const;
    void setAnimals(int value);
    int predators();
    int predators() const;
    void setPredators(int value);
    int victoryType();
    VictoryType victoryType() const;
    int victoryAmount();
    int victoryAmount() const;
    void setVictoryType(VictoryType type, int amount);
    int civilization(int player);
    int civilization(int player) const;
    int playerTeam(int player);
    void setCivilization(int player, int civilization);
    int scenarioPlayer(int player);
    int scenarioPlayer(int player) const;
    void setScenarioPlayer(int player, int value);
    int playerColor(int player);
    int playerColor(int player) const;
    void setPlayerColor(int player, int color);
    void setPlayerColor(int player, unsigned char color);
    int computerName(int player);
    int computerName(int player) const;
    void setComputerName(int player, int value);
    void setComputerName(int player, unsigned char value);
    int allowTrading();
    int allowTrading() const;
    void setAllowTrading(int value);
    int longCombat();
    int longCombat() const;
    void setLongCombat(int value);
    int randomizePositions();
    int randomizePositions() const;
    void setRandomizePositions(int value);
    int fullTechTree();
    int fullTechTree() const;
    void setFullTechTree(int value);
    ResourceLevel resourceLevel();
    int resourceLevel() const;
    void setResourceLevel(ResourceLevel value);
    Age startingAge();
    int startingAge() const;
    void setStartingAge(Age value);
    int startingUnits();
    int startingUnits() const;
    void setStartingUnits(int value);
    unsigned char deathMatch();
    unsigned char deathMatch() const;
    void setDeathMatch(unsigned char value);
    unsigned char popLimit();
    unsigned char popLimit() const;
    void setPopLimit(unsigned char value);
    void setQuickStartGame(unsigned char value);
    int randomStartValue();
    void setRandomStartValue(int value);
    void resetRandomComputerName();
    void SetClickTables(MouseClickInfo* right, int right_count,
                        MouseClickInfo* left, int left_count);
    int action_close(void* window, unsigned int message, unsigned int wparam, long lparam);
    virtual int action_close();
    virtual int action_key_down(unsigned long key, int param_2, int param_3,
                                int param_4, int param_5);
    virtual void set_interface_messages();
    void disconnect_multiplayer_game();
    void turn_world_sound_off();
    int handle_idle();
    int handle_query_new_palette(void* window, unsigned int message,
                                 unsigned int wparam, long lparam);
    int handle_activate(void* window, unsigned int message,
                        unsigned int wparam, long lparam);
    virtual int action_user_command(unsigned long param_1,
                                    unsigned long param_2);
    void add_notification_loc(long x, long y);
    void notification(int type, long a, long b, long c, long d);
    void play_sound(int sound_id);
    void message(int text_id, char* text, int max_len);
    long get_achievement_info(unsigned char param_1, char** param_2);
    void goto_notification_loc();
    char* gameSummary();
    void setMapSize(int x, int y, int z);
    void set_map_visible(unsigned char value);
    void set_map_fog(unsigned char value);
    int scenarioGame() const;
    int savedGame() const;
    int randomGame() const;
    int numberPlayers() const;
    int mapXSize() const;
    int mapYSize() const;
    unsigned char quickStartGame();
    unsigned char quickStartGame() const;
    int randomComputerName(int civ);
    int allowCheatCodes();
    int processCheatCode(int player_id, char* cheat);
    void set_tribe_options(TRIBE_Game_Options* options);
    void get_tribe_options(TRIBE_Game_Options* options);
};

class TribeJoinScreen {
public:
    virtual ~TribeJoinScreen();
    char gap_04[0x4AC];
    TribeJoinScreen();
};

#endif
