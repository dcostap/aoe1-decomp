// VA: 00416690 gatherObject (148B)
// Fully typed approach

#include "../../include/aiuaimod_context.h"

int UnitAIModule::gatherObject(int targetId, int flag) {
    if (flag != 0 || currentActionValue != 0x261) {
        int result = objectValue->gather(targetId, flag);
        if (result == 1) {
            RGE_Static_Object* target = objectValue->owner->world->object(targetId);

            setCurrentAction(0x261);

            if (target == 0) {
                setCurrentTarget(targetId, -1, 0, 0, 0);
            } else {
                short group = target->master_obj->object_group;
                setCurrentTarget(targetId, group, target->world_x, target->world_y, target->world_z);
            }
            return 1;
        }
    }
    return 0;
}
