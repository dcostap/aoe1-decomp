#include "../../include/airesmod_context.h"

void ResourceAIModule::incrementResources(ResourceItem* item) {
    int count;
    int i;
    int v;

    if (item != 0) {
        count = item->number();
        if (this->numberResourcesValue == count) {
            i = 0;
            count = item->number();
            if (count > 0) {
                do {
                    v = item->value(i);
                    this->incrementResource(i, v);
                    i++;
                    count = item->number();
                } while (i < count);
            }
        }
    }
}
