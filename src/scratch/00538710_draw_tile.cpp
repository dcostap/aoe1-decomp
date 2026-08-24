// 00538710 RGE_View::draw_tile
// Attempt log:
// try 1-10: the prior raw-offset model used the wrong parameter ABI and fake
// resolve/draw helpers; it was 842B and missed the two border helpers and five
// draw_terrain_shape sites.
// probe 1 baseline: recorded the rough scaffold before replacing it.
// probe 2: canonicalized RGE_Tile/RGE_Map/RGE_Border_Set ownership, the exact
// view.cpp helper signatures, duplicated simple/composite border calls, and the
// two binary-proven neighbor-marking paths.
// probe 3: removed the persistent map alias; resync similarity improved and the
// terrain offset became the correct map-relative 0x198 stride.
// probe 4-6: tested cached border-byte/index widths and edge-output declaration
// order; the int low-nibble index plus one cached byte recovered exact size,
// frame, and the broadest exact-block basin.
// probe 7: moved flag/result/border initialization after the loaded guard and
// combined the two early failures; this recovered the original shared tail.
// probe 8: a pTile alias was a codegen duplicate and was removed from living
// source. probe 9: retained the binary-proven comma assignment in the combined
// terrain guard.
// probe 11: reversed the terrain-count guard operands to match the original
// AX-versus-memory compare; diff improved 1056 -> 1054 bytes and first-hunk
// compare shape now matches, but the EBX tile load still follows the pushes.
// best final check: 1135B rebuilt/original, 0x28 frame, all 11 direct calls and
// target relocations aligned, 1056 strict diff bytes, 69.90% shape similarity,
// 33.87% exact-block coverage. Remaining drift is broad entry/local register
// coloring and duplicated-tail scheduling; no call/layout/ABI blocker remains.
// continuation probes: a shared done label matched the original 3-return CFG
// and raised shape similarity to 80.27%, but reduced effective size by 21B.
// Direct tile border-byte reloads moved the entry tile load into EBX before the
// saved-register pushes, matching the original first hunk, but reduced the
// frame to 0x20 and lost structural islands. Direct indexed border fields gave
// a diagnostic 824B diff, but kept the 0x20 frame and swapped the EBP/EDI
// index/base roles. Restored the pinned 0x28-frame natural source.
// probes 12-16: signed neighbor locals, a cached border index, int draw_border,
// and split initialization were duplicates or lost structural islands.
// probes 17-19: direct indexed fields in only the late border path improved
// shape and exact blocks at the same frame; a Windows header and output-order
// permutation were codegen duplicates. Ambient declaration samples made two
// basins but changed the effective size and produced no exact candidate.
// continuation probes (sa-349a0cd7-r1): restoring the earlier natural
// three-return/pointer-alias source gave exact size but a 0x24 frame, 969
// differing bytes, and 67.79% shape; it was restored because its CFG basin
// was worse. Splitting draw_border initialization was a codegen duplicate.
// Direct tile border reloads recovered the EBX tile register but reduced the
// frame to 0x20 and shape to 63.20%; a late-only reload reduced shape to
// 64.27%, and a separate top-index copy was a duplicate. Delaying result
// initialization was also a duplicate. Narrow border_type gave 982 bytes,
// 0x24 frame, and 71.77% shape. A byte border_type plus an int top_index gave
// exact size and frame but only 71.65% shape. Direct initial border fields gave
// 1039 bytes, 0x24 frame, and 68.53% shape. All variants were restored.
// Current clean unresolved source remains 1108B effective code, 0x28 frame,
// 3 returns, 11 aligned direct calls, 1049 strict diff bytes, and 80.85%
// shape. Open lead: recover the original EBX tile plus delayed EDI save while
// retaining the current natural frame and late-path CFG.
// Current clean unresolved source: 1108B effective code, 0x28 frame, 3 returns,
// 11 aligned calls, 1049 strict diff bytes, and 80.85% shape similarity.

#ifndef RGE_VIEW_SHARED_CONTEXT
struct TShape;

struct RGE_Tile {
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type;
    unsigned char border_type;
    unsigned char last_drawn_as;
    unsigned char last_drawn_shape;
    unsigned char draw_as;
    unsigned char draw_attribute;
    unsigned char last_drawn_shape2;
    char gap_0C[0x0C];
};

struct RGE_Tile_Set {
    unsigned char loaded;
    char gap_01[0x1F];
    TShape* shape;
    char gap_24[0x174];
};

struct RGE_TOB_Picts {
    short count;
    short animations;
    short shape_index;
};

struct RGE_Border_Set {
    unsigned char loaded;
    char gap_01[0x1F];
    TShape* shape;
    char gap_24[0x576];
    unsigned char draw_tile;
    unsigned char gap_59B;
    short underlay_terrain;
    short border_style;
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    RGE_Tile* map;
    long map_width;
    long map_height;
    long world_width;
    long world_height;
    char gap_18[0x74];
    RGE_Tile_Set terrain_types[32];
    RGE_Border_Set border_types[16];
    RGE_Tile** map_row_offset;
    short num_terrain;
    short num_borders;
};

class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0xF0];
};

class RGE_View : public TPanel {
public:
    char gap_F4[0x10];
    RGE_Map* map;

    short get_border_picture(unsigned char terrain_type,
                             unsigned char tile_type,
                             unsigned char border_type,
                             short x, short y);
    int get_border_edge_pictures(unsigned char terrain_type,
                                 unsigned char tile_type,
                                 unsigned char border_type,
                                 short x, short y,
                                 int* left, int* bottom,
                                 int* right, int* retval);
    short get_tile_picture(unsigned char terrain_type,
                           unsigned char tile_type, short x, short y);
    void draw_terrain_obstruction_map(int x, int y, TShape* shape,
                                      int frame, int tile_x, int tile_y);
    void draw_terrain_shape(int x, int y, TShape* shape, int frame,
                            unsigned char visibility,
                            unsigned char draw_attribute,
                            int draw1, int draw2);

    int draw_tile(RGE_Tile* tile, unsigned char terrain_type,
                  short x, short y, short map_x, short map_y,
                  unsigned char draw_attribute, int draw1, int draw2);
};
#endif

extern int View_Grid_Mode;
extern int view_debug_ObstructionMap;

int RGE_View::draw_tile(RGE_Tile* tile, unsigned char terrain_type,
                        short x, short y, short map_x, short map_y,
                        unsigned char draw_attribute, int draw1, int draw2)
{
    unsigned char draw_border = tile->draw_attribute;
    int terrain_offset;
    int overlay_available;
    int terrain_draw;
    unsigned char border_info;
    int border_type;
    int left_index;
    int right_index;
    int bottom_index;
    int retval;
    int result = 0;

    if ((short)terrain_type >= this->map->num_terrain ||
        ((terrain_offset = (int)terrain_type * (int)sizeof(RGE_Tile_Set)),
         this->map->terrain_types[terrain_type].loaded == 0)) {
        return 0;
    }

    terrain_draw = 1;
    result = 0;
    overlay_available = 0;
    border_info = tile->border_type;
    border_type = border_info & 0x0F;

    if (border_type != 0) {
        RGE_Border_Set* border = &this->map->border_types[border_type];
        if (border->loaded != 0 && border->shape != 0) {
            if (border->border_style == 0) {
                short picture = this->get_border_picture(
                    border_type, tile->tile_type,
                    (unsigned char)(border_info >> 4), map_x, map_y);
                if (picture != -1) {
                    overlay_available = 1;
                    terrain_draw = border->draw_tile;
                }
            } else {
                if (this->get_border_edge_pictures(
                        border_type, tile->tile_type,
                        (unsigned char)(border_info >> 4), map_x, map_y,
                        &left_index, &bottom_index,
                        &right_index, &retval) != 0) {
                    overlay_available = 1;
                    terrain_draw = 1;
                }
            }
        }
    }

    if (View_Grid_Mode > 0 && (draw_border & 0xDF) == 0 &&
        ((((int)map_x / View_Grid_Mode) +
          ((int)map_y / View_Grid_Mode)) & 1) == 1) {
        draw_border |= 0x20;
    }

    if (view_debug_ObstructionMap != 0) {
        overlay_available = 0;
    }

    if (terrain_draw != 0) {
        TShape* shape = this->map->terrain_types[terrain_type].shape;
        short picture = this->get_tile_picture(
            terrain_type, tile->tile_type, map_x, map_y);
        if (shape != 0 && picture != -1) {
            if (view_debug_ObstructionMap != 0) {
                this->draw_terrain_obstruction_map(
                    x, y, shape, picture, map_x, map_y);
                return 1;
            }
            this->draw_terrain_shape(
                x, y, shape, picture, draw_attribute,
                draw_border, draw1, draw2);
            result = 1;
        }

        if (overlay_available == 0) {
            if (map_x > 0) {
                RGE_Tile* left = this->map->map_row_offset[map_y] + map_x - 1;
                left->draw_attribute |= 0x40;
            }
            if (map_y < this->map->map_height - 1) {
                RGE_Tile* below = this->map->map_row_offset[map_y + 1] + map_x;
                below->draw_attribute |= 0x40;
            }
        }
    }

    if (overlay_available == 0) {
        // BINARY NOTE: The zero-overlay path joins the final return epilogue.
        goto done;
    }

    {
        // BINARY NOTE: The late path reloads the indexed border record.
        TShape* shape = this->map->border_types[border_type].shape;
        if (shape != 0) {
            if (this->map->border_types[border_type].border_style == 0) {
                short picture = this->get_border_picture(
                    border_type, tile->tile_type,
                    (unsigned char)(border_info >> 4), map_x, map_y);
                if (picture != -1) {
                    retval = picture;
                } else {
                    goto mark_neighbors;
                }
            } else {
                if (this->get_border_edge_pictures(
                        border_type, tile->tile_type,
                        (unsigned char)(border_info >> 4), map_x, map_y,
                        &left_index, &bottom_index,
                        &right_index, &retval) == 0) {
                    goto mark_neighbors;
                }
                if (left_index != -1) {
                    this->draw_terrain_shape(
                        x, y, shape, left_index, draw_attribute,
                        draw_border, draw1, draw2);
                }
                if (right_index != -1) {
                    this->draw_terrain_shape(
                        x, y, shape, right_index, draw_attribute,
                        draw_border, draw1, draw2);
                }
                if (bottom_index != -1) {
                    this->draw_terrain_shape(
                        x, y, shape, bottom_index, draw_attribute,
                        draw_border, draw1, draw2);
                }
                if (retval == -1) {
                    goto mark_neighbors;
                }
            }
            this->draw_terrain_shape(
                x, y, shape, retval, draw_attribute,
                draw_border, draw1, draw2);
        }
    }

mark_neighbors:
    if (map_x > 0) {
        RGE_Tile* left = this->map->map_row_offset[map_y] + map_x - 1;
        left->draw_attribute |= 0x40;
    }
    if (map_y < this->map->map_height - 1) {
        RGE_Tile* below = this->map->map_row_offset[map_y + 1] + map_x;
        below->draw_attribute |= 0x40;
    }

done:
    return result;
}
