// VA: 004848A0 RGE_RMM_Elevation_Generator::check_elevation
// Source: rmm_elev.cpp lines 100-153
// Attempt log:
// 1: initial reconstruction from packet/decompiler; wrong first-phase register topology and too-short text.
// 2: literal decompiler-style temporaries/order; too-short 0x10 frame due byte counter.
// 3: int local_10/row-count literal decompiler form even shorter/worse.
// 4: original-asm-inspired loop topology still too short/broad.
// 5: restore initial source as best behavioral baseline.
// 6: /Ob0, /O1, and /Gs flag probes did not reach original size/layout; removed flags.
// New claim: carry the second scan's row base plus x-offset across the row
// increment, matching the original `mov next_row; add offset` topology instead
// of recomputing the offset inside each cell LEA.
// Next ABI/layout probe: reuse the check_start_elevation sibling's byte-row
// ownership (`char**` plus byte row bases) instead of `int**`/`int*` aliases.
// Next liveness probe: model the binary-proven `count` stack local as the first
// scan's row counter, while keeping the second scan's byte result separate.
// Final source-width probe: use the period code's natural `long` coordinate,
// offset, and count locals throughout both scans instead of decompiler `int`s.
// Clean-source result: second-scan row-base carry is retained (408B boundary
// still lacks 11 effective bytes); first-scan row-base carry, result/row-count
// split, combined predicate, and inherited-class context were rolled back as
// worse or duplicate. No source-shape path reached the original first-scan
// stack homes.
// Left in scratch: behavior modeled, but first/second scan register topology and stack-slot layout remain broad.
// Continuation (sa-ab4dd300-r1): rmm_base/rmm_terr donors support the full
// inherited map-row and 24-byte tile surface; it compiled identically to the
// gap-only surface. A first-scan row_index and explicit self pointer were
// binary-motivated but formed a 370-byte-diff basin. Declaring the first
// row-pointer before its row base, while retaining byte-level tile access,
// improved the clean reconstruction to a 349-byte diff. Carrying the first
// row offset or swapping the second row-base/pointer order moved into broader
// structural basins; the latter reached 322 bytes but lost 13 bytes of code
// and kept the countdown in a register, so it was restored. Remaining gap is
// structural first-scan/second-countdown topology.
// Main-agent audit removed the diagnostic self alias and non-target padding
// helper; direct member ownership remains authoritative.
// Current claim: rechecked the full packet, dossier, same-TU donors, and ABI
// evidence. Prior bounded probes already exhausted first-scan row/count and
// second-scan liveness/layout families; no new source-supported lead justified
// replacing this readable 397-byte canonical reconstruction.
// Fresh worker (shardE-4848A0):
// - Baseline repeated the canonical typed two-scan source (397 bytes, diff 349).
// - Loading the second row base through row_ptr2 improved block/edit alignment
//   without changing size or strict diff; retained as a natural cursor form.
// - Reusing short-range names, hoisting first-scan declarations, and counted
//   while/for variants were duplicate or broader basins. Explicit radius-home
//   reuse was broader and was rolled back.
// - Reordering first row_ptr before row_offset was the best new lead: 394 bytes,
//   diff 323, shape 83.55%, with the oracle's saved-this, row-pointer, and
//   offset homes aligned. It still misses the count/y2/x2 home rotation and
//   remains structurally non-exact. A final index1 local probe broadened to 375
//   bytes and was rolled back.
// Paused: retain the readable row_ptr-before-offset reconstruction. Remaining
// blocker is the first-scan local-home rotation; no further blind variants fit
// the evidence budget.
// Fresh worker probes (orch-rmmelev-fresh-03):
// - Reusing the dead radius home for the first-scan clipped upper row bound
//   improved the diagnostic output to 398 bytes / 322 differing bytes, but
//   changed the prologue and remained a broad structural basin; rolled back.
// - Separate row_index declaration/scope and declaration-order variants were
//   exact-size or duplicate broad basins; none recovered the original
//   result/row-pointer/saved-this local rotation.
// - The typed Map_Stack/tile/base surface from the new same-TU two-byte stack
//   sibling is retained as canonical context; it is codegen-neutral here.
// Paused: clean source remains 397 bytes / 349 differing bytes. The remaining
// evidence-backed blocker is the first-scan local-window topology (original
// row counter [esp+10], result [esp+14], row pointer [esp+18], saved this
// [esp+1c], and offset [esp+20]) versus the natural compiler allocation;
// second-scan behavior and canonical map ownership are modeled.

typedef unsigned char uchar;

// Main-agent audit confirmed canonical elevation-map ownership and retained the
// natural two-scan bounds check; padding remains non-target scaffolding only.
struct Map_Stack {
    long x;
    long y;
    float cost;
    float tot_cost;
    Map_Stack* next;
    Map_Stack* prev;
};

struct RGE_Tile {
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type : 5;
    unsigned char elevation : 3;
    unsigned char border_type : 4;
    unsigned char border_shape : 4;
    unsigned char last_drawn_as;
    unsigned char last_drawn_shape;
    unsigned char draw_as;
    unsigned char draw_attribute;
    unsigned char last_drawn_shape2;
    char objects[12];
};

class RGE_Random_Map_Module_List;

class RGE_Random_Map_Module {
public:
    virtual uchar generate() = 0;

    RGE_Random_Map_Module* parent;
    RGE_Random_Map_Module_List* list;
    void* map;
    RGE_Tile** map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    uchar* search_map;
    uchar** search_map_rows;
    Map_Stack* stack_array;
    Map_Stack** stack_offsets;
};

class RGE_RMM_Elevation_Generator : public RGE_Random_Map_Module {
public:

    uchar check_elevation(uchar elev, long x, long y, long radius, uchar terrain, uchar min_elev);
};

uchar RGE_RMM_Elevation_Generator::check_elevation(uchar elev, long x, long y, long radius, uchar terrain, uchar min_elev)
{
    long count = 0;
    long x1;
    long y1;
    long y2;
    long x2;
    long row_offset;
    RGE_Tile** row_ptr;
    char* row;
    if (radius > 0) {
        x1 = x - radius;
        y1 = y - radius;
        y2 = y + radius;
        x2 = radius + x;
        if (x1 < 0) {
            x1 = 0;
        }
        if (y1 < 0) {
            y1 = 0;
        }
        if (x2 >= this->map_width) {
            x2 = this->map_width - 1;
        }
        if (y2 >= this->map_height) {
            y2 = this->map_height - 1;
        }
        row_ptr = &this->map_row_offset[y1];
        row_offset = x1 * 24;
        row = (char*)*row_ptr;
        for (; y1 <= y2; ++y1) {
            if (x1 <= x2) {
                unsigned char* cell = (unsigned char*)row + row_offset + 5;
                long xx = x1;
                do {
                    if (terrain == 0xFF) {
                        return 0;
                    }
                    unsigned char v = *cell;
                    if ((v & 0x1F) != terrain) {
                        return 0;
                    }
                    if ((v >> 5) < min_elev) {
                        return 0;
                    }
                    ++xx;
                    cell += 24;
                } while (xx <= x2);
            }
            ++row_ptr;
            row = (char*)*row_ptr;
        }
    }

    {
    long x1 = x - 2;
    long y1 = y - 2;
    long x2 = x + 2;
    long y2 = y + 2;
    if (x1 < 0) {
        x1 = 0;
    }
    if (y1 < 0) {
        y1 = 0;
    }
    if (x2 >= this->map_width) {
        x2 = this->map_width - 1;
    }
    if (y2 >= this->map_height) {
        y2 = this->map_height - 1;
    }

    long row_offset2 = x1 * 24;
    RGE_Tile** row_ptr2 = &this->map_row_offset[y1];
    // Keep the initial second-scan row load on the named row-table cursor.
    // The oracle loads the row pointer and its row address as separate values.
    unsigned char* row_base2 = (unsigned char*)*row_ptr2 + row_offset2;
    if (y1 <= y2) {
        long rows_left = y2 - y1 + 1;
        do {
            if (x1 <= x2) {
                unsigned char* cell = row_base2 + 5;
                long cols_left = x2 - x1 + 1;
                do {
                    if ((*cell >> 5) == elev) {
                        ++count;
                    }
                    cell += 24;
                    --cols_left;
                } while (cols_left != 0);
            }
            ++row_ptr2;
            row_base2 = (unsigned char*)*row_ptr2 + row_offset2;
            --rows_left;
        } while (rows_left != 0);
    }
    }

    return (uchar)count;
}
