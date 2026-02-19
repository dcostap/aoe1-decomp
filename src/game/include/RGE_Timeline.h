#pragma once
#include "common.h"

struct RGE_Time_Entry;

class RGE_Timeline {
public:
    RGE_Timeline(RGE_Game_World* param_1);
    // Virtuals (best-effort)
    virtual ~RGE_Timeline(); // vt[0] (0x0)
    void update();
    void save(int param_1);

    RGE_Game_World* world;
    RGE_Time_Entry* time_list;
    short list_num;
    short avail_id;
    float old_time;
};
static_assert(sizeof(RGE_Timeline) == 0x14, "Size mismatch");
