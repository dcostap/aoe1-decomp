#pragma once
#include "../common.h"

class RGE_Action_Transport : public RGE_Action {
public:

    RGE_Action_Transport(int param_1, RGE_Action_Object* param_2);
    virtual ~RGE_Action_Transport();
    RGE_Action_Transport(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5);
    virtual void first_in_stack(uchar param_1);
    virtual void set_state(uchar param_1);
    virtual uchar update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual int next_to_drop_off_terrain();
    virtual int targetZone();
};

static_assert(sizeof(RGE_Action_Transport) == 0x40, "RGE_Action_Transport Size Mismatch");

