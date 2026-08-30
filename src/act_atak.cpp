
#include "../include/act_atak.h"
#include "../include/act_list.h"
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

#include <math.h>

extern float DAT_0056e0cc;

RGE_Action_Attack::RGE_Action_Attack(int handle, RGE_Action_Object* object)
    : RGE_Action(handle, object, 1)
{
    short sprite_id;

    this->action_type = 9;
    rge_read(handle, &this->range, 4);
    rge_read(handle, &this->min_range, 4);
    rge_read(handle, &this->missile_id, 2);
    rge_read(handle, &this->fire_missile_at_frame, 2);
    rge_read(handle, &this->need_to_attack, 1);
    rge_read(handle, &this->was_same_owner, 1);
    rge_read(handle, &this->indirect_fire_flag, 1);
    rge_read(handle, &sprite_id, 2);
    this->move_sprite = this->obj->get_sprite_pointer(sprite_id);
    rge_read(handle, &sprite_id, 2);
    this->fight_sprite = this->obj->get_sprite_pointer(sprite_id);
    rge_read(handle, &sprite_id, 2);
    this->wait_sprite = this->obj->get_sprite_pointer(sprite_id);
}

RGE_Action_Attack::RGE_Action_Attack(
    RGE_Action_Object* object, RGE_Static_Object* target,
    RGE_Sprite* move, RGE_Sprite* fight, RGE_Sprite* wait,
    float attack_range, float minimum_range, short missile,
    short fire_frame)
    : RGE_Action(object, 1)
{
    this->action_type = 9;
    this->set_target_obj(target);
    this->fight_sprite = fight;
    this->wait_sprite = wait;
    this->range = attack_range;
    this->min_range = minimum_range;
    this->missile_id = missile;
    this->target_x = -1.0f;
    this->target_y = -1.0f;
    this->target_z = -1.0f;
    this->move_sprite = move;
    this->fire_missile_at_frame = fire_frame;
    this->need_to_attack = 0;
    this->indirect_fire_flag = 0;
    if (target != 0 && target->owner == object->owner) {
        this->was_same_owner = 1;
    } else {
        this->was_same_owner = 0;
    }

    if (move == 0) {
        RGE_Master_Moving_Object* master =
            static_cast<RGE_Master_Moving_Object*>(this->obj->master_obj);
        RGE_Sprite* sprite = master->run_sprite;
        if (sprite == 0) {
            sprite = master->move_sprite;
        }
        this->move_sprite = sprite;
    }
    if (fight == 0) {
        this->fight_sprite =
            static_cast<RGE_Master_Combat_Object*>(this->obj->master_obj)
                ->fight_sprite;
    }
    if (wait == 0) {
        this->wait_sprite = this->obj->master_obj->sprite;
    }
    if (attack_range == 0.0f) {
        this->range =
            static_cast<RGE_Master_Combat_Object*>(this->obj->master_obj)
                ->weapon_range;
        if (this->range == 0.0f) {
            this->range = 0.4f;
        }
    }
}

RGE_Action_Attack::RGE_Action_Attack(
    RGE_Action_Object* object, float x, float y, float z,
    RGE_Sprite* move, RGE_Sprite* fight, RGE_Sprite* wait,
    float attack_range, float minimum_range, short missile, short fire_frame)
    : RGE_Action(object, 1)
{
    this->target_x = x;
    this->range = attack_range;
    this->min_range = minimum_range;
    this->target_z = z;
    this->target_y = y;
    this->missile_id = missile;
    this->action_type = 9;
    this->move_sprite = move;
    this->fight_sprite = fight;
    this->wait_sprite = wait;
    this->fire_missile_at_frame = fire_frame;
    this->need_to_attack = 0;
    this->was_same_owner = 0;
    this->indirect_fire_flag = 2;

    if (move == 0) {
        RGE_Master_Moving_Object* master =
            static_cast<RGE_Master_Moving_Object*>(this->obj->master_obj);
        RGE_Sprite* sprite = master->run_sprite;
        if (sprite == 0) {
            sprite = master->move_sprite;
        }
        this->move_sprite = sprite;
    }
    if (fight == 0) {
        this->fight_sprite =
            static_cast<RGE_Master_Combat_Object*>(this->obj->master_obj)
                ->fight_sprite;
    }
    if (wait == 0) {
        this->wait_sprite = this->obj->master_obj->sprite;
    }
    if (attack_range == 0.0f) {
        this->range =
            static_cast<RGE_Master_Combat_Object*>(this->obj->master_obj)
                ->weapon_range;
        if (this->range == 0.0f) {
            this->range = 0.4f;
        }
    }
}

RGE_Action_Attack::~RGE_Action_Attack()
{
}

void RGE_Action_Attack::save(int handle)
{
    int saved_handle = handle;
    short sprite_id;

    RGE_Action::save(handle);
    rge_write(saved_handle, &this->range, 4);
    rge_write(saved_handle, &this->min_range, 4);
    rge_write(saved_handle, &this->missile_id, 2);
    rge_write(saved_handle, &this->fire_missile_at_frame, 2);
    rge_write(saved_handle, &this->need_to_attack, 1);
    rge_write(saved_handle, &this->was_same_owner, 1);
    rge_write(saved_handle, &this->indirect_fire_flag, 1);

    if (this->move_sprite != 0) {
        sprite_id = this->move_sprite->id;
    } else {
        sprite_id = -1;
    }
    rge_write(saved_handle, &sprite_id, 2);

    if (this->fight_sprite != 0) {
        sprite_id = this->fight_sprite->id;
    } else {
        sprite_id = -1;
    }
    rge_write(saved_handle, &sprite_id, 2);

    if (this->wait_sprite != 0) {
        sprite_id = this->wait_sprite->id;
    } else {
        sprite_id = -1;
    }
    rge_write(saved_handle, &sprite_id, 2);
}

void RGE_Action_Attack::first_in_stack(unsigned char)
{
    if (this->obj->maximumSpeed() != 0.0) {
        UnitAIModule* ai = this->obj->unitAI();
        if (ai == 0 || this->obj->unitAI()->currentOrder() != 0x2D5) {
            this->set_state(4);
            return;
        }
    }

    int range_status = -1;
    if (this->ready_to_attack(range_status) == 0) {
        if (range_status == 1) {
            this->set_state(6);
            return;
        }
        this->set_state(0x0D);
        return;
    }
    this->set_state(6);
}

int RGE_Action_Attack::stop()
{
    this->set_state(1);
    return 1;
}

void RGE_Action_Attack::set_state(unsigned char state)
{
    this->sub_actions->delete_list();
    this->state = state;

    switch (state) {
    case 2:
        this->indirect_fire_flag = 0;
        return;

    case 4: {
        if (this->indirect_fire_flag > 0) {
            this->indirect_fire_flag--;
        }
        RGE_Action_Move_To* action;
        if (this->target_obj != 0) {
            action = new RGE_Action_Move_To(this->obj, this->target_obj,
                                            this->range, this->move_sprite);
        } else {
            action = new RGE_Action_Move_To(
                this->obj, this->target_x, this->target_y, this->target_z,
                this->range, this->move_sprite);
        }
        if (action == 0) {
            if (this->subActionValue == 0) {
                this->obj->notify(this->obj->id, this->obj->id, 0x1F9,
                                  0x262, 0, 0);
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
        int range_status = -1;
        if (this->ready_to_attack(range_status)) {
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

unsigned char RGE_Action_Attack::update()
{
    this->timer += this->obj->owner->world->world_time_delta_seconds;

    if (this->targetID != -1 &&
        this->obj->owner->world->object(this->targetID) == 0) {
        this->set_target_obj(0);
        this->set_state(2);
        return 5;
    }

    if (this->target2ID != -1 &&
        this->obj->owner->world->object(this->target2ID) == 0) {
        this->set_target_obj2(0);
    }

    if (this->target_obj != 0 && this->target_obj->object_state >= 3) {
        this->set_target_obj(0);
        this->set_state(2);
        return 5;
    }

    if (this->target_obj != 0 && this->obj->owner->id != 0 &&
        this->obj->owner->isAlly(this->target_obj->owner->id) != 0) {
        this->set_state(1);
        if (this->subActionValue != 0) {
            goto target_done;
        }
        goto target_notify_body;
    }

    if (this->target_obj != 0 && this->target_obj->inside_obj != 0) {
        this->set_state(1);
        goto target_notify;
    }

    switch (this->state) {
    case 13:
        goto state13_common;

    case 4:
        switch (this->sub_actions->update()) {
        case 3:
state13_common:
            this->set_state(13);
            if (this->subActionValue != 0) {
                return 3;
            }
            this->obj->notify(this->obj->id, this->obj->id, 0x1F9, 0x258,
                              0, 0);
            return 3;
        case 4:
            this->set_state(14);
            goto target_notify;
        case 1:
        case 2:
            this->set_state(6);
            return 0;
        default:
            goto return_zero;
        }

    case 3:
        goto return_zero;

    default:
        goto return_zero;

target_notify:
        if (this->subActionValue != 0) {
            goto target_done;
        }

target_notify_body:
        this->obj->notify(this->obj->id, this->obj->id, 0x1FB, 0x258,
                          this->targetID, 0);

target_done:
        return 4;

return_zero:
        return 0;

    case 6: {
        int range_status = -1;
        if (this->ready_to_attack(range_status) != 0) {
            static_cast<RGE_Combat_Object*>(this->obj)->reset_attack_timer();
            this->set_state(7);
            return 0;
        }
        goto return_zero;
    }

    case 7: {
        if (this->need_to_attack == 0) {
            if (this->obj->can_attack() == 1) {
                if (this->target_obj == 0 && this->indirect_fire_flag == 0) {
                    this->set_state(2);
                    return 0;
                }
                static_cast<RGE_Combat_Object*>(this->obj)->reset_attack_timer();
                this->set_state(6);
                if (this->state != 13 && this->state != 4) {
                    this->set_state(7);
                }
            }

            if (this->need_to_attack == 0) {
                if (this->obj->sprite_list->looped(this->obj->sprite) != 1 &&
                    (this->obj->sprite->flags & 1) != 0) {
                    goto return_zero;
                }
                if (this->target_obj == 0 && this->indirect_fire_flag == 0) {
                    this->set_state(2);
                    return 0;
                }
                this->set_state(6);
                return 0;
            }
        }

        short frame = this->fire_missile_at_frame;
        if (frame == 0) {
            frame = (short)((float)this->obj->sprite->frame_num * 0.5f);
        }
        if (this->obj->sprite_list->frame_passed(this->obj->sprite, frame) !=
            0) {
            this->do_attack();
        }
        return 0;
    }

    case 2:
        if (this->obj->sprite_list->looped(this->obj->sprite) == 1) {
            this->set_target_obj(0);
            if (this->subActionValue == 0) {
                this->obj->notify(this->obj->id, this->obj->id, 0x1FA, 0x258,
                                  0, 0);
            }
            this->set_state(1);
            return this->subActionValue == 1 ? (unsigned char)5
                                              : (unsigned char)2;
        }
        goto return_zero;

    case 1:
        return 1;
    }
}

int RGE_Action_Attack::work(RGE_Static_Object* target, float x, float y,
                            float z)
{
    if (target != 0) {
        if (target == this->target_obj) {
            if (this->state == 4 || this->state == 6) {
                goto done;
            }
            if (this->state == 7) {
                return 1;
            }
        }

        this->indirect_fire_flag = 0;
        this->set_target_obj(target);
        this->set_state(4);

    done:
        return 1;
    }

    return 0;
}

int RGE_Action_Attack::ready_to_attack(int& range_status)
{
    if (this->obj->turn_towards(this->target_obj, this->target_x,
                                 this->target_y) == 0) {
        return 0;
    }

    if (this->target_obj == 0) {
        float distance = this->obj->distance_to_position(
            this->target_x, this->target_y, this->target_z);
        if (distance < this->min_range) {
            range_status = 0;
        } else {
            RGE_Master_Static_Object* master = this->obj->master_obj;
            float radius = sqrt(master->radius_x * master->radius_x +
                                master->radius_y * master->radius_y);
            float max_distance = radius + this->range - DAT_0056e0cc;
            if (distance <= max_distance) {
                range_status = 1;
            } else {
                range_status = 2;
            }
        }
    } else {
        if (this->target_obj->owner->id > 0) {
            short group = this->target_obj->master_obj->object_group;
            if (group != 3 && group != 27) {
                unsigned char visibility = this->obj->owner->visible->get_visible(
                    (int)this->target_obj->world_x,
                    (int)this->target_obj->world_y);
                if (visibility == 0) {
                    this->set_state(13);
                    return 0;
                }
                if (visibility == 0x80 &&
                    this->target_obj->master_obj->fog_flag == 0) {
                    this->set_state(13);
                    return 0;
                }
            }
        }

        if (this->target_obj->world_x == this->target_x &&
            this->target_obj->world_y == this->target_y &&
            this->target_obj->world_z == this->target_z) {
            range_status = 1;
        } else {
            float x_change = this->target_obj->world_x - this->target_x;
            float z_change = this->target_obj->world_z - this->target_z;
            float y_change = this->target_obj->world_y - this->target_y;
            if ((x_change > -0.5f && x_change < 0.5f) &&
                (y_change > -0.5f && y_change < 0.5f) &&
                (z_change > -0.5f && z_change < 0.5f)) {
                range_status = 1;
            } else {
                float distance =
                    this->obj->distance_to_object(this->target_obj);
                RGE_Master_Static_Object* master = this->obj->master_obj;
                float radius = sqrt(master->radius_x * master->radius_x +
                                    master->radius_y * master->radius_y);
                float max_distance = radius + this->range - DAT_0056e0cc;
                if (distance < this->min_range) {
                    range_status = 0;
                } else if (distance <= max_distance) {
                    this->target_x = this->target_obj->world_x;
                    this->target_y = this->target_obj->world_y;
                    this->target_z = this->target_obj->world_z;
                    range_status = 1;
                } else {
                    range_status = 2;
                }
            }
        }
    }

    if (range_status == 0) {
        if (this->subActionValue == 0) {
            this->obj->notify(this->obj->id, this->obj->id, 0x1FE, 0, 0, 0);
        }
        if (this->obj->maximumSpeed() != 0.0) {
            UnitAIModule* ai = this->obj->unitAI();
            if (ai == 0) {
                return 0;
            }
            ai = this->obj->unitAI();
            if (ai->currentOrder() != 0x2D5) {
                return 0;
            }
        }
        this->set_state(13);
        return 0;
    }

    if (range_status == 2) {
        if (this->subActionValue == 0) {
            this->obj->notify(this->obj->id, this->obj->id, 0x1FD, 0, 0, 0);
        }
        if (this->obj->maximumSpeed() != 0.0) {
            UnitAIModule* ai = this->obj->unitAI();
            if (ai == 0) {
                this->set_state(4);
                return 0;
            }
            ai = this->obj->unitAI();
            if (ai->currentOrder() != 0x2D5) {
                this->set_state(4);
                return 0;
            }
        }
        this->set_state(13);
        return 0;
    }

    range_status = 1;
    return this->obj->can_attack() != 0;
}

void RGE_Action_Attack::do_attack()
{
    RGE_Combat_Object* object = static_cast<RGE_Combat_Object*>(this->obj);

    if (this->target_obj != 0) {
        object->attack(this->target_obj, object);
    } else {
        object->attack(this->target_x, this->target_y, this->target_z, object);
    }
    this->need_to_attack = 0;
}

void RGE_Action_Attack::copy_obj_sprites(
    RGE_Master_Action_Object* source, RGE_Task* old_task, RGE_Task* new_task)
{
    if (this->move_sprite != 0) {
        if ((old_task != 0) && (new_task != 0) &&
            (this->move_sprite == old_task->move_sprite)) {
            this->move_sprite = new_task->move_sprite;
        } else if (this->move_sprite ==
                   static_cast<RGE_Master_Action_Object*>(this->obj->master_obj)
                       ->move_sprite) {
            this->move_sprite = source->move_sprite;
        }
    }

    if (this->fight_sprite != 0) {
        if ((old_task != 0) && (new_task != 0) &&
            (this->fight_sprite == old_task->work_sprite)) {
            this->fight_sprite = new_task->work_sprite;
        } else if ((old_task != 0) && (new_task != 0) &&
                   (this->fight_sprite == old_task->work_sprite2)) {
            this->fight_sprite = new_task->work_sprite2;
        } else if (this->fight_sprite ==
                   static_cast<RGE_Master_Combat_Object*>(this->obj->master_obj)
                       ->fight_sprite) {
            this->fight_sprite =
                static_cast<RGE_Master_Combat_Object*>(source)->fight_sprite;
        }
    }

    if (this->wait_sprite != 0) {
        if ((old_task != 0) && (new_task != 0) &&
            (this->wait_sprite == old_task->work_sprite)) {
            this->wait_sprite = new_task->work_sprite;
            return;
        }
        if ((old_task != 0) && (new_task != 0) &&
            (this->wait_sprite == old_task->work_sprite2)) {
            this->wait_sprite = new_task->work_sprite2;
            return;
        }
        if (this->wait_sprite == this->obj->master_obj->sprite) {
            this->wait_sprite = source->sprite;
        }
    }
}
