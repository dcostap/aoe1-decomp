#pragma once
#include "common.h"

class AIModuleID {
public:
    // Virtuals (best-effort)
    virtual ~AIModuleID(); // vt[0] (0x0)

    int id;
    char name[64];
};
static_assert(sizeof(AIModuleID) == 0x48, "Size mismatch");
