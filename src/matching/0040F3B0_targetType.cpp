// targetType (0040F3B0, 25 bytes, aipbook.cpp)
// bounds-check array access, return 0 if out of range
#include "game_globals.h"
#include "game_types.h"

class AIPlay {
public:
    unsigned char _pad[0x44];
    unsigned char targetTypeValue[5];    // +0x44
    unsigned char targetCharacteristicValue[5]; // +0x49
};

unsigned char AIPlay::targetType(int index) const {
    if (index >= 0 && index < 5)
        return targetTypeValue[index];
    return 0;
}
