// setTypeID (004080D0, 10 bytes, aibitm.cpp)
// simple setter: this->typeIDValue = value
#include "game_globals.h"
#include "game_types.h"

class BaseItem {
public:
    void* vtable;
    int typeIDValue;
};

void BaseItem::setTypeID(int value) {
    typeIDValue = value;
}
