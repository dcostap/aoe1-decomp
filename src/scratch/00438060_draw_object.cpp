// 00438060 RGE_Diamond_Map::draw_object (diam_map.cpp)
// param_1=col, param_2=row, param_3=color, param_4=type(1-4), param_5=object

struct FakeTDrawArea {
    void FillRect(int x1, int y1, int x2, int y2, unsigned char color);
};

struct FakeImageLine {
    short tile_row;
    short start_x;
    short line_len;
};

struct FakeTileRow {
    short tile_row;
    short start_x;
    char gap_04[2];
    unsigned char active;
    char gap_07[0x11];
    float ratio;
    float col_scale;
    float scale;
};

struct RGE_Diamond_Map {
    char gap_00[0x0C];
    long pnl_x;                 // +0x0C
    long pnl_y;                 // +0x10
    char gap_14[0x0C];
    FakeTDrawArea* render_area; // +0x20
    char gap_24[0x104];
    FakeImageLine* map_image_lines; // +0x128
    FakeTileRow* map_tile_rows;     // +0x12C
    short map_wid;              // +0x130
    short map_hgt;              // +0x132
    short map_image_start_y;    // +0x134
};

void RGE_Diamond_Map::draw_object(short param_1, short param_2, unsigned char param_3, short param_4, void* param_5)
{
    int row_idx = this->map_wid + (int)param_2 - (int)param_1;
    FakeTileRow* row = &this->map_tile_rows[row_idx * 9];

    int sc_idx = (int)param_2;
    if ((int)param_1 < (int)param_2) sc_idx = (int)param_1;

    float scale_val;
    if ((float)row->scale > 0.0f)
        scale_val = (float)sc_idx * (float)row->scale;
    else
        scale_val = (float)sc_idx * (float)row->col_scale;

    int y_offset = (int)scale_val;

    int tile_off = (int)row->tile_row;
    tile_off = tile_off + tile_off * 2; // tile_off * 3
    int x_pos = (int)this->map_image_lines[tile_off].start_x + (int)this->pnl_x + y_offset;
    int y_pos = (int)this->pnl_y + (int)this->map_image_start_y + (int)row->tile_row;

    if (param_4 == 1) {
        ((FakeTDrawArea*)this->render_area)->FillRect(x_pos - 1, y_pos - 1, x_pos + 1, y_pos + 1, param_3);
    } else if (param_4 == 2) {
        ((FakeTDrawArea*)this->render_area)->FillRect(x_pos - 1, y_pos, x_pos + 1, y_pos + 1, param_3);
        // Wait this doesn't match the asm...
    }
}
