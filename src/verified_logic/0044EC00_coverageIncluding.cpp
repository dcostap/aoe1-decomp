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
// - worker probe: naming yReference before the inclusive row count, then using
//   that local in the row index, moved register coloring and broadened the
//   function to 279B/143-byte drift; restored the clean donor-shaped source.
// - worker probe: spell the second threshold as `value + amount >= minimum`;
//   this fixes the binary-proven `cmp edx,ecx / jl` direction and reduces the
//   remaining drift from 6 bytes to 4.
// - worker variant lab: setup/access, row-index algebra, and standard-header
//   context axes produced no exact variant; the current typed basin remained
//   the only size/frame-compatible setup family.
// - worker diagnostics: explicit scaled row-byte cursors, adjusted row-map
//   bases, reversed count addition, and donor-shaped inner x-offset scope all
//   broadened or duplicated the existing basin; restored the clean typed form.
// Final bounded result: natural typed reconstruction is 275B with the 0x10
// frame, saved-register set, CFG, and all 94 instruction boundaries aligned;
// only 4 bytes remain in one localized hunk at +0x96.  The threshold predicate
// is retained because it matches the original compare direction; the remaining
// +0x96 gap is the VC5 setup order `inc eax; shl edi,2` versus
// the original `shl edi,2; inc eax`.  The row-map cache remains a plausible
// persistent map surface and the best clean source shape.
// Next lead: revisit original infmap.cpp declaration/evaluation order around
// the row-count initialization and y-reference scaling in a fresh assignment.
// Main-agent audit restored InfluenceMap's canonical destructor ownership; the
// validated four-byte instruction-order gap is unchanged.

typedef unsigned char uchar;

#ifndef INFMAP_SHARED_CONTEXT
struct XYPoint {
    int x;
    int y;
};
#endif

#ifndef INFMAP_SHARED_CONTEXT
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
#endif

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
                    rowsMap[y - this->yReferencePointValue][xOffset] + amount >= minimum) {
                    rVal++;
                }
                y++;
            } while (--rows);
        }
    }

    return rVal;
}
