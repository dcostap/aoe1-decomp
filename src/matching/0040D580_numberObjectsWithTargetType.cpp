// 0040D580 MainDecisionAIModule::numberObjectsWithTargetType
// PDB: aimdmod.cpp:153-163, 221 bytes
// __thiscall, ret 4
// FLAGS: default
//
// Probe 5: inline unitAI calls, no extra locals

#include <stdlib.h>

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* ptr);

class RGE_Static_Object;
class UnitAIModule;

class RGE_Static_Object {
public:
    UnitAIModule* unitAI();
};

class UnitAIModule {
public:
    int currentTargetType();
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int index);
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    void* player;
    int* objects_value;
    int objects_numberValue;
    int objects_pad_FC;
    int objects_maximumSizeValue;

    int numberObjectsWithTargetType(int targetType);
};

int MainDecisionAIModule::numberObjectsWithTargetType(int targetType) {
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

            {
                int id = this->objects_value[i];
                void* world = *(void**)((char*)this->player + 0x3C);
                RGE_Static_Object* obj = ((RGE_Game_World*)world)->object(id);
                if (obj != NULL) {
                    if (obj->unitAI()) {
                        if (obj->unitAI()->currentTargetType() == targetType) {
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
