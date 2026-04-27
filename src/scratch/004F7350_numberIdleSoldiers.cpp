// 004F7350 TribeTacticalAIModule::numberIdleSoldiers
// Source: taitacmd.cpp lines 6891-6904
// Iterates soldiers[] array; counts those with currentAction==-1; appends to workingArea[]
//
// Attempt log:
// Probe 1: rough first pass — 84% diff. Complex expandable int array pattern with
//   soldier lookup chain (md->aiPlayer->world). Left in scratch.

#include "..\..\include\game_globals.h"

extern "C" void* __cdecl operator_new(unsigned int);   // 0054B6F0
extern "C" void  __cdecl operator_delete(void*);        // 0054B660

extern RGE_Static_Object* __fastcall RGE_Game_World_object(RGE_Game_World*, int); // 00545D30 (ecx=this, edx=id? or stack?)
extern RGE_Static_Object* __fastcall RGE_Static_Object__unitAI(RGE_Static_Object*); // 004C7420

// from the asm: 00413960 — UnitAIModule::currentAction
// Thiscall: ecx = this, returns int
extern int __fastcall UnitAIModule__currentAction(void*); // 00413960

// TribeTacticalAIModule internal fields
// +0x0F0: md (some manager/context with world access)
// +0x114: soldiers.value (int*)
// +0x118: soldiers.number 
// +0x120: soldiers.maximumSize
// +0xD48: workingArea.value (int*)
// +0xD4C: workingArea.number
// +0xD54: workingArea.maximumSize

class TribeTacticalAIModule {
public:
    char _gap_00[0x0F0];
    char* md;                           // +0x0F0
    char _gap_F4[0x20];                 // +0x0F4 to +0x113
    int* soldiers_value;                // +0x114
    int soldiers_number;                // +0x118
    char _gap_11C[4];                   // +0x11C (padding to +0x120)
    int soldiers_maxSize;               // +0x120
    // ... lots of gap
    char _gap_124[0xD48 - 0x124];
    int* workingArea_value;             // +0xD48
    int workingArea_number;             // +0xD4C
    char _gap_D50[4];                   // +0xD50 (padding to +0xD54)
    int workingArea_maxSize;            // +0xD54

    int numberIdleSoldiers();
};

int TribeTacticalAIModule::numberIdleSoldiers()
{
    int count = 0;
    int i = 0;
    this->workingArea_number = 0;

    if (this->soldiers_number <= 0)
        return count;

    do {
        // Auto-resize soldiers array if needed
        if (i >= this->soldiers_maxSize - 1) {
            int* new_arr = (int*)operator_new((i + 1) * 4);
            if (new_arr != 0) {
                int j = 0;
                if (this->soldiers_maxSize > 0) {
                    while (j < i + 1 && j < this->soldiers_maxSize) {
                        new_arr[j] = this->soldiers_value[j];
                        j++;
                    }
                }
                operator_delete(this->soldiers_value);
                this->soldiers_value = new_arr;
                this->soldiers_maxSize = i + 1;
            }
        }

        // Get game object for soldier at index i
        int soldierId = this->soldiers_value[i];
        char* mdPtr = (char*)this->md;
        char* player = *(char**)(mdPtr + 0x1256C);
        RGE_Game_World* world = *(RGE_Game_World**)(player + 0x3C);
        RGE_Static_Object* obj = RGE_Game_World_object(world, soldierId);

        if (obj != 0) {
            void* unitAI = RGE_Static_Object__unitAI(obj);
            if (unitAI != 0) {
                int action = UnitAIModule__currentAction(unitAI);
                if (action == -1) {
                    // Second soldiers resize (same pattern)
                    if (i >= this->soldiers_maxSize - 1) {
                        int* new_arr = (int*)operator_new((i + 1) * 4);
                        if (new_arr != 0) {
                            int j = 0;
                            if (this->soldiers_maxSize > 0) {
                                while (j < i + 1 && j < this->soldiers_maxSize) {
                                    new_arr[j] = this->soldiers_value[j];
                                    j++;
                                }
                            }
                            operator_delete(this->soldiers_value);
                            this->soldiers_value = new_arr;
                            this->soldiers_maxSize = i + 1;
                        }
                    }

                    int objId = this->soldiers_value[i];

                    // Check for duplicate in workingArea
                    int k = 0;
                    if (this->workingArea_number > 0) {
                        while (k < this->workingArea_maxSize) {
                            if (this->workingArea_value[k] == objId)
                                goto next_count;
                            k++;
                            if (k >= this->workingArea_number)
                                break;
                        }
                    }

                    // Resize workingArea if needed
                    if (this->workingArea_number >= this->workingArea_maxSize - 1) {
                        int newSize = this->workingArea_number + 1;
                        int* new_arr = (int*)operator_new(newSize * 4);
                        if (new_arr != 0) {
                            int j = 0;
                            if (this->workingArea_maxSize > 0) {
                                while (j < newSize && j < this->workingArea_maxSize) {
                                    new_arr[j] = this->workingArea_value[j];
                                    j++;
                                }
                            }
                            operator_delete(this->workingArea_value);
                            this->workingArea_value = new_arr;
                            this->workingArea_maxSize = newSize;
                        }
                    }

                    // Append to workingArea
                    this->workingArea_value[this->workingArea_number] = objId;
                    this->workingArea_number++;

                next_count:
                    count++;
                }
            }
        }

        i++;
    } while (i < this->soldiers_number);

    return count;
}
