#pragma once
#include "../common.h"

class TRIBE_Master_Tree_Object : public RGE_Master_Static_Object {
public:

    TRIBE_Master_Tree_Object(TRIBE_Master_Tree_Object* param_1, int param_2);
    virtual ~TRIBE_Master_Tree_Object();
    TRIBE_Master_Tree_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
    TRIBE_Master_Tree_Object(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4);
    virtual RGE_Master_Static_Object* make_new_master();
};

static_assert(sizeof(TRIBE_Master_Tree_Object) == 0xB8, "TRIBE_Master_Tree_Object Size Mismatch");

