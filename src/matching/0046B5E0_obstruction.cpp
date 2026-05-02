extern unsigned char ObstructionValueShift[4];

class PathingSystem {
public:
    char gap_00[0xCE624];
    unsigned char obstructionValue[1];

    unsigned char obstruction(int x, int y);
};

unsigned char PathingSystem::obstruction(int x, int y) {
    return (unsigned char)(this->obstructionValue[(y >> 2) + x * 0xFF] >> ObstructionValueShift[y & 3]) & 3;
}
