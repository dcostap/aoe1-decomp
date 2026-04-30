// VA: 004C0C50 get_lowest_draw_level (50B)
// sprite.cpp

class RGE_Sprite {
public:
    char gap_00[0x29];
    unsigned char draw_level;  // +0x29
    char gap_2A[0x36 - 0x2A];
    short draw_list_num;       // +0x36
    char* draw_list;           // +0x38 (16-byte entries, sprite at +4)

    unsigned char get_lowest_draw_level(void);
};

unsigned char RGE_Sprite::get_lowest_draw_level(void) {
    short count = this->draw_list_num;
    if (count == 0) return this->draw_level;

    unsigned char lowest = 0x14;
    if (count > 0) {
        char* entry = this->draw_list + 4;
        int i = count;
        do {
            RGE_Sprite* sp = *(RGE_Sprite**)(entry);
            if (sp->draw_level < lowest) lowest = sp->draw_level;
            entry += 0x10;
        } while (--i != 0);
    }
    return lowest;
}
