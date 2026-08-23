// VA: 00452040 RGE_Master_Moving_Object::save
// PDB source: m_mo_obj.cpp

#include <stdlib.h>

extern "C" {
    void rge_write(int fd, void* buf, int size);
}

// RGE_Master_Animated_Object base: 0xBC bytes
#ifndef RGE_MO_OBJ_SHARED_CONTEXT
struct RGE_Master_Animated_Object_save {
    char base[0xBC];
    void save(int fd);
};

// RGE_Master_Moving_Object: 0xD8 bytes total
struct RGE_Master_Moving_Object {
    char base_000[0xBC];         // inherited (0xBC bytes)
    void* move_sprite;           // +0x0BC
    void* run_sprite;            // +0x0C0
    float turn_speed;            // +0x0C4
    unsigned char size_class;    // +0x0C8
    short obj_trail_id;          // +0x0CA
    unsigned char obj_trail_options; // +0x0CC
    char pad_0CD[3];             // padding
    float obj_trail_spacing;     // +0x0D0
    unsigned char move_algorithem; // +0x0D4
    
    void save(int fd);
};
#endif

void RGE_Master_Moving_Object::save(int fd)
{
    short temp_run_sprite;
    short temp_move_sprite;
    
    if (move_sprite)
        temp_run_sprite = *(short*)((char*)move_sprite + 0x72);
    else
        temp_run_sprite = -1;
    
    if (run_sprite)
        temp_move_sprite = *(short*)((char*)run_sprite + 0x72);
    else
        temp_move_sprite = -1;
    
#ifdef RGE_MO_OBJ_SHARED_CONTEXT
    RGE_Master_Animated_Object::save(fd);
#else
    ((RGE_Master_Animated_Object_save*)this)->save(fd);
#endif
    
    rge_write(fd, &temp_run_sprite, 2);
    rge_write(fd, &temp_move_sprite, 2);
    rge_write(fd, &turn_speed, 4);
    rge_write(fd, &size_class, 1);
    rge_write(fd, &obj_trail_id, 2);
    rge_write(fd, &obj_trail_options, 1);
    rge_write(fd, &obj_trail_spacing, 4);
    rge_write(fd, &move_algorithem, 1);
}
