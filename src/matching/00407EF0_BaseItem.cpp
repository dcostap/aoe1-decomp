#include "../../include/aibitm_context.h"

BaseItem::BaseItem(const BaseItem& src)
    : typeIDValue(src.typeIDValue), gameIDValue(src.gameIDValue),
      uniqueIDValue(src.uniqueIDValue), xValue(src.xValue),
      yValue(src.yValue), zValue(src.zValue),
      xSizeValue(src.xSizeValue), ySizeValue(src.ySizeValue),
      zSizeValue(src.zSizeValue), skipValue(src.skipValue) {
    strcpy(this->nameValue, src.nameValue);
}
