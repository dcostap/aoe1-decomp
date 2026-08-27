// attempt log:
// first pass: straight base-copy plus direct byte/dword field copies at 0x148..0x150
// second pass: call the base helper through a casted this pointer so VC5 emits the member-call shape
// target shape: call RGE_Master_Combat_Object::copy_obj(param), then copy missile fields from source to this
// BINARY NOTE: m_mi_obj.cpp lines 155-166 own this contiguous 0x004518B0-0x0045190A body.
// The canonical class layout proves the missile fields at 0x148, 0x149, 0x14A, 0x14B, 0x14C, and 0x150.
// Grouped exactness requires the shared class surface; local duplicate class declarations do not compile.

#include "../../include/m_mi_obj_context.h"

void RGE_Master_Missile_Object::copy_obj(RGE_Master_Static_Object* source) {
    RGE_Master_Combat_Object::copy_obj(source);
    RGE_Master_Missile_Object* missile_source =
        (RGE_Master_Missile_Object*)source;
    this->missile_type = missile_source->missile_type;
    this->targetting_type = missile_source->targetting_type;
    this->missile_hit_info = missile_source->missile_hit_info;
    this->missile_die_info = missile_source->missile_die_info;
    this->area_effect_specials = missile_source->area_effect_specials;
    this->ballistics_ratio = missile_source->ballistics_ratio;
}
