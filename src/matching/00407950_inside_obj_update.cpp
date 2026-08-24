#include "../../include/action_context.h"

unsigned char RGE_Action::inside_obj_update()
{
    if (this->target_obj != 0 && this->target_obj->object_state >= 7) {
        this->set_target_obj((RGE_Static_Object*)0);
    }
    if (this->target_obj2 != 0 && this->target_obj2->object_state >= 7) {
        this->set_target_obj2((RGE_Static_Object*)0);
    }
    return 1;
}
