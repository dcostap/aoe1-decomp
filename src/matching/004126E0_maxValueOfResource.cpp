#include "../../include/airesmod_context.h"

int ResourceAIModule::maxValueOfResource(int index) const {
    if (index >= 0 && index < numberResourcesValue) {
        return maxValue[index];
    }
    return -1;
}
