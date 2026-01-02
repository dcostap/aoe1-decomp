#pragma once
#include "../common.h"

class RGE_Missile_Object : public RGE_Combat_Object {
public:
    float max_range;                         // 0x1C4

    RGE_Missile_Object(RGE_Master_Combat_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6);
    virtual ~RGE_Missile_Object();
    RGE_Missile_Object(int param_1, RGE_Game_World* param_2, int param_3);
    virtual int setup(RGE_Master_Combat_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5);
    virtual int setup(int param_1, RGE_Game_World* param_2);
    virtual void rehook();
    virtual void save(int param_1);
    virtual uchar update();
    virtual void init_missile(RGE_Combat_Object* param_1, RGE_Static_Object* param_2, float param_3);
    virtual void init_missile(RGE_Combat_Object* param_1, float param_2, float param_3, float param_4, float param_5);
    virtual uchar missile_move();
    virtual RGE_Check_List* make_object_collision_list(float param_1);
};

static_assert(sizeof(RGE_Missile_Object) == 0x1C8, "RGE_Missile_Object Size Mismatch");
static_assert(offsetof(RGE_Missile_Object, max_range) == 0x1C4, "RGE_Missile_Object Offset Mismatch");

