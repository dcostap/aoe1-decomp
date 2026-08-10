// VA: 00455570 RGE_Map::init_tile_sizes
// Attempt log:
// baseline reconstruction: canonical map geometry and the map.cpp tile-size
// table initialization sequence.

class RGE_Tile;
class RGE_Game_World;
class RGE_Player;
class RGE_RMM_Database_Controller;
class RGE_Zone_Map_List;
class RGE_Unified_Visible_Map;
class Visible_Unit_Manager;
class RGE_Sound;

struct RGE_Tile_Size {
    short width;
    short height;
    short y_delta;
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
    char gap_8A[2];
    char terrain_types[0x3300];
    char border_types[0x5A00];
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
    char gap_8DAD[3];
    unsigned char* search_map;
    unsigned char** search_map_rows;
    unsigned char map_visible_flag;
    unsigned char fog_flag;
    char gap_8DBA[2];
    RGE_RMM_Database_Controller* random_map;
    RGE_Game_World* game_world;
    RGE_Zone_Map_List* map_zones;
    RGE_Unified_Visible_Map* unified_vis_map;
    Visible_Unit_Manager* unit_manager;

    void init_tile_sizes();
    void set_tile_size(unsigned char, short, short, short);
};

void RGE_Map::init_tile_sizes()
{
    this->tile_width = 0x40;
    this->tile_height = 0x20;
    this->tile_half_width = 0x20;
    this->tile_half_height = 0x10;
    this->elev_height = 0x10;

    this->set_tile_size(0, 0x40, 0x20, 0);
    this->set_tile_size(1, this->tile_width, this->elev_height, -8);
    this->set_tile_size(2, this->tile_width,
                        this->elev_height + this->tile_height, 8);
    this->set_tile_size(3, this->tile_width, this->tile_height, -8);
    this->set_tile_size(4, this->tile_width, this->tile_height, -8);
    this->set_tile_size(5, this->tile_width, this->elev_height, -8);
    this->set_tile_size(6, this->tile_width,
                        this->elev_height + this->tile_height, 8);
    this->set_tile_size(7, this->tile_width, this->elev_height, -8);
    this->set_tile_size(8, this->tile_width,
                        this->elev_height + this->tile_height, 8);
    this->set_tile_size(9, this->tile_width, this->elev_height, -8);
    this->set_tile_size(10, this->tile_width,
                        this->elev_height + this->tile_height, 8);
    this->set_tile_size(11, this->tile_width, this->tile_height, -8);
    this->set_tile_size(12, this->tile_width, this->tile_height, -8);
    this->set_tile_size(13, this->tile_width, this->elev_height, -8);
    this->set_tile_size(14, this->tile_width,
                        this->elev_height + this->tile_height, 8);
    this->set_tile_size(15, this->tile_width, this->tile_height, 8);
    this->set_tile_size(16, this->tile_width, this->tile_height, 8);
    this->set_tile_size(17, this->tile_half_width, this->tile_height, 0);
    this->set_tile_size(18, this->tile_half_width, this->tile_height, 0);
}
