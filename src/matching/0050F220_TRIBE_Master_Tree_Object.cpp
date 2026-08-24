// 0050F220 TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object
// Source: tm_tre_o.cpp lines 32-38
// Size: 113 bytes, EH-framed
//
// Attempt log:
// Probe 1: natural ctor with base init + conditional setup + field_04 = 'Z', /GX

#include "..\..\include\game_globals.h"
#include "..\..\include\tm_tre_o_context.h"

TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(int param_1, RGE_Sprite** sprites, RGE_Sound** sounds, int flag)
    : RGE_Master_Static_Object(param_1, sprites, sounds, 0)
{
    if (flag != 0) {
        ((RGE_Master_Static_Object*)this)->setup(param_1, sprites, sounds);
        this->field_04 = 0x5A;
    }
}
