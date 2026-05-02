// VA: 0040E3A0 id (46B, aimodule.cpp)
// AIModule::id - returns struct by value. VC5 NRVO writes to hidden output ptr.
#include <string.h>

struct AIModuleID {
    void* vtable;
    int id;
    int data[0x10];
};

class AIModule {
public:
    char gap_00[8];
    int some_id;
    int some_data[0x10];

    void id(AIModuleID& result) const;
};

void AIModule::id(AIModuleID& result) const {
    volatile int dummy = 0;
    result.id = this->some_id;
    memcpy(result.data, this->some_data, 0x40);
    result.vtable = (void*)0x56E928;
}
