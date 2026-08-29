#ifndef AOE1_TACTION_H
#define AOE1_TACTION_H


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
