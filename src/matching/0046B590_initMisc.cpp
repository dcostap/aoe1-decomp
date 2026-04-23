class PathingSystem {
public:
    unsigned char gap_00[0x10DE28];
    unsigned char miscValue[255][255];

    void initMisc(unsigned char value);
};

void PathingSystem::initMisc(unsigned char value) {
    unsigned int packed = (unsigned int)value | ((unsigned int)value << 8);
    packed |= packed << 16;
    unsigned char (*row)[255] = miscValue;
    for (int count = 0x3F80; count != 0; --count) {
        *(unsigned int*)*row = packed;
        row = (unsigned char (*)[255])((unsigned char*)*row + 4);
    }
    (*row)[0] = value;
}
