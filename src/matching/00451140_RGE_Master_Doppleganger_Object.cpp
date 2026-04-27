// 00451140 RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object
// Source: m_dg_obj.cpp lines 33-36
// public: __thiscall RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(int,RGE_Sprite**,RGE_Sound**,int)
//
// Attempt log:
// Probe 1: natural ctor with base init + conditional setup, default flags

#include "..\..\include\game_globals.h"

// RGE_Master_Static_Object — base, virtual dtor for vtable
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    RGE_Master_Static_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
};

// RGE_Master_Animated_Object — inherits from RGE_Master_Static_Object
class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    void setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
    RGE_Master_Animated_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
};

// RGE_Master_Doppleganger_Object — inherits from RGE_Master_Animated_Object, size 0xBC, no new fields
class RGE_Master_Doppleganger_Object : public RGE_Master_Animated_Object {
public:
    void setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
    RGE_Master_Doppleganger_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
};

RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4)
    : RGE_Master_Animated_Object(param_1, param_2, param_3, 0)
{
    if (param_4 != 0) {
        this->setup(param_1, param_2, param_3);
    }
}
