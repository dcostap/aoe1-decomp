// 004B4880 TribeGameSettingsScreen constructor
// Attempt log:
// baseline: natural scr_set panel hierarchy, complete named TPanel/TEasy_Panel
// virtual surfaces, exact screen fields, /GX base construction, and guarded
// panel setup sequence reconstructed from scr_set.cpp and the binary packet.
// tried preserving the first multiplayerGame result in a local to keep its
// selection branch ahead of the second setup-argument call.
// default scr3 plus a zero-result scr2 assignment reproduced the observed
// setup-file branch; caching draw_area reproduced the setup argument order.
// scenario victory if/else reproduced the binary's branch-owned append sites.
// num_str base and <= 200 reproduced the sprintf loop buffer and bound.
// Remaining nonexact drift is localized at scenario-list column arithmetic:
// VC5 keeps the receiver load/operand order different despite equivalent
// natural spellings; later branch displacements shift by two bytes.
// continuation: declaring a receiver local after the arithmetic, naming both
// width operands, using int temporaries, and calling through the proven
// TTextPanel base view all emitted the same 779-byte result.
// A focused /GX arithmetic lab covered inline, sequential, and temporary
// natural forms; all six variants kept size/frame/call-set parity but retained
// the localized hunk. The analogous 004B3C90 constructor proves the desired
// delayed receiver order in the same VC5 family; no natural local/source axis
// found here reproduces it. Clean source restored; leave the register-order
// barrier for a later donor/context investigation.

#include <stdio.h>

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

typedef int PositionMode;
typedef int RedrawMode;
typedef int FormatType;

class TPanel;
class TTextPanel;
class TButtonPanel;
class TDropDownPanel;
class TListPanel;
class TScrollBarPanel;
class TInputPanel;
class TEditPanel;
class TVerticalSliderPanel;
class THorizontalSliderPanel;
class TDrawArea;
class PanelNode;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea* draw_area, TPanel* parent, long p3,
                       long p4, long p5, long p6, unsigned char p7);
    virtual void set_rect(tagRECT rect);
    virtual void set_rect(long x, long y, long width, long height);
    virtual void set_color(unsigned char color);
    virtual void set_active(int active);
    virtual void set_positioning(PositionMode mode, long p2, long p3, long p4,
                                 long p5, long p6, long p7, long p8, long p9,
                                 TPanel* p10, TPanel* p11, TPanel* p12,
                                 TPanel* p13);
    virtual void set_fixed_position(long x, long y, long width, long height);
    virtual void set_redraw(RedrawMode mode);
    virtual void set_overlapped_redraw(TPanel* panel1, TPanel* panel2,
                                       RedrawMode mode);
    virtual void draw_setup(int mode);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(tagRECT* rect);
    virtual void draw_offset(long x, long y, tagRECT* rect);
    virtual void draw_rect2(tagRECT* rect);
    virtual void draw_offset2(long x, long y, tagRECT* rect);
    virtual void paint();
    virtual long wnd_proc(void* hwnd, unsigned int message,
                          unsigned int wparam, long lparam);
    virtual long handle_idle();
    virtual long handle_size(long width, long height);
    virtual long handle_paint();
    virtual long handle_key_down(long key, short repeat, int ctrl,
                                 int shift, int alt);
    virtual long handle_char(long key, short repeat);
    virtual long handle_command(unsigned int command, long param);
    virtual long handle_user_command(unsigned int command, long param);
    virtual long handle_timer_command(unsigned int command, long param);
    virtual long handle_scroll(long scroll, long param);
    virtual long handle_mouse_down(unsigned char button, long x, long y,
                                   int ctrl, int shift);
    virtual long handle_mouse_move(long x, long y, int ctrl, int shift);
    virtual long handle_mouse_up(unsigned char button, long x, long y,
                                 int ctrl, int shift);
    virtual long handle_mouse_dbl_click(unsigned char button, long x, long y,
                                        int ctrl, int shift);
    virtual long mouse_move_action(long x, long y, int ctrl, int shift);
    virtual long mouse_left_down_action(long x, long y, int ctrl, int shift);
    virtual long mouse_left_hold_action(long x, long y, int ctrl, int shift);
    virtual long mouse_left_move_action(long x, long y, int ctrl, int shift);
    virtual long mouse_left_up_action(long x, long y, int ctrl, int shift);
    virtual long mouse_left_dbl_click_action(long x, long y, int ctrl, int shift);
    virtual long mouse_right_down_action(long x, long y, int ctrl, int shift);
    virtual long mouse_right_hold_action(long x, long y, int ctrl, int shift);
    virtual long mouse_right_move_action(long x, long y, int ctrl, int shift);
    virtual long mouse_right_up_action(long x, long y, int ctrl, int shift);
    virtual long mouse_right_dbl_click_action(long x, long y, int ctrl, int shift);
    virtual long key_down_action(long key, short repeat, int ctrl,
                                 int shift, int alt);
    virtual long char_action(long key, short repeat);
    virtual long action(TPanel* panel, long code, unsigned long p3,
                        unsigned long p4);
    virtual void get_true_render_rect(tagRECT* rect);
    virtual int is_inside(long x, long y);
    virtual void set_focus(int focus);
    virtual void set_tab_order(TPanel* first, TPanel* second);
    virtual void set_tab_order(TPanel** panels, short count);
    virtual unsigned char get_help_info(char** text, long* page, long p3,
                                        long p4);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    void delete_panel(TPanel** panel);
    void set_curr_child(TPanel* child);
    void set_help_info(long help_id, long page_id);
    int get_string(int resource_id, char* buffer, int length);
    char* get_string(int resource_id);

    TPanel* previousPanelValue;              // +0x04
    TPanel* previousModalPanelValue;         // +0x08
    long pnl_x;                               // +0x0C
    long pnl_y;                               // +0x10
    long pnl_wid;                             // +0x14
    long pnl_hgt;                             // +0x18
    char* panelNameValue;                     // +0x1C
    TDrawArea* render_area;                   // +0x20
    tagRECT clip_rect;                        // +0x24
    PositionMode position_mode;               // +0x34
    RedrawMode need_redraw;                   // +0x38
    TPanel* curr_child;                       // +0x3C
    TPanel* parent_panel;                     // +0x40
    TPanel* left_panel;                       // +0x44
    TPanel* top_panel;                        // +0x48
    TPanel* right_panel;                      // +0x4C
    TPanel* bottom_panel;                     // +0x50
    PanelNode* node;                          // +0x54
    PanelNode* first_child_node;              // +0x58
    PanelNode* last_child_node;               // +0x5C
    TPanel* tab_prev_panel;                   // +0x60
    TPanel* tab_next_panel;                   // +0x64
    int mouse_captured;                       // +0x68
    int active;                               // +0x6C
    int visible;                              // +0x70
    int tab_stop;                             // +0x74
    int have_focus;                           // +0x78
    int overlapping_children;                 // +0x7C
    int handle_mouse_input;                   // +0x80
    int just_drawn;                           // +0x84
    void* clip_rgn;                           // +0x88
    tagRECT render_rect;                      // +0x8C
    long left_border;                         // +0x9C
    long top_border;                          // +0xA0
    long right_border;                        // +0xA4
    long bottom_border;                       // +0xA8
    long min_wid;                             // +0xAC
    long max_wid;                             // +0xB0
    long min_hgt;                             // +0xB4
    long max_hgt;                             // +0xB8
    long mouse_hold_interval;                 // +0xBC
    long mouse_move_tolerance;                // +0xC0
    long mouse_down_x;                        // +0xC4
    long mouse_down_y;                        // +0xC8
    int mouse_down_ctrl;                      // +0xCC
    int mouse_down_shift;                     // +0xD0
    unsigned long mouse_down_time;            // +0xD4
    int error_code;                           // +0xD8
    int z_order;                              // +0xDC
    int display_changed_count;                // +0xE0
    long help_string_id;                      // +0xE4
    long help_page_id;                        // +0xE8
    unsigned char mouse_action;               // +0xEC
    unsigned char mouse_down_button;          // +0xED
    unsigned char panel_type;                 // +0xEE
    unsigned char color;                      // +0xEF
    unsigned char fill_in_background;         // +0xF0
    unsigned char clip_to_parent;             // +0xF1
    unsigned char draw_rect2_flag;            // +0xF2
    unsigned char need_restore;               // +0xF3
};

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
    virtual void set_text(char** texts, short count);
    virtual void set_text(int string_id);
    virtual void set_text(char* text);
    virtual void set_bevel_info(int type, int c1, int c2, int c3, int c4,
                                int c5, int c6);

    void empty_list();
    int append_line(char* text, long value);
    int append_line(char* text1, char* text2, long value);
    int append_line(long string_id, long value);
    int append_line(long string_id, long value, long extra);
    void set_second_column_pos(long position);
    void set_alignment(int vertical, int horizontal);
    void set_spacer_size(int size);
};

class TListPanel : public TTextPanel {
public:
    int auto_track;                           // +0x188
    unsigned long mouse_scroll_last_time;     // +0x18C
    unsigned long mouse_scroll_interval;       // +0x190
    int mouse_scroll_up;                       // +0x194
    int mouse_scroll_down;                     // +0x198
    int drawHighlightBar;                      // +0x19C

    void setDrawHighlightBar(int draw);
};

class TScrollBarPanel : public TPanel {
};

class TButtonPanel : public TPanel {
public:
    long id[9];                                // +0x0F4
    long id2[9];                               // +0x118
    int buttonTypeValue;                       // +0x13C
    int drawTypeValue;                         // +0x140
    int notifyTypeValue;                       // +0x144
    void* sound;                               // +0x148
    void* pic[9];                              // +0x14C
    short pic_index[9];                        // +0x170
    unsigned char pad_182[2];                  // +0x182
    int auto_pic_pos;                          // +0x184
    long pic_x;                                // +0x188
    long pic_y;                                // +0x18C
    int all_hot;                               // +0x190
    int draw_reverse;                          // +0x194
    char* text1[9];                            // +0x198
    char* text2[9];                            // +0x1BC
    long text_x;                               // +0x1E0
    long text_y;                               // +0x1E4
    void* font;                                // +0x1E8
    long font_wid;                             // +0x1EC
    long font_hgt;                             // +0x1F0
    short num_states;                           // +0x1F4
    short cur_state;                            // +0x1F6
    int is_down;                               // +0x1F8
    TButtonPanel** radio_buttons;              // +0x1FC
    short num_radio_buttons;                   // +0x200
    unsigned char pad_202[2];                  // +0x202
    unsigned long button_down_time;            // +0x204
    unsigned long text_color1[9];              // +0x208
    unsigned long text_color2[9];              // +0x22C
    unsigned long highlight_text_color1[9];    // +0x250
    unsigned long highlight_text_color2[9];    // +0x274
    long hotkey;                                // +0x298
    int hotkey_shift;                           // +0x29C
    int bevel_type;                             // +0x2A0
    unsigned char bevel_color1;                // +0x2A4
    unsigned char bevel_color2;                // +0x2A5
    unsigned char bevel_color3;                // +0x2A6
    unsigned char bevel_color4;                // +0x2A7
    unsigned char bevel_color5;                // +0x2A8
    unsigned char bevel_color6;                // +0x2A9
    unsigned char pad_2AA[2];                  // +0x2AA
    long key_down;                              // +0x2AC
    int disabled;                               // +0x2B0
    int sound_number;                           // +0x2B4
};

class TDropDownPanel : public TPanel {
public:
    TTextPanel* val_panel;                     // +0xF4
    TButtonPanel* btn_panel;                   // +0xF8
    TListPanel* list_panel;                    // +0xFC
    TScrollBarPanel* scbar_panel;              // +0x100
    int mode;                                   // +0x104
    short val_num;                              // +0x108
    unsigned char pad_10A[2];                  // +0x10A
    long val_wid;                               // +0x10C
    long val_hgt;                               // +0x110
    long btn_wid;                               // +0x114
    long btn_hgt;                               // +0x118
    long list_wid;                              // +0x11C
    long list_hgt;                              // +0x120
    long scbar_wid;                             // +0x124
    long scbar_arrow_hgt;                       // +0x128
    long scbar_tab_hgt;                         // +0x12C
    unsigned char list_is_above;                // +0x130
    unsigned char pad_131[3];                   // +0x131
    long font_hgt;                              // +0x134
    int outline_color;                          // +0x138
    int draw_style;                             // +0x13C
    int draw_val_rect;                          // +0x140

    void empty_list();
    int append_line(char* text, long value);
    int append_line(long string_id, long value);
};

class TEasy_Panel : public TPanel {
public:
    long ideal_width;                           // +0x0F4
    long ideal_height;                          // +0x0F8
    char info_file_name[260];                   // +0x0FC
    long info_id;                               // +0x200
    void* background_pic;                       // +0x204
    void* background_pic2;                      // +0x208
    void* palette;                              // +0x20C
    char cursor_file[260];                      // +0x210
    long cursor_id;                             // +0x314
    int background_pos;                         // +0x318
    int use_bevels;                             // +0x31C
    unsigned char bevel_color1;                 // +0x320
    unsigned char bevel_color2;                 // +0x321
    unsigned char bevel_color3;                 // +0x322
    unsigned char bevel_color4;                 // +0x323
    unsigned char bevel_color5;                 // +0x324
    unsigned char bevel_color6;                 // +0x325
    unsigned char pad_326[2];                   // +0x326
    unsigned long text_color1;                  // +0x328
    unsigned long text_color2;                  // +0x32C
    unsigned long focus_color1;                 // +0x330
    unsigned long focus_color2;                 // +0x334
    unsigned long state_color1;                 // +0x338
    unsigned long state_color2;                 // +0x33C
    char popup_info_file_name[260];             // +0x340
    long popup_info_id;                         // +0x444
    void* button_pics;                           // +0x448
    void* shadow_color_table;                    // +0x44C
    long shadow_amount;                          // +0x450
    unsigned char background_color1;             // +0x454
    unsigned char background_color2;             // +0x455
    unsigned char pad_456[2];                    // +0x456
    int enable_ime;                              // +0x458
    unsigned char help_mode;                     // +0x45C
    unsigned char pad_45D[3];                    // +0x45D
    int stock_brush;                             // +0x460
    void* brush;                                 // +0x464
    unsigned long brush_color;                   // +0x468
    TDrawArea* shadow_area;                      // +0x46C
    int allow_shadow_area;                       // +0x470
    int saved_mouse_mode;                       // +0x474

    long setup(TDrawArea* draw_area, TPanel* parent, char* info_file,
               long info_id, int p5, long p6, long p7, long p8, long p9,
               int p10);
    virtual void draw_background(int mode);
    virtual void set_ideal_size(long width, long height);
    virtual int create_button(TPanel* parent, TButtonPanel** out, int string_id,
                              long p4, long p5, long p6, long p7, long p8,
                              long p9, long p10, long p11);
    virtual int create_button(TPanel* parent, TButtonPanel** out, char* text1,
                              char* text2, long p5, long p6, long p7, long p8,
                              long p9, long p10, long p11);
    virtual int create_check_box(TPanel* parent, TButtonPanel** out,
                                 long p3, long p4, long p5, long p6, long p7,
                                 long p8);
    virtual int create_radio_button(TPanel* parent, TButtonPanel** out,
                                    long p3, long p4, long p5, long p6, long p7,
                                    long p8);
    virtual int create_text(TPanel* parent, TTextPanel** out, int string_id,
                            long p4, long p5, long p6, long p7, long p8,
                            int p9, int p10, int p11);
    virtual int create_text(TPanel* parent, TTextPanel** out, char** texts,
                            long p4, long p5, long p6, long p7, long p8,
                            long p9, int p10, int p11);
    virtual int create_text(TPanel* parent, TTextPanel** out, char* text,
                            long p4, long p5, long p6, long p7, long p8,
                            int p9, int p10, int p11);
    virtual int create_input(TPanel* parent, TInputPanel** out, char* text,
                             short width, FormatType format, long x, long y,
                             long w, long h, long font);
    virtual int create_edit(TPanel* parent, TEditPanel** out, char* text,
                            short width, FormatType format, long x, long y,
                            long w, long h, long font, int p11, int p12);
    virtual int create_drop_down(TPanel* parent, TDropDownPanel** out,
                                 long p3, long p4, long p5, long p6, long p7,
                                 long p8, long p9);
    virtual int create_list(TPanel* parent, TListPanel** out, long x, long y,
                            long width, long height, long lines);
    virtual int create_scrollbar(TPanel* parent, TScrollBarPanel** out,
                                 TTextPanel* text, long x, long y, long w,
                                 long h, long p8);
    virtual int create_auto_scrollbar(TScrollBarPanel** out, TTextPanel* text,
                                      long param);
    virtual int create_vert_slider(TPanel* parent, TVerticalSliderPanel** out,
                                   long x, long y, long w, long h, long p7,
                                   long p8, long p9);
    virtual int create_horz_slider(TPanel* parent,
                                   THorizontalSliderPanel** out, long x,
                                   long y, long w, long h, long p7, long p8,
                                   long p9);
    virtual void position_panel(TPanel* panel, long x, long y, long w, long h);

    void setup_shadow_area(int force_rebuild);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
};

class TPanelSystem {
public:
    TPanel* panel(char* name);
};

class RGE_Base_Game {
public:
    char gap_00[0x4C];
    TDrawArea* draw_area;                      // +0x4C

    int multiplayerGame();
    int scenarioGame();
};

extern TPanelSystem panel_system;
extern RGE_Base_Game* rge_base_game;

class TribeMPSetupScreen;

class TribeGameSettingsScreen : public TScreenPanel {
public:
    TTextPanel* title;                         // +0x478
    int state;                                  // +0x47C
    TTextPanel* mapSizeLabel;                   // +0x480
    TDropDownPanel* mapSizeDrop;                // +0x484
    TTextPanel* mapTypeLabel;                  // +0x488
    TDropDownPanel* mapTypeDrop;               // +0x48C
    TTextPanel* victoryTypeLabel;              // +0x490
    TDropDownPanel* victoryTypeDrop;           // +0x494
    TTextPanel* victoryFixedText;              // +0x498
    TTextPanel* percentLabel;                 // +0x49C
    TTextPanel* scoreLabel;                   // +0x4A0
    TDropDownPanel* scoreDrop;                // +0x4A4
    TTextPanel* timeLabel;                    // +0x4A8
    TDropDownPanel* timeDrop;                 // +0x4AC
    TTextPanel* difficultyLabel;              // +0x4B0
    TDropDownPanel* difficultyDrop;           // +0x4B4
    TTextPanel* ageLabel;                     // +0x4B8
    TDropDownPanel* ageDrop;                  // +0x4BC
    TTextPanel* resourcesLabel;               // +0x4C0
    TDropDownPanel* resourcesDrop;            // +0x4C4
    TTextPanel* pathingLabel;                 // +0x4C8
    TDropDownPanel* pathingDrop;              // +0x4CC
    TTextPanel* limitLabel;                   // +0x4D0
    TDropDownPanel* limitDrop;                // +0x4D4
    TTextPanel* scenarioTitle;                // +0x4D8
    TTextPanel* scenarioPlayersTitle;         // +0x4DC
    long scenarioListX;                       // +0x4E0
    long scenarioListY;                       // +0x4E4
    long scenarioListWidth;                   // +0x4E8
    long scenarioListHeight;                  // +0x4EC
    TListPanel* scenarioList;                 // +0x4F0
    TScrollBarPanel* scenarioScrollbar;       // +0x4F4
    int scenarioCount;                        // +0x4F8
    char** scenarioMission;                   // +0x4FC
    int* scenarioFixed;                       // +0x500
    int scenariosLoaded;                      // +0x504
    TTextPanel* missionTitle;                 // +0x508
    long missionTextX;                        // +0x50C
    long missionTextY;                        // +0x510
    long missionTextWidth;                    // +0x514
    long missionTextHeight;                   // +0x518
    TTextPanel* missionText;                  // +0x51C
    TScrollBarPanel* missionScrollbar;        // +0x520
    TButtonPanel* optionButton[4];            // +0x524
    TTextPanel* optionText[4];                // +0x534
    TButtonPanel* okButton;                   // +0x544
    TButtonPanel* cancelButton;               // +0x548
    TButtonPanel* help_button;                // +0x54C
    TribeMPSetupScreen* chat_scr;             // +0x550
    int last_scenario_line;                   // +0x554
    int scenario_line_offset;                // +0x558
    unsigned long last_send_shared;           // +0x55C

    TribeGameSettingsScreen();
    virtual ~TribeGameSettingsScreen();
    virtual long handle_idle();
    virtual long handle_user_command(unsigned int command, long param);
protected:
    virtual long action(TPanel* panel, long code, unsigned long p3,
                        unsigned long p4);

    void init_vars();
    void fillScenarios();
    void getSettings();
    void fillMissionText();
    void activatePanels();
};

TribeGameSettingsScreen::TribeGameSettingsScreen()
    : TScreenPanel((char*)0x00586808)
{
    char num_str[5];
    char* setup_file;
    int multiplayer;
    TDrawArea* draw_area;

    this->init_vars();
    this->chat_scr = (TribeMPSetupScreen*)panel_system.panel((char*)0x005861AC);

    multiplayer = rge_base_game->multiplayerGame();
    setup_file = (char*)0x00586174;
    if (multiplayer == 0)
        setup_file = (char*)0x00586138;

    draw_area = rge_base_game->draw_area;

    if (!this->setup(draw_area, 0, setup_file,
                     (rge_base_game->multiplayerGame() != 0) + 0xC384,
                     1, 0, 0, 0, 0, 1)) {
        this->error_code = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1E0);

    if (!this->create_text(this, &this->title, 0x2616,
                           0x14, 0x0A, 0x258, 0x1E, 1, 1, 0, 1))
        return;

    if (!this->create_text(this, &this->mapSizeLabel, 0x29A0,
                           0x14, 0xD8, 0xB4, 0x14, 0x0B, 0, 0, 0))
        return;

    if (!this->create_drop_down(this, &this->mapSizeDrop,
                                0xB4, 100, 0x14, 0xEC, 0xB4, 0x18, 0x0B))
        return;
    this->mapSizeDrop->empty_list();
    this->mapSizeDrop->append_line(0x2973, 0);
    this->mapSizeDrop->append_line(0x2974, 1);
    this->mapSizeDrop->append_line(0x2975, 2);
    this->mapSizeDrop->append_line(0x2976, 3);
    this->mapSizeDrop->append_line(0x2977, 4);
    this->mapSizeDrop->append_line(0x2978, 5);
    this->mapSizeDrop->set_help_info(0x762A, -1);

    if (!this->create_text(this, &this->mapTypeLabel, 0x25DB,
                           0xDC, 0xD8, 0xB4, 0x14, 0x0B, 0, 0, 0))
        return;

    if (!this->create_drop_down(this, &this->mapTypeDrop,
                                0xB4, 100, 0xDC, 0xEC, 0xB4, 0x18, 0x0B))
        return;
    this->mapTypeDrop->empty_list();
    this->mapTypeDrop->append_line(0x296A, 0);
    this->mapTypeDrop->append_line(0x296B, 1);
    this->mapTypeDrop->append_line(0x296C, 2);
    this->mapTypeDrop->append_line(0x296D, 3);
    this->mapTypeDrop->append_line(0x296E, 4);
    this->mapTypeDrop->append_line(0x296F, 5);
    this->mapTypeDrop->append_line(0x2970, 6);
    this->mapTypeDrop->append_line(0x2971, 7);
    this->mapTypeDrop->append_line(0x2972, 8);
    this->mapTypeDrop->set_help_info(0x762B, -1);

    if (!this->create_text(this, &this->victoryTypeLabel, 0x2A34,
                           0x14, 0x108, 0xB4, 0x14, 0x0B, 0, 0, 0))
        return;

    if (!this->create_drop_down(this, &this->victoryTypeDrop,
                                0xB4, 100, 0x14, 0x11C, 0xB4, 0x18, 0x0B))
        return;
    this->victoryTypeDrop->empty_list();
    if (rge_base_game->scenarioGame() != 0) {
        this->victoryTypeDrop->append_line(0x10E7, 0);
        this->victoryTypeDrop->append_line(0x10EC, 9);
    } else {
        this->victoryTypeDrop->append_line(0x10EC, 0);
    }
    this->victoryTypeDrop->append_line(0x10E1, 1);
    this->victoryTypeDrop->append_line(0x10E9, 7);
    this->victoryTypeDrop->append_line(0x10EA, 8);
    this->victoryTypeDrop->set_help_info(0x762C, 0x25F0A);

    if (!this->create_text(this, &this->timeLabel, 0x10E9,
                           0x14, 0x138, 0xB4, 0x14, 0x0B, 0, 0, 0))
        return;

    if (!this->create_drop_down(this, &this->timeDrop,
                                0xB4, 100, 0x14, 0x14C, 0xB4, 0x18, 0x0B))
        return;
    this->timeDrop->empty_list();
    this->timeDrop->append_line(0x2634, 15000);
    this->timeDrop->append_line(0x2635, 13000);
    this->timeDrop->append_line(0x2636, 11000);
    this->timeDrop->append_line(0x2637, 9000);
    this->timeDrop->append_line(0x2638, 7000);
    this->timeDrop->append_line(0x2639, 5000);
    this->timeDrop->append_line(0x263A, 3000);
    this->timeDrop->set_help_info(0x763B, -1);

    if (!this->create_text(this, &this->scoreLabel, 0x10EA,
                           0x14, 0x138, 0xB4, 0x14, 0x0B, 0, 0, 0))
        return;

    if (!this->create_drop_down(this, &this->scoreDrop,
                                0xB4, 100, 0x14, 0x14C, 0xB4, 0x18, 0x0B))
        return;
    this->scoreDrop->empty_list();
    this->scoreDrop->append_line((char*)0x00586DA4, 3000);
    this->scoreDrop->append_line((char*)0x00586D9C, 2700);
    this->scoreDrop->append_line((char*)0x00586D94, 0x960);
    this->scoreDrop->append_line((char*)0x00586D8C, 0x834);
    this->scoreDrop->append_line((char*)0x00586D84, 0x708);
    this->scoreDrop->append_line((char*)0x00586D7C, 0x5DC);
    this->scoreDrop->append_line((char*)0x00586D74, 0x4B0);
    this->scoreDrop->append_line((char*)0x00586D70, 900);
    this->scoreDrop->append_line((char*)0x005800F8, 800);
    this->scoreDrop->append_line((char*)0x00586D6C, 700);
    this->scoreDrop->append_line((char*)0x00586D68, 600);
    this->scoreDrop->append_line((char*)0x00586D64, 500);
    this->scoreDrop->append_line((char*)0x00586D60, 400);
    this->scoreDrop->append_line((char*)0x00586D5C, 300);
    this->scoreDrop->set_help_info(0x763C, -1);

    if (!this->create_text(this, &this->victoryFixedText, 0x25D9,
                           0x14, 0x108, 0xB4, 0x5C, 0x0B, 1, 1, 1))
        return;
    this->victoryFixedText->set_bevel_info(3, this->bevel_color1,
                                           this->bevel_color2,
                                           this->bevel_color3,
                                           this->bevel_color4,
                                           this->bevel_color5,
                                           this->bevel_color6);

    if (!this->create_text(this, &this->ageLabel, 0x2606,
                           0xDC, 0x108, 0xB4, 0x14, 0x0B, 0, 0, 0))
        return;

    if (!this->create_drop_down(this, &this->ageDrop,
                                0xB4, 100, 0xDC, 0x11C, 0xB4, 0x18, 0x0B))
        return;
    this->ageDrop->empty_list();
    this->ageDrop->append_line(0x10E7, 0);
    this->ageDrop->append_line(0x106E, 1);
    this->ageDrop->append_line(0x1069, 2);
    this->ageDrop->append_line(0x106A, 3);
    this->ageDrop->append_line(0x106B, 4);
    this->ageDrop->append_line(0x106C, 5);
    this->ageDrop->set_help_info(0x7631, -1);

    if (!this->create_text(this, &this->resourcesLabel, 0x2607,
                           0xDC, 0x138, 0xB4, 0x14, 0x0B, 0, 0, 0))
        return;

    if (!this->create_drop_down(this, &this->resourcesDrop,
                                0xB4, 100, 0xDC, 0x14C, 0xB4, 0x18, 0x0B))
        return;
    this->resourcesDrop->empty_list();
    this->resourcesDrop->append_line(0x10E7, 0);
    this->resourcesDrop->append_line(0x2609, 2);
    this->resourcesDrop->append_line(0x260A, 3);
    this->resourcesDrop->set_help_info(0x7632, -1);

    if (!this->create_text(this, &this->pathingLabel, 0x260D,
                           0x1A4, 0x138, 0xB4, 0x14, 0x0B, 0, 0, 0))
        return;

    if (!this->create_drop_down(this, &this->pathingDrop,
                                0xB4, 100, 0x1A4, 0x14C, 0xB4, 0x18, 0x0B))
        return;
    this->pathingDrop->empty_list();
    this->pathingDrop->append_line(0x260E, 0);
    this->pathingDrop->append_line(0x260F, 1);
    this->pathingDrop->append_line(0x2610, 2);
    this->pathingDrop->set_help_info(0x763E, -1);

    if (rge_base_game->multiplayerGame() != 0) {
        if (!this->create_text(this, &this->limitLabel, 0x2613,
                               0x1A4, 0xD8, 0xB4, 0x14, 0x0B, 0, 0, 0))
            return;
        if (!this->create_drop_down(this, &this->limitDrop,
                                    0xB4, 100, 0x1A4, 0xEC, 0xB4, 0x18,
                                    0x0B))
            return;
        this->limitDrop->empty_list();
        for (int limit = 25; limit <= 0xC8; limit += 25) {
            sprintf(num_str, (char*)0x00584610, limit);
            this->limitDrop->append_line(num_str, limit);
        }
        this->limitDrop->set_help_info(0x763F, -1);
    }

    if (!this->create_text(this, &this->difficultyLabel, 0x2BCF,
                           0x1A4, 0x108, 0xB4, 0x14, 0x0B, 0, 0, 0))
        return;

    if (!this->create_drop_down(this, &this->difficultyDrop,
                                0xB4, 100, 0x1A4, 0x11C, 0xB4, 0x18,
                                0x0B))
        return;
    this->difficultyDrop->empty_list();
    this->difficultyDrop->append_line(0x2BD4, 4);
    this->difficultyDrop->append_line(0x2BD3, 3);
    this->difficultyDrop->append_line(0x2BD2, 2);
    this->difficultyDrop->append_line(0x2BD1, 1);
    this->difficultyDrop->append_line(0x2BD0, 0);
    this->difficultyDrop->set_help_info(0x763D, -1);

    if (!this->create_check_box(this, &this->optionButton[0],
                                10, 0x168, 0x1E, 0x1E, 0, 0))
        return;
    if (!this->create_text(this, &this->optionText[0], 0x2601,
                           0x28, 0x168, 0xAA, 0x1E, 0x0B, 0, 1, 0))
        return;
    this->optionButton[0]->set_help_info(0x7633, -1);

    if (!this->create_check_box(this, &this->optionButton[2],
                                0xDC, 0x168, 0x1E, 0x1E, 0, 0))
        return;
    if (!this->create_text(this, &this->optionText[2], 0x2604,
                           0xFA, 0x168, 0xAA, 0x1E, 0x0B, 0, 1, 0))
        return;
    this->optionButton[2]->set_help_info(0x7637, -1);

    if (!this->create_check_box(this, &this->optionButton[1],
                                0x1AE, 0x168, 0x1E, 0x1E, 0, 0))
        return;
    if (!this->create_text(this, &this->optionText[1], 0x25FC,
                           0x1CC, 0x168, 0xAA, 0x1E, 0x0B, 0, 1, 0))
        return;
    this->optionButton[1]->set_help_info(0x7634, -1);

    if (rge_base_game->multiplayerGame() != 0) {
        if (!this->create_check_box(this, &this->optionButton[3],
                                    0x1AE, 0x18B, 0x1E, 0x1E, 0, 0))
            return;
        if (!this->create_text(this, &this->optionText[3], 0x25FB,
                               0x1CC, 0x18B, 0xA5, 0x1E, 0x0B, 0, 1, 0))
            return;
        this->optionButton[3]->set_help_info(0x7638, -1);
    }

    this->scenarioListX = 0x14;
    this->scenarioListY = 0x3C;
    this->scenarioListWidth = 600;
    if (rge_base_game->multiplayerGame() != 0)
        this->scenarioListHeight = 0x6F;
    else
        this->scenarioListHeight = 0x18;

    if (!this->create_list(this, &this->scenarioList,
                           this->scenarioListX, this->scenarioListY,
                           this->scenarioListWidth, this->scenarioListHeight,
                           0x0B))
        return;

    long second_column_pos;
    second_column_pos = this->scenarioListWidth;
    second_column_pos -= 0x3C;
    second_column_pos *= this->pnl_wid;
    second_column_pos /= this->ideal_width;
    this->scenarioList->set_second_column_pos(second_column_pos);

    if (rge_base_game->multiplayerGame() != 0) {
        this->scenarioList->set_text(0x25FD);
        this->scenarioList->set_help_info(0x7639, -1);
        if (!this->create_auto_scrollbar(&this->scenarioScrollbar,
                                         this->scenarioList, 0x14))
            return;
    } else {
        this->scenarioList->handle_mouse_input = 0;
        this->scenarioList->setDrawHighlightBar(0);
        this->scenarioList->set_spacer_size(0);
    }

    if (!this->create_text(this, &this->scenarioTitle,
                           rge_base_game->multiplayerGame() ? 0x25FE : 0x2620,
                           this->scenarioListX,
                           this->scenarioListY - 0x14,
                           300, 0x14, 4, 0, 0, 0))
        return;

    if (!this->create_text(this, &this->scenarioPlayersTitle, 0x25FF,
                           this->scenarioListWidth - 0xDC + this->scenarioListX,
                           this->scenarioListY - 0x14,
                           0xDC, 0x14, 4, 0, 0, 0))
        return;
    this->scenarioPlayersTitle->set_alignment(3, 2);

    this->missionTextY = this->scenarioListHeight + this->scenarioListY + 0x18;
    this->missionTextWidth = this->scenarioListWidth;
    this->missionTextX = this->scenarioListX;
    this->missionTextHeight = 0x104 - this->missionTextY;

    if (!this->create_text(this, &this->missionTitle, 0x2600,
                           this->missionTextX, this->missionTextY - 0x14,
                           300, 0x14, 4, 0, 0, 0))
        return;

    if (!this->create_text(this, &this->missionText, (char*)0x00592A40,
                           this->missionTextX, this->missionTextY,
                           this->missionTextWidth, this->missionTextHeight,
                           0x0B, 0, 0, 1))
        return;
    this->missionText->set_bevel_info(3, this->bevel_color1,
                                      this->bevel_color2,
                                      this->bevel_color3,
                                      this->bevel_color4,
                                      this->bevel_color5,
                                      this->bevel_color6);

    if (!this->create_auto_scrollbar(&this->missionScrollbar,
                                     this->missionText, 0x14))
        return;
    this->missionScrollbar->set_help_info(0x763A, -1);

    if (!this->create_button(this, &this->okButton, 0xFA1,
                             0, 0x3C, 0x1B8, 0xF0, 0x1E, 0, 0, 0))
        return;
    this->okButton->set_help_info(0x7531, -1);

    if (!this->create_button(this, &this->cancelButton, 0xFA2,
                             0, 0x140, 0x1B8, 0xF0, 0x1E, 0, 0, 0))
        return;
    TButtonPanel* cancel_button = this->cancelButton;
    cancel_button->hotkey = 0x1B;
    cancel_button->hotkey_shift = 0;
    this->cancelButton->set_help_info(0x7532, -1);

    if (!this->create_button(this, &this->help_button, 0xFA9,
                             0, 0x244, 0x1B8, 0x1E, 0x1E, 0, 0, 0))
        return;

    this->fillScenarios();
    this->scenariosLoaded = 1;
    this->getSettings();
    this->fillMissionText();
    this->activatePanels();
    this->set_curr_child(this->okButton);
}
