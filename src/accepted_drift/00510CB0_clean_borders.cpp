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
// Current reduced-local version compiles but .text is 832B vs original 840B. Best prior natural
// version had equal size but broad prologue/register/frame drift. Remaining blocker is source/register allocation around parameter-slot
// reuse (original uses ebp=y, ebx=x, edi=tile byte offset, only two stack locals). No accepted_drift: broad drift.
//
// sa-e4d7ed85-10cb0 pass: established RGE_Tile stride 0x18, terrain byte +5 with
// &0x1f masking, RGE_Map set_terrain ABI, branch-local bools, and an outer x cursor.
// The best clean reconstruction is 818 bytes with 18/19 calls and 727 positional
// differing bytes; direct/qualified call forms and int-vs-long x were duplicates.
// Remaining structural gap is the original two distinct set_terrain sites plus
// x/offset register and parameter-home scheduling; no safe final exact lead remains.
// shardA6-510CB0-r1: removing continue, branch-local world/value copies, and
// direct/base call qualification were codegen duplicates; restored canonical source.
// shardA6-510CB0-r1: PDB-shaped do-while scans were duplicate or slightly worse.
// Typed row/tile cursors aligned all 19 calls but widened the frame and worsened drift.
// The remaining gap is tail-merged first set_terrain plus x/offset register coloring.
// orch-510CB0-a: widening the border accumulator and spelling explicit != 1 improved the diff to 593,
// but the first set_terrain call remained tail-merged; rolled back as non-canonical source.
// orch-510CB0-a: widening both border accumulators improved the diff to 585 but exceeded the function boundary;
// the call-count gap remained, so rolled back.
// Revisit sa-d9deee7e (2026-08-17): ran 20 distinct checked hypotheses.
// Qualification, loop-form simplifications, continue removal, and one shared
// byte flag were duplicates or worse. Widening only the first flag gave 601
// differing bytes. Widening both gave 543 differing bytes at exact size, but
// still merged the first set_terrain call (18/19 calls). An explicit inner
// while loop restored 19/19 calls but gave 691 differing bytes and a 2-byte
// boundary overrun. Explicit flag comparisons and short flags did not close
// the call gap. Restored the simplest checked source.
// sa-e941c99f-r1 pass: the executable's short-circuit OR groups are required
// for all vertical and diagonal neighbor tests. The prior independent vertical
// tests changed behavior and prevented separate set_terrain call sites. Explicit
// `border == 1` terminal tests recover the original `cmp byte,1` branches, the
// 840-byte boundary, all 19 calls, and all 276 instruction blocks.
//
// Exact-finish: changing the terrain member from a plain byte with an explicit
// mask to the proven five-bit terrain_type bitfield recovers the sole SIB byte.
// The exact transition changes no tile size, row stride, calls, or control flow.
// A reduction test removed the other canonical tile fields and stayed exact.
// Reverting only the bitfield, while retaining the mask, restored the one-byte
// mismatch at the current-tile load. The final source is therefore the smallest
// natural tmap.cpp reconstruction supported by the exact check.
// BINARY NOTE: terrain_type occupies the low five bits at tile offset +5.
//
// The map rows are arrays of 0x18-byte RGE_Tile records. The byte used by
// clean_borders is terrain at +5, distinct from the passability byte at +4.

#ifndef TMAP_GROUP_CONTEXT
struct RGE_Tile {
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type : 5;
    char gap_06[0x18 - 0x06];
};

class RGE_Map {
public:
    void* vtable;
    RGE_Tile* map;
    long map_width;
    long map_height;
    long world_width;
    long world_height;
    char gap_18[0x8D8C - 0x18];
    RGE_Tile** map_row_offset;
    char gap_8D90[0x30];
    void* game_world;

    void set_terrain(void* world, short x, short y, unsigned char terrain, int a, int b);
};

class TRIBE_Map : public RGE_Map {
public:
    unsigned char water(unsigned char value);
    void clean_borders(long x1, long y1, long x2, long y2, unsigned char terrain);
};
#endif

#define TERRAIN_AT(tile) ((tile)->terrain_type)

void TRIBE_Map::clean_borders(long x1, long y1, long x2, long y2, unsigned char terrain) {
    long max_y = this->map_height - 1;
    long max_x = this->map_width - 1;

    if (x1 < 0)
        x1 = 0;
    if (y1 < 0)
        y1 = 0;
    if (x2 >= this->map_width)
        x2 = max_x;
    if (y2 >= this->map_height)
        y2 = max_y;

    for (; y1 <= y2; ++y1) {
        long x = x1;
        if (x <= x2) {
            for (; x <= x2; ++x) {
                if (TERRAIN_AT(this->map_row_offset[y1] + x) == 2) {
                    bool border = false;
                    if ((y1 > 0 && this->water(TERRAIN_AT(this->map_row_offset[y1 - 1] + x))) ||
                        (y1 < max_y && this->water(TERRAIN_AT(this->map_row_offset[y1 + 1] + x))))
                        border = true;
                    if (x > 0) {
                        if (this->water(TERRAIN_AT(this->map_row_offset[y1] + x - 1)) ||
                            (y1 > 0 && this->water(TERRAIN_AT(this->map_row_offset[y1 - 1] + x - 1))) ||
                            (y1 < max_y && this->water(TERRAIN_AT(this->map_row_offset[y1 + 1] + x - 1))))
                            border = true;
                    }
                    if (x < max_x) {
                        if (this->water(TERRAIN_AT(this->map_row_offset[y1] + x + 1)) ||
                            (y1 > 0 && this->water(TERRAIN_AT(this->map_row_offset[y1 - 1] + x + 1))) ||
                            (y1 < max_y && this->water(TERRAIN_AT(this->map_row_offset[y1 + 1] + x + 1))))
                            border = 1;
                    }
                    if (border == 1)
                        continue;
                    RGE_Map::set_terrain(this->game_world, (short)x, (short)y1, terrain, 0, 0);
                } else if (!this->water(TERRAIN_AT(this->map_row_offset[y1] + x))) {
                    bool border = false;
                    if ((y1 > 0 && this->water(TERRAIN_AT(this->map_row_offset[y1 - 1] + x))) ||
                        (y1 < max_y && this->water(TERRAIN_AT(this->map_row_offset[y1 + 1] + x))))
                        border = true;
                    if (x > 0) {
                        if (this->water(TERRAIN_AT(this->map_row_offset[y1] + x - 1)) ||
                            (y1 > 0 && this->water(TERRAIN_AT(this->map_row_offset[y1 - 1] + x - 1))) ||
                            (y1 < max_y && this->water(TERRAIN_AT(this->map_row_offset[y1 + 1] + x - 1))))
                            border = true;
                    }
                    if (x < max_x) {
                        if (this->water(TERRAIN_AT(this->map_row_offset[y1] + x + 1)) ||
                            (y1 > 0 && this->water(TERRAIN_AT(this->map_row_offset[y1 - 1] + x + 1))) ||
                            (y1 < max_y && this->water(TERRAIN_AT(this->map_row_offset[y1 + 1] + x + 1))))
                            border = 1;
                    }
                    if (border == 1)
                        this->set_terrain(this->game_world, (short)x, (short)y1, 2, 0, 0);
                }
            }
        }
    }
}
