// VA: 00521120 TRIBE_Game::TRIBE_Game (599 B)
// PDB source: tribegam.cpp (lines 256-342)
// Attempt log:
// baseline: replaced the constructor scaffold with typed base construction,
// named video/game/notification fields, default option setters, player setup,
// and the natural optional setup path.
// control-flow: reordered global and mouse-click defaults before setMapSize to
// match the original push/store/call schedule.
// context: moving the video/game zero group into a natural constructor
// initializer list delayed the compiler-generated TRIBE_Game vptr store until
// the oracle's matching position; this produced MATCH without manual vptr or
// raw-address source.

extern void* StringTableX;
extern int disable_terrain_sounds;
extern int out_of_sync;
extern int out_of_sync2;
extern int player_dropped[9];

#include "../../include/tribegam_context.h"

#if 0
class RGE_Prog_Info {
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    RGE_Base_Game(RGE_Prog_Info* prog_info, int flags);

    char gap_04[0x3C];
    int error_code; // +0x40
    char gap_44[0x194];
    int is_mouse_on; // +0x1D8
    int windows_mouse; // +0x1DC
    char gap_1E0[0xA24 - 0x1E0];

    void setNumberPlayers(int number_players);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    void* MouseRightClickTable; // +0xA24
    int MouseRightClickTableSize; // +0xA28
    void* MouseLeftClickTable; // +0xA2C
    int MouseLeftClickTableSize; // +0xA30
    char gap_A34[0xAE8 - 0xA34];
    char testing_scenario[260]; // +0xAE8
    void* video_window; // +0xBEC
    int cur_video; // +0xBF0
    int (__stdcall *old_video_wnd_proc)(); // +0xBF4
    int video_paused; // +0xBF8
    unsigned long last_video_time; // +0xBFC
    int video_setup; // +0xC00
    int video_double_size; // +0xC04
    int video_changed_res; // +0xC08
    int video_hi_color; // +0xC0C
    long video_save_res_wid; // +0xC10
    long video_save_res_hgt; // +0xC14
    void* video_save_palette; // +0xC18
    int started_menu_music; // +0xC1C
    int show_object_id; // +0xC20
    void* game_screen; // +0xC24
    long notification_loc_x[5]; // +0xC28
    long notification_loc_y[5]; // +0xC3C
    long current_notification_loc; // +0xC50
    long current_notification_recalled; // +0xC54
    char startup_scenario[260]; // +0xC58
    char startup_game[260]; // +0xD5C
    unsigned long auto_exit_time; // +0xE60
    char save_game_name[260]; // +0xE64
    char load_game_name[260]; // +0xF68
    char timing_text2[256]; // +0x106C
    int save_humanity[9]; // +0x116C
    unsigned char quick_start_game; // +0x1190
    unsigned char gap_1191[3];
    int random_start_value; // +0x1194
    char computerNameUsed[18][10]; // +0x1198
    void* handleIdleLock; // +0x124C
    int inHandleIdle; // +0x1250

    void setMapSize(int value);
    void setMapType(int value);
    void setAnimals(int value);
    void setPredators(int value);
    void setVictoryType(int type, int amount);
    void setAllowTrading(int value);
    void setLongCombat(int value);
    void setRandomizePositions(int value);
    void setFullTechTree(int value);
    void setResourceLevel(int value);
    void setStartingAge(int value);
    void setStartingUnits(int value);
    void setDeathMatch(unsigned char value);
    void setPopLimit(unsigned char value);
    void setQuickStartGame(unsigned char value);
    void setRandomStartValue(int value);
    void setCivilization(int player, int civilization);
    void setScenarioPlayer(int player, int value);
    void setPlayerColor(int player, int color);
    void setComputerName(int player, int value);
    void resetRandomComputerName();
    int setup();

    TRIBE_Game(RGE_Prog_Info* prog_info, int setup_game);
};
#endif

TRIBE_Game::TRIBE_Game(RGE_Prog_Info* prog_info, int setup_game)
    : RGE_Base_Game(prog_info, 0),
      video_window(0),
      cur_video(-1),
      old_video_wnd_proc(0),
      video_paused(0),
      last_video_time(0),
      video_setup(0),
      video_double_size(0),
      video_changed_res(0),
      video_hi_color(0),
      video_save_res_wid(0),
      video_save_res_hgt(0),
      video_save_palette(0),
      started_menu_music(0),
      show_object_id(0),
      game_screen(0),
      inHandleIdle(0)
{
    int i;
    int player;
    int civilization;

    this->is_mouse_on = 1;
    this->windows_mouse = 0;
    this->testing_scenario[0] = 0;
    StringTableX = 0;
    this->startup_scenario[0] = 0;
    this->startup_game[0] = 0;
    this->save_game_name[0] = 0;
    this->load_game_name[0] = 0;
    this->auto_exit_time = 0;
    this->timing_text2[0] = 0;
    disable_terrain_sounds = 0;
    out_of_sync = 0;
    out_of_sync2 = 0;

    this->MouseRightClickTable = 0;
    this->MouseRightClickTableSize = 0;
    this->MouseLeftClickTable = 0;
    this->MouseLeftClickTableSize = 0;
    this->setMapSize(2);
    this->setMapType((TRIBE_Game::MapType)2);
    this->setAnimals(1);
    this->setPredators(1);
    this->setVictoryType((TRIBE_Game::VictoryType)1, 1);
    this->setAllowTrading(1);
    this->setLongCombat(0);
    this->setRandomizePositions(0);
    this->setFullTechTree(0);
    this->setResourceLevel((TRIBE_Game::ResourceLevel)0);
    this->setStartingAge((TRIBE_Game::Age)0);
    this->setStartingUnits(0);
    this->setDeathMatch(0);
    this->setPopLimit(50);
    this->setQuickStartGame(0);
    this->setRandomStartValue(-1);

    for (i = 0; i < 5; ++i) {
        this->notification_loc_x[i] = -1;
        this->notification_loc_y[i] = -1;
    }
    this->current_notification_loc = -1;
    this->current_notification_recalled = -1;

    civilization = 1;
    for (player = 0; player < 9; ++player) {
        this->setCivilization(player, civilization);
        ++civilization;
        if (civilization > 16) {
            civilization = 1;
        }
        this->setScenarioPlayer(player, player);
        this->setPlayerColor(player, 1);
        this->setComputerName(player, 0);
        player_dropped[player] = 0;
    }

    for (i = 0; i < 9; ++i) {
        this->save_humanity[i] = 0;
    }
    this->setNumberPlayers(4);
    this->resetRandomComputerName();

    if (setup_game != 0) {
        if (this->setup() == 0 && this->error_code == 0) {
            this->error_code = 1;
        }
    }
}
