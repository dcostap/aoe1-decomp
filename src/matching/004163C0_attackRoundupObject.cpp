// VA: 004163C0 UnitAIModule::attackRoundupObject
// aiuaimod.cpp
#include "../../include/aiuaimod_context.h"

int UnitAIModule::attackRoundupObject(int targetId) {
    if (this->currentTargetValue != targetId) {
        RGE_Static_Object* target =
            this->objectValue->owner->world->object(targetId);
        if (target != 0) {
            if (this->canAttackUnit(target)) {
                if (this->currentActionValue != -1) {
                    if (!this->objectValue->canPath(
                            targetId, this->objectValue->weaponRange(), 0, 0,
                            -1, -1)) {
                        return 0;
                    }
                }
                if (this->objectValue->attack(targetId, 1) == 1) {
                    this->setCurrentAction(0x258);
                    this->setCurrentTarget(targetId, target->world_x,
                                           target->world_y, target->world_z);
                    return 1;
                }
            }
        }
    }
    return 0;
}
