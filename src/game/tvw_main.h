#pragma once
#include "common.h"

class TRIBE_Main_View : public TPanel {
public:
    char _pad_0xF4[0x28C];

    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4); // vt0[36]+0x90=0x52D600
    virtual long mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4); // vt0[37]+0x94=0x52DE40
    virtual long mouse_right_up_action(long param_1, long param_2, int param_3, int param_4); // vt0[41]+0xA4=0x52D970
    virtual int pick_through_fog(RGE_Static_Object* param_1); // vt0[56]+0xE0=0x52DCE0
    virtual int pick_weight(RGE_Static_Object* param_1, int param_2); // vt0[57]+0xE4=0x52DD10
    virtual void draw_multi_object_outline();               // vt0[62]+0xF8=0x52CAF0
    virtual int command_place_object(long param_1, long param_2, int param_3); // vt0[63]+0xFC=0x52D1F0
    virtual int command_make_do(long param_1, long param_2, int param_3, short param_4); // vt0[64]+0x100=0x52DE20
    virtual int command_place_multi_object(long param_1, long param_2, long param_3, long param_4, int param_5); // vt0[67]+0x10C=0x52D320
    ~TRIBE_Main_View();
    int draw_wall_outline(long param_1, long param_2, TRIBE_Master_Building_Object* param_3, long param_4);
    void place_line_of_walls(TRIBE_Player* param_1, TRIBE_Master_Building_Object* param_2, int param_3, int param_4, int param_5, int param_6);
};

static_assert(sizeof(TRIBE_Main_View) == 0x380, "TRIBE_Main_View Size Mismatch");

