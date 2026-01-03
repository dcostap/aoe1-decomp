#pragma once
#include "../common.h"
#include "diam_map.h"
#include "Pnl_scr.h"
#include "Shape.h"
#include "tvw_main.h"
#include "tvw_dmap.h"

class TScrollBarPanel : public TPanel {
public:
    TPanel* list_panel;                      // 0xF4
    long list_len;                           // 0xF8
    long one_step;                           // 0xFC
    long page_step;                          // 0x100
    long list_num;                           // 0x104
    TShape* button_pics;                     // 0x108
    int back_frame;                          // 0x10C
    int up_frame;                            // 0x110
    int down_frame;                          // 0x114
    int tab_frame;                           // 0x118
    long arrowSize;                          // 0x11C
    long tabSize;                            // 0x120
    long tab_y;                              // 0x124
    long tab_min_y;                          // 0x128
    long tab_max_y;                          // 0x12C
    long tab_mouse_y;                        // 0x130
    long tab_x;                              // 0x134
    long tab_min_x;                          // 0x138
    long tab_max_x;                          // 0x13C
    long tab_mouse_x;                        // 0x140
    uchar item_down;                         // 0x144
    int item_is_down;                        // 0x148
    long item_x;                             // 0x14C
    long item_y;                             // 0x150
    uchar item_mode;                         // 0x154
    ulong item_last_time;                    // 0x158
    ulong item_hold_interval;                // 0x15C
    ulong item_down_interval;                // 0x160
    tagRECT up_rect;                         // 0x164
    tagRECT down_rect;                       // 0x174
    tagRECT tab_rect;                        // 0x184
    tagRECT top_rect;                        // 0x194
    tagRECT bottom_rect;                     // 0x1A4
    Orientation orientationValue;            // 0x1B4
    int bevel_type;                          // 0x1B8
    uchar bevel_color1;                      // 0x1BC
    uchar bevel_color2;                      // 0x1BD
    uchar bevel_color3;                      // 0x1BE
    uchar bevel_color4;                      // 0x1BF
    uchar bevel_color5;                      // 0x1C0
    uchar bevel_color6;                      // 0x1C1

    TScrollBarPanel();
    virtual ~TScrollBarPanel();
    virtual long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, char* param_7, char* param_8, char* param_9, char* param_10, long param_11, long param_12, TPanel* param_13, long param_14, Orientation param_15);
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4);
    virtual void calc_item_rects();
    virtual void set_tab_pos(long param_1);
    virtual void set_list_len(long param_1, long param_2);
    virtual void set_buttons(TShape* param_1, int param_2, int param_3, int param_4, int param_5);
    virtual void set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7);
    virtual long handle_idle();
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_move_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4);
    virtual void scroll(ActionType param_1, long param_2);
    virtual void draw();
    virtual void draw_border(int param_1, int param_2, tagRECT* param_3);
    virtual void draw_border(int param_1, int param_2, long param_3, long param_4, long param_5, long param_6);
    virtual void draw_back_pic();
    virtual void draw_button_pic(int param_1, int param_2, tagRECT* param_3);
};

static_assert(sizeof(TScrollBarPanel) == 0x1C4, "TScrollBarPanel Size Mismatch");
static_assert(offsetof(TScrollBarPanel, bevel_color6) == 0x1C1, "TScrollBarPanel Offset Mismatch");

