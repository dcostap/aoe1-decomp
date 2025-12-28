#pragma once
#include "../types.h"

struct RGE_Victory_Entry;
struct RGE_Victory_Point_Entry;

class RGE_Victory_Conditions {
public:
    virtual void handle_point_condition(RGE_Victory_Point_Entry *param_1);
    virtual void handle_condition(RGE_Victory_Entry *param_1);
    virtual char *condition_description(RGE_Victory_Entry *param_1);
    virtual void save(int file_ptr);

    // Padding for remaining 63 vtable entries if necessary for size/layout, 
    // but the size is only 32 bytes (including vptr).
    // 32 bytes = 8 dwords. 
    // vptr(0), victory_list(4), list_num(8), player(12), victory(16), 
    // victory_point_list(20), point_list_num(24), tot_victory_points(28)
    // 8 * 4 = 32. Perfect.

    RGE_Victory_Entry *victory_list;
    long list_num;
    class RGE_Player *player;
    uchar victory;
    // 3 bytes padding here by compiler to align to 4 bytes if victory is uchar?
    // Let's check offset of victory_point_list.
    // victory is 16, victory_point_list is 20. Yes, 3 bytes padding.
    RGE_Victory_Point_Entry *victory_point_list;
    long point_list_num;
    long tot_victory_points;

    RGE_Victory_Conditions(class RGE_Player *player);
    ~RGE_Victory_Conditions();
};

static_assert(sizeof(RGE_Victory_Conditions) == 32, "RGE_Victory_Conditions size mismatch");
