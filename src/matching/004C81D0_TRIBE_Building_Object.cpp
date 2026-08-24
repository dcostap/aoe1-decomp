// VA: 004C81D0 TRIBE_Building_Object::TRIBE_Building_Object
// PDB source: t_b_obj.cpp:117-124
// Baseline: natural three-argument constructor with the proven production
// queue layout, base constructor, setup gate, and doppleganger registration.

#include "../../include/t_b_obj_context.h"

TRIBE_Building_Object::TRIBE_Building_Object(int mode, RGE_Game_World* world,
                                             int do_setup)
    : TRIBE_Combat_Object(mode, world, 0)
{
    this->production_queue = 0;
    this->production_queue_size = 0;
    this->production_queue_count = 0;
    this->production_queue_enabled = 1;
    this->production_queue_actions = 0;
    this->production_queue_change_flag = 0;
    this->production_queue_auto_paused = 0;
    this->production_queue_need_attr = -1;
    this->DoppleInstalled = 0;
    if (do_setup != 0) {
        this->setup(mode, world);
    }

    int row = (int)this->world_y;
    int col = (int)this->world_x;
    this->DoppleInstalled = this->owner->doppleganger_creator->add_doppleganger_check(
        this, unified_map_offsets[row] + col);
}
