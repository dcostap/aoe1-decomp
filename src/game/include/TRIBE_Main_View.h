#pragma once

#include "RGE_Main_View.h"

class TRIBE_Main_View : public RGE_Main_View {
public:
    TRIBE_Main_View();
    virtual ~TRIBE_Main_View();
};

static_assert(sizeof(TRIBE_Main_View) == 0x380, "Size mismatch");
