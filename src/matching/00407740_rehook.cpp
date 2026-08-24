#include "../../include/action_context.h"

void RGE_Action::rehook(void) {
    if (this->target_obj != 0) {
        this->target_obj = ((RGE_Static_Object*)this->obj)->get_object_pointer((int)this->target_obj);
        if (this->target_obj != 0) {
            this->target_id = this->target_obj->id;
        }
    }
    if (this->target_obj2 != 0) {
        this->target_obj2 = ((RGE_Static_Object*)this->obj)->get_object_pointer((int)this->target_obj2);
        if (this->target_obj2 != 0) {
            this->target2_id = this->target_obj2->id;
        }
    }
    if (this->sub_actions != 0) {
        this->sub_actions->rehook();
    }
}
