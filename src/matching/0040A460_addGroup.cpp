// VA: 0040A460 BaseObject::addGroup
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
    int addGroup(int group_id);
};

int BaseObject::addGroup(int group_id)
{
    if (inGroup(group_id))
        return 0;
    
    int* new_array = (int*)operator_new(numberGroupsValue * 4 + 4);
    if (!new_array)
        return 0;
    
    int i;
    for (i = 0; i < numberGroupsValue; i++)
        new_array[i] = groupIDValue[i];
    
    new_array[numberGroupsValue] = group_id;
    numberGroupsValue++;
    operator_delete(groupIDValue);
    groupIDValue = new_array;
    return 1;
}
