#pragma once
#include "common.h"

class TRIBE_Action_Artifact : public RGE_Action {
public:

    virtual void first_in_stack(uchar param_1);             // vt0[7]+0x1C=0x4CCC70
    virtual uchar update();                                 // vt0[10]+0x28=0x4CCDF0
    virtual int stop();                                     // vt0[11]+0x2C=0x4CD120
    virtual int move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // vt0[12]+0x30=0x4CD130
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // vt0[13]+0x34=0x4CD160
    virtual void set_state(uchar param_1);                  // vt0[23]+0x5C=0x4CCCB0
    TRIBE_Action_Artifact(int param_1, RGE_Action_Object* param_2);
    ~TRIBE_Action_Artifact();
    TRIBE_Action_Artifact(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3);
    TRIBE_Action_Artifact(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5);
    RGE_Player* check_ownership();
    void reset_owner();
};

static_assert(sizeof(TRIBE_Action_Artifact) == 0x40, "TRIBE_Action_Artifact Size Mismatch");

