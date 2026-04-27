// VA: 004519A0 RGE_Master_Missile_Object::save
// PDB source: m_mi_obj.cpp

#include <stdlib.h>

extern "C" {
    void rge_write(int fd, void* buf, int size);
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
    void save(int fd);
};

struct RGE_Master_Combat_Object {
    char base[0x148];
    void save(int fd);
};

void RGE_Master_Missile_Object::save(int fd)
{
    ((RGE_Master_Combat_Object*)this)->save(fd);

    rge_write(fd, &missile_type, 1);
    rge_write(fd, &targetting_type, 1);
    rge_write(fd, &missile_hit_info, 1);
    rge_write(fd, &missile_die_info, 1);
    rge_write(fd, &area_effect_specials, 1);
    rge_write(fd, &ballistics_ratio, 4);
}
