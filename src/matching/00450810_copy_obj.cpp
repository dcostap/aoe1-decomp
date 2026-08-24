// VA: 00450810 RGE_Master_Combat_Object::copy_obj (481B)
// m_co_obj.cpp
//
// Attempt log:
// - Reconstructed the real static/action/combat inheritance and cast the
//   base-typed source to the owning combat view before named field access.
// - Natural free-then-positive-count calloc/memcpy replacement of the two
//   owned record arrays reproduces the original lifetime and copy order.
// - Exact under the default /O2 /Oy flags; no custom flags or compiler-only
//   scaffolding retained.

#ifndef RGE_MCO_OBJ_SHARED_CONTEXT
#include <stdlib.h>
#include <string.h>

class RGE_Sprite;

class RGE_Armor_Weapon_Info {
public:
    short type;
    short value;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* source);
    char gap_004[0xB4];
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    char gap_B8[0x04];
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    char gap_BC[0x1C];
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    char gap_D8[0x24];

    virtual void copy_obj(RGE_Master_Static_Object* source);
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

    void copy_obj(RGE_Master_Static_Object* source);
};
#endif

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
