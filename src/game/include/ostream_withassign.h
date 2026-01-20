#pragma once
#include "common.h"

class ostream_withassign {
public:
    // Virtuals (best-effort)
    virtual ~ostream_withassign(); // vt[0] (0x0)

};
static_assert(sizeof(ostream_withassign) == 0x1, "Size mismatch");
