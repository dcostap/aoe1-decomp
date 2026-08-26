#include "../../include/aibitm_context.h"

BaseItem::BaseItem(int typeID, int gameID, int uniqueID, char* name,
                   float x, float y, float z, float xSize, float ySize, float zSize)
    : typeIDValue(typeID), gameIDValue(gameID), uniqueIDValue(uniqueID),
      xValue(x), yValue(y), zValue(z),
      xSizeValue(xSize), ySizeValue(ySize), zSizeValue(zSize), skipValue(0) {
    strncpy(this->nameValue, name, 0x3F);
}
