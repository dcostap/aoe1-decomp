// incrementHitPoints (0040A710, 15 bytes, aibobj.cpp)
// this->hitPointValue += value;
#include "game_globals.h"
#include "game_types.h"

class BaseObject {
public:
    void* vtable;
    void* next;
    void* prev;
    int numberGroupsValue;
    int* groupIDValue;
    int categoryIDValue;
    int typeIDValue;
    int gameIDValue;
    char nameValue[64];
    float xPositionValue;
    float yPositionValue;
    float zPositionValue;
    float xSizeValue;
    float ySizeValue;
    float zSizeValue;
    int hitPointValue;
    int minHitPointValue;
};

void BaseObject::incrementHitPoints(int value) {
    hitPointValue += value;
}
