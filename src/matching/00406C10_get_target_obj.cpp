#include "../../include/act_obj_context.h"

RGE_Static_Object* RGE_Action_Object::get_target_obj(void) {
    RGE_Action* action;
    RGE_Static_Object* target_obj;

    action = this->actions->get_action();
    if (action != 0) {
        return action->get_target_obj();
    }
    target_obj = 0;
    return target_obj;
}
