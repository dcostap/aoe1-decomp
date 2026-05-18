// VA: 00456170 RGE_Map::postclean_elevation
// Attempt log:
// try 1: natural reconstruction with helper tile_elev/set_tile_elev; behavior plausible but broad codegen mismatch (90.34% positional), frame 0x18 vs original 0x24.
// try 2: rewrite with direct byte/offset arithmetic to mirror original row[y] + x*24 and neighbor offsets (±24, ±width*24, diagonals). This compiled closer in size family but still too small (816B vs 880B).
// try 3 notes from packet review: original precomputes width-derived offsets (-width, 1-width, and x*24) into stack slots and keeps the target elevation as a 16-bit stack local per row; current source still does not land in that local/register topology.
// try 4: kept direct arithmetic form rather than helper form because it models original memory effects better, but broad prologue/frame/local mismatch remains; no accepted_drift proposal.
// GIVEUP blockers: exact VC5 local topology for width offsets and byte/word temporaries, source spelling for the duplicated raise/lower neighbor checks, and row/column parameter-slot reuse. No inline asm used.

struct RGE_Tile { char gap0[5]; unsigned char terrain_elev; char rest[18]; };

class RGE_Map {
public:
    char gap00[8];
    short map_width;       // +8
    int map_height;        // +c
    char gap10[0x8d8c-0x10];
    RGE_Tile** rows;       // +8d8c

    unsigned char postclean_elevation(long x0, long y0, long x1, long y1, unsigned char elev);
};

#define ELEV_AT(base, off) ((unsigned char)(((unsigned char*)(base))[(off) + 5] >> 5))

unsigned char RGE_Map::postclean_elevation(long x0, long y0, long x1, long y1, unsigned char elev)
{
    unsigned char changed = 0;
    int width = this->map_width;
    int negw = -width;
    int posw = 1 - width;
    long min_x = x0;
    long min_y = y0;
    long max_x = x1;
    long max_y = y1;
    if (min_x > 0) min_x--;
    if (min_y > 0) min_y--;
    if (max_x < width - 1) max_x++;
    if (max_y < this->map_height - 1) max_y++;

    int row = min_y;
    while (row <= max_y) {
        int xoff = min_x * 24;
        RGE_Tile* tile = (RGE_Tile*)((char*)this->rows[row] + xoff);
        long col = min_x;
        while (col <= max_x) {
            unsigned char oldbyte = tile->terrain_elev;
            unsigned short target = elev;
            unsigned short cur = (unsigned char)(oldbyte >> 5);
            unsigned char bad = 0;
            unsigned short next;
            if (cur < target) {
                next = cur + 1;
                if (row > 0 && ELEV_AT(tile, negw * 24) > next) bad = 1;
                if (row < this->map_height - 1 && ELEV_AT(tile, width * 24) > next) bad = 1;
                if (col > 0 && ELEV_AT(tile, -24) > next) bad = 1;
                if (col < width - 1 && ELEV_AT(tile, 24) > next) bad = 1;
                if (row > 0) {
                    if (col > 0 && ELEV_AT(tile, (negw - 1) * 24) > next) bad = 1;
                    if (col < width - 1 && ELEV_AT(tile, posw * 24) > next) bad = 1;
                }
                if (row < this->map_height - 1) {
                    if (col > 0 && ELEV_AT(tile, (width - 1) * 24) > next) bad = 1;
                    if (col < width - 1 && ELEV_AT(tile, (width + 1) * 24) > next) bad = 1;
                }
            } else if (cur > target) {
                next = cur - 1;
                if (row > 0 && ELEV_AT(tile, negw * 24) < next) bad = 1;
                if (row < this->map_height - 1 && ELEV_AT(tile, width * 24) < next) bad = 1;
                if (col > 0 && ELEV_AT(tile, -24) < next) bad = 1;
                if (col < width - 1 && ELEV_AT(tile, 24) < next) bad = 1;
                if (row > 0) {
                    if (col > 0 && ELEV_AT(tile, (negw - 1) * 24) < next) bad = 1;
                    if (col < width - 1 && ELEV_AT(tile, posw * 24) < next) bad = 1;
                }
                if (row < this->map_height - 1) {
                    if (col > 0 && ELEV_AT(tile, (width - 1) * 24) < next) bad = 1;
                    if (col < width - 1 && ELEV_AT(tile, (width + 1) * 24) < next) bad = 1;
                }
            }
            if (bad) {
                tile->terrain_elev = (unsigned char)((oldbyte & 0x1f) | ((unsigned char)next << 5));
                changed = 1;
            }
            ++col;
            tile = (RGE_Tile*)((char*)tile + 24);
        }
        ++row;
    }
    return changed;
}
