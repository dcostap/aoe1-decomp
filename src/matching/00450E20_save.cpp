// VA: 00450E20 RGE_Master_Combat_Object::save (479B)
// m_co_obj.cpp
//
// Attempt log:
// - The same-TU combat layout plus a typed RGE_Sprite::id field recovered the
//   packed sprite-id save without raw offset plumbing.
// - Keeping the natural short temporary after the base save lets VC5 reuse
//   the dead file-parameter home for the later rge_write call.
// - Exact under the default /O2 /Oy flags; no custom flags or compiler-only
//   scaffolding retained.

class RGE_Sprite {
public:
    char gap_00[0x72];
    short id;
};

class RGE_Armor_Weapon_Info {
public:
    short type;
    short value;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float value, unsigned char attribute);
    virtual void modify_delta(float value, unsigned char attribute);
    virtual void modify_percent(float value, unsigned char attribute);
    virtual void save(int file);
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

    virtual void save(int file);
};

extern "C" void rge_write(int file, void* buffer, int size);

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

    void save(int file);
};

void RGE_Master_Combat_Object::save(int file) {
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
