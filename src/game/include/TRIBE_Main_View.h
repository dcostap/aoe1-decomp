#pragma once

#include "RGE_Main_View.h"

class TRIBE_Player;
class TRIBE_Master_Building_Object;

class TRIBE_Main_View : public RGE_Main_View {
public:
    TRIBE_Main_View();
    virtual ~TRIBE_Main_View();

    virtual void draw_multi_object_outline() override;
    virtual int  command_place_object(long param_1, long param_2, int param_3) override;
    virtual int  command_place_multi_object(long param_1, long param_2, long param_3, long param_4, int param_5) override;
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) override;
    virtual long mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) override;
    virtual long mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) override;
    virtual int  pick_through_fog(RGE_Static_Object* param_1) override;
    virtual int  pick_weight(RGE_Static_Object* param_1, int param_2) override;
    virtual int  command_make_do(long param_1, long param_2, int param_3, short param_4) override;

protected:
    int  draw_wall_outline(long col, long row, TRIBE_Master_Building_Object* master_bldg, long endpoint_flag);
    void place_line_of_walls(TRIBE_Player* player, TRIBE_Master_Building_Object* master_bldg, int col1, int row1, int col2, int row2);
};

static_assert(sizeof(TRIBE_Main_View) == 0x380, "Size mismatch");
