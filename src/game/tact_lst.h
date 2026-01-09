#pragma once
#include "common.h"

class TRIBE_Action_List : public RGE_Action_List {
public:

    virtual RGE_Action* create_action(int param_1, short param_2); // vt0[0]+0x0=0x4D0170
    virtual RGE_Action* create_task_action(RGE_Task* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5); // vt0[1]+0x4=0x4D05D0
    virtual void get_action_name(char* param_1);            // vt0[4]+0x10=0x4D0C50
    TRIBE_Action_List(RGE_Action_Object* param_1);
};

static_assert(sizeof(TRIBE_Action_List) == 0xC, "TRIBE_Action_List Size Mismatch");

