#pragma once
#include "common.h"
#include "RGE_Victory_Conditions.h"

class TRIBE_Victory_Conditions : public RGE_Victory_Conditions {
public:
    TRIBE_Victory_Conditions(RGE_Player* param_1);
    TRIBE_Victory_Conditions(RGE_Player* param_1, int param_2, long* param_3, uchar param_4);

    // Virtuals (best-effort)
    virtual void handle_condition(RGE_Victory_Entry* param_1); // vt[1] (0x4)
    ~TRIBE_Victory_Conditions();

    uchar add_tech(uchar param_1, long param_2);

protected:
    void handle_tech(RGE_Victory_Entry* param_1);
};
static_assert(sizeof(TRIBE_Victory_Conditions) == 0x20, "Size mismatch");
