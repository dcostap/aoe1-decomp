#pragma once
#include "common.h"

class RGE_Action_Gather : public RGE_Action {
public:
    int targetType;                          // 0x40

    virtual void save(int param_1);                         // vt0[5]+0x14=0x403020
    virtual void first_in_stack(uchar param_1);             // vt0[7]+0x1C=0x403050
    virtual uchar update();                                 // vt0[10]+0x28=0x403590
    virtual int stop();                                     // vt0[11]+0x2C=0x403CD0
    virtual int move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // vt0[12]+0x30=0x403CE0
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // vt0[13]+0x34=0x403D90
    virtual void set_state(uchar param_1);                  // vt0[23]+0x5C=0x403110
    RGE_Action_Gather(int param_1, RGE_Action_Object* param_2);
    ~RGE_Action_Gather();
    RGE_Action_Gather(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3);
    RGE_Action_Gather(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5);
    RGE_Sprite* get_move_sprite();
    RGE_Sprite* get_wait_sprite();
};

static_assert(sizeof(RGE_Action_Gather) == 0x44, "RGE_Action_Gather Size Mismatch");

