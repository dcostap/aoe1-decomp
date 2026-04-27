// VA: 00451C10 RGE_Master_Moving_Object::setup
// PDB source: m_mo_obj.cpp
// Attempt log:
// - v1: short locals -> 240/247 bytes (7 short)
// - v2: read into struct fields -> 247/247 but 81% diff (stack reuse different)
// - v3: back to locals, read into move_sprite field -> 81% diff
// - Not matching: VC5 reuses param stack slots for locals, C code uses separate slots
// - Left in scratch

#include <stdlib.h>

extern "C" {
    void rge_read(int fd, void* buf, int size);
}

struct RGE_Master_Animated_Object_setup3 {
    char base[0xBC];
    int setup(int a, void** b, void** c);
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
    int setup(int fd, void** sprites, void** sounds);
};

int RGE_Master_Moving_Object::setup(int fd, void** sprites, void** sounds)
{
    int r = ((RGE_Master_Animated_Object_setup3*)this)->setup(fd, sprites, sounds);

    *(unsigned char*)((char*)this + 4) = 0x1E;

    short move_idx;
    short run_idx;
    rge_read(fd, &move_idx, 2);
    rge_read(fd, &run_idx, 2);
    rge_read(fd, &turn_speed, 4);
    rge_read(fd, &size_class, 1);
    rge_read(fd, &obj_trail_id, 2);
    rge_read(fd, &obj_trail_options, 1);
    rge_read(fd, &obj_trail_spacing, 4);
    rge_read(fd, &move_algorithem, 1);

    if (move_idx >= 0)
        move_sprite = sprites[move_idx];
    else
        move_sprite = 0;

    if (run_idx >= 0)
        run_sprite = sprites[run_idx];
    else
        run_sprite = 0;

    return 1;
}
