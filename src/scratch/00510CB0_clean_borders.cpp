// VA: 00510CB0 TRIBE_Map::clean_borders
// tmap.cpp
// Attempt log:
// initial reconstruction from packet: clamp rectangle, scan tile rows, water-neighbor tests, set_terrain calls.
// tried direct typed TRIBE_Map fields: width +8, height +0xC, row table +0x8D8C, terrain_data +0x8DC0.
// tried set_terrain as natural member with six pushed args; call surface aligns behaviorally with original.
// tried using matched water(unsigned char) member for all terrain-type tests rather than helper wrappers.
// tried first natural tile-pointer form; it compiled to original size 840 but broad 81.43% positional diff,
//   first mismatch at prologue (sub esp 0x10 vs original 0x08, y in edi not ebp, x in edi not ebx).
// tried removing durable tile/type locals and using direct row/off expressions to reduce local pressure.
// tried parameter-slot style while/do loops instead of for loops to encourage x1/y1 stack-slot reuse.
// tried explicit OFF(x) expression `(x+x*2)*8` to match lea+shl tile offset computation.
// tried separate t==2 branch and non-water branch with duplicated neighbor checks to mirror original layout.
// tried byte flags for border decisions; compiler still chooses a separate local/register family instead of original
//   reuse of the x parameter stack slot low byte (`mov byte [esp+20],0/1`) in the t==2 branch.
// tried direct expressions for left/right offsets (-24/+24) to match `[base+edi-13h]` / `[base+edi+1Dh]` addressing.
// Current reduced-local version compiles but .text is 832B vs original 840B. Best prior natural version had equal
// size but broad prologue/register/frame drift. Remaining blocker is source/register allocation around parameter-slot
// reuse (original uses ebp=y, ebx=x, edi=tile byte offset, only two stack locals). No accepted_drift: broad drift.

class TRIBE_Map {
public:
    char gap_00[8]; int width; int height; char gap_10[0x8D7C]; unsigned char** rows; char gap_8D90[0x30]; void* terrain_data;
    unsigned char water(unsigned char value);
    void set_terrain(void* terrain_data, long x, long y, int terrain, int a, int b);
    void clean_borders(long x1, long y1, long x2, long y2, unsigned char terrain);
};
#define TT(base, off) ((unsigned char)(((base)[(off)+5]) & 0x1f))
#define ROW(y) (this->rows[(y)])
#define OFF(x) (((x)+(x)*2)*8)

void TRIBE_Map::clean_borders(long x1, long y1, long x2, long y2, unsigned char terrain) {
    long max_y = this->height - 1;
    long max_x = this->width - 1;
    if (x1 < 0) x1 = 0;
    if (y1 < 0) y1 = 0;
    if (x2 >= this->width) x2 = max_x;
    if (y2 >= this->height) y2 = max_y;

    while (y1 <= y2) {
        long x = x1;
        if (x <= x2) {
            long off = OFF(x);
            do {
                unsigned char* row = ROW(y1);
                if (TT(row, off) == 2) {
                    y1 = y1; // keep param-like live
                    unsigned char border = 0;
                    if (y1 > 0 && this->water(TT(ROW(y1-1), off))) border = 1;
                    if (y1 < max_y && this->water(TT(ROW(y1+1), off))) border = 1;
                    if (off > 0) {
                        if (this->water(TT(row, off-24))) border = 1;
                        else if (y1 > 0 && this->water(TT(ROW(y1-1), off-24))) border = 1;
                        else if (y1 < max_y && this->water(TT(ROW(y1+1), off-24))) border = 1;
                    }
                    if (x < max_x) {
                        if (this->water(TT(row, off+24))) border = 1;
                        else if (y1 > 0 && this->water(TT(ROW(y1-1), off+24))) border = 1;
                        else if (y1 < max_y && this->water(TT(ROW(y1+1), off+24))) border = 1;
                    }
                    if (border != 1) this->set_terrain(this->terrain_data, x, y1, terrain, 0, 0);
                } else {
                    if (!this->water(TT(row, off))) {
                        unsigned char border2 = 0;
                        if (y1 > 0 && this->water(TT(ROW(y1-1), off))) border2 = 1;
                        if (y1 < max_y && this->water(TT(ROW(y1+1), off))) border2 = 1;
                        if (off > 0) {
                            if (this->water(TT(row, off-24))) border2 = 1;
                            else if (y1 > 0 && this->water(TT(ROW(y1-1), off-24))) border2 = 1;
                            else if (y1 < max_y && this->water(TT(ROW(y1+1), off-24))) border2 = 1;
                        }
                        if (x < max_x) {
                            if (this->water(TT(row, off+24))) border2 = 1;
                            else if (y1 > 0 && this->water(TT(ROW(y1-1), off+24))) border2 = 1;
                            else if (y1 < max_y && this->water(TT(ROW(y1+1), off+24))) border2 = 1;
                        }
                        if (border2 == 1) this->set_terrain(this->terrain_data, x, y1, 2, 0, 0);
                    }
                }
                x++;
                off += 24;
            } while (x <= x2);
        }
        y1++;
    }
}
