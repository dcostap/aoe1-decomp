// VA: 004C0C50 get_lowest_draw_level (50B)
// sprite.cpp

#include "../../include/sprite_context.h"

unsigned char RGE_Sprite::get_lowest_draw_level(void) {
    short count = this->draw_list_num;
    if (count == 0) return this->draw_level;

    unsigned char lowest = 0x14;
    if (count > 0) {
        char* entry = (char*)this->draw_list + 4;
        int i = count;
        do {
            RGE_Sprite* sp = *(RGE_Sprite**)(entry);
            if (sp->draw_level < lowest) lowest = sp->draw_level;
            entry += 0x10;
        } while (--i != 0);
    }
    return lowest;
}
