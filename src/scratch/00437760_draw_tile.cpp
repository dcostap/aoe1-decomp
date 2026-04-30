// 00437760 RGE_Diamond_Map::draw_tile (diam_map.cpp:699-891)
// Very large function with switch dispatch

class TDrawArea;

class TPanel {
public:
    char gap_00[0xC];
    long pnl_x;         // +0x0C
    long pnl_y;         // +0x10
    long pnl_wid;       // +0x14
    long pnl_hgt;       // +0x18
    char gap_1C[4];
    TDrawArea* render_area; // +0x20
};

class RGE_Map_Tile_Row {
public:
    short tile_row;
    short start_x;
    unsigned char active;
    char gap_05[0x0B];
    float scale;
    float offset;
    short bound_col;
    short bound_row;
    short tail_start;
    short tail_cnt;
    float ratio;
    float col_scale;
    float ratio2;
};

class RGE_Map_Image_Line {
public:
    short tile_row;
    short start_x;
    short line_len;
};

class RGE_Map {
public:
    char gap_00[0x8D8C];
    void** tile_offset;
    unsigned char all_visible;
    unsigned char explored;
};

class RGE_Diamond_Map : public TPanel {
public:
    void draw_tile(short param_1, short param_2, int param_3, unsigned char param_4);

    void* world;                    // +0xF4
    void* player;                   // +0xF8
    RGE_Map* map;                   // +0xFC
    int render_all;                 // +0x104
    char gap_108[0x20];
    RGE_Map_Image_Line* map_image_lines; // +0x128
    RGE_Map_Tile_Row* map_tile_rows;      // +0x12C
    short map_wid_;                  // +0x130
    short map_hgt_;                  // +0x132
    short map_image_start_y;         // +0x134
    short map_image_wid;             // +0x136
    short map_image_hgt;             // +0x138
    short map_tile_row_cnt;          // +0x13A
    char gap_13C[0x0C];
    short map_tile_draw_hgt;         // +0x148
    char gap_14A[0x0E];
    unsigned char fog_color;         // +0x158
};

extern int* unified_map_offsets;

void RGE_Diamond_Map::draw_tile(short param_1, short param_2, int param_3, unsigned char param_4)
{
    // Complex tile drawing function
    // See asm at diam_map.cpp:699-891 for full implementation
}
