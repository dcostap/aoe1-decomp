// target: VA 004173D0 UnitAIModule::defendObject(int,float,int)
// sibling of followObject; keep the early currentAction gate, world lookup, action/target calls, and final field stores

#include "../../include/aiuaimod_context.h"

int UnitAIModule::defendObject(int id, float distance, int allow_when_busy) {
    RGE_Static_Object* target;

    if (allow_when_busy == 0 && this->currentActionValue != -1) {
        return 0;
    }

    target = this->objectValue->owner->world->object(id);
    if (target == 0) {
        return 0;
    }

    this->setCurrentAction(0x259);
    this->setCurrentTarget(id, target->world_x, target->world_y, target->world_z);
    this->defendTargetValue = id;
    this->desiredTargetDistanceValue = distance;
    return 1;
}
