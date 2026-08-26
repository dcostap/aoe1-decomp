// VA: 00409FA0 BaseObject::BaseObject (default constructor)
// PDB source: aibobj.cpp

#include <string.h>

#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    class BaseObject* next;  // +0x04
    class BaseObject* prev;  // +0x08
    int numberGroupsValue;   // +0x0C
    int* groupIDValue;       // +0x10
    int categoryIDValue;     // +0x14
    int typeIDValue;         // +0x18
    int gameIDValue;         // +0x1C
    char nameValue[64];      // +0x20 (0x40 bytes = space for a name)
    float xPositionValue;    // +0x60
    float yPositionValue;    // +0x64
    float zPositionValue;    // +0x68
    float xSizeValue;        // +0x6C
    float ySizeValue;        // +0x70
    float zSizeValue;        // +0x74
    int hitPointValue;       // +0x78
    int minHitPointValue;    // +0x7C
    int maxHitPointValue;    // +0x80
    int busyValue;           // +0x84
    int currentTaskValue;    // +0x88
    int currentTargetValue;  // +0x8C
    int currentTargetTypeValue; // +0x90
    float currentTargetXPositionValue; // +0x94
    float currentTargetYPositionValue; // +0x98
    float currentTargetZPositionValue; // +0x9C

    BaseObject();
};
#endif

BaseObject::BaseObject()
    : next(0), prev(0),
      numberGroupsValue(0), groupIDValue(0),
      categoryIDValue(-1), typeIDValue(-1), gameIDValue(-1),
      xPositionValue(-1.0f), yPositionValue(-1.0f), zPositionValue(-1.0f),
      xSizeValue(-1.0f), ySizeValue(-1.0f), zSizeValue(-1.0f),
      hitPointValue(0), minHitPointValue(0), maxHitPointValue(0),
      busyValue(0), currentTaskValue(-1), currentTargetValue(-1),
      currentTargetTypeValue(-1), currentTargetXPositionValue(0.0f),
      currentTargetYPositionValue(0.0f), currentTargetZPositionValue(0.0f)
{
    strcpy(nameValue, "");
}
