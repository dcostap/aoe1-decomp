// 00436C30 RGE_Diamond_Map::set_world (diam_map.cpp:227-354)
// Initial reconstruction: map/image ownership and the natural tile-row
// projection tables are named from the validated diam_map donors.
// Attempt log:
// - Canonical RGE_Map/RGE_Game_World offsets, 0x24-byte tile rows, four
//   __ftol sites, and the TPanel update_view(+0x20) call are established.
// - Full natural projection/table reconstruction reached 997 bytes versus
//   1081 original, with 7/7 ordered calls, matching frame 0x10, and 66.67%
//   instruction-shape similarity.  Reciprocal draw-step spelling, early
//   image-line store, and float row-state reuse were retained; local width /
//   height and merged-home variants were tested and rolled back.
// - Reintroduced a natural local map owner so width used world->map while
//   height reloaded this->map; this followed the oracle's ordered accesses,
//   but worsened the positional diff from 971 to 989 bytes and was rolled back.
// - Remaining broad drift starts in the dimension-store/x87 local-home basin;
//   the oracle reloads [esp+14] before each row and preserves a longer FPU
//   expression tree.  No raw cursor, fake volatility, or manual vtable form
//   is retained.

#include <stdlib.h>

extern "C" long __cdecl __ftol(void);
extern float DAT_0056f5fc;
extern float DAT_0056f600;
extern float DAT_0056f604;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup();
    virtual void set_rect();
    virtual void set_rect(long, long, long, long, long);
    virtual void set_color();
    virtual void set_active();
    virtual void set_positioning();
    virtual void set_fixed_position();
    virtual void update_view(int mode);
    char gap_04[0xF0];
};

class RGE_Map_Image_Line {
public:
    short tile_row;
    short start_x;
    short line_len;
};

class RGE_Map_Tile_Row {
public:
    short image_line;
    unsigned char draw;
    unsigned char pad_03;
    short row_len;
    unsigned char pad_06[2];
    float col_step;
    float col_extra;
    short map_col;
    short map_row;
    short draw_wid;
    unsigned char pad_16[2];
    float draw_step;
    short num_tiles;
    unsigned char pad_1E[2];
    float ratio;
};

class RGE_Map {
public:
    char gap_00[8];
    long map_width;
    long map_height;
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;
};

class RGE_Diamond_Map : public TPanel {
public:
    void set_world(RGE_Game_World* world);

    RGE_Game_World* world;         // +0xF4
    void* player;                   // +0xF8
    RGE_Map* map;                   // +0xFC
    int all_visible;               // +0x100
    int render_all;                // +0x104
    char gap_108[0x20];
    RGE_Map_Image_Line* map_image_lines; // +0x128
    RGE_Map_Tile_Row* map_tile_rows;      // +0x12C
    short map_wid;                 // +0x130
    short map_hgt;                 // +0x132
    short map_image_start_y;       // +0x134
    short map_image_wid;           // +0x136
    short map_image_hgt;           // +0x138
    short map_tile_row_cnt;        // +0x13A
    float map_row_step;            // +0x13C
    float map_col_ratio;           // +0x140
    float map_row_ratio;           // +0x144
    short map_tile_draw_hgt;        // +0x148
    short map_tile_draw_wid;        // +0x14A
    short view_col;                // +0x14C
    short view_row;                // +0x14E
    void* main_view;               // +0x150
    int scrolling;                 // +0x154
};

void RGE_Diamond_Map::set_world(RGE_Game_World* world)
{
    this->world = world;
    if (world == 0 || this->map_image_lines == 0) {
        this->map = 0;
        return;
    }

    this->map = world->map;
    this->map_wid = (short)this->map->map_width;
    short map_hgt = (short)this->map->map_height;
    this->map_hgt = map_hgt;
    this->map_tile_row_cnt = this->map_wid + map_hgt - 1;

    if (this->map_tile_rows != 0) {
        free(this->map_tile_rows);
    }
    this->map_tile_rows = (RGE_Map_Tile_Row*)calloc(this->map_tile_row_cnt, 0x24);

    float col_step = 0.0f;
    this->map_row_step = (float)this->map_tile_row_cnt /
                         (float)this->map_image_hgt;
    if (this->map_tile_row_cnt > this->map_image_hgt) {
        col_step = this->map_row_step * DAT_0056f600;
    }

    float tile_row = 0.0f;
    short total_draw_wid = 0;
    short image_line = 0;
    if (this->map_image_hgt > 0) {
        do {
            short line_len = this->map_image_lines[image_line].line_len;
            short row = (short)tile_row;

            if (row >= this->map_tile_row_cnt) {
                row = this->map_tile_row_cnt - 1;
            }

            RGE_Map_Tile_Row* table_row = &this->map_tile_rows[row];
            table_row->image_line = image_line;
            short row_len_tiles;
            if (row < this->map_wid) {
                row_len_tiles = this->map_hgt;
                if (row < row_len_tiles) {
                    row_len_tiles = row + 1;
                }
            } else {
                row_len_tiles = this->map_hgt - row - 1 + this->map_wid;
            }

            tile_row = (float)row_len_tiles;
            float line_width = (float)line_len;
            float ratio = tile_row / line_width;
            float draw_step = DAT_0056f604 / ratio;
            short draw_wid = (short)draw_step;
            if ((float)draw_wid != draw_step) {
                ++draw_wid;
            }

            table_row->draw = 1;
            table_row->row_len = row_len_tiles;
            table_row->col_step = line_width;
            table_row->draw_wid = draw_wid;
            table_row->draw_step = draw_step;
            table_row->num_tiles = (short)(tile_row / draw_step);
            table_row->ratio = ratio;
            table_row->col_extra = ratio < DAT_0056f604
                ? ratio * DAT_0056f600 : DAT_0056f5fc;

            if (row < this->map_wid) {
                table_row->map_row = 0;
                table_row->map_col = this->map_wid - row - 1;
            } else {
                table_row->map_row = row - this->map_wid + 1;
                table_row->map_col = 0;
            }

            tile_row = (float)draw_wid;
            total_draw_wid += draw_wid;
            ++image_line;
            col_step += this->map_row_step;
        } while (image_line < this->map_image_hgt);
    }

    float draw_height = DAT_0056f604 / this->map_row_step;
    this->map_tile_draw_hgt = (short)draw_height;
    if ((float)this->map_tile_draw_hgt != draw_height) {
        ++this->map_tile_draw_hgt;
    }

    this->map_tile_draw_wid = total_draw_wid / this->map_image_hgt;
    if (this->map_tile_draw_wid == 0) {
        this->map_tile_draw_wid = 1;
    }

    this->map_col_ratio = (float)this->map_tile_draw_hgt /
                          (float)this->map_tile_row_cnt;
    this->map_row_ratio = (float)this->map_tile_draw_wid /
                          (float)this->map_tile_row_cnt;

    short row = 0;
    short source_row = 0;
    if (this->map_tile_row_cnt > 0) {
        do {
            RGE_Map_Tile_Row* dst = &this->map_tile_rows[row];
            short source = row;
            if (dst->draw == 0) {
                source = source_row;
                dst->image_line = this->map_tile_rows[source].image_line;
                dst->row_len = this->map_tile_rows[source].row_len;
                dst->col_step = this->map_tile_rows[source].col_step;
                dst->draw_wid = this->map_tile_rows[source].draw_wid;
                dst->draw_step = this->map_tile_rows[source].draw_step;
                dst->num_tiles = this->map_tile_rows[source].num_tiles;
                dst->ratio = this->map_tile_rows[source].ratio;
                dst->col_extra = this->map_tile_rows[source].col_extra;
            }
            ++row;
            source_row = source;
        } while (row < this->map_tile_row_cnt);
    }

    this->view_col = -1;
    this->view_row = -1;
    this->update_view(2);
}
