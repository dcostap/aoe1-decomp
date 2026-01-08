#pragma once
#include "../common.h"

class type_info       {
public:

    type_info(type_info* param_1);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~type_info() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // --- Non-Virtual Members ---
    int operator==(type_info* param_1);
    int operator!=(type_info* param_1);
    int before(type_info* param_1);
    char* raw_name();
    type_info* operator=(type_info* param_1);
};

static_assert(sizeof(type_info) == 0x1, "type_info Size Mismatch");

