// VA: 0040E3A0 id (46B, aimodule.cpp)
// Returns a copy of this module's ID (struct return by value)
//
// Attempt log:
// - NRVO in VC5 means the function writes directly to the hidden output pointer
// - Push ecx for local allocation is a key prologue signature
// - vtable is stored LAST, not first
// - memcpy generates rep movsd with ecx=10h

#include <string.h>

struct AIModuleID {
    void* vtable;
    int id;
    int data[0x10];
};

class AIModule {
public:
    char gap_00[8];
    int some_id; // +0x08
    int some_data[0x10]; // +0x0C

    AIModuleID id(void) const;
};

AIModuleID AIModule::id(void) const {
    AIModuleID result;
    result.vtable = (void*)0x56E928;
    result.id = this->some_id;
    memcpy(result.data, this->some_data, 0x40);
    return result;
}
