#pragma once
#include "common.h"

class RGE_Victory_Conditions {
public:
    // Virtuals (best-effort)
    virtual void handle_point_condition(RGE_Victory_Point_Entry* param_1); // vt[0] (0x0)
    virtual void handle_condition(RGE_Victory_Entry* param_1); // vt[1] (0x4)
    virtual char* condition_description(RGE_Victory_Entry* param_1); // vt[2] (0x8)
    virtual void save(int param_1); // vt[3] (0xC)

    RGE_Victory_Entry* victory_list;
    long list_num;
    RGE_Player* player;
    unsigned char victory;
    RGE_Victory_Point_Entry* victory_point_list;
    long point_list_num;
    long tot_victory_points;
};
static_assert(sizeof(RGE_Victory_Conditions) == 0x20, "Size mismatch");
