#include "../../include/aiconitm_context.h"

ConstructionItem::ConstructionItem(float x, float y, float z, float xSize,
                                   float ySize, float zSize, int typeID,
                                   char* name)
    : BaseItem(typeID, -1, -1, name, x, y, z, xSize, ySize, zSize) {
    this->next = 0;
    this->prev = 0;
    this->inProgressValue = 0;
    this->builtValue = 0;
    this->buildAttemptsValue = 0;
}
