// VA: 004171F0 UnitAIModule::runAwayFromAttackers (357B)
// aiuaimod.cpp:3634-3678
//
// Attempt log:
// - Replaced the placeholder with the binary-supported early guard, attacking-
//   units ManagedArray<int> scan, world-object lookup, accumulated coordinate
//   deltas, float range getter, normalized retreat point, and evasiveMoveTo call.
// - Baseline below follows the exact same-TU typed surfaces and utmarray.h
//   inline growth body; initial body was 2 bytes over size and spilled the
//   range factor after the x87 sum.
// - Initializing xDiff/yDiff before the loop index restored the oracle's
//   immediate zero stores. Binding `range * 4.0f` at the maximumSpeed call kept
//   the scaled getter live through sqrt and reproduced the complete FPU tail.
//   MATCH (357/357 bytes, 5/5 calls, default flags).

#include <math.h>
#include "../../include/game_globals.h"
#include "../../include/aiuaimod_context.h"

#pragma intrinsic(sqrt)

int UnitAIModule::runAwayFromAttackers(int param_1) {
    if (param_1 == 0 && this->currentActionValue != -1)
        return 0;

    int i;
    float xDiff;
    float yDiff;

    xDiff = 0.0f;
    yDiff = 0.0f;
    i = 0;

    if (this->attackingUnitsValue.numberValue > 0) {
        do {
            RGE_Static_Object* attacker =
                this->objectValue->owner->world->object(this->attackingUnitsValue[i]);
            if (attacker != 0) {
                xDiff += attacker->world_x - this->objectValue->world_x;
                yDiff += attacker->world_y - this->objectValue->world_y;
            }
            ++i;
        } while (i < this->attackingUnitsValue.numberValue);
    }

    float range = this->objectValue->maximumSpeed() * 4.0f;
    float distance = (float)sqrt(xDiff * xDiff + yDiff * yDiff);

    return this->evasiveMoveTo(
        (float)(-((xDiff / distance) * range)) + this->objectValue->world_x,
        (float)(-((yDiff / distance) * range)) + this->objectValue->world_y,
        this->objectValue->world_z,
        1);
}
