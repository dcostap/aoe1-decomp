#include "../include/RGE_Combat_Object.h"
#include "../include/RGE_Action.h"
#include "../include/RGE_Action_List.h"
#include "../include/RGE_Armor_Weapon_Info.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Master_Combat_Object.h"
#include "../include/RGE_Object_Node.h"
#include "../include/RGE_Player.h"
#include "../include/globals.h"
#include "../include/debug_helpers.h"

#include <math.h>
#include <stdio.h>
#include <string.h>

// Default constructor
RGE_Combat_Object::RGE_Combat_Object()
    : RGE_Action_Object()
{
    for (int i = 0; i < 9; i++) {
        this->VUR_Ptrs[i] = nullptr;
    }
    this->Unified_Map_Value = 0;
    this->attack_timer = 0.0f;
    this->capture_flag = '\0';
}

// Fully verified. Source of truth: com_obj.cpp.decomp @ 0x0042F9E0
RGE_Combat_Object::RGE_Combat_Object(int param_1, RGE_Game_World* param_2, int param_3)
    : RGE_Action_Object(param_1, param_2, 0)
{
    if (param_3 != 0) {
        this->setup(param_1, param_2);
    }
}

// Fully verified. Source of truth: com_obj.cpp.decomp @ 0x0042FBA0
int RGE_Combat_Object::setup(int param_1, RGE_Game_World* param_2) {
    // Zero VUR_Ptrs and Unified_Map_Value before base setup
    for (int i = 0; i < 9; i++) {
        this->VUR_Ptrs[i] = nullptr;
    }
    this->Unified_Map_Value = 0;

    RGE_Action_Object::setup(param_1, param_2);
    this->type = 0x32;

    rge_read(param_1, &this->attack_timer, 4);

    if (save_game_version >= 2.01f) {
        rge_read(param_1, &this->capture_flag, 1);
    }

    return 1;
}

// Fully verified. Source of truth: com_obj.cpp.decomp @ 0x0042FC10
void RGE_Combat_Object::save(int param_1) {
    RGE_Action_Object::save(param_1);
    rge_write(param_1, &this->attack_timer, 4);
    rge_write(param_1, &this->capture_flag, 1);
}

// Source of truth: com_obj.cpp.decomp @ 0x0042FC50
void RGE_Combat_Object::stop() {
    RGE_Action_Object::stop();

    if (this->unitAIValue != nullptr) {
        if (actionFile != nullptr) {
            fprintf(actionFile, "%d call stopObject %s %d\n", (int)this->id, "C:\\msdev\\work\\age1_x1\\com_obj.cpp", 0xab);
        }

        using UnitAIStopFn = void(__thiscall*)(void* /*this*/, int);
        void** vtbl = *(void***)this->unitAIValue;
        ((UnitAIStopFn)vtbl[0x58 / 4])((void*)this->unitAIValue, 1);
    }
}

// Fully verified. Source of truth: com_obj.cpp.decomp @ 0x0042FC90
float RGE_Combat_Object::calc_attack_modifier(RGE_Static_Object* /*param_1*/) {
    return 1.0f;
}

// Source of truth: com_obj.cpp.decomp @ 0x004304A0
void RGE_Combat_Object::reset_attack_timer() {
    RGE_Master_Combat_Object* master = (RGE_Master_Combat_Object*)this->master_obj;
    this->attack_timer = master->speed_of_attack;
}

// Fully verified. Source of truth: com_obj.cpp.decomp @ 0x00430480
uchar RGE_Combat_Object::can_attack() {
    return (0.0f < this->attack_timer) ? 0 : 1;
}

// Source of truth: com_obj.cpp.decomp @ 0x00430570
void RGE_Combat_Object::get_weapon_range(float& param_1, float& param_2) {
    RGE_Master_Combat_Object* master = (RGE_Master_Combat_Object*)this->master_obj;
    param_1 = (master != nullptr) ? master->weapon_range : 0.0f;
    param_2 = (master != nullptr) ? master->minimum_weapon_range : 0.0f;
}

// Source of truth: com_obj.cpp.decomp @ 0x004305A0
void RGE_Combat_Object::get_speed_of_attack(float& param_1, float& param_2) {
    RGE_Master_Combat_Object* master = (RGE_Master_Combat_Object*)this->master_obj;
    param_1 = (master != nullptr) ? master->speed_of_attack : 0.0f;
    param_2 = (master != nullptr) ? master->orig_speed_of_attack : 0.0f;
}

// Source of truth: com_obj.cpp.decomp @ 0x004304B0
void RGE_Combat_Object::get_armor(short& param_1, short& param_2) {
    RGE_Master_Combat_Object* master = (RGE_Master_Combat_Object*)this->master_obj;
    if (master == nullptr) {
        param_1 = 0;
        param_2 = 0;
        return;
    }

    short max_armor = (short)master->base_armor;
    if (master->armor_num > 0 && master->armor != nullptr) {
        for (int i = 0; i < (int)master->armor_num; ++i) {
            short val = master->armor[i].value;
            if (max_armor < val) {
                max_armor = val;
            }
        }
    }
    param_1 = max_armor;
    param_2 = master->orig_armor;
}

// Source of truth: com_obj.cpp.decomp @ 0x00430510
void RGE_Combat_Object::get_weapon(short& param_1, short& param_2) {
    RGE_Master_Combat_Object* master = (RGE_Master_Combat_Object*)this->master_obj;
    if (master == nullptr) {
        param_1 = 0;
        param_2 = 0;
        return;
    }

    short max_weapon = 0;
    if (master->weapon_num > 0 && master->weapon != nullptr) {
        for (int i = 0; i < (int)master->weapon_num; ++i) {
            short val = master->weapon[i].value;
            if (max_weapon < val) {
                max_weapon = val;
            }
        }
    }
    param_1 = max_weapon;
    param_2 = master->orig_weapon;
}

// Source of truth: com_obj.cpp.decomp @ 0x004303A0
float RGE_Combat_Object::calculateDamage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* /*param_4*/, RGE_Static_Object* /*param_5*/) {
    RGE_Master_Combat_Object* master = (RGE_Master_Combat_Object*)this->master_obj;
    if (master == nullptr) {
        return 0.0f;
    }

    float terrain_mod = 1.0f;
    if (master->defense_terrain_bonus >= 0 && this->tile != nullptr && this->owner != nullptr && this->owner->world != nullptr &&
        this->owner->world->terrains != nullptr) {
        int bonus_idx = (int)master->defense_terrain_bonus;
        if (bonus_idx >= 0 && bonus_idx < (int)this->owner->world->terrain_num) {
            int terr = (int)(this->tile->terrain_type & 0x1f);
            if (terr >= 0 && terr < (int)this->owner->world->terrain_size && this->owner->world->terrains[bonus_idx] != nullptr) {
                terrain_mod = this->owner->world->terrains[bonus_idx][terr];
            }
        }
    }

    float total = 0.0f;
    if (param_1 > 0 && param_2 != nullptr) {
        for (int i = 0; i < param_1; ++i) {
            int armor_val = (int)master->base_armor;
            if (master->armor_num > 0 && master->armor != nullptr) {
                for (int j = 0; j < (int)master->armor_num; ++j) {
                    if (master->armor[j].type == param_2[i].type) {
                        armor_val = (int)master->armor[j].value;
                    }
                }
            }

            float dmg = ((float)(int)param_2[i].value - (float)armor_val) * terrain_mod * param_3;
            if (dmg > 0.0f) {
                total = total + dmg;
            }
        }
    }
    return total;
}

// Source of truth: com_obj.cpp.decomp @ 0x00430320
void RGE_Combat_Object::damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5) {
    float dmg = this->calculateDamage(param_1, param_2, param_3, param_4, param_5);
    float result = this->hp - dmg;
    this->hp = result;

    if (param_5 != nullptr) {
        long attacker_id = param_5->id;
        long uVar3 = 0;
        if (this->master_obj != nullptr) {
            uVar3 = (long)this->master_obj->hp;
        }
        this->notify((int)attacker_id, (int)this->id, 500, attacker_id, uVar3, 0);
    }

    if (result < 1.0f) {
        this->hp = 0.0f;
    }
}

// Source of truth: com_obj.cpp.decomp @ 0x00430230
uchar RGE_Combat_Object::do_attack(RGE_Static_Object* param_1, RGE_Combat_Object* param_2, float param_3, float param_4, float param_5) {
    if (param_1 == nullptr) {
        return 0;
    }

    RGE_Master_Combat_Object* master = (RGE_Master_Combat_Object*)this->master_obj;
    if (master == nullptr) {
        return 0;
    }

    if (master->area_effect_range > 0.0f) {
        this->area_attack(param_3, param_4, param_5, param_2, nullptr);
        return 1;
    }

    this->notify((int)this->id, (int)this->id, 0x200, 0x258, (long)param_1->id, 0);

    int rv = debug_rand("C:\\msdev\\work\\age1_x1\\com_obj.cpp", 0x17b);
    if ((rv * 100) / 0x7fff <= (int)master->base_hit_chance) {
        float attack_modifier = this->calc_attack_modifier(param_1);
        param_1->damage((int)master->weapon_num, master->weapon, attack_modifier, this->owner, (RGE_Static_Object*)param_2);
    }

    return 1;
}

// Source of truth: com_obj.cpp.decomp @ 0x0042FCA0
uchar RGE_Combat_Object::area_attack(float param_1, float param_2, float param_3, RGE_Combat_Object* param_4, RGE_Static_Object* param_5) {
    (void)param_3;

    RGE_Master_Combat_Object* master = (RGE_Master_Combat_Object*)this->master_obj;
    if (master == nullptr || master->area_effect_range <= 0.0f) {
        return 0;
    }
    if (this->owner == nullptr || this->owner->world == nullptr || this->owner->world->map == nullptr) {
        return 0;
    }

    RGE_Map* map = this->owner->world->map;
    int map_w = (int)map->map_width;
    int map_h = (int)map->map_height;

    int cx = (int)param_1;
    int cy = (int)param_2;
    int min_x = cx - 2;
    int max_x = cx + 2;
    int min_y = cy - 2;
    int max_y = cy + 2;

    if (min_x < 0) min_x = 0;
    if (min_y < 0) min_y = 0;
    if (max_x > map_w) max_x = map_w;
    if (max_y > map_h) max_y = map_h;

    float radius = master->area_effect_range;
    float r2 = radius * radius;

    for (int y = min_y; y < max_y; ++y) {
        for (int x = min_x; x < max_x; ++x) {
            RGE_Object_Node* node = map->map_row_offset[y][x].objects.list;
            for (; node != nullptr; node = node->next) {
                RGE_Static_Object* obj = node->node;
                if (obj == nullptr || obj == (RGE_Static_Object*)this || obj == param_5) {
                    continue;
                }

                if (obj->master_obj == nullptr || obj->master_obj->combat_level < master->area_effect_level) {
                    continue;
                }

                float dx = obj->world_x - param_1;
                float dy = obj->world_y - param_2;
                if (dx < 0.0f) dx = -dx;
                if (dy < 0.0f) dy = -dy;

                float rx = obj->master_obj->radius_x;
                float ry = obj->master_obj->radius_y;
                dx = (dx <= rx) ? 0.0f : (dx - rx);
                dy = (dy <= ry) ? 0.0f : (dy - ry);

                if (dx * dx + dy * dy < r2) {
                    int rv = debug_rand("C:\\msdev\\work\\age1_x1\\com_obj.cpp", 0xfa);
                    if ((rv * 100) / 0x7fff <= (int)master->base_hit_chance) {
                        float attack_modifier = this->calc_attack_modifier(obj);
                        obj->damage((int)master->weapon_num, master->weapon, attack_modifier, this->owner, (RGE_Static_Object*)param_4);
                    }
                }
            }
        }
    }

    return 1;
}

// Source of truth: com_obj.cpp.decomp @ 0x0042FF50
uchar RGE_Combat_Object::attack(RGE_Static_Object* param_1, RGE_Combat_Object* param_2) {
    if (param_1 == nullptr) {
        return 0;
    }
    return this->do_attack(param_1, param_2, param_1->world_x, param_1->world_y, param_1->world_z);
}

// Source of truth: com_obj.cpp.decomp @ 0x004300F0
uchar RGE_Combat_Object::attack(float param_1, float param_2, float param_3, RGE_Combat_Object* param_4) {
    return this->area_attack(param_1, param_2, param_3, param_4, nullptr);
}

// Source of truth: com_obj.cpp.decomp @ 0x00430680
uchar RGE_Combat_Object::update() {
    if (this->attack_timer > 0.0f && this->owner != nullptr && this->owner->world != nullptr) {
        this->attack_timer = this->attack_timer - this->owner->world->world_time_delta_seconds;
        if (this->attack_timer < 0.0f) {
            this->attack_timer = 0.0f;
        }
    }
    return RGE_Action_Object::update();
}

// Source of truth: com_obj.cpp.decomp @ 0x00431490
float RGE_Combat_Object::rateOfFire() {
    RGE_Master_Combat_Object* master = (RGE_Master_Combat_Object*)this->master_obj;
    return (master != nullptr) ? master->speed_of_attack : 0.0f;
}

// Source of truth: com_obj.cpp.decomp @ 0x004315A0
float RGE_Combat_Object::weaponRange() {
    RGE_Master_Combat_Object* master = (RGE_Master_Combat_Object*)this->master_obj;
    return (master != nullptr) ? master->weapon_range : 0.0f;
}

// Source of truth: com_obj.cpp.decomp @ 0x004315B0
float RGE_Combat_Object::minimumWeaponRange() {
    RGE_Master_Combat_Object* master = (RGE_Master_Combat_Object*)this->master_obj;
    return (master != nullptr) ? master->minimum_weapon_range : 0.0f;
}

// Source of truth: com_obj.cpp.decomp @ 0x004314A0
float RGE_Combat_Object::damageCapability() {
    RGE_Master_Combat_Object* master = (RGE_Master_Combat_Object*)this->master_obj;
    if (master == nullptr || master->weapon == nullptr || master->weapon_num <= 0) {
        return 0.0f;
    }

    float total = 0.0f;
    for (int i = 0; i < (int)master->weapon_num; ++i) {
        if ((int)master->weapon[i].value > 0) {
            total = total + (float)(int)master->weapon[i].value;
        }
    }
    return total;
}

// Source of truth: com_obj.cpp.decomp @ 0x004314F0
float RGE_Combat_Object::damageCapability(RGE_Static_Object* param_1) {
    if (param_1 == nullptr) {
        return 0.0f;
    }
    RGE_Master_Combat_Object* master = (RGE_Master_Combat_Object*)this->master_obj;
    if (master == nullptr) {
        return 0.0f;
    }

    float attack_modifier = param_1->calc_attack_modifier(this);
    return param_1->calculateDamage((int)master->weapon_num, master->weapon, attack_modifier, this->owner, this);
}

// Source of truth: com_obj.cpp.decomp @ 0x00431530
int RGE_Combat_Object::inAttackRange(RGE_Static_Object* param_1) {
    if (param_1 == nullptr) {
        return 0;
    }

    RGE_Master_Static_Object* target_master = param_1->master_obj;
    float rx = (target_master != nullptr) ? target_master->radius_x : 0.0f;
    float ry = (target_master != nullptr) ? target_master->radius_y : 0.0f;
    float rad = sqrtf(rx * rx + ry * ry);

    float dx = this->world_x - param_1->world_x;
    float dy = this->world_y - param_1->world_y;
    float dist = sqrtf(dx * dx + dy * dy);

    float range = this->weaponRange();
    return (dist <= (range + rad + 0.3f)) ? 1 : 0;
}

// Source of truth: com_obj.cpp.decomp @ 0x004315C0
int RGE_Combat_Object::currentTargetID() {
    if (this->actions != nullptr && this->actions->have_action() == 1) {
        RGE_Action* action = this->actions->get_action();
        if (action != nullptr) {
            RGE_Static_Object* target = action->get_target_obj();
            if (target != nullptr) {
                return (int)target->id;
            }
        }
    }
    return -1;
}

// Source of truth: com_obj.cpp.decomp @ 0x00431610
float RGE_Combat_Object::currentTargetX() {
    if (this->actions != nullptr && this->actions->have_action() == 1) {
        RGE_Action* action = this->actions->get_action();
        if (action != nullptr) {
            return action->target_x;
        }
    }
    return -1.0f;
}

// Source of truth: com_obj.cpp.decomp @ 0x00431640
float RGE_Combat_Object::currentTargetY() {
    if (this->actions != nullptr && this->actions->have_action() == 1) {
        RGE_Action* action = this->actions->get_action();
        if (action != nullptr) {
            return action->target_y;
        }
    }
    return -1.0f;
}

// Source of truth: com_obj.cpp.decomp @ 0x00431670
float RGE_Combat_Object::currentTargetZ() {
    if (this->actions != nullptr && this->actions->have_action() == 1) {
        RGE_Action* action = this->actions->get_action();
        if (action != nullptr) {
            return action->target_z;
        }
    }
    return -1.0f;
}

// Source of truth: com_obj.cpp.decomp @ 0x00431440
int RGE_Combat_Object::stopAction() {
    if (this->actions != nullptr) {
        this->actions->delete_list();
    }
    return 1;
}

// Source of truth: com_obj.cpp.decomp @ 0x00431470
int RGE_Combat_Object::pause() {
    return 1;
}

// Source of truth: com_obj.cpp.decomp @ 0x004308C0
int RGE_Combat_Object::attack(int param_1, int /*param_2*/) {
    if (this->owner == nullptr || this->owner->world == nullptr) {
        return 0;
    }
    RGE_Static_Object* target = this->owner->world->object(param_1);
    if (target == nullptr) {
        return 0;
    }
    if (this->can_attack() == 0) {
        return 0;
    }
    this->do_attack(target, this, target->world_x, target->world_y, target->world_z);
    this->reset_attack_timer();
    return 1;
}

// Source of truth: com_obj.cpp.decomp @ 0x00430A90
int RGE_Combat_Object::attack(float param_1, float param_2, float param_3, int /*param_4*/) {
    if (this->can_attack() == 0) {
        return 0;
    }
    uchar ok = this->attack(param_1, param_2, param_3, this);
    if (ok != 0) {
        this->reset_attack_timer();
        return 1;
    }
    return 0;
}
