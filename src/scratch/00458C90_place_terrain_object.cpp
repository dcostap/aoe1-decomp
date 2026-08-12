// 00458C90 RGE_Map::place_terrain_object
// Attempt log:
// 1: natural Ghidra-based implementation with direct terrain layout and virtual object placement calls.
// 2: first compile matched final size (832) but broad shifted mismatch: frame 0x2C vs original 0x30 and this kept in ESI not EDI.
// 3: fixed terrain-table offsets to original's this+terrain*0x198 + absolute field offsets (+0x220/+0x18A/+0x1C6/+0x202); edit diff improved 48.80% -> 46.03%.
// 4: changed get_terrain call through self local; no codegen change.
// 5: tried int terrain_id with explicit &0xff to avoid byte temp; generated too-small .text/failed size budget, rolled back.
// 6: tried volatile self local to force stack home / 0x30 frame; no codegen change, left harmless but not useful.
// 7: main blocker: prologue/local topology. Original uses EDI=this before get_terrain and homes it at [esp+38]; rebuilt uses ESI=this and a byte temp at [esp+2C].
// 8: second blocker: terrain density load/register family differs (original DI holds density and ESI object; rebuilt SI density and EDI object), cascading through both placement branches.
// 9: behavior/call set is represented (debug_rand lines, vtable +0x20/+0x18, mode 0 loop and mode 1 single placement), but register/local basin is not close enough.
// 10: replaced raw terrain cursor arithmetic with the typed RGE_Tile_Set array and named density/flag fields. This restores canonical map ownership; compile result is the baseline for this worker.
// 11: function-scope x/y locals moved the source into the best block basin: exact size/frame, 10/10 ordered calls, and 34.54% exact-block coverage.
// 12: canonical full map/Terrain_Set prefixes, an int terrain index, map alias, terrain-set pointer, repeated guard, and cursor scope variants were neutral or worse; restored the typed direct-member source.
// Binary facts: terrain_types records use this+0x8C, stride 0x198, obj_types +0x18A, obj_density +0x1C6, placement flags +0x202, and num_obj_type +0x220. Player master_objects is +0x24.
// Binary behavior: get_terrain(col,row) selects each terrain set; mode 0 performs density-weighted placement and mode 1 tries one placement. Coordinates are (col - random, row - random) or (col + 0.5, row + 0.5). Failed can_place calls invoke place.
// GIVEUP: left in scratch; calls, tile ownership, coordinates, and effects are reconstructed, but VC5 still colors this as ESI and the master object as EDI instead of the oracle's EDI/ESI pair.

extern "C" int __cdecl debug_rand(char* file, int line);

class RGE_Player;
class RGE_Game_World;

class RGE_Master_Static_Object {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void place(RGE_Player* player, float x, float y, int a, int b);
    virtual void vf1C();
    virtual unsigned char can_place(RGE_Player* player, float x, float y,
                                     int a, int b, int c, int d, int e,
                                     int f, int g);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x20];
    RGE_Master_Static_Object** master_objects;
};

class RGE_Game_World {};

class RGE_Tile_Set {
public:
    unsigned char loaded;
    unsigned char random;
    char name[13];
    char pict_name[13];
    long resource_id;
    void* shape;
    void* sound;
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
    char gap_46[0xB8];
    short obj_types[30];
    short obj_density[30];
    unsigned char obj_placement_flag[30];
    short num_obj_type;
    char gap_196[2];
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
    virtual unsigned char do_elevation_brush_stroke(long x0, long y0, long x1,
                                                    long y1, long radius,
                                                    unsigned char elevation);
    virtual unsigned char do_cliff_brush(long x, long y, unsigned char a,
                                         unsigned char b);
    virtual unsigned char do_cliff_brush_stroke(long x0, long y0, long x1,
                                                long y1, unsigned char a,
                                                unsigned char b);
    virtual void map_generate(RGE_Player*, RGE_Game_World*, void*,
                              unsigned char*);
    virtual void map_generate2(void*, long, long, unsigned char, long);
    char gap_04[0x88];
    RGE_Tile_Set terrain_types[32];
    char gap_338C[0x5A00];
    void* map_row_offset;

    unsigned char get_terrain(short col, short row);
    void place_terrain_object(RGE_Player* player, RGE_Game_World* world,
                              short row, short col, int object_id,
                              int single_placement);
};

void RGE_Map::place_terrain_object(RGE_Player* player, RGE_Game_World* world,
                                   short row, short col, int object_id,
                                   int single_placement)
{
    unsigned char terrain = get_terrain(col, row);
    short num_obj_type = terrain_types[terrain].num_obj_type;
    int terrain_i = 0;
    float x;
    float y;
    short* obj_types;

    if (num_obj_type > 0) {
        obj_types = terrain_types[terrain].obj_types;
        do {
            if (*obj_types != -1) {
                RGE_Master_Static_Object* master_obj =
                    player->master_objects[*obj_types];
                short obj_density = terrain_types[terrain].obj_density[terrain_i];
                unsigned char obj_flag =
                    terrain_types[terrain].obj_placement_flag[terrain_i];

                if (master_obj != 0) {
                    if (single_placement == 0) {
                        if (obj_density > 0) {
                            int density_left = obj_density;
                            do {
                                if (obj_flag != 0) {
                                    x = (float)(int)col - -0.5f;
                                    y = (float)(int)row - -0.5f;
                                } else {
                                    x = (float)(int)col -
                                        (float)debug_rand(
                                            "C:\\msdev\\work\\age1_x1\\map.cpp",
                                            0x894) * -3.051851e-05f;
                                    y = (float)(int)row -
                                        (float)debug_rand(
                                            "C:\\msdev\\work\\age1_x1\\map.cpp",
                                            0x895) * -3.051851e-05f;
                                }

                                int place_it;
                                if (obj_density >= 1000) {
                                    place_it = 1;
                                } else {
                                    int random_value = debug_rand(
                                        "C:\\msdev\\work\\age1_x1\\map.cpp",
                                        0x8A2);
                                    place_it =
                                        ((random_value * 1000) / 0x7fff) <
                                        density_left;
                                }

                                if (place_it) {
                                    if (!master_obj->can_place(
                                            player, x, y, 0, 0, 1, 0, 1, 0,
                                            1)) {
                                        master_obj->place(player, x, y, 0, 0);
                                    }
                                }

                                obj_density -= 1000;
                                density_left -= 1000;
                            } while (obj_density > 0);
                        }
                    } else if (single_placement == 1) {
                        if (obj_flag != 0) {
                            x = (float)(int)col - -0.5f;
                            y = (float)(int)row - -0.5f;
                        } else {
                            x = (float)(int)col -
                                (float)debug_rand(
                                    "C:\\msdev\\work\\age1_x1\\map.cpp",
                                    0x8AF) * -3.051851e-05f;
                            y = (float)(int)row -
                                (float)debug_rand(
                                    "C:\\msdev\\work\\age1_x1\\map.cpp",
                                    0x8B0) * -3.051851e-05f;
                        }

                        if (!master_obj->can_place(
                                player, x, y, 0, 0, 1, 0, 1, 0, 1)) {
                            master_obj->place(player, x, y, 0, 0);
                            return;
                        }
                    }
                }
            }

            ++terrain_i;
            ++obj_types;
        } while (terrain_i < num_obj_type);
    }
}
