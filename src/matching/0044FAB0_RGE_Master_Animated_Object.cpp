// 0044FAB0 RGE_Master_Animated_Object::RGE_Master_Animated_Object
// Source: m_an_obj.cpp lines 42-45
// Size: 119 bytes, EH-framed
//
// Attempt log:
// Probe 1: natural ctor with base init + conditional setup, /GX
// The PDB signature keeps the file index as short.  The earlier int probe was
// compiler steering and is not part of the shared source model.

#include "..\..\include\game_globals.h"

#ifndef RGE_MAN_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    RGE_Master_Static_Object(FILE* stream, RGE_Sprite** sprites,
                             RGE_Sound** sounds, short index, int flag);
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    RGE_Master_Animated_Object(FILE* stream, RGE_Sprite** sprites,
                               RGE_Sound** sounds, short index, int flag);
protected:
    void setup(FILE* stream, RGE_Sprite** sprites, RGE_Sound** sounds,
               short index);
};
#endif

RGE_Master_Animated_Object::RGE_Master_Animated_Object(FILE* stream,
    RGE_Sprite** sprites, RGE_Sound** sounds, short index, int flag)
    : RGE_Master_Static_Object(stream, sprites, sounds, index, 0)
{
    if (flag != 0) {
        this->setup(stream, sprites, sounds, index);
    }
}
