#pragma once
#include "../types.h"

#pragma pack(push, 1)
class TRegistry {
public:
    char key_name[256];

    TRegistry(const char* key);
    ~TRegistry();

    static int RegGetInt(TRegistry* reg, int type, const char* name);
    static void RegSetInt(TRegistry* reg, int type, const char* name, int value);
};
#pragma pack(pop)
