// BINARY NOTE: the shipped zero stores occur in +8, +0, +4 order.
extern int Map_Update_Suppresion;
#ifndef AOE1_VISIBLE_TU_CONTEXT_H
class RGE_Game_World;

class RGE_Unified_Visible_Map {
public:
    int mapHeight;
    int mapWidth;
    void* UnifiedVisibleMap;

    RGE_Unified_Visible_Map(int map, RGE_Game_World* world);
    void load(int map);
    void Set_Map_Offsets(void);
};
#endif

RGE_Unified_Visible_Map::RGE_Unified_Visible_Map(int map, RGE_Game_World* world) {
    this->UnifiedVisibleMap = 0;
    this->mapWidth = 0;
    this->mapHeight = 0;
    Map_Update_Suppresion = 0;
    load(map);
    Set_Map_Offsets();
}
