#pragma once
#include "../types.h"

class RGE_Player {
public:
    virtual ~RGE_Player();

    char data[540];
};

static_assert(sizeof(RGE_Player) == 544, "sizeof(RGE_Player) mismatch");
