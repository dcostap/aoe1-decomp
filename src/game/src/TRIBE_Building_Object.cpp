#include "../include/TRIBE_Building_Object.h"

#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Doppleganger_Creator.h"
#include "../include/TRIBE_Action_Make_Obj.h"
#include "../include/TRIBE_Action_Make_Tech.h"
#include "../include/TRIBE_Master_Building_Object.h"
#include "../include/TRIBE_Player.h"
#include "../include/TRIBE_World.h"
#include "../include/globals.h"

#include <new>
#include <stdlib.h>

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C7F50, t_b_obj.cpp.asm @ 0x004C7F50
TRIBE_Building_Object::TRIBE_Building_Object(TRIBE_Master_Building_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6, int param_7)
    : TRIBE_Combat_Object((TRIBE_Master_Combat_Object*)param_1, param_2, param_3, param_4, param_5, 0) {
    this->unique_build_id = param_6;
    this->production_queue = nullptr;
    this->production_queue_size = 0;
    this->production_queue_count = 0;
    this->production_queue_enabled = 1;
    this->production_queue_actions = nullptr;
    this->production_queue_change_flag = 0;
    this->production_queue_auto_paused = 0;
    this->production_queue_need_attr = -1;
    this->DoppleInstalled = 0;

    if (param_7 != 0) {
        this->setup(param_1, param_2, param_3, param_4, param_5);
    }

    if (param_1 != nullptr && param_1->id == 0x114) {
        this->set_task(*(short*)((char*)param_1 + 0xDC));
    }

    int y = (int)param_4;
    int x = (int)param_3;
    unsigned long* addr = unified_map_offsets[y] + x;
    this->DoppleInstalled = param_2->doppleganger_creator->add_doppleganger_check(this, addr);

    this->PriorMap1 = 0;
    this->PriorMap2 = 0;
    this->PriorMap3 = 0;
    this->PriorTurn1 = 0;
    this->PriorTurn2 = 0;
    this->PriorTurn3 = 0;
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C80B0, t_b_obj.cpp.asm @ 0x004C80B0
TRIBE_Building_Object::TRIBE_Building_Object(TRIBE_Master_Building_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6)
    : TRIBE_Combat_Object((TRIBE_Master_Combat_Object*)param_1, param_2, param_3, param_4, param_5, 0) {
    this->production_queue_need_attr = -1;
    this->unique_build_id = -1;
    this->production_queue = nullptr;
    this->production_queue_size = 0;
    this->production_queue_count = 0;
    this->production_queue_enabled = 1;
    this->production_queue_actions = nullptr;
    this->production_queue_change_flag = 0;
    this->production_queue_auto_paused = 0;
    this->DoppleInstalled = 0;

    if (param_6 != 0) {
        this->setup(param_1, param_2, param_3, param_4, param_5);
    }

    int y = (int)param_4;
    int x = (int)param_3;
    unsigned long* addr = unified_map_offsets[y] + x;
    this->DoppleInstalled = param_2->doppleganger_creator->add_doppleganger_check(this, addr);

    this->PriorMap1 = 0;
    this->PriorMap2 = 0;
    this->PriorMap3 = 0;
    this->PriorTurn1 = 0;
    this->PriorTurn2 = 0;
    this->PriorTurn3 = 0;
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C83E0, t_b_obj.cpp.asm @ 0x004C83E0
int TRIBE_Building_Object::setup(TRIBE_Master_Building_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) {
    this->built = 0;
    TRIBE_Combat_Object::setup((TRIBE_Master_Combat_Object*)param_1, param_2, param_3, param_4, param_5);

    this->type = 0x50;
    this->set_object_state(0);

    if (*(short*)((char*)param_1 + 0x15A) > 0) {
        this->new_sprite(*(RGE_Sprite**)((char*)param_1 + 0x168));
    }

    this->build_pts = 0.0f;
    this->hp = 1.0f;
    this->facet = *(unsigned char*)((char*)param_1 + 0x16E);
    this->culture = param_2->culture;

    TRIBE_World* world = (TRIBE_World*)this->owner->world;
    if (world != nullptr) {
        world->check_destructables(this->owner->id, param_1->id, this->world_x, this->world_y, 0);
    }

    this->production_queue_actions = this->create_action_list();
    return 1;
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C81D0
TRIBE_Building_Object::TRIBE_Building_Object(int param_1, RGE_Game_World* param_2, int param_3)
    : TRIBE_Combat_Object(param_1, param_2, 0) {
    this->production_queue = nullptr;
    this->production_queue_size = 0;
    this->production_queue_count = 0;
    this->production_queue_enabled = 1;
    this->production_queue_actions = nullptr;
    this->production_queue_change_flag = 0;
    this->production_queue_auto_paused = 0;
    this->production_queue_need_attr = -1;
    this->DoppleInstalled = 0;

    if (param_3 != 0) {
        this->setup(param_1, param_2);
    }

    // Install doppleganger checks after load/setup.
    int y = (int)this->world_y;
    int x = (int)this->world_x;
    unsigned long* addr = unified_map_offsets[y] + x;
    this->DoppleInstalled = this->owner->doppleganger_creator->add_doppleganger_check(this, addr);
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C82A0
TRIBE_Building_Object::~TRIBE_Building_Object() = default;

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C8490
int TRIBE_Building_Object::setup(int param_1, RGE_Game_World* param_2) {
    int fd = param_1;
    RGE_Game_World* world = param_2;

    TRIBE_Combat_Object::setup(fd, world);
    this->type = 'P';

    rge_read(fd, &this->built, 1);
    rge_read(fd, &this->build_pts, 4);
    rge_read(fd, &this->unique_build_id, 4);
    rge_read(fd, &this->culture, 1);

    this->production_queue_actions = this->create_action_list();

    if (save_game_version >= 7.21f) {
        rge_read(fd, &this->production_queue_size, 2);
        if (this->production_queue_size > 0) {
            this->production_queue = (Production_Queue_Record*)calloc((size_t)this->production_queue_size, sizeof(Production_Queue_Record));
            for (short i = 0; i < this->production_queue_size; ++i) {
                rge_read(fd, &this->production_queue[i].master_id, 2);
                rge_read(fd, &this->production_queue[i].unit_count, 2);
            }
        }

        rge_read(fd, &this->production_queue_count, 2);
        rge_read(fd, &this->production_queue_enabled, 1);
        this->production_queue_actions->load(fd);
    }

    return 1;
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C9560
unsigned char TRIBE_Building_Object::build(float p1) {
    if (this->built != 0) {
        return 1;
    }

    TRIBE_Master_Building_Object* master = (TRIBE_Master_Building_Object*)this->master_obj;
    float required = (float)(int)master->build_pts_required;
    if (required < p1 + this->build_pts) {
        p1 = required - this->build_pts;
    }

    float hp_now = (((float)(int)this->master_obj->hp * p1) / required) + this->hp;
    this->hp = hp_now;
    if ((float)(int)this->master_obj->hp < hp_now) {
        this->hp = (float)(int)this->master_obj->hp;
    }

    float new_build_pts = p1 + this->build_pts;
    this->build_pts = new_build_pts;
    if (new_build_pts < (float)(int)master->build_pts_required) {
        return 0;
    }

    this->set_object_state(2);
    return 1;
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C9870
void TRIBE_Building_Object::add_to_production_queue(short p1, short p2) {
    short master_id = p1;
    short queue_count = this->production_queue_count;
    bool queue_changed = false;
    short missing_attr = p1;

    if ((queue_count < 1) || (this->production_queue[queue_count - 1].master_id != p1)) {
        while (queue_count > 0) {
            this->remove_from_production_queue(this->production_queue->master_id, 1);
            queue_count = this->production_queue_count;
        }

        uchar can_pay = ((TRIBE_Player*)this->owner)->check_obj_cost(master_id, &missing_attr, 1.0f, 1);
        if (can_pay == 0) {
            rge_base_game->notification(0x7D, (long)this->owner->id, (long)missing_attr, 0, 0);
            return;
        }

        if (this->production_queue_count == this->production_queue_size) {
            Production_Queue_Record* new_queue = (Production_Queue_Record*)calloc(this->production_queue_size + 10, 4);
            if (new_queue == nullptr) {
                return;
            }

            if (this->production_queue != nullptr) {
                if (this->production_queue_size > 0) {
                    for (short i = 0; i < this->production_queue_size; ++i) {
                        new_queue[i].master_id = this->production_queue[i].master_id;
                        new_queue[i].unit_count = this->production_queue[i].unit_count;
                    }
                }
                free(this->production_queue);
            }

            this->production_queue_size = this->production_queue_size + 10;
            this->production_queue = new_queue;
        }

        int requested_count = (int)p2;
        int paid_count = 0;
        this->production_queue[this->production_queue_count].unit_count = 0;
        if (requested_count > 0) {
            do {
                can_pay = ((TRIBE_Player*)this->owner)->check_obj_cost(master_id, &missing_attr, 1.0f, 1);
                if (can_pay == 0) {
                    rge_base_game->notification(0x7D, (long)this->owner->id, (long)missing_attr, 0, 0);
                    break;
                }

                ((TRIBE_Player*)this->owner)->pay_obj_cost(master_id, 1.0f, 1);
                short* unit_count = &this->production_queue[this->production_queue_count].unit_count;
                *unit_count = *unit_count + 1;
                paid_count = paid_count + 1;
            } while (paid_count < requested_count);
        }

        this->production_queue[this->production_queue_count].master_id = master_id;
        this->production_queue_count = this->production_queue_count + 1;
        this->production_queue_change_flag = this->production_queue_change_flag + 1;
        rge_base_game->notification(0x7C, (long)this->owner->id, 0, 0, 0);
    } else {
        int requested_count = (int)p2;
        int paid_count = 0;
        if (requested_count > 0) {
            do {
                uchar can_pay = ((TRIBE_Player*)this->owner)->check_obj_cost(master_id, &missing_attr, 1.0f, 1);
                if (can_pay == 0) {
                    rge_base_game->notification(0x7D, (long)this->owner->id, (long)missing_attr, 0, 0);
                    break;
                }

                ((TRIBE_Player*)this->owner)->pay_obj_cost(master_id, 1.0f, 1);
                short* unit_count = &this->production_queue[this->production_queue_count - 1].unit_count;
                *unit_count = *unit_count + 1;
                paid_count = paid_count + 1;
                queue_changed = true;
            } while (paid_count < requested_count);
        }

        if (queue_changed) {
            this->production_queue_change_flag = this->production_queue_change_flag + 1;
            rge_base_game->notification(0x7C, (long)this->owner->id, 0, 0, 0);
            return;
        }
    }
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C9B10
void TRIBE_Building_Object::remove_from_production_queue(short p1, short p2) {
    if (this->production_queue_count != 0) {
        short queue_index = this->production_queue_count - 1;
        if (queue_index >= 0) {
            while (this->production_queue[queue_index].master_id != p1) {
                queue_index = queue_index - 1;
                if (queue_index < 0) {
                    break;
                }
            }

            if (queue_index >= 0) {
                short current_count = this->production_queue[queue_index].unit_count;
                short reimburse_count = p2;
                if (p2 < 0 || current_count <= p2) {
                    reimburse_count = current_count;
                }

                int refund_loops = (int)reimburse_count;
                if (refund_loops > 0) {
                    do {
                        ((TRIBE_Player*)this->owner)->reimburse_obj_cost(p1);
                        refund_loops = refund_loops - 1;
                    } while (refund_loops != 0);
                }

                short* unit_count = &this->production_queue[queue_index].unit_count;
                *unit_count = (short)(*unit_count - reimburse_count);
                this->production_queue_change_flag = this->production_queue_change_flag + 1;

                if (this->production_queue[queue_index].unit_count < 1) {
                    this->production_queue_count = this->production_queue_count - 1;
                    short shift_index = queue_index;
                    if (queue_index < this->production_queue_count) {
                        do {
                            short next_index = shift_index + 1;
                            this->production_queue[shift_index].master_id = this->production_queue[next_index].master_id;
                            this->production_queue[shift_index].unit_count = this->production_queue[next_index].unit_count;
                            shift_index = next_index;
                        } while (shift_index < this->production_queue_count);
                    }

                    if (queue_index == 0) {
                        if (this->production_queue_need_attr != -1) {
                            if (this->production_queue_need_attr == 4) {
                                int owner_id = (int)this->owner->id;
                                int* ai_queue_counter = (int*)((char*)rge_base_game + owner_id * 4 + 0xA34);
                                *ai_queue_counter = *ai_queue_counter - 1;
                            }
                            this->production_queue_need_attr = -1;
                        }

                        this->production_queue_actions->action_stop();
                        this->production_queue_actions->delete_list();
                    }
                }
            }
        }

        rge_base_game->notification(0x7C, (long)this->owner->id, 0, 0, 0);
    }
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C85D0
void TRIBE_Building_Object::take_building_attribute_from_owner() {
    for (int i = 0; i < 3; ++i) {
        TRIBE_Master_Building_Object* master = (TRIBE_Master_Building_Object*)this->master_obj;
        if (master != nullptr && master->build_inventory[i].flag > 3 && master->build_inventory[i].type >= 0) {
            this->owner->command_add_attribute(master->build_inventory[i].type, -(float)(int)master->build_inventory[i].amount);
        }
    }
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C8630
void TRIBE_Building_Object::give_building_attribute_to_owner() {
    for (int i = 0; i < 3; ++i) {
        TRIBE_Master_Building_Object* master = (TRIBE_Master_Building_Object*)this->master_obj;
        if (master != nullptr && master->build_inventory[i].flag > 3 && master->build_inventory[i].type >= 0) {
            this->owner->command_add_attribute(master->build_inventory[i].type, (float)(int)master->build_inventory[i].amount);
        }
    }
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C8E90
void TRIBE_Building_Object::transform(TRIBE_Master_Building_Object* param_1) {
    TRIBE_Combat_Object::transform((RGE_Master_Static_Object*)param_1);
    this->built = 0;
    if (param_1 != nullptr && param_1->build_pts_required > 0) {
        this->new_sprite(param_1->construction_sprite);
    }
    this->build_pts = 0.0f;
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C9480
void TRIBE_Building_Object::cancel_object() {
    if (this->object_state < 2) {
        this->cancel_build();
        return;
    }
    TRIBE_Combat_Object::cancel_object();
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C9490
void TRIBE_Building_Object::cancel_build() {
    if (this->selected != 0) {
        this->owner->unselect_one_object(this);
    }

    float percent = 0.0f;
    if (this->object_state <= 1 && this->hp > 0.0f) {
        float required = (float)(int)((TRIBE_Master_Building_Object*)this->master_obj)->build_pts_required;
        percent = ((required - this->build_pts) / required) * 0.5f;
    }
    if (percent > 1.0f) {
        percent = 1.0f;
    }

    TRIBE_Master_Building_Object* master = (TRIBE_Master_Building_Object*)this->master_obj;
    for (int i = 0; i < 3; ++i) {
        short attr = master->build_inventory[i].type;
        if (attr >= 0 && master->build_inventory[i].flag != 0) {
            this->owner->command_add_attribute(attr, (float)(int)master->build_inventory[i].amount * percent);
        }
    }
    this->hp = 0.0f;
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C9620
int TRIBE_Building_Object::work_status(short& param_1, short& param_2, short& param_3, char* param_4, short param_5) {
    TRIBE_Action_Make_Obj* action = (TRIBE_Action_Make_Obj*)this->production_queue_actions->get_action();
    if (action == nullptr) {
        param_1 = 0;
    } else {
        param_1 = action->type();
    }

    if (param_1 == 0x66) {
        action->get_info(&param_2, &param_3, param_4, param_5);
        return 1;
    }
    if (param_1 == 0x67) {
        ((TRIBE_Action_Make_Tech*)action)->get_info(&param_2, &param_3, param_4, param_5);
        return 1;
    }
    param_2 = -1;
    param_3 = 0;
    if (param_4 != nullptr) {
        *param_4 = '\0';
    }
    return 0;
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C96C0
short TRIBE_Building_Object::get_construction_progress() {
    if (this->built != 0) {
        return 100;
    }
    TRIBE_Master_Building_Object* master = (TRIBE_Master_Building_Object*)this->master_obj;
    if (master == nullptr || master->build_pts_required == 0) {
        return 100;
    }
    return (short)((this->build_pts * 100.0f) / (float)(int)master->build_pts_required);
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C9C80
void TRIBE_Building_Object::advance_production_queue() {
    if (this->production_queue_count == 0) {
        return;
    }

    this->production_queue->unit_count = this->production_queue->unit_count - 1;
    this->production_queue_change_flag = this->production_queue_change_flag + 1;
    if (this->production_queue->unit_count < 1) {
        this->production_queue_count = this->production_queue_count - 1;
        for (int i = 0; i < this->production_queue_count; ++i) {
            this->production_queue[i].master_id = this->production_queue[i + 1].master_id;
            this->production_queue[i].unit_count = this->production_queue[i + 1].unit_count;
        }
    }
    rge_base_game->notification(0x7C, (long)this->owner->id, 0, 0, 0);
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C9D20
void TRIBE_Building_Object::empty_production_queue() {
    if (this->production_queue_need_attr != -1) {
        if (this->production_queue_need_attr == 4) {
            int owner_id = (int)this->owner->id;
            int* ai_queue_counter = (int*)((char*)rge_base_game + owner_id * 4 + 0xA34);
            *ai_queue_counter = *ai_queue_counter - 1;
        }
        this->production_queue_need_attr = -1;
    }
    this->production_queue_count = 0;
    this->production_queue_actions->delete_list();
    this->production_queue_change_flag = this->production_queue_change_flag + 1;
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C9D90
void TRIBE_Building_Object::enable_production_queue(int param_1) {
    this->production_queue_enabled = (uchar)param_1;
}

// TODO: Full parity pending for resource-gated queue reasons and AI warning counters.
void TRIBE_Building_Object::update_production_queue() {
    if (this->production_queue_enabled == 0 || this->production_queue_count == 0) {
        if (this->production_queue_need_attr == 4) {
            this->production_queue_need_attr = -1;
            int owner_id = (int)this->owner->id;
            int* ai_queue_counter = (int*)((char*)rge_base_game + owner_id * 4 + 0xA34);
            *ai_queue_counter = *ai_queue_counter - 1;
        }
        return;
    }

    short work_type = 0;
    short progress = 0;
    short work_target = 0;
    int status = this->work_status(work_type, progress, work_target, nullptr, 0);
    if (status == 0 || (work_type != 0x66 && work_type != 0x67)) {
        if (this->production_queue_actions->list == nullptr) {
            TRIBE_Action_Make_Obj* action = new (std::nothrow) TRIBE_Action_Make_Obj((RGE_Action_Object*)this, this->production_queue->master_id, -1, 1);
            if (action != nullptr) {
                this->production_queue_actions->add_action(action);
            }
        }

        RGE_Action* action = this->production_queue_actions->get_action();
        if (action != nullptr) {
            char action_state = (char)action->state;
            if (action_state == 1 || action_state == 2 || action_state == 3) {
                this->production_queue_actions->remove_action();
                this->advance_production_queue();
            }
        }
    } else if (this->production_queue_count > 0) {
        do {
            this->remove_from_production_queue(this->production_queue->master_id, (short)-1);
        } while (this->production_queue_count > 0);
        return;
    }
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004CA030
int TRIBE_Building_Object::production_queue_status(short& param_1, short& param_2) {
    param_1 = -1;
    param_2 = 0;

    TRIBE_Action_Make_Obj* action = (TRIBE_Action_Make_Obj*)this->production_queue_actions->get_action();
    if (action != nullptr && action->type() == 0x66) {
        action->get_info(&param_1, &param_2, nullptr, 0);
        return 1;
    }
    if (this->production_queue_count > 0) {
        param_1 = this->production_queue->master_id;
        param_2 = 0;
        return 1;
    }
    return 0;
}


