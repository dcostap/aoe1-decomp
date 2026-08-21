// 004820A0 RGE_RMM_Cliffs_Generator::invalidate_cliff_area()
// Source: rmm_clif.cpp lines 348-375
// Attempt log:
// - Reconstructed the map bounds, clipped rectangle, row/column arrays, and
//   Map_Stack ownership from rmm_base.cpp and the same-TU cliff callers.
// - Reversed both upper-bound comparisons to preserve the original cmp/jle
//   topology; this recovered two exact blocks.
// - Replaced the cell pointer local with repeated typed row indexing; this is
//   the best source basin (237 bytes, 214 positional differing bytes, 85.71%
//   shape) and restores the target's EDI/EBP/ESI/EBX saved-register roles.
// - A 24-variant typed declaration/cell-access lab found no size/frame/call-set
//   eligible improvement; register-qualified parameters and declaration-order
//   reordering were rolled back. Remaining drift is early parameter-home
//   coloring plus the row-base/stack-node address schedule.
// - A fresh source-order probe moved the natural x=cliff_x2 assignment before
//   the negative-bound guards, matching the oracle's unconditional x-home
//   store before the first test. This is the best current basin (246 rebuilt
//   bytes, 177 positional differing bytes, 91.01% shape); it improves the
//   prior clean source by four bytes without changing calls or layout.
// - Mutating y as the outer countdown, endpoint declaration/addition reorder,
//   direct x/y endpoint expressions, and equivalent first-clip spellings were
//   neutral or farther. Keeping a separate right-endpoint local through the
//   loop removed the required frame and was rolled back. The retained source
//   therefore keeps typed named ownership and only the binary-supported
//   x-home scheduling change.
// - Bounded follow-up probes kept the clean repeated-row source as canonical.
//   Reusing x as the clipped right bound is the metric-best diagnostic (248
//   rebuilt bytes, 181 differing bytes, 89.89% shape) but remains nonexact and
//   was rolled back; exact base-field types and cursor declaration scope were
//   codegen-neutral. That earlier clean checkpoint remains useful history; the
//   current source is the later 246-byte basin described above, still with one
//   ordered remove_stack_node call and structural drift in the entry schedule.
// - Fresh direct-parameter/declaration-order probes and a 12-variant
//   input/loop lab did not move the entry register basin. The binary-proven
//   x-home assignment with the clipped-x second comparison remains the best
//   behavior-faithful reconstruction; later column/right-lifetime probes were
//   duplicate or farther and are not retained.
// - This session tested compound endpoint updates, spacing-first endpoint
//   seeds, removal of parameter-home mutations, grouped coordinate endpoints,
//   same-TU <string.h> context, a retained right-endpoint local, and split
//   bound decrements. None improved the current 246-byte basin; the clean
//   typed source was restored before final validation.
// - A new evidence pass restored named x/y aliases and kept the unconditional
//   x-home endpoint update. This reached exact size with 172 differing bytes,
//   stronger block coverage, and a cleaner resync than the prior 246-byte
//   source; the late x-home variant reached 170 bytes but lost that schedule.
// - Reversing alias declarations, splitting endpoint updates, and capturing
//   spacing as a local were codegen duplicates. The current aliases remain
//   readable ownership, not compiler-only scaffolding.
// - Follow-up direct endpoint locals, y-first declaration order, deferred
//   endpoint assignments, and parameter mutation were either duplicates or
//   structurally worse. The target's initial y home in EBP remains unresolved.
// - A four-case endpoint/input and x-home variant lab kept the 243-byte frame
//   basin but did not recover EBP; the aliases with early x-home update remain
//   the cleanest source. No exact policy-clean lead remains in this pass.
// - Terrain donors 00484C80 and 00488F90 confirm the 0x18-byte Map_Stack
//   stride, parameter-home reuse, and counted row scan. Testing their clipped
//   right-bound and cursor forms did not improve the clean 243-byte basin.
//   The remaining evidence gap is the target's EBP y-home color and its
//   register-held clipped-right value.
// - A fresh revisit tested y-home countdown reuse, endpoint declaration and
//   initialization order, single-axis aliases, clipped-right locals, and
//   ordinary for loops. These were duplicates or structurally worse; the
//   for-loop form reached diff 171 but added one byte and an extra CFG edge.
//   The pinned typed do-loop source remains the clean natural reconstruction.
// - This revisit compared exact terrain-bound donor 00547080 and exact
//   parameter-home donor 00484C80, then tested XYPoint bounds, mixed endpoint
//   aliases, complete base method declarations, and split bound declarations.
//   These emitted the existing 172-byte mismatch or a worse basin. The EBP
//   y-home and EBX clipped-right value remain the evidence gap.
// - Final revisit probes 078-097 tested direct and compound endpoint forms,
//   loop forms, row and stack-offset locals, field types, declaration order,
//   and TU context. The clean source stayed at 243 bytes and 172 differing
//   bytes. Outer for/while forms reached 171 differing bytes but added one
//   byte and one CFG edge. The clean do-loop source is restored.
// - TU reconstruction pass: repository-local exact donors fix the definition
//   order as constructor, generate, setup, generate_cliff, check, then this
//   function. Setup supports <string.h>, a full RGE_Tile, and the complete
//   stack-method surface. Generate supports debug_rand and the RGE_Map surface.
// - Header, tile, base-method, class-method-order, donor-body, donor-order,
//   pragma, ambient-declaration, and period-header variants all kept the
//   243-byte frame and the same 172 raw differing bytes. No variant selected
//   the target EBP y-home or EBX clipped-right liveness.
// - Default config/flags/default.rsp (/O2 /Oy) remains the only supported
//   flag context. /Oy-, /Ob0, /Ow, /O1, /Og-, and /Ot- changed codegen or
//   lost the target frame. No TU-only exact lead is retained.
// - Object audit: the original PDB has no inline expansion and confirms the
//   ABI, class layout, x1/x2, and two bound locals. Original FPO reports 243
//   bytes; the current object reports 242. A PDB-lifetime candidate improved
//   the masked difference but retained the wrong y and right-bound registers.
// - Source-gate audit removed parameter-home reuse. x1, y1, x2, and y2 are
//   named bounds, while x, y, and spacing remain input parameters. The map
//   pointer now uses the proven RGE_Map owner, with RGE_Tile row ownership.
//   BINARY NOTE: the upper y clamp compares x2 with the height bound. Keep
//   this original shipped behavior rather than correcting the comparison.
//   The policy-clean source rebuilds to 228 bytes with no FPO local frame;
//   the metric regression is accepted because the old frame came from a
//   Restoring that frame would require the removed compiler-facing alias.
// - This follow-up kept the named x1/y1/x2/y2 source and tested typed map-row
//   and stack-row locals, grouped and reordered endpoint declarations, split
//   endpoint arithmetic, row-count spelling, typed cell cursors, and for-loop
//   forms. These were duplicates or worse. Direct repeated typed row indexing
//   and the do-counted loops remain the clearest natural structure. No
//   parameter-home aliases were restored.
// - Accepted-drift audit: do not promote this candidate. The original has an
//   0x08 local frame, while the natural rebuild has none. Thus remove_stack_node
//   receives a different stack and exception context. The clipped traversal
//   and original x2-versus-height bug otherwise remain preserved.

struct Map_Stack {
    long x;
    long y;
    float cost;
    float tot_cost;
    Map_Stack* next;
    Map_Stack* prev;
};

struct RGE_Tile;
struct RGE_Map;

class RGE_Random_Map_Module {
public:
    virtual unsigned char generate(void);

    void* parent;
    void* list;
    RGE_Map* map;
    RGE_Tile** map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    unsigned char* search_map;
    unsigned char** search_map_rows;
    Map_Stack* stack_array;
    Map_Stack** stack_offsets;

    void remove_stack_node(Map_Stack* node);
};

struct RGE_Cliffs_Hot_Spots {
    long x;
    long y;
    long radius;
};

struct RGE_Cliffs_Info {
    long number_of_cliffs;
    long number_of_cliffs_variance;
    long average_cliff_size;
    long cliff_size_variance;
    long cliff_terrain_spacing;
    long cliff_to_cliff_spacing;
    RGE_Cliffs_Hot_Spots hot_spots[99];
    long hot_spot_num;
};

class RGE_RMM_Cliffs_Generator : public RGE_Random_Map_Module {
public:
    virtual unsigned char generate(void);

    RGE_Cliffs_Info info;
    Map_Stack valid_cliff_sites;

    void invalidate_cliff_area(long x, long y, long spacing);
};

void RGE_RMM_Cliffs_Generator::invalidate_cliff_area(long x, long y, long spacing) {
    long cliff_width2 = this->map_width / 3 - 1;
    long cliff_height2 = this->map_height / 3 - 1;
    long x1 = x - spacing;
    long y1 = y - spacing;
    long x2 = spacing + x;
    long y2 = spacing + y;

    if (x1 < 0) {
        x1 = 0;
    }
    if (y1 < 0) {
        y1 = 0;
    }
    if (x2 > cliff_width2) {
        x2 = cliff_width2;
    }
    if (x2 > cliff_height2) {
        y2 = cliff_height2;
    }

    if (y1 <= y2) {
        long row = y1;
        long row_count = y2 - y1 + 1;
        do {
            if (x1 <= x2) {
                long column = x1;
                do {
                    if (this->search_map_rows[row][column] != 0) {
                        this->search_map_rows[row][column] = 0;
                        this->remove_stack_node(this->stack_offsets[row] + column);
                    }
                    column++;
                } while (column <= x2);
            }
            row++;
            row_count--;
        } while (row_count != 0);
    }
}
