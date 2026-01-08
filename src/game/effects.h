#pragma once
#include "../common.h"

class RGE_Effects       {
public:
    RGE_Effect* effects;                     // 0x4
    long effect_num;                         // 0x8

    RGE_Effects(int param_1);
    RGE_Effects(char* param_1);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~RGE_Effects() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 (Override)
    virtual void save(int param_1); // Ghidra: save

    // [Slot 02] Offset 0x08 (Override)
    virtual void do_effect(short param_1, RGE_Player* param_2); // Ghidra: do_effect

};

static_assert(sizeof(RGE_Effects) == 0xC, "RGE_Effects Size Mismatch");
static_assert(offsetof(RGE_Effects, effect_num) == 0x8, "RGE_Effects Offset Mismatch");

