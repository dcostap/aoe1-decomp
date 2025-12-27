#pragma once
#include "../types.h"

class TRegistry {
public:
    static int RegGetInt(TRegistry* reg, int type, const char* name);
    static void RegSetInt(TRegistry* reg, int type, const char* name, int value);
};
