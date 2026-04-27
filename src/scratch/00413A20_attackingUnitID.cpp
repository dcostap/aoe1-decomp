// UnitAIModule::attackingUnitID — real pass
// VA: 00413A20
#include "../../include/game_globals.h"

int __fastcall attackingUnitID(void* _this, int _, int idx)
{
    if (idx < 0 || idx >= *(int*)((char*)_this + 0x64)) return -1;
    if (idx > *(int*)((char*)_this + 0x6C) - 1) {
        int newCap = idx + 1;
        int* newArr = (int*)operator new(newCap * 4);
        if (newArr) {
            int oldCap = *(int*)((char*)_this + 0x6C);
            int* oldArr = *(int**)((char*)_this + 0x60);
            for (int i = 0; i < oldCap && i < newCap; i++)
                newArr[i] = oldArr[i];
            operator delete(oldArr);
            *(int**)((char*)_this + 0x60) = newArr;
            *(int*)((char*)_this + 0x6C) = newCap;
        }
    }
    return (*(int**)((char*)_this + 0x60))[idx];
}
