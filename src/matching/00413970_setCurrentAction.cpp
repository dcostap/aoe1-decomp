#include "../../include/aiuaimod_context.h"

void UnitAIModule::setCurrentAction(int value) {
    this->lastActionValue = this->currentActionValue;
    this->currentActionValue = value;
}
