#include "../../include/airesmod_context.h"

int ResourceAIModule::resource(int index) const {
    if (index >= 0 && index < numberResourcesValue) {
        return resourceValue[index];
    }
    return -1;
}
