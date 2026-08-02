// TRIBE_Map::tribe_clean_elevation
// VA: 005110E0, tmap.cpp:1067-1087
// ACCEPTED_DRIFT: manually reviewed ESI/EDI allocation and prologue scheduling
// only. Original keeps `this` in ESI and the x cursor in EDI; rebuilt swaps those
// roles and loads x immediately before saving EDI. All predicates, addresses,
// field widths, loop updates, three call targets, stack arguments, cleanup, and
// return behavior are identical. Invalid-object/debug exception context can show
// the swapped registers, but no program-memory or supported callee-visible effect
// differs.
// Status: PAUSED in scratch - VC5 register allocation (esi vs edi swap)
//
// Attempt log:
// v0: Basic implementation, extern "C" set_terrain → 181 bytes, 31% diff
// v1: Member function set_terrain → 176 bytes, register issues
// v2: Local vars, while+goto loop structure → 12% positional diff
// v3: Direct param manipulation → 12%, same register swap
// v4: Short variable names (xc, tr, row, etc.) → 12%, same issue
// Retry 2026-05-26 Boss pass: 16 more probes. Revalidated current scratch (181B,
// 22 positional / 25 edit, first mismatch +3). Tried for/positive outer loop,
// direct row expressions, pointer rowbase, self alias/register self, parameter-slot reuse,
// no-continue forms, x-local before self, register x local, self declared after clips,
// x_start2 temp, and reloading x from the parameter slot. All non-regressing variants
// stayed in the same this-vs-x register swap family; attempts to force x into EDI and
// this into ESI regressed broadly (~150 positional). No accepted_drift proposal because
// although behavior is equivalent, the diff is a whole-function register-coloring swap.
//
// Retry 2026-08-02 Luna5110E0: baseline and nine source/layout/context probes plus a
// final canonical tile-type probe. Restored the donor RGE_Map/TRIBE_Map field surface,
// PDB long widths, typed set_terrain ABI, full tile/border arrays, polymorphic destructor
// declarations, inherited call qualification, and RGE_Tile::terrain_type bitfield access.
// Every probe stayed at 181 bytes with 22 positional / 25 edit bytes; all three direct
// call sites and the complete loop body remained aligned. register-parameter, mixed
// cursor widths, direct byte expression, full class context, and base-call variants were
// codegen duplicates. No accepted_drift proposal: the remaining drift is a whole-function
// ESI/EDI coloring swap (original ESI=this/EDI=x; rebuild EDI=this/ESI=x).
//
// Struct layout:
//   RGE_Map: exact 0x8DD0 layout with tile-size/terrain/border arrays,
//            map_row_offset(+0x8D8C), game_world(+0x8DC0)
//   TRIBE_Map: exact 0xB5F8 layout through cliff_master_table
//
// Final validated metrics: 181 bytes, ret 10h; 22 positional (12.1547%),
// 25 edit/resync (13.81%), 100% ordered-call alignment.

struct RGE_Game_World;
struct RGE_Object_List { char bytes[0xC]; };
struct RGE_Tile {
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type : 5;
    unsigned char border_type : 4;
    unsigned char last_drawn_as;
    unsigned char last_drawn_shape;
    unsigned char draw_as;
    unsigned char draw_attribute;
    unsigned char last_drawn_shape2;
    RGE_Object_List objects;
};
struct RGE_Tile_Size {
    short width;
    short height;
    short y_delta;
};
struct RGE_Tile_Set { char bytes[0x198]; };
struct RGE_Border_Set { char bytes[0x5A0]; };

struct RGE_Map {
    virtual ~RGE_Map();
    RGE_Tile* map;
    long map_width;
    long map_height;
    long world_width;
    long world_height;
    RGE_Tile_Size tilesizes[19];
    unsigned char gap_8A[2];
    RGE_Tile_Set terrain_types[32];
    RGE_Border_Set border_types[16];
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
    unsigned char gap_8DAD[3];
    unsigned char* search_map;
    unsigned char** search_map_rows;
    unsigned char map_visible_flag;
    unsigned char fog_flag;
    unsigned char gap_8DBA[2];
    void* random_map;
    RGE_Game_World* game_world;
    void* map_zones;
    void* unified_vis_map;
    void* unit_manager;

    void set_terrain(RGE_Game_World* world, short x, short y,
                     unsigned char type, int a, int b);
};

struct TRIBE_Map : RGE_Map {
    virtual ~TRIBE_Map();
    void* Game;
    void* rge_player;
    RGE_Game_World* rge_game_world;
    void* rge_map_gen_information;
    unsigned char* zones;
    long old_cliff_x;
    long old_cliff_y;
    long safe_cliff_x;
    long safe_cliff_y;
    long old_cliff_direction;
    char cliff_master_table[0x2800];

    unsigned char water(unsigned char elevation);
    unsigned char do_terrain_brush_check(long x, long y);
    void tribe_clean_elevation(long x_start, long y_start, long x_end, long y_end);
};

void TRIBE_Map::tribe_clean_elevation(long x_start, long y_start, long x_end, long y_end)
{
    if (x_start < 0)
        x_start = 0;
    if (y_start < 0)
        y_start = 0;
    if (x_end >= map_width)
        x_end = map_width - 1;
    if (y_end >= map_height)
        y_end = map_height - 1;

    for (; y_start <= y_end; ++y_start) {
        if (x_start <= x_end) {
            long x = x_start;
            do {
                if (water(map_row_offset[y_start][x].terrain_type)) {
                    if (!do_terrain_brush_check(x, y_start)) {
                        RGE_Map::set_terrain(game_world, (short)x, (short)y_start, 0, 0, 0);
                    }
                }
                ++x;
            } while (x <= x_end);
        }
    }
}
