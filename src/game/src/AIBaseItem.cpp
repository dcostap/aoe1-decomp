#include "../include/BaseItem.h"

#include <string.h>

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x00407D80
BaseItem::BaseItem() {
    this->typeIDValue = -1;
    this->gameIDValue = -1;
    this->uniqueIDValue = -1;
    this->xValue = 0.0f;
    this->yValue = 0.0f;
    this->zValue = 0.0f;
    this->xSizeValue = 0.0f;
    this->ySizeValue = 0.0f;
    this->zSizeValue = 0.0f;
    this->skipValue = 0;
    this->nameValue[0] = '\0';
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x00407E00
BaseItem::BaseItem(int param_1, int param_2, int param_3, char* param_4, float param_5, float param_6, float param_7, float param_8, float param_9, float param_10) {
    this->typeIDValue = param_1;
    this->gameIDValue = param_2;
    this->xValue = param_5;
    this->yValue = param_6;
    this->uniqueIDValue = param_3;
    this->xSizeValue = param_8;
    this->ySizeValue = param_9;
    this->zValue = param_7;
    this->zSizeValue = param_10;
    this->skipValue = 0;
    strncpy(this->nameValue, param_4, 0x3F);
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x00407E70
BaseItem::BaseItem(BaseItem* param_1) {
    this->typeIDValue = param_1->typeIDValue;
    this->gameIDValue = param_1->gameIDValue;
    this->uniqueIDValue = param_1->uniqueIDValue;
    this->xValue = param_1->xValue;
    this->yValue = param_1->yValue;
    this->zValue = param_1->zValue;
    this->xSizeValue = param_1->xSizeValue;
    this->ySizeValue = param_1->ySizeValue;
    this->zSizeValue = param_1->zSizeValue;
    this->skipValue = param_1->skipValue;
    strcpy(this->nameValue, param_1->nameValue);
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x00407EF0
BaseItem::BaseItem(const BaseItem& param_1) {
    this->typeIDValue = param_1.typeIDValue;
    this->gameIDValue = param_1.gameIDValue;
    this->uniqueIDValue = param_1.uniqueIDValue;
    this->xValue = param_1.xValue;
    this->yValue = param_1.yValue;
    this->zValue = param_1.zValue;
    this->xSizeValue = param_1.xSizeValue;
    this->ySizeValue = param_1.ySizeValue;
    this->zSizeValue = param_1.zSizeValue;
    this->skipValue = param_1.skipValue;
    strcpy(this->nameValue, param_1.nameValue);
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x00407F70
BaseItem::~BaseItem() {}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x00407F80
int operator==(const BaseItem& param_1, const BaseItem& param_2) {
    if (((param_1.gameIDValue == param_2.gameIDValue) && (param_1.xValue == param_2.xValue)) &&
        (param_1.yValue == param_2.yValue)) {
        return 1;
    }
    return 0;
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x00407FC0
int operator!=(const BaseItem& param_1, const BaseItem& param_2) {
    int iVar1 = operator==(param_1, param_2);
    return (uint)(iVar1 == 0);
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x00407FE0
int operator<(const BaseItem& param_1, const BaseItem& param_2) {
    return (uint)(param_1.gameIDValue < param_2.gameIDValue);
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x00408000
int operator>(const BaseItem& param_1, const BaseItem& param_2) {
    return (uint)(param_2.gameIDValue < param_1.gameIDValue);
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x00408020
int BaseItem::typeID() const {
    return this->typeIDValue;
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x00408030
int BaseItem::gameID() const {
    return this->gameIDValue;
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x00408040
int BaseItem::uniqueID() const {
    return this->uniqueIDValue;
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x00408050
char* BaseItem::name() {
    return this->nameValue;
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x00408060
float BaseItem::x() const {
    return this->xValue;
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x00408070
float BaseItem::y() const {
    return this->yValue;
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x00408080
float BaseItem::z() const {
    return this->zValue;
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x00408090
float BaseItem::xSize() const {
    return this->xSizeValue;
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x004080A0
float BaseItem::ySize() const {
    return this->ySizeValue;
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x004080B0
float BaseItem::zSize() const {
    return this->zSizeValue;
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x004080C0
int BaseItem::skip() const {
    return this->skipValue;
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x004080D0
void BaseItem::setTypeID(int param_1) {
    this->typeIDValue = param_1;
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x004080E0
void BaseItem::setGameID(int param_1) {
    this->gameIDValue = param_1;
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x004080F0
void BaseItem::setUniqueID(int param_1) {
    this->uniqueIDValue = param_1;
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x00408100
void BaseItem::setName(char* param_1) {
    strncpy(this->nameValue, param_1, 0x3F);
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x00408120
void BaseItem::setX(float param_1) {
    this->xValue = param_1;
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x00408130
void BaseItem::setY(float param_1) {
    this->yValue = param_1;
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x00408140
void BaseItem::setZ(float param_1) {
    this->zValue = param_1;
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x00408150
void BaseItem::setXSize(float param_1) {
    this->xSizeValue = param_1;
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x00408160
void BaseItem::setYSize(float param_1) {
    this->ySizeValue = param_1;
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x00408170
void BaseItem::setZSize(float param_1) {
    this->zSizeValue = param_1;
}

// Fully verified. Source of truth: aibitm.cpp.decomp @ 0x00408180
void BaseItem::setSkip(int param_1) {
    this->skipValue = param_1;
}
