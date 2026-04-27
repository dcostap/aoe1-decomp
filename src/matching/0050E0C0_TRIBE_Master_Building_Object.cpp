// 0050E0C0 TRIBE_Master_Building_Object::TRIBE_Master_Building_Object
// Source: tm_b_obj.cpp lines 38-41
// public: __thiscall TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(int,RGE_Sprite**,RGE_Sound**,int)
//
// Attempt log:
// Probe 1: natural ctor with base init + conditional setup, default flags

#include "..\..\include\game_globals.h"

// RGE_Master_Static_Object — root of the master object virtual chain
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    RGE_Master_Static_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
};

// Intermediate types in the chain
class RGE_Master_Action_Object : public RGE_Master_Static_Object {
public:
    RGE_Master_Action_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    RGE_Master_Combat_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
};

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object {
public:
    TRIBE_Master_Combat_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
};

class TRIBE_Master_Building_Object : public TRIBE_Master_Combat_Object {
public:
    void setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3);

    TRIBE_Master_Building_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
};

TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4)
    : TRIBE_Master_Combat_Object(param_1, param_2, param_3, 0)
{
    if (param_4 != 0) {
        this->setup(param_1, param_2, param_3);
    }
}
