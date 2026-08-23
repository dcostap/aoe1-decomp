// VA: 00416550 convertObject (148B)
// Based on matched gatherObject/buildObject siblings.
// Sibling pattern: inverted condition, nested success, shared return-0 tail.

#include "../../include/aiuaimod_context.h"

int UnitAIModule::convertObject(int targetId, int flag) {
    if (flag != 0 || currentActionValue != 0x25C) {
        int result = objectValue->convert(targetId, flag);
        if (result == 1) {
            RGE_Static_Object* target = objectValue->owner->world->object(targetId);

            setCurrentAction(0x25C);

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
