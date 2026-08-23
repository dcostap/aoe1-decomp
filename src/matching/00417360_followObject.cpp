// VA: 00417360
// UnitAIModule::followObject(int param_1, float param_2, int param_3)
// Size: 108 bytes
// Source: aiuaimod.cpp lines 3684-3702

// Local stubs for types used by this function
#include "../../include/aiuaimod_context.h"

int UnitAIModule::followObject(int param_1, float param_2, int param_3) {
    if (param_3 == 0 && this->currentActionValue != -1) {
        return 0;
    }

    RGE_Static_Object* target = this->objectValue->owner->world->object(param_1);
    if (target == 0) {
        return 0;
    }

    this->setCurrentAction(0x264);
    this->setCurrentTarget(param_1, target->world_x, target->world_y, target->world_z);
    this->desiredTargetDistanceValue = param_2;
    return 1;
}
