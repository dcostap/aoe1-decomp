#pragma once
#include "common.h"

class TRIBE_Action : public RGE_Action {
public:

    virtual int setup(RGE_Action_Object* param_1);          // vt0[1]+0x4=0x4D3A00
    virtual int setup(int param_1, RGE_Action_Object* param_2); // vt0[2]+0x8=0x4D39E0
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* param_1); // vt0[3]+0xC=0x4D3A10
    TRIBE_Action(int param_1, RGE_Action_Object* param_2, int param_3);
    ~TRIBE_Action();
    TRIBE_Action(RGE_Action_Object* param_1, int param_2);
};

static_assert(sizeof(TRIBE_Action) == 0x40, "TRIBE_Action Size Mismatch");

