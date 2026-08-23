// 004E4240 TribeInformationAIModule::damageInflictedPerSecond
// Source: taiinfmd.cpp lines 8263-8292
// public: float __thiscall TribeInformationAIModule::damageInflictedPerSecond(int*,int,RGE_Static_Object*)
//
// Attempt log:
// Probe 1: natural loop, virtual calls at correct slots, default flags

#include "../../include/information_dropsites_context.h"

float TribeInformationAIModule::damageInflictedPerSecond(int* ids, int count, RGE_Static_Object* refObj)
{
    float total = 0.0f;
    for (int i = 0; i < count; i++) {
        RGE_Static_Object* obj = this->md->object(ids[i]);
        if (obj != 0) {
            total += refObj->damageCapability(obj) / obj->rateOfFire();
        }
    }
    return total;
}
