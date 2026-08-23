// VA: 00451F30 RGE_Master_Moving_Object::copy_obj
// PDB source: m_mo_obj.cpp

#include <stdlib.h>

#ifndef RGE_MO_OBJ_SHARED_CONTEXT
struct RGE_Master_Animated_Object_copy {
    char base[0xBC];
    void copy_obj(void* src);
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
    void copy_obj(RGE_Master_Moving_Object* src);
};
#endif

#ifdef RGE_MO_OBJ_SHARED_CONTEXT
void RGE_Master_Moving_Object::copy_obj(RGE_Master_Static_Object* src)
#else
void RGE_Master_Moving_Object::copy_obj(RGE_Master_Moving_Object* src)
#endif
{
#ifdef RGE_MO_OBJ_SHARED_CONTEXT
    RGE_Master_Animated_Object::copy_obj(src);

    RGE_Master_Moving_Object* source = (RGE_Master_Moving_Object*)src;

    move_sprite = source->move_sprite;
    run_sprite = source->run_sprite;
    turn_speed = source->turn_speed;
    size_class = source->size_class;
    obj_trail_id = source->obj_trail_id;
    obj_trail_options = source->obj_trail_options;
    obj_trail_spacing = source->obj_trail_spacing;
    move_algorithem = source->move_algorithem;
#else
    ((RGE_Master_Animated_Object_copy*)this)->copy_obj(src);

    move_sprite = src->move_sprite;
    run_sprite = src->run_sprite;
    turn_speed = src->turn_speed;
    size_class = src->size_class;
    obj_trail_id = src->obj_trail_id;
    obj_trail_options = src->obj_trail_options;
    obj_trail_spacing = src->obj_trail_spacing;
    move_algorithem = src->move_algorithem;
#endif
}
