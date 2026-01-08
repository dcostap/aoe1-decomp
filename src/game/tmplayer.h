#pragma once
#include "../common.h"

class TRIBE_Master_Player : public RGE_Master_Player       {
public:
    char _pad_0x4[0x28];

    TRIBE_Master_Player(_iobuf* param_1);
    TRIBE_Master_Player(int param_1);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TRIBE_Master_Player() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void finish_init();

    // [Slot 02] Offset 0x08 (Override)
    virtual void load_master_object(int param_1, uchar param_2, RGE_Sprite** param_3, RGE_Sound** param_4, short param_5); // Ghidra: load_master_object

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void create_master_object_space();

    // [Slot 04] Offset 0x10 (Override)
    virtual void load_object(_iobuf* param_1, uchar param_2, RGE_Sprite** param_3, RGE_Sound** param_4, short param_5); // Ghidra: load_object

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void save();

};

static_assert(sizeof(TRIBE_Master_Player) == 0x2C, "TRIBE_Master_Player Size Mismatch");

