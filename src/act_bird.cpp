// PDB source module: C:\\msdev\\work\\age1_x1\\act_bird.cpp.
// Definitions follow the original source order.
// PDB bands: 00401FE0 (30-32), 00402040 (37-44), 00402080 (48-57),
// 004020C0 (61-87), and 00402180 (91-152).
// Direct owners: Action, action object, player, world, map, sprite, task,
// and master object. Combat is not referenced by this module.

#include "../include/act_bird.h"
#include "../include/act_list.h"
#include "../include/act_move.h"
#include "../include/map.h"
#include "../include/m_ac_obj.h"
#include "../include/player.h"
#include "../include/sprite.h"
#include "../include/stat_obj.h"
#include "../include/task.h"
#include "../include/world.h"

extern int __cdecl debug_rand(char*, int);

RGE_Action_Bird::RGE_Action_Bird(int param_1, RGE_Action_Object* param_2)
    : RGE_Action(param_1, param_2, 1) {
    this->action_type = 10;
}

RGE_Action_Bird::RGE_Action_Bird(
    RGE_Action_Object* param_1,
    RGE_Task* param_2,
    float param_3,
    float param_4,
    float param_5)
    : RGE_Action(param_1, 1) {
    this->task = param_2;
    this->action_type = 10;
    this->target_x = param_3;
    this->target_y = param_4;
    this->target_z = param_5;
}

void RGE_Action_Bird::first_in_stack(unsigned char param_1) {
    if (param_1) {
        RGE_Action_Object* obj;

        obj = this->obj;
        obj->teleport(obj->world_x, obj->world_y, 6.0f);
        this->set_state(3);
        return;
    }

    this->set_state(3);
}

void RGE_Action_Bird::set_state(unsigned char param_1) {
    RGE_Sprite* sprite;

    this->state = param_1;
    switch (param_1) {
    case 6:
        this->timer = (float)((debug_rand((char*)"C:\\msdev\\work\\age1_x1\\act_bird.cpp", 0x4C) * 10) / 0x7FFF + 5);
        sprite = this->task->work_sprite;
        break;

    case 4:
        this->timer = (float)((debug_rand((char*)"C:\\msdev\\work\\age1_x1\\act_bird.cpp", 0x44) * 10) / 0x7FFF + 5);
        sprite = this->task->move_sprite;
        break;

    default:
        this->sub_actions->delete_list();
        return;
    }

    if (sprite != 0) {
        this->obj->new_sprite(sprite);
        return;
    }

    this->obj->new_sprite(this->obj->master_obj->sprite);
}

static const double bird_update_zero = 0.0;

unsigned char RGE_Action_Bird::update(void) {
    RGE_Action_Move_To* move_to;

    if (bird_update_zero < this->timer) {
        this->timer = this->timer - this->obj->owner->world->world_time_delta_seconds;
    }

    switch (this->state) {
    case 4:
        if (this->timer <= bird_update_zero) {
            this->set_state(6);
        }
        if ((((int)this->sub_actions->update()) & 0xFF) - 1 != 0) {
            return 0;
        }
        this->set_state(3);
        return 0;

    case 6:
        if (this->timer <= bird_update_zero) {
            this->set_state(4);
        }
        if ((((int)this->sub_actions->update()) & 0xFF) - 1 != 0) {
            return 0;
        }
        this->set_state(3);
        return 0;

    case 3:
        {
            RGE_Map* map = this->obj->owner->world->map;
            this->target_x = (float)((debug_rand((char*)"C:\\msdev\\work\\age1_x1\\act_bird.cpp", 0x84) * map->map_width) / 0x7FFF);
            this->target_y = (float)((debug_rand((char*)"C:\\msdev\\work\\age1_x1\\act_bird.cpp", 0x85) * map->map_height) / 0x7FFF);
        }
        this->target_z = this->obj->world_z;
        move_to = new RGE_Action_Move_To(this->obj, this->target_x, this->target_y, this->target_z, this->task->work_range, this->obj->sprite);
        if (move_to == 0) {
            this->set_state(3);
            return 0;
        }
        this->sub_actions->add_action(move_to);
        this->set_state(4);
        return 0;

    case 1:
        return 1;
    }

    return 0;
}
