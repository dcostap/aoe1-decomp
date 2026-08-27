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
    unsigned char border_type : 4;
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
    RGE_Map(int, RGE_Sound**, unsigned char);
    RGE_Map(char*, char*, char*, short, short, short, RGE_Sound**);
    RGE_Map(RGE_Game_World*, long, long);
    virtual ~RGE_Map();
    virtual void data_load_random_map(int);
    virtual void load_random_map(char*, char*, char*, char*);
    virtual unsigned char do_terrain_brush(long, long, long, unsigned char);
    virtual unsigned char do_terrain_brush_stroke(long, long, long, long, long,
                                                   unsigned char);
    virtual unsigned char do_elevation_brush(long, long, long, unsigned char);
    virtual unsigned char do_elevation_brush_stroke(long, long, long, long,
                                                    long, unsigned char);
    virtual unsigned char do_cliff_brush(long, long, unsigned char, unsigned char);
    virtual unsigned char do_cliff_brush_stroke(long, long, long, long,
                                                unsigned char, unsigned char);
    virtual void map_generate(RGE_Player*, RGE_Game_World*, RGE_Player_Info*,
                              unsigned char*);
    virtual void map_generate2(RGE_Game_World*, long, long, unsigned char, long);
    virtual void save(int);

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
    void set_map_visible(unsigned char);
    void set_map_fog(unsigned char);
    void clear_map(RGE_Player*, RGE_Game_World*, unsigned char, long, long);
    void clear_map(unsigned char, unsigned char);
    void new_map(long, long);
    void request_redraw(int, int, int, int, unsigned char);
    void clear_map_view_info();
    void coordinate_map();
    void set_map_screen_pos(int, int, int, int);
    void scenario_save(int);
    void scenario_load(int, unsigned char*);
    RGE_Tile** give_up_map_offsets();
    long get_map_width();
    long get_map_height();
    void preclean_elevation(long, long, long, long, unsigned char);
    unsigned char postclean_elevation(long, long, long, long, unsigned char);
    void clean_elevation(long, long, long, long, unsigned char);
    void clean_terrain(long, long, long, long, unsigned char);
    void clean_borders(long, long, long, long);
    long clean_border_tile(long, long, long (* const)[32]);
    void load_map(int);
    void save_map(int);
    void load_terrain_types(char*, RGE_Sound**);
    void load_terrain_types(RGE_Sound**);
    void load_border_types(char*, RGE_Sound**);
    void load_border_types(RGE_Sound**);
    void load_terrain_obj_types(char*);
    void delete_objects_on_tile(RGE_Player*, RGE_Game_World*, int, int, int, int);
    void delete_all_objects_on_tile(int, int);
    void create_terrain_object(RGE_Player*, RGE_Game_World*, short, short, short,
                               int, int, int);
    int clear_terrain_object(RGE_Game_World*, short, short, short, int, int, int);
    void place_terrain_object(RGE_Player*, RGE_Game_World*, short, short, int,
                              int);
    void create_terrain_objects(RGE_Player*, RGE_Game_World*);
    void set_tile_size(unsigned char, short, short, short);
    void tile_map_coords(short, short, RGE_Tile*, float*, float*);
    unsigned char check_map_coords(short, short);
    unsigned char get_elev(short, short);
    unsigned char get_terrain(short, short);
    unsigned char get_border(short, short);
    void set_terrain_passablity(short, short, short, short, unsigned char);
    void set_elev(short, short, short, short, unsigned char, short, unsigned char);
    void set_terrain(RGE_Game_World*, short, short, unsigned char, int, int);
    void set_terrain_absolute(RGE_Game_World*, short, short, unsigned char, int, int);
    // Canonical RMM object-generator overload.
    void set_terrain(RGE_Player*, RGE_Game_World*, short, short, short, short,
                     unsigned char, unsigned char, int);
    unsigned char get_tile_type(short, short);
    void get_border_type(short, short);
    void check_for_border(unsigned char, unsigned char&);
    void update(unsigned long);
    void get_point(short&, short&, float, float, float, short, short);
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
