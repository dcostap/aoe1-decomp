#ifndef VISIBLE_CONTEXT_H
#define VISIBLE_CONTEXT_H

// Reviewed visible.cpp surface shared by the PDB-ordered owner set.
// Keep the declaration-only _rotl surface before the owner bodies.  Do not
// include a standard header before the exact visible-map anchors.
extern "C" unsigned long __cdecl _rotl(unsigned long value, int shift);
#pragma intrinsic(_rotl)

struct RGE_Map;
struct RGE_Tile;

class RGE_Tile_List {
public:
    char gap_000[0x14];
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
    char gap_004[0x46];
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

    void save(int handle);
    unsigned char get_visible(int x, int y) const;
    void set_all(unsigned char value);
    int explore_terrain(int x, int y, int radius, int square,
                       int update_tiles, int p6);
    void unexplore_terrain(int x, int y, int radius, int square,
                           int update_tiles, int p6);
    int explore_terrain_sq(int x1, int y1, int x2, int y2,
                           int update_tiles, int p6);
    void unexplore_terrain_sq(int x1, int y1, int x2, int y2,
                              int update_tiles, int p6);
};

extern float save_game_version;
extern int Map_Update_Suppresion;
extern unsigned long* unified_map_offsets[256];
extern LOSTBL* NormalLOS[17];
extern LOSTBL* SquareLOS[17];

extern "C" void __cdecl rge_write(int handle, void* buffer, int count);
extern void __cdecl log_map_call(int world_time, int player_id, int type,
                                 int p6, int x1, int y1, int x2, int y2,
                                 int suppression);

#endif
