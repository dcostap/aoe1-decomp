// 004E4350 TribeInformationAIModule::timeToBeKilled
// Size: 143 bytes

extern "C" int __cdecl _ftol();

#include "../../include/information_dropsites_context.h"

float TribeInformationAIModule::timeToBeKilled(int* ids, int count, RGE_Static_Object* obj) {
    float total = 0.0f;
    int remaining;
    int* p;
    RGE_Static_Object* target;
    int a;
    int b;
    float dps;

    if (count > 0) {
        remaining = count;
        p = ids;
        do {
            target = this->md->object(*p);
            if (target != 0) {
                a = (int)(obj->world_y);
                b = (int)(obj->world_x);
                dps = this->damagePerSecond(*p, b, a);
                if (dps == 0.0f) {
                    dps = 600.0f;
                } else {
                    dps = target->hp / dps;
                }
                total = total + dps;
            }
            p++;
            remaining--;
        } while (remaining != 0);
    }
    return total;
}
