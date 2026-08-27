// 00484700 RGE_RMM_Elevation_Generator::generate
// PDB: rmm_elev.cpp lines 29-59
// The tile elevation is owned by RGE_Tile::height at byte +0x05.
// Attempt log:
// - Natural generator loops walk the base map tile rows, copy the base
//   elevation value, then clean the generated map rectangle.
// - Do-while/indexed row loops retain the original outer CFG. The current
//   natural bitfield write rebuilds to 187 bytes and remains unresolved.
// - The former exact candidate used a volatile line pointer to steer stack
//   homes. That form is not retained in this natural scratch source.

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
