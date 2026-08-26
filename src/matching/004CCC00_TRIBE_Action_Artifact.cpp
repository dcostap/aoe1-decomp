#ifndef AOE1_TACT_ART_TU_CONTEXT
#include "../../include/tact_art_context.h"
#endif

TRIBE_Action_Artifact::TRIBE_Action_Artifact(RGE_Action_Object* object, RGE_Task* task, RGE_Static_Object* target)
    : RGE_Action(object, 1) {
    this->action_type = 0x6B;
    this->task = task;
    this->target = target;
}
