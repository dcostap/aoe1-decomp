#ifndef AOE1_PANEL_CONTEXT_H
#define AOE1_PANEL_CONTEXT_H

// Panel.cpp-specific aggregate context. The shared panel_context.h remains
// unchanged; this surface is limited to the candidate wrapper.

struct PanelNode;
struct tagPOINT;
struct TDrawSystem;

#if !defined(_WINDEF_) && !defined(_WINDOWS_)
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};
#endif

struct TDrawArea {
    TDrawSystem* DrawSystem;
    void* Wnd;
    char gap_08[0x10];
    union { long Width; long width; };
    union { long Height; long height; };
    char gap_20[0x18];
    void* DrawDc;
    void Clear(tagRECT* rect, unsigned int color);
    void SetClipRect(tagRECT* rect);
};

struct TDrawSystem {
    char gap_00[0x479];
    unsigned char ScreenMode;
    void Paint(tagRECT* rect);
};

struct RGE_Base_Game {
    char gap_00[0x18];
    int prog_active;
    int get_string(int string_id, char* buffer, int length);
};

extern RGE_Base_Game* rge_base_game;
extern "C" __declspec(dllimport) int __stdcall DeleteObject(void* object);

class TPanel;

enum PositionMode {
    PositionFixed = 0,
    PositionLeft = 3,
    PositionCentered = 2,
    PositionTop = 4,
    PositionLeftTop = 7,
    PositionLeftBottom = 8,
    PositionRightTop = 9,
    PositionRightBottom = 10
};

class TPanelSystem {
public:
    union { TPanel* mouseOwnerValue; int mouseOwner_; };
    union { TPanel* keyboardOwnerValue; int keyboardOwner_; };
    union { TPanel* modalPanelValue; int modalPanel_; int field_08; };
    union { TPanel* currentPanelValue; int currentPanel_; };
    union { PanelNode* panelListValue; int numberActivePanels_; int field_00; };
    union { void* field_14; int numberActivePanelsValue; int field_04; };
    void* field_18;
    void* palette[10];
    char palette_file[10][260];
    int palette_use_count[10];
    union { int palette_ids[10]; long palette_id[10]; int field_A94[10]; };
    union { TPanel* prevCurrentChildValue; unsigned long Imc; };
    union { int ImeEnabled; int ImeEnabled_; };
    union { int field_AC4; int ImeOn; int ImeOn_; };
    union { int InputEnabled; int InputEnabled_; };
    int saved_colors;
    unsigned long save_back_color;
    unsigned long save_text_color;

    TPanelSystem();
    ~TPanelSystem();
    int setup(void);
    TPanel* currentPanel();
    TPanel* previousPanel();
    TPanel* mouseOwner();
    TPanel* keyboardOwner();
    TPanel* modalPanel();
    TPanel* panel(char* name);
    int numberActivePanels();
    int addPanel(TPanel* panel, int make_current, int mode);
    int removePanel(char* name);
    int setCurrentPanel(char* name, int mode);
    int restorePreviousPanel(int destroy_current);
    void setMouseOwner(TPanel* owner);
    void setKeyboardOwner(TPanel* owner);
    void setModalPanel(TPanel* panel);
    void setCurrentPanelModal(void);
    int restorePreviousModalPanel(void);
    int destroyPanel(char* name);
    int inSystem(char* name);
    int inSystem(TPanel* panel);
    PanelNode* findPanelNode(char* name);
    void setCurrentPanel(TPanel* panel, int mode);
    void* get_palette(char* name, long mode);
    void release_palette(void* target_palette);
    void DisableIME(void);
    void EnableIME(void);
    int IsIMEEnabled(void);
    void TurnIMEOn(void);
    void TurnIMEOff(void);
    int IsIMEOn(void);
    int GetInputEnabled(void);
    void EnableInput(void);
    void DisableInput(void);
    void stop_sound_system(void);
    int restart_sound_system(void);
    void restore_system_colors(void);
    void set_restore(void);
};

extern TPanelSystem panel_system;

struct PanelNode {
    TPanel* panel;
    union { PanelNode* prev_node; PanelNode* prev; };
    PanelNode* next_node;
};

class TPanel {
public:
    virtual ~TPanel();
    virtual int setup(TDrawArea*, TPanel*, long, long, long, long, int);
    virtual void set_rect(tagRECT);
    virtual void set_rect(int, int, int, int);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, int, int, int, int, int, int, int, int,
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
    virtual int handle_command(int, int);
    virtual int handle_user_command(int, int);
    virtual int handle_timer_command(int, int);
    virtual int handle_scroll(int, int);
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual long handle_mouse_dbl_click(unsigned char, long, long, int, int);
    virtual long mouse_move_action(long, long, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_hold_action(int, int, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual long mouse_right_hold_action(int, int, int, int);
    virtual long mouse_right_move_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual long mouse_right_dbl_click_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long char_action(long, short);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void get_true_render_rect(tagRECT&);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    TPanel(char* name);
    TPanel();
    TPanel* previousPanel();
    void setPreviousPanel(TPanel* panel);
    void setPreviousPanel(int value);
    TPanel* previousModalPanel();
    void setPreviousModalPanel(int value);
    void setPreviousModalPanel(TPanel* panel);
    char* panelName();
    int xPosition();
    int yPosition();
    int width();
    int height();
    int renderArea();
    tagRECT clipRectangle() const;
    void setClipRectangle(tagRECT rect);
    void setPanelName(const char* name);
    void set_tab_order(void* previous, void* next);
    void set_curr_child(TPanel* panel);
    void set_any_overlapping_redraw(TPanel* panel, int mode);
    void set_child_z_order(TPanel* child, unsigned char mode, short order);
    int get_focus();
    long left_dbl_click_action(long, long, int, int);
    long right_dbl_click_action(long, long, int, int);
    void set_z_order(unsigned char mode, short order);
    void add_panel_node(PanelNode* node, PanelNode* sibling, int after);
    void remove_panel_node(PanelNode* node);
    int is_inside_rect(long x, long y, tagRECT* rect);
    int bound_point(long& x, long& y);
    void get_mouse_info(unsigned int keys, long packed_pos, tagPOINT& point,
                        int& focus_flag, int& capture_flag);
    void get_mouse_pos(tagPOINT& point);
    int capture_mouse();
    void release_mouse();
    unsigned char is_redraw_needed();
    void delete_panel(TPanel** panel);
    int get_string(int string_id, char* buffer, int length);
    char* get_string(int string_id);
    int get_help_message();
    int get_help_page();
    void set_help_info(int a, int b);

    union { TPanel* previous_panel; TPanel* previousPanelValue; int previousPanel_; };
    union { TPanel* previous_modal_panel; TPanel* previousModalPanelValue; int previousModalPanel_; };
    union { long pnl_x; int pnl_x_; int xPosition_; };
    union { long pnl_y; int pnl_y_; int yPosition_; };
    union { long pnl_wid; int pnl_wid_; int width_; };
    union { long pnl_hgt; int pnl_hgt_; int height_; };
    union { char* panel_name; char* panelNameValue; int panelName_; };
    union { TDrawArea* render_area; int render_area_; };
    union {
        tagRECT clip_rect;
        struct { long clip_left; long clip_top; long clip_right; long clip_bottom; };
    };
    union { int position_mode; int position_mode_; };
    union { int need_redraw; unsigned char need_redraw_; };
    union { TPanel* curr_child; int field_3C; };
    TPanel* parent_panel;
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    PanelNode* node;
    PanelNode* first_child_node;
    PanelNode* last_child_node;
    TPanel* tab_prev_panel;
    union { TPanel* tab_next_panel; int field_64; };
    union { int mouse_captured; int mouse_captured_; int field_68; };
    union { int active; int field_6C; };
    union { int visible; int field_70; };
    int tab_stop;
    union { int have_focus; int field_78; };
    union { int overlapping_children; int field_7C; };
    union { int handle_mouse_input; int field_80; };
    union { int just_drawn; int gap_84; };
    union { void* clip_rgn; int clip_rgn_; };
    union {
        tagRECT render_rect;
        struct {
            union { long render_left; long field_8C; };
            union { long render_top; long field_90; };
            union { long render_right; long field_94; };
            union { long render_bottom; long field_98; };
        };
    };
    union { long left_border; int left_border_; };
    union { long top_border; int top_border_; };
    union { long right_border; int right_border_; };
    union { long bottom_border; int bottom_border_; };
    union { long min_wid; int min_wid_; };
    union { long max_wid; int max_wid_; };
    union { long min_hgt; int min_hgt_; };
    union { long max_hgt; int max_hgt_; };
    union { long mouse_hold_interval; int mouse_hold_interval_; int field_BC; };
    union { long mouse_move_tolerance; int mouse_move_tolerance_; int field_C0; };
    union { long mouse_down_x; int mouse_down_x_; int field_C4; };
    union { long mouse_down_y; int mouse_down_y_; int field_C8; };
    union { int mouse_down_ctrl; int mouse_down_ctrl_; int field_CC; };
    union { int mouse_down_shift; int mouse_down_shift_; int field_D0; };
    union { unsigned long mouse_down_time; int mouse_down_time_; int field_D4; };
    union { int error_code; int field_D8; };
    union { int z_order; int field_DC; };
    union { int display_changed_count; int field_E0; };
    union { long help_string_id; int help_string_id_; int field_E4; };
    union { long help_page_id; int help_page_id_; int field_E8; };
    union { unsigned char mouse_action; unsigned char field_EC; };
    union { unsigned char mouse_down_button; unsigned char field_ED; };
    union { unsigned char panel_type; unsigned char field_EE; };
    union { unsigned char color; unsigned char field_EF; };
    union { unsigned char fill_in_background; unsigned char field_F0; };
    unsigned char clip_to_parent;
    union { unsigned char draw_rect2_flag; unsigned char field_F2; };
    union { unsigned char need_restore; unsigned char field_F3; };
};

typedef char panel_cpp_context_tpanel_size_check[(sizeof(TPanel) == 0xF4) ? 1 : -1];
typedef char panel_cpp_context_node_size_check[(sizeof(PanelNode) == 0x0C) ? 1 : -1];

#endif
