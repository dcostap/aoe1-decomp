#pragma once
#include "../common.h"
#include "act_obj.h"

class RGE_Combat_Object : public RGE_Action_Object {
public:
    VISIBLE_UNIT_REC* VUR_Ptrs[9];           // 0x194
    ulong Unified_Map_Value;                 // 0x1B8
    float attack_timer;                      // 0x1BC
    uchar capture_flag;                      // 0x1C0

    RGE_Combat_Object(RGE_Master_Combat_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6);
    RGE_Combat_Object(int param_1, RGE_Game_World* param_2, int param_3);
    virtual ~RGE_Combat_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5);
    virtual int setup(RGE_Master_Combat_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5);
    virtual int setup(int param_1, RGE_Game_World* param_2);
    virtual void save(int param_1);
    virtual void stop();
    virtual float calc_attack_modifier(RGE_Static_Object* param_1);
    virtual uchar area_attack(float param_1, float param_2, float param_3, RGE_Combat_Object* param_4, RGE_Static_Object* param_5);
    virtual uchar attack(RGE_Static_Object* param_1, RGE_Combat_Object* param_2);
    virtual uchar attack(float param_1, float param_2, float param_3, RGE_Combat_Object* param_4);
    virtual uchar do_attack(RGE_Static_Object* param_1, RGE_Combat_Object* param_2, float param_3, float param_4, float param_5);
    virtual void damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5);
    virtual float calculateDamage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5);
    virtual uchar can_attack();
    virtual void reset_attack_timer();
    virtual void get_armor(short* param_1, short* param_2);
    virtual void get_weapon(short* param_1, short* param_2);
    virtual void get_weapon_range(float* param_1, float* param_2);
    virtual void get_speed_of_attack(float* param_1, float* param_2);
    virtual void release_being_worked_on(RGE_Static_Object* param_1);
    virtual void enter_obj(RGE_Static_Object* param_1);
    virtual uchar update();
    virtual void copy_obj(RGE_Master_Static_Object* param_1);
    virtual void notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6);
    virtual int attack(int param_1, int param_2);
    virtual int attack(float param_1, float param_2, float param_3, int param_4);
    virtual int moveTo(int param_1, int param_2);
    virtual int moveTo(int param_1, float param_2, int param_3);
    virtual int moveTo(float param_1, float param_2, float param_3, float param_4, int param_5);
    virtual int moveAwayFrom(int param_1, int param_2);
    virtual int gather(int param_1, int param_2);
    virtual int explore(int param_1, int param_2, int param_3);
    virtual int enter(int param_1, int param_2);
    virtual int transport(float param_1, float param_2, float param_3, int param_4);
    virtual int unload(int param_1, float param_2, float param_3, float param_4);
    virtual int stopAction();
    virtual int pause();
    virtual float rateOfFire();
    virtual float damageCapability();
    virtual float damageCapability(RGE_Static_Object* param_1);
    virtual int inAttackRange(RGE_Static_Object* param_1);
    virtual float weaponRange();
    virtual float minimumWeaponRange();
    virtual int currentTargetID();
    virtual float currentTargetX();
    virtual float currentTargetY();
    virtual float currentTargetZ();
    virtual float teleport(float param_1, float param_2, float param_3);
};

static_assert(sizeof(RGE_Combat_Object) == 0x1C4, "RGE_Combat_Object Size Mismatch");
static_assert(offsetof(RGE_Combat_Object, capture_flag) == 0x1C0, "RGE_Combat_Object Offset Mismatch");

