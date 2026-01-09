#pragma once
#include "common.h"

class RGE_Master_Doppleganger_Object : public RGE_Master_Animated_Object {
public:

    virtual void copy_obj(RGE_Master_Static_Object* param_1); // vt0[1]+0x4=0x451420
    virtual void save(int param_1);                         // vt0[5]+0x14=0x451430
    virtual RGE_Master_Static_Object* make_new_master();    // vt0[7]+0x1C=0x4513B0
    virtual RGE_Static_Object* make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4, RGE_Static_Object* param_5); // vt0[14]+0x38=0x4512D0
    RGE_Master_Doppleganger_Object(RGE_Master_Doppleganger_Object* param_1, int param_2);
    RGE_Master_Doppleganger_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
    RGE_Master_Doppleganger_Object(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5);
    int setup(RGE_Master_Doppleganger_Object* param_1);
    int setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
    int setup(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4);
    ~RGE_Master_Doppleganger_Object();
};

static_assert(sizeof(RGE_Master_Doppleganger_Object) == 0xBC, "RGE_Master_Doppleganger_Object Size Mismatch");

