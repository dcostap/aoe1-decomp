#pragma once
#include "common.h"

class type_info {
public:
    // Virtuals (best-effort)
    virtual ~type_info(); // vt[0] (0x0)

};
static_assert(sizeof(type_info) == 0x1, "Size mismatch");
