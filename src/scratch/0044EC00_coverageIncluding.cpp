// VA: 0044EC00 InfluenceMap::coverageIncluding
// Source: infmap.cpp lines 464-488
// Attempt log:
// - baseline reconstruction: natural bounds validation and inclusive row/column scan;
//   291B, 0x14 frame; named byte temp caused a stack spill and the row cursor was
//   expressed at the wrong pointer-index level.
// - probe 2: inline the repeated map-byte expression and use the natural row index;
//   this should remove compiler-only local storage while retaining the source model.
// - probe 3: keep the first coordinate as the for-initializer rather than a
//   pre-validation local, mirroring the same-TU setCoverageCount donor.
// - probe 4: cache the row-pointer member at the start of the inner phase so
//   the source expresses the persistent map surface explicitly.
// - probe 5: form the inclusive row count with a separate increment statement,
//   testing the source-level scheduling of the count versus y-reference setup.
// - probe 6: name the y-reference value at the same point as the row-map cache,
//   testing whether the original setup evaluates that field before count closure.
//   Result: 279B and broad drift; rolled back.
// - probe 9: compute the inclusive row count directly from the reference
//   arguments while retaining the named y induction used by the map access.
// - probe 10: diagnostic raw byte-pointer spelling of the row lookup, exposing
//   the observed 4-byte row cursor without changing the map's ownership model.
// - probe 11: restore the canonical typed row lookup and put the decrement in
//   the do/while condition, testing the natural pre-decrement loop spelling.
// - current assignment: reordered y/row-count declarations and combined their
//   natural initializers; both emitted the same 6-byte setup-order gap.
// - current assignment: a post-decrement row condition broadened the function
//   to 283B; restored the clean pre-decrement form.
// - current assignment: a cached y-reference reproduced the earlier 279B,
//   143-byte drift; restored the direct named-field lookup.
// - current assignment: focused setup/access lab (row cursor, scaled offset,
//   loop and declaration orders) found no exact variant; the typed current
//   group remained best.
// Final bounded result: natural typed reconstruction is 275B with the 0x10
// frame, saved-register set, CFG, and all 94 instruction boundaries aligned;
// only 6 bytes remain at +0x96 (VC5 emits `inc eax; shl edi,2` instead of the
// original `shl edi,2; inc eax`).  The row-map cache is retained because it is
// a plausible persistent map surface and is the closest clean source shape.
// Next lead: revisit original infmap.cpp declaration/evaluation order around
// the row-count initialization and y-reference scaling in a fresh assignment.
// Main-agent audit restored InfluenceMap's canonical destructor ownership; the
// validated six-byte instruction-order gap is unchanged.

typedef unsigned char uchar;

struct XYPoint {
    int x;
    int y;
};

class InfluenceMap {
public:
    virtual ~InfluenceMap();             // +0x00
    int xSizeValue;                      // +0x04
    int ySizeValue;                      // +0x08
    int xReferencePointValue;            // +0x0C
    int yReferencePointValue;            // +0x10
    unsigned char* valueValue;           // +0x14
    unsigned char** rowValue;            // +0x18
    int coverageCountValue;              // +0x1C
    int connectionCountValue;            // +0x20
    unsigned char unchangeableLimitValue;// +0x24

    int coverageIncluding(const XYPoint& from, const XYPoint& to,
                          uchar minimum, uchar amount);
};

int InfluenceMap::coverageIncluding(const XYPoint& from, const XYPoint& to,
                                    uchar minimum, uchar amount)
{
    int rVal = this->coverageCountValue;

    if (from.x < 0 || from.y < 0 || from.x >= this->xSizeValue ||
        from.y >= this->ySizeValue || to.x < 0 || to.y < 0 ||
        to.x >= this->xSizeValue || to.y >= this->ySizeValue) {
        return 0;
    }

    for (int x = from.x; x <= to.x; x++) {
        if (from.y <= to.y) {
            unsigned char** rowsMap = this->rowValue;
            int xOffset = x - this->xReferencePointValue;
            int y = from.y;
            int rows = (to.y - from.y) + 1;

            do {
                if (rowsMap[y - this->yReferencePointValue][xOffset] < minimum &&
                    minimum <= rowsMap[y - this->yReferencePointValue][xOffset] + amount) {
                    rVal++;
                }
                y++;
            } while (--rows);
        }
    }

    return rVal;
}
