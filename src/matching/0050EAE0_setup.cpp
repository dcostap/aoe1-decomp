// VA: 0050EAE0 TRIBE_Master_Combat_Object::setup
// PDB source: tm_co_ob.cpp lines 51-69
// BINARY NOTE: The PDB owner is protected setup(TRIBE_Master_Combat_Object*).
// Its body is [0050EAE0,0050EB60), and its base call is 0044FFB0.

#ifndef TM_CO_OB_SHARED_CONTEXT
class RGE_Sprite;
class RGE_Sound;
class RGE_Master_Static_Object;

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

protected:
    int setup(RGE_Master_Action_Object* source);
};

class RGE_Armor_Weapon_Info {
public:
    short type;
    short value;
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

protected:
    int setup(RGE_Master_Combat_Object* source);
};

class Attribute_Cost {
public:
    short type;
    short amount;
    unsigned char flag;
    unsigned char gap_005;
};

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object {
public:
    Attribute_Cost build_inventory[3];
    short build_pts_required;
    short id_of_building_obj;
    unsigned char button_location;
    unsigned char gap_15F;
    short orig_pierce_armor;
    unsigned char gap_162[2];

protected:
    int setup(TRIBE_Master_Combat_Object* src);
};
#endif

int TRIBE_Master_Combat_Object::setup(TRIBE_Master_Combat_Object* src)
{
    RGE_Master_Combat_Object::setup(src);
    master_type = 0x46;
    
    int i;
    for (i = 0; i < 3; i++)
        build_inventory[i] = src->build_inventory[i];
    
    build_pts_required = src->build_pts_required;
    id_of_building_obj = src->id_of_building_obj;
    button_location = src->button_location;
    orig_pierce_armor = src->orig_pierce_armor;
    
    return 1;
}
