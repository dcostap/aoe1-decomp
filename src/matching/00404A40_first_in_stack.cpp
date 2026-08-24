#include "../../include/act_make_context.h"

void RGE_Action_Make::first_in_stack(unsigned char) {
    short attribute_type;

    this->set_state(6);
    attribute_type = this->task->attribute_type;
    if (attribute_type >= 0 && this->obj->attribute_type_held != attribute_type) {
        this->obj->set_attribute(attribute_type, 0);
    }
}
