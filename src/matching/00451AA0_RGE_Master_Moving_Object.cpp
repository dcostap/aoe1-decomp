// 00451AA0 RGE_Master_Moving_Object::RGE_Master_Moving_Object
// Source: m_mo_obj.cpp lines 34-37
// public: __thiscall RGE_Master_Moving_Object::RGE_Master_Moving_Object(int,RGE_Sprite**,RGE_Sound**,int)
//
// Attempt log:
// Probe 1: natural ctor with base init + conditional setup, default flags

#include "..\..\include\game_globals.h"

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    RGE_Master_Static_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    RGE_Master_Animated_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    void setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
    RGE_Master_Moving_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
};

RGE_Master_Moving_Object::RGE_Master_Moving_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4)
    : RGE_Master_Animated_Object(param_1, param_2, param_3, 0)
{
    if (param_4 != 0) {
        this->setup(param_1, param_2, param_3);
    }
}
