#include "../../include/aiuaimod_context.h"

void UnitAIModule::setCurrentOrder(int value) {
    this->lastOrderValue = this->currentOrderValue;
    this->currentOrderValue = value;
}
