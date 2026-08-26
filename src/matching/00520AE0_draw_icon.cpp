// Attempt log for 00520AE0 Time_Line_Panel::draw_icon
// try 1: natural reconstruction from packet/decompiler with minimal surfaces; too small 528B.
// try 2: add all post-location draw cases and closer decompiler fields; exact size but EBP=this, no IAT ptr local, wrong palette +8 load.
// try 3: use self local, explicit GetNearestPaletteIndex function-pointer local, and palette[2] expression; edit diff improved to 31.5%, but EBP=this instead of EBX=this.
// try 4: predeclare minute/hour locals at top to encourage EBP as arithmetic local; no codegen change.
// try 5: /O1 flag probe; too small 422B, rolled back.
// try 6: /Oy- flag probe; worse from offset 0, rolled back.
// try 7: remove self local and use direct this to probe EBX allocation; no change.
// try 8: remove getNearest local and call import pointer directly; worse (75.7%/33.9%), rolled back.
// try 9: restore getNearest local best form.
// try 10: reviewed switch vs if-chain; switch dispatch matches original jump-table family, so kept.
// BLOCKER: exact 581B size, call set and much of structure plausible, but register allocation remains wrong from prologue (rebuilt EBP=this, original EBX=this with EBP used later for hour quotient). This shifts all this-relative encodings and broad positional diff. Not accepted_drift-safe.
// worker probe 2: corrected Special_Events ownership/layout, inherited TPanel/TEasy_Panel context, and the six-argument TShape ABI; 315B diff, exact size/frame/call set.
// worker probe 3: replaced gap-only panel declarations with the ground-truth typed member surfaces; emitted code was unchanged.
// worker probes 4-5: reordered/widened time-format locals; emitted code was unchanged.
// worker probe 7: restored the binary-proven seconds -> zero-minute -> optional-hour source semantics; 8 differing bytes remain, all temp_str+4 stack displacement bytes.
// worker probes 6/8: declaration-order variant families for arithmetic and local declarations collapsed to one emitted group.
// worker probe 9: minimal RECT/header-context variant emitted the same 8-byte drift.
// worker probe 10: a synthetic union overlay reduced no bytes and changed the frame to 0x34; rolled back as implausible.
// worker probe 11: scoped temp_str to the event switch as a natural lifetime/scheduling lead; emitted code stayed unchanged at 8 bytes, rolled back.
// current worker probe 1: stored the palette result in typed temp_str[0]; the frame fell to 0x34 while the same eight displacement bytes remained.
// current worker probe 2: widened temp_str to 54 bytes for its four-byte palette prefix and 0x32-byte text destination; exact 581-byte match.
// Best current reconstruction is the typed period-style source below. The 54-byte temporary models the four-byte palette prefix and 0x32-byte text destination.

#define GetNearestPaletteIndex draw_icon_windows_GetNearestPaletteIndex
#include <windows.h>
#undef GetNearestPaletteIndex
#include <stdio.h>
#include <string.h>

typedef unsigned char uchar;
#ifndef TPNL_TML_WRAPPER
extern "C" unsigned int (__stdcall* const GetNearestPaletteIndex)(void*, unsigned int);
#endif

#ifndef TPNL_TML_WRAPPER
class TDrawSystem {
public:
    void* instance;
    void* window;
    void* Pal;
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    char gap_04[0x34];
    void DrawVertLine(long, long, long, uchar);
};

class TShape {
public:
    uchar shape_draw(TDrawArea*, long, long, int, uchar, uchar*);
};

struct Special_Events {
    long time_slice;
    long X_line_pos;
    long Y_line_pos;
    long intermediate_y_line_segment;
    uchar player_id;
    uchar player_color;
    uchar event;
    char gap_13;
    long pop_total;
    long integer_value_1;
    long integer_value_2;
    long start_x;
    long start_y;
    long start_txt_x1;
    long start_txt_y1;
    long start_txt_x2;
    long start_txt_y2;
    int text_length1;
    char text1[50];
    uchar gap_6e[2];
    int text_length2;
    char text2[50];
    uchar gap_a6[2];
    int icon_flag;
    Special_Events* next;
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(RECT*);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(RECT*);
    virtual void draw_offset(long, long, RECT*);
    virtual void draw_rect2(RECT*);

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
    void* node;
    void* first_child_node;
    void* last_child_node;
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
    int z_order;
    int display_changed_count;
    long help_string_id;
    long help_page_id;
    uchar mouse_action;
    uchar mouse_down_button;
    uchar panel_type;
    uchar color;
    uchar fill_in_background;
    uchar clip_to_parent;
    uchar draw_rect2_flag;
    uchar need_restore;

    int get_string(int, char*, int);
};

class TEasy_Panel : public TPanel {
public:
    char gap_f4[0x384];
};

class Time_Line_Panel : public TEasy_Panel {
public:
    void* axis_font;
    long axis_font_wid;
    long axis_font_hgt;
    void* body_font;
    long body_font_wid;
    long body_font_hgt;
    int text_style;
    unsigned long text_color1;
    unsigned long text_color2;
    unsigned long highlight_text_color1;
    unsigned long highlight_text_color2;
    long text_wid;
    long text_hgt;
    TShape* background_pic;
    short background_pic_wid;
    short background_pic_hgt;
    int fill_back;
    uchar back_color;
    uchar gap_4b9[3];
    int outline;
    uchar outline_color;
    uchar gap_4c1[3];
    int sorted;
    int bevel_type;
    uchar bevel_color1;
    uchar bevel_color2;
    uchar bevel_color3;
    uchar bevel_color4;
    uchar bevel_color5;
    uchar bevel_color6;
    uchar gap_4d2[2];
    TShape* special_events_pic;
    short special_events_pic_wid;
    short special_events_pic_hgt;
    long X_start_line_pos;
    long Y_start_line_pos;
    long X_line_pos;
    long Y_line_pos;
    long X_line_max_width;
    long Y_line_max_length;
    long X_axis_length;
    long Y_axis_length;
    float bar_thickness;
    long pop_reading_rate;
    float time_slice_drop_rate;
    long total_slices_to_drop;
    uchar drop_flag;
    uchar gap_50d[3];
    long num_entries_page;
    long num_history_entries;
    Special_Events* time_slice_events;
    uchar timeline_flag;

    int calculate_icon_location(Special_Events*, short, uchar);
    void draw_icon(Special_Events*, short, uchar);
};
#endif

void Time_Line_Panel::draw_icon(Special_Events* ev, short param_2, uchar param_3)
{
    char temp_str[54];
    long total;
    long hi_top;
    long q_top;
    unsigned int (__stdcall* getNearest)(void*,
#ifdef TPNL_TML_WRAPPER
                                         unsigned long) =
#else
                                         unsigned int) =
#endif
        GetNearestPaletteIndex;
    getNearest(this->render_area->DrawSystem->Pal, 0xffffff);
    temp_str[0] = (char)getNearest(this->render_area->DrawSystem->Pal, 0);

    switch (ev->event) {
    case 0:
        if (this->get_string(0x106a, temp_str + 4, 0x32)) sprintf(ev->text1, "%s", temp_str + 4); else ev->text1[0] = 0;
        break;
    case 1:
        if (this->get_string(0x106b, temp_str + 4, 0x32)) sprintf(ev->text1, "%s", temp_str + 4); else ev->text1[0] = 0;
        break;
    case 2:
        if (this->get_string(0x106c, temp_str + 4, 0x32)) sprintf(ev->text1, "%s", temp_str + 4); else ev->text1[0] = 0;
        break;
    case 8:
        sprintf(temp_str + 4, "%ld/%1d", ev->integer_value_1, ev->integer_value_2);
        sprintf(ev->text1, "%s", temp_str + 4);
        // fall through
    case 3: {
        sprintf(ev->text1, "%ld", ev->pop_total);
        hi_top = 0;
        ev->text_length1 = strlen(ev->text1);
        q_top = 0;
        total = ev->time_slice * 15;
        if (total > 59) {
            q_top = total / 60;
            if (q_top > 59) {
                hi_top = q_top / 60;
                q_top = q_top - hi_top * 60;
            }
        }
        sprintf(temp_str + 4, "%1ld:%02ld", hi_top, q_top);
        sprintf(ev->text2, "%s", temp_str + 4);
        ev->text_length2 = strlen(ev->text2);
        break;
    }
    default:
        break;
    }

    int ok = this->calculate_icon_location(ev, param_2, param_3);
    switch (ev->event) {
    case 0:
            this->render_area->DrawVertLine(ev->X_line_pos, ev->Y_line_pos, ev->intermediate_y_line_segment, (uchar)temp_str[0]);
        return;
    case 1:
        this->render_area->DrawVertLine(ev->X_line_pos, ev->Y_line_pos, ev->intermediate_y_line_segment, (uchar)temp_str[0]);
        return;
    case 2:
        this->render_area->DrawVertLine(ev->X_line_pos, ev->Y_line_pos, ev->intermediate_y_line_segment, (uchar)temp_str[0]);
        return;
    default:
        if (ok) {
            this->special_events_pic->shape_draw(this->render_area, ev->start_x, ev->start_y,
                                    (int)param_2, 0, (uchar*)0);
        }
        return;
    }
}
