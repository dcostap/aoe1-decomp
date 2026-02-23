#pragma once
#include "common.h"

struct RGE_Time_Entry;
class RGE_Static_Object;

class RGE_Timeline {
public:
    RGE_Timeline(RGE_Game_World* param_1);
    RGE_Timeline(int handle, RGE_Game_World* world);
    // Virtuals (best-effort)
    virtual ~RGE_Timeline(); // vt[0] (0x0)
    void update();
    void mock_update(float time);
    void save(int param_1);

    RGE_Time_Entry* add(float time);
    RGE_Time_Entry* add_attack(float time, RGE_Static_Object* this_obj, RGE_Static_Object* target_obj);
    RGE_Time_Entry* add_create(float time, short obj_type, uchar player, float x, float y, float z);
    RGE_Time_Entry* add_move(float time, RGE_Static_Object* this_obj, float x, float y, float z);
    RGE_Time_Entry* add_delete(float time, RGE_Static_Object* this_obj);
    void sub(RGE_Time_Entry* entry);

    RGE_Game_World* world;
    RGE_Time_Entry* time_list;
    short list_num;
    short avail_id;
    float old_time;

private:
    short find_id(RGE_Static_Object* obj);
};
static_assert(sizeof(RGE_Timeline) == 0x14, "Size mismatch");
