
#include <stdio.h>
#include "../include/tact_rep.h"
#include "../include/act_move.h"
#include "../include/basegame.h"
#include "../include/game_globals.h"
#include "../include/m_co_obj.h"
#include "../include/obj_list.h"
#include "../include/rge_base_game_global.h"
#include "../include/rge_fio.h"
#include "../include/sound.h"
#include "../include/act_list.h"
#include "../include/act_obj.h"
#include "../include/m_s_obj.h"
#include "../include/m_ac_obj.h"
#include "../include/move_obj.h"
#include "../include/world.h"
#include "../include/player.h"
#include "../include/task.h"


// The constructor keeps the period base initialization and conditional setup.
TRIBE_Action_Repair::TRIBE_Action_Repair(int infile, RGE_Action_Object* obj_in,
                                         int do_setup)
    : RGE_Action(infile, obj_in, 0) {
    this->action_type = TRIBE_ACTION_TYPE_REPAIR;
    if (do_setup != 0) {
        this->setup(infile, obj_in);
    }
}

TRIBE_Action_Repair::TRIBE_Action_Repair(RGE_Action_Object* obj_in,
                                         RGE_Task* task_in,
                                         RGE_Static_Object* target_obj_in)
    : RGE_Action(obj_in, 1) {
    this->task = task_in;
    this->action_type = TRIBE_ACTION_TYPE_REPAIR;
    this->save_target_command_flag = 0;
    this->set_target_obj(target_obj_in);
    if (target_obj_in != 0) {
        this->target_x = target_obj_in->world_x;
        this->target_y = target_obj_in->world_y;
        this->target_z = target_obj_in->world_z;
        this->meet_target();
    }
}

TRIBE_Action_Repair::TRIBE_Action_Repair(RGE_Action_Object* obj_in,
                                         RGE_Task* task_in,
                                         float x, float y, float z)
    : RGE_Action(obj_in, 1) {
    this->task = task_in;
    this->action_type = TRIBE_ACTION_TYPE_REPAIR;
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->save_target_command_flag = 0;
}

int TRIBE_Action_Repair::setup(int infile, RGE_Action_Object* obj_in) {
    int result = RGE_Action::setup(infile, obj_in);
    if (save_game_version >= 6.5f) {
        rge_read(infile, &this->save_target_command_flag, 1);
    } else {
        this->save_target_command_flag = 0;
    }
    return result;
}

void TRIBE_Action_Repair::save(int outfile) {
    RGE_Action::save(outfile);
    rge_write(outfile, &this->save_target_command_flag, 1);
}

void TRIBE_Action_Repair::first_in_stack(unsigned char first_time) {
    if (first_time != 0 && this->target_obj != 0) {
        this->set_state(4);
        return;
    }
    this->set_state(3);
}

void TRIBE_Action_Repair::set_state(unsigned char new_state) {
    this->sub_actions->delete_list();
    this->state = new_state;

    switch (new_state) {
    case 3:
        this->obj->notify(this->obj->id, this->obj->id, UNIT_AI_NOTIFY_REQUEST_TASK, UNIT_AI_ACTION_REPAIR, 0, 0);
        break;

    case 11: {
        RGE_Action_Move_To* action = new RGE_Action_Move_To(this->obj, this->target_x, this->target_y, this->target_z,
                                                            0.0f, this->task->move_sprite);
        if (action == 0) {
            this->set_state(0x0d);
            return;
        }
        action->setSubAction(1);
        this->sub_actions->add_action(action);
        return;
    }

    case 4: {
        if (this->target_obj != 0) {
            this->target_x = this->target_obj->world_x;
            this->target_y = this->target_obj->world_y;
            this->target_z = this->target_obj->world_z;
        }
        RGE_Action_Move_To* action = new RGE_Action_Move_To(this->obj, this->target_obj,
                                                            ((RGE_Master_Combat_Object*)this->obj->master_obj)->weapon_range, this->task->move_sprite);
        if (action == 0) {
            this->set_state(0x0d);
            return;
        }
        this->sub_actions->add_action(action);
        action->setSubAction(1);
        return;
    }

    //! @bug Out-of-range aborts route to state 10, which creates no sub-action.
    //! The empty list then reports done, so set_state(1) finishes the repair as success.
    //! UnitAI stops the order and the repairman stays idle forever.
    case 10: {
        this->obj->new_sprite(this->obj->master_obj->sprite);
        this->timer = 1.0f;
        RGE_Static_Object* target = this->target_obj;
        if (target == 0) return;
        short id = target->master_obj->object_group;
        if (id != OBJECT_GROUP_TRADE_BOAT && id != OBJECT_GROUP_TRANSPORT_BOAT && id != OBJECT_GROUP_FISHING_BOAT && id != OBJECT_GROUP_WAR_BOAT) return;
        if (((RGE_Action_Object*)target)->command_flag != this->save_target_command_flag) return;
        target->moveTo(this->obj->world_x, this->obj->world_y, this->obj->world_z, 0, 1);
        return;
    }

    case 6:
        this->target_x = this->target_obj->world_x;
        this->target_y = this->target_obj->world_y;
        this->target_z = this->target_obj->world_z;
        this->obj->new_sprite(this->task->move_sprite);
        return;

    case 7:
        this->obj->new_sprite(this->task->work_sprite);
        if (this->task->work_sound != 0) {
            this->task->work_sound->play(1);
            return;
        }
        return;

    case 1:
        this->set_target_obj(0);
        if (this->subActionValue == 0) {
            this->obj->notify(this->obj->id, this->obj->id, UNIT_AI_NOTIFY_ACTION_COMPLETED, UNIT_AI_ACTION_REPAIR, 0, 0);
        }
        break;

    case 2:
        break;

    default:
        return;
    }

    this->obj->new_sprite(this->obj->master_obj->sprite);
}

unsigned char TRIBE_Action_Repair::update() {
    RGE_Static_Object* check_target;
    RGE_Static_Object* target;

    if (this->targetID != -1) {
        if (this->obj->owner->world->object(this->targetID) == 0) {
            goto invalid_target;
        }
    }

    if (this->target2ID != -1) {
        if (this->obj->owner->world->object(this->target2ID) == 0) {
            this->set_target_obj2(0);
        }
    }

    check_target = this->target_obj;
    if (check_target != 0) {
        if (check_target->object_state != RGE_OBJECT_STATE_ACTIVE) {
            goto invalid_target;
        }
        if (this->target_obj != 0 && this->obj->owner->isAlly(this->target_obj->owner->id) == 0) {
            goto invalid_target;
        }
    }

    switch (this->state) {
    case 11:
        switch (this->sub_actions->update()) {
        case 4:
            this->set_target_obj(0);
            this->set_state(0x0B);
            return 0;
        case 1:
        case 2:
        case 3:
        case 5:
            this->set_state(1);
            return 0;
        }
        break;

    case 12:
        break;

    case 4:
        switch (this->sub_actions->update()) {
        case 1:
        case 2:
        case 3:
            break;
        case 4:
        case 5:
            goto invalid_target;
        default:
            goto update_done;
        }

        target = this->target_obj;
        repair_target_distance = this->obj->distance_to_object(target) - g_repair_distance_offset;
        if (repair_target_distance <= g_repair_distance_threshold) {
            this->set_state(6);
            return 0;
        }
        this->set_state(10);
        return 0;

    case 6:
        if (this->target_obj == 0) {
            this->set_state(1);
            return 0;
        }
        if (this->obj->turn_towards(this->target_obj, 0, 0) != 0) {
            this->set_state(7);
            return 0;
        }
        break;

    case 7: {
        if (this->target_obj == 0) {
            this->set_state(1);
            return 0;
        }
        if (this->target_obj->world_x != this->target_x || this->target_y != this->target_obj->world_y) {
            repair_target_distance =
                this->obj->distance_to_object(this->target_obj) - g_repair_distance_offset;
            if (repair_target_distance > g_repair_distance_threshold) {
                this->set_state(3);
                return 0;
            }
            this->target_x = this->target_obj->world_x;
            this->target_y = this->target_obj->world_y;
            this->target_z = this->target_obj->world_z;
            return 0;
        }

        unsigned char result = this->target_obj->heal((float)(this->task->work_val1 *
                                                              this->obj->owner->world->world_time_delta_seconds) *
                                                      ((RGE_Master_Action_Object*)this->obj->master_obj)->work_rate);
        if (result == 1) {
            this->set_state(1);
            return 0;
        }
        if (result == 2) {
            this->obj->notify(this->obj->id, this->obj->id, UNIT_AI_NOTIFY_TARGET_INVALID, UNIT_AI_ACTION_REPAIR, 0, 0);
            rge_base_game->notification(0x6B, this->obj->owner->id, this->target_obj->id, 0, 0);
            this->set_state(2);
            return 0;
        }
        break;
    }

    case 9:
        break;

    case 10:
        if (this->target_obj == 0) {
            break;
        }
        this->timer -= this->obj->owner->world->world_time_delta_seconds;
        if (this->timer <= 0.0f) {
            repair_target_distance =
                this->obj->distance_to_object(this->target_obj) - g_repair_distance_offset;
            if (repair_target_distance <= g_repair_distance_threshold) {
                this->set_state(6);
                return 0;
            }
            this->timer = 1.0f;
            return 0;
        }
        break;

    case 1:
        return 1;

    case 13:
        this->obj->notify(this->obj->id, this->obj->id, UNIT_AI_NOTIFY_ACTION_FAILED, UNIT_AI_ACTION_REPAIR, 0, 0);
        this->set_state(2);
        return 3;
    }

update_done:
    return 0;

invalid_target:
    this->set_target_obj(0);
    this->set_state(1);
    return 0;
}

int TRIBE_Action_Repair::stop() {
    this->set_state(2);
    return 1;
}

int TRIBE_Action_Repair::move_to(RGE_Static_Object* obj_in, float x, float y, float z) {
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->set_target_obj(0);
    this->set_state(0x0B);
    return 1;
}

int TRIBE_Action_Repair::work(RGE_Static_Object* obj_in, float x, float y, float z) {
    if (obj_in != 0) {
        if (obj_in == this->target_obj) {
            unsigned char state = this->state;
            if (state == 4 || state == 6) {
                return 1;
            }
        }
        this->set_target_obj(obj_in);
        this->target_x = obj_in->world_x;
        this->target_y = obj_in->world_y;
        this->target_z = obj_in->world_z;
        this->meet_target();
        this->set_state(4);
        return 1;
    }
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->set_target_obj(0);
    this->set_state(11);
    return 1;
}

void TRIBE_Action_Repair::meet_target() {
    XYPoint rVal;
    XYPoint start;
    XYPoint dest;
    short type = this->target_obj->master_obj->object_group;

    if (type == OBJECT_GROUP_TRADE_BOAT || type == OBJECT_GROUP_TRANSPORT_BOAT || type == OBJECT_GROUP_FISHING_BOAT || type == OBJECT_GROUP_WAR_BOAT) {
        RGE_Object_Node* node = this->obj->owner->objects->list;
        while (node != 0) {
            RGE_Static_Object* action = node->node;
            if (action != this->obj && action->master_obj->id == 0x9C) {
                if (action->get_target_obj() == this->target_obj && action->actionState() != 2) {
                    if (this->target_obj->actionState() == 0x0B) {
                        this->target_x =
                            ((RGE_Action_Object*)this->target_obj)
                                ->actions->get_action()->targetX();
                        this->target_y =
                            ((RGE_Action_Object*)this->target_obj)
                                ->actions->get_action()->targetY();
                    } else {
                        this->target_x = this->target_obj->world_x;
                        this->target_y = this->target_obj->world_y;
                    }
                    return;
                }
            }
            node = node->next;
        }

        dest.x = (int)this->obj->world_x;
        dest.y = (int)this->obj->world_y;
        start.x = (int)this->target_obj->world_x;
        start.y = (int)this->target_obj->world_y;
        if (this->obj->firstTileAlongLine(dest, start, rVal, 2, 2, 1) == 1) {
            this->target_x = (float)rVal.x + 0.5f;
            this->target_y = (float)rVal.y + 0.5f;
            this->target_obj->moveTo((float)rVal.x + 0.5f, (float)rVal.y + 0.5f, this->target_obj->world_z, 0.0f, 1);
            this->save_target_command_flag =
                ((RGE_Action_Object*)this->target_obj)->command_flag;
        }
    }
}
