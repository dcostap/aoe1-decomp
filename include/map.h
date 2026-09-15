#ifndef AOE1_MAP_H
#define AOE1_MAP_H

#include "obj_list.h"

struct RGE_Player_Info;
class TShape;
class RGE_Sound;
class RGE_Player;
class RGE_Game_World;
class RGE_RMM_Database_Controller;
class RGE_Zone_Map_List;
class RGE_Unified_Visible_Map;
class Visible_Unit_Manager;

struct RGE_TOB_Picts {
    short count;
    short animations;
    short shape_index;
};

struct RGE_Tile_Size {
    short width;
    short height;
    short y_delta;
};

struct RGE_Tile {
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type : 5;
    unsigned char height : 3;
    unsigned char border_type : 4;
    unsigned char border_shape : 4;
    unsigned char last_drawn_as;
    unsigned char last_drawn_shape;
    unsigned char draw_as;
    unsigned char draw_attribute;
    unsigned char last_drawn_shape2;
    RGE_Object_List objects;
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
};

class RGE_Border_Set {
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
    short underlay_terrain;
    short border_style;
};

class RGE_Map {
public:
    RGE_Map(int infile, RGE_Sound** sounds, unsigned char setup);
    RGE_Map(char* border_tbl, char* terrain_tbl, char* map_tbl, short TileWid,
            short TileHgt, short ElevHgt, RGE_Sound** sounds);
    RGE_Map(RGE_Game_World*, long, long);
    virtual ~RGE_Map();
    virtual void data_load_random_map(int infile);
    virtual void load_random_map(char* rmm_map_file, char* rmm_land_file, char* rmm_terr_file, char* rmm_obj_file);
    virtual unsigned char do_terrain_brush(long x, long y, long brush_size, unsigned char terrain_id);
    virtual unsigned char do_terrain_brush_stroke(long x1, long y1, long x2, long y2,
                                                   long brush_size, unsigned char terrain_id);
    virtual unsigned char do_elevation_brush(long x, long y, long brush_size, unsigned char elevation_height);
    virtual unsigned char do_elevation_brush_stroke(long x1, long y1, long x2, long y2,
                                                     long brush_size, unsigned char elevation_height);
    virtual unsigned char do_cliff_brush(long x, long y, unsigned char cliff_id, unsigned char delete_cliff);
    virtual unsigned char do_cliff_brush_stroke(long x1, long y1, long x2, long y2,
                                                unsigned char cliff_id, unsigned char delete_cliff);
    virtual void map_generate(RGE_Player* owner, RGE_Game_World* gworld,
                              RGE_Player_Info* player_info, unsigned char* zone_terrain);
    virtual void map_generate2(RGE_Game_World* gworld, long new_width, long new_height,
                               unsigned char type, long player_num);
    virtual void save(int outfile);

    RGE_Tile* map;
    long map_width;
    long map_height;
    long world_width;
    long world_height;
    RGE_Tile_Size tilesizes[19];
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
    unsigned char* search_map;
    unsigned char** search_map_rows;
    unsigned char map_visible_flag;
    unsigned char fog_flag;
    RGE_RMM_Database_Controller* random_map;
    RGE_Game_World* game_world;
    RGE_Zone_Map_List* map_zones;
    RGE_Unified_Visible_Map* unified_vis_map;
    Visible_Unit_Manager* unit_manager;

    void init_tile_sizes();
    void set_map_visible(unsigned char flag);
    void set_map_fog(unsigned char flag);
    void clear_map(RGE_Player* player, RGE_Game_World* world, unsigned char new_terrain, long width, long height);
    void clear_map(unsigned char terrain, unsigned char elev);
    void new_map(long width, long height);
    void request_redraw(int x1, int y1, int x2, int y2, unsigned char attribute);
    void clear_map_view_info();
    void coordinate_map();
    void set_map_screen_pos(int x1, int y1, int x2, int y2);
    void scenario_save(int outfile);
    void scenario_load(int infile, unsigned char* zone_terrain);
    RGE_Tile** give_up_map_offsets();
    long get_map_width();
    long get_map_height();
    void preclean_elevation(long x1, long y1, long x2, long y2, unsigned char elevation_height);
    unsigned char postclean_elevation(long x1, long y1, long x2, long y2, unsigned char elevation_height);
    void clean_elevation(long x1, long y1, long x2, long y2, unsigned char elevation_height);
    void clean_terrain(long x1, long y1, long x2, long y2, unsigned char replacement_terrain);
    void clean_borders(long x1, long y1, long x2, long y2);
    long clean_border_tile(long this_terrain, long other_terrain, long (* const matrix)[32]);
    void load_map(int infile);
    void save_map(int outfile);
    void load_terrain_types(char* terrain_table, RGE_Sound** sounds);
    void load_terrain_types(RGE_Sound** sounds);
    void load_border_types(char* border_table, RGE_Sound** sounds);
    void load_border_types(RGE_Sound** sounds);
    void load_terrain_obj_types(char* terr_obj_tbl);
    void delete_objects_on_tile(RGE_Player* obj_owner, RGE_Game_World* gworld, int x, int y,
                                int no_delete_start, int no_delete_end);
    void delete_all_objects_on_tile(int x, int y);
    void create_terrain_object(RGE_Player* obj_owner, RGE_Game_World* gworld, short row, short col,
                               short old_terrain, int delete_obj, int no_delete_start, int no_delete_end);
    int clear_terrain_object(RGE_Game_World* gworld, short row, short col, short old_terrain,
                             int delete_obj, int no_delete_start, int no_delete_end);
    void place_terrain_object(RGE_Player* player, RGE_Game_World* gworld, short row, short col,
                              int obj_type_id, int FillFlag);
    void create_terrain_objects(RGE_Player* obj_owner, RGE_Game_World* gworld);
    void set_tile_size(unsigned char tile_type, short width, short height, short y_delta);
    void tile_map_coords(short x, short y, RGE_Tile* tile, float* offset_x, float* offset_y);
    unsigned char check_map_coords(short mapcol, short maprow);
    unsigned char get_elev(short mapcol, short maprow);
    unsigned char get_terrain(short mapcol, short maprow);
    unsigned char get_border(short mapcol, short maprow);
    void set_terrain_passablity(short mapcol1, short maprow1, short mapcol2, short maprow2, unsigned char passabilty);
    void set_elev(short mapcol1, short maprow1, short mapcol2, short maprow2,
                  unsigned char elev, short delta, unsigned char set_flag);
    void set_terrain(RGE_Game_World* gworld, short mapcol, short maprow, unsigned char terrain,
                     int no_delete_start, int no_delete_end);
    void set_terrain_absolute(RGE_Game_World* gworld, short mapcol, short maprow, unsigned char terrain,
                              int no_delete_start, int no_delete_end);
    // Canonical RMM object-generator overload.
    void set_terrain(RGE_Player* obj_owner, RGE_Game_World* gworld, short mapcol1, short maprow1,
                     short mapcol2, short maprow2, unsigned char terrain, unsigned char set_flag,
                     int delete_obj);
    unsigned char get_tile_type(short map_col, short map_row);
    void get_border_type(short map_col, short map_row);
    void check_for_border(unsigned char cur_ter, unsigned char& bor_ter);
    void update(unsigned long world_time);
    void get_point(short& screen_x, short& screen_y, float x, float y, float z,
                   short x_offset, short y_offset);
};

typedef char rge_tob_picts_size_check[
    (sizeof(RGE_TOB_Picts) == 0x06) ? 1 : -1];
typedef char rge_tile_size_check[(sizeof(RGE_Tile_Size) == 0x06) ? 1 : -1];
typedef char rge_tile_struct_size_check[
    (sizeof(RGE_Tile) == 0x18) ? 1 : -1];
typedef char rge_tile_set_size_check[
    (sizeof(RGE_Tile_Set) == 0x198) ? 1 : -1];
typedef char rge_border_set_size_check[
    (sizeof(RGE_Border_Set) == 0x5A0) ? 1 : -1];
typedef char rge_map_size_check[(sizeof(RGE_Map) == 0x8DD0) ? 1 : -1];

#endif
