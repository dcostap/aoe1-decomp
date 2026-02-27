#include "../include/ConstructionItem.h"

#include "../include/BaseItem.h"

#include <string.h>

namespace {
BaseItem* construction_item_base(ConstructionItem* item) {
    return reinterpret_cast<BaseItem*>(item);
}

const BaseItem* construction_item_base(const ConstructionItem* item) {
    return reinterpret_cast<const BaseItem*>(item);
}

void init_base_item_default(BaseItem* item) {
    item->typeIDValue = -1;
    item->gameIDValue = -1;
    item->uniqueIDValue = -1;
    item->xValue = 0.0f;
    item->yValue = 0.0f;
    item->zValue = 0.0f;
    item->xSizeValue = 0.0f;
    item->ySizeValue = 0.0f;
    item->zSizeValue = 0.0f;
    item->skipValue = 0;
    item->nameValue[0] = '\0';
}

void init_base_item_params(BaseItem* item, int param_1, int param_2, int param_3, char* param_4, float param_5, float param_6, float param_7,
                           float param_8, float param_9, float param_10) {
    item->typeIDValue = param_1;
    item->gameIDValue = param_2;
    item->xValue = param_5;
    item->yValue = param_6;
    item->uniqueIDValue = param_3;
    item->xSizeValue = param_8;
    item->ySizeValue = param_9;
    item->zValue = param_7;
    item->zSizeValue = param_10;
    item->skipValue = 0;
    strncpy(item->nameValue, param_4, 0x3F);
}

void init_base_item_copy(BaseItem* item, const BaseItem* param_1) {
    item->typeIDValue = param_1->typeIDValue;
    item->gameIDValue = param_1->gameIDValue;
    item->uniqueIDValue = param_1->uniqueIDValue;
    item->xValue = param_1->xValue;
    item->yValue = param_1->yValue;
    item->zValue = param_1->zValue;
    item->xSizeValue = param_1->xSizeValue;
    item->ySizeValue = param_1->ySizeValue;
    item->zSizeValue = param_1->zSizeValue;
    item->skipValue = param_1->skipValue;
    strcpy(item->nameValue, param_1->nameValue);
}
}

// Fully verified. Source of truth: aiconitm.cpp.decomp @ 0x0040A820
ConstructionItem::ConstructionItem() {
    init_base_item_default(construction_item_base(this));
    this->next = nullptr;
    this->prev = nullptr;
    this->inProgressValue = 0;
    this->builtValue = 0;
    this->buildAttemptsValue = 0;
}

// Fully verified. Source of truth: aiconitm.cpp.decomp @ 0x0040A870
ConstructionItem::ConstructionItem(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, int param_7, char* param_8) {
    init_base_item_params(construction_item_base(this), param_7, -1, -1, param_8, param_1, param_2, param_3, param_4, param_5, param_6);
    this->next = nullptr;
    this->prev = nullptr;
    this->inProgressValue = 0;
    this->builtValue = 0;
    this->buildAttemptsValue = 0;
}

// Fully verified. Source of truth: aiconitm.cpp.decomp @ 0x0040A8D0
ConstructionItem::ConstructionItem(ConstructionItem* param_1) {
    init_base_item_copy(construction_item_base(this), construction_item_base(param_1));
    this->next = nullptr;
    this->prev = nullptr;
    this->inProgressValue = param_1->inProgressValue;
    this->builtValue = param_1->builtValue;
    this->buildAttemptsValue = param_1->buildAttemptsValue;
}

// Fully verified. Source of truth: aiconitm.cpp.decomp @ 0x0040A910
ConstructionItem::ConstructionItem(const ConstructionItem& param_1) {
    init_base_item_copy(construction_item_base(this), construction_item_base(&param_1));
    this->next = nullptr;
    this->prev = nullptr;
    this->inProgressValue = param_1.inProgressValue;
    this->builtValue = param_1.builtValue;
    this->buildAttemptsValue = param_1.buildAttemptsValue;
}

// Fully verified. Source of truth: aiconitm.cpp.decomp @ 0x0040A960
int operator==(const ConstructionItem& param_1, const ConstructionItem& param_2) {
    if ((construction_item_base(&param_1)->xValue == construction_item_base(&param_2)->xValue) &&
        (construction_item_base(&param_1)->yValue == construction_item_base(&param_2)->yValue)) {
        return 1;
    }
    return 0;
}

// Fully verified. Source of truth: aiconitm.cpp.decomp @ 0x0040A990
int operator!=(const ConstructionItem& param_1, const ConstructionItem& param_2) {
    if ((construction_item_base(&param_1)->xValue == construction_item_base(&param_2)->xValue) &&
        (construction_item_base(&param_1)->yValue == construction_item_base(&param_2)->yValue)) {
        return 0;
    }
    return 1;
}

// Fully verified. Source of truth: aiconitm.cpp.decomp @ 0x0040A9C0
int operator<(const ConstructionItem& param_1, const ConstructionItem& param_2) {
    return (uint)(construction_item_base(&param_1)->typeIDValue < construction_item_base(&param_2)->typeIDValue);
}

// Fully verified. Source of truth: aiconitm.cpp.decomp @ 0x0040A9E0
int operator>(const ConstructionItem& param_1, const ConstructionItem& param_2) {
    return (uint)(construction_item_base(&param_2)->typeIDValue < construction_item_base(&param_1)->typeIDValue);
}

// Fully verified. Source of truth: aiconitm.cpp.decomp @ 0x0040AA00
int ConstructionItem::inProgress() const {
    return this->inProgressValue;
}

// Fully verified. Source of truth: aiconitm.cpp.decomp @ 0x0040AA10
int ConstructionItem::built() const {
    return this->builtValue;
}

// Fully verified. Source of truth: aiconitm.cpp.decomp @ 0x0040AA20
int ConstructionItem::buildAttempts() const {
    return this->buildAttemptsValue;
}

// Fully verified. Source of truth: aiconitm.cpp.decomp @ 0x0040AA30
void ConstructionItem::setInProgress(int param_1) {
    this->inProgressValue = param_1;
}

// Fully verified. Source of truth: aiconitm.cpp.decomp @ 0x0040AA40
void ConstructionItem::setBuilt(int param_1) {
    this->builtValue = param_1;
}

// Fully verified. Source of truth: aiconitm.cpp.decomp @ 0x0040AA50
void ConstructionItem::incrementBuildAttempts() {
    this->buildAttemptsValue = this->buildAttemptsValue + 1;
}

// Fully verified. Source of truth: aiconitm.cpp.decomp @ 0x0040AA60
void ConstructionItem::decrementBuildAttempts() {
    int iVar1 = this->buildAttemptsValue - 1;
    this->buildAttemptsValue = iVar1;
    if (iVar1 < 0) {
        this->buildAttemptsValue = 0;
    }
}

// Fully verified. Source of truth: aiconitm.cpp.decomp @ 0x0040AA80
void ConstructionItem::setBuildAttempts(int param_1) {
    this->buildAttemptsValue = param_1;
}
