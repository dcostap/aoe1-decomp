// tried the straight decompiler-style loop first; mismatch was the row-index increment order
// tried a height local; that moved the mismatch into the prolog and made the match worse
// matched tail fill by switching the post-loop clear to the simplest indexed for-loop basin

extern unsigned long* unified_map_offsets[256];

#ifndef AOE1_VISIBLE_TU_CONTEXT_H
class RGE_Unified_Visible_Map {
public:
    int mapWidth;
    int mapHeight;
    unsigned long* UnifiedVisibleMap;

private:
    void Set_Map_Offsets(void);
};
#endif

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
    for (; height < 256; height++) {
        unified_map_offsets[height] = 0;
    }
}
