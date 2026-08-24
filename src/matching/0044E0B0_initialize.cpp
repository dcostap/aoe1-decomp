#include <string.h>

#ifndef INFMAP_SHARED_CONTEXT
struct InfluenceMap {
    void* vfptr;               // 0x00
    int xSizeValue;            // 0x04
    int ySizeValue;            // 0x08
    int field_C;               // 0x0C
    int field_10;              // 0x10
    unsigned char* valueValue; // 0x14

    int initialize(unsigned char value);
};
#endif

int InfluenceMap::initialize(unsigned char value) {
    memset(this->valueValue, value, this->xSizeValue * this->ySizeValue);
    return 1;
}
