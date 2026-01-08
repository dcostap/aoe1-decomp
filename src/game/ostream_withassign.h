#pragma once
#include "../common.h"

class ostream_withassign       {
public:

    ostream_withassign();
    ostream_withassign(streambuf* param_1);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~ostream_withassign() noexcept(false); // Ghidra: `vector_deleting_destructor'

};

static_assert(sizeof(ostream_withassign) == 0x1, "ostream_withassign Size Mismatch");

