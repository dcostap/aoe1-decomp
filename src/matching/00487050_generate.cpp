// 00487050 RGE_RMM_Shallows_Generator::generate
// Source: rmm_shal.cpp lines 42-102, size 418 bytes.
// The nested for loops follow the PDB line map: outer loop at line 56,
// inner loop at line 57, and connection call at line 58.

#include "..\..\include\rmm_shal_context.h"

uchar RGE_RMM_Shallows_Generator::generate()
{
    this->clear_stack();

    long i, j;
    long x, y;
    for (i = 0; i < this->info.shallows_num; ++i) {
        for (j = i + 1; j < this->info.shallows_num; ++j) {
            this->make_tribe_connections(i, j);
        }
    }

    long count = 2;
    this->info.shallows_num += 2;
    long index1 = this->info.shallows_num - 1;
    long index2 = this->info.shallows_num - 2;

    do {
        int found = 0;
        do {
            x = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0x45) *
                 (this->map_width - 1)) / 0x7FFF;
            y = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0x46) *
                 (this->map_height - 1)) / 0x7FFF;
            uchar terrain = this->map_row_offset[y][x].terrain & 0x1f;
            if (terrain != 1 && terrain != 0x16 && terrain != 4) {
                this->info.shallows[index1].x = x;
                found = 1;
                this->info.shallows[index1].y = y;
            }
        } while (!found);

        found = 0;
        do {
            x = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0x54) *
                 (this->map_width - 1)) / 0x7FFF;
            y = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0x55) *
                 (this->map_height - 1)) / 0x7FFF;
            uchar terrain = this->map_row_offset[y][x].terrain & 0x1f;
            if (terrain != 1 && terrain != 0x16 && terrain != 4) {
                this->info.shallows[index2].x = x;
                found = 1;
                this->info.shallows[index2].y = y;
            }
        } while (!found);

        this->make_tribe_connections(index1, index2);
        --count;
    } while (count != 0);

    return 1;
}
