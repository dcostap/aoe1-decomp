// VA: 0044FFB0 RGE_Master_Combat_Object::setup (438B)
// m_co_obj.cpp
//
// Attempt log:
// - Baseline used the same-TU master-action base, named combat fields, and
//   typed four-byte armor/weapon records with calloc/memcpy.
// - Positive `count > 0` allocation arms (rather than negative null guards)
//   reproduce the original VC5 test/jle block layout for both arrays.
// - Exact under the default /O2 /Oy flags; no custom flags or compiler-only
//   scaffolding retained.

#ifndef RGE_MCO_OBJ_SHARED_CONTEXT
#include <stdlib.h>
#include <string.h>

class RGE_Sprite;
class RGE_Master_Static_Object;

class RGE_Armor_Weapon_Info {
public:
    short type;
    short value;
};

class RGE_Master_Action_Object {
public:
    virtual ~RGE_Master_Action_Object();
    virtual void copy_obj(RGE_Master_Static_Object* object);
    virtual void modify(float value, unsigned char attribute);
    virtual void modify_delta(float value, unsigned char attribute);
    virtual void modify_percent(float value, unsigned char attribute);
    virtual void save(int file);

    unsigned char master_type;
    char gap_005[0xF7];

    int setup(RGE_Master_Action_Object* source);
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    RGE_Sprite* fight_sprite;
    unsigned char base_armor;
    unsigned char gap_101[1];
    short armor_num;
    RGE_Armor_Weapon_Info* armor;
    short weapon_num;
    unsigned char gap_10A[2];
    RGE_Armor_Weapon_Info* weapon;
    short defense_terrain_bonus;
    unsigned char gap_112[2];
    float weapon_range;
    float area_effect_range;
    unsigned char area_effect_level;
    unsigned char gap_11D[3];
    float speed_of_attack;
    short missile_id;
    short base_hit_chance;
    unsigned char break_off_combat;
    unsigned char gap_129[1];
    short fire_missile_at_frame;
    float weapon_offset_x;
    float weapon_offset_y;
    float weapon_offset_z;
    float minimum_weapon_range;
    short orig_armor;
    short orig_weapon;
    float orig_weapon_range;
    float orig_speed_of_attack;

    int setup(RGE_Master_Combat_Object* source);
};
#endif

int RGE_Master_Combat_Object::setup(RGE_Master_Combat_Object* source) {
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
