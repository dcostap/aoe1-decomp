
#include "../include/game_globals.h"
#include "../include/tribegam.h"
#include "../include/rge_fio.h"
#include "../include/tact_trd.h"
#include "../include/act_move.h"
#include "../include/act_list.h"
#include "../include/m_s_obj.h"
#include "../include/m_ac_obj.h"
#include "../include/stat_obj.h"
#include "../include/move_obj.h"
#include "../include/act_obj.h"
#include "../include/player.h"
#include "../include/sound.h"
#include "../include/sprite.h"
#include "../include/task.h"
#include "../include/world.h"
#include "../include/obj_list.h"

TRIBE_Action_Trade::TRIBE_Action_Trade(int infile, RGE_Action_Object* obj_in) : RGE_Action(infile, obj_in, 1) {
    rge_read(infile, &this->pick_up_x, 4);
    rge_read(infile, &this->pick_up_y, 4);
    this->action_type = TRIBE_ACTION_TYPE_TRADE;
}

TRIBE_Action_Trade::TRIBE_Action_Trade(RGE_Action_Object* obj_in, RGE_Task* task_in, RGE_Static_Object* target_obj_in) :
    RGE_Action(obj_in, 1) {
    this->task = task_in;
    this->action_type = TRIBE_ACTION_TYPE_TRADE;
    this->set_target_obj(target_obj_in);
    this->target_x = target_obj_in->world_x;
    this->target_y = target_obj_in->world_y;
    this->target_z = target_obj_in->world_z;
    this->pick_up_x = -1.0f;
    this->pick_up_y = -1.0f;
}

TRIBE_Action_Trade::TRIBE_Action_Trade(RGE_Action_Object* obj_in, RGE_Task* task_in, float x, float y, float z) :
    RGE_Action(obj_in, 1) {
    this->task = task_in;
    this->action_type = TRIBE_ACTION_TYPE_TRADE;
    *(int*) &this->target_x = *(int*) &x;
    *(int*) &this->target_y = *(int*) &y;
    this->pick_up_x = -1.0f;
    this->pick_up_y = -1.0f;
    *(int*) &this->target_z = *(int*) &z;
}

void TRIBE_Action_Trade::save(int outfile) {
    RGE_Action::save(outfile);
    rge_write(outfile, &this->pick_up_x, 4);
    rge_write(outfile, &this->pick_up_y, 4);
}

void TRIBE_Action_Trade::first_in_stack(unsigned char first_time) {
    if (this->obj->attribute_type_held != RGE_RESOURCE_FOOD && this->obj->attribute_type_held != RGE_RESOURCE_STONE
        && this->obj->attribute_type_held != RGE_RESOURCE_WOOD) {
        this->obj->attribute_type_held = RGE_RESOURCE_WOOD;
    }
    if (first_time != 0) {
        if (this->target_obj != 0) {
            this->set_state(4);
            return;
        }
        this->set_state(2);
        return;
    }
    this->set_state(3);
}

void TRIBE_Action_Trade::set_state(unsigned char new_state) {
    this->sub_actions->delete_list();
    this->state = new_state;

    switch (new_state) {
        case 3:
            this->obj->notify(this->obj->id, this->obj->id, UNIT_AI_NOTIFY_REQUEST_TASK, UNIT_AI_ACTION_TRADE, 0, 0);
            this->obj->new_sprite(this->get_wait_sprite());
            return;

        case 2:
            this->obj->new_sprite(this->get_wait_sprite());
            this->set_target_obj(0);
            this->set_target_obj2(0);
            this->target_x = -1.0f;
            this->target_y = -1.0f;
            this->target_z = -1.0f;
            return;

        case 11: {
            RGE_Action_Move_To* move_to = new RGE_Action_Move_To(
                this->obj, this->target_x, this->target_y, this->target_z, 0.0f, this->get_move_sprite()
            );
            if (move_to == 0) {
                this->set_state(0x0D);
                return;
            }
            move_to->setSubAction(1);
            this->sub_actions->add_action(move_to);
            return;
        }

        case 4: {
            if (this->target_obj == 0) {
                this->set_state(0x0D);
                return;
            }
            this->target_x = this->target_obj->world_x;
            this->target_y = this->target_obj->world_y;
            this->target_z = this->target_obj->world_z;

            RGE_Action_Move_To* action =
                new RGE_Action_Move_To(this->obj, this->target_obj, this->task->work_range, this->get_move_sprite());
            if (action == 0) {
                this->set_state(0x0D);
                return;
            }
            this->sub_actions->add_action(action);
            action->setSubAction(1);
            return;
        }

        case 6:
            this->obj->new_sprite(this->get_move_sprite());
            return;

        case 7:
            this->obj->new_sprite(this->task->work_sprite);
            if (this->task->work_sound != 0) {
                this->task->work_sound->play(1);
            }
            if (this->target_obj != 0) {
                this->pick_up_x = this->target_obj->world_x;
                this->pick_up_y = this->target_obj->world_y;
            } else {
                this->pick_up_x = -1.0f;
                this->pick_up_y = -1.0f;
            }
            return;

        case 8:
            if (this->obj->attribute_amount_held > g_trade_positive_amount_threshold) {
                if (this->target_obj2 == 0
                    || this->target_obj2->master_obj->id
                           != ((RGE_Master_Action_Object*) this->obj->master_obj)->drop_site) {
                    short drop_site = ((RGE_Master_Action_Object*) this->obj->master_obj)->drop_site;
                    if (drop_site != -1) {
                        this->set_target_obj2(this->obj->owner->objects->find_by_master_ids(
                            drop_site, ((RGE_Master_Action_Object*) this->obj->master_obj)->backup_drop_site,
                            this->obj->world_x, this->obj->world_y, 1, RGE_OBJECT_STATE_ACTIVE,
                            (RGE_Static_Object*) this->obj
                        ));
                    } else {
                        this->set_target_obj2(0);
                    }
                }

                if (this->target_obj2 != 0) {
                    RGE_Action_Move_To* action =
                        new RGE_Action_Move_To(this->obj, this->target_obj2, 0.0f, this->get_move_sprite());
                    if (action == 0) {
                        this->set_state(0x0D);
                        return;
                    }
                    this->sub_actions->add_action(action);
                    action->setSubAction(1);
                    return;
                }

                this->obj->notify(this->obj->id, this->obj->id, 0x203, UNIT_AI_ACTION_TRADE, 0, 0);
                this->set_state(0x0D);
                return;
            }

            if (this->target_obj != 0 && this->target_obj->attribute_amount_held <= g_trade_positive_amount_threshold
                && this->obj->keepGatheringWhenObjectIsOut(this->target_obj->master_obj->id) == 0) {
                this->set_target_obj(0);
                this->set_state(3);
            }
            return;

        default:
            return;
    }
}

// The original frame is eight bytes plus ESI and EDI.

unsigned char TRIBE_Action_Trade::update() {
    if (this->targetID != -1 && this->obj->owner->world->object(this->targetID) == 0) {
        this->set_target_obj(0);
    }
    if (this->target2ID != -1 && this->obj->owner->world->object(this->target2ID) == 0) {
        this->set_target_obj2(0);
    }

    if (this->target_obj != 0 && this->target_obj->object_state >= RGE_OBJECT_STATE_PENDING_REMOVAL) {
        this->set_target_obj(0);
    }
    if (this->target_obj2 != 0 && this->target_obj2->object_state >= RGE_OBJECT_STATE_PENDING_REMOVAL) {
        this->set_target_obj2(0);
    }

    //! @bug A converted home dock remains target_obj2; no check rejects its new owner.
    //! The existing trade route can still return gold to the former owner.
    if (this->target_obj != 0 && this->obj->owner->id == this->target_obj->owner->id) {
        this->set_target_obj(0);
        this->set_target_obj2(0);
        this->set_state(1);
        if (this->subActionValue == 0) {
            this->obj->notify(
                this->obj->id, this->obj->id, UNIT_AI_NOTIFY_TARGET_INVALID, UNIT_AI_ACTION_TRADE, this->targetID, 0
            );
        }
        return RGE_ACTION_UPDATE_TARGET_INVALID;
    }

    switch (this->state) {
        case 1:
            return RGE_ACTION_UPDATE_REMOVE;

        case 11:
            if (this->timer < g_trade_zero_value) {
                this->timer += this->obj->owner->world->world_time_delta_seconds;
                if (this->timer > g_trade_zero_value) {
                    this->timer = 0.0f;
                    if (this->target_obj != 0) {
                        this->set_state(4);
                        return RGE_ACTION_UPDATE_CONTINUE;
                    }
                    this->set_state(3);
                    return RGE_ACTION_UPDATE_CONTINUE;
                }
            } else {
                switch (this->sub_actions->update()) {
                    case RGE_ACTION_UPDATE_FAILED:
                    case RGE_ACTION_UPDATE_TARGET_INVALID:
                        this->timer = -0.5f;
                        return RGE_ACTION_UPDATE_CONTINUE;
                    case RGE_ACTION_UPDATE_REMOVE:
                    case RGE_ACTION_UPDATE_COMPLETED:
                    case RGE_ACTION_UPDATE_TARGET_LOST:
                        this->set_state(3);
                        return RGE_ACTION_UPDATE_CONTINUE;
                    default:
                        return RGE_ACTION_UPDATE_CONTINUE;
                }
            }
            return RGE_ACTION_UPDATE_CONTINUE;

        case 4:
            if (this->timer < g_trade_zero_value) {
                this->timer += this->obj->owner->world->world_time_delta_seconds;
                if (this->timer > g_trade_zero_value) {
                    this->timer = 0.0f;
                    if (this->target_obj != 0) {
                        this->set_state(4);
                        return RGE_ACTION_UPDATE_CONTINUE;
                    }
                    this->set_state(3);
                    return RGE_ACTION_UPDATE_CONTINUE;
                }
            } else {
                switch (this->sub_actions->update()) {
                    case RGE_ACTION_UPDATE_REMOVE:
                    case RGE_ACTION_UPDATE_COMPLETED:
                        this->set_state(6);
                        return RGE_ACTION_UPDATE_CONTINUE;
                    case RGE_ACTION_UPDATE_FAILED:
                    case RGE_ACTION_UPDATE_TARGET_INVALID:
                        this->timer = -0.5f;
                        return RGE_ACTION_UPDATE_CONTINUE;
                    case RGE_ACTION_UPDATE_TARGET_LOST:
                        this->set_target_obj(0);
                        this->set_state(3);
                        return RGE_ACTION_UPDATE_CONTINUE;
                    default:
                        return RGE_ACTION_UPDATE_CONTINUE;
                }
            }
            return RGE_ACTION_UPDATE_CONTINUE;

        case 6:
            if (this->target_obj == 0) {
                this->set_state(3);
                return RGE_ACTION_UPDATE_CONTINUE;
            }
            if (this->obj->turn_towards(this->target_obj, 0, 0)) {
                if (this->target_obj->attribute_amount_held > g_trade_positive_amount_threshold
                    || this->obj->keepGatheringWhenObjectIsOut((short) this->target_obj->master_obj->id) != 0) {
                    this->set_state(7);
                    return RGE_ACTION_UPDATE_CONTINUE;
                }
                this->set_target_obj(0);
                this->set_state(3);
                return RGE_ACTION_UPDATE_CONTINUE;
            }
            return RGE_ACTION_UPDATE_CONTINUE;

        case 7: {
            if (this->target_obj == 0) {
                if (this->obj->attribute_amount_held > g_trade_positive_amount_threshold) {
                    this->set_state(8);
                    return RGE_ACTION_UPDATE_CONTINUE;
                }
                this->set_state(3);
                return RGE_ACTION_UPDATE_CONTINUE;
            }

            if (this->obj->attribute_type_held != RGE_RESOURCE_FOOD
                && this->obj->attribute_type_held != RGE_RESOURCE_STONE
                && this->obj->attribute_type_held != RGE_RESOURCE_WOOD) {
                this->obj->attribute_type_held = RGE_RESOURCE_WOOD;
            }

            float max_hold = (float) (int) this->obj->master_obj->attribute_max_amount;
            float give_amount = max_hold - this->obj->attribute_amount_held;
            short attribute = this->obj->attribute_type_held;
            if (this->obj->owner->attributes[attribute] < give_amount) {
                give_amount = this->obj->owner->attributes[attribute];
            }
            if (this->target_obj->owner->attributes[PLAYER_ATTRIBUTE_TRADE_GOODS] < give_amount) {
                give_amount = this->target_obj->owner->attributes[PLAYER_ATTRIBUTE_TRADE_GOODS];
            }

            this->obj->owner->add_attribute_num(attribute, -give_amount, 1);
            this->target_obj->owner->attributes[PLAYER_ATTRIBUTE_TRADE_GOODS] -= give_amount;
            this->obj->attribute_amount_held += give_amount;

            if (this->obj->attribute_amount_held >= max_hold) {
                this->set_state(8);
                return RGE_ACTION_UPDATE_CONTINUE;
            }
            if (this->target_obj->owner->attributes[PLAYER_ATTRIBUTE_TRADE_GOODS] <= g_trade_positive_amount_threshold
                && this->obj->keepGatheringWhenObjectIsOut((short) this->target_obj->master_obj->id) == 0) {
                this->set_state(8);
                return RGE_ACTION_UPDATE_CONTINUE;
            }
            return RGE_ACTION_UPDATE_CONTINUE;
        }

        case 8:
            if (this->timer < g_trade_zero_value) {
                this->timer += this->obj->owner->world->world_time_delta_seconds;
                if (this->timer > g_trade_zero_value) {
                    this->timer = 0.0f;
                    this->set_state(8);
                    return RGE_ACTION_UPDATE_CONTINUE;
                }
            } else {
                switch (this->sub_actions->update()) {
                    case RGE_ACTION_UPDATE_FAILED:
                    case RGE_ACTION_UPDATE_TARGET_INVALID:
                    case RGE_ACTION_UPDATE_TARGET_LOST:
                        this->timer = -0.5f;
                        return RGE_ACTION_UPDATE_CONTINUE;

                    case RGE_ACTION_UPDATE_REMOVE:
                    case RGE_ACTION_UPDATE_COMPLETED:
                        if (this->target_obj2 == 0) {
                            this->set_state(8);
                            return RGE_ACTION_UPDATE_CONTINUE;
                        }
                        if (this->obj->attribute_amount_held > g_trade_positive_amount_threshold) {
                            if (this->task->work_sound2 != 0) {
                                this->task->work_sound2->play(1);
                            }

                            float modifier;
                            if (this->pick_up_x < g_trade_zero_value || this->pick_up_y < g_trade_zero_value) {
                                modifier = g_trade_minimum_transfer_modifier;
                            } else {
                                float dx = this->pick_up_x - this->target_obj2->world_x;
                                float dy = this->pick_up_y - this->target_obj2->world_y;
                                modifier = (dx * dx + dy * dy) * g_trade_distance_modifier_factor;
                                modifier *= g_trade_distance_modifier_scale;
                            }
                            if (this->obj->owner->master_player_id == CIVILIZATION_PALMYRAN) {
                                modifier += modifier;
                            }
                            if (modifier < g_trade_modifier_threshold) {
                                modifier = g_trade_minimum_transfer_modifier;
                            }

                            float take_amount = this->obj->attribute_amount_held * modifier;
                            if (take_amount > g_trade_max_transfer_amount) {
                                take_amount = 75.0f;
                            }
                            //! The drop-off always credits attribute 3 (gold); the configured trade attribute is ignored.
                            //! The clamp above assigns literal 75.0f although the comparison uses the configured maximum.
                            //! RockNROR enables other resources and other drop-site units (the dock id 0x2D is hard-coded).
                            this->obj->owner->add_attribute_num(3, take_amount, 1);
                            this->obj->set_attribute(this->obj->attribute_type_held, 0.0f);
                        }

                        if (this->target_obj != 0) {
                            this->set_state(4);
                        } else {
                            this->set_state(3);
                        }
                        return RGE_ACTION_UPDATE_CONTINUE;
                    default:
                        return RGE_ACTION_UPDATE_CONTINUE;
                }
            }
            return RGE_ACTION_UPDATE_CONTINUE;

        case 13:
            this->obj->notify(this->obj->id, this->obj->id, UNIT_AI_NOTIFY_ACTION_FAILED, UNIT_AI_ACTION_TRADE, 0, 0);
            this->set_state(2);
            return RGE_ACTION_UPDATE_FAILED;

        default:
            return RGE_ACTION_UPDATE_CONTINUE;
    }
}

RGE_Sprite* TRIBE_Action_Trade::get_move_sprite(void) {
    RGE_Task* task = this->task;
    short task_facet = task->attribute_type;

    if (task_facet != -1) {
        if (this->obj->attribute_type_held == task_facet) {
            if ((int) this->obj->attribute_amount_held > 0) {
                if (task->carry_sprite != 0) {
                    return task->carry_sprite;
                }
            }
        }
    }
    return task->move_sprite;
}

RGE_Sprite* TRIBE_Action_Trade::get_wait_sprite(void) {
    TRIBE_Action_Trade* action = this;
    RGE_Task* task = action->task;
    short task_facet = task->attribute_type;

    if (task_facet != (short) 0xFFFF && task_facet == action->obj->attribute_type_held
        && (int) action->obj->attribute_amount_held > 0 && task->carry_sprite != 0) {
        return task->carry_sprite;
    }
    return action->obj->master_obj->sprite;
}

int TRIBE_Action_Trade::stop() {
    this->set_state(2);
    return 1;
}

int TRIBE_Action_Trade::move_to(RGE_Static_Object* obj_in, float x, float y, float z) {
    if (obj_in != 0) {
        if (obj_in->owner == this->obj->owner) {
            if (obj_in->master_obj->id == ((RGE_Master_Action_Object*) this->obj->master_obj)->drop_site) {
                if (obj_in == this->target_obj2 && this->state == 8) {
                    return 1;
                }
                this->set_target_obj2(obj_in);
                this->set_state(8);
                return 1;
            }
        }
    }

    // Null path: store in field-offset order.
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->set_target_obj(0);
    this->set_state(0xB);
    return 1;
}

int TRIBE_Action_Trade::work(RGE_Static_Object* obj_in, float x, float y, float z) {
    if (obj_in != 0) {
        if (obj_in == this->target_obj) {
            if (this->state == 4 || this->state == 6 || this->state == 7) {
                return 1;
            }
        }

        // Check owner/id match.
        if (obj_in->owner == this->obj->owner) {
            if (obj_in->master_obj->id == ((RGE_Master_Action_Object*) this->obj->master_obj)->drop_site) {
                this->set_target_obj2(obj_in);
                this->set_state(8);
                return 1;
            }
        }

        this->set_target_obj(obj_in);
        this->set_state(4);
        return 1;
    }

    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->set_target_obj(0);
    this->set_state(0xB);
    return 1;
}
