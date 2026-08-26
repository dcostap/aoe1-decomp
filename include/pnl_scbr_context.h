#ifndef AOE1_PNL_SCBR_CONTEXT_H
#define AOE1_PNL_SCBR_CONTEXT_H

// Recovered Pnl_scbr.cpp translation-unit context.  The complete panel and
// scrollbar surfaces keep one compiler-facing declaration set for the owners
// in this module.  The bodies remain in their assigned owner files.

#include <windows.h>

class TDrawSystem;
class TDrawArea;
class TShape;
class TScrollBarPanel;

class TDrawArea {
public:
    void* DrawSystem;
    void* Wnd;
    char gap_08[0x10];
    long Width;
    long Height;

    ~TDrawArea();
    void* Lock(char*, int);
    void Unlock(char*);
    void SetClipRect(tagRECT*);
    void DrawRect(long, long, long, long, unsigned char);
    void DrawVertLine(long, long, long, unsigned char);
    void DrawHorzLine(long, long, long, unsigned char);
    void DrawBevel(long, long, long, long, unsigned char, unsigned char);
    void DrawBevel2(long, long, long, long, unsigned char, unsigned char,
                    unsigned char, unsigned char);
    void DrawBevel3(long, long, long, long, unsigned char, unsigned char,
                    unsigned char, unsigned char, unsigned char, unsigned char);
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long, long,
                                 long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void redraw(int);
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
    virtual void enterCS(int);
    virtual void leaveCS();

    union { TPanel* previous_panel; void* previousPanelValue; };
    union { TPanel* previous_modal_panel; void* previousModalPanelValue; };
    union { long pnl_x; long margin; long field_0C; };
    union { long pnl_y; long track_size; long field_10; };
    union { long pnl_wid; long perp_size; long field_14; };
    union { long pnl_hgt; long button_size; long field_18; };
    union { char* panel_name; char* panelNameValue; };
    union { TDrawArea* render_area; TDrawArea* draw_area; TDrawArea* field_20; };
    union { tagRECT clip_rect; tagRECT rect_24; };
    long position_mode;
    long need_redraw;
    TPanel* curr_child;
    union { TPanel* parent_panel; TPanel* panel; };
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    void* node;
    void* first_child_node;
    void* last_child_node;
    TPanel* tab_prev_panel;
    TPanel* tab_next_panel;
    long mouse_captured;
    long active;
    long visible;
    long tab_stop;
    long have_focus;
    long overlapping_children;
    long handle_mouse_input;
    long just_drawn;
    void* clip_rgn;
    union { tagRECT render_rect; tagRECT rect_8C; };
    long left_border;
    long top_border;
    long right_border;
    long bottom_border;
    long min_wid;
    long max_wid;
    long min_hgt;
    long max_hgt;
    long mouse_hold_interval;
    union { long mouse_move_tolerance; long field_C0; };
    long mouse_down_x;
    long mouse_down_y;
    long mouse_down_ctrl;
    long mouse_down_shift;
    unsigned long mouse_down_time;
    long error_code;
    long z_order;
    long display_changed_count;
    long help_string_id;
    long help_page_id;
    unsigned char mouse_action;
    unsigned char mouse_down_button;
    union { unsigned char panel_type; unsigned char field_EE; };
    unsigned char color;
    unsigned char fill_in_background;
    unsigned char clip_to_parent;
    unsigned char draw_rect2_flag;
    unsigned char need_restore;

    TPanel();
    void capture_mouse();
    void release_mouse();
    int is_inside_rect(long, long, tagRECT*);
    void set_curr_child(TPanel*);
};

class TShape {
public:
    char gap_00[0x20];
    TShape(char*, long);
    ~TShape();
    int is_loaded();
    unsigned char shape_minmax(long&, long&, long&, long&, long);
    unsigned char shape_draw(TDrawArea*, long, long, long, unsigned char,
                             unsigned char*);
};

extern "C" unsigned long __cdecl debug_timeGetTime(const char*, int);

class TScrollBarPanel : public TPanel {
public:
    enum Orientation { Vertical = 0, Horizontal = 1 };

    TPanel* list_panel;
    long list_len;
    long one_step;
    long page_step;
    long list_num;
    TShape* button_pics;
    long back_frame;
    long up_frame;
    long down_frame;
    long tab_frame;
    long arrowSize;
    long tabSize;
    long tab_y;
    long tab_min_y;
    long tab_max_y;
    long tab_mouse_y;
    long tab_x;
    long tab_min_x;
    long tab_max_x;
    long tab_mouse_x;
    union { unsigned char item_down; unsigned char action_type; unsigned char pressed_part; };
    unsigned char item_pad_145[3];
    union { long item_is_down; long active; };
    union { long item_x; long mouse_x; };
    union { long item_y; long mouse_y; };
    union { unsigned char item_mode; unsigned char state; };
    unsigned char item_pad_155[3];
    union { unsigned long item_last_time; unsigned long last_time; };
    union { unsigned long item_hold_interval; unsigned long repeat_time; };
    union { unsigned long item_down_interval; unsigned long initial_time; };
    union { tagRECT up_rect; tagRECT rect_up; };
    union { tagRECT down_rect; tagRECT rect_down; };
    tagRECT tab_rect;
    union { tagRECT top_rect; tagRECT rect1; };
    union { tagRECT bottom_rect; tagRECT rect2; };
    union { long orientationValue; long orientation; };
    long bevel_type;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    unsigned char bevel_pad_1c2[2];

    enum ActionType {
        ActionUp = 0,
        ActionDown = 1,
        ActionPrior = 2,
        ActionNext = 3,
        ActionPosition = 4
    };

    TScrollBarPanel();
    virtual ~TScrollBarPanel();
    // BINARY NOTE: PDB declares this public member as nonvirtual. Its final
    // parameter is the nested Orientation enum, which is part of its symbol.
    long setup(TDrawArea*, TPanel*, long, long, long, long,
               char*, char*, char*, char*, long, long, TPanel*, long, Orientation);
    virtual void set_rect(long, long, long, long);
    void calc_item_rects();
    void set_tab_pos(long);
    void set_list_len(long, long);
    void set_buttons(TShape*, int, int, int, int);
    void set_bevel_info(int, int, int, int, int, int, int);
    virtual long handle_idle();
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    void scroll(ActionType, long);
    void scroll(int action, long param) { this->scroll((ActionType)action, param); }
    virtual void draw();

protected:
    void draw_border(int, int, tagRECT*);
    void draw_border(int, int, long, long, long, long);
    void draw_back_pic();
    void draw_button_pic(int, int, tagRECT*);
};

typedef char pnl_scbr_tpanel_size_check[(sizeof(TPanel) == 0xF4) ? 1 : -1];
typedef char pnl_scbr_scrollbar_size_check[(sizeof(TScrollBarPanel) == 0x1C4) ? 1 : -1];

#endif
