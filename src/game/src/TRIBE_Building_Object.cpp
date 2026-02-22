#include "../include/TRIBE_Building_Object.h"

#include "../include/RGE_Action_List.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Doppleganger_Creator.h"
#include "../include/globals.h"

#include <new>
#include <stdlib.h>

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C81D0
TRIBE_Building_Object::TRIBE_Building_Object(int param_1, RGE_Game_World* param_2, int param_3)
    : TRIBE_Combat_Object(param_1, param_2, 0) {
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

    // Install doppleganger checks after load/setup.
    int y = (int)this->world_y;
    int x = (int)this->world_x;
    unsigned long* addr = unified_map_offsets[y] + x;
    this->DoppleInstalled = this->owner->doppleganger_creator->add_doppleganger_check(this, addr);
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C82A0
TRIBE_Building_Object::~TRIBE_Building_Object() = default;

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C8490
int TRIBE_Building_Object::setup(int param_1, RGE_Game_World* param_2) {
    int fd = param_1;
    RGE_Game_World* world = param_2;

    TRIBE_Combat_Object::setup(fd, world);
    this->type = 'P';

    rge_read(fd, &this->built, 1);
    rge_read(fd, &this->build_pts, 4);
    rge_read(fd, &this->unique_build_id, 4);
    rge_read(fd, &this->culture, 1);

    this->production_queue_actions = this->create_action_list();

    if (save_game_version >= 7.21f) {
        rge_read(fd, &this->production_queue_size, 2);
        if (this->production_queue_size > 0) {
            this->production_queue = (Production_Queue_Record*)calloc((size_t)this->production_queue_size, sizeof(Production_Queue_Record));
            for (short i = 0; i < this->production_queue_size; ++i) {
                rge_read(fd, &this->production_queue[i].master_id, 2);
                rge_read(fd, &this->production_queue[i].unit_count, 2);
            }
        }

        rge_read(fd, &this->production_queue_count, 2);
        rge_read(fd, &this->production_queue_enabled, 1);
        this->production_queue_actions->load(fd);
    }

    return 1;
}

