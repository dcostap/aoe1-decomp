// VA: 00451B10 RGE_Master_Moving_Object::RGE_Master_Moving_Object (constructor)
// PDB source: m_mo_obj.cpp

#include <stdio.h>
#include <stdlib.h>

// Sized base struct: RGE_Master_Animated_Object = 0xBC bytes
struct RGE_Master_Animated_Object_base {
    char base[0xBC];
    void ctor_init(FILE* f, void** sprites, void** sounds, short a, int b);
};

struct RGE_Master_Moving_Object {
    char base_000[0xBC];
    void* move_sprite;
    void* run_sprite;
    float turn_speed;
    unsigned char size_class;
    short obj_trail_id;
    unsigned char obj_trail_options;
    char pad_0CD[3];
    float obj_trail_spacing;
    unsigned char move_algorithem;
    int setup(FILE* f, void** sprites, void** sounds, short a);
    RGE_Master_Moving_Object(FILE* f, void** sprites, void** sounds, short a, int b);
};

RGE_Master_Moving_Object::RGE_Master_Moving_Object(FILE* f, void** sprites, void** sounds, short a, int b)
{
    ((RGE_Master_Animated_Object_base*)this)->ctor_init(f, sprites, sounds, a, 0);
    *(int*)this = 0x5705A0;
    if (b) {
        setup(f, sprites, sounds, a);
    }
}
