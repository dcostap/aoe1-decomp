#pragma once
#include "../common.h"

class TRIBE_Action_List : public RGE_Action_List {
public:

    TRIBE_Action_List(RGE_Action_Object* param_1);
    virtual RGE_Action* create_action(int param_1, short param_2);
    virtual RGE_Action* create_task_action(RGE_Task* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5);
    virtual void get_action_name(char* param_1);
};

static_assert(sizeof(TRIBE_Action_List) == 0xC, "TRIBE_Action_List Size Mismatch");

