#pragma once
#include "../common.h"

class Time_Line_Panel : public TEasy_Panel {
public:
    void* axis_font;                         // 0x478
    long axis_font_wid;                      // 0x47C
    long axis_font_hgt;                      // 0x480
    void* body_font;                         // 0x484
    long body_font_wid;                      // 0x488
    long body_font_hgt;                      // 0x48C
    Style text_style;                        // 0x490
    ulong text_color1;                       // 0x494
    ulong text_color2;                       // 0x498
    ulong highlightTextColor1;               // 0x49C
    ulong highlightTextColor2;               // 0x4A0
    long text_wid;                           // 0x4A4
    long text_hgt;                           // 0x4A8
    TShape* background_pic;                  // 0x4AC
    short background_pic_wid;                // 0x4B0
    short background_pic_hgt;                // 0x4B2
    int fill_back;                           // 0x4B4
    uchar back_color;                        // 0x4B8
    int outline;                             // 0x4BC
    uchar outline_color;                     // 0x4C0
    int sorted;                              // 0x4C4
    int bevel_type;                          // 0x4C8
    uchar bevel_color1;                      // 0x4CC
    uchar bevel_color2;                      // 0x4CD
    uchar bevel_color3;                      // 0x4CE
    uchar bevel_color4;                      // 0x4CF
    uchar bevel_color5;                      // 0x4D0
    uchar bevel_color6;                      // 0x4D1
    TShape* special_events_pic;              // 0x4D4
    short special_events_pic_wid;            // 0x4D8
    short special_events_pic_hgt;            // 0x4DA
    long X_start_line_pos;                   // 0x4DC
    long Y_start_line_pos;                   // 0x4E0
    long X_line_pos;                         // 0x4E4
    long Y_line_pos;                         // 0x4E8
    long X_line_max_width;                   // 0x4EC
    long Y_line_max_length;                  // 0x4F0
    long X_axis_length;                      // 0x4F4
    long Y_axis_length;                      // 0x4F8
    float bar_thickness;                     // 0x4FC
    long pop_reading_rate;                   // 0x500
    float time_slice_drop_rate;              // 0x504
    long total_slices_to_drop;               // 0x508
    uchar drop_flag;                         // 0x50C
    long num_entries_page;                   // 0x510
    long num_history_entries;                // 0x514
    Special_Events* time_slice_events;       // 0x518
    uchar timeline_flag;                     // 0x51C
    TTextPanel* legend_entry_text[3];        // 0x520

    Time_Line_Panel();
    virtual ~Time_Line_Panel();
    virtual long create_timeline(TPanel* param_1, Time_Line_Panel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10);
    virtual long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, void* param_7, long param_8, long param_9, void* param_10, long param_11, long param_12, char* param_13, char* param_14, int param_15, uchar param_16, int param_17, uchar param_18);
    virtual void set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7);
    virtual int set_background(char* param_1);
    virtual int set_background(char* param_1, long param_2);
    virtual int set_special_events(char* param_1);
    virtual int set_special_events(char* param_1, long param_2);
    virtual void set_axis_font(void* param_1, long param_2, long param_3);
    virtual void set_body_font(void* param_1, long param_2, long param_3);
    virtual void set_back_color(int param_1, uchar param_2);
    virtual void draw_border();
    virtual void init_timeline();
    virtual void add_pop_total_special_event(long param_1, long param_2, long param_3, int param_4);
    virtual void record_special_event(uchar param_1, TRIBE_History_Info* param_2, uchar param_3, long param_4, long param_5, long param_6, long param_7);
    virtual int calculate_icon_location(Special_Events* param_1, short param_2, uchar param_3);
    virtual void draw();
    virtual void draw_axis();
    virtual void draw_special_events();
    virtual void draw_background();
    virtual void draw_civilization_names();
    virtual void draw_timeline();
    virtual void draw_icon(Special_Events* param_1, short param_2, uchar param_3);
    virtual void draw_legend();
};

static_assert(sizeof(Time_Line_Panel) == 0x52C, "Time_Line_Panel Size Mismatch");
static_assert(offsetof(Time_Line_Panel, legend_entry_text) == 0x520, "Time_Line_Panel Offset Mismatch");

