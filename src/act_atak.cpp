
#include "../include/act_atak.h"
#include "../include/act_list.h"
#include "../include/asp_list.h"
#include "../include/act_move.h"
#include "../include/act_obj.h"
#include "../include/com_obj.h"
#include "../include/m_ac_obj.h"
#include "../include/m_co_obj.h"
#include "../include/move_obj.h"
#include "../include/m_s_obj.h"
#include "../include/player.h"
#include "../include/rge_fio.h"
#include "../include/stat_obj.h"
#include "../include/unit_ai_module.h"
#include "../include/visible.h"
#include "../include/world.h"
#include "../include/map.h"
#include "../include/task.h"
#include "../include/sprite.h"
#include "../include/game_globals.h"

#include <math.h>

RGE_Action_Attack::RGE_Action_Attack(int infile, RGE_Action_Object* obj_in)
    : RGE_Action(infile, obj_in, 1) {
    short short_val;

    this->action_type = 9;
    rge_read(infile, &this->range, 4);
    rge_read(infile, &this->min_range, 4);
    rge_read(infile, &this->missile_id, 2);
    rge_read(infile, &this->fire_missile_at_frame, 2);
    rge_read(infile, &this->need_to_attack, 1);
    rge_read(infile, &this->was_same_owner, 1);
    rge_read(infile, &this->indirect_fire_flag, 1);
    rge_read(infile, &short_val, 2);
    this->move_sprite = this->obj->get_sprite_pointer(short_val);
    rge_read(infile, &short_val, 2);
    this->fight_sprite = this->obj->get_sprite_pointer(short_val);
    rge_read(infile, &short_val, 2);
    this->wait_sprite = this->obj->get_sprite_pointer(short_val);
}

RGE_Action_Attack::RGE_Action_Attack(
    RGE_Action_Object* obj_in, RGE_Static_Object* target_obj_in,
    RGE_Sprite* move_sprite_in, RGE_Sprite* fight_sprite_in,
    RGE_Sprite* wait_sprite_in, float range_in, float min_range_in,
    short missile_id_in, short fire_missile_at_frame_in)
    : RGE_Action(obj_in, 1) {
    this->action_type = 9;
    this->set_target_obj(target_obj_in);
    this->fight_sprite = fight_sprite_in;
    this->wait_sprite = wait_sprite_in;
    this->range = range_in;
    this->min_range = min_range_in;
    this->missile_id = missile_id_in;
    this->target_x = -1.0f;
    this->target_y = -1.0f;
    this->target_z = -1.0f;
    this->move_sprite = move_sprite_in;
    this->fire_missile_at_frame = fire_missile_at_frame_in;
    this->need_to_attack = 0;
    this->indirect_fire_flag = 0;
    if (target_obj_in != 0 && target_obj_in->owner == obj_in->owner) {
        this->was_same_owner = 1;
    } else {
        this->was_same_owner = 0;
    }

    if (move_sprite_in == 0) {
        RGE_Master_Moving_Object* master =
            static_cast<RGE_Master_Moving_Object*>(this->obj->master_obj);
        RGE_Sprite* sprite = master->run_sprite;
        if (sprite == 0) {
            sprite = master->move_sprite;
        }
        this->move_sprite = sprite;
    }
    if (fight_sprite_in == 0) {
        this->fight_sprite =
            static_cast<RGE_Master_Combat_Object*>(this->obj->master_obj)
                ->fight_sprite;
    }
    if (wait_sprite_in == 0) {
        this->wait_sprite = this->obj->master_obj->sprite;
    }
    if (range_in == 0.0f) {
        this->range =
            static_cast<RGE_Master_Combat_Object*>(this->obj->master_obj)
                ->weapon_range;
        if (this->range == 0.0f) {
            this->range = 0.4f;
        }
    }
}

RGE_Action_Attack::RGE_Action_Attack(
    RGE_Action_Object* obj_in, float x, float y, float z,
    RGE_Sprite* move_sprite_in, RGE_Sprite* fight_sprite_in,
    RGE_Sprite* wait_sprite_in, float range_in, float min_range_in,
    short missile_id_in, short fire_missile_at_frame_in)
    : RGE_Action(obj_in, 1) {
    this->target_x = x;
    this->range = range_in;
    this->min_range = min_range_in;
    this->target_z = z;
    this->target_y = y;
    this->missile_id = missile_id_in;
    this->action_type = 9;
    this->move_sprite = move_sprite_in;
    this->fight_sprite = fight_sprite_in;
    this->wait_sprite = wait_sprite_in;
    this->fire_missile_at_frame = fire_missile_at_frame_in;
    this->need_to_attack = 0;
    this->was_same_owner = 0;
    this->indirect_fire_flag = 2;

    if (move_sprite_in == 0) {
        RGE_Master_Moving_Object* master =
            static_cast<RGE_Master_Moving_Object*>(this->obj->master_obj);
        RGE_Sprite* sprite = master->run_sprite;
        if (sprite == 0) {
            sprite = master->move_sprite;
        }
        this->move_sprite = sprite;
    }
    if (fight_sprite_in == 0) {
        this->fight_sprite =
            static_cast<RGE_Master_Combat_Object*>(this->obj->master_obj)
                ->fight_sprite;
    }
    if (wait_sprite_in == 0) {
        this->wait_sprite = this->obj->master_obj->sprite;
    }
    if (range_in == 0.0f) {
        this->range =
            static_cast<RGE_Master_Combat_Object*>(this->obj->master_obj)
                ->weapon_range;
        if (this->range == 0.0f) {
            this->range = 0.4f;
        }
    }
}

RGE_Action_Attack::~RGE_Action_Attack() {
}

void RGE_Action_Attack::save(int outfile) {
    int saved_handle = outfile;
    short short_val;

    RGE_Action::save(outfile);
    rge_write(saved_handle, &this->range, 4);
    rge_write(saved_handle, &this->min_range, 4);
    rge_write(saved_handle, &this->missile_id, 2);
    rge_write(saved_handle, &this->fire_missile_at_frame, 2);
    rge_write(saved_handle, &this->need_to_attack, 1);
    rge_write(saved_handle, &this->was_same_owner, 1);
    rge_write(saved_handle, &this->indirect_fire_flag, 1);

    if (this->move_sprite != 0) {
        short_val = this->move_sprite->id;
    } else {
        short_val = -1;
    }
    rge_write(saved_handle, &short_val, 2);

    if (this->fight_sprite != 0) {
        short_val = this->fight_sprite->id;
    } else {
        short_val = -1;
    }
    rge_write(saved_handle, &short_val, 2);

    if (this->wait_sprite != 0) {
        short_val = this->wait_sprite->id;
    } else {
        short_val = -1;
    }
    rge_write(saved_handle, &short_val, 2);
}

void RGE_Action_Attack::first_in_stack(unsigned char first_time) {
    if (this->obj->maximumSpeed() != 0.0) {
        UnitAIModule* ai = this->obj->unitAI();
        if (ai == 0 || this->obj->unitAI()->currentOrder() != 0x2D5) {
            this->set_state(4);
            return;
        }
    }

    int rangeStatus = -1;
    if (this->ready_to_attack(rangeStatus) == 0) {
        if (rangeStatus == 1) {
            this->set_state(6);
            return;
        }
        this->set_state(0x0D);
        return;
    }
    this->set_state(6);
}

int RGE_Action_Attack::stop() {
    this->set_state(1);
    return 1;
}

void RGE_Action_Attack::set_state(unsigned char new_state) {
    this->sub_actions->delete_list();
    this->state = new_state;

    switch (new_state) {
    case 2:
        this->indirect_fire_flag = 0;
        return;

    case 4: {
        if (this->indirect_fire_flag > 0) {
            this->indirect_fire_flag--;
        }
        RGE_Action_Move_To* action;
        if (this->target_obj != 0) {
            action = new RGE_Action_Move_To(this->obj, this->target_obj, this->range, this->move_sprite);
        } else {
            action = new RGE_Action_Move_To(this->obj, this->target_x, this->target_y, this->target_z,
                                            this->range, this->move_sprite);
        }
        if (action == 0) {
            if (this->subActionValue == 0) {
                this->obj->notify(this->obj->id, this->obj->id, 0x1F9, 0x262, 0, 0);
            }
            this->set_state(1);
            return;
        }
        this->sub_actions->add_action(action);
        action->setSubAction(1);
        this->timer = 0.0f;
        return;
    }

    case 6: {
        if (this->indirect_fire_flag > 0 && this->target_obj != 0) {
            this->indirect_fire_flag = 0;
        }
        int rangeStatus = -1;
        if (this->ready_to_attack(rangeStatus)) {
            static_cast<RGE_Combat_Object*>(this->obj)->reset_attack_timer();
            this->set_state(7);
            return;
        }
        if (this->missile_id == -1) {
            this->obj->new_sprite(this->fight_sprite);
        } else {
            this->obj->new_sprite(this->wait_sprite);
        }
        return;
    }

    case 7:
        this->obj->new_sprite(this->fight_sprite);
        this->need_to_attack = 1;
        return;

    case 1:
    case 13:
    case 14:
        this->obj->new_sprite(this->wait_sprite);
        return;

    default:
        return;
    }
}

unsigned char RGE_Action_Attack::update() {
    this->timer += this->obj->owner->world->world_time_delta_seconds;

    if (this->targetID != -1 && this->obj->owner->world->object(this->targetID) == 0) {
        this->set_target_obj(0);
        this->set_state(2);
        return 5;
    }

    if (this->target2ID != -1 && this->obj->owner->world->object(this->target2ID) == 0) {
        this->set_target_obj2(0);
    }

    if (this->target_obj != 0 && this->target_obj->object_state >= RGE_OBJECT_STATE_DYING) {
        this->set_target_obj(0);
        this->set_state(2);
        return 5;
    }

    if (this->target_obj != 0 && this->obj->owner->id != 0 && this->obj->owner->isAlly(this->target_obj->owner->id)) {
        this->set_state(1);
        if (this->subActionValue == 0) {
            this->obj->notify(this->obj->id, this->obj->id, 0x1FB, 0x258, this->targetID, 0);
        }
        return 4;
    }

    if (this->target_obj != 0 && this->target_obj->inside_obj != 0) {
        this->set_state(1);
        if (this->subActionValue == 0) {
            this->obj->notify(this->obj->id, this->obj->id, 0x1FB, 0x258, this->targetID, 0);
        }
        return 4;
    }

    switch (this->state) {
    case 1:
        return 1;

    case 2:
        if (this->obj->sprite_list->looped(this->obj->sprite) == 1) {
            this->set_target_obj(0);
            if (this->subActionValue == 0) {
                this->obj->notify(this->obj->id, this->obj->id, 0x1FA, 0x258, 0, 0);
            }
            this->set_state(1);
            if (this->subActionValue == 1) {
                return 5;
            }
            return 2;
        }
        break;

    case 4:
        switch (this->sub_actions->update()) {
        case 1:
        case 2:
            this->set_state(6);
            break;

        case 3:
            this->set_state(13);
            if (this->subActionValue == 0) {
                this->obj->notify(this->obj->id, this->obj->id, 0x1F9, 0x258, 0, 0);
            }
            return 3;

        case 4:
            this->set_state(14);
            if (this->subActionValue == 0) {
                this->obj->notify(this->obj->id, this->obj->id, 0x1FB, 0x258, this->targetID, 0);
            }
            return 4;

        default:
            break;
        }
        break;

    case 6: {
        int rangeStatus = -1;
        if (this->ready_to_attack(rangeStatus)) {
            static_cast<RGE_Combat_Object*>(this->obj)->reset_attack_timer();
            this->set_state(7);
        }
        break;
    }

    case 7:
        if (this->need_to_attack == 0) {
            if (this->obj->can_attack() == 1) {
                if (this->target_obj == 0 && this->indirect_fire_flag == 0) {
                    this->set_state(2);
                    return 0;
                }

                static_cast<RGE_Combat_Object*>(this->obj)
                    ->reset_attack_timer();
                this->set_state(6);
                if (this->state == 13 || this->state == 4) {
                    return 0;
                }
                this->set_state(7);
            }

            if (this->need_to_attack == 0) {
                if (this->obj->sprite_list->looped(this->obj->sprite) != 1 && (this->obj->sprite->flags & 1) != 0) {
                    return 0;
                }

                if (this->target_obj == 0 && this->indirect_fire_flag == 0) {
                    this->set_state(2);
                } else {
                    this->set_state(6);
                }
                return 0;
            }
        }

        {
            short attack_frame = this->fire_missile_at_frame;
            if (attack_frame == 0) {
                attack_frame =
                    static_cast<short>(this->obj->sprite->frame_num * 0.5f);
            }
            if (this->obj->sprite_list->frame_passed(this->obj->sprite, attack_frame)) {
                this->do_attack();
            }
        }
        break;

    case 13:
        this->obj->notify(this->obj->id, this->obj->id, 0x1F9, 0x258, 0, 0);
        return 3;

    default:
        break;
    }

    return 0;
}

int RGE_Action_Attack::work(RGE_Static_Object* obj_in, float x, float y, float z) {
    if (obj_in != 0) {
        if (obj_in == this->target_obj) {
            if (this->state == 4 || this->state == 6) {
                goto done;
            }
            if (this->state == 7) {
                return 1;
            }
        }

        this->indirect_fire_flag = 0;
        this->set_target_obj(obj_in);
        this->set_state(4);

    done:
        return 1;
    }

    return 0;
}

int RGE_Action_Attack::ready_to_attack(int& rangeState) {
    float rangeDistance;
    float radius_x;
    float radius_y;
    float radius_distance;
    float x_change;
    float y_change;
    float z_change;

    if (this->obj->turn_towards(this->target_obj, this->target_x, this->target_y) == 0) {
        return 0;
    }

    if (this->target_obj == 0) {
        rangeDistance = this->obj->distance_to_position(this->target_x, this->target_y, this->target_z);
        if (rangeDistance < this->min_range) {
            rangeState = 0;
            goto too_close;
        }

        radius_x = this->obj->master_obj->radius_x;
        radius_y = this->obj->master_obj->radius_y;
        radius_distance =
            (float)sqrt(radius_x * radius_x + radius_y * radius_y);
        radius_distance =
            radius_distance + this->range - g_attack_radius_distance_adjustment;
        if (rangeDistance <= radius_distance) {
            goto ready;
        }

        rangeState = 2;
        goto too_far;
    }

    if (this->target_obj->owner->id > 0 && this->target_obj->master_obj->object_group != 3 &&
        this->target_obj->master_obj->object_group != 0x1B) {
        unsigned char visible = this->obj->owner->visible->get_visible((int)this->target_obj->world_x,
                                                                       (int)this->target_obj->world_y);
        if (visible == 0) {
            this->set_state(0x0D);
            return 0;
        }
        if (visible == 0x80 && this->target_obj->master_obj->fog_flag == 0) {
            this->set_state(0x0D);
            return 0;
        }
    }

    if (this->target_obj->world_x == this->target_x && this->target_obj->world_y == this->target_y &&
        this->target_obj->world_z == this->target_z) {
        goto ready;
    }

    x_change = this->target_obj->world_x - this->target_x;
    y_change = this->target_obj->world_y - this->target_y;
    z_change = this->target_obj->world_z - this->target_z;

    if (x_change <= 0.5f && x_change >= -0.5f && y_change <= 0.5f && y_change >= -0.5f &&
        z_change <= 0.5f && z_change >= -0.5f) {
        goto ready;
    }

    rangeDistance = this->obj->distance_to_object(this->target_obj);
    radius_x = this->obj->master_obj->radius_x;
    radius_y = this->obj->master_obj->radius_y;
    radius_distance =
        (float)sqrt(radius_x * radius_x + radius_y * radius_y);
    radius_distance =
        radius_distance + this->range - g_attack_radius_distance_adjustment;

    if (rangeDistance < this->min_range) {
        rangeState = 0;

too_close:
        if (this->subActionValue == 0) {
            this->obj->notify(this->obj->id, this->obj->id, 0x1FE, 0, 0, 0);
        }
        if (this->obj->maximumSpeed() != 0.0) {
            if (this->obj->unitAI() == 0) {
                return 0;
            }
            if (this->obj->unitAI()->currentOrder() != 0x2D5) {
                return 0;
            }
        }
        this->set_state(0x0D);
        return 0;
    }

    if (rangeDistance <= radius_distance) {
        this->target_x = this->target_obj->world_x;
        this->target_y = this->target_obj->world_y;
        this->target_z = this->target_obj->world_z;
        goto ready;
    }
    rangeState = 2;

too_far:
    if (this->subActionValue == 0) {
        this->obj->notify(this->obj->id, this->obj->id, 0x1FD, 0, 0, 0);
    }
    if (this->obj->maximumSpeed() == 0.0 || (this->obj->unitAI() != 0 && this->obj->unitAI()->currentOrder() == 0x2D5)) {
        this->set_state(0x0D);
    } else {
        this->set_state(4);
    }
    return 0;

ready:
    rangeState = 1;
    return this->obj->can_attack() != 0;
}

void RGE_Action_Attack::do_attack() {
    RGE_Combat_Object* object = static_cast<RGE_Combat_Object*>(this->obj);

    if (this->target_obj != 0) {
        object->attack(this->target_obj, object);
    } else {
        object->attack(this->target_x, this->target_y, this->target_z, object);
    }
    this->need_to_attack = 0;
}

void RGE_Action_Attack::copy_obj_sprites(RGE_Master_Action_Object* source, RGE_Task* task, RGE_Task* new_task) {
    if (this->move_sprite != 0) {
        if ((task != 0) && (new_task != 0) && (this->move_sprite == task->move_sprite)) {
            this->move_sprite = new_task->move_sprite;
        } else if (this->move_sprite == static_cast<RGE_Master_Action_Object*>(this->obj->master_obj) ->move_sprite) {
            this->move_sprite = source->move_sprite;
        }
    }

    if (this->fight_sprite != 0) {
        if ((task != 0) && (new_task != 0) && (this->fight_sprite == task->work_sprite)) {
            this->fight_sprite = new_task->work_sprite;
        } else if ((task != 0) && (new_task != 0) && (this->fight_sprite == task->work_sprite2)) {
            this->fight_sprite = new_task->work_sprite2;
        } else if (this->fight_sprite == static_cast<RGE_Master_Combat_Object*>(this->obj->master_obj) ->fight_sprite) {
            this->fight_sprite =
                static_cast<RGE_Master_Combat_Object*>(source)->fight_sprite;
        }
    }

    if (this->wait_sprite != 0) {
        if ((task != 0) && (new_task != 0) && (this->wait_sprite == task->work_sprite)) {
            this->wait_sprite = new_task->work_sprite;
            return;
        }
        if ((task != 0) && (new_task != 0) && (this->wait_sprite == task->work_sprite2)) {
            this->wait_sprite = new_task->work_sprite2;
            return;
        }
        if (this->wait_sprite == this->obj->master_obj->sprite) {
            this->wait_sprite = source->sprite;
        }
    }
}
