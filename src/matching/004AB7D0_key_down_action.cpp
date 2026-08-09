// 004AB7D0 TRIBE_Screen_Sed::key_down_action
// scr_sed.cpp:2249-2503
//
// Reconstructed from the original switch structure and the named screen/panel
// ownership in the generated type reference.  In particular, the first switch
// is the modified-key scenario-mode hotkey switch; the second switch handles
// tab/cancel/delete and the numeric player selectors.
//
// Attempt log:
// - Replaced the prior placeholder modal/input and function-key model with the
//   binary-backed TPanelSystem modal guard and the two actual key switches.
// - Restored the __thiscall ABI (long, short, int, int, int), the screen field
//   ownership, and the exact TPanel/TButtonPanel virtual slots.
// - Kept scenario-mode cases in their source/PDB order (M,T,P,U,D,I,V,O,W,C,
//   with the grid-mode B case last) and numeric cases before tab/cancel/delete;
//   this reproduces the original jump-table handler placement.
// - Exact baseline: 1121 bytes, 45 ordered calls, 0-byte positional diff.

typedef unsigned char uchar;

struct tagRECT;
class TDrawArea;
class TPanel;
class TTextPanel;
class TEditPanel;
class TDropDownPanel;
class TButtonPanel;
class RGE_Player;
class RGE_Static_Object;
class RGE_Sprite;
class RGE_Active_Sprite_List;
class RGE_Base_Game;
class TRIBE_Main_View;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, uchar);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(uchar);
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
    virtual long handle_mouse_down(uchar, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(uchar, long, long, int, int);
    virtual long handle_mouse_dbl_click(uchar, long, long, int, int);
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
    virtual uchar get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    char gap_04[0x38];
    TPanel* curr_child;             // +0x3C
    char gap_40[0x2C];
    int field_6C;                   // +0x6C
    char gap_70[0x84];

    void set_curr_child(TPanel* child);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TTextPanel : public TPanel {};
class TEditPanel : public TTextPanel {};

class TDropDownPanel : public TTextPanel {
public:
    void setCurrentLineNumber(long line);
};

class TButtonPanel : public TPanel {
public:
    virtual void set_option(int value);     // vtable +0xE0
};

class TRIBE_Main_View : public TPanel {};

class TPanelSystem {
public:
    TPanel* modalPanel();
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x4C];
    uchar outline_type;              // +0x50
    char gap_51[0x40];
    uchar gameDeveloperModeValue;    // +0x91

    int gameDeveloperMode();
    RGE_Player* get_player();
};

class RGE_Player {
public:
    char gap_00[0x130];
    RGE_Static_Object* selected_obj; // +0x130
};

class RGE_Sprite {
public:
    uchar get_lowest_draw_level();
};

class RGE_Active_Sprite_List {
public:
    uchar get_lowest_draw_level();
};

class RGE_Static_Object {
public:
    virtual void set_selected(int selected);
    char gap_04[0x0C];
    RGE_Sprite* sprite;              // +0x10
    char gap_14[4];
    RGE_Active_Sprite_List* sprite_list; // +0x18
};

enum ScenarioMode {
    ScenarioModeNone = 0,
    ScenarioModeMap = 1,
    ScenarioModeTerrain = 2,
    ScenarioModePlayers = 3,
    ScenarioModeUnits = 4,
    ScenarioModeDiplomacy = 5,
    ScenarioModeVictory = 6,
    ScenarioModeVictoryMulti = 7,
    ScenarioModeOptions = 8,
    ScenarioModeMessages = 9,
    ScenarioModeCinematics = 10,
    ScenarioModeSave = 11
};

class TRIBE_Screen_Sed : public TScreenPanel {
public:
    int is_multi_player;             // +0x478
    int set_player_first_flag;
    RGE_Static_Object* SelectedObject;
    RGE_Static_Object* DestinationObject;
    float px1;
    float py1;
    float px2;
    float py2;
    int CurrentVictory;
    int CurrentPlayer;
    int SelectRegionFlag;
    ScenarioMode scenario_mode;      // +0x4A4
    int map_type;
    int mp_victory_type;
    int brush_size;
    int paint_type;
    short player_num;                // +0x4B8
    char gap_4BA[2];
    int message_type;
    uchar need_to_save_flag;
    uchar valid_save_spot_flag;
    char gap_4C2[2];
    void* background_pic;
    TRIBE_Main_View* main_view;      // +0x4C8
    TPanel* map_view;
    TPanel* message_panel;
    TPanel* bottom_panel;            // +0x4D4
    TButtonPanel* scenario_mode_button[10]; // +0x4D8
    char gap_500[0x5B4 - 0x500];
    TDropDownPanel* player_list;     // +0x5B4
    char gap_5B8[0x5D8 - 0x5B8];
    TEditPanel* player_inven_input[5]; // +0x5D8
    char gap_5EC[0x618 - 0x5EC];
    TDropDownPanel* unit_player_list; // +0x618
    char gap_61C[0x73C - 0x61C];
    TDropDownPanel* victory_player_list; // +0x73C
    char gap_740[0x76C - 0x740];
    TEditPanel* victory_amount_input; // +0x76C
    char gap_770[0x7CC - 0x770];
    TDropDownPanel* options_player_list; // +0x7CC
    char gap_7D0[0x894 - 0x7D0];
    TDropDownPanel* Diplomacy_player_list; // +0x894

    void set_scenario_mode(int mode);
    void command_cancel();
    void SaveDisabledItemsInScenario();
    void LoadDisabledItemsFromScenario();
    void set_player(short player, uchar update, uchar refresh);
    long key_down_action(long key, short ch, int a3, int a4, int a5);
};

extern TPanelSystem panel_system;
extern RGE_Base_Game* rge_base_game;
extern int View_Grid_Mode;

long TRIBE_Screen_Sed::key_down_action(long param_1, short param_2,
                                        int param_3, int param_4, int param_5)
{
    if (panel_system.modalPanel() == 0) {
        if (param_4 != 0) {
            switch (param_1) {
            case 0x41:
                if (rge_base_game->outline_type != 3) {
                    rge_base_game->outline_type = 3;
                    return 1;
                }
                rge_base_game->outline_type = 0;
                return 1;
            case 0x4D:
                this->scenario_mode_button[0]->set_option(1);
                this->set_scenario_mode(ScenarioModeMap);
                return 0;
            case 0x54:
                this->scenario_mode_button[1]->set_option(1);
                this->set_scenario_mode(ScenarioModeTerrain);
                return 0;
            case 0x50:
                this->scenario_mode_button[2]->set_option(1);
                this->set_scenario_mode(ScenarioModePlayers);
                return 0;
            case 0x55:
                this->scenario_mode_button[3]->set_option(1);
                this->set_scenario_mode(ScenarioModeUnits);
                return 0;
            case 0x44:
                this->scenario_mode_button[4]->set_option(1);
                this->set_scenario_mode(ScenarioModeDiplomacy);
                return 0;
            case 0x49:
                this->scenario_mode_button[5]->set_option(1);
                this->set_scenario_mode(ScenarioModeVictory);
                return 0;
            case 0x56:
                this->scenario_mode_button[6]->set_option(1);
                this->set_scenario_mode(ScenarioModeVictoryMulti);
                return 0;
            case 0x4F:
                this->scenario_mode_button[7]->set_option(1);
                this->set_scenario_mode(ScenarioModeOptions);
                return 0;
            case 0x57:
                this->scenario_mode_button[8]->set_option(1);
                this->set_scenario_mode(ScenarioModeMessages);
                return 0;
            case 0x43:
                this->scenario_mode_button[9]->set_option(1);
                this->set_scenario_mode(ScenarioModeCinematics);
                return 0;
            case 0x42:
                ++View_Grid_Mode;
                if (rge_base_game->gameDeveloperMode() != 0) {
                    if (View_Grid_Mode > 4) {
                        View_Grid_Mode = 0;
                    }
                } else if (View_Grid_Mode > 1) {
                    View_Grid_Mode = 0;
                }
                this->main_view->set_redraw(2);
                return 0;
            default:
                return 0;
            }
        }

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
            {
                ScenarioMode mode = this->scenario_mode;
                int i = param_1 - 0x30;
                short selected = (short)i;

                if ((mode == ScenarioModeOptions) && (0 < i)) {
                    this->SaveDisabledItemsInScenario();
                    this->options_player_list->setCurrentLineNumber(i - 1);
                    this->action(this->options_player_list, 3, 0, 0);
                    this->set_player(selected, 0, 0);
                    this->player_num = selected;
                    this->LoadDisabledItemsFromScenario();
                    return 0;
                }

                if ((mode == ScenarioModePlayers) && (0 < i)) {
                    if (this->bottom_panel->curr_child == 0) {
                        this->player_list->setCurrentLineNumber(i - 1);
                        this->action(this->player_list, 0, 0, 0);
                        return 0;
                    }
                } else {
                    if (mode == ScenarioModeUnits) {
                        this->unit_player_list->setCurrentLineNumber(i);
                        this->action(this->unit_player_list, 0, 0, 0);
                        return 0;
                    }
                    if ((mode == ScenarioModeVictory) && (0 < i)) {
                        if (this->bottom_panel->curr_child == 0) {
                            this->victory_player_list->setCurrentLineNumber(i - 1);
                            this->action(this->victory_player_list, 1, 0, 0);
                            return 0;
                        }
                    } else if (mode == ScenarioModeDiplomacy) {
                        if (0 < i) {
                            this->Diplomacy_player_list->setCurrentLineNumber(i - 1);
                            this->action(this->Diplomacy_player_list, 1, 0, 0);
                            return 0;
                        }
                    } else if (0 < i) {
                        this->set_player(selected, 0, 0);
                        this->player_num = selected;
                        return 0;
                    }
                }
            }
            break;
        case 9:
            if (this->scenario_mode == ScenarioModePlayers) {
                if (this->bottom_panel->curr_child == 0) {
                    this->bottom_panel->set_curr_child(this->player_inven_input[0]);
                    return 0;
                }
            } else if ((this->scenario_mode == ScenarioModeVictory) &&
                       (this->bottom_panel->curr_child == 0) &&
                       (this->victory_amount_input->field_6C != 0)) {
                this->bottom_panel->set_curr_child(this->victory_amount_input);
                return 0;
            }
            break;
        case 0x1B:
            this->command_cancel();
            return 0;
        case 0x2E:
            if (this->scenario_mode == ScenarioModeUnits) {
                RGE_Player* player = rge_base_game->get_player();
                RGE_Static_Object* object = player->selected_obj;
                if (object != 0) {
                    uchar draw_level;
                    if (object->sprite_list != 0) {
                        draw_level = object->sprite_list->get_lowest_draw_level();
                    } else if (object->sprite != 0) {
                        draw_level = object->sprite->get_lowest_draw_level();
                    } else {
                        draw_level = 0x14;
                    }
                    object->set_selected(1);
                    if (draw_level == 0) {
                        this->main_view->set_redraw(2);
                    }
                }
                return 1;
            }
            break;
        default:
            break;
        }
    }

    return 0;
}
