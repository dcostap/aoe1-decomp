// 0040D480 MainDecisionAIModule::numberObjectsWithActionAndTarget
// PDB: aimdmod.cpp:137-148, 241 bytes
// __thiscall, int ret, ret 8 (2 params)
// FLAGS: default
//
// Attempt log:
// probe 1: initial attempt, modeled after numberObjectsWithAction pattern

#include <stdlib.h>

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* ptr);

#ifndef AOE1_AIMDMOD_TU_CONTEXT_H
class RGE_Static_Object;
class UnitAIModule;

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

class RGE_Static_Object {
public:
    UnitAIModule* unitAI();
};

class UnitAIModule {
public:
    int currentAction();
    int currentTarget();
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];           // AIModule base
    void* player;                 // +0xF0: RGE_Player*
    int* objects_value;           // +0xF4
    int objects_numberValue;      // +0xF8
    int objects_pad_FC;           // +0xFC
    int objects_maximumSizeValue; // +0x100

    int numberObjectsWithActionAndTarget(int action, int target);
};
#endif

int MainDecisionAIModule::numberObjectsWithActionAndTarget(int action, int target) {
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

            void* world_ptr = *(void**)((char*)this->player + 0x3C);
            RGE_Static_Object* obj = ((RGE_Game_World*)world_ptr)->object(this->objects_value[i]);
            if (obj != NULL) {
                if (obj->unitAI() != NULL) {
                    if (obj->unitAI()->currentAction() == action) {
                        if (obj->unitAI()->currentTarget() == target) {
                            count++;
                        }
                    }
                }
            }

            i++;
        } while (i < this->objects_numberValue);
    }

    return count;
}
