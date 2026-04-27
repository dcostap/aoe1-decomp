// first pass: direct new-expression for the EH-framed factory helper
// if this is sticky, the only real follow-up is whether /GX is required to keep the ctor/new basin
#include "..\..\include\game_types.h"

class RGE_Master_Static_Object {
public:
    void* vtable_ptr;
    char pad_04[0xB8 - 0x4];
};

class RGE_Master_Action_Object : public RGE_Master_Static_Object {
public:
    char pad_B8[0xFC - 0xB8];
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    char pad_FC[0x148 - 0xFC];
    RGE_Master_Combat_Object(RGE_Master_Combat_Object* source, int do_setup);
    RGE_Master_Static_Object* make_new_master(void);
};

RGE_Master_Static_Object* RGE_Master_Combat_Object::make_new_master(void) {
    return new RGE_Master_Combat_Object(this, 1);
}
