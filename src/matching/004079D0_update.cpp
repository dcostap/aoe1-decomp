#include "../../include/action_context.h"

unsigned char RGE_Action::update()
{
    if (this->target_obj != 0 && this->target_obj->object_state >= 7)
        this->set_target_obj((RGE_Static_Object*)0);

    if (this->target_obj2 != 0 && this->target_obj2->object_state >= 7)
        this->set_target_obj2((RGE_Static_Object*)0);

    if (this->sub_actions->list != 0)
        return this->sub_actions->update();

    if (this->state != 1)
        return 0;

    return 1;
}
