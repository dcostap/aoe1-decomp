// target: VA 00412640 ResourceAIModule::unavailableResource(ResourceItem *)
// first pass: keep the null guard, resource-count guard, and indexed availability scan

#include "../../include/airesmod_context.h"

int ResourceAIModule::unavailableResource(ResourceItem* item) {
    int index;

    if (item == 0) {
        return 0;
    }

    if (this->numberResourcesValue != item->number()) {
        return -1;
    }

    for (index = 0; index < item->number(); ++index) {
        if (this->resourceValue[index] < item->value(index)) {
            return index;
        }
    }

    return -1;
}
