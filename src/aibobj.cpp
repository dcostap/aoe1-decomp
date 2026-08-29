// Authentic complete owner for C:\\msdev\\work\\age1_x1\\aibobj.cpp.

#include "../include/aibobj.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void* __cdecl operator new(size_t size);
void __cdecl operator delete(void* ptr);

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
    groupIDValue = new int[1];
    groupIDValue[0] = a;

    strncpy(nameValue, name, 63);
}

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
    groupIDValue = new int[numberGroupsValue];

    int i;
    for (i = 0; i < numberGroupsValue; i++)
        groupIDValue[i] = src->groupIDValue[i];

    strncpy(nameValue, src->nameValue, 63);
}

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
    groupIDValue = new int[numberGroupsValue];

    int i;
    for (i = 0; i < numberGroupsValue; i++)
        groupIDValue[i] = src.groupIDValue[i];

    strncpy(nameValue, src.nameValue, 63);
}

BaseObject::~BaseObject()
{
    delete[] groupIDValue;
}

int __cdecl operator==(const BaseObject& left, const BaseObject& right)
{
    return left.gameIDValue == right.gameIDValue;
}

int __cdecl operator!=(const BaseObject& left, const BaseObject& right)
{
    return left.gameIDValue != right.gameIDValue;
}

int __cdecl operator<(const BaseObject& left, const BaseObject& right)
{
    return left.gameIDValue < right.gameIDValue;
}

int __cdecl operator>(const BaseObject& left, const BaseObject& right)
{
    return left.gameIDValue > right.gameIDValue;
}

int BaseObject::numberGroups() const
{
    return this->numberGroupsValue;
}

int BaseObject::groupID(int index) const
{
    if (groupIDValue != 0 && index >= 0 && index < numberGroupsValue) {
        return groupIDValue[index];
    }
    return -1;
}

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

int BaseObject::addGroup(int group_id)
{
    if (inGroup(group_id))
        return 0;

    int* new_array = new int[numberGroupsValue + 1];
    if (!new_array)
        return 0;

    int i;
    for (i = 0; i < numberGroupsValue; i++)
        new_array[i] = groupIDValue[i];

    new_array[numberGroupsValue] = group_id;
    numberGroupsValue++;
    delete[] groupIDValue;
    groupIDValue = new_array;
    return 1;
}

int BaseObject::removeGroup(int group_id)
{
    if (!inGroup(group_id))
        return 0;

    int* new_array = new int[numberGroupsValue - 1];
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
    delete[] groupIDValue;
    groupIDValue = new_array;
    return 1;
}

int BaseObject::categoryID() const
{
    return this->categoryIDValue;
}

int BaseObject::typeID() const
{
    return this->typeIDValue;
}

const int& BaseObject::gameID() const
{
    return this->gameIDValue;
}

char* BaseObject::name()
{
    return this->nameValue;
}

float BaseObject::xPosition() const
{
    return this->xPositionValue;
}

float BaseObject::yPosition() const
{
    return this->yPositionValue;
}

float BaseObject::zPosition() const
{
    return this->zPositionValue;
}

float BaseObject::xSize() const
{
    return this->xSizeValue;
}

float BaseObject::ySize() const
{
    return this->ySizeValue;
}

float BaseObject::zSize() const
{
    return this->zSizeValue;
}

int BaseObject::hitPoints() const
{
    return this->hitPointValue;
}

int BaseObject::minHitPoints() const
{
    return this->minHitPointValue;
}

int BaseObject::maxHitPoints() const
{
    return this->maxHitPointValue;
}

int BaseObject::busy() const
{
    return this->busyValue;
}

int BaseObject::currentTask() const
{
    return this->currentTaskValue;
}

int BaseObject::currentTarget() const
{
    return this->currentTargetValue;
}

int BaseObject::currentTargetType() const
{
    return this->currentTargetTypeValue;
}

float BaseObject::currentTargetXPosition() const
{
    return this->currentTargetXPositionValue;
}

float BaseObject::currentTargetYPosition() const
{
    return this->currentTargetYPositionValue;
}

float BaseObject::currentTargetZPosition() const
{
    return this->currentTargetZPositionValue;
}

void BaseObject::setXPosition(float value)
{
    this->xPositionValue = value;
}

void BaseObject::setYPosition(float value)
{
    this->yPositionValue = value;
}

void BaseObject::setZPosition(float value)
{
    this->zPositionValue = value;
}

void BaseObject::setXSize(float value)
{
    this->xSizeValue = value;
}

void BaseObject::setYSize(float value)
{
    this->ySizeValue = value;
}

void BaseObject::setZSize(float value)
{
    this->zSizeValue = value;
}

void BaseObject::setHitPoints(int value)
{
    this->hitPointValue = value;
}

void BaseObject::incrementHitPoints(int value)
{
    this->hitPointValue += value;
}

void BaseObject::decrementHitPoints(int value)
{
    this->hitPointValue -= value;
}

void BaseObject::setMinHitPoints(int value)
{
    this->minHitPointValue = value;
}

void BaseObject::incrementMinHitPoints(int value)
{
    this->minHitPointValue += value;
}

void BaseObject::decrementMinHitPoints(int value)
{
    this->minHitPointValue -= value;
}

void BaseObject::setMaxHitPoints(int value)
{
    this->maxHitPointValue = value;
}

void BaseObject::incrementMaxHitPoints(int value)
{
    this->maxHitPointValue += value;
}

void BaseObject::decrementMaxHitPoints(int value)
{
    this->maxHitPointValue -= value;
}

void BaseObject::setBusy(int value)
{
    this->busyValue = value;
}

void BaseObject::setCurrentTask(int value)
{
    this->currentTaskValue = value;
}

void BaseObject::setCurrentTarget(int value)
{
    this->currentTargetValue = value;
}

void BaseObject::setCurrentTargetType(int value)
{
    this->currentTargetTypeValue = value;
}

void BaseObject::setCurrentTargetPosition(float a, float b, float c)
{
    this->currentTargetXPositionValue = a;
    this->currentTargetYPositionValue = b;
    this->currentTargetZPositionValue = c;
}
