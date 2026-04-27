// RGE_Map::clear_map — first pass
// VA: 00455C20
#include "../../include/game_globals.h"

void __fastcall clear_map(void* _this, int _, unsigned char param_1, unsigned char param_2)
{
    int h = *(int*)((char*)_this + 0xC);
    if (h <= 0) {
        // skip loop, just set_map_screen_pos
    } else {
        for (int y = 0; y < h; y++) {
            int w = *(int*)((char*)_this + 8);
            void* row = *(void**)(*(int*)((char*)_this + 0x8D8C) + y * 4);
            for (int x = 0; x < w; x++) {
                // tile init
                ((char*)row)[0] = 0;  // tile_type
                ((char*)row)[1] = 0;
                ((char*)row)[4] = 0;  // some field
                ((char*)row)[5] = (param_1 & 0x1F) | (param_2 << 5);
                ((char*)row)[6] = 0;  // field_0x6
                ((char*)row)[7] = 0;
                ((char*)row)[8] = 0xFF; // last_drawn_shape
                ((char*)row)[9] = 0;  // draw_as
                ((char*)row)[0xA] = 0; // draw_attribute
                ((char*)row)[0xB] = 0xFF; // last_drawn_shape2
                row = (char*)row + 0x18;
            }
        }
    }
    // set_map_screen_pos(this, 0, 0, map_width-1, map_height-1)
}
