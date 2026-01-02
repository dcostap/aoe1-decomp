#pragma once
#include "../common.h"

class TListPanel : public TTextPanel {
public:
    int auto_track;                          // 0x188
    ulong mouse_scroll_last_time;            // 0x18C
    ulong mouse_scroll_interval;             // 0x190
    int mouse_scroll_up;                     // 0x194
    int mouse_scroll_down;                   // 0x198
    int drawHighlightBar;                    // 0x19C

    TListPanel();
    virtual ~TListPanel();
    virtual void set_auto_track(int param_1);
    virtual void set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7);
    virtual long handle_idle();
    virtual long mouse_move_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_move_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4);
    virtual short item_at(long param_1, long param_2);
    virtual void goto_item(long param_1, long param_2);
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5);
    virtual long char_action(long param_1, short param_2);
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
    virtual void scroll_cur_line(uchar param_1, short param_2, int param_3);
    virtual void draw();
    virtual void draw_highlight_bar();
    virtual void setDrawHighlightBar(int param_1);
    virtual void set_focus(int param_1);
};

static_assert(sizeof(TListPanel) == 0x1A0, "TListPanel Size Mismatch");
static_assert(offsetof(TListPanel, drawHighlightBar) == 0x19C, "TListPanel Offset Mismatch");

