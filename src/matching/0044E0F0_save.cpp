void __cdecl rge_write(int fd, const void* data, int count);

class InfluenceMap {
public:
    char gap_00[0x04];
    int xSizeValue;              // +0x04
    int ySizeValue;              // +0x08
    int xReferencePointValue;    // +0x0C
    int yReferencePointValue;    // +0x10
    unsigned char* valueValue;   // +0x14
    unsigned char** rowValue;    // +0x18
    char gap_1C[0x08];
    unsigned char unchangeableLimitValue; // +0x24

    void save(int fd);
};

void InfluenceMap::save(int fd) {
    rge_write(fd, &xSizeValue, 4);
    rge_write(fd, &ySizeValue, 4);
    rge_write(fd, &xReferencePointValue, 4);
    rge_write(fd, &yReferencePointValue, 4);
    rge_write(fd, &unchangeableLimitValue, 1);

    for (int i = 0; i < ySizeValue; i++) {
        for (int j = 0; j < xSizeValue; j++) {
            rge_write(fd, rowValue[i] + j, 1);
        }
    }
}
