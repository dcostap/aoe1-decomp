#include "../include/aibitm.h"

#include <string.h>

BaseItem::BaseItem()
    : typeIDValue(-1), gameIDValue(-1), uniqueIDValue(-1),
      xValue(0), yValue(0), zValue(0),
      xSizeValue(0), ySizeValue(0), zSizeValue(0), skipValue(0) {
    strcpy(nameValue, "");
}

BaseItem::BaseItem(int typeID, int gameID, int uniqueID, char* name,
                   float x, float y, float z, float xSize, float ySize, float zSize)
    : typeIDValue(typeID), gameIDValue(gameID), uniqueIDValue(uniqueID),
      xValue(x), yValue(y), zValue(z),
      xSizeValue(xSize), ySizeValue(ySize), zSizeValue(zSize), skipValue(0) {
    strncpy(this->nameValue, name, 0x3F);
}

BaseItem::BaseItem(BaseItem* other)
    : typeIDValue(other->typeIDValue), gameIDValue(other->gameIDValue),
      uniqueIDValue(other->uniqueIDValue), xValue(other->xValue),
      yValue(other->yValue), zValue(other->zValue),
      xSizeValue(other->xSizeValue), ySizeValue(other->ySizeValue),
      zSizeValue(other->zSizeValue), skipValue(other->skipValue) {
    strcpy(this->nameValue, other->nameValue);
}

BaseItem::BaseItem(const BaseItem& src)
    : typeIDValue(src.typeIDValue), gameIDValue(src.gameIDValue),
      uniqueIDValue(src.uniqueIDValue), xValue(src.xValue),
      yValue(src.yValue), zValue(src.zValue),
      xSizeValue(src.xSizeValue), ySizeValue(src.ySizeValue),
      zSizeValue(src.zSizeValue), skipValue(src.skipValue) {
    strcpy(this->nameValue, src.nameValue);
}

BaseItem::~BaseItem() {}

int __cdecl operator==(const BaseItem& lhs, const BaseItem& rhs) {
    if (lhs.gameIDValue == rhs.gameIDValue) {
        if (lhs.xValue == rhs.xValue) {
            if (lhs.yValue == rhs.yValue) {
                return 1;
            }
        }
    }
    return 0;
}

int __cdecl operator!=(const BaseItem& lhs, const BaseItem& rhs) {
    return !operator==(lhs, rhs);
}

int __cdecl operator<(const BaseItem& lhs, const BaseItem& rhs) {
    return lhs.gameIDValue < rhs.gameIDValue;
}

int __cdecl operator>(const BaseItem& lhs, const BaseItem& rhs) {
    return lhs.gameIDValue > rhs.gameIDValue;
}

int BaseItem::typeID() const {
    return this->typeIDValue;
}

int BaseItem::gameID() const {
    return this->gameIDValue;
}

int BaseItem::uniqueID() const {
    return this->uniqueIDValue;
}

char* BaseItem::name() {
    return this->nameValue;
}

float BaseItem::x() const {
    return this->xValue;
}

float BaseItem::y() const {
    return this->yValue;
}

float BaseItem::z() const {
    return this->zValue;
}

float BaseItem::xSize() const {
    return this->xSizeValue;
}

float BaseItem::ySize() const {
    return this->ySizeValue;
}

float BaseItem::zSize() const {
    return this->zSizeValue;
}

int BaseItem::skip() const {
    return this->skipValue;
}

void BaseItem::setTypeID(int value) {
    typeIDValue = value;
}

void BaseItem::setGameID(int value) {
    gameIDValue = value;
}

void BaseItem::setUniqueID(int value) {
    uniqueIDValue = value;
}

void BaseItem::setName(char* value) {
    strncpy(this->nameValue, value, 63);
}

void BaseItem::setX(float value) {
    xValue = value;
}

void BaseItem::setY(float value) {
    yValue = value;
}

void BaseItem::setZ(float value) {
    zValue = value;
}

void BaseItem::setXSize(float value) {
    xSizeValue = value;
}

void BaseItem::setYSize(float value) {
    ySizeValue = value;
}

void BaseItem::setZSize(float value) {
    zSizeValue = value;
}

void BaseItem::setSkip(int value) {
    skipValue = value;
}
