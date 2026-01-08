#pragma once
#include "../common.h"

class RGE_Master_Doppleganger_Object : public RGE_Master_Animated_Object       {
public:
    char _pad_0x4[0xB8];

    RGE_Master_Doppleganger_Object(RGE_Master_Doppleganger_Object* param_1, int param_2);
    RGE_Master_Doppleganger_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
    RGE_Master_Doppleganger_Object(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~RGE_Master_Doppleganger_Object() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 (Override)
    virtual void copy_obj(RGE_Master_Static_Object* param_1); // Ghidra: copy_obj

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void modify();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void modify_delta();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void modify_percent();

    // [Slot 05] Offset 0x14 (Override)
    virtual void save(int param_1); // Ghidra: save

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void make_new_obj();

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

    // [Slot 14] Offset 0x38 (Override)
    virtual RGE_Static_Object* make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4, RGE_Static_Object* param_5); // Ghidra: make_new_obj

    // --- Non-Virtual Members ---
    int setup(RGE_Master_Doppleganger_Object* param_1);
    int setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
    int setup(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4);
};

static_assert(sizeof(RGE_Master_Doppleganger_Object) == 0xBC, "RGE_Master_Doppleganger_Object Size Mismatch");

