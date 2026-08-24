// VA: 0050EC90 TRIBE_Master_Combat_Object::setup (file-read setup)
// PDB source: tm_co_ob.cpp, lines 111-148
// Attempt log:
// - old source: 160/257 bytes; omitted the armor-record scans and used field
//   destinations for fscanf values that the original keeps in parameter homes.
// - baseline: canonical Attribute_Cost/RGE_Armor_Weapon_Info ownership, the
//   two max scans, and the source-proven %hd parameter-home destinations.
// - comparison polarity: spelling value > current maximum aligned both word
//   compares; the initial do/do form still colored the persistent count in ESI.
// - variant lab: keeping the first scan as a do-loop but expressing the second
//   scan as a while/for loop produces the original EDX/ESI counter coloring.
// - exact: the natural second while-loop, typed armor records, and parameter
//   home destinations reproduce all 257 bytes under default /O2 /Oy.
// Main-agent audit restored the donor-backed polymorphic base and named
// master_type field at +0x04; emitted code remains exact.

#include <stdio.h>

#ifndef TM_CO_OB_SHARED_CONTEXT
class RGE_Sprite;
class RGE_Sound;

class RGE_Armor_Weapon_Info {
public:
    short type;
    short value;
};

class RGE_Master_Combat_Object {
public:
    virtual ~RGE_Master_Combat_Object();
    unsigned char master_type;
    char gap_005[0xFB];
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

    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short count);
};

class Attribute_Cost {
public:
    short type;
    short amount;
    unsigned char flag;
    unsigned char gap_005[1];
};

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object {
public:
    Attribute_Cost build_inventory[3];
    short build_pts_required;
    short id_of_building_obj;
    unsigned char button_location;
    unsigned char gap_15F[1];
    short orig_pierce_armor;
    unsigned char gap_162[2];

    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short count);
};
#endif

int TRIBE_Master_Combat_Object::setup(FILE* file, RGE_Sprite** sprites,
                                      RGE_Sound** sounds, short count)
{
    int armor_count;
    int left;

    RGE_Master_Combat_Object::setup(file, sprites, sounds, count);
    this->master_type = 0x46;

    Attribute_Cost* cost = build_inventory;
    int remaining = 3;
    do {
        fscanf(file, "%hd %hd %hd", &cost->type, &cost->amount, &count);
        cost->flag = (unsigned char)count;
        cost++;
        remaining--;
    } while (remaining != 0);

    fscanf(file, "%hd %hd %hd", &build_pts_required, &id_of_building_obj,
           &sounds);

    armor_count = (int)armor_num;
    button_location = (unsigned char)sounds;
    orig_pierce_armor = 0;
    if (armor_count > 0) {
        RGE_Armor_Weapon_Info* entry = armor;
        left = armor_count;
        do {
            if (entry->type == 3 && entry->value > orig_pierce_armor)
                orig_pierce_armor = entry->value;
            entry++;
            left--;
        } while (left != 0);
    }

    orig_armor = (unsigned char)base_armor;
    if (armor_count > 0) {
        RGE_Armor_Weapon_Info* entry = armor;
        while (armor_count != 0) {
            if (entry->type != 3 && entry->value > orig_armor)
                orig_armor = entry->value;
            entry++;
            armor_count--;
        }
    }

    return 1;
}
