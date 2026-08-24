extern int Map_Update_Suppresion;
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);

#ifndef AOE1_VISIBLE_TU_CONTEXT_H
class RGE_Unified_Visible_Map {
public:
    int mapWidth;
    int mapHeight;
    unsigned long* UnifiedVisibleMap;

    RGE_Unified_Visible_Map(int mapWidth, int mapHeight);
    void Set_Map_Offsets(void);
};
#endif

RGE_Unified_Visible_Map::RGE_Unified_Visible_Map(int mapWidth, int mapHeight) {
    this->mapWidth = mapWidth;
    this->mapHeight = mapHeight;
    Map_Update_Suppresion = 0;
    if ((0 < this->mapHeight) && (0 < this->mapWidth)) {
        this->UnifiedVisibleMap = (unsigned long*)calloc(this->mapWidth * this->mapHeight, 4);
        Set_Map_Offsets();
    } else {
        this->UnifiedVisibleMap = 0;
        this->mapWidth = 0;
        this->mapHeight = 0;
        Set_Map_Offsets();
    }
}
