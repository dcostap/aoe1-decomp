#include "../../include/act_obj_context.h"

void RGE_Action_Object::transform(RGE_Master_Static_Object* master) {
    RGE_Moving_Object::transform(master);
    this->actions->delete_list();
}
