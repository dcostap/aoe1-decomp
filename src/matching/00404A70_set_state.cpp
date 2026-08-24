#include "../../include/act_make_context.h"

void RGE_Action_Make::set_state(unsigned char param) {
    this->state = param;
    this->timer = this->obj->owner->attributes[0x24];
}
