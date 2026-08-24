#include "../../include/act_obj_context.h"

void RGE_Action_Object::destroy_obj(void) {
    this->actions->delete_list();
    RGE_Static_Object::destroy_obj();
}
