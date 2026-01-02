#pragma once
#include "../common.h"

class TRIBE_Victory_Conditions : public RGE_Victory_Conditions {
public:

    TRIBE_Victory_Conditions(RGE_Player* param_1, int param_2, long* param_3, uchar param_4);
    TRIBE_Victory_Conditions(RGE_Player* param_1);
    virtual ~TRIBE_Victory_Conditions();
    virtual void handle_condition(RGE_Victory_Entry* param_1);
    virtual void handle_tech(RGE_Victory_Entry* param_1);
    virtual uchar add_tech(uchar param_1, long param_2);
};

static_assert(sizeof(TRIBE_Victory_Conditions) == 0x20, "TRIBE_Victory_Conditions Size Mismatch");

