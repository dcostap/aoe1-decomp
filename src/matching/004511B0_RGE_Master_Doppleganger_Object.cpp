// 004511B0 RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object
// Source: m_dg_obj.cpp lines 42-45
// Size: 119 bytes, EH-framed
//
// Attempt log:
// Probe 1: natural ctor with base init + conditional setup, /GX (sibling of 0044FAB0)

#include "..\..\include\game_globals.h"

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    RGE_Master_Static_Object(void* stream, void** sprites, void** sounds, int index, int flag);
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Animated_Object();
    RGE_Master_Animated_Object(void* stream, void** sprites, void** sounds, int index, int flag);
};

class RGE_Master_Doppleganger_Object : public RGE_Master_Animated_Object {
public:
    virtual ~RGE_Master_Doppleganger_Object();
    void setup(void* stream, void** sprites, void** sounds, int index);
    RGE_Master_Doppleganger_Object(void* stream, void** sprites, void** sounds, int index, int flag);
};

RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(void* stream, void** sprites, void** sounds, int index, int flag)
    : RGE_Master_Animated_Object(stream, sprites, sounds, index, 0)
{
    if (flag != 0) {
        this->setup(stream, sprites, sounds, index);
    }
}
