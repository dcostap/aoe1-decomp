#pragma once
#include "common.h"

class TRIBE_Master_Tree_Object : public RGE_Master_Static_Object {
public:

    virtual RGE_Static_Object* make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4); // vt0[6]+0x18=0x50F320
    virtual RGE_Master_Static_Object* make_new_master();    // vt0[7]+0x1C=0x50F3A0
    TRIBE_Master_Tree_Object(TRIBE_Master_Tree_Object* param_1, int param_2);
    ~TRIBE_Master_Tree_Object();
    TRIBE_Master_Tree_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
    TRIBE_Master_Tree_Object(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5);
};

static_assert(sizeof(TRIBE_Master_Tree_Object) == 0xB8, "TRIBE_Master_Tree_Object Size Mismatch");

