#ifndef AOE1_TPNL_TML_H
#define AOE1_TPNL_TML_H

// PDB source module: C:\msdev\work\age1_x1\tpnl_tml.cpp.
// Time_Line_Panel owns this layout. Its base and foreign members use their
// reviewed source-module owners.
#include "panel_ez.h"
#include "pnl_lst.h"
#include "Shape.h"
#include "basegame.h"
#include "rge_base_game_global.h"
#include "world.h"
#include "tplayer.h"
#include "t_histry.h"
#include "color.h"

struct Special_Events {
    long time_slice;
    long X_line_pos;
    long Y_line_pos;
    long intermediate_y_line_segment;
    unsigned char player_id;
    unsigned char player_color;
    unsigned char event;
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
    int text_length2;
    char text2[50];
    int icon_flag;
    Special_Events* next;
};

typedef char special_events_size_check[
    (sizeof(Special_Events) == 0xB0) ? 1 : -1];

class Time_Line_Panel : public TEasy_Panel {
public:
    enum Style { ChiseledStyle = 2 };

    void* axis_font;
    long axis_font_wid;
    long axis_font_hgt;
    void* body_font;
    long body_font_wid;
    long body_font_hgt;
    Style text_style;
    unsigned long text_color1;
    unsigned long text_color2;
    unsigned long highlightTextColor1;
    unsigned long highlightTextColor2;
    long text_wid;
    long text_hgt;
    TShape* background_pic;
    short background_pic_wid;
    short background_pic_hgt;
    int fill_back;
    unsigned char back_color;
    int outline;
    unsigned char outline_color;
    int sorted;
    int bevel_type;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
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
    unsigned char drop_flag;
    long num_entries_page;
    long num_history_entries;
    Special_Events* time_slice_events;
    unsigned char timeline_flag;
    TTextPanel* legend_entry_text[3];

    Time_Line_Panel();
    virtual ~Time_Line_Panel();
    virtual void draw();

    long create_timeline(TPanel*, Time_Line_Panel**, long, long, long, long,
                         long, long, long, long);
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long,
               void*, long, long, char*, char*, int, unsigned char, int,
               unsigned char);
    void set_bevel_info(int, int, int, int, int, int, int);
    int set_background(char*);
    int set_background(char*, long);
    int set_special_events(char*);
    int set_special_events(char*, long);
    void set_axis_font(void*, long, long);
    void set_body_font(void*, long, long);
    void set_back_color(int, unsigned char);
    void draw_border();
    void init_timeline();
    void add_pop_total_special_event(long, long, long, int);
    void record_special_event(unsigned char, TRIBE_History_Info*,
                              unsigned char, long, long, long, long);
    int calculate_icon_location(Special_Events*, short, unsigned char);
    void draw_axis();
    void draw_special_events();
    void draw_background();
    void draw_civilization_names();
    void draw_timeline();
    void draw_icon(Special_Events*, short, unsigned char);
    void draw_legend();
};

typedef char time_line_panel_size_check[
    (sizeof(Time_Line_Panel) == 0x52C) ? 1 : -1];

extern char s_tpnl_tml_draw_axis[];

#endif
