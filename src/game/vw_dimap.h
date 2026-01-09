#pragma once
#include "common.h"

class RGE_Diamond_Map_View : public RGE_Diamond_Map {
public:

    virtual void draw();                                    // vt0[12]+0x30=0x53D890
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5); // vt0[28]+0x70=0x53D3B0
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4); // vt0[33]+0x84=0x53D400
    virtual long mouse_left_move_action(long param_1, long param_2, int param_3, int param_4); // vt0[35]+0x8C=0x53D480
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4); // vt0[36]+0x90=0x53D500
    virtual long mouse_right_down_action(long param_1, long param_2, int param_3, int param_4); // vt0[38]+0x98=0x53D620
    virtual long mouse_right_move_action(long param_1, long param_2, int param_3, int param_4); // vt0[40]+0xA0=0x53D6A0
    virtual long mouse_right_up_action(long param_1, long param_2, int param_3, int param_4); // vt0[41]+0xA4=0x53D720
    virtual int command_make_do(long param_1, long param_2); // vt0[61]+0xF4=0x53D8E0
    virtual int command_make_move(long param_1, long param_2); // vt0[62]+0xF8=0x53D970
    virtual int command_make_work(long param_1, long param_2); // vt0[63]+0xFC=0x53DA10
    RGE_Diamond_Map_View();
    ~RGE_Diamond_Map_View();
};

static_assert(sizeof(RGE_Diamond_Map_View) == 0x16C, "RGE_Diamond_Map_View Size Mismatch");

