#include "../../include/aiuaimod_context.h"

void UnitAIModule::setCurrentTarget(int id, int type, float x, float y, float z) {
    this->lastTargetValue = this->currentTargetValue;
    this->lastTargetTypeValue = this->currentTargetTypeValue;
    this->currentTargetValue = id;
    this->currentTargetTypeValue = type;
    this->currentTargetXValue = x;
    this->currentTargetYValue = y;
    this->currentTargetZValue = z;
}
