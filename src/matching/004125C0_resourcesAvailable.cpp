// target: VA 004125C0 ResourceAIModule::resourcesAvailable(ResourceItem *)
// Exact-match note: keep a `count` local initialized from item->number(), then
// refresh it at the bottom of the loop. This gives VC5 the original single
// initial count test plus bottom `index < item->number()` back-edge, without an
// extra top-of-loop number() call or first-iteration peel.

#include "../../include/airesmod_context.h"

int ResourceAIModule::resourcesAvailable(ResourceItem* item) {
    int index;
    int count;

    if (item == 0) {
        return 0;
    }

    if (this->numberResourcesValue != item->number()) {
        return 0;
    }

    index = 0;
    count = item->number();
    while (index < count) {
        if (this->resourceValue[index] < item->value(index)) {
            return 0;
        }
        ++index;
        count = item->number();
    }

    return 1;
}
