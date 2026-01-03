#pragma once
#include "../common.h"
#include "stat_obj.h"
#include "player.h"
#include "m_an_obj.h"

class RGE_Animated_Object : public RGE_Static_Object {
public:
    float speed;                             // 0x88

    virtual float getSpeed() const { return this->speed; }
    RGE_Animated_Object(RGE_Master_Animated_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6);
    virtual ~RGE_Animated_Object();
    RGE_Animated_Object(int param_1, RGE_Game_World* param_2, int param_3);
    virtual void recycle_in_to_game(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5);
    virtual int setup(RGE_Master_Animated_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5);
    virtual int setup(int param_1, RGE_Game_World* param_2);
    virtual uchar update();
    virtual void save(int param_1);
    virtual void transform(RGE_Master_Static_Object* param_1);
    virtual void set_being_worked_on(RGE_Action_Object* param_1, short param_2, uchar param_3);
    virtual void release_being_worked_on(RGE_Static_Object* param_1);
};

static_assert(sizeof(RGE_Animated_Object) == 0x8C, "RGE_Animated_Object Size Mismatch");
static_assert(offsetof(RGE_Animated_Object, speed) == 0x88, "RGE_Animated_Object Offset Mismatch");


