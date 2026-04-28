// 004E4350 TribeInformationAIModule::timeToBeKilled
// Size: 143 bytes

extern "C" int __cdecl _ftol();

class MainDecisionAIModule {
public:
    void* object(int id);
};

class RGE_Static_Object {
public:
    char gap_00[0x30];
    float hp;                  // +0x30
    char gap_34[4];
    float field_38;            // +0x38
    float field_3C;            // +0x3C
};

class TribeInformationAIModule {
public:
    char gap_00[0x100];
    MainDecisionAIModule* md; // +0x100

    float damagePerSecond(int id, int a, int b);
    float timeToBeKilled(int* ids, int count, RGE_Static_Object* obj);
};

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
            target = (RGE_Static_Object*)this->md->object(*p);
            if (target != 0) {
                a = (int)(obj->field_3C);
                b = (int)(obj->field_38);
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
