#include "../../include/aibitm_context.h"

void BaseItem::setName(char* value) {
    strncpy(this->nameValue, value, 63);
}
