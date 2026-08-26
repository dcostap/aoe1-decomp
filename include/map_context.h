#ifndef MAP_CONTEXT_H
#define MAP_CONTEXT_H

// PDB source: C:\\msdev\\work\\age1_x1\\map.cpp.
// This surface covers the RGE_Map owners in src/map_tu.cpp.
// The field aliases retain the proven map offsets while supporting the
// historical declaration spellings used across this source module.

class TShape;
class RGE_Sound;
class RGE_Player;
class RGE_Game_World;
struct RGE_Player_Info;
class RGE_Map;
class RGE_Static_Object;
class RGE_RMM_Database_Controller;
class RGE_Random_Map_Module;
class RGE_Zone_Map_List;
class RGE_Unified_Visible_Map;
class Visible_Unit_Manager;
struct RGE_Object_Node;
struct RGE_Tile;

#ifdef MAP_CONTEXT_TU
class RGE_Sound {
public:
    char gap_00[0x0C];
    short id;
};

struct RGE_Map_Copy {
    char bytes[0x8DD0];
};

extern "C" void __cdecl rge_write(int, void*, int);
extern "C" void __cdecl rge_read(int, void*, int);

struct RGE_Tile {
    union {
        short screen_xpos;
        short screen_xpos_word;
    };
    short screen_ypos;
    unsigned char tile_type;
    union {
        unsigned char terrain_type;
        unsigned char terrain_elevation;
        unsigned char terrain_elev;
        unsigned char terrain_info;
        unsigned char terrain;
        unsigned char elev_and_terrain;
    };
    union {
        unsigned char border_type;
        unsigned char border;
    };
    unsigned char last_drawn_as;
    unsigned char last_drawn_shape;
    unsigned char draw_as;
    unsigned char draw_attribute;
    unsigned char last_drawn_shape2;
    union {
        struct {
            RGE_Object_Node* list;
            int number_of_objects;
        } objects;
        RGE_Object_Node* objects_list;
        RGE_Object_Node* list;
    };
    unsigned char gap_14[4];
};
#endif

struct RGE_Tile_Size {
    short width;
    short height;
    short y_delta;
};

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
    unsigned char pad_0;
    short underlay_terrain;
    short border_style;
};

#ifdef MAP_CONTEXT_TU
class TShape {
public:
    TShape();
    TShape(char*, long);
    ~TShape();
    int is_loaded();
};

class RGE_Object_List {
public:
    void removeAllObjects();
};

struct RGE_Object_Node {
    union {
        RGE_Object_Node* next;
        RGE_Static_Object* node;
    };
    RGE_Static_Object* object;
};

class RGE_Master_Static_Object {
public:
    long id;
    void* terrain_info;
    int terrain_type;
    int terrain_elevation;
    int can_place(...);
    void place(...);
    int check_placement(...);
};

class RGE_Static_Object {
public:
    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    float world_x;
    float world_y;
    float world_z;
    RGE_Tile* tile;
    void delete_object(int);
    void destroy_obj();
    void teleport(float, float, float);
};

class StaticObject_VTableHelper : public RGE_Static_Object {
public:
    void release(int);
};

class RGE_Tile_List {
public:
    RGE_Object_Node* list;
    int count;
    void add_node(int, int);
};

class RGE_Player {
public:
    char gap_00[0x28];
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    RGE_Game_World* world;
    RGE_Master_Static_Object** master_objects;
    RGE_Tile_List diam_tile_list;
};

class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
    unsigned char game_state;
    short curr_player;
    void reset_object_count();
    void reset_player_visible_maps();
};

class RGE_Base_Game {
public:
    char gap_00[0x3F4];
    RGE_Game_World* world;
    int random_map_seed;
    int save_random_map_seed;
};
extern RGE_Base_Game* rge_base_game;

class TDebuggingLog {
public:
    void Log(const char*, ...);
};
extern TDebuggingLog* L;

class RGE_Random_Map_Module {
public:
    virtual ~RGE_Random_Map_Module();
    void init(RGE_Map*, RGE_Game_World*, long, long, int);
    void generate();
    void de_init();
};

class RGE_RMM_Database_Controller : public RGE_Random_Map_Module {
public:
    RGE_Game_World* world;
    RGE_RMM_Database_Controller(int);
    RGE_RMM_Database_Controller(char*, char*, char*, char*);
    void save(int);
};

class RGE_Zone_Map_List {
public:
    RGE_Zone_Map_List(RGE_Map*);
    RGE_Zone_Map_List(int, RGE_Map*);
    ~RGE_Zone_Map_List();
    void save(int);
};

class RGE_Unified_Visible_Map {
public:
    RGE_Unified_Visible_Map(int, int);
    ~RGE_Unified_Visible_Map();
    void load(int);
    void save(int);
};

class Visible_Unit_Manager {
public:
    Visible_Unit_Manager(int, int);
    ~Visible_Unit_Manager();
};

#endif

class RGE_Map {
public:
    RGE_Map(int, RGE_Sound**, unsigned char);
    RGE_Map(char*, char*, char*, short, short, short, RGE_Sound**);
    RGE_Map(RGE_Game_World*, long, long);
    virtual ~RGE_Map();
    virtual void data_load_random_map(int file);
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
    RGE_Tile* map;
    union {
        int map_width;
        int field_8;
    };
    union {
        int map_height;
        int field_C;
    };
    long world_width;
    long world_height;
    RGE_Tile_Size tilesizes[19];
    unsigned char pad_8A[2];
    RGE_Tile_Set terrain_types[32];
    RGE_Border_Set border_types[16];
    union {
        RGE_Tile** map_row_offset;
        RGE_Tile** map_rows;
        int field_8D8C;
    };
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
    unsigned char pad_8DAD[3];
    unsigned char* search_map;
    unsigned char** search_map_rows;
    union {
        unsigned char map_visible_flag;
        unsigned char field_8DB8;
    };
    union {
        unsigned char fog_flag;
        unsigned char field_8DB9;
    };
    unsigned char pad_8DBA[2];
    union {
        RGE_RMM_Database_Controller* random_map;
        RGE_RMM_Database_Controller* random_map_controller;
    };
    RGE_Game_World* game_world;
    RGE_Zone_Map_List* map_zones;
    RGE_Unified_Visible_Map* unified_vis_map;
    Visible_Unit_Manager* unit_manager;

    void preclean_elevation(long, long, long, long, unsigned char);
    unsigned char postclean_elevation(long, long, long, long, unsigned char);
    void clean_elevation(long, long, long, long, unsigned char);
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
    void clean_terrain(long, long, long, long, unsigned char);
    void clean_borders(long, long, long, long);
    long clean_border_tile(long, long, long (* const)[32]);
    void map_generate2(void*, long, long, unsigned char, long);
    void load_map(int);
    void save_map(int);
    void save(int);
    void load_terrain_types(char*, RGE_Sound**);
    void load_terrain_types(RGE_Sound**);
    void load_border_types(char*, RGE_Sound**);
    void load_border_types(RGE_Sound**);
    void load_terrain_obj_types(char*);
    void delete_objects_on_tile(RGE_Player*, RGE_Game_World*, int, int, int,
                                int);
    void delete_all_objects_on_tile(int, int);
    void create_terrain_object(RGE_Player*, RGE_Game_World*, short, short, short,
                               int, int, int);
    int clear_terrain_object(RGE_Game_World*, short, short, short, int, int,
                             int);
    void place_terrain_object(RGE_Player*, RGE_Game_World*, short, short, int,
                              int);
    void create_terrain_objects(RGE_Player*, RGE_Game_World*);
    void set_tile_size(unsigned char, short, short, short);
    void set_elev(short, short, short, short, unsigned char, short, unsigned char);
    void tile_map_coords(short, short, RGE_Tile*, float*, float*);
    unsigned char check_map_coords(short, short);
    unsigned char get_elev(short, short);
    unsigned char get_terrain(short, short);
    unsigned char get_border(short, short);
    void set_terrain_passablity(short, short, short, short, unsigned char);
    void check_for_border(unsigned char, unsigned char&);
    void get_border_type(short, short);
    void set_terrain(RGE_Game_World*, short, short, unsigned char, int, int);
    void set_terrain_absolute(RGE_Game_World*, short, short, unsigned char, int,
                              int);
    void set_terrain(RGE_Player*, RGE_Game_World*, short, short, short, short,
                     unsigned char, unsigned char, int);
    unsigned char get_tile_type(short, short);
    void update(unsigned long time);
    void get_point(short&, short&, float, float, float, short, short);
};

#endif
