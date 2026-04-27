// maximum (0040F280, 25 bytes, aipbook.cpp)
// bounds-check array access, return 0xFF if out of range
#include "game_globals.h"
#include "game_types.h"

class AIPlayGroup {
public:
    unsigned char minValue[6];
    unsigned char maxValue[6];
};

unsigned char AIPlayGroup::maximum(int index) const {
    if (index >= 0 && index < 6)
        return maxValue[index];
    return 0xFF;
}
