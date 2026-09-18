
#include "../include/act_obj.h"
#include "../include/act_list.h"
#include "../include/act_move.h"
#include "../include/game_globals.h"
#include "../include/m_ac_obj.h"
#include "../include/player.h"
#include "../include/rge_fio.h"
#include "../include/task_lst.h"
#include "../include/unit_ai_module.h"
#include "../include/world.h"
#include <stdio.h>

RGE_Action_Object::RGE_Action_Object(RGE_Master_Action_Object* tobj,
                                     RGE_Player* obj_owner, float x, float y,
                                     float z, int do_setup)
    : RGE_Moving_Object(tobj, obj_owner, x, y, z, 0) {
    this->lastActionValue = -1;
    this->lastActionStateValue = -1;
    if (do_setup != 0) {
        this->setup(tobj, obj_owner, x, y, z);
    }
}

RGE_Action_Object::RGE_Action_Object(int infile, RGE_Game_World* gworld, int do_setup)
    : RGE_Moving_Object(infile, gworld, 0) {
    this->lastActionValue = -1;
    this->lastActionStateValue = -1;
    if (do_setup != 0) {
        this->setup(infile, gworld);
    }
}

RGE_Action_Object::~RGE_Action_Object() {
    RGE_Action_List* action_list = this->actions;
    if (action_list != 0) {
        delete action_list;
        this->actions = 0;
    }
}

void RGE_Action_Object::recycle_out_of_game() {
    if (this->actions) {
        this->actions->delete_list();
    }
    RGE_Static_Object::recycle_out_of_game();
}

void RGE_Action_Object::recycle_in_to_game(RGE_Master_Static_Object* tobj, RGE_Player* obj_owner,
                                           float x, float y, float z) {
    RGE_Moving_Object::recycle_in_to_game(tobj, obj_owner, x, y, z);
    this->waiting = 0;
}

int RGE_Action_Object::setup(RGE_Master_Action_Object* tobj, RGE_Player* obj_owner,
                             float x, float y, float z) {
    RGE_Moving_Object::setup(tobj, obj_owner, x, y, z);
    this->type = 0x28;
    this->waiting = 0;
    this->actions = this->create_action_list();
    this->command_flag = 0;
    return 1;
}

int RGE_Action_Object::setup(int infile, RGE_Game_World* gworld) {
    RGE_Moving_Object::setup(infile, gworld);
    this->type = 0x28;
    rge_read(infile, &this->waiting, 1);
    if (save_game_version >= 6.5f) {
        rge_read(infile, &this->command_flag, 1);
    } else {
        this->command_flag = 0;
    }
    this->actions = this->create_action_list();
    this->actions->load(infile);
    return 1;
}

RGE_Action_List* RGE_Action_Object::create_action_list(void) {
    return new RGE_Action_List(this);
}

void RGE_Action_Object::rehook() {
    RGE_Static_Object::rehook();
    this->actions->rehook();
}

void RGE_Action_Object::save(int outfile) {
    RGE_Moving_Object::save(outfile);
    rge_write(outfile, &this->waiting, 1);
    rge_write(outfile, &this->command_flag, 1);
    this->actions->save(outfile);
}

void RGE_Action_Object::transform(RGE_Master_Static_Object* obj) {
    RGE_Moving_Object::transform(obj);
    this->actions->delete_list();
}

void RGE_Action_Object::destroy_obj(void) {
    this->actions->delete_list();
    RGE_Static_Object::destroy_obj();
}

void RGE_Action_Object::notify_of_relation(long player_id, uchar relation) {
}

void RGE_Action_Object::do_command(RGE_Static_Object* obj, float x, float y, float z) {
    if (obj != this) {
        this->work2(obj, x, y, z, 0);
        this->command_flag = this->command_flag + 1;
    }
}

void RGE_Action_Object::move_to(RGE_Static_Object* obj, float x, float y, float z) {
    if (obj != this) {
        if (this->actions->action_move_to(obj, x, y, z) == 0) {
            RGE_Action_Move_To* action;

            if (obj != 0) {
                action = new RGE_Action_Move_To(this, obj, 0.4f, 0);
            } else {
                action = new RGE_Action_Move_To(this, x, y, z, 0.4f, 0);
            }

            if (this->unitAIValue != 0) {
                this->unitAIValue->setCurrentOrder(0x2C6);
                this->unitAIValue->setCurrentAction(0x262);
                if (obj != 0) {
                    this->unitAIValue->setCurrentTarget(obj->id, obj->master_obj->object_group, x, y, z);
                } else {
                    this->unitAIValue->setCurrentTarget(-1, -1, x, y, z);
                }
            }

            if (action != 0) {
                this->set_only_action(action);
            }
            this->command_flag = this->command_flag + 1;
        }
    }
}

void RGE_Action_Object::work(RGE_Static_Object* obj, float x, float y, float z) {
    if (obj != this) {
        this->work2(obj, x, y, z, 1);
        this->command_flag = this->command_flag + 1;
    }
}

void RGE_Action_Object::work2(RGE_Static_Object* obj, float x, float y, float z,
                              unsigned char work_flag) {
    int skip;
    RGE_Task* task;
    RGE_Action* action;
    RGE_Task* current_task;
    short actionType;
    RGE_Master_Static_Object* other;
    int i;
    int order;
    int current_action;

    if (obj != this) {
        task = static_cast<RGE_Master_Action_Object*>(this->master_obj)
                   ->tasks->get_target_task(this, obj, x, y, z);
        if (task == 0 && static_cast<RGE_Master_Action_Object*>(this->master_obj) ->task_by_group != 0) {
            i = 0;
            for (; i < this->owner->master_object_num; i++) {
                other = this->owner->master_objects[i];
                if (other != 0 && other->object_group == this->master_obj->object_group &&
                    other->master_type == this->master_obj->master_type &&
                    static_cast<RGE_Master_Action_Object*>(other)->task_by_group ==
                    static_cast<RGE_Master_Action_Object*>(this->master_obj) ->task_by_group) {
                    task = static_cast<RGE_Master_Action_Object*>(other)
                               ->tasks->get_target_task(this, obj, x, y, z);
                    if (task != 0) {
                        this->transform(other);
                        break;
                    }
                }
            }
        }

        current_task = this->actions->get_task();
        skip = 0;
        actionType = -1;
        if (current_task != 0 && task == current_task && this->actions->action_work(obj, x, y, z) != 0) {
            actionType = this->actions->get_action()->type();
            skip = 1;
        }

        if (this->actions->have_action() == 1) {
            if (this->actions->get_action()->get_target_obj() == obj && this->actions->get_action()->type() == 9) {
                if (this->actions->get_action()->work(obj, x, y, z) != 0) {
                    actionType = this->actions->get_action()->type();
                    skip = 1;
                }
            }
        }

        if (skip == 0) {
            if (task != 0) {
                action = this->actions->create_task_action(task, obj, x, y, z);
            } else {
                action = 0;
            }
            if (action != 0) {
                actionType = action->type();
                this->set_only_action(action);
            } else {
                actionType = 1;
                this->move_to(obj, x, y, z);
            }
        }

        if (this->unitAIValue != 0) {
            order = -1;
            current_action = -1;
            switch (actionType) {
            case 9:
                current_action = 0x258;
                order = 0x2BC;
                break;
            case 0x65:
                current_action = 0x25A;
                order = 0x2BE;
                break;
            case 3:
                current_action = 0x269;
                order = 0x2CD;
                break;
            case 4:
                current_action = 0x25D;
                order = 0x2C1;
                break;
            case 5:
                current_action = 0x261;
                order = 0x2C5;
                break;
            case 1:
                current_action = 0x262;
                order = 0x2C6;
                break;
            case 0x6E:
                current_action = 0x265;
                order = 0x2C9;
                break;
            case 0x0C:
                current_action = 0x266;
                order = 0x2CA;
                break;
            case 0x6F:
                current_action = 0x267;
                order = 0x2CB;
                break;
            case 0x68:
                current_action = 0x25C;
                order = 0x2C0;
                break;
            case 0x69:
                current_action = 0x25B;
                order = 0x2BF;
                break;
            case 0x6A:
                current_action = 0x26A;
                order = 0x2CE;
                break;
            }

            this->unitAIValue->setCurrentOrder(order);
            this->unitAIValue->setCurrentAction(current_action);
            if (obj != 0) {
                this->unitAIValue->setCurrentTarget(obj->id, obj->master_obj->object_group, x, y, z);
            } else {
                this->unitAIValue->setCurrentTarget(-1, -1, x, y, z);
            }
            this->unitAIValue->setTaskedByPlayer();
        }
    }
}

void RGE_Action_Object::set_attack(RGE_Static_Object* obj) {
}

void RGE_Action_Object::play_command_sound() {
    this->master_obj->play_command_sound();
}

void RGE_Action_Object::play_move_sound() {
    this->master_obj->play_move_sound();
}

RGE_Master_Static_Object* RGE_Action_Object::get_command_master(
    RGE_Static_Object* obj, float x, float y, float z) {
    int i;
    RGE_Master_Static_Object* master_obj;
    RGE_Task* task;

    if (obj != this) {
        if (static_cast<RGE_Master_Action_Object*>(this->master_obj) ->task_by_group != 0) {
            task = static_cast<RGE_Master_Action_Object*>(this->master_obj)
                       ->tasks->get_target_task(this, obj, x, y, z);
            if (task != 0) {
                return this->master_obj;
            }

            if (static_cast<RGE_Master_Action_Object*>(this->master_obj) ->task_by_group != 0) {
                for (i = 0; i < this->owner->master_object_num; i++) {
                    master_obj = this->owner->master_objects[i];
                    if (master_obj != 0 && master_obj->object_group == this->master_obj->object_group &&
                        master_obj->master_type == this->master_obj->master_type &&
                        static_cast<RGE_Master_Action_Object*>(master_obj) ->task_by_group ==
                        static_cast<RGE_Master_Action_Object*>(this->master_obj)->task_by_group) {
                        task = static_cast<RGE_Master_Action_Object*>(master_obj)
                                   ->tasks->get_target_task(this, obj, x, y, z);
                        if (task != 0) {
                            return master_obj;
                        }
                    }
                }
            }
        }
    }

    return this->master_obj;
}

void RGE_Action_Object::set_task(short task_id) {
    RGE_Task* task;
    RGE_Action* action;
    RGE_Master_Action_Object* master =
        static_cast<RGE_Master_Action_Object*>(this->master_obj);

    task = master->get_task(task_id);
    if (task != 0) {
        action = this->actions->create_task_action(task, 0, -1.0f, -1.0f, -1.0f);
        if (action != 0) {
            this->set_only_action(action);
        }
    }
}

void RGE_Action_Object::setTaskByTaskID(int t) {
    RGE_Task* task;
    RGE_Action* action;
    RGE_Master_Action_Object* master =
        static_cast<RGE_Master_Action_Object*>(this->master_obj);

    task = master->getTaskByTaskID(t);
    if (task != 0) {
        action = this->actions->create_task_action(task, 0, -1.0f, -1.0f, -1.0f);
        if (action != 0) {
            this->set_only_action(action);
        }
    }
}

void RGE_Action_Object::set_action(RGE_Action* action) {
    if (action != 0) {
        this->actions->add_action(action);
    }
}

void RGE_Action_Object::set_only_action(RGE_Action* action) {
    this->actions->delete_list();
    if (action != 0) {
        this->actions->add_action(action);
    }
}

void RGE_Action_Object::set_end_action(RGE_Action* action) {
    if (action) {
        this->actions->add_action_at_end(action);
    }
}

void RGE_Action_Object::stop(void) {
    if (this->actions->action_stop() == 0) {
        this->actions->delete_list();
    }
}

unsigned char RGE_Action_Object::update() {
    if (actionFile != 0) {
        int action_value;
        int action_state_value;

        if (this->actions->have_action() != 0) {
            action_value = this->actions->get_action()->type();
            action_state_value = this->actions->get_action()->state;
        } else {
            action_value = -1;
            action_state_value = -1;
        }

        if (this->lastActionValue != action_value || this->lastActionStateValue != action_state_value) {
            fprintf(actionFile, "t%d, %d,%d,%d,%d,%d\\n", this->owner->world->world_time, this->id, this->lastActionValue,
                    this->lastActionStateValue, action_value, action_state_value);
            this->lastActionValue = action_value;
            this->lastActionStateValue = action_state_value;
        }
    }

    unsigned char result = RGE_Animated_Object::update();
    unsigned char state = this->object_state;

    if (state > 2) {
        if (this->actions->list != 0) {
            this->actions->delete_list();
            return result;
        }
    } else {
        if (this->actions->list == 0) {
            if (state == 2 && static_cast<RGE_Master_Action_Object*>(this->master_obj) ->default_task != -1) {
                this->set_task(static_cast<RGE_Master_Action_Object*>(this->master_obj)->default_task);
                return result;
            }
        } else {
            if (this->inside_obj != 0) {
                this->actions->inside_obj_update();
                return result;
            }

            unsigned char action_result = this->actions->update();
            if (action_result == 3 || action_result == 1) {
                this->actions->remove_action();
            }
        }
    }

    return result;
}

void RGE_Action_Object::change_ownership(RGE_Player* new_owner) {
    this->stop();
    RGE_Static_Object::change_ownership(new_owner);
    this->set_only_action(0);
}

void RGE_Action_Object::copy_obj(RGE_Master_Static_Object* source) {
    this->actions->copy_obj(static_cast<RGE_Master_Action_Object*>(source));
    RGE_Moving_Object::copy_obj(source);
}

unsigned char RGE_Action_Object::have_action(void) {
    if (this->actions->have_action()) {
        return 1;
    }
    return 0;
}

RGE_Static_Object* RGE_Action_Object::get_target_obj(void) {
    RGE_Action* action;
    RGE_Static_Object* target_obj;

    action = this->actions->get_action();
    if (action != 0) {
        return action->get_target_obj();
    }
    target_obj = 0;
    return target_obj;
}

RGE_Task* RGE_Action_Object::getTask(RGE_Static_Object* target, float targetX, float targetY, float targetZ) {
    RGE_Task* task = static_cast<RGE_Master_Action_Object*>(this->master_obj)
                           ->tasks->get_target_task(this, target, targetX, targetY, targetZ);
    if (task == 0 && static_cast<RGE_Master_Action_Object*>(this->master_obj)->task_by_group != 0) {
        int i = 0;
        if (this->owner->master_object_num > 0) {
            RGE_Master_Static_Object* obj;
            while (1) {
                obj = this->owner->master_objects[i];
                if (obj != 0 && obj->object_group == this->master_obj->object_group &&
                    obj->master_type == this->master_obj->master_type &&
                    static_cast<RGE_Master_Action_Object*>(obj)->task_by_group ==
                    static_cast<RGE_Master_Action_Object*>(this->master_obj) ->task_by_group) {
                    task = static_cast<RGE_Master_Action_Object*>(obj)
                               ->tasks->get_target_task(this, target, targetX, targetY, targetZ);
                    if (task != 0) {
                        goto found;
                    }
                }
                i++;
                if (i < this->owner->master_object_num) continue;
                return task;
            }
found:
            this->transform(obj);
        }
    }
    return task;
}

unsigned char RGE_Action_Object::actionState(void) const {
    if (this->actions->have_action() == 1) {
        return this->actions->get_action()->state;
    }
    return 0;
}

long RGE_Action_Object::get_action_checksum(void) {
    RGE_Action* action;
    long checksum;

    checksum = 0;
    if (this->actions != 0) {
        action = this->actions->get_action();
        if (action != 0) {
            checksum = (int)action->action_type + (unsigned int)action->state;
        }
    }
    return checksum;
}
