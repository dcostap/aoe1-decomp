// 004514C0 RGE_Master_Missile_Object::RGE_Master_Missile_Object
// Source: m_mi_obj.cpp lines 33-36
// public: __thiscall RGE_Master_Missile_Object::RGE_Master_Missile_Object(int,RGE_Sprite**,RGE_Sound**,int)
//
// Attempt log:
// Probe 1: natural ctor with base init + conditional setup, default flags

#include "..\..\include\game_globals.h"

// RGE_Master_Static_Object — base of the chain, virtual dtor for vtable
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    RGE_Master_Static_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
};

// RGE_Master_Combat_Object — inherits from RGE_Master_Static_Object via RGE_Master_Action_Object
class RGE_Master_Combat_Object : public RGE_Master_Static_Object {
public:
    RGE_Master_Combat_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
};

// RGE_Master_Missile_Object — inherits from RGE_Master_Combat_Object, size 0x154
class RGE_Master_Missile_Object : public RGE_Master_Combat_Object {
public:
    void setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3);

    RGE_Master_Missile_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
};

RGE_Master_Missile_Object::RGE_Master_Missile_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4)
    : RGE_Master_Combat_Object(param_1, param_2, param_3, 0)
{
    if (param_4 != 0) {
        this->setup(param_1, param_2, param_3);
    }
}
