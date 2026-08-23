// VA: 00451B90 RGE_Master_Moving_Object::setup (copy-setup)
// PDB source: m_mo_obj.cpp

#include <stdlib.h>

#ifndef RGE_MO_OBJ_SHARED_CONTEXT
struct RGE_Master_Animated_Object_setup {
    char base[0xBC];
    int setup(void* src);
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
    int setup(RGE_Master_Moving_Object* src);
};
#endif

int RGE_Master_Moving_Object::setup(RGE_Master_Moving_Object* src)
{
#ifdef RGE_MO_OBJ_SHARED_CONTEXT
    RGE_Master_Animated_Object::setup(src);
#else
    ((RGE_Master_Animated_Object_setup*)this)->setup(src);
#endif
    
    *(unsigned char*)((char*)this + 4) = 0x1E;
    
    move_sprite = src->move_sprite;
    run_sprite = src->run_sprite;
    turn_speed = src->turn_speed;
    size_class = src->size_class;
    obj_trail_id = src->obj_trail_id;
    obj_trail_options = src->obj_trail_options;
    obj_trail_spacing = src->obj_trail_spacing;
    move_algorithem = src->move_algorithem;
    
    return 1;
}
