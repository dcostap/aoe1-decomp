#include "../../include/taction_context.h"

RGE_Action_List* TRIBE_Action::create_action_list(RGE_Action_Object*) {
    return new TRIBE_Action_List(this->obj);
}
