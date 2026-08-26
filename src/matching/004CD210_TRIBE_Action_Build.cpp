// VA: 004CD210 TRIBE_Action_Build::TRIBE_Action_Build (EH-framed, ret 0Ch)
// PDB source: tact_bld.cpp
// BINARY NOTE: The canonical action and object members reproduce the delayed
// derived-vtable store, task store, owner check, and coordinate loads.

TRIBE_Action_Build::TRIBE_Action_Build(RGE_Action_Object* action_obj, RGE_Task* task, RGE_Static_Object* target)
    : RGE_Action(action_obj, 1)
{
    this->action_type = 0x65;
    this->task = task;

    if (!target || action_obj->owner->id == target->owner->id) {
        this->set_target_obj(target);
        this->target_x = target->world_x;
        this->target_y = target->world_y;
        this->target_z = target->world_z;
    }
}
