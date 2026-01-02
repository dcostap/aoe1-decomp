#pragma once
#include "../common.h"

class RGE_Animated_Object : public RGE_Static_Object {
public:
    float speed;                             // 0x88

    virtual float getSpeed();
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

float RGE_Animated_Object::getSpeed() {
    /* TODO: Stub */
//                              float __thiscall getSpeed(RGE_Animated_Object * this)
//              float             ST0:10         <RETURN>
//              RGE_Animated_O    ECX:4 (auto)   this
//                               ?getSpeed@RGE_Animated_Object@@UBEMXZ                        XREF[8]:     0056e514(*), 0056ed04(*),
//                               RGE_Animated_Object::getSpeed                                             0056f34c(*), 00570314(*),
//                                                                                                         005707e4(*), 00570a3c(*),
//                                                                                                         0057486c(*), 00574b14(*)
//                              ani_obj.h:45 (7)
//         00405f40     FLD        float ptr [ECX + this->speed]
//         00405f46     RET
//         00405f47     ??         90h
//         00405f48     NOP
//         00405f49     NOP
//         00405f4a     NOP
//         00405f4b     NOP
//         00405f4c     NOP
//         00405f4d     NOP
//         00405f4e     NOP
//         00405f4f     NOP
    return 0;
}

