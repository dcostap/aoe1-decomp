#pragma once
#include "../common.h"
#include "diam_map.h"
#include "Pnl_scr.h"
#include "Shape.h"
#include "tvw_main.h"
#include "tvw_dmap.h"

class RGE_Diamond_Map_View : public RGE_Diamond_Map {
public:

    RGE_Diamond_Map_View();
    virtual ~RGE_Diamond_Map_View();
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5);
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_move_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_down_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_move_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_up_action(long param_1, long param_2, int param_3, int param_4);
    virtual void draw();
    virtual int command_make_do(long param_1, long param_2);
    virtual int command_make_move(long param_1, long param_2);
    virtual int command_make_work(long param_1, long param_2);
};

static_assert(sizeof(RGE_Diamond_Map_View) == 0x16C, "RGE_Diamond_Map_View Size Mismatch");

