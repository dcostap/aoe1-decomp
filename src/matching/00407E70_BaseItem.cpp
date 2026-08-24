#include "../../include/aibitm_context.h"

BaseItem::BaseItem(BaseItem* other) {
    this->typeIDValue = other->typeIDValue;
    this->gameIDValue = other->gameIDValue;
    this->uniqueIDValue = other->uniqueIDValue;
    this->xValue = other->xValue;
    this->yValue = other->yValue;
    this->zValue = other->zValue;
    this->xSizeValue = other->xSizeValue;
    this->ySizeValue = other->ySizeValue;
    this->zSizeValue = other->zSizeValue;
    this->skipValue = other->skipValue;
    strcpy(this->nameValue, other->nameValue);
}
