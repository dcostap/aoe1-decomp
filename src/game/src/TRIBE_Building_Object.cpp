#include "../include/TRIBE_Building_Object.h"

#include "../include/Production_Queue_Record.h"
#include "../include/RGE_Action_List.h"
#include "../include/RGE_Doppleganger_Creator.h"
#include "../include/RGE_Player.h"
#include "../include/globals.h"

#include <cstdlib>

TRIBE_Building_Object::TRIBE_Building_Object(int param_1, RGE_Game_World* param_2, int param_3)
    : TRIBE_Combat_Object(param_1, param_2, 0) {
    // Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C81D0
    this->production_queue = nullptr;
    this->production_queue_size = 0;
    this->production_queue_count = 0;
    this->production_queue_enabled = 1;
    this->production_queue_actions = nullptr;
    this->production_queue_change_flag = 0;
    this->production_queue_auto_paused = 0;
    this->production_queue_need_attr = -1;
    this->DoppleInstalled = 0;

    if (param_3 != 0) {
        this->setup(param_1, param_2);
    }

    int map_y = (int)this->world_y;
    int map_x = (int)this->world_x;
    this->DoppleInstalled =
        this->owner->doppleganger_creator->add_doppleganger_check(this, unified_map_offsets[map_y] + map_x);
}

int TRIBE_Building_Object::setup(int param_1, RGE_Game_World* param_2) {
    // Source of truth: t_b_obj.cpp.decomp @ 0x004C8490
    TRIBE_Combat_Object::setup(param_1, param_2);
    this->type = 0x50;

    rge_read(param_1, &this->built, 1);
    rge_read(param_1, &this->build_pts, 4);
    rge_read(param_1, &this->unique_build_id, 4);
    rge_read(param_1, &this->culture, 1);

    this->production_queue_actions = RGE_Action_Object::create_action_list();

    if (7.21f <= save_game_version) {
        rge_read(param_1, &this->production_queue_size, 2);
        if (this->production_queue_size > 0) {
            this->production_queue = (Production_Queue_Record*)calloc((int)this->production_queue_size, 4);
            for (short queue_index = 0; queue_index < this->production_queue_size; ++queue_index) {
                rge_read(param_1, &this->production_queue[queue_index], 2);
                rge_read(param_1, &this->production_queue[queue_index].unit_count, 2);
            }
        }

        rge_read(param_1, &this->production_queue_count, 2);
        rge_read(param_1, &this->production_queue_enabled, 1);
        if (this->production_queue_actions != nullptr) {
            this->production_queue_actions->load(param_1);
        }
    }

    return 1;
}
