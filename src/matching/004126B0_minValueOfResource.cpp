#include "../../include/airesmod_context.h"

int ResourceAIModule::minValueOfResource(int index) const {
    if (index >= 0 && index < numberResourcesValue) {
        return minValue[index];
    }
    return -1;
}
