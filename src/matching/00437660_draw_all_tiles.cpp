// attempt 1: lock, nested row/col loops, draw_tile calls, unlock
// result: exact match after restoring the exact save_area offset and the short loop bounds
// moved to src\matching\00437660_draw_all_tiles.cpp after local validation

#ifndef DIAM_MAP_CONTEXT_H
class TDrawArea {
public:
    unsigned char* Lock(const char* name, int flag);
    void Unlock(const char* name);
};
#endif

#ifndef DIAM_MAP_CONTEXT_H
class RGE_Diamond_Map {
public:
    char gap_00[0x130];
    short map_wid;
    short map_hgt;
    char gap_134[0x34];
    TDrawArea* save_area;

    void draw_tile(short x, short y, int, int);
    void draw_all_tiles();
};
#endif

void RGE_Diamond_Map::draw_all_tiles() {
    if (this->save_area->Lock("diam_map::draw_all_tiles", 1) == 0) {
        return;
    }

    for (short y = 0; y < this->map_hgt; ++y) {
        for (short x = 0; x < this->map_wid; ++x) {
            this->draw_tile(x, y, 0, 0);
        }
    }

    this->save_area->Unlock("diam_map::draw_all_tiles");
}
