#pragma once
#include "../common.h"

class TRIBE_Tree_Object : public RGE_Static_Object {
public:

    TRIBE_Tree_Object(TRIBE_Master_Tree_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6);
    virtual ~TRIBE_Tree_Object();
    TRIBE_Tree_Object(int param_1, RGE_Game_World* param_2, int param_3);
    virtual void set_object_state(uchar param_1);
};

static_assert(sizeof(TRIBE_Tree_Object) == 0x88, "TRIBE_Tree_Object Size Mismatch");

