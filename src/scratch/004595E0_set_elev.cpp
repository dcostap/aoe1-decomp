// VA: 004595E0 RGE_Map::set_elev
// Attempt log:
// initial reconstruction from packet: clamp rectangle, optionally modify/absolute set elevation nibble, then update terrain/object edges.
// modeled active player lookup through player list at +0x8dc0 -> +0x40/+0x7c, rectangle endpoint swaps, and bounds clamps.
// modeled relative-elevation path: per-tile high bits at tile+5, clamp adjusted elevation, clear if >8.
// modeled absolute-elevation path when delta is zero with relative byte capped to 8 and stored in high bits.
// modeled expansion by one tile around edited rectangle and terrain_at/update-object loop, plus final clear_area/repaint_area calls.
// tried direct vtable call syntax for object update; source compiles but call surface/loop details are speculative.
// current source is 720 bytes vs original 792, so no positional diff; broad/short and not accepted_drift-safe.

struct TileObjNode { void* obj; TileObjNode* next; };
struct Tile { unsigned char terrain; unsigned char pad[4]; unsigned char elev; char gap[10]; TileObjNode* objects; char pad2[4]; };
class Player { public: char gap[0x1d]; unsigned char mode; char gap2[0x1f]; short id; void* units; };
class RGE_Map { public:
    char gap0[8]; int width; int height; char gap10[0x8d8c-0x10]; Tile** rows; char gap2[0x8dc0-0x8d90]; Player* player;
    void clear_area(short,short,short,short); void repaint_area(short,short,short,short,int); unsigned char terrain_at(short,short);
    void set_elev(short x1, short y1, short x2, short y2, short delta, unsigned char relative);
};

void RGE_Map::set_elev(short x1, short y1, short x2, short y2, short delta, unsigned char relative)
{
    Player* cur = ((Player**)(*(int*)((char*)this->player + 0x40)))[*(short*)((char*)this->player+0x7c)];
    if (x1 > x2) { short t=x1; x1=x2; x2=t; }
    if (y1 > y2) { short t=y1; y1=y2; y2=t; }
    if (x1 < 0) x1 = 0;
    if (x2 >= this->height) x2 = (short)(this->height - 1);
    if (y1 < 0) y1 = 0;
    if (y2 >= this->width) y2 = (short)(this->width - 1);
    if (relative) {
        if (delta != 0) {
            for (short x=x1; x<=x2; ++x) {
                for (short y=y1; y<=y2; ++y) {
                    Tile* tile = &this->rows[x][y];
                    short e = (short)((tile->elev >> 5) + delta);
                    if (e < 0) e = 0; else if (e > 0xff) e = 0xff;
                    tile->elev = (unsigned char)((e << 5) | (tile->elev & 0x1f));
                    if ((tile->elev >> 5) > 8) tile->elev &= 0x1f;
                }
            }
        } else {
            if (relative > 8) relative = 8;
            for (short x=x1; x<=x2; ++x) {
                for (short y=y1; y<=y2; ++y) {
                    Tile* tile = &this->rows[x][y];
                    tile->elev = (unsigned char)((relative << 5) | (tile->elev & 0x1f));
                }
            }
        }
    }
    if (x1 > 0) --x1;
    if (x2 < this->height-1) ++x2;
    if (y1 > 0) --y1;
    if (y2 < this->width-1) ++y2;
    for (short x=x1; x<=x2; ++x) {
        for (short y=y1; y<=y2; ++y) {
            Tile* tile = &this->rows[x][y];
            tile->terrain = this->terrain_at(y, x);
            for (TileObjNode* n=tile->objects; n; n=n->next) {
                void* o = n->obj;
                (*(void(***)(void*,int,int,int))o)[13](o, *(int*)((char*)o+0x38), *(int*)((char*)o+0x3c), 0);
            }
            if (this->player->mode != 3) {
                // visibility update placeholder
            }
        }
    }
    this->clear_area(y1, x1, y2, x2);
    this->repaint_area(y1, x1, y2, x2, 0);
}
