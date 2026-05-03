// 004F99B0 TribeTacticalAIModule::taskPlay
// taitacmd.cpp:8231-8251, 281 bytes
//
// int __thiscall TribeTacticalAIModule::taskPlay(int param_1, int* param_2, int param_3, int param_4,
//     int param_5, Waypoint* waypoints, int waypointCount)
// ret 1Ch cleanup (7 stack params + this in ecx)
//
// Flow:
// 1. If waypoints != NULL and count > 0: iterate waypoints (16B stride)
//    and call addWaypoint(param_1, (int)x, (int)y) via __ftol
// 2. Search/grow unitsTasked IntArray for param_1 (same pattern)
// 3. Dispatch mission: this->md->missionObj->vtable[0x4C](param_1..param_5)
// 4. Return 1
//
// === Attempt log ===
// 1: First 7 bytes match (push ebx, push ebp, mov ebp param_1, push esi)
//    this→edi vs orig this→esi (registers swapped with Waypoint* ptr)
//    AddWaypoint loop uses esi for waypoint ptr vs orig edi
//    Array search: count→edx, maxSz→esi, value ptr→ecx (cascade from reg swap)
//    Virtual dispatch: vtable[0x4C] call has correct 5-param pattern
//    Same TU-context register cascade as all taitacmd functions
// BLOCKER: TU-context register swap (this↔Waypoint*)

#include <stdlib.h>

struct Waypoint {
    float x;       // +0x00
    float y;       // +0x04
    char _pad08[8]; // +0x08..0x0F (16 byte stride)
};

struct IntArray {
    int* value;       // +0x00 (this+0xD58)
    int count;        // +0x04 (this+0xD5C)
    char _gap_08[4];
    int maxSize;      // +0x0C (this+0xD64)
};

extern void* __cdecl operator_new(unsigned int size);
extern void __cdecl operator_delete(void* ptr);

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
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C(int p1, int* p2, int p3, int p4, int p5);  // slot 19 = 0x4C
};

class TribeMainDecisionAIModule {
public:
    char _gap_00[0x0F0];
    MissionSubObject* missionObj;  // +0xF0
};

class TribeTacticalAIModule {
public:
    char _gap_00[0x0F0];
    TribeMainDecisionAIModule* md;       // +0xF0
    char _gap_0F4[0x0D58 - 0x0F4];
    IntArray unitsTasked;                // +0xD58

    int taskPlay(int param_1, int* param_2, int param_3, int param_4,
                 int param_5, Waypoint* waypoints, int waypointCount);
    void addWaypoint(int param_1, int x, int y);
};

int TribeTacticalAIModule::taskPlay(int param_1, int* param_2, int param_3, int param_4,
                                     int param_5, Waypoint* waypoints, int waypointCount)
{
    // Part 1: Add waypoints if provided
    if (waypoints != 0 && waypointCount > 0) {
        Waypoint* wp = waypoints;
        int count = waypointCount;
        do {
            int y = (int)wp->y;
            int x = (int)wp->x;
            this->addWaypoint(param_1, x, y);
            wp++;
            count--;
        } while (count != 0);
    }

    // Part 2: Search/grow unitsTasked array for param_1
    {
        int cnt = this->unitsTasked.count;
        int i = 0;

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
    // Part 3: Mission dispatch via md->missionObj->vf4C
    this->md->missionObj->vf4C(param_1, param_2, param_3, param_4, param_5);

    return 1;
}
