struct InfluenceMap {
    int vfptr;
    int xSizeValue;
    int ySizeValue;
    int xReferencePointValue;
    int yReferencePointValue;
    int valueValue;
    int** rowValue;
};

int __fastcall lookupValue(InfluenceMap* self, int, int x, int y) {
    if (x < 0 || x >= self->xSizeValue)
        return -1;
    if (y < 0 || y >= self->ySizeValue)
        return -1;
    return self->rowValue[y][x];
}
