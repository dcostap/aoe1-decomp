// first pass: direct new-expression for the EH-framed factory helper
// if this is sticky, the only real follow-up is whether /GX is required to keep the ctor/new basin
#include "..\..\include\game_types.h"

#ifndef RGE_MAC_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    void* vtable_ptr;
    char pad_04[0xB8 - 0x4];
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    char pad_BC[0xD8 - 0xBC];
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    char pad_D8[0xFC - 0xD8];
    RGE_Master_Action_Object(RGE_Master_Action_Object* source, int do_setup);
    RGE_Master_Static_Object* make_new_master(void);
};
#endif

RGE_Master_Static_Object* RGE_Master_Action_Object::make_new_master(void) {
    return new RGE_Master_Action_Object(this, 1);
}
