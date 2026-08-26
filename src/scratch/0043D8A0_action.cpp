// VA: 0043D8A0 TribeDiplomacyDialog::action
// PDB: dlg_dip.cpp lines 434-738
// Baseline reconstruction: named dialog arrays, direct resource/button ownership,
// and the executable's observed command/update branches.
//
// Attempt log:
// - baseline: natural named-field reconstruction; frame was 0x10c and the
//   event parameter was unnecessarily kept in a callee-save register.
// - reversed the capacity comparison to the observed attribute-total form;
//   control-flow similarity moved from 39.68% to 64.82%.
// - changed the top guard to positive nested dispatch; frame became 0x108 and
//   control-flow similarity moved to 79.93%.
// - modeled the contribution arrays as one wood-based cursor with the proven
//   gold/food/stone negative offsets; ordered calls became 124/124 and the
//   structural diff stayed at the 81% shape basin.
// - hoisted the player-id initializer to match the original pre-loop setup;
//   this recovered additional exact blocks but not the missing 87 bytes.
// - declaration-order and explicit shared-fallback-label probes were emitted
//   duplicates; they were removed from the living source after review.
// - canonical surface pass: replaced the rejected TTextPanel vfXX scaffold
//   with TPanel inheritance, named TPanel slots 0..55, the four named text
//   slots, and the proven TDialogPanel/TEasy_Panel additions and layouts.
// - VC5 overload-order probe: declaring set_text(char*), set_text(long), then
//   set_text(char**, short) is required for the binary slots E8/E4/E0; the
//   declarations are intentionally in that source order, not CSV slot order.
// - negative early-guard, if/else-chain, explicit fallback-label, and early
//   return variants did not restore the original block placement; the natural
//   nested dispatch was restored.
// - using player_id - 1 for tribute arrays while retaining the zero-based
//   button index preserves the original two-counter topology and improved the
//   current canonical diff from 2932 to 2916 bytes. Applying the same distinct
//   counter form to all four resource arrays improved it to 2868 bytes,
//   83.97% shape, and 23.53% exact-block coverage.
// - declaring the clear-handler cursor before its total stores follows the
//   original LEA/store order and keeps the best source basin.
// - declaration order, pointer aliases, register hints, split guards, and
//   comparator spellings were tested. They were duplicates or worse.
// - binary stack addresses show that every action formatter and its matching
//   set_text call use one shared temp_str base. The decompiler's +4 aliases
//   were removed; this recovers the original formatter block shape.
// Second-pass handler-layout probes:
// - else-if, while, explicit-break, count-limit, cursor-scope, comparator,
//   and update-condition forms were duplicates or worse.
// - valid top-tested for forms moved the base call before the handlers and
//   aligned all 124 calls, but added a duplicate count test, shortened the
//   body by 98 bytes, and worsened the strict diff to 2882 bytes.
// - behavior-backed handler labels with one base_action target were a VC5
//   codegen duplicate. A malformed empty trailing while looked better at
//   2811 bytes but is rejected as a source artifact.
// - moving index initialization into the for header and using a top break
//   did not improve the valid for frontier. The natural do/while is restored.
// Final paused state: frame 0x108, 124/124 calls with 99.19% ordered alignment,
// 83.97% shape similarity, 23.53% exact-block coverage, rebuilt size 3115 vs.
// original 3201, strict diff 2868. The original uses EBX for the button index
// and EDI for the player id; the clean candidate preserves that distinction in
// resource addresses but still colors the panel and index differently. The
// shared TPanel::action call remains late instead of the original +059c block.
// No manual vfXX/VPAD surface, raw vptr, volatility, inline asm, or custom
// flags remain.

#include <stdio.h>

extern int allow_user_commands;
extern float DAT_0056f880;
extern float DAT_0056f884;
extern double DAT_0056f888;
extern float DAT_0056f890;
extern float DAT_0056f894;

class TDrawArea;
class TButtonPanel;
class TTextPanel;
class TInputPanel;
class TEditPanel;
class TDropDownPanel;
class TListPanel;
class TScrollBarPanel;
class TVerticalSliderPanel;
class THorizontalSliderPanel;

#ifndef DLG_DIP_SHARED_CONTEXT
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

typedef int PositionMode;
typedef int RedrawMode;

// The panel surface is kept in the original declaration order.  In
// particular, action is slot 45 (0xB4); the text-panel additions below then
// start at slot 56 without a synthetic vfXX/padding surface.
class TPanel {
public:
    virtual ~TPanel();                                      // slot 0
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long,
                       unsigned char);                     // slot 1
    virtual void set_rect(tagRECT);                         // slot 2
    virtual void set_rect(long, long, long, long);           // slot 3
    virtual void set_color(unsigned char);                  // slot 4
    virtual void set_active(int);                            // slot 5
    virtual void set_positioning(PositionMode, long, long, long, long,
                                 long, long, long, TPanel*, TPanel*,
                                 TPanel*, TPanel*);          // slot 6
    virtual void set_fixed_position(long, long, long, long); // slot 7
    virtual void set_redraw(RedrawMode);                     // slot 8
    virtual void set_overlapped_redraw(TPanel*, TPanel*, RedrawMode); // slot 9
    virtual void draw_setup(int);                            // slot 10
    virtual void draw_finish();                              // slot 11
    virtual void draw();                                     // slot 12
    virtual void draw_rect(tagRECT*);                        // slot 13
    virtual void draw_offset(long, long, tagRECT*);           // slot 14
    virtual void draw_rect2(tagRECT*);                       // slot 15
    virtual void draw_offset2(long, long, tagRECT*);          // slot 16
    virtual void paint();                                    // slot 17
    virtual long wnd_proc(void*, unsigned int, unsigned int, long); // slot 18
    virtual long handle_idle();                              // slot 19
    virtual long handle_size(long, long);                    // slot 20
    virtual long handle_paint();                             // slot 21
    virtual long handle_key_down(long, short, int, int, int); // slot 22
    virtual long handle_char(long, short);                   // slot 23
    virtual long handle_command(unsigned int, long);         // slot 24
    virtual long handle_user_command(unsigned int, long);    // slot 25
    virtual long handle_timer_command(unsigned int, long);   // slot 26
    virtual long handle_scroll(long, long);                  // slot 27
    virtual long handle_mouse_down(unsigned char, long, long, int, int); // slot 28
    virtual long handle_mouse_move(long, long, int, int);    // slot 29
    virtual long handle_mouse_up(unsigned char, long, long, int, int); // slot 30
    virtual long handle_mouse_dbl_click(unsigned char, long, long, int, int); // slot 31
    virtual long mouse_move_action(long, long, int, int);    // slot 32
    virtual long mouse_left_down_action(long, long, int, int); // slot 33
    virtual long mouse_left_hold_action(long, long, int, int); // slot 34
    virtual long mouse_left_move_action(long, long, int, int); // slot 35
    virtual long mouse_left_up_action(long, long, int, int); // slot 36
    virtual long mouse_left_dbl_click_action(long, long, int, int); // slot 37
    virtual long mouse_right_down_action(long, long, int, int); // slot 38
    virtual long mouse_right_hold_action(long, long, int, int); // slot 39
    virtual long mouse_right_move_action(long, long, int, int); // slot 40
    virtual long mouse_right_up_action(long, long, int, int); // slot 41
    virtual long mouse_right_dbl_click_action(long, long, int, int); // slot 42
    virtual long key_down_action(long, short, int, int, int); // slot 43
    virtual long char_action(long, short);                   // slot 44
    virtual long action(TPanel*, long, unsigned long, unsigned long); // slot 45
    virtual void get_true_render_rect(tagRECT*);             // slot 46
    virtual int is_inside(long, long);                       // slot 47
    virtual void set_focus(int);                             // slot 48
    virtual void set_tab_order(TPanel*, TPanel*);            // slot 49
    virtual void set_tab_order(TPanel**, short);             // slot 50
    virtual unsigned char get_help_info(char**, long*, long, long); // slot 51
    virtual void stop_sound_system();                        // slot 52
    virtual int restart_sound_system();                      // slot 53
    virtual void take_snapshot();                            // slot 54
    virtual void handle_reactivate();                        // slot 55

    TPanel* previousPanelValue;                              // +0x04
    TPanel* previousModalPanelValue;                         // +0x08
    long pnl_x;                                               // +0x0C
    long pnl_y;                                               // +0x10
    long pnl_wid;                                             // +0x14
    long pnl_hgt;                                             // +0x18
    char* panelNameValue;                                     // +0x1C
    void* render_area;                                        // +0x20
    tagRECT clip_rect;                                        // +0x24
    PositionMode position_mode;                               // +0x34
    RedrawMode need_redraw;                                   // +0x38
    TPanel* curr_child;                                       // +0x3C
    TPanel* parent_panel;                                     // +0x40
    TPanel* left_panel;                                       // +0x44
    TPanel* top_panel;                                        // +0x48
    TPanel* right_panel;                                      // +0x4C
    TPanel* bottom_panel;                                     // +0x50
    void* node;                                               // +0x54
    void* first_child_node;                                    // +0x58
    void* last_child_node;                                     // +0x5C
    TPanel* tab_prev_panel;                                    // +0x60
    TPanel* tab_next_panel;                                    // +0x64
    int mouse_captured;                                        // +0x68
    int active;                                                // +0x6C
    int visible;                                               // +0x70
    int tab_stop;                                              // +0x74
    int have_focus;                                            // +0x78
    int overlapping_children;                                  // +0x7C
    int handle_mouse_input;                                    // +0x80
    int just_drawn;                                            // +0x84
    void* clip_rgn;                                            // +0x88
    tagRECT render_rect;                                       // +0x8C
    long left_border;                                          // +0x9C
    long top_border;                                           // +0xA0
    long right_border;                                         // +0xA4
    long bottom_border;                                        // +0xA8
    long min_wid;                                              // +0xAC
    long max_wid;                                              // +0xB0
    long min_hgt;                                              // +0xB4
    long max_hgt;                                              // +0xB8
    long mouse_hold_interval;                                  // +0xBC
    long mouse_move_tolerance;                                 // +0xC0
    long mouse_down_x;                                         // +0xC4
    long mouse_down_y;                                         // +0xC8
    int mouse_down_ctrl;                                       // +0xCC
    int mouse_down_shift;                                      // +0xD0
    unsigned long mouse_down_time;                             // +0xD4
    int error_code;                                            // +0xD8
    int z_order;                                               // +0xDC
    int display_changed_count;                                 // +0xE0
    long help_string_id;                                       // +0xE4
    long help_page_id;                                         // +0xE8
    unsigned char mouse_action;                                // +0xEC
    unsigned char mouse_down_button;                           // +0xED
    unsigned char panel_type;                                  // +0xEE
    unsigned char color;                                       // +0xEF
    unsigned char fill_in_background;                         // +0xF0
    unsigned char clip_to_parent;                              // +0xF1
    unsigned char draw_rect2_flag;                             // +0xF2
    unsigned char need_restore;                                // +0xF3
};

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();                                   // inherited slot 0
    virtual void draw();                                      // inherited slot 12
    virtual void draw_background(int);                        // slot 56
    virtual void set_ideal_size(long, long);                  // slot 57
    virtual int create_button(TPanel*, TButtonPanel**, long, long, long,
                              long, long, long, long, long, long); // slot 58
    virtual int create_button(TPanel*, TButtonPanel**, char*, char*, long,
                              long, long, long, long, long, long); // slot 59
    virtual int create_check_box(TPanel*, TButtonPanel**, long, long, long,
                                 long, long, long);             // slot 60
    virtual int create_radio_button(TPanel*, TButtonPanel**, long, long,
                                    long, long, long, long);    // slot 61
    virtual int create_text(TPanel*, TTextPanel**, int, long, long, long,
                            long, long, int, int, int);         // slot 62
    virtual int create_text(TPanel*, TTextPanel**, char**, long, long, long,
                            long, long, long, int, int);        // slot 63
    virtual int create_text(TPanel*, TTextPanel**, char*, long, long, long,
                            long, long, int, int, int);         // slot 64
    virtual int create_input(TPanel*, TInputPanel**, char*, short, int, long,
                             long, long, long, long);           // slot 65
    virtual int create_edit(TPanel*, TEditPanel**, char*, short, int, long,
                            long, long, long, long, int, int); // slot 66
    virtual int create_drop_down(TPanel*, TDropDownPanel**, long, long, long,
                                 long, long, long, long);       // slot 67
    virtual int create_list(TPanel*, TListPanel**, long, long, long, long,
                            long, long);                       // slot 68
    virtual int create_scrollbar(TPanel*, TTextPanel*, long, long, long, long,
                                 long, long);                   // slot 69
    virtual int create_auto_scrollbar(TScrollBarPanel**, TTextPanel*, long); // slot 70
    virtual int create_vert_slider(TPanel*, TVerticalSliderPanel**, long,
                                   long, long, long, long, long, long); // slot 71
    virtual int create_horz_slider(TPanel*, THorizontalSliderPanel**, long,
                                   long, long, long, long, long, long); // slot 72
    virtual void position_panel(TPanel*, long, long, long, long); // slot 73

    long ideal_width;                                          // +0xF4
    long ideal_height;                                         // +0xF8
    char info_file_name[260];                                  // +0xFC
    long info_id;                                              // +0x200
    void* background_pic;                                      // +0x204
    void* background_pic2;                                     // +0x208
    void* palette;                                             // +0x20C
    char cursor_file[260];                                     // +0x210
    long cursor_id;                                             // +0x314
    int background_pos;                                        // +0x318
    int use_bevels;                                            // +0x31C
    unsigned char bevel_color1;                                // +0x320
    unsigned char bevel_color2;                                // +0x321
    unsigned char bevel_color3;                                // +0x322
    unsigned char bevel_color4;                                // +0x323
    unsigned char bevel_color5;                                // +0x324
    unsigned char bevel_color6;                                // +0x325
    unsigned char gap_326[2];                                  // +0x326
    unsigned long text_color1;                                 // +0x328
    unsigned long text_color2;                                 // +0x32C
    unsigned long focus_color1;                                // +0x330
    unsigned long focus_color2;                                // +0x334
    unsigned long state_color1;                                // +0x338
    unsigned long state_color2;                                // +0x33C
    char popup_info_file_name[260];                            // +0x340
    long popup_info_id;                                        // +0x444
    void* button_pics;                                         // +0x448
    void* shadow_color_table;                                  // +0x44C
    long shadow_amount;                                        // +0x450
    unsigned char background_color1;                           // +0x454
    unsigned char background_color2;                           // +0x455
    unsigned char gap_456[2];                                  // +0x456
    int enable_ime;                                            // +0x458
    unsigned char help_mode;                                   // +0x45C
    unsigned char gap_45D[3];                                  // +0x45D
    int stock_brush;                                           // +0x460
    void* brush;                                               // +0x464
    unsigned long brush_color;                                 // +0x468
    void* shadow_area;                                         // +0x46C
    int allow_shadow_area;                                     // +0x470
    int saved_mouse_mode;                                      // +0x474

    void setup_popup_help();
};

class TDialogPanel : public TEasy_Panel {
public:
    virtual ~TDialogPanel();                                   // inherited slot 0
    virtual int setup(TDrawArea*, TPanel*, long, long,
                      unsigned char, int);                    // slot 74
    virtual int setup(TDrawArea*, TPanel*, long, long, char*,
                      long, int);                             // slot 75

    void* dlg_wnd;                                              // +0x478
    TPanel* save_parent_child;                                  // +0x47C
    int text_font_id;                                           // +0x480
    int input_font_id;                                          // +0x484
    int button_font_id;                                         // +0x488
    int button_sound_id;                                        // +0x48C
};

class TButtonPanel : public TPanel {
public:
    virtual ~TButtonPanel();
    int get_state();
    void set_text(short state, char* text);
};

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
    virtual void set_text(char*);                               // slot 58
    virtual void set_text(long);                                // slot 57
    virtual void set_text(char**, short);                       // slot 56
    virtual void set_bevel_info(int, int, int, int, int, int, int); // slot 59

    void* list;                                                  // +0xF4
    short num_lines;                                             // +0xF8
    short draw_lines;                                             // +0xFA
    short top_line;                                               // +0xFC
    short bot_line;                                               // +0xFE
    short cur_line;                                               // +0x100
    short cur_col;                                                // +0x102
    void* font;                                                   // +0x104
    long font_wid;                                                // +0x108
    long font_hgt;                                                // +0x10C
    int vert_align;                                               // +0x110
    int horz_align;                                               // +0x114
    int word_wrap;                                                // +0x118
    int text_style;                                               // +0x11C
    unsigned long text_color1;                                   // +0x120
    unsigned long text_color2;                                   // +0x124
    unsigned long highlightTextColor1;                           // +0x128
    unsigned long highlightTextColor2;                           // +0x12C
    void* scbar_panel;                                            // +0x130
    int auto_scbar;                                                // +0x134
    short fixed_len;                                               // +0x138
    unsigned char gap_13A[2];                                     // +0x13A
    long text_wid;                                                 // +0x13C
    long text_hgt;                                                 // +0x140
    void* back_pic;                                                // +0x144
    short back_pic_wid;                                            // +0x148
    short back_pic_hgt;                                            // +0x14A
    int fill_back;                                                 // +0x14C
    unsigned char back_color;                                     // +0x150
    unsigned char gap_151[3];                                     // +0x151
    int outline;                                                   // +0x154
    unsigned char outline_color;                                  // +0x158
    unsigned char gap_159[3];                                     // +0x159
    int sorted;                                                    // +0x15C
    long second_column_pos;                                        // +0x160
    long full_width;                                               // +0x164
    long scbar_width;                                              // +0x168
    int scbar_active;                                              // +0x16C
    int bevel_type;                                                // +0x170
    unsigned char bevel_color1;                                   // +0x174
    unsigned char bevel_color2;                                   // +0x175
    unsigned char bevel_color3;                                   // +0x176
    unsigned char bevel_color4;                                   // +0x177
    unsigned char bevel_color5;                                   // +0x178
    unsigned char bevel_color6;                                   // +0x179
    unsigned char gap_17A[2];                                     // +0x17A
    void* clip_rgn2;                                               // +0x17C
    int border_size;                                               // +0x180
    int spacer_size;                                               // +0x184
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char value);
    virtual void do_resign(int value);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int value);
    virtual int isEnemy(int value);
    virtual int isAlly(int value);
    virtual int isNeutral(int value);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int value, int value2);
    virtual void loadAIInformation(char* a, char* b, char* c, int d, int e);
    virtual void sendUnitAIOrder(int a, int b, int c, int d, int e,
                                 float f, float g, float h, float i, int j, int k, int l);
    virtual void processAIOrder(int a, int b, int c, int d, int e,
                                float f, float g, float h, float i, int j, int k, int l);
    virtual void kickAI(int value);
    virtual int strategicNumber(int value);
    virtual void sendGameOrder(void* a, void* b, float c, float d);
    virtual void sendAddWaypointCommand(int a, void* b, int c);
    virtual void processAddWaypointCommand(int a, void* b, int c);
    virtual void sendPlayCommand(int a, int* b, int c, int d, int e);
    virtual void sendPlayCommand(int a, int b, int c);
    virtual int sendAICommand(int a, int b, int c, int d, int e);
    virtual int objectCostByType(int value);
    virtual void trackUnitGather(int a, int b, int c);
    virtual void* make_scenario_obj(float a, float b, float c, short d, unsigned char e, float f);
    virtual void scenario_save(int value);
    virtual void scenario_load(int a, long* b, float c);
    virtual void scenario_postsave(int value);
    virtual void scenario_postload(int a, long* b, float c);
    virtual void load(int value);
    virtual void add_attribute_num(short a, float b, unsigned char c);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int value);
    virtual void save2(int value);
    virtual void save_info(int value);
    virtual void random_start();
    virtual void* make_new_object(long a, float b, float c, float d, int e);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int a, int* b, int* c);
    virtual unsigned char command_make_move(void* a, float b, float c);
    virtual unsigned char command_make_work(void* a, float b, float c);
    virtual unsigned char command_make_do(void* a, float b, float c);
    virtual unsigned char command_stop();
    virtual unsigned char command_place_object(short a, float b, float c, float d);
    virtual unsigned char command_add_attribute(int a, float b);
    virtual unsigned char command_give_attribute(int a, int b, float c);
    virtual unsigned char command_formation(int value);
    virtual unsigned char command_stand_ground();
    virtual unsigned char command_create_group(int a, int* b, int c, float d);
    virtual unsigned char command_add_to_group(int a, int b, float c);
    virtual unsigned char command_remove_from_group(int a, int b);
    virtual unsigned char command_destroy_group(int value);
    virtual unsigned char command_resign(int a, int b);
    virtual unsigned char command_add_waypoint(float a, float b, float c);
    virtual void* addObject(void* a, int b, int c);
    virtual void removeObject(void* a, int b, int c, void* d);
    virtual void logMessage(char* value);
    virtual void notify(int a, int b, int c, long d, long e, long f);
    virtual void logStatus(void* file, int value);
    virtual void load_victory(int a, long* b, unsigned char c);
    virtual void new_victory();

    char gap_04[0x46];
    short id;
    char gap_4C[4];
    float* attributes;

    unsigned char get_allied_victory();
    unsigned char relation(long player_id);
};

class TRIBE_Player : public RGE_Player {
public:
    virtual unsigned char command_give_attribute(int player_id, int attribute,
                                                  float amount, float current_amount);
};

class TRIBE_Command {
public:
    void command_allied_victory(short player_id, unsigned char flag);
    void command_relation(short player_id, short target_id, short stance);
};

class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_num;
    char gap_3E[0x1A];
    TRIBE_Command* commands;
    char gap_5C[0x20];
    short curr_player;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x3F0];
    RGE_Game_World* world;
    char gap_3F8[0x608];
    int save_paused;

    RGE_Player* get_player();
    int singlePlayerGame();
    void set_paused(int paused, int value);
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int mode);
    int destroyPanel(char* name);
};

extern RGE_Base_Game* rge_base_game;
extern TPanelSystem panel_system;

class TribeDiplomacyDialog : public TDialogPanel {
public:
    TTextPanel* title[8];
    TTextPanel* playerName[8];
    TTextPanel* playerVictoryScores[8];
    TTextPanel* playerCivilization[8];
    TTextPanel* needMarket;
    TButtonPanel* goldTributeButton[8];
    TButtonPanel* woodTributeButton[8];
    TButtonPanel* foodTributeButton[8];
    TButtonPanel* stoneTributeButton[8];
    TButtonPanel* allyButton[24];
    TButtonPanel* allianceButton;
    TButtonPanel* okButton;
    TButtonPanel* clearButton;
    TButtonPanel* cancelButton;
    TButtonPanel* help_button;
    void* buttonPics;
    void* backgroundPics;
    float foodTotal;
    float woodTotal;
    float goldTotal;
    float stoneTotal;
    TTextPanel* playerFood;
    TTextPanel* playerGold;
    TTextPanel* playerWood;
    TTextPanel* playerStone;
    float goldTributeAmount[8];
    float foodTributeAmount[8];
    float stoneTributeAmount[8];
    float woodTributeAmount[8];
    int cur_player_row;
    int tribute_flag;

protected:
    int check_gold();
    int check_wood();
    int check_food();
    int check_stone();
    virtual long action(TPanel* panel, long event, unsigned long param_3, unsigned long param_4);
};
#endif

long TribeDiplomacyDialog::action(TPanel* panel, long event,
                                  unsigned long param_3, unsigned long param_4)
{
    char temp_str[256];
    float cost;
    TRIBE_Command* tc;

    if (panel) {
    if (event == 1) {

    if (panel == this->okButton) {
        tc = rge_base_game->world->commands;
        if (allow_user_commands != 0) {
            unsigned char allied = rge_base_game->get_player()->get_allied_victory();
            if (this->allianceButton->get_state() != allied) {
                tc->command_allied_victory(rge_base_game->get_player()->id,
                                           this->allianceButton->get_state());
            }
        }

        int player_id = 1;
        if (rge_base_game->world->player_num - 1 > 0) {
            float* tribute = this->woodTributeAmount;
            TButtonPanel** ally = this->allyButton;
            do {
                if (player_id != rge_base_game->world->curr_player && ally[0] != 0) {
                    unsigned char relation;
                    if (ally[0]->get_state() == 1) {
                        relation = 0;
                    } else {
                        relation = (unsigned char)((ally[1]->get_state() != 1) ? 3 : 1);
                    }

                    if (allow_user_commands != 0) {
                        if (rge_base_game->get_player()->relation(player_id) != relation) {
                            tc->command_relation(rge_base_game->get_player()->id,
                                                  (short)player_id, (short)relation);
                        }

                        if (tribute[-24] > DAT_0056f884) {
                            ((TRIBE_Player*)rge_base_game->get_player())->command_give_attribute(
                                player_id, 3, tribute[-24],
                                rge_base_game->get_player()->attributes[0x2e]);
                        }
                        if (tribute[0] > DAT_0056f884) {
                            ((TRIBE_Player*)rge_base_game->get_player())->command_give_attribute(
                                player_id, 1, tribute[0],
                                rge_base_game->get_player()->attributes[0x2e]);
                        }
                        if (tribute[-16] > DAT_0056f884) {
                            ((TRIBE_Player*)rge_base_game->get_player())->command_give_attribute(
                                player_id, 0, tribute[-16],
                                rge_base_game->get_player()->attributes[0x2e]);
                        }
                        if (tribute[-8] > DAT_0056f884) {
                            ((TRIBE_Player*)rge_base_game->get_player())->command_give_attribute(
                                player_id, 2, tribute[-8],
                                rge_base_game->get_player()->attributes[0x2e]);
                        }
                    }
                }
                ++ally;
                ++tribute;
                ++player_id;
            } while (player_id < rge_base_game->world->player_num);
        }

        if (rge_base_game->singlePlayerGame() == 1 && rge_base_game->save_paused == 0) {
            rge_base_game->set_paused(0, 0);
            panel_system.setCurrentPanel("Game Screen", 0);
            panel_system.destroyPanel("Diplomacy Dialog");
            return 1;
        }
        goto close_dialog;
    }

    if (panel == this->cancelButton) {
        if (rge_base_game->singlePlayerGame() == 1 && rge_base_game->save_paused == 0) {
            rge_base_game->set_paused(0, 0);
        }
        goto close_dialog;
    }

    if (panel == this->help_button) {
        this->setup_popup_help();
        return 1;
    }

    if (panel == this->clearButton) {
        TButtonPanel** buttons = this->foodTributeButton;
        this->foodTotal = 0.0f;
        this->goldTotal = 0.0f;
        this->stoneTotal = 0.0f;
        this->woodTotal = 0.0f;

        for (int i = 0; i < 8; ++i) {
            if (buttons[-16] != 0) {
                buttons[-16]->set_text(0, "");
            }
            if (buttons[0] != 0) {
                buttons[0]->set_text(0, "");
            }
            if (buttons[-8] != 0) {
                buttons[-8]->set_text(0, "");
            }
            if (buttons[8] != 0) {
                buttons[8]->set_text(0, "");
            }
            buttons[55] = 0;
            buttons[63] = 0;
            buttons[71] = 0;
            buttons[79] = 0;
            ++buttons;
        }

        sprintf(temp_str, "%ld",
                (long)rge_base_game->get_player()->attributes[3]);
        this->playerGold->set_text(temp_str);
        sprintf(temp_str, "%ld",
                (long)rge_base_game->get_player()->attributes[0]);
        this->playerFood->set_text(temp_str);
        sprintf((char*)&tc, "%ld",
                (long)rge_base_game->get_player()->attributes[1]);
        this->playerWood->set_text((char*)&tc);
        sprintf(temp_str, "%ld",
                (long)rge_base_game->get_player()->attributes[2]);
        this->playerStone->set_text(temp_str);
        this->check_gold();
        this->check_wood();
        this->check_stone();
        this->check_food();
        return 1;
    }

    {
    cost = 0.0f;
    if (rge_base_game->get_player()->attributes[0x2e] > DAT_0056f888) {
        cost = rge_base_game->get_player()->attributes[0x2e];
    }

    int index = 0;
    int player_id = 1;
    int player_count = rge_base_game->world->player_num - 1;
    if (player_count > 0) {
        TButtonPanel** buttons = this->woodTributeButton;
        do {
            if (panel == buttons[-8]) {
                if (this->check_gold() == 0) {
                    cost = cost - DAT_0056f890;
                    if (rge_base_game->get_player()->attributes[3] - this->goldTotal >=
                        cost * DAT_0056f880) {
                        this->goldTributeAmount[player_id - 1] =
                            this->goldTributeAmount[player_id - 1] - DAT_0056f894;
                        this->goldTotal = this->goldTotal - cost * DAT_0056f894;
                    } else {
                        float amount =
                            (rge_base_game->get_player()->attributes[3] - this->goldTotal) / cost;
                        this->goldTributeAmount[player_id - 1] =
                            amount + this->goldTributeAmount[player_id - 1];
                        this->goldTotal = amount * cost + this->goldTotal;
                    }
                    sprintf(temp_str, "%ld",
                            (long)(rge_base_game->get_player()->attributes[3] - this->goldTotal));
                    this->playerGold->set_text(temp_str);
                    sprintf(temp_str, "%ld",
                            (long)this->goldTributeAmount[player_id - 1]);
                    this->goldTributeButton[index]->set_text(0, temp_str);
                    this->check_gold();
                    return 1;
                }
                sprintf(temp_str, "%ld",
                        (long)(rge_base_game->get_player()->attributes[3] - this->goldTotal));
                this->playerGold->set_text(temp_str);
                this->check_gold();
                return 1;
            }

            if (panel == buttons[0]) {
                if (this->check_wood() == 0) {
                    cost = cost - DAT_0056f890;
                    if (rge_base_game->get_player()->attributes[4] - this->woodTotal >=
                        cost * DAT_0056f880) {
                        this->woodTributeAmount[player_id - 1] =
                            this->woodTributeAmount[player_id - 1] - DAT_0056f894;
                        this->woodTotal = this->woodTotal - cost * DAT_0056f894;
                    } else {
                        float amount =
                            (rge_base_game->get_player()->attributes[4] - this->woodTotal) / cost;
                        this->woodTributeAmount[player_id - 1] =
                            amount + this->woodTributeAmount[player_id - 1];
                        this->woodTotal = amount * cost + this->woodTotal;
                    }
                    sprintf(temp_str, "%ld",
                            (long)(rge_base_game->get_player()->attributes[4] - this->woodTotal));
                    this->playerWood->set_text(temp_str);
                    sprintf(temp_str, "%ld",
                            (long)this->woodTributeAmount[player_id - 1]);
                    this->woodTributeButton[index]->set_text(0, temp_str);
                    this->check_wood();
                    return 1;
                }
                sprintf(temp_str, "%ld",
                        (long)(rge_base_game->get_player()->attributes[4] - this->woodTotal));
                this->playerWood->set_text(temp_str);
                this->check_wood();
                return 1;
            }

            if (panel == buttons[8]) {
                if (this->check_food() == 0) {
                    cost = cost - DAT_0056f890;
                    if (rge_base_game->get_player()->attributes[0] - this->foodTotal >=
                        cost * DAT_0056f880) {
                        this->foodTributeAmount[player_id - 1] =
                            this->foodTributeAmount[player_id - 1] - DAT_0056f894;
                        this->foodTotal = this->foodTotal - cost * DAT_0056f894;
                    } else {
                        float amount =
                            (rge_base_game->get_player()->attributes[0] - this->foodTotal) / cost;
                        this->foodTributeAmount[player_id - 1] =
                            amount + this->foodTributeAmount[player_id - 1];
                        this->foodTotal = amount * cost + this->foodTotal;
                    }
                    sprintf(temp_str, "%ld",
                            (long)(rge_base_game->get_player()->attributes[0] - this->foodTotal));
                    this->playerFood->set_text(temp_str);
                    sprintf(temp_str, "%ld",
                            (long)this->foodTributeAmount[player_id - 1]);
                    this->foodTributeButton[index]->set_text(0, temp_str);
                    this->check_food();
                    return 1;
                }
                sprintf(temp_str, "%ld",
                        (long)(rge_base_game->get_player()->attributes[0] - this->foodTotal));
                this->playerFood->set_text(temp_str);
                this->check_food();
                return 1;
            }

            if (panel == buttons[16]) {
                if (this->check_stone() == 0) {
                    cost = cost - DAT_0056f890;
                    if (rge_base_game->get_player()->attributes[2] - this->stoneTotal >=
                        cost * DAT_0056f880) {
                        this->stoneTributeAmount[player_id - 1] =
                            this->stoneTributeAmount[player_id - 1] - DAT_0056f894;
                        this->stoneTotal = this->stoneTotal - cost * DAT_0056f894;
                    } else {
                        float amount =
                            (rge_base_game->get_player()->attributes[2] - this->stoneTotal) / cost;
                        this->stoneTributeAmount[player_id - 1] =
                            amount + this->stoneTributeAmount[player_id - 1];
                        this->stoneTotal = amount * cost + this->stoneTotal;
                    }
                    sprintf(temp_str, "%ld",
                            (long)(rge_base_game->get_player()->attributes[2] - this->stoneTotal));
                    this->playerStone->set_text(temp_str);
                    sprintf(temp_str, "%ld",
                            (long)this->stoneTributeAmount[player_id - 1]);
                    this->stoneTributeButton[index]->set_text(0, temp_str);
                    this->check_stone();
                    return 1;
                }
                sprintf(temp_str, "%ld",
                        (long)(rge_base_game->get_player()->attributes[2] - this->stoneTotal));
                this->playerStone->set_text(temp_str);
                this->check_stone();
                return 1;
            }

            ++index;
            ++buttons;
            ++player_id;
        } while (index < player_count);
    }

    }

    }

    }

    return TPanel::action(panel, event, param_3, param_4);

close_dialog:
    panel_system.setCurrentPanel("Game Screen", 0);
    panel_system.destroyPanel("Diplomacy Dialog");
    return 1;
}
