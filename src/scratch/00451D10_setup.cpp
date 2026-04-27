// VA: 00451D10 RGE_Master_Moving_Object::setup (file-based)
// PDB source: m_mo_obj.cpp

#include <stdio.h>
#include <stdlib.h>

struct RGE_Master_Animated_Object_setup4 {
    char base[0xBC];
    int setup(FILE* a, void** b, void** c, short d);
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
    int setup(FILE* param_1, void** param_2, void** param_3, short param_4);
};

int RGE_Master_Moving_Object::setup(FILE* param_1, void** param_2, void** param_3, short param_4)
{
    int local = 0;
    ((RGE_Master_Animated_Object_setup4*)this)->setup(param_1, param_2, param_3, param_4);
    
    *(unsigned char*)((char*)this + 4) = 0x1E;
    
    short v1, v2, v3, v4, v5;
    float vf;
    fscanf(param_1, "%hd %hd %hd %hd %hd %f", &v1, &v2, &v3, &v4, &v5, &vf);
    
    obj_trail_options = (unsigned char)v5;
    size_class = (unsigned char)v4;
    move_algorithem = (unsigned char)v3;
    obj_trail_id = v2;
    turn_speed = vf;
    obj_trail_spacing = *(float*)&v1;
    
    local = 1;
    return 1;
}
