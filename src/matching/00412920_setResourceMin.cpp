#include "../../include/airesmod_context.h"

void ResourceAIModule::setResourceMin(int index, int value) {
    if (index >= 0 && index < numberResourcesValue) {
        minValue[index] = value;
    }
}
