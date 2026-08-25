// VA: 004055A0 RGE_Action_Move_To::RGE_Action_Move_To
// PDB source: act_move.cpp

#include <stdlib.h>

#ifndef ACT_MOVE_CANONICAL_TU
#include "../../include/act_move_context.h"
#endif

RGE_Action_Move_To::RGE_Action_Move_To(RGE_Action_Object* obj, float x, float y, float z, float range_val, RGE_Sprite* spr)
    : RGE_Action(obj, 1)
{
    action_type = 1;

    target_x = x;
    target_y = y;
    target_z = z;
    range = range_val;
    sprite = spr;

    if (range_val <= 0.0f)
        range = 0.4f;

    if (spr == 0) {
        RGE_Master_Action_Object* master =
            (RGE_Master_Action_Object*)this->obj->master_obj;
        if (!master->move_sprite)
            sprite = master->sprite;
        else
            sprite = master->move_sprite;
    }
}
