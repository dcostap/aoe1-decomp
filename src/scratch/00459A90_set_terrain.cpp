// VA 00459A90 RGE_Map::set_terrain
// Fresh typed reconstruction from map.cpp:2636-2705.
// The rectangle uses short coordinates and clamps before terrain updates.
// Each eligible tile is updated before its terrain objects are rebuilt.
// Border recomputation runs before the final redraw request.
// Attempt log:
// - Replaced the prior raw-offset candidate with typed RGE_Map, RGE_Tile,
//   terrain-set, and map-row ownership. The target reads tile_type at +4 and
//   terrain_type at +5; terrain records use 0x198-byte entries.
// - Direct terrain_types access produced the best typed structural basin:
//   613 bytes, 0x10 frame, and all three calls aligned.
// - The create_terrain_object ABI and call bytes pass the tile's old terrain
//   value. A player-cast argument was a smaller diagnostic diff, but it was
//   not behaviorally valid and is not retained.
// - The source-backed row and tile byte-offset locals produce the strongest
//   structural basin: exact frame, 79.72% shape, and 35.10% exact blocks.
//   The remaining mismatch is register allocation and block placement.
// - Spelled terrain_to_draw as > -1 instead of >= 0. This reproduced the
//   original cmp ax,-1/jle eligibility block, improved the positional diff
//   from 561 to 420 bytes, and kept the typed terrain ownership natural.

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
    RGE_Map* map = this;
    short terrain_id;
    short maprow;
    short mapcol;
    int row_offset;
    int tile_offset;
    unsigned char old_value;

    if ((short)(unsigned char)terrain < map->num_terrain) {
        terrain_id = (short)(unsigned char)terrain;
        if (map->terrain_types[(unsigned char)terrain].loaded != 0 ||
            (map->terrain_types[(unsigned char)terrain].terrain_to_draw > -1 &&
             map->terrain_types[
                 map->terrain_types[(unsigned char)terrain].terrain_to_draw].loaded == 1)) {
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
            if ((int)y2 >= map->map_height)
                y2 = (short)(map->map_height - 1);
            if (x1 < 0)
                x1 = 0;
            if ((int)x2 >= map->map_width)
                x2 = (short)(map->map_width - 1);

            if ((blend != 0 || player != 0) && y1 <= y2) {
                maprow = y1;
                row_offset = (int)maprow * (int)sizeof(RGE_Tile*);
                tile_offset = (int)x1 * (int)sizeof(RGE_Tile);
                do {
                    mapcol = x1;
                    RGE_Tile* tile = (RGE_Tile*)((char*)*(RGE_Tile**)
                        ((char*)map->map_row_offset + row_offset) + tile_offset);
                    if (mapcol <= x2) {
                        do {
                            if (map->terrain_types[(unsigned char)terrain].tiles[
                                    tile->tile_type].count > 0) {
                                old_value = tile->terrain_type;
                                if ((short)(old_value & 0x1F) != terrain_id) {
                                    if (blend != 0) {
                                        tile->terrain_type =
                                            (unsigned char)((blend ^ old_value) & 0x1F) ^ old_value;
                                    }
                                }
                                if (player != 0) {
                                    map->create_terrain_object(player, world,
                                        maprow, mapcol, (short)(old_value & 0x1F),
                                        arg9, -1, -1);
                                }
                            }
                            ++mapcol;
                            ++tile;
                        } while (mapcol <= x2);
                    }
                    ++maprow;
                    row_offset += (int)sizeof(RGE_Tile*);
                } while (maprow <= y2);
            }

            if (y1 > 0)
                --y1;
            if ((int)y2 < map->map_height - 1)
                ++y2;
            if (x1 > 0)
                --x1;
            if ((int)x2 < map->map_width - 1)
                ++x2;

            maprow = y1;
            if (maprow <= y2) {
                do {
                    mapcol = x1;
                    if (mapcol <= x2) {
                        do {
                            map->get_border_type(mapcol, maprow);
                            ++mapcol;
                        } while (mapcol <= x2);
                    }
                    ++maprow;
                } while (maprow <= y2);
            }
            map->request_redraw(x1, y1, x2, y2, 0);
        }
    }
}
