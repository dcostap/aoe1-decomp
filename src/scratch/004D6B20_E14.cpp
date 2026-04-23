class InfluenceMap {
public:
    void* vtable_ptr;
    int xSizeValue;
    int ySizeValue;
    int xReferencePointValue;
    int yReferencePointValue;
    unsigned char* valueValue;
    unsigned char** rowValue;
    int coverageCountValue;
    int connectionCountValue;
    unsigned char unchangeableLimitValue;

    InfluenceMap(int width, int height, unsigned char fill);
};

InfluenceMap losMap(0x32, 0x32, 0);
