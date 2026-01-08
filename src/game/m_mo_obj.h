#pragma once
#include "../common.h"
#include "m_an_obj.h"
#include "sprite.h"
#include "stat_obj.h"

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object       {
public:
    char _pad_0x4[0xB8];
    RGE_Sprite* move_sprite;                 // 0xBC
    RGE_Sprite* run_sprite;                  // 0xC0
    float turn_speed;                        // 0xC4
    uchar size_class;                        // 0xC8
    short obj_trail_id;                      // 0xCA
    uchar obj_trail_options;                 // 0xCC
    float obj_trail_spacing;                 // 0xD0
    uchar move_algorithem;                   // 0xD4

    RGE_Master_Moving_Object(RGE_Master_Moving_Object* param_1, int param_2);
    RGE_Master_Moving_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
    RGE_Master_Moving_Object(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~RGE_Master_Moving_Object() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 (Override)
    virtual void copy_obj(RGE_Master_Static_Object* param_1); // Ghidra: copy_obj

    // [Slot 02] Offset 0x08 (Override)
    virtual void modify(float param_1, uchar param_2); // Ghidra: modify

    // [Slot 03] Offset 0x0C (Override)
    virtual void modify_delta(float param_1, uchar param_2); // Ghidra: modify_delta

    // [Slot 04] Offset 0x10 (Override)
    virtual void modify_percent(float param_1, uchar param_2); // Ghidra: modify_percent

    // [Slot 05] Offset 0x14 (Override)
    virtual void save(int param_1); // Ghidra: save

    // [Slot 06] Offset 0x18 (Override)
    virtual RGE_Static_Object* make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4); // Ghidra: make_new_obj

    // [Slot 07] Offset 0x1C (Override)
    virtual RGE_Master_Static_Object* make_new_master(); // Ghidra: make_new_master

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void check_placement();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void alignment();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void calc_base_damage_ability();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void play_command_sound();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void play_move_sound();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void copy_obj();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void modify();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void modify_delta();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void modify_percent();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void make_new_obj();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void make_new_master();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void check_placement();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void alignment();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void calc_base_damage_ability();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void play_command_sound();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void play_move_sound();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void draw();

    // --- Non-Virtual Members ---
    int setup(RGE_Master_Moving_Object* param_1);
    int setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
    int setup(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4);
};

static_assert(sizeof(RGE_Master_Moving_Object) == 0xD8, "RGE_Master_Moving_Object Size Mismatch");
static_assert(offsetof(RGE_Master_Moving_Object, move_algorithem) == 0xD4, "RGE_Master_Moving_Object Offset Mismatch");

