#ifndef INFMAP_SHARED_CONTEXT
struct InfluenceMap {
    int vfptr;
    int xSizeValue;
    int ySizeValue;
    int xReferencePointValue;
    int yReferencePointValue;
    int valueValue;
    int** rowValue;
    int lookupValue(int, int);
};
#endif

int InfluenceMap::lookupValue(int x, int y) {
    if (x < 0 || x >= this->xSizeValue)
        return -1;
    if (y < 0 || y >= this->ySizeValue)
        return -1;
    return this->rowValue[y][x];
}
