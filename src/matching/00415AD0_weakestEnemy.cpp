// VA: 00415AD0 UnitAIModule::weakestEnemy
// MATCHED: declare/init bestHp before the loop index. With `float bestHp = 0.0f; int i = 0;`
// VC5 emits `xor esi,esi; mov dword [esp+0Ch],0; test eax,eax`; declaring i first makes it
// reuse ESI for the zero store after the count test and shifts the loop by 4 bytes.
// Previous scratch state had behavior/calls/FPU compare modeled but drifted from that store order.

extern int g_object_count;
extern int* g_object_ids;
#pragma comment(linker, "/include:_g_object_count")

class RGE_Static_Object {
public:
    char gap_00[0x30];
    float hp;
};

class UnitAIModule {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void update_los();

    RGE_Static_Object* lookupObject(int id);
    int weakestEnemy(float* outHp);
};

int UnitAIModule::weakestEnemy(float* outHp) {
    this->update_los();
    int bestId = -1;
    float bestHp = 0.0f;
    int i = 0;
    if (g_object_count > 0) {
        do {
            int id = *(int*)((char*)g_object_ids + i * 8);
            RGE_Static_Object* obj = this->lookupObject(id);
            if (obj != 0) {
                if (bestId == -1 || obj->hp < bestHp) {
                    bestHp = obj->hp;
                    bestId = *(int*)((char*)g_object_ids + i * 8);
                }
            }
            i++;
        } while (i < g_object_count);
    }
    if (outHp != 0) {
        *outHp = bestHp;
    }
    return bestId;
}
