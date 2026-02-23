#pragma once
#include "common.h"

class AIModuleID {
public:
    AIModuleID(char* param_1, int param_2);

    // Virtuals (best-effort)
    virtual ~AIModuleID(); // vt[0] (0x0)

    void setID(int param_1, char* param_2);
    void* vector_deleting_destructor(uint param_1);

    int id;
    char name[64];
};
static_assert(sizeof(AIModuleID) == 0x48, "Size mismatch");
