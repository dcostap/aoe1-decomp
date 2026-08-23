#include "../../include/aiuaimod_context.h"

OrderEvent* UnitAIModule::orderQueueElement(int index) const {
    if (index >= 0 && index < this->orderQueueSizeValue &&
        this->orderQueueValue != 0) {
        return this->orderQueueValue + index;
    }
    return 0;
}
