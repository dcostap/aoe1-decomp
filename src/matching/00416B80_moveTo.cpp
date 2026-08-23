// VA: 00416B80 UnitAIModule::moveTo(int,float,int)
// aiuaimod.cpp lines 3410-3428
// Retry 2026-05-19: replace raw __fastcall/free-function body with natural member-call surface
// copied from matched 00416AF0 shape and adjusted for 3-arg virtual canMoveTo.

#include "../../include/aiuaimod_context.h"

int UnitAIModule::moveTo(int targetId, float range, int flag) {
    if (flag || this->currentActionValue == -1) {
        if (this->objectValue->moveTo(targetId, range, flag) == 1) {
            RGE_Static_Object* target = this->objectValue->owner->world->object(targetId);
            this->setCurrentAction(0x262);
            if (target == 0) {
                this->setCurrentTarget(targetId, 0, 0, 0);
                return 1;
            }
            this->setCurrentTarget(targetId, target->world_x, target->world_y, target->world_z);
            return 1;
        }
    }
    return 0;
}
