
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
    RGE_Master_Combat_Object* source, int do_setup)
    : RGE_Master_Action_Object(source, 0)
{
    if (do_setup != 0) {
        setup(source);
    }
}

// m_co_obj.cpp lines 36-39.
RGE_Master_Combat_Object::RGE_Master_Combat_Object(
    int id, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup)
    : RGE_Master_Action_Object(id, sprites, sounds, 0)
{
    if (do_setup != 0) {
        setup(id, sprites, sounds);
    }
}

// m_co_obj.cpp lines 45-48.
RGE_Master_Combat_Object::RGE_Master_Combat_Object(
    FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short id,
    int do_setup)
    : RGE_Master_Action_Object(file, sprites, sounds, id, 0)
{
    if (do_setup != 0) {
        setup(file, sprites, sounds, id);
    }
}

// m_co_obj.cpp lines 53-99.
int RGE_Master_Combat_Object::setup(RGE_Master_Combat_Object* source)
{
    RGE_Master_Action_Object::setup(source);
    master_type = 0x32;

    fight_sprite = source->fight_sprite;
    base_armor = source->base_armor;

    weapon_num = source->weapon_num;
    if (weapon_num > 0) {
        weapon = (RGE_Armor_Weapon_Info*)calloc(weapon_num, 4);
        memcpy(weapon, source->weapon, weapon_num * 4);
    } else {
        weapon = (RGE_Armor_Weapon_Info*)0;
    }

    armor_num = source->armor_num;
    if (armor_num > 0) {
        armor = (RGE_Armor_Weapon_Info*)calloc(armor_num, 4);
        memcpy(armor, source->armor, armor_num * 4);
    } else {
        armor = (RGE_Armor_Weapon_Info*)0;
    }

    defense_terrain_bonus = source->defense_terrain_bonus;
    weapon_range = source->weapon_range;
    area_effect_range = source->area_effect_range;
    speed_of_attack = source->speed_of_attack;
    missile_id = source->missile_id;
    base_hit_chance = source->base_hit_chance;
    break_off_combat = source->break_off_combat;
    fire_missile_at_frame = source->fire_missile_at_frame;
    weapon_offset_x = source->weapon_offset_x;
    weapon_offset_y = source->weapon_offset_y;
    weapon_offset_z = source->weapon_offset_z;
    area_effect_level = source->area_effect_level;
    minimum_weapon_range = source->minimum_weapon_range;
    orig_armor = source->orig_armor;
    orig_weapon = source->orig_weapon;
    orig_weapon_range = source->orig_weapon_range;
    orig_speed_of_attack = source->orig_speed_of_attack;

    return 1;
}

// m_co_obj.cpp lines 104-177.
int RGE_Master_Combat_Object::setup(int file, RGE_Sprite** sprites,
                                    RGE_Sound** sounds)
{
    int count;

    RGE_Master_Action_Object::setup(file, sprites, sounds);
    master_type = 0x32;

    rge_read(file, &base_armor, 1);
    rge_read(file, &weapon_num, 2);
    if (weapon_num > 0) {
        weapon = (RGE_Armor_Weapon_Info*)calloc((int)weapon_num, 4);
        rge_read(file, weapon, (int)weapon_num << 2);
    } else {
        weapon = (RGE_Armor_Weapon_Info*)0;
    }

    rge_read(file, &armor_num, 2);
    if (armor_num > 0) {
        armor = (RGE_Armor_Weapon_Info*)calloc((int)armor_num, 4);
        rge_read(file, armor, (int)armor_num << 2);
    } else {
        armor = (RGE_Armor_Weapon_Info*)0;
    }

    rge_read(file, &defense_terrain_bonus, 2);
    rge_read(file, &weapon_range, 4);
    rge_read(file, &area_effect_range, 4);
    rge_read(file, &speed_of_attack, 4);
    rge_read(file, &missile_id, 2);
    rge_read(file, &base_hit_chance, 2);
    rge_read(file, &break_off_combat, 1);
    rge_read(file, &fire_missile_at_frame, 2);
    rge_read(file, &weapon_offset_x, 4);
    rge_read(file, &weapon_offset_y, 4);
    rge_read(file, &weapon_offset_z, 4);
    rge_read(file, &area_effect_level, 1);
    rge_read(file, &minimum_weapon_range, 4);

    short sprite_id;
    RGE_Sprite* selected_sprite;
    rge_read(file, &sprite_id, 2);
    if (sprite_id >= 0)
        selected_sprite = sprites[sprite_id];
    else
        selected_sprite = (RGE_Sprite*)0;
    fight_sprite = selected_sprite;

    if (save_game_version >= DAT_00570500) {
        rge_read(file, &orig_armor, 2);
        rge_read(file, &orig_weapon, 2);
        rge_read(file, &orig_weapon_range, 4);
        rge_read(file, &orig_speed_of_attack, 4);
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
int RGE_Master_Combat_Object::setup(FILE* file, RGE_Sprite** sprites,
                                    RGE_Sound** sounds, short count)
{
    FILE* input = file;
    short temp_base_armor;
    short temp_area_effect_level;
    short temp_break_off_combat;
    short temp_fire_missile_at_frame;
    short index;
    short* armor_count_value;
    int value_count;
    short sprite_index;
    RGE_Sprite* selected_sprite;

    RGE_Master_Action_Object::setup(input, sprites, sounds, count);
    master_type = 0x32;

    fscanf(input,
           "%hd %hd %hd %hd %hd %f %f %f %hd %hd %hd %hd %f %f %f %hd %f",
           &sprite_index, &temp_base_armor, &armor_num, &weapon_num,
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

    if (sprite_index >= 0)
        selected_sprite = sprites[sprite_index];
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
RGE_Master_Combat_Object::~RGE_Master_Combat_Object()
{
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
    RGE_Player* player, float x, float y, float z)
{
    if (recyclable) {
        RGE_Static_Object* recycled =
            player->world->recycle_object_in_to_game(master_type);
        if (recycled) {
            recycled->recycle_in_to_game(this, player, x, y, z);
            return recycled;
        }
    }

    return (RGE_Static_Object*)new RGE_Combat_Object(this, player, x, y, z, 1);
}

// m_co_obj.cpp lines 304-306.
RGE_Master_Static_Object* RGE_Master_Combat_Object::make_new_master()
{
    return new RGE_Master_Combat_Object(this, 1);
}

// m_co_obj.cpp lines 311-358.
void RGE_Master_Combat_Object::copy_obj(RGE_Master_Static_Object* source)
{
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
void RGE_Master_Combat_Object::modify(float value, unsigned char attribute)
{
    switch (attribute) {
    case 8: {
        long packed = (long)value;
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
        long packed = (long)value;
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
        speed_of_attack = value;
        break;
    case 11:
        base_hit_chance = (short)value;
        break;
    case 12:
        weapon_range = value;
        break;
    case 15:
        base_armor = (unsigned char)value;
        break;
    case 16:
        missile_id = (short)(unsigned char)value;
        break;
    case 18:
        defense_terrain_bonus = (short)value;
        break;
    default:
        RGE_Master_Action_Object::modify(value, attribute);
        break;
    }
}

// m_co_obj.cpp lines 406-468.
void RGE_Master_Combat_Object::modify_delta(float value,
                                             unsigned char attribute)
{
    switch (attribute) {
    case 8: {
        int encoded = (int)value;
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
        int encoded = (int)value;
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
        turn_speed = (float)((double)value + (double)turn_speed);
        break;
    case 10:
        speed_of_attack = (float)((double)value + (double)speed_of_attack);
        break;
    case 11:
        base_hit_chance += (short)(long)value;
        break;
    case 12:
        weapon_range = (float)((double)value + (double)weapon_range);
        break;
    case 15:
        base_armor += (unsigned char)(long)value;
        break;
    case 16:
        missile_id += (short)(long)value;
        break;
    case 18:
        defense_terrain_bonus = (short)(long)value;
        break;
    default:
        RGE_Master_Action_Object::modify_delta(value, attribute);
        break;
    }
}

// m_co_obj.cpp lines 472-504.
void RGE_Master_Combat_Object::modify_percent(float value,
                                                unsigned char attribute)
{
    switch (attribute) {
    case 6:
        turn_speed = (float)((double)value * (double)turn_speed);
        break;
    case 10:
        speed_of_attack = (float)((double)value * (double)speed_of_attack);
        break;
    case 11:
        base_hit_chance = (short)((float)base_hit_chance * value);
        break;
    case 12:
        weapon_range = (float)((double)value * (double)weapon_range);
        break;
    case 15:
        // the shipped case 15 path uses missile_id as its source.
        base_armor = (unsigned char)((float)missile_id * value);
        break;
    case 16:
        missile_id = (short)((float)missile_id * value);
        break;
    case 18:
        defense_terrain_bonus = (short)value;
        break;
    default:
        RGE_Master_Action_Object::modify_percent(value, attribute);
        break;
    }
}

// m_co_obj.cpp lines 509-543.
void RGE_Master_Combat_Object::save(int file)
{
    RGE_Master_Action_Object::save(file);

    short sprite_id;
    if (fight_sprite != 0)
        sprite_id = fight_sprite->id;
    else
        sprite_id = -1;

    rge_write(file, &base_armor, 1);
    rge_write(file, &weapon_num, 2);
    if (weapon != 0)
        rge_write(file, weapon, (int)weapon_num * 4);
    rge_write(file, &armor_num, 2);
    if (armor != 0)
        rge_write(file, armor, (int)armor_num * 4);
    rge_write(file, &defense_terrain_bonus, 2);
    rge_write(file, &weapon_range, 4);
    rge_write(file, &area_effect_range, 4);
    rge_write(file, &speed_of_attack, 4);
    rge_write(file, &missile_id, 2);
    rge_write(file, &base_hit_chance, 2);
    rge_write(file, &break_off_combat, 1);
    rge_write(file, &fire_missile_at_frame, 2);
    rge_write(file, &weapon_offset_x, 4);
    rge_write(file, &weapon_offset_y, 4);
    rge_write(file, &weapon_offset_z, 4);
    rge_write(file, &area_effect_level, 1);
    rge_write(file, &minimum_weapon_range, 4);
    rge_write(file, &sprite_id, 2);
    rge_write(file, &orig_armor, 2);
    rge_write(file, &orig_weapon, 2);
    rge_write(file, &orig_weapon_range, 4);
    rge_write(file, &orig_speed_of_attack, 4);
}

// m_co_obj.cpp lines 549-577.
long RGE_Master_Combat_Object::calc_base_damage_ability(
    RGE_Master_Combat_Object* target)
{
    float total = DAT_00570504;
    int count = target->weapon_num;
    RGE_Armor_Weapon_Info* weapon = target->weapon;

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
