// incrementResource (004127C0, 92 bytes, airesmod.cpp)
// Attempt 2: logCommonHistory is __cdecl

#include "../../include/airesmod_context.h"

void ResourceAIModule::incrementResource(int resourceID, int value) {
    this->logCommonHistory("incrementResource: n=%d, v=%d.", resourceID, value);

    if (resourceID < 0 || resourceID >= numberResourcesValue) {
        return;
    }

    resourceValue[resourceID] += value;

    if (value == 0) {
        return;
    }

    this->logCommonHistory("  incrementResource: r[%d]=%d.", resourceID, resourceValue[resourceID]);
}
