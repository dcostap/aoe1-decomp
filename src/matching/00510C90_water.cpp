class TRIBE_Map {
public:
    unsigned char water(unsigned char value);
};

unsigned char TRIBE_Map::water(unsigned char value) {
    if (value == 1) {
        return value;
    }
    if (value == 0x16) {
        return 1;
    }
    if (value == 4) {
        return 1;
    }
    return 0;
}
