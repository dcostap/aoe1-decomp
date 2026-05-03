// 004FA820 TribeTacticalAIModule::taskExplorer
// taitacmd.cpp:8844-8865, 278 bytes
//
// int __thiscall TribeTacticalAIModule::taskExplorer(int param_1, int param_2)
// ret 8 cleanup (2 stack params + this in ecx)
//
// Flow:
// 1. Search/grow unitsTasked IntArray for param_1 (same pattern as taskToEnter)
// 2. If param_2 == 1: call unexploredArea(param_1, &targetPoint) to find target coords
//    - If found (returns 1): call taskExplorer(param_1, (float)x, (float)y, 1)
//    - If not found: call taskExplorer(param_1, -1.0f, -1.0f, 1)
// 3. If param_2 != 1: call taskExplorer(param_1, -1.0f, -1.0f, 0)
// 4. Returns result from the inner taskExplorer call (at 004FAAA0)
//
// === Attempt log ===
// 1: Prologue matches first 16 bytes exactly (sub esp,8, xor eax, push ebx/ebp,
//    mov ebp param_1, push esi, mov esi ecx, push edi)
//    First mismatch at offset 16: count→edx vs ecx (same cascade as taskToEnter)
//    Array search/grow/append same structure as taskToEnter
//    Dispatch section structurally correct with fild/fstp float conversion
// BLOCKER: Same TU-context register cascade (edx vs ecx for count) as taitacmd.cpp

#include <stdlib.h>

struct XYPoint {
    int x;
    int y;
};

struct IntArray {
    int* value;       // +0x00 (this+0xD58)
    int count;        // +0x04 (this+0xD5C)
    char _gap_08[4];
    int maxSize;      // +0x0C (this+0xD64)
};

extern void* __cdecl operator_new(unsigned int size);
extern void __cdecl operator_delete(void* ptr);

class TribeTacticalAIModule {
public:
    char _gap_00[0x0F0];
    void* md;                   // +0xF0
    char _gap_0F4[0x0D58 - 0x0F4];
    IntArray unitsTasked;       // +0xD58

    int taskExplorer(int param_1, int param_2);
    int taskExplorer(int param_1, float param_2, float param_3, int param_4);  // overload at 004FAAA0
    int unexploredArea(int param_1, XYPoint* point);
};

int TribeTacticalAIModule::taskExplorer(int param_1, int param_2)
{
    int cnt = this->unitsTasked.count;
    int i = 0;

    // Search for param_1 in unitsTasked array
    if (cnt > 0) {
        int maxSz = this->unitsTasked.maxSize;
        do {
            if (i >= maxSz)
                break;
            if (this->unitsTasked.value[i] == param_1)
                goto dispatch;
            i++;
        } while (i < cnt);
    }

    // Array growth and append (same as taskToEnter)
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
    if (param_2 == 1) {
        XYPoint targetPoint;
        int result = this->unexploredArea(param_1, &targetPoint);
        int flag = 1;

        if (result == 1) {
            return this->taskExplorer(param_1, (float)targetPoint.x, (float)targetPoint.y, flag);
        }

        // No unexplored area found — pass -1,-1 with flag=1
        return this->taskExplorer(param_1, -1.0f, -1.0f, flag);
    }

    // param_2 != 1 — pass -1,-1 with flag=0
    return this->taskExplorer(param_1, -1.0f, -1.0f, 0);
}
