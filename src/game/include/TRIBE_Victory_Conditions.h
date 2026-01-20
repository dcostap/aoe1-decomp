#pragma once
#include "common.h"
#include "RGE_Victory_Conditions.h"

class TRIBE_Victory_Conditions : public RGE_Victory_Conditions {
public:
    // Virtuals (best-effort)
    virtual void handle_point_condition(RGE_Victory_Point_Entry* param_1); // vt[0] (0x0)
    virtual void handle_condition(RGE_Victory_Entry* param_1); // vt[1] (0x4)
    virtual char* condition_description(RGE_Victory_Entry* param_1); // vt[2] (0x8)
    virtual void save(int param_1); // vt[3] (0xC)

};
static_assert(sizeof(TRIBE_Victory_Conditions) == 0x20, "Size mismatch");
