
#include "../include/taction.h"

TRIBE_Action::TRIBE_Action(int infile, RGE_Action_Object* obj_in, int do_setup) : RGE_Action(infile, obj_in, 0) {
    if (do_setup != 0) {
        setup(infile, obj_in);
    }
}

TRIBE_Action::TRIBE_Action(RGE_Action_Object* obj_in, int do_setup) : RGE_Action(obj_in, 0) {
    if (do_setup != 0) {
        setup(obj_in);
    }
}

int TRIBE_Action::setup(int infile, RGE_Action_Object* obj_in) {
    return RGE_Action::setup(infile, obj_in);
}

int TRIBE_Action::setup(RGE_Action_Object* obj_in) {
    return RGE_Action::setup(obj_in);
}

RGE_Action_List* TRIBE_Action::create_action_list(RGE_Action_Object* obj_in) {
    return new TRIBE_Action_List(this->obj);
}
