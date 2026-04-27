// 0050F320 TRIBE_Master_Tree_Object::make_new_obj
// Source: tm_tre_o.cpp lines 53-55
// Size: 122 bytes, EH-framed
//
// Attempt log:
// Probe 1: simple alloc+ctor with new expression, /GX

#include "..\..\include\game_globals.h"

class RGE_Player;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
};

class TRIBE_Tree_Object : public RGE_Static_Object {
public:
    char _gap_04[0x84];
    TRIBE_Tree_Object(void* master, void* player, float x, float y, float z, int flag);
};

class TRIBE_Master_Tree_Object {
public:
    virtual ~TRIBE_Master_Tree_Object();
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player, float x, float y, float z);
};

RGE_Static_Object* TRIBE_Master_Tree_Object::make_new_obj(RGE_Player* player, float x, float y, float z)
{
    TRIBE_Tree_Object* obj = new TRIBE_Tree_Object(this, player, x, y, z, 1);
    return obj;
}
