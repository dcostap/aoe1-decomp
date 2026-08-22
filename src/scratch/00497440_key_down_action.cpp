// VA: 00497440 key_down_action (3046B), scr_game.cpp:2163-2820
// Canonical reconstruction: TRIBE_Screen_Game over the real TPanel/TEasy_Panel/
// TScreenPanel surface, TRIBE_World/RGE_Game_World data ownership, and direct
// panel/game member calls. The original has scr_game.cpp's /GX lifetime frame.
// Attempt log:
// - baseline: natural panel delegation, three switch dispatches, typed
//   game/world/player surfaces, and real C++ new for TribeSaveGameScreen;
//   frame 0x204, but no /GX registration and broad structural drift.
// - /GX donor-context probe: matched the original EH frame and improved the
//   structural basin substantially; retained in config/flags.
// - removed an invented first-switch Tab case and guarded the building-list
//   scan by param4; this restored the original common-path behavior.
// - changed the building scan to a pre-tested indexed while with per-iteration
//   get_player(), matching the observed one-site loop and 0x28 entry stride.
// - restored first-switch key 9 after the formation cases so the jump-table
//   body topology follows the original; inverted the final param4 branch source
//   order so developer blocks precede normal-mode blocks.
// - reordered the second developer switch to its emitted case order and fixed
//   key 0x41 to use view_debug_Objects.
// - added TRIBE_Game::show_object_id at +0xC20 for the developer 0x49 case.
// - BINARY NOTE: the work-key arms return, but a no-match path falls through
//   to the later normal switch. This matches the original block edges.
// - BINARY NOTE: an unknown ctrl key returns through the shared zero epilogue;
//   it does not enter the building-key scan.
// - reordered the normal switch by its emitted body order. Independent host
//   and group guards restored the original param4 reload and block layout.
// - changed the global receiver to the reviewed RGE_Base_Game* surface and
//   downcast only for proven TRIBE_Game members. This was codegen-neutral.
// - current check: exact size, frame, 101 calls, and 97.88% shape; 338 bytes
//   differ. The first mismatch is the building-key scan's register map.
//   Remaining drift is local register allocation and switch-table relocation.
// BLOCKER: After each debug sprintf, the executable reads rge_base_game before
// removing 12 cdecl argument bytes. The rebuild removes those bytes first and
// then reads the global. A faulting global load therefore observes ESP values
// that differ by 12 bytes.

#include <stdio.h>
#include <string.h>

struct tagRECT;
class TDrawArea;
class TShape;
class TPanel;
class TTextPanel;
class TButtonPanel;
class TInputPanel;
class TEditPanel;
class TListPanel;
class TScrollBarPanel;
class TVerticalSliderPanel;
class THorizontalSliderPanel;
class RGE_Player;
class RGE_Master_Static_Object;
class RGE_Game_World;
class TRIBE_World;
class RGE_Scenario;
class RGE_Scenario_Header;
class RGE_Static_Object;
class TSound_Driver;
class TDigital;
class TCommunications_Handler;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long, long, long,
                                 TPanel*, TPanel*, TPanel*, TPanel*);
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

    char gap_04[0x68];
    void* field_6C;
    char gap_70[0x84];

    char* get_string(int id);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];
    void setup_popup_help();
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class RGE_Panel_Tool_Box : public TPanel {
public:
    virtual ~RGE_Panel_Tool_Box();
    char gap_F4[0x2C];
};

class TRIBE_Main_View : public TPanel {
public:
    virtual ~TRIBE_Main_View();
};

class TRIBE_Panel_Time : public TPanel {
public:
    virtual ~TRIBE_Panel_Time();
    char gap_F4[0x0C];
    int clock_type;
    int get_clock_type();
    void set_clock_type(int clock_type, int player_id);
};

class TCommunications_Handler {
public:
    int IsHost();
    int Kick(unsigned int player);
    int TXDebugPing();
};

class TDigital {
public:
    int play();
};

class TDebuggingLog {
public:
    static void Log(TDebuggingLog* log, const char* format, ...);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x9C];
    long hotkey_id;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(int);
    virtual int isAlly(int);
    virtual int isNeutral(int);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int, int);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void kickAI(int);

    char gap_04[0x20];
    RGE_Master_Static_Object** master_objects;
    char gap_28[0x22];
    short id;
    char gap_4C[8];
    unsigned char culture;
    char gap_55[3];
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x78];
    short curr_player;
    char gap_7E[2];
    char gap_80[0x84];
};

class TRIBE_World : public RGE_Game_World {
public:
    char gap_104[0x18];
    unsigned char score_displayed;
    unsigned char controlling_computer_player;
    char gap_11E[2];
    int sent_zone_score;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual char* get_string(int, long, char*, int);
    virtual char* get_string(long, char*, int);
    virtual char* get_string(long);
    virtual char* get_string2(int, long, long, char*, int);
    virtual TPanel* get_view_panel();
    virtual TPanel* get_map_panel();
    virtual RGE_Scenario_Header* new_scenario_header(RGE_Scenario*);
    virtual RGE_Scenario_Header* new_scenario_header(int);
    virtual RGE_Scenario* new_scenario_info(int);
    virtual void notification(int, long, long, long, long);
    virtual int reset_comm();
    virtual void send_game_options();
    virtual void receive_game_options();
    virtual char* gameSummary();
    virtual int processCheatCode(int, char*);

    char gap_04[0x4C];
    unsigned char outline_type;
    char gap_51[0x15F];
    int prog_mode;
    int game_mode;
    int sub_game_mode;
    char gap_1BC[0x818];
    int display_selected_ids;
    char gap_9D8[0x4C];

    int gameDeveloperMode();
    int get_paused();
    RGE_Player* get_player();
    TDigital* get_sound(int index);
    int multiplayerGame();
    unsigned char check_prog_argument(const char* name);
    void dump_memory_usage(char* name);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    virtual ~TRIBE_Game();
    char gap_A24[0x1FC];
    int show_object_id;                 // +0xC20

    void restart_game();
    void goto_notification_loc();
    void show_status_message(char* text, char* caption, long timeout);
    void close_status_message();
};

class TPanelSystem {
public:
    int modalPanel();
    int setCurrentPanel(char* name, int mode);
};

class TribeSaveGameScreen {
public:
    char gap_00[0x6A4];
    TribeSaveGameScreen(int mode, char* name, int flags);
};

struct BuildingEntry {
    char gap_00[4];
    short master_object_id;
    char gap_06[0x22];
};

class TRIBE_Screen_Game : public TScreenPanel {
public:
    TShape* game_screen_pic;                 // +0x478
    TShape* button_border1_pic;
    TShape* button_other_pic;
    TShape* button_border2_pic;
    TShape* button_border3_pic;
    TShape* button_cmd_pic;
    TShape* button_tech_pic;
    TShape* button_unit_pic;
    TShape* button_bldg_pics[5];
    TShape* more_cancel_pic;
    short more_frame;
    short cancel_frame;
    short unselect_frame;
    char gap_4B6[2];

    TRIBE_Main_View* main_view;               // +0x4B8
    TPanel* map_view;
    TPanel* inven_panel;
    TPanel* object_panel;
    TPanel* button_panel[17];
    TPanel* text_line_panel;
    TPanel* quit_message_panel;
    TRIBE_Panel_Time* time_panel;
    TPanel* countdown_clock[10];
    TPanel* pop_panel;
    TPanel* message_panel;
    TPanel* message_panel2;
    TPanel* message_panel3;
    TPanel* message_panel4;
    TPanel* message_panel5;
    TPanel* message_panel6;
    TPanel* chat_panel[8];
    RGE_Panel_Tool_Box* tool_box;
    TPanel* age_panel;
    TPanel* pause_text;
    TPanel* fps_panel;
    TPanel* score_panel[8];
    TPanel* log_text;
    TPanel* log_scrollbar;
    TRIBE_World* world;                       // +0x5B4
    char gap_5B8[0x20];
    BuildingEntry* bldg_list;                // +0x5D8
    char gap_5DC[4];
    short start_item;                         // +0x5E0
    char gap_5E2[0x152];
    int key_buffer_length;                    // +0x734
    char key_buffer[0x34];                    // +0x738
    int select_building_key;                  // +0x76C
    int work_key;                             // +0x770
    int move_key;                             // +0x774
    int attack_key;                           // +0x778
    int ungroup_key;                          // +0x77C
    char gap_780[4];
    int building_hotkeys[8];                  // +0x784

    long key_down_action(long, short, int, int, int);
    void command_group_by_number(int group);
    void command_select_group(int group, int unselect);
    void command_formation(int formation);
    void command_tab_selected(int tab);
    void command_view_selected();
    void command_building(int id);
    void command_select_building(int id);
    void command_player(int player);
    void command_add_attribute(int attribute);
    void command_tool_box();
    void command_quick_build();
    void command_work();
    void command_move();
    void command_attack();
    void command_ungroup();
    void command_score(int enabled);
    void command_fps();
    void command_visibility();
    void command_fog_of_war();
    void command_comm_info();
    void command_ai_info();
    void command_quick_chat();
    void command_cancel_building();
    void reset_clocks();
};

extern RGE_Base_Game* rge_base_game;
extern TPanelSystem panel_system;
extern TCommunications_Handler* comm;
extern TDebuggingLog* L;
extern int allow_user_commands;
extern int MapPathsDisplay;
extern int view_debug_spans;
extern int view_debug_redraw_all;
extern int view_debug_ObstructionMap;
extern int view_debug_Objects;
extern int view_debug_palette;
extern int View_Grid_Mode;
extern int displayPathingFlags;
extern int DAT_0086bac8;
extern char Save_Game_Screen[];
extern const char s_Writing_out_memory_info[];
extern const char s_memory_filename[];
extern const char s_ALLOWCTRLU[];
extern const char s_force_ctrl_u[];

long TRIBE_Screen_Game::key_down_action(long param_1, short param_2,
                                        int param_3, int param_4, int param_5)
{
    int game_over;
    int result;
    char str[512];

    if (panel_system.modalPanel() != 0) {
        return 0;
    }

    RGE_Panel_Tool_Box* tool_box = this->tool_box;
    if (tool_box->field_6C != 0 &&
        tool_box->key_down_action(param_1, param_2, param_3, param_4, param_5) != 0) {
        return 1;
    }

    game_over = (rge_base_game->prog_mode == 5);

    if (param_4 != 0 && param_5 != 0 && param_3 != 0) {
        if (game_over == 0) {
            if ((param_1 <= 0x7A) && (param_1 >= 0x61)) {
                param_1 -= 0x20;
            } else if (((param_1 > 0x5A) || (param_1 < 0x41)) &&
                       ((param_1 < 0x30) || (param_1 > 0x39))) {
                param_1 = 0;
            }

            if (param_1 != 0) {
                if (this->key_buffer_length == 0x32) {
                    this->key_buffer[0x32] = (char)param_1;
                    memcpy(this->key_buffer, this->key_buffer + 1, 0x33);
                } else {
                    this->key_buffer[this->key_buffer_length] = (char)param_1;
                    this->key_buffer_length++;
                    this->key_buffer[this->key_buffer_length] = 0;
                }

                if (rge_base_game->processCheatCode(this->world->curr_player,
                                                     this->key_buffer) != 0) {
                    this->key_buffer_length = 0;
                    this->key_buffer[0] = 0;
                    return 1;
                }
            }
        }
        return 1;
    }

    if (rge_base_game->gameDeveloperMode() != 0 && comm->IsHost() != 0) {
        if (param_4 != 0 && param_5 != 0 &&
            param_1 >= 0x32 && param_1 <= 0x38) {
            comm->Kick(param_1 - 0x30);
            return 1;
        }
    }
    if (param_4 != 0 && param_1 >= 0x30 && param_1 <= 0x39) {
        param_1 -= 0x30;
        this->command_group_by_number((int)param_1);
        return 1;
    }

    if (param_5 != 0) {
        switch (param_1) {
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:
        case 0x38:
        case 0x39:
            param_1 -= 0x30;
            this->command_select_group((int)param_1, 0);
            return 1;
        case 0x70:
            this->setup_popup_help();
            return 1;
        case 0x71:
            if (game_over == 0 && allow_user_commands != 0) {
                this->command_formation(0);
            }
            return 1;
        case 0x72:
            if (game_over == 0 && allow_user_commands != 0) {
                this->command_formation(1);
            }
            return 1;
        case 0x73:
            if (game_over == 0 && allow_user_commands != 0) {
                this->command_formation(2);
            }
            return 1;
        case 0x74:
            if (game_over == 0 && allow_user_commands != 0) {
                this->command_formation(3);
            }
            return 1;
        case 0x75:
            if (game_over == 0 && allow_user_commands != 0) {
                this->command_formation(4);
            }
            return 1;
        case 0x76:
            if (game_over == 0 && allow_user_commands != 0) {
                this->command_formation(5);
            }
            return 1;
        case 9:
            this->command_tab_selected(0);
            return 1;
        default:
            break;
        }
    }

    // BINARY NOTE: Ctrl and Alt 0x49 use different game fields.
    if (param_3 != 0) {
        switch (param_1) {
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:
        case 0x38:
        case 0x39:
            param_1 -= 0x30;
            this->command_select_group((int)param_1, 1);
            this->command_view_selected();
            return 1;
        case 0x49:
            if (rge_base_game->gameDeveloperMode() != 0) {
                rge_base_game->display_selected_ids =
                    (rge_base_game->display_selected_ids == 0);
            }
            return 1;
        case 0x50:
            if (rge_base_game->gameDeveloperMode() != 0) {
                MapPathsDisplay = (MapPathsDisplay == 0);
            }
            return 1;
        case 0x53:
            if (rge_base_game->gameDeveloperMode() != 0) {
                view_debug_spans = (view_debug_spans == 0);
            }
            return 1;
        case 0x43:
            if (rge_base_game->gameDeveloperMode() != 0) {
                view_debug_redraw_all = 1;
            }
            return 1;
        case 0x4F:
            if (rge_base_game->gameDeveloperMode() != 0) {
                view_debug_ObstructionMap = (view_debug_ObstructionMap == 0);
            }
            return 1;
        case 0x41:
            if (rge_base_game->gameDeveloperMode() != 0) {
                view_debug_Objects = (view_debug_Objects == 0);
            }
            return 1;
        case 0x58:
            if (rge_base_game->gameDeveloperMode() != 0) {
                view_debug_palette = (view_debug_palette == 0);
            }
            return 1;
        default:
            return 0;
        }
    }

    result = 1;
    if (param_4 == 0) {
        if (rge_base_game->get_paused() == 0 &&
            rge_base_game->game_mode == 6 &&
            rge_base_game->sub_game_mode == 1) {
            for (int i = 0; i < this->start_item; ++i) {
                RGE_Player* player = rge_base_game->get_player();
                if (param_1 == *this->get_string(
                                  player->master_objects[
                                      this->bldg_list[i].master_object_id]
                                          ->hotkey_id)) {
                    TDigital* sound = rge_base_game->get_sound(1);
                    if (sound != 0) {
                        sound->play();
                    }
                    this->command_building(this->bldg_list[i].master_object_id);
                    return 1;
                }
            }
        }
    }

    if (param_4 != 0) {
        int i = 0;
        int* hotkey = this->building_hotkeys;
        while (i < 8) {
            if (param_1 == *hotkey) {
                this->command_select_building(i);
                return result;
            }
            ++i;
            ++hotkey;
        }
    }

    if (this->select_building_key != 0 &&
        param_1 == this->select_building_key) {
        this->command_select_building(0);
        return 0;
    }

    if (param_4 != 0) {
        if (rge_base_game->gameDeveloperMode() == 0) {
            return 0;
        }

        switch (param_1) {
        case 0x70:
            this->command_player(1);
            return result;
        case 0x71:
            this->command_player(2);
            return result;
        case 0x72:
            this->command_player(3);
            return result;
        case 0x73:
            this->command_player(4);
            return result;
        case 0x74:
            this->command_player(5);
            return result;
        case 0x75:
            this->command_player(6);
            return result;
        case 0x76:
            this->command_player(7);
            return result;
        case 0x77:
            this->command_player(8);
            return result;
        case 0x78:
            this->command_player(0);
            return result;
        case 0x20:
            this->command_view_selected();
            break;
        case 0x45:
            new TribeSaveGameScreen(0, 0, 0);
            panel_system.setCurrentPanel(Save_Game_Screen, 0);
            break;
        case 0x46:
            if (allow_user_commands != 0) {
                this->command_add_attribute(0);
            }
            break;
        case 0x47:
            if (allow_user_commands != 0) {
                this->command_add_attribute(3);
            }
            break;
        case 0x49:
            ((TRIBE_Game*)rge_base_game)->show_object_id =
                (((TRIBE_Game*)rge_base_game)->show_object_id == 0);
            this->object_panel->set_redraw(result);
            return 0;
        case 0x4A:
            comm->TXDebugPing();
            break;
        case 0x4D:
            ++DAT_0086bac8;
            sprintf(str, s_Writing_out_memory_info, DAT_0086bac8);
            ((TRIBE_Game*)rge_base_game)->show_status_message(str, 0, -1);
            sprintf(str, s_memory_filename, DAT_0086bac8);
            rge_base_game->dump_memory_usage(str);
            ((TRIBE_Game*)rge_base_game)->close_status_message();
            break;
        case 0x4E:
            if (rge_base_game->multiplayerGame() == 0) {
                ((TRIBE_Game*)rge_base_game)->restart_game();
            }
            break;
        case 0x4F:
            if (rge_base_game->outline_type != 3) {
                rge_base_game->outline_type = 3;
                return result;
            }
            rge_base_game->outline_type = 2;
            return result;
        case 0x51:
            if (allow_user_commands != 0) {
                this->command_quick_build();
            }
            break;
        case 0x52:
            ++View_Grid_Mode;
            if (rge_base_game->gameDeveloperMode() != 0) {
                if (View_Grid_Mode > 4) {
                    View_Grid_Mode = 0;
                }
            } else if (View_Grid_Mode > result) {
                View_Grid_Mode = 0;
            }
            this->main_view->set_redraw(2);
            return 0;
        case 0x53:
            if (allow_user_commands != 0) {
                this->command_add_attribute(2);
            }
            break;
        case 0x54:
            this->command_tool_box();
            break;
        case 0x55:
            if (rge_base_game->gameDeveloperMode() != 0 &&
                rge_base_game->check_prog_argument(s_ALLOWCTRLU) != 0) {
                TDebuggingLog::Log(L, s_force_ctrl_u);
                displayPathingFlags = (displayPathingFlags == 0);
            }
            break;
        case 0x56:
            new TribeSaveGameScreen(1, 0, 0);
            panel_system.setCurrentPanel(Save_Game_Screen, 0);
            break;
        case 0x57:
            if (allow_user_commands != 0) {
                this->command_add_attribute(1);
            }
            break;
        case 0x58:
            if (allow_user_commands != 0) {
                rge_base_game->get_player()->kickAI(result);
            }
            break;
        case 0x59:
            if (allow_user_commands != 0) {
                rge_base_game->get_player()->kickAI(2);
            }
            break;
        case 0x5A:
            if (allow_user_commands != 0) {
                rge_base_game->get_player()->kickAI(3);
            }
            break;
        default:
            break;
        }
    } else {
        if (rge_base_game->game_mode == 6) {
            if (rge_base_game->sub_game_mode == 1) {
                goto normal_mode_switch;
            }
        }

        // BINARY NOTE: a matched work key returns; a miss reaches the next switch.
        if (this->work_key != 0 && param_1 == this->work_key &&
            game_over == 0) {
            if (allow_user_commands != 0) {
                this->command_work();
            }
            return 0;
        } else if (this->move_key != 0 && param_1 == this->move_key &&
                   game_over == 0) {
            if (allow_user_commands != 0) {
                this->command_move();
            }
            return 0;
        } else if (this->attack_key != 0 && param_1 == this->attack_key &&
                   game_over == 0) {
            if (allow_user_commands != 0) {
                this->command_attack();
            }
            return 0;
        } else if (this->ungroup_key != 0 && param_1 == this->ungroup_key) {
            this->command_ungroup();
            return 0;
        }

    // BINARY NOTE: this switch is after the work-key fall-through blocks.
    normal_mode_switch:
        switch (param_1) {
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:
        case 0x38:
        case 0x39:
            param_1 = param_1 + (-0x30);
            this->command_select_group((int)param_1, result);
            break;
        case 9:
            this->command_tab_selected(result);
            return result;
        case 0x73:
            this->command_score(this->world->score_displayed == 0);
            break;
        case 0x74:
            this->command_fps();
            break;
        case 0x75:
            if (rge_base_game->gameDeveloperMode() != 0) {
                this->command_visibility();
            }
            break;
        case 0x76:
            if (rge_base_game->gameDeveloperMode() != 0) {
                this->command_fog_of_war();
            }
            break;
        case 0x77:
            if (rge_base_game->gameDeveloperMode() != 0) {
                this->command_comm_info();
            }
            break;
        case 0x78:
            if (rge_base_game->gameDeveloperMode() != 0) {
                this->command_ai_info();
            }
            break;
        case 0x7A:
            if (this->time_panel->get_clock_type() == 0) {
                this->time_panel->set_clock_type(2, 0);
                this->pop_panel->set_active(result);
            } else {
                this->time_panel->set_clock_type(0, 0);
                this->pop_panel->set_active(0);
            }
                this->reset_clocks();
                this->main_view->set_redraw(result);
                return 0;
        case 0x20:
            this->command_view_selected();
            break;
        case 0x0D:
            this->command_quick_chat();
            break;
        case 0x24:
            ((TRIBE_Game*)rge_base_game)->goto_notification_loc();
            break;
        case 0x2E:
            if (game_over == 0 && allow_user_commands != 0) {
                this->command_cancel_building();
            }
            break;
        default:
            break;
        }

        return 0;
    }

    return 0;
}
