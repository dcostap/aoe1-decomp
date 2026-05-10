// TRIBE_Action_Repair::TRIBE_Action_Repair
// VA: 004D1720
// PDB source: tact_rep.cpp
// Attempt log:
// - Previous file was only a stub and produced a 16-byte body.
// - 2026-05-10 StarryZephyr pass: implemented natural /GX constructor with base ctor, vptr/type stores, target object, and meet_target.

class RGE_Action_Object;
class RGE_Task;

class RGE_Static_Object {
public:
    char gap_00[0x38];
    int world_x;
    int world_y;
    int world_z;
};

class RGE_Action {
public:
    RGE_Action(RGE_Action_Object* obj, int action_id);
    virtual ~RGE_Action();
    void set_target_obj(RGE_Static_Object* target);
};

class TRIBE_Action_Repair : public RGE_Action {
public:
    char gap_04[0x20 - 0x04];
    int target_x;
    int target_y;
    int target_z;
    char gap_2C[4];
    RGE_Task* task;
    char gap_34[0x40 - 0x34];
    unsigned char save_target_command_flag;

    TRIBE_Action_Repair(RGE_Action_Object* obj, RGE_Task* task, RGE_Static_Object* target);
    void meet_target();
};

extern void* const TRIBE_Action_Repair_vftable;

TRIBE_Action_Repair::TRIBE_Action_Repair(RGE_Action_Object* obj, RGE_Task* task_arg, RGE_Static_Object* target)
    : RGE_Action(obj, 1)
{
    this->task = task_arg;
    *(void**)this = (void*)&TRIBE_Action_Repair_vftable;
    *(short*)((char*)this + 4) = 0x6A;
    this->save_target_command_flag = 0;
    this->set_target_obj(target);
    if (target != 0) {
        this->target_x = target->world_x;
        this->target_y = target->world_y;
        this->target_z = target->world_z;
        this->meet_target();
    }
}
