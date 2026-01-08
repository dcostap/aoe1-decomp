#pragma once
#include "../common.h"

class istream_withassign       {
public:

    istream_withassign();
    istream_withassign(streambuf* param_1);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~istream_withassign() noexcept(false); // Ghidra: `vector_deleting_destructor'

};

static_assert(sizeof(istream_withassign) == 0x1, "istream_withassign Size Mismatch");

