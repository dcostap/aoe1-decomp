// 0050F320 TRIBE_Master_Tree_Object::make_new_obj
// Source: tm_tre_o.cpp lines 53-55
// Size: 122 bytes, EH-framed
//
// Attempt log:
// Probe 1: simple alloc+ctor with new expression, /GX

#include "..\..\include\game_globals.h"
#include "..\..\include\t_tre_ob_context.h"
#include "..\..\include\tm_tre_o_context.h"

RGE_Static_Object* TRIBE_Master_Tree_Object::make_new_obj(RGE_Player* player, float x, float y, float z)
{
    TRIBE_Tree_Object* obj = new TRIBE_Tree_Object(this, player, x, y, z, 1);
    return obj;
}
