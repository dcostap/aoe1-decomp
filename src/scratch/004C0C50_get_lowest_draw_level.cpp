struct DrawListEntry;

class RGE_Sprite {
public:
    char gap_00[0x29];
    unsigned char draw_level;
    char gap_2A[0x0C];
    short draw_list_num;
    DrawListEntry* draw_list;

    unsigned char get_lowest_draw_level(void);
};

struct DrawListEntry {
    RGE_Sprite* sprite;
    char gap_04[0x0C];
};

unsigned char RGE_Sprite::get_lowest_draw_level(void) {
    short count = this->draw_list_num;

    if (count == 0) {
        return this->draw_level;
    }

    unsigned char lowest = 0x14;
    if (count > 0) {
        DrawListEntry* entry = this->draw_list;
        int i = (int)count;
        do {
            if (entry->sprite->draw_level < lowest) {
                lowest = entry->sprite->draw_level;
            }
            entry = (DrawListEntry*)((char*)entry + 0x10);
            i = i - 1;
        } while (i != 0);
    }
    return lowest;
}
