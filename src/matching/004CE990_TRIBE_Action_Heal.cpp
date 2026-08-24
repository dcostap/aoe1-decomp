// 004CE990 TRIBE_Action_Heal::TRIBE_Action_Heal(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*)
// Source: tact_hea.cpp lines 51-59
// Size: 120 bytes, EH-framed (FS:[0] registration)
//
// Attempt log:
// Probe 1: base ctor + member inits + vtable + set_target_obj + world coords, /GX flag

#include "../../include/tact_hea_context.h"
#include "../../include/game_globals.h"

TRIBE_Action_Heal::TRIBE_Action_Heal(RGE_Action_Object* obj, RGE_Task* task, RGE_Static_Object* target)
    : RGE_Action(obj, 1)
{
    this->task = task;
    field_04 = 0x69;
    set_target_obj(target);
    world_x = target->world_x;
    world_y = target->world_y;
    world_z = target->world_z;
}
