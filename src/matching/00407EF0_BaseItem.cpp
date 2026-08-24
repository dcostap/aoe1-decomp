#include "../../include/aibitm_context.h"

BaseItem::BaseItem(const BaseItem& src) {
    this->typeIDValue = src.typeIDValue;
    this->gameIDValue = src.gameIDValue;
    this->uniqueIDValue = src.uniqueIDValue;
    this->xValue = src.xValue;
    this->yValue = src.yValue;
    this->zValue = src.zValue;
    this->xSizeValue = src.xSizeValue;
    this->ySizeValue = src.ySizeValue;
    this->zSizeValue = src.zSizeValue;
    this->skipValue = src.skipValue;
    strcpy(this->nameValue, src.nameValue);
}
