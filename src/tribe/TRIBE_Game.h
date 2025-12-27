#pragma once
#include "../rge/RGE_Base_Game.h"
#include "TRIBE_Game_Options.h"

// Forward declarations for pointers in your PDB dump
struct MouseClickInfo;
struct TRIBE_Screen_Game;

class TRIBE_Game : public RGE_Base_Game {
public:
    TRIBE_Game(struct RGE_Prog_Info *info, int setup_flag);
    virtual ~TRIBE_Game();

    virtual int handle_message(tagMSG* msg) override;
    virtual int handle_idle() override;
    virtual long wnd_proc(HWND hwnd, uint msg, WPARAM wparam, LPARAM lparam) override;

    // TRIBE_Game specific members (Starts at offset 0xA24)
    /* 0x0a24 */ struct MouseClickInfo *MouseRightClickTable;
    /* 0x0a28 */ int MouseRightClickTableSize;
    /* 0x0a2c */ struct MouseClickInfo *MouseLeftClickTable;
    /* 0x0a30 */ int MouseLeftClickTableSize;
    /* 0x0a34 */ long queue_is_waiting_on_pop_counter[9];
    /* 0x0a58 */ int random_civ[9];
    /* 0x0a7c */ struct TRIBE_Game_Options tribe_game_options;
    /* 0x0ae8 */ char testing_scenario[260];
    /* 0x0bec */ void *video_window;
    /* 0x0bf0 */ int cur_video;
    /* 0x0bf4 */ void *old_video_wnd_proc;
    /* 0x0bf8 */ int video_paused;
    /* 0x0bfc */ ulong last_video_time;
    /* 0x0c00 */ int video_setup;
    /* 0x0c04 */ int video_double_size;
    /* 0x0c08 */ int video_changed_res;
    /* 0x0c0c */ int video_hi_color;
    /* 0x0c10 */ long video_save_res_wid;
    /* 0x0c14 */ long video_save_res_hgt;
    /* 0x0c18 */ void *video_save_palette;
    /* 0x0c1c */ int started_menu_music;
    /* 0x0c20 */ int show_object_id;
    /* 0x0c24 */ struct TRIBE_Screen_Game *game_screen;
    /* 0x0c28 */ long notification_loc_x[5];
    /* 0x0c3c */ long notification_loc_y[5];
    /* 0x0c50 */ long current_notification_loc;
    /* 0x0c54 */ long current_notification_recalled;
    /* 0x0c58 */ char startup_scenario[260];
    /* 0x0d5c */ char startup_game[260];
    /* 0x0e60 */ ulong auto_exit_time;
    /* 0x0e64 */ char save_game_name[260];
    /* 0x0f68 */ char load_game_name[260];
    /* 0x106c */ char timing_text2[256];
    /* 0x116c */ int save_humanity[9];
    /* 0x1190 */ uchar quick_start_game;
    /* 0x1191 */ uchar _pad_1191[3];
    /* 0x1194 */ int random_start_value;
    /* 0x1198 */ uchar computerNameUsed[18][10];
    /* 0x124c */ void *handleIdleLock;
    /* 0x1250 */ int inHandleIdle;

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
    int setup() override;
    int setup_cmd_options() override;
    int setup_palette() override;
    int setup_sounds() override;

    int start_game(int param_1);
    int create_game(int param_1);

    // Virtual overrides
    virtual int get_error_code() override { return this->error_code; } // [1]
    virtual int run() override; // [6]
    virtual void show_error(int id, char* buf, int s) override; // [8]
    virtual void fatal_exit(int a, int b, int c, char* d, int e) override; // [10]
};


// Size check: must be exactly 0x1254 to match 'new' call in original EXE
static_assert(sizeof(TRIBE_Game) == 0x1254, "TRIBE_Game size mismatch!");

