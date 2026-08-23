// VA: 00451D10 RGE_Master_Moving_Object::setup (file-based)
// PDB source: m_mo_obj.cpp
//
// Attempt log:
// baseline: canonical moving-object fields and eight-value fscanf setup; two local IDs.
// aliases: preserving file/sprite-table values across scanf improved structural parity,
//          but source placement changed the prologue/register basin.
// control-flow: a local move-sprite result restored the common store and late null arm.
// parameter-home probe: direct casts to input parameter homes were worse and were rolled back.
// variant labs: alias placement/result/return and declaration/init surfaces were swept;
//              no exact or invariant-eligible result. Best emitted basin was alias-after
//              with a temporary move-sprite result (207-byte target remained 213 bytes).
// fresh pass: separate short outputs for the three scanf values copied into byte fields
//             recovered the original overlapping parameter-home LEAs; source assignment
//             order is size_class, move_algorithem, obj_trail_options.
// tail: a separate run_sprite result local, followed by one common member store/return,
//       restored the original success/null tail and produced the exact 207-byte body.
// Main-agent audit restored the canonical RGE_Master_Animated_Object inheritance
// and qualified base setup call; emitted code remains exact.

#include <stdio.h>

class RGE_Sprite;
class RGE_Sound;

#ifndef RGE_MO_OBJ_SHARED_CONTEXT
struct RGE_Master_Animated_Object {
    char base[0xBC];
    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short count);
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

    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short count);
};
#endif

int RGE_Master_Moving_Object::setup(FILE* file, RGE_Sprite** sprites,
                                    RGE_Sound** sounds, short count)
{
    RGE_Master_Animated_Object::setup(file, sprites, sounds, count);
    FILE* input = file;
    RGE_Sprite** sprite_table = sprites;
    short move_sprite_id;
    short run_sprite_id;
    short size_class_out;
    short obj_trail_options_out;
    short move_algorithem_out;
    RGE_Sprite* move_sprite;
    RGE_Sprite* run_sprite;

    *(unsigned char*)((char*)this + 4) = 0x1E;

    fscanf(input, "%hd %hd %f %hd %hd %hd %f %hd",
           &move_sprite_id, &run_sprite_id, &this->turn_speed, &size_class_out,
           &this->obj_trail_id, &obj_trail_options_out,
           &this->obj_trail_spacing, &move_algorithem_out);

    this->size_class = (unsigned char)size_class_out;
    this->move_algorithem = (unsigned char)move_algorithem_out;
    this->obj_trail_options = (unsigned char)obj_trail_options_out;

    if (move_sprite_id >= 0)
        move_sprite = sprite_table[move_sprite_id];
    else
        move_sprite = (RGE_Sprite*)0;
    this->move_sprite = move_sprite;

    if (run_sprite_id >= 0)
        run_sprite = sprite_table[run_sprite_id];
    else
        run_sprite = (RGE_Sprite*)0;
    this->run_sprite = run_sprite;
    return 1;
}
