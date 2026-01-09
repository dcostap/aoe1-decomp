#pragma once
#include "common.h"

class TRIBE_Action_Hunt : public RGE_Action {
public:
    int targetType;                          // 0x40

    virtual void save(int param_1);                         // vt0[5]+0x14=0x4CF210
    virtual void first_in_stack(uchar param_1);             // vt0[7]+0x1C=0x4CF240
    virtual uchar update();                                 // vt0[10]+0x28=0x4CF860
    virtual int stop();                                     // vt0[11]+0x2C=0x4CFF90
    virtual int move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // vt0[12]+0x30=0x4CFFD0
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // vt0[13]+0x34=0x4D0080
    virtual void set_state(uchar param_1);                  // vt0[23]+0x5C=0x4CF300
    TRIBE_Action_Hunt(int param_1, RGE_Action_Object* param_2);
    ~TRIBE_Action_Hunt();
    TRIBE_Action_Hunt(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3);
    TRIBE_Action_Hunt(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5);
    RGE_Sprite* get_move_sprite();
    RGE_Sprite* get_wait_sprite();
};

static_assert(sizeof(TRIBE_Action_Hunt) == 0x44, "TRIBE_Action_Hunt Size Mismatch");

