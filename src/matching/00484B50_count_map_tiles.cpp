// VA: 00484B50 count_map_tiles (54B)
// Keep byte-width comparisons

#include "..\..\include\rmm_elev_context.h"

long RGE_RMM_Elevation_Generator::count_map_tiles(unsigned char tile_type) {
    char* ptr = (char*)*this->map_row_offset;
    char* end = ptr + (this->width * this->height) * 24;
    long count = 0;

    while (ptr < end) {
        if (((unsigned char)ptr[5] & 0x1F) == tile_type) {
            count++;
        }
        ptr += 24;
    }
    return count;
}
