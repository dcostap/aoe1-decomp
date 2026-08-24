// RGE_Action::create_action_list
// The EH-aware allocation and constructor call use the module's custom VC5
// response file.

#include "../../include/action_context.h"

RGE_Action_List* RGE_Action::create_action_list(RGE_Action_Object*) {
    return new RGE_Action_List(this->obj);
}
