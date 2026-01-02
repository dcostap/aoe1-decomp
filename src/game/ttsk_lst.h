#pragma once
#include "../common.h"

class TRIBE_Task_List {
public:
    char _pad_0x0[0xC];

    virtual RGE_Task* get_target_task(RGE_Action_Object* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5);
    virtual int is_attack_task(RGE_Task* param_1);
};

static_assert(sizeof(TRIBE_Task_List) == 0xC, "TRIBE_Task_List Size Mismatch");

