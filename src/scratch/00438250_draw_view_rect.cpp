// 00438250 RGE_Diamond_Map::draw_view_rect (diam_map.cpp:1206-1310)
// Natural reconstruction of the diamond-map viewport outline.
// Attempt log (bf16-diam-8250, bounded 10-probe pass):
// - Typed DMap/player/map/view reconstruction established all 13 calls,
//   exact 0x10 frame, viewport formulas, and clipped endpoint/horizontal-line
//   drawing. Initial candidate was exact-size with 73.93% shape similarity.
// - Fractional-first ratio spelling, negative loop guards, nested line-clipping
//   comparisons, sequential map bounds, and the signed vhgt / 2 formula moved
//   the best reconstruction to 80.57% shape and 548 differing bytes.
// - The remaining drift is chiefly the second view-coordinate local home,
//   register coloring, x87/local scheduling, and expression operand order.
//   A player-pointer CSE variant deleted one required ftol and was rolled back;
//   a 16-bit coordinate-lifetime variant crossed the exact function boundary
//   and was rolled back. Left in scratch after the bounded pass.
// - Re-tested a natural typed player-pointer local across coordinate recomputation;
//   it deleted one ftol and worsened the first hunk, so the clean direct-access
//   reconstruction remains preferred.
// - This pass tested declaration/initialization splits, narrow/full coordinate
//   locals, function-scope map/tile locals, and explicit panel-x loads. These
//   forms were codegen duplicates or worsened structure; no new source-backed
//   lead displaced the clean direct-access reconstruction.

extern "C" long __cdecl __ftol(void);
#define DAT_0056F604 (*(float*)0x0056F604)

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea {
public:
    void SetPixel(long x, long y, unsigned char color);
    void DrawHorzLine(long x, long y, long width, unsigned char color);
};

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

    char gap_04[8];
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panel_name;
    TDrawArea* render_area;
    char gap_24[0xD0];
};

class RGE_Player {
public:
    char gap_00[0x114];
    float view_x;
    float view_y;
};

class RGE_Map {
public:
    char gap_00[8];
    int map_width;
    int map_height;
};

class RGE_View {
public:
    char gap_00[0x116];
    short max_col_num;
    short max_row_num;

    void get_max_size(short* cols, short* rows);
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

class RGE_Diamond_Map : public TPanel {
public:
    char gap_F4[4];
    RGE_Player* player;                    // +0xF8
    RGE_Map* map;                          // +0xFC
    int all_visible;
    int render_all;
    long mouse_last_x;
    long mouse_last_y;
    int repos_mouse;
    tagRECT view_rect;                    // +0x114
    RGE_Player* last_player;
    RGE_Map_Image_Line* map_image_lines;
    RGE_Map_Tile_Row* map_tile_rows;
    short map_wid;
    short map_hgt;
    short map_image_start_y;
    short map_image_wid;
    short map_image_hgt;
    short map_tile_row_cnt;
    float map_row_step;
    float map_col_ratio;
    float map_row_ratio;
    short map_tile_draw_hgt;
    short map_tile_draw_wid;
    short view_col;
    short view_row;
    RGE_View* main_view;
    int scrolling;
    unsigned char fog_color;
    unsigned char pad_159[3];
    int draw_objects_mode;
    unsigned long cur_player_bit;
    int own_save_area;
    TDrawArea* save_area;

    virtual void draw_view_rect();
};

void RGE_Diamond_Map::draw_view_rect()
{
    short view_x = (short)(long)this->player->view_x;
    long local_8 = (long)this->player->view_y;

    if (view_x != this->view_col || (short)local_8 != this->view_row) {
        if (view_x < 0) {
            return;
        }
        RGE_Map* map = this->map;
        if ((int)view_x >= map->map_width) {
            return;
        }
        if ((short)local_8 < 0) {
            return;
        }
        if ((int)(short)local_8 >= map->map_height) {
            return;
        }

        short map_x = (short)this->map_wid;
        short tile_x = (short)(long)this->player->view_x;
        short tile_y = (short)(long)this->player->view_y;
        RGE_Map_Tile_Row* tile_row = this->map_tile_rows +
            ((int)map_x - (int)tile_x) - 1 + (int)tile_y;

        short row = (short)local_8;
        if (view_x < (short)local_8) {
            row = view_x;
        }
        long x_offset;
        if (tile_row->ratio < DAT_0056F604) {
            x_offset = (long)((float)row * tile_row->ratio);
        } else {
            x_offset = (long)((float)row * tile_row->draw_step);
        }

        short image_line_num = tile_row->image_line;
        RGE_Map_Image_Line* image_line =
            this->map_image_lines + image_line_num;
        long x = this->pnl_x + image_line->start_x + x_offset;
        long y = this->pnl_y + this->map_image_start_y + image_line_num;

        short vhgt;
        short map_row;
        this->main_view->get_max_size(&vhgt, &map_row);

        int half_width = (int)vhgt / 2;
        this->view_rect.left =
            (long)((float)x - (float)half_width * this->map_col_ratio);
        this->view_rect.top =
            (long)((float)y - (float)map_row * this->map_row_ratio);
        this->view_rect.right =
            (long)((float)x + (float)(half_width + 2) * this->map_col_ratio);
        this->view_rect.bottom =
            (long)((float)y + (float)(map_row + 4) * this->map_row_ratio);
        this->view_col = view_x;
        this->view_row = (short)local_8;
    }

    long current_y = this->view_rect.top;
    long bottom = this->view_rect.bottom;
    if (current_y <= bottom) {
        do {
            long image_top = this->pnl_y + this->map_image_start_y;
            if (!(current_y < image_top ||
                  current_y > this->map_image_hgt - 1 + image_top)) {
                long image_index =
                    (current_y - this->map_image_start_y) - this->pnl_y;
                long right = this->view_rect.right;
                RGE_Map_Image_Line* line =
                    this->map_image_lines + image_index;
                long left = this->view_rect.left;

                if (current_y == this->view_rect.top || current_y == bottom) {
                    long line_start = line->start_x;
                    line_start += this->pnl_x;
                    long line_end = line_start + line->line_len;
                    if (left < line_end) {
                        if (right >= line_start) {
                            if (left < line_start) {
                                left = line_start;
                            }
                            if (right >= line_end) {
                                right = line_end - 1;
                            }
                            this->render_area->DrawHorzLine(
                                left, current_y, right - left + 1, 0xFF);
                        }
                    }
                } else {
                    long line_start = line->start_x;
                    line_start += this->pnl_x;
                    if (left < line_start + line->line_len) {
                        if (left >= line_start) {
                            this->render_area->SetPixel(left, current_y, 0xFF);
                        }
                    }
                    line_start = line->start_x;
                    line_start += this->pnl_x;
                    if (right < line_start + line->line_len) {
                        if (right >= line_start) {
                            this->render_area->SetPixel(right, current_y, 0xFF);
                        }
                    }
                }
            }
            bottom = this->view_rect.bottom;
            ++current_y;
        } while (current_y <= bottom);
    }
}
