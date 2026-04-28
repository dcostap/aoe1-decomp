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

struct TacticalAIGroup {
    int numberUnits();
    int unit(int idx);
};

struct MainDecisionAIModule {
    void* object(int unit_id);
};

struct RGE_Static_Object {
    char _pad[0x30];
    float hp;           // +0x30
    float gap_34;       // +0x34
    float field_38;     // +0x38
    float field_3C;     // +0x3C
};

struct TribeInformationAIModule {
    char _gap[0x100];
    void* md;  // +0x100

    float damagePerSecond(int uid, int val_38, int val_3C);
    float timeToBeKilled(TacticalAIGroup* group, RGE_Static_Object* target);
};

float TribeInformationAIModule::timeToBeKilled(TacticalAIGroup* group, RGE_Static_Object* target) {
    float rVal = 0.0f;
    int i = 0;

    int n = group->numberUnits();
    if (n > 0) {
        do {
            int uid = group->unit(i);
            void* obj = ((MainDecisionAIModule*)this->md)->object(uid);

            if (obj) {
                float dps = this->damagePerSecond(
                    group->unit(i),
                    (int)target->field_38,
                    (int)target->field_3C);

                if (dps == 0.0f) {
                    dps = DAT_005755C0;
                } else {
                    dps = *(float*)((char*)obj + 0x30) / dps;
                }

                rVal += dps;
            }

            i++;
        } while (i < group->numberUnits());
    }

    return rVal;
}
