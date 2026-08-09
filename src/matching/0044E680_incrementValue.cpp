// VA: 0044E680 | InfluenceMap::incrementValue | infmap.cpp:263-299 | 259 bytes
//
// Attempt log:
// Baseline reconstruction: direct coordinate normalization and the natural
// nested row/column loops over the inclusive clamped rectangle.  The map is
// represented by the original row-pointer array, not a raw cursor.
// Main-agent audit restored the donor-backed virtual destructor surface;
// emitted code remains exact.

#include "../../include/game_types.h"

class InfluenceMap {
public:
    virtual ~InfluenceMap();
    int xSize;                         // +0x04
    int ySize;                         // +0x08
    int xReferencePoint;               // +0x0C
    int yReferencePoint;               // +0x10
    char _gap_14[0x04];
    unsigned char** rowPointers;       // +0x18
    char _gap_1C[0x08];
    unsigned char threshold;            // +0x24

    int incrementValue(int x1, int y1, int x2, int y2,
                       unsigned char amount);
};

int InfluenceMap::incrementValue(int x1, int y1, int x2, int y2,
                                 unsigned char amount)
{
    x1 -= this->xReferencePoint;
    x2 -= this->xReferencePoint;
    y1 -= this->yReferencePoint;
    y2 -= this->yReferencePoint;

    if (x1 < 0)
        x1 = 0;
    else if (x1 >= this->xSize)
        x1 = this->xSize - 1;

    if (y1 < 0)
        y1 = 0;
    else if (y1 >= this->xSize)
        y1 = this->xSize - 1;

    if (x2 < 0)
        x2 = 0;
    else if (x2 >= this->xSize)
        x2 = this->xSize - 1;

    if (y2 < 0)
        y2 = 0;
    else if (y2 >= this->xSize)
        y2 = this->xSize - 1;

    if (y1 <= y2) {
        for (int y = y1; y <= y2; y++) {
            for (int x = x1; x <= x2; x++) {
                if (this->rowPointers[y][x] < this->threshold) {
                    int value = (int)this->rowPointers[y][x] + (int)amount;
                    if (value >= this->threshold)
                        this->rowPointers[y][x] = this->threshold - 1;
                    else
                        this->rowPointers[y][x] = (unsigned char)value;
                }
            }
        }
    }

    return 1;
}
