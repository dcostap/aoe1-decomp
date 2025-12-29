#pragma once
#include "../rge/RGE_Base_Game.h"
#include "../common.h"

// Forward Declares for Member Types
struct MouseClickInfo { int x, y; }; // Stub
struct TRIBE_Game_Options { char _data[0x6C]; }; // Stub size 0x6C
struct TRIBE_Screen_Game { char _data[100]; }; // Stub


class TRIBE_Game : public RGE_Base_Game {
public:
    // Constructor
    TRIBE_Game(RGE_Prog_Info* info, int do_setup);

    // VTable Overrides
    virtual int setup() override;

    // ---------------------------------------------------------------------
    // Override loader: try StringTableX first, fallback to base StringTable
    // Address 005228e0
    // ---------------------------------------------------------------------
    char* get_string(long id, char* out, int outLen) override;

    // ---------------------------------------------------------------------
    // Override selector: extra modes/mappings, otherwise fallback to base
    // Address 00522930
    // ---------------------------------------------------------------------
    char* get_string2(int mode, long code, long extra, char* out, int outLen) override;

    // -------------------------------------------------------------------------
    // MEMBERS (Starting at 0xA24)
    // -------------------------------------------------------------------------
    
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
    /* 0x0BFC */ unsigned long last_video_time;
    /* 0xC00 */ int video_setup;
    /* 0xC04 */ int video_double_size;
    /* 0xC08 */ int video_changed_res;
    /* 0xC0C */ int video_hi_color;
    /* 0xC10 */ long video_save_res_wid;
    /* 0xC14 */ long video_save_res_hgt;
    /* 0xC18 */ void* video_save_palette;
    /* 0xC1C */ int started_menu_music;
    /* 0xC20 */ int show_object_id;
    /* 0xC24 */ TRIBE_Screen_Game* game_screen;
    /* 0xC28 */ long notification_loc_x[5];
    /* 0xC3C */ long notification_loc_y[5];
    /* 0xC50 */ long current_notification_loc;
    /* 0xC54 */ long current_notification_recalled;
    /* 0xC58 */ char startup_scenario[260];
    /* 0x0D5C */ char startup_game[260];
    /* 0x0E60 */ unsigned long auto_exit_time;
    /* 0x0E64 */ char save_game_name[260];
    /* 0x0F68 */ char load_game_name[260];
    /* 0x106C */ char timing_text2[256];
    /* 0x116C */ int save_humanity[9];
    /* 0x1190 */ unsigned char quick_start_game;
    
    // Alignment padding for int
    /* 0x1191 */ char _pad_1191[3]; 
    
    /* 0x1194 */ int random_start_value;
    
    // char[18][10] = 180 bytes.
    /* 0x1198 */ unsigned char computerNameUsed[18][10]; 
    
    // 0x1198 + 0xB4 = 0x124C. Perfect.
    
    /* 0x124C */ void* handleIdleLock;
    /* 0x1250 */ int inHandleIdle;
    
    // 0x1254 End.
    
    // Helper Methods (Not virtuals, but regular functions seen in Constructor)
    void setMapSize(MapSize val);
    void setMapType(MapType val);
    void setAnimals(int val);
    void setPredators(int val);
    void setVictoryType(VictoryType type, int val);
    void setAllowTrading(int val);
    void setLongCombat(int val);
    void setRandomizePositions(int val);
    void setFullTechTree(int val);
    void setResourceLevel(int val);
    void setStartingAge(int val);
    void setStartingUnits(int val);
    void setDeathMatch(char val);
    void setPopLimit(char val);
    void setQuickStartGame(char val);
    void setRandomStartValue(int val);
    void setCivilization(int player, int civ);
    void setScenarioPlayer(int player, int val);
    void setPlayerColor(int player, int color);
    void setComputerName(int player, int val);
    void resetRandomComputerName();

    // Setup Helpers
    int start_video(void* this_ptr, int u, const char* name);
    int start_menu();
    int load_game(const char* name);
    int start_scenario(const char* name);
};

// MANDATORY VERIFICATION
static_assert(sizeof(TRIBE_Game) == 0x1254, "TRIBE_Game size mismatch");
static_assert(offsetof(TRIBE_Game, MouseRightClickTable) == 0x0A24, "TRIBE_Game::MouseRightClickTable offset mismatch");
static_assert(offsetof(TRIBE_Game, testing_scenario) == 0x0AE8, "TRIBE_Game::testing_scenario offset mismatch");
static_assert(offsetof(TRIBE_Game, handleIdleLock) == 0x124C, "TRIBE_Game::handleIdleLock offset mismatch");