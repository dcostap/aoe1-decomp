// VA: 0050EB60 TRIBE_Master_Combat_Object::setup (file-read via rge_read)
// PDB source: tm_co_ob.cpp
// Attempt log:
// - Initial scaffold had 256/293 bytes: it omitted the version-gated armor read.
// - Added the binary-proven save_game_version >= DAT_0057677c gate and direct read.
// - Guarded do-loops removed duplicate count tests and reached exact size/CFG (14-byte register drift).
// - Current reconstruction mirrors same-TU typed armor ownership and donor local lifetimes.
// - Main-agent audit confirmed canonical combat-object and armor ownership;
//   emitted code remains exact.

#include <stdlib.h>

extern "C" {
    void rge_read(int fd, void* buf, int size);
}

extern float save_game_version;
extern float DAT_0057677c;

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

    int setup(int fd, RGE_Sprite** sprites, RGE_Sound** sounds);
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

    int setup(int fd, RGE_Sprite** sprites, RGE_Sound** sounds);
};

int TRIBE_Master_Combat_Object::setup(int fd, RGE_Sprite** sprites,
                                      RGE_Sound** sounds)
{
    int armor_count;
    int left;

    RGE_Master_Combat_Object::setup(fd, sprites, sounds);
    master_type = 0x46;

    Attribute_Cost* cost = build_inventory;
    int remaining = 3;
    do {
        rge_read(fd, cost, 6);
        cost++;
        remaining--;
    } while (remaining != 0);

    rge_read(fd, &build_pts_required, 2);
    rge_read(fd, &id_of_building_obj, 2);
    rge_read(fd, &button_location, 1);

    if (save_game_version >= DAT_0057677c) {
        rge_read(fd, &orig_pierce_armor, 2);
        return 1;
    }

    armor_count = (int)armor_num;
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
