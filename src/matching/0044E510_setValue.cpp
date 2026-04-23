struct InfluenceMap {
    void* vfptr;              // 0x00
    int xSizeValue;           // 0x04
    int ySizeValue;           // 0x08
    int xReferencePointValue;  // 0x0C
    int yReferencePointValue;  // 0x10
    char gap_14[4];           // 0x14
    unsigned char** rowValue;  // 0x18

    int setValue(int x, int y, unsigned char value);
};

int InfluenceMap::setValue(int x, int y, unsigned char value) {
    x -= this->xReferencePointValue;
    y -= this->yReferencePointValue;
    if (x < 0 || y < 0 || x >= this->xSizeValue || y >= this->ySizeValue) {
        return 0;
    }
    this->rowValue[y][x] = value;
    return 1;
}
