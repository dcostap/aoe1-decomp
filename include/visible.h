#ifndef AOE1_VISIBLE_H
#define AOE1_VISIBLE_H

class RGE_Map;
class RGE_Player;
class RGE_Game_World;

struct LOSTBL {
    int y;
    int x1;
    int x2;
};

// Per-player visible_map cell values (RGE_Visible_Map::map_offsets).
// 0xFF is unexplored, 0 is explored but not currently seen, and 1..MAX is the number of
// viewers currently seeing the tile (incremented/decremented as units gain and lose sight).
#define RGE_VIS_UNEXPLORED 0xFF
#define RGE_VIS_EXPLORED 0x00
#define RGE_VIS_FIRST_VIEWER 0x01
#define RGE_VIS_MAX_VIEWERS 0xF9

// Tile display state returned by RGE_Visible_Map::get_visible and stored in RGE_Tile::draw_as.
#define RGE_TILE_BLACK 0x00
#define RGE_TILE_FOGGED 0x80
#define RGE_TILE_VISIBLE 0x0F

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

    RGE_Visible_Map(RGE_Map* in_map, RGE_Player* in_player);
    RGE_Visible_Map(int infile, RGE_Game_World* theWorld);
    ~RGE_Visible_Map();

    void save(int outfile);
    unsigned char get_visible(int map_col, int map_row) const;
    void set_all(unsigned char vis_flag);
    void explore_all(void);
    float percentExplored(void) const;
    void recomputeExplored(void);
    LOSTBL* get_los_table(int radius, int Square);
    int explore_terrain(int tx, int ty, int radius, int Square, int UpdateMap, int id);
    void unexplore_terrain(int tx, int ty, int radius, int Square, int UpdateMap, int id);
    int explore_terrain_sq(int tx1, int ty1, int tx2, int ty2, int UpdateMap, int id);
    void unexplore_terrain_sq(int tx1, int ty1, int tx2, int ty2, int UpdateMap, int id);
    unsigned long checksum_visible_inputs(void);
    long checksumVisible(void);
    unsigned long checksumUnifiedVisible(void);
};

class RGE_Unified_Visible_Map {
  public:
    int mapWidth;
    int mapHeight;
    unsigned long* UnifiedVisibleMap;

    RGE_Unified_Visible_Map(int width, int height);
    RGE_Unified_Visible_Map(int infile, RGE_Game_World* world);
    ~RGE_Unified_Visible_Map();

    void load(int infile);
    void save(int outfile);
    void reset(void);

  private:
    void Set_Map_Offsets(void);

  public:
    void suppress_updates(int mode);
};

class VC_LOG {
  public:
    int world_time;
    int player_id;
    int action;
    int object_id;
    int x1;
    int y1;
    int x2;
    int y2;
    int supress;
};

typedef char rge_lostbl_size_check[(sizeof(LOSTBL) == 0x0C) ? 1 : -1];
typedef char rge_visible_map_size_check[(sizeof(RGE_Visible_Map) == 0x38) ? 1 : -1];
typedef char rge_unified_visible_map_size_check[(sizeof(RGE_Unified_Visible_Map) == 0x0C) ? 1 : -1];
typedef char vc_log_size_check[(sizeof(VC_LOG) == 0x24) ? 1 : -1];

#endif
