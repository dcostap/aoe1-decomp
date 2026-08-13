// 00437760 RGE_Diamond_Map::draw_tile (diam_map.cpp:699-891)
// Natural reconstruction from the validated diamond-map rendering donors.
// Attempt log (bf16-diam-7760, bounded 10-probe pass):
// - Typed reconstruction established the map/tile/terrain/player ownership,
//   ratio gate, terrain switch, object color scan, fog fill, and all 12 calls.
// - Corrected RGE_Object_List to 0xC so RGE_Tile indexing uses the proven
//   0x18-byte stride; fixed the absolute unified-map and float globals.
// - Reversed the main param3 dispatch to regular rendering fallthrough with
//   fog in the else arm; this restored exact size and raised shape to 67.82%.
// - Restored the param4 > 0 color override and direct 32-bit panel coordinate
//   use. Final: 1145 bytes, 0x1C frame, 12/12 ordered calls, 69.33% shape,
//   1040 differing bytes. Remaining drift is the prologue/register coloring,
//   local-home layout, ratio x87 expression order, and object-scan CFG.
// - Inverted the fog height test into the same natural single-row/multi-row
//   branch shape as regular tiles; shape rose to 76.98% and exact blocks to
//   35.22%, but positional drift rose to 1054 bytes. Kept as the structural
//   lead; the first mismatch remains the prologue local/register topology.
// - Tested natural long map_y/map_x locals before tile-row setup; this moved
//   the first mismatch to the callee-save pushes and worsened diff to 1091.
//   Rolled back to the clean direct-coordinate expression.
// - Moved row/map/tile declarations above the first body statement to mirror
//   the PDB declaration-only band; VC5 emitted identical code, so restored clean.
// - Replaced the guarded do-loop with a post-test scan-row while loop, matching
//   the original loop-exit CFG; VC5 emitted the same code, so restored clean.
// - Left in scratch after the 10-hypothesis budget; no inline asm or opaque
//   codegen scaffolding is retained.

extern "C" long __cdecl __ftol(void);
#define DAT_0056f604 (*(float*)0x0056F604)
#define unified_map_offsets ((unsigned long**)0x00886808)

class TDrawArea {
public:
    void SetPixel(long x, long y, unsigned char color);
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
    virtual void update_view(int mode);

    char gap_04[8];
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panel_name;
    TDrawArea* render_area;
    char gap_24[0xD0];
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x8E];
    unsigned char map_draw_level;
    unsigned char map_color;
};

class RGE_Static_Object {
public:
    char gap_00[8];
    RGE_Master_Static_Object* master_obj;
};

class RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
};

class RGE_Object_List {
public:
    char gap_00[4];
    RGE_Object_Node* list;
    short number_of_objects;
    unsigned char gap_0A[2];
};

class RGE_Tile {
public:
    char gap_00[4];
    unsigned char tile_type;
    unsigned char terrain_type;
    char gap_06[6];
    RGE_Object_List objects;
};

class RGE_Terrain_Set {
public:
    char gap_00[0x28];
    unsigned char map_hi_color;
    unsigned char map_med_color;
    unsigned char map_low_color;
    char gap_2B[0x198 - 0x2B];
};

class RGE_Map {
public:
    char gap_00[0x8C];
    RGE_Terrain_Set terrain_types[32];
    char gap_338C[0x5A00];
    RGE_Tile** map_row_offset;       // +0x8D8C
    char gap_8D90[0x28];
    unsigned char map_visible_flag;  // +0x8DB8
};

class RGE_Player {
public:
    char gap_00[0xD0];
    unsigned long mutualExploredMask;
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
    RGE_Player* player;
    RGE_Map* map;
    int all_visible;
    int render_all;
    char gap_108[0x20];
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
    void* main_view;
    int scrolling;
    unsigned char fog_color;
    unsigned char pad_159[3];
    int draw_objects_mode;
    unsigned long cur_player_bit;
    int own_save_area;
    TDrawArea* save_area;

    void draw_tile(short x, short y, int param_3, unsigned char param_4);
};

void RGE_Diamond_Map::draw_tile(short param_1, short param_2,
                                int param_3, unsigned char param_4)
{
    unsigned char color = 0;
    RGE_Map_Tile_Row* row = this->map_tile_rows +
        ((int)param_2 + (int)this->map_wid - (int)param_1);
    --row;

    if (row->draw == 0) {
        return;
    }

    RGE_Map* map = this->map;
    RGE_Tile** tile_rows = map->map_row_offset;
    RGE_Tile* tile = tile_rows[param_2] + param_1;

    if (map->map_visible_flag == 0 &&
        (this->player->mutualExploredMask &
         unified_map_offsets[param_2][param_1]) == 0) {
        return;
    }

    bool draw = false;
    short x_offset;
    short max_coord = param_2;
    if (param_1 < param_2) {
        max_coord = param_1;
    }

    if (!(row->ratio >= DAT_0056f604)) {
        float scaled = (float)max_coord * row->ratio;
        x_offset = (short)scaled;
        if (scaled - (float)x_offset < row->ratio) {
            draw = true;
        }
    } else {
        x_offset = (short)((float)max_coord * row->draw_step);
        draw = true;
    }

    if (!draw) {
        return;
    }

    int x = (int)this->map_image_lines[row->image_line].start_x + x_offset;
    int y = (int)this->map_image_start_y + (int)row->image_line;
    unsigned char terrain = tile->terrain_type & 0x1F;

    if (param_3 == 0) {
        if (param_4 > 0) {
            color = param_4;
        } else {
            switch (tile->tile_type) {
            case 0:
                color = map->terrain_types[terrain].map_med_color;
                break;
            case 1:
            case 4:
            case 5:
            case 7:
            case 8:
            case 9:
            case 12:
            case 13:
            case 15:
                color = map->terrain_types[terrain].map_low_color;
                break;
            case 2:
            case 3:
            case 6:
            case 10:
            case 11:
            case 14:
            case 16:
                color = map->terrain_types[terrain].map_hi_color;
                break;
            }
        }

    short scan_row = param_2 - 1;
    param_2 += 2;
    do {
        if (param_2 <= scan_row) {
            short width = row->draw_wid;
            unsigned char draw_color = color;
            if (this->map_tile_draw_hgt == 1) {
                if (width == 1) {
                    this->save_area->SetPixel(x, y, draw_color);
                    return;
                }
                if (width == 2) {
                    this->save_area->SetPixel(x, y, draw_color);
                    this->save_area->SetPixel(x + 1, y, draw_color);
                    return;
                }
                if (width > 0) {
                    int count = width;
                    do {
                        this->save_area->SetPixel(x, y, draw_color);
                        ++x;
                        --count;
                    } while (count != 0);
                }
            } else {
                short dy = 0;
                if (this->map_tile_draw_hgt > 0) {
                    do {
                        if (width > 0) {
                            int count = width;
                            int px = x;
                            do {
                                this->save_area->SetPixel(px, y + dy, draw_color);
                                ++px;
                                --count;
                            } while (count != 0);
                        }
                        ++dy;
                    } while (dy < this->map_tile_draw_hgt);
                }
            }
            return;
        }

        if (scan_row >= 0 && scan_row < this->map_hgt) {
            short scan_col = param_1 - 1;
            while (scan_col < param_1 + 2) {
                if (scan_col < 0 || scan_col >= this->map_wid) {
                    ++scan_col;
                } else {
                    RGE_Object_Node* node = tile_rows[scan_row][scan_col].objects.list;
                    if (node == 0) {
                        ++scan_col;
                    } else {
                        do {
                            if (node->node->master_obj->map_draw_level == 4) {
                                color = node->node->master_obj->map_color;
                                break;
                            }
                            node = node->next;
                        } while (node != 0);
                        ++scan_col;
                    }
                }
            }
        }
        ++scan_row;
    } while (true);
    } else {
        x += this->pnl_x;
        y += this->pnl_y;
        short width = row->draw_wid;
        if (this->map_tile_draw_hgt == 1) {
            if (width == 1) {
                this->render_area->SetPixel(x, y, this->fog_color);
                return;
            }
            if (width == 2) {
                this->render_area->SetPixel(x, y, this->fog_color);
                this->render_area->SetPixel(x + 1, y, this->fog_color);
                return;
            }
            if (width < 1) {
                return;
            }
            int count = width;
            do {
                this->render_area->SetPixel(x, y, this->fog_color);
                ++x;
                --count;
            } while (count != 0);
            return;
        }
        short dy = 0;
        if (this->map_tile_draw_hgt < 1) {
            return;
        }
        do {
            if (width > 0) {
                int count = width;
                int px = x;
                do {
                    this->render_area->SetPixel(px, y + dy, this->fog_color);
                    ++px;
                    --count;
                } while (count != 0);
            }
            ++dy;
        } while (dy < this->map_tile_draw_hgt);
        return;
    }
}
