// VA: 004550A0 RGE_Map::RGE_Map
// Attempt log:
// baseline reconstruction: canonical map.cpp class/terrain/border ownership,
// natural tile-size calls, and the observed zero-initialization loops.

class RGE_Sound;
class RGE_Tile;
class RGE_Player;
class RGE_Game_World;
class RGE_RMM_Database_Controller;
class RGE_Zone_Map_List;
class RGE_Unified_Visible_Map;
class Visible_Unit_Manager;
class TShape;

class RGE_Base_Game {
public:
    char gap_00[0x3F4];
    RGE_Game_World* world;
};

class RGE_Game_World {
};

extern RGE_Base_Game* rge_base_game;

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

class RGE_Map {
public:
    virtual ~RGE_Map();
    virtual void data_load_random_map(int file);
    virtual void load_random_map(char*, char*, char*, char*);
    virtual unsigned char do_terrain_brush(long, long, long, unsigned char);
    virtual unsigned char do_terrain_brush_stroke(long, long, long, long, long, unsigned char);
    virtual unsigned char do_elevation_brush(long, long, long, unsigned char);
    virtual unsigned char do_elevation_brush_stroke(long, long, long, long, long, unsigned char);
    virtual unsigned char do_cliff_brush(long, long, unsigned char, unsigned char);
    virtual unsigned char do_cliff_brush_stroke(long, long, long, long, unsigned char, unsigned char);
    virtual void map_generate(RGE_Player*, RGE_Game_World*, void*, unsigned char*);
    virtual void map_generate2(void*, long, long, unsigned char, long);

    RGE_Tile* map;
    long map_width;
    long map_height;
    long world_width;
    long world_height;
    RGE_Tile_Size tilesizes[19];
    unsigned char pad_8A[2];
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
    unsigned char pad_8D[3];
    unsigned char* search_map;
    unsigned char** search_map_rows;
    unsigned char map_visible_flag;
    unsigned char fog_flag;
    unsigned char pad_8DBA[2];
    RGE_RMM_Database_Controller* random_map;
    RGE_Game_World* game_world;
    RGE_Zone_Map_List* map_zones;
    RGE_Unified_Visible_Map* unified_vis_map;
    Visible_Unit_Manager* unit_manager;

    RGE_Map(char*, char*, char*, short, short, short, RGE_Sound**);
    void set_tile_size(unsigned char, short, short, short);
    void load_terrain_types(char*, RGE_Sound**);
    void load_border_types(char*, RGE_Sound**);
};

RGE_Map::RGE_Map(char* border_file, char* terrain_file, char* unused_file,
                 short tile_width_arg, short tile_height_arg,
                 short elev_height_arg, RGE_Sound** sounds)
{
    int i;
    int j;

    this->map_zones = 0;
    this->random_map = 0;
    this->game_world = rge_base_game->world;

    this->tile_width = tile_width_arg;
    this->tile_half_width = tile_width_arg / 2;
    this->tile_height = tile_height_arg;
    this->tile_half_height = tile_height_arg / 2;
    this->elev_height = elev_height_arg;
    this->map_width = 0;
    this->map_height = 0;
    this->world_width = 0;
    this->world_height = 0;

    this->set_tile_size(0, tile_width_arg, tile_height_arg, 0);
    this->set_tile_size(1, this->tile_width, this->elev_height, -100);
    this->set_tile_size(2, this->tile_width, this->elev_height + this->tile_height, 100);
    this->set_tile_size(3, this->tile_width, this->tile_height, -100);
    this->set_tile_size(4, this->tile_width, this->tile_height, -100);
    this->set_tile_size(5, this->tile_width, this->elev_height, -100);
    this->set_tile_size(6, this->tile_width, this->elev_height + this->tile_height, 100);
    this->set_tile_size(7, this->tile_width, this->elev_height, -100);
    this->set_tile_size(8, this->tile_width, this->elev_height + this->tile_height, 100);
    this->set_tile_size(9, this->tile_width, this->elev_height, -100);
    this->set_tile_size(10, this->tile_width, this->elev_height + this->tile_height, 100);
    this->set_tile_size(11, this->tile_width, this->tile_height, -100);
    this->set_tile_size(12, this->tile_width, this->tile_height, -100);
    this->set_tile_size(13, this->tile_width, this->elev_height, -100);
    this->set_tile_size(14, this->tile_width, this->elev_height + this->tile_height, 100);
    this->set_tile_size(15, this->tile_width, this->tile_height, 100);
    this->set_tile_size(16, this->tile_width, this->tile_height, 100);
    this->set_tile_size(17, this->tile_half_width, this->tile_height, 0);
    this->set_tile_size(18, this->tile_half_width, this->tile_height, 0);

    this->cur_row = 0;
    this->cur_col = 0;
    this->num_terrain = 0;
    this->max_terrain = 0;
    this->block_beg_row = 0;
    this->block_end_row = 0;
    this->block_beg_col = 0;
    this->block_end_col = 0;
    this->any_frame_change = 0;
    this->map_visible_flag = 0;
    this->fog_flag = 1;

    for (i = 0; i < 32; ++i) {
        this->terrain_types[i].num_obj_type = 0;
        this->terrain_types[i].rows = 0;
        this->terrain_types[i].cols = 0;
        for (j = 0; j < 30; ++j) {
            this->terrain_types[i].obj_types[j] = 0;
            this->terrain_types[i].obj_density[j] = 0;
        }
        for (j = 0; j < 32; ++j) {
            this->terrain_types[i].borders[j] = 0;
        }
        this->terrain_types[i].shape = 0;
        this->terrain_types[i].sound = 0;
    }

    for (i = 15; i >= 0; --i) {
        this->border_types[i].shape = 0;
        this->border_types[i].sound = 0;
    }

    this->load_terrain_types(terrain_file, sounds);
    this->load_border_types(border_file, sounds);
    this->map = 0;
    this->search_map = 0;
    this->map_row_offset = 0;
    this->search_map_rows = 0;
    this->unified_vis_map = 0;
    this->unit_manager = 0;
}
