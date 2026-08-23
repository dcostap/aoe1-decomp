// VA: 004167D0 buildObject (148B)
// Based on matched gatherObject sibling; action 0x25A and vcall +0x174.
// Attempt log:
// try 1: replaced raw helper shim with typed/nested-success form from matched gatherObject.

#include "../../include/aiuaimod_context.h"

int UnitAIModule::buildObject(int targetId, int flag) {
    if (flag != 0 || currentActionValue != 0x25A) {
        int result = objectValue->build(targetId, flag);
        if (result == 1) {
            RGE_Static_Object* target = objectValue->owner->world->object(targetId);

            setCurrentAction(0x25A);

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
