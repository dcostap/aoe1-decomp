#pragma once
#include "common.h"

// ----------------------------------------------------------------
// PanelNode
// Size: 0xC
struct PanelNode {
    TPanel * panel; // 0x0
    PanelNode * prev_node; // 0x4
    PanelNode * next_node; // 0x8
};

enum MouseAction : unsigned int {
    MouseActionNone = 0,
    MouseActionDown = 1,
    MouseActionHold = 2,
    MouseActionMove = 3,
};

enum MouseButton : unsigned int {
    MouseButtonNone = 0,
    LeftMouseButton = 1,
    RightMouseButton = 2,
};

enum PositionMode : unsigned int {
    PositionFixed = 0,
    PositionVariable = 1,
    PositionCentered = 2,
    PositionLeft = 3,
    PositionTop = 4,
    PositionRight = 5,
    PositionBottom = 6,
    PositionLeftTop = 7,
    PositionLeftBottom = 8,
    PositionRightTop = 9,
    PositionRightBottom = 10,
};

enum RedrawMode : unsigned int {
    RedrawNone = 0,
    RedrawNormal = 1,
    RedrawFull = 2,
};

enum ZOrder : unsigned int {
    ZOrderPosition = 0,
    ZOrderTop = 1,
    ZOrderBottom = 2,
};

class TPanel {
public:
    // [omitted] vfptr @ 0x0 ('_padding_')
    TPanel* previousPanelValue;              // 0x4
    TPanel* previousModalPanelValue;         // 0x8
    long pnl_x;                              // 0xC
    long pnl_y;                              // 0x10
    long pnl_wid;                            // 0x14
    long pnl_hgt;                            // 0x18
    char* panelNameValue;                    // 0x1C
    TDrawArea* render_area;                  // 0x20
    tagRECT clip_rect;                       // 0x24
    PositionMode position_mode;              // 0x34
    RedrawMode need_redraw;                  // 0x38
    TPanel* curr_child;                      // 0x3C
    TPanel* parent_panel;                    // 0x40
    TPanel* left_panel;                      // 0x44
    TPanel* top_panel;                       // 0x48
    TPanel* right_panel;                     // 0x4C
    TPanel* bottom_panel;                    // 0x50
    PanelNode* node;                         // 0x54
    PanelNode* first_child_node;             // 0x58
    PanelNode* last_child_node;              // 0x5C
    TPanel* tab_prev_panel;                  // 0x60
    TPanel* tab_next_panel;                  // 0x64
    int mouse_captured;                      // 0x68
    int active;                              // 0x6C
    int visible;                             // 0x70
    int tab_stop;                            // 0x74
    int have_focus;                          // 0x78
    int overlapping_children;                // 0x7C
    int handle_mouse_input;                  // 0x80
    int just_drawn;                          // 0x84
    void* clip_rgn;                          // 0x88
    tagRECT render_rect;                     // 0x8C
    long left_border;                        // 0x9C
    long top_border;                         // 0xA0
    long right_border;                       // 0xA4
    long bottom_border;                      // 0xA8
    long min_wid;                            // 0xAC
    long max_wid;                            // 0xB0
    long min_hgt;                            // 0xB4
    long max_hgt;                            // 0xB8
    long mouse_hold_interval;                // 0xBC
    long mouse_move_tolerance;               // 0xC0
    long mouse_down_x;                       // 0xC4
    long mouse_down_y;                       // 0xC8
    int mouse_down_ctrl;                     // 0xCC
    int mouse_down_shift;                    // 0xD0
    ulong mouse_down_time;                   // 0xD4
    int error_code;                          // 0xD8
    int z_order;                             // 0xDC
    int display_changed_count;               // 0xE0
    long help_string_id;                     // 0xE4
    long help_page_id;                       // 0xE8
    uchar mouse_action;                      // 0xEC
    uchar mouse_down_button;                 // 0xED
    uchar panel_type;                        // 0xEE
    uchar color;                             // 0xEF
    uchar fill_in_background;                // 0xF0
    uchar clip_to_parent;                    // 0xF1
    uchar draw_rect2_flag;                   // 0xF2
    uchar need_restore;                      // 0xF3

    virtual long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7); // vt0[1]+0x4=0x464A80 | vt0[57]+0xE4=0x464A80
    virtual void set_rect(tagRECT param_1);                 // vt0[2]+0x8=0x464D70 | vt0[58]+0xE8=0x464D70
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4); // vt0[3]+0xC=0x464C50 | vt0[59]+0xEC=0x464C50
    virtual void set_color(uchar param_1);                  // vt0[4]+0x10=0x464DA0 | vt0[60]+0xF0=0x464DA0
    virtual void set_active(int param_1);                   // vt0[5]+0x14=0x464DC0 | vt0[61]+0xF4=0x464DC0
    virtual void set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13); // vt0[6]+0x18=0x464E00 | vt0[62]+0xF8=0x464E00
    virtual void set_fixed_position(long param_1, long param_2, long param_3, long param_4); // vt0[7]+0x1C=0x464EB0 | vt0[63]+0xFC=0x464EB0
    virtual void set_redraw(RedrawMode param_1);            // vt0[8]+0x20=0x464EE0 | vt0[64]+0x100=0x464EE0
    virtual void set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3); // vt0[9]+0x24=0x464F20 | vt0[65]+0x104=0x464F20
    virtual void draw_setup(int param_1);                   // vt0[10]+0x28=0x465320
    virtual void draw_finish();                             // vt0[11]+0x2C=0x465370 | vt0[67]+0x10C=0x465370
    virtual void draw();                                    // vt0[12]+0x30=0x465160
    virtual void draw_rect(tagRECT* param_1);               // vt0[13]+0x34=0x4651C0 | vt0[69]+0x114=0x4651C0
    virtual void draw_offset(long param_1, long param_2, tagRECT* param_3); // vt0[14]+0x38=0x465220 | vt0[70]+0x118=0x465220
    virtual void draw_rect2(tagRECT* param_1);              // vt0[15]+0x3C=0x4652C0 | vt0[71]+0x11C=0x4652C0
    virtual void draw_offset2(long param_1, long param_2, tagRECT* param_3); // vt0[16]+0x40=0x4652F0 | vt0[72]+0x120=0x4652F0
    virtual void paint();                                   // vt0[17]+0x44=0x4653A0 | vt0[73]+0x124=0x4653A0
    virtual long wnd_proc(void* param_1, uint param_2, uint param_3, long param_4); // vt0[18]+0x48=0x4653E0 | vt0[74]+0x128=0x4653E0
    virtual long handle_idle();                             // vt0[19]+0x4C=0x465780 | vt0[75]+0x12C=0x465780
    virtual long handle_size(long param_1, long param_2);   // vt0[20]+0x50=0x465820 | vt0[76]+0x130=0x465820
    virtual long handle_paint();                            // vt0[21]+0x54=0x465A70 | vt0[77]+0x134=0x465A70
    virtual long handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5); // vt0[22]+0x58=0x465B30 | vt0[78]+0x138=0x465B30
    virtual long handle_char(long param_1, short param_2);  // vt0[23]+0x5C=0x465BE0 | vt0[79]+0x13C=0x465BE0
    virtual long handle_command(uint param_1, long param_2); // vt0[24]+0x60=0x465C30 | vt0[80]+0x140=0x465C30
    virtual long handle_user_command(uint param_1, long param_2); // vt0[25]+0x64=0x465C40 | vt0[81]+0x144=0x465C40
    virtual long handle_timer_command(uint param_1, long param_2); // vt0[26]+0x68=0x465C50 | vt0[82]+0x148=0x465C50
    virtual long handle_scroll(long param_1, long param_2); // vt0[27]+0x6C=0x465C60 | vt0[83]+0x14C=0x465C60
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5); // vt0[28]+0x70=0x465C70
    virtual long handle_mouse_move(long param_1, long param_2, int param_3, int param_4); // vt0[29]+0x74=0x465DC0 | vt0[85]+0x154=0x465DC0
    virtual long handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5); // vt0[30]+0x78=0x465F70 | vt0[86]+0x158=0x465F70
    virtual long handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5); // vt0[31]+0x7C=0x466060 | vt0[87]+0x15C=0x466060
    virtual long mouse_move_action(long param_1, long param_2, int param_3, int param_4); // vt0[32]+0x80=0x437110 | vt0[88]+0x160=0x437110
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4); // vt0[33]+0x84=0x437230 | vt0[89]+0x164=0x437230
    virtual long mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4); // vt0[34]+0x88=0x437240 | vt0[90]+0x168=0x437240
    virtual long mouse_left_move_action(long param_1, long param_2, int param_3, int param_4); // vt0[35]+0x8C=0x437250 | vt0[91]+0x16C=0x437250
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4); // vt0[36]+0x90=0x437260 | vt0[92]+0x170=0x437260
    virtual long mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4); // vt0[37]+0x94=0x437270 | vt0[93]+0x174=0x437270
    virtual long mouse_right_down_action(long param_1, long param_2, int param_3, int param_4); // vt0[38]+0x98=0x437280 | vt0[94]+0x178=0x437280
    virtual long mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4); // vt0[39]+0x9C=0x437290 | vt0[95]+0x17C=0x437290
    virtual long mouse_right_move_action(long param_1, long param_2, int param_3, int param_4); // vt0[40]+0xA0=0x4372A0 | vt0[96]+0x180=0x4372A0
    virtual long mouse_right_up_action(long param_1, long param_2, int param_3, int param_4); // vt0[41]+0xA4=0x4372B0 | vt0[97]+0x184=0x4372B0
    virtual long mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4); // vt0[42]+0xA8=0x437490 | vt0[98]+0x188=0x437490
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5); // vt0[43]+0xAC=0x4374A0 | vt0[99]+0x18C=0x4374A0
    virtual long char_action(long param_1, short param_2);  // vt0[44]+0xB0=0x4374B0 | vt0[100]+0x190=0x4374B0
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt0[45]+0xB4=0x466140
    virtual void get_true_render_rect(tagRECT* param_1);    // vt0[46]+0xB8=0x4669F0 | vt0[102]+0x198=0x4669F0
    virtual int is_inside(long param_1, long param_2);      // vt0[47]+0xBC=0x4662E0 | vt0[103]+0x19C=0x4662E0
    virtual void set_focus(int param_1);                    // vt0[48]+0xC0=0x4663F0
    virtual void set_tab_order(TPanel* param_1, TPanel* param_2); // vt0[49]+0xC4=0x466650 | vt0[105]+0x1A4=0x466650
    virtual void set_tab_order(TPanel** param_1, short param_2); // vt0[50]+0xC8=0x466600 | vt0[106]+0x1A8=0x466600
    virtual uchar get_help_info(char** param_1, long* param_2, long param_3, long param_4); // vt0[51]+0xCC=0x4668D0 | vt0[107]+0x1AC=0x4668D0
    virtual void stop_sound_system();                       // vt0[52]+0xD0=0x466980 | vt0[108]+0x1B0=0x466980
    virtual int restart_sound_system();                     // vt0[53]+0xD4=0x4669A0 | vt0[109]+0x1B4=0x4669A0
    virtual void take_snapshot();                           // vt0[54]+0xD8=0x437610 | vt0[110]+0x1B8=0x437610
    virtual void handle_reactivate();                       // vt0[55]+0xDC=0x4669D0 | vt0[111]+0x1BC=0x4669D0
    TPanel(char* param_1);
    TPanel();
    ~TPanel();
    void add_panel_node(PanelNode* param_1, PanelNode* param_2, int param_3);
    void remove_panel_node(PanelNode* param_1);
    void set_any_overlapping_redraw(TPanel* param_1, RedrawMode param_2);
    void get_mouse_info(uint param_1, long param_2, tagPOINT* param_3, int* param_4, int* param_5);
    void get_mouse_pos(tagPOINT* param_1);
    int capture_mouse();
    void release_mouse();
    uchar is_redraw_needed();
    int is_inside_rect(long param_1, long param_2, tagRECT* param_3);
    int bound_point(long* param_1, long* param_2);
    void set_curr_child(TPanel* param_1);
    int get_focus();
    void set_z_order(uchar param_1, short param_2);
    void set_child_z_order(TPanel* param_1, uchar param_2, short param_3);
    TPanel* previousPanel();
    void setPreviousPanel(TPanel* param_1);
    TPanel* previousModalPanel();
    void setPreviousModalPanel(TPanel* param_1);
    char* panelName();
    void setPanelName(char* param_1);
    long xPosition();
    long yPosition();
    long width();
    long height();
    TDrawArea* renderArea();
    tagRECT* clipRectangle();
    void setClipRectangle(tagRECT param_1);
    void delete_panel(TPanel** param_1);
    int get_string(int param_1, char* param_2, int param_3);
    char* get_string(int param_1);
    long get_help_message();
    long get_help_page();
    void set_help_info(long param_1, long param_2);
};

static_assert(sizeof(TPanel) == 0xF4, "TPanel Size Mismatch");

class TPanelSystem {
public:
    TPanel* mouseOwnerValue;                 // 0x0
    TPanel* keyboardOwnerValue;              // 0x4
    TPanel* modalPanelValue;                 // 0x8
    TPanel* currentPanelValue;               // 0xC
    PanelNode* panelListValue;               // 0x10
    int numberActivePanelsValue;             // 0x14
    TPanel* prevCurrentChildValue;           // 0x18
    void* palette[10];                       // 0x1C
    char* palette_file[10];                  // 0x44
    int palette_use_count[10];               // 0xA6C
    long palette_id[10];                     // 0xA94
    ulong Imc;                               // 0xABC
    int ImeEnabled;                          // 0xAC0
    int ImeOn;                               // 0xAC4
    int InputEnabled;                        // 0xAC8
    int saved_colors;                        // 0xACC
    ulong save_back_color;                   // 0xAD0
    ulong save_text_color;                   // 0xAD4

    TPanelSystem();
    ~TPanelSystem();
    TPanel* currentPanel();
    TPanel* previousPanel();
    TPanel* mouseOwner();
    TPanel* keyboardOwner();
    TPanel* modalPanel();
    TPanel* panel(char* param_1);
    int numberActivePanels();
    int addPanel(TPanel* param_1, int param_2, int param_3);
    int removePanel(char* param_1);
    int setCurrentPanel(char* param_1, int param_2);
    int restorePreviousPanel(int param_1);
    void setMouseOwner(TPanel* param_1);
    void setKeyboardOwner(TPanel* param_1);
    void setModalPanel(TPanel* param_1);
    void setCurrentPanelModal();
    int restorePreviousModalPanel();
    int destroyPanel(char* param_1);
    int inSystem(char* param_1);
    int inSystem(TPanel* param_1);
    int setup();
    PanelNode* findPanelNode(char* param_1);
    void setCurrentPanel(TPanel* param_1, int param_2);
    void* get_palette(char* param_1, long param_2);
    void release_palette(void* param_1);
    void DisableIME();
    void EnableIME();
    int IsIMEEnabled();
    void TurnIMEOn();
    void TurnIMEOff();
    int IsIMEOn();
    int GetInputEnabled();
    void EnableInput();
    void DisableInput();
    void stop_sound_system();
    int restart_sound_system();
    void restore_system_colors();
    void set_restore();
};

static_assert(sizeof(TPanelSystem) == 0xAD8, "TPanelSystem Size Mismatch");

