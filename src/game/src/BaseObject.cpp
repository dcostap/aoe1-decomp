#include "../include/BaseObject.h"

#include <new>
#include <string.h>

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x00409FA0
BaseObject::BaseObject() {
    this->next = nullptr;
    this->prev = nullptr;
    this->numberGroupsValue = 0;
    this->groupIDValue = nullptr;
    this->categoryIDValue = -1;
    this->typeIDValue = -1;
    this->gameIDValue = -1;
    this->xPositionValue = -1.0f;
    this->yPositionValue = -1.0f;
    this->zPositionValue = -1.0f;
    this->xSizeValue = -1.0f;
    this->ySizeValue = -1.0f;
    this->zSizeValue = -1.0f;
    this->hitPointValue = 0;
    this->minHitPointValue = 0;
    this->maxHitPointValue = 0;
    this->busyValue = 0;
    this->currentTaskValue = -1;
    this->currentTargetValue = -1;
    this->currentTargetTypeValue = -1;
    this->currentTargetXPositionValue = 0.0f;
    this->currentTargetYPositionValue = 0.0f;
    this->currentTargetZPositionValue = 0.0f;
    this->nameValue[0] = '\0';
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A060
BaseObject::BaseObject(int param_1, int param_2, int param_3, int param_4, char* param_5, float param_6, float param_7, float param_8, float param_9, float param_10, float param_11, int param_12, int param_13, int param_14) {
    this->categoryIDValue = param_2;
    this->typeIDValue = param_3;
    this->gameIDValue = param_4;
    this->xPositionValue = param_9;
    this->yPositionValue = param_10;
    this->zPositionValue = param_11;
    this->xSizeValue = param_6;
    this->ySizeValue = param_7;
    this->zSizeValue = param_8;
    this->hitPointValue = param_12;
    this->minHitPointValue = param_13;
    this->next = nullptr;
    this->prev = nullptr;
    this->numberGroupsValue = 1;
    this->maxHitPointValue = param_14;
    this->busyValue = 0;
    this->currentTaskValue = -1;
    this->currentTargetValue = -1;
    this->currentTargetTypeValue = -1;
    this->currentTargetXPositionValue = 0.0f;
    this->currentTargetYPositionValue = 0.0f;
    this->currentTargetZPositionValue = 0.0f;
    this->groupIDValue = (int*)::operator new(4, std::nothrow);
    if (this->groupIDValue != nullptr) {
        *this->groupIDValue = param_1;
    }
    strncpy(this->nameValue, param_5, 0x3F);
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A130
BaseObject::BaseObject(BaseObject* param_1) {
    this->next = nullptr;
    this->prev = nullptr;
    this->numberGroupsValue = param_1->numberGroupsValue;
    this->categoryIDValue = param_1->categoryIDValue;
    this->typeIDValue = param_1->typeIDValue;
    this->gameIDValue = param_1->gameIDValue;
    this->xPositionValue = param_1->xPositionValue;
    this->yPositionValue = param_1->yPositionValue;
    this->zPositionValue = param_1->zPositionValue;
    this->xSizeValue = param_1->xSizeValue;
    this->ySizeValue = param_1->ySizeValue;
    this->zSizeValue = param_1->zSizeValue;
    this->hitPointValue = param_1->hitPointValue;
    this->minHitPointValue = param_1->minHitPointValue;
    this->maxHitPointValue = param_1->maxHitPointValue;
    this->busyValue = param_1->busyValue;
    this->currentTaskValue = param_1->currentTaskValue;
    this->currentTargetValue = param_1->currentTargetValue;
    this->currentTargetTypeValue = param_1->currentTargetTypeValue;
    this->currentTargetXPositionValue = param_1->currentTargetXPositionValue;
    this->currentTargetYPositionValue = param_1->currentTargetYPositionValue;
    this->currentTargetZPositionValue = param_1->currentTargetZPositionValue;
    this->groupIDValue = (int*)::operator new(this->numberGroupsValue << 2, std::nothrow);
    if (this->groupIDValue != nullptr) {
        int iVar3 = 0;
        if (0 < this->numberGroupsValue) {
            do {
                this->groupIDValue[iVar3] = param_1->groupIDValue[iVar3];
                iVar3 = iVar3 + 1;
            } while (iVar3 < this->numberGroupsValue);
        }
    }
    strncpy(this->nameValue, param_1->nameValue, 0x3F);
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A240
BaseObject::BaseObject(const BaseObject& param_1) {
    this->next = nullptr;
    this->prev = nullptr;
    this->numberGroupsValue = param_1.numberGroupsValue;
    this->categoryIDValue = param_1.categoryIDValue;
    this->typeIDValue = param_1.typeIDValue;
    this->gameIDValue = param_1.gameIDValue;
    this->xPositionValue = param_1.xPositionValue;
    this->yPositionValue = param_1.yPositionValue;
    this->zPositionValue = param_1.zPositionValue;
    this->xSizeValue = param_1.xSizeValue;
    this->ySizeValue = param_1.ySizeValue;
    this->zSizeValue = param_1.zSizeValue;
    this->hitPointValue = param_1.hitPointValue;
    this->minHitPointValue = param_1.minHitPointValue;
    this->maxHitPointValue = param_1.maxHitPointValue;
    this->busyValue = param_1.busyValue;
    this->currentTaskValue = param_1.currentTaskValue;
    this->currentTargetValue = param_1.currentTargetValue;
    this->currentTargetTypeValue = param_1.currentTargetTypeValue;
    this->currentTargetXPositionValue = param_1.currentTargetXPositionValue;
    this->currentTargetYPositionValue = param_1.currentTargetYPositionValue;
    this->currentTargetZPositionValue = param_1.currentTargetZPositionValue;
    this->groupIDValue = (int*)::operator new(this->numberGroupsValue << 2, std::nothrow);
    if (this->groupIDValue != nullptr) {
        int iVar3 = 0;
        if (0 < this->numberGroupsValue) {
            do {
                this->groupIDValue[iVar3] = param_1.groupIDValue[iVar3];
                iVar3 = iVar3 + 1;
            } while (iVar3 < this->numberGroupsValue);
        }
    }
    strncpy(this->nameValue, param_1.nameValue, 0x3F);
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A350
BaseObject::~BaseObject() {
    ::operator delete(this->groupIDValue);
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A370
int operator==(const BaseObject& param_1, const BaseObject& param_2) {
    return (uint)(param_1.gameIDValue == param_2.gameIDValue);
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A390
int operator!=(const BaseObject& param_1, const BaseObject& param_2) {
    return (uint)(param_1.gameIDValue != param_2.gameIDValue);
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A3B0
int operator<(const BaseObject& param_1, const BaseObject& param_2) {
    return (uint)(param_1.gameIDValue < param_2.gameIDValue);
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A3D0
int operator>(const BaseObject& param_1, const BaseObject& param_2) {
    return (uint)(param_2.gameIDValue < param_1.gameIDValue);
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A3F0
int BaseObject::numberGroups() const {
    return this->numberGroupsValue;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A400
int BaseObject::groupID(int param_1) const {
    if (((this->groupIDValue != nullptr) && (-1 < param_1)) && (param_1 < this->numberGroupsValue)) {
        return this->groupIDValue[param_1];
    }
    return -1;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A420
int BaseObject::inGroup(int param_1) const {
    int iVar1 = 0;
    if (this->numberGroupsValue < 1) {
        return 0;
    }
    int* piVar2 = this->groupIDValue;
    do {
        if (*piVar2 == param_1) {
            return 1;
        }
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 1;
    } while (iVar1 < this->numberGroupsValue);
    return 0;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A460
int BaseObject::addGroup(int param_1) {
    int iVar1 = inGroup(param_1);
    if (iVar1 != 0) {
        return 0;
    }
    int* piVar2 = (int*)::operator new(this->numberGroupsValue * 4 + 4, std::nothrow);
    if (piVar2 == nullptr) {
        return 0;
    }
    iVar1 = 0;
    if (0 < this->numberGroupsValue) {
        int iVar3;
        do {
            iVar3 = iVar1 + 1;
            piVar2[iVar1] = this->groupIDValue[iVar1];
            iVar1 = iVar3;
        } while (iVar3 < this->numberGroupsValue);
    }
    piVar2[this->numberGroupsValue] = param_1;
    this->numberGroupsValue = this->numberGroupsValue + 1;
    ::operator delete(this->groupIDValue);
    this->groupIDValue = piVar2;
    return 1;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A4E0
int BaseObject::removeGroup(int param_1) {
    int iVar1 = inGroup(param_1);
    if (iVar1 == 0) {
        return 0;
    }
    int* piVar2 = (int*)::operator new(this->numberGroupsValue * 4 - 4, std::nothrow);
    if (piVar2 != nullptr) {
        iVar1 = 0;
        int* piVar3 = piVar2;
        if (0 < this->numberGroupsValue) {
            do {
                if (this->groupIDValue[iVar1] != param_1) {
                    *piVar3 = this->groupIDValue[iVar1];
                    piVar3 = piVar3 + 1;
                }
                iVar1 = iVar1 + 1;
            } while (iVar1 < this->numberGroupsValue);
        }
        this->numberGroupsValue = this->numberGroupsValue - 1;
        ::operator delete(this->groupIDValue);
        this->groupIDValue = piVar2;
        return 1;
    }
    return 0;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A560
int BaseObject::categoryID() const {
    return this->categoryIDValue;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A570
int BaseObject::typeID() const {
    return this->typeIDValue;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A580
int const& BaseObject::gameID() const {
    return this->gameIDValue;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A590
char* BaseObject::name() {
    return this->nameValue;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A5A0
float BaseObject::xPosition() const {
    return this->xPositionValue;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A5B0
float BaseObject::yPosition() const {
    return this->yPositionValue;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A5C0
float BaseObject::zPosition() const {
    return this->zPositionValue;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A5D0
float BaseObject::xSize() const {
    return this->xSizeValue;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A5E0
float BaseObject::ySize() const {
    return this->ySizeValue;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A5F0
float BaseObject::zSize() const {
    return this->zSizeValue;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A600
int BaseObject::hitPoints() const {
    return this->hitPointValue;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A610
int BaseObject::minHitPoints() const {
    return this->minHitPointValue;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A620
int BaseObject::maxHitPoints() const {
    return this->maxHitPointValue;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A630
int BaseObject::busy() const {
    return this->busyValue;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A640
int BaseObject::currentTask() const {
    return this->currentTaskValue;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A650
int BaseObject::currentTarget() const {
    return this->currentTargetValue;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A660
int BaseObject::currentTargetType() const {
    return this->currentTargetTypeValue;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A670
float BaseObject::currentTargetXPosition() const {
    return this->currentTargetXPositionValue;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A680
float BaseObject::currentTargetYPosition() const {
    return this->currentTargetYPositionValue;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A690
float BaseObject::currentTargetZPosition() const {
    return this->currentTargetZPositionValue;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A6A0
void BaseObject::setXPosition(float param_1) {
    this->xPositionValue = param_1;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A6B0
void BaseObject::setYPosition(float param_1) {
    this->yPositionValue = param_1;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A6C0
void BaseObject::setZPosition(float param_1) {
    this->zPositionValue = param_1;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A6D0
void BaseObject::setXSize(float param_1) {
    this->xSizeValue = param_1;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A6E0
void BaseObject::setYSize(float param_1) {
    this->ySizeValue = param_1;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A6F0
void BaseObject::setZSize(float param_1) {
    this->zSizeValue = param_1;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A700
void BaseObject::setHitPoints(int param_1) {
    this->hitPointValue = param_1;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A710
void BaseObject::incrementHitPoints(int param_1) {
    this->hitPointValue = this->hitPointValue + param_1;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A720
void BaseObject::decrementHitPoints(int param_1) {
    this->hitPointValue = this->hitPointValue - param_1;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A730
void BaseObject::setMinHitPoints(int param_1) {
    this->minHitPointValue = param_1;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A740
void BaseObject::incrementMinHitPoints(int param_1) {
    this->minHitPointValue = this->minHitPointValue + param_1;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A750
void BaseObject::decrementMinHitPoints(int param_1) {
    this->minHitPointValue = this->minHitPointValue - param_1;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A760
void BaseObject::setMaxHitPoints(int param_1) {
    this->maxHitPointValue = param_1;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A770
void BaseObject::incrementMaxHitPoints(int param_1) {
    this->maxHitPointValue = this->maxHitPointValue + param_1;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A790
void BaseObject::decrementMaxHitPoints(int param_1) {
    this->maxHitPointValue = this->maxHitPointValue - param_1;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A7B0
void BaseObject::setBusy(int param_1) {
    this->busyValue = param_1;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A7C0
void BaseObject::setCurrentTask(int param_1) {
    this->currentTaskValue = param_1;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A7D0
void BaseObject::setCurrentTarget(int param_1) {
    this->currentTargetValue = param_1;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A7E0
void BaseObject::setCurrentTargetType(int param_1) {
    this->currentTargetTypeValue = param_1;
}

// Fully verified. Source of truth: aibobj.cpp.decomp @ 0x0040A7F0
void BaseObject::setCurrentTargetPosition(float param_1, float param_2, float param_3) {
    this->currentTargetXPositionValue = param_1;
    this->currentTargetYPositionValue = param_2;
    this->currentTargetZPositionValue = param_3;
}
