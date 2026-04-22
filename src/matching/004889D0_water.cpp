class RGE_RMM_Terrain_Generator {
public:
    unsigned char water(unsigned char value);
};

unsigned char RGE_RMM_Terrain_Generator::water(unsigned char value) {
    if (value == 1) {
        return value;
    }
    if (value == 4) {
        return 1;
    }
    if (value == 0x16) {
        return 1;
    }
    return 0;
}
