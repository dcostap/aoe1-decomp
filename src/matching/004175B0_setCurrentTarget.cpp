#include "../../include/aiuaimod_context.h"

void UnitAIModule::setCurrentTarget(int id, float x, float y, float z) {
    this->lastTargetValue = this->currentTargetValue;
    this->lastTargetTypeValue = this->currentTargetTypeValue;
    this->currentTargetValue = id;
    this->currentTargetXValue = x;
    this->currentTargetYValue = y;
    this->currentTargetZValue = z;

    RGE_Static_Object* object = this->objectValue->owner->world->object(id);
    if (object != 0) {
        this->currentTargetTypeValue = object->master_obj->object_group;
    }
}
