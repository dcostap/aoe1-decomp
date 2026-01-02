#pragma once
#include "../common.h"

class TRIBE_Action_Repair : public RGE_Action {
public:
    uchar save_target_command_flag;          // 0x40

    TRIBE_Action_Repair(int param_1, RGE_Action_Object* param_2, int param_3);
    virtual ~TRIBE_Action_Repair();
    TRIBE_Action_Repair(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3);
    TRIBE_Action_Repair(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5);
    virtual int setup(int param_1, RGE_Action_Object* param_2);
    virtual void save(int param_1);
    virtual void first_in_stack(uchar param_1);
    virtual void set_state(uchar param_1);
    virtual uchar update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual void meet_target();
};

static_assert(sizeof(TRIBE_Action_Repair) == 0x44, "TRIBE_Action_Repair Size Mismatch");
static_assert(offsetof(TRIBE_Action_Repair, save_target_command_flag) == 0x40, "TRIBE_Action_Repair Offset Mismatch");

