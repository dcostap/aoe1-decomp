#include <string.h>

#ifndef PATHSYS_TU_CONTEXT
class PathingSystem {
public:
    unsigned char gap_00[0x10DE28];
    unsigned char miscValue[255][255];

    void initMisc(unsigned char value);
};
#endif

// BINARY NOTE: the shipped fill is a 0xFE01-byte nonzero memset. VC5 lowers
// this natural form to the target REP STOSD and final REP STOSB sequence.
void PathingSystem::initMisc(unsigned char value) {
    memset(this->miscValue, value, 0xFE01);
}
