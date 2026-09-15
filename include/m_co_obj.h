#ifndef AOE1_M_CO_OBJ_H
#define AOE1_M_CO_OBJ_H

#include "m_ac_obj.h"
#include <stddef.h>

class RGE_Game_World;
class RGE_Master_Combat_Object;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Sound;
class RGE_Sprite;
class RGE_Static_Object;
class TDrawArea;
class RGE_Color_Table;

struct RGE_Armor_Weapon_Info;
class RGE_Armor_Weapon_Info {
public:
    short type;
    short value;
};

typedef char rge_armor_weapon_info_size_check[
    (sizeof(RGE_Armor_Weapon_Info) == 0x04) ? 1 : -1];

// The combat master owns the fields after RGE_Master_Action_Object.
class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    RGE_Master_Combat_Object(RGE_Master_Combat_Object* other_object, int do_setup);
    RGE_Master_Combat_Object(int infile, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup);
    RGE_Master_Combat_Object(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id, int do_setup);

    virtual ~RGE_Master_Combat_Object();
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float amount, unsigned char flag);
    virtual void modify_delta(float amount, unsigned char flag);
    virtual void modify_percent(float amount, unsigned char flag);
    virtual void save(int outfile);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* owner, float x, float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object* attacker);

protected:
    int setup(RGE_Master_Combat_Object* other_object);
    int setup(int infile, RGE_Sprite** sprites, RGE_Sound** sounds);
    int setup(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id);

public:
    RGE_Sprite* fight_sprite;
    unsigned char base_armor;
    short armor_num;
    RGE_Armor_Weapon_Info* armor;
    short weapon_num;
    RGE_Armor_Weapon_Info* weapon;
    short defense_terrain_bonus;
    float weapon_range;
    float area_effect_range;
    unsigned char area_effect_level;
    float speed_of_attack;
    short missile_id;
    short base_hit_chance;
    unsigned char break_off_combat;
    short fire_missile_at_frame;
    float weapon_offset_x;
    float weapon_offset_y;
    float weapon_offset_z;
    float minimum_weapon_range;
    short orig_armor;
    short orig_weapon;
    float orig_weapon_range;
    float orig_speed_of_attack;
};

typedef char m_co_obj_combat_size_check[
    (sizeof(RGE_Master_Combat_Object) == 0x148) ? 1 : -1];
typedef char m_co_obj_fight_sprite_offset_check[
    (offsetof(RGE_Master_Combat_Object, fight_sprite) == 0xFC) ? 1 : -1];

#endif  // AOE1_M_CO_OBJ_H
