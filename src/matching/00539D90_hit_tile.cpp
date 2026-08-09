// 00539D90 RGE_View::hit_tile (view.cpp:5709-5753, 300B)
// Tests if the given screen-space point hits the visible tile area.
//
// Attempt log:
//   baseline: existing flat/member-source reconstruction was 408B (diff 396).
//   control-flow: positive nested bounds/terrain guards reached 300B (diff 271).
//   liveness/layout: conditionally assign tile_type in the null arm and use
//     signed short locals; this recovered the original BP terrain, DX tile,
//     incoming tile-home reuse, and exact entry bytes.
//   context: canonical RGE_View:TPanel surface and exact donor call symbols.
//   final layout: map-local tilesize ownership plus tilesizes[tile_type] fixed
//     the +4 folded base-index fact. Current best is 283B, strict diff 173,
//     shape 92.52%, with 85.98% exact-block coverage.
// Left in scratch after the bounded pass: the remaining drift begins at the
// first failure-branch displacement; original extracts tile_type before the
// map load and places the shared success/failure tails 17 bytes later.
// Main-agent audit replaced numbered/decompiler map and tile types plus the raw
// vptr field with canonical polymorphic RGE_Map ownership; metrics are unchanged.
//   continuation: direct this->map tilesize expressions, with the map local
//   delayed until after the screen bounds, recovered the original movsx-before-
//   map load.  Explicit labels retain the binary-proven separate shape-success,
//   outer-success, and shared-failure tails; this source now matches exactly.
// FLAGS: /nologo /c /O2 /Oy

struct tagPOINT { long x, y; };

struct RGE_Tile {
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type;
};

struct RGE_Tile_Size {
    short width;
    short height;
    short y_delta;
};

struct TShape {
    virtual ~TShape();
    unsigned char shape_check(long dx, long dy, int pic);
};

struct RGE_Tile_Set {
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

class RGE_Map {
public:
    virtual ~RGE_Map();
    RGE_Tile* map_tiles;
    long map_width;
    long map_height;
    long world_width;
    long world_height;
    RGE_Tile_Size tilesizes[19];
    char _pad_8A[2];
    RGE_Tile_Set terrain_types[32];
    char _pad_338C[0x5A04];
    short num_terrain;
};

class TPanel {
public:
    virtual ~TPanel();
    char _gap_04[0xF0];
};

class RGE_View : public TPanel {
public:
    char _gap_F4[0x10];
    RGE_Map* map;

    short get_tile_picture(unsigned char terrain, unsigned char tile,
                           short a, short b);
    int hit_tile(RGE_Tile* tile, short sx, short sy,
                 short a, short b, tagPOINT* pt);
};

int RGE_View::hit_tile(RGE_Tile* tile, short sx, short sy,
                        short a, short b, tagPOINT* pt)
{
    short terrain_type = 0;
    short tile_type;

    if (tile) {
        tile_type = tile->tile_type;
        terrain_type = tile->terrain_type & 0x1F;
    } else {
        tile_type = 0;
    }

    if (pt->x >= sx) {
        if (pt->x < sx + this->map->tilesizes[(int)tile_type].width &&
            pt->y >= sy &&
            pt->y < sy + this->map->tilesizes[(int)tile_type].height) {
            RGE_Map* map = this->map;
            if (terrain_type < map->num_terrain &&
                map->terrain_types[terrain_type].loaded) {
                TShape* sh = map->terrain_types[terrain_type].shape;
                short pic = this->get_tile_picture(terrain_type, (unsigned char)tile_type, a, b);

                if (sh == 0 || pic == -1)
                    goto outer_success;

                if (pt->y >= sy + this->map->tilesizes[(int)tile_type].height)
                    goto failure;
                if (!sh->shape_check(pt->x - sx, pt->y - sy, pic))
                    goto failure;
                goto shape_success;

            shape_success:
                return 1;
            outer_success:
                return 1;
            failure:
                return 0;
            }
            return 1;
        }
    }

    return 0;
}
