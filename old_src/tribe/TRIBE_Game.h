#pragma once
#include "../rge/RGE_Base_Game.h"
#include "TRIBE_Game_Options.h"

// Forward declarations for pointers
struct MouseClickInfo;
struct TRIBE_Screen_Game;

class TRIBE_Game : public RGE_Base_Game {
public:
    TRIBE_Game(struct RGE_Prog_Info* info, int setup_flag);
    virtual ~TRIBE_Game();

    // ========================================================================
    // Virtual overrides (matching layout.json vtable)
    // ========================================================================
    virtual int run() override;
    virtual long wnd_proc(HWND hwnd, uint msg, WPARAM wparam, LPARAM lparam) override;
    virtual void set_game_mode(int mode, int sub_mode) override;
    virtual void set_player(short player_id) override;
    virtual int get_error_code() override { return this->error_code; }
    virtual char* get_string(long a, char* b, int c) override;
    virtual char* get_string2(int a, long b, long c, char* d, int e) override;
    virtual void* get_view_panel() override;
    virtual void* get_map_panel() override;
    virtual void* new_scenario_header(void* scenario) override;
    virtual void* new_scenario_header(int a) override;
    virtual void* new_scenario_info(int a) override;
    virtual void notification(int a, long b, long c, long d, long e) override;
    virtual void send_game_options() override;
    virtual void receive_game_options() override;
    virtual char* gameSummary() override;
    virtual int processCheatCode(int a, char* b) override;
    virtual int setup() override;
    virtual int setup_cmd_options() override;
    virtual int setup_palette() override;
    virtual int setup_sounds() override;
    virtual RGE_Game_World* create_world() override;
    virtual int handle_message(tagMSG* msg) override;
    virtual int handle_idle() override;
    virtual int handle_activate(void* hwnd, uint msg, uint wparam, long lparam) override;
    virtual int handle_query_new_palette(void* hwnd, uint msg, uint wparam, long lparam) override;
    virtual int action_key_down(ulong key, int a, int b, int c, int d) override;
    virtual int action_user_command(ulong a, ulong b) override;
    virtual int action_close() override;
    virtual void calc_timing_text() override;
    virtual void show_timings() override;
    virtual void show_comm() override;
    virtual void show_ai() override;
    virtual void set_interface_messages() override;

    // ========================================================================
    // Members (Offsets MUST match layout.json - first member at 0xA24)
    // ========================================================================
    /* 0x0A24 */ MouseClickInfo* MouseRightClickTable;
    /* 0x0A28 */ int MouseRightClickTableSize;
    /* 0x0A2C */ MouseClickInfo* MouseLeftClickTable;
    /* 0x0A30 */ int MouseLeftClickTableSize;
    /* 0x0A34 */ long queue_is_waiting_on_pop_counter[9];
    /* 0x0A58 */ int random_civ[9];
    /* 0x0A7C */ TRIBE_Game_Options tribe_game_options;
    /* 0x0AE8 */ char testing_scenario[260];
    /* 0x0BEC */ void* video_window;
    /* 0x0BF0 */ int cur_video;
    /* 0x0BF4 */ void* old_video_wnd_proc;
    /* 0x0BF8 */ int video_paused;
    /* 0x0BFC */ ulong last_video_time;
    /* 0x0C00 */ int video_setup;
    /* 0x0C04 */ int video_double_size;
    /* 0x0C08 */ int video_changed_res;
    /* 0x0C0C */ int video_hi_color;
    /* 0x0C10 */ long video_save_res_wid;
    /* 0x0C14 */ long video_save_res_hgt;
    /* 0x0C18 */ void* video_save_palette;
    /* 0x0C1C */ int started_menu_music;
    /* 0x0C20 */ int show_object_id;
    /* 0x0C24 */ TRIBE_Screen_Game* game_screen;
    /* 0x0C28 */ long notification_loc_x[5];
    /* 0x0C3C */ long notification_loc_y[5];
    /* 0x0C50 */ long current_notification_loc;
    /* 0x0C54 */ long current_notification_recalled;
    /* 0x0C58 */ char startup_scenario[260];
    /* 0x0D5C */ char startup_game[260];
    /* 0x0E60 */ ulong auto_exit_time;
    /* 0x0E64 */ char save_game_name[260];
    /* 0x0F68 */ char load_game_name[260];
    /* 0x106C */ char timing_text2[256];
    /* 0x116C */ int save_humanity[9];
    /* 0x1190 */ uchar quick_start_game;
    // Compiler adds 3 bytes padding here
    /* 0x1194 */ int random_start_value;
    /* 0x1198 */ uchar computerNameUsed[18][10];
    /* 0x124C */ void* handleIdleLock;
    /* 0x1250 */ int inHandleIdle;

    // ========================================================================
    // Non-virtual Methods
    // ========================================================================
    void setMapSize(MapSize v);
    void setMapType(MapType v);
    void setAnimals(int v);
    void setPredators(int v);
    void setVictoryType(VictoryType v, int a);
    void setAllowTrading(int v);
    void setLongCombat(int v);
    void setRandomizePositions(int v);
    void setFullTechTree(int v);
    void setResourceLevel(ResourceLevel v);
    void setStartingAge(Age v);
    void setStartingUnits(int v);
    void setDeathMatch(char v);
    void setPopLimit(char v);
    void setQuickStartGame(char v);
    void setRandomStartValue(int v);
    void setCivilization(int p, int v);
    void setScenarioPlayer(int p, int v);
    void setPlayerColor(int p, int v);
    void setComputerName(int p, int v);
    void resetRandomComputerName();

    void close_game_screens(int p);
    int start_game(int param_1);
    int create_game(int param_1);
};

// ============================================================================
// MANDATORY VERIFICATION (per AI_INSTRUCTIONS.md)
// ============================================================================
static_assert(sizeof(TRIBE_Game) == 0x1254, "TRIBE_Game size mismatch!");
static_assert(offsetof(TRIBE_Game, MouseRightClickTable) == 0xA24, "MouseRightClickTable offset");
static_assert(offsetof(TRIBE_Game, tribe_game_options) == 0xA7C, "tribe_game_options offset");
static_assert(offsetof(TRIBE_Game, handleIdleLock) == 0x124C, "handleIdleLock offset");
static_assert(offsetof(TRIBE_Game, inHandleIdle) == 0x1250, "inHandleIdle offset");
