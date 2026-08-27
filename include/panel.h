#ifndef AOE1_PANEL_H
#define AOE1_PANEL_H

#include <windows.h>

struct PanelNode;
class TPanel;

struct TDrawSystem {
    char gap_00[0x479];
    unsigned char ScreenMode;
    void Paint(tagRECT* rect);
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    void* Wnd;
    char gap_08[0x10];
    long Width;
    long Height;
    char gap_20[0x18];
    void* DrawDc;

    void Clear(tagRECT* rect, unsigned int color);
    void SetClipRect(tagRECT* rect);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    // BINARY NOTE: Panel.cpp dispatches get_string through vslot +0x20.
    virtual void set_game_mode(int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual int get_string(int string_id, char* buffer, int length);

    char gap_04[8];
    void* prog_info;
    char gap_10[0x0C];
    int prog_active;
};

extern RGE_Base_Game* rge_base_game;
extern void* AppWnd;
extern char DAT_0062E670[0x200];
extern "C" void* __cdecl ReadPalette(char*, long, int);
extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);

class TPanelSystem {
public:
    TPanel* mouse_owner;
    TPanel* keyboard_owner;
    TPanel* modal_panel;
    TPanel* current_panel;
    PanelNode* panel_list;
    int number_active_panels;
    TPanel* previous_current_child;
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
    TPanel* currentPanel() const;
    TPanel* previousPanel() const;
    TPanel* mouseOwner() const;
    TPanel* keyboardOwner() const;
    TPanel* modalPanel() const;
    TPanel* panel(char* name);
    int numberActivePanels() const;
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
    int setup(void);
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
    PanelNode* prev_node;
    PanelNode* next_node;
};

class TPanel {
public:
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
    enum RedrawMode {
        RedrawNone = 0,
        RedrawNormal = 1,
        RedrawImmediate = 2
    };

    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(long, long, long, long);
    virtual void set_rect(tagRECT);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(RedrawMode);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, RedrawMode);
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
    virtual void get_true_render_rect(tagRECT&);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel**, short);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual unsigned char get_help_info(char*&, long&, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    TPanel(char* name);
    TPanel();
    void add_panel_node(PanelNode* node, PanelNode* sibling, int after);
    void remove_panel_node(PanelNode* node);
    void set_any_overlapping_redraw(TPanel* panel, RedrawMode mode);
    void set_child_z_order(TPanel* child, unsigned char mode, short order);
    TPanel* previousPanel() const;
    void setPreviousPanel(TPanel* panel);
    TPanel* previousModalPanel() const;
    void setPreviousModalPanel(TPanel* panel);
    char* panelName() const;
    long xPosition() const;
    long yPosition() const;
    long width() const;
    long height() const;
    TDrawArea* renderArea() const;
    tagRECT clipRectangle() const;
    void setClipRectangle(tagRECT rect);
    void setPanelName(char* name);
    void set_curr_child(TPanel* panel);
    int get_focus();
    void set_z_order(unsigned char mode, short order);
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
    long get_help_message();
    long get_help_page();
    void set_help_info(long a, long b);

    TPanel* previous_panel;
    TPanel* previous_modal_panel;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panel_name;
    TDrawArea* render_area;
    tagRECT clip_rect;
    int position_mode;
    int need_redraw;
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

typedef char panel_tpanel_size_check[(sizeof(TPanel) == 0xF4) ? 1 : -1];
typedef char panel_node_size_check[(sizeof(PanelNode) == 0x0C) ? 1 : -1];

#endif
