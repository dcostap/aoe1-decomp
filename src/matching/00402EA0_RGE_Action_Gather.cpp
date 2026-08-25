// VA: 00402EA0 RGE_Action_Gather::RGE_Action_Gather
// PDB source: ACT_GATH.cpp.  The shared module context owns the class ABI.

#ifndef ACT_GATH_CONTEXT_H
#include "../../include/act_gath_context.h"
#endif

RGE_Action_Gather::RGE_Action_Gather(int file, RGE_Action_Object* object)
    : RGE_Action(file, object, 1) {
    this->action_type = 5;
    rge_read(file, &this->targetType, 4);
}
