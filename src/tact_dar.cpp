
#include "../include/tact_dar.h"
#include "../include/act_obj.h"
#include "../include/stat_obj.h"
#include "../include/m_s_obj.h"
#include "../include/map.h"
#include "../include/world.h"
#include "../include/obj_list.h"
#include "../include/player.h"
#include "../include/rge_fio.h"
#include "../include/game_globals.h"
#include <stdlib.h>

TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(int infile, RGE_Action_Object* obj_in) :
    RGE_Action(infile, obj_in, 1) {
    this->action_type = TRIBE_ACTION_TYPE_DISCOVERY_ARTIFACT;
    this->flags = (unsigned char*) calloc(this->obj->owner->world->player_num, 1);
    rge_read(infile, this->flags, this->obj->owner->world->player_num);
}

TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(
    RGE_Action_Object* obj_in, RGE_Task* task_in, RGE_Static_Object* target_obj_in
) : RGE_Action(obj_in, 1) {
    this->task = task_in;
    this->action_type = TRIBE_ACTION_TYPE_DISCOVERY_ARTIFACT;
    RGE_Action::set_target_obj(target_obj_in);
    this->flags = (unsigned char*) calloc(this->obj->owner->world->player_num, 1);
}

TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(
    RGE_Action_Object* obj_in, RGE_Task* task_in, float x, float y, float z
) : RGE_Action(obj_in, 1) {
    this->task = task_in;
    this->action_type = TRIBE_ACTION_TYPE_DISCOVERY_ARTIFACT;
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->flags = (unsigned char*) calloc(this->obj->owner->world->player_num, 1);
}

void TRIBE_Action_Discovery_Artifact::save(int outfile) {
    int size;

    RGE_Action::save(outfile);
    size = this->obj->owner->world->player_num;
    rge_write(outfile, this->flags, size);
}

void TRIBE_Action_Discovery_Artifact::first_in_stack(unsigned char first_time) {
    if (first_time != 0) {
        this->set_state(6);
    }
}

void TRIBE_Action_Discovery_Artifact::set_state(unsigned char new_state) {
    this->state = new_state;
    if (new_state == 10) {
        this->timer = 3.0f;
    }
}

unsigned char TRIBE_Action_Discovery_Artifact::update() {
    switch (this->state) {
        case 1:
            return RGE_ACTION_UPDATE_REMOVE;

        case 6:
            this->check_objects();
            this->set_state(10);
            break;

        case 10:
            float timer = this->timer - this->obj->owner->world->world_time_delta_seconds;
            if (timer <= g_discovery_artifact_timer_threshold) {
                this->timer = timer;
                this->set_state(6);
            } else {
                this->timer = timer;
            }
            break;
    }

    return RGE_ACTION_UPDATE_CONTINUE;
}

void TRIBE_Action_Discovery_Artifact::check_objects() {
    RGE_Action_Object* obj = this->obj;
    RGE_Master_Static_Object* master = obj->master_obj;

    short x1 = (short) (obj->world_x - g_discovery_artifact_scan_lower_adjustment - master->radius_x);
    short map_y = (short) (obj->world_y - g_discovery_artifact_scan_lower_adjustment - master->radius_y);
    short x0 = (short) (master->radius_x + obj->world_x - g_discovery_artifact_scan_upper_adjustment);
    short y0 = (short) (master->radius_y + obj->world_y - g_discovery_artifact_scan_upper_adjustment);

    RGE_Map* map = obj->owner->world->map;

    if (x1 < 0) {
        x1 = 0;
    }
    if (map_y < 0) {
        map_y = 0;
    }
    if (x0 >= map->map_width) {
        x0 = (short) map->map_width - 1;
    }
    if (y0 >= map->map_height) {
        y0 = (short) map->map_height - 1;
    }

    for (short y = map_y; y <= y0; ++y) {
        for (short x = x1; x <= x0; ++x) {
            RGE_Object_Node* node = map->map_row_offset[y][x].objects.list;
            while (node != 0) {
                //! @bug This award loop filters no object state and no object group.
                //! Ghost copies in the tile lists therefore count as real finds.
                //! The flags reset when the action rebuilds, so one find can award twice.
                if (node->node->owner != this->obj->owner && this->flags[node->node->owner->id] == 0) {
                    this->flags[node->node->owner->id] = 1;
                    node->node->owner->master_objects[162]->make_new_obj(
                        node->node->owner, node->node->world_x, node->node->world_y, node->node->world_z
                    );
                }
                node = node->next;
            }
        }
    }
}
