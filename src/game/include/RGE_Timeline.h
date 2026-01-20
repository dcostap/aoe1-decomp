#pragma once
#include "common.h"

class RGE_Timeline {
public:
    // Virtuals (best-effort)
    virtual ~RGE_Timeline(); // vt[0] (0x0)

    RGE_Game_World* world;
    RGE_Time_Entry* time_list;
    short list_num;
    short avail_id;
    float old_time;
};
static_assert(sizeof(RGE_Timeline) == 0x14, "Size mismatch");
