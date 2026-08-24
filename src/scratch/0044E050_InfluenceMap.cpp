#ifndef INFMAP_SHARED_CONTEXT
struct InfluenceMap {
    int vfptr;      // 0x00
    int xSizeValue;  // 0x04
    int ySizeValue;  // 0x08
    int xReferencePointValue; // 0x0C
    int yReferencePointValue; // 0x10
    InfluenceMap(int);
    void load(int);
};
#endif

InfluenceMap::InfluenceMap(int fd) {
    this->xSizeValue = -1;
    this->ySizeValue = -1;
    this->xReferencePointValue = 0;
    this->yReferencePointValue = 0;
    this->load(fd);
}
