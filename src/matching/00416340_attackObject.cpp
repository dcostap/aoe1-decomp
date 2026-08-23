// 00416340 UnitAIModule::attackObject
#include "../../include/aiuaimod_context.h"

int UnitAIModule::attackObject(int targetId, int flag) {
    if (flag != 0 || this->currentActionValue == -1) {
        RGE_Static_Object* target =
            this->objectValue->owner->world->object(targetId);
        if (target != 0) {
            if (this->canAttackUnit(target)) {
                if (this->objectValue->attack(targetId, flag) == 1) {
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
