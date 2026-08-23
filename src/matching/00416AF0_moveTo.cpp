// VA: 00416AF0 UnitAIModule::moveTo
// aiuaimod.cpp lines 3386-3404
//
// Attempt log:
// - Initial scratch was a free-function/raw-call implementation and not in the right thiscall/member-call surface.
// - Natural member-call source nearly matched immediately, but the first local layout had objectValue/currentActionValue
//   shifted by +4. Correcting UnitAIModule so objectValue is at +0x04 and currentActionValue at +0x30 produced exact code.
// Result: MATCH locally with `python tools/check_function.py --va 00416AF0`.

#include "../../include/aiuaimod_context.h"

int UnitAIModule::moveTo(int targetId, int flag) {
    if (flag || this->currentActionValue == -1) {
        if (this->objectValue->moveTo(targetId, flag) == 1) {
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
