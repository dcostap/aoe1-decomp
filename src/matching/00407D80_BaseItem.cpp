#include "../../include/aibitm_context.h"

BaseItem::BaseItem()
    : typeIDValue(-1), gameIDValue(-1), uniqueIDValue(-1),
      xValue(0), yValue(0), zValue(0),
      xSizeValue(0), ySizeValue(0), zSizeValue(0), skipValue(0) {
    strcpy(nameValue, default_item_name);
}
