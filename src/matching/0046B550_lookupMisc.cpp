#ifndef PATHSYS_TU_CONTEXT
class PathingSystem {
public:
    char gap_00[0x10DE28];
    unsigned char miscValue[255][255];

    unsigned char lookupMisc(int row, int column);
};
#endif

unsigned char PathingSystem::lookupMisc(int row, int column) {
    return this->miscValue[row][column];
}
