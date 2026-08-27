// VA: 004519A0 RGE_Master_Missile_Object::save
// PDB source: m_mi_obj.cpp
// BINARY NOTE: m_mi_obj.cpp lines 210-219 own this contiguous 0x004519A0-0x00451A1E body.
// The direct base save call and six ordered rge_write calls are the exact-anchor sequence.

#include "../../include/m_mi_obj_context.h"

extern "C" {
    void rge_write(int fd, void* buf, int size);
}

void RGE_Master_Missile_Object::save(int fd)
{
    RGE_Master_Combat_Object::save(fd);

    rge_write(fd, &missile_type, 1);
    rge_write(fd, &targetting_type, 1);
    rge_write(fd, &missile_hit_info, 1);
    rge_write(fd, &missile_die_info, 1);
    rge_write(fd, &area_effect_specials, 1);
    rge_write(fd, &ballistics_ratio, 4);
}
