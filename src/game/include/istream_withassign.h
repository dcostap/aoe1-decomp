#pragma once
#include "common.h"

class istream_withassign {
public:
    // Virtuals (best-effort)
    virtual ~istream_withassign(); // vt[0] (0x0)

};
static_assert(sizeof(istream_withassign) == 0x1, "Size mismatch");
