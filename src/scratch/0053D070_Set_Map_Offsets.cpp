// tried the straight decompiler-style loop first; mismatch was the row-index increment order
// tried a height local; that moved the mismatch into the prolog and made the match worse
// quick-win only: leaving this in scratch if the remaining mismatch stays in loop-shape / tail-fill codegen

extern unsigned long* unified_map_offsets[256];

class RGE_Unified_Visible_Map {
public:
    int mapWidth;
    int mapHeight;
    unsigned long* UnifiedVisibleMap;

    void Set_Map_Offsets(void);
};

void RGE_Unified_Visible_Map::Set_Map_Offsets(void) {
    int y = 0;
    if (this->mapHeight > 0) {
        unsigned long** row = unified_map_offsets;
        do {
            *row = this->UnifiedVisibleMap + this->mapWidth * y;
            y++;
            row++;
        } while (y < this->mapHeight);
    }
    int height = this->mapHeight;
    if (height < 256) {
        unsigned long** row = unified_map_offsets + height;
        int count = 256 - height;
        while (count != 0) {
            *row = 0;
            row++;
            count--;
        }
    }
}
