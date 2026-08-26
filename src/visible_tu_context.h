#ifndef AOE1_VISIBLE_TU_CONTEXT_H
#define AOE1_VISIBLE_TU_CONTEXT_H

// Local context for the complete C:\\msdev\\work\\age1_x1\\visible.cpp
// source module.  It keeps the shared visible-map layout and adds only the
// declarations needed by every owner in PDB order.
//
// The shared header guard is set because these owner files use the reviewed
// visible_context.h when compiled alone.  This local header is the wrapper's
// one declaration surface; it does not change the shared header.
#define VISIBLE_CONTEXT_H

typedef unsigned char byte;

class RGE_Map;
struct RGE_Tile;

class RGE_Tile_List {
public:
    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    void* list;

    void add_node(int x, int y);
};

struct LOSTBL {
    int y;
    int x1;
    int x2;
};

class RGE_Player;

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    unsigned long world_time;
    char gap_008_to_028[0x20];
    RGE_Map* map;
    char gap_02C_to_040[0x14];
    RGE_Player** players;
    char gap_044_to_07C[0x38];
    short curr_player;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_004_to_03C[0x38];
    RGE_Game_World* world;
    char gap_040_to_04A[0x0A];
    short id;
    char gap_04C_to_058[0x0C];
    RGE_Tile_List tile_list;
    RGE_Tile_List diam_tile_list;
    char gap_080_to_0AC[0x2C];
    int mutualAlly[8];
    char gap_0CC_to_0D0[4];
    unsigned long mutualExploredMask;
    unsigned long mutualVisibleMask;
};

struct RGE_Tile {
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type;
    unsigned char border_type;
    unsigned char last_drawn_as;
    unsigned char last_drawn_shape;
    unsigned char flags_09;
    unsigned char draw_attribute;
    unsigned char last_drawn_shape2;
    char gap_0C[0x0C];
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_0004[0x04];
    int map_width;
    int map_height;
    char gap_0010_to_8D8C[0x8D7C];
    RGE_Tile** map_row_offset;
    char gap_8D90[0x40];
};

class RGE_Visible_Map {
public:
    unsigned char** map_offsets;
    RGE_Game_World* world;
    RGE_Player* player;
    RGE_Map* map;
    unsigned char* visible_map;
    int widthValue;
    int heightValue;
    int numberTilesExploredValue;
    int numberTotalTilesValue;
    unsigned long PlayerVisibleMaskValue;
    unsigned long PlayerVisibleMaskInvertValue;
    unsigned long PlayerExploredMaskValue;
    unsigned long PlayerExploredMaskInvertValue;
    unsigned long input_csum;

    RGE_Visible_Map(RGE_Map* map, RGE_Player* player);
    RGE_Visible_Map(int file, RGE_Game_World* world);
    ~RGE_Visible_Map();

    void save(int handle);
    unsigned char get_visible(int x, int y) const;
    void set_all(unsigned char value);
    void explore_all(void);
    float percentExplored(void) const;
    void recomputeExplored(void);
    LOSTBL* get_los_table(int distance, int diagonal);
    int explore_terrain(int x, int y, int radius, int square,
                        int update_tiles, int p6);
    void unexplore_terrain(int x, int y, int radius, int square,
                           int update_tiles, int p6);
    int explore_terrain_sq(int x1, int y1, int x2, int y2,
                           int update_tiles, int p6);
    void unexplore_terrain_sq(int x1, int y1, int x2, int y2,
                              int update_tiles, int p6);
    unsigned long checksum_visible_inputs(void);
    long checksumVisible(void);
    unsigned long checksumUnifiedVisible(void);
};

class RGE_Unified_Visible_Map {
public:
    int mapWidth;
    int mapHeight;
    unsigned long* UnifiedVisibleMap;

    RGE_Unified_Visible_Map(int mapWidth, int mapHeight);
    RGE_Unified_Visible_Map(int map, RGE_Game_World* world);
    ~RGE_Unified_Visible_Map();

    void load(int handle);
    void save(int handle);
    void reset(void);
private:
    void Set_Map_Offsets(void);

public:
    void suppress_updates(int);
};

extern float save_game_version;
extern int Map_Update_Suppresion;
extern unsigned long* unified_map_offsets[256];
extern LOSTBL* NormalLOS[17];
extern LOSTBL* SquareLOS[17];
extern LOSTBL* Edge_Offsets_T16[17];
extern LOSTBL* Edge_Offsets_N16[17];

extern "C" void __cdecl rge_write(int handle, void* buffer, int count);
extern "C" void __cdecl rge_read(int handle, void* buffer, int count);
extern void __cdecl log_map_call(int world_time, int player_id, int type,
                                 int p6, int x1, int y1, int x2, int y2,
                                 int suppression);

#endif
