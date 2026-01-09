#pragma once
#include "common.h"

class RGE_Action_Transport : public RGE_Action {
public:

    virtual void first_in_stack(uchar param_1);             // vt0[7]+0x1C=0x406E00
    virtual uchar update();                                 // vt0[10]+0x28=0x406F90
    virtual int stop();                                     // vt0[11]+0x2C=0x407160
    virtual int move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // vt0[12]+0x30=0x407170
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // vt0[13]+0x34=0x4071A0
    virtual void set_state(uchar param_1);                  // vt0[23]+0x5C=0x406E50
    virtual int next_to_drop_off_terrain();                 // vt0[24]+0x60=0x4072B0
    RGE_Action_Transport(int param_1, RGE_Action_Object* param_2);
    ~RGE_Action_Transport();
    RGE_Action_Transport(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5);
    int targetZone();
};

static_assert(sizeof(RGE_Action_Transport) == 0x40, "RGE_Action_Transport Size Mismatch");

