// VA: 004A4190 TribeMPSetupScreen::updateSummary
// PDB source: scr_mps.cpp lines 2241-2686
//
// Baseline reconstruction: named summary buffers, scenario/player state, and
// the settingText/scenarioPlayerDrop panel arrays.  The source follows the
// period C++ structure suggested by the executable: scenario reload first,
// random/scenario player setup, then the ordered summary-panel writes.
//
// Exact recovery notes:
// - Canonical fields include scenarioPlayerDrop at +5F0, scenarioName at
//   +624, settingText at +62C, and the scenario state at +728 through +888.
// - The authentic local order is str1, str2, file_name, str3, and file_info.
//   Each call uses the declared buffer base. The first _findfirst uses the
//   file_name storage as an existence-only scratch record.
// - The scoped player index starts before scenarioInfo cleanup. A reset before
//   the active-player scan keeps the executable's shared zero value.
// - The random setup clears settingsFixed before it publishes both counts.
//   The save-name branch writes the nonzero random case first.
// - BINARY NOTE: both game-kind summary paths publish through scenarioName at
//   +624. settingText[0] is a different panel.
// - Victory type 9 always selects string 0x10EC. It is not the default case.
// - The checksum array uses a fixed source loop. Direct memset changes VC5's
//   address setup order.
// - The first exact transition also removed one extra map-setting increment
//   and used the shipped `scenarioPlayerCount >= 3` test.
// - Walkback kept exact output after removing extra same-TU includes, narrowing
//   player_index scope, and replacing field dependencies with literal zeros.
//   Removing the player-index reset, changing save-branch order, using memset,
//   or publishing through settingText[0] broke exact output.
// - Fresh authoritative validation: 3522 bytes, frame 0x534, 150 ordered calls,
//   qualified owner, Result: MATCH, and 0.0000%.

#ifndef SCR_MPS_TU_CONTEXT

#include <io.h>
#include <stdio.h>
#include <string.h>

#define CSTR(address) ((char*)(address))

struct tagRECT;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup();
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int value);                         // +0x14
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(tagRECT*);
    virtual void draw_offset(long, long, tagRECT*);
    virtual void draw_rect2(tagRECT*);
    virtual void draw_offset2(long, long, tagRECT*);
    virtual void paint();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual long handle_idle();
    virtual long handle_size(long, long);
    virtual long handle_paint();
    virtual long handle_key_down(long, short, int, int, int);
    virtual long handle_char(long, short);
    virtual long handle_command(unsigned int, long);
    virtual long handle_user_command(unsigned int, long);
    virtual long handle_timer_command(unsigned int, long);
    virtual long handle_scroll(long, long);
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual long handle_mouse_dbl_click(unsigned char, long, long, int, int);
    virtual long mouse_move_action(long, long, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_hold_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual long mouse_right_hold_action(long, long, int, int);
    virtual long mouse_right_move_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual long mouse_right_dbl_click_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long char_action(long, short);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void get_true_render_rect(tagRECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();
};

class TTextPanel : public TPanel {
public:
    virtual void set_text_id(long);
    virtual void set_text_string(char*);
    virtual void set_text(char* text);                            // +0xE8
};

class TDropDownPanel : public TPanel {
public:
    void empty_list();                                            // 00475460
    int append_line(char* text, long value);                      // 004752A0
};

class TEasy_Panel : public TPanel {
public:
    char gap_04[0xD4];
    int field_D8;
    char gap_DC[0x39C];                                           // size 0x478
};

class TScreenPanel : public TEasy_Panel {
public:
    char* get_string(int id);
    char* get_string(int id, char* buffer, int length);
};

class RGE_Prog_Info {
public:
    char gap_00[0xC17];
    char scenario_dir[1];
};

class RGE_Scenario;
class RGE_Static_Object;

class RGE_Base_Game {
public:
    char gap_00[0x0C];
    RGE_Prog_Info* prog_info;

    int scenarioGame();
    int randomGame();
    char* scenarioName();
    int multiplayerGame();
    int singlePlayerGame();
    int allowCheatCodes();
    int fullVisibility();
    unsigned char pathFinding();
    unsigned char mpPathFinding();
    int difficulty();
    int setScenarioGame(int value);
    void setPlayerTeam(int player, int team);
    RGE_Scenario* get_scenario_info(char* name, int campaign);
    long get_scenario_checksum(char* name);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    unsigned char deathMatch();
    int mapSize();
    int mapType();
    int victoryType();
    int victoryAmount();
    int startingAge();
    int resourceLevel();
    int randomizePositions();
    int fullTechTree();
    unsigned char popLimit();
    void setScenarioPlayer(int player, int scenario_player);
    void setPlayerColor(int player, int color);
};

class T_Scenario {
public:
    virtual RGE_Static_Object* get_object_pointer(int id);
    virtual ~T_Scenario();
    virtual void rehook();
    virtual void save(int file);
    int any_sp_victory();
};

class RGE_Scenario : public T_Scenario {
public:
    int Get_player_Active(int index);
    int Get_player_Type(int index);
};

extern RGE_Base_Game* rge_base_game;

class TribeMPSetupScreen : public TScreenPanel {
public:
    char gap_478[0x178];                                        // to +5F0
    TDropDownPanel* scenarioPlayerDrop[8];                     // +5F0
    char gap_610[0x14];                                         // to +624
    TTextPanel* scenarioName;                                   // +624
    char gap_628[4];                                            // to +62C
    TTextPanel* settingText[20];                                // +62C
    char gap_67C[0x60];                                         // to +6DC
    TPanel* numberPlayersTitle;                                 // +6DC
    TPanel* numberPlayersDrop;                                  // +6E0
    char gap_6E4[0x44];                                         // to +728
    int scenarioPlayerCount;                                    // +728
    int myCivilization;                                         // +72C
    int myScenarioPlayer;                                       // +730
    int myPlayerColor;                                          // +734
    int myPlayerTeam;                                           // +738
    long myScenarioChecksum;                                    // +73C
    char saveScenarioName[256];                                 // +740
    int saveRandomGame;                                         // +840
    long saveScenarioChecksum;                                  // +844
    RGE_Scenario* scenarioInfo;                                 // +848
    int settingsFixed;                                          // +84C
    int numberAnyPlayers;                                       // +850
    char gap_854[0x0C];                                         // to +860
    unsigned char defaultColor[8];                             // +860
    long scenarioCheckSum[8];                                   // +868

    void setupSinglePlayerPlayers();
    void fillPlayers();
    void updateSummary();
};

#endif

void TribeMPSetupScreen::updateSummary()
{
    int changed = 0;
    char str1[256];
    char str2[256];
    // The first existence-only _findfirst uses file_name as its _finddata_t
    // scratch window. The extra tail reaches str3 without overlap.
    char file_name[0x118];
    char str3[256];
    struct _finddata_t file_info;
    char* scenario_dir;
    char* scenario_name;

    if (rge_base_game->scenarioGame()) {
        if (this->saveRandomGame == 0) {
            if (strcmp(rge_base_game->scenarioName(), this->saveScenarioName) != 0) {
                changed = 1;
            }
        } else {
            changed = 1;
        }
    } else if (this->saveRandomGame == 0) {
        changed = 1;
    }

    if (changed != 0) {
        if (rge_base_game->scenarioGame()) {
            int player_index = 0;
            if (this->scenarioInfo != 0) {
                delete this->scenarioInfo;
                this->scenarioInfo = 0;
            }

            scenario_dir = rge_base_game->prog_info->scenario_dir;
            scenario_name = rge_base_game->scenarioName();
            sprintf(str1, CSTR(0x00586114), scenario_dir, scenario_name);
            long handle = _findfirst(str1,
                                     (struct _finddata_t*)file_name);
            if (handle == -1) {
                sprintf(str1, CSTR(0x00586840),
                        rge_base_game->scenarioName());
            } else {
                sprintf(str1, CSTR(0x00586838),
                        rge_base_game->scenarioName());
            }

            if (str1[0] != '.') {
                this->scenarioInfo = rge_base_game->get_scenario_info(str1, 0);
            }

            if (this->scenarioInfo == 0) {
                rge_base_game->setScenarioGame(0);
            } else {
                for (int empty_index = 0; empty_index < 8; ++empty_index) {
                    this->scenarioPlayerDrop[empty_index]->empty_list();
                }

                this->settingsFixed = this->scenarioInfo->any_sp_victory();
                player_index = 0;
                this->numberAnyPlayers = 0;
                this->scenarioPlayerCount = 0;

                for (; player_index < 9; ++player_index) {
                    if (((RGE_Scenario*)this->scenarioInfo)->Get_player_Active(player_index) != 0) {
                        ++this->scenarioPlayerCount;
                        sprintf(str2, CSTR(0x00584610), player_index + 1);
                        if (rge_base_game->multiplayerGame() ||
                            (rge_base_game->singlePlayerGame() &&
                             ((RGE_Scenario*)this->scenarioInfo)->Get_player_Type(player_index) == 1)) {
                            ++this->numberAnyPlayers;
                            for (int append_index = 0; append_index < 8; ++append_index) {
                                this->scenarioPlayerDrop[append_index]->append_line(
                                    str2, player_index);
                            }
                        }
                    }
                }

                int player = -1;
                for (int color_index = 0; color_index < 8; ++color_index) {
                    do {
                        ++player;
                        if (player == 9) {
                            player = 0;
                        }
                    } while (((RGE_Scenario*)this->scenarioInfo)->Get_player_Active(player) == 0);

                    this->defaultColor[color_index] = (unsigned char)player + 1;
                    ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(color_index, player);
                    ((TRIBE_Game*)rge_base_game)->setPlayerColor(
                        color_index, this->defaultColor[color_index]);
                    rge_base_game->setPlayerTeam(color_index, 1);
                }
            }
        }

        if (rge_base_game->randomGame()) {
            for (int random_empty_index = 0; random_empty_index < 8; ++random_empty_index) {
                this->scenarioPlayerDrop[random_empty_index]->empty_list();
            }
            this->settingsFixed = 0;
            this->scenarioPlayerCount = 8;
            this->numberAnyPlayers = 8;

            for (int random_index = 0; random_index < 8; ++random_index) {
                this->defaultColor[random_index] = (unsigned char)random_index + 1;
                ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(random_index, random_index);
                ((TRIBE_Game*)rge_base_game)->setPlayerColor(
                    random_index, this->defaultColor[random_index]);
                rge_base_game->setPlayerTeam(random_index, 1);
                sprintf(str2, CSTR(0x00584610), random_index + 1);
                for (int random_append_index = 0; random_append_index < 8;
                     ++random_append_index) {
                    this->scenarioPlayerDrop[random_append_index]->append_line(
                        str2, random_index);
                }
            }
        }

        if (rge_base_game->singlePlayerGame()) {
            this->setupSinglePlayerPlayers();
        }

        this->saveRandomGame = rge_base_game->randomGame();
        if (this->saveRandomGame != 0) {
            this->saveScenarioName[0] = 0;
        } else {
            strcpy(this->saveScenarioName, rge_base_game->scenarioName());
        }

        for (int checksum_index = 0; checksum_index < 8; ++checksum_index) {
            this->scenarioCheckSum[checksum_index] = 0;
        }

        if (rge_base_game->scenarioGame()) {
            scenario_dir = rge_base_game->prog_info->scenario_dir;
            scenario_name = rge_base_game->scenarioName();
            sprintf(file_name, CSTR(0x00586114), scenario_dir, scenario_name);
            long handle = _findfirst(file_name, &file_info);
            if (handle == -1) {
                sprintf(file_name, CSTR(0x00586840),
                        rge_base_game->scenarioName());
            } else {
                sprintf(file_name, CSTR(0x00586838),
                        rge_base_game->scenarioName());
            }
            this->myScenarioChecksum = rge_base_game->get_scenario_checksum(file_name);
        } else {
            this->myScenarioChecksum = 0;
        }
    }

    int setting;
    for (int i = 0; i < 20; ++i) {
        this->settingText[i]->set_active(0);
    }

    if (rge_base_game->scenarioGame()) {
        sprintf(str2, this->get_string(0x25ED),
                rge_base_game->scenarioName());
        this->scenarioName->set_text(str2);
        setting = 3;
    } else {
        if (((TRIBE_Game*)rge_base_game)->deathMatch()) {
            this->get_string(0x2617, str1, 0x100);
        } else {
            this->get_string(0x25B5, str1, 0x100);
        }
        sprintf(str2, this->get_string(0x25ED), str1);
        this->scenarioName->set_text(str2);
        setting = 1;
    }

    if (rge_base_game->randomGame()) {
        switch (((TRIBE_Game*)rge_base_game)->mapSize()) {
        case 0: strcpy(str1, this->get_string(0x2973)); break;
        case 1: strcpy(str1, this->get_string(0x2974)); break;
        case 2: strcpy(str1, this->get_string(0x2975)); break;
        case 3: strcpy(str1, this->get_string(0x2976)); break;
        case 4: strcpy(str1, this->get_string(0x2977)); break;
        case 5: strcpy(str1, this->get_string(0x2978)); break;
        }
        sprintf(str2, this->get_string(0x25DA), str1);
        this->settingText[setting]->set_text(str2);
        this->settingText[setting]->set_active(1);
        ++setting;

        switch (((TRIBE_Game*)rge_base_game)->mapType()) {
        case 0: strcpy(str1, this->get_string(0x296A)); break;
        case 1: strcpy(str1, this->get_string(0x296B)); break;
        case 2: strcpy(str1, this->get_string(0x296C)); break;
        case 3: strcpy(str1, this->get_string(0x296D)); break;
        case 4: strcpy(str1, this->get_string(0x296E)); break;
        case 5: strcpy(str1, this->get_string(0x296F)); break;
        case 6: strcpy(str1, this->get_string(0x2970)); break;
        case 7: strcpy(str1, this->get_string(0x2971)); break;
        case 8: strcpy(str1, this->get_string(0x2972)); break;
        }
        sprintf(str2, this->get_string(0x25B6), str1);
        this->settingText[setting]->set_text(str2);
        this->settingText[setting]->set_active(1);
        ++setting;
    }

    if (rge_base_game->scenarioGame()) {
        if (this->settingsFixed == 0 && this->scenarioPlayerCount != 2) {
            sprintf(str2, CSTR(0x00586C20), this->get_string(0x25B7),
                    2, this->scenarioPlayerCount);
        } else {
            sprintf(str2, CSTR(0x00586C18), this->get_string(0x25B7),
                    this->scenarioPlayerCount);
        }
    } else {
        sprintf(str2, CSTR(0x00586C0C), this->get_string(0x25B7));
    }
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    switch (((TRIBE_Game*)rge_base_game)->victoryType()) {
    case 1:
        strcpy(str1, this->get_string(0x10E1));
        goto victory_plain;
    case 7:
        strcpy(str1, this->get_string(0x10E9));
        goto victory_amount;
    case 8:
        strcpy(str1, this->get_string(0x10EA));
victory_amount:
        sprintf(str2, this->get_string(0x25BE), str1,
                ((TRIBE_Game*)rge_base_game)->victoryAmount());
        goto victory_done;
    case 9:
        strcpy(str1, this->get_string(0x10EC));
        goto victory_plain;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    default:
        if (rge_base_game->randomGame()) {
            strcpy(str1, this->get_string(0x10EC));
        } else {
            strcpy(str1, this->get_string(0x10E7));
        }
        goto victory_plain;
    victory_plain:
        sprintf(str2, this->get_string(0x25BC), str1);
victory_done:
        break;
    }
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    int age = ((TRIBE_Game*)rge_base_game)->startingAge();
    if (age == 0) {
        this->get_string(0x10E7, str1, 0x100);
    } else if (age == 1) {
        this->get_string(0x106E, str1, 0x100);
    } else {
        this->get_string(age + 0x1067, str1, 0x100);
    }
    sprintf(str2, this->get_string(0x25E4), str1);
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    int resources = ((TRIBE_Game*)rge_base_game)->resourceLevel();
    if (resources == 0) {
        this->get_string(0x10E7, str1, 0x100);
    } else {
        this->get_string(resources + 0x25E5, str1, 0x100);
    }
    sprintf(str2, this->get_string(0x25E5), str1);
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    rge_base_game->difficulty();
    this->get_string(rge_base_game->difficulty() + 0x2BD0, str1, 0x100);
    this->get_string(0x25E0, str2, 0x100);
    sprintf(str3, str2, str1);
    this->settingText[setting]->set_text(str3);
    this->settingText[setting]->set_active(1);
    ++setting;

    if (((TRIBE_Game*)rge_base_game)->randomizePositions()) {
        this->get_string(0xFA4, str1, 0x100);
    } else {
        this->get_string(0xFA3, str1, 0x100);
    }
    sprintf(str2, this->get_string(0x25E9), str1);
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    if (rge_base_game->fullVisibility()) {
        strcpy(str1, this->get_string(0xFA3));
    } else {
        strcpy(str1, this->get_string(0xFA4));
    }
    sprintf(str2, this->get_string(0x25B8), str1);
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    if (((TRIBE_Game*)rge_base_game)->fullTechTree()) {
        this->get_string(0xFA3, str1, 0x100);
    } else {
        this->get_string(0xFA4, str1, 0x100);
    }
    sprintf(str2, this->get_string(0x25EC), str1);
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    if (rge_base_game->multiplayerGame()) {
        if (rge_base_game->allowCheatCodes()) {
            strcpy(str1, this->get_string(0xFA3));
        } else {
            strcpy(str1, this->get_string(0xFA4));
        }
        sprintf(str2, this->get_string(0x25BB), str1);
        this->settingText[setting]->set_text(str2);
        this->settingText[setting]->set_active(1);
        ++setting;
    }

    if (rge_base_game->multiplayerGame()) {
        this->get_string(((TRIBE_Game*)rge_base_game)->mpPathFinding() + 0x260E,
                         str1, 0x100);
    } else {
        this->get_string(rge_base_game->pathFinding() + 0x260E,
                         str1, 0x100);
    }
    sprintf(str2, this->get_string(0x25F1), str1);
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);
    ++setting;

    sprintf(str2, this->get_string(0x25F0),
            ((TRIBE_Game*)rge_base_game)->popLimit());
    this->settingText[setting]->set_text(str2);
    this->settingText[setting]->set_active(1);

    if (rge_base_game->singlePlayerGame()) {
        if (rge_base_game->scenarioGame() == 0 ||
            (this->settingsFixed == 0 && this->scenarioPlayerCount >= 3)) {
            this->numberPlayersTitle->set_active(1);
            this->numberPlayersDrop->set_active(1);
        } else {
            this->numberPlayersTitle->set_active(0);
            this->numberPlayersDrop->set_active(0);
        }
    }

    this->fillPlayers();
}
