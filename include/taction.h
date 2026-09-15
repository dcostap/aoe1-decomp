#ifndef AOE1_TACTION_H
#define AOE1_TACTION_H


#include "action.h"
#include "act_list.h"

class TRIBE_Action_List : public RGE_Action_List {
public:
    TRIBE_Action_List(RGE_Action_Object* obj_in);
};

class TRIBE_Action : public RGE_Action {
public:
    TRIBE_Action(int infile, RGE_Action_Object* obj_in, int do_setup);
    TRIBE_Action(RGE_Action_Object* obj_in, int do_setup);

    virtual int setup(int infile, RGE_Action_Object* obj_in);
    virtual int setup(RGE_Action_Object* obj_in);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* obj_in);
};

#endif
