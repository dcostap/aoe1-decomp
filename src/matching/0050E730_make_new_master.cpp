// first pass: direct `return new TRIBE_Master_Building_Object(this, 1);` shape for the EH-framed factory helper
// /GX was required to land the exact ctor/new basin for the 0x17C allocation
#include "..\..\include\game_types.h"

class RGE_Master_Static_Object {
public:
    void* vtable_ptr;
    char pad_04[0xB8 - 0x4];
};

class RGE_Master_Combat_Object : public RGE_Master_Static_Object {
public:
    char pad_B8[0x148 - 0xB8];
};

class TRIBE_Master_Building_Object : public RGE_Master_Combat_Object {
public:
    char pad_148[0x17C - 0x148];
    TRIBE_Master_Building_Object(TRIBE_Master_Building_Object* source, int do_setup);
    RGE_Master_Static_Object* make_new_master(void);
};

RGE_Master_Static_Object* TRIBE_Master_Building_Object::make_new_master(void) {
    return new TRIBE_Master_Building_Object(this, 1);
}
