#pragma once
#include "common.h"

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    uchar own_master;                        // 0x1C4

    virtual uchar update();                                 // vt0[9]+0x24=0x4CA5F0
    virtual void save(int param_1);                         // vt0[12]+0x30=0x4CA570
    virtual void change_ownership(RGE_Player* param_1);     // vt0[17]+0x44=0x4CA8C0
    virtual void modify(float param_1, uchar param_2);      // vt0[18]+0x48=0x4CA640
    virtual void transform(RGE_Master_Static_Object* param_1); // vt0[21]+0x54=0x4CA700
    virtual void set_object_state(uchar param_1);           // vt0[23]+0x5C=0x4CA740
    virtual void die_die_die();                             // vt0[27]+0x6C=0x4CA790
    virtual void damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5); // vt0[28]+0x70=0x4CA7F0
    virtual int heal(int param_1, int param_2);             // vt0[34]+0x88=0x4CB300
    virtual uchar heal(float param_1);                      // vt0[35]+0x8C=0x4CC4C0
    virtual int canRepair();                                // vt0[36]+0x90=0x4CC570
    virtual float calc_attack_modifier(RGE_Static_Object* param_1); // vt0[60]+0xF0=0x4CAA00
    virtual uchar keepGatheringWhenObjectIsOut(int param_1); // vt0[78]+0x138=0x4CB860
    virtual uchar produceWhenKilledBy(int param_1);         // vt0[79]+0x13C=0x4CB880
    virtual uchar useSameZoneDropsite();                    // vt0[80]+0x140=0x4CB8B0
    virtual int hunt(int param_1, int param_2);             // vt0[89]+0x164=0x4CB060
    virtual int convert(int param_1, int param_2);          // vt0[91]+0x16C=0x4CB1B0
    virtual int repair(int param_1, int param_2);           // vt0[92]+0x170=0x4CB450
    virtual int build(int param_1, int param_2);            // vt0[93]+0x174=0x4CB5C0
    virtual int trade(int param_1, int param_2);            // vt0[94]+0x178=0x4CB710
    virtual int setup(int param_1, RGE_Game_World* param_2); // vt0[118]+0x1D8=0x4CA3E0
    virtual RGE_Action_List* create_action_list();          // vt0[134]+0x218=0x4CA510
    virtual uchar area_attack(float param_1, float param_2, float param_3, RGE_Combat_Object* param_4, RGE_Static_Object* param_5); // vt0[135]+0x21C=0x4CC1B0
    virtual uchar attack(RGE_Static_Object* param_1, RGE_Combat_Object* param_2); // vt0[137]+0x224=0x4CAA50
    virtual uchar do_attack(RGE_Static_Object* param_1, RGE_Combat_Object* param_2, float param_3, float param_4, float param_5); // vt0[138]+0x228=0x4CAAA0
    virtual void get_armor(short* param_1, short* param_2); // vt0[139]+0x22C=0x4CAC10
    virtual void cancel_object();                           // vt0[144]+0x240=0x4CA780
    virtual void get_pierce_armor(short* param_1, short* param_2); // vt0[145]+0x244=0x4CAC80
    virtual int higher_check_for_cliff(RGE_Static_Object* param_1, int param_2, int param_3, float param_4, float param_5, float param_6, float param_7, RGE_Map* param_8, RGE_Static_Object* param_9, float* param_10, int* param_11); // vt0[146]+0x248=0x4CBD40
    virtual int higher_than_target(RGE_Static_Object* param_1); // vt0[147]+0x24C=0x4CBEF0
    virtual void initUnitAI();                              // vt0[148]+0x250=0x4CB8D0
    virtual int setup(TRIBE_Master_Combat_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5); // vt0[149]+0x254=0x4CA300
    TRIBE_Combat_Object(TRIBE_Master_Combat_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6);
    TRIBE_Combat_Object(int param_1, RGE_Game_World* param_2, int param_3);
    ~TRIBE_Combat_Object();
    void reposition_artifact();
    int can_debark();
    void do_repair(RGE_Static_Object* param_1);
};

static_assert(sizeof(TRIBE_Combat_Object) == 0x1C8, "TRIBE_Combat_Object Size Mismatch");

