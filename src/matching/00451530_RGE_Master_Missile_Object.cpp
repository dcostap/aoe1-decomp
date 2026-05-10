// VA: 00451530 RGE_Master_Missile_Object::RGE_Master_Missile_Object
// PDB source: m_mi_obj.cpp lines 42-45
// public: __thiscall RGE_Master_Missile_Object::RGE_Master_Missile_Object(FILE*,RGE_Sprite**,RGE_Sound**,short,int)
//
// Attempt log:
// 1. Previous fake base-as-member `ctor` source compiled to only 80 bytes: no natural inheritance ctor EH/frame.
// 2. Switched to the same natural inheritance surface used by matched sibling 004514C0; base ctor in initializer list, visible virtual dtor, conditional setup in body.

#include "..\..\include\game_globals.h"
#include <stdio.h>

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
};

class RGE_Master_Combat_Object : public RGE_Master_Static_Object {
public:
    RGE_Master_Combat_Object(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5);
};

class RGE_Master_Missile_Object : public RGE_Master_Combat_Object {
public:
    RGE_Master_Missile_Object(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int do_setup);
    void setup(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4);
};

RGE_Master_Missile_Object::RGE_Master_Missile_Object(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int do_setup)
    : RGE_Master_Combat_Object(param_1, param_2, param_3, param_4, 0)
{
    if (do_setup != 0) {
        this->setup(param_1, param_2, param_3, param_4);
    }
}
