// 0044E560 InfluenceMap::setValue
// Source: infmap.cpp lines 219-235
// public: int __thiscall InfluenceMap::setValue(int,int,int,int,unsigned char)
//
// Attempt log:
// Probe 1: natural nested for-loops with bounds check, default flags
//   EXACT MATCH (0.0000%). No EH, no special flags needed.

#include "..\..\include\game_globals.h"

// InfluenceMap size 0x28 — only fields we need
class InfluenceMap {
public:
    void* vfptr;                    // +0x0 (4)
    int xSizeValue;                 // +0x4 (4)
    int ySizeValue;                 // +0x8 (4)
    int xReferencePointValue;       // +0xC (4)
    int yReferencePointValue;       // +0x10 (4)
    char _gap_14[4];                // +0x14 (4)
    unsigned char** rowValue;       // +0x18 (4)

    int setValue(int x1, int y1, int x2, int y2, unsigned char value);
};

int InfluenceMap::setValue(int x1, int y1, int x2, int y2, unsigned char value)
{
    x1 -= this->xReferencePointValue;
    x2 -= this->xReferencePointValue;
    y1 -= this->yReferencePointValue;
    y2 -= this->yReferencePointValue;

    if (x1 < 0 || y1 < 0 || x1 >= this->xSizeValue || y1 >= this->ySizeValue ||
        x2 < 0 || y2 < 0 || x2 >= this->xSizeValue || y2 >= this->ySizeValue)
        return 0;

    for (int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++) {
            this->rowValue[y][x] = value;
        }
    }
    return 1;
}
