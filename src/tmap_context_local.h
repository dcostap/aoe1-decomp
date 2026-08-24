#ifndef AOE1_TMAP_CONTEXT_H
#define AOE1_TMAP_CONTEXT_H

// Canonical declaration surface for the complete tmap.cpp source module.
// The owner files keep their standalone declarations for focused checks.  The
// module wrapper defines TMAP_GROUP_CONTEXT so those declarations are replaced
// by this one period-plausible class surface.

class RGE_Sound;
class RGE_Player;
class RGE_Game_World;
class RGE_Map;
class RGE_Static_Object;
class RGE_Random_Map_Module;
class TRIBE_RMM_Database_Controller;
class RGE_Tile_List;
struct RGE_Object_Node;
struct RGE_Player_Info;
typedef unsigned char uchar;

struct TRIBE_Cliff_Info {
    int info[4];
};

struct CliffMasterEntry {
    union {
        int id;
        int id_int;
    };
    union {
        int facet;
        int facet_int;
    };
    union {
        int id2;
        int id2_int;
    };
    union {
        int facet2;
        int facet2_int;
    };
    union {
        TRIBE_Cliff_Info info;
        int slot_info[4];
    };
    float offset_x;
    float offset_y;
};

struct RGE_Tile {
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    union {
        unsigned char terrain;
        struct {
            unsigned char terrain_type : 5;
            unsigned char terrain_unused : 3;
        };
    };
    union {
        unsigned char border;
        struct {
            unsigned char border_type : 4;
            unsigned char border_unused : 4;
        };
    };
    char gap_07[0x09];
    RGE_Object_Node* object_list;
    char gap_14[0x04];
};

struct RGE_Object_Node {
    RGE_Static_Object* object;
    RGE_Object_Node* next;
};

class RGE_Tile_List {
public:
    char gap_00[0x14];
    void add_node(int x, int y);
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[0x04];
    RGE_Master_Static_Object* master_obj;
    char gap_0C[0x29];
    unsigned char facet;
    char gap_36[0x02];
    float y;
    float z;
    char gap_40[0x08];
    unsigned char field_48;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual RGE_Static_Object* make_new_object(long id, float x, float y,
                                                float z, int unused);
    char gap_04[0x1E];
    short master_object_num;
    void* master_objects;
    void* objects;
    void* sleeping_objects;
    void* doppleganger_objects;
    void* victory_conditions;
    void* visible;
    char gap_3C[0x04];
    void* doppleganger_creator;
    char* name;
    char gap_48[0x04];
    short attribute_num;
    char gap_4E[0x02];
    float* attributes;
    char gap_54[0x04];
    RGE_Tile_List tile_list;
    RGE_Tile_List diam_tile_list;
};

// This class has no virtual prefix in the target field accesses.  The fields
// below preserve the tmap.cpp offsets used by the forest and cliff routines.
class RGE_Game_World {
public:
    char gap_00[0x1D];
    unsigned char game_state;
    char gap_1E[0x1E];
    short player_num;
    char gap_3E[0x02];
    RGE_Player** players;
    char gap_44[0x38];
    short curr_player;
    void check_destructables(short player_id, short master_id,
                             float x, float y, unsigned char flag);
};

class TRIBE_World : public RGE_Game_World {
public:
    void check_destructables(short player_id, short master_id,
                             float x, float y, unsigned char flag);
};

class RGE_Random_Map_Module {
public:
    virtual ~RGE_Random_Map_Module();
};

class TRIBE_RMM_Database_Controller : public RGE_Random_Map_Module {
public:
    char gap_04[0x4F58];
    TRIBE_RMM_Database_Controller(int param_1);
    TRIBE_RMM_Database_Controller(char* param_1, char* param_2,
                                  char* param_3, char* param_4);
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    RGE_Map(int, RGE_Sound**, unsigned char);
    RGE_Map(char*, char*, char*, short, short, short, RGE_Sound**);
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
    virtual void delete_cliff(long, long);

    RGE_Tile* map;
    long map_width;
    long map_height;
    long world_width;
    long world_height;
    char gap_18[0x8D8C - 0x18];
    RGE_Tile** map_row_offset;
    char gap_8D90[0x2C];
    union {
        TRIBE_RMM_Database_Controller* random_map;
        TRIBE_RMM_Database_Controller* random_map_controller;
    };
    RGE_Game_World* game_world;
    void* map_zones;
    void* unified_vis_map;
    void* unit_manager;

    void get_border_type(short row, short col);
    void set_terrain(void* world, short x, short y,
                     unsigned char type, int a, int b);
    void set_terrain(RGE_Player* player, RGE_Game_World* world,
                     int x1, int y1, long x2, long y2,
                     unsigned char type, unsigned char apply_terrain,
                     int behavior);
};

class TRIBE_Map : public RGE_Map {
public:
    virtual ~TRIBE_Map();
    union { void* Game; void* field_8DD0; };
    union { void* rge_player; void* field_8DD4; };
    union { RGE_Game_World* rge_game_world; void* field_8DD8; };
    union { void* rge_map_gen_information; int field_8DDC; };
    unsigned char* zones;
    long old_cliff_x;
    long old_cliff_y;
    long safe_cliff_x;
    long safe_cliff_y;
    long old_cliff_direction;
    CliffMasterEntry cliff_master_table[256];

    TRIBE_Map(int, RGE_Sound**, unsigned char);
    TRIBE_Map(char*, char*, char*, char*, short, short, short, RGE_Sound**);
    void save(int);
    virtual void map_generate(RGE_Player*, RGE_Game_World*, RGE_Player_Info*,
                              unsigned char*);
    void map_generate(RGE_Player_Info*);
    virtual void data_load_random_map(int);
    virtual void load_random_map(char*, char*, char*, char*);
    void check_tile_for_forest_change(short, short, RGE_Game_World*);
    void change_terrain(short, short, unsigned char, RGE_Game_World*);
    virtual unsigned char do_terrain_brush(long, long, long, unsigned char);
    virtual unsigned char do_terrain_brush_stroke(long, long, long, long, long,
                                                   unsigned char);
    virtual unsigned char do_elevation_brush_stroke(long, long, long, long,
                                                     long, unsigned char);
    void setup_cliff_type(long, long, long, long, long, long, long, long, float, float);
    RGE_Static_Object* find_cliff(long, long);
    TRIBE_Cliff_Info get_cliff_info(RGE_Static_Object*);
    unsigned char check_cliff_valid(TRIBE_Cliff_Info);
    RGE_Static_Object* make_new_cliff(long, long, TRIBE_Cliff_Info);
    void remove_cliff_edge(long, long, long);
    long reverse_cliff_direction(long);
    long add_cliff_edge(long, long, long, long, long);
    virtual void delete_cliff(long, long);
    virtual unsigned char do_cliff_brush(long, long, unsigned char, unsigned char);
    virtual unsigned char do_cliff_brush_stroke(long, long, long, long,
                                                 unsigned char, unsigned char);
    unsigned char water(unsigned char);
    void clean_borders(long, long, long, long, unsigned char);
    unsigned char do_terrain_brush_check(long, long);
    void tribe_clean_elevation(long, long, long, long);
    void tribe_clean_terrain(long, long, long, long, unsigned char, unsigned char);

    void set_terrain(void* world, short x, short y,
                     unsigned char type, int a, int b);
    void set_terrain(RGE_Player* player, RGE_Game_World* world,
                     int x1, int y1, long x2, long y2,
                     unsigned char type, unsigned char apply_terrain,
                     int behavior);
};

#endif
