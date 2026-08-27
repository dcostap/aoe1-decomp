// 00484700 RGE_RMM_Elevation_Generator::generate
// PDB: rmm_elev.cpp lines 29-59
// The tile elevation is owned by RGE_Tile::height at byte +0x05.
// Attempt log:
// - baseline: natural generator loops over the base map tile rows, copies each
//   elevation-info line by value, then cleans the generated map rectangle.
// - do-while/indexed row loops reached the exact 191-byte boundary and matched
//   the outer CFG.
// - moving the second-loop counter before its guard and using a binary-observed
//   narrow volatile line pointer reproduced the stack cursor and all late call
//   block topology; the volatile is local to the proven stack-home cursor.

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
        RGE_Elevation_Info_Line* volatile line = this->info.elevation;
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
