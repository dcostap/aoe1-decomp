// VA: 0040A060 BaseObject::BaseObject (parameterized constructor)
// PDB source: aibobj.cpp
// Natural BaseObject surface with the PDB constructor argument order.

#include <string.h>
#include <stdlib.h>

void* __cdecl operator new(size_t size);

 #ifndef AIBOBJ_CONTEXT_READY
struct BaseObject {
    virtual ~BaseObject();
    BaseObject* next;  // +0x04
    BaseObject* prev;  // +0x08
    int numberGroupsValue; // +0x0C
    int* groupIDValue;     // +0x10
    int categoryIDValue;   // +0x14
    int typeIDValue;       // +0x18
    int gameIDValue;       // +0x1C
    char nameValue[64];    // +0x20
    float xPositionValue;  // +0x60
    float yPositionValue;  // +0x64
    float zPositionValue;  // +0x68
    float xSizeValue;      // +0x6C
    float ySizeValue;      // +0x70
    float zSizeValue;      // +0x74
    int hitPointValue;     // +0x78
    int minHitPointValue;  // +0x7C
    int maxHitPointValue;  // +0x80
    int busyValue;         // +0x84
    int currentTaskValue;  // +0x88
    int currentTargetValue;// +0x8C
    int currentTargetTypeValue; // +0x90
    float currentTargetXPositionValue; // +0x94
    float currentTargetYPositionValue; // +0x98
    float currentTargetZPositionValue; // +0x9C

    BaseObject(int a, int category, int type, int game, char* name,
        float xSize, float ySize, float zSize,
        float xPos, float yPos, float zPos,
        int hitPt, int minHit, int maxHit);
};
#endif

BaseObject::BaseObject(int a, int category, int type, int game, char* name,
    float xSize, float ySize, float zSize,
    float xPos, float yPos, float zPos,
    int hitPt, int minHit, int maxHit)
{
    next = 0;
    prev = 0;
    categoryIDValue = category;
    typeIDValue = type;
    gameIDValue = game;
    xPositionValue = xPos;
    yPositionValue = yPos;
    zPositionValue = zPos;
    xSizeValue = xSize;
    ySizeValue = ySize;
    zSizeValue = zSize;
    hitPointValue = hitPt;
    minHitPointValue = minHit;
    numberGroupsValue = 1;
    maxHitPointValue = maxHit;
    busyValue = 0;
    currentTaskValue = -1;
    currentTargetValue = -1;
    currentTargetTypeValue = -1;
    currentTargetXPositionValue = 0;
    currentTargetYPositionValue = 0;
    currentTargetZPositionValue = 0;
    groupIDValue = new int;
    groupIDValue[0] = a;

    strncpy(nameValue, name, 63);
}
