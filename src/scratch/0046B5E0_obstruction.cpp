extern unsigned char ObstructionValueShift[4];

class PathingSystem {
public:
    unsigned char obstruction(int x, int y);
};

unsigned char PathingSystem::obstruction(int x, int y) {
    return (unsigned char)((unsigned char)this[x + (y >> 2)] >> ObstructionValueShift[y & 3]) & 3;
}
