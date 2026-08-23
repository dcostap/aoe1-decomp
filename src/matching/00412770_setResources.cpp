#include "../../include/airesmod_context.h"

void ResourceAIModule::setResources(ResourceItem* item) {
    if (item && this->numberResourcesValue == item->number()) {
        int i = 0;
        if (item->number() > 0) {
            do {
                this->setResource(i, item->value(i));
                i++;
            } while (i < item->number());
        }
    }
}
