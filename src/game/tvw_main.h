#pragma once
#include "../common.h"

class TRIBE_Main_View {
public:
    char _pad_0x4[0x37C];

    virtual ~TRIBE_Main_View();
    virtual void draw_multi_object_outline();
    virtual int draw_wall_outline(long param_1, long param_2, TRIBE_Master_Building_Object* param_3, long param_4);
    virtual int command_place_object(long param_1, long param_2, int param_3);
    virtual int command_place_multi_object(long param_1, long param_2, long param_3, long param_4, int param_5);
    virtual void place_line_of_walls(TRIBE_Player* param_1, TRIBE_Master_Building_Object* param_2, int param_3, int param_4, int param_5, int param_6);
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_up_action(long param_1, long param_2, int param_3, int param_4);
    virtual int pick_through_fog(RGE_Static_Object* param_1);
    virtual int pick_weight(RGE_Static_Object* param_1, int param_2);
    virtual int command_make_do(long param_1, long param_2, int param_3, short param_4);
    virtual long mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4);
};

static_assert(sizeof(TRIBE_Main_View) == 0x380, "TRIBE_Main_View Size Mismatch");

