#ifndef UI_CORE_H
#define UI_CORE_H

#include "common.h"

// Basic types for UI (usually from common.h)
typedef unsigned char  uchar;
typedef unsigned short ushort;
typedef unsigned int   uint;
typedef unsigned long  ulong;

// --- Forward Declarations ---
struct TDrawArea;
class TShape;
struct TDigital;
class TPanel;
struct PanelNode;
struct TPanelSystem;

// --- PanelNode ---
struct PanelNode {
    TPanel* panel;
    PanelNode* prev_node;
    PanelNode* next_node;
};

// --- TPanel ---
class TPanel {
public:
    enum PositionMode : int { Fixed = 0, Relative = 1, Center = 2 };
    // Source of truth: `src/game/src/panel.cpp.asm` / `.decomp` (immutable reference).
    // NOTE: The original has at least three redraw levels (none/normal/full).
    enum RedrawMode : int { NoRedraw = 0, Redraw = 1, RedrawFull = 2 };

    TPanel(char* name = nullptr);
    virtual ~TPanel();
    virtual long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7);
    virtual void set_rect(tagRECT param_1);
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4);
    virtual void set_color(uchar param_1);
    virtual void set_active(int param_1);
    virtual void set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10 = nullptr, TPanel* param_11 = nullptr, TPanel* param_12 = nullptr, TPanel* param_13 = nullptr);
    virtual void set_fixed_position(long param_1, long param_2, long param_3, long param_4);
    virtual void set_redraw(RedrawMode param_1);
    virtual void set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3);
    virtual void draw_setup(int param_1);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(tagRECT* param_1);
    virtual void draw_offset(long param_1, long param_2, tagRECT* param_3);
    virtual void draw_rect2(tagRECT* param_1);
    virtual void draw_offset2(long param_1, long param_2, tagRECT* param_3);
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
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
    virtual void get_true_render_rect(tagRECT* param_1);
    virtual int is_inside(long param_1, long param_2);
    virtual void set_focus(int param_1);
    virtual void set_tab_order(TPanel* param_1, TPanel* param_2);
    virtual void set_tab_order(TPanel** param_1, short param_2);
    virtual uchar get_help_info(char** param_1, long* param_2, long param_3, long param_4);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();
    
    void delete_panel(TPanel** panel);
    void set_curr_child(TPanel* child);
    void set_help_info(long help_id, long page_id);
    void set_z_order(char param_1, int param_2);
    int capture_mouse();
    void release_mouse();
    int bound_point(long* param_1, long* param_2);
     
    int get_string(int resid, char* buffer, int len);
    char* get_string(int resid);
    char* panelName() const;

    long xPosition() const;
    long yPosition() const;
    long width() const;
    long height() const;

    // Non-virtual helper: draw this panel and all children.
    // NOTE: This is not an original method; it exists to let our simplified game loop render the UI
    // tree while keeping the original semantics of `TPanel::draw()` (panel-only, no child recursion).
    void draw_tree();

    TPanel* previousPanelValue;
    TPanel* previousModalPanelValue;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panelNameValue;
    TDrawArea* render_area;
    tagRECT clip_rect;
    PositionMode position_mode;
    RedrawMode need_redraw;
    TPanel* curr_child;
    TPanel* parent_panel;
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    PanelNode* node;
    PanelNode* first_child_node;
    PanelNode* last_child_node;
    TPanel* tab_prev_panel;
    TPanel* tab_next_panel;
    int mouse_captured;
    int active;
    int visible;
    int tab_stop;
    int have_focus;
    int overlapping_children;
    int handle_mouse_input;
    int just_drawn;
    void* clip_rgn;
    tagRECT render_rect;
    long left_border;
    long top_border;
    long right_border;
    long bottom_border;
    long min_wid;
    long max_wid;
    long min_hgt;
    long max_hgt;
    long mouse_hold_interval;
    long mouse_move_tolerance;
    long mouse_down_x;
    long mouse_down_y;
    int mouse_down_ctrl;
    int mouse_down_shift;
    unsigned long mouse_down_time;
    int error_code;
    int z_order;
    int display_changed_count;
    long help_string_id;
    long help_page_id;
    unsigned char mouse_action;
    unsigned char mouse_down_button;
    unsigned char panel_type;
    unsigned char color;
    unsigned char fill_in_background;
    unsigned char clip_to_parent;
    unsigned char draw_rect2_flag;
    unsigned char need_restore;
};
static_assert(sizeof(TPanel) == 0xF4, "Size mismatch");

// --- TButtonPanel ---
class TButtonPanel : public TPanel {
public:
    // Enum values verified against `src/game/src/Pnl_btn.cpp.asm` (immutable reference).
    // Only values we currently rely on are defined here; add more as confirmed by ASM.
    enum ButtonType : int {
        // NOTE: `TButtonPanel::TButtonPanel` initializes `buttonTypeValue` to 1 (see `pnl_btn.cpp.asm`).
        Normal = 1,
        Radio = 2,
        State = 3,
    };
    enum DrawType : int {
        // NOTE: `TButtonPanel::TButtonPanel` initializes `drawTypeValue` to 1 and `TButtonPanel::draw`
        // early-returns on `drawTypeValue == 1` (see `pnl_btn.cpp.asm`).
        DrawClear = 1,
        DrawPicture = 2,
        DrawTextA = 3,
        DrawPictureAndText = 4,
        DrawFillAndText = 5,
        DrawBevelPicture = 6,
    };
    enum NotifyType : int {
        // NOTE: `NotifyAction == 1` confirmed by `TButtonPanel::do_action` in `Pnl_btn.cpp.asm`.
        NotifyAction = 1,
    };
    
    TButtonPanel();
    virtual ~TButtonPanel();
    virtual long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, DrawType param_7, TDigital* param_8, NotifyType param_9, long param_10);
    ButtonType buttonType();
    DrawType drawType();
    NotifyType notifyType();
    void setDrawType(DrawType type);
    void setButtonType(ButtonType type);
    void set_picture_info(TShape* pic, short pic_index, long x, long y, int all_hot, int auto_pic_pos);
    
    void set_text(short state, char* text);
    void set_text(short state, long resid);
    void set_text(long resid);
    void set_text(short state, long resid1, long resid2);
    void set_text(short state, char* text1, char* text2);
    void set_font(void* font, long wid = -1, long hgt = -1);
    void set_sound_number(int num);
    void set_id(long val);
    void set_id(short state, long id, long id2);
    void set_sound(TDigital* s);
    void set_state(short param_1);
    int get_state();
    void set_state_info(int num_states); // Added for scr_mps team buttons
    int hit_button(long param_1, long param_2);
    void do_action();
    void do_right_action(int param_1);
     void set_radio_button();
     void set_picture(short state, TShape* pic, short pic_index);
     void set_bevel_info(int type, int c1, int c2, int c3, int c4, int c5, int c6);
    void set_text_pos(long x, long y);
    void set_text_info(char* text, void* font, long wid, long hgt, long x, long y);
    void set_text_info(long resid, void* font, long wid, long hgt, long x, long y);
    void set_radio_info(TButtonPanel** buttons, short count);
    long get_id();
    long get_id2();
    int get_text(short state, char** text1, char** text2);
    void get_text_color(short state, ulong* color1, ulong* color2);
    void set_text_color(int state, ulong color1, ulong color2);
    void set_highlight_text_color(int state, ulong color1, ulong color2);
    void set_state_by_id(long id);
    void set_disabled(int disabled);
    void reset();

    virtual void set_rect(tagRECT param_1) override;
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4) override;
    virtual void set_color(uchar param_1) override;
    virtual void set_active(int param_1) override;
    virtual void set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13);
    virtual void set_fixed_position(long param_1, long param_2, long param_3, long param_4) override;
    virtual void set_redraw(RedrawMode param_1) override;
    virtual void set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) override;
    virtual void draw_setup(int param_1) override;
    virtual void draw_finish() override;
    virtual void draw_rect(tagRECT* param_1) override;
    virtual void draw_offset(long param_1, long param_2, tagRECT* param_3) override;
    virtual void draw_rect2(tagRECT* param_1) override;
    virtual void draw_offset2(long param_1, long param_2, tagRECT* param_3) override;
    virtual void paint() override;
    virtual long wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) override;
    virtual long handle_paint() override;
    virtual long handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) override;
    virtual long handle_char(long param_1, short param_2) override;
    virtual long handle_user_command(uint param_1, long param_2) override;
    virtual long handle_timer_command(uint param_1, long param_2) override;
    virtual long handle_scroll(long param_1, long param_2) override;
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) override;
    virtual long handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) override;
    virtual long handle_mouse_move(long param_1, long param_2, int param_3, int param_4) override;
    virtual long mouse_move_action(long param_1, long param_2, int param_3, int param_4) override;
    virtual long mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) override;
    virtual long mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) override;
    virtual long mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) override;
    virtual long mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) override;
    virtual long mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) override;
    virtual long mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) override;
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) override;
    virtual long char_action(long param_1, short param_2) override;
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) override;
    virtual void get_true_render_rect(tagRECT* param_1) override;
    virtual void set_focus(int param_1) override;
    virtual void set_tab_order(TPanel* param_1, TPanel* param_2) override;
    virtual void set_tab_order(TPanel** param_1, short param_2) override;
    virtual void stop_sound_system() override;
    virtual int restart_sound_system() override;
    virtual void take_snapshot() override;
    virtual void handle_reactivate() override;

    virtual void draw() override;
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) override;
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) override;
    virtual int is_inside(long param_1, long param_2) override;

    long id[9];
    long id2[9];
    ButtonType buttonTypeValue;
    DrawType drawTypeValue;
    NotifyType notifyTypeValue;
    TDigital* sound;
    TShape* pic[9];
    short pic_index[9];
    unsigned char _pad_0[0x2];
    int auto_pic_pos;
    long pic_x;
    long pic_y;
    int all_hot;
    int draw_reverse;
    char* text1[9];
    char* text2[9];
    long text_x;
    long text_y;
    void* font;
    long font_wid;
    long font_hgt;
    short num_states;
    short cur_state;
    int is_down;
    TButtonPanel** radio_buttons;
    short num_radio_buttons;
    unsigned char _pad_1[0x2];
    unsigned long button_down_time;
    unsigned long text_color1[9];
    unsigned long text_color2[9];
    unsigned long highlight_text_color1[9];
    unsigned long highlight_text_color2[9];
    long hotkey;
    int hotkey_shift;
    int bevel_type;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    unsigned char _pad_2[0x2];
    long key_down;
    int disabled;
    int sound_number;
};
static_assert(sizeof(TButtonPanel) == 0x2B8, "Size mismatch");

// --- TPanelSystem ---
struct TPanelSystem {
    TPanel* mouseOwnerValue;
    TPanel* keyboardOwnerValue;
    TPanel* modalPanelValue;
    TPanel* currentPanelValue;
    PanelNode* panelListValue;
    int numberActivePanelsValue;
    TPanel* prevCurrentChildValue;
    void* palette[10];
    char palette_file[10][260];
    int palette_use_count[10];
    long palette_id[10];
    unsigned long Imc;
    int ImeEnabled;
    int ImeOn;
    int InputEnabled;
    int saved_colors;
    unsigned long save_back_color;
    unsigned long save_text_color;

    TPanelSystem();
    ~TPanelSystem();

    void* get_palette(char* file, long id);
    void release_palette(void* pal);
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

    long check_message(void* hwnd, uint msg, uint wparam, long lparam);
    void add_panel(TPanel* panel);
    void remove_panel(TPanel* panel);
    TPanel* currentPanel();
    TPanel* previousPanel();
    TPanel* mouseOwner();
    TPanel* keyboardOwner();
    TPanel* modalPanel();
    int numberActivePanels();
    int addPanel(TPanel* panel, int set_current, int modal);
    int removePanel(char* name);

    // Missing methods needed for original game behavior
    TPanel* panel(char* name);
    int setCurrentPanel(char* name, int modal);
    void setCurrentPanel(TPanel* panel, int modal);
    int restorePreviousPanel(int destroy_current);
    int destroyPanel(char* name);
    int inSystem(char* name);
    int inSystem(TPanel* panel);
    int setup();
    PanelNode* findPanelNode(char* name);
    void setMouseOwner(TPanel* panel);
    void setKeyboardOwner(TPanel* panel);
    void setModalPanel(TPanel* panel);
    void setCurrentPanelModal();
    int restorePreviousModalPanel();
    void set_restore();
};
static_assert(sizeof(TPanelSystem) == 0xAD8, "Size mismatch");

#endif // UI_CORE_H
