// VA: 00415E50 UnitAIModule::closestResourceObject (235B)
// aiuaimod.cpp
//
// Canonical reconstruction: query the owning player's visible-resource list,
// rejecting already-tested resources until the object's path test succeeds.
// The 100-entry list is initialized to the historical 0x80000000 sentinel;
// the resource distance is returned through the optional integer output.
//
// Attempt log:
// - Replaced the stale placeholder with the binary-supported visible-resource
//   query, object path gate, distance check, and reject-list behavior.
// - A do/infinite-loop spelling caused VC5 to peel the first query; the
//   bounded while form restored one shared call site and the original CFG.
// - Naming the append cursor and incrementing the reject count before storing
//   the rejected ID reproduced the original EBP/EDI update order. MATCH.

extern float DAT_0056ebe0;

#include "../../include/aiuaimod_context.h"

int UnitAIModule::closestResourceObject(int resourceType, int* distance) {
    int excludeList[100];
    int* nextExclude = excludeList;
    for (int i = 0; i < 100; ++i) {
        excludeList[i] = 0x80000000;
    }

    int excludeCount = 0;
    VISIBLE_RESOURCE_REC* resource;
    while (excludeCount < 100) {
        resource = this->objectValue->owner->VR_List->Get_Closest_Resource(
            (int)this->objectValue->world_x,
            (int)this->objectValue->world_y,
            this->objectValue->currentZone(),
            resourceType,
            excludeList,
            excludeCount);
        if (resource == 0) {
            return -1;
        }

        if ((float)resource->distance >
            this->objectValue->master_obj->los - DAT_0056ebe0) {
            return -1;
        }

        if (this->objectValue->canPath(resource->object_id, 1.0f, 0, 0, -1,
                                       -1) == 1) {
            break;
        }

        ++excludeCount;
        *nextExclude++ = resource->object_id;
    }

    if (distance != 0) {
        *distance = resource->distance;
    }
    return resource->object_id;
}
