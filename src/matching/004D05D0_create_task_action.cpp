// VA: 004D05D0 TRIBE_Action_List::create_task_action
// PDB source: tact_lst.cpp:93-156
// FLAGS: config\flags\004D05D0_create_task_action.rsp (/GX)
// BINARY NOTE: Task action selection reads action_type at RGE_Task +0x6 and
// keeps separate target and coordinate constructor paths.

#include "../../include/tact_lst_context.h"

RGE_Action* TRIBE_Action_List::create_task_action(
    RGE_Task* task,
    RGE_Static_Object* target,
    float x,
    float y,
    float z)
{
    switch (task->action_type) {
    case 0x65:
        if (target != 0)
            return new TRIBE_Action_Build(this->obj, task, target);
        return new TRIBE_Action_Build(this->obj, task, x, y, z);
    case 0x68:
        if (target != 0)
            return new TRIBE_Action_Convert(this->obj, task, target);
        return new TRIBE_Action_Convert(this->obj, task, x, y, z);
    case 0x69:
        if (target != 0)
            return new TRIBE_Action_Heal(this->obj, task, target);
        return new TRIBE_Action_Heal(this->obj, task, x, y, z);
    case 0x6B:
        if (target != 0)
            return new TRIBE_Action_Artifact(this->obj, task, target);
        return new TRIBE_Action_Artifact(this->obj, task, x, y, z);
    case 0x78:
        return new TRIBE_Action_Wonder(this->obj);
    case 0x6C:
        if (target != 0)
            return new TRIBE_Action_Discovery_Artifact(this->obj, task, target);
        return new TRIBE_Action_Discovery_Artifact(this->obj, task, x, y, z);
    case 0x6E:
        if (target != 0)
            return new TRIBE_Action_Hunt(this->obj, task, target);
        return new TRIBE_Action_Hunt(this->obj, task, x, y, z);
    case 0x6A:
        if (target != 0)
            return new TRIBE_Action_Repair(this->obj, task, target);
        return new TRIBE_Action_Repair(this->obj, task, x, y, z);
    case 0x6F:
        if (target != 0)
            return new TRIBE_Action_Trade(this->obj, task, target);
        return new TRIBE_Action_Trade(this->obj, task, x, y, z);
    case 3:
        return new RGE_Action_Enter(this->obj, task, (RGE_Action_Object*)target);
    case 0x0C:
        return new RGE_Action_Transport(this->obj, task, x, y, z);
    default:
        return RGE_Action_List::create_task_action(task, target, x, y, z);
    }
}
