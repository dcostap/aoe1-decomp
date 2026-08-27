#include "../include/aiconitm.h"

ConstructionItem::ConstructionItem() : BaseItem() {
    this->next = 0;
    this->prev = 0;
    this->inProgressValue = 0;
    this->builtValue = 0;
    this->buildAttemptsValue = 0;
}

ConstructionItem::ConstructionItem(float x, float y, float z, float xSize,
                                   float ySize, float zSize, int typeID,
                                   char* name)
    : BaseItem(typeID, -1, -1, name, x, y, z, xSize, ySize, zSize) {
    this->next = 0;
    this->prev = 0;
    this->inProgressValue = 0;
    this->builtValue = 0;
    this->buildAttemptsValue = 0;
}

ConstructionItem::ConstructionItem(ConstructionItem* other)
    : BaseItem(other),
      next(0),
      prev(0),
      inProgressValue(other->inProgressValue),
      builtValue(other->builtValue),
      buildAttemptsValue(other->buildAttemptsValue) {}

ConstructionItem::ConstructionItem(const ConstructionItem& other)
    : BaseItem(other),
      next(0),
      prev(0),
      inProgressValue(other.inProgressValue),
      builtValue(other.builtValue),
      buildAttemptsValue(other.buildAttemptsValue) {}

ConstructionItem::~ConstructionItem() {
}

int __cdecl operator==(const ConstructionItem& left,
                       const ConstructionItem& right) {
    if (left.xValue == right.xValue && left.yValue == right.yValue) {
        return 1;
    }
    return 0;
}

int __cdecl operator!=(const ConstructionItem& left,
                       const ConstructionItem& right) {
    if (left.xValue == right.xValue && left.yValue == right.yValue) {
        return 0;
    }
    return 1;
}

int __cdecl operator<(const ConstructionItem& left,
                      const ConstructionItem& right) {
    return left.typeIDValue < right.typeIDValue;
}

int __cdecl operator>(const ConstructionItem& left,
                      const ConstructionItem& right) {
    return left.typeIDValue > right.typeIDValue;
}

int ConstructionItem::inProgress() const {
    return this->inProgressValue;
}

int ConstructionItem::built() const {
    return this->builtValue;
}

int ConstructionItem::buildAttempts() const {
    return this->buildAttemptsValue;
}

void ConstructionItem::setInProgress(int value) {
    this->inProgressValue = value;
}

void ConstructionItem::setBuilt(int value) {
    this->builtValue = value;
}

void ConstructionItem::incrementBuildAttempts() {
    this->buildAttemptsValue++;
}

void ConstructionItem::decrementBuildAttempts() {
    this->buildAttemptsValue--;
    if (this->buildAttemptsValue < 0) {
        this->buildAttemptsValue = 0;
    }
}

void ConstructionItem::setBuildAttempts(int value) {
    this->buildAttemptsValue = value;
}
