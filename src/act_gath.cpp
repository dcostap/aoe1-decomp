
#include "../include/act_gath.h"
#include "../include/game_globals.h"
#include "../include/act_list.h"
#include "../include/act_obj.h"
#include "../include/act_move.h"
#include "../include/basegame.h"
#include "../include/m_ac_obj.h"
#include "../include/m_s_obj.h"
#include "../include/move_obj.h"
#include "../include/obj_list.h"
#include "../include/player.h"
#include "../include/rge_fio.h"
#include "../include/sound.h"
#include "../include/stat_obj.h"
#include "../include/task.h"
#include "../include/world.h"
#include "../include/rge_base_game_global.h"


RGE_Action_Gather::RGE_Action_Gather(int infile, RGE_Action_Object* obj_in)
    : RGE_Action(infile, obj_in, 1) {
    this->action_type = 5;
    rge_read(infile, &this->targetType, 4);
}

// The empty derived destructor emits the 00402F30 thunk.
RGE_Action_Gather::~RGE_Action_Gather() {
}

RGE_Action_Gather::RGE_Action_Gather(RGE_Action_Object* obj_in, RGE_Task* task_in, RGE_Static_Object* target_obj_in)
    : RGE_Action(obj_in, 1) {
    this->task = task_in;
    this->action_type = 5;
    this->set_target_obj(target_obj_in);
    if (target_obj_in != 0) {
        this->target_x = target_obj_in->world_x;
        this->target_y = target_obj_in->world_y;
        this->target_z = target_obj_in->world_z;
        this->targetType = target_obj_in->master_obj->id;
    }
}

RGE_Action_Gather::RGE_Action_Gather(RGE_Action_Object* obj_in, RGE_Task* task_in, float x, float y, float z)
    : RGE_Action(obj_in, 1) {
    this->task = task_in;
    this->action_type = 5;
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->targetType = -1;
}

void RGE_Action_Gather::save(int outfile) {
    RGE_Action::save(outfile);
    rge_write(outfile, &this->targetType, 4);
}

void RGE_Action_Gather::first_in_stack(unsigned char first_time) {
    short attr = this->task->attribute_type;
    //! See TRIBE_Action_Build::update(): this discards a non-food carry with no credit.
    if (this->obj->attribute_type_held != attr) {
        this->obj->set_attribute(attr, 0);
    }

    if (first_time != 0) {
        RGE_Static_Object* target = this->target_obj;
        if (target != 0) {
            if (target->owner == this->obj->owner) {
                RGE_Master_Static_Object* target_master = target->master_obj;
                RGE_Master_Action_Object* object_master =
                    (RGE_Master_Action_Object*)this->obj->master_obj;
                short id = target_master->id;

                if ((id == object_master->drop_site || id == object_master->backup_drop_site) &&
                    this->obj->attribute_amount_held > g_gather_positive_amount_threshold) {
                    this->set_target_obj2(target);
                    this->set_target_obj(0);
                    this->target_x = -1.0f;
                    this->target_y = -1.0f;
                    this->target_z = -1.0f;
                    this->set_state(8);
                    return;
                }
            }
            this->set_state(4);
            return;
        } else {
            this->set_state(3);
            return;
        }
    }
    this->set_state(3);
}

void RGE_Action_Gather::set_state(unsigned char new_state) {
    this->sub_actions->delete_list();
    this->state = new_state;

    switch (new_state) {
    case 3:
        this->obj->notify(this->obj->id, this->obj->id, 0x202, 0x261, this->targetType, 0);
        this->timer = -10.0f;
        this->obj->new_sprite(this->get_wait_sprite());
        return;

    case 2:
        this->timer = 0.0f;
        this->obj->new_sprite(this->get_wait_sprite());
        this->set_target_obj(0);
        this->set_target_obj2(0);
        this->target_x = -1.0f;
        this->target_y = -1.0f;
        this->target_z = -1.0f;
        return;

    case 11:
    case 15: {
        this->timer = 0.0f;
        RGE_Action_Move_To* action = new RGE_Action_Move_To(this->obj, this->target_x, this->target_y, this->target_z,
                                                            this->task->work_range, this->get_move_sprite());
        if (action == 0) {
            this->set_state(13);
            return;
        }
        action->setSubAction(1);
        this->sub_actions->add_action(action);
        return;
    }

    case 4: {
        this->timer = 0.0f;
        if (this->target_obj == 0) {
            this->set_state(13);
            return;
        }

        this->target_x = this->target_obj->world_x;
        this->target_y = this->target_obj->world_y;
        this->target_z = this->target_obj->world_z;

        RGE_Action_Move_To* action = new RGE_Action_Move_To(this->obj, this->target_obj, this->task->work_range,
                                                            this->get_move_sprite());
        if (action == 0) {
            this->set_state(13);
            return;
        }
        this->sub_actions->add_action(action);
        action->setSubAction(1);
        return;
    }

    case 6:
        this->timer = 0.0f;
        this->obj->new_sprite(this->get_move_sprite());
        return;

    case 7:
        this->timer = 0.0f;
        if (this->obj->attribute_type_held != this->task->attribute_type) {
            this->obj->set_attribute(this->task->attribute_type, 0.0f);
        }
        this->obj->new_sprite(this->task->work_sprite);
        if (this->task->work_sound != 0) {
            this->task->work_sound->play(1);
        }
        return;

    case 8:
        if (this->obj->attribute_amount_held > g_gather_positive_amount_threshold) {
            if (this->target_obj2 == 0) {
                if (((RGE_Master_Action_Object*)this->obj->master_obj)->drop_site != -1) {
                    if (this->obj->useSameZoneDropsite() == 1) {
                        this->set_target_obj2(this->obj->owner->objects->find_by_master_ids(
                                ((RGE_Master_Action_Object*)this->obj->master_obj)->drop_site,
                                ((RGE_Master_Action_Object*)this->obj->master_obj)->backup_drop_site,
                                this->obj->world_x, this->obj->world_y, 1, 2, (RGE_Static_Object*)this->obj));
                    } else {
                        this->set_target_obj2(this->obj->owner->objects->find_by_master_ids(
                                ((RGE_Master_Action_Object*)this->obj->master_obj)->drop_site,
                                ((RGE_Master_Action_Object*)this->obj->master_obj)->backup_drop_site,
                                this->obj->world_x, this->obj->world_y, 1, 2, (RGE_Static_Object*)0));
                    }
                } else {
                    this->set_target_obj2(0);
                }
            }

            if (this->target_obj2 != 0) {
                RGE_Action_Move_To* action = new RGE_Action_Move_To(this->obj, this->target_obj2, this->task->work_range,
                                                                    this->get_move_sprite());
                if (action == 0) {
                    this->set_state(13);
                    return;
                }
                this->sub_actions->add_action(action);
                action->setSubAction(1);
                return;
            }

            this->obj->notify(this->obj->id, this->obj->id, 0x203, 0x261, 0, 0);
            this->set_state(13);
            return;
        }

        if (this->target_obj != 0 && this->target_obj->attribute_amount_held <= g_gather_positive_amount_threshold &&
            this->obj->keepGatheringWhenObjectIsOut((short)this->target_obj->master_obj->id) == 0) {
            this->set_target_obj(0);
        }
        this->set_state(3);
        return;

    case 1:
    case 13:
    case 14:
        this->timer = 0.0f;
        this->obj->new_sprite(this->get_wait_sprite());
        return;

    default:
        return;
    }
}

unsigned char RGE_Action_Gather::update() {
    if (this->targetID != -1 && this->obj->owner->world->object(this->targetID) == 0) {
        this->set_target_obj(0);
    }
    if (this->target2ID != -1 && this->obj->owner->world->object(this->target2ID) == 0) {
        this->set_target_obj2(0);
    }

    if (this->target_obj != 0 && this->target_obj->object_state >= 7) {
        this->set_target_obj(0);
    }
    if (this->target_obj2 != 0 && this->target_obj2->object_state >= 7) {
        this->set_target_obj2(0);
    }

    if (this->target_obj != 0 && this->target_obj->owner->id != 0 && this->target_obj->owner->id != this->obj->owner->id) {
        this->set_state(1);
        this->obj->notify(this->obj->id, this->obj->id, 0x1FB, 0x261, 0, 0);
        return 4;
    }

    switch (this->state) {
    case 3:
        if (this->timer < 0.0) {
            this->timer += this->obj->owner->world->world_time_delta_seconds;
            if (this->timer > 0.0) {
                this->timer = -10.0f;
                this->obj->notify(this->obj->id, this->obj->id, 0x202, 0x261, this->targetType, 0);
                return 0;
            }
        }
        break;

    case 11:
    case 15:
        switch (this->sub_actions->update()) {
        case 4:
            this->set_target_obj(0);
            if (this->state == 11) {
                this->set_state(11);
            } else {
                this->set_state(15);
            }
            return 0;

        case 1:
        case 2:
        case 5:
            if (this->state == 11) {
                this->set_state(3);
                return 0;
            }
            goto no_target;

        case 3:
            if (this->obj->owner->computerPlayer() == 1) {
                this->set_state(13);
            } else {
                this->set_state(3);
            }
            return 0;
        }
        break;

    case 4:
        switch (this->sub_actions->update()) {
        case 1:
        case 2:
            this->set_state(6);
            return 0;

        case 3:
            if (this->obj->owner->computerPlayer() == 1) {
                this->set_state(13);
            } else {
                this->set_state(3);
            }
            return 0;

        case 4:
        case 5:
            this->set_target_obj(0);
            this->set_state(11);
            return 0;
        }
        break;

    case 6:
        if (this->target_obj == 0) {
            this->set_state(3);
            return 0;
        }
        if (this->obj->turn_towards(this->target_obj, 0, 0) != 0) {
            if (this->target_obj->attribute_amount_held > g_gather_positive_amount_threshold ||
                this->obj->keepGatheringWhenObjectIsOut(this->target_obj->master_obj->id) != 0) {
                this->set_state(7);
                return 0;
            }
            this->set_target_obj(0);
            this->set_state(3);
        }
        return 0;

    case 7: {
        float give_amount;
        float adjusted_amount;
        float modifier;
        float max_hold;

        if (this->target_obj == 0) {
            if (this->obj->attribute_amount_held > g_gather_positive_amount_threshold) {
                this->set_state(8);
            } else {
                this->set_state(3);
            }
            return 0;
        }

        if (rge_base_game->quick_build != 0) {
            give_amount = this->target_obj->attribute_amount_held;
        } else {
            give_amount = this->task->work_val1 *
                ((RGE_Master_Action_Object*)this->obj->master_obj)->work_rate *
                this->obj->owner->world->world_time_delta_seconds;
        }
        if (give_amount > this->target_obj->attribute_amount_held) {
            give_amount = this->target_obj->attribute_amount_held;
        }

        short attr = this->task->attribute_type2;
        if (attr == -1) {
            modifier = 1.0f;
        } else {
            modifier = this->obj->owner->attributes[attr];
        }

        max_hold = (float)this->obj->master_obj->attribute_max_amount;
        adjusted_amount = modifier * give_amount;
        max_hold *= modifier;
        if (adjusted_amount > max_hold - this->obj->attribute_amount_held) {
            float excess = adjusted_amount -
                (max_hold - this->obj->attribute_amount_held);
            adjusted_amount -= excess;
            give_amount -= excess / modifier;
        }

        this->target_obj->set_attribute_amount(-give_amount, 1, 1);
        this->obj->set_attribute_amount(adjusted_amount, 1, 0);

        if (this->obj->attribute_amount_held < max_hold && (this->target_obj->attribute_amount_held > g_gather_positive_amount_threshold ||
             this->obj->keepGatheringWhenObjectIsOut(this->target_obj->master_obj->id) != 0)) {
            return 0;
        }
        this->set_state(8);
        return 0;
    }

    case 8:
        if (this->timer < 0.0) {
            this->timer += this->obj->owner->world->world_time_delta_seconds;
            if (this->timer > 0.0) {
                this->timer = 0.0f;
                this->set_state(8);
                return 0;
            }
        } else {
            switch (this->sub_actions->update()) {
            case 3:
            case 4:
            case 5:
                this->timer = -3.0f;
                this->obj->stop_moving();
                return 0;

            case 1:
            case 2: {
                if (this->target_obj2 == 0) {
                    this->set_state(8);
                    return 0;
                }
                if (this->obj->distance_to_object(this->target_obj2) > g_gather_dropoff_distance_threshold) {
                    this->timer = -3.0f;
                    this->obj->stop_moving();
                    return 0;
                }

                if (this->task->work_sound2 != 0) {
                    this->task->work_sound2->play(1);
                }

                short attribute = this->task->attribute_type3;
                if (attribute == -1) {
                    attribute = this->obj->attribute_type_held;
                }
                this->obj->owner->add_attribute_num(attribute, this->obj->attribute_amount_held, 1);
                this->obj->owner->trackUnitGather(this->obj->id, attribute, (int)this->obj->attribute_amount_held);
                this->obj->set_attribute(-1, 0.0f);

                if (this->target_obj != 0) {
                    this->set_target_obj2(0);
                    this->set_state(4);
                    return 0;
                }
                if (this->target_x != -1.0f && this->target_y != -1.0f) {
                    this->set_state(11);
                    return 0;
                }
                goto no_target;
            }
            }
        }
        break;

    case 1:
        return 1;

    case 13:
        this->obj->notify(this->obj->id, this->obj->id, 0x1F9, 0x261, 0, 0);
        if (this->obj->owner->computerPlayer() == 1) {
            this->set_state(1);
        } else {
            this->set_state(2);
        }
        return 3;
    }

    return 0;

no_target:
    if (this->obj->owner->computerPlayer() == 1) {
        this->set_state(1);
    } else {
        this->set_state(2);
    }
    return 0;
}

RGE_Sprite* RGE_Action_Gather::get_move_sprite() {
    RGE_Task* task = this->task;
    short task_facet = task->attribute_type;

    if (task_facet != -1) {
        if (this->obj->attribute_type_held == task_facet) {
            if ((int)this->obj->attribute_amount_held > 0) {
                if (task->carry_sprite != 0) {
                    return task->carry_sprite;
                }
            }
        }
    }
    return task->move_sprite;
}

RGE_Sprite* RGE_Action_Gather::get_wait_sprite() {
    RGE_Task* task = this->task;
    short value = task->attribute_type;
    if (value != (short)0xFFFF && value == this->obj->attribute_type_held && (int)this->obj->attribute_amount_held > 0 &&
        task->carry_sprite != 0) {
        return task->carry_sprite;
    }
    return this->obj->master_obj->sprite;
}

int RGE_Action_Gather::stop() {
    this->set_state(2);
    return 1;
}

int RGE_Action_Gather::move_to(RGE_Static_Object* obj_in, float x, float y, float z) {
    if (obj_in != 0) {
        if (obj_in->owner == this->obj->owner) {
            RGE_Master_Action_Object* object_master =
                (RGE_Master_Action_Object*)this->obj->master_obj;
            short id = obj_in->master_obj->id;
            if (id == object_master->drop_site || id == object_master->backup_drop_site) {
                if (this->obj->attribute_amount_held > 0.0f) {
                    if (obj_in == this->target_obj2 && this->state == 8) {
                        return 1;
                    }
                    this->set_target_obj(0);
                    this->target_x = -1.0f;
                    this->target_y = -1.0f;
                    this->target_z = -1.0f;
                    this->set_target_obj2(obj_in);
                    this->set_state(8);
                    return 1;
                }
            }
        }
    }

    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->set_target_obj(0);
    this->set_state(15);
    return 1;
}

int RGE_Action_Gather::work(RGE_Static_Object* obj_in, float x, float y, float z) {
    if (obj_in != 0) {
        if (obj_in == this->target_obj && (this->state == 4 || this->state == 6 || this->state == 7)) {
            return 1;
        }

        if (obj_in->owner == this->obj->owner) {
            short id = obj_in->master_obj->id;
            RGE_Master_Action_Object* object_master =
                (RGE_Master_Action_Object*)this->obj->master_obj;
            if ((id == object_master->drop_site || id == object_master->backup_drop_site) &&
                this->obj->attribute_amount_held > 0.0f) {
                this->timer = 0.0f;
                this->set_target_obj(0);
                this->target_x = -1.0f;
                this->target_y = -1.0f;
                this->target_z = -1.0f;
                this->set_target_obj2(obj_in);
                this->set_state(8);
                return 1;
            }
        }

        this->set_target_obj(obj_in);
        this->target_x = obj_in->world_x;
        this->target_y = obj_in->world_y;
        this->target_z = obj_in->world_z;
        this->set_target_obj2(0);
        this->set_state(4);
    } else {
        this->target_z = z;
        this->target_x = x;
        this->target_y = y;
        this->set_target_obj(0);
        this->set_state(15);
    }
    return 1;
}
