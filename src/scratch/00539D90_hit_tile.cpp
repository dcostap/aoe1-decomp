// 00539D90 RGE_View::hit_tile (view.cpp:5709-5753, 300B)
// Tests if the given screen-space point hits the visible tile area.
//
// Left in scratch: VC5 register allocation differs fundamentally from original.
// Original uses ebp=0/terrain_type, dx=tile_type, ebx=screen_x, [esp+10h]=this.
// Rebuilt uses esi=tile_type, cl/stack=terrain_type, ebx=this, [esp+2Ch]=point.
// Map pointer register differs: ecx (orig, overwrites this) vs edx (rebuilt).
// All field offsets (+0x104 map, +0x18 tilesizes, +0x8C terrain_types, +0x8D90
// num_terrain, +0xAC shape, +0x1A height), struct sizes, and logic verified
// correct. `get_tile_picture` and `shape_check` call signatures matched.
// Needs variant_lab pass to find source form that forces original register layout.
// FLAGS: /nologo /c /O2 /Oy

struct tagPOINT { long x, y; };

struct RGE_Tile2 {
    char _gap_00[4];
    unsigned char tile_type;
    unsigned char field_5;
};

struct RGE_Tile_Size2 {
    short width;
    short height;
    short y_delta;
};

struct TShape {
    char _gap_00[4];
    unsigned char shape_check(long dx, long dy, int pic);
};

struct RGE_Tile_Set2 {
    unsigned char loaded;
    unsigned char random;
    char name[13];
    char pict_name[13];
    long resource_id;
    TShape* shape;
    char _gap_24[4];
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
    short tiles[19][3];
    short terrain_to_draw;
    short rows;
    short cols;
    short borders[32];
    short obj_types[30];
    short obj_density[30];
    unsigned char obj_placement_flag[30];
    short num_obj_type;
};

struct RGE_Map2 {
    void* vtable_ptr;
    RGE_Tile2* map_tiles;
    long map_width;
    long map_height;
    long world_width;
    long world_height;
    RGE_Tile_Size2 tilesizes[19];
    char _pad_8A[2];
    RGE_Tile_Set2 terrain_types[32];
    char _pad_338C[0x5A04];
    short num_terrain;
};

struct RGE_View6 {
    char _pad_00[0x104];
    RGE_Map2* map;

    short get_tile_picture(unsigned char terrain, unsigned char tile,
                           short a, short b);
    int hit_tile(RGE_Tile2* tile, short sx, short sy,
                 short a, short b, tagPOINT* pt);
};

int RGE_View6::hit_tile(RGE_Tile2* tile, short sx, short sy,
                        short a, short b, tagPOINT* pt)
{
    unsigned short tile_type = 0;
    unsigned char terrain_type = 0;

    if (tile) {
        tile_type = tile->tile_type;
        terrain_type = tile->field_5 & 0x1F;
    }

    if (pt->x < sx) return 0;
    if (pt->x >= sx + map->tilesizes[tile_type + 4].width) return 0;
    if (pt->y < sy) return 0;
    if (pt->y >= sy + map->tilesizes[tile_type].height) return 0;

    if (terrain_type >= map->num_terrain) return 1;
    if (!map->terrain_types[terrain_type].loaded) return 1;

    {
        TShape* sh = map->terrain_types[terrain_type].shape;
        short pic = get_tile_picture(terrain_type, (unsigned char)tile_type, a, b);

        if (!sh) return 1;
        if (pic == -1) return 1;
        if (pt->y >= sy + map->tilesizes[tile_type].height) return 0;
        if (!sh->shape_check(pt->x - sx, pt->y - sy, pic)) return 0;
    }

    return 1;
}
