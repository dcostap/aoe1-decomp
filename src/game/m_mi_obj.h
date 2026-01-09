#pragma once
#include "common.h"

class RGE_Master_Missile_Object : public RGE_Master_Combat_Object {
public:
    uchar missile_type;                      // 0x148
    uchar targetting_type;                   // 0x149
    uchar missile_hit_info;                  // 0x14A
    uchar missile_die_info;                  // 0x14B
    uchar area_effect_specials;              // 0x14C
    float ballistics_ratio;                  // 0x150

    virtual void copy_obj(RGE_Master_Static_Object* param_1); // vt0[1]+0x4=0x4518B0
    virtual void modify(float param_1, uchar param_2);      // vt0[2]+0x8=0x451910
    virtual void modify_delta(float param_1, uchar param_2); // vt0[3]+0xC=0x451940
    virtual void modify_percent(float param_1, uchar param_2); // vt0[4]+0x10=0x451970
    virtual void save(int param_1);                         // vt0[5]+0x14=0x4519A0
    virtual RGE_Static_Object* make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4); // vt0[6]+0x18=0x451770
    virtual RGE_Master_Static_Object* make_new_master();    // vt0[7]+0x1C=0x451840
    RGE_Master_Missile_Object(RGE_Master_Missile_Object* param_1, int param_2);
    RGE_Master_Missile_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
    RGE_Master_Missile_Object(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5);
    int setup(RGE_Master_Missile_Object* param_1);
    int setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
    int setup(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4);
    ~RGE_Master_Missile_Object();
};

static_assert(sizeof(RGE_Master_Missile_Object) == 0x154, "RGE_Master_Missile_Object Size Mismatch");

