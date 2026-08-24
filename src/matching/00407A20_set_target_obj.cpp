// RGE_Action::set_target_obj
// VA: 00407A20
// Target notification uses the reviewed RGE_Static_Object slots +0xC0/+0xC4.

#include "../../include/action_context.h"

void RGE_Action::set_target_obj(RGE_Static_Object* param_1) {
    if (this->target_obj != 0 && this->target_obj != param_1) {
        RGE_Static_Object* previous = this->obj->owner->world->object(this->targetID);
        if (previous != 0) {
            previous->release_being_worked_on(this->obj);
        }
    }

    if (this->target_obj != param_1) {
        this->target_obj = param_1;
        if (param_1 != 0) {
            this->targetID = param_1->id;
            param_1->set_being_worked_on(this->obj, this->action_type, 0);
            return;
        }
        this->targetID = -1;
    }
}
