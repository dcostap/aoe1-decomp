#include "../include/BuildItem.h"

#include "../include/BaseItem.h"

#include <string.h>

namespace {
BaseItem* build_item_base(BuildItem* item) {
    return reinterpret_cast<BaseItem*>(item);
}

const BaseItem* build_item_base(const BuildItem* item) {
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

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x00408190
BuildItem::BuildItem() {
    init_base_item_default(build_item_base(this));
    this->next = nullptr;
    this->prev = nullptr;
    this->numberValue = 0;
    this->priorityValue = 0;
    this->progressValue = 0;
    this->builtValue = 0;
    this->buildAttemptsValue = 0;
    this->placeOnElevationValue = 0;
    this->numberBuildsValue = 0;
    this->skipCyclesValue = 0;
    this->permanentSkipValue = '\0';
    this->buildCategoryValue = -1;
    this->buildFromValue = -1;
    this->terrainSetValue = -1;
    this->buildCapValue = -1;
    this->terrainAdjacencyValue[0] = -1;
    this->terrainAdjacencyValue[1] = -1;
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x00408220
BuildItem::BuildItem(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, char* param_7, float param_8, float param_9, float param_10,
                     int param_11, int param_12, int param_13, int param_14) {
    init_base_item_params(build_item_base(this), param_2, -1, param_3, param_7, -1.0f, -1.0f, -1.0f, param_8, param_9, param_10);
    this->buildCategoryValue = param_1;
    this->numberValue = param_4;
    this->priorityValue = param_5;
    this->next = nullptr;
    this->prev = nullptr;
    this->progressValue = 0;
    this->builtValue = 0;
    this->buildAttemptsValue = 0;
    this->numberBuildsValue = 0;
    this->skipCyclesValue = 0;
    this->permanentSkipValue = '\0';
    this->buildFromValue = param_6;
    this->terrainSetValue = param_11;
    this->terrainAdjacencyValue[0] = param_12;
    this->placeOnElevationValue = param_14;
    this->buildCapValue = -1;
    this->terrainAdjacencyValue[1] = param_13;
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x004082F0
BuildItem::BuildItem(BuildItem* param_1) {
    init_base_item_copy(build_item_base(this), build_item_base(param_1));
    this->next = nullptr;
    this->prev = nullptr;
    this->buildCategoryValue = param_1->buildCategoryValue;
    this->numberValue = param_1->numberValue;
    this->priorityValue = param_1->priorityValue;
    this->progressValue = param_1->progressValue;
    this->builtValue = param_1->progressValue;
    this->buildAttemptsValue = param_1->buildAttemptsValue;
    this->buildFromValue = param_1->buildFromValue;
    this->terrainSetValue = param_1->terrainSetValue;
    this->placeOnElevationValue = param_1->placeOnElevationValue;
    this->numberBuildsValue = 0;
    this->buildCapValue = -1;
    this->skipCyclesValue = 0;
    this->permanentSkipValue = '\0';
    this->terrainAdjacencyValue[0] = param_1->terrainAdjacencyValue[0];
    this->terrainAdjacencyValue[1] = param_1->terrainAdjacencyValue[1];
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x004083B0
BuildItem::BuildItem(const BuildItem& param_1) {
    init_base_item_copy(build_item_base(this), build_item_base(&param_1));
    this->next = nullptr;
    this->prev = nullptr;
    this->buildCategoryValue = param_1.buildCategoryValue;
    this->numberValue = param_1.numberValue;
    this->priorityValue = param_1.priorityValue;
    this->progressValue = param_1.progressValue;
    this->builtValue = param_1.progressValue;
    this->buildAttemptsValue = param_1.buildAttemptsValue;
    this->buildFromValue = param_1.buildFromValue;
    this->terrainSetValue = param_1.terrainSetValue;
    this->placeOnElevationValue = param_1.placeOnElevationValue;
    this->numberBuildsValue = 0;
    this->buildCapValue = -1;
    this->skipCyclesValue = 0;
    this->permanentSkipValue = '\0';
    this->terrainAdjacencyValue[0] = param_1.terrainAdjacencyValue[0];
    this->terrainAdjacencyValue[1] = param_1.terrainAdjacencyValue[1];
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x00408480
int operator==(const BuildItem& param_1, const BuildItem& param_2) {
    return (uint)(build_item_base(&param_1)->typeIDValue == build_item_base(&param_2)->typeIDValue);
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x004084A0
int operator!=(const BuildItem& param_1, const BuildItem& param_2) {
    return (uint)(build_item_base(&param_1)->typeIDValue != build_item_base(&param_2)->typeIDValue);
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x004084C0
int operator<(const BuildItem& param_1, const BuildItem& param_2) {
    return (uint)(build_item_base(&param_1)->typeIDValue < build_item_base(&param_2)->typeIDValue);
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x004084E0
int operator>(const BuildItem& param_1, const BuildItem& param_2) {
    return (uint)(build_item_base(&param_2)->typeIDValue < build_item_base(&param_1)->typeIDValue);
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x00408500
int BuildItem::buildCategory() const {
    return this->buildCategoryValue;
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x00408510
int BuildItem::number() const {
    return this->numberValue;
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x00408520
int BuildItem::priority() const {
    return this->priorityValue;
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x00408530
int BuildItem::inProgress() const {
    return this->progressValue;
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x00408540
int BuildItem::built() const {
    return this->builtValue;
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x00408550
int BuildItem::buildAttempts() const {
    return this->buildAttemptsValue;
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x00408560
int BuildItem::buildFrom() const {
    return this->buildFromValue;
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x00408570
int BuildItem::terrainSet() const {
    return this->terrainSetValue;
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x00408580
int BuildItem::terrainAdjacency(int param_1) const {
    if ((0 < param_1) && (param_1 < 3)) {
        return this->terrainAdjacencyValue[param_1 - 1];
    }
    return -1;
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x004085A0
int BuildItem::placeOnElevation() const {
    return this->placeOnElevationValue;
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x004085B0
void BuildItem::setInProgress(int param_1) {
    this->progressValue = param_1;
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x004085C0
void BuildItem::setBuilt(int param_1) {
    this->builtValue = param_1;
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x004085D0
void BuildItem::setBuildAttempts(int param_1) {
    this->buildAttemptsValue = param_1;
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x004085E0
void BuildItem::incrementBuildAttempts() {
    this->buildAttemptsValue = this->buildAttemptsValue + 1;
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x004085F0
void BuildItem::decrementBuildAttempts() {
    int iVar1 = this->buildAttemptsValue - 1;
    this->buildAttemptsValue = iVar1;
    if (iVar1 < 0) {
        this->buildAttemptsValue = 0;
    }
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x00408610
int BuildItem::numberBuilds() {
    return this->numberBuildsValue;
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x00408620
void BuildItem::incrementNumberBuilds() {
    this->numberBuildsValue = this->numberBuildsValue + 1;
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x00408630
void BuildItem::setNumberBuilds(int param_1) {
    this->numberBuildsValue = param_1;
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x00408640
int BuildItem::buildCap() {
    return this->buildCapValue;
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x00408650
void BuildItem::setBuildCap(int param_1) {
    this->buildCapValue = param_1;
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x00408660
int BuildItem::skipCycles() {
    return this->skipCyclesValue;
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x00408670
void BuildItem::incrementSkipCycles() {
    this->skipCyclesValue = this->skipCyclesValue + 1;
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x00408680
void BuildItem::setSkipCycles(int param_1) {
    this->skipCyclesValue = param_1;
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x00408690
uchar BuildItem::permanentSkip() {
    return this->permanentSkipValue;
}

// Fully verified. Source of truth: aiblditm.cpp.decomp @ 0x004086A0
void BuildItem::setPermanentSkip(uchar param_1) {
    this->permanentSkipValue = param_1;
}
