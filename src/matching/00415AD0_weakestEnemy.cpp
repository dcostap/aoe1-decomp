// VA: 00415AD0 UnitAIModule::weakestEnemy
// MATCHED: declare/init bestHp before the loop index. With `float bestHp = 0.0f; int i = 0;`
// VC5 emits `xor esi,esi; mov dword [esp+0Ch],0; test eax,eax`; declaring i first makes it
// reuse ESI for the zero store after the count test and shifts the loop by 4 bytes.
// Previous scratch state had behavior/calls/FPU compare modeled but drifted from that store order.

#include "../../include/game_globals.h"
#include "../../include/aiuaimod_context.h"

int UnitAIModule::weakestEnemy(float* outHp) {
    this->search();
    int bestId = -1;
    float bestHp = 0.0f;
    int i = 0;
    if ((int)DAT_0087d7d8 > 0) {
        do {
            int id = *(int*)((char*)DAT_0087d7f0 + i * 8);
            RGE_Static_Object* obj = this->lookupObject(id);
            if (obj != 0) {
                if (bestId == -1 || obj->hitPoints < bestHp) {
                    bestHp = obj->hitPoints;
                    bestId = *(int*)((char*)DAT_0087d7f0 + i * 8);
                }
            }
            i++;
        } while (i < (int)DAT_0087d7d8);
    }
    if (outHp != 0) {
        *outHp = bestHp;
    }
    return bestId;
}
