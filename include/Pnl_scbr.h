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
    long setup(TDrawArea* render_area_in, TPanel* parent_panel_in, long x_in, long y_in,
               long wid_in, long hgt_in, char* back_pic_in, char* up_pic_in,
               char* down_pic_in, char* tab_pic_in, long arrowSizeIn, long tabSizeIn,
               TPanel* list_panel_in, long list_len_in, Orientation orientation);
    virtual void set_rect(long x_in, long y_in, long wid_in, long hgt_in);
protected:
    void calc_item_rects();
public:
    void set_tab_pos(long list_num_in);
    void set_list_len(long list_len_in, long list_num_in);
    void set_buttons(TShape* button_pics_in, int back_frame_in, int up_frame_in, int down_frame_in, int tab_frame_in);
    void set_bevel_info(int bevel_type_in, int c1, int c2, int c3, int c4, int c5, int c6);
    virtual long handle_idle();
    virtual long mouse_left_down_action(long x, long y, int ctrl_key, int shift_key);
    virtual long mouse_left_move_action(long x, long y, int ctrl_key, int shift_key);
    virtual long mouse_left_up_action(long x, long y, int ctrl_key, int shift_key);
    void scroll(ActionType action, long val);
    virtual void draw();

protected:
    void draw_border(int button, int down, tagRECT* rect);
    void draw_border(int button, int down, long x1, long y1, long x2, long y2);
    void draw_back_pic();
    void draw_button_pic(int frame, int down, tagRECT* rect);
};

typedef char pnl_scbr_tpanel_size_check[(sizeof(TPanel) == 0xF4) ? 1 : -1];
typedef char pnl_scbr_scrollbar_size_check[
    (sizeof(TScrollBarPanel) == 0x1C4) ? 1 : -1];

#endif
