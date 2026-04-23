extern unsigned long* unified_map_offsets[256];

class RGE_Visible_Map {
public:
    char gap_00[0x14];
    int widthValue;
    int heightValue;

    unsigned long checksumUnifiedVisible(void);
};

unsigned long RGE_Visible_Map::checksumUnifiedVisible(void) {
    unsigned long value = 0;
    int height = this->heightValue;

    if (height > 0) {
        unsigned long** offsets = unified_map_offsets;
        do {
            if (this->widthValue > 0) {
                unsigned long* row = *offsets;
                int width = this->widthValue;
                do {
                    value ^= (unsigned long)(*row);
                    row = row + 1;
                    width = width - 1;
                } while (width != 0);
            }
            offsets = offsets + 1;
            height = height - 1;
        } while (height != 0);
    }
    return value;
}
