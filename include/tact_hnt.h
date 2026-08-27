#ifndef AOE1_TACT_HNT_H
#define AOE1_TACT_HNT_H

// Declarations used only by the tact_hnt.cpp source module.
#include "action.h"
#include "act_list.h"
#include "act_obj.h"
#include "stat_obj.h"
#include "m_s_obj.h"
#include "m_ac_obj.h"
#include "move_obj.h"
#include "world.h"
#include "player.h"
#include "task.h"
#include "sound_context.h"
#include "basegame.h"
#include "rge_base_game_global.h"

// These dependent owner headers are not published yet.  Keep only the
// constructor and field declarations required by this source module.
class RGE_Action_Move_To : public RGE_Action {
public:
    RGE_Action_Move_To(RGE_Action_Object*, RGE_Static_Object*, float,
                       RGE_Sprite*);
    RGE_Action_Move_To(RGE_Action_Object*, float, float, float, float,
                       RGE_Sprite*);

    float range;
};

typedef char tact_hnt_move_to_size[
    (sizeof(RGE_Action_Move_To) == 0x44) ? 1 : -1];

class RGE_Action_Attack : public RGE_Action {
public:
    RGE_Action_Attack(RGE_Action_Object*, RGE_Static_Object*, RGE_Sprite*,
                      RGE_Sprite*, RGE_Sprite*, float, float, short, short);

    RGE_Sprite* move_sprite;
    RGE_Sprite* fight_sprite;
    RGE_Sprite* wait_sprite;
    float range;
    float min_range;
    short missile_id;
    short fire_missile_at_frame;
    unsigned char need_to_attack;
    unsigned char was_same_owner;
    unsigned char indirect_fire_flag;
    unsigned char _pad_5B;
};

typedef char tact_hnt_attack_size[
    (sizeof(RGE_Action_Attack) == 0x5C) ? 1 : -1];

// obj_list.h includes obsolete static and action-object bases.  Keep only the
// object-list method used by this module until that owner has a clean header.
class RGE_Object_List {
public:
    RGE_Static_Object* find_by_master_ids(long, long, float, float,
                                          unsigned char, unsigned char,
                                          RGE_Static_Object*);
};

// No canonical combat-master owner header is published yet.  This declaration
// keeps the proven fields used by the state-12 attack construction.
class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    RGE_Sprite* fight_sprite;
    unsigned char base_armor;
    unsigned char _pad_101;
    short armor_num;
    RGE_Armor_Weapon_Info* armor;
    short weapon_num;
    unsigned char _pad_10A[2];
    RGE_Armor_Weapon_Info* weapon;
    short defense_terrain_bonus;
    unsigned char _pad_112[2];
    float weapon_range;
    float area_effect_range;
    unsigned char area_effect_level;
    unsigned char _pad_11D[3];
    float speed_of_attack;
    short missile_id;
    short base_hit_chance;
    unsigned char break_off_combat;
    unsigned char _pad_129;
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

typedef char tact_hnt_combat_master_size[
    (sizeof(RGE_Master_Combat_Object) == 0x148) ? 1 : -1];

class TRIBE_Action_Hunt : public RGE_Action {
public:
    TRIBE_Action_Hunt(int, RGE_Action_Object*);
    TRIBE_Action_Hunt(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Hunt(RGE_Action_Object*, RGE_Task*, float, float, float);
    virtual void save(int);
    virtual void first_in_stack(unsigned char);
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);

protected:
    virtual void set_state(unsigned char);
    int targetType;

    RGE_Sprite* get_move_sprite();
    RGE_Sprite* get_wait_sprite();
};

typedef char tact_hnt_hunt_abi[
    (sizeof(TRIBE_Action_Hunt) == 0x44) ? 1 : -1];

extern float DAT_00575150;
extern double DAT_00575168;

#endif
