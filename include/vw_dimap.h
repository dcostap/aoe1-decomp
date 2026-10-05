#ifndef AOE1_VW_DIMAP_H
#define AOE1_VW_DIMAP_H

#include "diam_map.h"

class RGE_Diamond_Map_View : public RGE_Diamond_Map {
  public:
    RGE_Diamond_Map_View();

    virtual long handle_mouse_down(unsigned char mouse_button_in, long x, long y, int ctrl_key, int shift_key);
    virtual long mouse_left_down_action(long x, long y, int ctrl_key, int shift_key);
    virtual long mouse_left_move_action(long x, long y, int ctrl_key, int shift_key);
    virtual long mouse_left_up_action(long x, long y, int ctrl_key, int shift_key);
    virtual long mouse_right_down_action(long x, long y, int ctrl_key, int shift_key);
    virtual long mouse_right_move_action(long x, long y, int ctrl_key, int shift_key);
    virtual long mouse_right_up_action(long x, long y, int ctrl_key, int shift_key);
    virtual void draw();

    virtual int command_make_do(long x, long y);
    virtual int command_make_move(long x, long y);
    virtual int command_make_work(long x, long y);

    int right_click2(long, long);
};

typedef char vw_dimap_view_size_check[(sizeof(RGE_Diamond_Map_View) == 0x16C) ? 1 : -1];

#endif
