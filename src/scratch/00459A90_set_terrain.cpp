// VA 00459A90 RGE_Map::set_terrain
// Fresh typed reconstruction from map.cpp:2636-2705.
// The rectangle uses short coordinates and clamps before terrain updates.
// Each eligible tile is updated before its terrain objects are rebuilt.
// Border recomputation runs before the final redraw request.
// Attempt log:
// - Replaced the prior raw-offset candidate with typed RGE_Map, RGE_Tile,
//   terrain-set, and map-row ownership. The target reads tile_type at +4 and
//   terrain_type at +5; terrain records use 0x198-byte entries.
// - The create_terrain_object ABI passes the tile's old low-five terrain.
//   A player-cast argument was a smaller diagnostic diff, but was invalid.
// - The source-backed row and tile cursor follows the proven 4-byte row-table
//   and 24-byte tile layout. All three direct calls and their order align.
// - Spelled terrain_to_draw as > -1 instead of >= 0. This reproduced the
//   original cmp ax,-1/jle eligibility block, improved the positional diff
//   from 561 to 420 bytes, and kept the typed terrain ownership natural.
// - The binary uses blend only as the update gate. The replacement low-five
//   value comes from terrain, while create_terrain_object gets old terrain.
//   The current source preserves both effects. The remaining gap is the
//   target's 0x14 local frame and EDI/EBP allocation basin.
// - Added the PDB/decompiler-supported terrain index local for repeated
//   terrain_types indexing. It is a codegen duplicate; no missing local
//   ownership resolves the 0x14 versus 0x18 frame gap.
// - Canonical ownership is now bounded by the original: RGE_Map dimensions
//   are +0x08/+0x0C, num_terrain is +0x8D90, map_row_offset is +0x8D8C,
//   RGE_Tile is 0x18 bytes with tile_type +4 and terrain_type +5, and each
//   RGE_Tile_Set is 0x198 bytes. The three calls are direct RGE_Map members.
// - The typed formal-bound loop reconstruction reaches the exact 0x14 frame,
//   exact 649-byte size, all three ordered calls, and 70.89% shape similarity.
//   Its strict diff is 505 bytes. The remaining gap is register and local
//   scheduling: the oracle keeps this in EDI, row/column cursors in EBP/ESI,
//   and terrain-index work in stack homes, while VC5 selects another basin.
// - Tested decompiler/source-dump min/max locals, named and hoisted cursors,
//   guarded do-loops, receiver aliases, full virtual prefix, stdlib headers,
//   natural index casts, and direct terrain indexing. No tested variant was
//   exact; duplicate codegen was restored to this typed formal-bound source.
// - Revisit probes: a byte-pointer/decompiler-local scan fell to 622 bytes
//   with a 0x0C frame; separate min-row/min-column locals reached 548 bytes
//   with a 5-byte size overrun. Both were rejected as structural drift.
// - A reduced virtual declaration was a codegen duplicate. An unsigned-short
//   terrain identity local reached a 504-byte diagnostic diff but added 3
//   bytes and changed the compare form. Removing the named old-terrain local
//   was also a codegen duplicate. The pinned clean source is restored.

class RGE_Player;
class RGE_Game_World;
class TShape;
class RGE_Sound;

struct RGE_TOB_Picts {
    short count;
    short animations;
    short shape_index;
};

struct RGE_Tile {
    char gap_00[4];
    unsigned char tile_type;
    unsigned char terrain_type;
    char gap_06[18];
};

class RGE_Tile_Set {
public:
    unsigned char loaded;
    unsigned char random;
    char name[13];
    char pict_name[13];
    long resource_id;
    TShape* shape;
    RGE_Sound* sound;
    unsigned char map_hi_color;
    unsigned char map_med_color;
    unsigned char map_low_color;
    unsigned char map_lt_cliff_color;
    unsigned char map_rt_cliff_color;
    unsigned char passable_terrain;
    unsigned char impassable_terrain;
    unsigned char is_animated;
    short animation_frames;
    short pause_frames;
    float interval;
    float pause_between_loops;
    short frame;
    short draw_frame;
    float animate_last;
    unsigned char frame_changed;
    unsigned char drawn;
    RGE_TOB_Picts tiles[19];
    short terrain_to_draw;
    short rows;
    short cols;
    short borders[32];
    short obj_types[30];
    short obj_density[30];
    unsigned char obj_placement_flag[30];
    short num_obj_type;
    unsigned char pad_end[2];
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    virtual void data_load_random_map(int file);
    virtual void load_random_map(char* a, char* b, char* c, char* d);
    virtual unsigned char do_terrain_brush(long x, long y, long radius,
                                           unsigned char terrain);
    virtual unsigned char do_terrain_brush_stroke(long x0, long y0, long x1,
                                                  long y1, long radius,
                                                  unsigned char terrain);
    virtual unsigned char do_elevation_brush(long x, long y, long radius,
                                             unsigned char elevation);
    virtual unsigned char do_elevation_brush_stroke(long x0, long y0,
                                                    long x1, long y1,
                                                    long radius,
                                                    unsigned char elevation);
    virtual unsigned char do_cliff_brush(long x, long y, unsigned char a,
                                         unsigned char b);
    virtual unsigned char do_cliff_brush_stroke(long x0, long y0, long x1,
                                                long y1, unsigned char a,
                                                unsigned char b);
    virtual void map_generate(RGE_Player* player, RGE_Game_World* world,
                              void* info, unsigned char* data);
    virtual void map_generate2(RGE_Game_World* world, long a, long b,
                               unsigned char terrain, long value);
    virtual void save(int file);
    RGE_Tile* map;
    long map_width;
    long map_height;
    long world_width;
    long world_height;
    char tile_size_data[0x74];
    RGE_Tile_Set terrain_types[32];
    char border_types[0x5A00];
    RGE_Tile** map_row_offset;
    short num_terrain;
    short num_borders;
    short max_terrain;
    short tile_width;
    short tile_height;
    short tile_half_height;
    short tile_half_width;
    short elev_height;
    short cur_row;
    short cur_col;
    short block_beg_row;
    short block_end_row;
    short block_beg_col;
    short block_end_col;
    unsigned char any_frame_change;
    char gap_8DAD[3];
    unsigned char* search_map;
    unsigned char** search_map_rows;
    unsigned char map_visible_flag;
    unsigned char fog_flag;
    char gap_8DBA[2];
    void* random_map;
    RGE_Game_World* game_world;
    void* map_zones;
    void* unified_vis_map;
    void* unit_manager;

    void create_terrain_object(RGE_Player* player, RGE_Game_World* world,
                               short row, short col, short old_terrain,
                               int remove_now, int min_obj_id, int max_obj_id);
    void get_border_type(short x, short y);
    void request_redraw(int x0, int y0, int x1, int y1, unsigned char value);

    void set_terrain(RGE_Player* player, RGE_Game_World* world,
                     short x1, short y1, short x2, short y2,
                     unsigned char terrain, unsigned char blend, int arg9);
};

void RGE_Map::set_terrain(RGE_Player* player, RGE_Game_World* world,
                          short x1, short y1, short x2, short y2,
                          unsigned char terrain, unsigned char blend, int arg9)
{
    short terrain_id;
    unsigned int terrain_index;

    if ((short)(unsigned char)terrain < this->num_terrain) {
        terrain_id = (short)(unsigned char)terrain;
        terrain_index = (unsigned char)terrain;
        if (this->terrain_types[terrain_index].loaded != 0 ||
            (this->terrain_types[terrain_index].terrain_to_draw > -1 &&
             this->terrain_types[
                 this->terrain_types[terrain_index].terrain_to_draw].loaded == 1)) {
            if (y1 > y2) {
                short temp = y1;
                y1 = y2;
                y2 = temp;
            }
            if (x1 > x2) {
                short temp = x1;
                x1 = x2;
                x2 = temp;
            }

            if (y1 < 0)
                y1 = 0;
            if ((int)y2 >= this->map_height)
                y2 = (short)(this->map_height - 1);
            if (x1 < 0)
                x1 = 0;
            if ((int)x2 >= this->map_width)
                x2 = (short)(this->map_width - 1);

            if ((blend != 0 || player != 0) && y1 <= y2) {
                for (short row = y1; row <= y2; ++row) {
                    if (x1 <= x2) {
                        RGE_Tile* tile =
                            this->map_row_offset[(int)row] + (int)x1;
                        for (short col = x1; col <= x2; ++col) {
                            if (this->terrain_types[terrain_index].tiles[
                                    (int)tile->tile_type].count > 0) {
                                unsigned char old_value = tile->terrain_type;
                                short old_terrain = (short)(old_value & 0x1F);
                                if (old_terrain != terrain_id && blend != 0) {
                                    tile->terrain_type =
                                        (unsigned char)((terrain ^ old_value) & 0x1F) ^ old_value;
                                }
                                if (player != 0) {
                                    this->create_terrain_object(player, world,
                                        row, col, old_terrain,
                                        arg9, -1, -1);
                                }
                            }
                            ++tile;
                        }
                    }
                }
            }

            if (y1 > 0)
                --y1;
            if ((int)y2 < this->map_height - 1)
                ++y2;
            if (x1 > 0)
                --x1;
            if ((int)x2 < this->map_width - 1)
                ++x2;

            for (short row = y1; row <= y2; ++row) {
                for (short col = x1; col <= x2; ++col) {
                    this->get_border_type(col, row);
                }
            }
            this->request_redraw(x1, y1, x2, y2, 0);
        }
    }
}
