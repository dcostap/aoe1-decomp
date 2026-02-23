#include "../include/TRIBE_Action_Wonder.h"

#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Object_List.h"
#include "../include/RGE_Object_Node.h"
#include "../include/RGE_Player.h"
#include "../include/TRIBE_World.h"
#include "../include/globals.h"

TRIBE_Action_Wonder::TRIBE_Action_Wonder(int param_1, RGE_Action_Object* param_2) {
    RGE_Action::setup(param_1, param_2);
    this->action_type = 0x78;
}

TRIBE_Action_Wonder::TRIBE_Action_Wonder(RGE_Action_Object* param_1) {
    RGE_Action::setup(param_1);
    this->action_type = 0x78;
    this->timer = 0.0f;
}

TRIBE_Action_Wonder::~TRIBE_Action_Wonder() {
    // Fully verified. Source of truth: tact_wnd.cpp.asm @ 0x004D34F0
    if (rge_base_game == nullptr) {
        return;
    }

    TRIBE_World* world = (TRIBE_World*)rge_base_game->world;
    if (world == nullptr || world->game_state != 0) {
        return;
    }

    RGE_Action_Object* obj = this->obj;
    if (obj == nullptr || obj->owner == nullptr) {
        return;
    }

    const int owner_id = (int)obj->owner->id;
    const int player_num = (int)world->player_num;

    if ((this->state == 2) && (1 < player_num) && (world->players != nullptr)) {
        for (int i = 1; i < player_num; ++i) {
            if (i != owner_id) {
                obj->unexplore_terrain(world->players[i], 1, -1);
            }
        }
    }

    if ((this->state == 6) && (1 < player_num) && (world->players != nullptr)) {
        for (int i = 1; i < player_num; ++i) {
            if (i != owner_id) {
                obj->unexplore_terrain(world->players[i], 0, -1);
            }
        }

        if (world->victory_type == 0) {
            bool other_wonder_active = false;
            if (obj->owner->objects != nullptr) {
                for (RGE_Object_Node* node = obj->owner->objects->list; node != nullptr; node = node->next) {
                    RGE_Static_Object* other = node->node;
                    if (other == nullptr || other == obj) {
                        continue;
                    }
                    if (other->master_obj != nullptr &&
                        (int)other->master_obj->id == 0x114 &&
                        (uchar)other->object_state > 1) {
                        other_wonder_active = true;
                        break;
                    }
                }
            }

            rge_base_game->reset_countdown_timer(owner_id);
            if (other_wonder_active) {
                rge_base_game->set_countdown_timer(owner_id, 2000);
            }
        }
    }

    const long world_x = (long)obj->world_x; // __ftol
    const long world_y = (long)obj->world_y; // __ftol
    rge_base_game->notification(0x6e, owner_id, world_x, world_y, 0);
}

int TRIBE_Action_Wonder::setup(RGE_Action_Object* param_1) { int r = RGE_Action::setup(param_1); this->action_type = 0x78; return r; }
int TRIBE_Action_Wonder::setup(int param_1, RGE_Action_Object* param_2) { int r = RGE_Action::setup(param_1, param_2); this->action_type = 0x78; return r; }
RGE_Action_List* TRIBE_Action_Wonder::create_action_list(RGE_Action_Object* param_1) { return RGE_Action::create_action_list(param_1); }
void TRIBE_Action_Wonder::rehook() { RGE_Action::rehook(); }
void TRIBE_Action_Wonder::save(int param_1) { RGE_Action::save(param_1); }
short TRIBE_Action_Wonder::type() { return this->action_type; }
void TRIBE_Action_Wonder::first_in_stack(uchar param_1) {
    // Fully verified. Source of truth: tact_wnd.cpp.asm @ 0x004D3690
    if (param_1 != 0) {
        this->set_state(2);
    }
}
uchar TRIBE_Action_Wonder::inside_obj_update() { return RGE_Action::inside_obj_update(); }
uchar TRIBE_Action_Wonder::idle_update() { return RGE_Action::idle_update(); }

uchar TRIBE_Action_Wonder::update() {
    // Fully verified. Source of truth: tact_wnd.cpp.asm @ 0x004D3810
    if (this->state == 2) {
        if (this->obj->object_state == 2) {
            this->set_state(6);
            return 0;
        }
    } else if (this->state == 6 && this->timer < 2000.0f) {
        const float dt = this->obj->owner->world->world_time_delta_seconds;
        this->timer = dt + dt + this->timer;

        TRIBE_World* world = (TRIBE_World*)rge_base_game->world;
        if (world->victory_type == 0) {
            const long remaining = (long)(2000.0f - this->timer); // __ftol
            rge_base_game->set_countdown_timer((int)this->obj->owner->id, remaining);

            if (2000.0f <= this->timer) {
                this->obj->owner->win_game_now();
                world->game_end_condition = 'd';
                return 0;
            }
        }
    }

    return 0;
}

int TRIBE_Action_Wonder::stop() { this->set_state(2); return 1; }
int TRIBE_Action_Wonder::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::move_to(param_1, param_2, param_3, param_4); }
int TRIBE_Action_Wonder::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::work(param_1, param_2, param_3, param_4); }
uchar TRIBE_Action_Wonder::attack_response(RGE_Static_Object* param_1) { return RGE_Action::attack_response(param_1); }
uchar TRIBE_Action_Wonder::relation_response(long param_1, uchar param_2) { return RGE_Action::relation_response(param_1, param_2); }
void TRIBE_Action_Wonder::copy_obj(RGE_Master_Action_Object* param_1) { RGE_Action::copy_obj(param_1); }
void TRIBE_Action_Wonder::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) { RGE_Action::copy_obj_sprites(param_1, param_2, param_3); }
void TRIBE_Action_Wonder::get_state_name(char* param_1) { RGE_Action::get_state_name(param_1); }
RGE_Static_Object* TRIBE_Action_Wonder::get_target_obj() { return RGE_Action::get_target_obj(); }
RGE_Static_Object* TRIBE_Action_Wonder::get_target_obj2() { return RGE_Action::get_target_obj2(); }
void TRIBE_Action_Wonder::set_target_obj(RGE_Static_Object* param_1) { RGE_Action::set_target_obj(param_1); }
void TRIBE_Action_Wonder::set_target_obj2(RGE_Static_Object* param_1) { RGE_Action::set_target_obj2(param_1); }
void TRIBE_Action_Wonder::set_state(uchar param_1) {
    // Fully verified. Source of truth: tact_wnd.cpp.asm @ 0x004D36B0
    this->state = param_1;

    if (rge_base_game == nullptr) {
        return;
    }
    TRIBE_World* world = (TRIBE_World*)rge_base_game->world;
    if (world == nullptr || this->obj == nullptr || this->obj->owner == nullptr) {
        return;
    }

    const int owner_id = (int)this->obj->owner->id;
    const int player_num = (int)world->player_num;

    if (param_1 == 2) {
        if (1 < player_num && world->players != nullptr) {
            for (int i = 1; i < player_num; ++i) {
                if (i != owner_id) {
                    this->obj->explore_terrain(world->players[i], 1, -1);
                }
            }
        }

        const long world_x = (long)this->obj->world_x; // __ftol
        const long world_y = (long)this->obj->world_y; // __ftol
        rge_base_game->notification(0x6c, owner_id, world_x, world_y, 0);
        return;
    }

    if (param_1 == 6) {
        if (1 < player_num && world->players != nullptr) {
            for (int i = 1; i < player_num; ++i) {
                if (i != owner_id) {
                    this->obj->unexplore_terrain(world->players[i], 1, -1);
                    this->obj->explore_terrain(world->players[i], 0, -1);
                }
            }
        }

        if (world->victory_type == 0) {
            rge_base_game->set_countdown_timer(owner_id, 2000);
        }

        const long world_x = (long)this->obj->world_x; // __ftol
        const long world_y = (long)this->obj->world_y; // __ftol
        rge_base_game->notification(0x6d, owner_id, world_x, world_y, 0);
        return;
    }
}

