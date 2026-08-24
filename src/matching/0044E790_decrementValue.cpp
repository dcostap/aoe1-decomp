// VA: 0044E790 | InfluenceMap::decrementValue(int,int,uchar) | infmap.cpp:304-321 | 107 bytes
//
// Attempt log:
// [1] Register allocation different (x in edx vs eax). 62% diff.
// [2] Renamed temps to match asm ordering. Register allocation fixed! 52% diff.
//     Issues: stack spill for val temp, branch-based saturating sub instead of sets/dec/and
// [3] Remove val temp, use ternary for sets/dec/and branchless pattern.

#include "../../include/game_types.h"

#ifndef INFMAP_SHARED_CONTEXT
class InfluenceMap {
public:
    char _gap_00[0x04];
    int xSizeValue;         // +0x04
    int ySizeValue;         // +0x08
    int xReferencePointValue; // +0x0C
    int yReferencePointValue; // +0x10
    char _gap_14[0x04];
    unsigned char** rowValue; // +0x18
    char _gap_1C[0x08];
    unsigned char unchangeableLimitValue; // +0x24

    int decrementValue(int x, int y, unsigned char amount);
};
#endif

int InfluenceMap::decrementValue(int x, int y, unsigned char amount) {
    int tx = x - xReferencePointValue;
    int ty = y - yReferencePointValue;

    if (tx < 0 || ty < 0 || tx >= xSizeValue || ty >= ySizeValue) {
        return 0;
    }

    unsigned char* cell = &rowValue[ty][tx];

    if (*cell >= unchangeableLimitValue) {
        return 1;
    }

    int diff = (int)*cell - (int)amount;
    if (diff < 0) {
        *cell = 0;
    } else {
        *cell = (unsigned char)diff;
    }

    return 1;
}
