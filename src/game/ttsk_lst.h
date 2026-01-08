#pragma once
#include "../common.h"

class TRIBE_Task_List       {
public:
    char _pad_0x4[0x8];


    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 WARNING: Function body missing in analysis
    // virtual void create_task();

    // [Slot 01] Offset 0x04 (Override)
    virtual RGE_Task* get_target_task(RGE_Action_Object* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5); // Ghidra: get_target_task

    // [Slot 02] Offset 0x08 (Override)
    virtual int is_attack_task(RGE_Task* param_1); // Ghidra: is_attack_task

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void check_task();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void copy_obj();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void modify();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void modify_delta();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void modify_percent();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void make_new_obj();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void make_new_master();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void check_placement();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void alignment();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void calc_base_damage_ability();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void play_command_sound();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void play_move_sound();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void data_load_random_map();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void load_random_map();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void do_terrain_brush();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void do_terrain_brush_stroke();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void do_elevation_brush();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void do_elevation_brush_stroke();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void do_cliff_brush();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void do_cliff_brush_stroke();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void map_generate();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void map_generate2();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void delete_cliff();

};

static_assert(sizeof(TRIBE_Task_List) == 0xC, "TRIBE_Task_List Size Mismatch");

