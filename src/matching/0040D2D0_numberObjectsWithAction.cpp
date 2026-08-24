// 0040D2D0 MainDecisionAIModule::numberObjectsWithAction
// PDB: aimdmod.cpp:106-116, 221 bytes
// __thiscall, int, ret 4
// FLAGS: default
//
// Attempt log:
// probe 1: initial attempt, modeled after numberObjectsWithGroup pattern

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
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];          // AIModule base
    void* player;                // +0xF0: RGE_Player*
    int* objects_value;          // +0xF4
    int objects_numberValue;     // +0xF8
    int objects_pad_FC;          // +0xFC
    int objects_maximumSizeValue; // +0x100

    int numberObjectsWithAction(int action);
};
#endif

int MainDecisionAIModule::numberObjectsWithAction(int action) {
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
                UnitAIModule* ai = obj->unitAI();
                if (ai != NULL) {
                    if (obj->unitAI()->currentAction() == action) {
                        count++;
                    }
                }
            }

            i++;
        } while (i < this->objects_numberValue);
    }

    return count;
}
