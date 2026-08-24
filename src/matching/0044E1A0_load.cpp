void __cdecl rge_read(int fd, void* buf, int count);

#ifndef INFMAP_SHARED_CONTEXT
class InfluenceMap {
public:
    char gap_00[0x04];           // +0x00: vtable
    int xSizeValue;              // +0x04
    int ySizeValue;              // +0x08
    int xReferencePointValue;    // +0x0C
    int yReferencePointValue;    // +0x10
    unsigned char* valueValue;   // +0x14
    unsigned char** rowValue;    // +0x18
    char gap_1C[0x08];
    unsigned char unchangeableLimitValue; // +0x24

    void load(int fd);
};
#endif

void InfluenceMap::load(int fd) {
    rge_read(fd, &xSizeValue, 4);
    rge_read(fd, &ySizeValue, 4);
    rge_read(fd, &xReferencePointValue, 4);
    rge_read(fd, &yReferencePointValue, 4);
    rge_read(fd, &unchangeableLimitValue, 1);

    for (int i = 0; i < ySizeValue; i++) {
        for (int j = 0; j < xSizeValue; j++) {
            unsigned char b;
            rge_read(fd, &b, 1);
            rowValue[i][j] = b;
        }
    }
}
