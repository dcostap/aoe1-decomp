// InfluenceMap::incrementValue
// VA: 0044E600
// parked: original-like natural source without shared include. Remaining work is VC5 source-shape/register allocation.
// tried this pass: removed shared include, mutable parameter-style source, explicit byte locals, int cur, removed casts.
// current result is worse than prior parked note (81.3% positional diff): VC5 saves EBX/ESI and preserves this in ESI instead of original's single ESI save with this in ECX.
// leave in scratch; original notes above/below document prior best families (one missing masks vs extra callee-saved register).

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
