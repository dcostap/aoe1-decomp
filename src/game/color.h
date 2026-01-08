#pragma once
#include "../common.h"

class RGE_Color_Table       {
public:
    char color_table_name[30];               // 0x4
    short resource_id;                       // 0x22
    uchar type;                              // 0x24
    uchar map_color;                         // 0x25
    short id;                                // 0x26
    uchar table[256];                        // 0x28

    RGE_Color_Table(int param_1);
    RGE_Color_Table(_iobuf* param_1, short param_2);
    RGE_Color_Table(char* param_1);
    RGE_Color_Table(TDrawArea* param_1, long param_2, tagPALETTEENTRY* param_3, tagPALETTEENTRY* param_4);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~RGE_Color_Table() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // --- Non-Virtual Members ---
    void save(int param_1);
};

static_assert(sizeof(RGE_Color_Table) == 0x128, "RGE_Color_Table Size Mismatch");
static_assert(offsetof(RGE_Color_Table, table) == 0x28, "RGE_Color_Table Offset Mismatch");

