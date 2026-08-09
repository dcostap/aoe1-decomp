// VA: 0044E800 InfluenceMap::decrementValue
// infmap.cpp (242 bytes)
//
// Attempt log:
// Baseline reconstruction: direct parameter mutation, the observed xSize
// clamp for all four coordinates, and natural nested row/column loops.

class InfluenceMap {
public:
    virtual ~InfluenceMap();
    int xSizeValue;                      // +0x04
    int ySizeValue;                      // +0x08
    int xReferencePointValue;            // +0x0C
    int yReferencePointValue;            // +0x10
    char gap_14[4];                      // +0x14
    unsigned char** rowValue;            // +0x18
    char gap_1C[8];                      // +0x1C
    unsigned char unchangeableLimitValue;// +0x24

    int decrementValue(int x1, int y1, int x2, int y2,
                       unsigned char amount);
};

int InfluenceMap::decrementValue(int x1, int y1, int x2, int y2,
                                  unsigned char amount)
{
    x1 -= this->xReferencePointValue;
    x2 -= this->xReferencePointValue;
    y1 -= this->yReferencePointValue;
    y2 -= this->yReferencePointValue;

    if (x1 < 0)
        x1 = 0;
    else if (x1 >= this->xSizeValue)
        x1 = this->xSizeValue - 1;

    if (y1 < 0)
        y1 = 0;
    else if (y1 >= this->xSizeValue)
        y1 = this->xSizeValue - 1;

    if (x2 < 0)
        x2 = 0;
    else if (x2 >= this->xSizeValue)
        x2 = this->xSizeValue - 1;

    if (y2 < 0)
        y2 = 0;
    else if (y2 >= this->xSizeValue)
        y2 = this->xSizeValue - 1;

    if (y1 <= y2) {
        for (int y = y1; y <= y2; y++) {
            for (int x = x1; x <= x2; x++) {
                if (this->rowValue[y][x] < this->unchangeableLimitValue) {
                    int value = (int)this->rowValue[y][x] - (int)amount;
                    if (value < 0)
                        this->rowValue[y][x] = 0;
                    else
                        this->rowValue[y][x] = (unsigned char)value;
                }
            }
        }
    }

    return 1;
}
