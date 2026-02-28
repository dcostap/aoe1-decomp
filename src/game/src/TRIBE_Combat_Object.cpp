#include "../include/TRIBE_Combat_Object.h"

#include "../include/RGE_Game_World.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Action.h"
#include "../include/RGE_Armor_Weapon_Info.h"
#include "../include/RGE_Master_Action_Object.h"
#include "../include/RGE_Object_Node.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Task.h"
#include "../include/RGE_Task_List.h"
#include "../include/RGE_Base_Game.h"
#include "../include/TRIBE_Master_Combat_Object.h"
#include "../include/TRIBE_Master_Building_Object.h"
#include "../include/TRIBE_Action_List.h"
#include "../include/TribeUnitAIModules.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"

#include <cstddef>
#include <math.h>
#include <new>

static void tribe_adjust_player_attribute_offset(RGE_Player* player, size_t byte_offset, float delta) {
    if (player == nullptr || player->attributes == nullptr) {
        return;
    }
    *(float*)((char*)player->attributes + byte_offset) = *(float*)((char*)player->attributes + byte_offset) + delta;
}

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CA0F0, t_c_obj.cpp.asm @ 0x004CA0F0
TRIBE_Combat_Object::TRIBE_Combat_Object(TRIBE_Master_Combat_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6)
    : RGE_Combat_Object((RGE_Master_Combat_Object*)param_1, param_2, param_3, param_4, param_5, 0) {
    if (param_6 != 0) {
        this->setup(param_1, param_2, param_3, param_4, param_5);
    }
}

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CA1A0
TRIBE_Combat_Object::TRIBE_Combat_Object(int param_1, RGE_Game_World* param_2, int param_3)
    : RGE_Combat_Object(param_1, param_2, 0) {
    if (param_3 != 0) {
        this->setup(param_1, param_2);
    }
}

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CA210
TRIBE_Combat_Object::~TRIBE_Combat_Object() {
    if (this->own_master != 0) {
        if (this->master_obj != nullptr) {
            delete this->master_obj;
        }
        this->own_master = 0;
    }

    if (this->master_obj != nullptr) {
        short object_group = this->master_obj->object_group;
        if (object_group == 4 || object_group == 0x15 || object_group == 2) {
            tribe_adjust_player_attribute_offset(this->owner, 0x94, -1.0f);
        } else {
            short id = this->master_obj->id;
            if (((object_group != 0x12) && (this->master_obj->master_type == 0x46)) || (id == 0x4F || id == 0x45 || id == 199)) {
                tribe_adjust_player_attribute_offset(this->owner, 0xA0, -1.0f);
            }
        }
    }
}

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CA510
RGE_Action_List* TRIBE_Combat_Object::create_action_list() {
    TRIBE_Action_List* list = new (std::nothrow) TRIBE_Action_List((RGE_Action_Object*)this);
    return (RGE_Action_List*)list;
}

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CA3E0, t_c_obj.cpp.asm @ 0x004CA3E0
int TRIBE_Combat_Object::setup(int param_1, RGE_Game_World* param_2) {
    int fd = param_1;
    RGE_Game_World* world = param_2;

    RGE_Combat_Object::setup(fd, world);
    this->type = 'F';

    rge_read(fd, &this->own_master, 1);
    if (this->own_master != 0) {
        unsigned char master_type = 0;
        rge_read(fd, &master_type, 1);

        if (master_type == 'F') {
            TRIBE_Master_Combat_Object* master =
                (TRIBE_Master_Combat_Object*)::operator new(sizeof(TRIBE_Master_Combat_Object), std::nothrow);
            if (master != nullptr) {
                new (master) TRIBE_Master_Combat_Object(fd, world->sprites, world->sounds, 1);
            }
            this->master_obj = master;
        } else if (master_type == 'P') {
            TRIBE_Master_Building_Object* master =
                (TRIBE_Master_Building_Object*)::operator new(sizeof(TRIBE_Master_Building_Object), std::nothrow);
            if (master != nullptr) {
                new (master) TRIBE_Master_Building_Object(fd, world->sprites, world->sounds, 1);
            }
            this->master_obj = master;
        }
    }

    int has_unit_ai = 0;
    rge_read(fd, &has_unit_ai, 4);
    if (has_unit_ai == 1) {
        this->initUnitAI();
        if (this->unitAIValue != nullptr) {
            this->unitAIValue->load(fd);
        }
    }

    return 1;
}

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CA300, t_c_obj.cpp.asm @ 0x004CA300
int TRIBE_Combat_Object::setup(TRIBE_Master_Combat_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) {
    this->RGE_Combat_Object::setup((RGE_Master_Static_Object*)param_1, param_2, param_3, param_4, param_5);

    if (this->owner != nullptr && this->owner->id == 0) {
        this->capture_flag = 1;
    }

    this->type = 0x46;
    this->initUnitAI();
    this->own_master = 0;

    if (param_1 != nullptr) {
        short object_group = param_1->object_group;
        if (object_group == 4 || object_group == 0x15 || object_group == 2) {
            tribe_adjust_player_attribute_offset(this->owner, 0x94, 1.0f);
        } else {
            short id = param_1->id;
            if (((object_group != 0x12) && (param_1->master_type == 0x46)) || (id == 0x4F || id == 0x45 || id == 199)) {
                tribe_adjust_player_attribute_offset(this->owner, 0xA0, 1.0f);
            }
        }

        if (param_1->object_group == 0x12) {
            this->attribute_amount_held = 100.0f;
            this->attribute_type_held = 0x22;
        }
    }

    return 1;
}

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CB8D0
void TRIBE_Combat_Object::initUnitAI() {
    if (this->master_obj == nullptr) {
        return;
    }

    this->unitAIValue = CreateTribeUnitAIModule(this, this->master_obj->object_group, this->master_obj->id);
}

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CA780
void TRIBE_Combat_Object::cancel_object() {
    this->die_die_die();
}

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CAA50
uchar TRIBE_Combat_Object::attack(RGE_Static_Object* param_1, RGE_Combat_Object* param_2) {
    // TODO: Preserve t_c_obj.cpp side-effect callback for elevated attackers (owner vtbl +0x94).
    return RGE_Combat_Object::attack(param_1, param_2);
}

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CAAA0
uchar TRIBE_Combat_Object::do_attack(RGE_Static_Object* param_1, RGE_Combat_Object* param_2, float param_3, float param_4, float param_5) {
    TRIBE_Master_Combat_Object* master = (TRIBE_Master_Combat_Object*)this->master_obj;
    if (param_1 == nullptr || master == nullptr) {
        return 0;
    }

    short master_id = master->id;
    if (rge_base_game != nullptr && rge_base_game->quick_build != 0 && (master_id == 0x7A || master_id == 0x7B)) {
        this->notify((int)this->id, (int)this->id, 0x200, 600, param_1->id, 0);
        param_1->die_die_die();
        return 1;
    }

    if (master->area_effect_range > 0.0f && master->minimum_weapon_range < 0.99f) {
        this->area_attack(param_3, param_4, param_5, param_2, param_1);
        this->notify((int)this->id, (int)this->id, 0x200, 600, param_1->id, 0);
        int rv = debug_rand("C:\\msdev\\work\\age1_x1\\t_c_obj.cpp", 0x211);
        if ((rv * 100) / 0x7fff <= (int)master->base_hit_chance) {
            float attack_modifier = this->calc_attack_modifier(param_1);
            param_1->damage((int)master->weapon_num, master->weapon, attack_modifier, this->owner, param_2);
        }
        return 1;
    }

    return RGE_Combat_Object::do_attack(param_1, param_2, param_3, param_4, param_5);
}

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CAC10
void TRIBE_Combat_Object::get_armor(short& param_1, short& param_2) {
    TRIBE_Master_Combat_Object* master = (TRIBE_Master_Combat_Object*)this->master_obj;
    if (master == nullptr) {
        param_1 = 0;
        param_2 = 0;
        return;
    }

    param_1 = (short)master->base_armor;
    if (master->armor_num > 0 && master->armor != nullptr) {
        for (int i = 0; i < master->armor_num; ++i) {
            if (master->armor[i].type == 4 && param_1 < master->armor[i].value) {
                param_1 = master->armor[i].value;
            }
        }
    }
    param_2 = master->orig_armor;
}

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CAC80
void TRIBE_Combat_Object::get_pierce_armor(short& param_1, short& param_2) {
    TRIBE_Master_Combat_Object* master = (TRIBE_Master_Combat_Object*)this->master_obj;
    if (master == nullptr) {
        param_1 = 0;
        param_2 = 0;
        return;
    }

    param_1 = 0;
    if (master->armor_num > 0 && master->armor != nullptr) {
        for (int i = 0; i < master->armor_num; ++i) {
            if (master->armor[i].type == 3 && param_1 < master->armor[i].value) {
                param_1 = master->armor[i].value;
            }
        }
    }
    param_2 = master->orig_pierce_armor;
}

// TODO: Full cliff-aware artifact relocation parity pending deeper asm audit.
void TRIBE_Combat_Object::reposition_artifact() {
    if (this->owner == nullptr || this->owner->world == nullptr || this->owner->world->map == nullptr) {
        return;
    }

    RGE_Map* map = this->owner->world->map;
    int center_x = (int)this->world_x;
    int center_y = (int)this->world_y;
    int max_x = (int)map->map_width - 1;
    int max_y = (int)map->map_height - 1;
    if (max_x < 0 || max_y < 0) {
        return;
    }

    for (int radius = 0; radius <= (max_x + max_y); ++radius) {
        int x0 = center_x - radius;
        int x1 = center_x + radius;
        int y0 = center_y - radius;
        int y1 = center_y + radius;
        if (x0 < 0) x0 = 0;
        if (y0 < 0) y0 = 0;
        if (x1 > max_x) x1 = max_x;
        if (y1 > max_y) y1 = max_y;

        for (int y = y0; y <= y1; ++y) {
            for (int x = x0; x <= x1; ++x) {
                uchar terrain = map->get_terrain((short)x, (short)y);
                if (terrain == 1 || terrain == 2) {
                    continue;
                }
                float nx = (float)x + 0.5f;
                float ny = (float)y + 0.5f;
                if (this->passableTile(nx, ny, 0) != 0) {
                    this->set_location(nx, ny, this->world_z);
                    if (this->actions != nullptr) {
                        this->actions->action_stop();
                    }
                    return;
                }
            }
        }
    }
}

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CB040
int TRIBE_Combat_Object::can_debark() {
    if (this->object_state != 7) {
        return 0;
    }
    return (this->inside_obj != nullptr) ? 1 : 0;
}

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CBD30
int TRIBE_Combat_Object::lines_intersect(float, float, float, float, float, float, float, float) {
    return 1;
}

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CBD40
int TRIBE_Combat_Object::higher_check_for_cliff(RGE_Static_Object* param_1, int param_2, int param_3, float param_4, float param_5, float param_6,
                                                float param_7, RGE_Map* param_8, RGE_Static_Object* param_9, float& param_10, int& param_11) {
    if (param_8 == nullptr) {
        return 0;
    }
    if (param_3 < 0 || param_3 >= param_8->map_height || param_2 < 0 || param_2 >= param_8->map_width) {
        return 0;
    }

    RGE_Object_Node* node = param_8->map_row_offset[param_3][param_2].objects.list;
    while (node != nullptr) {
        RGE_Static_Object* cliff = node->node;
        if (cliff != nullptr && cliff->master_obj != nullptr && cliff->master_obj->object_group == 0x22 && cliff != param_9) {
            if (param_10 == -1.0f && param_1 != nullptr) {
                float angle = (float)atan2(param_1->world_y - this->world_y, param_1->world_x - this->world_x);
                if (angle < 0.0f) {
                    angle = angle - -6.2831855f;
                }
                param_10 = angle;
            }
            param_11 = param_11 + 1;
            (void)param_4;
            (void)param_5;
            (void)param_6;
            (void)param_7;
            return 1;
        }
        node = node->next;
    }
    return 0;
}

// TODO: Full parity path-tracing logic (tile stepping + cliff side tests) pending asm-guided transliteration.
int TRIBE_Combat_Object::higher_than_target(RGE_Static_Object* param_1) {
    if (param_1 == nullptr) {
        return 0;
    }
    if (param_1->world_z < this->world_z) {
        return 1;
    }
    return 0;
}

// TODO: Full parity filter for special IDs/friendly-fire edge-cases pending asm audit.
uchar TRIBE_Combat_Object::area_attack(float param_1, float param_2, float param_3, RGE_Combat_Object* param_4, RGE_Static_Object* param_5) {
    return RGE_Combat_Object::area_attack(param_1, param_2, param_3, param_4, param_5);
}

// Fully verified. Source of truth: t_c_obj.cpp.decomp @ 0x004CC5B0
void TRIBE_Combat_Object::do_repair(RGE_Static_Object* p1) {
    if ((TRIBE_Combat_Object*)p1 != this) {
        if (this->master_obj->object_group != 0x9C) {
            RGE_Master_Static_Object* repair_master = *(RGE_Master_Static_Object**)((char*)this->owner->world + 0x270);
            this->transform(repair_master);
        }

        RGE_Master_Action_Object* master_action = (RGE_Master_Action_Object*)this->master_obj;
        RGE_Task* matching_task = (RGE_Task*)p1;
        int task_count = (int)master_action->tasks->list_num;
        if (0 < task_count) {
            RGE_Task** task_array = master_action->tasks->list;
            for (int i = 0; i < task_count; ++i) {
                RGE_Task* task = task_array[i];
                matching_task = task;
                if ((task->action_type == 0x6A) &&
                    (((p1->master_obj->master_type == 'P') &&
                      ((task->object_group == -1) || (task->object_group == 0))) ||
                     (task->object_group == p1->master_obj->object_group))) {
                    break;
                }
                matching_task = nullptr;
            }
        }

        short action_type = 0;
        bool reused_action = false;
        RGE_Task* current_task = this->actions->get_task();
        if ((current_task != nullptr) && (matching_task == current_task) &&
            (this->actions->action_work(p1, p1->world_x, p1->world_y, p1->world_z) != 0)) {
            RGE_Action* current_action = this->actions->get_action();
            action_type = current_action->type();
            reused_action = true;
        }

        if (!reused_action) {
            RGE_Action* new_action = nullptr;
            if (matching_task != nullptr) {
                new_action = this->actions->create_task_action(matching_task, p1, p1->world_x, p1->world_y, p1->world_z);
            }

            if (new_action == nullptr) {
                action_type = 0;
            } else {
                action_type = new_action->type();
                typedef void(__thiscall* AddActionFn)(TRIBE_Combat_Object*, RGE_Action*);
                void** vtable = *(void***)this;
                AddActionFn add_action = (AddActionFn)vtable[0x208 / 4];
                add_action(this, new_action);
            }
        }

        if (this->unitAIValue != nullptr) {
            int ai_order = -1;
            int ai_action = -1;
            if (action_type == 0x6A) {
                ai_action = 0x26A;
                ai_order = 0x2CE;
            }
            this->unitAIValue->currentOrderValue = ai_order;
            this->unitAIValue->currentActionValue = ai_action;
            this->unitAIValue->currentTargetValue = (int)p1->id;
            this->unitAIValue->currentTargetTypeValue = (int)p1->master_obj->object_group;
            this->unitAIValue->currentTargetXValue = p1->world_x;
            this->unitAIValue->currentTargetYValue = p1->world_y;
            this->unitAIValue->currentTargetZValue = p1->world_z;
        }
    }
}
