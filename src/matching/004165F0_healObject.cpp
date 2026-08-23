// UnitAIModule::healObject — action wrapper
// VA: 004165F0
#include "../../include/game_globals.h"

#include "../../include/aiuaimod_context.h"

int UnitAIModule::healObject(int targetId, int flag)
{
    if (flag || this->currentActionValue != 0x25B) {
        RGE_Static_Object* unit = this->objectValue;
        if (unit->heal(targetId, flag) == 1) {
            RGE_Static_Object* target = this->objectValue->owner->world->object(targetId);
            this->setCurrentAction(0x25B);
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
