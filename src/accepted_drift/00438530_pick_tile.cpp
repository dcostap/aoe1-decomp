// 00438530 RGE_Diamond_Map::pick_tile (diam_map.cpp:1317-1354)
// PARKED after ~8 attempts
//
// Remaining drift (10 bytes, all VC5 codegen):
// 1. Load order: my code loads param_1/pnl_x BEFORE param_2/pnl_y (original does y first)
//    -> VO5 schedules x loads first despite y being declared first in source
// 2. Register alloc: my code uses edx for pnl_x, ebx for pnl_y (original: edx for pnl_y, ebx for pnl_x)  
// 3. FPU spill slot: [esp+14h] vs [esp+10h] (consequence of different load order)
// After subs: both versions have eax=adjusted_x, ecx=adjusted_y (same)
// All subsequent code is byte-perfect (100% identical from bounds checks through end)

extern "C" long __cdecl __ftol(void);

class TPanel {
public:
    char gap_00[0x0C];
    long pnl_x;                        // +0x0C
    long pnl_y;                        // +0x10
    char gap_14[0xE0];
};

class RGE_Map_Image_Line {
public:
    short tile_row;   // +0x00
    short start_x;    // +0x02
    short line_len;   // +0x04
};

class RGE_Map_Tile_Row {
public:
    char gap_00[8];
    float scale;      // +0x08
    float offset;     // +0x0C
    short map_col;    // +0x10
    short map_row;    // +0x12
    char gap_14[0x10];
};

class RGE_Map {
public:
    char gap_00[0x8D8C];
    void** map_row_offset;  // +0x8D8C
};

class RGE_Diamond_Map : public TPanel {
public:
    void* world;                         // +0xF4
    void* player;                        // +0xF8
    RGE_Map* map;                        // +0xFC
    char gap_100[0x28];
    RGE_Map_Image_Line* map_image_lines; // +0x128
    RGE_Map_Tile_Row* map_tile_rows;     // +0x12C
    short map_wid;                       // +0x130
    short map_hgt;                       // +0x132
    short map_image_start_y;             // +0x134
    short map_image_wid;                 // +0x136
    short map_image_hgt;                 // +0x138
    char gap_13C[0x30];

    int pick_tile(long param_1, long param_2, short* param_3, short* param_4, void** param_5);
};

int RGE_Diamond_Map::pick_tile(long param_1, long param_2, short* param_3, short* param_4, void** param_5)
{
    if (this->map == 0) {
        return 0;
    }

    if (this->map_image_lines == 0) {
        return 0;
    }

    int adjusted_y = param_2 - this->pnl_y;
    int adjusted_x = param_1 - this->pnl_x;

    if (adjusted_y >= this->map_image_start_y && adjusted_y <= this->map_image_start_y + this->map_image_hgt - 1) {
        int line_idx = adjusted_y - this->map_image_start_y;
        RGE_Map_Image_Line* line = &this->map_image_lines[line_idx];

        if (adjusted_x >= line->start_x && adjusted_x <= line->start_x + line->line_len - 1) {
            int tile_adjusted_x = adjusted_x - line->start_x;
            RGE_Map_Tile_Row* tile_row_ptr = &this->map_tile_rows[line->tile_row];

            long col_offset = (long)(tile_adjusted_x * tile_row_ptr->scale + tile_row_ptr->offset);

            short result_col = tile_row_ptr->map_col + (short)col_offset;
            short result_row = tile_row_ptr->map_row + (short)col_offset;

            if (param_3 != 0) {
                *param_3 = result_col;
            }
            if (param_4 != 0) {
                *param_4 = result_row;
            }
            if (param_5 != 0) {
                *param_5 = (char*)this->map->map_row_offset[result_row] + result_col * 24;
            }
            return 1;
        }
    }
    return 0;
}
