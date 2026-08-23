// VA: 004E41C0 TribeInformationAIModule::damageInflictedPerSecond()
// Source: taiinfmd.cpp lines 8228-8257
// Size: 121 bytes, __thiscall, returns float
// Match note: keeping only the numerator temp and inlining getMaxHitPoints() in the division
// makes VC5 emit the original fstp/call/fdivr/fadd x87 sequence.

#include "../../include/information_dropsites_context.h"

float TribeInformationAIModule::damageInflictedPerSecond(TacticalAIGroup* group, RGE_Static_Object* target) {
    float rVal = 0.0f;
    int i = 0;
    int count = group->numberUnits();

    if (count > 0) {
        do {
            int unitID = group->unit(i);
            RGE_Static_Object* obj = this->md->object(unitID);

            if (obj != 0) {
                float temp = target->damageCapability(obj);
                rVal = temp / obj->rateOfFire() + rVal;
            }

            i++;
            count = group->numberUnits();
        } while (i < count);
    }

    return rVal;
}
