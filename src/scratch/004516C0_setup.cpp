// VA: 004516C0 RGE_Master_Missile_Object::setup
// PDB source: m_mi_obj.cpp
// Attempt log:
// - First pass had wrong stack layout (no push ecx prolog)
// - 2nd: tried int local to force stack slot, got sub esp instead of push ecx
// - Current: accept push ecx vs sub esp difference

#include <stdio.h>
#include <stdlib.h>

struct RGE_Master_Missile_Object {
    char gap_000[0x148];
    unsigned char missile_type;
    unsigned char targetting_type;
    unsigned char missile_hit_info;
    unsigned char missile_die_info;
    unsigned char area_effect_specials;
    char gap_14D[3];
    float ballistics_ratio;
    int setup(FILE* param_1, void** param_2, void** param_3, short param_4);
};

struct RGE_Master_Combat_Object_setup4 {
    char base[0x148];
    int setup(FILE* param_1, void** param_2, void** param_3, short param_4);
};

int RGE_Master_Missile_Object::setup(FILE* param_1, void** param_2, void** param_3, short param_4)
{
    void* ecx_save = this;
    ((RGE_Master_Combat_Object_setup4*)this)->setup(param_1, param_2, param_3, param_4);
    
    *(unsigned char*)((char*)this + 0xA4) = 1;
    *(unsigned char*)((char*)this + 4) = 0x3C;
    
    short v1, v2, v3, v4, v5;
    float vf;
    fscanf(param_1, "%hd %hd %hd %hd %hd %f", &v1, &v2, &v3, &v4, &v5, &vf);
    
    targetting_type = (unsigned char)v5;
    missile_hit_info = (unsigned char)v4;
    missile_die_info = (unsigned char)v3;
    area_effect_specials = (unsigned char)v2;
    missile_type = (unsigned char)v1;
    ballistics_ratio = vf;
    
    if (ecx_save) ecx_save = 0;
    return 1;
}
