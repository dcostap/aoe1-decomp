#pragma once
#include "../common.h"

class TRIBE_Effects : public RGE_Effects       {
public:
    char _pad_0x4[0x8];

    TRIBE_Effects(int param_1);
    TRIBE_Effects(char* param_1);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TRIBE_Effects() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 02] Offset 0x08 (Override)
    virtual void do_effect(short param_1, RGE_Player* param_2); // Ghidra: do_effect

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // --- Non-Virtual Members ---
    void do_tech_effect(short param_1, RGE_Player* param_2);
};

static_assert(sizeof(TRIBE_Effects) == 0xC, "TRIBE_Effects Size Mismatch");

