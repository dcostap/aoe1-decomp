#include "../include/RGE_Action_Object.h"

#include "../include/RGE_Action.h"
#include "../include/RGE_Action_List.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Action_Object.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Task.h"
#include "../include/RGE_Task_List.h"
#include "../include/UnitAIModule.h"
#include "../include/globals.h"

#include <stdio.h>

namespace {
static RGE_Task* action_object_get_task_by_id(RGE_Master_Action_Object* master, short task_id) {
    if (master == nullptr || master->tasks == nullptr || task_id < 0) {
        return nullptr;
    }

    for (short i = 0; i < master->tasks->list_num; ++i) {
        if (master->tasks->list != nullptr && master->tasks->list[i] != nullptr && master->tasks->list[i]->id == task_id) {
            return master->tasks->list[i];
        }
    }
    return nullptr;
}

static RGE_Task* action_object_get_task_by_task_id(RGE_Master_Action_Object* master, int task_type_id) {
    if (master == nullptr || master->tasks == nullptr) {
        return nullptr;
    }

    for (short i = 0; i < master->tasks->list_num; ++i) {
        if (master->tasks->list != nullptr && master->tasks->list[i] != nullptr && master->tasks->list[i]->task_type == task_type_id) {
            return master->tasks->list[i];
        }
    }
    return nullptr;
}

static void action_object_set_current_order(UnitAIModule* unit_ai, int order_value) {
    if (unit_ai == nullptr) {
        return;
    }
    unit_ai->lastOrderValue = unit_ai->currentOrderValue;
    unit_ai->currentOrderValue = order_value;
}

static void action_object_set_current_action(UnitAIModule* unit_ai, int action_value) {
    if (unit_ai == nullptr) {
        return;
    }
    unit_ai->lastActionValue = unit_ai->currentActionValue;
    unit_ai->currentActionValue = action_value;
}

static void action_object_set_current_target(UnitAIModule* unit_ai, long target_id, int target_type, float x, float y, float z) {
    if (unit_ai == nullptr) {
        return;
    }
    unit_ai->lastTargetValue = unit_ai->currentTargetValue;
    unit_ai->lastTargetTypeValue = unit_ai->currentTargetTypeValue;
    unit_ai->currentTargetValue = (int)target_id;
    unit_ai->currentTargetTypeValue = target_type;
    unit_ai->currentTargetXValue = x;
    unit_ai->currentTargetYValue = y;
    unit_ai->currentTargetZValue = z;
}

static void action_object_set_tasked_by_player(UnitAIModule* unit_ai) {
    if (unit_ai == nullptr) {
        return;
    }
    unit_ai->notifyQueueSizeValue = 0;
    unit_ai->secondaryTimerValue = 0;
}
}

RGE_Action_Object::RGE_Action_Object()
    : RGE_Moving_Object() {
    this->lastActionValue = -1;
    this->lastActionStateValue = -1;
    this->waiting = '\0';
    this->actions = nullptr;
    this->command_flag = '\0';
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x00405C60
RGE_Action_Object::RGE_Action_Object(RGE_Master_Action_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6)
    : RGE_Moving_Object() {
    this->lastActionValue = -1;
    this->lastActionStateValue = -1;
    this->waiting = '\0';
    this->actions = nullptr;
    this->command_flag = '\0';

    if (param_6 != 0) {
        this->setup(param_1, param_2, param_3, param_4, param_5);
    }
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x00405F90
RGE_Action_Object::RGE_Action_Object(int param_1, RGE_Game_World* param_2, int param_3)
    : RGE_Moving_Object(param_1, param_2, 0) {
    this->lastActionValue = -1;
    this->lastActionStateValue = -1;
    this->waiting = '\0';
    this->actions = nullptr;
    this->command_flag = '\0';

    if (param_3 != 0) {
        this->setup(param_1, param_2);
    }
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x00406010
RGE_Action_Object::~RGE_Action_Object() {
    if (this->actions != nullptr) {
        delete this->actions;
        this->actions = nullptr;
    }
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x00406080
void RGE_Action_Object::recycle_out_of_game() {
    if (this->actions != nullptr) {
        this->actions->delete_list();
    }
    RGE_Static_Object::recycle_out_of_game();
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x004060A0
void RGE_Action_Object::recycle_in_to_game(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) {
    RGE_Moving_Object::recycle_in_to_game(param_1, param_2, param_3, param_4, param_5);
    this->waiting = '\0';
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x004060D0
int RGE_Action_Object::setup(RGE_Master_Action_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) {
    RGE_Moving_Object::setup((RGE_Master_Moving_Object*)param_1, param_2, param_3, param_4, param_5);
    this->type = 0x28;
    this->waiting = '\0';
    this->actions = this->create_action_list();
    this->command_flag = '\0';
    return 1;
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x00406120
int RGE_Action_Object::setup(int param_1, RGE_Game_World* param_2) {
    RGE_Moving_Object::setup(param_1, param_2);
    this->type = 0x28;

    rge_read(param_1, &this->waiting, 1);
    if (save_game_version < 6.5f) {
        this->command_flag = '\0';
    } else {
        rge_read(param_1, &this->command_flag, 1);
    }

    this->actions = this->create_action_list();
    if (this->actions != nullptr) {
        this->actions->load(param_1);
    }
    return 1;
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x004061A0
RGE_Action_List* RGE_Action_Object::create_action_list() {
    RGE_Action_List* list = new RGE_Action_List(this);
    return list;
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x00406200
void RGE_Action_Object::rehook() {
    RGE_Static_Object::rehook();
    if (this->actions != nullptr) {
        this->actions->rehook();
    }
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x00406220
void RGE_Action_Object::save(int param_1) {
    RGE_Moving_Object::save(param_1);
    rge_write(param_1, &this->waiting, 1);
    rge_write(param_1, &this->command_flag, 1);
    if (this->actions != nullptr) {
        this->actions->save(param_1);
    }
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x00406270
void RGE_Action_Object::transform(RGE_Master_Static_Object* param_1) {
    RGE_Moving_Object::transform(param_1);
    if (this->actions != nullptr) {
        this->actions->delete_list();
    }
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x00406290
void RGE_Action_Object::destroy_obj() {
    if (this->actions != nullptr) {
        this->actions->delete_list();
    }
    RGE_Static_Object::destroy_obj();
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x004062B0
void RGE_Action_Object::notify_of_relation(long param_1, uchar param_2) {
    (void)param_1;
    (void)param_2;
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x004062C0
void RGE_Action_Object::do_command(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    if ((RGE_Action_Object*)param_1 != this) {
        this->work2(param_1, param_2, param_3, param_4, 0);
        this->command_flag = this->command_flag + 1;
    }
}

// Source of truth: act_obj.cpp.decomp @ 0x00406300
void RGE_Action_Object::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    if ((RGE_Action_Object*)param_1 == this) {
        return;
    }

    if (this->actions != nullptr && this->actions->action_move_to(param_1, param_2, param_3, param_4) != 0) {
        return;
    }

    // TODO: STUB - RGE_Action_Move_To subclass constructor is not transliterated yet.
    RGE_Action* action = new RGE_Action();
    if (action != nullptr) {
        action->setup(this);
        action->action_type = 1;
        if (param_1 == nullptr) {
            action->target_x = param_2;
            action->target_y = param_3;
            action->target_z = param_4;
        } else {
            action->set_target_obj(param_1);
        }
    }

    if (this->unitAIValue != nullptr) {
        action_object_set_current_order(this->unitAIValue, 0x2C6);
        action_object_set_current_action(this->unitAIValue, 0x262);
        if (param_1 == nullptr) {
            action_object_set_current_target(this->unitAIValue, -1, -1, param_2, param_3, param_4);
        } else {
            int target_type = (param_1->master_obj != nullptr) ? (int)param_1->master_obj->object_group : -1;
            action_object_set_current_target(this->unitAIValue, param_1->id, target_type, param_2, param_3, param_4);
        }
    }

    if (action != nullptr) {
        this->set_only_action(action);
    }

    this->command_flag = this->command_flag + 1;
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x00406430
void RGE_Action_Object::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    if ((RGE_Action_Object*)param_1 != this) {
        this->work2(param_1, param_2, param_3, param_4, 1);
        this->command_flag = this->command_flag + 1;
    }
}

// Source of truth: act_obj.cpp.decomp @ 0x00406470
void RGE_Action_Object::work2(RGE_Static_Object* param_1, float param_2, float param_3, float param_4, uchar param_5) {
    (void)param_5;
    if ((RGE_Action_Object*)param_1 == this) {
        return;
    }

    RGE_Task* new_task = this->getTask(param_1, param_2, param_3, param_4);
    RGE_Task* cur_task = (this->actions != nullptr) ? this->actions->get_task() : nullptr;
    short action_type = -1;
    int reused_action = 0;

    if (cur_task != nullptr && new_task == cur_task && this->actions != nullptr &&
        this->actions->action_work(param_1, param_2, param_3, param_4) != 0) {
        RGE_Action* action = this->actions->get_action();
        if (action != nullptr) {
            action_type = action->type();
            reused_action = 1;
        }
    }

    if (!reused_action && this->actions != nullptr && this->actions->have_action()) {
        RGE_Action* action = this->actions->get_action();
        if (action != nullptr && action->get_target_obj() == param_1 && action->type() == 9) {
            if (action->work(param_1, param_2, param_3, param_4) != 0) {
                action_type = action->type();
                reused_action = 1;
            }
        }
    }

    if (!reused_action) {
        RGE_Action* action = nullptr;
        if (new_task != nullptr && this->actions != nullptr) {
            action = this->actions->create_task_action(new_task, param_1, param_2, param_3, param_4);
        }
        if (action == nullptr) {
            action_type = 1;
            this->move_to(param_1, param_2, param_3, param_4);
        } else {
            action_type = action->type();
            this->set_only_action(action);
        }
    }

    UnitAIModule* unit_ai = this->unitAIValue;
    if (unit_ai != nullptr) {
        int order_value = -1;
        int action_value = -1;

        switch (action_type) {
        case 1:
            action_value = 0x262;
            order_value = 0x2C6;
            break;
        case 3:
            action_value = 0x269;
            order_value = 0x2CD;
            break;
        case 4:
            action_value = 0x25D;
            order_value = 0x2C1;
            break;
        case 5:
            action_value = 0x261;
            order_value = 0x2C5;
            break;
        case 9:
            action_value = 600;
            order_value = 700;
            break;
        case 0x0C:
            action_value = 0x266;
            order_value = 0x2CA;
            break;
        case 0x65:
            action_value = 0x25A;
            order_value = 0x2BE;
            break;
        case 0x68:
            action_value = 0x25C;
            order_value = 0x2C0;
            break;
        case 0x69:
            action_value = 0x25B;
            order_value = 0x2BF;
            break;
        case 0x6A:
            action_value = 0x26A;
            order_value = 0x2CE;
            break;
        case 0x6E:
            action_value = 0x265;
            order_value = 0x2C9;
            break;
        case 0x6F:
            action_value = 0x267;
            order_value = 0x2CB;
            break;
        default:
            break;
        }

        action_object_set_current_order(unit_ai, order_value);
        action_object_set_current_action(unit_ai, action_value);
        if (param_1 == nullptr) {
            action_object_set_current_target(unit_ai, -1, -1, param_2, param_3, param_4);
        } else {
            int target_type = (param_1->master_obj != nullptr) ? (int)param_1->master_obj->object_group : -1;
            action_object_set_current_target(unit_ai, param_1->id, target_type, param_2, param_3, param_4);
        }
        action_object_set_tasked_by_player(unit_ai);
    }
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x00406830
void RGE_Action_Object::set_attack(RGE_Static_Object* param_1) {
    (void)param_1;
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x00406840
void RGE_Action_Object::play_command_sound() {
    RGE_Master_Action_Object* master = (RGE_Master_Action_Object*)this->master_obj;
    if (master != nullptr) {
        master->play_command_sound();
    }
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x00406850
void RGE_Action_Object::play_move_sound() {
    RGE_Master_Action_Object* master = (RGE_Master_Action_Object*)this->master_obj;
    if (master != nullptr) {
        master->play_move_sound();
    }
}

// Source of truth: act_obj.cpp.decomp @ 0x00406860
RGE_Master_Static_Object* RGE_Action_Object::get_command_master(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    (void)param_2;
    (void)param_3;
    (void)param_4;
    return this->master_obj;
}

// Source of truth: act_obj.cpp.decomp @ 0x00406940
void RGE_Action_Object::set_task(short param_1) {
    RGE_Master_Action_Object* master = (RGE_Master_Action_Object*)this->master_obj;
    RGE_Task* task = action_object_get_task_by_id(master, param_1);
    if (task != nullptr && this->actions != nullptr) {
        RGE_Action* action = this->actions->create_task_action(task, nullptr, -1.0f, -1.0f, -1.0f);
        if (action != nullptr) {
            this->set_only_action(action);
        }
    }
}

// Source of truth: act_obj.cpp.decomp @ 0x00406990
void RGE_Action_Object::setTaskByTaskID(int param_1) {
    RGE_Master_Action_Object* master = (RGE_Master_Action_Object*)this->master_obj;
    RGE_Task* task = action_object_get_task_by_task_id(master, param_1);
    if (task != nullptr && this->actions != nullptr) {
        RGE_Action* action = this->actions->create_task_action(task, nullptr, -1.0f, -1.0f, -1.0f);
        if (action != nullptr) {
            this->set_only_action(action);
        }
    }
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x004069E0
void RGE_Action_Object::set_action(RGE_Action* param_1) {
    if (param_1 != nullptr && this->actions != nullptr) {
        this->actions->add_action(param_1);
    }
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x00406A00
void RGE_Action_Object::set_only_action(RGE_Action* param_1) {
    if (this->actions != nullptr) {
        this->actions->delete_list();
        if (param_1 != nullptr) {
            this->actions->add_action(param_1);
        }
    } else if (param_1 != nullptr) {
        delete param_1;
    }
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x00406A30
void RGE_Action_Object::set_end_action(RGE_Action* param_1) {
    if (param_1 != nullptr && this->actions != nullptr) {
        this->actions->add_action_at_end(param_1);
    }
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x00406A50
void RGE_Action_Object::stop() {
    int stop_result = (this->actions != nullptr) ? this->actions->action_stop() : 0;
    if (stop_result == 0 && this->actions != nullptr) {
        this->actions->delete_list();
    }
}

// Source of truth: act_obj.cpp.decomp @ 0x00406A70
uchar RGE_Action_Object::update() {
    if (actionFile != nullptr) {
        int action_value = -1;
        unsigned int action_state_value = 0xFFFFFFFFu;
        if (this->actions != nullptr && this->actions->have_action() != 0) {
            RGE_Action* action = this->actions->get_action();
            if (action != nullptr) {
                action_value = (int)action->type();
                action_state_value = (unsigned int)action->state;
            }
        }

        if (this->lastActionValue != action_value || this->lastActionStateValue != (int)action_state_value) {
            fprintf(actionFile, "%d : (%d,%d)->(%d,%u)\n",
                (int)this->owner->id,
                this->lastActionValue,
                this->lastActionStateValue,
                action_value,
                action_state_value);
            this->lastActionValue = action_value;
            this->lastActionStateValue = (int)action_state_value;
        }
    }

    uchar ret = RGE_Animated_Object::update();
    RGE_Action_List* list = this->actions;
    uchar object_state = this->object_state;

    if (object_state < 3) {
        if (list == nullptr || list->list == nullptr) {
            if (object_state == 2) {
                RGE_Master_Action_Object* master = (RGE_Master_Action_Object*)this->master_obj;
                if (master != nullptr && master->default_task != -1) {
                    this->set_task(master->default_task);
                    return ret;
                }
            }
        } else {
            if (this->inside_obj != nullptr) {
                list->inside_obj_update();
                return ret;
            }
            uchar action_ret = list->update();
            if (action_ret == 3 || action_ret == 1) {
                list->remove_action();
            }
        }
    } else if (list != nullptr && list->list != nullptr) {
        list->delete_list();
        return ret;
    }

    return ret;
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x00406B90
void RGE_Action_Object::change_ownership(RGE_Player* param_1) {
    this->stop();
    RGE_Static_Object::change_ownership(param_1);
    this->set_only_action(nullptr);
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x00406BC0
void RGE_Action_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    if (this->actions != nullptr) {
        this->actions->copy_obj((RGE_Master_Action_Object*)param_1);
    }
    RGE_Moving_Object::copy_obj(param_1);
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x00406BF0
uchar RGE_Action_Object::have_action() {
    return (this->actions != nullptr && this->actions->have_action() != 0) ? 1 : 0;
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x00406C10
RGE_Static_Object* RGE_Action_Object::get_target_obj() {
    if (this->actions != nullptr) {
        RGE_Action* action = this->actions->get_action();
        if (action != nullptr) {
            return action->get_target_obj();
        }
    }
    return nullptr;
}

// Source of truth: act_obj.cpp.decomp @ 0x00406C30
RGE_Task* RGE_Action_Object::getTask(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    RGE_Master_Action_Object* master = (RGE_Master_Action_Object*)this->master_obj;
    if (master == nullptr || master->tasks == nullptr) {
        return nullptr;
    }

    RGE_Task* task = master->tasks->get_target_task(this, param_1, param_2, param_3, param_4);
    if (task == nullptr && master->task_by_group != 0 && this->owner != nullptr && this->owner->master_objects != nullptr) {
        for (int i = 0; i < this->owner->master_object_num; ++i) {
            RGE_Master_Static_Object* alt_master = this->owner->master_objects[i];
            if (alt_master == nullptr || alt_master->id == master->id) {
                continue;
            }
            if (alt_master->object_group != master->object_group || alt_master->master_type != master->master_type) {
                continue;
            }
            RGE_Master_Action_Object* alt_action_master = (RGE_Master_Action_Object*)alt_master;
            if (alt_action_master->task_by_group == master->task_by_group && alt_action_master->tasks != nullptr) {
                task = alt_action_master->tasks->get_target_task(this, param_1, param_2, param_3, param_4);
                if (task != nullptr) {
                    this->transform(alt_master);
                    break;
                }
            }
        }
    }
    return task;
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x00406D00
uchar RGE_Action_Object::actionState() {
    if (this->actions != nullptr && this->actions->have_action() == 1) {
        RGE_Action* action = this->actions->get_action();
        if (action != nullptr) {
            return action->state;
        }
    }
    return 0;
}

// Fully verified. Source of truth: act_obj.cpp.decomp @ 0x00406D30
long RGE_Action_Object::get_action_checksum() {
    long checksum = 0;
    if (this->actions != nullptr) {
        RGE_Action* action = this->actions->get_action();
        if (action != nullptr) {
            checksum = (long)action->action_type + (long)(unsigned int)action->state;
        }
    }
    return checksum;
}
