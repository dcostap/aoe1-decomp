// 004FB8D0 TribeTacticalAIModule::taskToEnter
// taitacmd.cpp:9258-9281, 268 bytes
//
// int __thiscall TribeTacticalAIModule::taskToEnter(int param_1, int param_2)
// ret 8 cleanup (2 stack params + this in ecx)
//
// Flow:
// 1. param_1 == -1 → return 0 immediately
// 2. Search unitsTasked IntArray[+0xD58] for param_1 (two-bound: i < maxSize inside, i < count at loop bottom)
// 3. If not found, append param_1 to array, growing if count >= maxSize
//    Growth: operator_new((cnt+1)*4), copy min(cnt, maxSize) elements, operator_delete(old)
// 4. Dispatch mission via this->md->missionObj->vf30() with 12 params
// 5. return 1
//
// === Attempt log ===
// 1: Initial — first 21 bytes match exactly (prologue, early exit, ret 8)
//    Search loop: do-while with indexed access, count as local
//    Issues: count→edx vs ecx (offset 21), extra test maxSz>0 check (offset 28),
//            pointer-based access instead of indexed [edi+eax*4],
//            copy loop has extra test ebx>0 check,
//            field_4A loaded as 16-bit mov+movsx vs single movsx from memory,
//            param_2 loaded at wrong stack offset in dispatch section
//    All gaps = TU-context register allocation + optimization cascade
// BLOCKER: Same TU-context class as taskDefender/other taitacmd functions

#include <stdlib.h>

extern void* __cdecl operator_new(unsigned int size);
extern void __cdecl operator_delete(void* ptr);

struct IntArray {
    int* value;       // +0x00 (this+0xD58)
    int count;        // +0x04 (this+0xD5C)
    char _gap_08[4];  // +0x08 (unused in this function)
    int maxSize;      // +0x0C (this+0xD64)
};

class MissionSubObject {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30(short a, int b, int c, int d, int e, float f, float g, float h, float i, int j, int k, int l);
    char _gap_04[70];
    short field_4A;   // +0x4A
};

class TribeMainDecisionAIModule {
public:
    char _gap_00[0x0F0];
    MissionSubObject* missionObj; // +0xF0
};

class TribeTacticalAIModule {
public:
    char _gap_00[0x0F0];
    TribeMainDecisionAIModule* md; // +0xF0
    char _gap_0F4[0x0D58 - 0x0F4];
    IntArray unitsTasked; // +0xD58 (value), +0xD5C (count), +0xD64 (maxSize)

    int taskToEnter(int param_1, int param_2);
};

int TribeTacticalAIModule::taskToEnter(int param_1, int param_2)
{
    if (param_1 == -1)
        return 0;

    int cnt = this->unitsTasked.count;
    int i;  // declared here to prevent compiler constant-folding i=0 in the loop check

    // Two-bound search: i < maxSize (checked inside body), i < cnt (checked at loop bottom)
    if (cnt > 0) {
        int maxSz = this->unitsTasked.maxSize;
        i = 0;
        do {
            if (i >= maxSz)
                break;
            if (this->unitsTasked.value[i] == param_1)
                goto dispatch;
            i++;
        } while (i < cnt);
    }

    // Append param_1 to the array, growing if needed
    {
        int maxSz = this->unitsTasked.maxSize;

        if (cnt > maxSz - 1) {
            int newCnt = cnt + 1;
            int* newArray = (int*)operator_new(newCnt * 4);
            if (newArray != 0) {
                int oldMax = this->unitsTasked.maxSize;
                int j = 0;
                if (oldMax > 0) {
                    do {
                        if (j >= newCnt)
                            break;
                        newArray[j] = this->unitsTasked.value[j];
                        j++;
                    } while (j < oldMax);
                }

                operator_delete(this->unitsTasked.value);
                this->unitsTasked.value = newArray;
                this->unitsTasked.maxSize = newCnt;
            }
        }

        this->unitsTasked.value[this->unitsTasked.count] = param_1;
        this->unitsTasked.count = this->unitsTasked.count + 1;
    }

dispatch:
    // Mission dispatch: this->md->missionObj->vf30(field_4A, param_1, 0x2CD, param_2,
    //     field_4A, -1.0f, -1.0f, -1.0f, 1.0f, 1, 0, 100)
    {
        MissionSubObject* obj = this->md->missionObj;
        obj->vf30(
            obj->field_4A,
            param_1,
            0x2CD,
            param_2,
            obj->field_4A,
            -1.0f,
            -1.0f,
            -1.0f,
            1.0f,
            1,
            0,
            100
        );
    }

    return 1;
}
