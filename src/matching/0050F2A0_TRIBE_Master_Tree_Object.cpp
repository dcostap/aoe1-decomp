// 0050F2A0 TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object
// Source: tm_tre_o.cpp lines 43-49
// Size: 123 bytes, EH-framed
//
// Attempt log:
// Probe 1: natural ctor with base init + conditional setup + field_04 = 'Z', /GX

#include "..\..\include\game_globals.h"

class RGE_Master_Static_Object {
public:
    char field_04;             // +0x04 (byte type marker)
    char _gap_05[0xB7];        // padding
    virtual ~RGE_Master_Static_Object();
    RGE_Master_Static_Object(int param_1, void** sprites, void** sounds, int flag);
    RGE_Master_Static_Object(void* stream, void** sprites, void** sounds, int index, int flag);
    void setup(void* stream, void** sprites, void** sounds, int index);
};

class TRIBE_Master_Tree_Object : public RGE_Master_Static_Object {
public:
    virtual ~TRIBE_Master_Tree_Object();
    TRIBE_Master_Tree_Object(void* stream, void** sprites, void** sounds, int index, int flag);
};

TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(void* stream, void** sprites, void** sounds, int index, int flag)
    : RGE_Master_Static_Object(stream, sprites, sounds, index, 0)
{
    if (flag != 0) {
        ((RGE_Master_Static_Object*)this)->setup(stream, sprites, sounds, index);
        this->field_04 = 0x5A;
    }
}
