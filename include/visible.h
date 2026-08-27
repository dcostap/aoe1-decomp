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
    void suppress_updates(int value);
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

typedef char rge_lostbl_size_check[
    (sizeof(LOSTBL) == 0x0C) ? 1 : -1];
typedef char rge_visible_map_size_check[
    (sizeof(RGE_Visible_Map) == 0x38) ? 1 : -1];
typedef char rge_unified_visible_map_size_check[
    (sizeof(RGE_Unified_Visible_Map) == 0x0C) ? 1 : -1];
typedef char vc_log_size_check[
    (sizeof(VC_LOG) == 0x24) ? 1 : -1];

#endif
