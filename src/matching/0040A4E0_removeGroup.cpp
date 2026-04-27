// VA: 0040A4E0 BaseObject::removeGroup
// PDB source: aibobj.cpp

#include <stdlib.h>

extern "C" {
    void* __cdecl operator_new(size_t size);
    void __cdecl operator_delete(void* ptr);
}

struct BaseObject {
    void* vtable;
    class BaseObject* next;
    class BaseObject* prev;
    int numberGroupsValue;
    int* groupIDValue;
    int categoryIDValue;
    int typeIDValue;
    int gameIDValue;
    char nameValue[64];
    float xPositionValue;
    float yPositionValue;
    float zPositionValue;
    float xSizeValue;
    float ySizeValue;
    float zSizeValue;
    int hitPointValue;
    int minHitPointValue;
    int maxHitPointValue;
    int busyValue;
    int currentTaskValue;
    int currentTargetValue;
    int currentTargetTypeValue;
    float currentTargetXPositionValue;
    float currentTargetYPositionValue;
    float currentTargetZPositionValue;

    int inGroup(int group_id);
    int removeGroup(int group_id);
};

int BaseObject::removeGroup(int group_id)
{
    if (!inGroup(group_id))
        return 0;
    
    int* new_array = (int*)operator_new(numberGroupsValue * 4 - 4);
    if (!new_array)
        return 0;
    
    int i = 0;
    if (numberGroupsValue > 0) {
        int* dst = new_array;
        do {
            if (groupIDValue[i] != group_id) {
                *dst = groupIDValue[i];
                dst++;
            }
            i++;
        } while (i < numberGroupsValue);
    }
    
    numberGroupsValue--;
    operator_delete(groupIDValue);
    groupIDValue = new_array;
    return 1;
}
