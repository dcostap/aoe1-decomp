// VA: 0044E680 | InfluenceMap::incrementValue | infmap.cpp:263-299 | 259 bytes
//
// Attempt log:
// Baseline reconstruction: direct coordinate normalization and the natural
// nested row/column loops over the inclusive clamped rectangle.  The map is
// represented by the original row-pointer array, not a raw cursor.
// Main-agent audit restored the donor-backed virtual destructor surface;
// emitted code remains exact.

#include "../../include/game_types.h"

#ifndef INFMAP_SHARED_CONTEXT
class InfluenceMap {
public:
    virtual ~InfluenceMap();
    int xSizeValue;                    // +0x04
    int ySizeValue;                    // +0x08
    int xReferencePointValue;          // +0x0C
    int yReferencePointValue;          // +0x10
    char _gap_14[0x04];
    unsigned char** rowValue;          // +0x18
    char _gap_1C[0x08];
    unsigned char unchangeableLimitValue;// +0x24

    int incrementValue(int x1, int y1, int x2, int y2,
                       unsigned char amount);
};
#endif

int InfluenceMap::incrementValue(int x1, int y1, int x2, int y2,
                                 unsigned char amount)
{
    x1 -= this->xReferencePointValue;
    x2 -= this->xReferencePointValue;
    y1 -= this->yReferencePointValue;
    y2 -= this->yReferencePointValue;

    if (x1 < 0)
        x1 = 0;
    else if (x1 >= this->xSizeValue)
        x1 = this->xSizeValue - 1;

    if (y1 < 0)
        y1 = 0;
    else if (y1 >= this->xSizeValue)
        y1 = this->xSizeValue - 1;

    if (x2 < 0)
        x2 = 0;
    else if (x2 >= this->xSizeValue)
        x2 = this->xSizeValue - 1;

    if (y2 < 0)
        y2 = 0;
    else if (y2 >= this->xSizeValue)
        y2 = this->xSizeValue - 1;

    if (y1 <= y2) {
        for (int y = y1; y <= y2; y++) {
            for (int x = x1; x <= x2; x++) {
                if (this->rowValue[y][x] < this->unchangeableLimitValue) {
                    int value = (int)this->rowValue[y][x] + (int)amount;
                    if (value >= this->unchangeableLimitValue)
                        this->rowValue[y][x] = this->unchangeableLimitValue - 1;
                    else
                        this->rowValue[y][x] = (unsigned char)value;
                }
            }
        }
    }

    return 1;
}
