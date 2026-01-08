#pragma once
#include "../common.h"

class TRIBE_Master_Building_Object : public TRIBE_Master_Combat_Object       {
public:
    char _pad_0x4[0x160];
    RGE_Sound* construction_sound;           // 0x164
    RGE_Sprite* construction_sprite;         // 0x168
    uchar building_connect_flag;             // 0x16C
    short building_facet;                    // 0x16E
    uchar build_and_go_away;                 // 0x170
    short on_build_make_obj;                 // 0x172
    short on_build_make_tile;                // 0x174
    short on_build_make_overlay;             // 0x176
    short on_build_make_tech;                // 0x178

    TRIBE_Master_Building_Object(TRIBE_Master_Building_Object* param_1, int param_2);
    TRIBE_Master_Building_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
    TRIBE_Master_Building_Object(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TRIBE_Master_Building_Object() noexcept(false); // Ghidra: `vector_deleting_destructor'

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

    // [Slot 09] Offset 0x24 (Override)
    virtual uchar alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4); // Ghidra: alignment

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void calc_base_damage_ability();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void play_command_sound();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void play_move_sound();

    // [Slot 13] Offset 0x34 (Override)
    virtual void draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8); // Ghidra: draw

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void create_task_list();

    // [Slot 15] Offset 0x3C (Override)
    virtual RGE_Static_Object* make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4, int param_5); // Ghidra: make_new_obj

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void copy_obj();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void modify();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void modify_delta();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void modify_percent();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void make_new_obj();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void make_new_master();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void check_placement();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void alignment();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void calc_base_damage_ability();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void play_command_sound();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void play_move_sound();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void create_task_list();

    // --- Non-Virtual Members ---
    int setup(TRIBE_Master_Building_Object* param_1);
    int setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
    int setup(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4);
};

static_assert(sizeof(TRIBE_Master_Building_Object) == 0x17C, "TRIBE_Master_Building_Object Size Mismatch");
static_assert(offsetof(TRIBE_Master_Building_Object, on_build_make_tech) == 0x178, "TRIBE_Master_Building_Object Offset Mismatch");

