#pragma once
#include "common.h"

class TRIBE_Action_Repair : public RGE_Action {
public:
    uchar save_target_command_flag;          // 0x40

    virtual int setup(int param_1, RGE_Action_Object* param_2); // vt0[2]+0x8=0x4D1800
    virtual void save(int param_1);                         // vt0[5]+0x14=0x4D1850
    virtual void first_in_stack(uchar param_1);             // vt0[7]+0x1C=0x4D1880
    virtual uchar update();                                 // vt0[10]+0x28=0x4D1BB0
    virtual int stop();                                     // vt0[11]+0x2C=0x4D1F50
    virtual int move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // vt0[12]+0x30=0x4D1F60
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // vt0[13]+0x34=0x4D1FA0
    virtual void set_state(uchar param_1);                  // vt0[23]+0x5C=0x4D18B0
    TRIBE_Action_Repair(int param_1, RGE_Action_Object* param_2, int param_3);
    ~TRIBE_Action_Repair();
    TRIBE_Action_Repair(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3);
    TRIBE_Action_Repair(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5);
    void meet_target();
};

static_assert(sizeof(TRIBE_Action_Repair) == 0x44, "TRIBE_Action_Repair Size Mismatch");

