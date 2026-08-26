#ifndef AOE1_PNL_BTN_CONTEXT_H
#define AOE1_PNL_BTN_CONTEXT_H

// Authentic source module: C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp.
// This header keeps the proven panel and button layouts in one compiler-facing
// owner. The event slots follow the reviewed TPanel surface.

#include <windows.h>

class TDigital;
class TShape;
class TPanel;
class TButtonPanel;
struct PanelNode;

class TDrawArea {
public:
    void* DrawSystem;
    void* Wnd;
    char gap_08[0x10];
    long width;
    long height;

    void Clear(RECT*, unsigned char);
    unsigned char* Lock(const char*, int);
    void Unlock(const char*);
    void* GetDc(const char*);
    void ReleaseDc(const char*);
    void DrawRect(long, long, long, long, unsigned char);
    void DrawHorzLine(long, long, long, unsigned char);
    void DrawVertLine(long, long, long, unsigned char);
    void DrawBevel(long, long, long, long, unsigned char, unsigned char);
    void DrawBevel2(long, long, long, long, unsigned char, unsigned char,
                    unsigned char, unsigned char);
    void DrawBevel3(long, long, long, long, unsigned char, unsigned char,
                    unsigned char, unsigned char, unsigned char, unsigned char);
    void DrawBevel21(long, long, long, long, unsigned char, unsigned char,
                     unsigned char, unsigned char);
    void DrawBevel32(long, long, long, long, unsigned char, unsigned char,
                     unsigned char, unsigned char, unsigned char, unsigned char);
};

class TShape {
public:
    char gap_00[4];
    virtual ~TShape();
    void shape_minmax(long*, long*, long*, long*, int);
    void shape_draw(TDrawArea*, long, long, int, unsigned char, unsigned char*);
    unsigned char shape_check(int, int, int);
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(RECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(RECT*);
    virtual void draw_offset(long, long, RECT*);
    virtual void draw_rect2(RECT*);
    virtual void draw_offset2(long, long, RECT*);
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
    virtual void get_true_render_rect(RECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    int capture_mouse();
    void release_mouse();
    void set_curr_child(TPanel*);
    int get_string(int, char*, int);

    TPanel* previous_panel;
    TPanel* previous_modal_panel;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panel_name;
    TDrawArea* render_area;
    RECT clip_rect;
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
    RECT render_rect;
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
    long z_order;
    long display_changed_count;
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

typedef char pnl_btn_tpanel_size_check[(sizeof(TPanel) == 0xF4) ? 1 : -1];

class TDigital {
public:
    int is_playing();
    void stop();
    int play();
};

class TButtonPanel : public TPanel {
public:
    // BINARY NOTE: PDB-qualified symbols use these nested enums and const
    // getters. The hit test is a virtual member at its observed slot.
    enum ButtonType {
        Normal = 1,
        Radio = 2,
        State = 3
    };
    enum DrawType {
        DrawClear = 1,
        DrawText = 2,
        DrawPicture = 3,
        DrawPictureAndText = 4,
        DrawFillAndText = 5,
        DrawBevelPicture = 6
    };
    enum NotifyType {
        NotifyAction = 1,
        NotifyMessage = 2
    };
    long id[9];
    long id2[9];
    ButtonType buttonTypeValue;
    DrawType drawTypeValue;
    NotifyType notifyTypeValue;
    TDigital* sound;
    TShape* pic[9];
    short pic_index[9];
    unsigned char gap_182[2];
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
    unsigned char gap_202[2];
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
    unsigned char gap_2AA[2];
    long key_down;
    int disabled;
    int sound_number;

    virtual ~TButtonPanel();
    TButtonPanel();

    long setup(TDrawArea*, TPanel*, long, long, long, long, DrawType, TDigital*, NotifyType, long);
    ButtonType buttonType() const;
    DrawType drawType() const;
    NotifyType notifyType() const;
    void setDrawType(DrawType);
    void setButtonType(ButtonType);
    void set_picture_info(TShape*, short, long, long, int, int);
    void set_text_info(char*, void*, long, long, long, long);
    void set_text_info(long, void*, long, long, long, long);
    void set_text_pos(long, long);
    void set_radio_info(TButtonPanel**, short);
    void set_state_info(short);
    void set_id(short, long, long);
    void set_picture(short, TShape*, short);
    void set_text(short, char*);
    void set_text(short, char*, char*);
    void set_text(short, long);
    void set_text(short, long, long);
    void set_font(void*, long, long);
    void set_text_color(int, unsigned long, unsigned long);
    void set_highlight_text_color(int, unsigned long, unsigned long);
    void set_sound(TDigital*);
    void set_radio_button();
    virtual void set_state(short);
    void set_state_by_id(long);
    void set_bevel_info(int, int, int, int, int, int, int);
    void set_disabled(int);
    int get_state();
    long get_id();
    long get_id2();
    int get_text(short, char**, char**);
    void get_text_color(short, unsigned long*, unsigned long*);

    virtual void draw();
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual long mouse_right_move_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long mouse_right_dbl_click_action(long, long, int, int);
    virtual long handle_key_down(long, short, int, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual long char_action(long, short);
    virtual void stop_sound_system();
    virtual int restart_sound_system();

    virtual int hit_button(long, long);
    void do_action();
    void do_right_action(int);
    void reset();
    void set_sound_number(int);
};

typedef char pnl_btn_tbutton_size_check[
    (sizeof(TButtonPanel) == 0x2B8) ? 1 : -1];

class RGE_Base_Game {
public:
    TDigital* get_sound(int);
};

extern RGE_Base_Game* rge_base_game;

#endif
