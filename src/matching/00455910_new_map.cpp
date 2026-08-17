// VA: 00455910 RGE_Map::new_map
// Attempt log:
// baseline reconstruction: canonical RGE_Map map/search ownership, player
// object-list cleanup, typed row/tile geometry, and real manager lifetimes.
// FLAGS: config/flags/00455910_new_map.rsp uses /GX for the original EH cleanup
// state around the three manager allocations.
// Sequential pass sa99_map559: typed canonical reconstruction reached exact
// size, call set, CFG, EH shape, and 99.20% shape similarity. Splitting the
// typed row base from the terrain-byte offset removed the broad drift and left
// only two allocator-product operand bytes at 00455A1E/00455A25. Arithmetic,
// local, and reference variants did not change that final hunk without worse
// scheduling. Best lead is VC5 operand ordering for map_height * map_width.
// shardD3_455910: reversed member expression was a codegen duplicate; restored
// height * width. The first hunk remains the allocator product operand order.
// orch-455910-a: a volatile height read through a pointer produced an exact
// 783-byte match, but this is codegen-only steering and not plausible source.
// Restored the clean typed expression; final validated drift remains two
// commutative allocator-product operand bytes at 00455A1E/00455A25.
// orch-455910-b: long and int height-first compound area temporaries were
// codegen duplicates; an unsigned-long first-operand cast and a local map alias
// were also duplicates. An adjacent dimensions view moved the store and worsened
// the diff to 12 bytes; /Oa changed broad structure and worsened it to 719 bytes.
// Restored the direct typed expression and default flags. Validation remains a
// 783-byte function with 24 calls aligned and only the two product bytes wrong.
// revisit sa-18c0524d: twenty fresh probes tested period CRT declarations,
// literal/sizeof forms, signed and unsigned count casts, int/long locals,
// dimension aliases, reference/pointer views, and parameter versus field
// counts. stdlib, sizeof(char), literal 1, signed-long, and algebraic forms
// were codegen duplicates. Unsigned fields widened the drift to 8 bytes;
// references and address-taken pointers widened it to 12; parameter counts
// widened it to 546. No natural probe changed the two product bytes.
// The clean typed source was restored after that pass. A focused donor search
// for the allocator block found no exact matching-bank source donor.
// revisit sa-df3a1f53: swapping the two independent dimension stores so that
// map_width is assigned before map_height changes only the two allocator
// product operand bytes at 00455A1E/00455A25. The natural source is exact.
// The first exact checkpoint is 20260817T140657.041956Z-aba6195756.
// Walking back this one change restored the two-byte mismatch. Reapplying it
// restored the exact 783-byte result. No volatile, no-effect expression,
// wrapper, raw cursor, or other compiler-steering form is retained.

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" void __cdecl free(void* block);
extern void* __cdecl operator new(unsigned int size);
extern void __cdecl operator delete(void* block);

class RGE_Tile;
class RGE_Player;
class RGE_Game_World;
class RGE_Map;
class RGE_Sound;
class RGE_RMM_Database_Controller;
class RGE_Zone_Map_List;
class RGE_Unified_Visible_Map;
class Visible_Unit_Manager;

class RGE_Object_List {
public:
    void removeAllObjects();
};

class RGE_Player {
public:
    char gap_00[0x28];
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
};

class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
};

class RGE_Tile {
public:
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type;
    char gap_06[0x12];
};

struct RGE_Tile_Size {
    short width;
    short height;
    short y_delta;
};

class RGE_Zone_Map_List {
public:
    void* zone_maps;
    long zone_map_num;
    RGE_Map* map;

    RGE_Zone_Map_List(RGE_Map* map);
    ~RGE_Zone_Map_List();
};

class RGE_Unified_Visible_Map {
public:
    int mapWidth;
    int mapHeight;
    unsigned long* UnifiedVisibleMap;

    RGE_Unified_Visible_Map(int map_width, int map_height);
    ~RGE_Unified_Visible_Map();
};

class Visible_Unit_Manager {
public:
    void* PlayerDataPtrs;
    void* Return_Buffer[5];
    int Player_Count;
    int Category_Count;
    unsigned char* distanceTable;

    Visible_Unit_Manager(int player_count, int category_count);
    ~Visible_Unit_Manager();
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

    void set_map_screen_pos(int col0, int row0, int col1, int row1);
    void new_map(long width, long height);
};

void RGE_Map::new_map(long width, long height)
{
    int i;

    if (width <= 0 || height <= 0) {
        return;
    }

    if (this->map != 0) {
        if (this->game_world != 0) {
            int player_count = this->game_world->player_num;
            for (i = 0; i < player_count; ++i) {
                if (this->game_world->players != 0 &&
                    this->game_world->players[i] != 0) {
                    this->game_world->players[i]->objects->removeAllObjects();
                    this->game_world->players[i]->sleeping_objects->removeAllObjects();
                    this->game_world->players[i]->doppleganger_objects->removeAllObjects();
                }
            }
        }
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

    this->map_width = width;
    this->map_height = height;
    this->world_width = this->tile_width * width;
    this->world_height = this->tile_height * height;
    this->map = (RGE_Tile*)calloc(height * width, sizeof(RGE_Tile));
    this->search_map = (unsigned char*)calloc(this->map_height * this->map_width,
                                               sizeof(unsigned char));
    this->map_row_offset = (RGE_Tile**)calloc(this->map_height + 1,
                                               sizeof(RGE_Tile*));
    this->search_map_rows = (unsigned char**)calloc(this->map_height + 1,
                                                     sizeof(unsigned char*));

    for (i = 0; i < this->map_height; ++i) {
        this->map_row_offset[i] = this->map + i * this->map_width;
        this->search_map_rows[i] = this->search_map + i * this->map_width;
    }

    this->map_row_offset[this->map_height] = this->map;
    this->search_map_rows[this->map_height] = this->search_map;

    for (i = 0; i < this->map_height; ++i) {
        for (int j = 0; j < this->map_width; ++j) {
            unsigned char* tile = (unsigned char*)this->map_row_offset[i];
            tile += j * sizeof(RGE_Tile);
            tile[5] = (tile[5] & 0x1f) | 0x20;
        }
    }

    this->set_map_screen_pos(0, 0, this->map_width - 1,
                             this->map_height - 1);

    if (this->map_zones != 0) {
        delete this->map_zones;
    }
    this->map_zones = new RGE_Zone_Map_List(this);

    if (this->unified_vis_map != 0) {
        delete this->unified_vis_map;
    }
    this->unified_vis_map = new RGE_Unified_Visible_Map(width, height);

    if (this->unit_manager != 0) {
        delete this->unit_manager;
    }
    this->unit_manager = new Visible_Unit_Manager(this->game_world->player_num,
                                                   0x40);
}
