#include "../../include/aibitm_context.h"

BaseItem::BaseItem(BaseItem* other)
    : typeIDValue(other->typeIDValue), gameIDValue(other->gameIDValue),
      uniqueIDValue(other->uniqueIDValue), xValue(other->xValue),
      yValue(other->yValue), zValue(other->zValue),
      xSizeValue(other->xSizeValue), ySizeValue(other->ySizeValue),
      zSizeValue(other->zSizeValue), skipValue(other->skipValue) {
    strcpy(this->nameValue, other->nameValue);
}
