// VA: 00455430 RGE_Map::~RGE_Map
// map.cpp lines 169-215
//
// Canonical ownership: map/search buffers are C allocations; map_zones,
// random_map, unified_vis_map, and unit_manager are owned C++ objects.  The
// terrain and border arrays own their TShape pointers and are walked from the
// last entry down, matching the original map.cpp cleanup order.
//
// Attempt log:
// - Replaced the decompiler-sized two-field scaffold with the proven RGE_Map
//   layout, typed terrain/border arrays, real child destructors, and natural
//   delete/free cleanup.  The first build is the baseline for this assignment.
// - Main-agent audit confirmed canonical map/child ownership and reverse cleanup
//   order; exact bytes were revalidated after promotion.

#include <stdlib.h>

class RGE_Map;
class RGE_Tile;
class RGE_Game_World;
class RGE_RMM_Database_Controller;
class RGE_Zone_Map_List;
class RGE_Unified_Visible_Map;
class Visible_Unit_Manager;
class RGE_Sound;

class TShape {
public:
    ~TShape();
};

class RGE_Tile_Size {
public:
    short width;
    short height;
    short y_delta;
};

class RGE_Tile_Set {
public:
    char gap_00[0x20];
    TShape* shape;
    char gap_24[0x174];
};

class RGE_Border_Set {
public:
    char gap_00[0x20];
    TShape* shape;
    char gap_24[0x57C];
};

class RGE_Zone_Map_List {
public:
    ~RGE_Zone_Map_List();
};

class RGE_RMM_Database_Controller {
public:
    ~RGE_RMM_Database_Controller();
};

class RGE_Unified_Visible_Map {
public:
    ~RGE_Unified_Visible_Map();
};

class Visible_Unit_Manager {
public:
    ~Visible_Unit_Manager();
};

class RGE_Map {
public:
    virtual ~RGE_Map();

    RGE_Tile* map;
    long map_width;
    long map_height;
    long world_width;
    long world_height;
    RGE_Tile_Size tilesizes[19];
    char gap_8A[0x2];
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
    char gap_8DAD[0x3];
    unsigned char* search_map;
    unsigned char** search_map_rows;
    unsigned char map_visible_flag;
    unsigned char fog_flag;
    char gap_8DBA[0x2];
    RGE_RMM_Database_Controller* random_map;
    RGE_Game_World* game_world;
    RGE_Zone_Map_List* map_zones;
    RGE_Unified_Visible_Map* unified_vis_map;
    Visible_Unit_Manager* unit_manager;
};

RGE_Map::~RGE_Map()
{
    int i;

    if (this->map_zones != 0) {
        delete this->map_zones;
        this->map_zones = 0;
    }
    if (this->random_map != 0) {
        delete this->random_map;
        this->random_map = 0;
    }
    if (this->map != 0) {
        free(this->map);
    }
    if (this->search_map != 0) {
        free(this->search_map);
    }
    if (this->map_row_offset != 0) {
        free(this->map_row_offset);
    }
    if (this->search_map_rows != 0) {
        free(this->search_map_rows);
    }

    for (i = 31; i >= 0; --i) {
        if (this->terrain_types[i].shape != 0) {
            delete this->terrain_types[i].shape;
            this->terrain_types[i].shape = 0;
        }
    }
    for (i = 15; i >= 0; --i) {
        if (this->border_types[i].shape != 0) {
            delete this->border_types[i].shape;
            this->border_types[i].shape = 0;
        }
    }

    if (this->unified_vis_map != 0) {
        delete this->unified_vis_map;
    }
    if (this->unit_manager != 0) {
        delete this->unit_manager;
    }
}
