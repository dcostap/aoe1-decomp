// 0044E9E0 InfluenceMap::setConnectionCount
// PDB: infmap.cpp:394-458, 498 bytes
// Attempt log:
// - baseline: reconstructed the row scan and eight-direction switch from the
//   executable, but used explicit gotos and raw row-address arithmetic.
// - natural typed reconstruction: named the complete InfluenceMap layout,
//   restored ordinary validation and loops, and kept the switch fall-through
//   effects shown by the original dispatch table.
// - hoisted xOffset and signed direction % 2 reproduce the 0x24 frame,
//   remainder sequence, and most switch block placement.
// - count-pointer, declaration-order, and virtual-surface probes did not move
//   codegen. Remaining drift starts at saved-this placement and local slots.
// - an explicit vfptr donor surface was codegen-neutral. Restored the natural
//   virtual class surface because raw vptr modeling adds no evidence.
// - donor declaration order with abs parity improved positional drift by 7
//   bytes but lost exact blocks; restored the cleaner signed-parity form.
// - fresh TU lead: hoisted direction to function scope to match the original
//   EBP loop state and switch-arm placement; emitted code was unchanged, so
//   restored the clean typed loop source.
// - named xSize/ySize after the negative from checks moved the first mismatch
//   no bytes, improved positional diff by 1 byte, but lost block alignment;
//   restored the clean typed source.
// - named rows, xReference, and yReference in the inner-loop preheader;
//   this moved the saved-this slot to [esp+10h] and reduced positional diff
//   from 479 to 346 bytes, but the remaining block-shape drift is unresolved.
// - removed the explicit self alias while retaining the named rows and
//   coordinate references; codegen was unchanged, so restored the clean alias.

typedef unsigned char uchar;

struct XYPoint {
    int x;
    int y;
};

class InfluenceMap {
public:
    virtual ~InfluenceMap();                  // +0x00 virtual surface
    int xSizeValue;                           // +0x04
    int ySizeValue;                           // +0x08
    int xReferencePointValue;                 // +0x0C
    int yReferencePointValue;                 // +0x10
    uchar* valueValue;                        // +0x14
    uchar** rowValue;                         // +0x18
    int coverageCountValue;                   // +0x1C
    int connectionCountValue;                // +0x20
    uchar unchangeableLimitValue;             // +0x24

    int setConnectionCount(const XYPoint& from, const XYPoint& to,
                           int minimum, int edgeHorizontal, int edgeVertical,
                           int allDirections);
};

int InfluenceMap::setConnectionCount(const XYPoint& from, const XYPoint& to,
                                     int minimum, int edgeHorizontal,
                                     int edgeVertical, int allDirections)
{
    int rowIndex;
    int xOffset;
    InfluenceMap* self = this;

    self->connectionCountValue = 0;

    if (from.x < 0 || from.y < 0 || from.x >= self->xSizeValue ||
        from.y >= self->ySizeValue || to.x < 0 || to.y < 0 ||
        to.x >= self->xSizeValue || to.y >= self->ySizeValue) {
        return 0;
    }

    for (int x = from.x; x <= to.x; ++x) {
        int y = from.y;
        if (y <= to.y) {
            uchar** rows = self->rowValue;
            int xReference = self->xReferencePointValue;
            xOffset = x - xReference;
            int yReference = self->yReferencePointValue;
            rowIndex = y * 4;
            do {
                if (rows[y - yReference]
                                      [xOffset] >= minimum) {
                    int neighborX = x;
                    int neighborY = y;
                    int neighborRow = rowIndex;

                    for (int direction = 0; direction < 8; ++direction) {
                        switch (direction) {
                        case 0:
                            --neighborX;
                        case 7:
                            --neighborY;
                            neighborRow -= 4;
                            break;
                        case 1:
                        case 2:
                            ++neighborX;
                            break;
                        case 3:
                        case 4:
                            ++neighborY;
                            neighborRow += 4;
                            break;
                        case 5:
                        case 6:
                            --neighborX;
                            break;
                        }

                        if (allDirections || (direction % 2) != 0) {
                            if (neighborX >= 0 && neighborX < self->xSizeValue &&
                                neighborY >= 0 && neighborY < self->ySizeValue) {
                                if (rows[neighborY - yReference]
                                                   [neighborX - self->xReferencePointValue] >= minimum) {
                                    ++self->connectionCountValue;
                                }
                            } else if ((edgeHorizontal == 1 && (direction % 2) == 1) ||
                                       (edgeVertical == 1 && (direction % 2) == 0)) {
                                ++self->connectionCountValue;
                            }
                        }
                    }
                }

                rowIndex += 4;
                ++y;
            } while (y <= to.y);
        }
    }

    return self->connectionCountValue;
}
