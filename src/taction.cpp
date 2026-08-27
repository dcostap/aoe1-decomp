// Authentic source module for C:\\msdev\\work\\age1_x1\\TACTION.cpp.
// The definitions follow the PDB source and address order.
//
// 004D3950 is a compiler-generated vector deleting destructor. It is not a
// handwritten owner in this module.

#include "../include/taction.h"

// VA 004D38E0; TACTION.cpp lines 23-26; matching.
TRIBE_Action::TRIBE_Action(int mode, RGE_Action_Object* object, int doSetup)
    : RGE_Action(mode, object, 0) {
    if (doSetup != 0) {
        setup(mode, object);
    }
}

// VA 004D3980; TACTION.cpp lines 31-34; matching.
TRIBE_Action::TRIBE_Action(RGE_Action_Object* object, int doSetup)
    : RGE_Action(object, 0) {
    if (doSetup != 0) {
        setup(object);
    }
}

// VA 004D39E0; TACTION.cpp lines 38-40; matching.
int TRIBE_Action::setup(int mode, RGE_Action_Object* object) {
    return RGE_Action::setup(mode, object);
}

// VA 004D3A00; TACTION.cpp lines 44-46; matching.
int TRIBE_Action::setup(RGE_Action_Object* object) {
    return RGE_Action::setup(object);
}

// VA 004D3A10; TACTION.cpp lines 50-52; matching.
RGE_Action_List* TRIBE_Action::create_action_list(RGE_Action_Object*) {
    return new TRIBE_Action_List(this->obj);
}
