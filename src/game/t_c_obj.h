#pragma once
#include "../common.h"

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    uchar own_master;                        // 0x1C4

    TRIBE_Combat_Object(TRIBE_Master_Combat_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6);
    TRIBE_Combat_Object(int param_1, RGE_Game_World* param_2, int param_3);
    virtual ~TRIBE_Combat_Object();
    virtual int setup(TRIBE_Master_Combat_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5);
    virtual int setup(int param_1, RGE_Game_World* param_2);
    virtual RGE_Action_List* create_action_list();
    virtual void save(int param_1);
    virtual uchar update();
    virtual void modify(float param_1, uchar param_2);
    virtual void transform(RGE_Master_Static_Object* param_1);
    virtual void set_object_state(uchar param_1);
    virtual void cancel_object();
    virtual void die_die_die();
    virtual void damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5);
    virtual void change_ownership(RGE_Player* param_1);
    virtual float calc_attack_modifier(RGE_Static_Object* param_1);
    virtual uchar attack(RGE_Static_Object* param_1, RGE_Combat_Object* param_2);
    virtual uchar do_attack(RGE_Static_Object* param_1, RGE_Combat_Object* param_2, float param_3, float param_4, float param_5);
    virtual void get_armor(short* param_1, short* param_2);
    virtual void get_pierce_armor(short* param_1, short* param_2);
    virtual void reposition_artifact();
    virtual int can_debark();
    virtual int hunt(int param_1, int param_2);
    virtual int convert(int param_1, int param_2);
    virtual int heal(int param_1, int param_2);
    virtual int repair(int param_1, int param_2);
    virtual int build(int param_1, int param_2);
    virtual int trade(int param_1, int param_2);
    virtual uchar keepGatheringWhenObjectIsOut(int param_1);
    virtual uchar produceWhenKilledBy(int param_1);
    virtual uchar useSameZoneDropsite();
    virtual void initUnitAI();
    virtual int higher_check_for_cliff(RGE_Static_Object* param_1, int param_2, int param_3, float param_4, float param_5, float param_6, float param_7, RGE_Map* param_8, RGE_Static_Object* param_9, float* param_10, int* param_11);
    virtual int higher_than_target(RGE_Static_Object* param_1);
    virtual uchar area_attack(float param_1, float param_2, float param_3, RGE_Combat_Object* param_4, RGE_Static_Object* param_5);
    virtual uchar heal(float param_1);
    virtual int canRepair();
    virtual void do_repair(RGE_Static_Object* param_1);
};

static_assert(sizeof(TRIBE_Combat_Object) == 0x1C8, "TRIBE_Combat_Object Size Mismatch");
static_assert(offsetof(TRIBE_Combat_Object, own_master) == 0x1C4, "TRIBE_Combat_Object Offset Mismatch");

