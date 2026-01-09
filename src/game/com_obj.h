#pragma once
#include "common.h"

class RGE_Combat_Object : public RGE_Action_Object {
public:
    VISIBLE_UNIT_REC* VUR_Ptrs[9];           // 0x194
    ulong Unified_Map_Value;                 // 0x1B8
    float attack_timer;                      // 0x1BC
    uchar capture_flag;                      // 0x1C0

    virtual void recycle_in_to_game(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5); // vt0[1]+0x4=0x42FAF0
    virtual uchar update();                                 // vt0[9]+0x24=0x430680
    virtual void save(int param_1);                         // vt0[12]+0x30=0x42FC10
    virtual float teleport(float param_1, float param_2, float param_3); // vt0[13]+0x34=0x4316A0
    virtual void copy_obj(RGE_Master_Static_Object* param_1); // vt0[22]+0x58=0x430810
    virtual void damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5); // vt0[28]+0x70=0x430320
    virtual float calculateDamage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5); // vt0[29]+0x74=0x4303A0
    virtual uchar can_attack();                             // vt0[31]+0x7C=0x430480
    virtual void stop();                                    // vt0[41]+0xA4=0x42FC50
    virtual void release_being_worked_on(RGE_Static_Object* param_1); // vt0[49]+0xC4=0x4305D0
    virtual void enter_obj(RGE_Static_Object* param_1);     // vt0[52]+0xD0=0x430610
    virtual int inAttackRange(RGE_Static_Object* param_1);  // vt0[57]+0xE4=0x431530
    virtual float calc_attack_modifier(RGE_Static_Object* param_1); // vt0[60]+0xF0=0x42FC90
    virtual float rateOfFire();                             // vt0[64]+0x100=0x431490
    virtual float damageCapability(RGE_Static_Object* param_1); // vt0[65]+0x104=0x4314F0
    virtual float damageCapability();                       // vt0[66]+0x108=0x4314A0
    virtual float weaponRange();                            // vt0[67]+0x10C=0x4315A0
    virtual float minimumWeaponRange();                     // vt0[68]+0x110=0x4315B0
    virtual int currentTargetID();                          // vt0[71]+0x11C=0x4315C0
    virtual float currentTargetX();                         // vt0[72]+0x120=0x431610
    virtual float currentTargetY();                         // vt0[73]+0x124=0x431640
    virtual float currentTargetZ();                         // vt0[74]+0x128=0x431670
    virtual void notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6); // vt0[82]+0x148=0x430850
    virtual int attack(float param_1, float param_2, float param_3, int param_4); // vt0[83]+0x14C=0x430A90
    virtual int attack(int param_1, int param_2);           // vt0[84]+0x150=0x4308C0
    virtual int moveTo(float param_1, float param_2, float param_3, float param_4, int param_5); // vt0[85]+0x154=0x430D50
    virtual int moveTo(int param_1, float param_2, int param_3); // vt0[86]+0x158=0x430C30
    virtual int moveTo(int param_1, int param_2);           // vt0[87]+0x15C=0x430C10
    virtual int moveAwayFrom(int param_1, int param_2);     // vt0[88]+0x160=0x430EC0
    virtual int gather(int param_1, int param_2);           // vt0[90]+0x168=0x430ED0
    virtual int explore(int param_1, int param_2, int param_3); // vt0[95]+0x17C=0x431020
    virtual int enter(int param_1, int param_2);            // vt0[96]+0x180=0x431150
    virtual int unload(int param_1, float param_2, float param_3, float param_4); // vt0[97]+0x184=0x431340
    virtual int transport(float param_1, float param_2, float param_3, int param_4); // vt0[98]+0x188=0x431250
    virtual int stopAction();                               // vt0[99]+0x18C=0x431440
    virtual int pause();                                    // vt0[100]+0x190=0x431470
    virtual int setup(int param_1, RGE_Game_World* param_2); // vt0[118]+0x1D8=0x42FBA0
    virtual uchar area_attack(float param_1, float param_2, float param_3, RGE_Combat_Object* param_4, RGE_Static_Object* param_5); // vt0[135]+0x21C=0x42FCA0
    virtual uchar attack(float param_1, float param_2, float param_3, RGE_Combat_Object* param_4); // vt0[136]+0x220=0x4300F0
    virtual uchar attack(RGE_Static_Object* param_1, RGE_Combat_Object* param_2); // vt0[137]+0x224=0x42FF50
    virtual uchar do_attack(RGE_Static_Object* param_1, RGE_Combat_Object* param_2, float param_3, float param_4, float param_5); // vt0[138]+0x228=0x430230
    virtual void get_armor(short* param_1, short* param_2); // vt0[139]+0x22C=0x4304B0
    virtual void get_weapon(short* param_1, short* param_2); // vt0[140]+0x230=0x430510
    virtual void get_weapon_range(float* param_1, float* param_2); // vt0[141]+0x234=0x430570
    virtual void get_speed_of_attack(float* param_1, float* param_2); // vt0[142]+0x238=0x4305A0
    virtual int setup(RGE_Master_Combat_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5); // vt0[143]+0x23C=0x42FB40
    RGE_Combat_Object(RGE_Master_Combat_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6);
    RGE_Combat_Object(int param_1, RGE_Game_World* param_2, int param_3);
    ~RGE_Combat_Object();
    void reset_attack_timer();
};

static_assert(sizeof(RGE_Combat_Object) == 0x1C4, "RGE_Combat_Object Size Mismatch");

