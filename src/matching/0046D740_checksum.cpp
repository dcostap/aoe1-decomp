#ifndef PATHSYS_TU_CONTEXT
class PathingSystem {
public:
    char gap_00[0xCE624];
    unsigned char obstructionValue[0x3FC][0xFF];

    long checksum(void);
};
#endif

long PathingSystem::checksum(void) {
    unsigned int value = 0;
    unsigned char (*row)[0xFF] = this->obstructionValue;
    int y = 0x3FC;

    do {
        int x = 0;
        do {
            value ^= (*row)[x];
            x++;
        } while (x < 0xFF);
        row = row + 1;
        y = y - 1;
    } while (y != 0);
    return value;
}
