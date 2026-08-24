#include "../../include/aibitm_context.h"

BaseItem::BaseItem(int typeID, int gameID, int uniqueID, char* name,
                   float x, float y, float z, float xSize, float ySize, float zSize) {
    this->typeIDValue = typeID;
    this->gameIDValue = gameID;
    this->uniqueIDValue = uniqueID;
    this->xValue = x;
    this->yValue = y;
    this->zValue = z;
    this->xSizeValue = xSize;
    this->ySizeValue = ySize;
    this->zSizeValue = zSize;
    this->skipValue = 0;
    strncpy(this->nameValue, name, 0x3F);
}
