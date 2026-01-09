#pragma once
#include "common.h"

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;                             // 0xB8

    virtual void copy_obj(RGE_Master_Static_Object* param_1); // vt0[1]+0x4=0x44FD40
    virtual void modify(float param_1, uchar param_2);      // vt0[2]+0x8=0x44FD60
    virtual void modify_delta(float param_1, uchar param_2); // vt0[3]+0xC=0x44FD90
    virtual void modify_percent(float param_1, uchar param_2); // vt0[4]+0x10=0x44FDC0
    virtual void save(int param_1);                         // vt0[5]+0x14=0x44FDF0
    virtual RGE_Static_Object* make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4); // vt0[6]+0x18=0x44FC00
    virtual RGE_Master_Static_Object* make_new_master();    // vt0[7]+0x1C=0x44FCD0
    RGE_Master_Animated_Object(RGE_Master_Animated_Object* param_1, int param_2);
    RGE_Master_Animated_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
    RGE_Master_Animated_Object(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5);
    int setup(RGE_Master_Animated_Object* param_1);
    int setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
    int setup(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4);
    ~RGE_Master_Animated_Object();
};

static_assert(sizeof(RGE_Master_Animated_Object) == 0xBC, "RGE_Master_Animated_Object Size Mismatch");

