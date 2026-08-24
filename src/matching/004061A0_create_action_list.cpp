#include "../../include/act_obj_context.h"

RGE_Action_List* RGE_Action_Object::create_action_list(void) {
    return new RGE_Action_List(this);
}
