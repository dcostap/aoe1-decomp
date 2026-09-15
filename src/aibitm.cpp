#include "../include/aibitm.h"

#include <string.h>

BaseItem::BaseItem()
    : typeIDValue(-1), gameIDValue(-1), uniqueIDValue(-1),
      xValue(0), yValue(0), zValue(0),
      xSizeValue(0), ySizeValue(0), zSizeValue(0), skipValue(0) {
    strcpy(nameValue, "");
}

BaseItem::BaseItem(int tid, int gid, int uid, char* n, float x, float y, float z, float xs, float ys, float zs)
    : typeIDValue(tid), gameIDValue(gid), uniqueIDValue(uid),
      xValue(x), yValue(y), zValue(z),
      xSizeValue(xs), ySizeValue(ys), zSizeValue(zs), skipValue(0) {
    strncpy(this->nameValue, n, 0x3F);
}

BaseItem::BaseItem(BaseItem* bi)
    : typeIDValue(bi->typeIDValue), gameIDValue(bi->gameIDValue),
      uniqueIDValue(bi->uniqueIDValue), xValue(bi->xValue),
      yValue(bi->yValue), zValue(bi->zValue),
      xSizeValue(bi->xSizeValue), ySizeValue(bi->ySizeValue),
      zSizeValue(bi->zSizeValue), skipValue(bi->skipValue) {
    strcpy(this->nameValue, bi->nameValue);
}

BaseItem::BaseItem(const BaseItem& bi)
    : typeIDValue(bi.typeIDValue), gameIDValue(bi.gameIDValue),
      uniqueIDValue(bi.uniqueIDValue), xValue(bi.xValue),
      yValue(bi.yValue), zValue(bi.zValue),
      xSizeValue(bi.xSizeValue), ySizeValue(bi.ySizeValue),
      zSizeValue(bi.zSizeValue), skipValue(bi.skipValue) {
    strcpy(this->nameValue, bi.nameValue);
}

BaseItem::~BaseItem() {}

int __cdecl operator==(const BaseItem& one, const BaseItem& two) {
    if (one.gameIDValue == two.gameIDValue) {
        if (one.xValue == two.xValue) {
            if (one.yValue == two.yValue) {
                return 1;
            }
        }
    }
    return 0;
}

int __cdecl operator!=(const BaseItem& one, const BaseItem& two) {
    return !operator==(one, two);
}

int __cdecl operator<(const BaseItem& one, const BaseItem& two) {
    return one.gameIDValue < two.gameIDValue;
}

int __cdecl operator>(const BaseItem& one, const BaseItem& two) {
    return one.gameIDValue > two.gameIDValue;
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

void BaseItem::setTypeID(int v) {
    typeIDValue = v;
}

void BaseItem::setGameID(int v) {
    gameIDValue = v;
}

void BaseItem::setUniqueID(int v) {
    uniqueIDValue = v;
}

void BaseItem::setName(char* n) {
    strncpy(this->nameValue, n, 63);
}

void BaseItem::setX(float v) {
    xValue = v;
}

void BaseItem::setY(float v) {
    yValue = v;
}

void BaseItem::setZ(float v) {
    zValue = v;
}

void BaseItem::setXSize(float v) {
    xSizeValue = v;
}

void BaseItem::setYSize(float v) {
    ySizeValue = v;
}

void BaseItem::setZSize(float v) {
    zSizeValue = v;
}

void BaseItem::setSkip(int v) {
    skipValue = v;
}
