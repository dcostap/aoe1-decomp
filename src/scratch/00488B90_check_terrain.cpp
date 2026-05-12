// 00488B90 RGE_RMM_Terrain_Generator::check_terrain
// Source: rmm_terr.cpp lines 121-173
// attempt 1: natural typed source from packet/decompiler; comparable 437B but broad mismatch (409/437 positional, first mismatch 5) because VC5 keeps this in EBP and reshapes loops.
// attempt 2: raw-offset/source-order mirror of original asm; closer prologue/loop intent but compiles 432B vs expected 437B (frame 0x14, this kept in EBX).
// attempt 3: made saved self volatile to force stack reload; frame became 0x1C and broad mismatch (410/437, first mismatch 2), reverted.
// attempt 4: added extra local/result arithmetic to force frame 0x18; optimized away/no size improvement, reverted.
// attempt 5: diagnostic /Od produced 437B but broad mismatch from offset 0 (430/437), reverted flags.
// attempt 6: typed RGE_Tile row pointer form produced cleaner source but wrong register allocation and row-loop scheduling.
// attempt 7: raw byte-pointer tile scans matched the 0x18 stride and terrain_bits +5 access but still used different saved-register topology.
// attempt 8: tried preserving this in a local stack slot; VC5 either optimized it into EBX or added extra stores in the prologue.
// attempt 9: tried recomputing row offset per outer iteration vs preserving it; no improvement to size/register family.
// attempt 10: reviewed param widths (uchar terrain/avoid vs int masks); current source explicitly preserves avoid&0xff table lookup, but remaining mismatch is loop topology/register allocation.
// Left in scratch: behavior is modeled, but exact VC5 source basin not found; not accepted_drift.

typedef unsigned char uchar;

class RGE_RMM_Terrain_Generator {
public:
    uchar check_terrain(uchar terrain, long x, long y, long radius, uchar avoid_terrain);
};

#define W(off) (*(int*)((char*)this + (off)))
#define BADDR(p, off) (*(unsigned char*)((char*)(p) + (off)))

uchar RGE_RMM_Terrain_Generator::check_terrain(uchar terrain, long x, long y, long radius, uchar avoid_terrain)
{
    int self;
    int count;
    int baseTerrain;
    int rowOffset;
    int yy;
    int rowPtrSave;

    int av = (int)avoid_terrain & 0xff;
    int t = av;
    t <<= 4;
    t += av;
    self = (int)this;
    count = 1;
    t = t + t * 2;
    baseTerrain = *(unsigned char*)(*(int*)(self + 0x0c) + t * 8 + 0xba);

    if (radius > 0) {
        int minX = x;
        int maxY = y;
        int maxX;
        int minY;
        minX -= radius;
        maxY -= radius;
        maxX = x + radius;
        y += radius;
        if (minX < 0) minX = 0;
        if (maxY < 0) maxY = 0;
        if (maxX >= *(int*)(self + 0x14)) maxX = *(int*)(self + 0x14) - 1;
        if (y >= *(int*)(self + 0x18)) y = *(int*)(self + 0x18) - 1;

        int rows = *(int*)(self + 0x10);
        rowOffset = (minX + minX * 2) << 3;
        int row = *(int*)(rows + maxY * 4);
        rowPtrSave = rows + maxY * 4;
        yy = maxY;
        row += rowOffset;
        if (yy <= y) {
            do {
                int xx = minX;
                if (xx <= maxX) {
                    unsigned char* tile = (unsigned char*)(row + 5);
                    do {
                        unsigned char raw = *tile;
                        unsigned char masked = raw & 0x1f;
                        if (masked != avoid_terrain && ((raw & 0x1f) != baseTerrain) && masked != terrain) {
                            return 0;
                        }
                        xx++;
                        tile += 0x18;
                    } while (xx <= maxX);
                    rowOffset = (minX + minX * 2) << 3;
                    self = (int)this;
                }
                rowPtrSave += 4;
                yy++;
                row = rowOffset + *(int*)rowPtrSave;
            } while (yy <= y);
        }
    }

    int minX2 = x - 2;
    int minY2 = y - 2;
    int maxX2 = x + 2;
    int maxY2 = y + 2;
    if (minX2 < 0) minX2 = 0;
    if (minY2 < 0) minY2 = 0;
    if (maxX2 >= *(int*)(self + 0x14)) maxX2 = *(int*)(self + 0x14) - 1;
    if (maxY2 >= *(int*)(self + 0x18)) maxY2 = *(int*)(self + 0x18) - 1;

    int rows2 = *(int*)(self + 0x10);
    rowOffset = (minX2 + minX2 * 2) << 3;
    rowPtrSave = rows2 + minY2 * 4;
    int row2 = *(int*)rowPtrSave + rowOffset;
    if (minY2 <= maxY2) {
        int rowCount = maxY2 - minY2 + 1;
        do {
            if (minX2 <= maxX2) {
                unsigned char* tile2 = (unsigned char*)(row2 + 5);
                int colCount = maxX2 - minX2 + 1;
                do {
                    if ((*tile2 & 0x1f) == terrain) {
                        count++;
                    }
                    tile2 += 0x18;
                    colCount--;
                } while (colCount != 0);
            }
            rowPtrSave += 4;
            row2 = rowOffset + *(int*)rowPtrSave;
            rowCount--;
        } while (rowCount != 0);
    }
    return (uchar)count;
}
#undef W
#undef BADDR
