#pragma once
#include "../common.h"

class TRIBE_Master_Tree_Object : public RGE_Master_Static_Object       {
public:
    char _pad_0x4[0xB4];

    TRIBE_Master_Tree_Object(TRIBE_Master_Tree_Object* param_1, int param_2);
    TRIBE_Master_Tree_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
    TRIBE_Master_Tree_Object(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TRIBE_Master_Tree_Object() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void copy_obj();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void modify();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void modify_delta();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void modify_percent();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void save();

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
    // virtual void data_load_random_map();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void load_random_map();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void do_terrain_brush();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void do_terrain_brush_stroke();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void do_elevation_brush();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void do_elevation_brush_stroke();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void do_cliff_brush();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void do_cliff_brush_stroke();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void map_generate();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void map_generate2();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void delete_cliff();

};

static_assert(sizeof(TRIBE_Master_Tree_Object) == 0xB8, "TRIBE_Master_Tree_Object Size Mismatch");

