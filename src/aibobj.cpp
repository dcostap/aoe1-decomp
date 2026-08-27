// Authentic complete owner for C:\\msdev\\work\\age1_x1\\aibobj.cpp.
// Normal owners stay in PDB source order.

#include "../include/aibobj.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void* __cdecl operator new(size_t size);

extern "C" {
    void* __cdecl operator_new(size_t size);
    void __cdecl operator_delete(void* ptr);
}

// VA: 00409FA0 BaseObject::BaseObject
// PDB source: aibobj.cpp lines 43-45.
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

// VA: 0040A060 BaseObject::BaseObject
// PDB source: aibobj.cpp lines 74-80.
BaseObject::BaseObject(int a, int category, int type, int game, char* name,
                       float xSize, float ySize, float zSize,
                       float xPos, float yPos, float zPos,
                       int hitPt, int minHit, int maxHit)
    : next(0), prev(0), numberGroupsValue(1),
      categoryIDValue(category), typeIDValue(type), gameIDValue(game),
      xPositionValue(xPos), yPositionValue(yPos), zPositionValue(zPos),
      xSizeValue(xSize), ySizeValue(ySize), zSizeValue(zSize),
      hitPointValue(hitPt), minHitPointValue(minHit), maxHitPointValue(maxHit),
      busyValue(0), currentTaskValue(-1), currentTargetValue(-1),
      currentTargetTypeValue(-1), currentTargetXPositionValue(0.0f),
      currentTargetYPositionValue(0.0f), currentTargetZPositionValue(0.0f)
{
    groupIDValue = new int;
    groupIDValue[0] = a;

    strncpy(nameValue, name, 63);
}

// VA: 0040A130 BaseObject::BaseObject
// PDB source: aibobj.cpp lines 107-114.
BaseObject::BaseObject(BaseObject* src)
    : next(0), prev(0),
      numberGroupsValue(src->numberGroupsValue),
      categoryIDValue(src->categoryIDValue), typeIDValue(src->typeIDValue),
      gameIDValue(src->gameIDValue),
      xPositionValue(src->xPositionValue), yPositionValue(src->yPositionValue),
      zPositionValue(src->zPositionValue), xSizeValue(src->xSizeValue),
      ySizeValue(src->ySizeValue), zSizeValue(src->zSizeValue),
      hitPointValue(src->hitPointValue), minHitPointValue(src->minHitPointValue),
      maxHitPointValue(src->maxHitPointValue), busyValue(src->busyValue),
      currentTaskValue(src->currentTaskValue), currentTargetValue(src->currentTargetValue),
      currentTargetTypeValue(src->currentTargetTypeValue),
      currentTargetXPositionValue(src->currentTargetXPositionValue),
      currentTargetYPositionValue(src->currentTargetYPositionValue),
      currentTargetZPositionValue(src->currentTargetZPositionValue)
{
    groupIDValue = (int*)operator_new(numberGroupsValue * 4);

    int i;
    for (i = 0; i < numberGroupsValue; i++)
        groupIDValue[i] = src->groupIDValue[i];

    strncpy(nameValue, src->nameValue, 63);
}

// VA: 0040A240 BaseObject::BaseObject
// PDB source: aibobj.cpp lines 141-148.
BaseObject::BaseObject(const BaseObject& src)
    : next(0), prev(0),
      numberGroupsValue(src.numberGroupsValue),
      categoryIDValue(src.categoryIDValue), typeIDValue(src.typeIDValue),
      gameIDValue(src.gameIDValue),
      xPositionValue(src.xPositionValue), yPositionValue(src.yPositionValue),
      zPositionValue(src.zPositionValue), xSizeValue(src.xSizeValue),
      ySizeValue(src.ySizeValue), zSizeValue(src.zSizeValue),
      hitPointValue(src.hitPointValue), minHitPointValue(src.minHitPointValue),
      maxHitPointValue(src.maxHitPointValue), busyValue(src.busyValue),
      currentTaskValue(src.currentTaskValue), currentTargetValue(src.currentTargetValue),
      currentTargetTypeValue(src.currentTargetTypeValue),
      currentTargetXPositionValue(src.currentTargetXPositionValue),
      currentTargetYPositionValue(src.currentTargetYPositionValue),
      currentTargetZPositionValue(src.currentTargetZPositionValue)
{
    groupIDValue = (int*)operator_new(numberGroupsValue * 4);

    int i;
    for (i = 0; i < numberGroupsValue; i++)
        groupIDValue[i] = src.groupIDValue[i];

    strncpy(nameValue, src.nameValue, 63);
}

// VA: 0040A350 BaseObject::~BaseObject
// PDB source: aibobj.cpp lines 153-155.
BaseObject::~BaseObject()
{
    operator_delete(groupIDValue);
}

// VA: 0040A370 operator==
// PDB source: aibobj.cpp lines 160-164.
int __cdecl operator==(const BaseObject& left, const BaseObject& right)
{
    return left.gameIDValue == right.gameIDValue;
}

// VA: 0040A390 operator!=
// PDB source: aibobj.cpp lines 169-173.
int __cdecl operator!=(const BaseObject& left, const BaseObject& right)
{
    return left.gameIDValue != right.gameIDValue;
}

// VA: 0040A3B0 operator<
// PDB source: aibobj.cpp lines 178-182.
int __cdecl operator<(const BaseObject& left, const BaseObject& right)
{
    return left.gameIDValue < right.gameIDValue;
}

// VA: 0040A3D0 operator>
// PDB source: aibobj.cpp lines 187-191.
int __cdecl operator>(const BaseObject& left, const BaseObject& right)
{
    return left.gameIDValue > right.gameIDValue;
}

// VA: 0040A3F0 BaseObject::numberGroups
// PDB source: aibobj.cpp lines 196-198.
int BaseObject::numberGroups() const
{
    return this->numberGroupsValue;
}

// VA: 0040A400 BaseObject::groupID
// PDB source: aibobj.cpp lines 203-207.
int BaseObject::groupID(int index) const
{
    if (groupIDValue != 0 && index >= 0 && index < numberGroupsValue) {
        return groupIDValue[index];
    }
    return -1;
}

// VA: 0040A420 BaseObject::inGroup
// PDB source: aibobj.cpp lines 212-217.
int BaseObject::inGroup(int groupId) const
{
    int n = this->numberGroupsValue;
    int i = 0;
    while (i < n) {
        if (this->groupIDValue[i] == groupId) return 1;
        i++;
    }
    return 0;
}

// VA: 0040A460 BaseObject::addGroup
// PDB source: aibobj.cpp lines 222-239.
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

// VA: 0040A4E0 BaseObject::removeGroup
// PDB source: aibobj.cpp lines 244-262.
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

// VA: 0040A560 BaseObject::categoryID
// PDB source: aibobj.cpp lines 267-269.
int BaseObject::categoryID() const
{
    return this->categoryIDValue;
}

// VA: 0040A570 BaseObject::typeID
// PDB source: aibobj.cpp lines 274-276.
int BaseObject::typeID() const
{
    return this->typeIDValue;
}

// VA: 0040A580 BaseObject::gameID
// PDB source: aibobj.cpp lines 281-283.
const int& BaseObject::gameID() const
{
    return this->gameIDValue;
}

// VA: 0040A590 BaseObject::name
// PDB source: aibobj.cpp lines 288-290.
char* BaseObject::name()
{
    return this->nameValue;
}

// VA: 0040A5A0 BaseObject::xPosition
// PDB source: aibobj.cpp lines 295-297.
float BaseObject::xPosition() const
{
    return this->xPositionValue;
}

// VA: 0040A5B0 BaseObject::yPosition
// PDB source: aibobj.cpp lines 302-304.
float BaseObject::yPosition() const
{
    return this->yPositionValue;
}

// VA: 0040A5C0 BaseObject::zPosition
// PDB source: aibobj.cpp lines 309-311.
float BaseObject::zPosition() const
{
    return this->zPositionValue;
}

// VA: 0040A5D0 BaseObject::xSize
// PDB source: aibobj.cpp lines 316-318.
float BaseObject::xSize() const
{
    return this->xSizeValue;
}

// VA: 0040A5E0 BaseObject::ySize
// PDB source: aibobj.cpp lines 323-325.
float BaseObject::ySize() const
{
    return this->ySizeValue;
}

// VA: 0040A5F0 BaseObject::zSize
// PDB source: aibobj.cpp lines 330-332.
float BaseObject::zSize() const
{
    return this->zSizeValue;
}

// VA: 0040A600 BaseObject::hitPoints
// PDB source: aibobj.cpp lines 337-339.
int BaseObject::hitPoints() const
{
    return this->hitPointValue;
}

// VA: 0040A610 BaseObject::minHitPoints
// PDB source: aibobj.cpp lines 344-346.
int BaseObject::minHitPoints() const
{
    return this->minHitPointValue;
}

// VA: 0040A620 BaseObject::maxHitPoints
// PDB source: aibobj.cpp lines 351-353.
int BaseObject::maxHitPoints() const
{
    return this->maxHitPointValue;
}

// VA: 0040A630 BaseObject::busy
// PDB source: aibobj.cpp lines 358-360.
int BaseObject::busy() const
{
    return this->busyValue;
}

// VA: 0040A640 BaseObject::currentTask
// PDB source: aibobj.cpp lines 365-367.
int BaseObject::currentTask() const
{
    return this->currentTaskValue;
}

// VA: 0040A650 BaseObject::currentTarget
// PDB source: aibobj.cpp lines 372-374.
int BaseObject::currentTarget() const
{
    return this->currentTargetValue;
}

// VA: 0040A660 BaseObject::currentTargetType
// PDB source: aibobj.cpp lines 379-381.
int BaseObject::currentTargetType() const
{
    return this->currentTargetTypeValue;
}

// VA: 0040A670 BaseObject::currentTargetXPosition
// PDB source: aibobj.cpp lines 386-388.
float BaseObject::currentTargetXPosition() const
{
    return this->currentTargetXPositionValue;
}

// VA: 0040A680 BaseObject::currentTargetYPosition
// PDB source: aibobj.cpp lines 393-395.
float BaseObject::currentTargetYPosition() const
{
    return this->currentTargetYPositionValue;
}

// VA: 0040A690 BaseObject::currentTargetZPosition
// PDB source: aibobj.cpp lines 400-402.
float BaseObject::currentTargetZPosition() const
{
    return this->currentTargetZPositionValue;
}

// VA: 0040A6A0 BaseObject::setXPosition
// PDB source: aibobj.cpp lines 407-409.
void BaseObject::setXPosition(float value)
{
    this->xPositionValue = value;
}

// VA: 0040A6B0 BaseObject::setYPosition
// PDB source: aibobj.cpp lines 414-416.
void BaseObject::setYPosition(float value)
{
    this->yPositionValue = value;
}

// VA: 0040A6C0 BaseObject::setZPosition
// PDB source: aibobj.cpp lines 421-423.
void BaseObject::setZPosition(float value)
{
    this->zPositionValue = value;
}

// VA: 0040A6D0 BaseObject::setXSize
// PDB source: aibobj.cpp lines 428-430.
void BaseObject::setXSize(float value)
{
    this->xSizeValue = value;
}

// VA: 0040A6E0 BaseObject::setYSize
// PDB source: aibobj.cpp lines 435-437.
void BaseObject::setYSize(float value)
{
    this->ySizeValue = value;
}

// VA: 0040A6F0 BaseObject::setZSize
// PDB source: aibobj.cpp lines 442-444.
void BaseObject::setZSize(float value)
{
    this->zSizeValue = value;
}

// VA: 0040A700 BaseObject::setHitPoints
// PDB source: aibobj.cpp lines 449-451.
void BaseObject::setHitPoints(int value)
{
    this->hitPointValue = value;
}

// VA: 0040A710 BaseObject::incrementHitPoints
// PDB source: aibobj.cpp lines 456-458.
void BaseObject::incrementHitPoints(int value)
{
    this->hitPointValue += value;
}

// VA: 0040A720 BaseObject::decrementHitPoints
// PDB source: aibobj.cpp lines 463-465.
void BaseObject::decrementHitPoints(int value)
{
    this->hitPointValue -= value;
}

// VA: 0040A730 BaseObject::setMinHitPoints
// PDB source: aibobj.cpp lines 470-472.
void BaseObject::setMinHitPoints(int value)
{
    this->minHitPointValue = value;
}

// VA: 0040A740 BaseObject::incrementMinHitPoints
// PDB source: aibobj.cpp lines 477-479.
void BaseObject::incrementMinHitPoints(int value)
{
    this->minHitPointValue += value;
}

// VA: 0040A750 BaseObject::decrementMinHitPoints
// PDB source: aibobj.cpp lines 484-486.
void BaseObject::decrementMinHitPoints(int value)
{
    this->minHitPointValue -= value;
}

// VA: 0040A760 BaseObject::setMaxHitPoints
// PDB source: aibobj.cpp lines 491-493.
void BaseObject::setMaxHitPoints(int value)
{
    this->maxHitPointValue = value;
}

// VA: 0040A770 BaseObject::incrementMaxHitPoints
// PDB source: aibobj.cpp lines 498-500.
void BaseObject::incrementMaxHitPoints(int value)
{
    this->maxHitPointValue += value;
}

// VA: 0040A790 BaseObject::decrementMaxHitPoints
// PDB source: aibobj.cpp lines 505-507.
void BaseObject::decrementMaxHitPoints(int value)
{
    this->maxHitPointValue -= value;
}

// VA: 0040A7B0 BaseObject::setBusy
// PDB source: aibobj.cpp lines 512-514.
void BaseObject::setBusy(int value)
{
    this->busyValue = value;
}

// VA: 0040A7C0 BaseObject::setCurrentTask
// PDB source: aibobj.cpp lines 519-521.
void BaseObject::setCurrentTask(int value)
{
    this->currentTaskValue = value;
}

// VA: 0040A7D0 BaseObject::setCurrentTarget
// PDB source: aibobj.cpp lines 526-528.
void BaseObject::setCurrentTarget(int value)
{
    this->currentTargetValue = value;
}

// VA: 0040A7E0 BaseObject::setCurrentTargetType
// PDB source: aibobj.cpp lines 533-535.
void BaseObject::setCurrentTargetType(int value)
{
    this->currentTargetTypeValue = value;
}

// VA: 0040A7F0 BaseObject::setCurrentTargetPosition
// PDB source: aibobj.cpp lines 540-544.
void BaseObject::setCurrentTargetPosition(float a, float b, float c)
{
    this->currentTargetXPositionValue = a;
    this->currentTargetYPositionValue = b;
    this->currentTargetZPositionValue = c;
}
