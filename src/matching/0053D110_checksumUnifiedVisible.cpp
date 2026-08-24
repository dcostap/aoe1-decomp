extern unsigned long* unified_map_offsets[256];

#ifndef AOE1_VISIBLE_TU_CONTEXT_H
class RGE_Visible_Map {
public:
    char gap_00[0x14];
    int widthValue;
    int heightValue;

    unsigned long checksumUnifiedVisible(void);
};
#endif

unsigned long RGE_Visible_Map::checksumUnifiedVisible(void) {
    unsigned long value;

    value = 0;
    if (this->heightValue > 0) {
        unsigned long** offsets;
        int height;

        offsets = unified_map_offsets;
        height = this->heightValue;
        do {
            if (this->widthValue > 0) {
                unsigned long* row;
                int width;

                row = *offsets;
                width = this->widthValue;
                do {
                    value ^= *row;
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
