class RGE_Visible_Map {
public:
    unsigned char** map_offsets;
    char gap_04[0x10];
    int widthValue;
    int heightValue;

    long checksumVisible(void);
};

long RGE_Visible_Map::checksumVisible(void) {
    unsigned int value = 0;
    int y = 0;

    if (this->heightValue > 0) {
        do {
            int x = 0;
            if (this->widthValue > 0) {
                unsigned char* row = this->map_offsets[y];
                do {
                    value ^= x[row];
                    x++;
                } while (x < this->widthValue);
            }
            y++;
        } while (y < this->heightValue);
    }
    return value;
}
