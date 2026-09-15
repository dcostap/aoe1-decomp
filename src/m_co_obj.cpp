
#include "../include/m_co_obj.h"
#include "../include/com_obj.h"
#include "../include/game_globals.h"
#include "../include/player.h"
#include "../include/rge_fio.h"
#include "../include/sprite.h"
#include "../include/stat_obj.h"
#include "../include/task.h"
#include "../include/world.h"
#include <stdlib.h>
#include <string.h>

extern float save_game_version;

// m_co_obj.cpp lines 27-30.
RGE_Master_Combat_Object::RGE_Master_Combat_Object(
    RGE_Master_Combat_Object* other_object, int do_setup)
    : RGE_Master_Action_Object(other_object, 0) {
    if (do_setup != 0) {
        setup(other_object);
    }
}

// m_co_obj.cpp lines 36-39.
RGE_Master_Combat_Object::RGE_Master_Combat_Object(
    int infile, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup)
    : RGE_Master_Action_Object(infile, sprites, sounds, 0) {
    if (do_setup != 0) {
        setup(infile, sprites, sounds);
    }
}

// m_co_obj.cpp lines 45-48.
RGE_Master_Combat_Object::RGE_Master_Combat_Object(
    FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id,
    int do_setup)
    : RGE_Master_Action_Object(infile, sprites, sounds, in_id, 0) {
    if (do_setup != 0) {
        setup(infile, sprites, sounds, in_id);
    }
}

// m_co_obj.cpp lines 53-99.
int RGE_Master_Combat_Object::setup(RGE_Master_Combat_Object* other_object) {
    RGE_Master_Action_Object::setup(other_object);
    master_type = 0x32;

    fight_sprite = other_object->fight_sprite;
    base_armor = other_object->base_armor;

    weapon_num = other_object->weapon_num;
    if (weapon_num > 0) {
        weapon = (RGE_Armor_Weapon_Info*)calloc(weapon_num, 4);
        memcpy(weapon, other_object->weapon, weapon_num * 4);
    } else {
        weapon = (RGE_Armor_Weapon_Info*)0;
    }

    armor_num = other_object->armor_num;
    if (armor_num > 0) {
        armor = (RGE_Armor_Weapon_Info*)calloc(armor_num, 4);
        memcpy(armor, other_object->armor, armor_num * 4);
    } else {
        armor = (RGE_Armor_Weapon_Info*)0;
    }

    defense_terrain_bonus = other_object->defense_terrain_bonus;
    weapon_range = other_object->weapon_range;
    area_effect_range = other_object->area_effect_range;
    speed_of_attack = other_object->speed_of_attack;
    missile_id = other_object->missile_id;
    base_hit_chance = other_object->base_hit_chance;
    break_off_combat = other_object->break_off_combat;
    fire_missile_at_frame = other_object->fire_missile_at_frame;
    weapon_offset_x = other_object->weapon_offset_x;
    weapon_offset_y = other_object->weapon_offset_y;
    weapon_offset_z = other_object->weapon_offset_z;
    area_effect_level = other_object->area_effect_level;
    minimum_weapon_range = other_object->minimum_weapon_range;
    orig_armor = other_object->orig_armor;
    orig_weapon = other_object->orig_weapon;
    orig_weapon_range = other_object->orig_weapon_range;
    orig_speed_of_attack = other_object->orig_speed_of_attack;

    return 1;
}

// m_co_obj.cpp lines 104-177.
int RGE_Master_Combat_Object::setup(int infile, RGE_Sprite** sprites, RGE_Sound** sounds) {
    int count;

    RGE_Master_Action_Object::setup(infile, sprites, sounds);
    master_type = 0x32;

    rge_read(infile, &base_armor, 1);
    rge_read(infile, &weapon_num, 2);
    if (weapon_num > 0) {
        weapon = (RGE_Armor_Weapon_Info*)calloc((int)weapon_num, 4);
        rge_read(infile, weapon, (int)weapon_num << 2);
    } else {
        weapon = (RGE_Armor_Weapon_Info*)0;
    }

    rge_read(infile, &armor_num, 2);
    if (armor_num > 0) {
        armor = (RGE_Armor_Weapon_Info*)calloc((int)armor_num, 4);
        rge_read(infile, armor, (int)armor_num << 2);
    } else {
        armor = (RGE_Armor_Weapon_Info*)0;
    }

    rge_read(infile, &defense_terrain_bonus, 2);
    rge_read(infile, &weapon_range, 4);
    rge_read(infile, &area_effect_range, 4);
    rge_read(infile, &speed_of_attack, 4);
    rge_read(infile, &missile_id, 2);
    rge_read(infile, &base_hit_chance, 2);
    rge_read(infile, &break_off_combat, 1);
    rge_read(infile, &fire_missile_at_frame, 2);
    rge_read(infile, &weapon_offset_x, 4);
    rge_read(infile, &weapon_offset_y, 4);
    rge_read(infile, &weapon_offset_z, 4);
    rge_read(infile, &area_effect_level, 1);
    rge_read(infile, &minimum_weapon_range, 4);

    short temp_fight_sprite;
    RGE_Sprite* selected_sprite;
    rge_read(infile, &temp_fight_sprite, 2);
    if (temp_fight_sprite >= 0)
        selected_sprite = sprites[temp_fight_sprite];
    else
        selected_sprite = (RGE_Sprite*)0;
    fight_sprite = selected_sprite;

    if (save_game_version >= DAT_00570500) {
        rge_read(infile, &orig_armor, 2);
        rge_read(infile, &orig_weapon, 2);
        rge_read(infile, &orig_weapon_range, 4);
        rge_read(infile, &orig_speed_of_attack, 4);
        return 1;
    }

    orig_armor = (unsigned char)base_armor;
    count = (int)armor_num;
    if (count > 0) {
        short* value = &armor->value;
        int left = count;
        do {
            if (*value > orig_armor)
                orig_armor = *value;
            value += 2;
            --left;
        } while (left != 0);
    }

    orig_weapon = 0;
    count = (int)weapon_num;
    if (count > 0) {
        short* value = &weapon->value;
        int left = count;
        do {
            if (*value > orig_weapon)
                orig_weapon = *value;
            value += 2;
            --left;
        } while (left != 0);
    }

    orig_weapon_range = weapon_range;
    orig_speed_of_attack = speed_of_attack;
    return 1;
}

// m_co_obj.cpp lines 182-262.
int RGE_Master_Combat_Object::setup(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id) {
    FILE* input = infile;
    short temp_base_armor;
    short temp_area_effect_level;
    short temp_break_off_combat;
    short temp_fire_missile_at_frame;
    short index;
    short* armor_count_value;
    int value_count;
    short temp_fight_sprite;
    RGE_Sprite* selected_sprite;

    RGE_Master_Action_Object::setup(input, sprites, sounds, in_id);
    master_type = 0x32;

    fscanf(input,
           "%hd %hd %hd %hd %hd %f %f %f %hd %hd %hd %hd %f %f %f %hd %f",
           &temp_fight_sprite, &temp_base_armor, &armor_num, &weapon_num,
           &defense_terrain_bonus,
           &weapon_range, &area_effect_range, &speed_of_attack, &missile_id,
           &base_hit_chance, &temp_break_off_combat,
           &temp_fire_missile_at_frame, &weapon_offset_x, &weapon_offset_y,
           &weapon_offset_z, &temp_area_effect_level, &minimum_weapon_range);

    armor_count_value = &armor_num;
    index = 0;
    if (*armor_count_value > 0) {
        armor = (RGE_Armor_Weapon_Info*)calloc((int)*armor_count_value, 4);
        if (0 < armor_num) {
            do {
                fscanf(input, "%hd %hd", &armor[index].type,
                       &armor[index].value);
                ++index;
            } while (index < *armor_count_value);
        }
    } else {
        armor = (RGE_Armor_Weapon_Info*)0;
    }

    index = 0;
    if (weapon_num > 0) {
        weapon = (RGE_Armor_Weapon_Info*)calloc((int)weapon_num, 4);
        if (0 < weapon_num) {
            do {
                fscanf(input, "%hd %hd", &weapon[index].type,
                       &weapon[index].value);
                ++index;
            } while (index < weapon_num);
        }
    } else {
        weapon = (RGE_Armor_Weapon_Info*)0;
    }

    if (temp_fight_sprite >= 0)
        selected_sprite = sprites[temp_fight_sprite];
    else
        selected_sprite = (RGE_Sprite*)0;
    break_off_combat = (unsigned char)temp_break_off_combat;
    area_effect_level = (unsigned char)temp_area_effect_level;
    fight_sprite = selected_sprite;
    base_armor = (unsigned char)temp_base_armor;
    // the shipped parser stores the low byte of this value.
    fire_missile_at_frame = (unsigned char)temp_fire_missile_at_frame;
    orig_armor = (unsigned char)base_armor;
    value_count = (int)armor_num;
    if (value_count > 0) {
        short* value = &armor->value;
        int left = value_count;
        do {
            if (*value > orig_armor)
                orig_armor = *value;
            value += 2;
            --left;
        } while (left != 0);
    }

    orig_weapon = 0;
    value_count = (int)weapon_num;
    if (value_count > 0) {
        short* value = &weapon->value;
        int left = value_count;
        do {
            if (*value > orig_weapon)
                orig_weapon = *value;
            value += 2;
            --left;
        } while (left != 0);
    }

    orig_weapon_range = weapon_range;
    orig_speed_of_attack = speed_of_attack;
    return 1;
}

// m_co_obj.cpp lines 268-280.
RGE_Master_Combat_Object::~RGE_Master_Combat_Object() {
    if (weapon != 0) {
        free(weapon);
        weapon = (RGE_Armor_Weapon_Info*)0;
    }
    if (armor != 0) {
        free(armor);
        armor = (RGE_Armor_Weapon_Info*)0;
    }
}

// m_co_obj.cpp lines 285-299.
RGE_Static_Object* RGE_Master_Combat_Object::make_new_obj(
    RGE_Player* owner, float x, float y, float z) {
    if (recyclable) {
        RGE_Static_Object* recycled =
            owner->world->recycle_object_in_to_game(master_type);
        if (recycled) {
            recycled->recycle_in_to_game(this, owner, x, y, z);
            return recycled;
        }
    }

    return (RGE_Static_Object*)new RGE_Combat_Object(this, owner, x, y, z, 1);
}

// m_co_obj.cpp lines 304-306.
RGE_Master_Static_Object* RGE_Master_Combat_Object::make_new_master() {
    return new RGE_Master_Combat_Object(this, 1);
}

// m_co_obj.cpp lines 311-358.
void RGE_Master_Combat_Object::copy_obj(RGE_Master_Static_Object* source) {
    RGE_Master_Action_Object::copy_obj(source);

    RGE_Master_Combat_Object* other = (RGE_Master_Combat_Object*)source;
    fight_sprite = other->fight_sprite;
    base_armor = other->base_armor;

    weapon_num = other->weapon_num;
    if (weapon != 0)
        free(weapon);
    if (weapon_num > 0) {
        weapon = (RGE_Armor_Weapon_Info*)calloc(weapon_num, 4);
        memcpy(weapon, other->weapon, weapon_num * 4);
    } else {
        weapon = (RGE_Armor_Weapon_Info*)0;
    }

    armor_num = other->armor_num;
    if (armor != 0)
        free(armor);
    if (armor_num > 0) {
        armor = (RGE_Armor_Weapon_Info*)calloc(armor_num, 4);
        memcpy(armor, other->armor, armor_num * 4);
    } else {
        armor = (RGE_Armor_Weapon_Info*)0;
    }

    defense_terrain_bonus = other->defense_terrain_bonus;
    weapon_range = other->weapon_range;
    area_effect_range = other->area_effect_range;
    speed_of_attack = other->speed_of_attack;
    missile_id = other->missile_id;
    base_hit_chance = other->base_hit_chance;
    break_off_combat = other->break_off_combat;
    fire_missile_at_frame = other->fire_missile_at_frame;
    weapon_offset_x = other->weapon_offset_x;
    weapon_offset_y = other->weapon_offset_y;
    weapon_offset_z = other->weapon_offset_z;
    area_effect_level = other->area_effect_level;
    minimum_weapon_range = other->minimum_weapon_range;
    orig_armor = other->orig_armor;
    orig_weapon = other->orig_weapon;
    orig_weapon_range = other->orig_weapon_range;
    orig_speed_of_attack = other->orig_speed_of_attack;
}

// m_co_obj.cpp lines 362-402.
void RGE_Master_Combat_Object::modify(float amount, unsigned char flag) {
    switch (flag) {
    case 8: {
        long packed = (long)amount;
        unsigned short index = (unsigned short)((packed >> 8) & 0xff);
        RGE_Armor_Weapon_Info* entries = armor;
        if (entries != 0) {
            if ((int)index < (int)armor_num) {
                entries[index].value = (short)(packed & 0xff);
            }
        }
        break;
    }
    case 9: {
        long packed = (long)amount;
        unsigned short index = (unsigned short)((packed >> 8) & 0xff);
        RGE_Armor_Weapon_Info* entries = weapon;
        if (entries != 0) {
            if ((int)index < (int)weapon_num) {
                entries[index].value = (short)(packed & 0xff);
            }
        }
        break;
    }
    case 10:
        speed_of_attack = amount;
        break;
    case 11:
        base_hit_chance = (short)amount;
        break;
    case 12:
        weapon_range = amount;
        break;
    case 15:
        base_armor = (unsigned char)amount;
        break;
    case 16:
        missile_id = (short)(unsigned char)amount;
        break;
    case 18:
        defense_terrain_bonus = (short)amount;
        break;
    default:
        RGE_Master_Action_Object::modify(amount, flag);
        break;
    }
}

// m_co_obj.cpp lines 406-468.
void RGE_Master_Combat_Object::modify_delta(float amount, unsigned char flag) {
    switch (flag) {
    case 8: {
        int encoded = (int)amount;
        unsigned short type = (unsigned short)((encoded >> 8) & 0xff);
        RGE_Armor_Weapon_Info* entries = armor;
        if (entries != 0) {
            int count = armor_num;
            unsigned short index = 0;
            for (; index < count; ++index) {
                if ((int)entries[index].type == type) {
                    entries[index].value += (short)(encoded & 0xff);
                    return;
                }
            }
        }
        break;
    }
    case 9: {
        int encoded = (int)amount;
        unsigned short type = (unsigned short)((encoded >> 8) & 0xff);
        RGE_Armor_Weapon_Info* entries = weapon;
        if (entries != 0) {
            int count = weapon_num;
            unsigned short index = 0;
            for (; index < count; ++index) {
                if ((int)entries[index].type == type) {
                    entries[index].value += (short)(encoded & 0xff);
                    return;
                }
            }
        }
        break;
    }
    case 6:
        turn_speed = (float)((double)amount + (double)turn_speed);
        break;
    case 10:
        speed_of_attack = (float)((double)amount + (double)speed_of_attack);
        break;
    case 11:
        base_hit_chance += (short)(long)amount;
        break;
    case 12:
        weapon_range = (float)((double)amount + (double)weapon_range);
        break;
    case 15:
        base_armor += (unsigned char)(long)amount;
        break;
    case 16:
        missile_id += (short)(long)amount;
        break;
    case 18:
        defense_terrain_bonus = (short)(long)amount;
        break;
    default:
        RGE_Master_Action_Object::modify_delta(amount, flag);
        break;
    }
}

// m_co_obj.cpp lines 472-504.
void RGE_Master_Combat_Object::modify_percent(float amount, unsigned char flag) {
    switch (flag) {
    case 8:
    case 9:
        break;
    case 6:
        turn_speed = (float)((double)amount * (double)turn_speed);
        break;
    case 10:
        speed_of_attack = (float)((double)amount * (double)speed_of_attack);
        break;
    case 11:
        base_hit_chance = (short)((float)base_hit_chance * amount);
        break;
    case 12:
        weapon_range = (float)((double)amount * (double)weapon_range);
        break;
    case 15:
        // the shipped case 15 path uses missile_id as its source.
        base_armor = (unsigned char)((float)missile_id * amount);
        break;
    case 16:
        missile_id = (short)((float)missile_id * amount);
        break;
    case 18:
        defense_terrain_bonus = (short)amount;
        break;
    default:
        RGE_Master_Action_Object::modify_percent(amount, flag);
        break;
    }
}

// m_co_obj.cpp lines 509-543.
void RGE_Master_Combat_Object::save(int outfile) {
    RGE_Master_Action_Object::save(outfile);

    short temp_fight_sprite;
    if (fight_sprite != 0)
        temp_fight_sprite = fight_sprite->id;
    else
        temp_fight_sprite = -1;

    rge_write(outfile, &base_armor, 1);
    rge_write(outfile, &weapon_num, 2);
    if (weapon != 0)
        rge_write(outfile, weapon, (int)weapon_num * 4);
    rge_write(outfile, &armor_num, 2);
    if (armor != 0)
        rge_write(outfile, armor, (int)armor_num * 4);
    rge_write(outfile, &defense_terrain_bonus, 2);
    rge_write(outfile, &weapon_range, 4);
    rge_write(outfile, &area_effect_range, 4);
    rge_write(outfile, &speed_of_attack, 4);
    rge_write(outfile, &missile_id, 2);
    rge_write(outfile, &base_hit_chance, 2);
    rge_write(outfile, &break_off_combat, 1);
    rge_write(outfile, &fire_missile_at_frame, 2);
    rge_write(outfile, &weapon_offset_x, 4);
    rge_write(outfile, &weapon_offset_y, 4);
    rge_write(outfile, &weapon_offset_z, 4);
    rge_write(outfile, &area_effect_level, 1);
    rge_write(outfile, &minimum_weapon_range, 4);
    rge_write(outfile, &temp_fight_sprite, 2);
    rge_write(outfile, &orig_armor, 2);
    rge_write(outfile, &orig_weapon, 2);
    rge_write(outfile, &orig_weapon_range, 4);
    rge_write(outfile, &orig_speed_of_attack, 4);
}

// m_co_obj.cpp lines 549-577.
long RGE_Master_Combat_Object::calc_base_damage_ability(
    RGE_Master_Combat_Object* attacker) {
    float total = DAT_00570504;
    int count = attacker->weapon_num;
    RGE_Armor_Weapon_Info* weapon = attacker->weapon;

    if (count > 0) {
        int remaining = count;
        int armor_count = this->armor_num;
        int base_armor = this->base_armor;
        do {
            int n;
            int value = base_armor;
            if (armor_count > 0) {
                short weapon_type = weapon->type;
                RGE_Armor_Weapon_Info* armor = this->armor;
                n = armor_count;
                do {
                    if (armor->type == weapon_type) {
                        value = armor->value;
                    }
                    ++armor;
                    --n;
                } while (n != 0);
            }

            int attack = weapon->value;
            float diff = (float)attack - (float)value;
            if ((double)diff > DAT_00570508) {
                total += diff;
            }
            ++weapon;
            --remaining;
        } while (remaining != 0);
    }

    if ((double)total < DAT_00570510) {
        total = DAT_00570518;
    }
    return (long)total;
}
