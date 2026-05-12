// VA: 0044E600 InfluenceMap::incrementValue
// PDB: infmap.cpp lines 240-257 (123 bytes, 45 asm lines)
// Default flags. No inline asm/hacks.

struct InfluenceMap {
    int vtable;
    int xSize;
    int ySize;
    int xReferencePoint;
    int yReferencePoint;
    int gap_14;
    unsigned char** rowData;
    int gap_1C_1;
    int gap_1C_2;
    unsigned char maxLimit;

    int incrementValue(int x, int y, unsigned char value);
};

int InfluenceMap::incrementValue(int x, int y, unsigned char value) {
    int rx = x - this->xReferencePoint;
    int ry = y - this->yReferencePoint;

    if (rx < 0 || ry < 0 || rx >= this->xSize || ry >= this->ySize)
        return 0;

    unsigned char* cell = this->rowData[ry] + rx;
    unsigned char cur = *cell;

    if (cur >= this->maxLimit)
        return 1;

    unsigned int sum = (unsigned int)(unsigned char)cur + (unsigned int)(unsigned char)value;

    if (sum >= (unsigned int)(unsigned char)this->maxLimit) {
        *cell = (unsigned char)((unsigned int)(unsigned char)this->maxLimit - 1);
        return 1;
    }

    *cell = (unsigned char)sum;
    return 1;
}
