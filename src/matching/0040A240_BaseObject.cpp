// VA: 0040A240 BaseObject::BaseObject (copy constructor, const ref)
// PDB source: aibobj.cpp

#include <string.h>
#include <stdlib.h>

extern "C" {
    void* __cdecl operator_new(size_t size);
}

 #ifndef AIBOBJ_CONTEXT_READY
struct BaseObject {
    virtual ~BaseObject();
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

    BaseObject(const BaseObject& src);
};
#endif

BaseObject::BaseObject(const BaseObject& src)
{
    next = 0;
    prev = 0;
    numberGroupsValue = src.numberGroupsValue;
    categoryIDValue = src.categoryIDValue;
    typeIDValue = src.typeIDValue;
    gameIDValue = src.gameIDValue;
    xPositionValue = src.xPositionValue;
    yPositionValue = src.yPositionValue;
    zPositionValue = src.zPositionValue;
    xSizeValue = src.xSizeValue;
    ySizeValue = src.ySizeValue;
    zSizeValue = src.zSizeValue;
    hitPointValue = src.hitPointValue;
    minHitPointValue = src.minHitPointValue;
    maxHitPointValue = src.maxHitPointValue;
    busyValue = src.busyValue;
    currentTaskValue = src.currentTaskValue;
    currentTargetValue = src.currentTargetValue;
    currentTargetTypeValue = src.currentTargetTypeValue;
    currentTargetXPositionValue = src.currentTargetXPositionValue;
    currentTargetYPositionValue = src.currentTargetYPositionValue;
    currentTargetZPositionValue = src.currentTargetZPositionValue;
    groupIDValue = (int*)operator_new(numberGroupsValue * 4);
    
    int i;
    for (i = 0; i < numberGroupsValue; i++)
        groupIDValue[i] = src.groupIDValue[i];
    
    strncpy(nameValue, src.nameValue, 63);
}
