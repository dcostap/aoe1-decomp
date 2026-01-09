#pragma once
#include "common.h"

class RGE_Animated_Object : public RGE_Static_Object {
public:
    float speed;                             // 0x88

    virtual void recycle_in_to_game(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5); // vt0[1]+0x4=0x41A280
    virtual uchar update();                                 // vt0[9]+0x24=0x41A350
    virtual void save(int param_1);                         // vt0[12]+0x30=0x41A3D0
    virtual void transform(RGE_Master_Static_Object* param_1); // vt0[21]+0x54=0x41A400
    virtual void set_being_worked_on(RGE_Action_Object* param_1, short param_2, uchar param_3); // vt0[48]+0xC0=0x41A410
    virtual void release_being_worked_on(RGE_Static_Object* param_1); // vt0[49]+0xC4=0x41A430
    virtual float getSpeed();                               // vt0[61]+0xF4=0x405F40
    virtual int setup(int param_1, RGE_Game_World* param_2); // vt0[118]+0x1D8=0x41A310
    virtual int setup(RGE_Master_Animated_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5); // vt0[122]+0x1E8=0x41A2C0
    RGE_Animated_Object(RGE_Master_Animated_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6);
    ~RGE_Animated_Object();
    RGE_Animated_Object(int param_1, RGE_Game_World* param_2, int param_3);
};

static_assert(sizeof(RGE_Animated_Object) == 0x8C, "RGE_Animated_Object Size Mismatch");

