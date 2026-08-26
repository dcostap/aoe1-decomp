// 00535FE0 RGE_View::view_function (view.cpp:2562-3006)
// __thiscall, 2354 bytes (corpus range 00535FE0-00536911).
//
// NOTE (corpus split): the original function physically continues past the
// inventory boundary (00536911) with the tile_screen_row switch cases
// (00536912/00536932/00536957...) and the shared loop tail (00536992+), plus
// jump tables at 00536B04/00536B1C/00536B2C.  The corpus tracks those blocks
// separately as parent-owned fragments (00536912, 00536957) and the naked
// fragment 00536932 (caseD_3).  A faithful single-function reconstruction is
// therefore always flagged "code-overflow" by the checker (the original's own
// `ja 00536992`/`jne 00536A9E`/`je 005369DC` targets and the switch jump-table
// entries lie beyond the 2354-byte compared range).  This file keeps the full
// natural source so the parent (and its fragments) stay readable; the exact
// check cannot succeed until the corpus boundary question is resolved.
//
// Attempt log:
//   p1 baseline: full natural reconstruction from Ghidra packet + exact donors
//     (get_selection_area, get_visible, shadow_draw, normal_draw, get_list_info)
//     + type dumps (RGE_View/RGE_Map/RGE_Tile/RGE_Player/TDrawArea). 45.3% shape.
//   p2 types: fixed RGE_Tile_Set sizeof 0x198 (was 0xBA -> shifted all map offsets)
//     and RGE_View gap after y_max (started at 0x98, overlapped; now 0x9C). 53.6%.
//   p3 liveness: removed the `tile_ptr != 0` guard in the terrain-update block; the
//     original derefs tile_ptr unconditionally (mov bl,[ebp+5] at 0053660C). This
//     flipped the frame to 0x78 and raised shape to 62.9%.
//   p4 layout: reversed local declaration order - no emitted-code change (negative).
//   p5 control-flow: swapped function_parm/function_mode store order - slightly worse,
//     reverted (negative).
//   p6 flags: `register` on a1/a2 - no emitted-code change (negative).
//   p7 control-flow: restructured in-bounds check from if/else-if/else to
//     if/else-with-nested-continue so VC5 keeps the out-of-bounds mode check inline
//     (matches original B029/B030 blocks); 63.9%.
//   p8 context: changed the mode-chain conditions (0x28/0x3C/.../0x2C and the 0x0E
//     selection check) to read `this->function_mode` instead of the `a1` parameter.
//     The original reloads the member after the get_list_info call (mov al,[esi+140h]
//     at 00536062), so the source used member reads, not the param. This made the
//     ENTIRE prologue byte-identical and raised shape to 65.0% (first mismatch now
//     only the fog_flag local slot +0x90).
//   p9 layout: restored natural declaration order - no change (negative).
//   p10 control-flow: assigned direction before cur_col_num to match the
//     original PDB statement order at view.cpp:2634/2637; strict diff improved
//     2529 -> 2526 bytes, but edit/resync diff worsened. Rolled back to the
//     clean natural source; the structural stage and corpus-boundary block
//     remain unresolved.
//   continuation claim #1 layout: short list_size matched the observed
//     16-bit max-row arithmetic but enlarged the code; restored int.
//   claim #2 control-flow: direction-before-cur order was a codegen duplicate.
//   claim #3 layout: max_row_num2 = picked_type improved the short-list basin
//     to 2451 bytes; the alias is retained.
//   claim #4 layout: int list_size with that alias reached 2433 bytes.
//   claim #5 layout: reversing the two max-col assignments regressed to 2526;
//     restored the alias direction.
//   claim #6 abi: modeled the binary/decompiler bounds predicate as bool
//     in_bounds; this improved strict diff to 2424 bytes and is retained.
//   claim #7 abi: bool draw_flag was a 2448-byte regression; restored int.
//   claim #8 layout: short list_size with the bool/alias surface was 2432 bytes;
//     restored int.
//   claim #9 layout: cast the short max-row sum before the shift, matching the
//     observed 16-bit add/shift and reaching the current best, 2423 bytes.
//   Status: structurally faithful (frame/saved-regs/calls/prologue exact, 65% shape,
//     ~42% exact-block coverage); remaining drift is VC5 local-slot permutation
//     (picked_type/fog_flag/tile/tile_ptr/start_map_row2/direction/tile_screen_row/
//     last_picked_obj region) and ebx/ebp register roles. Exact check is BLOCKED by
//     the corpus split (see note above); further probing would be blind allocation tuning.
//   latest pass (sa-c5cf6e0b): twelve fresh hypotheses were compiled and checked.
//     Narrow list_size, signed fog_flag, narrow/full picked_type, narrow direction,
//     narrow col_num, short tile_screen_row, full max_row_num2, paired narrow types,
//     reordered initializers, a separate visibility local, and register hints for
//     the persistent short states all regressed or produced duplicate codegen.
//     The clean source remains best at 2423 strict-diff bytes, 65.02% shape,
//     41.72% exact-block coverage, frame 0x78, and all 15 calls aligned.
//     No hypothesis changed the corpus overflow. Restore the clean source before
//     pause; the remaining lead is the proven local-home/register basin, not ABI.
//   latest pass (sa-ac59df96):
//     H1 moved fog_flag beside visible; codegen duplicate.
//     H2 moved the mode-0B tile test inside the in-bounds arm; strict diff 2434,
//     shape 65.85%, then restored because natural strict bytes worsened.
//     H3 swapped tile and tile_ptr declarations; codegen duplicate.
//     H4 used one explicit visible_zero label; same 2434-byte result as H2,
//     restored because it was not the clean natural basin.
//     H5 widened last_picked_obj to int; strict diff 2436, shape 63.90%, restored.
//     H6 restored cur_col_num-before-direction assignment order; codegen duplicate.
//     H7 used a short list_size with a separate shift; strict diff 2432, restored.
//     H8 reordered inner coordinate declarations; codegen duplicate.
//     H9 marked view_function protected. Bytes stayed unchanged and the owner
//     symbol changed from QAE to the target's protected IAE decoration; retained.
//     H10 used the target's negative visibility guard; codegen duplicate.
//     Final clean: 2423 strict diff, 65.02% shape, 41.72% exact blocks, 15 calls,
//     frame 0x78. The target's 2354-byte corpus boundary still truncates the
//     natural function tail and prevents exact boundary validation.

#include <windows.h>

#ifndef RGE_VIEW_SHARED_CONTEXT
extern int fog_next_shape;
#endif

#ifndef RGE_VIEW_SHARED_CONTEXT
class RGE_Map;
class RGE_Player;
class RGE_Visible_Map;
class TDrawArea;
struct RGE_Tile;

struct RGE_Master_Static_Object {
    char gap_00[0x8D];
    unsigned char select_level; // +0x8D
};

struct RGE_Static_Object {
    char gap_00[8];
    RGE_Master_Static_Object* master_obj; // +0x08
    char gap_0C[0x38 - 0x0C];
    float world_x; // +0x38
    float world_y; // +0x3C
};

class RGE_Object_List {
public:
    void* vtable;            // +0x00
    void* list;              // +0x04
    short number_of_objects; // +0x08
    char pad_0A[2];

    void shadow_draw(TDrawArea* draw_area, short x, short y, unsigned char param_4, unsigned char fog);
    void normal_draw(TDrawArea* draw_area, short x, short y, unsigned char param_4);
};

struct RGE_Tile {
    short screen_xpos;            // +0x00
    short screen_ypos;            // +0x02
    unsigned char tile_type;      // +0x04
    unsigned char field_5;        // +0x05
    unsigned char field_6;        // +0x06
    unsigned char last_drawn_as;  // +0x07
    unsigned char field_8;        // +0x08
    unsigned char draw_as;        // +0x09
    unsigned char field_A;        // +0x0A
    unsigned char field_B;        // +0x0B
    RGE_Object_List objects;      // +0x0C
};

struct RGE_Tile_Size {
    short width;   // +0x00
    short height;  // +0x02
    short y_delta; // +0x04
};

struct RGE_Tile_Set {
    char gap_00[0x44];
    unsigned char frame_changed; // +0x44
    unsigned char drawn;         // +0x45
    char gap_46[0x72];           // -> 0xB8
    short terrain_to_draw;       // +0xB8
    char gap_BA[0x198 - 0xBA];   // -> 0x198
}; // sizeof = 0x198

class RGE_Map {
public:
    virtual ~RGE_Map();
    RGE_Tile* map;                  // +0x04
    long map_width;                 // +0x08
    long map_height;                // +0x0C
    char gap_10[8];
    RGE_Tile_Size tilesizes[19];    // +0x18
    char gap_8A[2];
    RGE_Tile_Set terrain_types[32]; // +0x8C
    char gap_338C[0x5A00];          // border_types
    RGE_Tile** map_row_offset;      // +0x8D8C
    short num_terrain;              // +0x8D90
    char gap_8D92[0x26];
    unsigned char map_visible_flag; // +0x8DB8
    unsigned char fog_flag;         // +0x8DB9

    void tile_map_coords(short a, short b, RGE_Tile* tile, float* out_x, float* out_y);
};

class RGE_Visible_Map {
public:
    char gap_00[8];
    RGE_Player* player; // +0x08

    unsigned char get_visible(int x, int y);
};

class RGE_Tile_List {
public:
    char gap_0[4];
    int field_4;  // +0x04 num_active
    char gap_8[8];
    int field_10; // +0x10 list

    void get_list_info(int* out1, int* out2);
};

class RGE_Player {
public:
    char gap_00[0x38];
    RGE_Visible_Map* visible; // +0x38
    char gap_3C[0x1C];
    RGE_Tile_List tile_list;  // +0x58
};

class TDrawArea {
public:
    char gap_00[0xCC];
    void* SpanList;    // +0xCC
    void* CurSpanList; // +0xD0
};

class RGE_View {
public:
    char gap_00[0x8C];
    int x_min;                    // +0x8C
    int y_min;                    // +0x90
    int x_max;                    // +0x94
    int y_max;                    // +0x98
    char gap_9C[0xF4 - 0x9C];    // +0x9C..+0xF3
    TDrawArea* cur_render_area;   // +0xF4
    int calc_draw_count;          // +0xF8
    char gap_F8[0x100 - 0xFC];
    RGE_Player* player;           // +0x100
    RGE_Map* map;                 // +0x104
    short tile_wid;               // +0x108
    short tile_hgt;               // +0x10A
    short tile_half_wid;          // +0x10C
    short tile_half_hgt;          // +0x10E
    short elev_hgt;               // +0x110
    char gap_110[0x116 - 0x112];
    short max_col_num;            // +0x116
    short max_row_num;            // +0x118
    char gap_118[0x126 - 0x11A];
    short start_scr_col;          // +0x126
    short start_scr_row;          // +0x128
    short start_map_col;          // +0x12A
    short start_map_row;          // +0x12C
    char gap_12C[0x140 - 0x12E];
    unsigned char function_mode;  // +0x140
    unsigned char function_parm;  // +0x141
    char gap_141[0x178 - 0x142];
    void* Terrain_Clip_Mask;      // +0x178
    void* Terrain_Fog_Clip_Mask;  // +0x17C

protected:
    long view_function(register unsigned char a1, register unsigned char a2, tagPOINT* p1, tagPOINT* p2,
                       void** out_obj, float* out_x, float* out_y, short* out_col, short* out_row);

public:
    int get_selection_area(long* col1, long* row1, long* col2, long* row2, int normalize);
    RGE_Static_Object* hit_object(RGE_Tile* tile, short x, short y, short a, short b,
                                  tagPOINT* p1, tagPOINT* p2, short* out_x, short* out_y,
                                  RGE_Static_Object* skip, unsigned char through_fog);
    int hit_tile(RGE_Tile* tile, short sx, short sy, short a, short b, tagPOINT* pt);
};
#endif

#ifdef RGE_VIEW_SHARED_CONTEXT
#define RGE_VIEW_OBJECTS(tile) ((tile)->objects)
#else
#define RGE_VIEW_OBJECTS(tile) (&(tile)->objects)
#endif

long RGE_View::view_function(register unsigned char a1, register unsigned char a2, tagPOINT* p1, tagPOINT* p2,
                             void** out_obj, float* out_x, float* out_y, short* out_col, short* out_row)
{
    unsigned char visible;
    short map_row;
    short map_col;
    short start_scr_col2;
    short start_scr_row2;
    short cur_col_num;
    short picked_type;
    unsigned char fog_flag;
    unsigned char tile;
    RGE_Tile* tile_ptr;
    short start_map_row2;
    short direction;
    unsigned char tile_screen_row;
    short last_picked_obj;
    RGE_Static_Object* terrain_type;
    unsigned char tile_type;
    unsigned char col_num;
    short row_num;
    long calc_sel_col1;
    long calc_sel_col2;
    long calc_sel_row1;
    long calc_sel_row2;
    RGE_Static_Object* orig_picked_obj;
    RGE_Static_Object* find_col;
    short find_row;
    short max_col_num2;
    short max_row_num2;
    int list_size;

    this->function_mode = a1;
    this->function_parm = a2;

    if (a1 == 0x0A && this->calc_draw_count != 0) {
        for (short i = 0; i < this->map->num_terrain; i++) {
            this->map->terrain_types[i].drawn = 0;
        }
    }

    int list_node, num_active;
    this->player->tile_list.get_list_info(&list_node, &num_active);

    fog_flag = 0x32;
    if (this->function_mode == 0x28 || this->function_mode == 0x3C || this->function_mode == 0x29 ||
        this->function_mode == 0x2A || this->function_mode == 0x2B || this->function_mode == 0x2C) {
        if (this->function_mode == 0x3C) {
            find_row = (short)(long)(*out_x);
            max_col_num2 = (short)(long)(*out_y);
        }
        *out_x = 0.0f;
        *out_y = 0.0f;
        *out_col = 0;
        *out_row = 0;
        if (this->function_mode == 0x29 || this->function_mode == 0x2A || this->function_mode == 0x2B ||
            this->function_mode == 0x2C) {
            find_col = (RGE_Static_Object*)*out_obj;
        }
        *out_obj = 0;
        terrain_type = 0;
    }

    if (this->function_mode == 0x0E) {
        if (this->get_selection_area(calc_sel_col2, calc_sel_row2, calc_sel_row1, (long&)orig_picked_obj, 1) == 0) {
            return 0;
        }
    }

    start_scr_row2 = this->start_scr_col;
    start_map_row2 = this->start_map_col;
    direction = this->start_map_row;
    cur_col_num = this->start_scr_row;
    list_size = (short)(this->max_row_num + 6) << 1;
    picked_type = this->max_col_num + 4;
    max_row_num2 = picked_type;
    tile_screen_row = 4;
    calc_sel_col1 = 0;

    if ((short)list_size > 0) {
        do {
            map_row = start_scr_row2;
            start_scr_col2 = start_map_row2;
            map_col = direction;
            row_num = 0;
            if (picked_type > 0) {
                do {
                    bool in_bounds;
                    int draw_flag;
                    if (start_scr_col2 >= 0 && start_scr_col2 < this->map->map_width &&
                        map_col >= 0 && map_col < this->map->map_height) {
                        in_bounds = 1;
                    } else {
                        in_bounds = 0;
                        if (this->function_mode != 0x28 && this->function_mode != 0x2A) {
                            goto col_continue;
                        }
                    }
                    if (in_bounds) {
                        RGE_Visible_Map* vis = this->player->visible;
                        if (vis != 0 && this->map->map_visible_flag == 0) {
                            visible = vis->get_visible(start_scr_col2, map_col);
                            if (this->function_mode == 0x1E || this->function_mode == 0x1F) {
                                visible = 0x0F;
                            }
                        } else {
                            visible = vis->get_visible(start_scr_col2, map_col);
                            if (visible == 0) {
                                visible = 0x80;
                            }
                        }
                    } else {
                        visible = 0;
                    }
                    if (this->function_mode == 0x0B) {
                        RGE_Tile* t = this->map->map_row_offset[map_col] + start_scr_col2;
                        if (t->draw_as == t->last_drawn_as) {
                            visible = 0;
                        }
                    }
                    if (visible != 0x0F && visible != 0x80) {
                        visible = 0;
                    }
                    if (visible == 0 && this->function_mode != 0x0E && this->function_mode != 0x28 &&
                        this->function_mode != 0x3C && this->function_mode != 0x2A) {
                        goto col_continue;
                    }
                    if (in_bounds) {
                        tile_ptr = this->map->map_row_offset[map_col] + start_scr_col2;
                        col_num = tile_ptr->tile_type;
                        last_picked_obj = (short)(cur_col_num - (tile_ptr->field_5 >> 5) * this->elev_hgt);
                    } else {
                        tile_ptr = 0;
                        col_num = 0;
                        last_picked_obj = cur_col_num;
                    }
                    switch (col_num) {
                    case 2:
                    case 6:
                    case 8:
                    case 10:
                    case 14:
                    case 15:
                    case 16:
                        last_picked_obj -= this->elev_hgt;
                        break;
                    }
                    draw_flag = map_row > this->x_max || last_picked_obj > this->y_max ||
                        map_row + this->map->tilesizes[col_num].width <= this->x_min ||
                        last_picked_obj + this->map->tilesizes[col_num].height <= this->y_min ||
                        (this->function_mode == 0x0E &&
                         (start_scr_col2 < calc_sel_col2 || start_scr_col2 > calc_sel_row1 ||
                          map_col < calc_sel_row2 || map_col > (int)orig_picked_obj));
                    if (this->function_mode == 0x0A || this->function_mode == 0x1E || this->function_mode == 0x1F ||
                        this->function_mode == 0x20 || this->function_mode == 0x15 || this->function_mode == 0x0B ||
                        this->function_mode == 0x0E) {
                        if (draw_flag == 0 &&
                            (this->function_mode == 0x0A || this->function_mode == 0x0B || this->function_mode == 0x0E)) {
                            tile_type = tile_ptr->field_5 & 0x1F;
                            if (this->map->terrain_types[tile_type].terrain_to_draw != -1) {
                                tile_type = (unsigned char)this->map->terrain_types[tile_type].terrain_to_draw;
                            }
                            if (this->function_mode == 0x0A && this->calc_draw_count != 0 &&
                                (short)tile_type < this->map->num_terrain) {
                                this->map->terrain_types[tile_type].drawn++;
                            }
                            if (this->function_mode == 0x0B) {
                                tile_ptr->last_drawn_as = tile_ptr->draw_as;
                            }
                        }
                        if (visible == 0x0F || visible == 0x80) {
                            if (this->function_mode == 0x1E || this->function_mode == 0x1F ||
                                this->function_mode == 0x20 || this->function_mode == 0x15) {
                                if (visible == 0x0F || (visible == 0x80 && this->map->fog_flag == 0)) {
                                    tile = 0;
                                } else {
                                    tile = 1;
                                }
                                if (this->function_mode == 0x1E) {
                                    this->cur_render_area->CurSpanList = this->Terrain_Fog_Clip_Mask;
                                    fog_next_shape = 1;
                                    RGE_VIEW_OBJECTS(tile_ptr)->shadow_draw(this->cur_render_area, map_row, cur_col_num, 1, tile);
                                    this->cur_render_area->CurSpanList = this->Terrain_Clip_Mask;
                                    fog_next_shape = 0;
                                    RGE_VIEW_OBJECTS(tile_ptr)->shadow_draw(this->cur_render_area, map_row, cur_col_num, 1, tile);
                                    this->cur_render_area->CurSpanList = this->cur_render_area->SpanList;
                                }
                                if (this->function_mode == 0x1F) {
                                    this->cur_render_area->CurSpanList = this->Terrain_Fog_Clip_Mask;
                                    fog_next_shape = 1;
                                    RGE_VIEW_OBJECTS(tile_ptr)->shadow_draw(this->cur_render_area, map_row, cur_col_num, 0x0A, tile);
                                    this->cur_render_area->CurSpanList = this->Terrain_Clip_Mask;
                                    fog_next_shape = 0;
                                    RGE_VIEW_OBJECTS(tile_ptr)->shadow_draw(this->cur_render_area, map_row, cur_col_num, 0x0A, tile);
                                    this->cur_render_area->CurSpanList = this->cur_render_area->SpanList;
                                }
                                if (this->function_mode == 0x20) {
                                    if (this->map->fog_flag != 0 && visible == 0x80) {
                                        fog_next_shape = 1;
                                    }
                                    RGE_VIEW_OBJECTS(tile_ptr)->shadow_draw(this->cur_render_area, map_row, cur_col_num, 0, tile);
                                } else {
                                    if (this->function_mode != 0x15) {
                                        goto col_continue;
                                    }
                                    if (this->map->fog_flag != 0 && visible == 0x80) {
                                        fog_next_shape = 1;
                                    }
                                    RGE_VIEW_OBJECTS(tile_ptr)->normal_draw(this->cur_render_area, map_row, cur_col_num, tile);
                                }
                                fog_next_shape = 0;
                            }
                        }
                    } else {
                        if (visible == 0x0F || visible == 0x80) {
                            if (this->function_mode == 0x29 || this->function_mode == 0x2A ||
                                this->function_mode == 0x2B || this->function_mode == 0x2C) {
                                if (visible == 0x0F || (visible == 0x80 && this->map->fog_flag == 0)) {
                                    tile = 0;
                                } else {
                                    tile = 1;
                                }
                                RGE_Static_Object* obj = this->hit_object(tile_ptr, map_row, cur_col_num,
                                                                           start_scr_col2, map_col,
                                                                           (tagPOINT*)out_x, (tagPOINT*)out_obj,
                                                                           out_col, out_row, find_col, tile);
                                if (obj != 0) {
                                    if (this->function_mode == 0x2C) {
                                        fog_flag = 0x34;
                                    } else {
                                        if (find_col != 0 && obj == find_col && fog_flag == 0x34) {
                                            *out_obj = terrain_type;
                                            return 0x34;
                                        }
                                        if (terrain_type == 0 ||
                                            terrain_type->master_obj->select_level <= obj->master_obj->select_level ||
                                            (terrain_type == find_col && obj != find_col)) {
                                            *out_x = obj->world_x;
                                            *out_y = obj->world_y;
                                            fog_flag = 0x34;
                                            terrain_type = obj;
                                        }
                                    }
                                }
                            }
                        }
                        if (this->function_mode == 0x28 || (this->function_mode == 0x2A && fog_flag == 0x32)) {
                            if (this->hit_tile(tile_ptr, map_row, last_picked_obj, start_scr_col2, map_col, p1) != 0) {
                                if (tile_ptr == 0) {
                                    *out_x = (float)start_scr_col2;
                                    *out_y = (float)map_col;
                                } else {
                                    this->map->tile_map_coords((short)p1->x - map_row,
                                                               (short)p1->y - last_picked_obj,
                                                               tile_ptr, out_x, out_y);
                                    *out_x = (float)start_scr_col2 + *out_x;
                                    *out_y = (float)map_col + *out_y;
                                }
                                *out_col = map_row;
                                fog_flag = 0x33;
                                *out_row = last_picked_obj;
                                *out_obj = tile_ptr;
                            }
                        } else if (this->function_mode == 0x3C) {
                            if (start_scr_col2 == find_row && map_col == max_col_num2) {
                                *out_x = (float)start_scr_col2;
                                *out_y = (float)map_col;
                                *out_col = map_row;
                                *out_row = last_picked_obj;
                                *out_obj = tile_ptr;
                                return 0x33;
                            }
                        }
                    }
                col_continue:
                    map_row += this->tile_wid;
                    start_scr_col2++;
                    map_col++;
                    row_num++;
                } while (row_num < picked_type);
            }
            if (tile_screen_row == 1 && picked_type == max_row_num2) {
                tile_screen_row = 2;
            }
            switch (tile_screen_row) {
            case 1:
                picked_type++;
                start_scr_row2 -= this->tile_half_wid;
                start_map_row2--;
                break;
            case 2:
                picked_type--;
                start_scr_row2 += this->tile_half_wid;
                direction++;
                break;
            case 3:
                tile_screen_row = 4;
                start_scr_row2 -= this->tile_half_wid;
                start_map_row2--;
                break;
            case 4:
                start_scr_row2 += this->tile_half_wid;
                direction++;
                tile_screen_row = 3;
                break;
            }
            cur_col_num += this->tile_half_hgt;
            calc_sel_col1++;
        } while ((short)calc_sel_col1 < (short)list_size);
    }

    if (this->function_mode == 0x0A) {
        for (short i = 0; i < this->map->num_terrain; i++) {
            this->map->terrain_types[i].frame_changed = 0;
        }
    }
    if (this->function_mode == 0x29 || this->function_mode == 0x2A || this->function_mode == 0x2B) {
        if (fog_flag == 0x34) {
            *out_obj = terrain_type;
        }
    }
    return fog_flag;
}

#undef RGE_VIEW_OBJECTS
