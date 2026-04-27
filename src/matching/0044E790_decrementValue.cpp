// VA: 0044E790 | InfluenceMap::decrementValue(int,int,uchar) | infmap.cpp:304-321 | 107 bytes
//
// Attempt log:
// [1] Register allocation different (x in edx vs eax). 62% diff.
// [2] Renamed temps to match asm ordering. Register allocation fixed! 52% diff.
//     Issues: stack spill for val temp, branch-based saturating sub instead of sets/dec/and
// [3] Remove val temp, use ternary for sets/dec/and branchless pattern.

#include "../../include/game_types.h"

class InfluenceMap {
public:
    char _gap_00[0x04];
    int xSize;              // +0x04
    int ySize;              // +0x08
    int xReferencePoint;    // +0x0C
    int yReferencePoint;    // +0x10
    char _gap_14[0x04];
    unsigned char** rowPointers; // +0x18
    char _gap_1C[0x08];
    unsigned char threshold;     // +0x24

    int decrementValue(int x, int y, unsigned char amount);
};

int InfluenceMap::decrementValue(int x, int y, unsigned char amount) {
    int tx = x - xReferencePoint;
    int ty = y - yReferencePoint;

    if (tx < 0 || ty < 0 || tx >= xSize || ty >= ySize) {
        return 0;
    }

    unsigned char* cell = &rowPointers[ty][tx];

    if (*cell >= threshold) {
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
