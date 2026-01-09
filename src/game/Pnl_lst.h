#pragma once
#include "common.h"

enum ActionType : unsigned int {
    ActionItem = 1,
    ActionLand = 2,
    ActionSelect = 3,
};

class TListPanel : public TTextPanel {
public:
    int auto_track;                          // 0x188
    ulong mouse_scroll_last_time;            // 0x18C
    ulong mouse_scroll_interval;             // 0x190
    int mouse_scroll_up;                     // 0x194
    int mouse_scroll_down;                   // 0x198
    int drawHighlightBar;                    // 0x19C

    virtual void draw();                                    // vt0[12]+0x30=0x478BA0
    virtual long handle_idle();                             // vt0[19]+0x4C=0x4783F0
    virtual long mouse_move_action(long param_1, long param_2, int param_3, int param_4); // vt0[32]+0x80=0x4784A0
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4); // vt0[33]+0x84=0x478510
    virtual long mouse_left_move_action(long param_1, long param_2, int param_3, int param_4); // vt0[35]+0x8C=0x478540
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4); // vt0[36]+0x90=0x478610
    virtual long mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4); // vt0[37]+0x94=0x478660
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5); // vt0[43]+0xAC=0x478730
    virtual long char_action(long param_1, short param_2);  // vt0[44]+0xB0=0x478850
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt0[45]+0xB4=0x478900
    virtual void set_focus(int param_1);                    // vt0[48]+0xC0=0x478EF0
    virtual void set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7); // vt0[59]+0xEC=0x478350
    TListPanel();
    ~TListPanel();
    void set_auto_track(int param_1);
    short item_at(long param_1, long param_2);
    void goto_item(long param_1, long param_2);
    void scroll_cur_line(uchar param_1, short param_2, int param_3);
    void draw_highlight_bar();
    void setDrawHighlightBar(int param_1);
};

static_assert(sizeof(TListPanel) == 0x1A0, "TListPanel Size Mismatch");

