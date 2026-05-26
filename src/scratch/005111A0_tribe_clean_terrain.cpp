// 005111A0 TRIBE_Map::tribe_clean_terrain
// Attempt log:
// try 1: direct behavioral skeleton from packet: clamp/expand brush rect, scan neighbor passability, place terrain around edges, redraw/final cleanup; default /O2 too small (.text 1392 vs 1562).
// try 2: /GX no change from try 1; rolled back.
// try 3: /Od exact-size comparable but debug-basin broad mismatch: 93.8540% positional / 154.0333% edit, first mismatch prologue; rolled back.
// try 4: /O1 too small (.text 1179); rolled back.
// try 5: /O2 without /Oy no change from default; rolled back.
// left in scratch: no custom flags retained. Not accepted_drift quality; likely needs exact original nested condition topology and real TRIBE_Map/terrain helper declarations; current skeleton captures main behavior but not VC5 local/register/frame shape.

typedef unsigned char uchar;
struct Tile { char b[0x18]; };

class TRIBE_Map {
public:
    char gap0[8];
    short width;
    short height;
    char gap1[0x8D80];
    Tile** rows;
    char gap2[0x30];
    int terrain_table;

    uchar is_clean_type(int t);
    uchar can_place(int x, int y);
    void refresh_area(int x1,int y1,int x2,int y2,uchar terrain);
    void set_tile(int terrain_table,int x,int y,uchar terrain,int a,int b);
    void finalize(int a,int b,int x1,int y1,int x2,int y2,int c,int d,int e);
    void tribe_clean_terrain(int x1,int y1,int x2,int y2,uchar terrain,uchar cleanType);
};

#define TILE_AT(x,y) (&this->rows[(y)][(x)])
#define TILE_TYPE(t) (((t)->b[5]) & 0x1f)

void TRIBE_Map::tribe_clean_terrain(int x1,int y1,int x2,int y2,uchar terrain,uchar cleanType)
{
    int dx_up = -(int)this->width;
    int dx_down = (int)this->width;
    int dx_ul = -1 - (int)this->width;
    int dx_ur = 1 - (int)this->width;
    int dx_dl = (int)this->width - 1;
    int dx_dr = (int)this->width + 1;
    uchar changed;

    if (x1 < 0) x1 = 0;
    if (y1 < 0) y1 = 0;
    if (x2 >= this->width) x2 = this->width - 1;
    if (y2 >= this->height) y2 = this->height - 1;

    do {
        changed = 0;
        if (x1 > 0) --x1;
        if (y1 > 0) --y1;
        if (x2 < this->width - 1) ++x2;
        if (y2 < this->height - 1) ++y2;

        for (int pass = 0; pass < 2; ++pass) {
            for (int y = y1; y <= y2; ++y) {
                Tile* tile = TILE_AT(x1, y);
                for (int x = x1; x <= x2; ++x, ++tile) {
                    if (this->is_clean_type(TILE_TYPE(tile))) continue;

                    int up=0, down=0, left=0, right=0;
                    int ul=0, ur=0, dl=0, dr=0;
                    if (y > 0 && this->is_clean_type(TILE_TYPE((Tile*)((char*)tile + dx_up * 0x18)))) up = 1;
                    if (y < this->height - 1 && this->is_clean_type(TILE_TYPE((Tile*)((char*)tile + dx_down * 0x18)))) down = 1;
                    if (x > 0 && this->is_clean_type(TILE_TYPE(tile - 1))) left = 1;
                    if (x < this->width - 1 && this->is_clean_type(TILE_TYPE(tile + 1))) right = 1;
                    if (y > 0) {
                        if (x > 0 && this->is_clean_type(TILE_TYPE((Tile*)((char*)tile + dx_ul * 0x18)))) ul = 1;
                        if (x < this->width - 1 && this->is_clean_type(TILE_TYPE((Tile*)((char*)tile + dx_ur * 0x18)))) ur = 1;
                    }
                    if (y < this->height - 1) {
                        if (x > 0 && this->is_clean_type(TILE_TYPE((Tile*)((char*)tile + dx_dl * 0x18)))) dl = 1;
                        if (x < this->width - 1 && this->is_clean_type(TILE_TYPE((Tile*)((char*)tile + dx_dr * 0x18)))) dr = 1;
                    }

                    uchar place = 0;
                    if (pass == 0) {
                        if ((up && down) || (left && right)) place = 1;
                    } else {
                        if (ul && !place) {
                            if ((!ur || up) && (!left || ul) && (!dl || left) && (!right || ur)) place = 1;
                        }
                        if (ur && !place) {
                            if ((!up || ur) && (!right || ur) && (!dr || right) && (!left || up)) place = 1;
                        }
                        if (dr && !place) {
                            if ((!ur || right) && (!down || dr) && (!left || dl) && (!up || right)) place = 1;
                        }
                        if (dl && !place) {
                            if ((!left || dl) && (!up || ul) && (!right || down) && (!dr || down)) place = 1;
                        }
                    }
                    if (place) {
                        if (this->is_clean_type(cleanType)) {
                            if (!this->can_place(x,y)) continue;
                            this->set_tile(this->terrain_table, x, y, terrain, 0, 0);
                        } else {
                            if (ul) this->set_tile(this->terrain_table, x-1, y-1, terrain, 0, 0);
                            if (up) this->set_tile(this->terrain_table, x, y-1, terrain, 0, 0);
                            if (ur) this->set_tile(this->terrain_table, x+1, y-1, terrain, 0, 0);
                            if (right) this->set_tile(this->terrain_table, x+1, y, terrain, 0, 0);
                            if (dr) this->set_tile(this->terrain_table, x+1, y+1, terrain, 0, 0);
                            if (down) this->set_tile(this->terrain_table, x, y+1, terrain, 0, 0);
                            if (dl) this->set_tile(this->terrain_table, x-1, y+1, terrain, 0, 0);
                            if (left) this->set_tile(this->terrain_table, x-1, y, terrain, 0, 0);
                        }
                        changed = 1;
                    }
                }
            }
        }
    } while (changed);

    this->refresh_area(x1,y1,x2,y2,terrain);
    this->finalize(0,0,x1,y1,x2,y2,0,0,0);
}
