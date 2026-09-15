#include "../include/aiconitm.h"

ConstructionItem::ConstructionItem() : BaseItem() {
    this->next = 0;
    this->prev = 0;
    this->inProgressValue = 0;
    this->builtValue = 0;
    this->buildAttemptsValue = 0;
}

ConstructionItem::ConstructionItem(float x, float y, float z, float xs,
                                   float ys, float zs, int ti, char* n)
    : BaseItem(ti, -1, -1, n, x, y, z, xs, ys, zs) {
    this->next = 0;
    this->prev = 0;
    this->inProgressValue = 0;
    this->builtValue = 0;
    this->buildAttemptsValue = 0;
}

ConstructionItem::ConstructionItem(ConstructionItem* ci)
    : BaseItem(ci),
      next(0),
      prev(0),
      inProgressValue(ci->inProgressValue),
      builtValue(ci->builtValue),
      buildAttemptsValue(ci->buildAttemptsValue) {}

ConstructionItem::ConstructionItem(const ConstructionItem& ci)
    : BaseItem(ci),
      next(0),
      prev(0),
      inProgressValue(ci.inProgressValue),
      builtValue(ci.builtValue),
      buildAttemptsValue(ci.buildAttemptsValue) {}

ConstructionItem::~ConstructionItem() {
}

int __cdecl operator==(const ConstructionItem& one, const ConstructionItem& two) {
    if (one.xValue == two.xValue && one.yValue == two.yValue) {
        return 1;
    }
    return 0;
}

int __cdecl operator!=(const ConstructionItem& one, const ConstructionItem& two) {
    if (one.xValue == two.xValue && one.yValue == two.yValue) {
        return 0;
    }
    return 1;
}

int __cdecl operator<(const ConstructionItem& one, const ConstructionItem& two) {
    return one.typeIDValue < two.typeIDValue;
}

int __cdecl operator>(const ConstructionItem& one, const ConstructionItem& two) {
    return one.typeIDValue > two.typeIDValue;
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

void ConstructionItem::setInProgress(int p) {
    this->inProgressValue = p;
}

void ConstructionItem::setBuilt(int b) {
    this->builtValue = b;
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

void ConstructionItem::setBuildAttempts(int v) {
    this->buildAttemptsValue = v;
}
