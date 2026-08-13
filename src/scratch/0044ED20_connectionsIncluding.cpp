// 0044ED20 InfluenceMap::connectionsIncluding
// Source: infmap.cpp lines 495-585
// Attempt log:
// - initial scaffold used an incomplete InfluenceMap layout and a compact
//   direction loop; it built 656B against the 713B original and was not a
//   behavior-safe reconstruction.
//
// Canonical baseline below follows the binary-supported source family: bounds
// validation, an x/y rectangle scan, two natural eight-direction switch loops,
// and the original odd/even edge and neighbor accounting.  The full class
// surface is local until this function's layout is independently reusable.
// - split validation guards and positive outer guards broadened or reduced
//   structural parity; restored the shared natural validation form.
// - explicit dispatch labels/common checks for both switch loops moved the
//   direction handlers to the binary-proven cold placement: 252 instructions,
//   0x34 frame, 588 differing bytes. That diagnostic layout was normalized
//   back to ordinary switches for the living source.
// - signed modulo-2 parity and a hoisted edge accumulator were tested; the
//   former grew the body to 828B and the latter to a 0x38 frame, so both were
//   rolled back.
// - first-direction locals declared neighborY, neighborX, edgeResult in that
//   order; this changed 4 bytes without improving alignment, so it was rolled back.
// - named x plus an open-ended outer scan preserved the initial from.x load,
//   but regressed to 686-690 differing bytes; rolled back.
// - restored direct result updates and switch fall-through; this returns to
//   the best 579-byte diagnostic basin, but the first prologue hunk remains.

#include <stdlib.h>

typedef unsigned char uchar;

struct XYPoint {
    int x;
    int y;
};

class InfluenceMap {
public:
    virtual ~InfluenceMap();
    int xSizeValue;                         // +0x04
    int ySizeValue;                         // +0x08
    int xReferencePointValue;               // +0x0C
    int yReferencePointValue;               // +0x10
    unsigned char* valueValue;              // +0x14
    unsigned char** rowValue;               // +0x18
    int coverageCountValue;                 // +0x1C
    int connectionCountValue;               // +0x20
    unsigned char unchangeableLimitValue;   // +0x24

    int connectionsIncluding(const XYPoint& from, const XYPoint& to,
                             uchar minimum, uchar amount,
                             int mode1, int mode2, int allDirections);
};

int InfluenceMap::connectionsIncluding(const XYPoint& from, const XYPoint& to,
                                       uchar minimum, uchar amount,
                                       int mode1, int mode2, int allDirections)
{
    int result = this->connectionCountValue;

    if (from.x < 0 || from.y < 0 || from.x >= this->xSizeValue ||
        from.y >= this->ySizeValue || to.x < 0 || to.y < 0 ||
        to.x >= this->xSizeValue || to.y >= this->ySizeValue) {
        return 0;
    }

    for (int x = from.x; x <= to.x; ++x) {
        if (from.y <= to.y) {
            unsigned char** rowsMap = this->rowValue;
            int xOffset = x - this->xReferencePointValue;
            int y = from.y;

            for (; y <= to.y; ++y) {
                if ((int)rowsMap[y - this->yReferencePointValue][xOffset] +
                        (int)amount >= (int)minimum) {
                    if (rowsMap[y - this->yReferencePointValue][xOffset] >= minimum) {
                        int neighborX = x;
                        int neighborY = y;

                        for (int direction = 0; direction < 8; ++direction) {
                            switch (direction) {
                            case 0:
                                --neighborX;
                                // fall through
                            case 7:
                                --neighborY;
                                break;
                            case 1:
                            case 2:
                                ++neighborX;
                                break;
                            case 3:
                            case 4:
                                ++neighborY;
                                break;
                            case 5:
                            case 6:
                                --neighborX;
                                break;
                            }

                            if (allDirections || (abs(direction) & 1) != 0) {
                                if (neighborX < 0 || neighborX >= this->xSizeValue ||
                                    neighborY < 0 || neighborY >= this->ySizeValue) {
                                    if ((mode1 == 1 && abs(direction) == 1) ||
                                        (mode2 == 1 && abs(direction) == 0)) {
                                        --result;
                                    }
                                    if (result <= 0)
                                        break;
                                }
                            }
                        }
                    }

                    int neighborX = x;
                    int neighborY = y;
                    for (int direction = 0; direction < 8; ++direction) {
                        switch (direction) {
                        case 0:
                            --neighborX;
                            // fall through
                        case 7:
                            --neighborY;
                            break;
                        case 1:
                        case 2:
                            ++neighborX;
                            break;
                        case 3:
                        case 4:
                            ++neighborY;
                            break;
                        case 5:
                        case 6:
                            --neighborX;
                            break;
                        }

                        if (allDirections || (abs(direction) & 1) != 0) {
                            if (neighborX < 0 || neighborX >= this->xSizeValue ||
                                neighborY < 0 || neighborY >= this->ySizeValue) {
                                if ((mode1 == 1 && abs(direction) == 1) ||
                                    (mode2 == 1 && abs(direction) == 0)) {
                                    --result;
                                }
                            } else if (rowsMap[neighborY - this->yReferencePointValue]
                                             [neighborX - this->xReferencePointValue] >= minimum) {
                                result += 2;
                            }
                        }
                    }
                }
            }
        }
    }

    return result;
}
