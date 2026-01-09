#pragma once
#include "common.h"

class TRIBE_Victory_Conditions : public RGE_Victory_Conditions {
public:

    virtual void handle_condition(RGE_Victory_Entry* param_1); // vt0[1]+0x4=0x52C950
    TRIBE_Victory_Conditions(RGE_Player* param_1, int param_2, long* param_3, uchar param_4);
    TRIBE_Victory_Conditions(RGE_Player* param_1);
    ~TRIBE_Victory_Conditions();
    void handle_tech(RGE_Victory_Entry* param_1);
    uchar add_tech(uchar param_1, long param_2);
};

static_assert(sizeof(TRIBE_Victory_Conditions) == 0x20, "TRIBE_Victory_Conditions Size Mismatch");

