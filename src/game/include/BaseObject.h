#pragma once
#include "common.h"

class BaseObject {
public:
    // Virtuals (best-effort)
    virtual ~BaseObject(); // vt[0] (0x0)

    BaseObject* next;
    BaseObject* prev;
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
};
static_assert(sizeof(BaseObject) == 0xA0, "Size mismatch");
