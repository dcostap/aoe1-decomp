#ifndef AOE1_BASEGAME_H
#define AOE1_BASEGAME_H

#include <windows.h>

class RGE_Base_Game;
class RGE_Action_Gather;
class RGE_Campaign;
class RGE_Command;
class RGE_Dialog_List;
class RGE_Diamond_Map_View;
class RGE_Game_Info;
class RGE_Game_World;
class RGE_Master_Static_Object;
class RGE_Panel_Time;
class RGE_Panel_Tool_Box;
class RGE_View;
class TRIBE_History_Info;
class RGE_Diamond_Map;
class RGE_Map;
class RGE_Player;
class TRIBE_Player;
class TRIBE_Action_Build;
class TRIBE_Action_Hunt;
class TRIBE_Action_Make_Obj;
class TRIBE_Action_Make_Tech;
class TRIBE_Action_Wonder;
class TRIBE_Combat_Object;
class TRIBE_Campaign_Editor_Screen;
class TRIBE_Master_Building_Object;
class TRIBE_Mission_Screen;
class TRIBE_Panel_Inven;
class TRIBE_Panel_Object;
class TRIBE_Panel_Pop;
class TRIBE_Panel_Time;
class TRIBE_Screen_Campaign_Selection;
class TRIBE_Screen_Game;
class TRIBE_Screen_Info;
class TRIBE_Screen_Main_Error;
class TRIBE_Screen_Main_Menu;
class TRIBE_Screen_Name;
class TRIBE_Screen_Sed;
class TRIBE_Screen_Sed_Menu;
class TRIBE_Screen_Sed_Open;
class TRIBE_Screen_Status_Message;
class TRIBE_Scenario_Editor_Panel_Object;
class TRIBE_Credits_Screen;
class TRIBE_Command;
class TribeInformationAIModule;
class TribeAboutDialog;
class TribeAchievementsScreen;
class TribeConfigDialog;
class TribeDiplomacyDialog;
class TribeEndScreen;
class TribeLoadSavedGameScreen;
class TribeMenuDialog;
class TribeSPMenuScreen;
class TribeSaveGameScreen;
class TribeSelectScenarioScreen;
class TribeSelectTribeScreen;
class TribeSendMessageDialog;
class TribeSendQuickMessageDialog;
class TRIBE_Dialog_Name;
class TChat;
class TEditPanel;
class TEasy_Panel;
class TMessageDialog;
class THelpDialog;
class Time_Line_Panel;
struct RGE_Prog_Info;
class RGE_Scenario;
class RGE_Scenario_File_Info;
class RGE_Scenario_Header;
class T_Scenario;
class TCommunications_Handler;
class TDebuggingLog;
class TDrawArea;
class TDrawSystem;
class TMousePointer;
class TMusic_System;
class TPanel;
class TMessagePanel;
class TRegistry;
class TShape;
class TSound_Driver;
class TDigital;
class RGE_Communications_Synchronize;
class RGE_Main_View;
class TRIBE_Main_View;
class TribeJoinScreen;
class TribeMPCreateDialog;
class TribeMPSetupScreen;
class TribeGameSettingsScreen;
class TribeMPStartupScreen;
class TRIBE_Screen_Wait;
class TRIBE_Screen_Disconnect;
void __cdecl color_log(unsigned char, unsigned char, int);

unsigned long __cdecl debug_timeGetTime(char* source_name, int source_line);
int __cdecl debug_rand(char* source_name, int source_line);
void __cdecl debug_srand(char* source_name, int source_line, unsigned int seed);

// Error values returned by RGE_Base_Game::get_error_code().
enum RGE_Base_Game_Error_Code {
    RGE_ERROR_NONE = 0,
    RGE_ERROR_SETUP = 1,
    RGE_ERROR_SETUP_COMMAND_OPTIONS = 2,
    RGE_ERROR_CHECK_EXPIRATION = 3,
    RGE_ERROR_CHECK_MULTI_COPIES = 4,
    RGE_ERROR_SETUP_CLASS = 5,
    RGE_ERROR_SETUP_MAIN_WINDOW = 6,
    RGE_ERROR_SETUP_GRAPHICS = 7,
    RGE_ERROR_SETUP_MOUSE = 8,
    RGE_ERROR_SETUP_COMM = 9,
    RGE_ERROR_SETUP_SOUND = 10,
    RGE_ERROR_SETUP_FONTS = 11,
    RGE_ERROR_SETUP_SOUNDS = 12,
    RGE_ERROR_SETUP_BLANK_SCREEN = 13,
    RGE_ERROR_SETUP_REGISTRY = 14,
    RGE_ERROR_SETUP_DEBUG_LOG = 15,
    RGE_ERROR_SETUP_CHAT = 16,
    RGE_ERROR_SETUP_PALETTE = 17,
    RGE_ERROR_OUT_OF_SYNC = 18,
    RGE_ERROR_SETUP_COLOR_DEPTH = 19,
    RGE_ERROR_DIRECTX_VERSION = 20,
    RGE_ERROR_WINDOWS_VERSION = 21,
    RGE_ERROR_MEMORY = 22,
    RGE_ERROR_GAME_EXECUTABLE = 23
};

// Domains accepted by RGE_Base_Game::get_string2().
enum RGE_String_Type {
    RGE_STRING_TYPE_ERROR = 1,
    RGE_STRING_TYPE_RESOURCE = 2,
    RGE_STRING_TYPE_INVENTORY = 100,
    RGE_STRING_TYPE_AGE = 101,
    RGE_STRING_TYPE_COMMAND = 102,
    RGE_STRING_TYPE_ATTRIBUTE = 103,
    RGE_STRING_TYPE_ATTRIBUTE_NAME = 104,
    RGE_STRING_TYPE_CIVILIZATION = 105
};

enum RGE_Attribute_String_Id {
    RGE_ATTRIBUTE_ERROR_POPULATION_LIMIT = 0x20,
    RGE_ATTRIBUTE_MESSAGE_TRIBUTE_RECEIVED = 0x68,
    RGE_ATTRIBUTE_ERROR_NO_ROOM_FOR_UNIT = 1000,
    RGE_ATTRIBUTE_ERROR_NO_DOCKS = 0x65,
    RGE_ATTRIBUTE_ERROR_NOT_CLOSE_ENOUGH_TO_LAND = 0x66,
    RGE_ATTRIBUTE_ERROR_NOT_ENOUGH_UNLOAD_SPACE = 0x67,
    RGE_ATTRIBUTE_ERROR_CANNOT_TRADE_WITH_ENEMY = 0x69,
    RGE_ATTRIBUTE_ERROR_CANNOT_REPAIR = 0x6A
};

// Font index 11 is the normal Arial font loaded by setup_fonts().
enum RGE_Font_Index {
    RGE_FONT_STRIKEOUT = 8,
    RGE_FONT_STANDARD = 11
};

struct RGE_Font {
    void* font;
    long font_wid;
    long font_hgt;
};

typedef char rge_font_size_check[(sizeof(RGE_Font) == 0x0C) ? 1 : -1];

class RGE_Timing_Info {
public:
    unsigned long accum_time;
    unsigned long last_time;
    unsigned long start_time;
    int include_in_total;
    int is_summary;
    unsigned long last_single_time;
    unsigned long max_time;
    unsigned long last_max_time;
};

typedef char rge_timing_info_size_check[
    (sizeof(RGE_Timing_Info) == 0x20) ? 1 : -1];

class RGE_Base_Game {
    friend class RGE_Action_Gather;
    friend class RGE_Campaign;
    friend class RGE_Command;
    friend class RGE_Dialog_List;
    friend class RGE_Diamond_Map_View;
    friend class RGE_Game_Info;
    friend class RGE_Master_Static_Object;
    friend class RGE_Panel_Time;
    friend class RGE_Panel_Tool_Box;
    friend class RGE_Scenario_File_Info;
    friend class RGE_View;
    friend class TRIBE_Action_Build;
    friend class TRIBE_Action_Hunt;
    friend class TRIBE_Action_Make_Obj;
    friend class TRIBE_Action_Make_Tech;
    friend class TRIBE_Action_Wonder;
    friend class TRIBE_Combat_Object;
    friend class TRIBE_Campaign_Editor_Screen;
    friend class TRIBE_Master_Building_Object;
    friend class TRIBE_Mission_Screen;
    friend class TRIBE_Panel_Inven;
    friend class TRIBE_Panel_Object;
    friend class TRIBE_Panel_Pop;
    friend class TRIBE_Panel_Time;
    friend class TRIBE_Screen_Campaign_Selection;
    friend class TRIBE_Screen_Game;
    friend class TRIBE_Screen_Info;
    friend class TRIBE_Screen_Main_Error;
    friend class TRIBE_Screen_Main_Menu;
    friend class TRIBE_Screen_Name;
    friend class TRIBE_Screen_Sed;
    friend class TRIBE_Screen_Sed_Menu;
    friend class TRIBE_Screen_Sed_Open;
    friend class TRIBE_Screen_Status_Message;
    friend class TRIBE_Scenario_Editor_Panel_Object;
    friend class TRIBE_Credits_Screen;
    friend class TRIBE_Command;
    friend class TribeAboutDialog;
    friend class TribeAchievementsScreen;
    friend class TribeConfigDialog;
    friend class TribeDiplomacyDialog;
    friend class TribeEndScreen;
    friend class TribeLoadSavedGameScreen;
    friend class TribeMenuDialog;
    friend class TribeSPMenuScreen;
    friend class TribeSaveGameScreen;
    friend class TribeSelectScenarioScreen;
    friend class TribeSelectTribeScreen;
    friend class TribeSendMessageDialog;
    friend class TribeSendQuickMessageDialog;
    friend class TRIBE_Dialog_Name;
    friend class TChat;
    friend class TEditPanel;
    friend class TEasy_Panel;
    friend class TMessageDialog;
    friend class THelpDialog;
    friend class Time_Line_Panel;
    friend int __cdecl debug_rand(char*, int);
    friend void __cdecl debug_srand(char*, int, unsigned int);
    friend void* __cdecl ReadPalette(char*, long, int);
    friend void __cdecl color_log(unsigned char, unsigned char, int);
    friend class RGE_Player;
    friend class RGE_Static_Object;
    friend class TMessagePanel;
    friend class TPanel;
    friend class RGE_Game_World;
    friend class RGE_Diamond_Map;
    friend class RGE_Map;
    friend class TRIBE_Player;
    friend class TRIBE_History_Info;
    friend class TribeInformationAIModule;
    friend class TCommunications_Handler;
    friend class RGE_Communications_Synchronize;
    friend class RGE_Main_View;
    friend class TRIBE_Main_View;
    friend class TPanel;
    friend class RGE_Scenario;
    friend class T_Scenario;
    friend class TribeJoinScreen;
    friend class TribeMPCreateDialog;
    friend class TribeMPSetupScreen;
    friend class TribeGameSettingsScreen;
    friend class TribeMPStartupScreen;
    friend class TRIBE_Screen_Wait;
    friend class TRIBE_Screen_Disconnect;

public:
    struct RGE_Game_Options {
    public:
        float versionValue;
        unsigned char scenarioGameValue;
        char scenarioNameValue[128];
        unsigned char singlePlayerGameValue;
        unsigned char multiplayerGameValue;
        unsigned char mapXSizeValue;
        unsigned char mapYSizeValue;
        unsigned char mapZSizeValue;
        unsigned char allowCheatCodesValue;
        unsigned char mpPathFindingValue;
        unsigned char cheatNotificationValue;
        unsigned char fullVisibilityValue;
        unsigned char fogOfWarValue;
        unsigned char coloredChatValue;
        unsigned char numberPlayersValue;
        unsigned char gameDeveloperModeValue;
        unsigned char playerCDAndVersionValue[9];
        unsigned char difficultyValue;
        unsigned char playerTeamValue[9];
    };

    virtual ~RGE_Base_Game();
    virtual int run();
    virtual LRESULT CALLBACK wnd_proc(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);
    virtual void set_prog_mode(int value) { this->prog_mode = value; }
    virtual void set_game_mode(int new_mode, int new_sub_mode);
    virtual void set_player(short new_player_id);
    virtual int get_error_code();
    // VC5 reverses this adjacent overload group in the vtable.
    virtual char* get_string(long text_id);
    virtual char* get_string(long string_id, char* str, int max_len);
    virtual char* get_string(int string_type, long id, char* str, int max_len);
    virtual char* get_string2(int string_type, long id, long id2, char* str, int max_len);
    virtual TPanel* get_view_panel() { return 0; }
    virtual TPanel* get_map_panel() { return 0; }
    // VC5 reverses this adjacent overload pair in the vtable.
    virtual RGE_Scenario_Header* new_scenario_header(int infile);
    virtual RGE_Scenario_Header* new_scenario_header(RGE_Scenario* scenario_info);
    virtual RGE_Scenario* new_scenario_info(int infile);
    virtual void notification(int, long, long, long, long) {}
    virtual int reset_comm();
    virtual void send_game_options();
    virtual void receive_game_options();
    virtual char* gameSummary();
    virtual int processCheatCode(int, char*) { return 0; }
    virtual int setup_music_system();
    virtual void shutdown_music_system();
protected:
    virtual int setup();
    virtual int setup_cmd_options();
    virtual int setup_class();
    virtual int setup_main_window();
    virtual int setup_graphics_system();
    virtual int setup_palette();
    virtual int setup_mouse();
    virtual int setup_registry();
    virtual int setup_debugging_log();
    virtual int setup_chat();
    virtual int setup_comm();
    virtual int setup_sound_system();
    virtual int setup_fonts();
    virtual int setup_sounds();
    virtual int setup_shapes();
    virtual int setup_blank_screen();
    virtual void setup_timings();
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void stop_music_system();
    virtual int restart_music_system();
    virtual RGE_Game_World* create_world();
    virtual int handle_message(tagMSG*) { return 1; }
    virtual int handle_idle();
    virtual int handle_mouse_move(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);
    virtual int handle_key_down(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);
    virtual int handle_user_command(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);
    virtual int handle_command(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);
    virtual int handle_music_done(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);
    virtual int handle_paint(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);
    virtual int handle_activate(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);
    virtual int handle_init_menu(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);
    virtual int handle_exit_menu(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);
    virtual int handle_size(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);
    virtual int handle_palette_changed(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);
    virtual int handle_query_new_palette(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);
    virtual int handle_close(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);
    virtual int handle_destroy(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);
    virtual int action_update() { return 1; }
    virtual int action_mouse_move(long, long, int, int, int, int) { return 1; }
    virtual int action_key_down(unsigned long, int, int, int, int) { return 1; }
    virtual int action_user_command(unsigned long, unsigned long) { return 1; }
    virtual int action_command(unsigned long, unsigned long) { return 1; }
    virtual int action_music_done() { return 1; }
    virtual int action_activate() { return 1; }
    virtual int action_deactivate() { return 1; }
    virtual int action_init_menu() { return 1; }
    virtual int action_exit_menu() { return 1; }
    virtual int action_size() { return 1; }
    virtual int action_close() { return 1; }
public:
    void disable_input();
    void enable_input();
protected:
    virtual void calc_timings();
    virtual void calc_timing_text();
    virtual void show_timings();
    virtual void show_comm();
    virtual void show_ai();
    virtual int setup_map_save_area();
    virtual void set_interface_messages();

public:
    RGE_Base_Game(RGE_Prog_Info* prog_info_in, int do_setup);
protected:
    int check_expiration();
    int check_multi_copies();
public:
    int check_for_cd(int num_players);
    void close();
    int create_dialog(TPanel** dialog_ptr, TPanel* new_dialog);
    void delete_dialog(TPanel** dialog_ptr);
    unsigned char check_prog_argument(char* argument);
    void add_to_timing(int id, unsigned long time);
    int multiplayerGame() const;
    int randomGame() const;
    int campaignGame() const;
    int singlePlayerGame() const;
    int gameDeveloperMode() const;
    int playerTeam(int player_num);
    int playerID(int player_index);
    int difficulty();
    int campaign_open_scenario();
    float get_game_speed();
    void write_scenario_header(int outfile);
    void get_campaign_info(long& campaign, long& campaign_player, long& campaign_scenario);
    unsigned char set_campaign_info(long campaign, long campaign_player, long campaign_scenario);
    void set_campaign_win();
    unsigned long get_accum_time(int id);
    int get_paused();
    void set_paused(int paused_in, int non_user_pause_in);
    RGE_Player* get_player();
    void get_mouse_pos(tagPOINT& point);
    RGE_Font* get_font(int font_id);
    void setScenarioGame(int);
    void setVersion(float val);
    void setScenarioName(char* n);
    void setCampaignGame(int);
    void setSavedGame(int);
    void setSinglePlayerGame(int);
    void setMultiplayerGame(int);
    void setMapSize(int x, int y, int z);
    void setAllowCheatCodes(int);
    void setCheatNotification(int);
    void setFullVisibility(int);
    void setFogOfWar(int);
    void setColoredChat(int);
    void setNumberPlayers(int);
    void setGameDeveloperMode(int);
    void setPlayerHasCD(int player_num, int has_cd);
    void setPlayerVersion(int player_num, unsigned char player_version);
    void setPlayerCDAndVersion(int player_num, unsigned char val);
    void setDifficulty(int difficulty);
    void setPlayerTeam(int player_num, int team);
    void setPathFinding(unsigned char val);
    void setMpPathFinding(unsigned char val);
    unsigned char GetWorldChecksums(long& new_checksum, long& new_position_checksum, long& new_action_checksum);
    long GetChecksum(long player);
    void reset_countdown_timer(long in_countdown_player_id);
    void set_countdown_timer(long in_countdown_player_id, long in_countdown_timer);
    void get_countdown_timer(long out_countdown_player_id, long& out_countdown_timer);
    TShape* get_shape(int shape_id);
    TDigital* get_sound(int sound_id);
    void increment_view_update_count();
    void mouse_off();
    void mouse_on();
    void set_mouse_cursor(HCURSOR val);
    void set_mouse_facet(long facet);
    void draw_window();
    void set_render_all();

    void reset_timings();
    void increment_world_update_count();
    void set_last_single_time(int id, unsigned long time);
    unsigned long get_last_time(int id);
    unsigned long get_last_single_time(int id);
    unsigned long get_max_time(int id);
    unsigned long get_last_max_time(int id);
    unsigned long get_last_world_update_count();
    unsigned long get_last_view_update_count();
    unsigned long get_world_update_count();
    unsigned long get_view_update_count();
    RGE_Scenario* get_scenario_info(char* scenario_file, int from_campaign);
    RGE_Scenario_Header* get_scenario_header(char* scenario_file, int from_campaign);

protected:
    HFONT make_font(HDC dc, long string_id, int strike_out);
    HFONT make_font(HDC dc, char* face_name, int point_size, int wgt, int strike_out);
    int check_paint();
    void clear_window();

public:
    void request_pause();
    void get_mouse_info(WPARAM wparam, LPARAM lparam, tagPOINT& point, int& left_btn, int& right_btn, int& ctrl_key, int& shift_key);
    void set_windows_mouse(int val);
    void set_game_options(RGE_Game_Options* options);
    void get_game_options(RGE_Game_Options*);
    float version() const;
    int scenarioGame() const;
    int savedGame() const;
    char* scenarioName();
    int mapXSize() const;
    int mapYSize() const;
    int mapZSize() const;
    int allowCheatCodes() const;
    int cheatNotification() const;
    int fullVisibility() const;
    int fogOfWar() const;
    int coloredChat() const;
    int playerHasCD(int player_num);
    unsigned char playerVersion(int player_num);
    char* playerVersionString(int player_num);
    unsigned char playerCDAndVersion(int player_num);
    int numberPlayers() const;
    unsigned char pathFinding();
    unsigned char mpPathFinding();
    void find_campaigns();
    void set_map_visible(unsigned char flag);
    void set_map_fog(unsigned char flag);
    void turn_world_sound_off();
    long GetWorldChecksum();
    void set_screen_size(long, long);
    long get_scenario_checksum(char* scenario_file);
    unsigned char check_scenario_checksum(char* scenario, long checksum);
    void dump_memory_usage(char* file_name);
    void setPlayerID(int player_index, int player_id);
    int play_video(char* file_name);
    void close_video();
    void handle_video_notify();
    int play_sound(int sound_id);
    void set_game_speed(float val);
    int get_single_player_difficulty();
    void set_single_player_difficulty(int val);
    void reload_scenarios_info();

protected:
    RGE_Game_Info* player_game_info;
    RGE_Scenario_File_Info* scenario_info;
    RGE_Prog_Info* prog_info;
    HWND prog_window;
    int prog_ready;
    int prog_active;
    HPALETTE prog_palette;
    HANDLE prog_mutex;
    long window_style;
    int random_game_seed;
    int random_map_seed;
    int save_random_game_seed;
    int save_random_map_seed;
    int screen_saver_enabled;
    int low_power_enabled;
    int error_code;
    int is_timer;
    TDrawSystem* draw_system;
    TDrawArea* draw_area;
    unsigned char outline_type;
    int custom_mouse;
    short shape_num;
    TShape** shapes;
    TSound_Driver* sound_system;
    TMusic_System* music_system;
    short sound_num;
    TDigital** sounds;
    unsigned char save_music_type;
    int save_music_track_from;
    int save_music_track_to;
    int save_music_cur_track;
    char save_music_file[260];
    int save_music_loop;
    unsigned long save_music_pos;
    TCommunications_Handler* comm_handler;
    int comm_syncstop;
    int comm_droppackets;
    int comm_syncmsg;
    int comm_stepmode;
    int comm_speed;
    TDebuggingLog* debugLog;
    int log_comm;
    TRegistry* registry;
    int prog_mode;
    int game_mode;
    int sub_game_mode;
    int paused;
    TMousePointer* mouse_pointer;
    int erase_mouse;
    int mouse_blit_sync;
    int is_mouse_on;
    int windows_mouse;
    HCURSOR mouse_cursor;
    int input_enabled;
    HWND input_disabled_window;
    short font_num;
    RGE_Font* fonts;
    char work_dir[261];
    char string_dll_name[261];
    RGE_Game_World* world;
    int render_all;
    short master_obj_id;
    short terrain_id;
    short elevation_height;
    short brush_size;
    char timing_text[256];
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
    unsigned long last_view_time;
    RGE_Game_Options rge_game_options;
    int campaignGameValue;
    int savedGameValue;
    int quick_build;
    int save_check_for_cd;
    int playerIDValue[9];
    int display_selected_ids;
    long countdown_timer[9];
    int auto_paused;
    int save_paused;
    int non_user_pause;
    int rollover;
    float game_speed;
    int single_player_difficulty;
    unsigned char pathFindingValue;
    unsigned char resigned[9];
    TDrawArea* map_save_area;
};

typedef char rge_game_options_size_check[
    (sizeof(RGE_Base_Game::RGE_Game_Options) == 0xA8) ? 1 : -1];
typedef char rge_base_game_size_check[
    (sizeof(RGE_Base_Game) == 0xA24) ? 1 : -1];

#endif
