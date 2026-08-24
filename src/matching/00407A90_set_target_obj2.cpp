// RGE_Action::set_target_obj2
// VA: 00407A90
// Target notification uses the reviewed RGE_Static_Object slots +0xC0/+0xC4.

#include "../../include/action_context.h"
#include "../../include/game_globals.h"

void RGE_Action::set_target_obj2(RGE_Static_Object* target)
{
    if (this->target_obj2 && this->target_obj2 != target) {
        RGE_Game_World* world = this->obj->owner->world;
        RGE_Static_Object* old_target = world->object(this->target2ID);
        if (old_target) {
            old_target->release_being_worked_on(this->obj);
        }
    }

    if (this->target_obj2 != target) {
        this->target_obj2 = target;
        if (target) {
            this->target2ID = target->id;
            target->set_being_worked_on(this->obj, this->action_type, 0);
        } else {
            this->target2ID = -1;
        }
    }
}
