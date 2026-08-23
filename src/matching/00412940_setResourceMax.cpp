#include "../../include/airesmod_context.h"

void ResourceAIModule::setResourceMax(int index, int value) {
    if (index >= 0 && index < numberResourcesValue) {
        maxValue[index] = value;
    }
}
