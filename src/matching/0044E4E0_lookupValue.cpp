#ifndef INFMAP_SHARED_CONTEXT
struct InfluenceMap {
    void* vfptr;
    int xSizeValue;
    int ySizeValue;
    int xReferencePointValue;
    int yReferencePointValue;
    unsigned char* valueValue;
    unsigned char** rowValue;
    int coverageCountValue;
    int connectionCountValue;
    unsigned char unchangeableLimitValue;
    int lookupValue(int, int);
};
#endif

int InfluenceMap::lookupValue(int x, int y) {
    return this->rowValue[y - this->yReferencePointValue]
                       [x - this->xReferencePointValue];
}
