#pragma once
#include "common.h"

class RGE_Missile_Object : public RGE_Combat_Object {
public:
    float max_range;                         // 0x1C4

    virtual uchar update();                                 // vt0[9]+0x24=0x45A940
    virtual void rehook();                                  // vt0[11]+0x2C=0x45A900
    virtual void save(int param_1);                         // vt0[12]+0x30=0x45A910
    virtual int setup(int param_1, RGE_Game_World* param_2); // vt0[118]+0x1D8=0x45A8A0
    virtual int setup(RGE_Master_Combat_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5); // vt0[143]+0x23C=0x45A870
    RGE_Missile_Object(RGE_Master_Combat_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6);
    ~RGE_Missile_Object();
    RGE_Missile_Object(int param_1, RGE_Game_World* param_2, int param_3);
    void init_missile(RGE_Combat_Object* param_1, RGE_Static_Object* param_2, float param_3);
    void init_missile(RGE_Combat_Object* param_1, float param_2, float param_3, float param_4, float param_5);
    uchar missile_move();
    RGE_Check_List* make_object_collision_list(float param_1);
};

static_assert(sizeof(RGE_Missile_Object) == 0x1C8, "RGE_Missile_Object Size Mismatch");

