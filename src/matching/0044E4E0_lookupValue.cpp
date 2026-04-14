// InfluenceMap::lookupValue(int x, int y)
// return (unsigned char) rowValue[y - yReferencePointValue][x - xReferencePointValue]
// ret 8 = 2 params

struct InfluenceMap {
    int vfptr;
    int xSizeValue;
    int ySizeValue;
    int xReferencePointValue;
    int yReferencePointValue;
    unsigned char* valueValue;
    unsigned char** rowValue;
};

int __fastcall lookupValue(InfluenceMap* self, int, int x, int y) {
    return (unsigned char)self->rowValue[y - self->yReferencePointValue][x - self->xReferencePointValue];
}
