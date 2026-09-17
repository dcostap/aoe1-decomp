
#include "../include/tact_wnd.h"
#include "../include/act_list.h"
#include "../include/act_obj.h"
#include "../include/basegame.h"
#include "../include/m_ac_obj.h"
#include "../include/m_s_obj.h"
#include "../include/move_obj.h"
#include "../include/obj_list.h"
#include "../include/player.h"
#include "../include/rge_base_game_global.h"
#include "../include/stat_obj.h"
#include "../include/world.h"

static const float LIMIT = 2000.0f;

TRIBE_Action_Wonder::TRIBE_Action_Wonder(int infile, RGE_Action_Object* obj_in)
    : RGE_Action(infile, obj_in, 1) {
    this->action_type = 0x78;
}

TRIBE_Action_Wonder::TRIBE_Action_Wonder(RGE_Action_Object* obj_in)
    : RGE_Action(obj_in, 1) {
    this->action_type = 0x78;
    this->timer = 0.0f;
}

TRIBE_Action_Wonder::~TRIBE_Action_Wonder() {
    RGE_Game_World* world = rge_base_game->world;

    if (world->game_state == 0) {
        RGE_Player** players = world->players;
        int player_num = (int)world->player_num;

        if (this->state == 2) {
            RGE_Player** current = players;
            int i = 1;
            if (1 < player_num) {
                ++current;
                do {
                    if (i != this->obj->owner->id) {
                        this->obj->unexplore_terrain(current[0], 1, -1);
                    }
                    ++i;
                    ++current;
                } while (i < player_num);
            }
        }

        if (this->state == 6) {
            RGE_Player** current = players;
            int i = 1;
            if (1 < player_num) {
                ++current;
                do {
                    if (i != this->obj->owner->id) {
                        this->obj->unexplore_terrain(current[0], 0, -1);
                    }
                    ++i;
                    ++current;
                } while (i < player_num);
            }

            if (rge_base_game->world[1].world_time == 0) {
                int found = 0;
                RGE_Player* owner = this->obj->owner;
                RGE_Object_Node* node = owner->objects->list;

                while (node != 0) {
                    RGE_Static_Object* action = node->node;
                    if (action != this->obj) {
                        RGE_Master_Static_Object* master = action->master_obj;
                        if (master->id == 0x114 && action->object_state >= 2) {
                            found = 1;
                            break;
                        }
                    }
                    node = node->next;
                }

                rge_base_game->reset_countdown_timer(owner->id);
                if (found) {
                    rge_base_game->set_countdown_timer(this->obj->owner->id, 2000);
                }
            }
        }

        rge_base_game->notification(0x6E, this->obj->owner->id, (long)this->obj->world_x, (long)this->obj->world_y, 0);
    }
}

void TRIBE_Action_Wonder::first_in_stack(unsigned char first_time) {
    if (first_time != 0) {
        this->set_state(2);
    }
}

void TRIBE_Action_Wonder::set_state(unsigned char new_state) {
    this->state = new_state;

    switch (new_state) {
    case 6: {
        int player_num = (int)rge_base_game->world->player_num;
        RGE_Player** players = rge_base_game->world->players;
        int i = 1;

        if (1 < player_num) {
            ++players;
            do {
                if (i != this->obj->owner->id) {
                    this->obj->unexplore_terrain(players[0], 1, -1);
                    this->obj->explore_terrain(players[0], 0, -1);
                }
                ++i;
                ++players;
            } while (i < player_num);
        }

        if (rge_base_game->world[1].world_time == 0) {
            rge_base_game->set_countdown_timer(this->obj->owner->id, 2000);
        }

        rge_base_game->notification(0x6D, this->obj->owner->id, (long)this->obj->world_x, (long)this->obj->world_y, 0);
        return;
    }

    case 2: {
        int player_num = (int)rge_base_game->world->player_num;
        RGE_Player** players = rge_base_game->world->players;
        int i = 1;

        if (1 < player_num) {
            ++players;
            do {
                if (i != this->obj->owner->id) {
                    this->obj->explore_terrain(players[0], 1, -1);
                }
                ++i;
                ++players;
            } while (i < player_num);
        }

        rge_base_game->notification(0x6C, this->obj->owner->id, (long)this->obj->world_x, (long)this->obj->world_y, 0);
        return;
    }

    default:
        return;
    }
}

unsigned char TRIBE_Action_Wonder::update() {
    switch (this->state) {
    case 6:
        if (this->timer >= LIMIT) return 0;

        {
            float time_delta = this->obj->owner->world->world_time_delta_seconds;
            this->timer = (time_delta + time_delta) + this->timer;

            if (rge_base_game->world[1].world_time != 0) {
                goto cleanup;
            }

            int player_id = this->obj->owner->id;
            rge_base_game->set_countdown_timer(player_id, (int)(LIMIT - this->timer));

            if (this->timer >= LIMIT) {
                RGE_Player* owner = this->obj->owner;
                owner->win_game_now();
                rge_base_game->world->game_end_condition = 100;
            }
        }
        goto cleanup;

    case 2:
        if (this->obj->object_state == 2) {
            this->set_state(6);
            return 0;
        }
        goto cleanup;

cleanup:
        return 0;

    default:
        return 0;
    }
}
