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
// 13: tested an independent single-placement condition because the oracle reloads the mode parameter after mode zero. It improved positional diff by 12 bytes but broke size and block shape; restored the natural else-if form.
// Binary facts: terrain_types records use this+0x8C, stride 0x198, obj_types +0x18A, obj_density +0x1C6, placement flags +0x202, and num_obj_type +0x220. Player master_objects is +0x24.
// Binary behavior: get_terrain(col,row) selects each terrain set; mode 0 performs density-weighted placement and mode 1 tries one placement. Coordinates are (col - random, row - random) or (col + 0.5, row + 0.5). Failed can_place calls invoke place.
// GIVEUP: left in scratch; calls, tile ownership, coordinates, and effects are reconstructed, but VC5 still colors this as ESI and the master object as EDI instead of the oracle's EDI/ESI pair.
// 14: widened the terrain selector and object count to int; this moved the
// first block 8 bytes closer and restored the oracle's ECX selector home.
// 15: a pretested for loop without an outer count guard restored 66.27% exact
// blocks and 688 positional bytes at exact size; while/do-while forms were worse.
// 16: declaration order, map alias, and cursor initializer were emitted-code
// duplicates. Remaining drift is the EDI-this/ESI-master register basin and
// the initial pointer-setup order; calls, widths, effects, and CFG are stable.
// 17: fresh validation under the current pinned VC5 host emits 822 bytes, not
// the 832-byte historical checkpoint. The current mismatch remains 307 bytes,
// with 10 ordered calls, frame 0x30, and 88.35% exact blocks.
// 18: restored the period map.cpp header set and the complete RGE_Tile_Set,
// RGE_Map, RGE_Player, and RGE_Master_Static_Object layouts. Fresh output kept
// the same 307-byte basin. These declarations are retained as canonical context.
// 19: a nested repeated master-object guard was optimized away. Sibling mode
// arms preserved the extra test but moved the first block and produced 649 bytes
// of drift. The natural nested body is restored.
// 20: terrain-set and map pointer aliases, scoped master declarations, and a
// register-qualified master pointer did not recover the EDI/ESI basin. The
// aliases and register qualifier are removed.
// 21: fresh checks prove exact 00458600, 00459900, and 00459A00 remain intact.
// Final unresolved state: the source has the full period map context and the
// simplest behavior-preserving body. Current VC5 still assigns this/master to
// ESI/EDI instead of the oracle's EDI/ESI pair and omits its redundant mode-one
// test. No supported natural source change recovered that basin.

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

extern "C" int __cdecl debug_rand(char* file, int line);

class RGE_Player;
class RGE_Game_World;

class RGE_Master_Static_Object {
public:
    unsigned char master_type;
    unsigned char pad_05[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    unsigned char pad_16[2];
    void* sprite;
    void* death_sprite;
    void* undead_sprite;
    unsigned char undead_flag;
    unsigned char pad_25;
    short hp;
    float los;
    unsigned char obj_max;
    unsigned char pad_2D[3];
    float radius_x;
    float radius_y;
    float radius_z;
    void* selected_sound;
    void* created_sound;
    void* death_sound;
    short death_spawn_obj_id;
    unsigned char sort_number;
    unsigned char can_be_built_on;
    short button_pict;
    unsigned char hide_in_scenario_editor;
    unsigned char pad_4F;
    short portrait_pict;
    unsigned char available;
    unsigned char pad_53;
    short tile_req1;
    short tile_req2;
    short center_tile_req1;
    short center_tile_req2;
    float construction_radius_x;
    float construction_radius_y;
    unsigned char elevation_flag;
    unsigned char fog_flag;
    short terrain;
    unsigned char movement_type;
    unsigned char pad_69;
    short attribute_type_held[3];
    float attribute_amount_held[3];
    short attribute_max_amount;
    unsigned char pad_7E[2];
    float attribute_rot;
    float multiple_attribute_mod;
    unsigned char attribute_flag[3];
    unsigned char area_effect_object_level;
    unsigned char combat_level;
    unsigned char select_level;
    unsigned char map_draw_level;
    unsigned char unit_level;
    unsigned char map_color;
    unsigned char attack_reaction;
    unsigned char convert_terrain_flag;
    unsigned char damage_sprite_num;
    void* damage_sprites;
    long help_string_id;
    long help_page_id;
    long hotkey_id;
    unsigned char recyclable;
    unsigned char track_as_resource;
    unsigned char create_doppleganger_on_death;
    unsigned char resource_group;
    unsigned char draw_flag;
    unsigned char draw_color;
    unsigned char pad_AA[2];
    float outline_radius_x;
    float outline_radius_y;
    float outline_radius_z;
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void place(RGE_Player* player, float x, float y, int a);
    virtual void vf1C();
    virtual unsigned char can_place(RGE_Player* player, float x, float y,
                                     int a, int b, int c, int d, int e,
                                     int f, int g);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;
    long checksum;
    long position_checksum;
    long action_checksum;
    unsigned char checksum_created_this_update;
    unsigned char pad_21;
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    void* objects;
    void* sleeping_objects;
    void* doppleganger_objects;
    void* victory_conditions;
    void* visible;
    RGE_Game_World* world;
    void* doppleganger_creator;
    char* name;
    unsigned char type;
    unsigned char pad_49;
    short id;
    short attribute_num;
    unsigned char pad_4E[2];
    float* attributes;
    unsigned char culture;
    unsigned char pad_55[3];
    char tile_list[0x28];
    unsigned char game_status;
    unsigned char resigned;
    unsigned char pad_82[2];
    unsigned char* relations;
    int unitDiplomacy[9];
    int mutualAlly[9];
    unsigned long mutualExploredMask;
    unsigned long mutualVisibleMask;
    unsigned long nonMutualVisibleMask;
    unsigned long RemoveVisibleBits[9];
    int allied_LOS_Enable;
    unsigned char allied_victory;
    unsigned char master_player_id;
    unsigned char pad_106[2];
    void* color_table;
    long tribe_effect;
    void* VR_List;
    float view_x;
    float view_y;
    short map_x;
    short map_y;
    short selected_start_col;
    short selected_start_row;
    short selected_end_col;
    short selected_end_row;
    short replacement_terrain;
    short replacement_overlay;
    short replacement_overlay_shape;
    unsigned char pad_12E[2];
    void* selected_obj;
    void* sel_list[25];
    unsigned long sel_object_properties;
    short sel_count;
    unsigned char groups_used[127];
    unsigned char pad_end[3];
};

class RGE_Game_World {};

struct RGE_TOB_Picts {
    short count;
    short animations;
    short shape_index;
};

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
    RGE_TOB_Picts tiles[19];
    short terrain_to_draw;
    short rows;
    short cols;
    short borders[32];
    short obj_types[30];
    short obj_density[30];
    unsigned char obj_placement_flag[30];
    short num_obj_type;
    char gap_196[2];
};

struct RGE_Tile_Size {
    short width;
    short height;
    short y_delta;
};

class RGE_Border_Set {
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
    RGE_TOB_Picts borders[19][12];
    unsigned char draw_tile;
    unsigned char pad_0;
    short underlay_terrain;
    short border_style;
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
    void* map;
    long map_width;
    long map_height;
    long world_width;
    long world_height;
    RGE_Tile_Size tilesizes[19];
    unsigned char pad_8A[2];
    RGE_Tile_Set terrain_types[32];
    RGE_Border_Set border_types[16];
    void* map_row_offset;
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
    unsigned char pad_8D[3];
    unsigned char* search_map;
    unsigned char** search_map_rows;
    unsigned char map_visible_flag;
    unsigned char fog_flag;
    unsigned char pad_8DBA[2];
    void* random_map;
    RGE_Game_World* game_world;
    void* map_zones;
    void* unified_vis_map;
    void* unit_manager;

    unsigned char get_terrain(short col, short row);
    void place_terrain_object(RGE_Player* player, RGE_Game_World* world,
                              short row, short col, int object_id,
                              int single_placement);
};

void RGE_Map::place_terrain_object(RGE_Player* player, RGE_Game_World* world,
                                   short row, short col, int object_id,
                                   int single_placement)
{
    RGE_Master_Static_Object* master_obj;
    int num_obj_type;
    int terrain;
    terrain = this->get_terrain(col, row);
    num_obj_type = this->terrain_types[terrain].num_obj_type;
    int terrain_i = 0;
    float x;
    float y;

    for (terrain_i = 0; terrain_i < num_obj_type; ++terrain_i) {
            int object_type = (short)this->terrain_types[terrain].obj_types[terrain_i];
            if (object_type != -1) {
                master_obj = player->master_objects[object_type];
                short obj_density = this->terrain_types[terrain].obj_density[terrain_i];
                unsigned char obj_flag =
                    this->terrain_types[terrain].obj_placement_flag[terrain_i];

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
                                            master_obj->place(player, x, y, 0);
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
                            master_obj->place(player, x, y, 0);
                            return;
                        }
                    }
                }
            }

    }
}
