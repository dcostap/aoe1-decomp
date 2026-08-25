// VA: 004E42B0 TribeInformationAIModule::timeToBeKilled(TacticalAIGroup*, RGE_Static_Object*)
// Source: taiinfmd.cpp lines 8298-8335
// Size: 158 bytes, __thiscall, ret 8 (2 params)
// Returns float
// MATCH (0% diff, 10 relocations masked)
// Key: gap_34 in RGE_Static_Object fixes field_3C offset;
//      `int i = 0` before numberUnits() call pushes esi in prologue;
//      do-while loop matches original structure;
//      inline group->unit(i) in damagePerSecond args for push ordering

extern float DAT_00575580;  // 0.0f
extern float DAT_005755C0;  // 600.0f

#ifndef TAIINFMD_PREFIX_CONTEXT
#define TAIINFMD_INFO_CONTEXT "../../include/information_dropsites_context.h"
#include TAIINFMD_INFO_CONTEXT
#undef TAIINFMD_INFO_CONTEXT
#endif

float TribeInformationAIModule::timeToBeKilled(TacticalAIGroup* group, RGE_Static_Object* target) {
    float rVal = 0.0f;
    int i = 0;

    int n = group->numberUnits();
    if (n > 0) {
        do {
            int uid = group->unit(i);
            RGE_Static_Object* obj = this->md->object(uid);

            if (obj) {
                float dps = this->damagePerSecond(
                    group->unit(i),
                    (int)target->world_x,
                    (int)target->world_y);

                if (dps == 0.0f) {
                    dps = DAT_005755C0;
                } else {
                    dps = obj->hp / dps;
                }

                rVal += dps;
            }

            i++;
        } while (i < group->numberUnits());
    }

    return rVal;
}
