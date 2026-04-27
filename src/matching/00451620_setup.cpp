// VA: 00451620 RGE_Master_Missile_Object::setup
// PDB source: m_mi_obj.cpp

#include <stdlib.h>

extern "C" {
    void rge_read(int fd, void* buf, int size);
}

struct RGE_Master_Missile_Object {
    char gap_000[0x148];
    unsigned char missile_type;
    unsigned char targetting_type;
    unsigned char missile_hit_info;
    unsigned char missile_die_info;
    unsigned char area_effect_specials;
    char gap_14D[3];
    float ballistics_ratio;
    int setup(int param_1, void** param_2, void** param_3);
};

struct RGE_Master_Combat_Object {
    char base[0x148];
    int setup(int param_1, void** param_2, void** param_3);
};

int RGE_Master_Missile_Object::setup(int param_1, void** param_2, void** param_3)
{
    int r = ((RGE_Master_Combat_Object*)this)->setup(param_1, param_2, param_3);
    
    *(unsigned char*)((char*)this + 4) = 0x3C;
    
    rge_read(param_1, &missile_type, 1);
    rge_read(param_1, &targetting_type, 1);
    rge_read(param_1, &missile_hit_info, 1);
    rge_read(param_1, &missile_die_info, 1);
    rge_read(param_1, &area_effect_specials, 1);
    rge_read(param_1, &ballistics_ratio, 4);
    
    return 1;
}
