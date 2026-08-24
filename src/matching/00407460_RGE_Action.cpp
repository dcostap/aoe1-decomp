#include "../../include/action_context.h"

RGE_Action::RGE_Action(int mode, RGE_Action_Object* object, int doSetup) {
    this->targetID = -1;
    this->target2ID = -1;
    if (doSetup != 0) {
        this->setup(mode, object);
    }
}
