// 00436C30 RGE_Diamond_Map::set_world (diam_map.cpp:227-354)
// Complex FPU function - computes map projection tile data

#include <stdlib.h>

extern "C" long __cdecl __ftol(void);

class RGE_Map {
public:
    short map_wid;
    short map_hgt;
    char gap_04[0x8D88 - 4];
    void** tile_offset;
};

class RGE_Map_Tile_Row {
public:
    short tile_row;
    short start_x;
    char gap_04[2];
    unsigned char active;
    char gap_07[1];
    float scale;
    char gap_0C[4];
    short bound_col;
    short bound_row;
    short tail_start;
    short tail_cnt;
    float ratio;
    float col_scale;
    float ratio2;
};

class RGE_Game_World;

class TPanel {
public:
    virtual ~TPanel() {}
    char _pad[0xF0];
};

class RGE_Diamond_Map : public TPanel {
public:
    void set_world(RGE_Game_World* world);

    void* game_world;              // +0xF4
    void* player;                  // +0xF8
    RGE_Map* map;                  // +0xFC
    int all_visible;               // +0x100
    int render_all;                // +0x104
    char gap_108[0x20];
    void* map_image_lines;         // +0x128
    RGE_Map_Tile_Row* map_tile_rows; // +0x12C
    short map_wid_;                // +0x130
    short map_hgt_;                // +0x132
    short map_image_start_y;       // +0x134
    short map_image_wid;           // +0x136
    short map_image_hgt;           // +0x138
    short map_tile_row_cnt;        // +0x13A
    float map_row_step;            // +0x13C
    float map_col_ratio;           // +0x140
    float map_row_ratio;           // +0x144
    short map_tile_draw_hgt;       // +0x148
    short map_tile_draw_wid;       // +0x14A
    short view_col;               // +0x14C
    short view_row;               // +0x14E
    void* main_view;              // +0x150
    int scrolling;                // +0x154
};

extern float DAT_0056f5fc;
extern float DAT_0056f600;
extern float DAT_0056f604;

void RGE_Diamond_Map::set_world(RGE_Game_World* world)
{
    this->game_world = world;
    if (world == 0 || this->map_image_lines == 0) {
        this->map = 0;
        return;
    }

    this->map = (RGE_Map*)((int*)world)[0x28 / 4];
    this->map_wid_ = this->map->map_wid;
    this->map_hgt_ = this->map->map_hgt;
    this->map_tile_row_cnt = this->map_wid_ + this->map_hgt_ - 1;

    if (this->map_tile_rows != 0) {
        free(this->map_tile_rows);
    }
    this->map_tile_rows = (RGE_Map_Tile_Row*)calloc(this->map_tile_row_cnt, 0x24);

    this->map_row_step = (float)this->map_tile_row_cnt / (float)this->map_image_hgt;

    float col_step;
    if (this->map_tile_row_cnt > this->map_image_hgt) {
        col_step = this->map_row_step * 3.0f;
    } else {
        col_step = 0.0f;
    }

    for (short i = 0; i < this->map_image_hgt; i++) {
        // ... complex loop body ...
    }
    // This function is very complex - need full implementation
}
