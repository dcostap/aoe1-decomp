// UnitAIModule::healObject — action wrapper
// VA: 00416730
#include "../../include/game_globals.h"

#include "../../include/aiuaimod_context.h"

int UnitAIModule::repairObject(int targetId, int flag)
{
    if (flag || this->currentActionValue != 0x26A) {
        RGE_Static_Object* unit = this->objectValue;
        if (unit->repair(targetId, flag) == 1) {
            RGE_Static_Object* target = this->objectValue->owner->world->object(targetId);
            this->setCurrentAction(0x26A);
            if (target == 0) {
                this->setCurrentTarget(targetId, -1, 0, 0, 0);
                return 1;
            }
            this->setCurrentTarget(targetId, target->master_obj->object_group, target->world_x, target->world_y, target->world_z);
            return 1;
        }
    }
    return 0;
}
