#pragma once
#include "common.h"
#include "RGE_Scenario_Header.h"

class TRIBE_Scenario_Header : public RGE_Scenario_Header {
public:
    // Virtuals (best-effort)
    virtual long get_size(); // vt[0] (0x0)
    virtual void save(int param_1); // vt[1] (0x4)

    int any_sp_victory;
    int active_player_count;
};
static_assert(sizeof(TRIBE_Scenario_Header) == 0x1C, "Size mismatch");
