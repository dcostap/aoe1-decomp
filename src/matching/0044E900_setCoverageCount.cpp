// 0044E900 InfluenceMap::setCoverageCount(const XYPoint&, const XYPoint&, int)
// Source: infmap.cpp lines 369-387
// Size: 221 bytes
// NC: no custom flags (default /O2 /Oy)
//
// Mangled name: ?setCoverageCount@InfluenceMap@@QAEHABUXYPoint@@0H@Z
//   -> public __thiscall int InfluenceMap::setCoverageCount(const XYPoint&, const XYPoint&, int)
//
// Canonical reconstruction (EXACT MATCH):
// - this->coverageCountValue = 0; then 8-term bounds validation on the raw
//   (un-relative) from/to coordinates; shared fail returns 0.
// - x outer loop, y inner loop over inclusive [from..to] ranges.
// - Inner access: rowValue[y - yReferencePointValue][x - xReferencePointValue].
//   KEY: the x-relative index is named `int xr = x - xReferencePointValue` as
//   the FIRST STATEMENT OF THE INNER LOOP BODY. VC5 hoists it into the
//   preheader (once per outer iteration), transforms the x register in place
//   (sub esi, xRef), and spills x to [esp+14h] - matching the original's
//   2-local frame exactly. Placing the same statement before the inner `for`
//   instead keeps x in a copy register (edi) and changes the whole validation
//   register coloring (from->ebx vs edi).
//
// Attempt log:
// (prior workers) parked with VC5 TU-context drift; several loop/validation
// variants stayed at 192B (push ecx prologue, 1 local).
// coverage-worker-sa probes:
// - clean canonical with inline x-xRef: 191B (push ecx; -xRef folded into row
//   pointer in-loop; x kept in ebp)
// - named xr before inner for: 221B/0x8 frame but validation coloring off
//   (from->ebx vs original edi; xSize->ebp vs ebx; ySize->edi vs memory)
// - lab sweep (validation form x xr placement x access shape x class surface)
//   found exact match with xr as first statement of the inner loop body.

#ifndef INFMAP_SHARED_CONTEXT
struct XYPoint {
    int x;
    int y;
};
#endif

#ifndef INFMAP_SHARED_CONTEXT
class InfluenceMap {
public:
    void* vfptr;                    // +0x00
    int xSizeValue;                 // +0x04
    int ySizeValue;                 // +0x08
    int xReferencePointValue;       // +0x0C
    int yReferencePointValue;       // +0x10
    unsigned char* valueValue;      // +0x14
    unsigned char** rowValue;       // +0x18
    int coverageCountValue;         // +0x1C
    int connectionCountValue;       // +0x20
    unsigned char unchangeableLimitValue; // +0x24

    int setCoverageCount(const XYPoint& from, const XYPoint& to, int threshold);
};
#endif

int InfluenceMap::setCoverageCount(const XYPoint& from, const XYPoint& to, int threshold)
{
    this->coverageCountValue = 0;

    if (from.x < 0 || from.y < 0 || from.x >= this->xSizeValue || from.y >= this->ySizeValue
        || to.x < 0 || to.y < 0 || to.x >= this->xSizeValue || to.y >= this->ySizeValue) {
        return 0;
    }

    for (int x = from.x; x <= to.x; x++) {
        for (int y = from.y; y <= to.y; y++) {
            int xr = x - this->xReferencePointValue;
            if (this->rowValue[y - this->yReferencePointValue][xr] >= threshold) {
                this->coverageCountValue++;
            }
        }
    }

    return this->coverageCountValue;
}
