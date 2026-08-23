// decrementResource (00412870, 92 bytes, airesmod.cpp)
// Attempt 1

#include "../../include/airesmod_context.h"

void ResourceAIModule::decrementResource(int resourceID, int value) {
    this->logCommonHistory("decrementResource: n=%d, v=%d.", resourceID, value);

    if (resourceID < 0 || resourceID >= numberResourcesValue) {
        return;
    }

    resourceValue[resourceID] -= value;

    if (value == 0) {
        return;
    }

    this->logCommonHistory("  decrementResource: r[%d]=%d.", resourceID, resourceValue[resourceID]);
}
