#pragma once
#include "../common.h"

class TRIBE_Action_Discovery_Artifact : public RGE_Action {
public:
    uchar* flags;                            // 0x40

    TRIBE_Action_Discovery_Artifact(int param_1, RGE_Action_Object* param_2);
    virtual ~TRIBE_Action_Discovery_Artifact();
    TRIBE_Action_Discovery_Artifact(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3);
    TRIBE_Action_Discovery_Artifact(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5);
    virtual void save(int param_1);
    virtual void first_in_stack(uchar param_1);
    virtual void set_state(uchar param_1);
    virtual uchar update();
    virtual void check_objects();
};

static_assert(sizeof(TRIBE_Action_Discovery_Artifact) == 0x44, "TRIBE_Action_Discovery_Artifact Size Mismatch");
static_assert(offsetof(TRIBE_Action_Discovery_Artifact, flags) == 0x40, "TRIBE_Action_Discovery_Artifact Offset Mismatch");

