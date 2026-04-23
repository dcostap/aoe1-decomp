#include <string.h>

class RGE_Unified_Visible_Map {
public:
    int mapWidth;
    int mapHeight;
    unsigned long* UnifiedVisibleMap;

    void reset(void);
};

void RGE_Unified_Visible_Map::reset(void) {
    if (this->UnifiedVisibleMap != 0) {
        memset(this->UnifiedVisibleMap, 0, this->mapWidth * this->mapHeight * 4);
    }
}
