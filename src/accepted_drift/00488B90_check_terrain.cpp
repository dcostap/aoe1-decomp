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
// attempt 11: rebuilt the prior raw-offset source as the session baseline; 426B/0x14 frame, structural stage.
// attempt 12: restored the period terrain-generator/map/row ownership and direct repeated tile-byte predicates; test whether the canonical base surface restores the original frame and loop topology.
// attempt 13: corrected the proven terrain-set member from rows to impassable_terrain (+0x2E within the +0x8C terrain table); the observed map-relative lookup is +0xBA + index*0x198.
// attempt 14: widened the base-terrain result to long, matching the original dword local/home and EBX zero-plus-byte load rather than a byte-only stack home.
// attempt 15: gave the first radius scan its own row index instead of mutating min_y; original asm spills/reloads that outer index at +0x18 while retaining min_y in the setup register.
// attempt 16: hoisted the row-index declaration before count/base locals to probe VC5's source declaration/home ordering without changing ownership or CFG.
// attempt 17: carried a typed self pointer through both scans, reflecting the binary's repeated saved-this reloads rather than relying on an implicit compiler spill.
// attempt 19: ordered the row-index declaration before the typed self local, probing the remaining four-byte home permutation at the otherwise exact prologue.
// attempt 20: initialized the spilled first-scan row index directly from y-radius rather than copying min_y; this is the last bounded liveness probe before retaining the best canonical basin.
// attempt 21: block-scoped the first-scan row index; emitted code was unchanged.
// attempt 22: restored first-scan induction to clamped min_y; behaviorally natural and exact-size, but drift widened to 353 bytes, so restored the prior basin.
// attempt 23: register/split self initialization and function-scope first-row locals were compiler duplicates; restored.
// Left in scratch: canonical typed terrain/map/row ownership, long base-terrain ABI, and both scan CFGs are reconstructed; remaining drift is VC5 stack-home/register coloring and early loop block shape (best current 429B, exact frame, 70.7% positional diff).
// Main-agent audit removed the codegen-only self alias; direct member ownership
// is authoritative for the paused canonical source.
// Fresh pass: first-scan for/while and clamped-min_y combinations were worse or
// exact-size but structurally farther; second-scan cursor declaration/update
// variants were compiler duplicates (focused six-variant lab, 429B/309 diff).
// Function-scope reuse of all bounds/cursors and local int row cursors did not
// improve the canonical basin. Restored clean source after the 10-probe budget;
// remaining lead is the target's early local-home/register assignment and
// spilled first row-pointer topology.
// New claim: the binary clamps the first-scan row index before induction; using
// y-radius would read extra rows at a map edge, so the typed reconstruction uses
// the clamped min_y value.
// New claim: a named 24-byte RGE_Tile terrain_type byte preserves tile ownership
// and low-five-bit behavior, but VC5 emits a broader 351-byte mismatch. The
// remaining gap is local-home/register allocation and early block placement.
// Fresh claim probes: x-bound declaration order (min_x, max_x, min_y, max_y)
// reached 437 bytes and reduced positional drift to 295 bytes, but did not
// recover the target's stack-home permutation. Other bound permutations were
// worse or compiler duplicates. Explicit copy-then-adjust bounds, row-index
// declaration moves, typed self/map-row aliases, split row assignments, math
// header context, and split inner-count initialization also produced no lead.
// The best natural source remains this typed reconstruction; no exact result.
// Revisit pass: row-index scope and initializer forms, bound declaration and
// assignment forms, typed row-pointer order/scope, radius-home reuse, typed
// same-TU list context, and count initialization produced no lead. Restored
// the canonical typed terrain/map source after each probe.
// Accepted drift: both scans use the same clipped inclusive bounds, terrain
// predicate order, initial-row read, and next-row read before loop exit. The
// second scan has the same byte-count wrap and return. This function has no
// calls or writes. Remaining drift is private local-home and register choice.

typedef unsigned char uchar;

struct RGE_Tile {
    char gap_00[5];
    unsigned char terrain_type;
    char gap_06[0x12];
};

class RGE_Tile_Set {
public:
    unsigned char loaded;
    unsigned char random;
    char name[13];
    char pict_name[13];
    long resource_id;
    void* shape;
    void* sound;
    unsigned char map_hi_color;
    unsigned char map_med_color;
    unsigned char map_low_color;
    unsigned char map_lt_cliff_color;
    unsigned char map_rt_cliff_color;
    unsigned char passable_terrain;
    unsigned char impassable_terrain;
    unsigned char is_animated;
    short animation_frames;
    short pause_frames;
    float interval;
    float pause_between_loops;
    short frame;
    short draw_frame;
    float animate_last;
    unsigned char frame_changed;
    unsigned char drawn;
    char tiles[0x72];
    short terrain_to_draw;
    short rows;
    short cols;
    char rest[0x198 - 0xC0];
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    RGE_Tile* map;
    long map_width;
    long map_height;
    long world_width;
    long world_height;
    char tile_sizes[0x74];
    RGE_Tile_Set terrain_types[32];
};

class RGE_Random_Map_Module {
public:
    virtual uchar generate() = 0;
    RGE_Random_Map_Module* parent;
    void* list;
    RGE_Map* map;
    RGE_Tile** map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    uchar* search_map;
    uchar** search_map_rows;
    void* stack_array;
    void* stack_offsets;
};

class RGE_RMM_Terrain_Generator : public RGE_Random_Map_Module {
public:
    uchar check_terrain(uchar terrain, long x, long y, long radius,
                        uchar avoid_terrain);
};

uchar RGE_RMM_Terrain_Generator::check_terrain(
    uchar terrain, long x, long y, long radius, uchar avoid_terrain)
{
    long count = 1;
    long base_terrain = this->map->terrain_types[avoid_terrain].impassable_terrain;
    long row_index;

    if (radius > 0) {
        long min_x = x - radius;
        long max_x = x + radius;
        long min_y = y - radius;
        long max_y = y + radius;

        if (min_x < 0) min_x = 0;
        if (min_y < 0) min_y = 0;
        if (max_x >= this->map_width) max_x = this->map_width - 1;
        if (max_y >= this->map_height) max_y = this->map_height - 1;

        RGE_Tile** row_ptr = this->map_row_offset + min_y;
        RGE_Tile* row = *row_ptr + min_x;

        row_index = min_y;
        if (row_index <= max_y) {
            do {
                if (min_x <= max_x) {
                    long xx = min_x;
                    RGE_Tile* tile = row;
                    do {
                        if (((tile->terrain_type & 0x1f) != avoid_terrain) &&
                            ((tile->terrain_type & 0x1f) != base_terrain) &&
                            ((tile->terrain_type & 0x1f) != terrain)) {
                            return 0;
                        }
                        ++xx;
                        ++tile;
                    } while (xx <= max_x);
                }
                ++row_ptr;
                ++row_index;
                row = *row_ptr + min_x;
            } while (row_index <= max_y);
        }
    }

    long min_x = x - 2;
    long min_y = y - 2;
    long max_x = x + 2;
    long max_y = y + 2;

    if (min_x < 0) min_x = 0;
    if (min_y < 0) min_y = 0;
    if (max_x >= this->map_width) max_x = this->map_width - 1;
    if (max_y >= this->map_height) max_y = this->map_height - 1;

    RGE_Tile** row_ptr = this->map_row_offset + min_y;
    RGE_Tile* row = *row_ptr + min_x;
    if (min_y <= max_y) {
        long row_count = max_y - min_y + 1;
        do {
            if (min_x <= max_x) {
                RGE_Tile* tile = row;
                long col_count = max_x - min_x + 1;
                do {
                    if ((tile->terrain_type & 0x1f) == terrain) {
                        ++count;
                    }
                    ++tile;
                    --col_count;
                } while (col_count != 0);
            }
            ++row_ptr;
            row = *row_ptr + min_x;
            --row_count;
        } while (row_count != 0);
    }
    return (uchar)count;
}
