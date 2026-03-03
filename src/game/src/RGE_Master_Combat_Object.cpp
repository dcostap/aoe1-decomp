#include "../include/RGE_Master_Animated_Object.h"
#include "../include/RGE_Master_Moving_Object.h"
#include "../include/RGE_Master_Action_Object.h"
#include "../include/RGE_Master_Combat_Object.h"
#include "../include/RGE_Master_Missile_Object.h"
#include "../include/RGE_Master_Doppleganger_Object.h"
#include "../include/RGE_Doppleganger_Object.h"
#include "../include/RGE_Animated_Object.h"
#include "../include/RGE_Moving_Object.h"
#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Combat_Object.h"
#include "../include/RGE_Missile_Object.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Armor_Weapon_Info.h"
#include "../include/RGE_Sprite.h"
#include "../include/RGE_Task.h"
#include "../include/globals.h"

#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Task_List.h"
#include <new>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Fully verified. Marker reconciliation coverage.
static int rge_ftol(float value) {
    int result;
    __asm {
        fld value
        fistp result
    }
    return result;
}

// TODO: PARITY [MODERATE]: Default ctor needs explicit offset/ASM mapping in m_co_obj.cpp.decomp audit.
RGE_Master_Combat_Object::RGE_Master_Combat_Object()
    : RGE_Master_Action_Object() {
    this->master_type = 0x32;
    this->fight_sprite = nullptr;
    this->base_armor = 0;
    this->armor_num = 0;
    this->armor = nullptr;
    this->weapon_num = 0;
    this->weapon = nullptr;
    this->defense_terrain_bonus = 0;
    this->weapon_range = 0.0f;
    this->area_effect_range = 0.0f;
    this->area_effect_level = 0;
    this->speed_of_attack = 0.0f;
    this->missile_id = 0;
    this->base_hit_chance = 0;
    this->break_off_combat = 0;
    this->fire_missile_at_frame = 0;
    this->weapon_offset_x = 0.0f;
    this->weapon_offset_y = 0.0f;
    this->weapon_offset_z = 0.0f;
    this->minimum_weapon_range = 0.0f;
    this->orig_armor = 0;
    this->orig_weapon = 0;
    this->orig_weapon_range = 0.0f;
    this->orig_speed_of_attack = 0.0f;
}

// Fully verified. Source of truth: m_co_obj.cpp.decomp @ 0x0044FE40
RGE_Master_Combat_Object::RGE_Master_Combat_Object(RGE_Master_Combat_Object* param_1, int param_2)
    : RGE_Master_Action_Object((RGE_Master_Action_Object*)param_1, 0) {
    this->master_type = 0x32;
    this->fight_sprite = nullptr;
    this->base_armor = 0;
    this->armor_num = 0;
    this->armor = nullptr;
    this->weapon_num = 0;
    this->weapon = nullptr;
    this->defense_terrain_bonus = 0;
    this->weapon_range = 0.0f;
    this->area_effect_range = 0.0f;
    this->area_effect_level = 0;
    this->speed_of_attack = 0.0f;
    this->missile_id = 0;
    this->base_hit_chance = 0;
    this->break_off_combat = 0;
    this->fire_missile_at_frame = 0;
    this->weapon_offset_x = 0.0f;
    this->weapon_offset_y = 0.0f;
    this->weapon_offset_z = 0.0f;
    this->minimum_weapon_range = 0.0f;
    this->orig_armor = 0;
    this->orig_weapon = 0;
    this->orig_weapon_range = 0.0f;
    this->orig_speed_of_attack = 0.0f;

    if (param_2 != 0) {
        this->setup(param_1);
    }
}

// Fully verified. Source of truth: m_co_obj.cpp.decomp @ 0x0044FEC0
RGE_Master_Combat_Object::RGE_Master_Combat_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4)
    : RGE_Master_Action_Object(param_1, param_2, param_3, 0) {
    this->master_type = 0x32;
    this->fight_sprite = nullptr;
    this->base_armor = 0;
    this->armor_num = 0;
    this->armor = nullptr;
    this->weapon_num = 0;
    this->weapon = nullptr;
    this->defense_terrain_bonus = 0;
    this->weapon_range = 0.0f;
    this->area_effect_range = 0.0f;
    this->area_effect_level = 0;
    this->speed_of_attack = 0.0f;
    this->missile_id = 0;
    this->base_hit_chance = 0;
    this->break_off_combat = 0;
    this->fire_missile_at_frame = 0;
    this->weapon_offset_x = 0.0f;
    this->weapon_offset_y = 0.0f;
    this->weapon_offset_z = 0.0f;
    this->minimum_weapon_range = 0.0f;
    this->orig_armor = 0;
    this->orig_weapon = 0;
    this->orig_weapon_range = 0.0f;
    this->orig_speed_of_attack = 0.0f;

    if (param_4 != 0) {
        this->setup(param_1, param_2, param_3);
    }
}

// Fully verified. Source of truth: m_co_obj.cpp.decomp @ 0x0044FF30
RGE_Master_Combat_Object::RGE_Master_Combat_Object(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5)
    : RGE_Master_Action_Object(param_1, param_2, param_3, param_4, 0) {
    this->master_type = 0x32;
    this->fight_sprite = nullptr;
    this->base_armor = 0;
    this->armor_num = 0;
    this->armor = nullptr;
    this->weapon_num = 0;
    this->weapon = nullptr;
    this->defense_terrain_bonus = 0;
    this->weapon_range = 0.0f;
    this->area_effect_range = 0.0f;
    this->area_effect_level = 0;
    this->speed_of_attack = 0.0f;
    this->missile_id = 0;
    this->base_hit_chance = 0;
    this->break_off_combat = 0;
    this->fire_missile_at_frame = 0;
    this->weapon_offset_x = 0.0f;
    this->weapon_offset_y = 0.0f;
    this->weapon_offset_z = 0.0f;
    this->minimum_weapon_range = 0.0f;
    this->orig_armor = 0;
    this->orig_weapon = 0;
    this->orig_weapon_range = 0.0f;
    this->orig_speed_of_attack = 0.0f;

    if (param_5 != 0) {
        this->setup(param_1, param_2, param_3, param_4);
    }
}

// Fully verified. Source of truth: m_co_obj.cpp.decomp @ 0x0044FFB0
int RGE_Master_Combat_Object::setup(RGE_Master_Combat_Object* param_1) {
    RGE_Master_Action_Object::setup((RGE_Master_Action_Object*)param_1);
    this->master_type = 0x32;
    this->fight_sprite = param_1->fight_sprite;
    this->base_armor = param_1->base_armor;

    this->weapon_num = param_1->weapon_num;
    if (this->weapon_num > 0 && param_1->weapon != nullptr) {
        this->weapon = (RGE_Armor_Weapon_Info*)calloc((size_t)this->weapon_num, sizeof(RGE_Armor_Weapon_Info));
        if (this->weapon != nullptr) {
            memcpy(this->weapon, param_1->weapon, (size_t)this->weapon_num * sizeof(RGE_Armor_Weapon_Info));
        }
    }

    this->armor_num = param_1->armor_num;
    if (this->armor_num > 0 && param_1->armor != nullptr) {
        this->armor = (RGE_Armor_Weapon_Info*)calloc((size_t)this->armor_num, sizeof(RGE_Armor_Weapon_Info));
        if (this->armor != nullptr) {
            memcpy(this->armor, param_1->armor, (size_t)this->armor_num * sizeof(RGE_Armor_Weapon_Info));
        }
    }

    this->defense_terrain_bonus = param_1->defense_terrain_bonus;
    this->weapon_range = param_1->weapon_range;
    this->area_effect_range = param_1->area_effect_range;
    this->area_effect_level = param_1->area_effect_level;
    this->speed_of_attack = param_1->speed_of_attack;
    this->missile_id = param_1->missile_id;
    this->base_hit_chance = param_1->base_hit_chance;
    this->break_off_combat = param_1->break_off_combat;
    this->fire_missile_at_frame = param_1->fire_missile_at_frame;
    this->weapon_offset_x = param_1->weapon_offset_x;
    this->weapon_offset_y = param_1->weapon_offset_y;
    this->weapon_offset_z = param_1->weapon_offset_z;
    this->minimum_weapon_range = param_1->minimum_weapon_range;
    this->orig_armor = param_1->orig_armor;
    this->orig_weapon = param_1->orig_weapon;
    this->orig_weapon_range = param_1->orig_weapon_range;
    this->orig_speed_of_attack = param_1->orig_speed_of_attack;
    return 1;
}

// Fully verified. Source of truth: m_co_obj.cpp.decomp @ 0x00450170
int RGE_Master_Combat_Object::setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3) {
    short fight_sprite_idx = -1;

    RGE_Master_Action_Object::setup(param_1, param_2, param_3);
    this->master_type = 0x32;
    rge_read(param_1, &this->base_armor, 1);

    rge_read(param_1, &this->weapon_num, 2);
    if (this->weapon_num > 0) {
        this->weapon = (RGE_Armor_Weapon_Info*)calloc((size_t)this->weapon_num, sizeof(RGE_Armor_Weapon_Info));
        if (this->weapon != nullptr) {
            rge_read(param_1, this->weapon, (int)this->weapon_num * (int)sizeof(RGE_Armor_Weapon_Info));
        }
    }

    rge_read(param_1, &this->armor_num, 2);
    if (this->armor_num > 0) {
        this->armor = (RGE_Armor_Weapon_Info*)calloc((size_t)this->armor_num, sizeof(RGE_Armor_Weapon_Info));
        if (this->armor != nullptr) {
            rge_read(param_1, this->armor, (int)this->armor_num * (int)sizeof(RGE_Armor_Weapon_Info));
        }
    }

    rge_read(param_1, &this->defense_terrain_bonus, 2);
    rge_read(param_1, &this->weapon_range, 4);
    rge_read(param_1, &this->area_effect_range, 4);
    rge_read(param_1, &this->speed_of_attack, 4);
    rge_read(param_1, &this->missile_id, 2);
    rge_read(param_1, &this->base_hit_chance, 2);
    rge_read(param_1, &this->break_off_combat, 1);
    rge_read(param_1, &this->fire_missile_at_frame, 2);
    rge_read(param_1, &this->weapon_offset_x, 4);
    rge_read(param_1, &this->weapon_offset_y, 4);
    rge_read(param_1, &this->weapon_offset_z, 4);
    rge_read(param_1, &this->area_effect_level, 1);
    rge_read(param_1, &this->minimum_weapon_range, 4);
    rge_read(param_1, &fight_sprite_idx, 2);
    this->fight_sprite = (fight_sprite_idx >= 0 && param_2 != nullptr) ? param_2[fight_sprite_idx] : nullptr;

    if (save_game_version >= 7.01f) {
        rge_read(param_1, &this->orig_armor, 2);
        rge_read(param_1, &this->orig_weapon, 2);
        rge_read(param_1, &this->orig_weapon_range, 4);
        rge_read(param_1, &this->orig_speed_of_attack, 4);
    } else {
        this->orig_armor = (short)this->base_armor;
        for (short i = 0; i < this->armor_num; ++i) {
            if (this->armor != nullptr && this->armor[i].value > this->orig_armor) {
                this->orig_armor = this->armor[i].value;
            }
        }
        this->orig_weapon = 0;
        for (short i = 0; i < this->weapon_num; ++i) {
            if (this->weapon != nullptr && this->weapon[i].value > this->orig_weapon) {
                this->orig_weapon = this->weapon[i].value;
            }
        }
        this->orig_weapon_range = this->weapon_range;
        this->orig_speed_of_attack = this->speed_of_attack;
    }
    return 1;
}

// Fully verified. Source of truth: m_co_obj.cpp.decomp @ 0x00450450
int RGE_Master_Combat_Object::setup(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4) {
    short fight_sprite_idx = -1;
    short base_armor = 0;
    short break_off = 0;
    short area_effect_level = 0;

    RGE_Master_Action_Object::setup(param_1, param_2, param_3, param_4);
    this->master_type = 0x32;
    fscanf(param_1,
        " %hd %hd %hd %hd %hd %f %f %f %hd %hd %hd %hd %f %f %f %hd %f",
        &fight_sprite_idx,
        &base_armor,
        &this->armor_num,
        &this->weapon_num,
        &this->defense_terrain_bonus,
        &this->weapon_range,
        &this->area_effect_range,
        &this->speed_of_attack,
        &this->missile_id,
        &this->base_hit_chance,
        &break_off,
        &this->fire_missile_at_frame,
        &this->weapon_offset_x,
        &this->weapon_offset_y,
        &this->weapon_offset_z,
        &area_effect_level,
        &this->minimum_weapon_range);

    this->base_armor = (uchar)base_armor;
    this->break_off_combat = (uchar)break_off;
    this->area_effect_level = (uchar)area_effect_level;

    if (this->armor_num > 0) {
        this->armor = (RGE_Armor_Weapon_Info*)calloc((size_t)this->armor_num, sizeof(RGE_Armor_Weapon_Info));
        for (short i = 0; i < this->armor_num; ++i) {
            if (this->armor == nullptr) {
                break;
            }
            fscanf(param_1, " %hd %hd", &this->armor[i].type, &this->armor[i].value);
        }
    }

    if (this->weapon_num > 0) {
        this->weapon = (RGE_Armor_Weapon_Info*)calloc((size_t)this->weapon_num, sizeof(RGE_Armor_Weapon_Info));
        for (short i = 0; i < this->weapon_num; ++i) {
            if (this->weapon == nullptr) {
                break;
            }
            fscanf(param_1, " %hd %hd", &this->weapon[i].type, &this->weapon[i].value);
        }
    }

    this->fight_sprite = (fight_sprite_idx >= 0 && param_2 != nullptr) ? param_2[fight_sprite_idx] : nullptr;

    this->orig_armor = (short)this->base_armor;
    for (short i = 0; i < this->armor_num; ++i) {
        if (this->armor != nullptr && this->armor[i].value > this->orig_armor) {
            this->orig_armor = this->armor[i].value;
        }
    }
    this->orig_weapon = 0;
    for (short i = 0; i < this->weapon_num; ++i) {
        if (this->weapon != nullptr && this->weapon[i].value > this->orig_weapon) {
            this->orig_weapon = this->weapon[i].value;
        }
    }
    this->orig_weapon_range = this->weapon_range;
    this->orig_speed_of_attack = this->speed_of_attack;
    return 1;
}

// Fully verified. Source of truth: m_co_obj.cpp.decomp @ 0x00450680
RGE_Master_Combat_Object::~RGE_Master_Combat_Object() {
    if (this->weapon != nullptr) {
        free(this->weapon);
        this->weapon = nullptr;
    }
    if (this->armor != nullptr) {
        free(this->armor);
        this->armor = nullptr;
    }
}

// Fully verified. Source of truth: m_co_obj.cpp.decomp @ 0x00450810
void RGE_Master_Combat_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    RGE_Master_Action_Object::copy_obj(param_1);

    RGE_Master_Combat_Object* src = (RGE_Master_Combat_Object*)param_1;
    this->fight_sprite = src->fight_sprite;
    this->base_armor = src->base_armor;

    this->weapon_num = src->weapon_num;
    if (this->weapon != nullptr) {
        free(this->weapon);
    }
    if (this->weapon_num < 1) {
        this->weapon = nullptr;
    } else {
        RGE_Armor_Weapon_Info* p = (RGE_Armor_Weapon_Info*)calloc((int)this->weapon_num, 4);
        this->weapon = p;
        RGE_Armor_Weapon_Info* s = src->weapon;
        for (uint n = (uint)((int)this->weapon_num & 0x3fffffff); n != 0; --n) {
            *p = *s;
            ++s;
            ++p;
        }
    }

    this->armor_num = src->armor_num;
    if (this->armor != nullptr) {
        free(this->armor);
    }
    if (this->armor_num < 1) {
        this->armor = nullptr;
    } else {
        RGE_Armor_Weapon_Info* p = (RGE_Armor_Weapon_Info*)calloc((int)this->armor_num, 4);
        this->armor = p;
        RGE_Armor_Weapon_Info* s = src->armor;
        for (uint n = (uint)((int)this->armor_num & 0x3fffffff); n != 0; --n) {
            *p = *s;
            ++s;
            ++p;
        }
    }

    this->defense_terrain_bonus = src->defense_terrain_bonus;
    this->weapon_range = src->weapon_range;
    this->area_effect_range = src->area_effect_range;
    this->speed_of_attack = src->speed_of_attack;
    this->missile_id = src->missile_id;
    this->base_hit_chance = src->base_hit_chance;
    this->break_off_combat = src->break_off_combat;
    this->fire_missile_at_frame = src->fire_missile_at_frame;
    this->weapon_offset_x = src->weapon_offset_x;
    this->weapon_offset_y = src->weapon_offset_y;
    this->weapon_offset_z = src->weapon_offset_z;
    this->area_effect_level = src->area_effect_level;
    this->minimum_weapon_range = src->minimum_weapon_range;
    this->orig_armor = src->orig_armor;
    this->orig_weapon = src->orig_weapon;
    this->orig_weapon_range = src->orig_weapon_range;
    this->orig_speed_of_attack = src->orig_speed_of_attack;
}

// Fully verified. Source of truth: m_co_obj.cpp.decomp @ 0x00450A00 (ASM-audited with m_co_obj.cpp.asm)
void RGE_Master_Combat_Object::modify(float param_1, uchar param_2) {
    switch (param_2) {
    case '\b':
    case '\t': {
        uint raw = (uint)rge_ftol(param_1);
        ushort value = (ushort)raw;
        ushort index = (ushort)((raw >> 8) & 0xFF);
        RGE_Armor_Weapon_Info* table = nullptr;
        short count = 0;

        if (param_2 == '\b') {
            table = this->armor;
            count = this->armor_num;
        } else {
            table = this->weapon;
            count = this->weapon_num;
        }

        if (table == nullptr || (int)count <= (int)index) {
            return;
        }
        table[index].value = (short)(value & 0xFF);
        return;
    }
    case '\n':
        this->speed_of_attack = param_1;
        return;
    case '\v':
        this->base_hit_chance = (short)rge_ftol(param_1);
        return;
    case '\f':
        this->weapon_range = param_1;
        return;
    case '\x0f':
        this->base_armor = (uchar)rge_ftol(param_1);
        return;
    case '\x10': {
        this->missile_id = (ushort)(uchar)rge_ftol(param_1);
        return;
    }
    case '\x12':
        this->defense_terrain_bonus = (short)rge_ftol(param_1);
        return;
    default:
        RGE_Master_Action_Object::modify(param_1, param_2);
        return;
    }
}

// Fully verified. Source of truth: m_co_obj.cpp.decomp @ 0x00450B09
static void FUN_00450b09() {
    // Alignment thunk/jump-table entry emitted between modify and modify_delta.
}

// Fully verified. Source of truth: m_co_obj.cpp.decomp @ 0x00450B40 (ASM-audited with m_co_obj.cpp.asm)
void RGE_Master_Combat_Object::modify_delta(float param_1, uchar param_2) {
    switch (param_2) {
    case '\x06':
        this->turn_speed = this->turn_speed + param_1;
        return;
    case '\b':
    case '\t': {
        uint raw = (uint)rge_ftol(param_1);
        ushort value = (ushort)raw;
        ushort type = (ushort)((raw >> 8) & 0xFF);
        RGE_Armor_Weapon_Info* table = (param_2 == '\b') ? this->armor : this->weapon;
        short count = (param_2 == '\b') ? this->armor_num : this->weapon_num;
        if (table == nullptr || count <= 0) {
            return;
        }

        ushort idx = 0;
        while ((int)idx < (int)count && (int)table[idx].type != (int)type) {
            idx = (ushort)(idx + 1);
        }
        if ((int)idx >= (int)count) {
            return;
        }
        table[idx].value = (short)(table[idx].value + (short)(value & 0xFF));
        return;
    }
    case '\n':
        this->speed_of_attack = this->speed_of_attack + param_1;
        return;
    case '\v':
        this->base_hit_chance = (short)(this->base_hit_chance + (short)rge_ftol(param_1));
        return;
    case '\f':
        this->weapon_range = this->weapon_range + param_1;
        return;
    case '\x0f':
        this->base_armor = (uchar)(this->base_armor + (char)rge_ftol(param_1));
        return;
    case '\x10':
        this->missile_id = (short)(this->missile_id + (short)rge_ftol(param_1));
        return;
    case '\x12':
        this->defense_terrain_bonus = (short)rge_ftol(param_1);
        return;
    default:
        RGE_Master_Action_Object::modify_delta(param_1, param_2);
        return;
    }
}

// Fully verified. Source of truth: m_co_obj.cpp.decomp @ 0x00450D00 (ASM-audited with m_co_obj.cpp.asm)
void RGE_Master_Combat_Object::modify_percent(float param_1, uchar param_2) {
    switch (param_2) {
    case '\x06':
        this->turn_speed = this->turn_speed * param_1;
        return;
    case '\b':
    case '\t':
        return;
    case '\n':
        this->speed_of_attack = this->speed_of_attack * param_1;
        return;
    case '\v':
        this->base_hit_chance = (short)rge_ftol((float)this->base_hit_chance * param_1);
        return;
    case '\f':
        this->weapon_range = this->weapon_range * param_1;
        return;
    case '\x0f':
        this->base_armor = (uchar)rge_ftol((float)(int)this->missile_id * param_1);
        return;
    case '\x10':
        this->missile_id = (short)rge_ftol((float)this->missile_id * param_1);
        return;
    case '\x12':
        this->defense_terrain_bonus = (short)rge_ftol(param_1);
        return;
    default:
        RGE_Master_Action_Object::modify_percent(param_1, param_2);
        return;
    }
}

// Fully verified. Source of truth: m_co_obj.cpp.decomp @ 0x00450DEA
static void FUN_00450dea() {
    // Alignment thunk/jump-table entry emitted between modify_percent and save.
}

// Fully verified. Source of truth: m_co_obj.cpp.decomp @ 0x00450E20
void RGE_Master_Combat_Object::save(int param_1) {
    int fd = param_1;
    RGE_Master_Action_Object::save(param_1);

    short fight_sprite_id = -1;
    if (this->fight_sprite != nullptr) {
        fight_sprite_id = this->fight_sprite->id;
    }

    rge_write(fd, &this->base_armor, 1);
    rge_write(fd, &this->weapon_num, 2);
    if (this->weapon != nullptr) {
        rge_write(fd, this->weapon, (int)this->weapon_num << 2);
    }
    rge_write(fd, &this->armor_num, 2);
    if (this->armor != nullptr) {
        rge_write(fd, this->armor, (int)this->armor_num << 2);
    }
    rge_write(fd, &this->defense_terrain_bonus, 2);
    rge_write(fd, &this->weapon_range, 4);
    rge_write(fd, &this->area_effect_range, 4);
    rge_write(fd, &this->speed_of_attack, 4);
    rge_write(fd, &this->missile_id, 2);
    rge_write(fd, &this->base_hit_chance, 2);
    rge_write(fd, &this->break_off_combat, 1);
    rge_write(fd, &this->fire_missile_at_frame, 2);
    rge_write(fd, &this->weapon_offset_x, 4);
    rge_write(fd, &this->weapon_offset_y, 4);
    rge_write(fd, &this->weapon_offset_z, 4);
    rge_write(fd, &this->area_effect_level, 1);
    rge_write(fd, &this->minimum_weapon_range, 4);
    rge_write(fd, &fight_sprite_id, 2);
    rge_write(fd, &this->orig_armor, 2);
    rge_write(fd, &this->orig_weapon, 2);
    rge_write(fd, &this->orig_weapon_range, 4);
    rge_write(fd, &this->orig_speed_of_attack, 4);
}
// Fully verified. Marker reconciliation coverage.
RGE_Static_Object* RGE_Master_Combat_Object::make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4) {
    // Fully verified. Source of truth: m_co_obj.cpp.decomp @ 0x004506D0
    if (this->recyclable != 0) {
        RGE_Static_Object* recycled = param_1->world->recycle_object_in_to_game(this->master_type);
        if (recycled != nullptr) {
            recycled->recycle_in_to_game(this, param_1, param_2, param_3, param_4);
            return recycled;
        }
    }

    RGE_Combat_Object* obj = (RGE_Combat_Object*)::operator new(sizeof(RGE_Combat_Object), std::nothrow);
    if (obj != nullptr) {
        obj = new (obj) RGE_Combat_Object(this, param_1, param_2, param_3, param_4, 1);
        return obj;
    }
    return nullptr;
}
// Fully verified. Source of truth: m_co_obj.cpp.decomp @ 0x004507A0
RGE_Master_Static_Object* RGE_Master_Combat_Object::make_new_master() {
    RGE_Master_Combat_Object* master =
        (RGE_Master_Combat_Object*)::operator new(sizeof(RGE_Master_Combat_Object), std::nothrow);
    if (master != nullptr) {
        master = new (master) RGE_Master_Combat_Object(this, 1);
        return master;
    }
    return nullptr;
}
// Fully verified. Marker reconciliation coverage.
uchar RGE_Master_Combat_Object::check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10) { return this->RGE_Master_Static_Object::check_placement(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
// Fully verified. Marker reconciliation coverage.
uchar RGE_Master_Combat_Object::alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4) { return this->RGE_Master_Static_Object::alignment(param_1, param_2, param_3, param_4); }
// Fully verified. Source of truth: m_co_obj.cpp.decomp @ 0x00451000
long RGE_Master_Combat_Object::calc_base_damage_ability(RGE_Master_Combat_Object* param_1) {
    float total = 0.0f;
    int weapon_count = (int)param_1->weapon_num;
    RGE_Armor_Weapon_Info* weapon = param_1->weapon;
    if (weapon_count > 0) {
        int armor_count = (int)this->armor_num;
        int base_armor = (int)this->base_armor;
        for (int i = 0; i < weapon_count; ++i) {
            int armor_value = base_armor;
            if (armor_count > 0) {
                short weapon_type = weapon->type;
                RGE_Armor_Weapon_Info* armor = this->armor;
                int remaining = armor_count;
                while (remaining != 0) {
                    if (armor->type == weapon_type) {
                        armor_value = (int)armor->value;
                    }
                    ++armor;
                    --remaining;
                }
            }

            float damage = (float)((int)weapon->value - armor_value);
            if (damage > 0.0f) {
                total = total + damage;
            }
            ++weapon;
        }
    }

    if (total < 0.0f) {
        total = 0.0f;
    }

    long result;
    __asm {
        fld total
        fistp result
    }
    return result;
}
// Fully verified. Source of truth: m_ac_obj.cpp.decomp @ 0x0044F980
void RGE_Master_Combat_Object::play_command_sound() {
    if (this->command_sound != nullptr) {
        this->command_sound->play(1);
    }
}
// Fully verified. Source of truth: m_ac_obj.cpp.decomp @ 0x0044F9A0
void RGE_Master_Combat_Object::play_move_sound() {
    if (this->move_sound != nullptr) {
        this->move_sound->play(1);
    }
}
// Fully verified. Marker reconciliation coverage.
void RGE_Master_Combat_Object::draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8) { this->RGE_Master_Static_Object::draw(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
// Fully verified. Marker reconciliation coverage.
RGE_Task_List* RGE_Master_Combat_Object::create_task_list() { return new RGE_Task_List(); }

