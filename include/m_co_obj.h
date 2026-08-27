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

// The combat master owns the fields after RGE_Master_Action_Object.
class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    RGE_Master_Combat_Object(RGE_Master_Combat_Object*, int);
    RGE_Master_Combat_Object(int, RGE_Sprite**, RGE_Sound**, int);
    RGE_Master_Combat_Object(FILE*, RGE_Sprite**, RGE_Sound**, short, int);

    virtual ~RGE_Master_Combat_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual unsigned char check_placement(RGE_Player*, float, float, int*,
                                          unsigned char, unsigned char,
                                          unsigned char, unsigned char,
                                          unsigned char, unsigned char);
    virtual unsigned char alignment(float*, float*, RGE_Game_World*,
                                   unsigned char);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*, long, long,
                      int, unsigned char);
    virtual RGE_Task_List* create_task_list();

protected:
    int setup(RGE_Master_Combat_Object*);
    int setup(int, RGE_Sprite**, RGE_Sound**);
    int setup(FILE*, RGE_Sprite**, RGE_Sound**, short);

public:
    RGE_Sprite* fight_sprite;
    unsigned char base_armor;
    short armor_num;
    RGE_Armor_Weapon_Info* armor;
    short weapon_num;
    RGE_Armor_Weapon_Info* weapon;
    short defense_terrain_bonus;
    // PDB and tact_rep prove a float at +0x114.
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
