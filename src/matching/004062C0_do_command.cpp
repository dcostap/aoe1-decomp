#include "../../include/act_obj_context.h"

void RGE_Action_Object::do_command(RGE_Static_Object* target, float x, float y, float z) {
    if ((void*)target != (void*)this) {
        this->work2(target, x, y, z, 0);
        this->command_flag = this->command_flag + 1;
    }
}
