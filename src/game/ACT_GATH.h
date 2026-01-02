#pragma once
#include "../common.h"

class RGE_Action_Gather : public RGE_Action {
public:
    int targetType;                          // 0x40

    RGE_Action_Gather(int param_1, RGE_Action_Object* param_2);
    virtual ~RGE_Action_Gather();
    RGE_Action_Gather(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3);
    RGE_Action_Gather(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5);
    virtual void save(int param_1);
    virtual void first_in_stack(uchar param_1);
    virtual void set_state(uchar param_1);
    virtual uchar update();
    virtual RGE_Sprite* get_move_sprite();
    virtual RGE_Sprite* get_wait_sprite();
    virtual int stop();
    virtual int move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
};

static_assert(sizeof(RGE_Action_Gather) == 0x44, "RGE_Action_Gather Size Mismatch");
static_assert(offsetof(RGE_Action_Gather, targetType) == 0x40, "RGE_Action_Gather Offset Mismatch");

