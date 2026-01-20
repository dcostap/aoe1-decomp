#pragma once
#include "common.h"
#include "RGE_Task_List.h"

class TRIBE_Task_List : public RGE_Task_List {
public:
    // Virtuals (best-effort)
    virtual RGE_Task* create_task(short param_1, short param_2); // vt[0] (0x0)
    virtual RGE_Task* get_target_task(RGE_Action_Object* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5); // vt[1] (0x4)
    virtual int is_attack_task(RGE_Task* param_1); // vt[2] (0x8)
    virtual int check_task(RGE_Task* param_1, RGE_Action_Object* param_2, RGE_Static_Object* param_3); // vt[3] (0xC)

};
static_assert(sizeof(TRIBE_Task_List) == 0xC, "Size mismatch");
