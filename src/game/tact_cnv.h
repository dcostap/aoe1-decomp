#pragma once
#include "common.h"

class TRIBE_Action_Convert : public RGE_Action {
public:
    uchar was_same_owner;                    // 0x40
    float requiredRange;                     // 0x44

    virtual void save(int param_1);                         // vt0[5]+0x14=0x4CDB70
    virtual void first_in_stack(uchar param_1);             // vt0[7]+0x1C=0x4CDBB0
    virtual uchar update();                                 // vt0[10]+0x28=0x4CE070
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4); // vt0[13]+0x34=0x4CE450
    virtual void set_state(uchar param_1);                  // vt0[23]+0x5C=0x4CDE10
    TRIBE_Action_Convert(int param_1, RGE_Action_Object* param_2);
    ~TRIBE_Action_Convert();
    TRIBE_Action_Convert(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3);
    TRIBE_Action_Convert(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5);
    void martyrdom();
};

static_assert(sizeof(TRIBE_Action_Convert) == 0x48, "TRIBE_Action_Convert Size Mismatch");

