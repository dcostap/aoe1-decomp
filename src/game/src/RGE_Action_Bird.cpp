#include "../include/RGE_Action_Bird.h"

#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action_Move_To.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Task.h"
#include "../include/debug_helpers.h"

#include <new>

namespace {
static const char s_act_bird_cpp[] = "C:\\msdev\\work\\age1_x1\\act_bird.cpp";
}

// Fully verified. Source of truth: act_bird.cpp.decomp @ 0x00401FE0
RGE_Action_Bird::RGE_Action_Bird(int param_1, RGE_Action_Object* param_2) {
    this->setup(param_1, param_2);
}

RGE_Action_Bird::~RGE_Action_Bird() = default;

int RGE_Action_Bird::setup(RGE_Action_Object* param_1) {
    RGE_Action::setup(param_1);
    this->action_type = 10;
    return 1;
}

int RGE_Action_Bird::setup(int param_1, RGE_Action_Object* param_2) {
    RGE_Action::setup(param_1, param_2);
    this->action_type = 10;
    return 1;
}

RGE_Action_List* RGE_Action_Bird::create_action_list(RGE_Action_Object* param_1) { return RGE_Action::create_action_list(param_1); }
void RGE_Action_Bird::rehook() { RGE_Action::rehook(); }
void RGE_Action_Bird::save(int param_1) { RGE_Action::save(param_1); }
short RGE_Action_Bird::type() { return RGE_Action::type(); }
uchar RGE_Action_Bird::inside_obj_update() { return RGE_Action::inside_obj_update(); }
uchar RGE_Action_Bird::idle_update() { return RGE_Action::idle_update(); }
int RGE_Action_Bird::stop() { return RGE_Action::stop(); }
int RGE_Action_Bird::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::move_to(param_1, param_2, param_3, param_4); }
int RGE_Action_Bird::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::work(param_1, param_2, param_3, param_4); }
uchar RGE_Action_Bird::attack_response(RGE_Static_Object* param_1) { return RGE_Action::attack_response(param_1); }
uchar RGE_Action_Bird::relation_response(long param_1, uchar param_2) { return RGE_Action::relation_response(param_1, param_2); }
void RGE_Action_Bird::copy_obj(RGE_Master_Action_Object* param_1) { RGE_Action::copy_obj(param_1); }
void RGE_Action_Bird::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) { RGE_Action::copy_obj_sprites(param_1, param_2, param_3); }
void RGE_Action_Bird::get_state_name(char* param_1) { RGE_Action::get_state_name(param_1); }
RGE_Static_Object* RGE_Action_Bird::get_target_obj() { return RGE_Action::get_target_obj(); }
RGE_Static_Object* RGE_Action_Bird::get_target_obj2() { return RGE_Action::get_target_obj2(); }
void RGE_Action_Bird::set_target_obj(RGE_Static_Object* param_1) { RGE_Action::set_target_obj(param_1); }
void RGE_Action_Bird::set_target_obj2(RGE_Static_Object* param_1) { RGE_Action::set_target_obj2(param_1); }

// Fully verified. Source of truth: act_bird.cpp.decomp @ 0x00402080
void RGE_Action_Bird::first_in_stack(uchar param_1) {
    if (param_1 != 0) {
        this->obj->teleport(this->obj->world_x, this->obj->world_y, 6.0f);
        this->set_state(3);
        return;
    }
    this->set_state(3);
}

// Fully verified. Source of truth: act_bird.cpp.decomp @ 0x004020C0
void RGE_Action_Bird::set_state(uchar param_1) {
    this->state = param_1;

    if (param_1 == 4) {
        int r = debug_rand(s_act_bird_cpp, 0x44);
        this->timer = (float)(((r * 10) / 0x7fff) + 5);

        RGE_Sprite* sprite = this->task->move_sprite;
        if (sprite != nullptr) {
            this->obj->new_sprite(sprite);
            return;
        }

        this->obj->new_sprite(this->obj->master_obj->sprite);
        return;
    }

    if (param_1 != 6) {
        this->sub_actions->delete_list();
        return;
    }

    int r = debug_rand(s_act_bird_cpp, 0x4c);
    this->timer = (float)(((r * 10) / 0x7fff) + 5);

    RGE_Sprite* sprite = this->task->work_sprite;
    if (sprite != nullptr) {
        this->obj->new_sprite(sprite);
        return;
    }

    this->obj->new_sprite(this->obj->master_obj->sprite);
}

// Fully verified. Source of truth: act_bird.cpp.decomp @ 0x00402180
uchar RGE_Action_Bird::update() {
    if (0.0f < this->timer) {
        this->timer = this->timer - this->obj->owner->world->world_time_delta_seconds;
    }

    switch (this->state) {
    case 1:
        return 1;

    case 3: {
        RGE_Map* map = this->obj->owner->world->map;

        int r = debug_rand(s_act_bird_cpp, 0x84);
        this->target_x = (float)((r * (int)map->map_width) / 0x7fff);

        r = debug_rand(s_act_bird_cpp, 0x85);
        this->target_y = (float)((r * (int)map->map_height) / 0x7fff);

        this->target_z = this->obj->world_z;

        RGE_Action_Move_To* move_to = (RGE_Action_Move_To*)operator new(sizeof(RGE_Action_Move_To));
        RGE_Action* action = nullptr;
        if (move_to != nullptr) {
            action = (RGE_Action*)new (move_to)
                RGE_Action_Move_To(this->obj, this->target_x, this->target_y, this->target_z, this->task->work_range, this->obj->sprite);
        }

        if (action == nullptr) {
            this->set_state(3);
            return 0;
        }

        this->sub_actions->add_action(action);
        this->set_state(4);
        return 0;
    }

    case 4: {
        if (this->timer <= 0.0f) {
            this->set_state(6);
        }

        uchar result = this->sub_actions->update();
        if (result == 1) {
            this->set_state(3);
            return 0;
        }
        break;
    }

    case 6: {
        if (this->timer <= 0.0f) {
            this->set_state(4);
        }

        uchar result = this->sub_actions->update();
        if (result == 1) {
            this->set_state(3);
            return 0;
        }
        break;
    }

    default:
        break;
    }

    return 0;
}

