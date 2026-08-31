#ifndef AOE1_PNL_SCBR_H
#define AOE1_PNL_SCBR_H

// This header owns TScrollBarPanel.
#include "pnl_lst.h"
#include "drawarea.h"
#include "Shape.h"
#include "color.h"

class TScrollBarPanel : public TPanel {
public:
    enum Orientation { Vertical = 0, Horizontal = 1 };
    enum ActionType {
        ActionUp = 0,
        ActionDown = 1,
        ActionPrior = 2,
        ActionNext = 3,
        ActionPosition = 4
    };

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
    unsigned char item_down;
    unsigned char item_pad_145[3];
    long item_is_down;
    long item_x;
    long item_y;
    unsigned char item_mode;
    unsigned char item_pad_155[3];
    unsigned long item_last_time;
    unsigned long item_hold_interval;
    unsigned long item_down_interval;
    tagRECT up_rect;
    tagRECT down_rect;
    tagRECT tab_rect;
    tagRECT top_rect;
    tagRECT bottom_rect;
    Orientation orientationValue;
    long bevel_type;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    unsigned char bevel_pad_1c2[2];

    TScrollBarPanel();
    virtual ~TScrollBarPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long,
               char*, char*, char*, char*, long, long, TPanel*, long,
               Orientation);
    virtual void set_rect(long, long, long, long);
protected:
    void calc_item_rects();
public:
    void set_tab_pos(long);
    void set_list_len(long, long);
    void set_buttons(TShape*, int, int, int, int);
    void set_bevel_info(int, int, int, int, int, int, int);
    virtual long handle_idle();
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    void scroll(ActionType, long);
    virtual void draw();

protected:
    void draw_border(int, int, tagRECT*);
    void draw_border(int, int, long, long, long, long);
    void draw_back_pic();
    void draw_button_pic(int, int, tagRECT*);
};

typedef char pnl_scbr_tpanel_size_check[(sizeof(TPanel) == 0xF4) ? 1 : -1];
typedef char pnl_scbr_scrollbar_size_check[
    (sizeof(TScrollBarPanel) == 0x1C4) ? 1 : -1];

#endif
