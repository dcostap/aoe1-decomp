// VA: 00402F40 RGE_Action_Gather::RGE_Action_Gather
// PDB source: ACT_GATH.cpp.  The shared module context owns the class ABI.

#ifndef ACT_GATH_CONTEXT_H
#include "../../include/act_gath_context.h"
#endif

RGE_Action_Gather::RGE_Action_Gather(RGE_Action_Object* object, RGE_Task* task,
                                     RGE_Static_Object* target)
    : RGE_Action(object, 1) {
    this->task = task;
    this->action_type = 5;
    this->set_target_obj(target);
    if (target != 0) {
        this->target_x = target->world_x;
        this->target_y = target->world_y;
        this->target_z = target->world_z;
        this->targetType = target->master_obj->id;
    }
}
