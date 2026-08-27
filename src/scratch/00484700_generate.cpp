// VA: 00484700 RGE_RMM_Elevation_Generator::generate
// Owner: rmm_elev.cpp:29-59.
// Natural field: RGE_Tile::height at byte +0x05.
// Current natural-module result: 187 / 191 bytes and 154 positional
// differences.
// Classification: scratch.

#include "..\..\include\rmm_elev_context.h"

unsigned char RGE_RMM_Elevation_Generator::generate() {
    this->clear_stack();

    if (this->info.elevation_num > 0) {
        long row = 0;
        if (row < this->map_height) {
            do {
                long col = 0;
                if (col < this->map_width) {
                    RGE_Tile* tile = this->map_row_offset[row];
                    do {
                        tile->height = (unsigned char)
                            this->info.elevation[0].base_elevation;
                        ++col;
                        ++tile;
                    } while (col < this->map_width);
                }
                ++row;
            } while (row < this->map_height);
        }
    }

    this->generate_modifiers();

    long i = 0;
    if (this->info.elevation_num > 0) {
        RGE_Elevation_Info_Line* line = this->info.elevation;
        do {
            this->base_elevation_generate(*line);
            this->map->clean_elevation(0, 0, this->map_width - 1,
                this->map_height - 1, 8);
            ++i;
            ++line;
        } while (i < this->info.elevation_num);
    }

    return 1;
}
