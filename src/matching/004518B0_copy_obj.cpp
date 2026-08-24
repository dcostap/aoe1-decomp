// attempt log:
// first pass: straight base-copy plus direct byte/dword field copies at 0x148..0x150
// second pass: call the base helper through a casted this pointer so VC5 emits the member-call shape
// target shape: call RGE_Master_Combat_Object::copy_obj(param), then copy missile fields from source to this

#include "../../include/m_mi_obj_context.h"

#ifndef M_MI_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object;
class RGE_Master_Combat_Object;

class RGE_Master_Missile_Object {
public:
    char gap_00[0x148];
    unsigned char missile_type;
    unsigned char targetting_type;
    unsigned char missile_hit_info;
    unsigned char missile_die_info;
    unsigned char area_effect_specials;
    char gap_14D[0x3];
    float ballistics_ratio;

    void copy_obj(RGE_Master_Static_Object* source);
};

class RGE_Master_Combat_Object {
public:
    void copy_obj(RGE_Master_Static_Object* source);
};
#endif

void RGE_Master_Missile_Object::copy_obj(RGE_Master_Static_Object* source) {
    ((RGE_Master_Combat_Object*)this)->copy_obj(source);
#ifdef M_MI_OBJ_SHARED_CONTEXT
    RGE_Master_Missile_Object* missile_source =
        (RGE_Master_Missile_Object*)source;
    this->missile_type = missile_source->missile_type;
    this->targetting_type = missile_source->targetting_type;
    this->missile_hit_info = missile_source->missile_hit_info;
    this->missile_die_info = missile_source->missile_die_info;
    this->area_effect_specials = missile_source->area_effect_specials;
    this->ballistics_ratio = missile_source->ballistics_ratio;
#else
    this->missile_type = *(unsigned char*)((char*)source + 0x148);
    this->targetting_type = *(unsigned char*)((char*)source + 0x149);
    this->missile_hit_info = *(unsigned char*)((char*)source + 0x14A);
    this->missile_die_info = *(unsigned char*)((char*)source + 0x14B);
    this->area_effect_specials = *(unsigned char*)((char*)source + 0x14C);
    this->ballistics_ratio = *(float*)((char*)source + 0x150);
#endif
}
