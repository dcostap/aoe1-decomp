// 00436C30 RGE_Diamond_Map::set_world (diam_map.cpp:227-354)
// Attempt log:
// - The field offsets, row size, four __ftol calls, and virtual slot +0x20
//   match local binary evidence. The call set is 7/7 and the frame is 0x10.
// - BINARY NOTE: each image line stores its computed tile_row before the
//   destination row table is filled.
// - BINARY NOTE: both row passes use one array base with separate row offsets.
//   Direct typed indexing keeps this ownership model.
// - BINARY NOTE: the executable carries draw height into the final ratio
//   stores. The source keeps draw_height live for that reason.
// - LIKELY INTENT: col_step maps image pixels to map tiles. draw_step maps
//   map tiles to image pixels. ratio handles sub-pixel tile placement.
// - Additional probes tested source order, local lifetime, field type, loop
//   shape, row ownership, global form, and register color. The source remains
//   nonexact. Its structural shape is now closer, with exact second-pass
//   blocks and the original ordered calls. The remaining drift is mainly in
//   x87 homes, the first projection block, and saved-register colors.
// - BINARY NOTE: col_step drives the tile row and receives map_row_step after
//   each image line. A separate accumulator sums each row ratio.
// - BINARY NOTE: a tile row stores row_len/line_len in col_step and its
//   reciprocal in draw_step and ratio. The final ratios use col_step and the
//   accumulated draw width.
// - BINARY NOTE: the second pass updates source_row only for a drawn row. The
//   source condition keeps the original JE copy-arm topology.
// - Main review restored the per-row ratio division and its separate sum. The
//   executable adds each +0x20 ratio in the loop, then divides that sum by the
//   image height. This correction reaches exact size, 91.20% shape, and 690
//   differing bytes. It replaces the worker's unsupported final ratio algebra.

#include <stdlib.h>

extern "C" long __cdecl __ftol(void);
extern const float DAT_0056f5fc;
extern const float DAT_0056f600;
extern const float DAT_0056f604;

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
    if (world != 0 && this->map_image_lines != 0) {
        this->map = world->map;
    this->map_wid = (short)this->map->map_width;
    short map_hgt = (short)this->map->map_height;
    this->map_hgt = map_hgt;
    this->map_tile_row_cnt = this->map_wid + map_hgt - 1;

    if (this->map_tile_rows != 0) {
        free(this->map_tile_rows);
    }
    this->map_tile_rows = (RGE_Map_Tile_Row*)calloc(this->map_tile_row_cnt, 0x24);

    float col_step = 0;
    this->map_row_step = (float)this->map_tile_row_cnt /
                         (float)this->map_image_hgt;
    if (this->map_tile_row_cnt > this->map_image_hgt) {
        col_step = this->map_row_step * DAT_0056f600;
    }

    float ratio_sum = 0.0f;
    short total_draw_wid = 0;
    short image_line = 0;
    if (this->map_image_hgt > 0) {
        do {
            short line_len =
                this->map_image_lines[image_line].line_len;
            short row = (short)col_step;

            if (row >= this->map_tile_row_cnt) {
                row = this->map_tile_row_cnt - 1;
            }

            this->map_image_lines[image_line].tile_row = row;

            short row_len_tiles;
            if (row < this->map_wid) {
                row_len_tiles = this->map_hgt;
                if (row < row_len_tiles) {
                    row_len_tiles = row + 1;
                }
            } else {
                row_len_tiles = this->map_hgt - row - 1 + this->map_wid;
            }

            float row_ratio =
                (float)row_len_tiles / (float)line_len;
            float draw_step = DAT_0056f604 / row_ratio;
            short draw_wid = (short)draw_step;
            if ((float)draw_wid != draw_step) {
                ++draw_wid;
            }

            this->map_tile_rows[row].image_line = image_line;
            this->map_tile_rows[row].draw = 1;
            this->map_tile_rows[row].row_len = row_len_tiles;
            this->map_tile_rows[row].col_step = row_ratio;
            this->map_tile_rows[row].draw_wid = draw_wid;
            this->map_tile_rows[row].draw_step = draw_step;
            this->map_tile_rows[row].num_tiles =
                (short)((float)line_len / draw_step);
            this->map_tile_rows[row].ratio = draw_step / (float)line_len;
            this->map_tile_rows[row].col_extra =
                this->map_tile_rows[row].ratio < DAT_0056f604
                    ? row_ratio * DAT_0056f600
                    : DAT_0056f5fc;

            if (row < this->map_wid) {
                this->map_tile_rows[row].map_row = 0;
                this->map_tile_rows[row].map_col = this->map_wid - row - 1;
            } else {
                this->map_tile_rows[row].map_row = row - this->map_wid + 1;
                this->map_tile_rows[row].map_col = 0;
            }

            total_draw_wid += draw_wid;
            ratio_sum += this->map_tile_rows[row].ratio;
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

    this->map_col_ratio = ratio_sum / (float)this->map_image_hgt;
    this->map_row_ratio = (float)this->map_image_hgt /
                          (float)this->map_tile_row_cnt;

    short row = 0;
    short source_row = 0;
    if (this->map_tile_row_cnt > 0) {
        do {
            unsigned char draw = this->map_tile_rows[row].draw;
            if (draw != 0) {
                source_row = row;
            } else {
                this->map_tile_rows[row].image_line = this->map_tile_rows[source_row].image_line;
                this->map_tile_rows[row].row_len = this->map_tile_rows[source_row].row_len;
                this->map_tile_rows[row].col_step = this->map_tile_rows[source_row].col_step;
                this->map_tile_rows[row].draw_wid = this->map_tile_rows[source_row].draw_wid;
                this->map_tile_rows[row].draw_step = this->map_tile_rows[source_row].draw_step;
                this->map_tile_rows[row].num_tiles = this->map_tile_rows[source_row].num_tiles;
                this->map_tile_rows[row].ratio = this->map_tile_rows[source_row].ratio;
                this->map_tile_rows[row].col_extra = this->map_tile_rows[source_row].col_extra;
            }
            ++row;
        } while (row < this->map_tile_row_cnt);
    }

    this->view_col = -1;
    this->view_row = -1;
        this->update_view(2);
        return;
    }

    this->map = 0;
}
