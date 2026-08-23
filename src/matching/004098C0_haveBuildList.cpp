// 004098C0 BuildAIModule::haveBuildList
// Source: aibldmod.cpp lines 499-505. 140 bytes. __thiscall.
// Returns 1 if this->buildListNameValue is not "NONE" or "NULL", else 0.
// MATCHED. Exact 140-byte match confirmed via local check_function.py.
// Key: #pragma intrinsic(strcmp) forces VC5 to inline strcmp with 2-byte
// comparison and sbb/sbb pattern, matching the original exactly.
extern "C" int strcmp(const char*, const char*);
#pragma intrinsic(strcmp)
#include "../../include/aibldmod_context.h"

#ifndef AIBLDMOD_SHARED_CONTEXT
class BuildAIModule {
public:
    char gap_00[0x1A4];
    char buildListNameValue[257]; // +0x1A4

    int haveBuildList();
};
#endif

int BuildAIModule::haveBuildList() {
    char* name = this->buildListNameValue;
    if (name != 0 && strcmp(name, "NONE") != 0 && strcmp(name, "NULL") != 0) return 1;
    return 0;
}
