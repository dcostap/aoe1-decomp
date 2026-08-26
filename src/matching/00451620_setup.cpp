// VA: 00451620 RGE_Master_Missile_Object::setup
// PDB source: m_mi_obj.cpp

#include "../../include/m_mi_obj_context.h"
#include <stdlib.h>

extern "C" {
    void rge_read(int fd, void* buf, int size);
}

#ifndef M_MI_OBJ_SHARED_CONTEXT
struct RGE_Master_Missile_Object {
    char gap_000[0x148];
    unsigned char missile_type;
    unsigned char targetting_type;
    unsigned char missile_hit_info;
    unsigned char missile_die_info;
    unsigned char area_effect_specials;
    char gap_14D[3];
    float ballistics_ratio;
protected:
    int setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
};

struct RGE_Master_Combat_Object {
    char base[0x148];
    int setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
};
#endif

int RGE_Master_Missile_Object::setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3)
{
#ifdef M_MI_OBJ_SHARED_CONTEXT
    RGE_Master_Combat_Object::setup(param_1, param_2, param_3);

    field_4 = 0x3C;

    rge_read(param_1, &missile_type, 1);
    rge_read(param_1, &targetting_type, 1);
    rge_read(param_1, &missile_hit_info, 1);
    rge_read(param_1, &missile_die_info, 1);
    rge_read(param_1, &area_effect_specials, 1);
    rge_read(param_1, &ballistics_ratio, 4);
#else
    int r = ((RGE_Master_Combat_Object*)this)->setup(param_1, param_2, param_3);
    
    *(unsigned char*)((char*)this + 4) = 0x3C;
    
    rge_read(param_1, &missile_type, 1);
    rge_read(param_1, &targetting_type, 1);
    rge_read(param_1, &missile_hit_info, 1);
    rge_read(param_1, &missile_die_info, 1);
    rge_read(param_1, &area_effect_specials, 1);
    rge_read(param_1, &ballistics_ratio, 4);

    return 1;
#endif

    return 1;
}
