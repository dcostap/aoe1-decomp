// 004FADA0 TribeTacticalAIModule::taskDefender
// taitacmd.cpp:8935-8946, 260 bytes
//
// int __thiscall TribeTacticalAIModule::taskDefender(int param_1, int param_2, float param_3, int param_4)
// ret 10h cleanup (4 stack params + this in ecx)
//
// === Attempt log ===
// 1: Initial version - class layout structs, new[]/delete[], do-while search loop
//    Prologue OK through offset 13, but register cascade: count→edx vs ecx
//    Search loop uses pointer arithmetic (add ecx,4) instead of indexed [edi+eax*4]
//    Edit diff: 97/260 (37.3%), positional diff: 213/260 (81.9%)
//    Text size: 272 vs 260 (12 bytes too big)
// 2: Variant lab confirms both do-while and while-break search styles produce identical code
//    Register allocation (count→edx vs ecx) is the cascade root

#include <new.h>

struct IntArray {
    int* value;      // +0x00: this+0xD58
    int count;       // +0x04: this+0xD5C
    int gap_08;      // +0x08
    int maxSize;     // +0x0C: this+0xD64
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
    short field_4A;
};

class TribeMainDecisionAIModule {
public:
    char _gap_00[0x0F0];
    MissionSubObject* missionObj;
};

class TribeTacticalAIModule {
public:
    char _gap_00[0x0F0];
    TribeMainDecisionAIModule* md;
    char _gap_0F4[0x0D58 - 0x0F4];
    IntArray unitsTasked;

    int taskDefender(int param_1, int param_2, float param_3, int param_4);
};

int TribeTacticalAIModule::taskDefender(int param_1, int param_2, float param_3, int param_4)
{
    int cnt = this->unitsTasked.count;
    int i = 0;

    // Search existing entries for param_1
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

    // Not found - add to tracked units
    {
        int maxSz = this->unitsTasked.maxSize;

        if (cnt > maxSz - 1) {
            // Grow the array by 1
            int newSize = cnt + 1;
            int* newVals = new int[newSize];
            if (newVals != 0) {
                int oldMax = this->unitsTasked.maxSize;
                int j = 0;
                if (oldMax > 0) {
                    do {
                        if (j >= newSize)
                            break;
                        newVals[j] = this->unitsTasked.value[j];
                        j++;
                    } while (j < oldMax);
                }

                delete[] this->unitsTasked.value;
                this->unitsTasked.value = newVals;
                this->unitsTasked.maxSize = newSize;
            }
        }

        this->unitsTasked.value[this->unitsTasked.count] = param_1;
        this->unitsTasked.count = this->unitsTasked.count + 1;
    }

dispatch:
    // Mission dispatch through this->md->missionObj->vf30()
    {
        MissionSubObject* obj = this->md->missionObj;
        obj->vf30(
            obj->field_4A,    // short at +0x4A: unit type/attribute
            param_1,          // unit ID
            0x2BD,            // mission type (701)
            param_2,          // target parameter
            -1,               // -1 (sentinel)
            -1.0f,            // -1.0f
            -1.0f,            // -1.0f
            -1.0f,            // -1.0f
            param_3,          // float parameter
            1,                // flag
            0,                // flag
            param_4           // last parameter
        );
    }

    return 1;
}
