#include "../include/TRIBE_Building_Object.h"

#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Doppleganger_Creator.h"
#include "../include/TRIBE_Action_Make_Obj.h"
#include "../include/TRIBE_Action_Make_Tech.h"
#include "../include/TRIBE_Master_Building_Object.h"
#include "../include/TRIBE_Player_Tech.h"
#include "../include/TRIBE_Player.h"
#include "../include/TRIBE_World.h"
#include "../include/RGE_Object_List.h"
#include "../include/globals.h"
#include "../include/debug_helpers.h"

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

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C9DA0
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
            if (this->owner != nullptr && this->owner->attributes != nullptr && this->owner->attribute_num > 0x20) {
                if (this->owner->attributes[0x20] <= this->owner->attributes[4]) {
                    if (this->production_queue_need_attr != 0x20) {
                        this->production_queue_need_attr = 0x20;
                        rge_base_game->notification(0x7D, (long)this->owner->id, 0x20, 0, 0);
                        int owner_id = (int)this->owner->id;
                        int* ai_queue_counter = (int*)((char*)rge_base_game + owner_id * 4 + 0xA34);
                        *ai_queue_counter = *ai_queue_counter + 1;
                    }
                    return;
                }
                if (this->owner->attributes[4] <= 0.0f) {
                    if (this->production_queue_need_attr != 4) {
                        this->production_queue_need_attr = 4;
                        rge_base_game->notification(0x7D, (long)this->owner->id, 4, 0, 0);
                        int owner_id = (int)this->owner->id;
                        int* ai_queue_counter = (int*)((char*)rge_base_game + owner_id * 4 + 0xA34);
                        *ai_queue_counter = *ai_queue_counter + 1;
                    }
                    return;
                }
            }
            if (this->production_queue_need_attr == 4) {
                int owner_id = (int)this->owner->id;
                int* ai_queue_counter = (int*)((char*)rge_base_game + owner_id * 4 + 0xA34);
                *ai_queue_counter = *ai_queue_counter - 1;
            }
            this->production_queue_need_attr = -1;
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

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C8370
void TRIBE_Building_Object::recycle_out_of_game() {
    if (this->production_queue_actions != nullptr) {
        this->production_queue_actions->delete_list();
    }
    if (this->production_queue != nullptr) {
        free(this->production_queue);
        this->production_queue = nullptr;
        this->production_queue_size = 0;
        this->production_queue_count = 0;
        this->production_queue_enabled = 1;
        this->production_queue_change_flag = 0;
        this->production_queue_auto_paused = 0;
        this->production_queue_need_attr = -1;
    }
    RGE_Action_Object::recycle_out_of_game();
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C8690
void TRIBE_Building_Object::destroy_obj() {
    this->take_building_attribute_from_owner();
    RGE_Action_Object::destroy_obj();
    if (this->DoppleInstalled != 0 && this->owner != nullptr && this->owner->doppleganger_creator != nullptr) {
        this->owner->doppleganger_creator->remove_doppleganger_check(this);
        this->DoppleInstalled = 0;
    }
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C86C0
uchar TRIBE_Building_Object::heal(float param_1) {
    TRIBE_Master_Building_Object* master = (TRIBE_Master_Building_Object*)this->master_obj;
    if (master == nullptr || master->build_pts_required <= 0) {
        return 2;
    }

    float max_hp = (float)(int)this->master_obj->hp;
    float heal_amount = (param_1 * max_hp) / (float)(int)master->build_pts_required;
    if (max_hp < heal_amount + this->hp) {
        heal_amount = max_hp - this->hp;
    }

    uchar paid = ((TRIBE_Player*)this->owner)->pay_obj_cost(master->id, heal_amount / (float)(int)(this->master_obj->hp * 2), 0);
    if (paid == 0) {
        return 2;
    }
    return TRIBE_Combat_Object::heal(heal_amount);
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C8740
void TRIBE_Building_Object::set_object_state(uchar param_1) {
    if (param_1 == 2) {
        TRIBE_Master_Building_Object* master = (TRIBE_Master_Building_Object*)this->master_obj;
        this->build_pts = (float)(int)master->build_pts_required;

        unsigned int saved_seed = (unsigned int)debug_rand("C:\\msdev\\work\\age1_x1\\t_b_obj.cpp", 299);
        int saved_debug_random_on = debug_random_on;
        debug_random_on = 0;
        if (master->construction_sound != nullptr && this->owner != nullptr && this->owner->world != nullptr &&
            this->owner->id == this->owner->world->curr_player) {
            master->construction_sound->play(1);
        }
        debug_random_on = saved_debug_random_on;
        debug_srand("C:\\msdev\\work\\age1_x1\\t_b_obj.cpp", 0x135, saved_seed);

        this->built = 1;
        this->take_building_attribute_from_owner();

        if (master->build_and_go_away == 0) {
            if (this->owner != nullptr) {
                this->unexplore_terrain(this->owner, 1, -1);
                this->explore_terrain(this->owner, 0, -1);
            }
            this->new_sprite(this->master_obj->sprite);
            this->facet = master->building_facet;
            if (master->building_connect_flag != 0) {
                this->connect();
            }
        } else {
            this->die_die_die();
        }

        if (this->owner != nullptr && this->owner->master_objects != nullptr && master->on_build_make_obj >= 0 &&
            (int)master->on_build_make_obj < this->owner->master_object_num) {
            RGE_Master_Static_Object* make_obj_master = this->owner->master_objects[master->on_build_make_obj];
            if (make_obj_master != nullptr) {
                make_obj_master->make_new_obj(this->owner, this->world_x, this->world_y, this->world_z);
            }
        }

        if (master->on_build_make_tile >= 0 && this->owner != nullptr && this->owner->world != nullptr && this->owner->world->map != nullptr) {
            RGE_Map* map = this->owner->world->map;
            short col0 = (short)(this->world_x - this->master_obj->radius_x);
            short row0 = (short)(this->world_y - this->master_obj->radius_y);
            short col1 = (short)(this->world_x + this->master_obj->radius_x);
            short row1 = (short)(this->world_y + this->master_obj->radius_y);
            map->set_terrain(this->owner, this->owner->world, col0, row0, col1, row1, (uchar)master->on_build_make_tile, 1, 0);
            map->request_redraw((int)col0 - 1, (int)row0 - 1, (int)col1 + 1, (int)row1 + 1, 0);
        }

        if (master->on_build_make_tech >= 0) {
            TRIBE_Player* tribe_player = (TRIBE_Player*)this->owner;
            if (tribe_player != nullptr && tribe_player->tech_tree != nullptr) {
                tribe_player->tech_tree->do_tech(master->on_build_make_tech);
            }
        }
        rge_base_game->notification(0x69, (long)this->owner->id, (long)master->id, (long)(int)this->world_x, (long)(int)this->world_y);
        ((TRIBE_Player*)this->owner)->registerBuild(this, this->unique_build_id);
    }

    bool became_dead = (param_1 == 3 && this->object_state == 2);
    if (became_dead) {
        this->take_building_attribute_from_owner();
        if (this->owner != nullptr && this->owner->doppleganger_creator != nullptr) {
            this->owner->doppleganger_creator->remove_doppleganger_check(this);
        }
        this->DoppleInstalled = 0;
    }

    RGE_Static_Object::set_object_state(param_1);

    if (became_dead && this->owner != nullptr && this->owner->objects != nullptr && this->master_obj != nullptr) {
        RGE_Static_Object* same_master = this->owner->objects->find_by_master_ids((int)this->master_obj->id, -1, -1.0f, -1.0f, 1, 2, nullptr);
        if (same_master == nullptr) {
            TRIBE_Master_Building_Object* master = (TRIBE_Master_Building_Object*)this->master_obj;
            TRIBE_Player* tribe_player = (TRIBE_Player*)this->owner;
            if (tribe_player != nullptr && tribe_player->tech_tree != nullptr) {
                if (master->on_build_make_tech >= 0) {
                    tribe_player->tech_tree->undo_tech(master->on_build_make_tech);
                }
                tribe_player->tech_tree->undo_tech(0x4A);
                tribe_player->tech_tree->undo_tech(0x4B);
                tribe_player->tech_tree->undo_tech(0x4C);
            }
        }
    }
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C8A60
void TRIBE_Building_Object::rehook() {
    RGE_Action_Object::rehook();
    if (this->production_queue_actions != nullptr) {
        this->production_queue_actions->rehook();
    }
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C8A80
uchar TRIBE_Building_Object::update() {
    if (this->object_state == 0 && this->master_obj != nullptr) {
        short build_pts_required = ((TRIBE_Master_Building_Object*)this->master_obj)->build_pts_required;
        uchar new_facet = (uchar)(int)(((this->build_pts * 100.0f) / (float)(int)build_pts_required) * 0.01f * build_pts_required);
        if ((short)new_facet < this->master_obj->radius_x && new_facet != this->facet) {
            this->facet = new_facet;
        }
        if (this->build_pts >= (float)(int)build_pts_required) {
            this->set_object_state(2);
        }
    }

    this->PriorMap3 = this->PriorMap2;
    this->PriorMap2 = this->PriorMap1;
    this->PriorTurn3 = this->PriorTurn2;
    this->PriorTurn2 = this->PriorTurn1;
    this->PriorTurn1 = world_update_counter;

    uchar rv = TRIBE_Combat_Object::update();
    if (this->object_state > 2) {
        this->empty_production_queue();
        this->PriorMap1 = this->Unified_Map_Value;
        return rv;
    }

    this->update_production_queue();
    this->PriorMap1 = this->Unified_Map_Value;
    return rv;
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C8B80
int TRIBE_Building_Object::explore_terrain(RGE_Player* param_1, uchar param_2, int param_3) {
    if (this->built != 0) {
        return RGE_Static_Object::explore_terrain(param_1, param_2, param_3);
    }
    return RGE_Static_Object::explore_terrain(param_1, 1, param_3);
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C8BC0
void TRIBE_Building_Object::save(int param_1) {
    TRIBE_Combat_Object::save(param_1);
    rge_write(param_1, &this->built, 1);
    rge_write(param_1, &this->build_pts, 4);
    rge_write(param_1, &this->unique_build_id, 4);
    rge_write(param_1, &this->culture, 1);
    rge_write(param_1, &this->production_queue_size, 2);
    for (short i = 0; i < this->production_queue_size; ++i) {
        rge_write(param_1, &this->production_queue[i].master_id, 2);
        rge_write(param_1, &this->production_queue[i].unit_count, 2);
    }
    rge_write(param_1, &this->production_queue_count, 2);
    rge_write(param_1, &this->production_queue_enabled, 1);
    this->production_queue_actions->save(param_1);
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C8CB0
void TRIBE_Building_Object::change_ownership(RGE_Player* param_1) {
    if (this->object_state == 2) {
        this->take_building_attribute_from_owner();
    }

    if (this->object_state == 0 && this->owner != nullptr) {
        this->unexplore_terrain(this->owner, 1, -1);
    }

    if (this->production_queue_count > 0) {
        if (this->production_queue_need_attr == 4) {
            this->production_queue_need_attr = -1;
            int owner_id = (int)this->owner->id;
            int* ai_queue_counter = (int*)((char*)rge_base_game + owner_id * 4 + 0xA34);
            *ai_queue_counter = *ai_queue_counter - 1;
        }
        this->production_queue_count = 1;
        this->production_queue->unit_count = 1;
    }

    this->production_queue_actions->delete_list();
    TRIBE_Combat_Object::change_ownership(param_1);

    if (this->object_state == 0 && this->owner != nullptr) {
        this->explore_terrain(this->owner, 1, -1);
    }

    if (this->object_state == 2) {
        TRIBE_Master_Building_Object* master = (TRIBE_Master_Building_Object*)this->master_obj;
        if (master != nullptr && this->owner != nullptr && this->owner->master_objects != nullptr &&
            master->on_build_make_obj >= 0 && (int)master->on_build_make_obj < this->owner->master_object_num) {
            RGE_Master_Static_Object* make_obj_master = this->owner->master_objects[master->on_build_make_obj];
            if (make_obj_master != nullptr) {
                make_obj_master->make_new_obj(this->owner, this->world_x, this->world_y, this->world_z);
            }
        }
        if (master != nullptr && master->on_build_make_tech >= 0) {
            TRIBE_Player* tribe_player = (TRIBE_Player*)this->owner;
            if (tribe_player != nullptr && tribe_player->tech_tree != nullptr) {
                tribe_player->tech_tree->do_tech(master->on_build_make_tech);
            }
        }
        this->give_building_attribute_to_owner();
    }
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C8E60
void TRIBE_Building_Object::modify(float param_1, uchar param_2) {
    if (param_2 != 0x11) {
        TRIBE_Combat_Object::modify(param_1, param_2);
        return;
    }
    this->facet = (uchar)(int)param_1;
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C9710
void TRIBE_Building_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    if (this->sprite == ((TRIBE_Master_Building_Object*)this->master_obj)->construction_sprite) {
        this->new_sprite(((TRIBE_Master_Building_Object*)param_1)->construction_sprite);
    }
    RGE_Combat_Object::copy_obj(param_1);
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C9760
void TRIBE_Building_Object::rotate(long) {
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C9770
void TRIBE_Building_Object::damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5) {
    float temp_hp = this->hp;
    if (this->hp <= 0.0f) {
        return;
    }

    RGE_Combat_Object::damage(param_1, param_2, param_3, param_4, param_5);

    if (param_5 == nullptr || param_5->master_obj == nullptr) {
        return;
    }

    short group_or_id = param_5->master_obj->object_group;
    bool siege_like = (group_or_id == 0 || group_or_id == 0x17 || group_or_id == 0x24 || group_or_id == 0x1A);
    if (!siege_like) {
        short id = param_5->master_obj->id;
        siege_like = (id == 0x4F || id == 0x45 || id == 199 || id == 0x17F || id == 0x17C);
    }

    float min_delta = siege_like ? 0.1f : 1.0f;
    if (temp_hp - this->hp < min_delta) {
        this->hp = temp_hp - min_delta;
    }

    if (this->owner->id > 0 && this->hp < 1.0f) {
        param_4->command_add_attribute(0x2B, 1.0f);
    }
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004CA0B0
void TRIBE_Building_Object::stop() {
    RGE_Combat_Object::stop();
    while (this->production_queue_count > 0) {
        this->remove_from_production_queue(this->production_queue->master_id, 1);
    }
}

static TRIBE_Building_Object* tribe_find_adjacent_building(RGE_Map* map, short tile_x, short tile_y, int master_id) {
    if (map == nullptr || map->map_row_offset == nullptr) {
        return nullptr;
    }
    if (tile_x < 0 || tile_y < 0 || (int)map->map_width <= tile_x || (int)map->map_height <= tile_y) {
        return nullptr;
    }
    RGE_Tile* row = map->map_row_offset[tile_y];
    if (row == nullptr) {
        return nullptr;
    }
    RGE_Static_Object* found = row[tile_x].objects.find_by_master_id(master_id, -1.0f, -1.0f, 0, 0, nullptr);
    return reinterpret_cast<TRIBE_Building_Object*>(found);
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C8ED0
long TRIBE_Building_Object::check(TRIBE_Building_Object** param_1) {
    if (param_1 == nullptr) {
        return 0;
    }

    param_1[0] = nullptr;
    param_1[1] = nullptr;
    param_1[2] = nullptr;
    param_1[3] = nullptr;

    if (this->owner == nullptr || this->owner->world == nullptr || this->owner->world->map == nullptr || this->master_obj == nullptr) {
        return 0;
    }

    RGE_Map* map = this->owner->world->map;
    const short tile_x = (short)this->world_x;
    const short tile_y = (short)this->world_y;
    const int master_id = this->master_obj->id;
    long count = 0;

    if (tile_y > 0) {
        TRIBE_Building_Object* north = tribe_find_adjacent_building(map, tile_x, (short)(tile_y - 1), master_id);
        if (north != nullptr && north->owner == this->owner) {
            param_1[0] = north;
            count = count + 1;
        }
    }

    if (tile_x > 0) {
        TRIBE_Building_Object* west = tribe_find_adjacent_building(map, (short)(tile_x - 1), tile_y, master_id);
        if (west != nullptr && west->owner == this->owner) {
            param_1[1] = west;
            count = count + 1;
        }
    }

    if (tile_x < (short)(map->map_width - 1)) {
        TRIBE_Building_Object* east = tribe_find_adjacent_building(map, (short)(tile_x + 1), tile_y, master_id);
        if (east != nullptr && east->owner == this->owner) {
            param_1[2] = east;
            count = count + 1;
        }
    }

    if (tile_y < (short)(map->map_height - 1)) {
        TRIBE_Building_Object* south = tribe_find_adjacent_building(map, tile_x, (short)(tile_y + 1), master_id);
        if (south != nullptr && south->owner == this->owner) {
            param_1[3] = south;
            count = count + 1;
        }
    }

    return count;
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C90B0
void TRIBE_Building_Object::connect() {
    if (this->master_obj == nullptr) {
        return;
    }
    if (*reinterpret_cast<short*>(reinterpret_cast<char*>(this->master_obj) + 0x60) != 3) {
        this->facet = 0;
        return;
    }

    this->RGE_Moving_Object::set_angle();

    TRIBE_Building_Object* checks[4] = {nullptr, nullptr, nullptr, nullptr};
    this->check(checks);

    TRIBE_Building_Object* north = checks[0];
    TRIBE_Building_Object* west = checks[1];
    TRIBE_Building_Object* east = checks[2];
    TRIBE_Building_Object* south = checks[3];

    int rotate_delta = 2 - (int)this->facet;
    if ((north == nullptr) || (south == nullptr)) {
        if ((west != nullptr) && (east != nullptr) && (north == nullptr) && (south == nullptr)) {
            rotate_delta = -(int)this->facet;
        }
    } else {
        if ((west == nullptr) && (east == nullptr)) {
            rotate_delta = 1 - (int)this->facet;
        }
    }

    this->RGE_Moving_Object::rotate(rotate_delta);
    if (north != nullptr) {
        north->connect2();
    }
    if (west != nullptr) {
        west->connect2();
    }
    if (east != nullptr) {
        east->connect2();
    }
    if (south != nullptr) {
        south->connect2();
    }
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C9180
void TRIBE_Building_Object::connect2() {
    if (this->master_obj == nullptr) {
        return;
    }
    if (*reinterpret_cast<short*>(reinterpret_cast<char*>(this->master_obj) + 0x60) != 3) {
        this->facet = 0;
        return;
    }

    TRIBE_Building_Object* checks[4] = {nullptr, nullptr, nullptr, nullptr};
    this->check(checks);

    TRIBE_Building_Object* north = checks[0];
    TRIBE_Building_Object* west = checks[1];
    TRIBE_Building_Object* east = checks[2];
    TRIBE_Building_Object* south = checks[3];

    int rotate_delta = 2 - (int)this->facet;
    if ((north == nullptr) || (south == nullptr)) {
        if ((west != nullptr) && (east != nullptr) && (north == nullptr) && (south == nullptr)) {
            rotate_delta = -(int)this->facet;
        }
    } else {
        if ((west == nullptr) && (east == nullptr)) {
            rotate_delta = 1 - (int)this->facet;
        }
    }

    this->RGE_Moving_Object::rotate(rotate_delta);
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C9230
void TRIBE_Building_Object::lay_down_impassable_terrain() {
    if (this->owner == nullptr || this->owner->world == nullptr || this->owner->world->map == nullptr || this->master_obj == nullptr) {
        return;
    }
    if (*reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this->master_obj) + 0x174) <= 0x7FFF) {
        return;
    }

    RGE_Map* map = this->owner->world->map;
    const float half_w = *reinterpret_cast<float*>(reinterpret_cast<char*>(this->master_obj) + 0x30);
    const float half_h = *reinterpret_cast<float*>(reinterpret_cast<char*>(this->master_obj) + 0x34);

    short min_x = (short)(this->world_x - half_w);
    short max_x = (short)((this->world_x + half_w) - 10.0f);
    short min_y = (short)(this->world_y - half_h);
    short max_y = (short)((this->world_y + half_h) - 10.0f);

    if (min_x < 0) {
        min_x = 0;
    }
    if (min_y < 0) {
        min_y = 0;
    }
    if ((int)map->map_width <= max_x) {
        max_x = (short)(map->map_width - 1);
    }
    if ((int)map->map_height <= max_y) {
        max_y = (short)(map->map_height - 1);
    }

    for (int y = min_y; y <= max_y; ++y) {
        RGE_Tile* row = map->map_row_offset[y];
        if (row == nullptr) {
            continue;
        }

        for (int x = min_x; x <= max_x; ++x) {
            unsigned char* terrain_bits = reinterpret_cast<unsigned char*>(&row[x]) + 5;
            unsigned char value = *terrain_bits;
            unsigned char terrain_code = value & 0x1F;
            if (terrain_code == 0) {
                value = (unsigned char)((value & 0xF0) | 0x10);
            } else if (terrain_code == 1) {
                value = (unsigned char)((value & 0xEF) | 0x0F);
            } else if (terrain_code == 6) {
                value = (unsigned char)((value & 0xEE) | 0x0E);
            }
            *terrain_bits = value;
        }
    }
}

// Fully verified. Source of truth: t_b_obj.cpp.decomp @ 0x004C9360
void TRIBE_Building_Object::lay_down_passable_terrain() {
    if (this->owner == nullptr || this->owner->world == nullptr || this->owner->world->map == nullptr || this->master_obj == nullptr) {
        return;
    }
    if (*reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this->master_obj) + 0x174) <= 0x7FFF) {
        return;
    }

    RGE_Map* map = this->owner->world->map;
    const float half_w = *reinterpret_cast<float*>(reinterpret_cast<char*>(this->master_obj) + 0x30);
    const float half_h = *reinterpret_cast<float*>(reinterpret_cast<char*>(this->master_obj) + 0x34);

    short min_x = (short)(this->world_x - half_w);
    short max_x = (short)((this->world_x + half_w) - 10.0f);
    short min_y = (short)(this->world_y - half_h);
    short max_y = (short)((this->world_y + half_h) - 10.0f);

    if (min_x < 0) {
        min_x = 0;
    }
    if (min_y < 0) {
        min_y = 0;
    }
    if ((int)map->map_width <= max_x) {
        max_x = (short)(map->map_width - 1);
    }
    if ((int)map->map_height <= max_y) {
        max_y = (short)(map->map_height - 1);
    }

    for (int y = min_y; y <= max_y; ++y) {
        RGE_Tile* row = map->map_row_offset[y];
        if (row == nullptr) {
            continue;
        }

        for (int x = min_x; x <= max_x; ++x) {
            unsigned char* terrain_bits = reinterpret_cast<unsigned char*>(&row[x]) + 5;
            unsigned char value = *terrain_bits;
            unsigned char terrain_code = value & 0x1F;
            if (terrain_code == 0x0E) {
                value = (unsigned char)((value & 0xE6) | 0x06);
            } else if (terrain_code == 0x0F) {
                value = (unsigned char)((value & 0xE1) | 0x01);
            } else if (terrain_code == 0x10) {
                value = (unsigned char)(value & 0xE0);
            }
            *terrain_bits = value;
        }
    }
}

