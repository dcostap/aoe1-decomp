#include "../../include/t_b_obj_context.h"

void TRIBE_Building_Object::rehook() {
    RGE_Action_Object::rehook();
    this->production_queue_actions->rehook();
}
