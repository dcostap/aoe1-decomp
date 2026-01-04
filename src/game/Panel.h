#pragma once
#include "../common.h"
#include "Drawarea.h"
#include "Panel.h"

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

    virtual long mouse_move_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_move_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_down_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_move_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_up_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4);
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5);
    virtual long char_action(long param_1, short param_2);
    virtual void take_snapshot();
    TPanel(char* param_1);
    TPanel();
    virtual ~TPanel();
    virtual long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7);
    virtual void add_panel_node(PanelNode* param_1, PanelNode* param_2, int param_3);
    virtual void remove_panel_node(PanelNode* param_1);
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4);
    virtual void set_rect(tagRECT param_1);
    virtual void set_color(uchar param_1);
    virtual void set_active(int param_1);
    virtual void set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13);
    virtual void set_fixed_position(long param_1, long param_2, long param_3, long param_4);
    virtual void set_redraw(RedrawMode param_1);
    virtual void set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3);
    virtual void set_any_overlapping_redraw(TPanel* param_1, RedrawMode param_2);
    virtual void draw();
    virtual void draw_rect(tagRECT* param_1);
    virtual void draw_offset(long param_1, long param_2, tagRECT* param_3);
    virtual void draw_rect2(tagRECT* param_1);
    virtual void draw_offset2(long param_1, long param_2, tagRECT* param_3);
    virtual void draw_setup(int param_1);
    virtual void draw_finish();
    virtual void paint();
    virtual long wnd_proc(void* param_1, uint param_2, uint param_3, long param_4);
    virtual long handle_idle();
    virtual long handle_size(long param_1, long param_2);
    virtual long handle_paint();
    virtual long handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5);
    virtual long handle_char(long param_1, short param_2);
    virtual long handle_command(uint param_1, long param_2);
    virtual long handle_user_command(uint param_1, long param_2);
    virtual long handle_timer_command(uint param_1, long param_2);
    virtual long handle_scroll(long param_1, long param_2);
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5);
    virtual long handle_mouse_move(long param_1, long param_2, int param_3, int param_4);
    virtual long handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5);
    virtual long handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5);
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
    virtual void get_mouse_info(uint param_1, long param_2, tagPOINT* param_3, int* param_4, int* param_5);
    virtual void get_mouse_pos(tagPOINT* param_1);
    virtual int capture_mouse();
    virtual void release_mouse();
    virtual uchar is_redraw_needed();
    virtual int is_inside(long param_1, long param_2);
    virtual int is_inside_rect(long param_1, long param_2, tagRECT* param_3);
    virtual int bound_point(long* param_1, long* param_2);
    virtual void set_curr_child(TPanel* param_1);
    virtual void set_focus(int param_1);
    virtual int get_focus();
    virtual void set_z_order(uchar param_1, short param_2);
    virtual void set_child_z_order(TPanel* param_1, uchar param_2, short param_3);
    virtual void set_tab_order(TPanel** param_1, short param_2);
    virtual void set_tab_order(TPanel* param_1, TPanel* param_2);
    virtual TPanel* previousPanel();
    virtual void setPreviousPanel(TPanel* param_1);
    virtual TPanel* previousModalPanel();
    virtual void setPreviousModalPanel(TPanel* param_1);
    virtual char* panelName();
    virtual void setPanelName(char* param_1);
    virtual long xPosition();
    virtual long yPosition();
    virtual long width();
    virtual long height();
    virtual TDrawArea* renderArea();
    virtual tagRECT* clipRectangle(tagRECT* __return_storage_ptr__);
    virtual void setClipRectangle(tagRECT param_1);
    virtual void delete_panel(TPanel** param_1);
    virtual int get_string(int param_1, char* param_2, int param_3);
    virtual char* get_string(int param_1);
    virtual long get_help_message();
    virtual long get_help_page();
    virtual void set_help_info(long param_1, long param_2);
    virtual uchar get_help_info(char** param_1, long* param_2, long param_3, long param_4);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void handle_reactivate();
    virtual void get_true_render_rect(tagRECT* param_1);
};

static_assert(sizeof(TPanel) == 0xF4, "TPanel Size Mismatch");
static_assert(offsetof(TPanel, need_restore) == 0xF3, "TPanel Offset Mismatch");

class TPanelSystem {
public:
    TPanel* keyboardOwnerValue;              // 0x4
    TPanel* modalPanelValue;                 // 0x8
    TPanel* currentPanelValue;               // 0xC
    PanelNode* panelListValue;               // 0x10
    int numberActivePanelsValue;             // 0x14
    TPanel* prevCurrentChildValue;           // 0x18
    void* palette[10];                       // 0x1C
    char palette_file[10][260];                  // 0x44
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
    virtual ~TPanelSystem();
    virtual TPanel* currentPanel();
    virtual TPanel* previousPanel();
    virtual TPanel* mouseOwner();
    virtual TPanel* keyboardOwner();
    virtual TPanel* modalPanel();
    virtual TPanel* panel(char* param_1);
    virtual int numberActivePanels();
    virtual int addPanel(TPanel* param_1, int param_2, int param_3);
    virtual int removePanel(char* param_1);
    virtual int setCurrentPanel(char* param_1, int param_2);
    virtual int restorePreviousPanel(int param_1);
    virtual void setMouseOwner(TPanel* param_1);
    virtual void setKeyboardOwner(TPanel* param_1);
    virtual void setModalPanel(TPanel* param_1);
    virtual void setCurrentPanelModal();
    virtual int restorePreviousModalPanel();
    virtual int destroyPanel(char* param_1);
    virtual int inSystem(char* param_1);
    virtual int inSystem(TPanel* param_1);
    virtual int setup();
    virtual PanelNode* findPanelNode(char* param_1);
    virtual void setCurrentPanel(TPanel* param_1, int param_2);
    virtual void* get_palette(char* param_1, long param_2);
    virtual void release_palette(void* param_1);
    virtual void DisableIME();
    virtual void EnableIME();
    virtual int IsIMEEnabled();
    virtual void TurnIMEOn();
    virtual void TurnIMEOff();
    virtual int IsIMEOn();
    virtual int GetInputEnabled();
    virtual void EnableInput();
    virtual void DisableInput();
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void restore_system_colors();
    virtual void set_restore();
};

static_assert(sizeof(TPanelSystem) == 0xAD8, "TPanelSystem Size Mismatch");
static_assert(offsetof(TPanelSystem, save_text_color) == 0xAD4, "TPanelSystem Offset Mismatch");

