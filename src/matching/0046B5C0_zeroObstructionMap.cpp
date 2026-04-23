#include <string.h>

class PathingSystem {
public:
    unsigned char gap_00[0xCE624];
    unsigned char obstructionValue[1020][255];

    void zeroObstructionMap(void);
};

void PathingSystem::zeroObstructionMap(void) {
    memset(obstructionValue, 0, sizeof(obstructionValue));
}
