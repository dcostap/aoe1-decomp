#pragma once
#include "../common.h"

class TRIBE_Action : public RGE_Action {
public:

    TRIBE_Action(int param_1, RGE_Action_Object* param_2, int param_3);
    virtual ~TRIBE_Action();
    TRIBE_Action(RGE_Action_Object* param_1, int param_2);
    virtual int setup(int param_1, RGE_Action_Object* param_2);
    virtual int setup(RGE_Action_Object* param_1);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* param_1);
};

static_assert(sizeof(TRIBE_Action) == 0x40, "TRIBE_Action Size Mismatch");

