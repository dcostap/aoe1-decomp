#ifndef AOE1_TACTION_H
#define AOE1_TACTION_H

// Authentic declaration surface for C:\\msdev\\work\\age1_x1\\TACTION.cpp.
//
// Binary evidence:
// - RGE_Action's vtable at 0056E6D0 has one-argument setup at +04,
//   two-argument setup at +08, and create_action_list at +0C.
// - RGE_Action::obj is at +08.  The TACTION create helper reads this->obj.
// - RGE_Action_List is 0x0C bytes.  Its constructor stores obj at +04 and
//   clears list at +08.  TRIBE_Action_List uses that constructor.
// - TRIBE_Action's vtable at 005753E0 has the same first three override slots.
//
// Shared action and action-list bases are owned by their canonical headers.

#include "action.h"
#include "act_list.h"

class TRIBE_Action_List : public RGE_Action_List {
public:
    TRIBE_Action_List(RGE_Action_Object*);
};

class TRIBE_Action : public RGE_Action {
public:
    TRIBE_Action(int, RGE_Action_Object*, int);
    TRIBE_Action(RGE_Action_Object*, int);

    virtual int setup(int, RGE_Action_Object*);
    virtual int setup(RGE_Action_Object*);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object*);
};

#endif
