#ifndef PATHSYS_TU_CONTEXT
class PathingSystem {
public:
    char gap_00[0x10DE28];
    unsigned char miscValue[255][255];

    void setMisc(int row, int column, unsigned char value);
};
#endif

void PathingSystem::setMisc(int row, int column, unsigned char value) {
    this->miscValue[row][column] = value;
}
