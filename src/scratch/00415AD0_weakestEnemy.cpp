// UnitAIModule::weakestEnemy — real pass
// VA: 00415AD0
#include "../../include/game_globals.h"

extern void* __fastcall _lookupObj(void* _this, int _, int id);

int __fastcall weakestEnemy(void* _this, int _, float* outHp)
{
    (*(void(__stdcall**)(void))(*(int*)_this + 0x20))();
    int bestId = -1;
    float bestHp = 0.0f;
    int count = *(int*)0x87D7D8;
    int* base = *(int**)0x87D7F0;
    for (int i = 0; i < count; i++) {
        int id = *(int*)((char*)base + i * 8);
        void* obj = _lookupObj(_this, 0, id);
        if (obj) {
            float hp = *(float*)((char*)obj + 0x30);
            if (bestId == -1 || hp < bestHp) {
                bestHp = hp;
                bestId = id;
            }
        }
    }
    if (outHp) *outHp = bestHp;
    return bestId;
}
