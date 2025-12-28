#pragma once
#include "../types.h"

class TRegistry {
public:
    TRegistry(const char* key);
    ~TRegistry();

    static int RegGetInt(TRegistry* reg, int type, const char* name);
    static void RegSetInt(TRegistry* reg, int type, const char* name, int value);

    char key_name[256];
    char pad[16];
};

static_assert(sizeof(TRegistry) == 272, "TRegistry size mismatch");
