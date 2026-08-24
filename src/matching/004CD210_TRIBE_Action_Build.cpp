// VA: 004CD210 TRIBE_Action_Build::TRIBE_Action_Build (EH-framed, ret 0Ch)
// PDB source: tact_bld.cpp
// BINARY NOTE: The canonical action and object members reproduce the delayed
// derived-vtable store, task store, owner check, and coordinate loads.

class RGE_Action_Object;
class RGE_Task;
class RGE_Static_Object;

#ifndef TACT_BLD_CONTEXT_H
class RGE_Action {
public:
    virtual ~RGE_Action();
    RGE_Action(void* obj, int flag);
    void set_target_obj(void* obj);
};

class TRIBE_Action_Build : public RGE_Action {
public:
    TRIBE_Action_Build(RGE_Action_Object* action_obj, RGE_Task* task, RGE_Static_Object* target);
};
#endif

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
