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
// - hoisted the natural inner y declaration before the positive guard; this
//   exposed the target y home and improved the typed source to 485 differing
//   bytes with 77.34% shape similarity.
// - split the first neighbor pass into a separate edgeResult accumulator,
//   supported by the target's EBP result lifetime and spill before pass two.
//   With the hoisted y, this gives the exact prologue block, 64.26% exact
//   block coverage, and 84.56% shape similarity; positional drift is 541B.
//   Retained as the best binary-supported source reconstruction.
// - focused pass: target parity lowering is signed remainder, so direction % 2
//   improved block coverage to 84.34% but worsened positional drift to 560B.
//   Named coordinate/size aliases, direct x-offset expressions, loop-form
//   changes, shared direction/neighbor scopes, and declaration-order probes
//   either duplicated codegen or left the clean basin unchanged.
// - a natural independent case-0/case-7 switch with signed remainder produced
//   a 249B body and 97.59% shape similarity, but retained a 312B positional
//   mismatch from register-map conflicts. Its case split also lacks the target
//   PDB-supported case-0 fall-through, so it was not retained.
// - a 32-variant local lab covering switch form and parity spellings found no
//   exact result. The best diagnostic group still had 306B positional drift;
//   no lab source replaced this clean typed reconstruction.
// - Accepted drift: validation covered both inclusive rectangle loops, bounds
//   guards, repeated cell reads, all eight direction updates, edge predicates,
//   result decrements/increments, overflow behavior, and returns. Direction is
//   always 0..7, so the different parity lowering is equivalent. The function
//   has no calls, writes, or floating-point operations. Remaining drift is
//   switch-block placement and private register/local scheduling.
// - exact-finish follow-up: the corrected setConnectionCount switch evidence
//   was applied as behavior-preserving duplicated case-7 updates. The first
//   pass with signed direction remainder reached a 249-instruction, 312-byte
//   mismatch, but VC5 swapped the proven x/y register colors from validation
//   through the graph walk. Removing the CRT include reduced this to 311 bytes.
//   Applying the duplicated form to both passes reached 550 bytes; applying it
//   only to the second pass reached 551 bytes. None was exact.
// - exact-finish follow-up: a self alias was codegen-neutral. A one-result
//   accumulator grew the body to 784 bytes. Moving edgeResult into its guard
//   was codegen-neutral. These forms were removed. The pinned natural source
//   remains the smallest behavior-safe reconstruction.
// - exact-finish audit: the best 249-instruction source was fresh-checked at
//   311 differing bytes and 97.59% shape. Its first blocker is the target's
//   EBX xSize / EDI to.x color versus VC5's reversed colors. The target also
//   keeps a distinct second-pass case-0 to case-7 edge. Open-ended scans,
//   cached size aliases, full local class declarations, independent second
//   cases, and a named case-7 jump did not improve this basin. All probes were
//   removed. The pinned 541-byte source is restored.
// - BINARY NOTE: 0044E9E0 setConnectionCount remains unedited. Fresh audit
//   still shows its documented 8-byte self/row home swap and its exact row,
//   filter, count, and malformed-input behavior.

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
    int edgeResult;
    int result = this->connectionCountValue;

    if (from.x < 0 || from.y < 0 || from.x >= this->xSizeValue ||
        from.y >= this->ySizeValue || to.x < 0 || to.y < 0 ||
        to.x >= this->xSizeValue || to.y >= this->ySizeValue) {
        return 0;
    }

    for (int x = from.x; x <= to.x; ++x) {
        int y = from.y;
        if (from.y <= to.y) {
            unsigned char** rowsMap = this->rowValue;
            int xOffset = x - this->xReferencePointValue;

            do {
                if ((int)rowsMap[y - this->yReferencePointValue][xOffset] +
                        (int)amount >= (int)minimum) {
                    if (rowsMap[y - this->yReferencePointValue][xOffset] >= minimum) {
                        edgeResult = result;
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
                                        --edgeResult;
                                    }
                                    if (edgeResult <= 0)
                                        break;
                                }
                            }
                        }
                        result = edgeResult;
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
                ++y;
            } while (y <= to.y);
        }
    }

    return result;
}
