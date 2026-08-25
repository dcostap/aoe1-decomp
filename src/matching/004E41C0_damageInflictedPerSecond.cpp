// VA: 004E41C0 TribeInformationAIModule::damageInflictedPerSecond()
// Source: taiinfmd.cpp lines 8228-8257
// Size: 121 bytes, __thiscall, returns float
// BINARY NOTE: The body ends at 004E4238 and has six calls, including two numberUnits rereads.
// BINARY NOTE: Direct target and object member expressions preserve the virtual-call and fault order.
// Match note: the direct damageCapability/rateOfFire expression emits the original x87 sequence.

#ifndef TAIINFMD_PREFIX_CONTEXT
#define TAIINFMD_INFO_CONTEXT "../../include/information_dropsites_context.h"
#include TAIINFMD_INFO_CONTEXT
#undef TAIINFMD_INFO_CONTEXT
#endif

float TribeInformationAIModule::damageInflictedPerSecond(TacticalAIGroup* group, RGE_Static_Object* target) {
    float rVal = 0.0f;
    int i = 0;
    int count = group->numberUnits();

    if (count > 0) {
        do {
            int unitID = group->unit(i);
            RGE_Static_Object* obj = this->md->object(unitID);

            if (obj != 0) {
                rVal = target->damageCapability(obj) / obj->rateOfFire() + rVal;
            }

            i++;
            count = group->numberUnits();
        } while (i < count);
    }

    return rVal;
}
