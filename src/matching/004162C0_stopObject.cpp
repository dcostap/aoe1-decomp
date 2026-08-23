// VA: 004162C0 stopObject (118B)
// aiuaimod.cpp
//
// Attempt log:
// - Existing scratch was a near match (2 bytes diff): saving currentOrderValue into an `order` local before
//   storing currentOrderValue=-1 made VC5 use eax for the copied value, while original reloads through ecx in
//   the reset block.
// - SpruceGlow try 1 MATCH: assign `lastOrderValue = currentOrderValue;` directly before `currentOrderValue = -1`.
//   This lets VC5 use ecx for the member reload/store pair exactly as original.
// Result: MATCH locally with `python tools/check_function.py --va 004162C0`.

#include <stdio.h>

extern FILE* actionFile;

#include "../../include/aiuaimod_context.h"

int UnitAIModule::stopObject(int param) {
    if (actionFile != 0) {
        fprintf(actionFile, "t%ld, U#%d sO, cOAA=%d.\n",
            objectValue->owner->world->world_time,
            objectValue->id,
            param);
    }

    lastActionValue = currentActionValue;
    if (param == 0 || currentActionValue + 100 == currentOrderValue) {
        lastOrderValue = currentOrderValue;
        currentOrderValue = -1;
        currentOrderPriorityValue = -1;
    }

    objectValue->stopAction();
    currentActionValue = -1;
    return 1;
}
