#pragma once
#include "common.h"

class RGE_Scenario_Header {
public:
    // Virtuals (best-effort)
    virtual long get_size(); // vt[0] (0x0)
    virtual void save(int param_1); // vt[1] (0x4)

    int error_code;
    long version;
    unsigned long checksum;
    char* description;
};
static_assert(sizeof(RGE_Scenario_Header) == 0x14, "Size mismatch");
