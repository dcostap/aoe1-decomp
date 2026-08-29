
#include "../include/taction.h"

TRIBE_Action::TRIBE_Action(int mode, RGE_Action_Object* object, int doSetup)
    : RGE_Action(mode, object, 0) {
    if (doSetup != 0) {
        setup(mode, object);
    }
}

TRIBE_Action::TRIBE_Action(RGE_Action_Object* object, int doSetup)
    : RGE_Action(object, 0) {
    if (doSetup != 0) {
        setup(object);
    }
}

int TRIBE_Action::setup(int mode, RGE_Action_Object* object) {
    return RGE_Action::setup(mode, object);
}

int TRIBE_Action::setup(RGE_Action_Object* object) {
    return RGE_Action::setup(object);
}

RGE_Action_List* TRIBE_Action::create_action_list(RGE_Action_Object*) {
    return new TRIBE_Action_List(this->obj);
}
