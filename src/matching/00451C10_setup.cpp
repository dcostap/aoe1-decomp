// VA: 00451C10 RGE_Master_Moving_Object::setup
// PDB source: m_mo_obj.cpp
// Attempt log:
// - v1: short locals -> 240/247 bytes (7 short)
// - v2: read into struct fields -> 247/247 but 81% diff (stack reuse different)
// - v3: back to locals, read into move_sprite field -> 81% diff
// - Not matching: VC5 reuses param stack slots for locals, C code uses separate slots
// - Left in scratch
// - baseline: the natural serialized-field reconstruction matched the read/setup prefix;
//   remaining drift was the sprite-result control-flow and register topology.
// - move-result local: a named selected_move restored the original test/zero/join shape.
// - move predicate: nonnegative-first source order restored the late move null arm.
// - run-result local: selected_run, followed by one common member store, matched the
//   same-TU setup donor's success/null tail exactly.
// - Main-agent audit restored donor-backed animated-object inheritance, typed
//   sprite/sound parameters, and the named master-type field; code remains exact.

#include <stdlib.h>

extern "C" {
    void rge_read(int fd, void* buf, int size);
}

class RGE_Sprite;
class RGE_Sound;

#ifndef RGE_MO_OBJ_SHARED_CONTEXT
struct RGE_Master_Animated_Object {
    virtual ~RGE_Master_Animated_Object();
    unsigned char master_type;
    char gap_05[0xB7];
    int setup(int, RGE_Sprite**, RGE_Sound**);
};

struct RGE_Master_Moving_Object : RGE_Master_Animated_Object {
    RGE_Sprite* move_sprite;
    RGE_Sprite* run_sprite;
    float turn_speed;
    unsigned char size_class;
    short obj_trail_id;
    unsigned char obj_trail_options;
    char pad_0CD[3];
    float obj_trail_spacing;
    unsigned char move_algorithem;
    int setup(int fd, RGE_Sprite** sprites, RGE_Sound** sounds);
};
#endif

int RGE_Master_Moving_Object::setup(int fd, RGE_Sprite** sprites, RGE_Sound** sounds)
{
    RGE_Master_Animated_Object::setup(fd, sprites, sounds);
    RGE_Sprite** sprite_table = sprites;

    this->master_type = 0x1E;

    short move_idx;
    short run_idx;
    RGE_Sprite* selected_move;
    RGE_Sprite* selected_run;
    rge_read(fd, &move_idx, 2);
    rge_read(fd, &run_idx, 2);
    rge_read(fd, &turn_speed, 4);
    rge_read(fd, &size_class, 1);
    rge_read(fd, &obj_trail_id, 2);
    rge_read(fd, &obj_trail_options, 1);
    rge_read(fd, &obj_trail_spacing, 4);
    rge_read(fd, &move_algorithem, 1);

    if (move_idx >= 0)
        selected_move = sprite_table[move_idx];
    else
        selected_move = 0;

    move_sprite = selected_move;

    if (run_idx >= 0)
        selected_run = sprite_table[run_idx];
    else
        selected_run = 0;

    run_sprite = selected_run;

    return 1;
}
