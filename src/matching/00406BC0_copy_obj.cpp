#include "../../include/act_obj_context.h"

void RGE_Action_Object::copy_obj(RGE_Master_Static_Object* master_obj) {
    this->actions->copy_obj(master_obj);
    RGE_Moving_Object::copy_obj(master_obj);
}
