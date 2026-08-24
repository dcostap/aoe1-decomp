// 0040D3B0 MainDecisionAIModule::numberObjectsWithGroup
// PDB: aimdmod.cpp:121-131, 201 bytes
// __thiscall, ret 4
// FLAGS: default
//
// Attempt log:
// probe 1: naive, 81.6% - wrong count init pattern (mov dword vs mov reg)
// probe 2-3: decl ordering -> wrong frame (sub esp,0Ch vs push ecx)
// probe 4: for loop, count=0;i=0 -> 77.6%, right prologue, first diff at +19
//   issue: EBP used for groupId, not i+1; copy loop uses wrong registers
// probe 5-10: various tweaks, no improvement
// probe 11: int limit = i+1 BEFORE operator_new -> EBP allocated to limit!
//   This prevents EBP from being used for groupId -> groupId stays on stack
//   Copy loop now matches original exactly
// Result: MATCH (0.0000% positional diff)

#include <stdlib.h>

class RGE_Static_Object;

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* ptr);

#ifndef AOE1_AIMDMOD_TU_CONTEXT_H
class RGE_Game_World {
public:
    char gap_00[0x88];
    RGE_Static_Object** objectsValue;
    int numberObjectsValue;
    int maxNumberObjectsValue;
    RGE_Static_Object** negativeObjectsValue;
    int numberNegativeObjectsValue;
    int maxNumberNegativeObjectsValue;

    RGE_Static_Object* object(int index);
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];          // AIModule base class
    void* player;                // +0xF0: RGE_Player*
    int* objects_value;          // +0xF4
    int objects_numberValue;     // +0xF8
    int objects_pad_FC;          // +0xFC
    int objects_maximumSizeValue; // +0x100

    int numberObjectsWithGroup(int groupId);
};
#endif

int MainDecisionAIModule::numberObjectsWithGroup(int groupId) {
    int count = 0;
    int i = 0;

    if (this->objects_numberValue > 0) {
        do {
            if (i > this->objects_maximumSizeValue - 1) {
                int limit = i + 1;
                int* new_arr = (int*)operator_new(i * 4 + 4);
                if (new_arr != NULL) {
                    int j = 0;
                    while (j < this->objects_maximumSizeValue && j < limit) {
                        new_arr[j] = this->objects_value[j];
                        j++;
                    }
                    operator_delete(this->objects_value);
                    this->objects_value = new_arr;
                    this->objects_maximumSizeValue = limit;
                }
            }

            void* world = *(void**)((char*)this->player + 0x3C);
            RGE_Static_Object* obj = ((RGE_Game_World*)world)->object(this->objects_value[i]);

            if (obj != NULL) {
                void* master_obj = *(void**)((char*)obj + 8);
                if (*(short*)((char*)master_obj + 0x14) == groupId) {
                    count++;
                }
            }

            i++;
        } while (i < this->objects_numberValue);
    }

    return count;
}
