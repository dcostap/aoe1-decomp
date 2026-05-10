// InfluenceMap::incrementValue
// VA: 0044E600
// parked: original-like natural source without shared include. Remaining work is VC5 source-shape/register allocation.
// tried this pass: removed shared include, mutable parameter-style source, explicit byte locals, int cur, removed casts.
// current result is worse than prior parked note (81.3% positional diff): VC5 saves EBX/ESI and preserves this in ESI instead of original's single ESI save with this in ECX.
// SpruceGlow tries 1-10: mutable x/y params, no cell local, byte cur/sum, limit locals, positive/nested bounds,
// raw offsets, early limit, return local. All worse/same; byte-cur form failed compile under current surface.
// SpruceGlow tries 11-22: no-this member access, unsigned cur/sum, char* row local, limit ref, single return,
// goto fail, direct/compact field names, threshold decrement local, virtual class surface. None recovered original
// single-ESI-save register allocation; best remains current 81.3% positional diff family.
// Left in scratch: behavior is understood, but broad register-allocation/frame mismatch remains. Not proposing
// accepted_drift due broad codegen differences and extra callee-saved register/epilogue changes. No inline asm/hacks.
// 2026-05-10 StarryZephyr pass: rechecked baseline and retried mutable x/y parameters with explicit byte limit/cur/sum.
// It worsened to 91.1% positional and first mismatch offset 1, still saving EBX/ESI and not matching original ECX-live shape.
// Restored baseline.

struct InfluenceMap {
    char gap_00[4];
    int xSize;
    int ySize;
    int xReferencePoint;
    int yReferencePoint;
    char gap_14[4];
    unsigned char** rowData;
    char gap_1C[8];
    unsigned char maxLimit;

    int incrementValue(int x, int y, unsigned char value);
};

int InfluenceMap::incrementValue(int x, int y, unsigned char value) {
    int rx = x - this->xReferencePoint;
    int ry = y - this->yReferencePoint;

    if (rx < 0 || ry < 0 || rx >= this->xSize || ry >= this->ySize)
        return 0;

    unsigned char* cell = this->rowData[ry] + rx;
    int cur = *cell;

    if (cur >= this->maxLimit)
        return 1;

    cur = cur + value;

    if (cur >= this->maxLimit) {
        *cell = this->maxLimit - 1;
        return 1;
    }

    *cell = cur;
    return 1;
}
