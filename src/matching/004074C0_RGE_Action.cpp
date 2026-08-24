#include "../../include/action_context.h"

RGE_Action::RGE_Action(RGE_Action_Object* object, int do_setup) {
    this->targetID = -1;
    this->target2ID = -1;
    if (do_setup) {
        setup(object);
    }
}
