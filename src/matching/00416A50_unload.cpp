// 00416A50 UnitAIModule::unload
// aiuaimod.cpp lines 3364-3381
#include "../../include/game_globals.h"

#include "../../include/aiuaimod_context.h"

int UnitAIModule::unload(int id, float x, float y)
{
    if (id || this->currentActionValue == -1) {
        RGE_Static_Object* obj = this->objectValue;
        if (obj->unload(id, x, y, obj->world_z) == 1) {
            RGE_Static_Object* target = this->objectValue;
            this->setCurrentAction(0x26D);
            if (target == 0) {
                this->setCurrentTarget(this->objectValue->id, -1, 0, 0, 0);
                return 1;
            }
            this->setCurrentTarget(this->objectValue->id, target->master_obj->object_group, target->world_x, target->world_y, target->world_z);
            return 1;
        }
    }
    return 0;
}
