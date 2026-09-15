
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
      currentTargetYPositionValue(0.0f), currentTargetZPositionValue(0.0f) {
    strcpy(nameValue, "");
}

BaseObject::BaseObject(int gri, int ci, int ti, int gi, char* nm, float xs, float ys, float zs, float xp, float yp, float zp, int hp, int minp, int maxp)
    : next(0), prev(0), numberGroupsValue(1),
      categoryIDValue(ci), typeIDValue(ti), gameIDValue(gi),
      xPositionValue(xp), yPositionValue(yp), zPositionValue(zp),
      xSizeValue(xs), ySizeValue(ys), zSizeValue(zs),
      hitPointValue(hp), minHitPointValue(minp), maxHitPointValue(maxp),
      busyValue(0), currentTaskValue(-1), currentTargetValue(-1),
      currentTargetTypeValue(-1), currentTargetXPositionValue(0.0f),
      currentTargetYPositionValue(0.0f), currentTargetZPositionValue(0.0f) {
    groupIDValue = new int[1];
    groupIDValue[0] = gri;

    strncpy(nameValue, nm, 63);
}

BaseObject::BaseObject(BaseObject* bo)
    : next(0), prev(0),
      numberGroupsValue(bo->numberGroupsValue),
      categoryIDValue(bo->categoryIDValue), typeIDValue(bo->typeIDValue),
      gameIDValue(bo->gameIDValue),
      xPositionValue(bo->xPositionValue), yPositionValue(bo->yPositionValue),
      zPositionValue(bo->zPositionValue), xSizeValue(bo->xSizeValue),
      ySizeValue(bo->ySizeValue), zSizeValue(bo->zSizeValue),
      hitPointValue(bo->hitPointValue), minHitPointValue(bo->minHitPointValue),
      maxHitPointValue(bo->maxHitPointValue), busyValue(bo->busyValue),
      currentTaskValue(bo->currentTaskValue), currentTargetValue(bo->currentTargetValue),
      currentTargetTypeValue(bo->currentTargetTypeValue),
      currentTargetXPositionValue(bo->currentTargetXPositionValue),
      currentTargetYPositionValue(bo->currentTargetYPositionValue),
      currentTargetZPositionValue(bo->currentTargetZPositionValue) {
    groupIDValue = new int[numberGroupsValue];

    int i;
    for (i = 0; i < numberGroupsValue; i++)
        groupIDValue[i] = bo->groupIDValue[i];

    strncpy(nameValue, bo->nameValue, 63);
}

BaseObject::BaseObject(const BaseObject& bo)
    : next(0), prev(0),
      numberGroupsValue(bo.numberGroupsValue),
      categoryIDValue(bo.categoryIDValue), typeIDValue(bo.typeIDValue),
      gameIDValue(bo.gameIDValue),
      xPositionValue(bo.xPositionValue), yPositionValue(bo.yPositionValue),
      zPositionValue(bo.zPositionValue), xSizeValue(bo.xSizeValue),
      ySizeValue(bo.ySizeValue), zSizeValue(bo.zSizeValue),
      hitPointValue(bo.hitPointValue), minHitPointValue(bo.minHitPointValue),
      maxHitPointValue(bo.maxHitPointValue), busyValue(bo.busyValue),
      currentTaskValue(bo.currentTaskValue), currentTargetValue(bo.currentTargetValue),
      currentTargetTypeValue(bo.currentTargetTypeValue),
      currentTargetXPositionValue(bo.currentTargetXPositionValue),
      currentTargetYPositionValue(bo.currentTargetYPositionValue),
      currentTargetZPositionValue(bo.currentTargetZPositionValue) {
    groupIDValue = new int[numberGroupsValue];

    int i;
    for (i = 0; i < numberGroupsValue; i++)
        groupIDValue[i] = bo.groupIDValue[i];

    strncpy(nameValue, bo.nameValue, 63);
}

BaseObject::~BaseObject() {
    delete[] groupIDValue;
}

int __cdecl operator==(const BaseObject& one, const BaseObject& two) {
    return one.gameIDValue == two.gameIDValue;
}

int __cdecl operator!=(const BaseObject& one, const BaseObject& two) {
    return one.gameIDValue != two.gameIDValue;
}

int __cdecl operator<(const BaseObject& one, const BaseObject& two) {
    return one.gameIDValue < two.gameIDValue;
}

int __cdecl operator>(const BaseObject& one, const BaseObject& two) {
    return one.gameIDValue > two.gameIDValue;
}

int BaseObject::numberGroups() const {
    return this->numberGroupsValue;
}

int BaseObject::groupID(int v) const {
    if (groupIDValue != 0 && v >= 0 && v < numberGroupsValue) {
        return groupIDValue[v];
    }
    return -1;
}

int BaseObject::inGroup(int v) const {
    int n = this->numberGroupsValue;
    int i = 0;
    while (i < n) {
        if (this->groupIDValue[i] == v) return 1;
        i++;
    }
    return 0;
}

int BaseObject::addGroup(int v) {
    if (inGroup(v))
        return 0;

    int* new_array = new int[numberGroupsValue + 1];
    if (!new_array)
        return 0;

    int i;
    for (i = 0; i < numberGroupsValue; i++)
        new_array[i] = groupIDValue[i];

    new_array[numberGroupsValue] = v;
    numberGroupsValue++;
    delete[] groupIDValue;
    groupIDValue = new_array;
    return 1;
}

int BaseObject::removeGroup(int v) {
    if (!inGroup(v))
        return 0;

    int* new_array = new int[numberGroupsValue - 1];
    if (!new_array)
        return 0;

    int i = 0;
    if (numberGroupsValue > 0) {
        int* dst = new_array;
        do {
            if (groupIDValue[i] != v) {
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

int BaseObject::categoryID() const {
    return this->categoryIDValue;
}

int BaseObject::typeID() const {
    return this->typeIDValue;
}

const int& BaseObject::gameID() const {
    return this->gameIDValue;
}

char* BaseObject::name() {
    return this->nameValue;
}

float BaseObject::xPosition() const {
    return this->xPositionValue;
}

float BaseObject::yPosition() const {
    return this->yPositionValue;
}

float BaseObject::zPosition() const {
    return this->zPositionValue;
}

float BaseObject::xSize() const {
    return this->xSizeValue;
}

float BaseObject::ySize() const {
    return this->ySizeValue;
}

float BaseObject::zSize() const {
    return this->zSizeValue;
}

int BaseObject::hitPoints() const {
    return this->hitPointValue;
}

int BaseObject::minHitPoints() const {
    return this->minHitPointValue;
}

int BaseObject::maxHitPoints() const {
    return this->maxHitPointValue;
}

int BaseObject::busy() const {
    return this->busyValue;
}

int BaseObject::currentTask() const {
    return this->currentTaskValue;
}

int BaseObject::currentTarget() const {
    return this->currentTargetValue;
}

int BaseObject::currentTargetType() const {
    return this->currentTargetTypeValue;
}

float BaseObject::currentTargetXPosition() const {
    return this->currentTargetXPositionValue;
}

float BaseObject::currentTargetYPosition() const {
    return this->currentTargetYPositionValue;
}

float BaseObject::currentTargetZPosition() const {
    return this->currentTargetZPositionValue;
}

void BaseObject::setXPosition(float v) {
    this->xPositionValue = v;
}

void BaseObject::setYPosition(float v) {
    this->yPositionValue = v;
}

void BaseObject::setZPosition(float v) {
    this->zPositionValue = v;
}

void BaseObject::setXSize(float v) {
    this->xSizeValue = v;
}

void BaseObject::setYSize(float v) {
    this->ySizeValue = v;
}

void BaseObject::setZSize(float v) {
    this->zSizeValue = v;
}

void BaseObject::setHitPoints(int v) {
    this->hitPointValue = v;
}

void BaseObject::incrementHitPoints(int v) {
    this->hitPointValue += v;
}

void BaseObject::decrementHitPoints(int v) {
    this->hitPointValue -= v;
}

void BaseObject::setMinHitPoints(int v) {
    this->minHitPointValue = v;
}

void BaseObject::incrementMinHitPoints(int v) {
    this->minHitPointValue += v;
}

void BaseObject::decrementMinHitPoints(int v) {
    this->minHitPointValue -= v;
}

void BaseObject::setMaxHitPoints(int v) {
    this->maxHitPointValue = v;
}

void BaseObject::incrementMaxHitPoints(int v) {
    this->maxHitPointValue += v;
}

void BaseObject::decrementMaxHitPoints(int v) {
    this->maxHitPointValue -= v;
}

void BaseObject::setBusy(int v) {
    this->busyValue = v;
}

void BaseObject::setCurrentTask(int v) {
    this->currentTaskValue = v;
}

void BaseObject::setCurrentTarget(int v) {
    this->currentTargetValue = v;
}

void BaseObject::setCurrentTargetType(int v) {
    this->currentTargetTypeValue = v;
}

void BaseObject::setCurrentTargetPosition(float x, float y, float z) {
    this->currentTargetXPositionValue = x;
    this->currentTargetYPositionValue = y;
    this->currentTargetZPositionValue = z;
}
